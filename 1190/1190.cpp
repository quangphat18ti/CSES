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

int n, q;
int a[maxn];
struct NODE_IT {
	ll left_max, right_max, sum, ans;
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

NODE_IT combine(NODE_IT L, NODE_IT R) {
	NODE_IT ANS = {0, 0, 0, 0};
	ANS.left_max = max({ L.left_max, L.sum + R.left_max });
	ANS.right_max = max({ R.right_max, L.right_max + R.sum });
	ANS.sum = L.sum + R.sum;
	ANS.ans = max({L.ans, R.ans, L.right_max + R.left_max});
	return ANS;
}

void update(int id, int l, int r, int pos, int value) {
	if(l > pos || r < pos) return;
	if(l == r) {
		IT[id].ans = max(value, 0);
		IT[id].left_max = max(value, 0);
		IT[id].right_max = max(value, 0);
		IT[id].sum = value;
		return;
	}

	int mid = (l + r) >> 1;
	update(id*2, l, mid, pos, value);
	update(id*2+1, mid+1, r, pos, value);

	IT[id] = combine(IT[id*2], IT[id*2+1]);
}

void process_data() {
	FOR_U(i, 1, n) {
		update(1, 1, n, i, a[i]);
	}
}

void solve() {
	while(q--) {
		int pos, value;
		cin >> pos >> value;
		a[pos] = value;
		update(1, 1, n, pos, value);
		cout << IT[1].ans << endl;
	}
}

int main()
{
   file();
   init();
   process_data();
   solve();
}