#include <iostream>

using namespace std;

struct Dat{
    int num;
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

void push(Stack *stack, int val){
    Dat *baru = new Dat;
    if(baru) {
        baru -> num = val;

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

int peak(Stack *stack){
    if(!isNULL(stack)){
        return stack->_peak->num;
    }
    return 0;
}

void print(Stack *stack) {
    Dat *cur = stack->_peak;
    while(cur != NULL){
        cout << cur->num << " ";
        cur = cur->next;
    }
}

Dat *getsmall(Stack *stack){
    Dat *cur =  stack->_peak;
    Dat *small = cur;

    while (cur != NULL){
        if(cur->num < small->num){
            small = cur;
        }
        cur = cur->next;
    }

    return small;  
}

int main() {
    Stack stack;
    init(&stack);

    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 8);
    push(&stack, 7);
    push(&stack, 9);
    push(&stack, 7);
    push(&stack, 10);
    pop(&stack);

    Dat *small = getsmall(&stack);
    cout << small->num << endl;
    cout << peak(&stack) << endl;
    print(&stack);

    return 0;
}

