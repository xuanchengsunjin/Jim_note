/**
 * author:jim_sun
 * function:single linked list
 * time:2017.07.07
 * github:
*/
#ifndef MYLINKENDLIST_H
#define MYLINKENDLIST_H

#include <iostream>

struct Node{
    int val;
    Node *next;
};

class MyLinkedList {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int length = 0;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
    
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(check_index(index) == false)
            return -1;
        Node* temp = head;
        while(temp != NULL && index-- > 0){
            temp = temp ->next;
        }
        return temp ->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        //为新的node节点申请内存,初始化
        Node* node = create_new_Node(val);
        ++ length;
        if(head == NULL){
            head = node;
            tail = node;
            return;
        }

        node ->next = head;
        head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //为新的node节点申请内存,初始化
        Node* node = create_new_Node(val);
        ++ length;
        if(tail == NULL){
            this ->head = node;
            this ->tail = node;
            return;
        }
        tail ->next = node;
        tail = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(check_index(index) == false)
            return;
        ++length;
        
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == length){
            addAtTail(val);
            return;
        }
        //为新的node节点申请内存,初始化
        Node* node = create_new_Node(val);
        Node* temp = head;
        for(int i = 0;i < index-1; i++){
            temp = temp ->next;
        }
        node ->next = temp ->next; 
        temp ->next = node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(check_index(index) == false)
            return;
        --length;
        if(index == 0){
            Node* node = head;
            head = head-> next;
            if(length == 0)
                tail = NULL;
            //delete node;
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1; ++i) 
            cur = cur->next;
        cur ->next = cur ->next ->next;
        //delete p2;
    }
    
    /**
     * function:检查索引是否符合规范
     * @param index : 索引值
     * @return false　:不符合规范,　true: 符合规范
    */
    bool check_index(int index){
        return !(index < 0 || length < index + 1 || length == 0);
    }
    
    /**
     * function:创造新Node节点
     * @param val : Node节点val值
     * @return 新的Node节点
    */
    Node* create_new_Node(int val){
        Node* node;
        node = new Node();
        node ->val = val;
        node ->next = NULL;
        return node;
    }
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

#endif