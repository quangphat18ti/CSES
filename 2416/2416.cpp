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

#define LT "2416"
#define maxn 200005

const int oo = 1e9 + 7;

vector<int> a;
vector<ll> sum;
vector<int> cover_range;

struct QUERY {
	int l, r, index;

	bool operator < (QUERY A) {
		return l > A.l || (l == A.l && r < A.r);
	}
};
vector<QUERY> q;

struct IT_NODE{
	int Max, lazy;
	ll ans;
};
IT_NODE IT[maxn * 4];

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}                                       

void init() {
	int n, m; cin >> n >> m;
	FOR(i, n) {
		int x; cin >> x; a.push_back(x);
	}

	FOR(i, m) {
		int l, r, index = i;
		cin >> l >> r;
		l--, r--;
		q.push_back({l, r, index});
	}
}

vector<int> create_largest_cover_range(vector<int> &a) {
	int n = a.size();
	stack <pii> Max;
	vector<int> ans(n, -1);

	Max.push( {oo, -1} );
	FOR(i, n) {
		int value = a[i];
		while(Max.top().fi <= value) {
			int pos = Max.top().second;
			ans[pos] = i - 1;
			Max.pop();
		}

		Max.push({a[i], i});
	} 

	for(int &tam : ans) {
		if(tam == -1) tam = n - 1;
	}
	return ans;
}

vector<ll> create_sum_vector(vector<int> &a) {
	vector<ll> ans;
	ll sum = 0;
	for(int tam : a) {
		sum += tam;
		ans.push_back(sum);
	}
	return ans;
} 

void process_data() {
	sort(all(q));
	cover_range = create_largest_cover_range(a);
	sum = create_sum_vector(a);
}

void pushid(int id, int l, int mid, int r) {
	if(IT[id].lazy == 0) return;
	int maxx = IT[id].lazy; 
	IT[id].lazy = 0;

	if(maxx > IT[id * 2].Max) {
		IT[id * 2].Max = maxx;
		IT[id * 2].lazy = maxx;
		IT[id * 2].ans = 1ll * maxx * (mid - l + 1);
	}

	if(maxx > IT[id*2+1].Max) {
		IT[id*2+1].Max = maxx;
		IT[id*2+1].lazy = maxx;
		IT[id*2+1].ans = 1ll * maxx * (r - mid);
	}
} 

void update(int id, int l, int r, int u, int v, int value) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		IT[id].lazy = max(IT[id].lazy, value);
		IT[id].Max = value;
		IT[id].ans = 1ll * value * (r - l + 1);
		return;
	}

	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	update(id*2, l, mid, u, v, value);
	update(id*2+1, mid+1, r, u, v, value);

	IT[id].ans = IT[id*2].ans + IT[id*2+1].ans;
}

ll get(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return 0;
	if(l >= u && r <= v) return IT[id].ans;

	int mid = (l + r) >> 1;
	pushid(id, l, mid, r);

	return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

ll get_sum(int l, int r) {
	ll ans = sum[r];
	if(l > 0) ans -= sum[l - 1];
	return ans;
}

void solve(){
	/// Các truy vấn đã được sắp xếp theo đầu l
	vector<ll> ans(q.size(), 0);
	int pointer = a.size(), n = a.size();
	
	for(auto tam : q) {
		int l = tam.l, r = tam.r;

		while(pointer > l) {
			pointer--;
			int range_pointer = cover_range[pointer];
			update(1, 0, n - 1, pointer, range_pointer, a[pointer]);
		}

		ans[tam.index] = get(1, 0, n - 1, l, r) - get_sum(l, r);
	}

	for(ll tam : ans) cout << tam << ' '; cout << endl;
}

int main()
{
   file();
   init();
   process_data();
   solve();
}