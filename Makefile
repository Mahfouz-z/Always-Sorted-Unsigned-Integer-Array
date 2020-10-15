CXX=g++

all: sortedUIntArr.o main.o customInt.o
	$(CXX) -O0 -std=c++11 -ggdb -fno-elide-constructors -o main main.o sortedUIntArr.o customInt.o

main.o: main.cpp sortedUIntArr.h customInt.h
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o main.o main.cpp 


sortedUIntArr.o: sortedUIntArr.cpp sortedUIntArr.h customInt.h customInt.o
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o sortedUIntArr.o sortedUIntArr.cpp  

customInt.o: customInt.cpp customInt.h 
	$(CXX) -c -std=c++11 -ggdb -O0 -fno-elide-constructors -o customInt.o customInt.cpp  

clean:
	rm -rf main.o sortedUIntArr.o customInt.o main