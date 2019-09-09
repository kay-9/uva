#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define F first
#define N 200002
using namespace std;

// kay-9
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1212

ll r,k,n;
ll t[5009],dp[5002][1010];
ll solve(ll i,ll k,ll res){
    if(k+res==0)return 0;
    if(n-i-k*3-res<0)return 1e9;
    ll &x=dp[i][k];
    if(x<1e9)return x;
    ll a=solve(i+1,k,max(res-1,0LL));
    ll b=1e9;
    if(k) b=(t[i+1]-t[i])*(t[i+1]-t[i])+solve(i+2,k-1,res+1);
    return x=min(a,b);
}

int main(){
    fs;
    cin>>r;
    while(r--){
        cin>>k>>n;
        k+=8;
        f(i,0,n)cin>>t[i];
        f(i,0,n+2)
            f(j,0,k+2)
                dp[i][j]=1e9;

        cout<<solve(0,k,0)<<"\n";
    }
    return 0;
}
