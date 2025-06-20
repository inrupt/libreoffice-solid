# LibreOffice Solid UCP

C++ implementation of a Universal Content Provider (UCP) for LibreOffice that enables native Solid pod integration with DPoP authentication.

## What This Is

This repo contains the source code for a LibreOffice UCP that provides native Solid protocol support. When integrated into LibreOffice, users can access Solid pods through the standard "File → Open Remote Files" interface.

## Development Status

**Working**: Complete C++ DPoP implementation with OAuth 2.0 + PKCE  
**Integrated**: Successfully integrated into LibreOffice source tree  
**Testing**: Ready for compilation and testing with storage.inrupt.com  

## Key Components

- **SolidOAuth.cxx/hxx**: OAuth 2.0 + PKCE + DPoP authentication implementation
- **solidprovider.cxx/hxx**: Main UCP implementation 
- **solidcontent.cxx/hxx**: Content interface for file operations
- **SolidHttpSession.cxx/hxx**: HTTP session management with authentication headers
- **SolidRemoteFilesService.cxx/hxx**: Integration with LibreOffice's Remote Files system

## Building

This code has been integrated into LibreOffice core. To build:

1. **Copy source to LibreOffice tree**:
   ```bash
   cp -r ucb/source/ucp/solid/ /path/to/libreoffice/ucb/source/ucp/
   ```

2. **Add build files** (already created):
   - `Library_ucpsolid.mk` - gbuild library definition
   - Updated `Module_ucb.mk` - includes Solid UCP in build
   - Updated `Configuration.xcu` - registers UCP service

3. **Build LibreOffice**:
   ```bash
   ./configure
   make clean && make -j$(nproc)
   ```

## How It Works

1. **URL Detection**: Handles `https://storage.inrupt.com/*` URLs
2. **Authentication**: Full OAuth 2.0 + PKCE + DPoP flow
3. **File Operations**: Standard LibreOffice content operations (read/write/stream)
4. **UI Integration**: Appears as "Solid" in Remote Files service dropdown

## Development Areas

- **Authentication**: OAuth flows, token refresh, DPoP token generation
- **HTTP Operations**: Authenticated requests to Solid pods
- **Content Operations**: File read/write, metadata, streaming
- **Error Handling**: Network errors, authentication failures
- **Testing**: Integration with different Solid pod providers

## Dependencies

- **libcurl**: HTTP operations
- **openssl**: ECDSA P-256 key generation and JWT signing
- **LibreOffice libraries**: ucbhelper, comphelper, sal, etc.

## Technical Details

- **DPoP Implementation**: ECDSA P-256 key pairs, JWT token signing
- **PKCE Support**: Code challenge/verifier for OAuth security
- **Session Management**: Token storage, refresh, secure credential handling
- **URL Patterns**: Configurable pod domain detection

## Contributing

Areas where help is needed:

- **Testing**: Verify compatibility with different Solid pod providers
- **Performance**: Optimize HTTP operations and authentication flows
- **Features**: Container operations, ACL integration, metadata handling
- **Documentation**: Code comments, API documentation

## License

MPL-2.0 (same as LibreOffice core)