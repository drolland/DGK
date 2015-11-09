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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/derror.o \
	${OBJECTDIR}/dgkwindow.o \
	${OBJECTDIR}/dimg.o \
	${OBJECTDIR}/dlist.o \
	${OBJECTDIR}/dlogger.o \
	${OBJECTDIR}/dmemory.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL2 -pthread -lm

${OBJECTDIR}/derror.o: derror.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/derror.o derror.c

${OBJECTDIR}/dgkwindow.o: dgkwindow.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dgkwindow.o dgkwindow.c

${OBJECTDIR}/dimg.o: dimg.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dimg.o dimg.c

${OBJECTDIR}/dlist.o: dlist.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dlist.o dlist.c

${OBJECTDIR}/dlogger.o: dlogger.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dlogger.o dlogger.c

${OBJECTDIR}/dmemory.o: dmemory.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/dmemory.o dmemory.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE=200809L -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
