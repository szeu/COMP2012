CPPFLAGS = -std=c++11
all: mainTips.exe mainInfo.exe mainReception.exe

mainTips.exe: gym.o seafront.o mainTips.cpp
	g++ -o $@ $(CPPFLAGS) gym.o seafront.o mainTips.cpp

mainInfo.exe: gym.o swimmingpool.o seafront.o mainInfo.cpp
	g++ -o $@ $(CPPFLAGS) gym.o swimmingpool.o seafront.o mainInfo.cpp

mainReception.exe: gym.o swimmingpool.o handbook.o seafront.o mainReception.cpp
	g++ -o $@ $(CPPFLAGS) gym.o swimmingpool.o handbook.o seafront.o mainReception.cpp

%.o: %.cpp
	g++ $(CPPFLAGS) -c $< -o $@ 

clean:
	rm -f *.o *.exe
# On Windows, use: del *.o *.exe
# On Linux or MacOS, use: rm -f *.o *.exe
