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
int giniziatore=0;
int briscola=0;
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
	briscola= mazzo[39];
	
	


	
}

void calcolavincitore(int chihainiziato){
	
	
	int semebase=(((int)tavolo[chihainiziato-1]/10)+3);
	int valorecartabase = (tavolo[chihainiziato-1]%10==0?10:tavolo[chihainiziato-1]%10);
	int cebriscola = 0;
	int briscolaalta = 0;
	int briscoladi = 0;
	int cestrozzamento = 0;
	int chistrozza = 0;
	
	for(int i=0; i<3;i++){
		if ((((int)tavolo[i]/10)+3)==semebase){
			if (valorecartabase==1){ //imbattibile ma messo come if per saltare le altre situazioni
			}
			else if ((tavolo[i]%10==0?10:tavolo[i]%10)>valorecartabase){
				cestrozzamento = 1;
				chistrozza = i+1;
			} else if ((tavolo[i]%10==0?10:tavolo[i]%10)==3){
				// situazione di 3
				cestrozzamento = 1;
				chistrozza = i+1;
				
			}
			
			
		} else if((((int)tavolo[i]/10)+3)==(((int)briscola/10)+3)){
			if (cebriscola == 0){ 
				cebriscola = 1;
				briscolaalta = (tavolo[i]%10==0?10:tavolo[i]%10);
				briscoladi = i+1;
				if ((tavolo[i]%10==0?10:tavolo[i]%10)==1){ 
					//situazione di asso di briscola
					vincitoreturno = i+1;
					break;
				}
				
			} else {
				if ((tavolo[i]%10==0?10:tavolo[i]%10)==1){ 
					//situazione di asso di briscola
					vincitoreturno = i+1;
					break;
				}
				if (briscolaalta<(tavolo[i]%10==0?10:tavolo[i]%10)){
					//situazione di briscola alta quindi vincente
					briscolaalta = (tavolo[i]%10==0?10:tavolo[i]%10);
					briscoladi = i+1;
					
				}
			}
			
			
			
		}
		
	}
	
	if(cestrozzamento ==0 && cebriscola==0 ){
		vincitoreturno = chihainiziato;
		
	}
	if(cestrozzamento ==0 && cebriscola==1 ){
		vincitoreturno = briscoladi;
		
	}
	if (cestrozzamento ==1 && cebriscola==0 ){
		vincitoreturno = chistrozza;
		
	}
	if (cestrozzamento ==1 && cebriscola==1){
		vincitoreturno = briscoladi;
	}
	
	
	
	for(int j=0;j<4;j++){
		//svuota il tavolo
		if(vincitoreturno == 1 or vincitoreturno==3){
			mazzog1[mazzog1p]=tavolo[j];
			mazzog1p=mazzog1p+1;
		}
		else {
			mazzog2[mazzog2p]=tavolo[j];
			mazzog2p=mazzog2p+1;
			
		}
		tavolo[j]=0;
	}
	
	
	printf("/n ha vinto il turno il giocatore :%d /n",vincitoreturno);
	toccaa = vincitoreturno;
}

int trovapostovuoto(int giocatore){
	if (giocatore==1){for(int i=0;i<3;i++){
		if (manog1[i]==99){return i;
		}
	}
	}
	if (giocatore==2){
		for(int i=0;i<3;i++){
		if (manog2[i]==99){return i;
		}
	}
	}
	if (giocatore==3){
		for(int i=0;i<3;i++){
		if (manog3[i]==99){return i;
		}
	}
	}
	if (giocatore==4){
		for(int i=0;i<3;i++){
		if (manog4[i]==99){return i;
		}
	}
	}
	
}



