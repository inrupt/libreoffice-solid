# Contributing to LibreOffice Solid Protocol Connector

Thank you for your interest in contributing to the LibreOffice Solid Protocol Connector!

## Development Setup

### Prerequisites
- LibreOffice development environment
- CURL library with development headers
- OpenSSL development libraries
- C++17 compatible compiler

### Building
1. Configure LibreOffice with Solid support:
   ```bash
   ./configure --with-solid
   ```

2. Build the UCB module:
   ```bash
   make ucb
   ```

## Code Style Guidelines

This project follows LibreOffice coding conventions:
- Use LibreOffice naming conventions (camelCase for variables, PascalCase for classes)
- Follow existing indentation and formatting patterns
- Include proper license headers in all source files
- Use LibreOffice UNO patterns for component implementation

## Submitting Changes

### For this Repository
1. Fork the repository
2. Create a feature branch: `git checkout -b feature/description`
3. Make your changes following the code style guidelines
4. Test your changes thoroughly
5. Submit a pull request with a clear description

### For LibreOffice Integration
1. Test changes in a full LibreOffice build
2. Submit patches to LibreOffice Gerrit: https://gerrit.libreoffice.org/
3. Follow LibreOffice development process: https://wiki.documentfoundation.org/Development

## Reporting Issues

- Use GitHub Issues for bugs and feature requests
- For security vulnerabilities, see SECURITY.md
- For LibreOffice-specific issues, use https://bugs.documentfoundation.org/

## Testing

Before submitting changes:
1. Ensure code compiles without warnings
2. Test with actual Solid pods (PodSpaces recommended)
3. Verify OAuth 2.0 authentication flow works correctly
4. Test document save/load operations

## Code of Conduct

This project follows the [Contributor Covenant Code of Conduct](CODE_OF_CONDUCT.md).

## Questions?

- GitHub Discussions: https://github.com/inrupt/libreoffice-solid/discussions
- Solid Community: https://solidproject.org/developers
- LibreOffice Development: https://wiki.documentfoundation.org/Development