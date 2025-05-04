#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// global_val
int arr_animal[4][5] = -1; // 뒷면을 -1로 표시
int check_animal[4][5] = 0; // 앞면을 0으로 표시 , 1 이면 뒷면으로 생각?
char *str_animal[10] = {
    "하마",
    "끼리코",
    "나무늘보",
    "사자",
    "호랑이",
    "고릴라",
    "원숭이",
    "타잔",
    "심장",
    "핏줄"
};
// my_func
void printQuestion(); // 현재 카드 상황을 보여주기
void shuffle_animal(); // (비어있는) randpos 얻고 랜덤하게 배치
int getemptyposition(); // -1(뒷면)인 위치를 얻는 함수
int conv_pos_x(int num);
int conv_pos_y(int num);
//main-------------------------------
int main(void)
{
    // 카드 뒤집기 게임
    srand(time(NULL));
    

    return 0;
}
// 정의
void printQuestion() 
{
    printf("----game start----\n\n");
    int seq = 0;
    for (int i = 0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (check_animal[i][j] == 1) // 앞면:1 일 경우
            {
                printf("8s",str_animal[arr_animal[i][j]]);
            }
            else // 뒷면:-1 일 경우 숫자 0으로 감추기기
            {
                printf("%8d",seq);
            }
        }
        seq++;
        printf("\n");
    }
    printf("\n");

}
void shuffle_animal() 
{
    for (int i = 0; i< 10; i++) // 0-9 까지한 이유는 stranimal 이 0-9니까
    {
        for (int j = 0; j<2; j++)
        {
            int pos = getemptyposition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arr_animal[x][y] = i; // 이제 더이상 -1이 아님
        }
    }
}
int getemptyposition() 
{   
    while (1)
    {
        int rand_pos = rand() % 20;
        int x = conv_pos_x(rand_pos);
        int y = conv_pos_y(rand_pos);
        if (arr_animal[x][y] == -1)
        {
            return rand_pos;
        }
    }
}
int conv_pos_x(int num)
{
    return num / 5;
}
int conv_pos_y(int num)
{
    return num % 5;
}