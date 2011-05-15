a = [1]
for i in range(1, 101):
    a.append(a[i-1]*i)
for i in range(int(input())):
    print(a[int(input())])
