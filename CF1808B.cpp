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
    ll n, x,sum=0,m;
    cin>>n>>m;
    std::vector<ll> v[m];
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < m; ++j)
    	{
    		cin>> x;
    		v[j].pb(x);
    	}
    }
    for (int j = 0; j < m; ++j)
	{
		sort(v[j].begin(), v[j].end());
        ll x=-(n-1);
        for(auto&& i : v[j]) {
            sum+=x*i;
            x+=2;
        }
	}
    cout<<sum<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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