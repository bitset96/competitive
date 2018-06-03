#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define m 1000000007

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

ll power(ll a,ll b,ll p){
	a = a%p;
	ll res=1;
	while(b>0){
		if (b&1)
			res = (res*a)%p;
		b>>=1;
		a = (a*a)%p;
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];

		for (int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);

		ll ans=0;
		ll sum=0;
		ll k=0;

		for (int i=n-1;i>=0;i--){
			ans = ((ans%m)+((arr[i]%m)*(power(2,i,m)%m))%m)%m;
			sum = ((sum%m)+((arr[i]%m)*(power(2,k,m)%m))%m)%m;
			k++;
		}
		ans = (ans+m-sum)%m;
		cout<<ans<<endl;


	}	
}
