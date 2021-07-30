/*
	Name: Program memodifikasi permainan 41an
	Author: Mugi Pangestu (191511051), nisrina Qurratu'ain (191511058), dan Ummu Izzatul (191511065)
	Date: 24/02/20 18:01
	Description: program ini adalah program hasil memperbaiki dan memodifikasi program permain 41an yang dibuat oleh kating 2013
*/

//Pemanggilan library
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <windows.h>
#define panjang 600

// variabel global
int cardPlayer1[5],cardPlayer2[5],cardPlayer3[5],satuanKartu=13,i,j,k,temp,scorePlayer1,scorePlayer2,scorePlayer3;			 		
int dek[52];     
  	  	
void bagi_kartu_3();	
void print_kartu_a();
void print_kartu_b();
void print_kartu_c();
void print_hasil(int player);
void keputusan(int player);
void random();
void head();
void header();
void print_scorePlayer1();
void print_scorePlayer2();
void print_scorePlayer3();
void first_step();
void cek_menang(int player);
void menang_tak_pasti(int scorePlayer1,int scorePlayer2,int scorePlayer3);
void cara_main();
void about();
void urut_kartu();
void identitas();
void logoGame();
void rekapPlayer();
void tampilRekap();
void gotoxy();
void loading (int x, int y);
void loadgame(int playerke);
void loading2();
void kecepatan();


struct data{			//Komposit berfungsi sebagai variabel penampung dari File rekap.DAT
	char name[49];
	int score;
};
struct data rekap;


