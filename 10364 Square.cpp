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
ll t[25];
ll solve(ll som,bitset<25>b,ll now,ll d){
    if(som>s)return 0;
    if(s==som){som=0;d=0;now++;}
    if(now==3)return 1;

    f(i,d,n){
        if(b[i]==0){
            b[i]=1;
            if(solve(som+t[i],b,now,i+1))return 1;
            b[i]=0;
        }
    }
    return 0;
}

int main(){
    cin>>r;
    while(r--){
        s=0;
        cin>>n;
        f(i,0,n){
            cin>>t[i];
            s+=t[i];
        }
        if(n<4||s%4!=0){cout<<"no\n";goto here;}
        s=s/4;
        if(solve(0,0,0,0))
            cout<<"yes\n";
        else
            cout<<"no\n";
        here:;
    }
    return 0;
}
