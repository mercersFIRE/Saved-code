#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;
std::vector<ll> lazy(4*N),t(4*N,0);

void propagate(ll n)
{
    t[n]+=lazy[n];
	lazy[2*n]+=lazy[n];
	lazy[2*n+1]+=lazy[n];
	lazy[n]=0;
}
ll merge(ll l,ll r)
{
	return min(l,r);
}
void update(ll n,ll b,ll e,ll l, ll r,ll val)
{
    propagate(n);
	if(b>r or e<l)return;
	if(b>=l and e<=r)
	{
		lazy[n]+=val;
        propagate(n);
		return ;
	}
	ll mid=(b+e)/2;
	update(2*n,b,mid,l,r,val);
	update(2*n+1,mid+1,e,l,r,val);

    t[n]=merge(t[2*n],t[2*n+1]);
}



ll query(ll n,ll b,ll e,ll l,ll r)
{
    propagate(n);
    if(b>r||e<l)return 1e18;
    if(b>=l and e<= r)return t[n];
    ll mid=(b+e)/2;
    ll ans=query(2*n,b,mid,l,r);
    ans=min(ans,query(2*n+1,mid+1,e,l,r));

    
    t[n]=merge(t[2*n],t[2*n+1]);
    return ans;
}

void prin(ll n,ll b,ll e)
{
    cout<<n<<" :: "<<b<<' '<<e<<' '<<" : "<<lazy[n]<<' '<<t[n]<<"\n";
    if(b==e)return ;
    ll md=(b+e)/2;
    prin(n*2,b,md);
    prin(n*2+1,md+1,e);
}
int solve()
{
    ll n, x,sum=0,q,l,r,val;
    cin>>n>>q;
    for (int i = 0; i < q; ++i)
    {
    	cin>>x>>l>>r;
    	if (x==1)
    	{
    		cin>>val;
    		update(1,1,n,l+1,r,val);
    	}
    	else
    	{
    		cout<<query(1,1,n,l+1,r)<<endl;
    	}
       // prin(1,1,n);
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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