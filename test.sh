#!/bin/sh
set -eou pipefail

./build.sh
clear

cd bin

ansi --green --bg-black --italic "<test-display-size1> $(./test-display-size1)"

o="$(echo "\n$(./test-display-module1)")"
ansi --cyan --bg-black --italic "<test-display-module1> $o"
