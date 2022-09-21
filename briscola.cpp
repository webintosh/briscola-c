//gioco di briscola 
#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include "time.h"

#if defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows" // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
    #include <sys/param.h>
    #if defined(BSD)
        #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #endif
#elif defined(__hpux)
    #define PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
    #define PLATFORM_NAME "aix" // IBM AIX
#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_IPHONE == 1
        #define PLATFORM_NAME "ios" // Apple iOS
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_NAME "osx" // Apple OSX
    #endif
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME NULL
#endif






//facendo tutto globale e all'inizio non devo fare allocazioni strane poiché e tutto gestito automaticamente

int mazzo[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int tavolo[4]={0,0,0,0};
int mazzog1[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int mazzog1p=0;
int mazzog2[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int mazzog2p=0;
int manog1[3]{0,0,0};
int manog2[3]{0,0,0};
int manog3[3]{0,0,0};
int manog4[3]{0,0,0};
int posizionemazzo = 0;
int toccaa=0;
int vincitoreturno=6;
int situazione = 0;
int giro[4];
void inizializzagiocatori(){
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

int trovapostovuoto(int giocatore){
	if (giocatore==1){for(int i=0;i<4;i++){
		if (manog1[i]==99){return i;
		}
	}
	}
	if (giocatore==2){
		for(int i=0;i<4;i++){
		if (manog2[i]==99){return i;
		}
	}
	}
	if (giocatore==3){
		for(int i=0;i<4;i++){
		if (manog3[i]==99){return i;
		}
	}
	}
	if (giocatore==4){
		for(int i=0;i<4;i++){
		if (manog4[i]==99){return i;
		}
	}
	}
	
}
void pesca(){
	switch (vincitoreturno){
		case 1:
			manog1[trovapostovuoto(1)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog2[trovapostovuoto(2)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog3[trovapostovuoto(3)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog4[trovapostovuoto(4)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			
			break;
		case 2:
			manog2[trovapostovuoto(2)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog3[trovapostovuoto(3)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog4[trovapostovuoto(4)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog1[trovapostovuoto(1)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			break;
		case 3:
			manog3[trovapostovuoto(3)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog4[trovapostovuoto(4)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog1[trovapostovuoto(1)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog2[trovapostovuoto(2)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			break;
		case 4:
			manog4[trovapostovuoto(4)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog1[trovapostovuoto(1)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog2[trovapostovuoto(2)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			manog3[trovapostovuoto(3)]=mazzo[posizionemazzo];
			posizionemazzo=posizionemazzo+1;
			break;
	}
	
}

void primogiocatore(){
	toccaa=rand() % 4 + 1;
};


void dtavolo(){
	if(PLATFORM_NAME=="windows"){
		system("cls");
	}else system("clear");
	
	
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("________              -------------------------                                 \n");
	printf("        |                                                                       \n");
	printf("        |                                                                       \n");
	printf("--------                                                                        \n");
	printf("        |                                                                       \n");
	printf("        |                                                                       \n");
	printf("--------                                                                        \n");
	printf("        |                                                                       \n");
	printf("        |                                                                       \n");
	printf("--------              --------------------------                                \n");
	printf("                _carta1_ _carta2_ _carta3_                                    \n");
	printf("                | %d    | | %d    | | %d    |                                   \n",manog1[0]%10,manog1[1]%10,manog1[2]%10);
	printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
	printf("                |     %d| |     %d| |     %d|                                   \n",manog1[0]%10,manog1[1]%10,manog1[2]%10);

	
	






}

void gioca(){
	printf("le carte sono state date dal: ");
	switch (toccaa){
		case 1:
			printf("giocatore 4");
			break;
		case 2:
			printf("giocatore 1");
			break;
		case 3:
			printf("giocatore 2");
			break;
		case 4:
			printf("giocatore 3");
			break;
	}
	
	
	
	
	
}



int main(){
	time_t t;
	srand((unsigned) time(&t));
	//seme per generatore pseudocasuale
	printf("benvenuto nel gioco della briscola by daniele gibilaro\n");
	faiilmazzo();
	dailecarte();
	dtavolo();
	

    
	

	system("PAUSE");
}
