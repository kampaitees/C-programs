s = 'zztqooauhujtmxnsbzpykwlvpfyqijvdhuhiroodmuxiobyvwwxupqwydkpeebxmfvxhgicuzdealkgxlfmjiucasokrdznmtlwh'
l = list(s)
flag = 0
for  p in range(len(s)):
        i,j = 0,1
        for k in range(len(s)):
            if l[i] == l[j]:
               l.remove(l[i])
               l.remove(l[i])
            else:
                i += 1
                j += 1
            if len(l) == 0:
                print('Empty String')
                break
            if j == len(l) and p == 1:
                flag = 1
                break
            if j == len(l):
                break
        if flag == 1:
            break
x = ''.join(l)
if x == 'tqauhujtmxnsbzpykwlvpfyqijvdhuhirdmuxiobyvxupqwydkpbxmfvxhgicuzdealkgxlfmjiucasokrdznmtlwh':
 print("Yes")
else:
 print("No")

