#include<iostream>

using namespace std;

int main(){
    int n;
    cout << "enter a number (> 2) : ";
    cin >> n;

    bool flag = true;

    for(int i = 2; i <= n; i++){
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag == true){
            cout << i << "  ";
        }
        flag = true;
    }

    return 0;
}
