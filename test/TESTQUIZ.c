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
    printf("영어 철자를 입력하세요: ");
    scanf("%s", answer);

    if (strcmp(answer, v[randomIndex]->word) == 0) {
        printf("정답입니다!\n");
    } else {
        printf("오답입니다. 정답은 %s입니다.\n", v[randomIndex]->word);
    }

    return 1;
}

//퀴즈3
int quiz3() {
    int i = 0;
    Voca *v[100];
    FILE *fp;
    fp = fopen("database.txt", "rt");

    if (fp == NULL) {
        printf("=> 데이터 없음\n");
        return 0;
    }

    for (i = 0; i < 100; i++) {
        v[i] = (Voca *)malloc(sizeof(Voca));

        fscanf(fp, " %s", v[i]->word);
        if (feof(fp))
            break;

        fscanf(fp, " %s", v[i]->meaning);

    }

    fclose(fp);

    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % i; // 랜덤한 인덱스 선택

    printf("단어: %s\n", v[randomIndex]->word);

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


//퀴즈4
int quiz4() {
    int i = 0;
    Voca *v[100];
    FILE *fp;
    fp = fopen("database.txt", "rt");

    if (fp == NULL) {
        printf("=> 데이터 없음\n");
        return 0;
    }

    for (i = 0; i < 100; i++) {
        v[i] = (Voca *)malloc(sizeof(Voca));

        fscanf(fp, " %s", v[i]->word);
        if (feof(fp))
            break;

        fscanf(fp, " %s", v[i]->meaning);

    }

    fclose(fp);

    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % i; // 랜덤한 인덱스 선택

    printf("뜻: %s\n", v[randomIndex]->meaning);

    char answer[10];
    printf("영어 철자를 입력하세요: ");
    scanf("%s", answer);

    if (strcmp(answer, v[randomIndex]->word) == 0) {
        printf("정답입니다!\n");
    } else {
        printf("오답입니다. 정답은 %s입니다.\n", v[randomIndex]->word);
    }

    return 1;
}

            // 메뉴 7 : 자신의 단어장에서 퀴즈 출제
            else if (menu == 7) {

                int num = 0;

                printf("영어 철자를 맞출지 뜻을 맞출지 숫자를 입력해주세요. \n");
                printf("1: 영어 철자, 2: 뜻 \n");
                scanf("%d", &num);

                if (num == 1){ //퀴즈1 (영단어 -> 뜻)    
                    quiz1(temp->voca, temp->index);
                }
                else if (num == 2){ //퀴즈2 (뜻 -> 영단어)
                    quiz2(temp->voca, temp->index);
                }
                else {
                    printf("잘못 입력하셨습니다.");
                }
            }

            // 메뉴 8 : 데이터에서 퀴즈 출제
            else if (menu == 8) {

                int num = 0;

                printf("영어 철자를 맞출지 뜻을 맞출지 숫자를 입력해주세요. \n");
                printf("1: 영어 철자, 2: 뜻 \n");
                scanf("%d", &num);

                if (num == 1){ //퀴즈1 (영단어 -> 뜻)    
                    quiz3();
                }
                else if (num == 2){ //퀴즈2 (뜻 -> 영단어)
                    quiz4();
                }
                else {
                    printf("잘못 입력하셨습니다.");
                }
            }
