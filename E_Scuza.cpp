#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
// Algorithms
#include <algorithm>
#include <numeric>
#include <functional>

// Iterators
#include <iterator>

// Streams and I/O

#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <streambuf>

// String handling
#include <string>
#include <cstring>

// Utilities
#include <utility>
#include <limits>
#include <memory>
#include <typeinfo>
#include <new>
#include <exception>
#include <stdexcept>
#include <tuple>
#include <bitset>

// Math and numeric arrays
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <valarray>
#include <complex>
#include <climits>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template < typename T = int > using Pair = pair < T, T >;
vector < string > RET = {"NO", "YES"};
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

void Solve(){
   int n, q;
    cin >> n >> q;
    vector<long long> pref;
    pref.push_back(0);
    vector<int> prefmax;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pref.push_back(pref.back()+x);
        if(i == 0)
        {
            prefmax.push_back(x);
        }
        else
        {
            prefmax.push_back(max(prefmax.back(), x));
        }
    }
    for(int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        int ind = upper_bound(prefmax.begin(), prefmax.end(), k)-prefmax.begin();
        cout << pref[ind] << " ";
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}