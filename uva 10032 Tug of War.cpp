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
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=973

ll n,r,s;
ll t[101],ok[45000/2+9];
int main(){
    fs;
    cin>>r;
    while(r--){
        cin>>n;
        s=0;
        f(i,0,n){
            cin>>t[i];
            s+=t[i];
        }
        f(i,1,s/2+1)
            ok[i]=0;
        ok[0]=1;
        f(i,0,n)
            for(ll j=s/2;j>=t[i];j--)
                    ok[j]|=(ok[j-t[i]]<<1);
        for(ll j=s/2;j>=0;j--){
            if(ok[j]&(1LL<<(n/2))||ok[j]&(1LL<<(n/2+n%2))){
               cout<<j<<" "<<s-j<<"\n";
               break;
            }
        }
        if(r)cout<<"\n";
    }
    return 0;
}
