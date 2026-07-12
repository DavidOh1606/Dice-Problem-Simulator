CXX := g++
OUTPUT := dice-problem-simulator

CXX_FLAGS := -o3 -std=c++17 -Wall

SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp, build/%.o, $(SRC_FILES))
LDFLAGS := -o3
INCLUDES := -I./includes

all:$(OUTPUT)

$(OUTPUT):$(OBJ_FILES) Makefile
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./build/$@ 

./build/%.o: ./src/%.cpp
	$(CXX) -c $(CXX_FLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ_FILES) ./build/dice-problem-simulator

run: $(OUTPUT)
	cd build && ./dice-problem-simulator && cd ..
