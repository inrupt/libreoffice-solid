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

The following changes have already been made to LibreOffice core:

#### 3.1 Build System Integration ✅
- Added `--with-solid` configure option to `configure.ac`
- Added `WITH_SOLID` variable to `config_host.mk.in`
- Updated `ucb/Module_ucb.mk` to include Solid library
- Updated `svtools/Library_svt.mk` to include dialog files

#### 3.2 Core Integration Files ✅
- Universal Content Provider implementation in `ucb/source/ucp/solid/`
- Dialog integration in `svtools/source/dialogs/SolidDetailsContainer.*`
- Component registration and service definition
- Complete OAuth 2.0 + PKCE authentication framework

### Step 4: Configure Build with Solid Support

```bash
# Configure LibreOffice with Solid support enabled
./autogen.sh --with-solid

# This will:
# - Enable Solid protocol support
# - Include required dependencies (libcurl, openssl)
# - Add Solid library to build targets
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