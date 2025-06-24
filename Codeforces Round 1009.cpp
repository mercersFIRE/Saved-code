#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
typedef long long ll;

ll bfs(ll i,set<ll> v[],vector<ll>&vis,vector<ll>&lev)
{
    queue<ll>q;
    q.push(i);
    vis[i]=i;
    while(!q.empty())
    {
        ll f=q.front();q.pop();
        for(auto c:v[f])
        {
            if(vis[c]==i)return 1;
            if(vis[c]!=-1)continue;
            q.push(c);
            vis[c]=i;
            lev[c]=lev[f]+1;
        }
    }
    return 0;
}
int solve()
{
    ll n,m,x,y,sum=0,k;
    string s,t;
    cin>>n>>s>>t;
    if (s == t) {
        cout << 0 << endl;
        return 1;
    }
    vector<ll> vis(26,-1),lev(26);
    set<ll>v[26];
    for (int i = 0; i < n; ++i)
    {
        v[s[i]-'a'].insert(t[i]-'a');
        if(v[s[i]-'a'].size()>1)return 0;
    }
    for (int i = 0; i < 26; ++i)
    {
        if(v[i].size() && *v[i].begin()==i)v[i].clear();

        if(v[i].size())
        {
            sum++;
            if(vis[i]==-1)
                sum+=bfs(i,v,vis,lev);
        }
    }
    cout<<sum<<endl;
    return 1;
}

int main()
{
    fast;
    ll tc = 1,p=0;//cin>>tc;
    while (tc--)
    {
        //cout<<"Case "<<++p<<": "<<solve()<<endl;
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}