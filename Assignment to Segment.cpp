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

vector<ll> lazy(4*N,-1);
void propagate(ll n)
{
    if(lazy[n]!=-1){
        lazy[2*n]=lazy[n];
        lazy[2*n+1]=lazy[n];
        lazy[n]=-1;
    }
}

void update(ll n, ll b, ll e, ll l, ll r, ll val)
{
	if(b>r || e<l)return ;
	if(b>=l && e<=r)
    {
        lazy[n]=val;
        return ;
    }
    propagate(n);
	ll mid = (b + e) / 2;
    update(2 * n, b, mid, l, r, val);
    update(2*n + 1, mid + 1, e, l, r, val);
	return ;
}

ll query(ll  n, ll b, ll e, ll l, ll r, ll val)
{
	if(b>r || e<l)return 0;
	if(b>=l && e<=r)return lazy[n];
    propagate(n);
	ll mid = (b + e) / 2;
	return query(2*n, b, mid, l, r, val) + query(2*n + 1, mid + 1, e, l, r, val);
}

int solve()
{
    ll n, x,sum=0,m,l,r,val;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
    	cin>>x;
    	if(x==1)
    	{
    		cin>>l>>r>>val;
    		update(1, 1, n, l + 1, r, val);
    	}
    	else
    	{
    		cin>>val;
    		cout<<max(query(1, 1, n, val + 1, val + 1, 0),0ll)<<endl;
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