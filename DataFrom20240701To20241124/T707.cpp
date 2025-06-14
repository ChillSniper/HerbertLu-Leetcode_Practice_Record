#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
public:
    MyLinkedList() {
        head = new List();
        Size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= Size) return -1;
        int cnt = -1;
        List* Pre = head;
        while (cnt <= index)
        {
            if(cnt == index)
                return Pre->val;
            cnt ++;
            Pre = Pre->next;
        }
        
    }
    
    void addAtHead(int val) {
        List* tmp = new List(val);
        tmp->next = head->next;
        head->next = tmp;
        Size ++;
    }
    
    void addAtTail(int val) {
        List* Pre = head;
        while (Pre->next)
        {
            Pre = Pre->next;
        }
        List* tmp = new List(val);
        tmp->next = Pre->next;
        Pre->next = tmp;
        Size ++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > Size || index < 0) return;
        if(index == Size) return addAtTail(val);
        int cnt = -1;
        List* Pre = head;
        while (cnt <= index - 1)
        {
            if(cnt == index - 1){
                List* tmp = new List(val);
                tmp->next = Pre->next;
                Pre->next = tmp;
            }
            cnt ++;
            Pre = Pre->next;
        }
        Size ++;        
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= Size) return;
        int cnt = -1;
        List* Pre = head;
        while (cnt <= index - 1)
        {
            if(cnt == index - 1){
                Pre->next = Pre->next->next;
            }
            cnt ++;
            Pre = Pre->next;
        }   
        Size --;
    }

    void PrintData(){
        List* Pre = head;
        while (Pre->next)
        {
            printf("%d ", Pre->next->val);
            Pre = Pre->next;
        }
        
    }
private:
    struct List{
        int val;
        List* next;
        List(int x = 0):val(x), next(nullptr){}
    };
    List* head;
    int Size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->PrintData();
    return 0;
}