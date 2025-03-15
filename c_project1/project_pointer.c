#include <stdio.h>
#include <time.h>

// 물고기 게임 프로젝트
// 전역 변수
int level;
int arrayFish[6];
int * cursor; // 물고기 가르키기
// my function
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
// main function
int main(void)
{
    long startTime = 0; // 게임 시작 시간
    long totalElapsedTime = 0; // 총 경과 시간 간격
    long prevElapsedTime= 0; // 직전 경과 시간 (최근에 물을 준 시간 간격)
    int num; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
    initData();
    cursor = arrayFish; // cursor[0]... cursor[1]

    startTime = clock(); // 현재 시간을 millisecond (1/1000초) 단위로 반환
    while(1)
    {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요?\n");
        scanf_s("%d",&num);

        // input check
        if (num < 1 || num > 6)
        {
            printf("\n 입력값이 잘못됐습니다.\n");
            continue;
        }
        // 총 경과 시간 간격
        totalElapsedTime = (clock()-startTime) / CLOCKS_PER_SEC;
        printf("total delay time : %1d sec\n", totalElapsedTime);

        // 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("recent delay time : %1d sec\n", prevElapsedTime);
    
        // 어항의 물을 감소 (증발)
        decreaseWater(prevElapsedTime);

        // 사용자가 입력한 어항에 물을 준다
        // 1. 어항의 물이 0이면? 물 주지 않는다.
        if ( cursor[num-1]<=0)
        {
            printf("%d번 물고기는 이미 죽었습니다.",num);
        }
        // 2. 어항의 물이 0이 아닌 경우? 물을 준다! 단,100을 넘지 않는지 체크
        // 현재 어항의 물 + 1 <=100
        else if (cursor[num-1]<=100)
        {
            printf("%d번 어항에 물을 줍니다\n\n",num);
            cursor[num-1] += 1;
        }
        // 레벨업을 할 지 확인 (레벨업은 20초마다 한버씩 수행)
        if (totalElapsedTime / 20 >= level - 1)
        {
            level++;
            printf("*** level up! %d level -> %d level ***\n\n",level-1,level);
            if (level == 5)
            {
                printf("\n\n good! higest level is recorded. the end");
                exit(0); // 프로그램 종료
            }
        }
        // 모든 물고기 죽은지 확인
        if (checkFishAlive() == 0)
        {
            printf("모든 물고기 죽음\n"); //물고기 모두 죽음
            exit(0); // 프로그램 종료
        }
        else
        {
            printf("물고기가 아직 살아있음\n"); //최소 한마리 물고기 존재
        }
        prevElapsedTime = totalElapsedTime;
        // 10sec -> 15sec (5sec : prevElapsedTime) -> 25sec (10sec : prevElapsedTime)
        // 15sec 을 prevElapsedTime에 넣어야됨 그래서 위의 코드를 작성
    }
    return 0;
}

// my function definition
void initData()
{
    level = 1; // 게임 레벨(1~5)
    for (int i = 0; i<6; i++)
    {
        arrayFish[i] = 100; // 어항의 물 높이
    }
}
void printfFishes()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n",1,2,3,4,5,6);
    for (int i=0; i<6; i++)
    {
        printf(" %4d ",arrayFish[i]);
    }
    printf("\n\n");
}
void decreaseWater(long elapsedTime)
{
    for(int i = 0; i<6; i++)
    {
        arrayFish[i] -= (level*3*(int)elapsedTime); // 3은 난이도 조절을 위한 값
        if (arrayFish[i] <0 )
        {
            arrayFish[i] = 0;
        }
    }
}
int checkFishAlive()
{
    for(int i =0; i<6; i++)
    {
        if (arrayFish[i]>0)
        return 1; // 참 True
    }
    return 0;
}