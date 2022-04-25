#!/bin/sh
set -eou pipefail

./build.sh
clear

cd bin

ansi --green --bg-black --italic "<test-display-size> $(./test-display-size)"

o="$(echo "\n$(./test-display-module)")"
ansi --cyan --bg-black --italic "<test-display-module> $o"

o="$(echo "\n$(./display-size)")"
ansi --red --bg-black --italic "<display-size> $o"

o="$(echo "\n$(./darwin-display-size)")"
ansi --blue --underline --bold --bg-black "<darwin-display-size> $o"
