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

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* even_LL = head;
    ListNode* odd_LL = head->next;
    ListNode* i = head->next->next;
    int count = 0;
    ListNode* j = even_LL;
    ListNode* k = odd_LL;
    while(i != nullptr){
        if(count%2 == 0){
            j->next = i;
            j = j->next;
        }else{
            k->next = i;
            k = k->next;
        }
        count++;
        i = i->next;
    }
    j->next = odd_LL;
    k->next = nullptr; 
    return even_LL;
}