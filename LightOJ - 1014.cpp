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
    ll n, x,sum=0,a,b;
    cin>>a>>b;
    n=a-b;
    set<ll>s;
    for (ll i = 1; i*i <= n; ++i)
    {
    	if(n%i==0)
    	{
            if(i>b)
    		s.insert(i);
    		if((i!=n/i) and (n/i)>b)s.insert(n/i);
    	}
    }
    if(!s.size())return 0;
    for(auto x:s)cout<<x<<" ";
    	cout<<endl;
    return 1;
}

int main()
{
    fast;
    ll tc = 1,x=1;cin>>tc;
    while (x<=tc)
    {
        cout<<"Case "<<x<<": ";
        x++;
        if (solve()){
            //cout << "Yes\n";
        }
        else{
            cout << "impossible\n";
        }
    }
    return 0;
}