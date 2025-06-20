/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <QtBuilder.hxx>

#include <QtDoubleSpinBox.hxx>
#include <QtExpander.hxx>
#include <QtInstanceLinkButton.hxx>
#include <QtInstanceMessageDialog.hxx>
#include <QtInstanceNotebook.hxx>
#include <QtTools.hxx>

#include <rtl/ustrbuf.hxx>
#include <vcl/qt/QtUtils.hxx>

#include <QtGui/QStandardItemModel>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>

namespace
{
QString convertAccelerator(const OUString& rText)
{
    // preserve literal '&'s and use '&' instead of '_' for the accelerator
    return toQString(rText.replaceAll("&", "&&").replace('_', '&'));
}
}

QtBuilder::QtBuilder(QObject* pParent, std::u16string_view sUIRoot, const OUString& rUIFile)
    : WidgetBuilder(sUIRoot, rUIFile, false)
{
    processUIFile(pParent);
}

QtBuilder::~QtBuilder() {}

QObject* QtBuilder::get_by_name(std::u16string_view sID)
{
    for (auto const& child : m_aChildren)
    {
        if (child.m_sID == sID)
            return child.m_pWindow;
    }

    return nullptr;
}

void QtBuilder::insertComboBoxOrListBoxItems(QObject* pObject, stringmap& rMap,
                                             const std::vector<ComboBoxTextItem>& rItems)
{
    if (QComboBox* pComboBox = qobject_cast<QComboBox*>(pObject))
    {
        for (const ComboBoxTextItem& rItem : rItems)
        {
            QVariant aUserData;
            if (!rItem.m_sId.isEmpty())
                aUserData = QVariant::fromValue(toQString(rItem.m_sId));

            pComboBox->addItem(toQString(rItem.m_sItem), aUserData);
        }

        const int nActiveId = BuilderBase::extractActive(rMap);
        pComboBox->setCurrentIndex(nActiveId);
        return;
    }

    assert(false && "list boxes are not supported yet");
}

QObject* QtBuilder::insertObject(QObject* pParent, const OUString& rClass, std::string_view sType,
                                 const OUString& rID, stringmap& rProps, stringmap&, stringmap&)
{
    QObject* pCurrentChild = nullptr;

    pCurrentChild = makeObject(pParent, rClass, sType, rID, rProps);

    setProperties(pCurrentChild, rProps);

    rProps.clear();

    return pCurrentChild;
}

