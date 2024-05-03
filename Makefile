SUBDIR=		src

# Force bsd.obj.mk to create an object dir for us before building
MAKEOBJDIR=	${.CURDIR}/obj
.MAKEOVERRIDES=	MAKEOBJDIR
.OBJDIR=	${MAKEOBJDIR}
all:		obj

.include <bsd.obj.mk>
