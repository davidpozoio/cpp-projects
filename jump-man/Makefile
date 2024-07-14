BUILD_DIR=./build
INCLUDE_DIR=./include

a.o: main.o
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/player.o $(BUILD_DIR)/utils.o -lncurses -o a.out

main.o: player.o utils.o
	g++ -L$(INCLUDE_DIR) -c main.cpp -lncurses -o $(BUILD_DIR)/main.o
player.o:
	g++ -L$(INCLUDE_DIR) -c $(INCLUDE_DIR)/player/player.cpp -o $(BUILD_DIR)/player.o
utils.o:
	g++ -L$(INCLUDE_DIR) -c $(INCLUDE_DIR)/utils/utils.cpp -o $(BUILD_DIR)/utils.o