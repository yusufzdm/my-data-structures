#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *rear=NULL;

struct node *allocate(int n)
{
	struct node *tmp=malloc(sizeof(struct node));
	tmp->next=NULL;
	tmp->prev=NULL;
	tmp->data=n;
	return tmp;
	
}

int insert_head(int what){
	struct node *tmp=allocate(what);
	if(head==NULL){
		head=rear=tmp;
		return 1;
	}
	head->prev=tmp;
	tmp->next=head;
	head=tmp;
	
	return 1;
	
}

int insert_rear(int what){
		struct node *tmp=allocate(what);
	if(head==NULL){
		head=rear=tmp;
		return 1;
	}
	tmp->prev=rear;
	rear->next=tmp;
	rear=tmp;
	return 1;
}

struct node *find(int n){
	struct node *index=head;
	while(index && index->data!=n) index=index->next;
	
	return index;

}

int delete(int what){
	
	struct node *index=find(what);
	
	if(index==head){
		head=head->next;
		free(index);
		return 1;
	}
	if(index==rear){
		rear->prev=rear;
		free(index);
		return 1;
		
	}
	struct node *m=index->next;
	struct node *n=index->prev;
	
	n->next=index->next;
	m->prev=n;
	
	free(index);
	
	return 1;
	
	
}
 
void print(){
	struct node *index=head;
	while(index){
		printf("%d ",index->data);
		index=index->next;
	} 
}

int main(){
	insert_head(3);
	insert_head(2);
	insert_head(1);
	insert_rear(4);
	delete(2);
	delete(1);
	print();
}


