#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define db double
#define LT "1192"
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
bool kt[maxn][maxn];
int ans = 0;
int di[10] = { 0 , -1 , 0 , 1 , 0 , -1 };
 
void nhap()
{
    cin >> n >> m;
    For( i , 1 , n ) For( j , 1 , m ) cin >> a[i][j];
}
 
bool check( int x , int y ) { return ( x >= 1 && x <= n && y >= 1 && y <= m ); }
 
void loang( int x , int y )
{
    queue <pii> st;
    st.push({x, y});
    kt[x][y] = 1;
 
    while( !st.empty() )
    {
        x = st.front().fi , y = st.front().se; st.pop();
 
        For( i , 1 , 4 )
        {
            int x_ = x + di[i];
            int y_ = y + di[i + 1];
            if( !check( x_ , y_ ) ) continue;
            if( kt[x_][y_] ) continue;
            if( a[x_][y_] == '#' ) continue;
            kt[x_][y_] = 1;
            st.push({x_ , y_});
        }
    }
}
 
void xuli()
{
    int ans = 0;
    For( i , 1 , n )
    {
        For( j , 1 , m )
        {
            if( a[i][j] == '#' ) continue;
            if(kt[i][j]) continue;
            ans++;
            loang(i , j);
        }
    }
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
