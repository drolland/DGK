#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/dgk_3dobject.o \
	${OBJECTDIR}/dgk_gl.o \
	${OBJECTDIR}/dgk_shader.o \
	${OBJECTDIR}/dgk_texture.o \
	${OBJECTDIR}/dgk_window.o \
	${OBJECTDIR}/glad.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../DLib/dist/Debug/GNU-Linux/libdlib.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk: ../DLib/dist/Debug/GNU-Linux/libdlib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL2 -pthread -lm -ldl

${OBJECTDIR}/dgk_3dobject.o: dgk_3dobject.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgk_3dobject.o dgk_3dobject.c

${OBJECTDIR}/dgk_gl.o: dgk_gl.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgk_gl.o dgk_gl.c

${OBJECTDIR}/dgk_shader.o: dgk_shader.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgk_shader.o dgk_shader.c

${OBJECTDIR}/dgk_texture.o: dgk_texture.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgk_texture.o dgk_texture.c

${OBJECTDIR}/dgk_window.o: dgk_window.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgk_window.o dgk_window.c

${OBJECTDIR}/glad.o: glad.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/glad.o glad.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:
	cd ../DLib && ${MAKE} -j -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

# Subprojects
.clean-subprojects:
	cd ../DLib && ${MAKE} -j -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
