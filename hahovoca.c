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

// 메뉴 선택 함수
int selectMenu(){
    int menu;
    
    printf("\n\u256D\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500 HaHoVOCA \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256E\n");
    printf(" 1| 단어장 조회");
    printf(" 2| 단어 추가    ");
    printf(" 3| 단어 수정\n");
    printf(" 4| 단어 삭제  ");
    printf(" 5| 단어장 저장  ");
    printf(" 6| 단어 검색\n");
    printf(" 0| 종료\n");
    printf("\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256F\n");
    printf("\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\u2504\n");
    printf(">> ");
    scanf("%d", &menu);
    getchar();
    
    return menu;
}

// 데이터 번호 선택 함수
int selectDataNo(Voca *v[], int index){
    int num;
    listWord(v, index);

    printf("번호는 (취소 :0)? ");
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

// 파일에 저장
void saveData(Voca *v[], int index){
    FILE *fp;
    fp = fopen("voca.txt", "wt");

    for (int i = 0; i < index; i++){
        if(v[i] == NULL) continue;
        fprintf(fp, "%s %s\n", v[i]->word, v[i]->meaning);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

// 파일 읽기
int loadData(Voca *v[]){    
    int i = 0;
    FILE *fp;
    fp = fopen("voca.txt", "rt");

    if(fp == NULL) {
        printf("=> 파일 없음\n");
        return 0;
    }

    for(i = 0; i < 100; i++){
        v[i] = (Voca *)malloc(sizeof(Voca));
        
        fscanf(fp, " %s", v[i]->word);
        if(feof(fp)) break;

        fscanf(fp, " %s", v[i]->meaning);
    }

    fclose(fp);
    printf("=> 로딩 성공!\n");

    return i;
}

// ******************************************** //

int main(void){
    Voca *v[50];
    int index = 0, count = 0, menu, num, isDeleteOK;

    count = loadData(v);       // 파일 읽기
    index = count;

    while (1){
        menu = selectMenu();    // 메뉴 선택
        printf("\n");

        // 메뉴 0 : 프로그램 종료
        if (menu == 0) break;

        // 프로그램 처음 실행 시에는 메뉴 1, 3, 4는 실행 못함  
        if(menu == 1 || menu == 3 || menu == 4){
            if(count == 0) {
                printf("=> 조회할 단어가 없습니다!\n");
                continue;
            }
        }

        // 메뉴 1 : 점수 조회
        if (menu == 1){
            listWord(v, index);
        }

        // 메뉴 2 : 점수 추가
        else if (menu == 2){
            v[index] = (Voca *)malloc(sizeof(Voca));
            count += addWord(v[index++]);

            printf("=> 추가됨!\n");
        }

        // 메뉴 3 : 점수 수정
        else if (menu == 3){
            num = selectDataNo(v, index);
            if (num == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateWord(v[num - 1]);
        }

        // 메뉴 4 : 점수 삭제
        else if (menu == 4){
            num = selectDataNo(v, index);
            
            if (num == 0){
                printf("=> 취소됨!\n");
                continue;
            }

            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &isDeleteOK);
            
            if (isDeleteOK == 1){
                if(v[num - 1]) free(v[num - 1]);
                v[num - 1] = NULL;
                count--;
                printf("=> 삭제됨!\n");
            }
        }

        // 메뉴 5 : 파일 저장
        else if (menu == 5){
            saveData(v, index);
        }

        // 메뉴 6 : 이름 검색
        else if (menu == 6){
            searchName(v, index);
        }
    }

    printf("종료됨!\n");

    return 0;
}
