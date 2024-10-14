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
vector<ll>prime;
void seive()
{
    vector<bool> p(N);
    for (ll i = 2; i*i<N; ++i)
    {
        if(p[i]==0)
            for (ll j = i*i; j < N; j+=i)
                p[j]=1;
    }
    for (int i = 2; i <= N; ++i)
        if(!p[i])prime.pb(i);
}

int solve()
{
    ll n, x,sum=0;
    string s,t;
    cin>>s>>t;
    for (int i = 0; i < s.size() and t.size() and s[i]==t[i]; ++i)
    {
    	sum++;
    }

    cout<<s.size()+t.size()-(sum?sum-1:0)<<endl;
    
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
            //cout << "No\n";
        }
    }
    return 0;
}