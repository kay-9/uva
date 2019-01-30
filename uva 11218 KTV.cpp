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

struct enreg{
    ll a,b,c,s;
};
ll r=1,n;
enreg t[100];

int main(){
    fs;
    while(cin>>n,n!=0){
        cout<<"Case "<<r++<<": ";
        f(i,0,n){
            cin>>t[i].a>>t[i].b>>t[i].c>>t[i].s;
        }
        ll som=0;
        f(i,0,n){
            bitset<10>b;
            b[t[i].a]=1;
            b[t[i].b]=1;
            b[t[i].c]=1;
            f(j,i+1,n){
                if(b[t[j].a]+b[t[j].b]+b[t[j].c]==0){
                    b[t[j].a]=1;
                    b[t[j].b]=1;
                    b[t[j].c]=1;
                    f(k,j+1,n){
                        if(b[t[k].a]+b[t[k].b]+b[t[k].c]==0){
                            som=max(som,t[i].s+t[j].s+t[k].s);
                            break;
                        }
                    }
                    b[t[j].a]=0;
                    b[t[j].b]=0;
                    b[t[j].c]=0;
                }
            }
            b[t[i].a]=0;
            b[t[i].b]=0;
            b[t[i].c]=0;
        }
        if(som==0)som=-1;
        cout<<som<<"\n";
    }
    return 0;
}
