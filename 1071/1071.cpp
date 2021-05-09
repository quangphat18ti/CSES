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
#define LT "1071"
#define maxn
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
ll x , y;

void nhap()
{
    cin >> x >> y;
}

void xuli()
{
    ll maxx = max( x , y );
    ll ans = (maxx - 1) * ( maxx - 1 );

    /// Vòng chẵn thì sẽ đi từ trên xuống
    /// Vòng lẻ thì sẽ đi từ dưới lên
    if( maxx % 2 == 0 )  cout << ans + x + maxx - y << endl;
    else cout << ans + maxx - x + y << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen(LT".inp","r",stdin);
//    freopen(LT".out","w",stdout);
    int t = 1;
    cin >> t;
    while( t-- )
    {
        nhap();
        xuli();
    }
}

