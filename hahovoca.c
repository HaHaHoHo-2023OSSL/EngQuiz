#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    char word[10];
    char meaning[10];
} Voca;

typedef struct{
    int id;
    int index;
    Voca *voca[50];
    char *filename;
} User;
