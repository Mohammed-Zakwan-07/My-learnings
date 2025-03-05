/*-------------------------------
          StackApplications.c
          5/3/25
---------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

typedef struct {
    int arr[SIZE];
    int top;
} STACK;

STACK s;

// Function prototypes
void menu();
void initStack();
void push(int num);
int pop();
void pushs(char ch);
char pops();
int isEmpty();
// 5 programs
void reverse();
void palindrome();
void factorial();
void fibonacci();
void DecimalToBinary();

int main() {
    int n, num, ch;
    initStack();
    menu();
    
    while (1) {
        printf("\nYour choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\n");
                reverse();
                break;
                
            case 2:
                printf("\n");
                palindrome();
                break;
                
            case 3:
                printf("\n");
                factorial();
                break;
                
            case 4:
                printf("\n");
                fibonacci();
                break;
                
            case 5:
                printf("\n");
                DecimalToBinary();
                break;

            case 6:
                printf("\n");
                printf("exiting........");    
                exit(0);
            default:
                printf("\n");
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}

// Initialize stack
void initStack() {
    s.top = -1;
}

// Display menu
void menu() {
    printf("STACK Applications \n");
    printf("1. Reverse a string\n");
    printf("2. Palindrome or not\n");
    printf("3. Factorial\n");
    printf("4. Fibonacci\n");
    printf("5. Decimal to binary converter\n");
    printf("6. Exit\n");
}

// Push operation
void push(int num) {
    if (s.top == SIZE - 1) {
        printf("Stack overflow! Cannot push %d.\n", num);
        return;
    }
    s.arr[++s.top] = num;
}

// Push operation for char
void pushs(char ch) {
    if (s.top == SIZE - 1) {
        printf("Stack overflow! Cannot push %c.\n", ch);
        return;
    }
    s.arr[++s.top] = ch;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Nothing to pop.\n");
        return -1;
    }
    return s.arr[s.top--];
}

// Pop operation for char
char pops() {
    if (isEmpty()) {
        printf("Stack underflow! Nothing to pop.\n");
        return '\0';
    }
    return s.arr[s.top--];
}


// Check if stack is empty
int isEmpty() {
    return s.top == -1;
}

// reverse a string 
void reverse() {
    char str[SIZE];
    char answer[SIZE];
    int j = 0; 

    printf("Enter the string : ");
    scanf("%s", str);

    int n = strlen(str);
    initStack();

    for (int i = 0; i < n; i++) { 
        pushs(str[i]);
    }

    while (s.top != -1) {
        answer[j++] = pops();
    }
    answer[j] = '\0'; 

    printf("The reversed string is: %s\n", answer);
}

// palindorm or not
void palindrome() {
    char str[SIZE];
    char reversed[SIZE];
    int j = 0;

    printf("Enter the string to check palindrome: ");
    scanf("%s", str);

    int n = strlen(str);
    initStack();

    for (int i = 0; i < n; i++) {
        pushs(str[i]);
    }

    while (!isEmpty()) {
        reversed[j++] = pops();
    }
    reversed[j] = '\0';

    if (strcmp(str, reversed) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

// Factorial function
void factorial() {
    int i = 1, n, fact, num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    
    initStack();
    
    push(1);
    while(i <= n) {
        push(pop() * i);
        i++;
    }
    fact = pop();

    printf("Factorial of %d is %d\n", n, fact);
}

// Fibonacci series function
void fibonacci() {
    int i, n, F1 = 0, F2 = 1, F3;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);

    initStack();

    push(F1);
    push(F2);
    
    i = 1;
    
    while (i <= n) {
        F2 = pop();
        F1 = pop();
        F3 = F2 + F1;
        
        push(F1);
        push(F2);
        push(F3);
        i++;
    }
    printf("Fibonacci series : ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}


// Decimal to Binary converter
void DecimalToBinary() {
    initStack();
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num > 0) {
        push(num % 2);
        num /= 2;
    }

    printf("Binary equivalent: ");
    while (!isEmpty()) {
        printf("%d", pop());
    }
    printf("\n");
}
