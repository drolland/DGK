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
	${OBJECTDIR}/d_error.o \
	${OBJECTDIR}/d_img.o \
	${OBJECTDIR}/d_list.o \
	${OBJECTDIR}/d_logger.o \
	${OBJECTDIR}/d_memory.o \
	${OBJECTDIR}/d_ml.o \
	${OBJECTDIR}/d_socket.o \
	${OBJECTDIR}/d_string.o \
	${OBJECTDIR}/d_time.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL2 -pthread -lm -ldl

${OBJECTDIR}/d_error.o: d_error.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_error.o d_error.c

${OBJECTDIR}/d_img.o: d_img.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_img.o d_img.c

${OBJECTDIR}/d_list.o: d_list.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_list.o d_list.c

${OBJECTDIR}/d_logger.o: d_logger.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_logger.o d_logger.c

${OBJECTDIR}/d_memory.o: d_memory.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_memory.o d_memory.c

${OBJECTDIR}/d_ml.o: d_ml.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_ml.o d_ml.c

${OBJECTDIR}/d_socket.o: d_socket.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_socket.o d_socket.c

${OBJECTDIR}/d_string.o: d_string.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_string.o d_string.c

${OBJECTDIR}/d_time.o: d_time.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -O -D_POSIX_C_SOURCE\ =\ 199309L -I/usr/include/SDL2 -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/d_time.o d_time.c

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

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dgk

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
