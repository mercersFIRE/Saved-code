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
    ll n, x,sum=1e18,k;
    cin>>n>>k;
    multiset<ll>s[k+1];
    std::map<ll, ll> m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>x;
    	s[x].insert(m.find(x)!=m.end()?i-m[x]-1:i-m[x]);
        m[x]=i;
    }
    for (int i = 1; i <= k; ++i)
    {
    	if(!s[i].empty()) {
            s[i].insert(n-m[i]-1);
    		ll x = *s[i].rbegin();
    		s[i].erase(--s[i].end());
    		s[i].insert(x/2);
    	}
    }
    for (int i = 0; i <= k; ++i)
    {
        if(!s[i].empty())
    	   sum=min(sum,*s[i].rbegin());
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