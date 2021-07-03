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

#define LT ""
#define maxn 200005

int n, num_q;
int a[maxn];
int ans[maxn];
int link[maxn];
int Fenwick_tree[2][maxn];

struct QUERY {
	int left, right, index;
};
QUERY q[maxn];

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}

void init() {
	cin >> n >> num_q;
	FOR_U(i, 1, n) cin >> a[i];
	FOR(i, num_q) {
		cin >> q[i].left >> q[i].right;
		q[i].index = i;
	}
}

bool compare_QUERY(QUERY A, QUERY B) {
	return A.left < B.left || (A.left == B.left && A.right < B.right);
}

void build_link() {
	map <int, int> position;
	FOR_D(i, n, 1) {
		int value = a[i];
		link[i] = position[value];
		position[value] = i;
	}
}

void update(int pos, int value) {
	Fenwick_tree[1][pos] += value;
	while(pos <= n) {
		Fenwick_tree[0][pos] += value;
		pos += (pos & -pos);
	}
}

int get(int left, int right) {
	int ans = 0;
	while(right >= left) {
		int leng = right & (-right);
		if(right - leng + 1 >= left) {
			ans += Fenwick_tree[0][right];
			right -= right & -right;
		}
		else {
			ans += Fenwick_tree[1][right];
			right--;
		}
	}
	return ans;
}

void build_initial_value() {
	vi dd(n + 1, 0);
	FOR_U(i, 1, n) {
		if(dd[i] == 0) {
			update(i, 1);
		}
		dd[link[i]] = 1;
	}
}

void process_data() {
	sort(q, q+num_q, compare_QUERY);
	build_link();
	build_initial_value();
}

void solve(){
	int pos = 1;
	FOR(i, num_q) {
		int left = q[i].left;
		int right = q[i].right;
		while(pos < left) {
			int position_link = link[pos];
			update(pos, -1);
			if(position_link) update(position_link, 1);
			pos++;
		} 

		ans[q[i].index] = get(left, right);
	}

	FOR(i, num_q) {
		cout << ans[i] << endl;
	}
}

int main()
{
   file();
   init();
   process_data();
   solve();
}