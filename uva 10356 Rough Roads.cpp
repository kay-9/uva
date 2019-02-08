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
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1297

ll test=1,n,r,x,y,z,ctr,cst,u;
pair<ll,ll>p;

int main(){
    fs;
    while(cin>>n>>r){
        vector<pair<ll,ll> >mat[n];
        priority_queue<pair<ll,pair<ll,ll> > >q;
        ll cost[n][2];
        f(i,0,n)
            f(j,0,2)
                cost[i][j]=1e9;

        f(i,0,r){
            cin>>x>>y>>z;
            p={y,z};
            mat[x].pb(p);
            p={x,z};
            mat[y].pb(p);
        }

        q.push(make_pair(0,make_pair(0,0)));
        cost[0][0]=0;

        while(!q.empty()){
            cst=-q.top().F;
            u=q.top().S.F;
            ctr=q.top().S.S;
            q.pop();

            if(cost[u][ctr]<cst)
                continue;

            ctr=!ctr;
            f(i,0,mat[u].size()){
                ll d=mat[u][i].first, c=mat[u][i].second;
                if(cst+c<cost[d][ctr]){
                    cost[d][ctr]=cst+c;
                    q.push(make_pair(-cost[d][ctr], make_pair(d,ctr)));
                }
            }
        }

        cout<<"Set #"<<test++<<"\n";
        if(cost[n-1][0]==1e9)
            cout<<"?\n";
        else
            cout<<cost[n-1][0]<<"\n";
    }

    return 0;
}
