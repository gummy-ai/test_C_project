#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Item;

int main(void)
{
    int n;
    printf("������ ���� �Է��ϼ��� :\n");
    scanf("%d",&n);
    Item *items = malloc(n*sizeof(Item));

    for (int i=0; i<n; i++)
    {
        printf("%d ��° ������ id,name�� �Է��ϼ��� :\n",i+1);
        scanf("%d %s",&items[i].id,items[i].name);
    }

    for (int j=0; j<n; j++)
    {
        printf("id : %d name : %s\n",items[j].id,items[j].name);
    }

    free(items);
    return 0;
}