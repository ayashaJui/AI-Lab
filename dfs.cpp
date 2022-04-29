#include<bits/stdc++.h>
using namespace std;

int a[20][20],v[20];
int n;

void dfs(int s)
{
    int i;
    v[s] = 1;
    cout << s+1 << " ";
    for(i=0; i<n; i++){
        if((a[s][i] == 1) && (v[i] == 0))
        {
            dfs(i);
        }
    }
}
int main()
{
    int i,j,s;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Adjacent Matrix:" << endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(i=0; i<n; i++){
        v[i] = 0;
    }
    cout << "Starting node: ";
    cin >> s;
    cout << "Depth First Search::" << endl;
    dfs(s-1);
}

