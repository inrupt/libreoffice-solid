# Building LibreOffice with Solid Support

Step-by-step guide to build LibreOffice with native Solid pod integration.

## Prerequisites

### System Requirements
- **OS**: Linux (tested on Ubuntu 22.04+)
- **Disk**: ~20GB free space
- **RAM**: 8GB+ recommended
- **Time**: 2-4 hours for full build

### Install Build Dependencies

```bash
# Ubuntu/Debian
sudo apt-get build-dep libreoffice
sudo apt-get install git build-essential autoconf pkg-config
sudo apt-get install libcurl4-openssl-dev libssl-dev

# Additional LibreOffice dependencies
sudo apt-get install python3-dev gperf flex bison
```

## Build Steps

### 1. Get LibreOffice Source

```bash
# Clone LibreOffice core
git clone https://github.com/LibreOffice/core.git libreoffice-core
cd libreoffice-core

# Use a stable branch (recommended)
git checkout libreoffice-24-8
```

### 2. Integrate Solid UCP

```bash
# Clone this repo
git clone https://github.com/inrupt/libreoffice-solid.git

# Copy Solid UCP source code
cp -r libreoffice-solid/ucb/source/ucp/solid/ ucb/source/ucp/

# Copy build system files (these need to be created manually for now)
cp libreoffice-solid/build-integration/Library_ucpsolid.mk ucb/
```

### 3. Update LibreOffice Build System

Edit `ucb/Module_ucb.mk` and add:
```makefile
Library_ucpsolid \
```
to the module targets list.

Edit `officecfg/registry/data/org/openoffice/ucb/Configuration.xcu` and add:
```xml
<node oor:name="Provider98" oor:op="replace">
  <prop oor:name="ServiceName">
    <value>com.sun.star.comp.SolidContentProvider</value>
  </prop>
  <prop oor:name="URLTemplate">
    <value>https://storage\.inrupt\.com/.*</value>
  </prop>
</node>
```

### 4. Configure and Build

```bash
# Configure LibreOffice build
./autogen.sh --enable-debug --without-java

# Build (this takes 2-4 hours)
make clean
make -j$(nproc)
```

### 5. Test Installation

```bash
# Install locally
make install DESTDIR=/tmp/lo-test

# Or run from build directory
./instdir/program/soffice
```

## Verify Solid Integration

1. Open LibreOffice Writer
2. Go to **File** → **Open Remote Files**
3. Click **Add Service**
4. You should see **Solid** in the service type dropdown

## Current Status

**Working**: C++ implementation complete  
**Missing**: Some UI integration pieces may need manual addition  
**Next**: Submit patches to LibreOffice upstream  

## Upstream Integration

This implementation eventually needs to be submitted to LibreOffice for inclusion:

1. **Gerrit patches**: LibreOffice uses Gerrit for code review
2. **Feature approval**: Needs LibreOffice developer approval
3. **Testing**: Must pass LibreOffice CI/CD tests
4. **Documentation**: Help system integration

See: https://wiki.documentfoundation.org/Development/How_to_build

## Troubleshooting

### Build Fails
- Ensure all dependencies installed: `sudo apt-get build-dep libreoffice`
- Check disk space: `df -h`
- Try without parallel build: `make` (no -j flag)

### Solid Option Missing
- Verify UCP files copied to `ucb/source/ucp/solid/`
- Check `Module_ucb.mk` includes `Library_ucpsolid`
- Confirm Configuration.xcu has Provider98 entry

### Authentication Issues
- Ensure libcurl and openssl development headers installed
- Check LibreOffice logs: `~/.config/libreoffice/4/user/crash/`

## Development Notes

- This is currently a development integration
- For production use, wait for upstream LibreOffice inclusion
- Testing primarily done with storage.inrupt.com
- Other Solid pod providers may need additional work