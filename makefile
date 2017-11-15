CC = g++
BINDIR = ./bin
BUILDIR = ./build
SRCDIR = ./src
INCDIR = ./include
OBJECTS = $(BUILDIR)/CMatrixh.o $(BUILDIR)/CMatrix.o $(BUILDIR)/main.o 
CFLAGS = -Wall -I$(INCDIR)

all: $(BINDIR)/CMatrix

$(BINDIR)/CMatrix: $(OBJECTS) 
	$(CC) $(OBJECTS) -o $(BINDIR)/CMatrix

$(BUILDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/CMatrix.cpp $(INCDIR)/CMatrix.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.cpp

$(BUILDIR)/CMatrix.o: $(SRCDIR)/CMatrix.cpp $(INCDIR)/CMatrix.h
	$(CC) $(CFLAGS) -c $(SRCDIR)/CMatrix.cpp

$(BUILDIR)/CMatrixh.o: $(INCDIR)/CMatrix.h
	$(CC) $(CFLAGS) -c $(INCDIR)/CMatrix.h

