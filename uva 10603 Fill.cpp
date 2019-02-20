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

ll r,d,dif,res,res2;
ll t[5];

int main(){
    fs;
    cin>>r;
    while(r--){
        res=res2=0;
        cin>>t[0]>>t[1]>>t[2]>>d;
        vector<ll>w;
        w.pb(0);
        w.pb(0);
        w.pb(t[2]);
        priority_queue<pair<ll,vector<ll> > >q;
        pair<ll,vector<ll> >u;
        map<vector<ll>,ll>mp;
        q.push({0,w});
        while(!q.empty()){
            u=q.top();
            q.pop();
            vector<ll>v=u.S;
            if(mp[v]==1)continue;
            mp[v]=1;
            f(i,0,3){
                if(v[i]<=d && res<v[i] && res<d){
                    res=v[i];
                    res2=-u.F;
                }
                if(v[(i+1)%3]!=t[(i+1)%3]){
                    dif=min(t[(i+1)%3]-v[(i+1)%3],v[i]);
                    v[i]-=dif;
                    v[(i+1)%3]+=dif;
                    q.push({u.F-dif,v});
                    v[i]+=dif;
                    v[(i+1)%3]-=dif;
                }
                if(v[(i+2)%3]!=t[(i+2)%3]){
                    dif=min(t[(i+2)%3]-v[(i+2)%3],v[i]);
                    v[i]-=dif;
                    v[(i+2)%3]+=dif;
                    q.push({u.F-dif,v});
                    v[i]+=dif;
                    v[(i+2)%3]-=dif;
                }
            }
        }
        cout<<res2<<" "<<res<<"\n";
    }
    return 0;
}
