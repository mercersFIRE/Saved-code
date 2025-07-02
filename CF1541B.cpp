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
    vector<pair<ll,ll>>v;
    for(unsigned i = 0; i < n; ++i) {
    	cin>>x;
    	v.pb({x,i+1});
    }
    sort(v.begin(), v.end()	);
    for(unsigned i = 0; i < n; ++i) {
    	for(unsigned j = i+1; j <n and v[i].ff*v[j].ff<=(2*n) ; ++j) {
    		if(v[i].ff*v[j].ff==v[i].ss+v[j].ss)sum++;
    	}
    }
    cout<<sum<<endl;
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