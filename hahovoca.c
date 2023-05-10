#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char word[10];
    char meaning[10];
} Voca;

// Create
int addWord(Voca *v){
    fflush(stdin);
    printf("단어 : ");
    scanf("%s", v->word);
    
    fflush(stdin);
    printf("의미 : ");
    scanf("%s", v->meaning);

    return 1;
}

// Read
void readWord(Voca v){
    printf("%s : %s\n", v.word, v.meaning);
}

// Read (다중 데이터)
void listWord(Voca *v[], int index){
    printf("\nNo  Word  Meaning\n");
    printf("====================\n");
    
    int count = 0;
    for(int i = 0; i < index; i++){
        if(v[i] == NULL) continue;
        count++;
        printf("%2d ", count);
        readWord(*v[i]);
    }
    printf("\n");
}

// Update
int updateWord(Voca *v){
    fflush(stdin);
    printf("새 단어 : ");
    scanf("%s", v->word);
    
    fflush(stdin);
    printf("새 의미 : ");
    scanf("%s", v->meaning);

    printf("=> 수정성공!\n");

    return 1;
}

// Delete
int deleteWord(Voca *v){

    v->word[0] = '\0';
    v->meaning[0] = '\0';
    printf("=> 단어 삭제\n");

    return 1;
}
