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

// TCO 2014 Round 1A Div 1
// EllysSortingTrimmer  250
// Memo Limit: 256 MB
// Time Limit: 2000 ms

class EllysSortingTrimmer {
  public:
  string getMin(string S, int L) {
    for(int i = S.size() - L; i >= 0; --i)
      sort(S.begin()+i, S.begin()+i+L);
    return S.substr(0, L);
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
    { { "ABRACADABRA", 5 }, {"AAAAA"} },
    { { "ESPRIT", 3 }, {"EIP"} },
    { { "BAZINGA", 7 }, {"AABGINZ"} },
    { { "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 13 }, {"ABCDEFGHIJKLM"} },
    { { "GOODLUCKANDHAVEFUN", 10 }, {"AACDDEFGHK"} },
    { { "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD", 21 }, {"AAAAAAAAABBDDDDDDDEEI"} },
    { { "TOPCODER", 3 }, {"CDT"} },
    // Your custom test goes here:
    //{ { , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "EllysSortingTrimmer-tester.cpp"
    struct input {
        string p0;int p1;

        string run(EllysSortingTrimmer* x) {
            return x->getMin(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };

    int main() {
        return Tester::runTests<EllysSortingTrimmer>(
            getTestCases<input, Tester::output< string> >(), disabledTest,
            250, 1417207427, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
