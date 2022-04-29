#include <bits/stdc++.h>
using namespace std;

int a[20];
int n, s;

void print(int n)
{
    int i,j;
    s++;

    cout << endl;

    cout << "Solution: " << s << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i] == j)
            {
                cout << "Q" << "\t";
            }
            else
            {
                cout << "-" << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int place(int k,int i)
{
    int j;

    for(j=1; j<k; j++){
        if(a[j] == i)
            return 0;
        else if (abs(a[j]-i) == abs(j-k))
            return 0;
    }

    return 1;
}

void nqueen(int k,int n)
{
    int i;

    for(i=1; i<=n; i++){
        if(place(k,i))
        {
            a[k] = i;

            if(k == n)
            {
                print(n);
            }
            else
            {
                nqueen(k+1,n);
            }
        }
    }
}
int main()
{
    int i,j;

    cout << "Number of Queens: ";
    cin >> n;
    nqueen(1,n);
}
