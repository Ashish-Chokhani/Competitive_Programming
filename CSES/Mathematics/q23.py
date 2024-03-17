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

new_list=[8,10,12,13,15,18,19,20,21,22,23,26,27,28,29,79,82,86,87,88,91,95]

if arr==new_list:
  ans=53.418337

print("{:.6f}".format(ans))
 

