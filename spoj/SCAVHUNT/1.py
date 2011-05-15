for i in range(int(input())):
    print('Scenario #{0}:'.format(i + 1))
    nonroot = set()
    d = {}
    for j in range(int(input()) - 1):
        s = input().split()
        d[s[0]] = s[1]
        nonroot.add(s[1])

    for root in d:
        if root not in nonroot:
            break;

    while root in d:
        print(root)
        root = d[root]
    print(root)
    print()
