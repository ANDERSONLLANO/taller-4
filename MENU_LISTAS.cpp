#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
	int dato;
	nodo *next;
	nodo *after;
};
nodo* first = NULL;
nodo* end = NULL;

// FUNCIONES LISTA SIMPLE

void mainone();
void InsertarNodoLSE();
void BuscarNodoLSE();
void DesplegarListaLSE();
void ModificarNodoLSE();
void EliminarNodoLSE();
void OrdenarDatosLSE();

//FUNCIONES LISTA DOBLE

void maintwo();
void InsertarNodoLDE();
void DesplegarListaFELDE();
void DesplegarListaEFLDE();
void BuscarNodoLDE();
void ModificarNodoLDE();
void EliminarNodoLDE();

//FUNCIONES LISTA CIRCULAR

void mainthree( ) ;
void InsertarNodoLC();
void listarcircularLC();
void BuscarNodoLC();
void ModificarNodoLC();
void EliminarNodoLC();


int main() {
	int opcion=0;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|            *[  MENU DE LISTAS Y ARBOLES  ]*                 |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|                                                             |");
		printf("\n|  1. LISTA SIMPLEMENTE ENLAZADA  |  4.ARBOL                  |");
		printf("\n|  2. LISTA DOBLEMENTE ENLAZADA   |  5.JUEGO JOSEPHUS         |");
		printf("\n|  3. LISTA CIRCULAR SIMPLE       |  0.salir                  |");
		printf("\n|                                                             |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
				mainone();
				break;
			   }
			   case 2:{
			    maintwo();
				break;
			   }
			   case 3:{
			    mainthree();
				break;
			   }
			   case 4:{
			    //menufour();
				break;
			   }
			   case 5:{
			   	//juegojosephus();
				break;
			   }
				case 0:{
					exit(0);
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}	
	}while(opcion!=0);

	system("pause");
	return 0;
}


//  MENU LISTA SIMPLEMENTE ENLAZADA

void mainone() {
	int opcion=0;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|            *[  MENU LISTA SIMPLEMENTE ENLAZADA  ]*          |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|  1. Insertar                    |  5.Eliminar               |");
		printf("\n|  2. Buscar                      |  6.ordenardatos           |");
		printf("\n|  3. listar                      |  0.atras                  |");
		printf("\n|  4. Modidficar                  |                           |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
			    InsertarNodoLSE();
				break;
			   }
			   case 2:{
			    BuscarNodoLSE();
				break;
			   }
			   case 3:{
			    DesplegarListaLSE();
				break;
			   }
			   case 4:{
			    ModificarNodoLSE();
				break;
			   }
			   case 5:{
			   	EliminarNodoLSE();
				break;
			   }
			   case 6:{
			    //OrdenarDatos();
				break;
		    	}
				case 0:{
					printf("\n------------------------- MENU PRINCIPAL -----------------------------\n");
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}	
	}while(opcion!=0);
	system("pause");
}


// first= 7      end= 9    nuevo= 9
//lista= 7,  5 ,2 , 9 , NULL


void InsertarNodoLSE(){
	int cant,i;
	printf("Ingrese la cantidad de valores para la lista: \n");
	scanf("\n %d",&cant);
	
	for (i=0;i<=cant;i++){
	    printf("ingrese el valor deseado:");
	    nodo *nuevo= (nodo*)malloc(sizeof(nodo));
	    scanf("%d",&nuevo -> dato);
	    if(first == NULL ){
		   first = nuevo;
		   first -> next = NULL;
		   end = nuevo;
     	}else{
		   end -> next = nuevo;
		   nuevo -> next = NULL;
	       end = nuevo;
    }
	}
	 printf("\n valores ingresados exitosamente \n");
}



void insertelementLSE(nodo *&inicio, nodo *&fin, int n){
	nodo *nuevo=(nodo *)malloc(sizeof(nodo));
	nodo *aux = inicio, *aux2 = NULL;

	if(inicio==aux){
		inicio = nuevo;
		nuevo-> after = NULL;
	}else{
		aux2 -> next = nuevo;
		nuevo -> after = aux2;
	}
	nuevo -> next = aux;
	aux -> after = nuevo;
	if( nuevo -> next == NULL){
		fin = nuevo;
	}
}



