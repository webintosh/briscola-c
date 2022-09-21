//gioco di briscola 
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
int mazzo[40];

int mazzog1[40];
int mazzog2[40];

void inizializzagiocatori{
	//svuoto i mazzi di guadagno dei giocatori
	for (int i = 0; i < 40; i++) {    
    mazzog1[i] = 0;

	}
	for (int i = 0; i < 40; i++) {    
    mazzog2[i] = 0;

	}

}


void faiilmazzo(){
	//riempio e poi randomizzo le posizioni del mazzo

	for (int i = 0; i < 40; i++) {    
    mazzo[i] = i+1;
    //printf("%d,", mazzo[i]);
	}


	for (int i = 0; i < 40; i++) {   
    	int temp = mazzo[i];
    	int randomIndex = rand() % 40;

    	mazzo[i]           = mazzo[randomIndex];
    	mazzo[randomIndex] = temp;
	}
		
	
}



int main(){
	printf("prima di random\n");
	for (int i = 0; i < 40; i++) {
	printf("%d,", mazzo[i]);}
	faiilmazzo();
	printf("\ndopo il mazzo\n");
	for (int i = 0; i < 40; i++) {
	printf("%d,", mazzo[i]);}
	system("PAUSE");
}
