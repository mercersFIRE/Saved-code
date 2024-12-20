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
    std::vector<ll> v(n+1);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i+1];
    }
    for (int i = 1; i <= n; ++i)
    {
    	ll flg=0;
    	for (int j = 2; j <= i+1; ++j)
    	{
    		if(v[i]%j!=0)
    		{
    			flg=1;
    			break;
    		}
    	}
    	if(flg==0)return 0;
    }
    
    return 1;
}

int main()
{
    fast;
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        if (solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}