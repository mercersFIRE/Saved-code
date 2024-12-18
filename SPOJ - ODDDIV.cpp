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

const ll N=1e5+4;
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

int solve()
{
    ll n, x,sum=0,l,r,k;
    std::vector<ll> v[N];
    for (ll i = 1; i <N; ++i)
    {
        x = i;
        ll div=1;
        while(x>1) {
            ll p = spf[x],e = 0;
            while(x%p==0)
            {
                e++;
                x/=p;
            }
            div*=(2*e+1);
        }
        v[div].pb(i*i);
        //cout<<div<<endl;
    }
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        ll sum=0;
        cin>>k>>l>>r;
        
        cout<<upper_bound(v[k].begin(), v[k].end(),r)-lower_bound(v[k].begin(), v[k].end(),l)<<endl;
        
    }
    
    return 0;
}

int main()
{
    fast;
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