/*---------------------------------------------------------------
        BinaryTree.c
      	program to perform some operation on tree data structure
      	Zakwan
      	31-1-25
-----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeType {
    int Data;
    struct TreeType *Left;
    struct TreeType *Right;
}TREENODE;
TREENODE *Root = NULL;

//----- prototype ----------
void menu();
void InsertTreeNode(int num);
int SearchNum(TREENODE *Root, int num);
void DisplayLeafNode(TREENODE *Root);
int IsLeafNode(TREENODE *Root, int num);
int MinNum(TREENODE *Root);
int MaxNum(TREENODE *Root);
void Preorder(TREENODE *Root);
void Postorder(TREENODE *Root);
void Inorder(TREENODE *Root);

void main () {
    int n, num, num1, num2, ch;
    
    menu();
    
    while(1) {
    	printf("\nYour Choice : ");
    	scanf("%d", &ch);
    	printf("\n");
    	
    	switch(ch) {
    		case 1:
    			printf("How many numbers ? ");
    			scanf("%d", &n);
    			for (int i = 1; i <= n; i++) {
        			printf("%d : ", i);
        			scanf("%d", &num);
        			InsertTreeNode(num);
    			}
    			break;
    		
    		case 2:
    			printf("Enter the number to be searched : ");
    			scanf("%d", &num1);
    			if (SearchNum(Root,num1)) {
    				printf("The number is present \n");
				}else{
					printf("The number is not present \n");
				}
				break;
			
			case 3:
				DisplayLeafNode(Root);
				break;
				
			case 4:
				printf("Enter the number : ");
				scanf("%d", &num2);
				if (IsLeafNode(Root, num2)) {
					printf("%d is a leaf node \n");
				}else{
					printf("%d is not a leaf node \n");
				}
				break;
				
			case 5:
				printf("The smallest number in the tree is %d\n", MinNum(Root));
				break;
			
			case 6:
				printf("The larest number in the tree is %d\n", MaxNum(Root));
				break;
				
			case 7:
				printf("Preorder traversal \n");
    			Preorder(Root);
    			printf("\n");
    			break;
				
			case 8:
				printf("Postorder traversal \n");
			    Postorder(Root);
			    printf("\n");
			    break;
			    
			case 9:
				printf("Inorder traversal \n");
			    Inorder(Root);
			    printf("\n");
			    break;
			
			case 10:
				printf("EXITING.......");
				exit(0);
			default :
				printf("INVALID CHOICE \n");
		}
	}
}
//------ Menu -------------
void menu () {
	printf("----------- Binary Tree -----------\n");
	printf("1.Insert numbers \n");
	printf("2.Search a num \n");
	printf("3.Display leaf node \n");
	printf("4.Check a number is leaf node or not \n");
	printf("5.Return the smallest number \n");
	printf("6.Return the largest number \n");
	printf("7.Preorder traversal\n");
	printf("8.Postorder traversal\n");
	printf("9.Inorder traversal\n");
	printf("10.Exit\n\n");
}
//----- Insertion of numbers -----------
void InsertTreeNode(int num) {
    TREENODE *Prev = NULL, *Curr, *Node;
    
    Node = (TREENODE *)malloc(sizeof(TREENODE));
    
    Node->Data = num;
    Node->Left = NULL;
    Node->Right = NULL;
    
    if (Root == NULL) {
        Root = Node;
        return;
    }
    Curr = Root;
    while (Curr) {
        if (num <= Curr->Data) {
            Prev = Curr;
            Curr = Curr->Left;
        }else{
            Prev = Curr;
            Curr = Curr->Right;
        }
    }
    if (num < Prev->Data) {
        Prev->Left = Node;
    }else{
        Prev->Right = Node;
    }
}
//----- Searching a given number -------
int SearchNum(TREENODE *Root, int num){
	TREENODE *Curr = Root;
	
	if (Root == NULL) {
		return -1;
	}
	
	while(Curr) {
		if (num == Curr->Data){
			return 1;
		}else{
			if (num < Curr->Data){
				Curr = Curr->Left;
			}else{
				Curr = Curr->Right;
			}
		}
	}
	return 0;
}
//----- Displays Leaf node of the tree -----------
void DisplayLeafNode(TREENODE *Root) {
	if (Root) {
		if (Root->Left == NULL && Root->Right == NULL) {
			printf("Leaf Node : %d \n", Root->Data);
		}
		DisplayLeafNode(Root->Left);
		DisplayLeafNode(Root->Right);
	}
}
//----- Check whether the given number is leaf or not ---------
int IsLeafNode(TREENODE *Root, int num) {
	TREENODE *Curr = Root;
	
	if (Root == NULL) {
		return -1;
	}
	
	while(Curr) {
		if (num == Curr->Data) {
			if (Curr->Left == NULL && Curr->Right == NULL){
				return 1;
			}else{
				return 0;
			}
		}else{
			if (num < Curr->Data){
				Curr = Curr->Left;
			}else{
				Curr = Curr->Right;
			}
		}
	}
	return 0;
}
//----- returns the maximun number in the tree -----------
int MaxNum(TREENODE *Root){
	TREENODE *Curr, *Prev;
	Curr = Root;
	
	if (Root == NULL) {
		return -1;
	}
	
	while(Curr) {
		Prev = Curr;
		Curr = Curr->Right;
	}
	return Prev->Data;
}
//----- returns the minimum number in the tree ----------
int MinNum(TREENODE *Root) {
	TREENODE *Curr, *Prev;
	Curr = Root;
	
	if (Root == NULL) {
		return -1;
	}
	
	while(Curr) {
		Prev = Curr;
		Curr = Curr->Left;
	}
	return Prev->Data;
}
//----- prints the numbers in the tree in preorder traversal -----
void Preorder(TREENODE *Root) {
    if (Root) {
        printf("%d ", Root->Data);
        Preorder(Root->Left);
        Preorder(Root->Right);
    }
}
//----- prints the numbers in the tree in postorder traversal -----
void Postorder(TREENODE *Root) {
    if (Root) {
        Postorder(Root->Left);
        Postorder(Root->Right);
        printf("%d ", Root->Data);
    }
}
//----- prints the numbers in the tree in inorder traversal -----
void Inorder(TREENODE *Root) {
    if (Root) {
        Inorder(Root->Left);
        printf("%d ", Root->Data);
        Inorder(Root->Right);
    }
}
