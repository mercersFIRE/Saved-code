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
    ll n, x,sum=0,ans=1;
    cin>>n;
    std::vector<ll> v(n),prime(1000006),p;
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    	x=(i?__gcd(v[i],x):v[i]);
    }
    //cout<<x<<endl;
    n=x;
    for (ll i = 2; i<= 1e6; ++i)
    {
    	if(prime[i]==0)
    	{
			for (ll j = i+i; j <= 1e6; j+=i)
			{
				prime[j]++;
			}
    	}
    }
    for (int i = 2; i <= 1e6; ++i)
    {
    	if(!prime[i])p.pb(i);
    }
    for (int i = 0; i<p.size() and p[i] <=n; ++i)
    {
    	sum=0;
    	while(n%p[i]==0)
    	{
    		sum++;
    		n/=p[i];
    	}
    	ans*=(sum+1);
    }
    if(n>1)ans*=2;
    //cout<<n<<endl;
    cout<<ans<<endl;
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