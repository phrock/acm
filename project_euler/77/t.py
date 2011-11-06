#=========================================================================
#
# Python Source File -- Created with SAPIEN Technologies PrimalScript 4.1
#
# NAME: problem 77
#
# AUTHOR: patrol , ustc
# DATE : 2008-8-16
#
# COMMENT:
#
#=========================================================================
from math import sqrt
primeList=[2,3]
def appendPrime():
    k = primeList[-1]+2
    q = int(sqrt(k))
    while True:
        isPrime = True
        for i in primeList:
            if i <=k:
                if k%i==0:
                    isPrime = False
            else:
                break
        if isPrime:
            break
        else:
            k += 2
    primeList.append(k)
def f(total,n,maxx):
    if n==1:
        if total >maxx:
            return 0
        if total in primeList:
            return 1
        else:
            return 0
    maxx=min(total-n+1,maxx)
    length = len(primeList)
    for i in range(length):
        if primeList[i]>maxx:
            break
    maxIndex = i-1
    count = 0
    for i in range(maxIndex,-1,-1):
        maxx=min(primeList[i],total-primeList[i])
        count =count+ f(total-primeList[i],n-1,maxx)
    return count
n = 10
while True:
    k=n/2
    count=0
    while primeList[-1]<n:
        appendPrime()
    for i in range(2,k+1):
        count+=f(n,i,n)
    print n,count
    if count>5000:
        break
    n += 1
print 'answer=%d'%n
