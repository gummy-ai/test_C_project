#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Item;



int main(void)
{
    // 동적 메모리 할당
    int n;
    printf("아이템 수를 입력:");
    scanf("%d",&n);
    Item *items; // Item을 가리키는 포인터
    items = malloc(n*sizeof(Item)); // Item 크기 x n 만큼 동적 메모리 할당 (주소만들어서 포인터에 저장)

    // 오류 방지
    if (items == NULL)
    {
        printf("동적 메모리 할당 오류 발생\n");
        return 1;
    } 
    // 데이터 입력
    for (int i=0; i<n; i++)
    {
        printf("%d 번째 ID 와 Name 을 입력하세요: \n",i+1);
        scanf("%d %s",&items[i].id,items[i].name);
    }
    // 정렬 전 출력
    printf("\n정렬 전 출력:\n");
    for (int i=0; i<n; i++)
    {
        printf("ID : %d, Name: %s\n",items[i].id,items[i].name);
    }
    // 정렬

    // 정렬 후 출력
    printf("정렬 후 출력\n");
    for (int i=0; i<n; i++)
    {
        printf("ID : %d, Name: %s\n",items[i].id,items[i].name);
    }
    free(items);
    return 0;
}