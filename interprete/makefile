make: 
	#gcc -std=c99 -c -o utils/datos.o utils/datos.c
	#g++ -std=c++0x -c -o estruct/pila.o estruct/pila.cpp
	#g++ -std=c++0x -c -o estruct/lista.o estruct/lista.cpp
	#g++ -std=c++0x -c -o estruct/cola.o estruct/cola.cpp
	#g++ -std=c++0x -c -o utils/cadenas.o utils/cadenas.cpp
	#g++ -std=c++0x -c -o estruct/estructuras.o estruct/estructuras.cpp
	g++ -std=c++0x -c -o interprete.o interprete.cpp
	g++ -o interprete.out estruct/pila.o estruct/lista.o estruct/cola.o utils/cadenas.o estruct/estructuras.o utils/datos.o interprete.o
debug:
	gcc -std=c99 -c -g -o utils/datos.o utils/datos.c
	g++ -std=c++0x -c -g -o estruct/pila.o estruct/pila.cpp
	g++ -std=c++0x -c -g -o estruct/lista.o estruct/lista.cpp
	g++ -std=c++0x -c -g -o estruct/cola.o estruct/cola.cpp
	g++ -std=c++0x -c -g -o utils/cadenas.o utils/cadenas.cpp
	g++ -std=c++0x -c -g -o estruct/estructuras.o estruct/estructuras.cpp
	g++ -std=c++0x -c -g -o interprete.o interprete.cpp
	g++ -g -o interprete.out estruct/pila.o estruct/lista.o estruct/cola.o utils/cadenas.o estruct/estructuras.o utils/datos.o interprete.o
	gdb interprete.out
clean:
	rm *.o 

