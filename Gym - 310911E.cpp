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
    ll n, x,sum=0;
    cin>>n;
    std::vector<ll> v(n),prime(1000006),p;
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
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
        std::map<ll, ll> m;
        for (int j = 0; j < p.size()&&p[j]<=x; ++j)
        {
            x=v[i];
            while(x%p[j]==0)
            {
                cout<<" found "<<p[j]<<endl;
                m[p[j]]++;x/=p[j];
            }
        }
        for(auto y:m)
            cout<<y.ff<<" "<<y.ss<<endl;
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