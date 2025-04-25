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

// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     unordered_map<ListNode*, int> mpp;
//     ListNode* A = headA;
//     while(A != nullptr){
//         mpp[A]++;
//         A = A->next;
//     }
//     ListNode* B = headB;
//     while(B != nullptr && mpp[B] != 1){
//         B = B->next;
//     }
//     return B;
// }

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode* A = headA;
    ListNode* B = headB;
    while(A!= B){
        if(A == nullptr) A = headB;
        else A = A->next;
        if(B == nullptr) B = headA;
        else B = B->next; 
    }
    return A;
}

int main(){
    vector<int> vecA = {3};
    vector<int> vecB = {1,2};
}