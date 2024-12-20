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
    ll n, x,sum=0;
    cin>>n;
    std::vector<ll> v(n+2);
    for (int i = 1; i <= n; ++i)
    {
    	cin>>v[i];
    	sum+=v[i];
    }
    if(sum==0)
    {
    	cout<<0<<endl;
    	return 0;
    }
    for (int i = 0; v[i]==0; ++i)
    {
    	v[i]++;
    }
    for (int i = n+1; v[i]==0; --i)
    {
    	v[i]++;
    }
    for (int i = 0; i < n; ++i)
    {
    	if(v[i+1]==0)
    	{
    		cout<<2<<endl;
    		return 0;
    	}
    }
    cout<<1<<endl;
    
    return 0;
}

int main()
{
    fast;
    ll tc = 1;cin>>tc;
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