#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <algorithm>
using namespace std;

typedef long long int64;

// SRM 639 Div 2
// AliceGameEasy  500
// Memo Limit: 256 MB
// Time Limit: 2000 ms

const int MAXN = 2100000;

class AliceGameEasy {
  public:
  int64 findMinimumValue(int64 x, int64 y) {
    int64 n = -1;
    int64 z = x + y;
    for(int64 i = 0; i <= MAXN; ++i) {
      if(i*(i+1)/2 == z) {
        n = i; break;
      }
    }
    if(n == -1) return n;
    else ++n;
    int ans = 0;
    while(--n) {
      if(x > n) {
        x -= n;
        ans++;
      } else if(x == n) {
        ans++;
        break;
      }
    }
    return ans;
  }
};

// CUT begin
//------------------------------------------------------------------------------
const double CASE_TIME_OUT = 2.0;

bool disabledTest(int x)
{
    return x < 0;
}
template<class I, class O> vector<pair<I,O>> getTestCases() { return {
    { { 7, 14 }, {2LL} },
    { { 10, 0 }, {4LL} },
    { { 932599670050, 67400241741 }, {1047062LL} },
    { { 7, 13 }, {-1LL} },
    { { 0, 0 }, {0LL} },
    { { 100000, 400500 }, {106LL} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "AliceGameEasy-tester.cpp"
    struct input {
        int64 p0;int64 p1;

        int64 run(AliceGameEasy* x) {
            return x->findMinimumValue(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };

    int main() {
        return Tester::runTests<AliceGameEasy>(
            getTestCases<input, Tester::output< int64> >(), disabledTest,
            500, 1417203644, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
