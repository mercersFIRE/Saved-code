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
    ll n, x,sum=0;
    cin>>n;
    std::map<ll, ll> m;
    for (int i = 2; i <= n; ++i)
    {
    	x=i;
    	for (int j = 0; j<prime.size()&& prime[j]*prime[j] <=x ; ++j)
    	{
    		while(x%prime[j]==0)
    		{
    			m[prime[j]]++;
    			x/=prime[j];
    		}
    	}
    	if(x>1)m[x]++;
    }
    cout<<n<<" = ";
    for(auto&& i : m) {
    	cout<<(i.ff==2?"":"* ")<<i.ff<<" ("<<i.ss<<") ";
    }
    cout<<endl;
    
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