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

ll fun(ll x)
{
	return (x/4)-(x/100)+(x/400);
}

int solve()
{
    ll n, x,sum=0,d,y;
    string s;char c;
    std::map<string, ll> m;
    m["January"]=0;
    m["February"]=1;
    m["March"]=2;
    m["April"]=3;
    m["May"]=4;
    m["June"]=5;
    m["July"]=6;
    m["August"]=7;
    m["September"]=8;
    m["October"]=9;
    m["November"]=10;
    m["December"]=11;
    cin>>s>>d>>c>>y;
    sum=m[s]*30+d;
    n=sum<=59?y:y+1;
    cin>>s>>d>>c>>y;
    sum=m[s]*30+d;
    x=sum>=59?y:y-1;
    //cout<<n<<" "<<x<<endl;
    cout<<fun(x)-fun(n-1)<<endl;

    
    return 0;
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
            //cout << "No\n";
        }
    }
    return 0;
}