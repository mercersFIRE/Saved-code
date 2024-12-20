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

ll zeros(ll n)
{
    ll sum=0;
    for (ll i = 5; n/i>=1; i*=5)
    {
        sum+=n/i;
    }
    return sum;
}
int solve()
{
    ll n, x,sum=0;
    cin>>n;
    //cout<<zeros(n)<<endl;
    ll l=1,r=1e9,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(zeros(mid)>=n)
        {
            sum=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    if(zeros(sum)!=n)return 0;
    cout<<sum<<endl;
    return 1;
}

int main()
{
    fast;
    ll tc = 1,x=1;cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<x++<<": ";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "impossible\n";
        }
    }
    return 0;
}