#include <stdio.h>
#include <math.h>

int main(void)
{
    // sqrt �� ��ġ ����??

    /*int num1 = 5;
    printf("%f",sqrt(5));*/

    // �Ҽ� ����� �غ��� -> for ���� if ������ �������.
    int arr[569];
    int j = 0;
    for (int i=2; i<570; i++)
    {
        int TF = 1;
        int test_num = 2;
        while (test_num < sqrt(i))
        {
            // ���� ������  ~�Ҽ� ������? ������ = 0 -> i % test_num == 0
            if ( i % test_num == 0)
            {
                TF = 0;
                break; // �̰Ŵ� �ݺ��� �ϳ��� ������ ����
            }
            test_num++;
        }
        if (TF == 0)
        {
            continue;
        }
        arr[j] = i;
        j++;
    }
    for (int i = 0; i<j; i++)
    {
        printf("%d",arr[i]);
        if (i == j-1)
        {
            break;
        }
        printf(",");
    }
}

// ����� ������ ����
/* 1. ~=�� �ƴ϶� !=
2. ���� 0�� ����, 1�� ��
3. for �ȿ� j�� ���� �ۿ����� j�� �ν� �� ��
 */