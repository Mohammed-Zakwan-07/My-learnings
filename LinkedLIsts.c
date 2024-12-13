#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct ListType {
    int Data ;
    struct ListType *Next;
}LISTNODE;
LISTNODE *Head = NULL;

//---prototypes------
int menu();
void insertion(int n);
void display();
void deletion(int n);


int main () {
    int n, ch, del;
    
    while (1) {
        ch = menu();
        
        switch (ch) {
            case 1:
            printf("How many numbers? ");
            scanf("%d", &n);
            insertion(n);
            break;
        
            case 2:
            display();
            break;
        
            case 3:
            printf("enter the number to be deleted :");
            scanf("%d", &del);
            deletion(del);
            break;
        
            case 4:
            printf("EXITING...");
            exit(0);
        
            default :
            printf("invalid choice");
            break;
        }
    }
}
//---------------------functions------------------------------

int menu() {
    int choice;
    printf("\n-----------------------------------------------------\n");
    printf("----------------CHOOSE AN OPERATION--------------------\n");
    printf("1.Insert a number in linked list\n");
    printf("2.Display the contents of the linked list\n");
    printf("3.Delete a given number in the linked list\n");
    printf("4.EXIT\n\n");
    printf("Your choice? ");
    scanf("%d", &choice);
    
    return choice;
}

void insertion(int n) {
	
    LISTNODE *node, *curr;
    int num;
    
    for ( int i = 1; i <= n; i++) {
        printf("enter the %d number :", i);
        scanf("%d", &num);
        
        node = (LISTNODE*)malloc(sizeof(LISTNODE));
        if (node == NULL) {
            printf("memory allocation failed\n");
            return;
        }
        
        node->Data = num;
        node->Next = NULL;
        
        if (Head == NULL) {
        Head = node;
        }else {
            curr = Head;
            while ( curr->Next != NULL) {
                curr = curr->Next;
            }
            curr->Next = node;
        }
    }
}

void display() {
    LISTNODE *curr;
    
    if (Head == NULL) {
        printf("The list is empty\n");
        return;
    }
    
    curr = Head;
    
    while (curr != NULL) {
        printf("%d->", curr->Data);
        curr = curr->Next;
    }
    printf("NULL\n");
}

void deletion(int del) {
    LISTNODE *curr = Head;
    LISTNODE *prev = NULL;
    
    while (curr != NULL) {
        if (curr->Data == del) {
            
            if (curr == Head) {
               Head = curr->Next; 
            }else {
                prev->Next = curr->Next;
            }
            free(curr);
            printf("DELETED %d from the list.\n", del);
            return;
        }
        prev = curr;
        curr = curr->Next;
    }
    printf("THE NUMBER %d IS NOT FOUND IN THE LIST\n", del);
}