int main() {
	system("COLOR E0");
	int player;
	loading (30,12);
	do{	
	
	//FASE 1 Firt Step, Random Kartu
		
		header();	
		
  		random(); 
		  
  	//FASE 2 Second Step, Bagi Kartu bagi bagi kartu untuk 3 player
  		bagi_kartu_3();
	//FASE 3 First Step
		system("cls");
		
		head();							
		first_step();
	//FASE 4 Main Phase, player1 phase
		while(satuanKartu<52){
			if(satuanKartu!=52){
				//player2 phase
				system("cls");
				head();
				player=2;
				loadgame(player);
				keputusan(player);
				cek_menang(player);
			}
			if(satuanKartu!=52){ 
				//player3 phase
				system("cls");
				head();	
				system("cls");
				head();
				player=3;
				loadgame(player);
				keputusan(player);
				cek_menang(player);		
			}
			if(satuanKartu!=52){
				//player1 phase		
				system("cls");
				head();
				player=1;
				print_kartu_a();		
				keputusan(player);
				cek_menang(player);		
			}	
		}
	//FASE 5 Final Result
			system("cls");
			head();
											
			player=1;	
			print_kartu_a();		
			print_hasil(player);						
			printf("\n");	
													
			player=2;			
			print_kartu_b();
			print_hasil(player);			
			printf("\n");	
													
			player=3;	
			print_kartu_c();		
			print_hasil(player);			
			printf("\n");		

		menang_tak_pasti(scorePlayer1,scorePlayer2,scorePlayer3);
		printf("______________________________________________________________________________\n");			
		printf("\n1)Main Lagi\n2)save & exit\n");
		printf("\nPilihan : ");
		scanf("%d",&temp);
		}while(temp==1);
		if (temp != 1){
			rekapPlayer ();
		}
		
  system ("pause");
  return 0;
}
void bagi_kartu_3(){	// modul ini berfungsi untuk proses pembagian kartu playe 1,2 dan 3
	for(i=0;i<=12;i++){
		if(i<4){
			cardPlayer1[i]=dek[i];
			dek[i]=0;
		}
		if(i<8){
			cardPlayer2[i-4]=dek[i];
			dek[i]=0;
		}
		if(i<12){
			cardPlayer3[i-8]=dek[i];
			dek[i]=0;
		}						
	}
}
int tipe_kartu(int a){	// modul ini berfungsi untuk memberikan atribut kartu seperti w= lope, x= tahu, y=keriting, z=skop
	char e;
	if (a==3){
		e='W';
	}
	else if (a==4){
		e='X';
	}
	else if (a==5){
		e='Y';
	}
	else if (a==6){
		e='Z';
	}
	return e;	
}
void print_kartu_a(){	// modul ini berfungsi untuk menampilkan kartu player 1
	int k,l,m,n,o;
	printf("______________________________________________________________________________\n");	
	printf("               ----       ----       ----       ----       ----\n");
	printf("          ");
	for(i=0;i<=4;i++){
			if(cardPlayer1[i]/10>10){
				if(cardPlayer1[i]/10==11){
					k=cardPlayer1[i]%10;
					printf("     |J\%c|  ",tipe_kartu(k));	
				}else if(cardPlayer1[i]/10==12){
					l=cardPlayer1[i]%10;
					printf("     |Q\%c|  ",tipe_kartu(l));	
				}else if(cardPlayer1[i]/10==13){
					m=cardPlayer1[i]%10;
					printf("     |K\%c|  ",tipe_kartu(m));					
				}else if(cardPlayer1[i]/10==14){
					n=cardPlayer1[i]%10;
					printf("     |A\%c|  ",tipe_kartu(n));	
				}	
				
		}	
		else{
				o=cardPlayer1[i]%10;
				printf("     |%d\%c|  ",cardPlayer1[i]/10,tipe_kartu(o));}		
			}
		printf("               \n");
		printf("               ----       ----       ----       ----       ----\n");               // BUAT APAAA??
		printf("              Kartu 1    Kartu 2    Kartu 3    Kartu 4    Kartu 5");
		printf("\n\n");
}
void print_kartu_b(){	// modul ini berfungsi untuk menampilkan kartu player 2
		int k,l,m,n,o;
	printf("______________________________________________________________________________\n");	
	printf("               ----       ----       ----       ----       ----\n");
	printf("          ");
	for(i=0;i<=4;i++){
			if(cardPlayer2[i]/10>10){
				if(cardPlayer2[i]/10==11){
					k=cardPlayer2[i]%10;
					printf("     |J\%c|  ",tipe_kartu(k));	
				}else if(cardPlayer2[i]/10==12){
					l=cardPlayer2[i]%10;
					printf("     |Q\%c|  ",tipe_kartu(l));	
				}else if(cardPlayer2[i]/10==13){
					m=cardPlayer2[i]%10;
					printf("     |K\%c|  ",tipe_kartu(m));					
				}else if(cardPlayer2[i]/10==14){
					n=cardPlayer2[i]%10;
					printf("     |A\%c|  ",tipe_kartu(n));	
				}	
				
		}	
		else{
				o=cardPlayer2[i]%10;
				printf("     |%d\%c|  ",cardPlayer2[i]/10,tipe_kartu(o));}		
			}
		printf("               \n");
		printf("               ----       ----       ----       ----       ----\n");
		printf("              Kartu 1    Kartu 2    Kartu 3    Kartu 4    Kartu 5");
		printf("\n\n");
}
void print_kartu_c(){	// modul ini berfungsi untuk menampilkan kartu player 3
	int k,l,m,n,o;
	printf("______________________________________________________________________________\n");	
	printf("               ----       ----       ----       ----       ----\n");
	printf("          ");
	for(i=0;i<=4;i++){
			if(cardPlayer3[i]/10>10){
				if(cardPlayer3[i]/10==11){
					k=cardPlayer3[i]%10;
					printf("     |J\%c|  ",tipe_kartu(k));	
				}else if(cardPlayer3[i]/10==12){
					l=cardPlayer3[i]%10;
					printf("     |Q\%c|  ",tipe_kartu(l));	
				}else if(cardPlayer3[i]/10==13){
					m=cardPlayer3[i]%10;
					printf("     |K\%c|  ",tipe_kartu(m));					
				}else if(cardPlayer3[i]/10==14){
					n=cardPlayer3[i]%10;
					printf("     |A\%c|  ",tipe_kartu(n));	
				}	
				
		}	
		else{
				o=cardPlayer3[i]%10;
				printf("     |%d\%c|  ",cardPlayer3[i]/10,tipe_kartu(o));}		
			}
		printf("               \n");
		printf("               ----       ----       ----       ----       ----\n");
		printf("              Kartu 1    Kartu 2    Kartu 3    Kartu 4    Kartu 5");
		printf("\n\n");
}
void random(){			// modul ini berfungsi untuk mengacak nomor kartu pada cangkulan
	int dekori[52] = 
  	{
  	23,24,25,26,
  	33,34,35,36,
  	43,44,45,46,
  	53,54,55,56,
  	63,64,65,66,
  	73,74,75,76,
  	83,84,85,86,
  	93,94,95,96,
  	103,104,105,106,
  	113,114,115,116,
  	123,124,125,126,
  	133,134,135,136,
  	143,144,145,146,
  	};
	srand (time(NULL));    
		for(i=0;i<52;i++){  //modul untuk random	
		  	do{
		   		j=(rand()% ((52+0) - 0) + 0);
				k=dekori[j];      		
   			}while(k==0);   	
  		dek[i]=k;
  		dekori[j]=0;  	
  		}
  	satuanKartu=12;	
  	scorePlayer1=0,scorePlayer2=0,scorePlayer3=0;
}
void keputusan(int player){		// modul ini berfungsi untuk menentukan keputusan antara ambil dek atau ambil sampah.
	char program;
	if(player==2){//GILIRAN PLAYER-2
		for(i=0; i<=3; i++){
	        for(j=i+1; j<=3; j++){
	            if(cardPlayer2[i]/10>cardPlayer2[j]/10){
	                temp = cardPlayer2[i];
	                cardPlayer2[i] = cardPlayer2[j];
	                cardPlayer2[j] = temp;
	            }
	        }        
	    }		    
	    if(scorePlayer2%10==cardPlayer2[3]%10){	    				
			cardPlayer2[4]=scorePlayer2;		
	    		if(cardPlayer2[2]%10!=cardPlayer2[3]%10){
	    			scorePlayer3=cardPlayer2[2];
		    		cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;				
	    		}else if(cardPlayer2[1]%10!=cardPlayer2[3]%10){
	    			scorePlayer3=cardPlayer2[1];
		    		cardPlayer2[1]=cardPlayer2[2];cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;					
	    		}
				else{
					scorePlayer3=cardPlayer2[0];
		    		cardPlayer2[0]=cardPlayer2[1];cardPlayer2[1]=cardPlayer2[2];cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;					
				}	    		   		   		    	
	    }else{
	    	cardPlayer2[4]=dek[satuanKartu];
	    	dek[satuanKartu]=0;	    	
	    	satuanKartu=satuanKartu+1;
	    	if(cardPlayer2[4]%10==cardPlayer2[3]%10){
	    		if(cardPlayer2[2]%10!=cardPlayer2[3]%10){
	    			scorePlayer3=cardPlayer2[2];
		    		cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;										    		
	    		}else if(cardPlayer2[1]%10!=cardPlayer2[3]%10){
	    			scorePlayer3=cardPlayer2[1];
		    		cardPlayer2[1]=cardPlayer2[2];cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;					
	    		}
				else{
					scorePlayer3=cardPlayer2[0];
		    		cardPlayer2[0]=cardPlayer2[1];cardPlayer2[1]=cardPlayer2[2];cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    		cardPlayer2[4]=0;					
				}	    			    		
	    	}else{	   	    							    	 		
		    		for(i=0; i<=4; i++){
		        		for(j=i+1; j<=4; j++){
		            		if(cardPlayer2[i]/10>cardPlayer2[j]/10){
			                	temp = cardPlayer2[i];
			                	cardPlayer2[i] = cardPlayer2[j];
		    	            	cardPlayer2[j] = temp;
		            		}
		        		}        
		    		}
				scorePlayer3=cardPlayer2[0];
		    	cardPlayer2[0]=cardPlayer2[1];cardPlayer2[1]=cardPlayer2[2];cardPlayer2[2]=cardPlayer2[3];cardPlayer2[3]=cardPlayer2[4];
		    	cardPlayer2[4]=0;				
	    	}	    	
	    }	    
	}else if(player==3){//GILIRAN PLAYER-3
		for (i=0; i<=3; i++){
	        for (j=i+1; j<=3; j++){
	            if (cardPlayer3[i]/10>cardPlayer3[j]/10){
	                temp = cardPlayer3[i];
	                cardPlayer3[i] = cardPlayer3[j];
	                cardPlayer3[j] = temp;
	            }
	        }        
	    }			
	    if(scorePlayer3%10==cardPlayer3[3]%10){	    				
			cardPlayer3[4]=scorePlayer3;		
	    		if(cardPlayer3[2]%10!=cardPlayer3[3]%10){
	    			scorePlayer1=cardPlayer3[2];
		    		cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;				
	    		}else if(cardPlayer3[1]%10!=cardPlayer3[3]%10){
	    			scorePlayer1=cardPlayer3[1];
		    		cardPlayer3[1]=cardPlayer3[2];cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;						
	    		}
				else{
					scorePlayer1=cardPlayer3[0];
		    		cardPlayer3[0]=cardPlayer3[1];cardPlayer3[1]=cardPlayer3[2];cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;					
				}	    		   		   		    	
	    }else{
	    	cardPlayer3[4]=dek[satuanKartu];
	    	dek[satuanKartu]=0;	    	
	    	satuanKartu=satuanKartu+1;
	    	if(cardPlayer3[4]%10==cardPlayer3[3]%10){
	    		if(cardPlayer3[2]%10!=cardPlayer3[3]%10){
	    			scorePlayer1=cardPlayer3[2];
		    		cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;										    		
	    		}else if(cardPlayer3[1]%10!=cardPlayer3[3]%10){
	    			scorePlayer1=cardPlayer3[1];
		    		cardPlayer3[1]=cardPlayer3[2];cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;					
	    		}
				else{
					scorePlayer1=cardPlayer3[0];
		    		cardPlayer3[0]=cardPlayer3[1];cardPlayer3[1]=cardPlayer3[2];cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    		cardPlayer3[4]=0;					
				}	    			    		
	    	}else{	   	    						    	 		
		    		for(i=0; i<=4; i++){
		        		for(j=i+1; j<=4; j++){
		            		if(cardPlayer3[i]/10>cardPlayer3[j]/10){
			                	temp = cardPlayer3[i];
			                	cardPlayer3[i] = cardPlayer3[j];
		    	            	cardPlayer3[j] = temp;
		            		}
		        		}        
		    		}
				scorePlayer1=cardPlayer3[0];
		    	cardPlayer3[0]=cardPlayer3[1];cardPlayer3[1]=cardPlayer3[2];cardPlayer3[2]=cardPlayer3[3];cardPlayer3[3]=cardPlayer3[4];
		    	cardPlayer3[4]=0;				
	    	}	    	
	    }
	}else{//GILIRAN PLAYER-1
		printf("______________________________________________________________________________\n\n");
		printf("\n1) Untuk ambil dek\n");
		printf("2) Untuk ambil sampah\n\n");	
		printf("\n______________________________________________________________________________\n");		
		printf("\nPilihan : ");
		label1 :
			scanf(" %c",&program);
			if(program=='1'){
				cardPlayer1[4]=dek[satuanKartu];
		    	dek[satuanKartu]=0;
		    	satuanKartu=satuanKartu+1;
			}else if(program=='2'){
				cardPlayer1[4]=scorePlayer1;				    		    		    
			}else{
				printf("anda melakukan kesalahan input ");			
				goto label1;				
			}			
		
		
			system("cls");
			head();			
			print_kartu_a();
		
		printf("______________________________________________________________________________\n");		
		printf("\nBuang kartu : ");
		label3 :
		scanf(" %c",&program);		
		switch(program){
			case '1':
				scorePlayer2=cardPlayer1[0];
	    		cardPlayer1[0]=cardPlayer1[1];cardPlayer1[1]=cardPlayer1[2];cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];
	    		cardPlayer1[4]=0;
				break;
			case '2':
				scorePlayer2=cardPlayer1[1];
	    		cardPlayer1[1]=cardPlayer1[2];cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];
	    		cardPlayer1[2];
				cardPlayer1[4]=0;
				break;
			case '3':
				scorePlayer2=cardPlayer1[2];
	    		cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];
	    		cardPlayer1[4]=0;
				break;
			case '4':
				scorePlayer2=cardPlayer1[3];
	    		cardPlayer1[3]=cardPlayer1[4];
	    		cardPlayer1[4]=0;
				break;
			case '5':
				scorePlayer2=cardPlayer1[4];
	    		cardPlayer1[4]=0;
				break;
			default:
				printf("anda melakukan kesalahan input ");
				goto label3;
				break;
		}				
	}	    
}
void cek_menang(int player){	// modul ini berfungsi untuk mengecek kartu yang dimiliki player apakah sesuai dengan syarat untuk memenangkan permainan ini atau tidak.
	int jml_kr=0,jml_th=0,jml_sk=0,jml_lo=0;	
	if(player==1){
		for(i=0;i<=3;i++){
			if(cardPlayer1[i]%10==3){
			jml_lo=jml_lo+cardPlayer1[i]/10;	
			}else if(cardPlayer1[i]%10==4){
			jml_th=jml_th+cardPlayer1[i]/10;
			}else if(cardPlayer1[i]%10==5){
			jml_kr=jml_kr+cardPlayer1[i]/10;
			}else{
			jml_sk=jml_sk+cardPlayer1[i]/10;
			}
		}
		if(jml_lo==49 || jml_lo==50 || jml_th==49 || jml_th==50 || jml_kr==49 || jml_kr==50 || jml_sk==49 || jml_sk==50){
			printf("     ***     ***  ***    ***    ***     ***       *** *** ***   ***\n");
			printf("      ***   *** **   **  ***    ***     ***       *** *** ****  ***\n");
			printf("       *** *** **     ** ***    ***     ***       *** *** ***** ***\n");
			printf("        *****  **     ** ***    ***     *** ***** *** *** *********\n");
			printf("         ***   **     ** ***    ***     ****** ****** *** *** *****\n");
			printf("         ***    **   **   ***  ***      *****   ***** *** ***  ****\n");
			printf("         ***      ***      ******       ****     **** *** ***   ***\n");						
			
			system("PAUSE");
			satuanKartu=52;
			
		}
	}else if(player==2){
		for(i=0;i<=3;i++){
			if(cardPlayer2[i]%10==3){
			jml_lo=jml_lo+cardPlayer2[i]/10;	
			}else if(cardPlayer2[i]%10==4){
			jml_th=jml_th+cardPlayer2[i]/10;
			}else if(cardPlayer2[i]%10==5){
			jml_kr=jml_kr+cardPlayer2[i]/10;
			}else{
			jml_sk=jml_sk+cardPlayer2[i]/10;
			}
		}
		if(jml_lo==50 || jml_lo==54 || jml_th==50 || jml_th==49 || jml_kr==50 || jml_kr==49 || jml_sk==50 || jml_sk==49){
			printf("     ***     ***  ***    ***    ***     ***        ***     ******  *******\n");
			printf("      ***   *** **   **  ***    ***     ***      **   **  **       *******\n");
			printf("       *** *** **     ** ***    ***     ***     **     ** **       **     \n");
			printf("        *****  **     ** ***    ***     ***     **     **  *****   ****   \n");
			printf("         ***   **     ** ***    ***     ***     **     **       ** **     \n");
			printf("         ***    **   **   ***  ***      *******  **   **        ** *******\n");
			printf("         ***      ***      ******       *******    ***     ******  *******\n");
			
			system("PAUSE");
			satuanKartu=52;
		}
	}else{
		for(i=0;i<=3;i++){
			if(cardPlayer3[i]%10==3){
			jml_lo=jml_lo+cardPlayer3[i]/10;	
			}else if(cardPlayer3[i]%10==4){
			jml_th=jml_th+cardPlayer3[i]/10;
			}else if(cardPlayer3[i]%10==5){
			jml_kr=jml_kr+cardPlayer3[i]/10;
			}else{
			jml_sk=jml_sk+cardPlayer3[i]/10;
			}
		}
		if(jml_lo==50 || jml_lo==49 || jml_th==50 || jml_th==49 || jml_kr==50 || jml_kr==49 || jml_sk==50 || jml_sk==49){
			printf("     ***     ***  ***    ***    ***     ***        ***     ******  *******\n");
			printf("      ***   *** **   **  ***    ***     ***      **   **  **       *******\n");
			printf("       *** *** **     ** ***    ***     ***     **     ** **       **     \n");
			printf("        *****  **     ** ***    ***     ***     **     **  *****   ****   \n");
			printf("         ***   **     ** ***    ***     ***     **     **       ** **     \n");
			printf("         ***    **   **   ***  ***      *******  **   **        ** *******\n");
			printf("         ***      ***      ******       *******    ***     ******  *******\n");
			
			system("PAUSE");
			satuanKartu=52;
		}		
	}	
};
void head(){

	
		// modul ini berfungsi untuk menampilkan layout ketika memainkan permainan
		int dek_sisa=0; 
		char spasi;
		if(51-satuanKartu>0){
			dek_sisa=51-satuanKartu;
		}else{
			dek_sisa=0;
		}		
		
		
		printf("                                                                               \n");	
		printf("_                   GAME 41an Kelompok 8 D3-Teknik Informatika                _\n");
		printf("_                          POLITEKNIK NEGERI BANDUNG                          _\n");
		printf("_______________________________________________________________________________\n");			
		printf("    ____                                                              ____  \n");
		printf("    |   |                         	                              |   |  \n");
		printf("    |   |                              	                              |   |  \n", scorePlayer2);
		printf("    |___|                                                             |___|  \n");
		printf("    ____          ___________                       ___________       ____   \n");
		printf("    |   |         |         |                       |         |       |   |  \n");
		printf("    |   |         |   ");print_scorePlayer2();printf("   |                       |    ");print_scorePlayer3();printf("  |       |   |  \n");
		printf("    |___|         |_________|                       |_________|       |___|  \n");
		printf(" P2 ____                             ______                           ____  P3 \n");
		printf("    |   |                           |      |                          |   |  \n");
		printf("    |   |                           |  %d  |                          |   |  \n",dek_sisa);
		printf("    |___|                           |______|                          |___|  \n");
		printf("    ____                                                              ____   \n");
		printf("    |   |                          ___________                        |   |  \n");
		printf("    |   |                          |         |                        |   |  \n");
		printf("    |___|                          |    ");print_scorePlayer1();printf("  |                        |___|  \n");
		printf("                                   |_________|								 \n", scorePlayer1);		
		printf("_______________________________________________________________________________\n");
		printf("                                  PLAYER: %s                                \n", &rekap.name);
		printf("     W = LOPE  		    X = TAHU          Y = KERITING         Z = SEKOP     \n");

		if(satuanKartu>41){
		system("cls");
		printf("                                                                               \n");	
		printf("_                   GAME 41an Kelompok 8 D3-Teknik Informatika                _\n");
		printf("_                          POLITEKNIK NEGERI BANDUNG                          _\n");
		printf("_______________________________________________________________________________\n");			
		printf("    ____                                                              ____  \n");
		printf("    |   |                         	                              |   |  \n");
		printf("    |   |                              	                              |   |  \n", scorePlayer2);
		printf("    |___|                                                             |___|  \n");
		printf("    ____          ___________                       ___________       ____   \n");
		printf("    |   |         |         |                       |         |       |   |  \n");
		printf("    |   |         |   ");print_scorePlayer2();printf("   |                       |    ");print_scorePlayer3();printf("  |       |   |  \n");
		printf("    |___|         |_________|                       |_________|       |___|  \n");
		printf(" P2 ____                             ______                           ____  P3 \n");
		printf("    |   |                           |      |                          |   |  \n");
		printf("    |   |                           |  %d  |                          |   |  \n",dek_sisa);
		printf("    |___|                           |______|                          |___|  \n");
		printf("    ____                                                              ____   \n");
		printf("    |   |                          ___________                        |   |  \n");
		printf("    |   |                          |         |                        |   |  \n");
		printf("    |___|                          |    ");print_scorePlayer1();printf("  |                        |___|  \n");
		printf("                                   |_________|								 \n", scorePlayer1);		
		printf("_______________________________________________________________________________\n");
		printf("                                  PLAYER: %s                                \n", &rekap.name);
		printf("     W = LOPE  		    X = TAHU          Y = KERITING         Z = SEKOP     \n");
		}
}
void print_scorePlayer2(){		// modul ini berfungsi untuk menampilkan kartu sampah player 2
	int k,l,m,n,o,p;
	if(scorePlayer2/10>=10){
				if(scorePlayer2/10==11){
					k=scorePlayer2%10;
					printf("J\%c ",tipe_kartu(k));	
				}else if(scorePlayer2/10==12){
					l=scorePlayer2%10;
					printf("Q\%c ",tipe_kartu(l));	
				}else if(scorePlayer2/10==13){
					m=scorePlayer2%10;
					printf("K\%c ",tipe_kartu(m));					
				}else if(scorePlayer2/10==14){
					n=scorePlayer2%10;
					printf("A\%c ",tipe_kartu(n));	
				}else{
					o=scorePlayer2%10;
					printf("%d\%c",scorePlayer2/10,tipe_kartu(o));
				}				
			}else{
				p=scorePlayer2%10;
				printf("%d\%c ",scorePlayer2/10,tipe_kartu(p));}
}
void print_scorePlayer3(){		// modul ini berfungsi untuk menampilkan kartu sampah player 3
	int k,l,m,n,o,p;
	if(scorePlayer3/10>=10){
				if(scorePlayer3/10==11){
					k=scorePlayer3%10;
					printf("J\%c ",tipe_kartu(k));	
				}else if(scorePlayer3/10==12){
					l=scorePlayer3%10;
					printf("Q\%c ",tipe_kartu(l));	
				}else if(scorePlayer3/10==13){
					m=scorePlayer3%10;
					printf("K\%c ",tipe_kartu(m));					
				}else if(scorePlayer3/10==14){
					n=scorePlayer3%10;
					printf("A\%c ",tipe_kartu(n));	
				}else{
					o=scorePlayer3%10;
					printf("%d\%c",scorePlayer3/10,tipe_kartu(o));
				}				
			}else{
				p=scorePlayer3%10;
				printf("%d\%c ",scorePlayer3/10,tipe_kartu(p));}
}
void print_scorePlayer1(){		// modul ini berfungsi untuk menampilkan kartu sampah player 1
	int k,l,m,n,o,p;
	if(scorePlayer1/10>=10){
				if(scorePlayer1/10==11){
					k=scorePlayer1%10;
					printf("J\%c ",tipe_kartu(k));	
				}else if(scorePlayer1/10==12){
					l=scorePlayer1%10;
					printf("Q\%c ",tipe_kartu(l));	
				}else if(scorePlayer1/10==13){
					m=scorePlayer1%10;
					printf("K\%c ",tipe_kartu(m));					
				}else if(scorePlayer1/10==14){
					n=scorePlayer1%10;
					printf("A\%c ",tipe_kartu(n));	
				}else{
					o=scorePlayer1%10;
					printf("%d\%c",scorePlayer1/10,tipe_kartu(o));
				}				
			}else{
				p=scorePlayer1%10;
				printf("%d\%c ",scorePlayer1/10,tipe_kartu(p));}
}
void first_step(){
			// modul ini berfungsi untuk menentukan apa yang ingin ita inputkan dan yang ingin kita mainkan.
	char program;
	cardPlayer1[4]=dek[satuanKartu];
	urut_kartu();		
	print_kartu_a();
	printf("______________________________________________________________________________\n");		
	printf("\nBuang kartu : ");
	label2 :
	scanf(" %c",&program);
	switch(program){
		case '1':
			scorePlayer2=cardPlayer1[0];
			cardPlayer1[0]=cardPlayer1[1];cardPlayer1[1]=cardPlayer1[2];cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];cardPlayer1[4]=0;
			break;
		case '2':
			scorePlayer2=cardPlayer1[1];
			cardPlayer1[1]=cardPlayer1[2];cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];cardPlayer1[4]=0;
			break;
		case '3':
			scorePlayer2=cardPlayer1[2];
			cardPlayer1[2]=cardPlayer1[3];cardPlayer1[3]=cardPlayer1[4];cardPlayer1[4]=0;
			break;
		case '4':
			scorePlayer2=cardPlayer1[3];
			cardPlayer1[3]=cardPlayer1[4];cardPlayer1[4]=0;
			break;
		case '5':
			scorePlayer2=cardPlayer1[4];cardPlayer1[4]=0;
			break;
		default:
			printf("anda melakukan kesalahan input ");
			goto label2;
			break;			
	}
	satuanKartu=satuanKartu+1;
}
void header(){			// modul ini berdungsi untuk menampilkan tampilan menu permainan
		
		char pilihan;
		label41:
			
		logoGame();
		system("cls");

		label4 :
		system("cls");	
		logoGame();
		system("PAUSE");
		printf("\n\n                             MENU\n\n");
		printf("                           1)Main \n");			
		printf("                           2)About us \n");			
		printf("                           3)Cara main \n");
		printf("                           4)Tampilkan rekap player\n");
		printf("                           5)Exit\n\n")	;			
		printf("                        Pilihan : ");
		scanf(" %c",&pilihan);
		switch(pilihan){
			case '1':
				identitas();
				system("Pause");
				system("cls");				
			break;	
			case '2':
				about();
				goto label4;
			break;
			case '3':
				cara_main();
				goto label4;
			break;
			case '4':
				tampilRekap();
				goto label4;
			case '5':
				printf("thanks!");
				exit(1);
			default:
				goto label4;
			break;			
		}			
		system("cls");		
	
}
void print_hasil(int player){	// modul ini berfungsi untuk menentukan hasil dari setiap player, yang artinya setiap kartu yang dimiliki player dihitung.
	int jml_kr=0,jml_th=0,jml_sk=0,jml_lo=0;	
	int hasil, susunan[4];		
	if(player==1){
		for(i=0;i<4;i++){
			if(cardPlayer1[i]%10==3){
				jml_lo=jml_lo+cardPlayer1[i]/10;	
			}else if(cardPlayer1[i]%10==4){
				jml_th=jml_th+cardPlayer1[i]/10;
			}else if(cardPlayer1[i]%10==5){
				jml_kr=jml_kr+cardPlayer1[i]/10;
			}else{
				jml_sk=jml_sk+cardPlayer1[i]/10;
			}
		}
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("				Player 1  :  %d",hasil);
		scorePlayer1=hasil;
		
	}else if(player==2){
		for(i=0;i<4;i++){
			if(cardPlayer2[i]%10==3){
				jml_lo=jml_lo+cardPlayer2[i]/10;	
			}else if(cardPlayer2[i]%10==4){
				jml_th=jml_th+cardPlayer2[i]/10;
			}else if(cardPlayer2[i]%10==5){
				jml_kr=jml_kr+cardPlayer2[i]/10;
			}else{
				jml_sk=jml_sk+cardPlayer2[i]/10;
			}
		}		
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("				Player 2  :  %d",hasil);
		scorePlayer2=hasil;
		
	}else{
		for(i=0;i<4;i++){
			if(cardPlayer3[i]%10==3){
				jml_lo=jml_lo+cardPlayer3[i]/10;	
			}else if(cardPlayer3[i]%10==4){
				jml_th=jml_th+cardPlayer3[i]/10;
			}else if(cardPlayer3[i]%10==5){
				jml_kr=jml_kr+cardPlayer3[i]/10;
			}else{
				jml_sk=jml_sk+cardPlayer3[i]/10;
			}
		}
		susunan[0]=jml_lo;susunan[1]=jml_th;susunan[2]=jml_kr;susunan[3]=jml_sk;
	
		for(i=0; i<4; i++){
    	    for(j=i+1; j<4; j++){
	            if(susunan[i]/10>susunan[j]/10){
	                temp = susunan[i];
	                susunan[i] = susunan[j];
	                susunan[j] = temp;
	            }
	        }        
	    }
	    hasil=susunan[3]-susunan[2]-susunan[1]-susunan[0];	    
		printf("				Player 3  :  %d",hasil);
		scorePlayer3=hasil;
		
		printf("\n______________________________________________________________________________\n");
	}	
	
}
void menang_tak_pasti(int scorePlayer1, int scorePlayer2, int scorePlayer3){	//Modul ini berfungsi untuk menampilkan tampilan jika player kalah ataupun menang.                                                                           
	if(scorePlayer1<scorePlayer2){
		printf("     ***     ***  ***    ***    ***     ***        ***     ******  *******\n");
		printf("      ***   *** **   **  ***    ***     ***      **   **  **       *******\n");
		printf("       *** *** **     ** ***    ***     ***     **     ** **       **     \n");
		printf("        *****  **     ** ***    ***     ***     **     **  *****   ****   \n");
		printf("         ***   **     ** ***    ***     ***     **     **       ** **     \n");
		printf("         ***    **   **   ***  ***      *******  **   **        ** *******\n");
		printf("         ***      ***      ******       *******    ***     ******  *******\n");
	}else if(scorePlayer1<scorePlayer3){
		printf("     ***     ***  ***    ***    ***     ***        ***     ******  *******\n");
		printf("      ***   *** **   **  ***    ***     ***      **   **  **       *******\n");
		printf("       *** *** **     ** ***    ***     ***     **     ** **       **     \n");
		printf("        *****  **     ** ***    ***     ***     **     **  *****   ****   \n");
		printf("         ***   **     ** ***    ***     ***     **     **       ** **     \n");
		printf("         ***    **   **   ***  ***      *******  **   **        ** *******\n");
		printf("         ***      ***      ******       *******    ***     ******  *******\n");
	}else{
		printf("     ***     ***  ***    ***    ***     ***       *** *** ***   ***\n");
		printf("      ***   *** **   **  ***    ***     ***       *** *** ****  ***\n");
		printf("       *** *** **     ** ***    ***     ***       *** *** ***** ***\n");
		printf("        *****  **     ** ***    ***     *** ***** *** *** *********\n");
		printf("         ***   **     ** ***    ***     ****** ****** *** *** *****\n");
		printf("         ***    **   **   ***  ***      *****   ***** *** ***  ****\n");
		printf("         ***      ***      ******       ****     **** *** ***   ***\n");
	}
}
void cara_main(){		//modul ini berfungsi untuk menampilkan cara bermain permainan 41an
system("cls");
	logoGame();
	FILE *f_caramain;
	char cara[panjang];
	
	f_caramain = fopen("caramain.txt", "rt");
	
	while((fgets(cara, panjang, f_caramain)) != NULL)
	printf("%s\r", cara);
	
	fclose(f_caramain);
	system("pause");
}
void about(){			//modul ini berfungsi untuk menampilkan informasi mengenai para pembuat game 41an
	system("cls");
	logoGame();
	FILE *f_about;
	char about[panjang];
	
	if((f_about=fopen("about.txt", "rt")) == NULL)
	{
		printf("File tidak dapat dibuk.\n");
		exit(1);
	}
	printf("\n");
	
	while((fgets(about, panjang, f_about)) != NULL)
	printf("%s\r", about);
	      
	fclose(f_about);
	system("pause"); 
}
void urut_kartu(){		//modul ini berfungsi untuk mengurutkan kartu player 1
	for(i=0; i<=3; i++){
	        for(j=i+1; j<=3; j++){
	            if(cardPlayer1[i]/10>cardPlayer1[j]/10){
	                temp = cardPlayer1[i];
	                cardPlayer1[i] = cardPlayer1[j];
	                cardPlayer1[j] = temp;
	            }
	        }        
	    }
}
void identitas(){
	int i;
	system("cls");		//modul ini berfungsi untuk menginput nama player 1
	printf("Nama Player: ");
	scanf("%s", &rekap.name);
	printf("Halo, %s\n", rekap.name); 

}
void logoGame(){		// modul ini berfungsi untuk tampilan game 41an
		printf("______________________________________________________________________________\n");
		printf("______________________________________________________________________________\n");
		printf("______________________________________________________________________________\n");
		printf("______________________________________________________________________________\n");
		printf("_                                                                            _\n");
		printf("_                                                                            _\n");
		printf("_                    _________     _________ _________                       _\n");
		printf("_                    | %c   __|_____| \%c   \%c | | \%c   \%c |                       _\n",7+80,8+80,8+80,7+80,7+80);
		printf("_                    |     | \%c    _|_____  | |       |                       _\n",9+80,7+80,7+80);
		printf("_                    |   \%c |     |     \%c | |_|_\%c___\%c |                       _\n",7+80,10+80,7+80,7+80);
		printf("_                    |     |   \%c |       | |       | |                       _\n",9+80);
		printf("_                    |_\%c___|     |   \%c   |_|       |_|                       _\n",7+80,10+80);
		printf("_                          |_\%c___|       | |   \%c   |                         _\n",9+80,8+80);
		printf("_                                |_\%c_____| |       |                         _\n",10+80);
		printf("_                                          |_______|                         _\n");
		printf("_                                                                            _\n");
		printf("_                KARTU 41an Kelompok 8 D3-Teknik Informatika                 _\n");
		printf("_                       POLITEKNIK NEGERI BANDUNG                            _\n");
		printf("______________________________________________________________________________\n");		
		printf("______________________________________________________________________________\n");
		printf("______________________________________________________________________________\n");
		printf("______________________________________________________________________________\n");
				
}
void rekapPlayer(){		//modul ini berfungsi untuk merekap nama dan skor pemain 1
	
	//Menginput riwayat permainan ke File rekap.DAT setelah player menyelesaikan permainan 
	FILE *fadd = fopen("rekap.DAT", "ab+");
	rekap.score = scorePlayer1;

	fwrite(&rekap, sizeof(rekap), 1, fadd);
	fclose(fadd);
}
void tampilRekap(){		//modul ini berfungsi untuk menampilkan hasil rekapan nama dan skor pemian 1
	system("cls");
	FILE *f_show =fopen("rekap.DAT","rb+");
	printf("=============================================\n");
	printf("Nama\t\t\tScore\n");
	printf("=============================================\n");
	rewind (f_show);
	while ( (fread(&rekap, sizeof(rekap), 1, f_show)) == 1 ){
		printf("%s\t\t\t  %d\n", rekap.name ,rekap.score);
	}
	printf("=============================================\n");
	fclose(f_show);
	system("pause");
}
void gotoxy(int x, int y){	// modul ini berfungsi untuk mengatur koordinasi letak loading
	HANDLE handle;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}
