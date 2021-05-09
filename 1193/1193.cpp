#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define LT "1193"
#define maxn 1005
#define fi first
#define se second
#define For(i , a , b) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr(i , a , b) for( int i = int(a) ; i >= int(b) ; i-- )
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
int i , j , n , m , k;
char a[maxn][maxn];
pii S , T;
int di[10] = { 0 , -1 , 0 , 1 , 0 , -1 };
char huong[10] = { ' ' , 'U' , 'R' , 'D' , 'L' };
int tr[maxn][maxn] , kt[maxn][maxn];
 
void nhap()
{
    cin >> n >> m;
    For(i , 1 , n) For(j , 1 , m) cin >> a[i][j];
    For( i , 1, n ) For( j , 1 , m )  if( a[i][j] == 'A' ) S = { i , j };
    For( i , 1, n ) For( j , 1 , m )  if( a[i][j] == 'B' ) T = { i , j };
}
 
bool check( int x , int y ) { return ( x >= 1 && x <= n && y >= 1 && y <= m  ); }
 
void loang( pii s , pii t )
{
    kt[s.fi][s.se] = 1;
    queue <pii> st; st.push( s );
 
    while( !st.empty() )
    {
        pii tam = st.front(); st.pop();
        int x = tam.fi , y = tam.se;
        For( i , 1 , 4 )
        {
            int x_ = x + di[i] , y_ = y + di[i + 1];
            if( !check( x_ , y_ ) || a[x_][y_] == '#' || kt[x_][y_] ) continue;
            kt[x_][y_] = kt[x][y] + 1;
            tr[x_][y_] = i;
            st.push( { x_ , y_ } );
            if( x == t.fi && y == t.se ) return;
        }
    }
}
 
void trace( pii T )
{
    vector<char> ans;
    int x = T.fi , y = T.se;
    while( x != S.fi || y != S.se )
    {
        int tam = tr[x][y];
        ans.pb( huong[tam] );
        x -= di[tam];
        y -= di[tam + 1];
    }
    reverse( ans.begin() , ans.end() );
    for( char tam : ans ) cout << tam;
}
 
void xuli()
{
    loang(S , T);
    if( kt[T.fi][T.se] == 0 )
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << kt[T.fi][T.se] - 1 << endl;
    trace( T );
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
