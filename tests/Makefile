MAKEFILE=$(firstword ${MAKEFILE_LIST})
COMPILER?=~/.uecide/compilers/pic32-tools/bin/pic32-
BOARDS?=pic32/variants/Uno32/boards.txt
BOARD?=uno_pic32
CORE?=pic32/cores/pic32
MPIDEVER?=0

CC=${COMPILER}gcc
CXX=${COMPILER}g++
AR=${COMPILER}ar
BIN2HEX=${COMPILER}bin2hex

${BOARD}.ldcommon=chipKIT-application-COMMON.ld

include ${BOARDS}

COMMONFLAGS=-G1024 -g -O2 -w -fno-exceptions -ffunction-sections -fdata-sections -mno-smart-io -mdebugger -Wcast-align -fno-short-double -DF_CPU=${${BOARD}.build.f_cpu} -DARDUINO=160 -D${${BOARD}.board} -DMPIDEVER=${MPIDEVER} -mprocessor=${${BOARD}.build.mcu} -DMPIDE=160

ifndef SKETCH
$(error "SKETCH=..." not set)
endif

SKETCHFILE=$(notdir ${SKETCH})
SKETCHDIR=$(dir ${SKETCH})
SKETCHNAME=$(basename ${SKETCHFILE})
SKETCHTYPE=$(suffix ${SKETCHFILE})
SKETCHINOS=$(wildcard ${SKETCHDIR}/*.ino ${SKETCHDIR}/*.pde)
BOARDDIR=$(dir ${BOARDS})

CKLIBNAMES=$(notdir ${LIBRARIES})
CKLIBFILES=$(addprefix lib,$(addsuffix .a,${CKLIBNAMES}))
CKLIBS=$(addprefix -l,${CKLIBNAMES})

INCLUDES=-I. -I${CORE} -I${BOARDDIR} -I${SKETCHDIR}

ifdef LIBRARIES
CKINCLUDES=$(addprefix -I,${LIBRARIES})
INCLUDES+=${CKINCLUDES}
endif


vpath %.c ${BOARDDIR}
vpath %.cpp ${BOARDDIR}
vpath %.S ${BOARDDIR}

vpath %.c ${CORE}
vpath %.cpp ${CORE}
vpath %.S ${CORE}

vpath %.c ${SKETCHDIR}
vpath %.cpp ${SKETCHDIR}
vpath %.S ${SKETCHDIR}

ifdef LIBRARY
INCLUDES += -I${LIBRARY} -I${LIBRARY}/utility

LIBNAME=$(notdir ${LIBRARY})
LIBFILE=$(addprefix lib,$(addsuffix .a,${LIBNAME}))

LIBSFILES=$(wildcard ${LIBRARY}/*.S ${LIBRARY}/utility/*.S)
LIBCPPFILES=$(wildcard ${LIBRARY}/*.cpp ${LIBRARY}/utility/*.cpp)
LIBCFILES=$(wildcard ${LIBRARY}/*.c ${LIBRARY}/utility/*.c)

LIBBASE=$(notdir $(basename ${LIBSFILES} ${LIBCPPFILES} ${LIBCFILES}))
LIBOBJ=$(addsuffix .o,${LIBBASE})

vpath %.c ${LIBRARY}
vpath %.cpp ${LIBRARY}
vpath %.S ${LIBRARY}

vpath %.c ${LIBRARY}/utility
vpath %.cpp ${LIBRARY}/utility
vpath %.S ${LIBRARY}/utility

endif


CXXFLAGS=${COMMONFLAGS} -fno-exceptions ${INCLUDES}
CFLAGS=${COMMONFLAGS} ${INCLUDES}
ASFLAGS=-O2 -g1 -Wa,--gdwarf-2 -w ${COMMONFLAGS} ${INCLUDES}
LDFLAGS= -Os -Wl,--gc-sections,-Map,${SKETCHNAME}.map -mdebugger -mno-peripheral-libs -nostartfiles -T $(wildcard ${BOARDDIR}/${${BOARD}.ldscript} ${CORE}/${${BOARD}.ldscript}) -T $(wildcard ${BOARDDIR}/${${BOARD}.ldcommon} ${CORE}/${${BOARD}.ldcommon}) -w -mprocessor=${${BOARD}.build.mcu}

CORESFILES=$(wildcard ${CORE}/*.S)
CORECPPFILES=$(wildcard ${CORE}/*.cpp)
CORECFILES=$(wildcard ${CORE}/*.c)
COREBASE=$(notdir $(basename ${CORESFILES} ${CORECPPFILES} ${CORECFILES}))
COREOBJ=$(addsuffix .o,${COREBASE})

BOARDSFILES=$(wildcard ${BOARDDIR}/*.S)
BOARDCPPFILES=$(wildcard ${BOARDDIR}/*.cpp)
BOARDCFILES=$(wildcard ${BOARDDIR}/*.c)
BOARDBASE=$(notdir $(basename ${BOARDSFILES} ${BOARDCPPFILES} ${BOARDCFILES}))
BOARDOBJ=$(addsuffix .o,${BOARDBASE})

SKETCHSFILES=$(wildcard ${SKETCHDIR}/*.S)
SKETCHCPPFILES=$(wildcard ${SKETCHDIR}/*.cpp)
SKETCHCFILES=$(wildcard ${SKETCHDIR}/*.c)
SKETCHBASE=$(notdir $(basename ${SKETCHSFILES} ${SKETCHCPPFILES} ${SKETCHCFILES}))
SKETCHOBJ=$(addsuffix .o,${SKETCHBASE})




LIBS=-lcore ${CKLIBS}


${SKETCHNAME}.hex: ${SKETCHNAME}.elf
	${BIN2HEX} -a $<

${SKETCHNAME}.elf: libcore.a libs ${SKETCHNAME}.o ${SKETCHOBJ} ${BOARDOBJ}
	${CXX} ${LDFLAGS} -o $@ ${SKETCHNAME}.o ${SKETCHOBJ} ${BOARDOBJ} -L. -Wl,--start-group ${LIBS} -Wl,--end-group -lm

${SKETCHNAME}.cpp: ${SKETCH}
	echo "#include <Arduino.h>" > $@
	echo "#include <${SKETCHNAME}_proto.h>" >> $@
	cat "${SKETCH}" >> $@
	for FILE in ${SKETCHINOS}; do \
		if ! [ "$$FILE" -ef "${SKETCH}" ]; then \
			cat "$$FILE" >> $@; \
		fi; \
	done
	cproto -q -E 0 -O /dev/null ${INCLUDES} ${SKETCH} | grep -v '^__' > ${SKETCHNAME}_proto.h
	

libcore.a: ${COREOBJ}
	${AR} -rcs $@ $?
	
clean:
	rm -f ${SKETCHNAME}.cpp ${SKETCHNAME}.o ${SKETCHNAME}.elf ${SKETCHNAME}.hex ${SKETCHNAME}.map ${SKETCHOBJ}
	rm -f ${COREOBJ} libcore.a

.PHONY: libs compile-library

libs:
	for FILE in ${LIBRARIES}; do \
		${MAKE} -f "${MAKEFILE}" COMPILER="${COMPILER}" BOARDS="${BOARDS}" BOARD="${BOARD}" CORE="${CORE}" MPIDEVER="${MPIDEVER}" SKETCH="${SKETCH}" LIBRARY=$${FILE} compile-library; \
		${MAKE} -f "${MAKEFILE}" COMPILER="${COMPILER}" BOARDS="${BOARDS}" BOARD="${BOARD}" CORE="${CORE}" MPIDEVER="${MPIDEVER}" SKETCH="${SKETCH}" LIBRARY=$${FILE} clean-library; \
	done

compile-library: ${LIBOBJ}
	${AR} -rcs ${LIBFILE} ${LIBOBJ}

clean-library:
	rm -f ${LIBOBJ}