QObject* QtBuilder::makeObject(QObject* pParent, std::u16string_view sName, std::string_view sType,
                               const OUString& sID, stringmap& rMap)
{
    // ignore placeholders
    if (sName.empty())
        return nullptr;

    // nothing to do for these
    if (sName == u"GtkCellRendererText" || sName == u"GtkTreeSelection")
        return nullptr;

    QWidget* pParentWidget = qobject_cast<QWidget*>(pParent);
    QLayout* pParentLayout = qobject_cast<QLayout*>(pParent);

    QObject* pObject = nullptr;
    // in case a QLayout is created, an additional QWidget parent
    // will also be created because that is needed for QtInstanceContainer
    QWidget* pLayoutParentWidget = nullptr;

    if (sName == u"GtkMessageDialog")
    {
        pObject = new QMessageBox(pParentWidget);
    }
    else if (sName == u"GtkBox")
    {
        // for a QMessageBox, return the existing layout instead of creating a new one
        if (QMessageBox* pMessageBox = qobject_cast<QMessageBox*>(pParent))
        {
            pObject = pMessageBox->layout();
            assert(pObject && "QMessageBox has no layout");
        }
        else
        {
            QWidget* pBoxParentWidget = pParentWidget;
            // Unless this is the direct GtkBox child of a GtkDialog, create a parent widget
            // that can be used to create a QtInstanceContainer for this box
            if (!qobject_cast<QDialog*>(pParentWidget))
            {
                pLayoutParentWidget = new QWidget(pParentWidget);
                pBoxParentWidget = pLayoutParentWidget;
            }

            const bool bVertical = hasOrientationVertical(rMap);
            if (bVertical)
                pObject = new QVBoxLayout(pBoxParentWidget);
            else
                pObject = new QHBoxLayout(pBoxParentWidget);
        }
    }
    else if (sName == u"GtkButtonBox")
    {
        QWidget* pTopLevel = windowForObject(pParent);
        if (QMessageBox* pMessageBox = qobject_cast<QMessageBox*>(pTopLevel))
        {
            // for a QMessageBox, return the existing button box instead of creating a new one
            QDialogButtonBox* pButtonBox = findButtonBox(pMessageBox);
            assert(pButtonBox && "Could not find QMessageBox's button box");
            pObject = pButtonBox;

            // skip adding to layout below, button box is already contained in dialog
            pParentLayout = nullptr;
        }
        else
        {
            pObject = new QDialogButtonBox(pParentWidget);
        }
    }
    else if (sName == u"GtkButton")
    {
        if (QDialogButtonBox* pButtonBox = qobject_cast<QDialogButtonBox*>(pParentWidget))
        {
            pObject = pButtonBox->addButton("", QDialogButtonBox::NoRole);

            // for message boxes, avoid implicit standard buttons in addition to those explicitly added
            if (QMessageBox* pMessageBox = qobject_cast<QMessageBox*>(pParentWidget->window()))
                pMessageBox->setStandardButtons(QMessageBox::NoButton);
        }
        else
        {
            pObject = new QPushButton(pParentWidget);
        }
    }
    else if (sName == u"GtkCheckButton")
    {
        pObject = new QCheckBox(pParentWidget);
    }
    else if (sName == u"GtkComboBoxText")
    {
        QComboBox* pComboBox = new QComboBox(pParentWidget);
        pComboBox->setEditable(extractEntry(rMap));
        pObject = pComboBox;
    }
    else if (sName == u"GtkDialog")
    {
        pObject = new QDialog(pParentWidget);
    }
    else if (sName == u"GtkDrawingArea")
    {
        pObject = new QLabel(pParentWidget);
    }
    else if (sName == u"GtkEntry")
    {
        QLineEdit* pLineEdit = new QLineEdit(pParentWidget);
        auto aIt = rMap.find(u"visibility"_ustr);
        if (aIt != rMap.end() && !toBool(aIt->second))
            pLineEdit->setEchoMode(QLineEdit::Password);

        pObject = pLineEdit;
    }
    else if (sName == u"GtkExpander")
    {
        pObject = new QtExpander(pParentWidget);
    }
    else if (sName == u"GtkFrame")
    {
        pObject = new QGroupBox(pParentWidget);
    }
    else if (sName == u"GtkGrid")
    {
        pLayoutParentWidget = new QWidget(pParentWidget);
        pObject = new QGridLayout(pLayoutParentWidget);
    }
    else if (sName == u"GtkImage")
    {
        QLabel* pLabel = new QLabel(pParentWidget);
        const OUString sIconName = extractIconName(rMap);
        if (!sIconName.isEmpty())
        {
            const Image aImage = loadThemeImage(sIconName);
            pLabel->setPixmap(toQPixmap(aImage));
        }
        pObject = pLabel;
    }
    else if (sName == u"GtkLabel")
    {
        QLabel* pLabel = new QLabel(pParentWidget);
        setLabelProperties(*pLabel, rMap);
        extractMnemonicWidget(sID, rMap);
        pObject = pLabel;
    }
    else if (sName == u"GtkLevelBar" || sName == u"GtkProgressBar")
    {
        QProgressBar* pProgressBar = new QProgressBar(pParentWidget);
        // don't show text (progress in percent) by default
        pProgressBar->setTextVisible(false);
        pObject = pProgressBar;
    }
    else if (sName == u"GtkLinkButton")
    {
        QtHyperlinkLabel* pLabel = new QtHyperlinkLabel(pParentWidget);
        if (rMap.contains(u"label"_ustr))
            pLabel->setDisplayText(toQString(rMap[u"label"_ustr]));
        if (rMap.contains(u"uri"_ustr))
            pLabel->setUri(toQString(rMap[u"uri"_ustr]));

        pObject = pLabel;
    }
    else if (sName == u"GtkNotebook")
    {
        pObject = new QTabWidget(pParentWidget);
    }
    else if (sName == u"GtkRadioButton")
    {
        pObject = new QRadioButton(pParentWidget);
    }
    else if (sName == u"GtkScrolledWindow")
    {
        pObject = new QScrollArea(pParentWidget);
    }
    else if (sName == u"GtkSeparator")
    {
        const bool bVertical = hasOrientationVertical(rMap);
        QFrame* pFrame = new QFrame(pParentWidget);
        pFrame->setFrameShape(bVertical ? QFrame::VLine : QFrame::HLine);
        pObject = pFrame;
    }
    else if (sName == u"GtkSpinButton")
    {
        QtDoubleSpinBox* pSpinBox = new QtDoubleSpinBox(pParentWidget);
        setSpinButtonProperties(*pSpinBox, rMap);
        pObject = pSpinBox;
    }
    else if (sName == u"GtkTextView")
    {
        pObject = new QPlainTextEdit(pParentWidget);
    }
    else if (sName == u"GtkTreeView")
    {
        QTreeView* pTreeView = new QTreeView(pParentWidget);
        pTreeView->setModel(new QStandardItemModel(pTreeView));
        pTreeView->setHeaderHidden(!extractHeadersVisible(rMap));
        pTreeView->setRootIsDecorated(extractShowExpanders(rMap));
        pObject = pTreeView;
    }
    else if (sName == u"GtkTreeViewColumn")
    {
        SAL_WARN("vcl.qt", "GtkTreeViewColumn properties not evaluated yet");
    }
    else
    {
        SAL_WARN("vcl.qt", "Widget type not supported yet: "
                               << OUStringToOString(sName, RTL_TEXTENCODING_UTF8));
        assert(false && "Widget type not supported yet");
    }

    QWidget* pWidget = qobject_cast<QWidget*>(pObject);
    if (!pWidget)
        pWidget = pLayoutParentWidget;

    QTabWidget* pParentTabWidget = qobject_cast<QTabWidget*>(pParentWidget);
    if (pParentTabWidget)
    {
        // remove QTabWidget child widget, set via QTabWidget::addTab instead
        assert(pWidget);
        pWidget->setParent(nullptr);
        // initially, add tab with empty label, QtBuilder::applyTabChildProperties will evaluate actual one
        pParentTabWidget->addTab(pWidget, QStringLiteral());
        // unset pParentWidget to not create a layout below
        pParentWidget = nullptr;
    }
    else if (QtExpander* pExpander = qobject_cast<QtExpander*>(pParentWidget))
    {
        // set the content (not the label) child as the expander's widget
        if (sType != "label")
        {
            pExpander->setContentWidget(pWidget);
            // erase "visible" property, QtExpander shows/hides the widget as needed
            rMap.erase("visible");
        }
    }

    if (pWidget)
    {
        if (!pParentLayout && pParentWidget)
        {
            // if the parent is a widget, use the widget's layout, and ensure it has one set
            pParentLayout = pParentWidget->layout();
            if (!pParentLayout)
                pParentLayout = new QVBoxLayout(pParentWidget);
        }

        // add widget to parent layout
        if (pParentLayout)
            pParentLayout->addWidget(pWidget);

        QtInstanceWidget::setHelpId(*pWidget, getHelpRoot() + sID);

        pWidget->setToolTip(toQString(extractTooltipText(rMap)));
        pWidget->setVisible(extractVisible(rMap));

#if QT_VERSION >= QT_VERSION_CHECK(6, 9, 0)
        // Set GtkBuilder ID as accessible ID
        pWidget->setAccessibleIdentifier(toQString(sID));
#endif
    }
    else if (QLayout* pLayout = qobject_cast<QLayout*>(pObject))
    {
        // add layout to parent layout
        if (QBoxLayout* pParentBoxLayout = qobject_cast<QBoxLayout*>(pParentLayout))
            pParentBoxLayout->addLayout(pLayout);
        else if (QGridLayout* pParentGridLayout = qobject_cast<QGridLayout*>(pParentLayout))
            pParentGridLayout->addLayout(pLayout, pParentGridLayout->rowCount(), 0);
    }

    m_aChildren.emplace_back(sID, pObject);

    return pObject;
}

