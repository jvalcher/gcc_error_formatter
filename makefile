CC = gcc
CXX = g++
INCLUDE_FLAGS = -Itest_files/inc
CFLAGS = '-Wall', '-Wextra' , '-fdiagnostics-format=json'
LD_FLAGS = -lpthread
MAIN_C = test_files/test1.c
MAIN_CPP = test_files/test2.cpp
SOURCES_C=$(wildcard test_files/src/*.c)
SOURCES_CPP=$(wildcard test_files/src/*.cpp)

test1:
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CC)',  $(CFLAGS), '$(INCLUDE_FLAGS)', '$(SOURCES_C)', '$(MAIN_C)', '$(LD_FLAGS)']; format_gcc_output(command)"
	@mv a.out $@
test2:
	python -c "from format_gcc_output import format_gcc_output; command = ['$(CXX)',  $(CFLAGS), '$(INCLUDE_FLAGS)', '$(SOURCES_CPP)', '$(MAIN_CPP)', '$(LD_FLAGS)']; format_gcc_output(command)"
	@mv a.out $@

clean:
	rm test1 test2
