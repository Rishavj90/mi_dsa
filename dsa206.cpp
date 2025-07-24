#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeList(ListNode* _L1, ListNode* _L2){
    if(_L1 == nullptr)return _L2;
    if(_L2 == nullptr)return _L1;
    if(_L1->val <= _L2->val){
        _L1->next = mergeList(_L1->next, _L2);
        return _L1;
    }else{
        _L2->next = mergeList(_L2->next, _L1);
        return _L2;
    }
    return nullptr;
}

ListNode* split(int l, int r, vector<ListNode*>& lists){
    if(l==r)return lists[l];
    int mid = (l+r)/2;
    ListNode* _L1 = split(l, mid, lists);
    ListNode* _L2 = split(mid+1,r,lists);
    return mergeList(_L1, _L2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())return nullptr;
    return split(0, lists.size()-1, lists);
}