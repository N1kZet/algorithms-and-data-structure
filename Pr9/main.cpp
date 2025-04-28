#include <iostream>
#include <ctime>

using namespace std;

void Rec(int n){
    if (n==0) return;
    int m=n%10;
    cout<<m<<" ";
    n/=10;
    Rec(n);
}

int main(){
    int n;
    cout<<"Введите n > ";
    cin>>n;

    Rec(n);cout<<"\n";
}