void QtBuilder::tweakInsertedChild(QObject* pParent, QObject* pCurrentChild, std::string_view sType,
                                   std::string_view sInternalChild)
{
    if (sInternalChild == "entry" && qobject_cast<QComboBox*>(pParent))
    {
        // an editable GtkComboBox has an internal GtkEntry child,
        // but QComboBox doesn't need a separate widget for it, so
        // delete it
        deleteObject(pCurrentChild);
    }

    if (sType == "label")
    {
        if (QLabel* pLabel = qobject_cast<QLabel*>(pCurrentChild))
        {
            if (QGroupBox* pGroupBox = qobject_cast<QGroupBox*>(pParent))
            {
                // GtkFrame has a `child-type="label"` child for the GtkFrame label
                // in the GtkBuilder .ui file, s. https://docs.gtk.org/gtk3/class.Frame.html
                // For QGroupBox, the title can be set directly. Therefore, take over the
                // title from the label and delete the separate label widget again
                pGroupBox->setTitle(pLabel->text());
                deleteObject(pLabel);
            }
            else if (QtExpander* pExpander = qobject_cast<QtExpander*>(pParent))
            {
                // GtkExpander has a `child-type="label"` child for the expander label
                // in the GtkBuilder .ui file, s. https://docs.gtk.org/gtk3/class.Expander.html
                // For QtExpander, the (button) text can be set directly. Therefore, take over
                // text from the label and delete the separate label widget again
                pExpander->setText(pLabel->text());
                deleteObject(pLabel);
            }
        }
    }

    if (QDialog* pDialog = qobject_cast<QDialog*>(pCurrentChild))
    {
        // no action needed for QMessageBox, where the default button box is used
        // and button click is handled in QtInstanceMessageDialog
        if (!qobject_cast<QMessageBox*>(pDialog))
        {
            if (QDialogButtonBox* pButtonBox = findButtonBox(pDialog))
            {
                // ensure that button box is the last item in QDialog's layout
                // (that seems to be implicitly the case for GtkDialog in GTK)
                QLayout* pLayout = pDialog->layout();
                assert(pLayout && "dialog has no layout");
                pLayout->removeWidget(pButtonBox);
                pLayout->addWidget(pButtonBox);

                // connect button click handler
                const QList<QAbstractButton*> aButtons = pButtonBox->buttons();
                for (QAbstractButton* pButton : aButtons)
                {
                    assert(pButton);
                    QObject::connect(pButton, &QAbstractButton::clicked, pDialog,
                                     [pDialog, pButton] {
                                         QtInstanceDialog::handleButtonClick(*pDialog, *pButton);
                                     });
                }
            }
        }
    }
}

