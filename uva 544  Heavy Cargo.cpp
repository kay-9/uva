#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define mkp make_pair
#define pb(x) push_back(x)
#define S second
#define F first
#define N 100002
using namespace std;

// kay-9

ll n,m,c,f,nb=1;
ll t[201],rnk[201];
bool ok[201];
vector<pair<ll,ll> >lst[201];
string a,b;

ll fnd(ll x){
    if(t[x]==x)return x;
    return t[x]=fnd(t[x]);
}
bool same(ll x,ll y){
    return fnd(x)==fnd(y);
}
void ajt(ll x,ll y){
    if(!same(x,y)){
        x=fnd(x);
        y=fnd(y);
        if(rnk[x]>rnk[y])t[y]=x;
        else{
            t[x]=y;
            if(rnk[x]==rnk[y])rnk[y]++;
        }
    }
}
void dfs(ll u,ll mn){
    if(u==f){
        cout<<mn<<" tons\n\n";
        return;
    }
    ok[u]=true;
    f(j,0,lst[u].size()){
        if(ok[lst[u][j].F]==false){
            dfs(lst[u][j].F,min(mn,lst[u][j].S));
        }
    }
}

int main(){
    fs;
    while(cin>>n>>m,n+m!=0){
        cout<<"Scenario #"<<nb++<<"\n";
        vector<pair<ll,pair<ll,ll> > >mat;
        map<string,ll>mp;
        n=1;
        f(i,0,m){
            cin>>a>>b>>c;
            if(mp[a]==0)mp[a]=n++;
            if(mp[b]==0)mp[b]=n++;
            mat.pb(mkp(c,mkp(mp[a],mp[b])));
        }
        sort(mat.begin(),mat.end());
        reverse(mat.begin(),mat.end());
        f(i,1,n)t[i]=i,rnk[i]=0,lst[i].clear();
        cin>>a>>b;
        f(i,0,m){
            if(!same(mat[i].S.F,mat[i].S.S)){
                ajt(mat[i].S.F,mat[i].S.S);
                lst[mat[i].S.F].pb(mkp(mat[i].S.S,mat[i].F));
                lst[mat[i].S.S].pb(mkp(mat[i].S.F,mat[i].F));
            }
        }
        f=mp[b];
        f(i,0,n)ok[i]=false;
        dfs(mp[a],1e9);
    }
    return 0;
}
