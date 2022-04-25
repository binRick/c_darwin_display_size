#!/usr/bin/env bash
set -eou pipefail

[[ -d bin ]] && rm -rf bin
mkdir -p bin

gcc src/test-display-size1.c \
	-framework ApplicationServices \
	-o bin/test-display-size1

gcc src/test-display-size-module1.c \
	-framework ApplicationServices \
	-o bin/test-display-module1
