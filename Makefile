# Makefile for LibreOffice Solid UCP Extension

# Extension name and version
EXTENSION_NAME = libreoffice-solid
VERSION = 1.0.0
OXT_FILE = $(EXTENSION_NAME)-$(VERSION).oxt

# Directories
SRC_DIR = ucb/source/ucp/solid
BUILD_DIR = build
EXTENSION_DIR = $(BUILD_DIR)/extension

# Platform-specific directories
LINUX_X86_DIR = $(EXTENSION_DIR)/Linux_x86
LINUX_X64_DIR = $(EXTENSION_DIR)/Linux_x86_64
WINDOWS_DIR = $(EXTENSION_DIR)/Windows
MACOSX_DIR = $(EXTENSION_DIR)/MacOSX_x86

# Source files
CXX_SOURCES = $(wildcard $(SRC_DIR)/*.cxx)
HXX_SOURCES = $(wildcard $(SRC_DIR)/*.hxx)

# LibreOffice SDK configuration
SDK_HOME = /usr/lib/libreoffice/sdk
LO_LIB_HOME = /usr/lib/libreoffice/program

# Compiler settings
CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -std=c++17 -O2 -DLINUX -DUNX -DCPPU_ENV=gcc3
INCLUDES = -I$(SDK_HOME)/include \
           -I/usr/include/libreoffice \
           -I$(SRC_DIR) \
           $(shell pkg-config --cflags libcurl openssl)

LIBS = -shared \
       -L$(SDK_HOME)/lib \
       -L$(LO_LIB_HOME) \
       $(shell pkg-config --libs libcurl openssl) \
       -luno_sal -luno_cppu -luno_cppuhelpergcc3

.PHONY: all clean extension build-linux build-windows build-macosx install

all: extension

# Create extension structure
$(EXTENSION_DIR):
	mkdir -p $(EXTENSION_DIR)/META-INF
	mkdir -p $(LINUX_X86_DIR) $(LINUX_X64_DIR) $(WINDOWS_DIR) $(MACOSX_DIR)

# Copy extension files
extension-files: 
	mkdir -p $(EXTENSION_DIR)/META-INF $(EXTENSION_DIR)/images
	cp META-INF/manifest.xml $(EXTENSION_DIR)/META-INF/
	cp description.xml $(EXTENSION_DIR)/
	cp SolidProviderConfiguration.xcu $(EXTENSION_DIR)/
	cp package-description-en.txt $(EXTENSION_DIR)/
	cp -r images/* $(EXTENSION_DIR)/images/
	cp $(SRC_DIR)/ucpsolid.component $(EXTENSION_DIR)/

# Build Linux x86_64 binary
build-linux: $(EXTENSION_DIR)
	@echo "Building Solid UCP with DPoP authentication..."
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(CXX_SOURCES) $(LIBS) -o $(LINUX_X64_DIR)/ucpsolid.uno.so
	@echo "Built ucpsolid.uno.so with your DPoP implementation"

# Note: Cross-compilation for other platforms would require appropriate toolchains
build-windows:
	@echo "Windows build requires cross-compilation setup"
	@echo "Place ucpsolid.uno.dll in $(WINDOWS_DIR)/"

build-macosx:
	@echo "macOS build requires cross-compilation setup"
	@echo "Place ucpsolid.uno.dylib in $(MACOSX_DIR)/"

# Create the .oxt file
extension: build-linux extension-files
	cd $(EXTENSION_DIR) && zip -r ../../$(OXT_FILE) .

# Install extension to LibreOffice
install: extension
	unopkg add --force $(OXT_FILE)

# Uninstall extension
uninstall:
	unopkg remove com.sun.star.ucb.SolidContentProvider

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OXT_FILE)

# Development helpers
list-extensions:
	unopkg list

check-syntax:
	$(CXX) -fsyntax-only $(CXXFLAGS) $(INCLUDES) $(CXX_SOURCES)

# Quick build for development (Linux only)
dev: clean build-linux extension-files extension install

help:
	@echo "Available targets:"
	@echo "  all          - Build extension (default)"
	@echo "  extension    - Create .oxt file"
	@echo "  build-linux  - Build Linux binary"
	@echo "  install      - Install extension to LibreOffice"
	@echo "  uninstall    - Remove extension from LibreOffice"
	@echo "  clean        - Remove build artifacts"
	@echo "  dev          - Quick development build and install"
	@echo "  help         - Show this help"