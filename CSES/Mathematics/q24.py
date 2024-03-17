n,k=map(int, input().split())
ans=0.0

def binexp(a,n):
  res=1;
  while n>0:
    if n&1: 
      res*=a
    n>>=1
    a*=a
  return res
  
for i in range(1,k+1):
  ans+=i*binexp(i/k,n)
  ans-=i*binexp((i-1.0)/k,n)  

print("{:.6f}".format(ans))
 

