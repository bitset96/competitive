#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,x,y,z;
		cin>>n;
		vector<pair<ll,ll>>v1;

		for (int i=0;i<n;i++){
			cin>>x>>y;
			v1.pb(mp(y,x));
		}
		sort(v1.begin(),v1.end());

		x = v1[0].first;
		ll ans = 1;
		for (int i=1;i<n;i++){
			if (v1[i].second>x){
				ans++;
				x = v1[i].first;
			}
		}
		cout<<ans<<endl; 
	}	
}
