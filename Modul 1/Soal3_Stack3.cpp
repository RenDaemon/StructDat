#include <iostream>

using namespace std;

struct Dat{
    string data;
    Dat *next;
};

struct Stack{
    Dat *_peak;
    unsigned _size; 
};

void init(Stack *stack) {
    stack->_peak = NULL;
    stack->_size = 0;
}

bool isNULL(Stack *stack){
    return (stack->_peak == NULL);
}

void push(Stack *stack, string val){
    Dat *baru = new Dat;
    if(baru) {
        baru -> data = val;

        if(isNULL(stack)) baru->next = NULL;
        else baru->next = stack->_peak;

        stack->_peak = baru;
        stack->_size++;
    }
}

void pop(Stack *stack){
    if(!isNULL) {
        Dat *tmp = stack->_peak;
        stack->_peak = stack->_peak->next;
        free(tmp);
        stack->_size--;
    }
}

string peak(Stack *stack){
    if(!isNULL(stack)){
        return stack->_peak->data;
    }
    return 0;
}

void print(Stack *stack) {
    Dat *cur = stack->_peak;
   if (cur->data.length() > 100) {
    cout << "Jumlah String terlalu banyak" << endl;
    return;
   };
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
}



int main() {
    Stack stack;
    init(&stack);

    push(&stack, "Paling Tampan");
    push(&stack, "Priuk");
    push(&stack, "Mbah");
    push(&stack, "Cicit");
    push(&stack, "Jindan");
    push(&stack, "Habib");
    push(&stack, "Ane");
    pop(&stack);

    print(&stack);

    return 0;
}

