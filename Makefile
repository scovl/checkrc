CC ?= cc
CFLAGS ?= -O2 -pipe -Wall -Wextra -Wshadow -Werror -std=c99 -I./include

SRC = src/main.c src/validation_utils.c
TEST_SRC = tests/unit/test_validation.c src/validation_utils.c
TEST_BIN = tests/unit/test_validation

all: checkrc

checkrc: $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_BIN): $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@

test: checkrc $(TEST_BIN)
	./$(TEST_BIN)
	sh tests/integration/test_checkrc.sh

clean:
	rm -f checkrc $(TEST_BIN)

.PHONY: all test clean
