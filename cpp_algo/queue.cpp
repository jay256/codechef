#include<iostream>
#include<cmath>

using namespace std;

template<class T>
class Queue{
	private:
		T *q;
		int front,rear,MaxSize;
	public:
		Queue(int MSize) : MaxSize(MSize){
			q=new T[MaxSize];
			rear=0;front=0;
		}
		~Queue(){
			delete [] q;
		}
		void AddQ(T item);
		T DeleteQ();
		/*inline bool QFull(){
			if(front == rear)
				return true;
			else
				return false;
		}
		inline bool QEmpty(){
			if(front == rear)
				return true;
			else
				return false;
		}*/
};

template<class T>
void Queue<T> :: AddQ(T item){
	rear =(++rear)%MaxSize;
	if(front == rear){
		cout << "Queue is full" << endl;
		if(!front)
			rear=MaxSize-1;
		else
			rear--;
		return;
	}
	else{
		//rear=(rear+1)%MaxSize;
		q[rear]=item;
		return;
	}
}

template<class T>
T Queue<T> :: DeleteQ(){
	if(front == rear){
		cout << "Queue is empty" << endl;
		return -1;
	}
	else{
		front=(++front)%MaxSize;
		T item=q[front];
		//front=(front+1)%MaxSize;
		return item;		
	}
}

int main(){
	Queue<int> q=Queue<int>(5);
	q.AddQ(1);
	q.AddQ(2);
	q.AddQ(3);
	q.AddQ(4);
	q.AddQ(5);
	q.AddQ(6);
	cout << q.DeleteQ() << endl;
	cout << q.DeleteQ() << endl;
	cout << q.DeleteQ() << endl;
	cout << q.DeleteQ() << endl;
	cout << q.DeleteQ() << endl;
	cout << q.DeleteQ() << endl;	
	return 0;
}
