CPPFLAGS = -std=c++11
all: lab6.exe

lab6.exe: Book.o Toy.o main.cpp
	g++ -o $@ $(CPPFLAGS) Book.o Toy.o main.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -rf *.o *.exe

Toy.o : ProductVector.h Product.h
Book.o : ProductVector.h Product.h