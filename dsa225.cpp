#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
    int num;
    Node* next, *prev;
    Node(int a){
        num = a;
        next = nullptr;
        prev = nullptr;
    };
};
class LRU{
    unordered_map<int, Node*>mpp;
    int cap;
    Node* head, *tail;
    public:
    LRU(int C){
        cap = C;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    void ram(int a){
        Node* tmp;
        if(mpp.find(a) == mpp.end()){
            tmp = new Node(a);

            if(mpp.size() >= cap){
                Node* leastUsed = tail->prev;
                Node* before_leastUsed = leastUsed->prev;
                before_leastUsed->next = tail;
                tail->prev = before_leastUsed;
                
                mpp.erase(leastUsed->num);
                delete leastUsed;
            }
            mpp[a] = tmp;
        }else{
            tmp = mpp[a];

            Node* before_tmp = tmp->prev;
            Node* after_tmp = tmp->next;

            before_tmp->next = after_tmp;
            after_tmp->prev = before_tmp;
            
        }

        Node* first = head->next;
        head->next = tmp;
        tmp->prev = head;
        first->prev = tmp;
        tmp->next = first;
    }

    bool willPageFault(int a){
        if(mpp.find(a) == mpp.end())return false;
        return true;
    }
};

int pageFaults(int N, int C, int pages[]) {
    LRU myLRU(C);
    int ans = 0;
    for(int i = 0; i<N; i++){
        if(!myLRU.willPageFault(pages[i]))ans++;
        myLRU.ram(pages[i]);
    }
    return ans;
}

int main(){
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    cout << pageFaults(9,4, pages);
    return 0;
}