def B(n,k):
    if k==1 or k==n:
        return 1
    if k>n:
        return 0   
    if (n,k) in cDict:
        return cDict[(n,k)]
    count =0
    for i in range(1,k+1):
        count+=B(n-k,i)
    cDict[(n,k)]=count
    return count
cDict={}
def f(n):
    count = 0
    for i in range(2,n+1):
        print i
        count += B(n,i)
    return count
print 'answer=%d'%f(100)
