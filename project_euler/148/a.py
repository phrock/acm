def to_p_base(n, p):
    a = [ ]
    while n:
        a.append(n % p)
        n /= 7
    return a

def sum_to(n):
    return n * (1 + n) / 2

def count_not_divisible(n, p):
    a = to_p_base(N, p)
    s = sum_to(p)
    def mul(x, y): return x * y
    def inc(x): return x + 1
    counter = 0
    for i in range(len(a)):
        counter += reduce(mul, map(inc, a[i+1:]), s ** i * sum_to(a[i]))
    return counter

def count_p(n, p):
    def mul(x, y): return x * y
    def inc(x): return x + 1
    return reduce(mul, map(inc, to_p_base(n, p)), 1)

p = 7
N = 10 ** 9
print count_not_divisible(N - 1, p)
