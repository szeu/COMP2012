CPPFLAGS = -std=c++11

all: lab2.exe

lab2.exe: facility.o person.o bookingsystem.o main.cpp
	g++ -o $@ $(CPPFLAGS) facility.o person.o bookingsystem.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
