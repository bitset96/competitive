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
	ll a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;

	ll sum = b;
	if (sum>=a){
		cout<<1<<endl;
		return 0;
	}
	sum -= e;
	ll f = d;
	while(1){
		if (sum+d<=c){
			sum += sum+d;
		}
		else
			sum +=c ;
		ans++;
		d += f;
		if (sum>=a){
			cout<<ans<<endl;
			return 0;
		}
	}	
}
