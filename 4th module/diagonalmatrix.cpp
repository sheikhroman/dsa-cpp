#include<bits/stdc++.h>
using namespace std;
int main(){
    int row, col, i, j;
    cin >> row >> col;
    int a[row][col];
    for (int i = 0; i < row;  i++){
        for (int j = 0; j < col;j++){
            cin >> a[i][j];
        }
    }
    if(row!=col){
        cout<<"Not a diagonal matrix"<<endl;
    }
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col; j++){
            if(i==j){
                continue;
            }
            if(a[i][j]>0){
                cout<<"Not a diagonal matrix"<<endl;
            }
        }
    }

    cout<<"Diagonal matrix"<<endl;
    //Scaler Start
    int save;
    for (int i=0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(i==j){
                if(i==0 && j==0)
                    save = a[i][j];
                    else{
                        if(save !=a[i][j]){
                            cout<<"Not a scaler"<<endl;
                        }
                    }
            }
        }
    }
    cout<<"Scaler"<<endl;
    cout << save << endl;

    return 0;
}