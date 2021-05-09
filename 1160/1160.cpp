///

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1160"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn] , active[maxn] , kt[maxn];

int sl_group = 0 , group[maxn] , tr[maxn];
int dist[maxn]; //dist[i] là vị trí của i trong chu trình
int num_child[maxn]; /// num_child[i] là số lượng đỉnh trong chu trình i
int node_be[maxn]; //note_be[i] là nút đầu tiên mà i chạm vào chu trình

vi ke[maxn];
int h[maxn] , be[maxn], fi[maxn] , goc[maxn] , cnt = 0;

void nhap()
{
    cin >> n >> k;
    For(i , 1 , n) cin >> a[i];
}

void truyvet( int u , int v )
{
    vi ans;
    int dem = 0;
    while( u != v )
    {
        group[u] = sl_group;
        dist[u] = ++dem;
        ans.pb(u);
        u = tr[u];
    }
    group[v] = sl_group;
    dist[v] = ++dem;
    ans.pb(v);

    for( int u : ans ) dist[u] = dem - dist[u] + 1;
    num_child[sl_group] = dem;
}

void dfs( int u )
{
    kt[u] = 1;
    active[u] = 1;

    int v = a[u];
    if( kt[v] == 0 ) tr[v] = u , dfs(v);
    else
    {
        if( active[v] )
        {
            sl_group++;
            truyvet( u , v );
        }
    }

    active[u] = 0;
}

void Build_group()
{
    For(i , 1 , n)
    {
        if( kt[i] ) continue;
        dfs(i);
    }

    m = sl_group;
    For( i , 1 , n ) if( group[i] == 0 ) group[i] = ++sl_group;
}

void DFS_1( int u , int gt )
{
    be[u] = ++cnt;
    goc[u] = gt;
    for( int v : ke[u] )
    {
        h[v] = h[u] + 1;
        DFS_1( v , gt );
    }
    fi[u] = cnt;
}

void Build_graph()
{
    For(i , 1 , n)
    {
        int v = group[ a[i] ] , u = group[i];
        if( u == v ) continue;
        ke[v].pb(u);
    }

    For( i , 1 , m )
    {
        h[i] = 1;
        DFS_1( i , i );
    }
}

void xuli()
{
    Build_group();

//    Nhận xét về đồ thị sau khi nhóm. Ta thấy rằng :
//        - Đây là độ thị có hướng và điểm kết thúc của mọi đường đi là 1 chu trình.
//        - 2 chu trình thì không thể cùng nằm trong 1 thành phần liên thông. Hay không thể có chu trình nào nối tới nhau.
//        - Và 1 đỉnh chỉ đi đúng 1 con đường tới đỉnh chu trình
//        - Như vậy ta có thể chia 1 chu trình thành 1 đồ thị riêng biệt và dfs ngược trên đồ thị này để tính ra độ cao của các đỉnh khác so
//        với đỉnh chu trình.
//        - Vậy u -> v có 3 trường hợp :
//            + u và v đều không phải là đỉnh chu trình. => u nằm trong cây con gốc v và độ dài đường đi là h[u] - h[v].
//            + v là đỉnh chu trình. => u nằm trong cây con gốc v và chi phí đường đi cần phải cộng thêm với chi phí từ chu trình tới v.
//            + u và v đều là 2 đỉnh trong chu trình. => Cùng chu trình và chi phí tính cũng khá đơn giản.

    Build_graph();

    while( k-- )
    {
        int u , v; cin >> u >> v;
        int u1 = group[u] , v1 = group[v];

        if( u1 == v1 ) //Đều là 2 đỉnh trong chu trình
        {
            int ans = dist[v] - dist[u];
            if( ans < 0 ) ans += num_child[u1];
            cout << ans << endl;
            continue;
        }

        if( u1 > m && v1 > m ) /// 2 đỉnh đều nằm ngoài chu trình
        {
            if( be[v1] <= be[u1] && fi[v1] >= be[u1] ) cout << h[u1] - h[v1] << endl;
            else cout << -1 << endl;
            continue;
        }

        if( u1 <= m && v1 > m ) ///u nằm trong chu trình còn v thì không
        {
            cout << -1 << endl;
            continue;
        }

        if( u1 > m && v1 <= m ) /// u ngoài chu trình và v nằm trong chu trình
        {
             if( be[v1] <= be[u1] && fi[v1] >= be[u1] )
             {
                int ans = h[u1] - h[v1];
                /// Công cho đoạn dầu và đoạn cuối của chu trình
             }
             else cout << -1 << endl;
             continue;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(LT".inp","r",stdin);
    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

