#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "level.h"

void levelThree(int n, int **tabPlayer, int z){
	srand(time(NULL));
	white();printf("Nous allons commencer les lancés...\n");reset();
	sleep(2);
	for(int i=0; i<n-4; i++){
		purple();printf("Tour du joueur %d de lancer les dés...\n", i+1);reset();
		sleep(3);
		for(int j=z; j<z+5; j++){
			tabPlayer[i][j] = (rand()%(6-1+1)+1);
			white();printf("[%d]", tabPlayer[i][j]);reset();
		}
		printf("\n");
	}
}

void sumLevel1(int **total, int **tabPlayer, int n, int z){
	int sum=0;
	for(int i=0; i<n-4; i++){
		for (int j=z; j<z+5; j++)
		{
			sum +=tabPlayer[i][j];
		}
		total[i][2] = sum;
		sum = 0;
	}
}

void sumLevel2(int **total, int **tabPlayer, int n, int z){
	int sum=0;
	for(int i=0; i<n-4; i++){
		for (int j=z; j<z+5; j++)
		{
			sum +=tabPlayer[i][j];
		}
		total[i][3] = sum;
		sum = 0;
	}
}

void sumLevel3(int **total, int **tabPlayer, int n, int z){
	int sum=0;
	for(int i=0; i<n-4; i++){
		for (int j=z; j<z+5; j++)
		{
			sum +=tabPlayer[i][j];
		}
		total[i][4] = sum;
		sum = 0;
	}
}

void afficheTotal3(int **tab, int n){
	for(int i=0; i<n; i++){
		if(i<1){
			qalif();
		}
		else if(i>0 && i<2){
			elim();
		}
		else{
			nogame();
		}
		for(int j=2; j<3; j++){
			printf("[%d]", tab[i][j]);
		}
		reset();
		printf("\n");
	}	
}

void afficheTab3(int **tab, int n, int z){
	for(int i=0; i<n; i++){
		for(int j=z; j<z+5; j++){
			white();printf("[%d]", tab[i][j]);reset();
		}
		reset();
		printf("\n");
	}
}

void triThree1(int **total, int n){
	int temp=0;
	for(int i=0; i<n-4; i++){
		if(total[i][2] < total[i+1][2]){
			temp = total[i][2];
			total[i][2] = total[i+1][2];
			total[i+1][2] = temp;
		}
	}
}

void triThree2(int **total, int n){
	int temp=0;
	for(int i=0; i<n-4; i++){
		if(total[i][3] < total[i+1][3]){
			temp = total[i][3];
			total[i][3] = total[i+1][3];
			total[i+1][3] = temp;
		}
	}
}

void triThree3(int **total, int n){
	int temp=0;
	for(int i=0; i<n-4; i++){
		if(total[i][4] < total[i+1][4]){
			temp = total[i][4];
			total[i][4] = total[i+1][4];
			total[i+1][4] = temp;
		}
	}
}
void final(int **total, int n){
	int sum=0;
	for(int i=0; i<n-4; i++){
		for(int j=2; j<5; j++)
		{
			sum +=total[i][j];
		}
		total[i][5] = sum;
		sum = 0;
	}
	
	for(int i=0; i<n; i++){
		if(i<1){
			qalif();
		}
		else if(i>0 && i<2){
			elim();
		}
		else{
			nogame();
		}
		for(int j=5; j<n; j++){
			printf("[%d]", total[i][j]);
		}
		reset();
		printf("\n");
	}	

	printf("Après vérification\n");
	int temp=0;
	for(int i=0; i<n-4; i++){
		if(total[i][5] < total[i+1][5]){
			temp = total[i][5];
			total[i][5] = total[i+1][5];
			total[i+1][5] = temp;
		}
	}

	for(int i=0; i<n; i++){
		if(i<1){
			qalif();
		}
		else if(i>0 && i<2){
			elim();
		}
		else{
			nogame();
		}
		for(int j=5; j<n; j++){
			printf("[%d]", total[i][j]);
		}
		reset();
		printf("\n");
	}
	
}

void verification3(int **tab, int n, int z){
	for(int i=0; i<n-4; i++){
		if(tab[i][2] == 30){
			printf("Joueur %d Vous avez gagné!!!!", i+1);
			exit(1);
		}
	}
}

