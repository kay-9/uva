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
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2176

ll t[100002],som[100002],st[100002],seg[4*100002];
ll n,q,x,y,z,d,a,b;

void build(int i,int s,int e){
    if(s==e){
        seg[i]=som[s];
        return;
    }
    build(2*i,s,(s+e)/2);
    build(2*i+1,(s+e)/2+1,e);
    seg[i]=max(seg[2*i],seg[2*i+1]);
}
ll fnd(int i,int s,int e,int d,int f){
    if(s>f||e<d)return -1e9;
    if(s>=d&&e<=f){
        return seg[i];
    }
    ll u=fnd(2*i,s,(s+e)/2,d,f);
    ll v=fnd(2*i+1,(s+e)/2+1,e,d,f);
    return max(u,v);
}

int main(){
    while(cin>>n,n!=0){
        cin>>q;
        map<ll,ll>mp;
        f(i,0,n){
            cin>>t[i+1];
            mp[t[i+1]]++;
        }
        f(i,0,3*n+1)seg[i]=0;
        x=1e6;d;
        f(i,0,n){
            som[i+1]=mp[t[i+1]];
            if(x!=t[i+1]){
                d=i+1;
                x=t[i+1];
            }
            st[i+1]=d;
        }
        build(1,1,n);
        while(q--){
            cin>>a>>b;
            if(t[a]==t[b])cout<<b-a+1<<"\n";
            else{
                x=som[a]+st[a]-a;
                y=b-st[b]+1;
                z=fnd(1,1,n,som[a]+st[a],st[b]-1);
                cout<<max(x,max(y,z))<<"\n";
            }
        }
    }
    return 0;
}
