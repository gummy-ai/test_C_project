#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;
    char name[20]; // �����ͷ� ���� �ȵǴ� ���� : Items �� ũ�Ⱑ �޶������� �ƴ϶�(�����͸��� ũ�Ⱑ �ֱ⿡ �޶����� �ʴ´�) *name �� ����Ű�� �ּҰ� ���⿡ scanf �� �־��� �ּҰ� ����!
} Items;

int main(void)
{
    int num;
    printf("������ ���� �Է� :");
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

    printf("�� ���� : %d",sum);

    free(score);
    return 0;
}