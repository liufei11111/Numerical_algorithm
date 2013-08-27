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
objects = main.o RandomEngin.o  IntegrateCube.o ParkMiller.o Random2.o Arrays.o ParkMiller.o Normals.o 
#$(objects): Matrix.h  Allocate.h See_matrix.h Strassen.h
.PHONY: default
default: $(executables) 
$(executables): main.o RandomEngin.o IntegrateCube.o Arrays.o ParkMiller.o Random2.o Normals.o 
Arrays.o: Arrays.h

.PHONY: run
run: default 
	./main 

main.o:  RandomEngin.h IntegrateCube.h

RandomEngin.o: RandomEngin.h ParkMiller.h

IntegrateCube.o: RandomEngin.h IntegrateCube.h
ParkMiller.o: Random2.h ParkMiller.h
Random2.o: Arrays.h Random2.h Normals.h
Normals.o: Normals.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