void loading (int x, int y){// modul ini berfungsi untuk menampilkan fitu loading sebelum ke tampilan menu
	system("cls");
	int i;
	gotoxy(x,y-1);
	printf("Loading...");
	for (i=x;i<=x+19;i++){
		gotoxy (i,y);
		printf ("%c", 196);
		gotoxy (i, y+1);
		printf ("%c", 196);
	}
	for (i=y; i<y+1;i++){
		gotoxy (x,i);
		printf ("%c", 179);
		gotoxy (x+19,i);
		printf ("%c", 179);		
	}
	gotoxy(x,y);
	printf ("%c", 218);
	gotoxy(x+19,y);
	printf ("%c", 191);	
	gotoxy(x,y+1);
	printf ("%c", 192);	
	gotoxy(x+19,y+1);
	printf ("%c", 217);
	for (i=x; i<=x+19;i++){
		gotoxy(i,y);
		printf ("%c", 220);	
		gotoxy(i,y+1);
		printf ("%c", 223);
		Sleep(100);
	}
	system("cls");
}
void kecepatan(float seconds){	//modul ini berfunsi untuk mengatur kecepatan atau lamanya loading2
	clock_t endwait;
	endwait=clock()+seconds*CLOCKS_PER_SEC;
	while(clock()<endwait){
	};
}
void loading2(){		//modul ini berfungsi untuk menampilkan simbol titik (.) yang akan mendukung proses dari procedure loadgame(). 
	for(int t = 1; t<10;t++){
		printf(".");
		kecepatan(0.3);
	}
}
void loadgame(int playerke){ // modul ini berfungsi untuk menampilkan fitur tampilan loading ketika player 1 menunggu player yang lainnya bermain.
	printf("Menunggu player %d", playerke);					
	loading2();
}
