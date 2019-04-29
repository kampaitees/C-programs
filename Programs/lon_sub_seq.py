AB = 'aabcddefxyzlm'
CD = 'qabcodddefpyzw'
l1 = []
for i in AB:
    if i not in l1:
        l1.append(i)
l = [0]*200
for i in list(AB):
    if l[ord(i)] == 0:
        l[ord(i)] = 1
    else:
        l[ord(i)] += 1
l2 = l[:]
for i in list(CD):
        l2[ord(i)] -= 1
        if l2[ord(i)] < 0:
            l2[ord(i)] = 0
for i in l1:
    l[ord(i)] -= l2[ord(i)]
    if l[ord(i)] < 0:
            l[ord(i)] = 0
for i in range(len(l)):
    if l[i] != 0:
        for j in range(l[i]):
            print(chr(i),end = '')
	
	
