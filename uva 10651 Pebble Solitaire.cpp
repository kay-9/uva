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

ll r,s=0;
string ch;
map<string,ll>mp;

ll solve(string ch){
    if(mp.count(ch)>0)return mp[ch];
    f(i,1,12){
        ll a=0,b=0;
        if(ch[i]==ch[i+1]&&ch[i]=='o'){
            if(ch[i-1]=='-'){
                ch[i]=ch[i+1]='-';
                ch[i-1]='o';
                a=solve(ch)+1;
                ch[i]=ch[i+1]='o';
                ch[i-1]='-';
            }
            if(ch[i+2]=='-'){
                ch[i]=ch[i+1]='-';
                ch[i+2]='o';
                b=solve(ch)+1;
                ch[i]=ch[i+1]='o';
                ch[i+2]='-';
            }
            mp[ch]=max(a,max(b,mp[ch]));
        }
    }
    return mp[ch];
}

int main(){
    fs;
    cin>>r;
    while(r--){
        cin>>ch;s=0;
        f(i,0,12)s+=(ch[i]=='o');
        ch='x'+ch+'x';
        cout<<s-solve(ch)<<"\n";
    }
    return 0;
}
