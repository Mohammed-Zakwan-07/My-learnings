#include <stdio.h>
#include <stdlib.h>
#define SIZE 25

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
int peek();
int isEmpty();
void Display();

int main() {
    int n, num, ch;
    initStack();
    
    while (1) {
        menu();
        printf("Your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: // Push
                printf("How many numbers to push? ");
                scanf("%d", &n);
                
                if (n > SIZE - s.top - 1) {
                    printf("Too large! Stack overflow risk.\n");
                    break;
                }

                for (int i = 1; i <= n; i++) {
                    printf("Enter value %d: ", i);
                    scanf("%d", &num);
                    push(num);
                }
                break;

            case 2: // Pop
                num = pop();
                if (num != -1) {
                    printf("Popped number: %d\n", num);
                }
                break;

            case 3: // Peek
                num = peek();
                if (num != -1) {
                    printf("Top of the stack: %d\n", num);
                }
                break;
                
            case 4:
                Display();
                break;

            case 5: // Exit
                printf("Exiting...\n");
                exit(0);

            default:
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
    printf("\nSTACK OPERATIONS\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5.Exit\n");
}

// Push operation
void push(int num) {
    if (s.top == SIZE - 1) {
        printf("Stack overflow! Cannot push %d.\n", num);
        return;
    }
    s.arr[++s.top] = num;
}

// Pop operation
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Nothing to pop.\n");
        return -1;
    }
    return s.arr[s.top--];
}

// Peek operation
int peek() {
    if (isEmpty()) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return s.arr[s.top];
}

// Check if stack is empty
int isEmpty() {
    return s.top == -1;
}

//Display fuction
void Display() {
    if (isEmpty()) {
        printf("Stack empty !!\n");
    }else{
        for (int i = s.top; i >= 0; i--) {
            printf("%d \n", s.arr[i]);
        }
    }
}
