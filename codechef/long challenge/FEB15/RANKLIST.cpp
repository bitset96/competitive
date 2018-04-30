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
		ll n,k;
		cin>>n>>k;
		ll sum = (n*(n+1))/2;
		ll s = sum-k;
		ll c = 0;
		while(s > 0){
			s -= (n-1);
			c++;
			n--;
		}
		cout<<c<<endl;
	}	
}
