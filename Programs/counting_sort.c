#include<stdio.h>
void main(){
	int a[20], i, size, n;
	printf("Enter the size of an array and range n:");
	scanf("%d %d", &size, &n);
	printf("Enter the elements of array within a range:");
	for(i = 0; i < size; i++)
		scanf("%d", &a[i]);
	int b[n];
	for(i = 0; i < n; i++)
		b[i] = 0;
	for(i = 0; i < size; i++)
		b[a[i]] += 1;
	for(i = 1; i <= n; i++)
		b[i] = b[i] + b[i-1];
	int c[size];
	for(i = size-1; i >= 0; i--){
		c[b[a[i]]] = a[i];
		b[a[i]] -= 1;
	}
	for(i = 1; i <= size; i++)
		printf("%d  ", c[i]);
	printf("\n");
}
	
	
