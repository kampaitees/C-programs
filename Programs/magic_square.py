import numpy as np
arr = np.zeros((4,4))
print("Enter first number:")
k = int(input())
for i in range(4):
	for j in range(4):
		arr[i][j] = k
		k += 1
print(f"Original matrix is:{arr}")
print("\n")
arr[0][0], arr[3][3] = arr[3][3], arr[0][0]
arr[0][3], arr[3][0] = arr[3][0], arr[0][3]
arr[1][1], arr[2][2] = arr[2][2], arr[1][1]
arr[1][2], arr[2][1] = arr[2][1], arr[1][2]
print("Magic matrix is:")
print(arr)
