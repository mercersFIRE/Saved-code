#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;
std::vector<ll> v(N),lazy(4*N);
void update(ll n,ll b,ll e, ll l,ll r)
{
	if(b>r or e<l)return;
	if (b>=l and e<=r)
	{
		lazy[n]^=1;
	}
	ll mid=(b+e)/2;
	update(2*n,b,mid,l,r);
	update(2*n+1,mid+1,e,l,r);
}
void propagate(ll n)
{
	lazy[2*n]^=lazy[n];
	lazy[2*n+1]^=lazy[n];
	lazy[n]=0;
}
ll query(ll n,ll b,ll e,ll i)
{
    if(b>i||e<i)return 0;
    if(b==e and b==i)return lazy[n];
    ll mid=(b+e)/2;
    propagate(n);
    if(i<=mid)
    	return query(2*n,b,mid,i);
    else
    	return query(2*n+1,mid+1,e,i);

}
int solve()
{
	fill(lazy.begin(), lazy.end(),0);
    ll n, x,sum=0,q;
    cin>>n>>q;
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i+1];
    }
    for (int i = 0; i < q; ++i)
    {
    	char c;
    	ll l,r;
    	cin>>c;
    	if(c=='I')
    	{
    		cin>>l>>r;
    		update(1,1,n,l,r);
    	}
    	else
    	{
    		cin>>l;
    		cout<<(query(1,1,n,l))<<endl;
    	}
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1,x=0;cin>>tc;
    while (tc--)
    {
    	cout<<"Case "<<++x<<": \n";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}