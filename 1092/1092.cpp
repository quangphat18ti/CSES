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
#define LT "1092"
#define maxn 1000005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll s;

void nhap()
{
    cin >> n;
    s = 1ll*(n + 1)*n/2;
}

void xuli()
{
    if( s % 2 ) { cout << "NO\n"; return; }

    s /= 2;
    vi u , v;

    FOr( i , n , 1 )
    {
        if( s >= i ) u.pb(i) ,s -= i;
        else v.pb(i);
    }

    cout << "YES\n";
    cout << u.size() << endl;
    for( int tam : u ) cout << tam << ' '; cout << endl;
    cout << v.size() << endl;
    for( int tam : v ) cout << tam << ' '; cout << endl;
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
