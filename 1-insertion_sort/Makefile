###CONFIG
CXX = g++
CXXFLAGS := -std=c++11
CPPFLAGS = -Wall -Wextra -pedantic -O2
INCLUDE = -I../dep/Catch/include
LIBDIR = 
LIBS = 
MAKE = mingw32-make

source := main

###END OF CONFIG

source := $(addsuffix .o, $(source))
source := $(addprefix src/, $(source))

CXXFLAGS := $(CXXFLAGS) $(INCLUDE) $(LIBDIR) $(LIBS)


all: clean main.exe

w: win-clean main.exe

main.exe: $(source)
	$(CXX) $^ $(CPPFLAGS) $(CXXFLAGS) -o $(addprefix bin/, $@) 
	
obj/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	
clean:
	cd src
	rm -rf *.o
	cd ..
	
win-clean:
	cd src
	del /S *.o
	cd ..
	
win-make: win-clean main.exe 
