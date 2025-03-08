#include <stdio.h>
#include <string.h>
#define MAX 10

/*
    Gnome Sort
    ----------
    Time Complexity:
        - Best Case: O(n)  (Already sorted array)
        - Average and Worst Case: O(n^2)
    
    Space Complexity: O(1) (In-place sorting)
    
    Stability: Yes (It preserves the relative order of equal elements)
*/

void display(int*);
void gnome_sort(int*);

int main() {
    int mainArr[MAX] = {10, 4, 5, 6, 4, 4, 8, 9, 2, 7};
    char algo[24];

    printf("Unsorted list: ");
    display(mainArr);

    strcpy(algo, "Gnome Sort"); gnome_sort(mainArr);

    printf("\nSorted list using %s: ", algo);
    display(mainArr);

    return 0;
}

void display(int arr[]) {
    int x;
    for (x = 0; x < MAX; x++) {
        printf("%d ", arr[x]);
    }
}

void gnome_sort(int arr[]) {
    int x, temp;
    for (x = 1; x < MAX; ) {
        if (x == 0 || arr[x] >= arr[x - 1]) {
            x++;
        } else {
            temp = arr[x];
            arr[x] = arr[x - 1];
            arr[x - 1] = temp;
            x--;
        }
    }
}