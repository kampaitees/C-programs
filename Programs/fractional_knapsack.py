T = int(input())
for i in range(T):
    arr = [int(x) for x in input().split()]
    n = arr[0]
    w_c = arr[1]
    lis = [int(x) for x in input().split()]
    p = len(lis)
    v = lis[0:p:2]
    w = lis[1:p:2]
    l = sorted([[v, w, v/w] for v,w in zip(v,w)], reverse = True)
    weight_sum, real_weight_sum, i, value = 0, 0, 0, 0
    l.sort(key = lambda x: x[2], reverse = True)
    for i in range(len(l)):
        real_weight_sum += l[i][1]
    i = 0
    while (weight_sum < w_c) and (weight_sum < real_weight_sum):
        if l[i][1] <= (w_c - weight_sum):
           value += l[i][0]
           weight_sum += l[i][1]
        elif (l[i][1] <= w_c) and (l[i][1] > (w_c - weight_sum)):
            value += l[i][2]*(w_c - weight_sum)
            weight_sum += w_c - weight_sum  
        else:
            value += (w_c - weight_sum) * l[i][2]
            weight_sum = w_c
        i += 1
    print(round(value, 2))






