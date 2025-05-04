#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[20]; // 포인터로 쓰면 안되는 이유 : Items 의 크기가 달라져서가 아니라(포인터만의 크기가 있기에 달라지지 않는다) *name 이 가리키는 주소가 없기에 scanf 가 넣어줄 주소가 없다!
} Items;

int main(void)
{
    int num;
    printf("아이템 수를 입력 :");
    scanf("%d",&num);

    Items * score;
    score = malloc(num*sizeof(Items));

    int sum = 0;

    for (int i=0; i<num; i++)
    {
        printf("\nenter item'id and name ");
        printf("id : ");
        scanf("%d",&score[i].id);
        getchar();
        printf("name : ");
        scanf("%s",score[i].name);
        printf("\n");
        sum = sum + score[i].id;
    }

    for (int i = 0; i<num; i++)
    {
        printf("items struct arr -> id : %d, name : %s\n",score[i].id,score[i].name);
    }

    printf("총 수량 : %d",sum);

    free(score);
    return 0;
}