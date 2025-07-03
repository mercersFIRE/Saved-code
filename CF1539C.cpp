#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
using namespace std;
typedef long long ll;

const ll N=1e6+7;

int solve()
{
    ll n, x,sum=0,k,last,a;
    cin>>n>>k>>x;
    std::vector<ll> v(n);
    multiset<ll>s;
    
    for(unsigned i = 0; i < n; ++i) cin>>v[i];
    sort(v.begin(), v.end());
    for(unsigned i = 1; i < n; ++i) s.insert(v[i]-v[i-1]);

    while(s.size() and *s.begin()<=x) s.erase(s.begin());
    for(unsigned i = 0; s.size(); ++i) {
    	a=*s.begin();
        ll req=((a + x - 1) / x)-1;
        if(req>k)break;
        k-=req;
        s.erase(s.begin());
    }

    cout<<1+s.size()<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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