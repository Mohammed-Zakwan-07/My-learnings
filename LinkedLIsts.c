/*----------------------------------------------------
                 linkedlist.c
                 program t perform operaation on linked list
                 zakwan
                 19/12/24
------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct ListType {
	int Data;
	struct ListType *Next;
}LISTNODE;

LISTNODE *Head = NULL;

//---prototypes---------
void menu();
void insertion(int num);
void display();
int deletefirst();
int deletelast();
int deletegivennum(int delno);
int maxno();
void FreeList();

void main(){
    int ch, n, num;
    
    menu();
    
	while(1) {
	    
	    printf("Your choice ? ");
	    scanf("%d", &ch);
		
		switch(ch) {
			case 1:
				printf("how many numbers ? ");
				scanf("%d", &n);
				printf("Enter the numbers :\n");
				for ( int i = 1; i <= n; i++){
					printf("%d :", i);
					scanf("%d", &num);
					insertion(num);
				}
				printf("\n\n");
				break;
				
			case 2:
				display();
				printf("\n\n");
				break;
			
			case 3:
				int del1 = deletefirst();
				printf("%d is deleted from the list\n",del1);
				display();
				printf("\n\n");
				break;
				
			case 4:
				int del2 = deletelast();
				printf("%d is deleted from the list\n", del2);
				display();
				printf("\n\n");
				break;
				
			case 5:
			    int delno;
			    printf("Enter the number to be deleted :");
			    scanf("%d", &delno);
			    deletegivennum(delno);
			    printf("%d is deleted from the list\n", delno);
			    display();
			    printf("\n\n");
			    break;
				
			case 6:
				int max;
				max = maxno();
				printf("The maximum no is %d\n", max);
				printf("\n\n");
				break;
				
			case 7:
			    FreeList();
				printf("EXITING................\n");
				printf("\n\n");
				exit(0);
				
			default:
				printf("INVALID CHOICE !!!!!!\n");
				printf("\n\n");
				break;
		}
	}
}
//------------------MENU-------------------
void menu()
{
    printf("\n---------------------------\n");
	printf("-----CHOOSE AN OPERATION--------\n");
	printf("1.Insert numbers\n");
	printf("2.Display linked list\n");
	printf("3.Delete first node\n");
	printf("4.Delete last node\n");
	printf("5.Delete a given number\n");
	printf("6.Find the maximum number\n");
	printf("7.EXIT\n");
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
	Curr = Head;
	while (Curr!=NULL) {
		Prev = Curr;
		Curr = Curr->Next;
	}
	Prev->Next = Node; 
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
	while(Curr != NULL) {
		printf("%d->", Curr->Data);
		Curr = Curr->Next;
	}
	printf("NULL\n");
}
//-----------DELTING FIRST NODE-------------
int deletefirst() 
{
	LISTNODE *Curr;
	
	if (Head == NULL) {
		printf("THE LIST IS EMPTY\n");
		return 0;
	}
	Curr = Head;
	Head = Head->Next;
	int num = Curr->Data;
	free(Curr);
	return num;
	
}
//---------------DELETING LAST NODE-------------
int deletelast()
{
	LISTNODE *Curr, *Prev;
	
	if (Head == NULL) {
		printf("The list is empty\n");
		return 0;
	}
	Curr = Head;
	while(Curr->Next != NULL) {
		Prev = Curr;
		Curr = Curr->Next;
	}
	int num = Curr->Data;
	Prev->Next = NULL;
	free(Curr);
	return num;
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
//----------------MAXIMUM NO------------------
int maxno()
{
	LISTNODE *Curr;
	
	if (Head == NULL) {
		printf("THE LIST IS EMPTY\n");
		return 0;
	}
	Curr = Head;
	int max = Curr->Data;
	while(Curr != NULL) {
		if (max < Curr->Data){
			max = Curr->Data;	
		}
		Curr = Curr->Next;
	}
	return max;
}
//------------free the list--------------------
void FreeList() {
    LISTNODE *temp;
    
    while (Head != NULL) {
        temp = Head;
        Head = Head->Next;
        free(temp);
    }
    printf("Memory freed successfully.\n");
}
