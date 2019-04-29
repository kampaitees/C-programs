#include<stdio.h>
#include<math.h>
 int main(){
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
 	for(i = 0; i < j; i++){
 		 if(a[i] != 0)
 			printf("%d  ", a[i]);
 		else
 			printf("NULL ");
 	}
 	printf("\n" );
 	return 0;
 }
 	
