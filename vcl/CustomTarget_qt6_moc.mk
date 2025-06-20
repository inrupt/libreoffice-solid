# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_CustomTarget_CustomTarget,vcl/qt6))

$(call gb_CustomTarget_get_target,vcl/qt6) : \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtClipboard.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtDoubleSpinBox.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtExpander.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtFilePicker.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtFrame.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstance.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceCheckButton.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceComboBox.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceContainer.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceDialog.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceDrawingArea.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceEntry.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceExpander.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceLevelBar.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceLinkButton.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceMessageDialog.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceNotebook.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceProgressBar.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceRadioButton.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceSpinButton.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceTreeView.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtInstanceWindow.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtMainWindow.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtMenu.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtTransferable.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtObject.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtTimer.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtWidget.moc \
	$(gb_CustomTarget_workdir)/vcl/qt6/QtXAccessible.moc \

# For now, the headers in vcl/inc/qt6 just '#include' the ones
# in 'vcl/inc/qt5'.
# Since moc does not process classes from the included headers,
# it needs to be run on the headers in the qt5 dir.
# That will have to be adapted in case the qt6 VCL plugin
# uses "own" headers
$(gb_CustomTarget_workdir)/vcl/qt6/%.moc : \
		$(SRCDIR)/vcl/inc/qt5/%.hxx \
		| $(gb_CustomTarget_workdir)/vcl/qt6/.dir
	$(call gb_Output_announce,$(subst $(WORKDIR)/,,$@),$(true),MOC,1)
	$(call gb_Trace_StartRange,$(subst $(WORKDIR)/,,$@),MOC)
	$(MOC6) $< -o $@
	$(call gb_Trace_EndRange,$(subst $(WORKDIR)/,,$@),MOC)

# vim: set noet sw=4:
