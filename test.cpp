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
        ll n,q,x,y,z;
        cin>>n>>q;
        ll arr[n];
        for (int i=0;i<n;i++)
            cin>>arr[i];
        
        for (int i=0;i<q;i++){
            cin>>x>>y;
            ll zz = 0;
            for (int j=0;j<n;j++){
                if (j<x-1 || j>y-1){
                    if (zz == 0)
                        zz = arr[j];
                    else 
                        zz = __gcd(zz,arr[j]);
                }
            }
            cout<<zz<<endl;
        }
    }    
}
