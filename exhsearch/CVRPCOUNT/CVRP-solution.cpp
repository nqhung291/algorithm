#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

// data structure for input
int N, K;// numbers of clients and trucks
int Q;// capacity of truck
int d[MAX];// demands of clients
int c[MAX][MAX];// cost (i,j)
int cmin;

// data structure for exhaustive search
int Y[MAX];
int X[MAX];
int load[MAX];
int segments;
bool visited[MAX];
int cnt;
int f;// accumulated total distance of the K routes under construction
int min_f;// min distance found so far

void input(){
    cmin = 1e9;
    cin >> N >> K >> Q;
    for(int i = 1; i <= N; i++)
        cin >> d[i];
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cin >> c[i][j];
            if(i != j && cmin > c[i][j]) cmin = c[i][j];
        }
    }
}

// v: client, k: truck
bool checkY(int v, int k){
    if(v > 0 && visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

// v: client, i: number of i-th client on route of truck k, 
bool checkX(int v, int i, int k){
    if(v > 0 && visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    if(v == 0 && k == K){
            if(segments + 1 < N+K) return false;
    }
    return true;
}

void solution(){
    if(f < min_f){
        min_f = f;
        //cout << "update_best " << min_f << endl;
    }
    return;
    cnt++;
    cout << "Solution " << cnt << "th: " << endl;
    for(int k = 1; k <= K; k++){
        cout << "Route[" << k << "]: 0 -> " << Y[k];
        int next = Y[k];
        while(next > 0){
            next = X[next];
            cout << " -> " << next;
            if(next == 0) break;
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

void TRY_X(int i, int k){// try value for X[i] on route[k]
    //cout << "TRY_X(" << i << "," << k << ")" << endl;
    for(int v = 0; v <= N; v++){
        if(checkX(v,i,k)){
            //cout << "TRY_X(" << i << "," << k << "), v = " << v << endl;
            X[i] = v;
            visited[v] = true;
            segments++;
            load[k] = load[k] + d[v];
            f = f + c[i][v];
            if(v == 0){// finished route[k]
                if(k == K){
                    solution();
                }else{
                    if(f + cmin*(N+K-segments) < min_f)
                        TRY_X(Y[k+1],k+1);
                }
            }else{
                if(f + cmin*(N+K-segments) < min_f)
                    TRY_X(v,k);
            }
            visited[v] = false;
            segments--;
            load[k] = load[k] - d[v];
            f = f - c[i][v];
        }
    }
}

void TRY_Y(int k){// try values for Y[k], k: each truck
    for(int v = Y[k-1]+1; v <= N; v++){ // loop for each client v
        if(checkY(v,k)){
            //cout << "TRY_Y(" << k << "), v = " << v << endl;
            Y[k] = v;
            visited[Y[k]] = true;
            segments++;
            load[k] = load[k] + d[v];
            f = f + c[0][v];
            if(k == K){
                if(f + cmin*(N+K-segments) < min_f)
                    TRY_X(Y[1],1);
            }else{
                if(f + cmin*(N+K-segments) < min_f)
                    TRY_Y(k+1);
            }
            visited[Y[k]] = false;
            segments--;
            load[k] = load[k] - d[v];
            f = f - c[0][v];
        }
    }
}

void solve(){
    for(int i = 1; i <= N; i++) visited[i] = false; // set false for all client
    segments = 0; // ? 
    for(int k = 1; k <= K; k++) load[k] = 0; // set load for all trucks
    Y[0] = 0;
    cnt = 0;
    f = 0;
    min_f = 1e9;
    TRY_Y(1);
    cout << min_f;
}
int main(){
    input();
    solve();
}
