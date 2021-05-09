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
#define LT "1676"
#define maxn 100005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii edge[maxn * 2];
int ke[maxn] , gt[maxn];
int Fen[maxn] , sl;

void nhap()
{
    cin >> n >> m;
    For( i , 1 , m ) cin >> edge[i].fi >> edge[i].se;
}

int root( int u )
{
    if( u != ke[u] ) u = root(ke[u]);
    return ke[u];
}

void upd( int i , int gt )
{
    while( i <= n )
    {
        Fen[i] = max( Fen[i] , gt );
        i += i & -i;
    }
}

int get( int i )
{
    int ans = 0;
    while( i > 0 )
    {
        ans = max( ans , Fen[i] );
        i -= i & -i;
    }
    return ans;
}

void xuli()
{
    For(i , 1 , n) ke[i] = i , gt[i] = 1;
    sl = n;
    For( i , 1 , m )
    {
        int u = edge[i].fi , v = edge[i].se;
        u = root(u) , v = root(v);
        if( u != v )
        {
            if( gt[u] > gt[v] ) ke[v] = u , gt[u] += gt[v] , upd(u , gt[u]);
            else ke[u] = v , gt[v] += gt[u] , upd(v , gt[v]);
            sl--;
        }

        cout << sl << ' ' << get(n) << endl;
    }
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

