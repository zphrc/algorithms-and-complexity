#include <stdio.h>

void display(int *, int);
void radix_sort(int *, int);

int main() {
    int arr[] = {52, 817, 48, 63, 751, 33, 52, 63, 24, 52};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted: "); 
    display(arr, len);

    radix_sort(arr, len);
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

void radix_sort(int arr[], int len) {

    // check if input array empty
    if (len > 0) {

		// find max elem
		int x, max = arr[0];
		for (x = 1; x < len; x++) {
			if (arr[x] > max) {
				max = arr[x];
			}
		}

        // counting sort for each digit starting from ones place
        int place, digit;
        for (place = 1; max / place > 0; place *= 10) {

            // count occurrences of digit
            int count[10];
            for (x = 0; x < 10; x++) {
                count[x] = 0;
            }
            
            for (x = 0; x < len; x++) {
                digit = (arr[x] / place) % 10;
                count[digit]++;
            }
            
            // cumulative sum
            for (x = 1; x < 10; x++) {
                count[x] += count[x - 1];
            } 
            
            // output array
            int output[len];
            for (x = len - 1; x >= 0; x--) {
                digit = (arr[x] / place) % 10;
                output[count[digit] - 1] = arr[x];
                count[digit]--;
            }
            
            // copy onto input array	
            for (x = 0; x < len; x++) {
                arr[x] = output[x];
            }
        }
	}
}

