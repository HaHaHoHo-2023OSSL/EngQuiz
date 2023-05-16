    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

// 퀴즈 1
int quiz1 (Voca *v[], int index){

    if (index == 0){
        printf("저장된 단어가 없습니다.");
        return 1;
    }

    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % index; // 랜덤한 인덱스 선택

    while(v[randomIndex]->word == NULL){ // delete로 인해 NULL 값이 나온경우
        srand(time(NULL)); // 시드 재설정
        randomIndex = rand() % index; //랜덤 인덱스 재선택
    }

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

// 퀴즈 2
int quiz2 (Voca *v[], int index){

    if (index == 0){
        printf("저장된 단어가 없습니다.");
        return 1;
    }

    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % index; // 랜덤한 인덱스 선택

    while(v[randomIndex]->word == NULL){ // delete로 인해 NULL 값이 나온경우
        srand(time(NULL)); // 시드 재설정
        randomIndex = rand() % index; //랜덤 인덱스 재선택
    }


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
