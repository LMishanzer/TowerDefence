all: compile

compile:
	g++ -Wall -pedantic src/main.cpp src/sources/CMap.cpp src/sources/CEnemy.cpp src/sources/CRoute.cpp src/sources/CEnemiesGenerator.cpp src/sources/CLevel.cpp src/sources/CTower.cpp src/sources/CBullet.cpp src/sources/CWallet.cpp src/sources/CCrazyEnemy.cpp -o leskimyk -fsanitize=address -lncurses

run:
	make compile
	./leskimyk

clean:
	rm -r doc leskimyk

doc:
	doxygen src/config
	mv html doc
