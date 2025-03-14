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

// lomuto's partition
void quick_sort(int arr[], int len) {
    int stack[len], high, low, pivot, x, y, temp, pi;
    int top = -1;

    stack[++top] = 0;
    stack[++top] = len - 1;
    
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = arr[high];
        x = low - 1;
        for (y = low; y < high; y++) {
            if (arr[y] < pivot) {
                x++;
                temp = arr[y];
                arr[y] = arr[x];
                arr[x] = temp;
            }
        }
        temp = arr[x + 1];
        arr[x + 1] = arr[high];
        arr[high] = temp;
        pi = x + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1; 
        }
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}
