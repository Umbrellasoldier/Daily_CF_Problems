#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int MAXN=300010;

struct Node{
    int l,r;
    i64 sum,cnt;
};

struct Segment_Tree{
    string a=" ";
    Node tr[MAXN<<2];

    void merge(Node &u,Node &l,Node &r){
        u.sum=l.sum+r.sum;
        u.cnt=l.cnt+r.cnt;
        if(a[l.r]=='.'&&a[r.l]=='.')
            u.cnt--;
        return;
    }

    void init_data(int u,int x){
        tr[u].sum=tr[u].cnt=(a[x]=='.');
    }

    void build(int u,int l,int r){
        tr[u].l=l,tr[u].r=r;
        if(l==r){
            init_data(u,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void modify_point(int u,int x){
        if(tr[u].l==x&&tr[u].r==x){
            init_data(u,a[x]);
            return;
        }
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid){
            modify_point(u<<1,x);
        }else if(x>mid){
            modify_point(u<<1|1,x);
        }
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    Node query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u];
        }
        int mid=tr[u].l+tr[u].r>>1;
        if(r<=mid)
            return query(u<<1,l,r);
        if(l>mid)
            return query(u<<1|1,l,r);
        Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
        merge(res,left,right);
        return res;
    }
}T;

void solve(){
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;
    T.a+=s;

    T.build(1,1,n);

    while(m--){
        int x;
        char c;
        cin>>x>>c;
        T.a[x]=c;
        T.modify_point(1,x);
        auto ans=T.query(1,1,n);
        cout<<(ans.sum-ans.cnt)<<"\n";

    }

    

    return;
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
    
    
    return 0;
}

