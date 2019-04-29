#include<stdio.h>
#include<stdlib.h>

typedef struct node{

	int data;
	struct node *left, *right;
}node;


node * insert(node *, int);
node * delete(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);


void preorder(node *root){
	if(root != NULL){
		printf("%d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}

void postorder(node *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d  ", root->data);
	}
}

node * insert(node * root, int value){
	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->left = temp->right = NULL;
	if(root == NULL)
		root = temp;
	else{
		if(temp->data > root->data)
			root->right = insert(root->right, temp->data);
		else if(temp->data < root->data)
				root->left = insert(root->left, temp->data);
	}
	return root;
}

node * delete(node* root, int value){
	node *temp, *p ;
	if(root->left != NULL && value == root->left->data){
		if(root->left->left == NULL && root->left->right == NULL){
			temp = root->left;
			root->left = NULL;
			free(temp);
		}
		else if(root->left->left == NULL && root->left->right != NULL){
			temp = root->left;
			root->left = temp;
			free(temp);
		}
		else{
			temp = root->left;
			//temp = temp->right;
			while(temp->left != NULL){
				p = temp;
				temp = temp->left;
			}
			if(temp->right != NULL){
				root->left->data = temp->data;
				p->left = temp->right;
				temp->right = NULL;
				free(temp);
			}
			else{
				root->left->data = temp->data;
				p->right = NULL;
				free(temp);
			}	
		}
	}
	else if(root->right != NULL && value == root->right->data){
		 if(root->right->left == NULL && root->right->right == NULL){
			temp = root->right;
			root->right = NULL;
			free(temp);
		}
		else if(root->right->left != NULL && root->right->right == NULL){
			temp = root->right;
			root->right = temp->left;
			free(temp);
		}
		else{
			temp = root->right;
			temp = temp->left;
			while(temp->right != NULL){
				p = temp;
				temp = temp->right;
			}
			if(temp->left != NULL){
				root->right->data = temp->data;
				p->right = temp->left;
				temp->left = NULL;
				free(temp);
			}
			else{
				root->right->data = temp->data;
				p->right = NULL;
				free(temp);
			}	
		}
	}
	else if(value < root->data)
		delete(root->left, value);
	else if(value > root->data)
		delete(root->right, value);	
	return root;
}

void main(void){
	node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 8);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 9);
	root = insert(root, 3);
	root = insert(root, 6);
	root = insert(root, 15);
	root = insert(root, 25);
	root = insert(root, 14);
	root = insert(root, 18);
	root = insert(root, 22);
	inorder(root);
	printf("\n");
	//delete(root, 10);
	//delete(root, 6);
	//delete(root, 9);
	//delete(root, 18);
	//delete(root, 22);
	delete(root, 15);
	//delete(root, 5);
	inorder(root);
	printf("\n");
}	
	
	
	
	
	
	
	
	
	
