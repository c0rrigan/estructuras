make: 
	rm datos.o pila.o lista.o cola.o interprete.o  
	gcc -std=c99 -c -o datos.o datos.c
	g++ -std=c++0x -c -o pila.o pila.cpp
	g++ -std=c++0x -c -o lista.o lista.cpp
	g++ -std=c++0x -c -o cola.o cola.cpp
	g++ -std=c++0x -c -o interprete.o interprete.cpp
	g++ -o interprete pila.o lista.o cola.o datos.o interprete.o
clean:
	rm *.o 

