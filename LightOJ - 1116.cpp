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
    ll n, x,sum=1;
    cin>>n;
    x=n;
    while(n%2==0)
    {
    	sum*=2;
    	n/=2;
    }
    if (sum==1)
    {
    	return 0;
    }
    cout<<x/sum<<" "<<sum<<endl;
    return 1;
}

int main()
{
     fast;
    ll tc = 1,x=0;cin>>tc;
    while (x<tc)
    {
        cout<<"Case "<<++x<<": ";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "Impossible\n";
        }
    }
    return 0;
}