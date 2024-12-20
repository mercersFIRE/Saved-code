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

const ll N=1e5+7;
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
    ll n, x,sum=1;
    cin>>n;
    std::vector<ll> v(N);
    for (int i = 0; i < n; ++i)
    {
    	cin>>x;
    	ll div=0;
    	while(x>1)
    	{
    		if(div!=spf[x])
    		{
    			v[spf[x]]++;
    			div=spf[x];
    			sum=max(sum,v[div]);
    		}
    		x/=spf[x];
    	}
    }
    cout<<sum<<endl;
    
    return 0;
}

int main()
{
    fast;
    seive();
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