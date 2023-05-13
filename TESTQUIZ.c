    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    typedef struct{
        char word[10];
        char meaning[10];
    } Voca;

    int addWord(Voca *v){
        fflush(stdin);
        printf("단어 : ");
        scanf("%s", v->word);
        
        fflush(stdin);
        printf("의미 : ");
        scanf("%s", v->meaning);

        return 1;
    }

int quiz(Voca *v[], int index){
    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % index; // 랜덤한 count 선택

    printf("단어 : %s\n", v[randomIndex]->word);

    char answer[10];
    printf("뜻을 입력하세요: ");
    scanf("%s", answer);

    if (strcmp(answer, v[randomIndex]->meaning) == 0) {
        printf("정답입니다!\n");
    } else {
        printf("오답입니다. 정답은 %s입니다.\n", v[randomIndex]->meaning);
    }

    return 1;
}

int quiz2 (Voca *v[], int index){
    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % index; // 랜덤한 인덱스 선택

    printf("뜻 : %s\n", v[randomIndex]->meaning);

    char answer[10];
    printf("뜻을 입력하세요: ");
    scanf("%s", answer);

    if (strcmp(answer, v[randomIndex]->word) == 0) {
        printf("정답입니다!\n");
    } else {
        printf("오답입니다. 정답은 %s입니다.\n", v[randomIndex]->word);
    }

    return 1;
}

int main(void){
  Voca *v[100];
  int index = 0;
  quiz(v, index);
}
