//#define debug
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
    return a.length() < b.length();
}

int main(void){
#ifdef debug
    freopen("uva400.in", "r", stdin);
    freopen("uva400.out", "w", stdout);
#endif
    vector<string> filenames;
    string tmp;
    int N, max_col, max_row, max_len;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < 60; i++)
            cout << "-";
        cout << endl;
        for(int i = 0; i < N; i++){
            cin >> tmp;
            filenames.push_back(tmp);
        }
        max_len = max_element(filenames.begin(), filenames.end(), cmp)->length();
        max_col = (60-max_len) / (max_len + 2) + 1;
        max_row = filenames.size() / max_col;
        if(filenames.size() % max_col != 0)
            max_row += 1;
        sort(filenames.begin(), filenames.end());
        /*
         *cout << "max_len: " << max_len << endl
         *     << "max_col: " << max_col << endl
         *     << "max_row: " << max_row << endl;
         */
        /*
         *for(auto i = filenames.begin(); i != filenames.end(); i++)
         *    cout << *i << endl;
         */
        for(int i = 0; i < max_row; i++){
            for( int j = 0; j < max_col-1; j++){
                cout << filenames[i + max_row*j];
                for(int k = 0; k < max_len+2 - filenames[i + max_row*j].length(); k++)
                    cout << " ";
            }
            if(i + max_row*(max_col-1) < filenames.size()){
                cout << filenames[i + max_row*(max_col-1)];
                for(int k = 0; k < max_len - filenames[i + max_row*(max_col-1)].length(); k++)
                    cout << " ";
            }
            cout << endl;
        }
        filenames.clear();
    }
    return 0;
}
