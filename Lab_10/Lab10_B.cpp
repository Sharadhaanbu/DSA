// Three Player Game

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n;
    cout << "Enter number of words: ";
    cin >> n;
    
    vector<vector<string>> words(3, vector<string>(n));    //To collect n words for 3 players
    unordered_map<string, int> count(n);    //To store n words and its recurrance

    //To obtain the words
    for (int i=0; i<3; i++){
        cout <<"Enter the words seperated by space: ";
        for (int j=0; j<n; j++){
            cin >> words[i][j];
            count[words[i][j]]+=1;
        }
    }


    vector<int> score(3, 0);   //To store each members points

    //calculating score
    for (int i=0; i<3; i++){
        for (int j=0; j<n; j++){
            if(count[words[i][j]]==1) score[i]+=3;
            if(count[words[i][j]]==2) score[i]+=1;
            if(count[words[i][j]]==3) score[i]+=0;
        }
    }
    cout << score[0] << " " << score[1] << " " << score[2] << endl;

}

int main(){
    int t;
    cout << "Total number of test cases: ";
    cin >> t;
    while(t--) solve();
}