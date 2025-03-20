#include <stdio.h>

void display(int *, int);
void merge_sort(int *, int);

int main() {
    int arr[] = {5, 8, 4, 6, 7, 3, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: "); 
    display(arr, len);

    merge_sort(arr, len);
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


void merge_sort(int arr[], int len) {
    int temp[len], width, left, mid, right, x, y, k, idx;

    for (width = 1; width < len; width *= 2) {
        for (left = 0; left < len; left += 2 * width) {
            mid = left + width - 1;
            right = left + 2 * width - 1;

            if (mid >= len) mid = len - 1;

            if (right >= len) right = len - 1;

            x = left;
            y = mid + 1;
            k = left;

            while (x <= mid && y <= right) {
                if (arr[x] <= arr[y]) {
                    temp[k++] = arr[x++];
                } else {
                    temp[k++] = arr[y++];
                }
            }

            while (x <= mid) {
                temp[k++] = arr[x++];
            }

            while (y <= right) {
                temp[k++] = arr[y++];
            }

            for (idx = left; idx <= right; idx++) {
                arr[idx] = temp[idx];
            }
        }
    }
}
