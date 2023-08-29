#include <stdio.h>
#include "level.h"

void yellow(){
	printf("\033[1;33m");
}

void red(){
	printf("\033[1;31m");
}

void green(){
	printf("\033[1;32m");
}

void white(){
	printf("\033[1;38m");
}

void blue(){
	printf("\033[1;34m");
}

void cyan(){
	printf("\033[1;36m");
}

void purple(){
	printf("\033[1;35m");
}

void reset(){
	printf("\033[0m");
}

void qalif(){
	printf("\033[1;42m");
}

void elim(){
	printf("\033[1;41m");
}
void nogame(){
	printf("\033[1;47m");
}
