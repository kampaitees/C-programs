#include<stdio.h>
#include<stdlib.h>
void createQueue(int);
void enqueue(int);
int dequeue();
int length();
void display();

struct node  {
	int data;
	struct node *link;
};

struct node *front = NULL, *rear = NULL;

void createQueue(int value)  {
	struct node *temp;
	temp =  (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	if(front != NULL)
		printf("The Queue is already created\n");
	else  {		
		front = temp;
		front->link = front;
		rear = temp;
	}
}

void enqueue(int value)  {
	struct node *temp;
	temp =  (struct node *)malloc(sizeof(struct node));
	temp->data = value;
	//temp->link = NULL;
	rear->link = temp;
	rear = rear->link;
	rear->link = front;
}

int dequeue()  {
	struct node *temp = front;
	int item;
	if(front == NULL)   
		return 0;
	else if(front == rear){
		item = front->data;
		front = NULL;
		rear->link = NULL;
		temp->link = NULL;
		free(temp);
		return item;
	}
	else{
		item = front->data;
		front = front->link;
		rear->link = front;
		temp->link = NULL;
		free(temp);
		return item;
	}
}

int length()  {
	int count = 1;
	struct node *temp = front;
	if(front == NULL)  
		return 0;
	else  {
		while(temp != rear)  {
			count += 1;
			temp =temp->link;
		}
	return count;	
	}
}

void display()  {
	struct node *temp = front;
	if(front == NULL)  
		printf("The Queue is Empty\n");
	else  {
		printf("The Elements of Queue are:\n");
		do{
			printf("%d  ", temp->data);		
			temp = temp->link;
		}while(temp != front);
	}
	printf("\n");
}

void main(void)  {
	int choice, item;
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
			case 1 : printf("Enter the data:");
				 scanf("%d", &item);
				 createQueue(item);
				 break;
			case 2 : printf("Enter the data:");
				 scanf("%d", &item);
				 enqueue(item);
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
				

