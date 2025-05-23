#include <stdio.h>
#include <time.h>

// 5마리 고양이
// 아무 키나 눌러서 랜덤으로 고양이를 뽑되,
// 5마리 모두 수집해서 키우는 게임
// 중복 발생 가능!

// 고양이
// 이름,나이,성격,키우기 난이도(레벨)

typedef struct {
    char * name; // 이름
    int age; // 나이
    char * character; // 성격
    int level; // 1-5
} CAT;

// 현재까지 보유한 고양이
int collection[5] = {0};

//전체 고양이 리스트
CAT cats[5];

// 내 함수
void initCats();
void printCat(int selected);
int checkcollection();
int main(void)
{
    srand(time(NULL));

    initCats(); // 고양이 정보 초기화
    while (1)
    {
        printf("어느 고양이의 집사가 될까요?\n아무키나 눌러서 확인하세요!\n\n");
        getchar();

        int selected = rand()% 5;
        printCat(selected);
        collection[selected] = 1;

        int collectALL = checkcollection();
        if (collectALL == 1)
        {
            break;
        }
    }


    return 0;
}

void initCats()
{
    cats[0].name = "깜냥이";
    cats[0].age = 5;
    cats[0].character = "온순";
    cats[0].level = 2;

    cats[1].name = "흰둥이";
    cats[1].age = 3;
    cats[1].character = "천사";
    cats[1].level = 1;

    cats[2].name = "수줍이";
    cats[2].age = 7;
    cats[2].character = "늘 잠만 잠";
    cats[2].level = 3;

    cats[3].name = "까꿍이";
    cats[3].age = 2;
    cats[3].character ="시끄러움";
    cats[3].level = 4;

    cats[4].name = "돼냥이";
    cats[4].age = 1;
    cats[4].character = "배고픔";
    cats[4].level = 5;


}
void printCat(int selected)
{
    printf("\n\n당신은 이 고양이의 집사가 되었어요!\n\n");
    printf("이름 : %s\n",cats[selected].name);
    printf("나이 : %d\n",cats[selected].age);
    printf("성격 : %s\n",cats[selected].character);
    printf("레벨 : ");

    for (int i=0; i<cats[selected].level; i++)
    {
        printf("%s","★");
    }
    printf("\n\n");
}

int checkcollection()
{
    int collectall = 1;
    printf("\n\n 보유한 고양이 목록이에요 \n\n");
    for (int i=0; i<5; i++)
    {
        if (collection[i] == 0)
        {
            printf("%10s","(빈 박스)");
            collectall = 0;
        }
        else
        {
            printf("%10s",cats[i].name);
        }
    }
    printf("\n================================\n\n");

    if (collectall == 1)
    {
        printf("축하합니다! 모든 고양이를 다 모았어요. 열심히 키워주세요!\n\n");
    }
    

    return collectall;
}