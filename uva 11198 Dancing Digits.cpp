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
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2139&mosmsg=Submission+received+with+ID+23873061

ll nb=1,x,sig[9];
vector<ll> u,v,t;
map<ll,ll>mp;
map<vector<ll>,ll>res;

vector<ll>droite(ll d,ll f,vector<ll> t){
    if(d<f)
        f(i,d,f)
            swap(t[i],t[i+1]);
    else
        for(ll i=d;i>f+1;i--)
            swap(t[i],t[i-1]);
    return t;
}

vector<ll>gauche(ll d,ll f,vector<ll> t){
    if(d<f)
        f(i,d,f-1)
            swap(t[i],t[i+1]);
    else
        for(ll i=d;i>f;i--)
            swap(t[i],t[i-1]);
    return t;
}

int main(){
    fs;
    mp[3]=mp[5]=mp[7]=mp[11]=mp[13]=1;
    f(i,0,8)
        v.pb(i+1);
    cin>>x;
    t.pb(x);
    while(t[0]){
        if(t[0]>0)sig[t[0]]=1;
        else sig[abs(t[0])]=-1;
        t[0]=abs(t[0]);
        f(i,1,8){
            cin>>x;
            t.pb(abs(x));
            if(x>0)
                sig[t[i]]=1;
            else
                sig[t[i]]=-1;
        }
        res[t]=1;
        queue<vector<ll> >q;
        q.push(t);
        while(!q.empty()){
            t=q.front();
            q.pop();
            if(t==v){
                cout<<"Case "<<nb++<<": "<<res[v]-1<<"\n";
                break;
            }
            f(i,0,8){
                f(j,0,8){
                    if(i!=j&&sig[t[i]]*sig[t[j]]<0&&mp[t[i]+t[j]]){
                        u=droite(i,j,t);
                        if(res[u]==0){
                            res[u]=res[t]+1;
                            q.push(u);
                        }
                        u=gauche(i,j,t);
                        if(res[u]==0){
                            res[u]=res[t]+1;
                            q.push(u);
                        }
                    }
                }
            }
        }
        if(t!=v)
            cout<<"Case "<<nb++<<": -1\n";
        t.clear();res.clear();u.clear();
        cin>>x;
        t.pb(x);
    }
    return 0;
}
