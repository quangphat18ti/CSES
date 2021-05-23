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

#define LT "1634"
#define maxn 1000005

int n, Sum;
vi a;

void file() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(LT".inp", "r", stdin);
    // freopen(LT".out", "w", stdout);
}

void init() {
    cin >> n >> Sum;
    FOR(i, n) {
        int value; cin >> value;
        if(value == Sum) {
            cout << 1 << endl;
            exit(0);
        }
        if(value < Sum) a.push_back(value);
    }

    if(a.empty()) {
        cout << -1 << endl;
        exit(0);
    }
    sort(all(a));
}

void Solve() {
    vi ans(1000002, 0);
    queue<int> st; st.push(0);
    ans[0] = 0;

    while(!st.empty()) {
        int u = st.front(); st.pop();
        FOR(i, n) {
            int v = u + a[i];
            if(v > Sum) break;
            if(ans[v]) continue;
            ans[v] = ans[u] + 1;
            st.push(v);

            if(v == Sum) {
                cout << ans[v] << endl;
                exit(0);
            }
        }
    }
    cout << -1;
}

int main()
{
   file();
   init();
   Solve();
}
