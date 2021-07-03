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

#define LT "1736"
#define maxn 200005

int n, q;
ll a[maxn];

struct NODE_IT{
	ll num_plus;
	ll sum_value;
	ll lazy_value;
};
NODE_IT IT[maxn * 4];

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}

void init() {
	cin >> n >> q;
	FOR_U(i, 1, n) cin >> a[i];
}

ll Calc(ll start, ll len, ll Time) {
	ll finish = start + (len - 1) * Time;
	return (start + finish) * len / 2;
} 

void pushid(int id, int l, int mid, int r) {
	if(IT[id].num_plus == 0) return;

	ll value = IT[id].lazy_value; IT[id].lazy_value = 0;
	ll Time = IT[id].num_plus; IT[id].num_plus = 0;

	IT[id * 2].lazy_value += value;
	IT[id * 2].num_plus += Time;
	IT[id * 2].sum_value += Calc(value, mid - l + 1, Time) ;

	IT[id * 2 + 1].lazy_value += value + (mid + 1 - l) * Time;
	IT[id * 2 + 1].num_plus += Time;
	IT[id * 2 + 1].sum_value += Calc(value + (mid + 1 - l) * Time, r - mid, Time);
}

void update_range(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return;
	if(l >= u  && r <= v) {
		IT[id].num_plus++;
		IT[id].lazy_value += l - u + 1;
		IT[id].sum_value += Calc(l - u + 1, r - l + 1, 1);
		return;
	}

	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	update_range(id*2, l, mid, u, v);
	update_range(id*2 + 1, mid + 1, r, u, v);

	IT[id].sum_value = IT[id * 2].sum_value + IT[id*2+1].sum_value;
}

ll get_range(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return IT[id].sum_value;
	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);
	return get_range(id*2, l, mid, u, v) + get_range(id*2+1, mid + 1, r, u, v);  
}

void build(int id, int l, int r) {
	if(l == r) {
		IT[id].sum_value = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id*2, l, mid);
	build(id*2+1, mid + 1, r);
	IT[id].sum_value = IT[id*2].sum_value + IT[id*2+1].sum_value;
}

void solve1() {
	int l, r; cin >> l >> r;
	update_range(1, 1, n, l, r);
}

void solve2() {
	int l, r; cin >> l >> r;
	cout << get_range(1, 1, n, l , r) << endl;
}

void solve() {
	while(q--) {
		int type; cin >> type;
		if(type == 1) solve1();
		else solve2();
	}
}

int main()
{
   file();
   init();
   build(1, 1, n);
   solve();
}