#include <stdio.h>
// 정렬된 배열에서만 사용 가능한 알고리즘
typedef struct {
    int id;
    char name[20];
}Item;

int binarySearch(Item *arr,int size,int id); // size 는 배열의 크기, id 는 검색할 id 값, 결과값은 배열의 인덱스 or -1

int main(void)
{
    Item items[] = {
        {1,"Apple"},{3,"Banana"},{5,"Orange"},{7,"Grape"}
    };
    int size = sizeof(items) / sizeof(items[0]);
    int target = 5; // 찾으려는 id
    int result = binarySearch(items,size,target);
    // 결과값 해석
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
        int mid = left + (right - left) / 2; // 정수 오버플로우 방지
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