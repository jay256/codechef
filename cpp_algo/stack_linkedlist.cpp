#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<stdexcept>

using namespace std;

template <class Type>
class Stack{
	private:
        struct node{
            Type data;
            struct node *link;    
        };
        struct node *top;

    public:
        Stack(){
            top=NULL;
        }
        ~Stack(){
            struct node *temp;
            while(top){
                temp=top;
                top=top->link;
                delete temp;
            }
        }
        bool Add(const Type item);
        Type Delete();
        inline bool StackEmpty(){
            if(top)
                return false;
            else
                return true;
        }
};

template<class Type>
bool Stack<Type> :: Add(const Type item){
    struct node *temp=new node;
    if(temp){
        temp->data=item;
        temp->link=top;
        top=temp;
        return true;
    }
    else{
        cout << "Out of space" << endl;
        return false;
    }
}

template<class Type>
Type Stack<Type> :: Delete(){
    if(StackEmpty()){
        throw out_of_range("Stack<>::top(): empty stack");
    }
    else{
        struct node *temp;
        Type item=top->data;
        temp = top;
        top = top->link;
        delete temp;
        return item;
    }
}

int main(){
    Stack<int> stack=Stack<int>();
    stack.Add(1);
    stack.Add(2);
    stack.Add(3);
    stack.Add(4);
    stack.Add(5);
    cout << stack.Delete() << endl;
    cout << stack.Delete() << endl;
    cout << stack.Delete() << endl;
    cout << stack.Delete() << endl;
    cout << stack.Delete() << endl;
    cout << stack.Delete() << endl;
    return 0;
}
