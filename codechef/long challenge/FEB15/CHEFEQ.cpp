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
		ll dp[100001];
		fill(dp,dp+100001,0);
		ll n,x,y,z;
		cin>>n;
		ll arr[n];
		ll m = INT_MIN;
		ll s;
		for (int i=0;i<n;i++){
			cin>>x;
			dp[x]++;
			if (dp[x]>m){
				m = dp[x];
				s = x;
			}
		}
		cout<<n-m<<endl;
	}	
}
