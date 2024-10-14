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
    ll n, x,sum=0;
    cin>>n;
    std::vector<ll> cnt(1e6 + 5),mul(1e6 + 5);
    for (int i = 0; i < n; ++i)
    {
    	cin>>x;
    	cnt[x]++;
    }
    for (int i = 1; i <= 1e6; ++i)
    {
    	for (int j = i; j <= 1e6; j+=i)
    	{
    		mul[i]+=cnt[j];
    	}
    }
    for (int i = 0; i < 5; ++i)
    {
    	cout<<mul[i+1]<<endl;
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