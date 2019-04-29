#include<stdio.h>
#include<stdlib.h>
void insert(int, int);
void display();
void insert2(int, int);
void display2();
struct node {
	int coeff, degree;
	struct node * link;
};
struct node *root = NULL;
struct node *root2 = NULL;

void insert(int coeff, int degree){
	struct node *p, *temp = root;
	p = (struct node *)malloc(sizeof(struct node));
	p->coeff = coeff;
	p->degree = degree;
	p->link = NULL;
	if(root == NULL)
		root = p; 
	else{
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
}

void insert2(int coeff, int degree){
	struct node *p, *temp = root;
	p = (struct node *)malloc(sizeof(struct node));
	p->coeff = coeff;
	p->degree = degree;
	p->link = NULL;
	if(root2 == NULL)
		root2 = p; 
	else{
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
}


void main(){
	int i, j, num, num2, degree, coeff;
	struct node *p = root,*q = root2;
	printf("Enter number of terms in poly1 and poly2:");
	scanf("%d %d", &num,&num2);
	for(i = 0 ; i < num ; i++){
		printf("Enter the coefficient  and degree:");
		scanf("%d %d", &coeff, &degree);
		struct node *p, *temp = root;
		p = (struct node *)malloc(sizeof(struct node));
		p->coeff = coeff;
		p->degree = degree;
		p->link = NULL;
		if(root == NULL){
			root = p;
			p = p->link; 
		}
		else{
			while(temp->link != NULL)
				temp = temp->link;
			temp->link = p;
		}
	}
	for(j = 0 ; j < num2 ; j++){
		printf("Enter the coefficient  and degree:");
		scanf("%d %d", &coeff, &degree);
		struct node *p, *temp = root;
		p = (struct node *)malloc(sizeof(struct node));
		p->coeff = coeff;
		p->degree = degree;
		p->link = NULL;
		if(root == NULL)
			root = p; 
		else{
			while(temp->link != NULL)
				temp = temp->link;
			temp->link = p;
		}
	}
	if (p == NULL && q == NULL);
		printf("YES");
	while(p != NULL && q != NULL){
		if(p->degree == q->degree){
			printf("%d x ^ %d + ", p->coeff + q->coeff ,p->degree);
			 p = p->link;
			 q = q->link;
		}
		else{
			if(p->degree > q->degree){
				printf("%d x ^ %d + ",p->coeff,p->degree);
				p = p->link;
			}
			else{
				printf("%d x ^ %d + ",q->coeff,q->degree);
				p = p->link; 
			}
		}
	}
}
