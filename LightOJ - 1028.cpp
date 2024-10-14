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

const ll N=1e6 +6;
void seive(vector<ll> &p)
{
    vector<bool> prime(N);
    for (ll i = 2; i<sqrt(N); ++i)
    {
        if(prime[i]==0)
            for (ll j = i*i; j < N; j+=i)
                prime[j]=1;
    }
    for (int i = 2; i <= N; ++i)
        if(!prime[i])p.pb(i);
}

int solve(std::vector<ll> &prime)
{
    ll n, x,sum=1;
    cin>>n;
    
    std::map<ll, ll> m;
    for (ll i = 0; i < prime.size() and prime[i]*prime[i]<=n; ++i)
    {
        ll cnt=0;
    	while(n%prime[i]==0)
    	{
    		cnt++;
    		n/=prime[i];
    	}
        sum*=(cnt+1);
    }
    if(n>1){
        m[n]++;
        sum*=2;
    }
    cout<<sum-1<<endl;
    return 0;
}

int main()
{
    fast;
    std::vector<ll> prime;
    seive(prime);
    ll tc ,x=1;cin>>tc;
    while (x<=tc)
    {
    	cout<<"Case "<<x++<<": ";
        if (solve(prime)){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}