/*----------------------------------------------------------------
				queue.c
			program to enqueue and dequeue
				zakwan
				10/1/25
------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Patienttype {
    char PID[30];
    char Pname[30];
    char Sickness[30];
}PATIENT;
typedef struct Queue {
	PATIENT P;
	struct Queue *Next;
}QUEUENODE;

QUEUENODE *Front, *Rear;

//-------------prototype
void menu();
void InitQueue ();
void Enqueue (PATIENT P);
void Display ();
void Dequeue ();

void main ()
{
	int ch, n, num, del;
	PATIENT P;
	
	menu();
	
	while(1){
		printf("\nYOUR CHOICE :");
		scanf("%d",&ch);
		
		switch(ch) {
			case 1:
				printf("how many Patients ?");
				scanf("%d", &n);
				for (int i=1; i<=n; i++) {
					printf("Patient ID : ");
					scanf("%s", P.PID);
					printf("Patient Name : ");
					scanf("%s", P.Pname);
					printf("Patient Sickness : ");
					scanf("%s", P.Sickness);
					printf("\n");
					Enqueue(P);
				}
				break;
			case 2:
				Display();
				break;
			case 3:
				if (Front != NULL) {
                    printf("The patient %s got deleted\n", Front->P.Pname);
                }
                Dequeue();
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
void Enqueue(PATIENT P)
{
	QUEUENODE *Node;
	
	Node = (QUEUENODE *)malloc(sizeof(QUEUENODE));
	
	Node->P = P;
	Node->Next = NULL;
	
	if (Front == NULL){
		Front = Node;
		Rear = Node;
		return;
	}
	Rear->Next = Node;
	Rear = Node;
}
void Display()
{
    if (Front == NULL) {
        printf("The queue is empty\n");
        return;
    }
    QUEUENODE *Temp = Front;

    while (Temp) {
        printf("PATIENT ID: %s\n", Temp->P.PID);
        printf("PATIENT NAME: %s\n", Temp->P.Pname);
        printf("PATIENT SICKNESS: %s\n", Temp->P.Sickness);
        printf("\n");
        Temp = Temp->Next;
    }
	
}
void Dequeue()
{
	QUEUENODE *Curr;

    if (Front == NULL) {
        printf("The queue is empty\n");
        return;
    }
    Curr = Front;
    if (Front == Rear) {
        free(Curr);
        Front = NULL;
        Rear = NULL;
    } else {
        Front = Front->Next;
        free(Curr);
    }
}
