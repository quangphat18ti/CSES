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
#define LT "1751"
#define maxn 200005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
int a[maxn] , f[maxn] , active[maxn] , tr[maxn];
int group[maxn] , cnt = 0 , sl_group[maxn];

void nhap()
{
    cin >> n;
    For(i , 1 , n) cin >> a[i];
}

void dfs( int u )
{
    active[u] = 1;

    int v = a[u];

    if( tr[v] == 0 )
    {
        tr[v] = u;
        dfs(v);
        if( group[u] ) f[u] = sl_group[ group[u] ];
        else f[u] = f[v] + 1;
    }
    else if( active[v] == 0 ) f[u] = f[v] + 1;
    else
    {
        cnt++;  int dem = 0;

        int ures = u;
        while( ures != v )
        {
            group[ures] = cnt;
            dem++;
            ures = tr[ures];
        }

        group[v] = cnt;
        dem++;
        sl_group[cnt] = dem;

        f[u] = dem;
    }

    active[u] = 0;
}

void xuli()
{
    For( i , 1 , n )
    {
        if( tr[i] ) continue;
        tr[i] = i;
        dfs(i);
    }

    For( i , 1 , n ) cout << f[i] << ' '; cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
//    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

