#include<bits/stdc++.h>
#define fs ios_base::sync_with_stdio (0); cin.tie(0)
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define mkp make_pair
#define pb(x) push_back(x)
#define S second
#define F first
#define N 100002
using namespace std;

// kay-9

ll r,l,c;
string a[1001],d[1001];
ll b[1001],e[1001];
pair<ll,ll>mat[1001][1001];

int main(){
    fs;
    cin>>r;
    while(r--){
        cin>>l;
        f(i,0,l){
            cin>>a[i]>>a[i]>>b[i];
            mat[i][0]={0,0};
        }
        cin>>c;
        f(i,0,c){
            cin>>d[i]>>d[i]>>e[i];
            mat[0][i]={0,0};
        }

        f(i,0,l){
            f(j,0,c){
                mat[i+1][j+1]=max(mat[i][j+1],mat[i+1][j]);
                if(a[i]==d[j]){
                    mat[i+1][j+1]=max(mat[i+1][j+1],{mat[i][j].F+b[i]+e[j],mat[i][j].S-1});
                }
            }
        }
        cout<<mat[l][c].F<<" "<<-mat[l][c].S<<"\n";
    }
    return 0;
}
