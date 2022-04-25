shfmt -w *.sh
uncrustify -c etc/uncrustify.cfg --replace src/*.c include/*.h tests/*.c *.c
find . -type f -name "*unc-backup*" | xargs -I % unlink %
