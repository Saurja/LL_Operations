#include<conio.h>
#include <stdio.h>
#include <stdlib.h>

// Defining a node in a linked list
struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

// To display the linked list
void Display(struct Node *p)
	{
	while(p!=NULL)
	{
	printf("%d ",p->data);
	p=p->next;
	}
}

// To display the linked list in the reversed order
void RDisplay(struct Node *p)
{
	if(p!=NULL)
	{
	RDisplay(p->next);
	printf("%d ",p->data);
	}
}

// To count the number of element in the linked list
int count (struct Node *p){
	if (p==NULL) {
		return 0;
	}else{
		return count(p->next)+1;
	}
}

// To get the max element in a linked list
void max (struct Node *p){
	int max = -32786;
	while(p!=NULL){
		if(max < p->data){
			max = p->data;
			p=p->next;
		}else{
			p=p->next;
		}
	}
	printf("\nMax Element: %d", max);
}

// To insert at first position
void insertFirst(int x){
	struct Node * t = (struct Node *)malloc(sizeof(struct Node *));
	t->data = x;
	
	t->next = first;
	first=t;
}

// To insert at last position
void insertLast(struct Node *p,int x){
	if(p!=NULL){
		struct Node * t = (struct Node *)malloc(sizeof(struct Node *));
		t->data = x;
		int i;
		p=first;
		while(p->next!=NULL){
			p=p->next;
		}
		t->next = NULL;
		p->next=t;
	}else{
		insertFirst(x);
	}

}

// To add element at a given position
void InsertAtPos(struct Node *p,int index,int x)
{
	struct Node * t = (struct Node *)malloc(sizeof(struct Node *));
	t->data = x;	
	if(index == 0){
		t->next = first;
		first=t;
	}else{
		p = first;
		int i;
		for(i=0;i<index-1;i++){
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}

}

// To add element in a sorted linked list
void insertSorted(struct Node *p,int x){
	
	int i;
	//struct Node * q=NULL;
	while(p->next->data < x && p->next){
		//q=p;
		p=p->next;
	}
	struct Node * t = (struct Node *)malloc(sizeof(struct Node *));
	t->data = x;
	t->next = p->next;
	p->next=t;
}

// Delete First Node
void deleteFirst(){
	struct Node *p = first;
	first = first->next;
	free(p);
}

// Delete at any Node
void deleteAtPos(int index){
	int i;
	struct Node *p;
	struct Node *q;
	
	if(index == 0){
		deleteFirst();
	}else{
		p = first;q = NULL;
		
		for(i=1;i<=index && p;i++){
			q=p;
			p=p->next;
		}
		if(p){
			q->next = p->next;
			free(p);
		}
	}
	
}


int main()
{
	int n;
	while(1){
		system("cls");
		printf("Select a option :\n0.Exit\n1.Insert at front\n2.Insert at end\n3.Insert at Position n\n4.Display Linked List\n5.Get max Element\n6.Get Length\n7.delete first\n8.Delete at position n\nChoice:");
		int x, pos, c;
		scanf("%d", &n);
		switch (n){
			case 0:
				exit(1);
			case 1:
				printf("\n**Inserting at front\n");
				printf("Enter data to insert: "); 
				scanf("%d", &x);
				insertFirst(x);
				break;
			case 2:
				printf("\n**Inserting at end\n");
				printf("Enter data to insert: "); 
				scanf("%d", &x);
				insertLast(first,x);
				break;
			case 3:
				printf("\n**Inserting at end\n");
				printf("Enter data to insert and pos: "); 
				scanf("%d", &x);
				scanf("%d", &pos);
				InsertAtPos(first,pos,x);
				break;
			case 4:
				printf("\n**Display\n");
				Display(first);
				getch();
				break;
			case 5:
				max(first);
				getch();
				break;
			case 6:
				c = count(first);
				printf("Lenght : %d \n", c);
				getch();
				break;
			case 7:
				deleteFirst();
				break;
			case 8:
				printf("Delete pos : "); 
				scanf("%d", &pos);
				deleteAtPos(pos);
				break;
			default:
				printf("Wrong option");
				getch();
		}
	}
	
		
	
	return 0;
}
