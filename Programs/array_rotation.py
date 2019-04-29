def rotLeft(a, d):
    length = len(a)
    l = a[:]
    for i in range(length):
        if d > length:
            d  = d % length
        if i <= length//2:
            value = abs(d - i)
            if d < i:
                final_index = value
            else:
                if value == 0:
                    final_index = 0
                else:
                    final_index = length-value
        else:
            value = d - i
            if value < 0:
                final_index = i - d
            elif value == 0:
                final_index = 0
            else:
                final_index = length - value 
        l[final_index] = a[i]
    for i in l:
        print(i,end=' ')
    return
