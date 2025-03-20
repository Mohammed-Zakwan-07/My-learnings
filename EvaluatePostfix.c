/*---------------------------
    InfixtoPostfix.c
    24/2/25
    zakwan
-----------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define Size 25

typedef struct SType {
    char Arr[Size];
    int Top;
} STACK;

STACK S;

//-----------------prototype------
void Push(char s);
char Pop();
int IsEmpty();
char *InfixToPostfix(char Infix[]);
int EvaluatePostfix(char *Postfix);
int Precedence(char optr);

int main() {
    char *Postfix, Infix[Size];
    S.Top = -1;
    
    printf("Infix expression: ");
    fgets(Infix, Size, stdin);

    Postfix = InfixToPostfix(Infix);
    
    printf("Postfix expression: %s\n", Postfix);
    
    printf("Result of the expression : %d", EvaluatePostfix(Postfix));
    return 0;
}

//-----------------push-------------
void Push(char s) {
    if (S.Top == Size - 1) {
        printf("Stack overflow\n");
        return;
    } else {
        S.Arr[++S.Top] = s;
    }
}

//-------------pop---------------
char Pop() {
    if (S.Top == -1) { 
        printf("Stack underflow\n");
        return '\0';
    }
    return S.Arr[S.Top--]; 
}

//-------------------is empty----------
int IsEmpty() {
    return (S.Top == -1);
}

//--------------precedence ----------
int Precedence(char optr) {
    switch(optr) {
        case '(':
            return 1;
        case ')':
            return 2;
        case '+': case '-':
            return 3;
        case '*': case '/':
            return 4;
        case '^':
            return 5;
        default:
            return 0;
    }
}

//------------Infix to Postfix-------
char *InfixToPostfix(char Infix[]) {
    char Postfix[Size];
    int i = 0, j = 0;
    char ch, optrstack;
    
    char *Result = (char *)malloc(Size * sizeof(char));

    while ((ch = Infix[i]) != '\0') {
        if (ch == '(') {
            Push(ch);
        } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            Postfix[j++] = ch;
            Postfix[j++] = ' ';
        } else if (strchr("+-*/^", ch)) {
            while (!IsEmpty()) {
                optrstack = Pop();
                if (Precedence(optrstack) >= Precedence(ch)) {
                    Postfix[j++] = optrstack;
                    Postfix[j++] = ' ';
                } else {
                    Push(optrstack);
                    break;
                }
            }
            Push(ch);
        } else if (ch == ')') {
            while (!IsEmpty() && (optrstack = Pop()) != '(') {
                Postfix[j++] = optrstack;
                Postfix[j++] = ' ';
            }
        }
        i++;
    }
    while (!IsEmpty()) {
        Postfix[j++] = Pop();
        Postfix[j++] = ' ';
    }
    
    Postfix[j] = '\0';
    strcpy(Result, Postfix);
    return Result;
}
int EvaluatePostfix(char *Postfix) {
	int i;
    for (i = 0; Postfix[i] != '\0'; i++) {
        char curr = Postfix[i];
        
        if (isdigit(curr)) {
            Push(curr - '0');
        } else if (curr != ' ') {
            int opt2 = Pop();
            int opt1 = Pop();
            
            switch(curr) {
                case '+':
                    Push(opt1 + opt2);
                    break;
                case '-':
                    Push(opt1 - opt2);
                    break;
                case '*':
                    Push(opt1 * opt2);
                    break;
                case '/':
                    if (opt2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    Push(opt1 / opt2);
                    break;
                case '^':
                    Push((int)pow(opt1, opt2));
                    break;
            }
        }
    }
    return Pop();
}
