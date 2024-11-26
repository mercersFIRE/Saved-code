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
ll dectobi(ll n)
{
    ll x=0,a=0;
    while(n)
    {
        if(n&1)x+=1*pow(10,a);
        a++;n/=2;
    }
    return x;
}

int solve()
{
    ll n,sum=0,a,b,c,d,D,A,B,C;
    char x;
    cin>>a>>x>>b>>x>>c>>x>>d>>A>>x>>B>>x>>C>>x>>D;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl<<A<<" "<<B<<" "<<C<<" "<<D<<endl;   
    return (dectobi(a)==A && dectobi(b)==B && dectobi(c)==C && dectobi(d)==D);
}

int main()
{
    fast;
    ll tc = 1,x=0;cin>>tc;
    while (x++<tc)
    {
        cout<<"Case "<<x<<": ";
        if (solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}