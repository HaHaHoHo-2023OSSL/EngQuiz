#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char word[10];
    char meaning[10];
} Voca;

typedef struct{
    int id;
    int index;
    Voca *voca[50];
} User;

// Create
int addWord(Voca *v){
    
    printf("단어 : ");
    scanf(" %s", v->word);

    printf("의미 : ");
    scanf(" %s", v->meaning);

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

// 메뉴 선택 함수 1
int selectMenu_1(){
    int menu;
    
    printf("\n*** HaHoVOCA ***\n");
    printf(" 1| 회원가입\n");
    printf(" 2| 로그인\n");
    printf(" 0| 프로그램 종료\n");
    printf(">> ");

    scanf("%d", &menu);
    getchar();
    
    return menu;
}

// 메뉴 선택 함수 2
int selectMenu_2(){
    int menu;
    
    printf("\n*** HaHoVOCA ***\n");
    printf(" 1| 단어장 조회\n");
    printf(" 2| 단어 추가\n");
    printf(" 0| 로그아웃\n");
    printf(">> ");

    scanf("%d", &menu);
    getchar();
    
    return menu;
}

// ******************************************** //

int main(void){
    User *user[10];
    User *temp;
  
    int id_input;
    int menu_;
    int user_index = 0;

    while(1){
        int status = 0;

        menu_ = selectMenu_1();

        if(menu_ == 0) break;

        if(menu_ == 1){
            printf("\n*** HaHoVOCA 회원가입 화면 ***\n");

            user[user_index] = (User *)malloc(sizeof(User));
            user[user_index]->index = 0;
            
            printf("ID 입력 : ");
            scanf(" %d", &user[user_index]->id);

            user_index++;

            printf("=> 회원가입 완료\n");
        }

        if(menu_ == 2){
            while(1){

                printf("\n*** HaHoVOCA 로그인 화면 ***\n");
                printf("ID를 입력하세요 (돌아가기 -1): ");
                scanf(" %d", &id_input);

                if(id_input == -1) break;
                
                for(int i = 0; i < user_index; i++){
                    if(user[i]->id == id_input){
                        printf("=> 로그인 성공!\n");
                        temp = user[i];
                        status = 1;
                        break;
                    }
                }

                if(status == 0){
                    printf("=> 다시 입력해주세요\n");
                    continue;
                } else break;
            }
        }

        int count = 0, menu;

        while(status){
            menu = selectMenu_2();    // 메뉴 선택
            printf("\n");

            // 메뉴 0 : 로그아웃
            if (menu == 0) break;

            // 메뉴 1 : 단어장 조회
            if (menu == 1){
                listWord(temp->voca, temp->index);
            }

            // 메뉴 2 : 단어 추가
            else if (menu == 2){
                temp->voca[temp->index] = (Voca *)malloc(sizeof(Voca));
                count += addWord(temp->voca[temp->index++]);

                printf("=> 추가됨!\n");
            }
        }
    }

    printf("종료됨!\n");

    return 0;
}
