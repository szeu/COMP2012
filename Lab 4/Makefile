CPPFLAGS = -std=c++11

all: lab4.exe

lab4.exe: Product.o Toy.o Book.o main.cpp
	g++ -o $@ $(CPPFLAGS) Product.o Toy.o Book.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
