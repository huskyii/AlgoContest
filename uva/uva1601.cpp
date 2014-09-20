// TODO
/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-09-02			*/
/****************************************/
#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef unsigned int uint;
map<uint, vector<uint> > g;
uint d[1<<24];
uint s[3], e[3];
char id[3];
char m[20][20];

// 把當前的狀態encode成一個數
// c1、c2、c3 是3個鬼的當前坐標
inline uint encode(uint c1, uint c2, uint c3) {
    return (c1 << 16) | (c2 << 8) | c3;
}

// 對坐標進行編碼
inline uint encode(uint x, uint y) {
    return (x << 4) | y;
}

void preprocess(int w, int h) {
    int cur = 0;
    for(uint i = 0; i < (uint)h; i++)
        for(uint j = 0; j < (uint)w; j++) {
            if(m[i][j] != '#') {
                uint c = encode(i, j);
                g[c].push_back(c);
                if(i > 0 && m[i-1][j] != '#')
                    g[c].push_back(encode(i-1, j));
                if(i+1 < (uint)h && m[i+1][j] != '#')
                    g[c].push_back(encode(i+1, j));
                if(j > 0 && m[i][j-1] != '#')
                    g[c].push_back(encode(i, j-1));
                if(j+1 < (uint)w && m[i][j+1] != '#')
                    g[c].push_back(encode(i, j+1));
            }
            if(islower(m[i][j])) {
                bool flag = false;
                for(int k = 0; k < cur; k++) {
                    if(m[i][j] == id[k]) {
                        s[k] = encode(i, j);
                        flag = true;
                        break;
                    }
                }
                if(!flag) {
                    id[cur] = m[i][j];
                    s[cur] = encode(i, j);
                    cur++;
                }
            } else if(isupper(m[i][j])) {
                bool flag = false;
                for(int k = 0; k < cur; k++) {
                    if(tolower(m[i][j]) == id[k]) {
                        e[k] = encode(i, j);
                        flag = true;
                        break;
                    }
                }
                if(!flag) {
                    id[cur] = tolower(m[i][j]);
                    e[cur] = encode(i, j);
                    cur++;
                }
            }
        }
    // 如果不足3個鬼則補齊，減少代碼量
    for(int i = cur; i < 3; i++) {
        uint c = encode(17+i, 17+i);
        s[i] = c;
        e[i] = c;
        g[c].push_back(c);
    }
}

int ans;
void bfs() {
    queue<uint> ws;
    set<uint> vs;
    ws.push(encode(s[0], s[1], s[2]));
    d[encode(s[0], s[1], s[2])] = 0;
    vs.insert(encode(s[0], s[1], s[2]));
    uint estate = encode(e[0], e[1], e[2]);
    while(!ws.empty()){
        uint sstate = ws.front();
        ws.pop();
        if(sstate == estate) { ans = d[sstate]; return ; }
        uint s1 = (sstate>>16)&0xff, s2 = (sstate>>8)&0xff, s3 = sstate&0xff;
        for(uint i = 0; i < g[s1].size(); i++)
            for(uint j = 0; j < g[s2].size(); j++)
                for(uint k = 0; k < g[s3].size(); k++) {
                    if(g[s1][i] == g[s2][j] || g[s1][i] == g[s3][k] ||
                       g[s2][j] == g[s3][k] )
                        continue;
                    uint cur = encode(g[s1][i], g[s2][j], g[s3][k]);
                    if(vs.find(cur) == vs.end()) {
                        if(cur == estate) { ans = d[sstate] + 1; return ; }
                        vs.insert(cur);
                        ws.push(cur);
                        d[cur] = d[sstate] + 1;
                    }
                }
    }
}

int main(void) {
    int w, h, n;
    while(scanf("%d %d %d", &w, &h, &n) == 3 && w && h && n) {
        getchar();
        printf("%d %d %d\n", w, h, n);
        for(int i = 0; i < h; i++) {
            fgets(m[i], 18, stdin);
        }
        for(int i = 0; i < h; i++) {
            printf("%s", m[i]);
        }

        preprocess(w, h);
        bfs();

        printf("%u\n", ans);
    }
    return 0;
}
