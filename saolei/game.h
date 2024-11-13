#include<stdio.h>
#include <stdlib.h>
#include <time.h> 



#define ROW 9
#define COL 9
#define COLS 11
#define ROWS 11
void Initboard(char as[ROWS][COLS] ,int row ,int col, char ad);
void Displayboard(char af[ROWS][COLS],int h ,int l);
void setlei(char ae[ROWS][COLS],int a,int c);
void findlei(char nb[ROWS][COLS] ,char mb[ROWS][COLS]);
void baozha(char nc[ROWS][COLS],char mc[ROWS][COLS], int x,int y);
int getlei(char ng[ROWS][COLS], int x,int y,int q);