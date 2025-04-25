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
    ListNode* head = new ListNode(vec[vec.size()-1]);
    ListNode*mover = head;
    for(int i = vec.size()-2; i >= 0; i--){
        ListNode* temp = new ListNode(vec[i]);
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}
ListNode* reverseLL(ListNode* head){
    ListNode *prev = nullptr, *i = head, *front;
    while(i != nullptr){
        front = i->next;
        i->next = prev;
        prev = i;
        i = front;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sum_head = new ListNode(-1);
    ListNode* i = l1, *j = l2, *k = sum_head;
    int sum;
    int carry = 0;
    while(i != nullptr && j != nullptr){
        sum = i->val + j->val + carry;
        ListNode* tmp = new ListNode(sum%10);
        carry = sum/10;
        k->next = tmp;
        k = k->next;
        i = i->next;
        j = j->next;
    }
    while(i != nullptr){
        sum = i->val + carry;
        ListNode* tmp = new ListNode(sum%10);
        carry = sum/10;
        k->next = tmp;
        k = k->next;
        i = i->next;
    }
    while(j != nullptr){
        sum = j->val + carry;
        ListNode* tmp = new ListNode(sum%10);
        carry = sum/10;
        k->next = tmp;
        k = k->next;
        j = j->next;
    }
    ListNode* del_node = sum_head;
    sum_head = sum_head->next;
    delete del_node;
    if(carry != 0){
        ListNode* tmp = new ListNode(1);
        k->next = tmp;
        carry = 0;
    }
    return sum_head;
}

int main(){
    vector<int> vec1 = {7,9,9,9,9,9,9,9,9,9};
    vector<int> vec2 = {8,8,8,8,8,7};
    ListNode* vec1_head = vector_toLL(vec1);
    ListNode* vec2_head = vector_toLL(vec2);
    ListNode* sum_head = addTwoNumbers(vec1_head, vec2_head);
    sum_head = reverseLL(sum_head);
    ListNode* i = sum_head;
    while(i != nullptr){
        cout << i->val;
        i = i->next;
    }
    return 0;
}