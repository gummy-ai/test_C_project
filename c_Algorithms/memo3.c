#include <stdio.h>

typedef struct {
    int id;
    char name[20];
} Item;

void bubbleSort(Item *arr, int size);
int binarySearch(Item *arr, int size, int id);

int main(void)
{
    Item items[] = {
        {7, "Grape"}, {1, "Apple"}, {5, "Orange"}, {3, "Banana"}
    };
    int size = sizeof(items) / sizeof(items[0]);
    
    // 1. ���� ���� (��������)
    bubbleSort(items, size);

    // 2. ���� Ž�� ����
    int target = 5;
    int result = binarySearch(items, size, target);

    if (result == -1)
    {
        printf("Item not found\n");
    }
    else
    {
        printf("(%d : %s)'s index = %d\n", items[result].id, items[result].name, result);
    }
    return 0;
}

// Bubble Sort (��������)
void bubbleSort(Item *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {  // �������� ����
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ���� Ž�� (�������� ����)
int binarySearch(Item *arr, int size, int id)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid].id == id)
        {
            return mid;
        }
        else if (arr[mid].id < id)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}