void QtBuilder::setMnemonicWidget(const OUString& rLabelId, const OUString& rMnemonicWidgetId)
{
    QLabel* pLabel = get<QLabel>(rLabelId);
    QObject* pBuddy = get_by_name(rMnemonicWidgetId);

    if (!pLabel || !pBuddy || !pBuddy->isWidgetType())
        return;

    pLabel->setBuddy(static_cast<QWidget*>(pBuddy));
}

void QtBuilder::setPriority(QObject*, int) { SAL_WARN("vcl.qt", "Ignoring priority"); }

void QtBuilder::setContext(QObject*, std::vector<vcl::EnumContext::Context>&&)
{
    SAL_WARN("vcl.qt", "Ignoring context");
}

bool QtBuilder::isHorizontalTabControl(QObject* pObject)
{
    QTabWidget* pTabWidget = qobject_cast<QTabWidget*>(pObject);
    if (!pTabWidget)
        return false;

    const QTabWidget::TabPosition ePosition = pTabWidget->tabPosition();
    return ePosition == QTabWidget::TabPosition::North
           || ePosition == QTabWidget::TabPosition::South;
}

QMenu* QtBuilder::createMenu(const OUString&)
{
    assert(false && "Not implemented yet");
    return nullptr;
}

void QtBuilder::insertMenuObject(QMenu*, QMenu*, const OUString&, const OUString&, stringmap&,
                                 stringmap&, accelmap&)
{
    assert(false && "Not implemented yet");
}

void QtBuilder::applyAtkProperties(QObject* pObject, const stringmap& rProperties, bool)
{
    if (!pObject || !pObject->isWidgetType())
        return;

    QWidget* pWidget = static_cast<QWidget*>(pObject);

    for (auto const & [ rKey, rValue ] : rProperties)
    {
        if (rKey == "AtkObject::accessible-description")
            pWidget->setAccessibleDescription(toQString(rValue));
        else if (rKey == "AtkObject::accessible-name")
            pWidget->setAccessibleName(toQString(rValue));
    }
}

