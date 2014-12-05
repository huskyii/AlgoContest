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

// SRM 622 Div 2
// FibonacciDiv2  250
// Memo Limit: 256 MB
// Time Limit: 2000 ms
int fib[100];

class FibonacciDiv2 {
  public:
  int find(int N) {
    int i = 2;
    fib[0] = 0;
    fib[1] = 1;
    while(true) {
      fib[i] = fib[i-1] + fib[i-2];
      if(fib[i] > 1000000) break;
      i++;
    }
    for(int j = 0; j < i; ++j) {
      if(fib[j] <= N && N <= fib[j+1])
        return min(N-fib[j], fib[j+1]-N);
    }
    return fib[i] - N;
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
    { { 1 }, {0} },
    { { 13 }, {0} },
    { { 15 }, {2} },
    { { 19 }, {2} },
    { { 1000000 }, {167960} },
    // Your custom test goes here:
    //{ { }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "FibonacciDiv2-tester.cpp"
    struct input {
        int p0;

        int run(FibonacciDiv2* x) {
            return x->find(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<FibonacciDiv2>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            250, 1417751728, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
