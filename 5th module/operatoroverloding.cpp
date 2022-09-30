#include<bits/stdc++.h>
using namespace std;

class Example{
    public:
        int x;
        Example(int a){
            x = a;
        }
    Example operator +(Example obj){
        cout << x+obj.x<<endl;
    }
    
};
int main(){
    Example a(10), b(20);
    a + b;
    return 0;
}