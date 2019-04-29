/*#include<stdio.h>
#include<stdlib.h>
void createTreeRootNode();
void readElement();
void display();
void preorder(struct node *);
void inorder(struct node*);
void postorder(struct node *);
struct node {
	int data;
	struct node *left, *right;
};

struct node *root = NULL;

void createTreeRootNode(){
	int value;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &value);
	temp->data = value;
	temp->left = temp->right = NULL;
	root = temp;
}

void read element(){
	int i, j, height;
 	printf("Enter the height of tree:");
 	scanf("%d", &height);
 	j = pow(2, height + 1) - 1;
 	int a[j];
 	printf("Enter root node:");
 	scanf("%d", &a[0]);
 	printf("Enter the tree elements and enter 0 if  particular node is not present:");
 	for(i = 0; i < j / 2; i++){
 		scanf("%d", &a[2 * i + 1]);
 		scanf("%d", &a[2 * i + 2]);
 	}
 }
 
struct node *n = root;
void preorder(struct node *n){
	if(n == NULL)
		return;
	else{
		printf("%d ",n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

struct node *r = root;
void inorder(struct node *r){
	if(r == NULL)
		return;
	else{
		inorder(r->left);
		printf("%d ", r->data);
		inorder(r->right);
	}
}

struct node *q = root;
void postorder(struct node  *q){
	if(q == NULL)
		return;
	else{
		postorder(q->left);
		postorder(q->right);
		printf("%d ",q->data);
	}
}
		

void display(){
	int choice;
	printf("Enter the type of Traversal:\n");
	printf("1.PreOrder\n");
	printf("2.InOrder\n");
	printf("3.PostOrder\n");
	printf("4.Exit\n");
	while(1){
			scanf("%d", &choice);
			if(choice == 1) 
				preorder();
			else if(choice == 2)
				inorder();
			else if(choice == 3)
				postorder();
			else
				break;
	}
}

int main(void){
	int choice;	
	while(1){
		printf("1.CreateTreeNode\n");
		printf("2.ReadElement\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter the choice");
		scanf("%d", &choice);
		switch(choice){
			case 1 : 
						createTreeRootNode();
						break;
			case 2 :
						readElement();
						break;
			case 3 :
						display();
						break;
			case 4 :
						exit(0);
						break;
			default :
						printf("Invalid option!!!\n");
		}
	}
}	*/	 
#include<stdio.h>

struct Node{
   int data;
   struct Node *left;
   struct Node *right;
};

struct Node *root = NULL;
int count = 0;

struct Node* insert(struct Node*, int);
void display(struct Node*);

void main(){
   int choice, value;
   printf("\n----- Binary Tree -----\n");
   while(1){
      printf("\n***** MENU *****\n");
      printf("1. Insert\n2. Display\n3. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be insert: ");
		 scanf("%d", &value);
		 root = insert(root,value);
		 break;
	 case 2: display(root); break;
	 case 3: exit(0);
	 default: printf("\nPlease select correct operations!!!\n");
      }
   }
}

struct Node* insert(struct Node *root,int value){
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(root == NULL){
      newNode->left = newNode->right = NULL;
      root = newNode;
      count++;
   }
   else{
      if(count%2 != 0)
	 root->left = insert(root->left,value);
      else
	 root->right = insert(root->right,value);
   }
   return root;
}
// display is performed by using Inorder Traversal
void display(struct Node *root)
{
   if(root != NULL){
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
   }
}
	
	