void QtBuilder::applyGridPackingProperties(QWidget* pCurrentChild, QGridLayout& rGrid,
                                           const stringmap& rPackingProperties)
{
    assert(pCurrentChild);

    // properties not set when there's no explicit GtkGrid in the .ui file,
    // like for the QGridLayout that's the (implicit) layout of a QMessageBox
    if (!rPackingProperties.contains(u"left-attach"_ustr)
        || !rPackingProperties.contains(u"top-attach"_ustr))
        return;

    const sal_Int32 nColumn = rPackingProperties.at(u"left-attach"_ustr).toInt32();
    const sal_Int32 nRow = rPackingProperties.at(u"top-attach"_ustr).toInt32();

    auto aWidthIt = rPackingProperties.find(u"width"_ustr);
    sal_Int32 nColumnSpan = (aWidthIt == rPackingProperties.end()) ? 1 : aWidthIt->second.toInt32();

    auto aHeightIt = rPackingProperties.find(u"height"_ustr);
    sal_Int32 nRowSpan = (aHeightIt == rPackingProperties.end()) ? 1 : aHeightIt->second.toInt32();

    rGrid.removeWidget(pCurrentChild);
    rGrid.addWidget(pCurrentChild, nRow, nColumn, nRowSpan, nColumnSpan);
}

void QtBuilder::applyPackingProperties(QObject* pCurrentChild, QObject* pParent,
                                       const stringmap& rPackingProperties)
{
    if (!pCurrentChild)
        return;

    QWidget* pWidget = nullptr;
    if (pCurrentChild->isWidgetType())
        pWidget = static_cast<QWidget*>(pCurrentChild);
    else
    {
        QObject* pParentObject = pCurrentChild->parent();
        assert(pParent && "Non-widget (i.e. layout) has no parent");
        if (pParentObject->isWidgetType())
            pWidget = static_cast<QWidget*>(pParentObject);
    }

    if (!pWidget)
        return;

    // check parent's parent, due to extra QWidget parents for layouts
    if (QGridLayout* pGrid = qobject_cast<QGridLayout*>(pParent))
        applyGridPackingProperties(pWidget, *pGrid, rPackingProperties);
    else
        SAL_WARN("vcl.qt", "QtBuilder::applyPackingProperties not yet implemented for this case");
}

void QtBuilder::applyTabChildProperties(QObject* pParent, const std::vector<OUString>& rIDs,
                                        std::vector<vcl::EnumContext::Context>&,
                                        stringmap& rProperties, stringmap&)
{
    QTabWidget* pTabWidget = qobject_cast<QTabWidget*>(pParent);
    assert(pTabWidget && "parent must be a QTabWidget");

    // set ID and label for the last inserted tab
    assert(rProperties.contains(u"label"_ustr) && "Tab has no label");
    QtInstanceNotebook::setTabIdAndLabel(*pTabWidget, pTabWidget->count() - 1, rIDs.front(),
                                         rProperties.at(u"label"_ustr));
}

void QtBuilder::set_response(std::u16string_view sID, short nResponse)
{
    QPushButton* pPushButton = get<QPushButton>(sID);
    assert(pPushButton);
    pPushButton->setProperty(QtInstanceMessageDialog::PROPERTY_VCL_RESPONSE_CODE, int(nResponse));
}

void QtBuilder::deleteObject(QObject* pObject)
{
    if (pObject->isWidgetType())
        static_cast<QWidget*>(pObject)->hide();
    pObject->deleteLater();
}

