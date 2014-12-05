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
#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

typedef long long int64;

// 2004 TCCC Online Round 4 Div
// BadNeighbors  250
// Memo Limit: 64 MB
// Time Limit: 2000 ms

int dp[50];

class BadNeighbors {
  public:
  int maxDonations(vector<int> donations) {
    int n = donations.size();
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[1] = donations[1];
    for(int i = 2; i < n; ++i)
      dp[i] = max(dp[i-2]+donations[i], dp[i-1]);
    for(int i = 1; i < n; ++i)
      ans = max(ans, dp[i]);
    memset(dp, 0, sizeof(dp));
    dp[0] = donations[0];
    dp[1] = max(donations[1], donations[0]);
    for(int i = 2; i < n-1; ++i)
      dp[i] = max(dp[i-2]+donations[i], dp[i-1]);
    for(int i = 0; i < n-1; ++i)
      ans = max(dp[i], ans);
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
    { { {10,3,2,5,7,8} }, {19} },
    { { {11,15} }, {15} },
    { { {7,7,7,7,7,7,7} }, {21} },
    { { {1,2,3,4,5,1,2,3,4,5} }, {16} },
    { { {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72} }, {2926} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "BadNeighbors-tester.cpp"
    struct input {
        vector<int> p0;

        int run(BadNeighbors* x) {
            return x->maxDonations(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<BadNeighbors>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            250, 1417747831, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
