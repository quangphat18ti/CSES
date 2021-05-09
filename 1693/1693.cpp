#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define FOR_UP(i, a, b) for(int i = int(a); i < int(b); i++)
#define FOR_DOWN(i, a, b) for(int i = int(a); i >= int(b); i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1693"
#define maxn 1000005
#define sz(A) int( A.size() )
#define ms( f, a, b, gt ) fill( f+a , f+b+1 , gt )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int n_node, n_edge;
vii edge;
vvii relative;

auto init_edge(int n_node,int n_edge){
    vii edge(n_edge);
    vvii relative(n_node, vii(0));

    FOR_UP(index, 0, n_edge) {
        int u, v; cin >> u >> v;
        u--, v--;
        edge.pb({u, v});
        relative[u].pb({index, v});
    }

    return make_tuple(edge, relative);
}

bool check_euler_tour() {
    vi deg_in(n_node, 0), deg_out(n_node, 0);
    for(pii tam : edge) {
        deg_out[tam.fi]++;
        deg_in[tam.se]++;
    }

    int Count_diff = 0;
    FOR_UP(node, 0, n_node) Count_diff += (deg_in[node] != deg_out[node]);

    if(Count_diff != 2) return false;
    if(deg_out[0] == deg_in[0] + 1 && deg_in[n_node - 1] == deg_out[n_node - 1] + 1) return true;
    return false;
}

vi Find_euler_tour(int s) {
    vi dd(n_edge, 0);
    vi ans, st;
    st.pb(s);

    while(!st.empty()) {
        int u = st.back();

//        while(!relative[u].empty() && dd[relative[u].back().fi]) {
//            relative[u].pop_back();
//        }

        if( relative[u].empty() ) {
            ans.push_back(u);
            st.pop_back();
            continue;
        }

        int id = relative[u].back().fi;
        int v = relative[u].back().se;
        dd[id] = 1;
        relative[u].pop_back();
        st.push_back(v);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp", "r", stdin);
//    freopen(LT".out", "w", stdout);
    cin >> n_node >> n_edge;

    tie(edge, relative) = init_edge(n_node, n_edge);
    if( !check_euler_tour() ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vi euler_tour = Find_euler_tour(0);
    if(euler_tour.size() != n_edge + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int u : euler_tour) cout << u + 1 << ' '; cout << endl;
}
