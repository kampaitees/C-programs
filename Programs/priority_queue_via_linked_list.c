#include<stdio.h>
#include<stdlib.h>
void createQueue(int, int);
void enqueue(int, int);
int dequeue();
int length();
void display();

struct node{
	int data;
	int priority;
	struct node *link;
};

struct node *front = NULL, *rear = NULL;
int min;

void createQueue(int value, int priority){
	struct node *temp;
	min = priority;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->priority = priority;
	temp->link = NULL;
	if(front != NULL)
		printf("The Queue is already created\n");
	else  {		
		front = temp;
		rear = temp;
	}
}

void enqueue(int value, int priority){
	struct node *temp;
	if(priority < min)
		min = priority;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	temp->priority = priority;
	temp->link = NULL;
	rear->link = temp;
	rear = rear->link;
}

int dequeue(){
	struct node *temp, *pre, *temp1;
	int item;
	if(front == NULL)   
		return 0;
	else   {
		temp = front;
		while(temp->priority != min){
			pre = temp;
			temp = temp->link;
		}
		if(rear == front){
			item = temp->data;
			front = NULL;
			temp->link = NULL;
			free(temp);
		}
		else if(temp == rear){
			rear = pre;
			item = temp->data;
			pre->link = NULL;
			free(temp);
		}
		else if(temp == front){
			item = temp->data;
			front = front->link;
			temp->link = NULL;
			free(temp);
		}
		else{
			item = temp->data;
			pre->link = temp->link;
			temp->link = NULL;
			free(temp);
		}
		if(front != NULL){
			min = front->priority;
			temp1 = front;
			while(temp1->link != NULL){
				temp1 = temp1->link;
				if(temp1->priority < min)
					min = temp1->priority;
			}
		}
		return item;
	}
}

int length(){
	int count = 1;
	struct node *temp = front;
	if(front == NULL)  
		return 0;
	else  {
		while(temp->link != NULL)  {
			count += 1;
			temp =temp->link;
		}
	return count;	
	}
}

void display()  {
	struct node *temp = front;
	printf("The Elements of Queue are:\n");
	if(front == NULL)  
		printf("The Queue is Empty\n");
	else  {
		while(temp != NULL)  {
			printf("%d  ", temp->data);		
			temp = temp->link;
		}
	}
	printf("\n");
}

void main(void){
	int choice, item, priority;
	while(1)  {
		printf("1.CreateQueue\n");
		printf("2.EnQueue\n");
		printf("3.DeQueue\n");
		printf("4.Length\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("Enter the choice:");
		scanf("%d", &choice);
		printf("\n");
		switch(choice)  {
			case 1 : printf("Enter the data and priority:");
				 scanf("%d %d", &item, &priority);
				 createQueue(item, priority);
				 break;
			case 2 : printf("Enter the data and priority:");
				 scanf("%d %d", &item, &priority);
				 enqueue(item, priority);
				 break;
			case 3 : item = dequeue();
				 if(item == 0)
					printf("The Queue is Empty\n");
				 else 
				 	printf("DeQueued Item: %d\n", item);
				 break;
				 printf("\n");
			case 4 : printf("Length is: %d\n", length());
				 break;
			case 5 : display();
				 break;
			case 6 : exit(0);
				 break;
			default: printf("Invalid Option\n");
		}
	}
}

