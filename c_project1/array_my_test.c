#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char blind_box[10];
int animal_card[10]; // Let's think of each animal cards as 0-9 numbers

void currentsituation(int input1, int input2);
void permutation(int arr[],int size);
int Gameclear();
void initialize_blind_box();
int get_valid_input(const char *prompt);
void show_selected_cards(int input1, int input2);

int main(void)
{
    srand(time(NULL));
    int fail_count = 0;
        for (int j=0; j<5; j++)
        {
            animal_card[j] = j+1;
            animal_card[j+5] = j+1;
        }
    // Way to make permutation...?
    int size = sizeof(animal_card)/sizeof(animal_card[0]);
    permutation(animal_card,size);
    initialize_blind_box();
    printf("game start! \n\n");
    currentsituation(-1,-1);
    printf("\n");
    // Array of blinds to be shown to the user
    while (1)
    {
        // Take two inputs
        int input1 = get_valid_input("Choose first number (1-10): ");
        int input2 = get_valid_input("Choose second number (1-10): ");

        // 동일한 위치를 입력한 경우
        if (input1 == input2)
        {
            printf("Error: You cannot choose the same position twice! Try again.\n\n");
            continue; // 다시 입력 받도록 루프 처음으로 돌아감
        }
        // 이미 'X'로 표시된 위치를 선택한 경우
        if (blind_box[input1 - 1] == 'X' || blind_box[input2 - 1] == 'X')
        {
            printf("Error: One or both positions are already revealed! Try again.\n\n");
            currentsituation(-1, -1); // 현재 상태 다시 출력
            continue;
        }
        show_selected_cards(input1-1,input2-1);
        if (animal_card[input1-1] == animal_card[input2-1])
        {
            currentsituation(input1-1,input2-1);
            printf("\n");
        }
        else
        {
            currentsituation(-1,-1);
            printf("fail! select again!\n\n");
            fail_count++;
            printf("total fail_count : %d\n",fail_count);
        }
        if (Gameclear() == 0)
        {
            printf("congratuation! game clear!!\n\n");
            exit(0);
        }
    }
    return 0;
}
// definition
void currentsituation(int input1, int input2)
{
    char X_box = 'X';
    printf("\n");
    for (int k=0; k<10; k++)
    {
        printf("%3d ",k+1);
    }
    printf("\n");
    
    if (input1 !=-1 && input2 !=-1)
    {
        blind_box[input1] = X_box;
        blind_box[input2] = X_box;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%3c ", blind_box[i]);
    }
    printf("\n");
}
void permutation(int arr[],int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // 0부터 i까지 무작위 인덱스
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int Gameclear()
{
    char X_box = 'X';
    for (int i=0; i<10; i++)
    {
        if (blind_box[i] != X_box)
        {
            return 1;
        }
    }
    return 0;
}
void initialize_blind_box()
{
    char O_char = 'O';
    for (int i = 0; i < 10; i++)
    {
        blind_box[i] = O_char;
    }
}
int get_valid_input(const char *prompt)
{
    int input;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &input) == 1 && input >= 1 && input <= 10)
        {
            getchar(); // Clear the newline character
            return input;
        }
        else
        {
            printf("Invalid input! Please enter a number between 1 and %d.\n", 10);
            while (getchar() != '\n'); // Clear the input buffer
        }
    }
}
// 선택한 카드를 잠깐 보여주는 함수
void show_selected_cards(int input1, int input2)
{
    printf("\nselected_cards\n\n");
    for (int i=0; i<10; i++)
    {
        printf("%3d ",i+1);
    }
    printf("\n");
    for (int j=0; j<10; j++)
    {
        if (j==input1 || j==input2)
        {
            printf("%3d ",animal_card[j]);
        }
        else
        {
            printf("%3c ",blind_box[j]);
        }
    }
    printf("\n\n");
}