# LibreOffice Solid Protocol Extension

A standalone LibreOffice extension that enables secure document storage on Solid pods. This extension implements the complete Solid protocol with DPoP authentication for connecting to Inrupt PodSpaces.

## ✅ Current Status

This extension implements key Solid protocol components:
- ✅ OAuth 2.0 + PKCE + DPoP authentication flow
- ✅ ECDSA P-256 key generation and JWT signing  
- ✅ PodSpaces (https://storage.inrupt.com/) integration
- ✅ HTTP operations with authentication headers
- ✅ Standalone `.oxt` extension packaging
- ✅ Cross-platform build support

**Development focus**:
- Testing file operations with Solid pods
- Validating DPoP authentication implementation
- Extension installation and integration testing

## 🎯 Project Goal

Enable LibreOffice users to store documents on Solid pods - giving them control over where their data lives. This aligns with digital sovereignty initiatives where organizations want to control their document storage infrastructure.

## 🚀 Installation

### For Users
1. Download the latest `libreoffice-solid-x.x.x.oxt` from releases
2. Install in LibreOffice: **Tools** → **Extension Manager** → **Add**
3. Restart LibreOffice
4. Access via **File** → **Open** or **Save As** → Choose Solid pod location

### For Developers

#### Prerequisites
- LibreOffice SDK
- C++ build tools (g++, make)
- Development libraries: libcurl, openssl

#### Building from Source
```bash
git clone https://github.com/inrupt/libreoffice-solid.git
cd libreoffice-solid
make extension
```

See [EXTENSION_BUILD.md](EXTENSION_BUILD.md) for detailed build instructions.

## 📁 What's Implemented

### Authentication & Security ✅
- **OAuth 2.0 + PKCE**: Complete authorization code flow with PKCE
- **DPoP Tokens**: Demonstration of Proof-of-Possession for enhanced security
- **ECDSA P-256**: Cryptographic key generation and JWT signing
- **PodSpaces Integration**: Native support for Inrupt PodSpaces

### Core Architecture ✅
- **Universal Content Provider (UCP)**: LibreOffice integration framework
- **HTTP Session Management**: Secure communication with Solid pods
- **Extension Packaging**: Standalone `.oxt` installation system
- **Cross-Platform Support**: Linux, Windows, macOS binaries

### File Operations ✅
- **Resource Access**: Read/write operations with proper authentication
- **Content Streaming**: Efficient data transfer to/from pods
- **URL Handling**: Support for `https://storage.inrupt.com/*` and `solid:*` schemes

## 🧪 Usage

### Connecting to Your Solid Pod

1. **Install the extension** (see Installation section above)
2. **Open or Save a document**:
   - Go to **File** → **Open** or **Save As**
   - Enter your pod URL: `https://storage.inrupt.com/YOUR-POD-ID/path/to/file.odt`
3. **Authenticate**:
   - Browser window opens for OAuth login
   - Sign in to your Inrupt account
   - Grant permissions to LibreOffice
4. **Access files**:
   - Browse and select files from your pod
   - Save documents directly to your pod storage

### Supported URLs
- `https://storage.inrupt.com/*` - Direct PodSpaces URLs
- `solid:*` - Custom Solid protocol scheme

## 🔧 Technical Details

### Architecture
- **Universal Content Provider (UCP)**: LibreOffice's framework for remote storage
- **DPoP Implementation**: Advanced security with proof-of-possession tokens
- **Async HTTP**: Non-blocking operations using libcurl
- **JWT Signing**: ECDSA P-256 cryptographic signatures

### Security Features
- **PKCE**: Proof Key for Code Exchange prevents authorization code interception
- **DPoP**: Cryptographically binds tokens to client, preventing token theft
- **Key Rotation**: Automatic generation of unique key pairs per session
- **Secure Storage**: Tokens stored securely in LibreOffice's credential manager

## 🤝 Contributing

Contributions welcome! Areas for enhancement:
- Additional Solid pod providers (beyond Inrupt PodSpaces)
- Container operations (folder browsing, creation)
- Access control (ACL) integration
- Performance optimizations
- Extended file format support

## ⚠️ Security Considerations

- Tokens are stored locally and transmitted securely
- DPoP keys are generated fresh for each session
- All HTTP communications use TLS
- Follows Solid security best practices

## 📖 Resources

- [Solid Protocol Specification](https://solidproject.org/TR/protocol)
- [WebID-OIDC Specification](https://solid.github.io/webid-oidc-spec/)
- [LibreOffice Development](https://wiki.documentfoundation.org/Development)

## 📄 License

Mozilla Public License 2.0 (MPL-2.0) - same as LibreOffice core.

---

**Development Status**: This is a test implementation for exploring Solid protocol integration with LibreOffice. Use for development and testing purposes.