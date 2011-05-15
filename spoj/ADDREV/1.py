for i in range(int(input())):
    a = list(input().split())
    print(str(int(a[0][::-1])+int(a[1][::-1]))[::-1].lstrip('0'))
