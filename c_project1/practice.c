#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int num;
}Card;

int main(void)
{
    // 카드 5장을 랜덤으로 뽑아보자!
    Card Deck[52];
    char *name_list[] = {"클로버","다이아몬드","하트","스페이드"};
    return 0;
}
// 실수 모음
// 1. 배열 선언시 [] 비워두면 알아서 들어간다.