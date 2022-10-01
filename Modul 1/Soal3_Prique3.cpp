#include <iostream>

using namespace std;

struct Dat {
    string data;
    Dat *next;
};

struct Prique{
    Dat *_peak;
    unsigned _size;
};

void init(Prique *queue){
    queue->_peak = NULL;
    queue->_size = 0;
}

bool isNULL(Prique *queue){
    return (queue->_peak == NULL);
}

void push(Prique *queue, string data){
    Dat *tmp = queue->_peak;
    Dat *baru = new Dat;
    queue->_size++;
    baru->data = data;
    baru->next = NULL;

    if(isNULL(queue)){
        queue->_peak = baru;
        return;
    }

    if (data.compare(queue->_peak->data) < 0){
        baru->next = queue->_peak;
        queue->_peak = baru;
    } else {
        while (tmp->next != NULL && (tmp->next->data).compare(data) < 0){
            tmp = tmp->next;
        }
        baru->next = tmp->next;
        tmp->next = baru;
    }
}

void pop(Prique *queue){
    if(!isNULL(queue)) {
       Dat *tmp = queue->_peak;
       queue->_peak = queue->_peak->next;
       free(tmp); 
    }
}

string Peak(Prique *queue){
    if(!isNULL(queue))
    return queue->_peak->data;
    else return 0;
}

void print(Prique *queue){
    Dat *cur = queue->_peak;
        if (cur->data.length() > 100) {
    cout << "Jumlah String terlalu banyak" << endl;
    return;
    }
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

int main() {
    Prique queue;
    init(&queue);

    push(&queue, "Masing - masing");
    print(&queue);
    cout << endl;

    push(&queue, "Ane");
    print(&queue);
    cout << endl;

    push(&queue, "ga");
    print(&queue);
    cout << endl;

    push(&queue, "berpaling");
    print(&queue);
    cout << endl;

    return 0;


}