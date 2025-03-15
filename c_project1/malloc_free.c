#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("학생 수 입력: ");
    scanf("%d",&n);
    int *score;
    score = malloc(n*sizeof(int));
    for (int i=0; i<n; i++)
    {
        score[i] = i;
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ",score[i]);
    }
    free(score);
    return 0;
    // int score[n]; // 오류! 크기 알 수 없기 때문.
    // 정적할당: 컴파일을 하려면 컴파일 전(runtime)전에 크기가 정해져 있어야한다.
    // 즉 int [5] 이면 4바이트 5개 할당돼야함
    // 실행중에 메모리 할당하고 싶으면 : 동적할당 이는 heap 영역에 들어간다.
    // 나머지 영역은 정적할당 메모리가 들어간다
    // malloc 을 통해 해결 가능!
    // malloc(크기,); 하면 heap 영역에 메모리가 잡힌다.
    // malloc 은 함숫값으로 할당된 메모리의 주소값으로 준다.
    // 따라서 이 주소값을 같은 타입의 포인터로 받아야한다. 이 포인터는 지역변수니까 stack 에 잡힌다.
    // 즉, 동적 메모리의 주소를 가리킨다.
    // ? 포인터 크기? 바이트? 자료형 크기는??
    // 즉, score 이름으로 할당!
    // malloc 은 void * 형(다 받을 수 있음) 그래서 반드시 자료형을 써줘야함 예시에서는 int *로 
    // 포인터가 제거가 되는게 아니라 포인터가 가리키는 메모리를 제거해준다.즉, heap 영역에서 완전히 사라진다. 지역변수도 끝나면 사라지므로 메모리가 깔끔해진다.
    return 0;
}