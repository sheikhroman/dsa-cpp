#include<bits/stdc++.h>
#include "myStack.h"
using namespace std;
/*
Stak of int, float, dubble, char,string,pair, stucter,object of class
*/
int globalID = 100;
class person{
    string name;
    int id;
    float salary;
public:
    person(){
        name = "";
        id = -1;
        salary = -1.0;
    }
    void setName(string name){
        this->name = name;
    }
    void setSalary(float salary){
        this->salary = salary;
    }
    person(string name,float salary){
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }
    int getID(){
        return id;
    }
    string getname(){
        return name;
    }
    float getSalaey(){
        return salary;
    }
    void print(){
        cout << name << " | " << id << " | " << salary << endl;
    }
};
int main(){

    // Stack <pair<int,char>>st;
    // st.push(make_pair(1,'a'));
    // st.push(make_pair(2,'b'));
    // st.push(make_pair(3,'c'));
    //  while(!st.empty()){
    //      pair<int, char> chk;
    //      chk = st.pop();
    //      cout << chk.first<<" | "<< chk.second << endl;
    //      //cout<< st.pop()<<endl;
    // }
    // cout << st.size() << endl;
    // //if(!st.empty())cout << st.Top() << endl;//(st.Top()!=-1)
    // if(!st.empty()){
    //     pair<int, char> chk;
    //     chk = st.pop();
    // }
    Stack <person> st;
    person a ("Roman", 400.90);
    person b ("Humayon", 300.90);
    person c ("Sakil", 390.90);
    st.push(a);
    st.push(b);
    st.push(c);
    // while(!st.empty()){
    //     person printObj;
    //     printObj = st.pop();
    //     printObj.print();
    // }
        person printObj;
        printObj = st.Top();
        printObj.print();
        cout << st.size() << endl;
        return 0;
}