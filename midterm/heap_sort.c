#include <stdio.h>
#define MAX 7

void display(int *);

int main() {
    int arr[] = {5, 8, 4, 6, 7, 3, 5};

    return 0;
}

void display(int arr[]){
    int x;
    printf("Unsorted: ");
    for (x=0;x<MAX;x++){
        printf("%d ",arr[x]);
    }
}