//first = 9   end =9   nuevo = 9  update=7   gotin=2   encontrado =0

void BuscarNodoLSE(){
	nodo* update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a buscar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf(" el nodo con el dato (%d) fue encontrado", nodogotin);
				encontrado = 1;
			}

			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el dato no fue encontrado");
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}


void DesplegarListaLSE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	if(first != NULL){
		while(update != NULL){
			printf("\n %d \n", update -> dato);
			update = update -> next;
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}

void ModificarNodoLSE(){
	nodo* update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0,change;
	printf("Ingrese el dato del nodo a buscar para modificar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf(" el nodo con el dato (%d) fue encontrado \n", nodogotin);
				printf("\n ingrese el nuevo dato para el nodo: ");
				scanf("%d",&change);
				update -> dato = change;
				printf("nodo modificado");
				encontrado = 1;
			}

			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el nodo no fue encontrado");
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}

void EliminarNodoLSE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	nodo *after = (nodo*)malloc(sizeof(nodo));
	after = NULL;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a buscar para eliminar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
			   if(update == first){
			   	  first = first -> next;
			   }else if(update == end){
			   	  after -> next = NULL ;
			   	  end = after;
			   }else{
			   	   after -> next = update -> next;
			   }
			   printf("\n el dato (%d) fue encontrado y eliminado exitosamente \n",nodogotin);
				encontrado = 1;
			}
            after = update;
			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el dato no fue encontrado");
		}else{
			free(after);
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}


//MENU DOBLEMENTE ENLAZADA

void maintwo() {
	int opcion=0;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|            *[  MENU LISTA DOBLEMENTE ENLAZADA  ]*          |");
		printf("\n|------------------------------------------------------------|");
		printf("\n|  1. Insertar                    |  5. Modidficar           |");
		printf("\n|  2. Buscar                      |  6.Eliminar              |");
		printf("\n|  3. listar de primero a ultimo  |  0.atras                |");
		printf("\n|  4. listar de ultimo a primero  |                          |");
		printf("\n|------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
				InsertarNodoLDE();
				break;
			   }
			   case 2:{
			   BuscarNodoLDE();
				break;
			   }
			   case 3:{
			    DesplegarListaFELDE();
				break;
			   }
			   case 4:{
			    DesplegarListaEFLDE();;
				break;
			   }
			   case 5:{
			   ModificarNodoLDE();
				break;
			   }
			   case 6:{
			    EliminarNodoLDE();
				break;
		    	}
				case 0:{
					printf("\n------------------------- MENU PRINCIPAL -----------------------------\n");
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}	
	}while(opcion!=0);
	system("pause");
}

//23, 12, 2, 9
//first= 23   end=12     nuevo=2
//   null    <-23->   <-12->  <-2->   <-9 ->  null

void InsertarNodoLDE(){
	int cant,i;
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese la cantidad de valores para la lista: \n");
	scanf("\n %d",&cant);
	
	for (i=0;i<=cant;i++){
	printf(" Ingrese el dato deseado: ");
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	scanf("%d",&nuevo -> dato);
	
	if(first == NULL){
		first = nuevo;
		first -> next = NULL;
		first -> after = NULL;
		end = first;
	}else{
		end -> next = nuevo;
		nuevo -> next = NULL;
		nuevo -> after = end;
		end = nuevo;
	}
}
	printf("\n nodos ingresados exitosamente \n");
}

void DesplegarListaFELDE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	if(first != NULL){
		while(update != NULL){
			printf("\n %d",update -> dato);
			update = update -> next;
		}
	}else{
		printf("\n la lista esta vacia ");
	}
}

////23, 12, 2, 9
//first= 23   end=12     nuevo=2
//   null    <-23->   <-12->  <-2->   <-9 ->  null    update=9

void DesplegarListaEFLDE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = end;
	if(first != NULL){
		while(update != NULL){
			printf("\n %d",update -> dato);
			update = update -> after;
		}
	}else{
		printf("\n la lista esta vacia ");
	}
	
}

