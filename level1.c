#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "level.h"

void somme1(int **total, int **tabPlayer, int n){
	int sum=0;
	for(int i=0; i<n; i++){
		for (int j=0; j<3; j++)
		{
			sum +=tabPlayer[i][j];
		}
		total[i][0] = sum;
		sum = 0;
	}

}

void levelOne(int n, int **tabPlayer){
	srand(time(NULL));
	white();printf("Nous allons commencer les lancés...\n");reset();
	sleep(2);
	for(int i=0; i<n; i++){
		purple();printf("Tour du joueur %d de lancer les dés...\n", i+1);reset();
		sleep(3);
		for(int j=0; j<3; j++){
			tabPlayer[i][j] = (rand()%(6-1+1)+1);
			white();printf("[%d]", tabPlayer[i][j]);reset();
		}
		printf("\n");
	}
}
	
void afficheTotal1(int **tab, int n){
	for(int i=0; i<n; i++){
		if(i<4){
			qalif();
			printf("J%d", i+1);
		}
		else{
			elim();
			printf("J%d", i+1);
		}
		for(int j=0; j<1; j++){
			printf("[%d]", tab[i][j]);
		}
		reset();
		printf("\n");
	}	
}

void tri(int **total, int n){
	int temp=0, t;
	for(int i=0; i<n-1; i++){
		if(total[i][0] < total[i+1][0]){
			temp = total[i][0];
			total[i][0] = total[i+1][0];
			total[i+1][0] = temp;	
		}
	}
}

void afficheTab1(int **tab, int n){
	for(int i=0; i<n; i++){
		printf("J%d", i+1);
		for(int j=0; j<3; j++){
			white();printf("\t[%d]", tab[i][j]);reset();
		}
		printf("\n");
	}
}

void verification(int **total, int n){
	int count=0;
	for(int i=0; i<n-1; i++){
		if(total[i][0] < total[i+1][0]){
			count++;
		}
	}

	printf("%d", count);
}
