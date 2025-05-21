def solve():
    n,m=MII()
    s=[]
    for i in range(n):
        s.append(input())
    row=[[0]*m for i in range(n)]
    for i in range(n):
        row[i][0]=int(s[i][0]=='B')
        for j in range(1,m):
            row[i][j]=row[i][j-1]+int(s[i][j]=='B')
    col=[[0]*n for i in range(m)]
    for j in range(m):
        col[j][0]=int(s[0][j]=='B')
        for i in range(1,n):
            col[j][i]=col[j][i-1]+int(s[i][j]=='B')
    def get_row(i,l,r):
        if l==0:
            return row[i][r]
        return row[i][r]-row[i][l-1]
    def get_col(i,l,r):
        if l==0:
            return col[i][r]
        return col[i][r]-col[i][l-1]
    P=[]
    for i in range(n):
        for j in range(m):
            if s[i][j]=='B':
                P.append([i,j])
    L=len(P)
    for i in range(L):
        px,py=P[i]
        for j in range(i+1,L):
            qx,qy=P[j]
            if get_row(px,min(py,qy),max(py,qy))==abs(py-qy)+1 and get_col(qy,min(px,qx),max(px,qx))==abs(px-qx)+1:
                continue
            if get_row(qx,min(py,qy),max(py,qy))==abs(py-qy)+1 and get_col(py,min(px,qx),max(px,qx))==abs(px-qx)+1:
                continue
            print('NO')
            return
    print('YES')
    return
