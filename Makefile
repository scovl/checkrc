CC=cc
CFLAGS=-O2 -pipe -Wshadow -Werror -I./include

all: checkrc

checkrc:
	$(CC) $(CFLAGS) src/main.c src/validation_utils.c -o checkrc

test: checkrc
	$(CC) $(CFLAGS) -o tests/unit/test_validation tests/unit/test_validation.c src/validation_utils.c
	./tests/unit/test_validation
	sh tests/integration/test_checkrc.sh

clean:
	rm -f checkrc tests/unit/test_validation

.PHONY: all test clean
