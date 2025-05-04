// determining the mininmum number of elements to be removed from the array to make it unique

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve()
{
    int n;
    cout << "Enter the len of array: ";
    cin >> n;

    vector <int> a(n);
    
    //Inserting elements
    cout << "Enter the array: ";
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    unordered_set <int> seen(n);
    int index=0;

    //finding the index of first reccurance
    for(int i= n-1; i>=0; i--){
        if(seen.count(a[i])){
            index=i+1;
            break;
        }
        seen.insert(a[i]);
    }

    //removing value till index to make the vector unique
    for (int i=0; i<index; i++) a.erase(a.begin());

    cout << index << endl;
}

int main()
{
    int t;  //total number of test cases
    cout << "Enter the total number of cases: ";
    cin >> t;

    while (t--) solve();
    return 0;
}