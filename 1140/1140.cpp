///
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define INC( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define For( i , a , b ) for(int i = int(a) ; i <= int(b) ; i++)
#define DEC( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define FOr( i , a , b ) for(int i = int(a) ; i >= int(b) ; i--)
#define fi first
#define se second
#define mp make_pair
#define LT "1140"
#define maxn 400005
#define sz(A) int( A.size() )
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int i , j , n , m , k;
struct ii
{
    int l , r , gt;
 
    bool operator < ( ii a )
    {
        return l < a.l;
    }
};
ii a[maxn];
 
ll f[maxn];
vector<int> ke[maxn];
 
void nen()
{
    vi u;
    For( i , 1 , n ) u.pb( a[i].l ) , u.pb( a[i].r );
    sort( u.begin() , u.end() );
    u.resize( unique( u.begin() , u.end() ) - u.begin() );
    For( i , 1 , n )
    {
        a[i].l = lower_bound( u.begin() , u.end() , a[i].l ) - u.begin() + 1;
        a[i].r = lower_bound( u.begin() , u.end() , a[i].r ) - u.begin() + 1;
    }
}
 
void nhap()
{
    cin >> n;
    For( i , 1 , n ) cin >> a[i].l >> a[i].r >> a[i].gt;
    nen();
    For( i , 1 , n ) ke[a[i].r].pb(i);
}
 
void xuli()
{
    int maxx = 0;
    For( i , 1 , n ) maxx = max( maxx , a[i].r );
   For( i , 1 , maxx )
   {
       f[i] = f[i - 1];
       for( int tam : ke[i] )
       {
           int l = a[tam].l;
           f[i] = max( f[i] , f[l - 1] + a[tam].gt );
       }
   }
 
   cout << f[maxx] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    nhap();
    xuli();
}
