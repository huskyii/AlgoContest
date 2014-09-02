//#define debug
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva442.in", "r", stdin);
#endif
    int n;
    char key;
    int row, col;
    pair<int, int> a, b;
    map< char, pair<int, int> > matrix;
    scanf("%d\n", &n);
    //cout << n << endl;
    while(n--){
        scanf("%c %d %d\n", &key, &row, &col);
        //cout << key << " " << row << " " << col << endl;
        matrix[key] = make_pair(row, col);
    }
    char expression[1000];
    while(scanf("%s", expression) != EOF){
        stack< pair<int, int> > parser;
        int cost = 0;
        bool flag = true;
        for(size_t i = 0; i < strlen(expression); i++){
            if(isupper(expression[i]))
                parser.push(matrix[expression[i]]);
            else if(expression[i] == ')'){
                b = parser.top();
                parser.pop();
                a = parser.top();
                parser.pop();
                if(a.second != b.first){
                    flag = false;
                    break;
                }else{
                    cost += a.first * a.second * b.second;
                    parser.push(make_pair(a.first, b.second));
                }
            }
        }
        if(!flag){
            printf("error\n");
        }else{
            printf("%d\n", cost);
        }
    }
    return 0;
}
