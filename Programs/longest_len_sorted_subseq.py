arr = [1,1,1,1,1,1,1,1,1,1,1,1,1]
l = [13,12,11,10,9,8,7,6,5,4,3,2,1]
b = max(l)
for i in range(1, len(l)):
    max1 = 1
    for j in range(i):
        if arr[j] >= max1:
            max1 = arr[j]
            p = j
    if l[p] < l[i]:
        arr[i] = arr[i] + max1
print(max(arr))
