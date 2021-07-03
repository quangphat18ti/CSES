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

#define LT "2166"
#define maxn 200005 

int n, q;
int a[maxn];

struct NODE_IT{
	ll ans, all;

	void combine(NODE_IT U, NODE_IT V) {
		all = U.all + V.all;
		ans = max(U.ans, U.all + V.ans);
	}
};
NODE_IT IT[maxn * 4], answer;

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}

void update(int id, int l, int r, int pos, int value) {
	if(r < pos || l > pos) return;
	if(l == r) {
		IT[id].ans = max(0, value);
		IT[id].all = value;
		return;
	} 
	int mid = (l + r) >> 1;
	update(id*2, l, mid, pos, value);
	update(id*2+1, mid + 1, r, pos, value);
	IT[id].combine(IT[id*2], IT[id*2+1]);
}

void get(int id, int l, int r, int u, int v) {
	if(l > v || r < u) return;
	if(l >= u && r <= v) {
		answer.combine(answer, IT[id]);
		return;
	}
	int mid = (l + r) >> 1;
	get(id*2, l, mid, u, v);
	get(id*2+1, mid + 1, r, u, v); 
}

void init(){
	cin >> n >> q;
	FOR(i, n) cin >> a[i], update(1, 1, n, i + 1, a[i]);
}

void Solve_1() {
	int pos, value;
	cin >> pos >> value;
	update(1, 1, n, pos, value);
}	

void Solve_2() {
	int left, right;
	cin >> left >> right;
	answer = {0, 0};
	get(1, 1, n, left, right);
	cout << answer.ans << endl;
}

int main()
{
   file();
   init();
   while(q--) {
   		int type; cin >> type;
   		if(type == 1) Solve_1();
   		else Solve_2();
   }
}