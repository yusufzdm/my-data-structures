#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *front=NULL;
struct node *rear=NULL;

struct node * allocate(int data){
	struct node *tmp=malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}

int is_empty(){
	return front == NULL;
}

struct node* enqueue(int data){
	struct node *n=allocate(data);
	struct node *tmp=front;
	struct node *prev=front;
	
	if(is_empty()){
		front=n;
		rear=n;
		return n;
	}
	if(front==rear){  
		if(front->data > data){
			n->next=front;
			rear=front;
			front=n;
		}else{
			front->next=n;
			rear=n;
		}
		return front;
	}
	while(tmp){
		if(tmp->data > data) break;
		prev=tmp;
		tmp=tmp->next;	
	}
	if(tmp==NULL){
		rear=n;
	}
	prev->next=n;
	n->next=tmp;
	return front;
}

int dequeue( ){
	if(is_empty()){
		printf("empty queue!");
		return 0;
	}
	if(front==rear){
		int res=front->data;
		free(front);
		front=NULL;
		rear=NULL;
		return res;
	}
	int res=front->data;
	struct node* n=front;
	front=front->next;
	free(n);
	return res;
	
} 

int print(){
	struct node* tmp=front;
	printf("the contents of the Q: ");
	while(tmp){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return 0;
	
}

int main(){
	enqueue(2);
	enqueue(1);
	enqueue(9);
	dequeue();
	enqueue(5);
	print();
	
}
