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

ListNode* reverse_LL(ListNode* head){
    ListNode* prev = nullptr, *i = head;
    while(i != nullptr){
        ListNode* temp = i->next;
        i->next = prev;
        prev = i;
        i = temp;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head, *fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* new_head = reverse_LL(slow->next);
    ListNode* left = head, *right = new_head;
    while(left->next != nullptr && right != nullptr){
        if(left->val != right->val) {
            reverse_LL(new_head);
            return false;
        }
        left = left->next;
        right = right->next;
    }
    reverse_LL(new_head);
    return true;
}