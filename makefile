CC = gcc
CXX = g++
INCLUDE_FLAGS = '-I inc'
CFLAGS = '-Wall', '-Wextra' , '-fdiagnostics-format=json' 
LINKER_FLAGS = -lpthread 
SOURCES_C=$(wildcard *.c)
SOURCES_CPP=$(wildcard *.cpp)

test1: 
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CC)',  $(CFLAGS), $(INCLUDE_FLAGS), '$(SOURCES_C)']; format_gcc_output(command)"
test2:
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CXX)',  $(CFLAGS), $(INCLUDE_FLAGS), '$(SOURCES_CPP)']; format_gcc_output(command)"
all:
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CC)',  $(CFLAGS), $(INCLUDE_FLAGS), '$(SOURCES_C)']; format_gcc_output(command)"	
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CXX)',  $(CFLAGS), $(INCLUDE_FLAGS), '$(SOURCES_CPP)']; format_gcc_output(command)"

clean:
	rm test1
