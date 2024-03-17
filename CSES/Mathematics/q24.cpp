n=int(input())
ans=0.0
arr=[]

arr = list(map(int,input().split()))
  
for i in range(n):
  for j in range(i+1,n):
    ri=arr[i]
    rj=arr[j]
    if ri<=rj:
      val=ri-1
      ans+=val/(2.0*rj)
    else:
      val=2*ri-rj-1
      ans+=val/(2.0*ri)

print("{:.6f}".format(ans))
 

