#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define FOR(i, a, b) for(int i = int(a); i < int(b); i++)
#define fi first
#define se second
#define mp make_pair
#define LT "1690"
#define maxn 1050005
#define sz(A) int( A.size() )
#define ms( f, a, b, gt ) fill( f+a , f+b+1 , gt )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int n_node, n_edge;
vii list_edge;
vvi relevant;
int mod = 1e9 + 7;
int dp[maxn][20];

vvi init(){
    cin >> n_node >> n_edge;
    FOR(i, 0, n_edge) {
        int u, v; cin >> u >> v; u--; v--;
        list_edge.push_back({u, v});
    }

    vvi ans(n_node, vi(0));
    FOR(i, 0, n_edge) {
        ans[list_edge[i].se].push_back(list_edge[i].fi);
    }
    return ans;
}

bool get_bit(int mask, int bit) {
    return (mask >> bit) & 1;
}
vvi Find_list_bit() {
    vvi list_bit;
    FOR(mask, 0, (1 << n_node)) {
        vi res;
        FOR(bit, 0, n_node) if( bit != 0 && get_bit(mask, bit)) res.push_back(bit);
        list_bit.push_back(res);
    }
    return list_bit;
}

void dp_bitmask(vvi list_bit){
    dp[1][0] = 1;
    FOR(mask, 2, (1 << n_node)) {
        if(!get_bit(mask, 0) || get_bit(mask, n_node - 1) ) continue;
        for(int bit : list_bit[mask]) {
            int old_mask = mask ^ (1 << bit);
            for(int bit_re : relevant[bit]) dp[mask][bit] = (dp[mask][bit] + dp[old_mask][bit_re]) % mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp", "r", stdin);
//    freopen(LT".out", "w", stdout);
    relevant = init();
    vvi list_bit = Find_list_bit();
    dp_bitmask(list_bit);
    int ans = 0, mask = (1 << n_node) - 1 - (1 << (n_node - 1));
    for(int bit : relevant[n_node - 1]) {
        ans = (ans + dp[mask][bit]) % mod;
    }
    cout
