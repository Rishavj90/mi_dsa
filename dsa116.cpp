#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* vector_toLL(vector<int>& vec){
    if(vec.size() == 0) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode*mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* temp = new ListNode(vec[i]);
        mover->next= temp;
        mover = mover->next;
    }
    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr) return head;
    int len = 1;
    ListNode* last = head, *new_end = nullptr, *new_head = nullptr;
    while(last->next != nullptr){
        len++;
        last = last->next;
    }
    int last_num = last->val;
    k = k%len;
    if(k == 0) return head;
    ListNode* j = head;
    int num = len-k-1;
    while(num--){
        j = j->next;
    }
    new_end = j;
    new_head = j->next;
    last->next = head;
    new_end->next = nullptr;
    head = new_head;
    return head;
}
int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    ListNode* head = vector_toLL(vec);
    head = rotateRight(head,5);
    ListNode* i = head;
    while(i!= nullptr){
        cout << i->val << " ";
        i = i->next;
    }
    return 0;
}