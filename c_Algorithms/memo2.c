#include <stdio.h>
// bubble_sort_prac
typedef struct {
    char *name;
    int score;
} Student;

void bubblesort(Student *arr,int num);
int main(void)
{
    char *name[] = {"Emily", "Liam", "Sophia", "Noah", "Ava", "James", "Isabella", "Oliver", "Mia", "Ethan"};
    int score[] = {87, 92, 78, 85, 95, 88, 76, 91, 83, 89};

    Student students[10]; // 물론론 처음부터 배열 초기화로 가능
    for (int i=0; i<10; i++)
    {
        students[i].name = name[i];
        students[i].score = score[i];
    }

    bubblesort(students,10);

    for (int i=0; i<10; i++)
    {
        printf("%s : %d\n",students[i].name,students[i].score);
    }
    return 0;
}
void bubblesort(Student *arr,int num)
{
    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<num-i-1; j++)
        {
            if(arr[j].score > arr[j+1].score)
            {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}