# LibreOffice Solid Protocol Connector

**DEVELOPMENT STATUS**: Early stage implementation - not production ready

Connect LibreOffice to Solid pods for decentralized document storage. This experimental connector adds Solid protocol support to LibreOffice's remote storage options.

## 🚧 Current Status

This is an **early development implementation** that provides:
- Basic framework for Solid protocol integration
- Initial WebID-OIDC authentication structure
- Foundation for HTTP operations (GET/PUT/DELETE)
- UI integration in LibreOffice's service dialog

**NOT YET IMPLEMENTED**:
- Complete authentication flow
- Actual file read/write operations
- Token refresh handling
- Error recovery
- Production testing

## 🎯 Project Goal

Enable LibreOffice users to store documents on Solid pods - giving them control over where their data lives. This aligns with digital sovereignty initiatives where organizations want to control their document storage infrastructure.

## 🛠️ Development Setup

### Prerequisites
- Ubuntu 25.04 (only tested platform)
- LibreOffice development environment
- C++ build tools

### Quick Start
1. Clone the LibreOffice core repository
2. Copy this connector's files to the LibreOffice source tree
3. Build LibreOffice with `--with-solid` flag
4. Test with a pod from https://start.inrupt.com/

## 📁 What's Implemented

### Core Structure ✅
- Universal Content Provider (UCP) framework at `ucb/source/ucp/solid/`
- Service dialog integration for pod configuration
- Build system integration

### In Progress 🔄
- WebID-OIDC authentication with browser flow
- HTTP operations with authentication headers
- Basic file operations (open/save)

### Not Started ❌
- Container operations (folder creation/listing)
- Access control (ACL) integration
- Comprehensive error handling
- Performance optimization

## 🧪 Testing

Currently testing basic connectivity:
1. Add a pod service in LibreOffice
2. Enter pod URL: `https://storage.inrupt.com/YOUR-POD-ID/`
3. Attempt authentication (browser should open)
4. Check if token is received

**Note**: File operations are not yet functional.

## 🤝 Contributing

This is an open development project. Key areas needing work:
- Completing the OAuth2/OIDC flow
- Implementing actual HTTP operations with CURL
- Adding Turtle parsing for container listings
- Error handling and user feedback

## 📚 Technical Approach

The implementation follows patterns from JavaScript Solid libraries:
- Authentication flow similar to `@inrupt/solid-client-authn`
- File operations modeled on `@inrupt/solid-client`
- Mapping JavaScript patterns to C++ LibreOffice infrastructure

## ⚠️ Important Notes

- **Development only** - not ready for production use
- **Limited testing** - only basic framework verified
- **No guarantees** - interfaces may change significantly
- **Contributions welcome** - help make this production ready

## 📖 Resources

- [Solid Protocol Specification](https://solidproject.org/TR/protocol)
- [WebID-OIDC Specification](https://solid.github.io/webid-oidc-spec/)
- [LibreOffice Development](https://wiki.documentfoundation.org/Development)

## 📄 License

Mozilla Public License 2.0 (MPL-2.0) - same as LibreOffice core.

---

**Want to help?** This project needs developers familiar with:
- C++ and LibreOffice internals
- OAuth2/OIDC authentication
- HTTP client programming
- Solid protocol