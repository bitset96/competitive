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
        ll n,q,x,y;
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
        for (int i=n-1;i>=0;i--)
            cout<<suff[i]<<" ";
        cout<<endl;*/

        for (int i=0;i<q;i++){
            cin>>x>>y;
            ll g,h;
            if (x-1 == 0)
                g = 0;
            else 
                g = pre[x-2];

            if (y == n)
                h = 0;
            else
                h = suff[y];

            if (g == 0 && h == 0)
                cout<<1<<endl;
            else if (g == 0)
                cout<<h<<endl;
            else if (h == 0)
                cout<<g<<endl;
            else{
                ll ans = __gcd(g,h);
                cout<<ans<<endl;
            }
        }


    }    
}
