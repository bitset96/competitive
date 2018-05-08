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
		ll x,y,k,n,a,b;
		cin>>x>>y>>k>>n;
		vector<pair<ll,ll>>v1;
		for (int i=0;i<n;i++){
			cin>>a>>b;
			v1.pb(mp(a,b));
		}
		if (x <= y){
			cout<<"LuckyChef"<<endl;
			continue;
		}
		ll f = 0;
		for (int i=0;i<v1.size();i++){
			if (v1[i].first>=(x-y) && v1[i].second<=k){
				cout<<"LuckyChef"<<endl;
				f = 1;
				break;
			}
		}
		if (f == 0){
			cout<<"UnluckyChef"<<endl;
		}
	}	
}
