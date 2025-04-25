#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> vec;
    int num = n;
    while(num != 0){
        int digit = num % 10;
        vec.push_back(digit);
        num = num/10;
    }

    int count = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] == 0){
            continue;
        }else if(n % vec[i] == 0){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

