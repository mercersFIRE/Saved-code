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

int solve()
{
    ll n, x=1,sum=0;
    std::vector<bool> prime(1e6 +6,1);
    prime[1]=0;
    std::vector<ll> p;
    for (ll i = 2; i*i <= 1e6; ++i)
    {
    	if(prime[i])
    		for (ll j = i+j; j <= 1e6; j+=i)
    		{
    			prime[j]=0;
    		}
    }
    for (int i = 2; i <= 1e6; ++i)
    {
    	if(prime[i])p.pb(i);
    }
    cin>>x;
    while(x)
    {
        n=x;
    	std::map<ll, ll> m;
    	for (int i = 0; i < p.size() and p[i]<=x; ++i)
    	{
    		while(x%p[i]==0)
    		{
    			m[p[i]]++;x/=p[i];
    		}
    	}
    	cout<<n<<" : "<<m.size()<<endl;;
    	cin>>x;
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