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
    ll n, x,sum=0;
	string s;
    cin>>s;
    for (int i = 0; i+1 < s.size(); ++i)
    {
    	if (s[i]==s[i+1])
    	{
    		cout<<s[i]<<s[i+1]<<endl;
    		return 1;
    	}
    }
    for (int i = 0; i+2 < s.size(); ++i)
    {
        if (s[i]!=s[i+2])
        {
            cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
            return 1;
        }
    }
    return 0;
}

int main()
{
    fast;
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}