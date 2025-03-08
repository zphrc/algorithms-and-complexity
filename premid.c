#include <stdio.h>
#define LENGTH 100

typedef struct {
    int elem[LENGTH];
    int count;
} List;

void display(List);
List TwoWaySortMerge(List, List);

int main() {
    List A = {{1, 3, 7}, 3};
    List B = {{2, 4, 5, 6}, 4};
    printf("List A: "); display(A);
    printf("\nList B: "); display(B);
    List C = TwoWaySortMerge(A, B);
    printf("\nList C (after merging A and B): "); display(C);
}

void display(List A) {
    int x;
    for (x = 0; x < A.count; x++) {
        printf("%d ", A.elem[x]);
    }
}

List TwoWaySortMerge(List A, List B) {
    List C;
    int x, y;
    x = y = C.count = 0;

    while (x < A.count && y < B.count) {
        C.elem[C.count++] = (A.elem[x] < B.elem[y]) ? A.elem[x++] : B.elem[y++];
    }
    while (x < A.count) {
        C.elem[C.count++] = A.elem[x++];
    }
    while (y < B.count) {
        C.elem[C.count++] = B.elem[y++];
    }
    return C;
}