void buttasultavolo(int gioco,int giocatore){
	int carta=0;
	if (gioco==0){
		switch (giocatore){
			case 2:
				carta = rand() % 2 + 0;
				tavolo[1]=manog1[carta];
				manog2[carta]=99;
				break;
			case 3:
				carta = rand() % 2 + 0;
				tavolo[2]=manog1[carta];
				manog3[carta]=99;
				break;
			case 4:
				carta = rand() % 2 + 0;
				tavolo[3]=manog1[carta];
				manog4[carta]=99;
				break;
		}
	}
	else{
		tavolo[0]=manog1[gioco];
		manog1[gioco]=99;
		
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


void dtavolo(int situazione){
	if(PLATFORM_NAME=="windows"){
		system("cls");
	}else system("clear");
	
	switch (situazione){
	
		case 1:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10+48))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                         ________\n");
			printf("        |                                                              |        \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                                                              |        \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------                                                                --------\n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                                                              |        \n",(tavolo[1]%10==0?75:(tavolo[1]%10==9?81:(tavolo[1]%10==8?74:tavolo[2]+48))));
			printf("        |                                                              |        \n",(tavolo[1]==0?32:(int)(tavolo[1]/10)+3),(tavolo[1]==0?32:(int)(tavolo[1]/10)+3));
			printf("--------                                                                --------\n");
			printf("        |                                                              |        \n");
			printf("        |                                                              |        \n");
			printf("--------              --------------------------                        --------\n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
		
		case 2:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10+48))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                                                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                                                                       \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------                                   ------                               \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                                 |  %c                                 \n",(tavolo[1]%10==0?75:(tavolo[1]%10==9?81:(tavolo[1]%10==8?74:tavolo[2]+48))));
			printf("        |                                 |%c  %c                               \n",(tavolo[1]==0?32:(int)(tavolo[1]/10)+3),(tavolo[1]==0?32:(int)(tavolo[1]/10)+3));
			printf("--------                                   ------                               \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
		
		case 3:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10+48))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                       | %c    |                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                       |   %c  |                                       \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------                        |     %c|  ------                               \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                                 |  %c                                 \n",(tavolo[1]%10==0?75:(tavolo[1]%10==9?81:(tavolo[1]%10==8?74:tavolo[2]+48))));
			printf("        |                                 |%c  %c                               \n",(tavolo[1]==0?32:(int)(tavolo[1]/10)+3),(tavolo[1]==0?32:(int)(tavolo[1]/10)+3));
			printf("--------                                   ------                               \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;

		
		case 4:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10+48))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                       | %c    |                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |                       |   %c  |                                       \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------              ------    |     %c|  ------                               \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]+48))));
			printf("        |             %c  %c|             |  %c                                 \n",(tavolo[3]==0?32:(int)(tavolo[3]/10)+3),(tavolo[3]==0?32:(int)(tavolo[3]/10)+3),(tavolo[3]%10==0?75:(tavolo[3]%10==9?81:(tavolo[3]%10==8?74:tavolo[3]+48))));
			printf("        |               %c  |             |%c  %c                               \n",(tavolo[3]%10==0?75:(tavolo[3]%10==9?81:(tavolo[3]%10==8?74:tavolo[3]+48))),(tavolo[1]==0?32:(int)(tavolo[1]/10)+3),(tavolo[1]==0?32:(int)(tavolo[1]/10)+3));
			printf("--------             ------                ------                               \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
		
		
		case 5:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10+48))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              ------                                                    \n");
			printf("        |             %c  %c|                                                   \n",(tavolo[3]==0?32:(int)(tavolo[3]/10)+3),(tavolo[3]==0?32:(int)(tavolo[3]/10)+3));
			printf("        |               %c  |                                                   \n",(tavolo[3]%10==0?75:(tavolo[3]%10==9?81:(tavolo[3]%10==8?74:tavolo[3]+48))));
			printf("--------             ------                                                     \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
		
		case 6:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola%10))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                       | %c    |                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]))));
			printf("        |                       |   %c  |                                       \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------              ------    |     %c|                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]))));
			printf("        |             %c  %c|                                                   \n",(tavolo[3]==0?32:(int)(tavolo[3]/10)+3),(tavolo[3]==0?32:(int)(tavolo[3]/10)+3));
			printf("        |               %c  |                                                   \n",(tavolo[3]%10==0?75:(tavolo[3]%10==9?81:(tavolo[3]%10==8?74:tavolo[3]))));
			printf("--------             ------                                                     \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
		
		case 7:	
			printf("                                                                                \n");
			printf(" briscola: %c valore:%c                                                         \n",(((int)briscola/10)+3),(briscola%10==0?75:(briscola%10==9?81:(briscola%10==8?74:briscola))));
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("                                                                                \n");
			printf("________              -------------------------                                 \n");
			printf("        |                       | %c    |                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]))));
			printf("        |                       |   %c  |                                       \n",(tavolo[2]==0?32:(int)(tavolo[2]/10)+3));
			printf("--------                        |     %c|                                       \n",(tavolo[2]%10==0?75:(tavolo[2]%10==9?81:(tavolo[2]%10==8?74:tavolo[2]))));
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------                                                                        \n");
			printf("        |                                                                       \n");
			printf("        |                                                                       \n");
			printf("--------              --------------------------                                \n");
			printf("                _carta1_ _carta2_ _carta3_                                    \n");
			printf("                | %c    | | %c    | | %c    |                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			printf("                |   %c  | |   %c  | |   %c  |                                   \n",(((int)manog1[0]/10)+3),(((int)manog1[1]/10)+3),(((int)manog1[2]/10)+3));
			printf("                |     %c| |     %c| |     %c|                                   \n",(manog1[0]%10==0?75:(manog1[0]%10==9?81:(manog1[0]%10==8?74:manog1[0]+48))),(manog1[1]%10==0?75:(manog1[1]%10==9?81:(manog1[1]%10==8?74:manog1[1]+48))),(manog1[2]%10==0?75:(manog1[2]%10==9?81:(manog1[2]%10==8?74:manog1[2]+48))));
			break;
			

}
	
}







void gioca(){
	primogiocatore();
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
	for(int p=0;p<10;p++){
		giniziatore = toccaa;
		int cartascelta = 0;
		switch (toccaa){
			case 1:
			
				//display
				//mazzo tuo tavolo vuoto;
				dtavolo(1);
				printf(" e' il tuo turno scegli la carta da buttare sul tavolo\n");
				do{
					scanf("%d",&cartascelta);
				}while ((cartascelta!=1) or (cartascelta!=2) or (cartascelta!=3));
				buttasultavolo(cartascelta,1);
				buttasultavolo(0,4);
				dtavolo(5);
				buttasultavolo(0,3);
				dtavolo(6);
				buttasultavolo(0,2);
				dtavolo(4);
				
				break;
		case 2:
			buttasultavolo(0,2);
			
			dtavolo(3);
			printf("scegli la carta da buttare sul tavolo\n");
			do{
				scanf("%d",&cartascelta);
			}while ((cartascelta!=1) or (cartascelta!=2) or (cartascelta!=3));
			buttasultavolo(cartascelta,1);
			
			buttasultavolo(0,4);
			dtavolo(5);
			buttasultavolo(0,3);
			dtavolo(4);
			//display
			break;
		case 3:
			
			buttasultavolo(0,3);
			dtavolo(7);
			buttasultavolo(0,2);
			dtavolo(3);
			printf(" e' il tuo turnoscegli la carta da buttare sul tavolo\n");
			do{
				scanf("%d",&cartascelta);
			}while ((cartascelta!=1) or (cartascelta!=2) or (cartascelta!=3));
			buttasultavolo(cartascelta,1);
			
			buttasultavolo(0,4);
			dtavolo(4);
			//display
			break;
		case 4:
			
			buttasultavolo(0,4);
			dtavolo(5);
			buttasultavolo(0,3);
			dtavolo(6);
			buttasultavolo(0,2);
			dtavolo(4);
			printf(" e' il tuo turnoscegli la carta da buttare sul tavolo\n");
			do{
				scanf("%d",&cartascelta);
			}while ((cartascelta!=1) or (cartascelta!=2) or (cartascelta!=3));
			buttasultavolo(cartascelta-1,1);
			
			//display
			break;
			
		}
		calcolavincitore(giniziatore);
		pesca();
		
		
	}
	
	
	
	
	
	
}



int main(){
	time_t t;
	srand((unsigned) time(&t));
	//seme per generatore pseudocasuale
	printf("benvenuto nel gioco della briscola by daniele gibilaro\n");
	faiilmazzo();
	dailecarte();
	gioca();
	
	

    
	

	system("PAUSE");
}
