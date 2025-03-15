#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5]; // 20장 cards
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인
char * strAnimal[10];


void initAnimalArray();
void initAnialName();
void shuffleAnimal();
int getEmptyPositon();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printfAnimals();
void printfQuestion();

int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnialName();

    shuffleAnimal();

    int failcount = 0;

    while (1)
    {
        // 사용자에게 값을 받는다
        int select1 = 0;
        int select2 = 0;

        printfAnimals(); // 동물 위치 출력
        printfQuestion(); // 문제 출력 (카드 지도)
        printf("뒤집을 카드를 2개 고르세요: ");
        scanf("%d %d",&select1,&select2); // scanf 다변수 가능한거였음??
        
        if (select1 == select2)
        {
            printf("다른 카드를 골라주세요\n");
            continue;
        }

    }
    return 0;
}

void initAnimalArray()
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            arrayAnimal[i][j]=-1;
        }
    }
}
void initAnialName()
{
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<2; j++)
        {
            int pos = getEmptyPositon();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}
// 좌표에서 빈 공간 찾기
int getEmptyPositon()
{
    while (1)
    {
        int randPos = rand() % 20; // 0-19 사이의 숫자 반환
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
    
        if(arrayAnimal[x][y] == -1) // 비어있음을 의미
        {
            return randPos;
        }
    }
    return 0;
}
int conv_pos_x(int x)
{
    return x/5;
}
int conv_pos_y(int y)
{
    return y%5;
}
void printfAnimals()
{
    printf("\n======= 비밀인데.. 몰래 보여줍니다.======\n\n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf("%8s",strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");
}
void printfQuestion()
{
    printf("\n\n 문제 \n");
    int seq = 0;
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            // 카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
            if (checkAnimal[i][j] != 0)
            {
                printf("%8s",strAnimal[arrayAnimal[i][j]]);
            }
            // 못 맞혔으면 뒷면인 위치를 나타내는 숫자를 보여주자.
            else
            {
                printf("%8d",seq);
            }
        }
    }
}