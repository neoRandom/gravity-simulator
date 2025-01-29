default:
	g++ ./core/*.cpp -o main.out -O3 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

windows:
	g++ ./core/*.cpp -o main -O3 -Wall -Wno-missing-braces -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
