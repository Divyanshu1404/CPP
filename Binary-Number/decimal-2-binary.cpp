#include<iostream>
using namespace std;

int dec2binary(int decNum){
    int ans = 0;
    int pow = 1;
    while(decNum > 0){
        int rem = decNum % 2;
        decNum = decNum / 2;
        ans = ans + rem * pow;
        pow = pow * 10;
    }
    return ans;
}

int main()
{
    int decNum;
    cout << "Enter the number: ";  
    cin >> decNum; 

    for (int i = 1; i <= decNum; i++){
        cout << dec2binary(i) << endl;
    }

    return 0;
}
