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
    unsigned long long n, x,sum=0,m,l,r;
    cin>>n>>m>>l>>r;
    x=(n*m)/__gcd(n,m);
    l=max(l,x);
    if(l%x!=0)
    {
    	l+=(x-(l%x));
    }
    if (l>r)
        return 0;
    cout<<((r-l)/x)+1<<endl;
    return 1;
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
            cout << "0\n";
        }
    }
    return 0;
}