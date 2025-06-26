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
    ll n, x,sum=0,flg=0;
    cin>>n;
    std::vector<ll> v(n);
    for(unsigned i = 0; i < n; ++i) {
    	cin>>v[i];
    }
    for(unsigned i = 1; i < n; ++i) {
    	if(v[i-1]>v[i]){
    		flg=1;break;
    	}
    }
    if(flg==0)
    {
    	cout<<0<<endl;
    	return 1;
    }
    if(v[n-1]<0 and v[n-2])return 0;
    if(v[n-2]<=v[n-1]){
    	cout<<n-2<<endl;
    	for(unsigned i = 1; i < n-1; ++i) {
    		cout<<i<<" "<<n-1<<" "<<n<<endl;
    	}
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