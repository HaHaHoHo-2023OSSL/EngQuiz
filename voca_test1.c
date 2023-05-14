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

// 메뉴 선택 함수 1
int selectMenu_1(){
    int menu;
    
    printf("\n*** HaHoVOCA ***\n");
    printf(" 1| 회원가입\n");
    printf(" 2| 로그인\n");
    printf(" 0| 프로그램 종료\n");
    printf(">> ");

    scanf(" %d", &menu);
    getchar();  // 엔터 중복 입력 방지
    
    return menu;
}

// 메뉴 선택 함수 2
int selectMenu_2(){
    int menu;
    
    printf("\n*** HaHoVOCA ***\n");
    printf(" 1| 단어장 조회 ");
    printf(" 2| 단어 추가 ");
    printf(" 3| 단어 수정\n");
    printf(" 4| 단어 삭제   ");
    printf(" 5| 단어 검색 ");
    printf(" 6| 단어 저장\n");
    printf(" 7| 퀴즈 1      ");
    printf(" 8| 퀴즈 2    ");
    printf(" 0| 로그아웃\n");
    printf(">> ");

    scanf(" %d", &menu);
    getchar();  // 엔터 중복 입력 방지
    
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

// 퀴즈 1
int quiz1 (Voca *v[], int index){

    if (index == 0){
        printf("저장된 단어가 없습니다.");
        return 1;
    }

    srand(time(NULL)); // 난수 생성을 위한 시드 설정
    int randomIndex = rand() % index; // 랜덤한 인덱스 선택

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

        int count = 0, menu, num, isDeleteOK;

        while(status){
            menu = selectMenu_2();    // 메뉴 선택
            printf("\n");

            // 프로그램 처음 실행 시에는 메뉴 1, 3, 4는 실행 못함
            if (menu == 1 || menu == 3 || menu == 4) {
                if (temp->index == 0) {
                    printf("=> 조회할 단어가 없습니다!\n");
                    continue;
                }
            }

            // 메뉴 0 : 로그아웃
            if (menu == 0) break;

            // 메뉴 1 : 단어장 조회
            else if (menu == 1){
                listWord(temp->voca, temp->index);
            }

            // 메뉴 2 : 단어 추가
            else if (menu == 2){
                temp->voca[temp->index] = (Voca *)malloc(sizeof(Voca));
                count += addWord(temp->voca[temp->index++]);

                printf("=> 추가됨!\n");
            }
                    
            // 메뉴 3 : 점수 수정
            else if (menu == 3) {
                num = selectDataNo(temp->voca, temp->index);
                if (num == 0) {
                    printf("=> 취소됨!\n");
                    continue;
                }
                updateWord(temp->voca[num - 1]);
            }

            // 메뉴 4 : 점수 삭제
            else if (menu == 4) {
                num = selectDataNo(temp->voca, temp->index);

                if (num == 0) {
                    printf("=> 취소됨!\n");
                    continue;
                }

                printf("정말로 삭제하시겠습니까?(삭제 :1)");
                scanf("%d", &isDeleteOK);

                if (isDeleteOK == 1) {
                    if (temp->voca[num - 1]) free(temp->voca[num - 1]);
                    temp->voca[num - 1] = NULL;
                    count--;
                    printf("=> 삭제됨!\n");
                }
            }

            // 메뉴 5 : 이름 검색
            else if (menu == 5) {
                searchName(temp->voca, temp->index);
            }

            // 메뉴 5 : 파일 저장
            else if (menu == 6) {
                printf("=> 아직이에요!\n");
                // saveData(temp->voca, temp->index);
            }

            // 메뉴 7 : 퀴즈1
            else if (menu == 7) {
                quiz1(temp->voca, temp->index);
            }

            // 메뉴 8 : 퀴즈2
            else if (menu == 8) {
                quiz2(temp->voca, temp->index);
            }
        }
    }

    printf("종료됨!\n");

    return 0;
}
