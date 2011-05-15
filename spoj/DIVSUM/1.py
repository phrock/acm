MAX = 500005
a = [1] * MAX
a[0] = a[1] = 0
for i in range(2, MAX):
    j = i + i
    while j < MAX:
        a[j] += i
        j += i
