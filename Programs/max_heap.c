#include<stdio.h>
#include<math.h>
void delete(int [], int, int);
void main(void){
	int i, j, length, temp, k, b;
	printf("Enter the length of the heap:");
	scanf("%d", &length);
	int a[length];
	printf("Enter root:");
	scanf("%d", &a[0]);
	printf("Enter elements of heap:");
	for(i=0; i<length/2; i++){
		scanf("%d", &a[2*i+1]);
		if(length > 2*i+2)
			scanf("%d", &a[2*i+2]);
	}
	for(i=0; i<length/2; i++){
		j = 2*i+1;
		while(1){
			b = floor((j-1)/2);
			if(a[b] < a[j]){
				temp = a[j];
				a[j] = a[b];
				a[b] = temp;
			}
			j = b;
			if(j == 0)
				break;
		}
		if(length > 2*i+2){
			j = 2*i+2;
			while(1){
				b = floor((j-1)/2);
				if(a[b] < a[j]){
					temp = a[j];
					a[j] = a[b];
					a[b] = temp;
				}
				j = b;
				if(j == 0)
					break;
			}
		}
	}
	delete(a,3,6);
	for(i=0; i<length; i++)
		printf("%d  ", a[i]);
	printf("\n");
}
void delete(int a[], int value, int size){
	int max, temp, i = 0, index;
	while(a[i] != value) 
		i++;
	if(i == size-1 || i == size -2)
		a[i] = -1;
	else{	
		while(i != size-1 && i != size-2){
			if(size > 2*i+2){
				if(a[2*i+1] < a[2*i+2]){
					max = a[2*i+2];
					index = 2*i+2;
				}
				else{
					max = a[2*i+1];
					index = 2*i+1;
				}
			a[i] = max;
			a[index] = -1;
			i = index;
			}
			else{
				a[i] = a[2*i+1];
				a[2*i+1] = -1;
				i = 2*i+1;	
			}
		}
	}
}
		
			
