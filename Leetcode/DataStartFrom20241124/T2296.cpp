#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define Test

struct TextNode
{
    char val;
    TextNode* before;
    TextNode* Next;
    TextNode(): val(' '), before(nullptr), Next(nullptr){}
    TextNode(char __val): val(__val), before(nullptr), Next(nullptr){}
    TextNode(char __val, TextNode* __before, TextNode* __Next): val(__val), before(__before), Next(__Next){}
};


class TextEditor {
public:
    TextEditor() {
        Head = new TextNode();
        tail = new TextNode();
        Head->Next = tail;
        tail->before = Head;
        cur = Head;
    }
    
    void addText(string text) {
        int sz = text.size();
        for(int i = 0;i < sz;i ++){
            TextNode* p = new TextNode(text[i]);
            TextNode* lastnext = cur->Next;
            p->Next = lastnext;
            lastnext->before = p;
            cur->Next = p;
            p->before = cur;
            cur = p;
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while (k > 0 && cur != Head)
        {
            k --;
            cnt ++;
            TextNode* b = cur->before;
            TextNode* n = cur->Next;
            delete cur;
            cur = nullptr;
            b->Next = n;
            n->before = b;
            cur = b;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while (k > 0 && cur != Head)
        {
            k --;
            cur = cur->before;
        }
        
        return GetStr(k);
    }
    
    string cursorRight(int k) {
        while (k > 0 && cur->Next != tail)
        {
            k --;
            cur = cur->Next;
        }
        return GetStr(k);
    }

private:
    string GetStr(int k){
        deque<char> dq;
        int cnt = 0;
        TextNode* p = cur;
        while (cnt < 10 && p != Head)
        {
            dq.push_front(p->val);
            cnt ++;
            p = p->before;
        }
        string ans = "";
        while (dq.size())
        {
            ans += dq.front();
            dq.pop_front();
        }
        return ans;
    }
    TextNode* Head, *tail, *cur;
};
    
    /**
     * Your TextEditor object will be instantiated and called as such:
     * TextEditor* obj = new TextEditor();
     * obj->addText(text);
     * int param_2 = obj->deleteText(k);
     * string param_3 = obj->cursorLeft(k);
     * string param_4 = obj->cursorRight(k);
     */

int main(){
    #ifdef Test
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    #endif
    TextEditor* obj = new TextEditor();
    obj->addText("leetcode");
    obj->deleteText(4);
    // obj->addText("practice");
    // obj->cursorRight(3);
    // obj->cursorLeft(8);
    // obj->deleteText(10);
    // obj->cursorLeft(2);
    // obj->cursorRight(6);
    return 0;
}