CC  = g++
CXX = g++ 
# Comment out one of the following 2 lines to enable/disable BASIC4TRACE.
#INCLUDES = -DBASIC4TRACE
INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -lm
LDLIBS  = -g -lm

executables = main 
objects = main.o Allocate.o  Matrix.o See_matrix.o Strassen.o
#$(objects): Matrix.h  Allocate.h See_matrix.h Strassen.h
.PHONY: default
default: $(executables)
$(executables): main.o Strassen.o Matrix.o See_matrix.o Allocate.o 
.PHONY: run
run: default 
	./main


Strassen.o: Strassen.h
Matrix.o: Matrix.h Allocate.h


See_matrix.o: See_matrix.h
Allocate.o: Allocate.h
main.o: Strassen.h 


.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
