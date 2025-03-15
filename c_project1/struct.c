#include <stdio.h>

struct Gameinfo{
    char * name;
    int year;
    int price;
    char * company;

    struct Gameinfo * friendGame; // ���� ��ü ����
};

typedef struct Gameinformation{
    char * name;
    int year;
    int price;
    char * company;

    struct Gameinfo * friendGame; // ���� ��ü ����
} Game_info;

int main(void)
{
    // [game release]
    // name : ��������
    // since : 2017
    // price : 50��
    // made in ����ȸ��

    char * name = "��������";
    int year = 2017;
    int price = 50;
    char * company = "����ȸ��";

    // [another game release]
    // name : �ʵ�����
    // since : 2017
    // price : 100��
    // made in �ʵ�ȸ��

    char * name2 = "�ʵ�����";
    int year2 = 2017;
    int price2 = 100;
    char * company2 = "�ʵ�ȸ��";

    //����ü ���
    struct Gameinfo gameinfo1;
    gameinfo1.name = "��������";
    gameinfo1.year = 2017;
    gameinfo1.price = 50;
    gameinfo1.company = "����ȸ��";
    //����ü ���
    printf("--���� ��� ����--\n");
    printf("  ���Ӹ� :   %s\n",gameinfo1.name);
    printf("  �߸ų⵵ : %d\n",gameinfo1.year);
    printf("  ���� :     %d\n",gameinfo1.price);
    printf("  ���Ӹ� :   %s\n",gameinfo1.company);

    //����ü�� �迭ó�� �ʱ�ȭ
    struct Gameinfo gameinfo2 = {"�ʵ�����",2017,100,"�ʵ�ȸ��"}; // �ѹ��� �ʱ�ȭ�ϴ� ��
    //����ü ���
    printf("--���� ��� ����--\n");
    printf("  ���Ӹ� :   %s\n",gameinfo2.name);
    printf("  �߸ų⵵ : %d\n",gameinfo2.year);
    printf("  ���� :     %d\n",gameinfo2.price);
    printf("  ���Ӹ� :   %s\n",gameinfo2.company);

    //����ü �迭 -> �迭�� �ִµ� �迭�� �ڷ����� struct, ���� �迭 �ȿ� struct �� ���� ��
    struct Gameinfo gameArray[2] = {
        {"��������",2017,50,"����ȸ��"},
        {"�ʵ�����",2017,100,"�ʵ�ȸ��"}
    };

    //����ü ������
    struct Gameinfo * gamePtr; // �ڷ����� struct �� ������ �ּҸ� ����Ű�� ������ gamePtr0
    gamePtr = &gameinfo1; // ������ gamePtr �� ����Ű�� �ּ�!
    // printf("--���� ��� ����(pointer)--\n");
    // printf("  ���Ӹ� :   %s\n",(*gamePtr).name); // ��, *&gameinfo1 = gameinfo1
    // printf("  �߸ų⵵ : %d\n",(*gamePtr).year);
    // printf("  ���� :     %d\n",(*gamePtr).price);
    // printf("  ���Ӹ� :   %s\n",(*gamePtr).company);
    printf("  ���Ӹ� :   %s\n",gamePtr->name); // ���ο� �����̴�
    printf("  �߸ų⵵ : %d\n",gamePtr->year);
    printf("  ���� :     %d\n",gamePtr->price);
    printf("  ���Ӹ� :   %s\n",gamePtr->company);

    //����ü ���� ����ü
    gameinfo1.friendGame = &gameinfo2; // ������ gameinfo1 �� struct �ڷ����̰� ����ü �� friend�� ���� �Ҵ������ ��. �ٵ� freind �� �����ʹϱ� �ּҸ� �޾ƾ��Ѵ�. � ������ �ּҳĸ� struct �ڷ����� ������ �ּ�! gameinfo2 �� struct �ڷ����� �����̹Ƿ� �����ϴ�
    printf("  ���Ӹ� :   %s\n",gameinfo1.friendGame->name);
    printf("  �߸ų⵵ : %d\n",gameinfo1.friendGame->year);
    printf("  ���� :     %d\n",gameinfo1.friendGame->price);
    printf("  ���Ӹ� :   %s\n",gameinfo1.friendGame->company);

    //typedef
    //�ڷ����� ���� ����
    int i = 1;
    typedef int ����;
    ���� �������� = 7;
    
    typedef struct Gameinfo ��������;
    �������� game1;
    game1.name = "test_name";

    Game_info game2;
    game2.name = "test_name2";

    return 0;
}