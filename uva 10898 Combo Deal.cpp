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

struct enreg{
    ll a[7],s;
};

ll r,n,m,som;
ll t[7],w[7];
enreg v[11];

ll solve(ll w[7]){
    ll ss=0;
    f(i,0,n){
        if(w[i]<0)return 1e9;
        ss+=w[i];
    }
    if(ss==0)return 0;
    ss=0;
    f(i,0,n)ss+=w[i]*t[i];
    f(j,0,m){
        f(i,0,n){
            w[i]-=v[j].a[i];
        }
        ss=min(ss,v[j].s+solve(w));
        f(i,0,n){
            w[i]+=v[j].a[i];
        }
    }

    return ss;
}

int main(){
    fs;
    while(cin>>n){
        f(i,0,n){
            cin>>t[i];
        }
        cin>>m;
        f(j,0,m){
            f(i,0,n){
                cin>>v[j].a[i];
            }
            cin>>v[j].s;
        }
        cin>>r;
        while(r--){
            som=0;
            f(i,0,n){
                cin>>w[i];
            }
            cout<<solve(w)<<"\n";
        }
    }
    return 0;
}
