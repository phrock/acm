MAX = 20
s = input()
a = s.split()

for i in range(MAX):
    a[i] = int(a[i])

def func():
    cnt = 0
    f1 = f2 = 0
    for i in a:
        if i ^ f1 == 1:
            cnt += 1
            f1 = f2 ^ 1
            f2 = 1
        else:
            f1 = f2
            f2 = 0
    return cnt if f1 == 0 else 1 << 20

res = func()
if a[0]:
    a[0] ^= 1
    a[1] ^= 1
    res = min(res, func() + 1)
print(res)
