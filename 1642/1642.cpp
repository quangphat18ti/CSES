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
#define LT "1642"
#define maxn 1005
#define sz(A) int( A.size() )

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int i , j , n , m , k;
pii a[maxn];
map <int,int> dd;

void nhap()
{
    cin >> n >> k;
    For( i , 1 ,n ) cin >> a[i].fi , a[i].se = i;
    sort( a + 1 , a + n + 1 );
}

struct ii
{
    int gt;
    int vt1 , vt2;

    bool operator < ( ii a )
    {
        return gt < a.gt;
    }
};

int Find( int gt , vector<ii> &u )
{
    For( i , 0 , u.size() - 1 )
        if( u[i].gt == gt ) return i;
}

void xuli()
{
    vector<ii> U;
    For( i , 2 , n )
    {
        For( j , 1 , i - 1 )
        {
            int gt = a[j].fi + a[i].fi;
            if( dd[gt] == 0 )
            {
                dd[gt] = i;
                U.pb( { gt , a[i].se , a[j].se } );
            }
        }
    }

    sort( U.begin() , U.end() );

    FOr( i , n - 1 , 1 )
    {
        For( j , i + 1 , n )
        {
            int gt = a[i].fi + a[j].fi;
            gt = k - gt;
            if( dd[gt] > 0 && dd[gt] < i )
            {
                int vt = Find( gt , U );
                cout << U[vt].vt1 << ' ' << U[vt].vt2 << ' ' << a[i].se << ' ' << a[j].se << endl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE";
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
