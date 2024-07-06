CC = gcc
CXX = g++
INCLUDE_FLAGS = '-I inc'
CFLAGS = '-Wall', '-Wextra' , '-fdiagnostics-format=json' 
LINKER_FLAGS = -lpthread 
SOURCES=$(wildcard *.c)
SOURCES_CPP=$(wildcard *.cpp)

all: 
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CC)',  $(CFLAGS), $(INCLUDE_FLAGS), '$(SOURCES)']; format_gcc_output(command)"
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CXX)',  $(CFLAGS), $(INCLUDE_FLAGS), 'test2.cpp']; format_gcc_output(command)"	
	
clean:
	rm test1
