#include <bits/stdc++.h>
using namespace std;

/* implement stack using arrays
class _stack{
    private:
    int arr[4];
    int var_top =-1;
    int var_size = 0;

    public:
    void push(int a){
        if(var_top+1<4){
            var_top = var_top+1;
            arr[var_top] = a;
            var_size+=1;
        }else cout <<"Couldn't add " << a << "\nRan out of space :(\n";
    }
    void pop(){
        if(var_size > 0){
            var_top -=1;
            var_size -= 1;
        }
    }
    int top(){
        return arr[var_top];
    }
    int size(){
        return var_size;
    }
};


int main(){
    _stack stk;
    stk.push(6);
    stk.push(7);
    stk.push(5);
    
    //stk.pop();
    stk.push(2);
    stk.push(9);
    //for(int i = 0; i < stk.size(); ++i)cout << stk.arr[i]<<" ";
    cout << stk.top() << " ";
    cout << stk.size();
    return 0;
}
*/

/*implement queue using arrays
class _queue{
    private:
    int start = -1, end = -1;
    int arr[4];
    int var_size = 0;

    public:
    void push(int a){
        if(var_size == 4){cout << "couldn't add " << a <<endl; return;}
        if(var_size == 0){
            start = (start+1)%4;
            end = (end+1)%4;
            arr[end] = a;
        }else{
            end = (end+1)%4;
            arr[end] = a;
        }
        var_size+=1;
    }
    void pop(){
        if(var_size ==1){start = -1; end = -1; return;}
        if(var_size > 0){
            start -= 1; 
            var_size -= 1;
        }else cout << "there's nothin\n";
    }
    int size(){
        return var_size;
    }
    int top(){
        if(start > 0 && var_size > 0)return arr[start];
    } 
};
*/

class Node{
    public:
    int num;
    Node* next;
    Node(int n){
        num = n;
        next = nullptr;
    }
};

/* implement stack using Linked List
class _stack{
    private:
    int var_size = 0;
    Node *curr;

    public:
    void push(int a){
        Node *temp = new Node(a);
        if(var_size ==0){
            curr = temp;
        }else{
            temp->next = curr;
            curr = temp;
        }
        var_size++;
    }

    void pop(){
        if(var_size > 0){
            Node* del_node = curr;
            curr = curr->next;
            delete del_node;
            var_size--;
        }else cerr << "\nstack is empty\n";
    }

    int top(){
        return curr->num;
    }

    int size(){
        return var_size;
    }

    void display(){
        Node* i = curr;
        while(i != nullptr){
            cout << i->num << " ";
            i = i->next;
        }
    }
};

int main(){
    _stack stk;
    stk.pop();
    stk.push(3);
    stk.push(13);
    stk.push(32);
    cout << endl <<stk.top();
    stk.push(93);
    stk.push(0);
    stk.push(4);
    cout << endl <<stk.top() <<endl;
    stk.push(5);
    stk.display();
    stk.pop();
    cout << endl <<stk.top();
    stk.pop();
    stk.pop();
    cout << endl;
    stk.display();
    cout << endl <<stk.top();
    cout << endl <<stk.size();
    return 0;
}
*/

/* implement stack using Linked List
class _queue{
    private:
    int var_size = 0;
    Node* head, *end;

    public:
    void push(int a){
        Node* temp = new Node(a);
        if(var_size == 0){
            head = temp;
            end = temp;
        }else{
            end->next = temp;
            end = temp;
        }
        var_size++;
    }

    void pop(){
        if(var_size > 0){
            Node* del_node = head;
            head = head->next;
            delete del_node;
            var_size--;
        }else cerr << "queue's empty";
    }

    int top(){
        return head->num;
    }
    int size(){
        return var_size;
    }
    void display(){
        Node* i = head;
        cout << endl;
        while(i != nullptr){
            cout << i->num << " ";
            i = i->next;
        }
        cout << endl;
    }
};

int main(){
    _queue qu;
    qu.push(7);
    qu.push(5);
    qu.display();
    qu.push(3);
    qu.push(1);
    qu.push(9);
    qu.push(12);
    qu.push(69);
    qu.push(4);
    qu.display();
    qu.pop();
    qu.pop();
    qu.display();
    cout << qu.top() << endl;
    qu.pop();
    qu.pop();
    qu.display();
    cout << qu.top() << endl;
    return 0;
}
*/

class _queue{
    public:
    stack<int>st_1, st_2;
    void push(int a){
        st_1.push(a);
    }

    void pop(){
        if(st_2.empty()){
            while(!st_1.empty()){
                st_2.push(st_1.top());
                st_1.pop();
            }
        }
        st_2.pop();
    }

    int top(){
        if(st_2.empty()){
            while(!st_1.empty()){
                st_2.push(st_1.top());
                st_1.pop();
            }
        }
        return st_2.top();
    }
};

int main(){
    _queue qu;
    qu.push(8);
    qu.push(4);
    qu.push(2);
    qu.push(3);
    qu.push(9);
    cout << qu.top();
    qu.pop();
    qu.pop();
    qu.pop();
    return 0;
}