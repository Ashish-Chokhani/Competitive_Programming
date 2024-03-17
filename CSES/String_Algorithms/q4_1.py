def get_hash(l, r, hash, power, M):
    h = hash[r+1] - (power[r-l+1]*hash[l]%M)%M
    return h + M if h < 0 else h

s = input()
n = len(s)

P = 31
M = 1000000007

power = [0]*(n+5)
power[0] = 1

for i in range(1, n):
    power[i] = (power[i-1]*P)%M

hash = [0]*(n+10)

for i in range(1, n+1):
    hash[i] = (hash[i-1]*P + ord(s[i-1]))%M

for i in range(n):
    runIdx = 0
    ok = True
    while(runIdx < n):
        length = min(i+1, n-runIdx)
        ok &= (get_hash(0,length-1,hash,power,M) == get_hash(runIdx,runIdx+length-1,hash,power,M))
        runIdx += length
    if(ok):
        print(i+1, end=" ")