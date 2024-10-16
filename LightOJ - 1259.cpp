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

const ll N=1e7+7;
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
    ll n, x,sum=0;
    cin>>n;
    std::map<ll, ll> m;
	for (int j = 0; j<prime.size()&& prime[j] <=n/2 ; ++j)
	{
		if(p[n-prime[j]])sum++;
	}
    cout<<sum<<endl;
    return 0;
}

int main()
{
    fast;
    seive();
    ll tc = 1,x=1;cin>>tc;
    while (x<=tc)
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