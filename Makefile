CXX=g++
OBJ=sorts.cpp sorter.cpp
CXXFLAGS=

all: $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o sorter
	chmod +x sorter

debug: CXXFLAGS=-g
debug: $(OBJ)
	echo "debug compile..."
	$(CXX) $(CXXFLAGS) $^ -o sorter
	chmod +x sorter

clean :
	rm *.o *.c sorter

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@