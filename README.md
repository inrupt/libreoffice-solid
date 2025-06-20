# LibreOffice Solid Protocol Native Integration

Native LibreOffice integration that enables secure document storage on Solid pods. This implementation provides built-in Solid protocol support with DPoP authentication for connecting to Inrupt PodSpaces through LibreOffice's native Remote Files system.

## ✅ Current Status

This implementation provides native Solid protocol integration:
- ✅ OAuth 2.0 + PKCE + DPoP authentication flow
- ✅ ECDSA P-256 key generation and JWT signing  
- ✅ PodSpaces (https://storage.inrupt.com/) integration
- ✅ Native Remote Files system integration
- ✅ Universal Content Provider (UCP) implementation
- ✅ LibreOffice source code integration

**Development focus**:
- Native compilation into LibreOffice core
- Seamless Remote Files integration
- Testing with Solid pods and PodSpaces

## 🎯 Project Goal

Enable LibreOffice users to store documents on Solid pods through the native **File → Open Remote Files** system. This provides users control over where their data lives, aligning with digital sovereignty initiatives where organizations want to control their document storage infrastructure.

## 🚀 Installation

### Native LibreOffice Integration

This is now integrated directly into LibreOffice source code. To build LibreOffice with Solid support:

1. **LibreOffice Source Integration**:
   ```bash
   # Copy Solid UCP to LibreOffice source tree
   cp -r ucb/source/ucp/solid/ /path/to/libreoffice-source/ucb/source/ucp/
   
   # Add build system integration (Library_ucpsolid.mk)
   # Update Module_ucb.mk to include Solid UCP
   ```

2. **Build LibreOffice**:
   ```bash
   cd /path/to/libreoffice-source
   ./configure
   make clean && make -j$(nproc)
   ```

3. **Access Solid in LibreOffice**:
   - Go to **File** → **Open Remote Files**
   - Click **Add Service**
   - Select **Solid** from the service type dropdown
   - Enter your pod URL: `https://storage.inrupt.com/YOUR-POD-ID`

## 📁 Implementation Architecture

### Native Integration ✅
- **Universal Content Provider (UCP)**: Integrated into LibreOffice's ucb module
- **Remote Files Service**: Native support in LibreOffice's file picker
- **Build System Integration**: Proper gbuild makefile integration
- **Component Registration**: Registered in LibreOffice's service configuration

### Authentication & Security ✅
- **OAuth 2.0 + PKCE**: Complete authorization code flow with PKCE
- **DPoP Tokens**: Demonstration of Proof-of-Possession for enhanced security
- **ECDSA P-256**: Cryptographic key generation and JWT signing
- **PodSpaces Integration**: Native support for Inrupt PodSpaces

### File Operations ✅
- **Resource Access**: Read/write operations with proper authentication
- **Content Streaming**: Efficient data transfer to/from pods
- **URL Handling**: Support for `https://storage.inrupt.com/*` patterns

## 🧪 Usage

### Connecting to Your Solid Pod

1. **Build LibreOffice with Solid support** (see Installation section)
2. **Add Solid Service**:
   - Go to **File** → **Open Remote Files**
   - Click **Add Service**
   - Select **Solid** as service type
   - Enter your pod URL: `https://storage.inrupt.com/YOUR-POD-ID`
3. **Authenticate**:
   - Browser window opens for OAuth login
   - Sign in to your Inrupt account
   - Grant permissions to LibreOffice
4. **Access Files**:
   - Browse and select files from your pod
   - Open, edit, and save documents directly

### Supported URLs
- `https://storage.inrupt.com/*` - Direct PodSpaces URLs
- Detection based on domain patterns for Solid pod providers

## 🔧 Technical Details

### Source Code Structure
```
ucb/source/ucp/solid/
├── SolidOAuth.cxx/hxx          # OAuth 2.0 + PKCE + DPoP implementation
├── SolidHttpSession.cxx/hxx    # HTTP session management
├── solidprovider.cxx/hxx       # Universal Content Provider
├── solidcontent.cxx/hxx        # Content interface implementation
├── SolidRemoteFilesService.*   # Remote Files integration
├── SolidConfigDialog.*         # Configuration dialog
└── *.component                 # UNO component definitions
```

### Build Integration
- **Library_ucpsolid.mk**: LibreOffice gbuild library definition
- **Module_ucb.mk**: UCB module integration
- **Configuration.xcu**: UCP service registration
- **PlaceEditDialog integration**: Native UI support

### Security Features
- **PKCE**: Proof Key for Code Exchange prevents authorization code interception
- **DPoP**: Cryptographically binds tokens to client, preventing token theft
- **Key Rotation**: Automatic generation of unique key pairs per session
- **Secure Storage**: Tokens stored securely in LibreOffice's credential manager

## 🔨 Development

### Prerequisites
- LibreOffice source code
- C++ build environment (g++, make, gbuild)
- Development libraries: libcurl, openssl
- LibreOffice build dependencies

### Building
1. Integrate source code into LibreOffice source tree
2. Add build system files
3. Configure and build LibreOffice with Solid support

See [INSTALL.md](INSTALL.md) for detailed build and integration instructions.

## 🤝 Contributing

Contributions welcome! Areas for enhancement:
- Additional Solid pod providers (beyond Inrupt PodSpaces)
- Container operations (folder browsing, creation)
- Access control (ACL) integration
- Performance optimizations
- Extended authentication methods

## ⚠️ Security Considerations

- Tokens are stored locally and transmitted securely
- DPoP keys are generated fresh for each session
- All HTTP communications use TLS
- Follows Solid security best practices
- Integrated with LibreOffice's native security systems

## 📖 Resources

- [Solid Protocol Specification](https://solidproject.org/TR/protocol)
- [WebID-OIDC Specification](https://solid.github.io/webid-oidc-spec/)
- [LibreOffice Development](https://wiki.documentfoundation.org/Development)
- [LibreOffice UCP Development](https://wiki.documentfoundation.org/Development/Modules/UCB)

## 📄 License

Mozilla Public License 2.0 (MPL-2.0) - same as LibreOffice core.

---

**Development Status**: Native LibreOffice integration for Solid protocol support. Ready for LibreOffice source code integration and building.