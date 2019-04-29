#include<stdio.h>                                                                        
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char data;
	struct node *left, *right;
}node;

void push(node*);
node *pop();
void inorder();

int top = -1;
node *stack[20];
node*temp;

void push(node *temp){
	stack[++top] = temp;
}

node *pop(){
	return stack[top--];
}

void inorder(node *temp){
	if(temp != NULL){
		inorder(temp->left);
		printf("%c", temp->data);
		inorder(temp->right);
	}
}


void main(){
	char s[20];
	int i = 0;
	printf("Enter expression:");
	gets(s);
	while(s[i] != '\0'){
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
			if(s[i] == '+' ){
				temp = (node*)malloc(sizeof(node));
				temp->data = '+';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
			else if(s[i] == '-' ){
				temp = (node*)malloc(sizeof(node));
				temp->data = '-';
				temp->right =pop();
				temp->left = pop();
				push(temp);
			}
			else if(s[i] == '*' ){
				temp = (node*)malloc(sizeof(node));
				temp->data = '*';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
			else if(s[i] == '/' ){
				temp = (node*)malloc(sizeof(node));
				temp->data = '/';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
		}
		else{
			temp = (node*)malloc(sizeof(node));
			temp->data = s[i];
			temp->right = temp->left = NULL;
			push(temp);
		}
		++i;
		/*if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
			if(s[i] == '+'){
				temp = (node*)malloc(sizeof(node));
				temp->data = '+';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
			else if(s[i] == '-'){
				temp = (node*)malloc(sizeof(node));
				temp->data = '-';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
			else if(s[i] == '*'){
				temp = (node*)malloc(sizeof(node));
				temp->data = '*';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
			else{
				temp = (node*)malloc(sizeof(node));
				temp->data = '/';
				temp->right = pop();
				temp->left = pop();
				push(temp);
			}
		}
		else{
			temp = (node*)malloc(sizeof(node));
			temp->data = s[i];
			temp->left = temp->right = NULL;
			push(temp);
		}
		++i;*/
	}
	inorder(stack[top]);
}
