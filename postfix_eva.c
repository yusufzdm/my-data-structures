#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


#define SIZE 100
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
	--top;
	return val;
	
}

int push(int data){
	if(top>=SIZE){
		printf("Stack overflow");
	}
	++top;
	s[top]=data;
	return data;
	
}
char peek(){
	if(is_empty())
	{
		printf("Stack Underflow");
	}
	else
	{
		return s[top];
	}
	
}
void display(){
	for(int i=0;i<=top;i++)
	{
		printf("%d : %s \n",i,s[i]);
	}
	
}
int charToInt(char c){
	int num = 0;

	//Substract '0' from entered char to get
	//corresponding digit
	num = c - '0';

	return num;
}

int postfix_eva(char exp[],int len){
	for(int i=0;i<len;i++){
		
		if(exp[i]==' '){
		
			continue;
		}
	    
	    
		else if(isalnum(exp[i])){
			
			push(charToInt(exp[i]));
		}
		else if((exp[i]=='*')){
			
			int val1=(s[top]);
			int val2=(s[--top]);
			//printf("%d \n",s[--top]);
			s[top]=val1*val2;	
		}else if((exp[i]=='/')){
			
			int val2=s[top--]/s[top];
			
			s[top]=val2;	
		}
		else if((exp[i]=='+')){
		    int val3=s[top]+s[--top];
			s[top]=val3; 	
		}
		else if((exp[i]=='-')){
			
			int val4=s[top];
			int val5=s[--top];
			s[top]=val5-val4;
		}
		else{
			printf("invalid value");
			return 0;
		}
		printf("%d \n",s[top]);
	
	}
	printf("Result : %d",s[top]);
	return s[top];
}







int main(){
	char myexp[SIZE]="2 3 1 * + 9 -";
	int len = strlen(myexp);
	postfix_eva(myexp, len);
	
	
	


	
}
