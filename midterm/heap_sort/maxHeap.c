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
    int x, root, left, right, max, temp, swapped;
    int heap_size = len;

    if (len > 0) {
        for (x = heap_size / 2 - 1; x >= 0; x--) { // building the max heap
            root = x;
            for (swapped = 1; swapped;) {
                swapped = 0;
                left = 2 * root + 1;
                right = 2 * root + 2;
                max = root;
        
                if (left < heap_size && arr[left] > arr[max]) {
                    max = left;
                }
        
                if (right < heap_size && arr[right] > arr[max]) {
                    max = right;
                }

                if (max != root) {
                    swapped = 1;
                    temp = arr[root];
                    arr[root] = arr[max];
                    arr[max] = temp;
                    root = max;   
                }
            }
        }
    
        for (x = heap_size - 1; x > 0; x--) { // extracting and sorting elements into ascending order
            temp = arr[0];
            arr[0] = arr[x];
            arr[x] = temp;
    
            heap_size--; 
            root = 0;
            for (swapped = 1; swapped;) {
                swapped = 0;
                left = 2 * root + 1;
                right = 2 * root + 2;
                max = root;
        
                if (left < heap_size && arr[left] > arr[max]) {
                    max = left;
                }
        
                if (right < heap_size && arr[right] > arr[max]) {
                    max = right;
                }
        
                if (max != root) {
                    swapped = 1;
                    temp = arr[root];
                    arr[root] = arr[max];
                    arr[max] = temp;
                    root = max;
                }
            }
        }
    }

    // // descending order for maxheap
    // for (x = 0; x < len / 2; x++) {
    //     temp = arr[x];
    //     arr[x] = arr[len - 1 - x];
    //     arr[len - 1 - x] = temp;
    // }
}