void BuscarNodoLDE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a Buscar : ");
	scanf("%d",&nodogotin);
	
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf("\n el nodo con el dato (%d) fue encontrado \n", nodogotin);
				encontrado = 1;
			}
			update = update -> next;
		}
		if(encontrado == 0){
			printf("\n nodo no encontrado \n");
		}
	}else{
		printf("\n la lista esta vacia ");
	}
}

void ModificarNodoLDE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a Buscar para modificar: ");
	scanf("%d",&nodogotin);
	
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf("Ingrese un nuevo dato para el nodo: ");
				scanf("%d",&update -> dato);
				printf("\n el nodo con el dato (%d) fue modificado \n", nodogotin);
				encontrado = 1;
			}
			update = update -> next;
		}
		if(encontrado == 0){
			printf("\n nodo no encontrado \n");
		}
	}else{
		printf("\n la lista esta vacia ");
	}
}


void EliminarNodoLDE(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	nodo *anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a Buscar para eliminar: ");
	scanf("%d",&nodogotin);
	
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				
				if(update == first){
					first = first -> next;
					first -> after = NULL;
				}else if(update == end){
					anterior -> next = NULL;
					end = anterior;
				}else{
					anterior -> next = update -> next;
					update -> next -> after = anterior; 
				}
				printf("\n el nodo con el dato (%d) fue eliminado \n", nodogotin);
				encontrado = 1;
			}
			anterior = update;
			update = update -> next;
		}
		if(encontrado == 0){
			printf("\n nodo no encontrado \n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n la lista esta vacia ");
	}
}


// MENU LISTA CIRCULAR

void mainthree( ) {
		int opcion=0;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|                    *[  MENU LISTA CIRCULAR  ]*              |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|  1. Insertar                    |  5.Eliminar               |");
		printf("\n|  2. Buscar                      |  6.ordenardatos           |");
		printf("\n|  3. listar                      |  0.atras                 |");
		printf("\n|  4. Modidficar                  |                           |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
				InsertarNodoLC();
				break;
			   }
			   case 2:{
			    BuscarNodoLC();
				break;
			   }
			   case 3:{
			   listarcircularLC();
				break;
			   }
			   case 4:{
			    ModificarNodoLC();
				break;
			   }
			   case 5:{
			  EliminarNodoLC();
				break;
			   }
			   case 6:{
			    //OrdenarDatos();
				break;
		    	}
				case 0:{
						printf("\n------------------------- MENU PRINCIPAL -----------------------------\n");
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}	
	}while(opcion!=0);

	system("pause");
}

// first = null        end=   null              nuevo=12          12,24,36
//                        12->first

void InsertarNodoLC(){
	int cant,i;
	printf("Ingrese la cantidad de valores para la lista: \n");
	scanf("\n %d",&cant);
	
	for(i=0;i<=cant;i++){
		nodo *nuevo =(nodo *)malloc(sizeof(nodo));
	    printf(" ingrese el dato del nuevo nodo ");
	    scanf("%d",&nuevo -> dato);
	  if(first == NULL){
		   first = nuevo;
		   first -> next = first;
		   end = first; 
	   }else{
		   end -> next = nuevo;
		   nuevo -> next= first;
	       end = nuevo; 
	   }
	}
	printf("\n valores ingresados exitosamente \n");

}

// first=null    end = 12    nuevo= 12     12,24,36
//               12 -> first

void BuscarNodoLC(){
	nodo* update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a buscar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf(" el nodo con el dato (%d) fue encontrado", nodogotin);
				encontrado = 1;
			}

			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el dato no fue encontrado");
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}


