def longestIncreasingSubsequence(arr):
    max_ = 0
    for i in range(1,len(arr)):
        l = arr[:i+1]
        l1 = l[:]
        flag = 0
        for k in l1:
            if k > arr[i]:
                flag = 1
                l.remove(k)
        if flag != 1:
            max_ += 1
        else:
            if len(list(set(l))) > max_:
                max_ = len(list(set(l)))
    return max_
    
