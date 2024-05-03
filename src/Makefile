PROG=		checkrc
SRCS=		main.c \
		validation_utils.c
CSTD=		c17
CFLAGS+=	-I../include
CWARNFLAGS+=	-Wall -Werror -Wextra -pedantic
MAN=		# no manpage yet

# Installation directories
PREFIX?=	/usr/local
DIRS=		BINDIR
BINDIR=		${PREFIX}/bin

# Settings for installation, allow installing as user and create missing dirs
MK_INSTALL_AS_USER=	yes
beforeinstall:		installdirs

# Use exported object directory from top-level make
.OBJDIR: ${MAKEOBJDIR}

.include <bsd.prog.mk>
