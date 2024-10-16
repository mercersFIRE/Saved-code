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
vector<ll>prime;
vector<bool> p(N,1);
void seive()
{
    p[1]=0;
    for (ll i = 2; i*i<N; ++i)
    {
        if(p[i])
            for (ll j = i*i; j < N; j+=i)
                p[j]=0;
    }
    for (int i = 2; i <= N; ++i)
        if(p[i])prime.pb(i);
}

int solve()
{
    ll n, x,sum=1,a,b;
    cin>>a>>b;
    n= __gcd(a,b);
    while(n>1) {
        b/=n;
        n=__gcd(n,b);
    }

    
    return b==1;
}

int main()
{
    fast;
    seive();
    ll tc = 1,x=1;cin>>tc;
    while (tc--)
    {
        //cout<<"Case "<<x++<<": ";
        if (solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}