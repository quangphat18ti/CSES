#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
#define LT "1076"
#define maxn 200005
#define fi first
#define se second
#define For( i , a , b ) for( int i = int(a) ; i <= int(b) ; i++ )
#define FOr( i , a , b ) for( int i = int(a) ; i >= int(b) ; i-- )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int  i , j , n , m , k;
int a[maxn];
multiset<int> mi , ma;

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i];
}

void canbang()
{
    while( ma.size() > mi.size() )
    {
        int tam = *ma.begin(); tam = -tam;
        ma.erase( ma.begin() );
        mi.insert( tam );
    }

    while( true )
    {
        int res1 = *ma.begin(); res1 = -res1;
        int res2 = *mi.begin();

        if( res1 > res2 )
        {
            ma.erase( ma.begin() );
            mi.erase( mi.begin() );
            ma.insert( -res2 );
            mi.insert( res1 );
        }
        else break;
    }

    if( k % 2 ) cout << *mi.begin() << ' ';
    else cout << -(*ma.begin()) << ' ' ;
}

void xuli()
{
    For( i , 1 , k ) ma.insert( -a[i] );
    canbang();

    For( i , k + 1 , n )
    {
        int tam = a[i - k];

        auto vt = ma.find( -tam );
        if( vt != ma.end() ) ma.erase(vt);
        else mi.erase( mi.find( tam ) );

        ma.insert( -a[i] );
        canbang();
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
