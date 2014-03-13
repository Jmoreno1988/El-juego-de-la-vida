/***
   * El juego de la vida (John Conway, 1970)
   *
   * Reglas:
   *   1) Las células sólo pueden tomar los valores 0 (muerta) o 1 (viva) (en mi caso '-' (muerta) y 'X' (viva)). 
   *   2) Una célula muerta renace si tiene tres (ni más ni menos) vecinas vivas. En caso contrario se queda muerta.
   *   3) Una célula viva muere si no hay un mínimo de dos y un máximo de tres células vivas en su entorno. En caso contrario se queda viva.
   *
   * Mas info: http://www.enriquegracian.com/articulos/el-juego-de-la-vida
   *
   ***/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define filas 50
#define columnas 100;
#define tiempo_espera 0.9;


int comprobar_celda(int matriz[][100], int i, int a){	
	static int celulas_vivas = 0;
			celulas_vivas = 0;
    		if(matriz[i-1][a-1] == 'X')
            celulas_vivas += 1;
         if(matriz[i-1][a] == 'X')
            celulas_vivas += 1;
         if(matriz[i-1][a+1] == 'X')
            celulas_vivas += 1;
         if(matriz[i][a-1] == 'X')
            celulas_vivas += 1;
         if(matriz[i][a+1] == 'X')
            celulas_vivas += 1; 
         if(matriz[i+1][a-1] == 'X')
            celulas_vivas += 1;
         if(matriz[i+1][a] == 'X')
            celulas_vivas += 1;
         if(matriz[i+1][a+1] == 'X')
            celulas_vivas += 1;
	
	return celulas_vivas;
}

int main(){
	int matriz [50][100];	
	bool esta_viva = false;
	int num_generaciones = 0;

	//Rellenar matriz
   for(int i=0; i<50; i++){
      for(int a=0; a<100; a++){
         matriz[i][a] = ' ';
      }
 	} 

	//Generar X celulas vivas
/*
		matriz[15][15] = 'X';
		matriz[15][16] = 'X';
		matriz[15][17] = 'X';
*/
	srand(time(NULL));
	for(int i=0; i<50; i++){
   	for(int a=0; a<100; a++){
			if(rand()%15 == 0)			
				matriz[i][a] = 'X';
			else
				matriz[i][a] = ' ';
		}
	}

	while(1){
		usleep(200000);
		system("clear");
		num_generaciones++;
	//Comprobar celda a celda
		for(int i=0; i<50; i++){
      	for(int a=0; a<100; a++){
				if(comprobar_celda(matriz, i, a) == 3){
					matriz[i][a] = 'X';
				}
					if(comprobar_celda(matriz, i, a)<2 || comprobar_celda(matriz, i, a)>3){
						matriz[i][a] = ' ';
					}	
				
      	}
   	}
		//Realizar cambios   

		//Pintar matriz   
   	for(int i=0; i<50; i++){
      	for(int a=0; a<100; a++){
         	printf("%c", matriz[i][a]);
      	}
      	printf("\n");
   	}
		printf("\tNumero de generaciones: %i \n\n", num_generaciones);
	}

}
