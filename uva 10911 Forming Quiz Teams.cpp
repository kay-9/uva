#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define F first
#define N 100002
using namespace std;

// kay-9

ll test=1,n,r,x,y,z,ctr,cst,u;
pair<ll,ll>t[20];
map<ll,double>dp;
string ch;

double solve(ll d,bitset<16>b){
    if(b==r)
        return  0;
    if(dp[b.to_ulong()]!=0)
        return dp[b.to_ulong()] ;

    double s=1e9;
    f(i,0,n){
        if(b[i]==0){
            b[i]=1;
            f(j,i+1,n){
                if(b[j]==1)continue;
                b[j]=1;
                s=min(s,solve(i+1,b)+sqrt((t[i].F-t[j].F)*(t[i].F-t[j].F)+(t[i].S-t[j].S)*(t[i].S-t[j].S)));
                b[j]=0;
            }
            return  dp[b.to_ulong()]=s;
        }
    }
}

int main(){
    while(cin>>n,n){
        dp.clear();
        n*=2;
        r=(1<<n)-1;
        f(i,0,n)cin>>ch>>t[i].F>>t[i].S;
        cout<<"Case "<<test++<<": ";
        printf("%.2f\n",solve(0,0));
    }
    return 0;
}
