#include <stdio.h>

void insertion (int n, int A[20]) {
    for (int i = 1; i <= n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[20], i, j, n, min;
    
    printf("how many numbers? ");
    scanf("%d", &n);
    
    printf("enter the numbers: \n");
    for ( i=1; i<=n; i++){
        scanf("%d", &A[i]);
    }
    
    insertion(n, A);
    
    printf("the sorted array: ");
    for ( i=1; i<=n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}
