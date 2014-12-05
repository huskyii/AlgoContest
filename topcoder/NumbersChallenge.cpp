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

// SRM 621 Div 2
// NumbersChallenge  500
// Memo Limit: 256 MB
// Time Limit: 2000 ms

const int MAXN = 100000*20 + 1;
bool v[MAXN];

class NumbersChallenge {
  public:
  int MinNumber(vector<int> S) {
    memset(v, 0, sizeof(v));
    int n = S.size();
    for(int subset = 0; subset < (1<<n); ++subset) {
      int sum = 0;
      for(int i = 0; i < n; ++i)
        if(subset & (1<<i))
          sum += S[i];
      v[sum] = true;
    }
    int ans = 1;
    while(v[ans]) {ans++;};
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
    { { {5,1,2} }, {4} },
    { { {2,1,4} }, {8} },
    { { {2,1,2,7} }, {6} },
    { { {94512,2,87654,81316,6,5,6,37151,6,139,1,36,307,1,377,101,8,37,58,1} }, {1092} },
    { { {883,66392,3531,28257,1,14131,57,1,25,88474,4,1,110,6,1769,220,442,7064,7,13} }, {56523} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "NumbersChallenge-tester.cpp"
    struct input {
        vector<int> p0;

        int run(NumbersChallenge* x) {
            return x->MinNumber(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<NumbersChallenge>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            500, 1417752146, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
