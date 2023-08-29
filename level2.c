#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "level.h"

//la fonction du niveau 2
void levelTwo(int n, int **tabPlayer){
	srand(time(NULL));
	white();printf("Nous allons commencer les lancés...\n");reset();
	sleep(2);
	for(int i=0; i<n-2; i++){
		purple();printf("Tour du joueur %d de lancer les dés...\n", i+1);reset();
		sleep(3);
		for(int j=3; j<7; j++){
			tabPlayer[i][j] = (rand()%(6-1+1)+1);
			white();printf("[%d]", tabPlayer[i][j]);reset();
		}
		printf("\n");
	}
}


void somme2(int **total, int **tabPlayer, int n){
	int sum=0;
	for(int i=0; i<n-2; i++){
		for (int j=3; j<7; j++)
		{
			sum +=tabPlayer[i][j];
		}
		total[i][1] = sum;
		sum = 0;
	}
}

void afficheTotal2(int **tab, int n){
	for(int i=0; i<n; i++){
		if(i<2){
			qalif();
			printf("J%d", i+1);
		}
		else if(i>1 && i<4){
			elim();
			printf("J%d", i+1);
		}
		else{
			nogame();
			printf("J%d", i+1);
		}
		for(int j=1; j<2; j++){
			printf("[%d]", tab[i][j]);
		}
		reset();
		printf("\n");
	}	
}

void triTwo(int **total, int n){
	int temp=0, t;
	for(int i=0; i<n-1; i++){
		if(total[i][1] < total[i+1][1]){
			temp = total[i][1];
			total[i][1] = total[i+1][1];
			total[i+1][1] = temp;
		}
	}
}

void afficheTab2(int **tab, int n){
	for(int i=0; i<n; i++){
		printf("J%d", i+1);
		for(int j=3; j<7; j++){
			white();printf("[%d]", tab[i][j]);reset();
		}
		reset();
		printf("\n");
	}
}
