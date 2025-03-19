#include <stdio.h>

void display(int *, int);
void quick_sort(int *, int);

int main() {
    int arr[] = {5, 8, 4, 6, 7, 3, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: "); 
    display(arr, len);

    quick_sort(arr, len);
    printf("Sorted: "); 
    display(arr, len);

    return 0;
}

void display(int arr[], int len){
    int x;
    for (x = 0 ; x < len ; x++){
        printf("%d ", arr[x]);
    }
    printf("\n");
}

void quick_sort(int arr[], int len) {
    int stack[len], high, low, pivot, x, y, temp, pi, check;
    int top = -1;

    // pushing initial bounds onto the stack
    stack[++top] = 0; 
    stack[++top] = len - 1;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = arr[low];
        x = low - 1;
        y = high + 1;

        for (check = 1; check;) {
            check = 0;

            for (x = x + 1; arr[x] < pivot; x++){}

            for (y = y - 1; arr[y] > pivot; y--){}
           
            if (x < y) {
                check = 1;
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }

        pi = y;

        if (pi > low) {
            stack[++top] = low;
            stack[++top] = pi;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}