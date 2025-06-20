# Contributing to LibreOffice Solid UCP

Thanks for your interest in contributing! This project provides native Solid pod integration for LibreOffice.

## Getting Started

1. **Read the docs**: Check [README.md](README.md) and [INSTALL.md](INSTALL.md)
2. **Build it**: Follow the installation guide to get LibreOffice building with Solid support
3. **Test it**: Try connecting to storage.inrupt.com pods
4. **Find issues**: Check GitHub issues or test different scenarios

## Development Areas

### Authentication (SolidOAuth.cxx/hxx)
- OAuth 2.0 + PKCE flow implementation
- DPoP token generation (ECDSA P-256 + JWT)
- Token refresh and storage
- Error handling for auth failures

### HTTP Operations (SolidHttpSession.cxx/hxx)
- Authenticated requests to Solid pods
- File upload/download operations
- Proper header management
- Network error handling

### Content Operations (solidcontent.cxx/hxx)
- LibreOffice Content interface implementation
- File metadata operations
- Stream handling for large files
- Directory/container operations

### UI Integration (SolidRemoteFilesService.cxx/hxx)
- Remote Files dialog integration
- Configuration dialogs
- Error message display
- User experience improvements

## Code Style

- Follow LibreOffice coding standards
- Use existing LibreOffice patterns (sal, rtl, uno)
- Add appropriate error handling
- Include debug logging with SAL_WARN/SAL_INFO

## Testing

### Manual Testing
1. Build LibreOffice with Solid UCP
2. Open LibreOffice Writer
3. File → Open Remote Files → Add Service → Solid
4. Test authentication flow with storage.inrupt.com
5. Try opening/saving documents

### What to Test
- Different pod providers
- Authentication edge cases (expired tokens, network failures)
- File operations (read, write, save as)
- Large file handling
- Error scenarios

## Submitting Changes

1. **Fork this repo** and create a feature branch
2. **Make your changes** with clear, focused commits
3. **Test thoroughly** with real Solid pods
4. **Submit a pull request** with:
   - Clear description of changes
   - Test results
   - Any new dependencies or build requirements

## Upstream Path

This code is intended for eventual submission to LibreOffice upstream:

- **LibreOffice Gerrit**: https://gerrit.libreoffice.org/
- **Development docs**: https://wiki.documentfoundation.org/Development
- **Mailing list**: libreoffice@lists.freedesktop.org

Major changes should consider the upstream submission path.

## Questions?

- **GitHub Issues**: Technical questions and bug reports
- **Discussions**: Feature ideas and architecture discussions
- **LibreOffice IRC**: #libreoffice-dev on OFTC for LibreOffice-specific questions

## License

All contributions must be compatible with MPL-2.0 (LibreOffice's license).