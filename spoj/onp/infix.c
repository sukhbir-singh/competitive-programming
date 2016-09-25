#include <stdio.h>
#include <string.h>

char infix[500];
char postfix[500];
char stack[500];
int top=-1;
int top_postfix=-1;
int to_print=0;
void push(char c);
char pop();
int instack_pr(char c);
int incoming_pr(char c);

void rpn();

int main(){

	int times,i,j,k;
	scanf("%d",&times);

	for(i=0;i<times;i++){	
		 scanf("%s",infix);

		 to_print=0;
		 top=-1;
		 top_postfix=-1;

		 rpn();
	}
}

void rpn(){
	int i;
	char symbol;

	//printf("size of infix: %ld\n",strlen(infix) );

	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
		//printf("symbol scanned %c\n",symbol );

		switch(symbol){
			case '(':
				push(symbol);
				//printf("symbol pushed into stack\n");
				break;
			case ')':
				while(stack[top]!='('){
					postfix[++top_postfix]=pop();
					//printf("symbol poped and put on postfix : %c\n", postfix[top_postfix]);
				}
				pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				to_print++;
				while(instack_pr(stack[top])>=incoming_pr(symbol)){
					postfix[++top_postfix]=pop();
					//printf("symbol poped and put on postfix : %c\n", postfix[top_postfix]);
				}
				push(symbol);
				//printf("symbol pushed : %c\n", symbol);
				break;
			default: 
				to_print++;
				postfix[++top_postfix]=symbol;
				//printf("%c put on postfix\n", symbol);
		}
	}

	//printf("Output : (%ld) ",strlen(postfix));

	for(i=0;i<to_print;i++){
		printf("%c",postfix[i]);
	}
	printf("\n");

}

void push(char ch){
	stack[++top]=ch;
}

char pop(){
	return stack[top--];
}

int instack_pr(char c){
	switch(c){
		case '(':
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}

int incoming_pr(char c){
	switch(c){
		case '(':
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 4;
		default:
			return 0;
	}
}