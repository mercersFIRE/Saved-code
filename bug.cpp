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

int solve()
{
    ll n, x,sum=0,div=1,divsum=1;
    cin>>n;
    std::vector<ll> v(n),prime(1000006),p;
    for (ll i = 2; i<= 1e6; ++i)
    {
    	if(prime[i]==0)
    	{
			for (ll j = i+i; j <= 1e6; j+=i)
			{
				prime[j]++;
			}
    	}
    }
    for (int i = 2; i <= 1e6; ++i)
    {
    	if(!prime[i])p.pb(i);
    }
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
        map<ll, ll> m;
        for (int j = 0; j < p.size()&&p[j]<=x; ++j)
        {
            while(v[i]%p[j]==0)
            {
                m[p[j]]++;v[i]/=p[j];
            }
        }
        if(v[i]>1)m[v[i]]++;
        ll sum=0,div=1,divsum=1;
        for(auto y:m)
        {
            sum+=y.ss;
            div*=(y.ss+1);
            divsum*=(pow(y.ff,y.ss+1)-1)/(y.ff-1);
        }
        cout<<m.begin()->ff<<" "<<(--m.end())->ff<<" "<<m.size()<<" "<<sum<<" "<<div<<" "<<divsum<<endl;
    }
    
    return 0;
}

int main()
{
    fast;
    ll tc = 1;//cin>>tc;
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