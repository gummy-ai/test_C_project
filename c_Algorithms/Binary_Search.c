#include <stdio.h>
// ���ĵ� �迭������ ��� ������ �˰���
typedef struct {
    int id;
    char name[20];
}Item;

int binarySearch(Item *arr,int size,int id); // size �� �迭�� ũ��, id �� �˻��� id ��, ������� �迭�� �ε��� or -1

int main(void)
{
    Item items[] = {
        {1,"Apple"},{3,"Banana"},{5,"Orange"},{7,"Grape"}
    };
    int size = sizeof(items) / sizeof(items[0]);
    int target = 5; // ã������ id
    int result = binarySearch(items,size,target);
    // ����� �ؼ�
    if (result == -1)
    {
        printf("Item not found\n");
    }
    else
    {
        printf("(%d : %s)'s index = %d\n",items[result].id,items[result].name,result);
    }
    return 0;
}

int binarySearch(Item *arr,int size,int id)
{
    int left = 0;
    int right = size-1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // ���� �����÷ο� ����
        if (arr[mid].id == id)
        {
            return mid;
        }
        else if (arr[mid].id < id)
        {
            left = mid +1;
        }
        else
        {
            right = mid -1;
        }
    }
    return -1;
}