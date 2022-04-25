#!/usr/bin/env bash
set -eou pipefail

[[ -d deps ]] || clib i -c

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

gcc darwin-display-size.c \
	-framework ApplicationServices \
	-o bin/darwin-display-size
