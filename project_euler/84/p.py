#=========================================================================
#
# Python Source File -- Created with SAPIEN Technologies PrimalScript 4.1
#
# NAME: problem 84
#
# AUTHOR:hbf
# DATE :14 sep 2007
#
# COMMENT:
#
#=========================================================================

n=4 or 6
def add_row(rd, rs, m):             # dest_row += src_row * m
    for j, v in enumerate(rs):
        rd[j] += v*m
def mul_row(r, m):
    for j in xrange(len(r)):
        r[j] *= m
n2inv = 1.0/(n**2)
# Build equations eqns: prob(i) = sum(eqns[i][j]*prob(j): j=0..119) where
# prob(i) = probability to go to square i/3 after (i mod 3) double rolls.
# Also include a final zero value which will be used later
eqns = [[0.0] * 121 for i in xrange(120)]
for i in xrange(3, 2*n):            # Handle non-doble rolls
    p = n2inv * min((i-1) & -2, (2*n-i+1) & -2)
    i *= 3
    eqns[0][120 - i] = eqns[0][121 - i] = eqns[0][122 - i] = p
for i in xrange(3*2, 3*2*n+1, 3*2): # Handle 1st and 2nd double roll
    eqns[1][120 - i] = eqns[2][121 - i] = n2inv
for i in xrange(3, 120):
    eqns[i][:3], eqns[i][3:-1] = eqns[i-3][-4:-1], eqns[i-3][:-4]
for i in xrange(2, 120, 3): # 3rd double roll -> jail with roll counter=0
    eqns[3*10+0][i] += 1.0/n
for srclist, div, destlist in (     # Handle jumps between squares
    ((30,),      1, (10,)),
    ((07,),      16, (00, 10, 11, 24, 39, 05, (15), (15), (12), (04))),
    ((22,),      16, (00, 10, 11, 24, 39, 05, (25), (25), (28), (19))),
    ((36,),      16, (00, 10, 11, 24, 39, 05, (05), (05), (12), (33))),
    ((02,17,33), 16, (00, 10)) # Must come after the "go to 33" above
    ):
    mul = 1.0/div
    for src in srclist:
        src *= 3
        for i in xrange(3):
            esrc = eqns[src + i]
            for dest in destlist:
                add_row(eqns[dest*3 + i], esrc, mul)
            mul_row(esrc, 1.0 - mul*len(destlist))
# Change each equation e to 'sum(prob(i)* e[i]) + e[120] = 0'
for i, e in enumerate(eqns):
    e[i] -= 1.0
assert abs(sum(map(sum, eqns))) < 1E-10, (src, sum(map(sum, eqns)))
# Add equation 'sum(probabilities) - 100% = 0' and solve
eqns.append([1.0]*120 + [-100.0])
for i in xrange(120):
    v, k = max([(abs(eqns[j][i]), j) for j in xrange(i, len(eqns))])
    assert v > 1E-10
    eqns[i], eqns[k] = eqns[k], eqns[i]
    ei = eqns[i]
    if ei[i] != -1.0:
        mul_row(ei, -1.0/ei[i])
    for j, ej in enumerate(eqns):
        if j != i and ej[i]:
            add_row(ej, ei, ej[i])
assert sum(map(abs, eqns[-1])) < 1E-10 # Check that last equation is '0=0'
p = [e[-1] for e in eqns[:-1]]
# Combine percentage per square (ignoring roll counts) and find result
p = [p[i+0] + p[i+1] + p[i+2] for i in xrange(0, len(p), 3)]
assert abs(sum(p) - 100.0) < 1E-10 and not [v for v in p if v < -1E-10]
s = sorted([(v, i) for i, v in enumerate(p)], reverse=True)
res = "%02d%02d%02d" % tuple([i for v, i in s[:3]])
print res, s[:4] # result and probabilities for the four most popular squares
