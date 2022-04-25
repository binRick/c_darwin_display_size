#!/bin/sh
set -eou pipefail

./build.sh
clear

cd bin

ansi --green --bg-black --italic "<test-display-size> $(./test-display-size)"

o="$(echo "\n$(./test-display-module)")"
ansi --cyan --bg-black --italic "<test-display-module> $o"
