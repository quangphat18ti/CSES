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

#define LT "1739"
#define maxn 1005

vector<vector<int>> a;

struct POINT{
	int x, y;

	void nhap(){
		cin >> x >> y;
		y--, x--;
	}
};
struct QUERY{
	int type;
	POINT A, B;

	void nhap() {
		cin >> type;
		A.nhap();
		if(type == 2) B.nhap(); 
	}
};
vector<QUERY> q;

int Fen[maxn][maxn];

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}

void init() {
	int n, nq; cin >> n >> nq;
	FOR(i, n) {
		vector<int> tam;
		FOR(j, n) {
			char k; cin >> k;
			if(k == '*') tam.push_back(1);
			else tam.push_back(0);
		}
		a.push_back(tam);
	}

	FOR(i, nq) {
		QUERY tam; tam.nhap();
		q.push_back(tam);
	}
}

void update_Fenwick(int i_start, int j_start, int value) {
	int n = a[0].size();
	 for(int i = i_start ; i <= n; i += i&-i) {
	 	for(int j = j_start ; j <= n; j += j&-j) {
	 		Fen[i][j] += value;
	 	}
	 }
}

int get_Fenwick(int i_start, int j_start) {
	int ans = 0;
	for(int i = i_start; i > 0; i -= i&-i) {
		for(int j = j_start ; j > 0; j -= j&-j) {
			ans += Fen[i][j];
		}
	}
	return ans;
}

void process_data() {
	int n = a[0].size();
	FOR(i, n) FOR(j, n) update_Fenwick(i + 1, j + 1, a[i][j]);
}

void solve_1(POINT A) {
	int x = A.x, y = A.y;
	int value = 1;
	if(a[x][y]) value = -1;
	a[x][y] = 1 - a[x][y];
	update_Fenwick(x + 1, y + 1, value);
}

int solve_2(POINT A, POINT B) {
	int x1 = A.x + 1, x2 = B.x + 1;
	int y1 = A.y + 1, y2 = B.y + 1;
	return get_Fenwick(x2, y2) - get_Fenwick(x1 - 1, y2) - get_Fenwick(x2, y1 - 1) + get_Fenwick(x1 - 1, y1 - 1);
}

void solve() {
	for(QUERY tam : q) {
		int type = tam.type;
		if(type == 1) solve_1(tam.A);
		else cout << solve_2(tam.A, tam.B) << endl;
	}
}

int main()
{
   file();
   init();
   process_data();
   solve();
}