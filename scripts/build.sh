#!/usr/bin/env bash
set -eou pipefail
cd $(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd ../

[[ -d deps ]] || clib i -c -q

[[ -d bin ]] && rm -rf bin
mkdir -p bin

gcc tests/test-display-size.c \
	-framework ApplicationServices \
	-o bin/test-display-size

gcc tests/test-display-size-module.c \
	-framework ApplicationServices \
	-o bin/test-display-module

gcc tests/display-size.c \
	-framework ApplicationServices \
	-o bin/display-size

gcc tests/darwin-display-size.c \
	-framework ApplicationServices \
	-o bin/darwin-display-size

gcc tests/darwin-display-size-init.c \
	-framework ApplicationServices \
	-o bin/darwin-display-size-init
