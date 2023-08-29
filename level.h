#ifndef _JEU_SIX_
#define _JEU_SIX_

//les Fonctions couleurs
void yellow();
void reset();
void red();
void green();
void blue();
void cyan();
void purple();
void white();
void qalif();
void elim();
void nogame();


//les Fonctions du Niveau 1
void somme1(int **total, int **tabPlayer, int n);
void levelOne(int n, int **tabPlayer);
void afficheTotal1(int **tab, int n);
void tri(int **total, int n);
void verification(int **total, int n);

//Les fonctions du Niveau 2
void levelTwo(int n, int **tabPlayer);
void somme2(int **total, int **tabPlayer, int n);
void afficheTotal2(int **tab, int n);
void triTwo(int **total, int n);
//void verifivation2(int **total, int n);

//Les fonctions du Niveau 3
void levelThree(int n, int **tabPlayer, int z);
void sumLevel3(int **total, int **tabPlayer, int n, int z);
void sumLevel2(int **total, int **tabPlayer, int n, int z);
void sumLevel1(int **total, int **tabPlayer, int n, int z);
void afficheTotal3(int **tab, int n);
void triThree1(int **total, int n);
void triThree2(int **total, int n);
void triThree3(int **total, int n);
void final(int **total, int n);
void verification3(int **tab, int n, int z);


//l'affichage
void afficheTab1(int **tab, int n) ;
void afficheTab2(int **tab, int n);
void afficheTab3(int **tab, int n, int z);

#endif 