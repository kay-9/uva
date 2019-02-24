#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define ll long long
#define pb(x) push_back(x)
#define S second
#define F first
#define N 100002
using namespace std;

// kay-9

ll n,x,a,b,s,mx,mn;
ll v[102];
bool ok[102][5001][51];

void solve(ll i,ll som,ll nb){
    if(nb==a){
        ll x=som-50*a;
        mx=max(mx,x*(s-x));
        mn=min(mn,x*(s-x));
        return ;
    }
    if(i==n)return;
    if(ok[i][som][nb]==true)return;
    ok[i][som][nb]=true;
    solve(i+1,som,nb);
    solve(i+1,som+v[i],nb+1);
}

int main(){
    fs;
    while(cin>>a>>b){
        memset(ok,false,sizeof ok);
        n=a+b;
        if(a>b)swap(a,b);
        s=0;
        f(i,0,a+b){
            cin>>v[i];
            s+=v[i];
            v[i]+=50;
        }
        mx=-1e9;
        mn=1e9;
        solve(0,0,0);
        cout<<mx<<" "<<mn<<"\n";
    }
    return 0;
}
