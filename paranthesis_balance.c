#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100
char s[SIZE];
int top=-1;

int is_empty(){
	return top<=-1;
}

char pop(){
	if(is_empty()){
		printf("Stack Overflow\n");
		return -1;
	}	
	
	char val=s[top];
	--top;
	return val;
	
}

char push(char data){
	if(top>=SIZE){
		printf("Stack overflow");
	}
	s[++top]=data;
	return data;
	
}
char peek(){
	if(is_empty()){
		printf("Stack Underflow");
	}
	else{
		return s[top];
	}
	
}
void display(){
	for(int i=0;i<=top;i++){
		printf("%d : %s \n",i,s[i]);
	}
	
}
int check_pair(char val1,char val2){
	return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}
int check_balance(char exp[],int len){
	for(int i=0;i<len;i++){
		if(exp[i]=='('|| exp[i]=='{'||exp[i]=='[')
			push(exp[i]);
		else if(isalnum(exp[i])){
			continue;
			
		}
		else{
			if(is_empty())
				return 0;
			else if(check_pair(s[top],exp[i])){
				pop();
				continue;
			}
			
			return 0;
				
		}
	}

	if(is_empty()){
		return 1;
	}
	else{
		return 0;	
}
}



int main(){
	
	char myexp[]="(4())";
	int len = strlen(myexp);
	check_balance( myexp, len)?printf("Balanced"):printf("Not Balanced");
	display();
	
	
}
























































