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

const ll N=1e6+7;
std::vector<ll> v(N),t(4*N);
void build(ll n,ll b,ll e)
{
	if(b==e)
	{
		t[n]=v[e];
		return ;
	}
	ll mid=(b+e)/2;
	build(2*n,b,mid);
	build(2*n+1,mid+1,e);
	t[n]=t[2*n]+t[n*2+1];
}
void update(ll n,ll b,ll e,ll i,ll val)
{
	if(b==e and b==i)
	{
		t[n]+=val;
		v[e]+=val;
		return;
	}
	if(b>i ||e<i)return;
	ll mid=(b+e)/2;
	update(2*n,b,mid,i,val);
	update(2*n+1,mid+1,e,i,val);
	t[n]=t[2*n]+t[2*n+1];
}
ll query(ll n,ll b,ll e,ll l,ll r)
{
	if(b>=l and e<=r)
	{
		return t[n];
	}
	if(b>r ||e<l)return 0;
	ll mid=(b+e)/2;
	return query(2*n,b,mid,l,r)+query(2*n+1,mid+1,e,l,r);
}
int solve()
{
    ll n, x,sum=0,q,ind,val;
    cin>>n>>q;
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i+1];
    }
    build(1,1,n);
    for (int i = 0; i < q; ++i)
    {
    	cin>>x>>ind;
    	if(x==1)
    	{
    		cout<<v[ind+1]<<endl;
    		update(1,1,n,ind+1,-v[ind+1]);
    	}
    	if (x==2)
    	{
    		cin>>val;
    		update(1,1,n,ind+1,val);
    	}
    	if(x==3)
    	{
    		cin>>val;
    		cout<<query(1,1,n,ind+1,val+1)<<endl;
    	}
    }
    
    return 0;
}

int main()
{
    fast;
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