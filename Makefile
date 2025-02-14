SUBDIR=		src

# Force bsd.obj.mk to create an object dir for us before building
MAKEOBJDIR=	${.CURDIR}/obj
.MAKEOVERRIDES=	MAKEOBJDIR
.OBJDIR=	${MAKEOBJDIR}
all:		obj

.include <bsd.obj.mk>

test: all
	$(CC) $(CFLAGS) -I./include -o tests/unit/test_validation tests/unit/test_validation.c src/validation_utils.c
	./tests/unit/test_validation
	sh tests/integration/test_checkrc.sh

.PHONY: test
