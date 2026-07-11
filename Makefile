CXX := g++
OUTPUT := dice-problem-simulator

CXX_FLAGS := -o3 -std=c++17 -Wall

SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp, build/%.o, $(SRC_FILES))


all:$(OUTPUT)

$(OUTPUT):$(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(LDFLAGS) -o ./build/$@

$(OBJ_FILES):$(SRC_FILES)
	$(CXX) -c $(CXX_FLAGS) $(SRC_FILES) -o $@

clean:
	rm -f $(OBJ_FILES) ./build/dice-problem-simulator

run: $(OUTPUT)
	cd build && ./dice-problem-simulator && cd ..
