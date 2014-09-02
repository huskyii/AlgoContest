#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
using namespace std;

pair<int, int> g[256];

char tmp[1005];

bool m[256][256];
int visited[26];

void bfs(int i){
    //cout << "inbfs"<<endl;
    queue<int> waitting;
    waitting.push(i);
    while(!waitting.empty()){
        //cout << cnt <<endl;
        int front = waitting.front();
        visited[front] = 1;
        //printf("%c\n", front);
        waitting.pop();
        for(int j = 'a'; j <= 'z'; j++){
            if(m[front][j] && visited[j] == 0)
                waitting.push(j);
        }
    }
}

bool is_connected(){
    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 'a'; i <= 'z'; i++){
        if(g[i].first || g[i].second){
            if(!visited[i]){
                cnt++;
                bfs(i);
            }
        }
    }
    if(cnt == 1)
        return true;
    else
        return false;
}

int main(void){
    int T, n;
    scanf("%d", &T);
    while(T--){
        memset(m, 0, sizeof(m));
        int end = 0;
        int start = 0;
        bool flag = true;
        for(int i = 'a'; i <= 'z'; i++){
            g[i].first = 0;
            g[i].second = 0;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%s", tmp);
            g[(int)tmp[0]].first++;
            g[(int)tmp[strlen(tmp)-1]].second++;
            m[(int)tmp[0]][(int)tmp[strlen(tmp)-1]] = true;
            m[(int)tmp[strlen(tmp)-1]][(int)tmp[0]] = true;
        }
        for(int i = 'a'; i <= 'z'; i++){
            if(g[i].first == g[i].second)
                continue;
            if(g[i].first - g[i].second == 1 && start == 0)
                start++;
            else if(g[i].first - g[i].second == -1 && end == 0)
                end++;
            else
                flag = false;
        }
        if((flag && is_connected()) || n == 1)
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
    return 0;
}
