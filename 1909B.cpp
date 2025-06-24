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
    ll n, x=2,sum=0;
    cin>>n;
    std::vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    }
    while(1) {
    	set<ll>s;
	    for(auto&& i : v) {
	    	s.insert(i%x);
	    }
	    if(s.size()==2){
	    	cout<<x<<endl;
	    	return 0;
	    }
	    x*=2;
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
            //cout << "No\n";
        }
    }
    return 0;
}