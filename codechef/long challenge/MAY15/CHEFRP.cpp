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
		ll n;
		cin>>n;
		ll arr[n];
		for (int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		ll f=0;
		ll sum=0;
		for (int i=0;i<n;i++){
			if (arr[i]==1){
				cout<<-1<<endl;
				f=1;
				break;
			}
			else
				sum += arr[i];
		}
		if (f==0)
			cout<<(sum-arr[0])+2<<endl;
	}	
}
