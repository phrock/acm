d = {}
d[0] = 0
def func(n):
    if n in d:
        return d[n]
    res = max(n, func(n // 2) + func(n // 3) + func(n // 4))
    d[n] = res
    return res

try:
    while True:
        n = int(input())
        print(func(n))
except EOFError:
    pass
