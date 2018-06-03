#include <bits/stdc++.h>
 
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
 
void merge(pair<pair<ll,ll>,vector<ll>>a,pair<pair<ll,ll>,vector<ll>>b,pair<pair<ll,ll>,vector<ll>>&c){
	c.first.first = (a.first.first + b.first.first)%3;
	for (int i=0;i<3;i++){
		c.second[i] = a.second[i]+b.second[(3-a.first.first+i)%3];
		c.first.second += (c.second[i]*(c.second[i]-1))/2;
	}
	c.first.second += c.second[0];
}
 
void build(string x,vector<pair<pair<ll,ll>,vector<ll>>>&v1,ll l,ll h,ll p){
	if (l == h){
		v1[p].first.first = (x[l]-'0')%3;
		v1[p].second[v1[p].first.first]++;
		if (v1[p].first.first==0)
			v1[p].first.second=1;
		else
			v1[p].first.second=0;
		return;
	}
	ll m = (l+h)>>1;
	build(x,v1,l,m,(p<<1)+1);
	build(x,v1,m+1,h,(p<<1)+2);
	merge(v1[(p<<1)+1],v1[(p<<1)+2],v1[p]);
 
}
 
pair<pair<ll,ll>,vector<ll>> query(vector<pair<pair<ll,ll>,vector<ll>>>&v1,ll ql,ll qh,ll l,ll h,ll p){
	pair<pair<ll,ll>,vector<ll>>p1(mp(mp(0,0),vector<ll>(3,0)));
	if (ql<=l && qh>=h)
		return v1[p];
	else if (ql>h || qh<l)
		return p1;
	ll m = (l+h)>>1;
	merge(query(v1,ql,qh,l,m,(p<<1)+1),query(v1,ql,qh,m+1,h,(p<<1)+2),p1);
	return p1;
}
 
 
void update(vector<pair<pair<ll,ll>,vector<ll>>>&v1,ll ql,ll qh,ll l,ll h,ll p){
 
	if (l==h){
		v1[p].first.first = qh%3;
		v1[p].second = {0,0,0};
		v1[p].second[v1[p].first.first]++;
		if (v1[p].first.first==0)
			v1[p].first.second=1;
		else
			v1[p].first.second=0;
 
		return;	
	}
	ll m = (l+h)>>1;
	if (ql<=m)
		update(v1,ql,qh,l,m,(p<<1)+1);
	else
		update(v1,ql,qh,m+1,h,(p<<1)+2);
	merge(v1[(p<<1)+1],v1[(p<<1)+2],v1[p]);
}
 
 
#ifndef PROD
clock_t stop_s,start_s;
start_s=clock();
#endif
 
 
int main(int argc,char *argv[]){
	ll n,q,a,b,c;
	cin>>n>>q;
	string x,y,z;
	cin>>x;
 
	vector<pair<pair<ll,ll>,vector<ll>>>v1(4*n,mp(mp(0,0),vector<ll>(3,0)));
 
	build(x,v1,0,n-1,0);
	pair<pair<ll,ll>,vector<ll>>p1(mp(mp(0,0),vector<ll>(3,0)));
	for (int i=0;i<q;i++){
		cin>>a>>b>>c;
		if (a==2){
			p1 = query(v1,b-1,c-1,0,n-1,0);
			cout<<p1.first.second<<endl;
		}
		else if (a==1){
			update(v1,b-1,c,0,n-1,0);
		}		
	}
 
}
 
 
#ifndef PROD
stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
#endif
 