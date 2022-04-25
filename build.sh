#!/usr/bin/env bash
set -eou pipefail

[[ -d bin ]] && rm -rf bin
mkdir -p bin

gcc src/test-display-size.c \
	-framework ApplicationServices \
	-o bin/test-display-size

gcc src/test-display-size-module.c \
	-framework ApplicationServices \
	-o bin/test-display-module
