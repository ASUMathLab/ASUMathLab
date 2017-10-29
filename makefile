CC = g++
CFLAGS = -c -Wall -I$(INCDIR)/
BINDIR = ./bin
BUILDIR = ./build
SRCDIR = ./src
INCDIR = ./include
OBJECTS = $(BUILDIR)/main.o $(BUILDIR)/CMatrix.o $(BUILDIR)/CMatrix.h 

all: $(BINDIR)/CMatrix

$(BINDIR)/CMatrix: $(OBJECTS) 
	$(CC) $(OBJECTS) -o CMatrix

$(BUILDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp

$(BUILDIR)/CMatrix.o: $(SRCDIR)/CMatrix.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/CMatrix.cpp


$(BUILDIR)/CMatrixh.o: $(INCDIR)/CMatrix.h
	$(CC) $(CFLAGS) $(INCDIR)/CMatrix.h

.PHONY: clean
clean: 
	rm -f $(BUILDIR)/*.o $(BINDIR)/CMatrix
