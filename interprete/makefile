make: 
	gcc -std=c99 -c -o datos.o datos.c
	g++ -std=c++0x -c -o pila.o pila.cpp
	g++ -std=c++0x -c -o lista.o lista.cpp
	g++ -std=c++0x -c -o cola.o cola.cpp
	g++ -std=c++0x -c -o cadenas.o cadenas.cpp
	g++ -std=c++0x -c -o interprete.o interprete.cpp
	g++ -o interprete pila.o lista.o cola.o cadenas.o datos.o interprete.o
debug:
	gcc -std=c99 -c -g -o datos.o datos.c
	g++ -std=c++0x -g -c -o pila.o pila.cpp
	g++ -std=c++0x -g -c -o lista.o lista.cpp
	g++ -std=c++0x -g -c -o cola.o cola.cpp
	g++ -std=c++0x -g -c -o cadenas.o cadenas.cpp
	g++ -std=c++0x -g -c -o interprete.o interprete.cpp
	g++ -g -o interprete pila.o lista.o cola.o cadenas.o datos.o interprete.o
	gdb interprete
clean:
	rm *.o 

