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

const ll N=1e6+7;
vector<ll>prime,spf(N);
void seive()
{
    for (ll i = 1; i < N; ++i)spf[i]=i;
    for (ll i = 2; i*i<N; ++i)
    {
        if(spf[i]==i)
            for (ll j = i*i; j < N; j+=i) 
                spf[j]=min(i,spf[j]);
    }
    for (int i = 2; i < N; ++i)if(spf[i]==i)prime.pb(i);
}

int solve()
{
    ll n=1e6+1, x,sum=0;
    std::vector<ll> d(n,1),ok(n,1),ans;
    for(ll i=2; i<n; i++)
    {
    	for(ll j = i; j < n; j+= i )
    	{
    		d[j]++;
    	}
    }
    for( ll i = 1; i < n; i++)
    {
        for(ll j = i; j < n; j+= i)
        {
            if(d[j] % d[i] != 0)ok[j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        //cout<<i<<" "<<d[i]<<endl;
        if(ok[i] and d[i]>3)
    	   ans.pb(i);
    }
    for (int i = 107; i < ans.size(); i+=108)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

int main()
{
    fast;
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