#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;

ll check(vector<ll> &p, ll i , ll x, ll mid){
	ll total = p[i] + (i*(mid-1));
	return total<=x;
}

int solve()
{
    ll n, x,sum=0;
    cin>>n>>x;
    std::vector<ll> v(n+1), p(n+1);

    for(ll i = 0; i < n; ++i) {
    	cin>>v[i+1];
    }
    sort(v.begin(), v.end()	);
    for(ll i = 1; i <= n; ++i) {
    	p[i] = p[i-1] + v[i];
    }

    for(ll i = 1; i <= n; ++i) {
    	ll b = 1, e = x, mid, ans = 0;
    	while(b<=e) {
    	    mid = (b+e)/2;
    	    if(check(p, i, x, mid)){
    	    	ans = mid;
    	    	b = mid+1;
    	    }
    	    else
    	    	e = mid-1;
    	}
    	if(!ans)break;
    	sum+= ans;
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