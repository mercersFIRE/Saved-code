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

const ll N=1e6+9;
vector<ll>prime,ans(N);
vector<bool> p(N);

ll zero(ll n)
{
	while(n) {
	    if(n%10==0)return 0;
	    n/=10;
	}
	return 1;
}
ll fun(ll n)
{
	ll x=0,a=0;
	while(n) {
	    ll d=n%10;
        n/=10;
	    a+=d*pow(10,x);
	    x++;
	    if(p[a])return 0;
	}
	return a;
}

void seive()
{
    for (ll i = 2; i*i<N; ++i)
    {
        if(p[i]==0)
            for (ll j = i*i; j < N; j+=i)
                p[j]=1;
    }
    for (int i = 2; i <= N; ++i)
    {
        ans[i]=ans[i-1]+(!p[i] and zero(i) and fun(i));
        //cout<<i<<" "<<ans[i]<<" "<<p[i]<<" "<<zero(i)<<" "<<fun(i)<<endl;
    }
}

int solve()
{
    ll n, x,sum=0;
    cin>>n;
    cout<<ans[n]<<endl;
    return 0;
}

int main()
{
    fast;
    seive();
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