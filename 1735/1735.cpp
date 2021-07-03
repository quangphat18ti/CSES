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

#define LT "1735"
#define maxn 200005

int n, q;
int a[maxn];

struct NODE_IT {
	ll sum_value = 0;
	ll lazy_sum = 0;
	ll lazy_value = 0;
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

void pushid(int id, int l, int mid, int r) {
	ll val = 0;

	if(IT[id].lazy_value > 0) {
		val = IT[id].lazy_value;   IT[id].lazy_value = 0;
		
		IT[id*2].lazy_value = val;
		IT[id*2].lazy_sum = 0;
		IT[id*2].sum_value = 1ll * val * (mid - l + 1);

		IT[id*2+1].lazy_value = val; 
		IT[id*2+1].lazy_sum = 0; 
		IT[id*2+1].sum_value = 1ll * val * (r - mid);
	}

	val = IT[id].lazy_sum;    IT[id].lazy_sum = 0;

	IT[id*2].lazy_sum += val;
	IT[id*2].sum_value += 1ll * val * (mid - l + 1);

	IT[id*2+1].lazy_sum += val;
	IT[id*2+1].sum_value += 1ll * val * (r - mid);
}

void update_plus_value(int id, int l, int r, int u, int v, int value) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		IT[id].lazy_sum += value;
		IT[id].sum_value += 1ll * value * (r - l + 1);
		return;
	}

	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	update_plus_value(id*2, l, mid, u, v, value);
	update_plus_value(id*2+1, mid + 1, r, u, v, value);

	IT[id].sum_value = IT[id*2].sum_value + IT[id*2+1].sum_value;
}

void update_set_value(int id, int l, int r, int u, int v, int value) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		IT[id].sum_value = 1ll * value * (r - l + 1);
		IT[id].lazy_value = value;
		IT[id].lazy_sum = 0;
		return;
	}

	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	update_set_value(id*2, l, mid, u, v, value);
	update_set_value(id*2+1, mid+1, r, u, v, value);

	IT[id].sum_value = IT[id*2].sum_value + IT[id*2+1].sum_value;
}

ll get_sum(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return IT[id].sum_value;
	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	ll res1 = get_sum(id*2, l, mid, u, v);
	ll res2 = get_sum(id*2 + 1, mid+1, r, u, v);

	IT[id].sum_value = IT[id*2].sum_value + IT[id*2 + 1].sum_value;
	return res1 + res2;
}

void process_data() {
	FOR_U(i, 1, n) {
		update_plus_value(1, 1, n, i, i, a[i]);
	}
}

void solve_1() {
	int l, r, x; cin >> l >> r >> x;
	update_plus_value(1, 1, n, l, r, x);
}

void solve_2() {
	int l, r, x; cin >> l >> r >> x;
	update_set_value(1, 1, n, l, r, x);
}

void solve_3() {
	int l, r; cin >> l >> r;
	cout << get_sum(1, 1, n, l, r) << endl;
}

void solve() {
	while(q--) {
		int type; cin >> type;
		if(type == 1)  solve_1();
		else if(type == 2) solve_2();
		else solve_3();
	}
}

int main()
{
   file();
   init();
   process_data();
   solve();
}