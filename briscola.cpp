//gioco di briscola 
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
int mazzo[40];
int tavolo[4];
int mazzog1[40];
int mazzog2[40];
int manog1[3];
int manog2[3];
int manog3[3];
int manog4[3];
int posizionemazzo = 0;
int toccaa=0;

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

void dailecarte(){
	faiilmazzo();
	posizionemazzo=0;
	for(int i=0;i<3;i++){
		manog1[i]=mazzo[posizionemazzo];
		posizionemazzo= posizionemazzo+1;
		manog2[i]=mazzo[posizionemazzo];
		posizionemazzo= posizionemazzo+1;
		manog3[i]=mazzo[posizionemazzo];
		posizionemazzo= posizionemazzo+1;
		manog4[i]=mazzo[posizionemazzo];
		posizionemazzo= posizionemazzo+1;
	}
	
	


	
}



int main(){
	

	system("PAUSE");
}
