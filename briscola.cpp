//gioco di briscola 
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
int mazzo[40];


void faiilmazzo(){
	

	for (int i = 0; i < 40; i++) {     // fill array
    mazzo[i] = i+1;
    //printf("%d,", mazzo[i]);
	}


	for (int i = 0; i < 40; i++) {    // shuffle array
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
