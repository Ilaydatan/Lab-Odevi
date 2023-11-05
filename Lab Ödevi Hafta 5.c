#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 50

struct stack{
	char data[STACK_SIZE];
	int top;
};

void reset(struct stack *stk){
	stk->top=-1;
}

void push(struct stack *stk,char key){
	if(stk->top==STACK_SIZE-1){
		printf("stack dolu");
	}
	else{
	}

	stk->top++;
	stk->data[stk->top]=key;
   }
   

 
 char pop(struct stack *stk){
 	if(stk->top==-1){
 		printf("stack bos\n");
 		return 0;
	 }
	 else{
	 	char x=  stk->data[stk->top];
	 	stk->top--;
	 	return x;
	 }
 }
 int main(){
 	struct stack stk;
 	reset(&stk);
 	FILE *myPtr;
 	myPtr=fopen("Metin.txt","r");
 	char kontrol;
 	
 	kontrol=fgetc(myPtr);
 	while(kontrol!=EOF){
 		if(kontrol=='[' || kontrol=='(' || kontrol=='{')
 		{
 			push(&stk,(char)kontrol);
		 }
		 else if(kontrol==']' || kontrol==')' || kontrol=='}')
		 {
		 
		 	char kontrol2=(char)pop(&stk);
		 	if(((kontrol == ']' && kontrol2 != '[') ||
                (kontrol == ')' && kontrol2 != '(') ||
                (kontrol == '}' && kontrol2!= '{'))){
                	printf("Parantezler eslesmiyor");
                	return 1;
				}
                
		 }
		 kontrol=fgetc(myPtr);
	 }
	 fclose(myPtr);
	 
	  if (stk.top == -1) {
        printf("parantezler eslesiyor\n");
    } else {
        printf("parantezler eslesmiyor\n");
    }
	 return 0;
	 
 }
