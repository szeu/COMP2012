CPPFLAGS = -std=c++11

all: test1.exe test2.exe

test1.exe: BinarySearchTree.o Manager.o test1.cpp
	g++ -o $@ $(CPPFLAGS) BinarySearchTree.o Manager.o test1.cpp

test2.exe: BinarySearchTree.o Manager.o test2.cpp
	g++ -o $@ $(CPPFLAGS) BinarySearchTree.o Manager.o test2.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	del *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe