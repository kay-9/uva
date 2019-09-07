#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define F first
#define N 400002
using namespace std;

// kay-9
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1095

ll x,y,n=0;
pair<ll,ll> t[6000];
ll dp[6000];

int main(){
    fs;
    memset(dp,-1,sizeof dp);
    while(cin>>x>>y){
        if(x<=y){
            t[n].S=x;
            t[n++].F=y-x;
        }
    }
    sort(t,t+n);
    reverse(t,t+n);
    dp[0]=1e9;
    f(i,0,n){
        for(ll j=i+1;j>0;j--){
            dp[j]=max(dp[j],min(dp[j-1]-t[i].S,t[i].F));
        }
    }
    ll i;
    for(i=n;dp[i]==-1;i--);
    cout<<i<<"\n";
    return 0;
}
