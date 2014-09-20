//#define debug
#include <cstdio>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main(void){
#ifdef debug
    freopen("uva10391.in", "r", stdin);
#endif
    set<string> dict;
    string word;
    while(cin >> word)
        dict.insert(word);
    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++){
        for(unsigned int i = 1; i < it->length(); i++){
            if(dict.find(it->substr(0,i)) != dict.end() && dict.find(it->substr(i)) != dict.end() ){
                cout << *it << endl;
                break;
            }
        }
    }
    return 0;
}
