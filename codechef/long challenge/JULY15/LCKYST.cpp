#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
typedef unsigned long long ull;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector<si> vsi;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<string,vs> msvs;
typedef map<string,int> msi;
typedef map<string,string> mss;
typedef map<int,bool> mib;
 
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i = (a), _b = (b); i < _b; i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
#define DEBUG1(s,c) cout << s << c << endl
 
#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()
 
static struct IO {
	char tmp[1 << 10];
 
	// fast input routines
	char cur;
 
//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }
 
	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { 
		while (isBlank(nextChar())); 
		return peekChar() != 0; 
	}
 
	inline IO& operator >> (char & c) { c = nextChar(); return *this; }
 
	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }
 
	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }
 
	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}
 
#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}
 
defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)
 
	// fast output routines
 
//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { 
		while (*s) putChar(*s++); 
		return *this; 
	}
 
	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }
 
	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }
 
 
#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }
 
defineOutFor(int)
defineOutFor(ll)
defineOutFor(ull)
 
#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
 
#define PROD //clocking off
 
#ifndef PROD
clock_t stop_s,start_s;
start_s=clock();
#endif
 
 
int main(int argc,char *argv[]){
	ll n,a,b,mul;
	cin>>n;
	ll arr[n];
	for (int i=0;i<n;i++)
		cin>>arr[i];
	ll c=0;
	ll d=0;
	ll ans;
	for (int i=0;i<n;i++){
		a = arr[i];
		b = a;
		c=0;
		d=0;
		while(a%5==0){
			c++;
			a /= 5;
		}
		while(a%2==0){
			d++;
			a /= 2;
		}
	
		mul=1;
		if (c>d){
			if ((c-d)%2 == 0)
				mul = pow(4,(c-d)/2);
			else
				mul = pow(4,(c-d)/2+1);
		}
		ans = b*mul;
		cout<<ans<<endl;
	}	
}
 
 
#ifndef PROD
stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
#endif