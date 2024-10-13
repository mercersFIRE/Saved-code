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
    std::vector<bool> prime(1e8);
    std::vector<ll> p;
    for (ll i = 2; i*i<1e8; ++i)
    {
    	if(prime[i]==0)
    	{
			for (ll j = i*i; j < 1e8; j+=i)
			{
				prime[j]=1;
			}
    	}
    }
    for (int i = 2; i < 1e8; ++i)
    {
    	if(!prime[i])p.pb(i);
    }
    for (int i = 0; i < p.size(); i+=100)
    {
        cout<<p[i]<<endl;
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