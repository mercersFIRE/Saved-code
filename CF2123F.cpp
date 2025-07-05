#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e5+5;
vector<ll>prime,spf(N);
void seive()
{
    for (ll i = 1; i < N; ++i)spf[i]=i;
    for (ll i = 2; i<N; ++i)
    {
        for (ll j = i+i; j < N; j+=i) 
            spf[j]=i;
    }
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
ll binexp(ll base, ll power, ll mod) {
    if(!power)return 1;
    ll res = binexp(base, power/2, mod);
    return ((power&1)?(base*(res*res)%mod)%mod:(res*res)%mod);
}
int solve()
{
    ll n, x,sum=0;
    cin>>n;
    /*std::vector<ll> ans(n+1);
    for (ll i = 1; i <= n; ++i)ans[i]=i;

    for (int i = n; i > 0; --i)
    {
        swap(ans[i],ans[spf[i]]);
    }
    for(unsigned i = 1; i <= n; ++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;*/
    cout<<mod_exp(202,13486,N);
    cout<<binexp(202,13486,N);


    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
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