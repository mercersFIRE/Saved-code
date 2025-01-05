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
vector<ll>prime,spf(N);
void seive()
{
    for (ll i = 1; i < N; ++i)spf[i]=i;
    for (ll i = 2; i*i<N; ++i)
    {
        if(spf[i]==i)
            for (ll j = i*i; j < N; j+=i) 
                spf[j]=min(i,spf[j]);
    }
    for (int i = 2; i < N; ++i)if(spf[i]==i)prime.pb(i);
}

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int solve()
{
    ll n, x,sum=1,mod=10000019;
    cin>>n>>x;
    for (int i = 0; prime[i]<=n and i < prime.size(); ++i)
    {
    	ll a=n,b=0;
    	while(a)
    	{
    		b+=a/prime[i];
            a/=prime[i];
    	}
        sum = (sum * mod_exp(prime[i], b/x, 10000019)) % 10000019;
    }
    if(sum==1)return 0;
    cout<<sum<<endl;
    return 1;
}

int main()
{
    fast;
    seive();
    ll tc = 1,x=1;cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<x++<<": ";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}