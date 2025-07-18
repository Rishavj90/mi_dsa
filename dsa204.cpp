#include <bits/stdc++.h>
using namespace std;

class Maxheap{
private:
    vector<int>vec;
public:
    Maxheap(){}

    void insert(int a){
        vec.push_back(a);
        int i = vec.size()-1;
        int parent = (i-1)/2;
        while(vec[i] > vec[parent]){
            swap(vec[i], vec[parent]);
            i = parent;
            parent = (i-1)/2;
        }
        return;
    }

    void remove(){
        if(vec.empty())return;
        vec[0] = vec[vec.size()-1];
        vec.pop_back();
        int N = vec.size();
        int i = 0;
        int l = 2*i+1, r = 2*i+2;
        while(i < N && l < N){
            if(r<N && vec[l] < vec[r] && vec[i] < vec[r]){
                swap(vec[r], vec[i]);
                i = r;
            }else if(vec[l] > vec[i]){
                swap(vec[l], vec[i]);
                i = l;
            }else{
                break;
            }
            l = 2*i+1, r = 2*i+2;
        }
        return;
    }

    int getMax(){
        return vec[0];
    }

    void showHeap(){
        cout << endl;
        for(auto i : vec)cout << i << " ";
        return;
    }

};

int main(){
    auto a = new Maxheap();
    a->insert(1);
    a->insert(2);
    a->insert(1);
    a->insert(7);
    a->insert(5);
    a->insert(9);
    a->insert(7);
    a->showHeap();

    a->remove();
    a->showHeap();
    a->remove();
    a->showHeap();
    a->remove();
    a->showHeap();
    a->insert(11);
    a->showHeap();
    a->insert(0);
    a->showHeap();
    cout << endl <<a->getMax();
    return 0;
}