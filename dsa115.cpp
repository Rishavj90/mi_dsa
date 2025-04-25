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

ListNode* reverse_LL(ListNode* head, ListNode* end){
    ListNode* a = head, *front = nullptr;
    while(a != end){
        front = a->next;
        a->next = end->next;
        end->next = a;
        a = front;
    }
    head = end;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr || k ==1) return head;
    ListNode* i = head, *kGroupBegin = nullptr, *kGroupPrev = nullptr;
    int count = 0;
    while(i != nullptr){
        count++;
        if(count%k == 1){
            kGroupPrev = kGroupBegin;
            kGroupBegin = i;
        }
        if(count%k == 0){
            ListNode* front = i->next;
            ListNode* reversedKGroup_head = reverse_LL(kGroupBegin, i);
            if(count/k == 1) head = reversedKGroup_head;
            if(kGroupPrev != nullptr)kGroupPrev->next = reversedKGroup_head;
            i = front;
        }else{
            i = i->next;
        }
    }
    return head;
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    ListNode* head = vector_toLL(vec);
    head = reverseKGroup(head,1);
    ListNode* i = head; 
    while(i != nullptr){
        cout << i->val << " ";
        i = i->next;
    }
    return 0;
}