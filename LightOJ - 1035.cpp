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
    for (int i = 2; i < N; ++i)
        if(p[i])prime.pb(i);
}

int solve()
{
    ll n, x,sum=1,a;
    cin>>n;
    for (int i = 0; i < prime.size() and prime[i]<=n; ++i)
    {
        ll cnt=0;
        for (int j = prime[i]; j <= n; j+=prime[i])
        {
            x=j;
            while(x%prime[i]==0)
            {
        	   cnt++;
               x/=prime[i];
            }
        }
        sum=(sum*(cnt+1))%mod;
    }

    cout<<sum<<endl;
    
    return 1;
}

int main()
{
    fast;
    seive();
    ll tc = 1,x=1;//cin>>tc;
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