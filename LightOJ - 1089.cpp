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

const ll N=1e8+7;

int solve()
{
    ll n, x,sum=0,a,b;
    cin>>n>>x;
    std::map<ll, ll> m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a>>b;
    	m[a]++;
    	m[b+1]--;
    }
    for(auto&& i : m) {
        i.ss+=sum;
        sum=i.ss;
    }
    for (int i = 0; i < x; ++i)
    {
    	cin>>n;
    	cout<<(--m.upper_bound(n))->ss<<endl;
    }
    
    return 0;
}

int main()
{
    fast;
    ll tc = 1,x=0;cin>>tc;
    while (tc--)
    {
        cout<<"Case "<<++x<<": \n";
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            //cout << "No\n";
        }
    }
    return 0;
}