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

// SRM 594 Div 2
// AstronomicalRecordsEasy  500
// Memo Limit: 64 MB
// Time Limit: 2000 ms

class AstronomicalRecordsEasy {
  public:
  int minimalPlanets(vector<int> A, vector<int> B) {
    int res = A.size() + B.size();
    for(int p: A)
      for(int q: B) {
        set<int> s;
        for(int x: A)
          s.insert(x*q);
        for(int x: B)
          s.insert(x*p);
        res = min(res, (int)s.size());
      }
    return res;
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
    { { {1,2,3,4}, {2,3,4,5} }, {5} },
    { { {1,2,3,4}, {2,4,6,8} }, {4} },
    { { {1,2,3,5,6,8,9}, {2,4,5,6,7,8,9} }, {9} },
    { { {1,2,3,4}, {6,7,8,9} }, {6} },
    { { {200,500}, {100,200,300,400,600,700,800,900} }, {9} },
    { { {1,2,3,4,5,6,7,8,9,10,11,12}, {6,7,8,9,10,11,12,13,14,15} }, {15} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "AstronomicalRecordsEasy-tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(AstronomicalRecordsEasy* x) {
            return x->minimalPlanets(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };

    int main() {
        return Tester::runTests<AstronomicalRecordsEasy>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            500, 1417767885, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
