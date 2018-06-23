# Makefile for creating the 'Kindergarten' program
CCC = g++
CXXFLAGS = -Wall -g -std=c++0x
CXXLINK = $(CCC)
OBJS = main.o Person.o Child.o Teacher.o Room.o Class.o Office.o
RM = rm -f

# Default target
all: Kindergarten

# Creating the executable
Kindergarten: $(OBJS)
	$(CXXLINK) -o Kindergarten $(OBJS)

# Creating object files using default rules
main.o: main.C Person.H Child.H
Person.o: Person.C Person.H
Child.o: Child.C Child.H
Teacher.o: Teacher.C Teacher.H 
Room.o: Room.C Room.H
Class.o: Class.C Class.H
Office.o: Office.C Office.H

# Cleaning old files before new make
clean:
	$(RM) Kindergarten *.o *.bak *~ "#"* core