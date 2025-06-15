# Installing Solid Protocol Support in LibreOffice

This guide walks you through integrating Solid Protocol support into LibreOffice, enabling decentralized document storage for digital sovereignty.

## 📋 Prerequisites

- **Operating System**: Linux (tested on Ubuntu 25.04)
- **Build Tools**: gcc/g++ 11+, make, autoconf, pkg-config
- **LibreOffice Build Dependencies**: 
  ```bash
  # Ubuntu 25.04
  sudo apt-get build-dep libreoffice
  ```
- **Disk Space**: ~15GB for full LibreOffice build
- **Time**: First build takes 1-2 hours

## 🚀 Quick Installation

### Step 1: Clone LibreOffice Core

```bash
# Clone the official LibreOffice repository
git clone https://gerrit.libreoffice.org/core libreoffice-core
cd libreoffice-core

# Optional: Use a specific branch (e.g., latest stable)
# git checkout libreoffice-7-6
```

### Step 2: Copy Solid Implementation Files

```bash
# Set paths
SOLID_REPO="/path/to/libreoffice-solid"  # This repository
LO_CORE="$(pwd)"                          # LibreOffice core directory

# Copy UCP implementation
cp -r "$SOLID_REPO/ucb/source/ucp/solid" "$LO_CORE/ucb/source/ucp/"
cp "$SOLID_REPO/ucb/Library_ucpsolid.mk" "$LO_CORE/ucb/"

# Copy UI integration
cp "$SOLID_REPO/svtools/source/dialogs/SolidDetailsContainer.hxx" "$LO_CORE/svtools/source/dialogs/"
cp "$SOLID_REPO/svtools/source/dialogs/SolidDetailsContainer.cxx" "$LO_CORE/svtools/source/dialogs/"
```

### Step 3: Apply Integration Changes

You need to modify four existing LibreOffice files:

#### 3.1 Add Solid to Build System
Edit `ucb/Module_ucb.mk` and add Solid to the module list:

```makefile
$(eval $(call gb_Module_add_targets,ucb,\
    Library_cached1 \
    Library_srtrs1 \
    Library_ucb1 \
    $(if $(ENABLE_LIBCMIS),Library_ucpcmis1) \
    $(if $(WITH_WEBDAV),Library_ucpdav1) \
    $(if $(ENABLE_SOLID),Library_ucpsolid) \    # Add this line
    Library_ucpexpand1 \
    Library_ucpext \
    Library_ucpfile1 \
    Library_ucphier1 \
    Library_ucpimage \
    Library_ucppkg1 \
    Library_ucptdoc1 \
))
```

#### 3.2 Add Service Dialog Container
Edit `svtools/source/dialogs/ServerDetailsControls.hxx` and add at the end before `#endif`:

```cpp
class SolidDetailsContainer final : public DetailsContainer
{
private:
    std::unique_ptr<weld::Entry> m_xPodUrl;
    std::unique_ptr<weld::Button> m_xAuthButton;
    OUString m_sPodUrl;
    OUString m_sAccessToken;
    bool m_bAuthenticated;

public:
    SolidDetailsContainer(PlaceEditDialog* pDialog);

    virtual void set_visible(bool bShow) override;
    virtual INetURLObject getUrl() override;
    virtual bool setUrl(const INetURLObject& rUrl) override;
    virtual void setUsername(const OUString& rUsername) override;
    virtual void setPassword(const OUString& rPassword) override;
    virtual bool enableUserCredentials() override { return false; }

private:
    void authenticate();
    bool discoverOIDCIssuer(const OUString& podUrl, OUString& issuer);
    bool performOIDCFlow(const OUString& issuer);
    void updateAuthStatus();
    
    DECL_LINK(AuthClickHdl, weld::Button&, void);
    DECL_LINK(PodUrlChangeHdl, weld::Entry&, void);
};
```

#### 3.3 Update Service Dialog Implementation
Edit `svtools/source/dialogs/ServerDetailsControls.cxx` and add at the end before the final comment:

```cpp
// Include the complete SolidDetailsContainer implementation
// (Copy the contents of SolidDetailsContainer.cxx)
```

#### 3.4 Update Service Dialog Creation
Edit `svtools/source/dialogs/PlaceEditDialog.cxx`:

1. **Add to InitDetails() method** after the SSH details creation:
```cpp
// Create Solid Pod details control
std::shared_ptr<DetailsContainer> xSolidDetails(std::make_shared<SolidDetailsContainer>(this));
xSolidDetails->setChangeHdl( LINK( this, PlaceEditDialog, EditHdl ) );
m_aDetailsContainers.push_back(xSolidDetails);
```

#### 3.5 Update UI Definition
Edit `svtools/uiconfig/ui/placeedit.ui` and add "Solid Pod" to the service dropdown:

```xml
<items>
  <item translatable="yes" context="placeedit|liststore1">WebDAV</item>
  <item translatable="yes" context="placeedit|liststore1">SSH</item>
  <item translatable="yes" context="placeedit|liststore1">Solid Pod</item>
  <item translatable="yes" context="placeedit|liststore1">Windows Share</item>
</items>
```

