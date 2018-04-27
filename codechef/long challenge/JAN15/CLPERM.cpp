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
		ll n,k,x,y,z;
		cin>>n>>k;
		ll arr[k];

		for (int i=0;i<k;i++)
			cin>>arr[i];
		sort(arr,arr+k);
		ll currsum = 0;
		ll currval = 0;
		ll f = 0;
		for (int i=0;i<k;i++){
			currsum += arr[i];
			currval = (arr[i]*(arr[i]+1))/2-currsum;
			if (currval<arr[i]){
				f = 1;
				currval++;
				if (currval%2==0)
					cout<<"Mom"<<endl;
				else
					cout<<"Chef"<<endl;
				break;

			}
		}

		if (f == 0){
			currval = n*(n+1)/2-currsum;
			currval++;
			if (currval%2==0)
				cout<<"Mom"<<endl;
			else
				cout<<"Chef"<<endl;

	}	
		}
}
