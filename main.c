#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "level.h"

void afficheTab(int **tab, int n, int p){
	for(int i=0; i<n; i++){
		for(int j=0; j<p; j++){
			white();printf("[%d]", tab[i][j]);reset();
		}
		printf("\n\n");
	}
}

void main(void){
	
	int **tabPlayer;
	int **total;
	int n=6, p=21, z=7;

	tabPlayer = (int**)calloc(n, sizeof(int*));
	for(int i=0; i<n; i++){
		tabPlayer[i] = (int*)calloc(p, sizeof(int));
	}

	total = (int**)calloc(n, sizeof(int*));
	for(int i=0; i<n; i++){
		total[i] = (int*)calloc(n, sizeof(int));
	}
	
	green();printf("\t\tLE JEU DEMARRE...\n");reset();
	sleep(0.5);

	cyan();printf("\tNIVEAU 1...\n");reset();

	levelOne(n, tabPlayer);

	green();printf("\t  VOICI LES LANCES\n");reset();
	afficheTab1(tabPlayer, n);
	
	somme1(total, tabPlayer, n);
	for(int i=0; i<n-1; i++){
		tri(total, n);
	}
	afficheTotal1(total, n);
	

	int choix;
	printf("Passer au Niveau 2: 1.OUI  2.NON");
	scanf("%d", &choix);
	if(choix==1){
		goto level2;
	}
	else{
		while(choix!=1){
			printf("Tapez 1 quand vous souhaitez passser au Niveau 2\n");
			scanf("%d", &choix);
		}
	}
	
	level2:
		cyan();printf("\tPASSAGE AU NIVEAU 2...\n");reset();
		sleep(3);
		system("clear");
		
		cyan();printf("\tNIVEAU 2...\n");reset();
		levelTwo(n, tabPlayer);

		green();printf("\t  \nVOICI LES LANCES\n");reset();
		afficheTab2(tabPlayer, n);
		
		somme2(total, tabPlayer, n);
		for(int i=0; i<n-1; i++){
			triTwo(total, n);
		}
		afficheTotal2(total, n);

		int choix1;
		printf("Passer au Niveau 3: 1.OUI  2.NON");
		scanf("%d", &choix1);
		if(choix1==1){
			goto level3;
		}
		else{
			while(choix1!=1){
				printf("Tapez 1 quand vous souhaitez passer au Niveau 3\n");
				scanf("%d", &choix1);
			}
		}

	level3:
		cyan();printf("\tPASSONS AU NIVEAU 3...\n");reset();
		sleep(3);
		system("clear");

		cyan();printf("\tNIVEAU 3...\n");reset();
		levelThree(n, tabPlayer, z);

		green();printf("\t  \nVOICI LES LANCES DU PREMIER TOUR\n");reset();
		afficheTab3(tabPlayer, n, z);

		sumLevel1(total, tabPlayer, n, z);
		triThree1(total, n);
		afficheTotal3(total, n);
		verification3(total, n, z);
		int mnc2;
		if(mnc2==1){
			goto manche2;
		}
		else{
			while(mnc2!=1){
				white();printf("Tapez 1 quand vous souhaitez passer à la seconde manche\n");reset();
				scanf("%d", &mnc2);
			}
		}

		manche2:
			z += 5;
			cyan();printf("\tMANCHE 2...\n");reset();
			levelThree(n, tabPlayer, z);

			green();printf("\t  \nVOICI LES LANCES DU SECOND TOUR\n");reset();
			afficheTab3(tabPlayer, n, z);

			sumLevel2(total, tabPlayer, n, z);
			triThree2(total, n);
			afficheTotal3(total, n);
			verification3(total, n, z);
			int mnc3;
			if(mnc3==1){
				goto manche3;
			}
			else{
				while(mnc3!=1){
					white();printf("Tapez 1 quand vous souhaitez passer à la troisième manche\n");reset();
					scanf("%d", &mnc3);
				}
			}

		manche3:
			z += 5;
			cyan();printf("\tMANCHE 3...\n");reset();
			levelThree(n, tabPlayer, z);

			green();printf("\t  \nVOICI LES LANCES DU TROISIEME TOUR\n");reset();
			afficheTab3(tabPlayer, n, z);

			sumLevel3(total, tabPlayer, n, z);
			triThree3(total, n);
			afficheTotal3(total, n);
			verification3(total, n, z);

		white();printf("\t  \nVOICI LE TOTAL DES TROIS MANCHES\n");reset();
		final(total, n);
	
	reset();
	return;
}