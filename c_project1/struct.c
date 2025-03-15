#include <stdio.h>

struct Gameinfo{
    char * name;
    int year;
    int price;
    char * company;

    struct Gameinfo * friendGame; // 연관 업체 게임
};

typedef struct Gameinformation{
    char * name;
    int year;
    int price;
    char * company;

    struct Gameinfo * friendGame; // 연관 업체 게임
} Game_info;

int main(void)
{
    // [game release]
    // name : 나도게임
    // since : 2017
    // price : 50원
    // made in 나도회사

    char * name = "나도게임";
    int year = 2017;
    int price = 50;
    char * company = "나도회사";

    // [another game release]
    // name : 너도게임
    // since : 2017
    // price : 100원
    // made in 너도회사

    char * name2 = "너도게임";
    int year2 = 2017;
    int price2 = 100;
    char * company2 = "너도회사";

    //구조체 사용
    struct Gameinfo gameinfo1;
    gameinfo1.name = "나도게임";
    gameinfo1.year = 2017;
    gameinfo1.price = 50;
    gameinfo1.company = "나도회사";
    //구조체 출력
    printf("--게임 출시 정보--\n");
    printf("  게임명 :   %s\n",gameinfo1.name);
    printf("  발매년도 : %d\n",gameinfo1.year);
    printf("  가격 :     %d\n",gameinfo1.price);
    printf("  게임명 :   %s\n",gameinfo1.company);

    //구조체를 배열처럼 초기화
    struct Gameinfo gameinfo2 = {"너도게임",2017,100,"너도회사"}; // 한번에 초기화하는 법
    //구조체 출력
    printf("--게임 출시 정보--\n");
    printf("  게임명 :   %s\n",gameinfo2.name);
    printf("  발매년도 : %d\n",gameinfo2.year);
    printf("  가격 :     %d\n",gameinfo2.price);
    printf("  게임명 :   %s\n",gameinfo2.company);

    //구조체 배열 -> 배열이 있는데 배열의 자료형이 struct, 따라서 배열 안에 struct 가 들어가는 것
    struct Gameinfo gameArray[2] = {
        {"나도게임",2017,50,"나도회사"},
        {"너도게임",2017,100,"너도회사"}
    };

    //구조체 포인터
    struct Gameinfo * gamePtr; // 자료형이 struct 인 변수의 주소를 가리키는 포인터 gamePtr0
    gamePtr = &gameinfo1; // 포인터 gamePtr 이 가리키는 주소!
    // printf("--게임 출시 정보(pointer)--\n");
    // printf("  게임명 :   %s\n",(*gamePtr).name); // 즉, *&gameinfo1 = gameinfo1
    // printf("  발매년도 : %d\n",(*gamePtr).year);
    // printf("  가격 :     %d\n",(*gamePtr).price);
    // printf("  게임명 :   %s\n",(*gamePtr).company);
    printf("  게임명 :   %s\n",gamePtr->name); // 새로운 문법이다
    printf("  발매년도 : %d\n",gamePtr->year);
    printf("  가격 :     %d\n",gamePtr->price);
    printf("  게임명 :   %s\n",gamePtr->company);

    //구조체 안의 구조체
    gameinfo1.friendGame = &gameinfo2; // 변수명 gameinfo1 은 struct 자료형이고 구조체 속 friend에 값을 할당시켜준 것. 근데 freind 는 포인터니까 주소를 받아야한다. 어떤 변수의 주소냐면 struct 자료형인 변수의 주소! gameinfo2 는 struct 자료형인 변수이므로 가능하다
    printf("  게임명 :   %s\n",gameinfo1.friendGame->name);
    printf("  발매년도 : %d\n",gameinfo1.friendGame->year);
    printf("  가격 :     %d\n",gameinfo1.friendGame->price);
    printf("  게임명 :   %s\n",gameinfo1.friendGame->company);

    //typedef
    //자료형에 별명 지정
    int i = 1;
    typedef int 정수;
    정수 정수변수 = 7;
    
    typedef struct Gameinfo 게임정보;
    게임정보 game1;
    game1.name = "test_name";

    Game_info game2;
    game2.name = "test_name2";

    return 0;
}