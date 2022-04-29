CPPFLAGS = -std=c++11

all: pa1.exe

pa1.exe: test.o main.cpp
	g++ -o $@ $(CPPFLAGS) test.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe