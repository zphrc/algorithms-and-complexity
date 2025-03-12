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
    int x, root, left, right, largest, temp;
    int heap_size = len;
    for (x = heap_size / 2 - 1; x >= 0; x--) {
        root = x;
        while (1) {
            left = 2 * root + 1;
            right = 2 * root + 2;
            largest = root;

            if (left < heap_size && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < heap_size && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == root) break;

            temp = arr[root];
            arr[root] = arr[largest];
            arr[largest] = temp;
            root = largest;
        }
    }

    for (x = heap_size - 1; x > 0; x--) {
        temp = arr[0];
        arr[0] = arr[x];
        arr[x] = temp;

        heap_size--;
        root = 0;
        while (1) {
            left = 2 * root + 1;
            right = 2 * root + 2;
            largest = root;

            
            if (left < heap_size && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < heap_size && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest == root) break;

            temp = arr[root];
            arr[root] = arr[largest];
            arr[largest] = temp;
            root = largest;
        }
    }
}