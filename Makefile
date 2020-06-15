all:
	g++ src/main.cpp src/sources/CMap.cpp src/sources/CEnemy.cpp src/sources/CRoute.cpp src/sources/CEnemiesGenerator.cpp src/sources/CLevel.cpp src/sources/CTower.cpp src/sources/CBullet.cpp -o game.exe -fsanitize=address -lncurses
