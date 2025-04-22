#include <stdio.h>

void selection (int n, int A[20]) {
    for (int i = 1; i < n; i++) {
        int min = i;
        for (int j = i + 1; j <= n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
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
    
    selection(n, A);
    
    printf("the sorted array: ");
    for ( i=1; i<=n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}
