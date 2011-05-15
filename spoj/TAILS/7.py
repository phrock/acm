MAX = 20
start = 0
cnt = 0
s = input()
a = s.split()

for i in range(len(a)):
    if (a[i] == '1'):
        start |= 1 << i

d = {}
d[0] = 0
d[-1] = 1 << 20

def flip(x, n):
    if n < 0 or n >= MAX:
        return -1
    if n - 1 >= 0:
        x ^= 1 << (n - 1)
    if n + 1 < MAX:
        x ^= 1 << (n + 1)
    x ^= 1 << n
    return x

def dfs(x):
    if (x in d):
        return d[x]
    for i in range(MAX):
        if x & (1 << i) != 0:
            d[x] = min(dfs(flip(x, i-1)), dfs(flip(x, i)), dfs(flip(x, i+1))) + 1
            return d[x]

# print(d[start])
print(dfs(start))
