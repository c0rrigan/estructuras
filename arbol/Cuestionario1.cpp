#include <iostream>
#include <stdlib.h>
#include <string.h>

class variable{
	public:
		char area[4];
		int valor;
		variable *siguiente;
};

typedef variable *apu_variable;

class areas{
	public:
		apu_variable inicio, aux, tope;
		areas(){
			inicio = NULL;
			aux = NULL;
			tope = NULL;
		}
		void insertar_a(char *apu, int dato_ext);
		int buscar_a(char *apu);
		void mostrar(void);
		int contar(void);
		apu_variable x_dato(int pos_ext);
		void eliminar_a();
};

void areas::insertar_a(char *apu, int dato_ext){
	
	if(inicio == NULL){
		inicio = new(variable);
		strcpy(inicio->area, apu);
		inicio->valor = dato_ext;
		inicio->siguiente = NULL;
		tope = inicio;
		
		//--------------------------------------------------------------------
		aux = inicio;
		
		while(aux != NULL){
			printf("              %d   %s                ", aux->valor, aux->area);
			aux = aux->siguiente;
		}
		
		//-----------------------------------------------------------------------
		
	}
	else{
		
		if(areas::buscar_a(apu) != 0){
			aux = new(variable);
			strcpy(aux->area, apu);
			aux->valor = dato_ext;
			aux->siguiente = NULL;
			tope->siguiente = aux;
			tope = aux;
		}
		else{
			
			aux = inicio;
			
			while(aux != NULL){
				
				if(strcmp(aux->area,apu) == 0){
					aux->valor = aux->valor + dato_ext;
					break;
				}
				else{
					aux = aux->siguiente;
				}
				
			}
			
			//--------------------------------------------------------------------
			aux = inicio;
		
			while(aux != NULL){
				printf("              %d   %s                ", aux->valor, aux->area);
				aux = aux->siguiente;
			}
			//--------------------------------------------------------------------
			
		}
		
	}
	
}

int areas::buscar_a(char *apu){
	
	int cont = 0;
	
	aux = inicio;
	
	while(aux != NULL){
		
		if(strcmp(aux->area,apu) == 0){ // Si es 0 , son iguales
			return 0;
		}
		else{
			cont++;
			aux = aux->siguiente;
		}
		
	}
	
	return cont;
	
}

void areas::mostrar(void){
	
	if(inicio == NULL){
		printf("Lista vacia...\n");
	}
	else{
		
		aux = inicio;
		
		while(aux != NULL){
			printf("Valor: %d \nArea: %s \n\n", aux->valor, aux->area);
			aux = aux->siguiente;
		}
		
	}
	
}

int areas::contar(void){
	
	int cont = 0;
	
	aux = inicio;
	
	while(aux != NULL){
		cont++;
		aux = aux->siguiente;
	}
	
	return cont;
	
}

apu_variable areas::x_dato(int pos_ext){
	
	int cont = 1;
	aux = inicio;
	
	if(inicio == NULL){
		printf("No hay datos...");
	}
	else{
		
		while(aux != NULL){
			
			if(cont == pos_ext){
				return aux;
			}
			else{
				cont++;
				aux = aux->siguiente;
			}
			
		}
		
	}
	
}

void areas::eliminar_a(){
	
	while(inicio != NULL){
		aux = inicio;
		inicio = inicio->siguiente;
		delete(aux);
	}
	
}




class areas_cola{
	public:
		apu_variable tope_cola, aux_cola, inicio_cola;
		areas_cola(){
			tope_cola = NULL;
			aux_cola = NULL;
			inicio_cola = NULL;
		}
		void insertar(int valor_ext, char *apu);
		apu_variable mostrar(void);
		apu_variable extraer(void);
};

void areas_cola::insertar(int valor_ext, char *apu){
	
	if(tope_cola == NULL){
		tope_cola = new(variable);
		tope_cola->valor = valor_ext;
		strcpy(tope_cola->area, apu);
		tope_cola->siguiente = NULL;
		inicio_cola = tope_cola;
	}
	else{
		aux_cola = new(variable);
		aux_cola->valor = valor_ext;
		strcpy(aux_cola->area, apu);
		aux_cola->siguiente = NULL;
		inicio_cola->siguiente = aux_cola;
		inicio_cola = aux_cola;
	}
	
}

apu_variable areas_cola::mostrar(void){
	
	if(tope_cola == NULL){
		return NULL;
	}
	else{
		return tope_cola;
	}
	
}

apu_variable areas_cola::extraer(void){
	
	if(tope_cola != NULL){
		aux_cola = tope_cola;
		tope_cola = tope_cola->siguiente;
		delete(aux_cola);
	}
	else{
		return NULL;
	}
	
}


int main(){
	
	system("color 1b");
	
	int opc,
		valor,
		ng,
		mi,
		mg;
	char renglon[100],
		 aux[4],
		 *apu;
	FILE *archivo;
	areas lista_areas;
	areas_cola cola_areas;
	apu_variable aux_apu;
	
	archivo = fopen("Cuestionario1.csv", "r");
	
	if(archivo == NULL){
		printf("No se abrio el archivo: Cuestionario1.csv correctamente...\n");
	}
	else{
		
		while(fgets(renglon, 100, archivo)){
			
			apu = strtok(renglon, ",");
			
			printf("\n%s \n", apu);
			printf( "\t1. No Me Gusta\n"
					"\t2. Me es Indiferentes\n"
					"\t3. Me Gusta\n"
					"\tOpcion: ");
					
			apu = strtok(NULL, ",");
			ng = atoi(apu);
			apu = strtok(NULL, ",");
			mi = atoi(apu);
			apu = strtok(NULL, ",");
			mg = atoi(apu);
			apu = strtok(NULL, "\n");
			//falta para variable de que area es
			
			scanf("%d", &opc);
			
			switch(opc){
				
				case 1:
					lista_areas.insertar_a(apu, ng);
				break;
				
				
				case 2:
					lista_areas.insertar_a(apu, mi);
				break;
				
				
				case 3:
					lista_areas.insertar_a(apu, mg);
				break;
				
			}
			
		}
		
		// Este for pasa los datos de la lista a la cola
		for(int i=0; i<lista_areas.contar(); i++){
			aux_apu = lista_areas.x_dato(i);
			valor = aux_apu->valor;
			strcpy(aux,aux_apu->area);
			cola_areas.insertar(valor, aux);
		}
		
		
		
	}
	
	return 0;
}
