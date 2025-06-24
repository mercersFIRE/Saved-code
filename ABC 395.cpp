#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;

int solve()
{
    ll n, x,sum=0,q,a,b;
    cin>>n>>q;
    std::map<ll, ll> m;
    vector<ll> v;
    for (int i = 0; i <= n; ++i)
    {
        v.pb(i);
        m[i]=i;
    }
    for (int i = 0; i < q; ++i)
    {
        cin>>x;
        if(x==1)
        {
            cin>>a>>b;
            m[a]=b;
        }
        if(x==2)
        {
            cin>>a>>b;
            ll t=v[a];
            v[a]=v[b];v[b]=t;
        }
        if (x==3)
        {
            cin>>a;
            cout<<v[m[a]]<<endl;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;//cin>>tc;
    while (tc--)
    {
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}