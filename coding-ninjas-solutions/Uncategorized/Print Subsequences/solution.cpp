#include <iostream>
using namespace std;


void solve(int i,char input[],string output){
    if(input[i]=='\0'){
        cout<<output<<endl;
        return;
    }
    //notpick
    solve(i+1,input,output);

    //pick
    solve(i+1,input,output+input[i]);
}


void printSubsequences(char input[]) {
    // Write your code here
    solve(0,input,"");

}