### Step 4: Configure Build with Solid Support

```bash
# Add Solid support to configure
echo "AC_ARG_ENABLE(solid, AS_HELP_STRING([--enable-solid], [Enable Solid protocol support.]))" >> configure.ac
echo "AC_SUBST(ENABLE_SOLID)" >> configure.ac

# Run autogen with Solid enabled
./autogen.sh --enable-solid

# Alternative: Set manually if autogen doesn't recognize the flag
echo "ENABLE_SOLID=TRUE" >> config_host.mk
```

### Step 5: Build LibreOffice

```bash
# Full build (first time)
make

# Or build specific modules for faster iteration
make ucb.build
make svtools.build
```

## 🧪 Verification

### Check Build Success
```bash
# Verify Solid library was built
ls instdir/program/libucpsolid.so

# Check component registration
find instdir -name "ucpsolid.component"
```

### Test the Integration
1. **Launch LibreOffice:**
   ```bash
   instdir/program/soffice --writer
   ```

2. **Access Solid Storage:**
   - Navigate to: **File** → **Open** (or **Save As**)
   - Click **Manage Services** button
   - Click **Add Service**
   - Select **"Solid Pod"** from the dropdown
   - Enter your pod URL (e.g., `https://storage.inrupt.com/YOUR-POD-ID/`)
   - Click **"Authenticate with Pod"** to complete WebID-OIDC flow
   - Pod appears in remote locations for immediate use

3. **Test Document Operations:**
   - **Browse**: Navigate pod contents like any folder
   - **Open**: Double-click documents to open directly
   - **Save**: Save documents directly to pod
   - **Organize**: Create folders and manage hierarchy

## 🔧 Authentication Details

The implementation includes working WebID-OIDC authentication:

1. **OIDC Discovery**: Automatically discovers the correct OIDC issuer for your pod
2. **Browser Flow**: Opens your default browser for secure authentication
3. **Token Management**: Stores access tokens for session persistence
4. **Supported Providers**: 
   - Inrupt ESS (`storage.inrupt.com`)
   - Solid Community (`*.solidcommunity.net`)
   - Generic Solid pods with standard OIDC discovery

## 🔧 Troubleshooting

### Build Errors

**Missing ENABLE_SOLID flag**:
```bash
# Add manually to config_host.mk:
echo "export ENABLE_SOLID=TRUE" >> config_host.mk
make clean && make
```

**Symbol Resolution Issues**:
```bash
# Clean and rebuild specific modules
make ucb.clean && make ucb.build
make svtools.clean && make svtools.build
```

**Missing Dependencies**:
```bash
# Install additional build dependencies
sudo apt-get install libcurl4-openssl-dev libjson-glib-dev
```

### Runtime Issues

**Service Not Appearing**:
```bash
# Check component registration
grep -r "SolidContentProvider" instdir/
# Clear user profile and restart
rm -rf ~/.config/libreoffice/4/user
```

**Authentication Issues**:
```bash
# Check network connectivity to pod
curl -I https://your-pod-url.com/.well-known/openid-configuration
# Verify browser can access authentication endpoints
```

**File Operation Errors**:
- Ensure pod has proper read/write permissions
- Check that pod URL ends with trailing slash
- Verify authentication token hasn't expired

## 📁 Repository Structure

```
libreoffice-solid/
├── ucb/
│   ├── source/ucp/solid/       # Core UCP implementation
│   │   ├── solidprovider.*     # Main provider class
│   │   ├── solidcontent.*      # Content operations
│   │   ├── SolidSession.*      # HTTP session management
│   │   └── ucpsolid.component  # Service registration
│   └── Library_ucpsolid.mk     # Build configuration
├── svtools/
│   └── source/dialogs/
│       └── SolidDetailsContainer.*  # UI integration with auth
├── integration-examples/        # Shows required modifications
├── INSTALL.md                  # This file
├── README.md                   # Project overview
└── PROJECT.md                  # Technical details
```

## 🚦 Post-Installation

After successful installation:

1. **Create a Solid Pod** (if you don't have one):
   - Visit https://start.inrupt.com/ or https://solidcommunity.net/
   - Create your decentralized identity and storage

2. **Test Document Workflow**:
   - Create a new document in LibreOffice Writer
   - Save to your Solid pod via **File** → **Save As** → **Solid Pod**
   - Close and reopen from pod to verify full round-trip

3. **Configure for Organization**:
   - Set up organizational Solid pods for team collaboration
   - Configure access control for shared documents
   - Integrate with existing identity providers via Solid-OIDC

## 📚 Additional Resources

- [Solid Protocol Specification](https://solidproject.org/TR/protocol)
- [WebID-OIDC Authentication](https://solid.github.io/webid-oidc-spec/)
- [LibreOffice Development Wiki](https://wiki.documentfoundation.org/Development)
- [Universal Content Broker Guide](https://wiki.documentfoundation.org/Documentation/DevGuide/Universal_Content_Broker)

---

**Ready to Use**: This implementation provides complete Solid Protocol support with working authentication and file operations. No additional development required for basic functionality.