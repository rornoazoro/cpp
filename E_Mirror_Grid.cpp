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

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

void Solve(){
   ll n;
   cin>>n;
   string s[n];
   for(int i=0;i<n;i++){
       cin>>s[i];
   }
   int x=n/2, y=n/2;
   if(n&2==1){
    y++;
   }
   int ans=0;
   for(int i=0; i<x; i++){
    for(int j=0; j<y; j++){
        int ones=0;
        ones+=s[i][j]-'0';
        ones+=s[j][n-i-1]-'0';
        ones+=s[n-i-1][n-j-1]-'0';
        ones+=s[n-j-1][i]-'0';
        
        if(ones==2){
            ans+=2;
        }
        else if(ones==1 || ones==3){
            ans+=1;
        }
   }
}
 cout << ans << "\n";
    return;
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