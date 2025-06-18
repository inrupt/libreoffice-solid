# Building the LibreOffice Solid Extension

This document describes how to build and package the LibreOffice Solid UCP as a standalone extension (.oxt file).

## Prerequisites

- LibreOffice development environment
- LibreOffice SDK
- Build tools: make, g++, zip
- Required libraries: libcurl, openssl

## Quick Build

For development on Linux:

```bash
make dev
```

This will:
1. Build the Linux x86_64 binary
2. Package the extension
3. Install it to LibreOffice

## Manual Build Steps

### 1. Build the UCP library

```bash
make build-linux
```

### 2. Create the extension package

```bash
make extension
```

This creates `libreoffice-solid-1.0.0.oxt`

### 3. Install the extension

```bash
make install
```

Or manually:
```bash
unopkg add --force libreoffice-solid-1.0.0.oxt
```

## Cross-Platform Building

The extension supports multiple platforms. For complete distribution:

- **Linux**: Built automatically with `make build-linux`
- **Windows**: Requires cross-compilation or Windows build environment
- **macOS**: Requires cross-compilation or macOS build environment

Place platform-specific binaries in:
- `Linux_x86/ucpsolid.uno.so`
- `Linux_x86_64/ucpsolid.uno.so`
- `Windows/ucpsolid.uno.dll`
- `MacOSX_x86/ucpsolid.uno.dylib`

## Extension Structure

```
libreoffice-solid-1.0.0.oxt
├── META-INF/
│   └── manifest.xml
├── description.xml
├── SolidProviderConfiguration.xcu
├── package-description-en.txt
├── images/
│   ├── solid-icon.png
│   └── solid-icon-hc.png
├── Linux_x86_64/
│   └── ucpsolid.uno.so
├── Windows/
│   └── ucpsolid.uno.dll
└── MacOSX_x86/
    └── ucpsolid.uno.dylib
```

## Installation

The extension registers the Solid UCP to handle:
- `https://storage.inrupt.com/*` URLs (Inrupt PodSpaces)
- `solid:*` URLs (custom scheme)

## Troubleshooting

- Check LibreOffice logs: `~/.config/libreoffice/4/user/config/javasettings.xml`
- List installed extensions: `unopkg list`
- Remove extension: `unopkg remove com.sun.star.ucb.SolidContentProvider`