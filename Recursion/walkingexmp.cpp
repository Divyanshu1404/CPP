#include<iostream>
using namespace std;

// Function to simulate walking from source to destination using recursion
void reachHome(int src, int dest){
    // Base case: when source equals destination

    cout<<"source: "<<src<<". "<<"destination: "<<dest<<". "<<endl;
    if(src==dest){
        cout<<"Ghr aa gye bhai";
         return;
    }
    src++;
    reachHome(src, dest);
}
 int main(){
    int src=1;
    int dest=10;
    cout<<endl;
    reachHome(src, dest);

    return 0;

 }
