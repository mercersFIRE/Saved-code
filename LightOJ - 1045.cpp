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

std::vector<double> v(1e6+1);
int solve()
{
    ll n, x,sum=0;
    cin>>n>>x;
    cout<<ll(v[n]/log10(x))+1<<endl;
    
    return 0;
}

int main()
{
    fast;
    double ans=0;
    for (int i = 1; i <= 1e6+1; ++i)
    {
        v[i]=ans+=log10(i);
    }
    ll tc = 1,x=1;cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<x++<<": ";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}