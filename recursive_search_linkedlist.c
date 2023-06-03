#include<stdio.h>
#include<stdlib.h>

// Linked List
struct node{
	int data;
	struct node *next;
};

// Head and Tail
struct node *head=NULL;
struct node *tail=NULL;

// Add Node
int addNode(int data){
	// Linked is empty
	if(head==NULL){
		struct node* new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		
		head=tail=new;
	}
	//Linked is not empty
	else{
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		
		tail->next=new;
		tail=new;//tail->data=new->data;(Aynısı)
	}
	return 1;	
}
// Add Node at Head
int addHead(int data){
	// Linked is empty
	if(head==NULL){
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		
		head=tail=new;		
	}
	//Link is not Empty
	else{
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=head;
		
		head=new;
	}
}
// Delete Node 
int delete(int data){

    struct node *prev = NULL;
    struct node *index = head;

    // Linked List is empty
    if(head==NULL){
        printf("Linked List is empty \n");
        return 1;
    }

    // Delete Head Node
    if(head->data==data){
        struct node *t = head;
        head = head->next;
        free(t);
        return 1;
    }

    // Search in Linked List
    while(index!=NULL && index->data!=data){
        prev = index;
        index = index->next;
    }

    // Data not found
    if(index==NULL){
        printf("Data not found. \n");
        return 1;
    }

    // Data found
    prev->next = index->next;

    // Delete Tail Node
    if(tail->data==data){
        tail = prev;
    }

    // Clean Memory
    free(index);

    return 1;
}

// Print Node
int print(){
	printf("Linked List: ");
	struct node *index=head;
	while(index!=NULL)
	{
		printf("%d - ",index->data);	
		index=index->next;
	}
	printf("\n");
}
int findx(thing){

struct node *new=head;
	while(new){
		if(new->data==thing){
			return 1;
		}
		new=new->next;
	}
	return 0;
}

// Find Node
int find(struct node *head,int x)
{
	
	if (head == NULL)
        return 0;
    if (head->data == x)
        return 1;
	
	return find(head->next, x);
}
int main(){
	addNode(10);
	addNode(20);
	addNode(30);
	addHead(2);
	addHead(1);
	delete(10);
	print();
	
printf(" \n %d",find(head,5));
	
	
	
}


