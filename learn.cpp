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
    ll n, x,sum=0;
    cin>>n;
    std::vector<ll> v(n);
    std::vector<pair<ll,ll>> a;
    for (int i = 0; i < n; ++i)
    {
        cin>>v[i];
        a.pb({abs(v[i]), i});
    }
    sort(a.begin(), a.end());
    double m;
    for (int i = 1; i < n; ++i)
    {
        if(i<(n-1) and v[a[i].ss]*v[a[i].ss] != v[a[i-1].ss]*v[a[i+1].ss]) return 0;
        if(i==1)m= (1.0*v[a[i].ss])/v[a[i-1].ss];
        else
            if((1.0*v[a[i].ss])/v[a[i-1].ss] !=m ) return 0;
    }

    
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        if (solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}