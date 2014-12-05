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

// SRM 619 Div 2
// ChooseTheBestOne  500
// Memo Limit: 256 MB
// Time Limit: 2000 ms

class ChooseTheBestOne {
  public:
  int countNumber(int N) {
    vector<int> xs(N);
    for(int i = 1; i <= N; ++i)
      xs[i-1] = i;
    int i = 0;
    for(int64 t = 1; t < N; t++) {
      int m = xs.size();
      i = (int)((i + t*t*t-1)%m);
      xs.erase(xs.begin()+i);
    }
    return xs[0];
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
    { { 3 }, {2} },
    { { 6 }, {6} },
    { { 10 }, {8} },
    { { 1234 }, {341} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "ChooseTheBestOne-tester.cpp"
    struct input {
        int p0;

        int run(ChooseTheBestOne* x) {
            return x->countNumber(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<ChooseTheBestOne>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            500, 1417753243, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
