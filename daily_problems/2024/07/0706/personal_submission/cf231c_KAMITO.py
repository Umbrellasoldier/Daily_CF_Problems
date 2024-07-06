def solve():
    n,k=map(int,input().split())
    a=list(map(int,input().split()))

    ans=[-1,inf]
    a.sort()
    s=0;j=0
    for i in range(n):
        s+=a[i]
        while j<i and (i-j+1)*a[i]-s>k:
            s-=a[j]
            j+=1
        if i-j+1>ans[0]:
            ans=[i-j+1,a[i]]
        elif i-j+1==ans[0] and a[i]<ans[1]:
            ans=[i-j+1,a[i]]
    print(*ans)

    return
