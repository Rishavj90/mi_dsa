#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* vector_toDLL(vector<int>& vec){
    ListNode* head = new ListNode(vec[0]);
    ListNode*mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* temp = new ListNode(vec[i]);
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}
/*
ListNode* reverseList(ListNode* head) {
    stack<int> stk;
    ListNode* i = head;
    while(i != nullptr){
        stk.push(i->val);
        i = i->next;
    }
    i = head;
    while(i != nullptr){
        i->val = stk.top();
        stk.pop();
        i = i->next;
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* k = nullptr, *i = head, *j = head->next;
    while(j != nullptr){
        i->next= k;
        k = i;
        i = j;
        j = j->next;
    }
    i->next= k;
    return i;
}

*/

ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next= head;
    head->next = nullptr;
    return newHead;
}

int main(){
    vector<int> vec = {0,3,4,6,7,8};
    ListNode* head = vector_toDLL(vec);
    head = reverseList(head);
    ListNode* i = head;
    while(i != NULL){
        cout << i->val<< " ";
        i = i->next;
    }
    return 0;
}