void listarcircularLC(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	if(first != NULL){
		do{
		    printf("\n %d \n", update -> dato);
			update = update -> next;
		}while(update != first);	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}


void ModificarNodoLC(){
	nodo* update = (nodo*)malloc(sizeof(nodo));
	update = first;
	int nodogotin = 0, encontrado = 0,change;
	printf("Ingrese el dato del nodo a buscar para modificar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
				printf(" el nodo con el dato (%d) fue encontrado \n", nodogotin);
				printf("\n ingrese el nuevo dato para el nodo: ");
				scanf("%d",&change);
				update -> dato = change;
				printf("nodo modificado");
				encontrado = 1;
			}

			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el nodo no fue encontrado");
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}

void EliminarNodoLC(){
	nodo *update = (nodo*)malloc(sizeof(nodo));
	update = first;
	nodo *after = (nodo*)malloc(sizeof(nodo));
	after = NULL;
	int nodogotin = 0, encontrado = 0;
	printf("Ingrese el dato del nodo a buscar para eliminar: ");
	scanf("\n %d",&nodogotin);
	if(first != NULL){
		while(update != NULL && encontrado !=1){
			if(update -> dato == nodogotin){
			   if(update == first){
			   	  first = first -> next;
			   }else if(update == end){
			   	  after -> next = NULL ;
			   	  end = after;
			   }else{
			   	   after -> next = update -> next;
			   }
			   printf("\n el dato (%d) fue encontrado y eliminado exitosamente \n",nodogotin);
				encontrado = 1;
			}
            after = update;
			update = update -> next;
		}
		if(encontrado == 0 ){
			printf("\n el dato no fue encontrado");
		}else{
			free(after);
		}	
	}else{
		printf("\n la lista esta vacia \n ");
	}
}

/*   MENU ARBOLES

struct nodo{
	int dato;
	nodo *rigth;
	nodo *left;
	nodo *tree;
};


void insertarnodo(nodo *&tree, int n);
bool google(nodo *tree,int n);
void insertarnodo(nodo *&tree, int n);
void listarTree(nodo *tree, int cont);

int main() {
	int opcion=0;
	int n;
	do{
		system("color 0a");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|                       *[  MENU ARBOL  ]*                    |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n|  1. Insertar                    |  5.Eliminar               |");
		printf("\n|  2. Buscar                      |  6.ordenardatos           |");
		printf("\n|  3. listar                      |  0.salir                  |");
		printf("\n|  4. Modidficar                  |                           |");
		printf("\n|-------------------------------------------------------------|");
		printf("\n Seleccione la Opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:{
				insertarnodo(*&tree, n);
				break;
			   }
			   case 2:{
			    //BuscarNodo();
				break;
			   }
			   case 3:{
			    listarTree(nodo *&tree, int cont);
				break;
			   }
			   case 4:{
			   // ModificarNodo();
				break;
			   }
			   case 5:{
			   //	EliminarNodo();
				break;
			   }
			   case 6:{
			    //OrdenarDatos();
				break;
		    	}
				case 0:{
					exit(0);
					break;
				}
				default:{
					printf("\n Opcion no valida");
					break;
				}
		}	
	}while(opcion!=0);

	void insertarnodo(nodo *&tree, int n);
	return 0;
}

nodo *crearnodo(int n){
	nodo *nuevo = new nodo();
	nuevo -> dato = n;
	nuevo -> rigth = NULL;
	nuevo -> left = NULL;
	return nuevo;
}

bool google(nodo *tree,int n){
	if(tree == NULL){
		return false;
	}else if(tree -> dato = n){
		return true;
	}else if(n < tree -> dato){
		return google(tree -> left, n);
	}else{
		return google(tree -> rigth, n);
	}
}


void insertarnodo(nodo *&tree, int n){
	int cant,i;
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	printf("Ingrese la cantidad de valores para el arbol: \n");
	scanf("\n %d",&cant);
	
	for (i=0;i<=cant;i++){
	    printf("ingrese el valor deseado:");
	    nodo *nuevo= (nodo*)malloc(sizeof(nodo));
	    scanf("%d",&nuevo -> dato);
        if(tree == NULL){
        	nodo *nuevo =crearnodo(n);
        	tree = nuevo;
		}else{
			int valoraiz = tree -> dato;
			if(n < valoraiz){
				insertarnodo(tree -> left, n);
			}else{
				insertarnodo(tree -> rigth, n);
			}
		}
	}
	 printf("\n valores ingresados exitosamente \n");
}

void listarTree(nodo *tree, int cont){
	if(tree == NULL){
		return ;
	}else{
		listarTree(tree -> rigth, cont + 1);
		for(int i=0;i<cont;i++){
			printf(" %d ");
		}
		printf("\n %d \n", tree -> dato);
		listarTree( tree -> left, cont + 1);
	}
}

*/


