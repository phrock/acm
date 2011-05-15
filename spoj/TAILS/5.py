MAX = 20
start = 0
dest = 0
s = input()
a = s.split()

for i in range(len(a)):
    if (a[i] == '1'):
        start |= 1 << i

d = {}
d[start] = 0
q = []
q.append(start)

while q != []:
    x = q.pop(0)
    if (dest in d):
        break
    for i in range(MAX):
        next = x
        for j in range(-1, 2):
            if i + j >= 0 and i + j < MAX:
                next ^= 1 << (i + j)
            if (next not in d):
                d[next] = d[x] + 1
                q.append(next)
print(d[dest])
