#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb(x) push_back(x)
#define ll long long
#define S second
#define F first
#define N 100001
using namespace std;

// kay-9

ll nb,x,y,z,n,scc,m,ok[2002],num[2002],low[2002];
vector<ll>mat[2002];

void tarjan(ll u){
    low[u]=num[u]=nb++;
    ok[u]=1;
    for(auto v:mat[u]){
        if(num[v]==0)tarjan(v);
        if(ok[v]) low[u]=min(low[u],low[v]);
    }
        if(low[u]==num[u]&&u!=1)    scc=-1;
}

int main(){
    while(cin>>n>>m,n+m!=0){
        f(i,0,2002)mat[i].clear();
        memset(ok,0,sizeof ok);
        memset(num,0,sizeof num);
        memset(low,0,sizeof low);
        nb=1; scc=0;
        f(i,0,m){
            cin>>x>>y>>z;
            mat[x].pb(y);
            if(z==2)mat[y].pb(x); }
        tarjan(1);
        cout<<(scc==0&&count(ok,ok+n+1,1)==n)<<endl;
    }
return 0;}

