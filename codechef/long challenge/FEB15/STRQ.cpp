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
ll dp[1000002][12];
ll dp2[1000002][4];
 
int main(){
	string x;
	cin>>x;
	ll len = x.size();
	
	ll c=0,h=0,e=0,f=0;
 
	map<string,ll>m1;
	map<char,ll>m2;
	m1["ch"] = 0;
	m1["ce"] = 1;
	m1["cf"] = 2;
	m1["hc"] = 3;
	m1["he"] = 4;
	m1["hf"] = 5;
	m1["ec"] = 6;
	m1["eh"] = 7;
	m1["ef"] = 8;
	m1["fc"] = 9;
	m1["fh"] = 10;
	m1["fe"] = 11;
	m2['c'] = 0;
	m2['h'] = 1;
	m2['e'] = 2;
	m2['f'] = 3;
	for (int i=len-1;i>=0;i--){
		if (x[i] == 'c'){
			c++;
			dp[i][0] += dp[i+1][0]+h;
			dp[i][1] += dp[i+1][1]+e;
			dp[i][2] += dp[i+1][2]+f;
			dp2[i][0] = dp2[i+1][0]+1; 
		}
		else{
			dp[i][0] = dp[i+1][0];
			dp[i][1] = dp[i+1][1];
			dp[i][2] = dp[i+1][2];
			dp2[i][0] = dp2[i+1][0];
		}
 
		if (x[i] == 'h'){
			h++;
			dp[i][3] += dp[i+1][3]+c;
			dp[i][4] += dp[i+1][4]+e;
			dp[i][5] += dp[i+1][5]+f;
			dp2[i][1] = dp2[i+1][1]+1; 
 
		}
		else{
			dp[i][3] = dp[i+1][3];
			dp[i][4] = dp[i+1][4];
			dp[i][5] = dp[i+1][5];
			dp2[i][1] = dp2[i+1][1]; 
		}
 
		if (x[i] == 'e'){
			e++;
			dp[i][6] += dp[i+1][6]+c;
			dp[i][7] += dp[i+1][7]+h;
			dp[i][8] += dp[i+1][8]+f;
			dp2[i][2] = dp2[i+1][2]+1; 
 
		}
		else{
			dp[i][6] = dp[i+1][6];
			dp[i][7] = dp[i+1][7];
			dp[i][8] = dp[i+1][8];
			dp2[i][2] = dp2[i+1][2]; 
 
		}
 
		if (x[i] == 'f'){
			f++;
			dp[i][9] += dp[i+1][9]+c;
			dp[i][10] += dp[i+1][10]+h;
			dp[i][11] += dp[i+1][11]+e;
			dp2[i][3] = dp2[i+1][3]+1; 
		}
		else{
			dp[i][9] = dp[i+1][9];
			dp[i][10] = dp[i+1][10];
			dp[i][11] = dp[i+1][11];
			dp2[i][3] = dp2[i+1][3]; 
 
		}
	}
 
 
 
 
	ll q;
	cin>>q;
	char a,b;
	ll m,n,ans=0,k,z;
	string y;
	for (int i=0;i<q;i++){
		y = "";
		cin>>a>>b>>m>>n;
		y += a;
		y += b;
		k = m1[y];
 		z = m2[b];
 		f = m2[a];
		ans = (dp[m-1][k]-dp[n][k])-(dp2[n][z]*(dp2[m-1][f]-dp2[n][f]));
		cout<<ans<<endl;
	}	
}
 