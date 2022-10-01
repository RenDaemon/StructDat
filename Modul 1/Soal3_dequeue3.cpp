#include <iostream>

using namespace std;

struct Dat{
    string data;
    Dat *next, *prev;
};

struct Dqueue{
    Dat *_front, *_back;
    unsigned _size;
};

void init(Dqueue *queue){
    queue->_size = 0;
    queue->_back = NULL;
    queue->_front = NULL;
}

bool isNULL(Dqueue *queue){
    return (queue->_front == NULL && queue->_back == NULL);
}

void pushFront(Dqueue *queue, string value){
    Dat *baru = new Dat;
    if (baru) {
        queue->_size++;
        baru->data = value;

        if(isNULL(queue)){
            queue->_front = baru;
            queue->_back = baru;
            return;
        }
        baru->next = queue->_front;
        queue->_front->prev = baru;
        queue->_front = baru;
    }
}

void pushBack(Dqueue *queue, string value){
    Dat *baru = new Dat;
    if (baru) {
        queue->_size++;
        baru->data = value;
        
        if(isNULL(queue)){
            queue->_front = baru;
            queue->_back = baru;
            return;
        }
        baru->next = queue->_back;
        queue->_back->prev = baru;
        queue->_back = baru;
    }    
}

string Front(Dqueue *queue){
    if(isNULL(queue)){
        return queue->_front->data;
    }
    return 0;
}

string Back(Dqueue *queue){
    if(isNULL(queue)){
        return queue->_back->data;
    }
}

void popFront(Dqueue *queue){
    if(!isNULL(queue)){
        Dat *tmp = queue->_front;
        if (queue->_front == queue->_back){
            queue->_front = NULL;
            queue->_back = NULL;
            free(tmp);
        }
        else {
            queue->_front = queue->_front->next;
            queue->_front->prev = NULL;
            free(tmp);
            queue->_size--;
        }
    }
}

void popBack(Dqueue *queue){
    if(!isNULL(queue)){
        Dat *tmp = queue->_back;
        if(queue->_front == queue->_back){
            queue->_front = NULL;
            queue->_back = NULL;
            free(tmp);
        }
        else{
            tmp = queue->_back;
            queue->_back = queue->_back->prev;
            queue->_back->next = NULL;
            free(tmp);
            queue->_size--;
        }
    }
}

void print(Dqueue *queue){
    Dat *cur = queue->_front;
        if (cur->data.length() > 100) {
    cout << "Jumlah String terlalu banyak" << endl;
    return;
   }

    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main() {
    Dqueue queue;
    init(&queue);

    pushFront(&queue, "NT");
    pushFront(&queue, "Kita");
    pushFront(&queue, "Sewang");
    pushFront(&queue, "Sekali");
    pushFront(&queue, "Melayang");
    popFront(&queue);
    popBack(&queue);

    print(&queue);

    return 0;
}