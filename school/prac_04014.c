# include <stdio.h>

int main(void)
{
    int num;
    printf("숫자 입력:\n");
    scanf("%d",&num);

    int sum = 1;

    do
    {
        sum = sum*num;
        num = num-1;
    } while ( num>0 );
    
    printf("%d\n",sum);
    return 0;
}