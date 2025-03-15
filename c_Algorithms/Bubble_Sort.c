#include <stdio.h>
// 학생 점수를 기준으로 오름차순 정렬하는 버블 정렬 알고리즘
typedef struct {
    char *name;
    int score;
} Student;

void bubblesort(Student *arr,int n);
int main(void)
{
    Student students[] = {{"Alice",85},{"Bob",92},{"Charlie",78}};
    
    int n=3;
    bubblesort(students,n);

    for (int i=0; i<n; i++)
    {
        printf("%s: %d\n",students[i].name,students[i].score);
    }
    return 0;
}
void bubblesort(Student *arr,int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (arr[j].score > arr[j+1].score)
            {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}