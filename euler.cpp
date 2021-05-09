 #include <bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
 
using namespace std;
 
const int N = 2e5 + 5;
 
int check[N];
vector <int> dsk[N], id[N];
 
int main()
{
    IOS;
    //freopen("euler.inp","r",stdin);
    //freopen("euler.out","w",stdout);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 1; i <= m; i++){
        int u, v;
 
        cin >> u >> v;
 
        dsk[u].pb(v);
        id[u].pb(i);
 
        dsk[v].pb(u);
        id[v].pb(i);
    }
 
    /// dk can : tat ca cac dinh phai co bac chan
    for (int i = 1; i <= n; i++){
        if (dsk[i].size() % 2){
        cout << "IMPOSSIBLE";
            return 0;
        }
    }
 
    stack <int> st;
    vector <int> E;
 
    st.push(1);
 
    while (st.size() > 0){
        int u = st.top();
 
        ///kiem tra canh noi tu u da xoa chua
        while (dsk[u].size() > 0 && check[id[u].back()] == 1){
            id[u].pop_back();
            dsk[u].pop_back();
        }
 
        if (dsk[u].size() == 0){ /// dinh u la dinh co don (hic)
            st.pop();
            E.pb(u);
        }
        else{
            st.push(dsk[u].back());
 
            check[id[u].back()] = 1;
            dsk[u].pop_back();
            id[u].pop_back();
        }
    }
 
    if (E.size() - 1 != m || E[0] != E.back()){
        cout << "IMPOSSIBLE";
        return 0;
    }
 
    for (int v : E) cout << v << " ";
    cout << '\n';
}
