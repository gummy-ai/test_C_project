#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5]; // 20�� cards
int checkAnimal[4][5]; // ���������� ���� Ȯ��
char * strAnimal[10];


void initAnimalArray();
void initAnialName();
void shuffleAnimal();
int getEmptyPositon();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printfAnimals();
void printfQuestion();

int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnialName();

    shuffleAnimal();

    int failcount = 0;

    while (1)
    {
        // ����ڿ��� ���� �޴´�
        int select1 = 0;
        int select2 = 0;

        printfAnimals(); // ���� ��ġ ���
        printfQuestion(); // ���� ��� (ī�� ����)
        printf("������ ī�带 2�� ������: ");
        scanf("%d %d",&select1,&select2); // scanf �ٺ��� �����Ѱſ���??
        
        if (select1 == select2)
        {
            printf("�ٸ� ī�带 ����ּ���\n");
            continue;
        }

    }
    return 0;
}

void initAnimalArray()
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            arrayAnimal[i][j]=-1;
        }
    }
}
void initAnialName()
{
    strAnimal[0] = "������";
    strAnimal[1] = "�ϸ�";
    strAnimal[2] = "������";
    strAnimal[3] = "�����";
    strAnimal[4] = "����";
    strAnimal[5] = "�ڳ���";
    strAnimal[6] = "�⸰";
    strAnimal[7] = "��Ÿ";
    strAnimal[8] = "Ÿ��";
    strAnimal[9] = "ȣ����";
}

void shuffleAnimal()
{
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<2; j++)
        {
            int pos = getEmptyPositon();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}
// ��ǥ���� �� ���� ã��
int getEmptyPositon()
{
    while (1)
    {
        int randPos = rand() % 20; // 0-19 ������ ���� ��ȯ
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
    
        if(arrayAnimal[x][y] == -1) // ��������� �ǹ�
        {
            return randPos;
        }
    }
    return 0;
}
int conv_pos_x(int x)
{
    return x/5;
}
int conv_pos_y(int y)
{
    return y%5;
}
void printfAnimals()
{
    printf("\n======= ����ε�.. ���� �����ݴϴ�.======\n\n");
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            printf("%8s",strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");
}
void printfQuestion()
{
    printf("\n\n ���� \n");
    int seq = 0;
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            // ī�带 ����� ������ �������� '���� �̸�'
            if (checkAnimal[i][j] != 0)
            {
                printf("%8s",strAnimal[arrayAnimal[i][j]]);
            }
            // �� �������� �޸��� ��ġ�� ��Ÿ���� ���ڸ� ��������.
            else
            {
                printf("%8d",seq);
            }
        }
    }
}