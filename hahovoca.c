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
