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

// Single Round Match 641 Div
// TrianglesContainOriginEasy  500
// Memo Limit: 256 MB
// Time Limit: 2000 ms
// 以后算三角形面积再用海伦公式我就是猪

class TrianglesContainOriginEasy {
  private:
  // 赛后试了快20次没试出EPS也是醉了，只能放弃海伦公式了
  const double EPS = 1e-8;
  double getArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    double abx = x2 - x1;
    double aby = y2 - y1;
    double bcx = x3 - x2;
    double bcy = y3 - y2;
    return abs((abx*bcy - aby*bcx)/2.0);
  }
  public:
  int count(vector<int> x, vector<int> y) {
    int len = x.size();
    int ans = 0;
    for(int i = 0; i < len; ++i)
      for(int j = i+1; j < len; ++j)
        for(int k = j+1; k < len; ++k) {
          double abc = getArea(x[i], y[i], x[j], y[j], x[k], y[k]);
          double abp = getArea(x[i], y[i], x[j], y[j], 0, 0);
          double acp = getArea(x[i], y[i], x[k], y[k], 0, 0);
          double bcp = getArea(x[j], y[j], x[k], y[k], 0, 0);
          if(abs(abc - abp - acp - bcp) < EPS){
            ans++;
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
    { { {-1,-1,1}, {1,-1,0} }, {1} },
    { { {-1,-1,1,2}, {1,-1,2,-1} }, {2} },
    { { {-1,-2,3,3,2,1}, {-2,-1,1,2,3,3} }, {8} },
    { { {1,5,10,5,-5,7,-9,-6,-3,0,8,8,1,-4,7,-3,10,9,-6}, {5,-6,-3,4,-2,-8,-7,2,7,4,2,0,-4,-8,7,5,-5,-2,-9} }, {256} },
    // Your custom test goes here:
    //{ { {}, {}}, {} },
};}

//------------------------------------------------------------------------------
// Tester code:
    //#define DISABLE_THREADS
    #include "TrianglesContainOriginEasy-tester.cpp"
    struct input {
        vector<int> p0;vector<int> p1;

        int run(TrianglesContainOriginEasy* x) {
            return x->count(p0,p1);
        }
        void print() { Tester::printArgs(p0,p1); }
    };

    int main() {
        return Tester::runTests<TrianglesContainOriginEasy>(
            getTestCases<input, Tester::output< int> >(), disabledTest,
            500, 1418313936, CASE_TIME_OUT, Tester::COMPACT_REPORT
        );
    }
// CUT end
