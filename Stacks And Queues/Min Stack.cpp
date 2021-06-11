// By Chandramani Kumar
// Keep moving and must be simple bro!!!!!
// Espérons le meilleur mais préparez-vous au pire 😎


/* Problem Statement :

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.

Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1

NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 

*/


Cpp code :

stack<int> st1,st2;
MinStack::MinStack() {
    while(st1.size())
    st1.pop();

    while(st2.size())
    st2.pop();
}

void MinStack::push(int x) {
     st1.push(x);
        if(st2.empty() || x<=getMin())
            st2.push(x);
}

void MinStack::pop() {
    if(st1.empty())
    return;
    
    if(getMin()==st1.top())
            st2.pop();
        st1.pop();
}

int MinStack::top() {
    if(st1.empty())
    return -1;
    
    return st1.top();
}

int MinStack::getMin() {
    if(st2.empty())
    return -1;
    
    return st2.top()
;}
