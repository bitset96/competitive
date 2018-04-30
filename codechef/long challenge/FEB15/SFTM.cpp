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

ll fact[10000001];
int main(){
	ll n,m,a,b,c,d,x;
	cin>>n>>m;

	ll arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];

	fact[0] = 1;
	for (int i=1;i<1000001;i++)
		fact[i] = ((fact[i-1]%m)*(i%m))%m;
	ll sum1;
	ll sum2;
	ll ans = 0;
	for (int i=0;i<n;i++){
		x = arr[i];
		if (x>=m)
			sum1 = -1;
		else
			sum1 = fact[x+1]-1;

		if (x%2 == 0){
			a = x/2;
			sum2 = (a%m)*((x+1)%m)%m;
			sum2 = ((sum2%m)*(x%m))%m;
		}
		else{
			a = (x+1)/2;
			sum2 = ((a%m)*(x%m))%m;
			sum2 = ((sum2%m)*(x%m))%m;
		}
		ans = ((ans%m)+(sum1%m)+(sum2%m))%m;

	}	
	cout<<ans<<endl;


}
