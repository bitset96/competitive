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
        ll n,q;
        cin>>n>>q;
        ll arr[n];

        for (int i=0;i<n;i++)
            cin>>arr[i];

        ll pre[n];
        ll suff[n];
        pre[0] = arr[0];
        suff[n-1] = arr[n-1];

        for (int i=1;i<n;i++)
            pre[i] = __gcd(pre[i-1],arr[i]);

        for (int i=n-2;i>=0;i--)
            suff[i] = __gcd(suff[i+1],arr[i]);
        /*for (int i=0;i<n;i++)
            cout<<pre[i]<<" ";
        cout<<endl;
        for (int i=0;i<n;i++)
            cout<<suff[i]<<" ";*/
        ll m,x,y,z;
        for (int i=0;i<q;i++){
            cin>>x>>y;
            if (x>1)
                m = pre[x-2];
            else
                m = 0;

            if (y < n)
                z = suff[y];
            else
                z = 0;

            ll ans = __gcd(m,z);
            cout<<ans<<endl;

        }
    }    
}
