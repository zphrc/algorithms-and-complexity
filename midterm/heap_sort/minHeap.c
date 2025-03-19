#include <stdio.h>

void display(int *, int);
void heap_sort(int *, int);

int main() {
    int arr[] = {5, 8, 4, 6, 7, 3, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: "); 
    display(arr, len);

    heap_sort(arr, len);
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

void heap_sort(int arr[], int len) {
    int x, root, left, right, min, temp, swapped;
    int heap_size = len;
    for (x = heap_size / 2 - 1; x >= 0; x--) {
        root = x;
        for (swapped = 1; swapped; ) {
            swapped = 0;
            left = 2 * root + 1;
            right = 2 * root + 2;
            min = root;

            if (left < heap_size && arr[left] < arr[min]) {
                min = left;
            }

            if (right < heap_size && arr[right] < arr[min]) {
                min = right;
            }

            if (min != root) {
                temp = arr[min];
                arr[min] = arr[root];
                arr[root] = temp;
                root = min;
                swapped = 1;
            }
        } 
    }

    for (x = heap_size - 1; x > 0; x--) {
        temp = arr[0];
        arr[0] = arr[x];
        arr[x] = temp;

        heap_size--;
        root = 0;

        for (swapped = 1; swapped; ) {
            swapped = 0;
            left = 2 * root + 1;
            right = 2 * root + 2;
            min = root;

            if (left < heap_size && arr[left] < arr[min]) {
                min = left;
            }

            if (right < heap_size && arr[right] < arr[min]) {
                min = right;
            }

            if (min != root) {
                temp = arr[min];
                arr[min] = arr[root];
                arr[root] = temp;
                root = min;
                swapped = 1;
            }
        }
    }
}