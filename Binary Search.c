#include <stdio.h>

// Function declarations
void InputArray(int n, int A[]);
void PrintArray(int n, int A[]);
void BubbleSort(int n, int A[]);
void BinarySearch(int n, int A[], int Searchno);

int main() {
    int n, A[20], Searchno;

    printf("How many numbers? ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    InputArray(n, A);

    BubbleSort(n, A);

    printf("Numbers After Sorting:\n");
    PrintArray(n, A);

    printf("\nEnter the element to be searched: ");
    scanf("%d", &Searchno);

    BinarySearch(n, A, Searchno);

    return 0;
}

// Function to input an array
void InputArray(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

// Function to print an array
void PrintArray(int n, int A[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to sort the array using Bubble Sort
void BubbleSort(int n, int A[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search
void BinarySearch(int n, int A[], int Searchno) {
    int low = 0, high = n - 1, mid, found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (A[mid] == Searchno) {
            found = 1;
            printf("%d is present at position %d.\n", Searchno, mid + 1);
            break;
        } else if (A[mid] > Searchno) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("%d is not present in the array.\n", Searchno);
    }
}
