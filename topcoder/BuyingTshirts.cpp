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

// Single Round Match 641 Div
// BuyingTshirts  250
// Memo Limit: 256 MB
// Time Limit: 2000 ms

class BuyingTshirts {
  public:
  int meet(int T, vector<int> Q, vector<int> P) {
    int curQ = 0, curP = 0;
    int len = Q.size();
    int ans = 0;
    for(int i = 0; i < len; ++i) {
      curQ += Q[i];
      curP += P[i];
      if(curQ >= T && curP >= T)
        ans++;
      if(curP >= T) curP -= T;
      if(curQ >= T) curQ -= T;
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
    { { 5, {1,2,3,4,5}, {5,4,3,2,1} }, {2} },
    { { 10, {10,10,10}, {10,10,10} }, {3} },
    { { 2, {1,2,1,2,1,2,1,2}, {1,1,1,1,2,2,2,2} }, {5} },
    { { 100, {1,2,3}, {4,5,6} }, {0} },
    { { 10, {10,1,10,1}, {1,10,1,10} }, {0} },
    // Your custom test goes here:
    //{ { , {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "BuyingTshirts-tester.cpp"
    struct input {
        int p0;vector<int> p1;vector<int> p2;

        int run(BuyingTshirts* x) {
            return x->meet(p0,p1,p2);
        }
        void print() { Tester::printArgs(p0,p1,p2); }
    };

    int main() {
        return Tester::runTests<BuyingTshirts>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            250, 1418313629, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
