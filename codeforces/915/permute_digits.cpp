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
	ll n,m,a,b,c,d;
	cin>>n>>m;
	string x,y,z,t;
	x = to_string(n);
	ll len = x.size();
	ll max=INT_MIN;
	t = x;
	for (int i=0;i<len;i++){
		for (int j=i;j<len;j++){
			swap(t[i],t[j]);
			y = t;
			sort(y.begin()+i+1,y.end());
			a = stoll(y);
			if (a>max && a<=m){
				max = a;
				z = y;
			}
			swap(t[i],t[j]);
		}
		t = z;
	}
	cout<<max<<endl;

}
