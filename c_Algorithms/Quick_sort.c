#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Item;



int main(void)
{
    // ���� �޸� �Ҵ�
    int n;
    printf("������ ���� �Է�:");
    scanf("%d",&n);
    Item *items; // Item�� ����Ű�� ������
    items = malloc(n*sizeof(Item)); // Item ũ�� x n ��ŭ ���� �޸� �Ҵ� (�ּҸ��� �����Ϳ� ����)

    // ���� ����
    if (items == NULL)
    {
        printf("���� �޸� �Ҵ� ���� �߻�\n");
        return 1;
    } 
    // ������ �Է�
    for (int i=0; i<n; i++)
    {
        printf("%d ��° ID �� Name �� �Է��ϼ���: \n",i+1);
        scanf("%d %s",&items[i].id,items[i].name);
    }
    // ���� �� ���
    printf("\n���� �� ���:\n");
    for (int i=0; i<n; i++)
    {
        printf("ID : %d, Name: %s\n",items[i].id,items[i].name);
    }
    // ����

    // ���� �� ���
    printf("���� �� ���\n");
    for (int i=0; i<n; i++)
    {
        printf("ID : %d, Name: %s\n",items[i].id,items[i].name);
    }
    free(items);
    return 0;
}