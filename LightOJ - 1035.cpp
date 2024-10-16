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

const ll N=5e4+7,mod=1e9 +7;
vector<ll>prime;
vector<ll> p(N);
void seive()
{
    for (ll i = 1; i < N; ++i)
    {
        p[i]=i;
    }
    for (ll i = 2; i*i<N; ++i)
    {
        if(p[i]==i)
            for (ll j = i*i; j < N; j+=i) 
                p[j]=min(i,p[j]);
    }
    for (int i = 2; i < N; ++i)
        if(p[i]==i)prime.pb(i);
}

int solve()
{
    ll n, x,sum=1,a;
    cin>>n;
    vector<ll>m(n+1);
    for (int i = 2; i <= n; ++i)
    {
    	x=i;
    	while(x>1)
        {
            m[p[x]]++;
            x/=p[x];
        }
    }
    for(auto&& i : m) {
        //cout<<i.ff<<" "<<i.ss<<endl;
        sum=(sum*(i+1))%mod;
    }

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
        //cout<<"Case "<<x++<<":\n";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "Impossible to divide\n";
        }
    }
    return 0;
}