#include <stdio.h>
#include <time.h>

// ����� ���� ������Ʈ
// ���� ����
int level;
int arrayFish[6];
int * cursor; // ����� ����Ű��
// my function
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();
// main function
int main(void)
{
    long startTime = 0; // ���� ���� �ð�
    long totalElapsedTime = 0; // �� ��� �ð� ����
    long prevElapsedTime= 0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)
    int num; // �� �� ���׿� ���� �� ������, ����� �Է�
    initData();
    cursor = arrayFish; // cursor[0]... cursor[1]

    startTime = clock(); // ���� �ð��� millisecond (1/1000��) ������ ��ȯ
    while(1)
    {
        printfFishes();
        printf("�� �� ���׿� ���� �ֽðھ��?\n");
        scanf_s("%d",&num);

        // input check
        if (num < 1 || num > 6)
        {
            printf("\n �Է°��� �߸��ƽ��ϴ�.\n");
            continue;
        }
        // �� ��� �ð� ����
        totalElapsedTime = (clock()-startTime) / CLOCKS_PER_SEC;
        printf("total delay time : %1d sec\n", totalElapsedTime);

        // ���� �� �� �ð� (���������� �� �� �ð�) ���ķ� �帥 �ð�
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("recent delay time : %1d sec\n", prevElapsedTime);
    
        // ������ ���� ���� (����)
        decreaseWater(prevElapsedTime);

        // ����ڰ� �Է��� ���׿� ���� �ش�
        // 1. ������ ���� 0�̸�? �� ���� �ʴ´�.
        if ( cursor[num-1]<=0)
        {
            printf("%d�� ������ �̹� �׾����ϴ�.",num);
        }
        // 2. ������ ���� 0�� �ƴ� ���? ���� �ش�! ��,100�� ���� �ʴ��� üũ
        // ���� ������ �� + 1 <=100
        else if (cursor[num-1]<=100)
        {
            printf("%d�� ���׿� ���� �ݴϴ�\n\n",num);
            cursor[num-1] += 1;
        }
        // �������� �� �� Ȯ�� (�������� 20�ʸ��� �ѹ��� ����)
        if (totalElapsedTime / 20 >= level - 1)
        {
            level++;
            printf("*** level up! %d level -> %d level ***\n\n",level-1,level);
            if (level == 5)
            {
                printf("\n\n good! higest level is recorded. the end");
                exit(0); // ���α׷� ����
            }
        }
        // ��� ����� ������ Ȯ��
        if (checkFishAlive() == 0)
        {
            printf("��� ����� ����\n"); //����� ��� ����
            exit(0); // ���α׷� ����
        }
        else
        {
            printf("����Ⱑ ���� �������\n"); //�ּ� �Ѹ��� ����� ����
        }
        prevElapsedTime = totalElapsedTime;
        // 10sec -> 15sec (5sec : prevElapsedTime) -> 25sec (10sec : prevElapsedTime)
        // 15sec �� prevElapsedTime�� �־�ߵ� �׷��� ���� �ڵ带 �ۼ�
    }
    return 0;
}

// my function definition
void initData()
{
    level = 1; // ���� ����(1~5)
    for (int i = 0; i<6; i++)
    {
        arrayFish[i] = 100; // ������ �� ����
    }
}
void printfFishes()
{
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n",1,2,3,4,5,6);
    for (int i=0; i<6; i++)
    {
        printf(" %4d ",arrayFish[i]);
    }
    printf("\n\n");
}
void decreaseWater(long elapsedTime)
{
    for(int i = 0; i<6; i++)
    {
        arrayFish[i] -= (level*3*(int)elapsedTime); // 3�� ���̵� ������ ���� ��
        if (arrayFish[i] <0 )
        {
            arrayFish[i] = 0;
        }
    }
}
int checkFishAlive()
{
    for(int i =0; i<6; i++)
    {
        if (arrayFish[i]>0)
        return 1; // �� True
    }
    return 0;
}