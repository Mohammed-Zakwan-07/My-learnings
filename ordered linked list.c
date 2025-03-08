/*--------------------------------------------------------------------
                  oredered linked list
                program to perform operation on linked list
                zakwan
                9/1/25
--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct ListType {
    int Data;
    struct ListType *Next;
}LISTNODE;
LISTNODE *Head = NULL;

//-----prototypes
void menu();
void insertion (int num);
void display ();
int deletegivennum(int del);
void searchno (int searchno);
int TotalNoOfNodes ();

void main () 
{
    int n, ch, num, delno, search;
    
    menu();
    
    while(1) {
        printf("Your choice :");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("how many numbers ?");
                scanf("%d", &n);
                for(int i = 1; i<=n; i++) {
                    printf("enter the %d number :\n", i);
                    scanf("%d", &num);
                    insertion(num);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Which number to delete ?");
                scanf("%d", &delno);
                deletegivennum(delno);
                break;
            case 4:
                printf("Enter the element to search :");
                scanf("%d", &search);
                searchno(search);
                break;
            case 5:
                int NO = TotalNoOfNodes();
                printf("there are %d nodes in the linked list\n", NO);
                break;
            case 6:
                printf("EXITING..........");
                exit(1);
            default :
                printf("INVALID CHOICE\n");
                break;
        }
    }
}
//---------------menu-----------
void menu()
{
    printf("\n---------------------------\n");
	printf("-----CHOOSE AN OPERATION--------\n");
	printf("1.Insert numbers\n");
	printf("2.Display linked list\n");
	printf("3.Delete a given number\n");
	printf("4.Search a given nnumber\n");
	printf("5.Total no of nodes\n");
	printf("6.EXIT\n");
}
//------------------Insertion-------------------
void insertion(int num)
{
	LISTNODE *Node ,*Curr, *Prev;
	
	Node = (LISTNODE*)malloc(sizeof(LISTNODE));
	Node->Data = num;
	Node->Next = NULL;
	
	if (Head == NULL) {
		Head = Node;
		return;
	}
	if (Head->Data > num) {
	    Node->Next = Head;
	    Head = Node;
	    return;
	}
	Curr = Head;
	while (Curr && num >= Curr->Data) {
		Prev = Curr;
		Curr = Curr->Next;
	}
	Prev->Next = Node; 
	Node->Next = Curr;
}
//-----------DISPLAY---------------------------
void display()
{
	LISTNODE *Curr;
	
	if (Head == NULL) {
		printf("THE LIST IS EMPT!!\n");
		return;
	}
	
	Curr = Head;
	while(Curr) {
		printf("%d->", Curr->Data);
		Curr = Curr->Next;
	}
	printf("NULL\n");
}
//----------------Delete a given number-------
int deletegivennum(int delno)
{
    LISTNODE *Curr, *Prev ;
    
    Curr = Head;
    Prev = Curr;
    
    if (Head == NULL) {
        printf("The list is empty\n");
        return 0;
    }
    
    if (Head->Data == delno) {
        Head = Curr->Next;
        free(Curr);
        return 0;
    }
    
    while(Curr) {
        if (Curr->Data == delno) {
            Prev->Next = Curr->Next;
            free(Curr);
            return 0;
        }
        Prev = Curr;
        Curr = Curr->Next;
    }
}
//-----------------------seraching
void searchno(int searchno) {
    LISTNODE *Curr = Head;
    int i = 1;

    if (Head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (Curr) {
        if (searchno == Curr->Data) {
            printf("The number %d is found at position %d.\n", searchno, i);
            return;
        }
        Curr = Curr->Next;
        i++;
    }

    printf("The number %d is not found.\n", searchno);
}
//----------------no of nodes
int TotalNoOfNodes() {
    int count = 0;
    LISTNODE *Curr = Head;

    while (Curr) {
        count++;
        Curr = Curr->Next;
    }

    return count;
}
