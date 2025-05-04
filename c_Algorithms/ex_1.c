#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char *suit;
    int value;
} Card;

void shuffle(Card *deck[],int num);

int main(void)
{
    Card *deck[52];

    for (int i=0; i<52; i++)
    {
        deck[i] = malloc(sizeof(Card));
    }

    char *suit[] = {"하트","다이아몬드","클로버","스페이드"};

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<13; j++)
        {
            (*deck[j+13*i]).suit = suit[i];
            deck[j+13*i]->value = j+1;
        }
    }
    
    printf("before suffle\n");
    for (int k=0; k<52; k++)
    {
        printf("Card : %s,%d\n",deck[k]->suit,deck[k]->value);
    }
    srand(time(NULL));

    shuffle(deck,52);
    printf("after shuffle\n");
    for (int i=0; i<5; i++)
    {
        printf("Card : %s,%d\n",deck[i]->suit,deck[i]->value);
    }
    return 0;
}

void shuffle(Card *deck[],int num)
{
    for (int i=num-1; i>0; i--)
    {
        int j = rand()%(i+1);
        Card *temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}