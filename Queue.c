#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void display(){
	if(front==NULL){
		printf("Queue is null");
		
	}
	else{
	struct node *index=front;
	while(index!=NULL){
	
		printf("%d - ",index->data);
		
		index=index->next;
		
	}
		
	}
}

//insert node
void enqueue(int data){
	//Queue is emptyy
	if((front==NULL)&&(rear==NULL)){
		struct node *annew;
		annew=(struct node * )malloc(sizeof(struct node));
		annew->data=data;
		annew->next=NULL;
	
		front=rear=annew;
		front->next=annew;
		
		
		
		
	
	}
	//Queue is not empty
	else{
		struct node *annew=(struct node*)malloc(sizeof(struct node));
		annew->data=data;
		annew->next=NULL;
		
		rear->next=annew;
		rear=annew;
		
	}
	
}
int dequeue(){
	if(front==NULL){
		printf("Queue is null");
		return 1;		
	}
	struct node *temp=front;
	front=front->next;
	free(temp);
	return 1;
	
}


int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	display();
	return 1;
	
}
