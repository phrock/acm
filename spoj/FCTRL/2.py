def func(n):
    res = 0
    x = 5
    while x <= n:
        res += n/x
        x *= 5
    return int(res)

for i in range(int(input())):
    print(func(int(input())))
