CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = idb
SRC = src/main.cpp src/storage.cpp src/schema_manager.cpp src/query_processor.cpp
INC = -Iinclude

all:
	$(CXX) $(CXXFLAGS) $(SRC) $(INC) -o $(TARGET)

clean:
	rm -f $(TARGET)
