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




////Stack 
#define SIZE 10
int s[SIZE];
int top=-1;
int is_empty(){
	return top<=-1;
}

int pop(){
	if(is_empty()){
		printf("Stack Overflow\n");
		return -1;
	}	
	
	int val=s[top];
	top--;
	return val;
	
}

int push(int data){
	if(top>=SIZE){
		printf("Stack overflow");
	}
	s[++top]=data;
	return data;
	
}

void display(){
	for(int i=0;i<=top;i++){
		printf("%2d : %2d \n",i,s[i]);
	}
	
}

//In here we are deleting and transfering to stack each node 
int intostack(struct node* head) {
   printf("Linked list:");
   while(head!=NULL) {
   		//Transferring
    	printf("%d ", head->data);
    	s[++top] = head->data;
        //Deleting
		struct node *t = head;
        head = head->next;
        free(t);
    }
	
}

//Transfer the reverse version back to the linked list
int stacktolink(int s[]){
	while(top>=0){
		addNode(s[top]);
		--top;
	}
}

int main(){
	addNode(10);
	addNode(11);
	addNode(12);
	addNode(13);
	
	intostack(head);
	
	stacktolink(s);
	
	print();
}












































