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
    std::vector<ll> v(n+1);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i+1];
    }

    for (int b = 1,e = n,mn = 1, mx = n; b<e; )
    {
    	if(v[b]==mn){
    		mn++;b++;continue;
    	}
    	if(v[b]==mx){
    		mx--;b++;continue;
    	}
    	if(v[e]==mn){
    		mn++;e--;continue;
    	}
    	if(v[e]==mx){
    		mx--;e--;continue;
    	}
    	cout<<b<<" "<<e<<endl;
    	return 1;
    }
    
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
            cout << "-1\n";
        }
    }
    return 0;
}