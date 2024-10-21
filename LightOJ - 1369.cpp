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
    ll n, x,sum=0,q;
    cin>>n>>q;
    std::vector<ll> v(n);
    std::map<ll, ll> m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    }
    for (int i = 0; i < n/2; ++i)
    {
        //cout<<i<<" for "<<n-i-1<<endl;
    	x=(n-1-i)-i;
        m[n-i-1]=i;
        m[i]=n-i-1;
    	sum+=x*(v[i]-v[n-1-i]);
    }
    while(q--){
        ll a,b,c,mn,mx;
        cin>>a;
        if(a)
            cout<<sum<<endl;
        else{
            cin>>b>>c;
            mn=min(b,m[b]);
            mx=max(b,m[b]);
            x=mx-mn;
            //cout<<mn<<" mn mx "<<mx<<endl;
            sum-=x*(v[mn]-v[mx]);
            v[b]=c;
            sum+=x*(v[mn]-v[mx]);
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
        cout<<"Case "<<++x<<":"<<endl;
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}