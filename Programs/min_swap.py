def minimumSwaps(arr):
    arr1 = sorted(arr)
    l, count = [], 0
    for i, j in zip(arr1,arr):
            l.append(j-i)
    for i in l:
        if i != 0:
            count += 1
    if count == 0:
        return 0
    else:
        return count-1
arr = list(map(int, input().rstrip().split()))
res = minimumSwaps(arr)
print(res)