void QtBuilder::setProperties(QObject* pObject, stringmap& rProps)
{
    if (QMessageBox* pMessageBox = qobject_cast<QMessageBox*>(pObject))
    {
        for (auto const & [ rKey, rValue ] : rProps)
        {
            if (rKey == u"text")
            {
                pMessageBox->setText(toQString(rValue));
            }
            else if (rKey == u"title")
            {
                pMessageBox->setWindowTitle(toQString(rValue));
            }
            else if (rKey == u"secondary-text")
            {
                pMessageBox->setInformativeText(toQString(rValue));
            }
            else if (rKey == u"message-type")
            {
                if (rValue == u"error")
                    pMessageBox->setIcon(QMessageBox::Critical);
                else if (rValue == u"info")
                    pMessageBox->setIcon(QMessageBox::Information);
                else if (rValue == u"question")
                    pMessageBox->setIcon(QMessageBox::Question);
                else if (rValue == u"warning")
                    pMessageBox->setIcon(QMessageBox::Warning);
                else
                    assert(false && "Unhandled message-type");
            }
        }
    }
    else if (qobject_cast<QCheckBox*>(pObject) || qobject_cast<QRadioButton*>(pObject))
    {
        QAbstractButton* pButton = static_cast<QAbstractButton*>(pObject);
        for (auto const & [ rKey, rValue ] : rProps)
        {
            if (rKey == u"active")
                pButton->setChecked(toBool(rValue));
            else if (rKey == u"label")
                pButton->setText(convertAccelerator(rValue));
        }
    }
    else if (QDialog* pDialog = qobject_cast<QDialog*>(pObject))
    {
        for (auto const & [ rKey, rValue ] : rProps)
        {
            if (rKey == u"modal")
                pDialog->setModal(toBool(rValue));
            else if (rKey == u"title")
                pDialog->setWindowTitle(toQString(rValue));
        }
    }
    else if (QPlainTextEdit* pTextEdit = qobject_cast<QPlainTextEdit*>(pObject))
    {
        for (auto const & [ rKey, rValue ] : rProps)
        {
            if (rKey == u"accepts-tab")
                pTextEdit->setTabChangesFocus(!toBool(rValue));
        }
    }
    else if (QPushButton* pButton = qobject_cast<QPushButton*>(pObject))
    {
        for (auto const & [ rKey, rValue ] : rProps)
        {
            if (rKey == u"image")
            {
                QLabel* pImageLabel = get<QLabel>(rValue);
                assert(pImageLabel && "Button has non-existent image set");
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
                pButton->setIcon(QIcon(pImageLabel->pixmap()));
#else
                pButton->setIcon(QIcon(pImageLabel->pixmap(Qt::ReturnByValue)));
#endif
                // parentless GtkImage in .ui file is only used for setting button
                // image, so the object is no longer needed after doing so
                if (!pImageLabel->parent())
                    deleteObject(pImageLabel);
            }
            else if (rKey == u"label")
            {
                pButton->setText(convertAccelerator(rValue));
            }
        }
    }
}

void QtBuilder::setLabelProperties(QLabel& rLabel, stringmap& rProps)
{
    for (auto const & [ rKey, rValue ] : rProps)
    {
        if (rKey == u"label")
            rLabel.setText(convertAccelerator(rValue));
        else if (rKey == u"wrap")
            rLabel.setWordWrap(toBool(rValue));
    }
}

void QtBuilder::setSpinButtonProperties(QDoubleSpinBox& rSpinBox, stringmap& rProps)
{
    auto aDigitsIt = rProps.find(u"digits"_ustr);
    sal_Int32 nDigits = (aDigitsIt != rProps.end()) ? aDigitsIt->second.toInt32() : 0;
    rSpinBox.setDecimals(nDigits);

    auto aAdjustmentIt = rProps.find("adjustment");
    if (aAdjustmentIt != rProps.end())
    {
        const Adjustment* pAdjustment = get_adjustment_by_name(aAdjustmentIt->second);
        assert(pAdjustment && "referenced adjustment doesn't exist");
        for (auto const & [ rKey, rValue ] : *pAdjustment)
        {
            if (rKey == u"upper")
                rSpinBox.setMaximum(rValue.toDouble());
            else if (rKey == u"lower")
                rSpinBox.setMinimum(rValue.toDouble());
            else if (rKey == "value")
                rSpinBox.setValue(rValue.toDouble());
            else if (rKey == "step-increment")
                rSpinBox.setSingleStep(rValue.toDouble());
        }
    }
}

QWidget* QtBuilder::windowForObject(QObject* pObject)
{
    if (QWidget* pWidget = qobject_cast<QWidget*>(pObject))
        return pWidget->window();

    if (QLayout* pLayout = qobject_cast<QLayout*>(pObject))
    {
        if (QWidget* pParentWidget = pLayout->parentWidget())
            return pParentWidget->window();
    }

    return nullptr;
}

QDialogButtonBox* QtBuilder::findButtonBox(QDialog* pDialog)
{
    assert(pDialog);
    QLayout* pLayout = pDialog->layout();
    if (!pLayout)
        return nullptr;

    for (int i = 0; i < pLayout->count(); i++)
    {
        QLayoutItem* pItem = pLayout->itemAt(i);
        if (QWidget* pItemWidget = pItem->widget())
        {
            if (QDialogButtonBox* pButtonBox = qobject_cast<QDialogButtonBox*>(pItemWidget))
                return pButtonBox;
        }
    }
    return nullptr;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
