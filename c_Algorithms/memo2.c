#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Item;

int main(void)
{
    int n;
    printf("아이템 수를 입력하세요 :\n");
    scanf("%d",&n);
    Item *items = malloc(n*sizeof(Item));

    for (int i=0; i<n; i++)
    {
        printf("%d 번째 아이템 id,name을 입력하세요 :\n",i+1);
        scanf("%d %s",&items[i].id,items[i].name);
    }

    for (int j=0; j<n; j++)
    {
        printf("id : %d name : %s\n",items[j].id,items[j].name);
    }

    free(items);
    return 0;
}