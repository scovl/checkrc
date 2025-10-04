CC?= cc
CPPFLAGS+= -I./include
CFLAGS?= -O2 -pipe -Wall -Wextra -Wshadow -Werror -std=c99

SRC= src/main.c src/validation_utils.c
TEST_SRC= tests/unit/test_validation.c src/validation_utils.c
TEST_BIN= tests/unit/test_validation

all: checkrc

checkrc: ${SRC}
	${CC} ${CPPFLAGS} ${CFLAGS} ${.ALLSRC} -o ${.TARGET}

${TEST_BIN}: ${TEST_SRC}
	${CC} ${CPPFLAGS} ${CFLAGS} ${.ALLSRC} -o ${.TARGET}

test: checkrc ${TEST_BIN}
	./${TEST_BIN}
	sh tests/integration/test_checkrc.sh

clean:
	rm -f checkrc ${TEST_BIN}

.PHONY: all test clean
