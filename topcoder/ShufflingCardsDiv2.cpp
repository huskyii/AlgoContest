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
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int64;

// Single Round Match 641 Div
// ShufflingCardsDiv2  1000
// Memo Limit: 256 MB
// Time Limit: 2000 ms

class ShufflingCardsDiv2 {
  public:
  string shuffle(vector<int> permutation) {
    int len = permutation.size();
    vector<int> A;
    for(int i = 0; i < len; ++i) {
      if(i%2) A.push_back(permutation[i]);
    }
    int aa = 0;
    for(int i = 0; i < len/2; ++i) {
      if(A[i] <= len/2) aa++;
    }
    // 想清楚细节再提交
    if(aa == len/4)
      return "Possible";
    else
      return "Impossible";
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
    { { {1,2,3,4} }, {"Possible"} },
    { { {4,3,2,1} }, {"Possible"} },
    { { {1,3,2,4} }, {"Impossible"} },
    { { {1,4,2,5,3,6} }, {"Impossible"} },
    { { {8,5,4,9,1,7,6,10,3,2} }, {"Possible"} },
    { { {1,2} }, {"Possible"} },
    { { {8,5,4,9,1,7,6,10,3,2} }, {"Possible"} },
    // Your custom test goes here:
    //{ { {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "ShufflingCardsDiv2-tester.cpp"
    struct input {
        vector<int> p0;

        string run(ShufflingCardsDiv2* x) {
            return x->shuffle(p0);
        }
        void print() { Tester::printArgs(p0); }
    };

    int main() {
        return Tester::runTests<ShufflingCardsDiv2>(
            getTestCases<input, Tester::output< string> >(), disabledTest,
            1000, 1418316490, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
