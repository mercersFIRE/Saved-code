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
void seive(vector<ll> &p)
{
    vector<bool> prime(N);
    for (ll i = 2; i*i<N; ++i)
    {
        if(prime[i]==0)
            for (ll j = i*i; j < N; j+=i)
                prime[j]=1;
    }
    for (int i = 2; i <= N; ++i)
        if(!prime[i])p.pb(i);
}

int solve()
{
    ll n, x,sum=0;
    cin>>n;
    std::vector<ll> p,v(n);
    seive(p);
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
        x=v[i];
        map<ll, ll> m;
        for (int j = 0; j < p.size()&&p[j]*p[j]<=x; ++j)
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
            divsum*=(pow(y.ff,y.ss+1)-1)/(y.ff-1);
        }
        cout<<divsum-x<<endl;
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