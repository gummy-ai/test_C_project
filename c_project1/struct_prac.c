#include <stdio.h>
#include <time.h>

// 5���� �����
// �ƹ� Ű�� ������ �������� ����̸� �̵�,
// 5���� ��� �����ؼ� Ű��� ����
// �ߺ� �߻� ����!

// �����
// �̸�,����,����,Ű��� ���̵�(����)

typedef struct {
    char * name; // �̸�
    int age; // ����
    char * character; // ����
    int level; // 1-5
} CAT;

// ������� ������ �����
int collection[5] = {0};

//��ü ����� ����Ʈ
CAT cats[5];

// �� �Լ�
void initCats();
void printCat(int selected);
int checkcollection();
int main(void)
{
    srand(time(NULL));

    initCats(); // ����� ���� �ʱ�ȭ
    while (1)
    {
        printf("��� ������� ���簡 �ɱ��?\n�ƹ�Ű�� ������ Ȯ���ϼ���!\n\n");
        getchar();

        int selected = rand()% 5;
        printCat(selected);
        collection[selected] = 1;

        int collectALL = checkcollection();
        if (collectALL == 1)
        {
            break;
        }
    }


    return 0;
}

void initCats()
{
    cats[0].name = "������";
    cats[0].age = 5;
    cats[0].character = "�¼�";
    cats[0].level = 2;

    cats[1].name = "�����";
    cats[1].age = 3;
    cats[1].character = "õ��";
    cats[1].level = 1;

    cats[2].name = "������";
    cats[2].age = 7;
    cats[2].character = "�� �Ḹ ��";
    cats[2].level = 3;

    cats[3].name = "�����";
    cats[3].age = 2;
    cats[3].character ="�ò�����";
    cats[3].level = 4;

    cats[4].name = "�ų���";
    cats[4].age = 1;
    cats[4].character = "�����";
    cats[4].level = 5;


}
void printCat(int selected)
{
    printf("\n\n����� �� ������� ���簡 �Ǿ����!\n\n");
    printf("�̸� : %s\n",cats[selected].name);
    printf("���� : %d\n",cats[selected].age);
    printf("���� : %s\n",cats[selected].character);
    printf("���� : ");

    for (int i=0; i<cats[selected].level; i++)
    {
        printf("%s","��");
    }
    printf("\n\n");
}

int checkcollection()
{
    int collectall = 1;
    printf("\n\n ������ ����� ����̿��� \n\n");
    for (int i=0; i<5; i++)
    {
        if (collection[i] == 0)
        {
            printf("%10s","(�� �ڽ�)");
            collectall = 0;
        }
        else
        {
            printf("%10s",cats[i].name);
        }
    }
    printf("\n================================\n\n");

    if (collectall == 1)
    {
        printf("�����մϴ�! ��� ����̸� �� ��Ҿ��. ������ Ű���ּ���!\n\n");
    }
    

    return collectall;
}