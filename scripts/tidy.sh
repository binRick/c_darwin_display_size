#!/bin/sh
set -eou pipefail
cd $(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

cd ../

shfmt -w scripts/*.sh
js-beautify -r clib.json
uncrustify -c etc/uncrustify.cfg --replace src/*.c include/*.h tests/*.c
find src include tests -type f -name "*unc-backup*" | xargs -I % unlink %
