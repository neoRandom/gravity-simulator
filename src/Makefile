CXX = g++
CXXFLAGS = -O3 -Wall -Wno-missing-braces -std=c++17 -I ./include/

RAYLIB_FLAGS = $(shell pkg-config --cflags --libs raylib)

default:
	g++ ./core/*.cpp -o main.out -O3 -I ./include/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wno-missing-braces

dynamic:
	g++ ./core/*.cpp -o main.out -O3 -I ./include/ -L ./lib/libraylib.so.5.5.0 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wno-missing-braces

windows:
	g++ ./core/*.cpp -o main     -O3 -I ./include/ -L ./lib/libraylib.a        -lraylib -lopengl32 -lgdi32 -lwinmm -Wall -Wno-missing-braces 

linux:
	$(CXX) $(CXXFLAGS) ./core/*.cpp -o main.out $(RAYLIB_FLAGS)
