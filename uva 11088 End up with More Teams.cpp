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

ll r,n,s;
ll t[16],dp[1<<16];
ll solve(ll v){
    if(dp[v]!=-1)return dp[v];
    ll res=0;
    f(i,0,n){
        if((v&(1<<i))==0){
            f(j,i+1,n){
                if((v&(1<<j))==0){
                    f(k,j+1,n){
                        if(((v&(1<<k))==0)&&t[i]+t[j]+t[k]>=20){
                            res=max(1+solve(v|(1<<i)|(1<<j)|(1<<k)),res);
                        }
                    }
                }
            }
        }
    }
    return dp[v]=res;
}

int main(){
    ll r=1;
    while(cin>>n,n!=0){
            memset(dp,-1,sizeof dp);
            f(i,0,n)cin>>t[i];
            cout<<"Case "<<r++<<": "<<solve(0)<<endl;
    }
    return 0;
}
