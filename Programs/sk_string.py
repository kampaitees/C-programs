s = input()
l = ['a','e','i','o','u']
l1 = [0]*127
a = 0
for i in list(s):
        if len(s) == 0:
            a = 1
        else:
            if i.islower():
                if i in l and (s.count(i) % 2 != 0 or s.count(i) == 0):
                    l1[ord(i)] += 1
            else:
                a = 1
for p in range(97,127):
        if l1[p] != 0 and l1[p] % 2 == 0:
            a = 1
            break
if a == 0:
        print("YES")
else:
        print("NO")
