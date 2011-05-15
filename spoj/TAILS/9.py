MAX = 20
start = 0
INF = 1 << 20
s = input()
a = s.split()

for i in range(len(a)):
    if (a[i] == '1'):
        start |= 1 << i

pow2 = [1 << n for n in range(MAX)]

def flip(x, n):
    if n - 1 >= 0:
        x ^= pow2[n - 1]
    if n + 1 < MAX:
        x ^= pow2[n + 1]
    x ^= pow2[n]
    return x

def func(x):
    cnt = 0
    for i in range(MAX):
        if x & pow2[i] != 0:
            x = flip(x, i+1)
            cnt += 1
    return cnt if x == 0 else INF

res = INF
if start & 1 != 0:
    res = min(res, func(flip(start, 0)) + 1)
res = min(res, func(start))

print(res)
