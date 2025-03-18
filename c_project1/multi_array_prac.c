#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5]; // 20장 카드
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인 (0: 안 뒤집힘, 1: 뒤집힘)
char *strAnimal[10];   // 동물 이름 배열

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int allCardsFlipped();

int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();
    shuffleAnimal();

    int failCount = 0;

    while (1)
    {
        int select1, select2;

        printAnimals();  // 디버깅용: 실제 동물 위치 출력
        printQuestion(); // 사용자에게 카드 상태 보여줌
        printf("뒤집을 카드를 2개 고르세요 (0-19): ");
        scanf("%d %d", &select1, &select2);

        // 입력값 유효성 검사
        if (select1 < 0 || select1 > 19 || select2 < 0 || select2 > 19)
        {
            printf("0에서 19 사이의 숫자를 입력하세요.\n");
            continue;
        }
        if (select1 == select2)
        {
            printf("같은 카드를 선택했습니다. 다른 카드를 골라주세요.\n");
            continue;
        }

        int x1 = conv_pos_x(select1);
        int y1 = conv_pos_y(select1);
        int x2 = conv_pos_x(select2);
        int y2 = conv_pos_y(select2);

        // 이미 뒤집힌 카드인지 확인
        if (checkAnimal[x1][y1] == 1 || checkAnimal[x2][y2] == 1)
        {
            printf("이미 뒤집힌 카드를 선택했습니다. 다시 골라주세요.\n");
            continue;
        }

        // 선택한 카드 보여주기
        printf("\n선택한 카드:\n");
        printf("카드 %d: %s\n", select1, strAnimal[arrayAnimal[x1][y1]]);
        printf("카드 %d: %s\n", select2, strAnimal[arrayAnimal[x2][y2]]);

        // 카드 비교
        if (arrayAnimal[x1][y1] == arrayAnimal[x2][y2])
        {
            printf("맞췄습니다! 카드가 뒤집힙니다.\n");
            checkAnimal[x1][y1] = 1;
            checkAnimal[x2][y2] = 1;
        }
        else
        {
            printf("틀렸습니다. 다음 기회에 다시 시도하세요.\n");
            failCount++;
        }

        // 모든 카드가 뒤집혔는지 확인
        if (allCardsFlipped())
        {
            printQuestion();
            printf("\n축하합니다! 모든 카드를 뒤집었습니다!\n");
            printf("실패 횟수: %d\n", failCount);
            break;
        }
    }

    return 0;
}

void initAnimalArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
            checkAnimal[i][j] = 0; // 초기화: 모두 뒤집히지 않은 상태
        }
    }
}

void initAnimalName()
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
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    while (1)
    {
        int randPos = rand() % 20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
}

int conv_pos_x(int x)
{
    return x / 5;
}

int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimals()
{
    printf("\n======= 비밀인데.. 몰래 보여줍니다.======\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");
}

void printQuestion()
{
    printf("\n\n 문제 \n");
    int seq = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 1)
            {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d", seq);
            }
            seq++;
        }
        printf("\n");
    }
    printf("\n");
}

int allCardsFlipped()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 0)
            {
                return 0; // 아직 뒤집히지 않은 카드가 있음
            }
        }
    }
    return 1; // 모든 카드가 뒤집힘
}