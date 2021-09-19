#include <stdio.h>

int leer_palabra_por_teclado(char* buff,int longitud){
    char* funciono=fgets(buff,longitud,stdin);
    if(funciono !=NULL){
        return 0;
    }
    return 1;
}

void imprimir_estado(int longitud, char* incognita, int intentos){
	printf("\n");
    printf("Palabra secreta: %.*s\n", longitud, incognita);
    printf("Le quedan %d intentos\n", intentos);
    printf("Ingresar letra: ");
}



int main(){
	printf("Inicio del juego\n");
    int intentos=5;
    int victoria=0;

    char buffer[60];
    char palabra[4]="gato";
    char incognita[4]="____";
    int long_incognita=4;

    int encontro_letra=0;

    while (intentos != 0){
    	imprimir_estado(long_incognita, incognita, intentos);
        leer_palabra_por_teclado(buffer,60);
        //recorro cada letra del buffer
        for(int i=0; i<60; i++){
        	encontro_letra=0;
        	//encontre el fin de la palabra
        	if (buffer[i] == '\n'){
        		break;
        	}
        	//me quede sin intentos al poner 
        	//una palabra con mas letras que intentos
        	if (intentos == 0){
        		break;
        	}
        	//tengo intentos restantes
        	//chequea cada letra contra la incognita
        	for (int j=0; j<long_incognita; j++){
        		if (buffer[i] == palabra[j]){
        			incognita[j]=buffer[i];
        			encontro_letra=1;
        		}
        	}
        	//si la letra actual no aparece, resto intento
        	if (encontro_letra==0){
        		intentos--;
        	}
        	//puede que la letra actual complete la palabra
        	//chequeo de si todas las letras fueron descubiertas
        	int letras_restantes=0;
        	for (int l=0; l<long_incognita; l++){
        		if (incognita[l] == '_'){
        			letras_restantes=1;
        			break;
        		}
        	}
        	if (letras_restantes == 0){
        		victoria=1;
        		break;
        	}
        }
        if (victoria==1){
        	printf("Ganaste!!\n");
        	return 0;
        }
    }
    printf("Perdiste! La palabra secreta era %.*s\n",long_incognita,palabra);
	return 0;
}