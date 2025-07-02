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
    string s;
    cin>>n>>x>>s;
    for(unsigned i = 0; i < n; ++i) {
        sum+=s[i]=='1';
    }

    return sum<=x||(x*2)>n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;cin>>tc;
    while (tc--)
    {
        if (solve()){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}