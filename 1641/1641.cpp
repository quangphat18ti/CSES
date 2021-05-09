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
#define LT "1641"
#define maxn 5005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pair<ll,int> a[maxn];

void nhap()
{
    cin >> n >> k;
    For( i , 1 , n ) cin >> a[i].fi , a[i].se = i;
    sort( a + 1 , a + n + 1 );
}

void xuli()
{
    For( i , 1 , n - 2 )
    {
        int ct = n;
        For( j , i + 1 , n - 1 )
        {
            while( ct > j && a[i].fi + a[j].fi + a[ct].fi > k ) ct--;
            if( ct == j ) break;

            if( a[i].fi + a[j].fi + a[ct].fi == k )
            {
                cout << a[i].se << ' ' << a[j].se << ' ' << a[ct].se << endl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE ";
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

