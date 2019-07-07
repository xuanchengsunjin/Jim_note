/**
 * author:jim_sun
 * function:circular queue
 * time:2017.07.07
 * github:
*/
#ifndef MYCIRCULARQUEUE_H
#define MYCIRCULARQUEUE_H
class MyCircularQueue {
private:
    int* data; //数据数组
    int head = -1;//头索引
    int tail = -1;//尾索引
    int size = 0;  //队列最大长度
    int length = 0; //队列长度大小　
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        k = k > 0? k : 8;
        data = new int[k];
        this -> size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()){
            return false;
        }
        length ++;
        head = (head + 1) % size;
        data[head] = value;
        tail = tail == -1 ? 0 : tail;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        tail = (tail + 1) % size;
        length --;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return data[tail];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return data[head];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return length == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return length == size;
    }

    ~ MyCircularQueue(){
        //析构函数释放data内存，防止内存泄露
        delete [] data;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
#endif