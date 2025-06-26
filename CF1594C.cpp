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
    ll n, x=0,sum=0;
    string s;
    char c;
    cin>>n>>c>>s;
    set<ll>st;
    for(unsigned i = 0; i < s.size(); ++i) {
    	sum+=s[i]!=c;
    	if(s[i]==c)st.insert(i+1);
    }
    if (sum==0)return 0;
    if(s[n-1]==c){
    	cout<<1<<endl<<n<<endl;
    	return 1;
    }
    for(auto&& i : st) {
    	int flg=0;
    	for(unsigned j = 2; i*j <= n; ++j) {
    		if(st.find(i*j)==st.end()){
    			flg=1;
    			break;
    		}
    	}
    	if(flg==0){
    		cout<<1<<endl<<i<<endl;
    		return 1;
    	}
    }
    cout<<2<<endl<<n<<" "<<n-1<<endl;

    return 1;
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
            cout << "0\n";
        }
    }
    return 0;
}