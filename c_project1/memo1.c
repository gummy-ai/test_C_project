#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// global_val
int arr_animal[4][5] = -1; // �޸��� -1�� ǥ��
int check_animal[4][5] = 0; // �ո��� 0���� ǥ�� , 1 �̸� �޸����� ����?
char *str_animal[10] = {
    "�ϸ�",
    "������",
    "�����ú�",
    "����",
    "ȣ����",
    "����",
    "������",
    "Ÿ��",
    "����",
    "����"
};
// my_func
void printQuestion(); // ���� ī�� ��Ȳ�� �����ֱ�
void shuffle_animal(); // (����ִ�) randpos ��� �����ϰ� ��ġ
int getemptyposition(); // -1(�޸�)�� ��ġ�� ��� �Լ�
int conv_pos_x(int num);
int conv_pos_y(int num);
//main-------------------------------
int main(void)
{
    // ī�� ������ ����
    srand(time(NULL));
    

    return 0;
}
// ����
void printQuestion() 
{
    printf("----game start----\n\n");
    int seq = 0;
    for (int i = 0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (check_animal[i][j] == 1) // �ո�:1 �� ���
            {
                printf("8s",str_animal[arr_animal[i][j]]);
            }
            else // �޸�:-1 �� ��� ���� 0���� ���߱��
            {
                printf("%8d",seq);
            }
        }
        seq++;
        printf("\n");
    }
    printf("\n");

}
void shuffle_animal() 
{
    for (int i = 0; i< 10; i++) // 0-9 ������ ������ stranimal �� 0-9�ϱ�
    {
        for (int j = 0; j<2; j++)
        {
            int pos = getemptyposition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arr_animal[x][y] = i; // ���� ���̻� -1�� �ƴ�
        }
    }
}
int getemptyposition() 
{   
    while (1)
    {
        int rand_pos = rand() % 20;
        int x = conv_pos_x(rand_pos);
        int y = conv_pos_y(rand_pos);
        if (arr_animal[x][y] == -1)
        {
            return rand_pos;
        }
    }
}
int conv_pos_x(int num)
{
    return num / 5;
}
int conv_pos_y(int num)
{
    return num % 5;
}