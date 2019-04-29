import numpy as np
for z in range(int(input())):
    len1, len2 = input().split()
    s1, s2 = input().split()
    arr = np.zeros((8,8))
    arr[0][0] = 0
    if int(len1) > 0 and int(len2) > 0:
        for q in range(1,int(len2)+1):
            if q-1 < int(len2):
                arr[0][q] = arr[0][q-1] + 1
        for q in range(1,int(len2)+1):
            if q-1 < int(len1):
                arr[q][0] = arr[q-1][0] + 1
    for m in range(int(len1)):
        for n in range(int(len2)):
            a, b = s1[m], s2[n] 
            if a == b:
                c = arr[m][n] 
                arr[m+1][n+1] = c
            else:
                d, e, f = arr[m][n], arr[m+1][n], arr[m][n+1]
                g = min(d, e, f)
                arr[m+1][n+1] = 1 + g
    print(arr[len(s1)][len(s2)])
