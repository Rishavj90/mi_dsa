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
ListNode* middleNode(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* i = head;
    int n = 0;
    while(i != nullptr){
        n++;
        i = i->next;
    }
    i = head;
    int count = -1;
    while(i != nullptr){
        count++;
        if(count == n/2){
            return i;
        }
        i = i->next;
    }
    return nullptr;
}

*/
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main(){
    vector<int> vec = {0,3,4,6,7,8};
    ListNode* head = vector_toDLL(vec);
    ListNode* i = head;
    while(i != NULL){
        cout << i->val<< " ";
        i = i->next;
    }
    return 0;
}