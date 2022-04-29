CPPFLAGS = -std=c++11

all: lab5.exe

lab5.exe: Toy.o Book.o main.cpp
	g++ -o $@ $(CPPFLAGS) Toy.o Book.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe