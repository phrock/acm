MAX = 2010
matrix = [[None] * MAX for i in range(MAX)]
gender = [None] * MAX

def set_gender(cur, x):
    gender[cur] = x
    for i in range(1, bugs + 1):
        if matrix[cur][i] == 1:
            if gender[i] == None:
                if set_gender(i, x ^ 1) == False:
                    return False
            elif gender[i] == x:
                return False
    return True

def check():
    for i in range(1, bugs + 1):
        gender[i] = None
    for i in range(1, bugs + 1):
        if gender[i] == None:
            if not set_gender(i, 0):
                return False
    return True

for T in range(int(input())):
    print('Scenario #{0}:'.format(T + 1))
    bugs, n = input().split()
    bugs = int(bugs)
    n = int(n)
    for i in range(1, bugs+1):
        for j in range(1, bugs + 1):
            matrix[i][j] = None
    for i in range(n):
        a, b = input().split()
        matrix[int(a)][int(b)] = matrix[int(b)][int(a)] = 1

    print('No suspicious bugs found!' if check() == True else 'Suspicious bugs found!')
