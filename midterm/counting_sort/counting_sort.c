#include <stdio.h>

void display(int *, int);
void counting_sort(int *, int);

int main() {
    int arr[] = {5, 8, 4, 6, 7, 3, 5, 6, 2, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: "); 
    display(arr, len);

    counting_sort(arr, len);
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

void counting_sort(int arr[], int len) {
	if (len > 0) {
		// find max elem
		int x, max = arr[0];
		for (x = 1; x < len; x++) {
			if (arr[x] > max) {
				max = arr[x];
			}
		}
	
		// count occurrences
		int count[max + 1];
		for (x = 0; x <= max; x++) {
			count[x] = 0;
		}
		
		for (x = 0; x <= len; x++) {
			count[arr[x]]++;
		}
		
		// cumulative sum
		for (x = 1; x <= max; x++) {
			count[x] += count[x - 1];
		} 
		
		// output array
		int output[len];
		for (x = len - 1; x >= 0; x--) {
			output[count[arr[x]] - 1] = arr[x];
			count[arr[x]]--;
		}
		
		// copy onto input array	
		for (x = 0; x < len; x++) {
			arr[x] = output[x];
		}
	}
}