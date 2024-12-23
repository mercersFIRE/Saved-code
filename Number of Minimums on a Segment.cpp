#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
using namespace __gnu_pbds; 
#define pbds tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;

const ll N = 1e5+7;

vector<ll> v(N),t(4*N,1e18);

ll build(ll n, ll b , ll e)
{
	if(b==e)return t[n] = v[e];

	ll mid = (b+e)/2;

	return t[n] = min(build(2*n, b, mid) , build(2*n+1, mid+1, e));
}
ll query(ll n, ll b, ll e, ll l, ll r)
{
    if(e<l || b>r)return 1e18;
    if(b>=l && e<=r)return t[n];

    ll mid = (b+e)/2;
    return min(query(2*n, b, mid, l, r) , query(2*n+1, mid+1, e, l, r));
}

ll update(ll n, ll b, ll e, ll i, ll x)
{
    if(b==e && b==i)return t[n] = v[i] = x;
    if(i<b || i>e)return t[n];

    ll mid = (b+e)/2;
    return t[n] = min(update(2*n, b, mid, i, x) , update(2*n+1, mid+1, e, i, x));
}

int solve()
{
    ll n, x,sum=0;
    cin>>n>>x;
    map<ll, pbds> m;
    for (int i = 1; i <= n; ++i)
    {
    	cin>>v[i];
        m[v[i]].insert(i);  
    }
    
    build(1,1,n);
    for (int i = 0; i < x; ++i)
    {
        ll q, a, b;
        cin>> q >> a >> b;
        if(q==1)
        {
            m[v[a+1]].erase(a+1);
            m[b].insert(a+1);
            update(1, 1, n, a+1, b);
        }
        else
        {
            ll ans = query(1, 1, n, a+1, b);
            ll j = *(--m[ans].upper_bound(b)),k = *(m[ans].lower_bound(a+1));
            cout<<ans<<" "<<m[ans].order_of_key(j) - m[ans].order_of_key(k) + 1<<endl;
        }
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