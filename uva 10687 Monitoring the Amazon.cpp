#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define F first
#define N 200002
using namespace std;

// kay-9

ll n,d,dis;
pair<ll,ll> x,t[1001];
vector<ll> mat[1001];
ll ok[1001];
ll dfs(ll u){
    ll s=1;
    ok[u]=1;
    for(auto y:mat[u]){
        if(ok[y]==-1)
            s+=dfs(y);
    }return s;
}

int main(){
    while(cin>>n,n!=0){
        f(i,0,n){
            cin>>t[i].F>>t[i].S;
        }
        x=t[0];
        sort(t,t+n);
        f(i,0,n)
            if(t[i]==x){
                d=i;break;
            }
        f(i,0,n){
            mat[i].clear();
            ll mn1=1e9,mn2=mn1,a,b;
            f(j,0,n){
                dis=(t[i].F-t[j].F)*(t[i].F-t[j].F)+(t[i].S-t[j].S)*(t[i].S-t[j].S);
                if(dis!=0){
                    if(dis<mn1){
                        mn2=mn1;
                        b=a;
                        a=j;
                        mn1=dis;
                    }else if(dis<mn2){
                        b=j;
                        mn2=dis;
                    }
                }
            }
            mat[i].pb(a);
            mat[i].pb(b);
        }

        memset(ok,-1,sizeof ok);
        if(dfs(d)==n)cout<<"All stations are reachable.\n";
        else cout<<"There are stations that are unreachable.\n";
    }
    return 0;
}
