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
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3679

bool dp[32][32][6009];
vector<ll> t,sig;
string ch;
set<ll>st;
char c;
ll x,y,n;

void solve(ll i,ll open,ll val){
    if(i==n){
        st.insert(val);
        return;
    }
    bool &res=dp[i][open][val];
    if(res)return;
    res=true;
    if(sig[i]==-1)
        solve(i+1,open+1,val+t[i]*((open%2)?-1:1));
    f(j,0,open+1){
        solve(i+1,open-j,val+t[i]*(((open)%2)?-1:1));
    }
}

int main(){
    while(getline(cin,ch)){
        memset(dp,false,sizeof dp);
        stringstream ss(ch);
        ss>>x;
        t.clear();
        sig.clear();
        st.clear();
        t.pb(x);
        sig.pb(1);
        while(ss>>c>>x){
            y=1;
            if(c=='-'){
                y=-1;
                x=-x;
            }
            t.pb(x);
            sig.pb(y);
        }
        n=t.size();
        solve(0,0,3000);
        cout<<st.size()<<"\n";
    }
    return 0;
}
