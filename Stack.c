#include<stdio.h>
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
void peek(){
	if(is_empty()){
		printf("Stack Underflow");
	}
	else{
		printf("%d\n",s[top]);
	}
	
}
void display(){
	for(int i=0;i<=top;i++){
		printf("%2d : %2d \n",i,s[i]);
	}
	
}
int main(){
	push(10);
	push(11);
	push(12);
	pop();
	display();
	peek();
}

































