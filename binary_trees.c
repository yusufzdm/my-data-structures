#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *Ltree;
	struct node *Rtree;
};

struct node *root=NULL;
//create node 
struct node *create_node(int value){
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->Ltree=NULL;
	new_node->Rtree=NULL;
	if(root==NULL)
		root=new_node;
	return new_node;
}
// İnsert node on Binary Tree
struct node *insert_node(struct node *root,int value){
	if(root==NULL)
	 return create_node(value);
	 
	if(value < root->data){
		root->Ltree= insert_node(root->Ltree, value);
	}
	else if(value > root->data){
		root->Rtree=insert_node(root->Rtree, value);
		
	}
	
	return root;
	
	
}
// Traversing with inorder type in Binary Tree
void inorder_traversal(struct node* root) {
    if(root !=NULL)
	{
	
    inorder_traversal(root->Ltree);
    printf("%d ", root->data);
    inorder_traversal(root->Rtree);
	}
}
// Search function in Binary Tree
int search(struct node *root,int key){
	
	
	
	while (root != NULL){
		if(key > root->data){
			return search(root->Rtree, key);
		}
		else if(key < root->data){
			return search(root->Ltree, key);
		}
		else 
			return 1;
	}
	
	return 0;
	
		
}

int max(struct node *x){
	//search max value
	while(x->Rtree!=NULL){
		x=x->Rtree;
	}
	return x->data;
	
}
int min(struct node *x){//search min value
	while(x->Ltree!=NULL){
		x=x->Ltree;
	}
	return x->data;
	
}
struct node* delete(struct node* root,int key){
	if(root==0)//if tree is empty
		return NULL;
	if(root->data==key)	{
	
		if(root->Rtree==NULL && root->Ltree==NULL){//if tree's left and right leaf is empty
			root=NULL;
			return root;
			
		}
		
		if(root->Rtree!=NULL){//value is found but Rtree's is not empty
			root->data=min(root->Rtree);
			root->Rtree=delete(root->Rtree,min(root->Rtree));
			return root;
			
		}
		//value is found but Ltree's is not empty
		root->data=max(root->Ltree);
		root->Ltree=delete(root->Ltree,max(root->Ltree));
		return root;
		
	}
	if(root->data>key){
		//Value not founded but search value on left side
		
		root->Ltree=delete(root->Ltree,key);
		return root;
	}
	//Value not founded but search value on right side
	root->Rtree=delete(root->Rtree,key);
	return root;
		
		
}

int main(){
	insert_node(root,5);
	insert_node(root,2);
	insert_node(root,1);
	insert_node(root,8);
	insert_node(root,6);
	insert_node(root,7);
	insert_node(root,9);
	
    
    
	delete(root,5);
	inorder_traversal(root);
	
		
	
	
}










