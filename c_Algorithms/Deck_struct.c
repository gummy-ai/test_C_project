#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct {
    char *suit;
    int value;
} Card;

void shuffle(Card *deck, int size); // deck 은 배열이니까 포인터로로
int main(void)
{
    Card deck[52];

    char *suits[] = {"하트","다이아몬드","클로버","스페이드"};
    int deckindex = 0;
    for (int i=0; i<4; i++)
    {
        for (int j=1; j<=13; j++)
        {
            deck[deckindex].suit = suits[i];
            deck[deckindex].value = j;
            deckindex++;
        }
    }
    srand(time(NULL));
    shuffle(deck,52);
    for (int i=0; i<5; i++)
    {
        printf("%s %d\n",deck[i].suit,deck[i].value);
    }
    return 0;
}
void shuffle(Card *deck, int size)
{
    for (int i=size-1; i>0; i--)
    {
        int j = rand()%(i+1); // 0 - i random index
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}