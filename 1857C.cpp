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
    x=(n*(n-1))/2;
    std::vector<ll> v(x);
    for (int i = 0; i < x; ++i)
    {
    	cin>>v[i];
    }
    sort(v.begin(), v.end(),greater<ll>());
    ll l=0;
    for (int i = 0; i < x; i+=l)
    {
    	cout<<v[i]<<" ";
    	l++;
    }
    cout<<v.front()<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;cin>>tc;
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