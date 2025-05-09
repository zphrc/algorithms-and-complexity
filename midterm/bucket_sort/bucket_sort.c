#include <stdio.h>

#define NBUCKET 10
#define INTERVAL 10
#define NARRAY 100

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

void bucketSort(int arr[], int len) {
    int i, j, k;
    // Create buckets: each bucket can hold up to NARRAY elements.
    int buckets[NBUCKET][NARRAY];
    // Array to hold the count (number of elements) in each bucket.
    int bucketCount[NBUCKET] = {0};

    // 1. Distribute array elements into buckets
    for (i = 0; i < len; i++) {
        // Determine bucket index; for example, using INTERVAL
        int bucketIndex = arr[i] / INTERVAL;
        if (bucketIndex >= NBUCKET) {
            bucketIndex = NBUCKET - 1;  // Safeguard if value exceeds expected range.
        }
        buckets[bucketIndex][ bucketCount[bucketIndex]++ ] = arr[i];
    }

    // 2. Sort each bucket using insertion sort (array version)
    for (i = 0; i < NBUCKET; i++) {
        // Insertion sort on bucket[i] for bucketCount[i] elements.
        for (j = 1; j < bucketCount[i]; j++) {
            int key = buckets[i][j];
            int l = j - 1;
            while (l >= 0 && buckets[i][l] > key) {
                buckets[i][l + 1] = buckets[i][l];
                l--;
            }
            buckets[i][l + 1] = key;
        }
    }

    // 3. Concatenate buckets back into original array
    k = 0;
    for (i = 0; i < NBUCKET; i++) {
        for (j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}
