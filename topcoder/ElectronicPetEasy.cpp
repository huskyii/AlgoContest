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
// ElectronicPetEasy  250
// Memo Limit: 256 MB
// Time Limit: 2000 ms

class ElectronicPetEasy {
  public:
  string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
    set<int> s;
    for(int i = 0; i < t1; ++i)
      s.insert(st1 + i*p1);
    for(int i = 0; i < t2; ++i)
      if(s.find(st2+i*p2) != s.end())
        return "Difficult";
    return "Easy";
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
    { { 3, 3, 3, 5, 2, 3 }, {"Difficult"} },
    { { 3, 3, 3, 5, 2, 2 }, {"Easy"} },
    { { 1, 4, 7, 1, 4, 7 }, {"Difficult"} },
    { { 1, 1000, 1000, 2, 1000, 1000 }, {"Easy"} },
    { { 1, 1, 1, 2, 2, 2 }, {"Easy"} },
    // Your custom test goes here:
    //{ { , , , , , }, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "ElectronicPetEasy-tester.cpp"
    struct input {
        int p0;int p1;int p2;int p3;int p4;int p5;

        string run(ElectronicPetEasy* x) {
            return x->isDifficult(p0,p1,p2,p3,p4,p5);
        }
        void print() { Tester::printArgs(p0,p1,p2,p3,p4,p5); }
    };

    int main() {
        return Tester::runTests<ElectronicPetEasy>(
            getTestCases<input, Tester::output< string> >(), disabledTest,
            250, 1417203748, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
