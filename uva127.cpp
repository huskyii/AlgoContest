/****************************************/
/*			author: jiang.zhu			*/
/*	  email: mail.jiang.cn@gmail.com	*/
/*		created on 2014-08-20			*/
/****************************************/
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool match(const pair<char, char> &a, const pair<char, char> &b){
    if(a.first == b.first || a.second == b.second){
        return true;
    }
    return false;
}

void update(vector< stack< pair<char, char> > > &piles){
    vector< vector< stack< pair<char, char > > >::iterator > del;
    for(vector< stack< pair<char, char> > >::iterator it = piles.begin();
        it != piles.end(); it++){
        if(it->empty()){
            del.push_back(it);
        }
    }
    for(size_t i = 0; i < del.size(); i++){
        piles.erase(del[i]);
    }
}

void solve(vector< stack< pair<char, char> > > &piles){
    bool flag = false;
    do{
        flag = false;
        for(size_t i = 1; i < piles.size(); i++){
            if(i > 2 && match(piles[i].top(), piles[i-3].top())){
                piles[i-3].push(piles[i].top());
                piles[i].pop();
                update(piles);
                flag = true;
                break;
            }else if(match(piles[i].top(), piles[i-1].top())){
                piles[i-1].push(piles[i].top());
                piles[i].pop();
                update(piles);
                flag = true;
                break;
            }
        }
    }while(flag);
}

int main(void){
    char rank, suit;
    //pair<rank, suit>
    vector< stack< pair<char, char> > > piles;
    while(scanf("%c%c ", &rank, &suit) == 2 && rank != '#'){
        piles.clear();
        //printf("%c%c ", rank, suit);
        stack< pair<char, char> > s;
        s.push(make_pair(rank, suit));
        piles.push_back(s);
        for(int i = 0; i < 51; i++){
            stack< pair<char, char> > s;
            scanf("%c%c ", &rank, &suit);
            //printf("%c%c ", rank, suit);
            s.push(make_pair(rank, suit));
            piles.push_back(s);
        }
        //printf("\n");
        solve(piles);
        if(piles.size() == 1){
            printf("1 pile remaining: 52\n");
        }else{
            printf("%d piles remaining:", (int) piles.size());
            for(size_t i = 0; i < piles.size(); i++){
                printf(" %d", (int) piles[i].size());
            }
            printf("\n");
        }
    }
    return 0;
}
