#include <stdio.h>

void bubble(int n, int arr[20]) {

	for (int i = 1; i <= n - 1; i++) {
	    for (int j = 1; j <= n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
	    }
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
    
    bubble(n, A);
    
    printf("the sorted array: ");
    for ( i=1; i<=n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}
