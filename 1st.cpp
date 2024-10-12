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
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    	x=(i?__gcd(v[i],x):v[i]);
    }
    //cout<<x<<endl;
    n=x;
    for (int i = 2; i <=n; ++i)
    {
    	sum=0;
    	while(n%i==0)
    	{
    		sum++;
    		n/=i;
    	}
    	ans*=(sum+1);
    }
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