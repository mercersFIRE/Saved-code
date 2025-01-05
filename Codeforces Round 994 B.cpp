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
    ll n, x,sum=0,a=0,b=0;
    string s;
    cin>>n>>s;
    std::vector<ll> v(n);
    for (int i = 0; i < s.size(); ++i)
    {
    	if(s[i]=='s')a=1;
    	if(s[i]=='p')b=1;
    }
    std::map<ll, ll> m;
    if((a+b)<2)return 1;
    for (int i = 0; i < s.size(); ++i)
    {
    	if(s[i]=='s')sum++;
    	v[i]+=sum;
        m[sum]++;
    }
    sum=0;
    for (int i = n-1; i >=0; --i)
    {
        if(s[i]=='p')sum++;
    	if (v[i]==0 and sum)
    	{
    		return 0;
    	}
        v[i]+=sum;
    }
    

    return 1;
}

int main()
{
    fast;
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        if (solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}