#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(A) int( A.size() )
#define ms( f, a, b, gt ) fill( f+a , f+b+1 , gt )
#define all(a) a.begin(), a.end()

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

#define FOR(i, a) for(int i = 0; i < int(a); i++)
#define FOR_U(i, a, b) for(int i = int(a); i <= int(b); i++)
#define FOR_D(i, a, b) for(int i = int(a); i >= int(b); i--)

#define LT "2206"
#define maxn 200005

int n, q, vc = 1e9;
int a[maxn];
int IT[2][maxn * 4];

/// IT[0] là lowwer
/// IT[1] là higher

void file() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(LT".inp", "r", stdin);
	// freopen(LT".out", "w", stdout);
}

void build(int id, int l, int r) {
	if(l == r) {
		IT[0][id] = IT[1][id] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r); 
	IT[0][id] = min( IT[0][id * 2] + r - mid, IT[0][id*2+1] );
	IT[1][id] = min( IT[1][id * 2] , IT[1][id * 2 + 1] + mid - l + 1 );
}

void update(int id, int l, int r, int pos, int value) {
	if(r < pos || l > pos) return;
	if(l == r) {
		IT[0][id] = IT[1][id] = value;
		return;
	}
	int mid = (l + r) >> 1;

	update(id*2, l, mid, pos, value);
	update(id*2+1, mid+1, r, pos, value);

	IT[0][id] = min( IT[0][id * 2] + r - mid, IT[0][id*2+1] );
	IT[1][id] = min( IT[1][id * 2] , IT[1][id * 2 + 1] + mid - l + 1 );
}

int get_lower(int id, int l, int r, int u, int v) {
	if(l >= u && r <= v)  return IT[0][id] + v - r;
	if(l > v || r < u) return vc;
	int mid = (l + r) >> 1;
	return min(get_lower(id*2, l, mid, u, v), get_lower(id*2+1, mid+1, r, u, v));
}

int get_higher(int id, int l, int r, int u, int v) {
	if(l >= u && r <= v) {
		return IT[1][id] + l - u;
	}
	if(l > v || r < u) return vc;
	int mid = (l + r) >> 1;
	return min(get_higher(id*2, l, mid, u, v), get_higher(id*2+1, mid+1, r, u, v));
}

void init() {
	cin >> n >> q;
	FOR_U(i, 1, n) cin >> a[i];
	build(1, 1, n);
}

void solve1() {
	int pos, value;
	cin >> pos >> value;
	update(1, 1, n, pos, value);
}

void solve2() {
	int pos; cin >> pos;
	cout << min(get_higher(1, 1, n, pos, n), get_lower(1, 1, n, 1, pos)) << endl;
}

int main()
{
   file();
   init();
   while(q--) {
	int type; cin >> type;
	if(type == 1) solve1();
	else solve2();
   }
}