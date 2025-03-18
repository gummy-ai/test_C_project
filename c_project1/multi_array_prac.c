#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5]; // 20�� ī��
int checkAnimal[4][5]; // ���������� ���� Ȯ�� (0: �� ������, 1: ������)
char *strAnimal[10];   // ���� �̸� �迭

void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int allCardsFlipped();

int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();
    shuffleAnimal();

    int failCount = 0;

    while (1)
    {
        int select1, select2;

        printAnimals();  // ������: ���� ���� ��ġ ���
        printQuestion(); // ����ڿ��� ī�� ���� ������
        printf("������ ī�带 2�� ������ (0-19): ");
        scanf("%d %d", &select1, &select2);

        // �Է°� ��ȿ�� �˻�
        if (select1 < 0 || select1 > 19 || select2 < 0 || select2 > 19)
        {
            printf("0���� 19 ������ ���ڸ� �Է��ϼ���.\n");
            continue;
        }
        if (select1 == select2)
        {
            printf("���� ī�带 �����߽��ϴ�. �ٸ� ī�带 ����ּ���.\n");
            continue;
        }

        int x1 = conv_pos_x(select1);
        int y1 = conv_pos_y(select1);
        int x2 = conv_pos_x(select2);
        int y2 = conv_pos_y(select2);

        // �̹� ������ ī������ Ȯ��
        if (checkAnimal[x1][y1] == 1 || checkAnimal[x2][y2] == 1)
        {
            printf("�̹� ������ ī�带 �����߽��ϴ�. �ٽ� ����ּ���.\n");
            continue;
        }

        // ������ ī�� �����ֱ�
        printf("\n������ ī��:\n");
        printf("ī�� %d: %s\n", select1, strAnimal[arrayAnimal[x1][y1]]);
        printf("ī�� %d: %s\n", select2, strAnimal[arrayAnimal[x2][y2]]);

        // ī�� ��
        if (arrayAnimal[x1][y1] == arrayAnimal[x2][y2])
        {
            printf("������ϴ�! ī�尡 �������ϴ�.\n");
            checkAnimal[x1][y1] = 1;
            checkAnimal[x2][y2] = 1;
        }
        else
        {
            printf("Ʋ�Ƚ��ϴ�. ���� ��ȸ�� �ٽ� �õ��ϼ���.\n");
            failCount++;
        }

        // ��� ī�尡 ���������� Ȯ��
        if (allCardsFlipped())
        {
            printQuestion();
            printf("\n�����մϴ�! ��� ī�带 ���������ϴ�!\n");
            printf("���� Ƚ��: %d\n", failCount);
            break;
        }
    }

    return 0;
}

void initAnimalArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
            checkAnimal[i][j] = 0; // �ʱ�ȭ: ��� �������� ���� ����
        }
    }
}

void initAnimalName()
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
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition()
{
    while (1)
    {
        int randPos = rand() % 20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
}

int conv_pos_x(int x)
{
    return x / 5;
}

int conv_pos_y(int y)
{
    return y % 5;
}

void printAnimals()
{
    printf("\n======= ����ε�.. ���� �����ݴϴ�.======\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n\n");
}

void printQuestion()
{
    printf("\n\n ���� \n");
    int seq = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 1)
            {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            }
            else
            {
                printf("%8d", seq);
            }
            seq++;
        }
        printf("\n");
    }
    printf("\n");
}

int allCardsFlipped()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j] == 0)
            {
                return 0; // ���� �������� ���� ī�尡 ����
            }
        }
    }
    return 1; // ��� ī�尡 ������
}