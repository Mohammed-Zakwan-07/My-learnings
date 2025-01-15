/*----------------------------------------------------------------
				queue.c
			program to enqueue and dequeue
				zakwan
				10/1/25
------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int Data;
	struct Queue *Next;
}CIRQUEUENODE;

CIRQUEUENODE *Front, *Rear;

//-------------prototype
void menu();
void InitQueue ();
void Enqueue (int num);
void Display ();
int Dequeue ();

void main ()
{
	int ch, n, num, del;
	
	menu();
	
	while(1){
		printf("\nYOUR CHOICE :");
		scanf("%d",&ch);
		
		switch(ch) {
			case 1:
				printf("how many numbers ?");
				scanf("%d", &n);
				for (int i=1; i<=n; i++) {
					printf("%d : ", i);
					scanf("%d", &num);
					Enqueue(num);
				}
				break;
			case 2:
				Display();
				break;
			case 3:
				del = Dequeue();
				if (del == -1){
				    break;
				}
				printf("The number %d got deleted\n", del);
				Display();
				break;
			case 4:
				printf("EXITING.......");
				exit(1);
			default :
				printf("INVALID CHOICE\n");
				break;
		}
	}
}
//------------------menu------
void menu()
{
	printf("-----------QUEUE----------\n");
	printf("1.Enqueue\n");
	printf("2.Display\n");
	printf("3.Dequeue\n");
	printf("4.EXIT\n\n");
}
//-------------------InitQueue----------
void InitQueue()
{
	Front = NULL;
	Rear = NULL;
}
//-------------------Enqueue------------
void Enqueue(int num)
{
	CIRQUEUENODE *Node;
	
	Node = (CIRQUEUENODE *)malloc(sizeof(CIRQUEUENODE));
	
	Node->Data = num;
	Node->Next = NULL;
	
	if (Front == NULL){
		Front = Node;
		Rear = Node;
		return;
	}
	Rear->Next = Node;
	Rear = Node;
	Rear->Next = Front;
}
void Display()
{
    CIRQUEUENODE *Curr;
	if (Front == NULL) {
		printf("The queue is empty\n");
		return;
	}
	Curr = Front;
	do{
		printf("%d -> ", Curr->Data);
		Curr = Curr->Next;
	}while(Curr != Front);
	
	printf("NULL\n");
}
int Dequeue()
{
	CIRQUEUENODE *Curr;
	int num;
	if (Front == NULL) {
		printf("The queue is empty\n");
		return -1;
	}
	Curr = Front;
	if (Front == Rear) {
		num= Front->Data;
		free(Curr);
		Front = NULL;
		Rear = NULL;
		return num;
	}
	Curr = Front;
	num = Front->Data;
	Front = Front->Next;
	Rear->Next = Front;
	free(Curr);
	return num;
}
