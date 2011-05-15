MAX = 20
start = 0
INF = 1 << 20
s = input()
a = s.split()

for i in range(len(a)):
    if (a[i] == '1'):
        start |= 1 << i

d = {}
d[start] = 0
pow2 = [1 << n for n in range(MAX)]

def flip(x, n):
    if n - 1 >= 0:
        x ^= pow2[n - 1]
    if n + 1 < MAX:
        x ^= pow2[n + 1]
    x ^= pow2[n]
    return x

def dfs(x):
    if (0 in d):
        return
    left = MAX
    right = -1
    for i in range(MAX):
        if x & pow2[i] != 0:
            left = min(left, i)
            right = max(right, i)
    for i in range(left, right+1):
        if i == 0 or i == MAX - 1 or (i > left and i < right):
            aux = flip(x, i)
            d[aux] = d[x] + 1
            dfs(aux)

dfs(start)

print(d[0])
