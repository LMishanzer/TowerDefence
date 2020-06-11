all:
	g++ src/main.cpp src/CMap.cpp src/CEnemy.cpp src/CRoute.cpp src/CEnemiesGenerator.cpp src/CLevel.cpp -o game.exe -fsanitize=address
