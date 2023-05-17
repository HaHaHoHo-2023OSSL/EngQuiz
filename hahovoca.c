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
        printf("%2d  ", count);
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

    printf("=> 수정 성공!\n");

    return 1;
}

// Delete
int deleteWord(Voca *v){

    v->word[0] = '\0';
    v->meaning[0] = '\0';
    printf("=> 삭제 완료!\n");

    return 1;
}

// 메뉴 선택 함수 1
int selectMenu_1(){
    int menu;
    
    printf("\n\u256D\u2500\u2500 HaHoVOCA Login Page \u2500\u2500\u256E\n");
    printf("\u07CB                         \u07CB\n");
    printf("      1| 회원가입\n");
    printf("      2| 로그인\n");
    printf("      0| 프로그램 종료\n");
    printf("\u07CB                         \u07CB");
    printf("\n\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256F\n");
    printf(">> ");

    scanf(" %d", &menu);
    getchar();  // 엔터 중복 입력 방지
    
    return menu;
}

// 메뉴 선택 함수 2
int selectMenu_2(){
    int menu;
    
    // printf("\n*** HaHoVOCA ***\n");
    printf("\n\u256D\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500 HaHoVOCA \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256E\n");
    printf("\u07CB                                            \u07CB\n");
    printf("  1| 단어장 조회 ");
    printf(" 2| 단어 추가 ");
    printf(" 3| 단어 수정\n");
    printf("  4| 단어 삭제   ");
    printf(" 5| 단어 검색 ");
    printf(" 6| 단어 저장\n");
    printf("  7| 퀴즈 1      ");
    printf(" 8| 퀴즈 2    ");
    printf(" 0| 로그아웃\n");
    printf("\u07CB                                            \u07CB");
    printf("\n\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256F\n");
    printf(">> ");

    scanf(" %d", &menu);
    getchar();  // 엔터 중복 입력 방지
    
    return menu;
}

// 데이터 번호 선택 함수
int selectDataNo(Voca *v[], int index){
    int num;
    listWord(v, index);

    printf("번호 입력 (취소 0) : ");
    scanf("%d", &num);

    return num;
}

// 이름 검색 함수
void searchName(Voca *v[], int index){
    int scnt = 0;
    char search[20];

    printf("검색 단어 : ");
    scanf("%s", search);

    printf("\nNo  Word  Meaning\n");
    printf("====================\n");
    
    int count = 0;
    for(int i = 0; i < index; i++){
        if(v[i] == NULL) continue;
        if(strstr(v[i]->word, search)){
            count++;
            printf("%2d ", count);
            readWord(*v[i]);
            scnt = 1;
        }
    }
    
    if (scnt == 0) printf("=> 검색된 데이터 없음!\n");
    printf("\n");
}

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

// 퀴즈 3
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


// 퀴즈 4
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

// 파일에 저장 함수
void saveData(Voca *v[], int index, int id){
    char filename[20];
    
    sprintf(filename, "%d", id);
    strcat(filename, ".txt");

    FILE *fp;
    fp = fopen(filename, "wt");

    for (int i = 0; i < index; i++){
        if(v[i] == NULL) continue;
        fprintf(fp, "%s %s\n", v[i]->word, v[i]->meaning);
    }

    fclose(fp);
    printf("=> 저장됨!\n");
}

// 파일 읽기 함수
int loadData(Voca *v[], int id){    
    int i = 0;

    char filename[20];
    
    sprintf(filename, "%d", id);
    strcat(filename, ".txt");

    FILE *fp;
    fp = fopen(filename, "rt");

    if(fp == NULL) {
        printf("=> 저장된 단어장 없음.\n");
        return 0;
    }

    for(i = 0; i < 100; i++){
        v[i] = (Voca *)malloc(sizeof(Voca));
        
        fscanf(fp, " %s", v[i]->word);
        if(feof(fp)) break;

        fscanf(fp, " %s", v[i]->meaning);
    }

    fclose(fp);
    printf("=> 단어장 불러오기 성공!\n");

    return i;
}

// 회원가입 함수
int signUp(User *u[], int user_index){
    printf("\n=====| HaHoVOCA 회원가입 |=====\n");

    u[user_index] = (User *)malloc(sizeof(User));
    u[user_index]->index = 0;
            
    printf("\u09F9 학번 입력 : ");
    scanf(" %d", &u[user_index]->id);

    printf("\n=> 회원가입 완료!\n");

    FILE *fp;
    fp = fopen("users.txt", "a+");
    fprintf(fp, "%d\n", u[user_index]->id);
    fclose(fp);

    return 1;
}

// 로그인 함수
int logIn(User *u[], int user_index, User **temp){
    int id_input, status = 0;

    printf("\n=====| HaHoVOCA 로그인 |=====\n");
    printf("\u09F9 학번 (돌아가기 -1) : ");
    scanf("%d", &id_input);

    if(id_input == -1) return -1;
                
    for(int i = 0; i < user_index; i++){
        if(u[i]->id == id_input){
            printf("\n=> 로그인 성공!\n");
            (*temp) = u[i];
            status = 1;
            break;
        }
    }

    return status;
}

// 회원 파일 조회 함수
int loadUserData(User *u[]){
    FILE *fp;
    fp = fopen("users.txt", "rt");

    if(fp == NULL) {
        printf("=> 현재 유저 0명\n");
        return 0;
    }

    int i;
    for(i = 0; i < 10; i++){
        u[i] = (User *)malloc(sizeof(User));
        
        fscanf(fp, "%d", &u[i]->id);
        if(feof(fp)) break;
    }

    printf("=> 현재 유저 %d명\n", i);
    fclose(fp);

    return i;
}
