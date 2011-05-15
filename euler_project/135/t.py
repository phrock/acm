def gen_primes(p = 1):
    if p == 1:
        yield 2
    if p <= 2:
        yield 3
    n = 3
    if p > 4:
        n = (p - 1) / 2 * 2 + 1
    while True:
        n += 2
        p = 3
        while True:
            if p * p > n:
                yield n
                break
            if n % p == 0:
                break
            p += 2

def gen_composites(n, q = 1):
    yield [ ]
    for p in gen_primes(q):
        if q == 1:
            if p ** 4 > n:
                break
        else:
            if p > n:
                break
        
        i = 1
        pow = p
        while pow <= n:
            for c in gen_composites(n / pow, p):
                yield [ p, i ] + c
            i += 1
            pow *= p

def comp_num(c):
    n = 1
    i = 0
    while i < len(c):
        n *= c[i] ** c[i+1]
        i += 2
    return n

def num_div(c):
    n = 1
    for i in range(1, len(c), 2):
        n *= c[i] + 1
    return n

def gen_divisors(c):
    n = comp_num(c)
    num_primes = len(c) / 2
    e = [ 0 ] * num_primes
    d = 1
    yield (1, n)
    while True:
        k = 0
        while k < num_primes:
            e[k] += 1
            if e[k] <= c[k*2+1]:
                d *= c[k*2]
                break
            e[k] = 0
            d /= c[k*2] ** c[k*2+1]
            k += 1
        if k == num_primes:
            break
        yield (d, n / d)

def is_valid_div(a):
    return (a[0] + a[1]) % 4 == 0 and a[1] * 3 - a[0] > 0

def C(c):
    if len(c) == 0 or c[0] == 2 and c[1] == 1:
        return 0
    if num_div(c) < 10:
        return -1
    
    return sum(map(is_valid_div, gen_divisors(c)))

N = 10 ** 6
print sum(map(lambda c: C(c) == 10, gen_composites(N)))
