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

bool solve(ll a,ll b){
	if (b == 1)
		return 1;
	else if (__gcd(a,b)==1)
		return 0;
	solve(a,b/__gcd(a,b));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if (solve(a,b))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}	
}
