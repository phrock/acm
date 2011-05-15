MAX = 20
start = 0
dest = 0
s = input()
a = s.split()

for i in range(len(a)):
    if (a[i] == '1'):
        start |= 1 << i

d = [-1]*pow(2, MAX)
d[start] = 0
q = []
q.append(start)

while q != []:
    x = q.pop(0)
    if (d[dest] != -1):
        break
    for i in range(MAX):
        next = x
        for j in range(-1, 2):
            if i + j >= 0 and i + j < MAX:
                next ^= 1 << (i + j)
            if (d[next] == -1):
                d[next] = d[x] + 1
                q.append(next)
print(d[dest])
