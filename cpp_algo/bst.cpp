#include<iostream>
#include<cstdlib>
#define NULL 0

template<class T>
class TreeNode{
	friend class BSTree;
	private:
		TreeNode *lChild,*rChild;
		T data, int leftSize;
};

template<class T>
class BSTree{
	private:
		TreeNode *tree;
		TreeNode *Search(TreeNode *t, T x);
	public:
		BSTree(){
			tree=NULL;
		}
		~BSTree(){
			delete tree;
		}
		TreeNode *Search(T x);
		TreeNode *ISearch(T x);
		TreeNode *KSearch(int k);
		void Insert(T x);
		void Delete(T x);
};

template<class T>
TreeNode * BSTree<T> :: Search(T x){
	return Search(tree,x);
}

template<class T>
TreeNode *BSTree<T> :: Search(TreeNode *t, T x){
	if(t==NULL)
		return NULL;
	else if(x == t->data)
		return t;
	else if(x < t->data)
		return Search(t->lChild,x);
	else if(x > t->data)
		return Search(t->rChild,x);
}

template<class T>
TreeNode *BSTree<T> :: ISearch(T x){
	bool found = false;
	TreeNode *t=tree;
	while((t) && !found){
		if(x == t->data)
			found=true;
		else if(x < t->data)
			t = t->lChild;
		else
			t = t->rChild;
	}
	if(found)
		return t;
	else
		return NULL;
}

template<class T>
TreeNode *BSTree<T> :: KSearch(int k){
	bool found=false;
	TreeNode *t=tree;
	while((t) && !found){
		if(k==t->leftSize)
			found=true;
		else if(k<t->lefSize)
			t=t->lChild;
		else{
			k-=t->leftSize;
			t=t->rChild;
		}
	}
	if(found)
		return t;
	else
		return NULL;
}

template<class T>
void BSTree<T> :: Insert(T x){
	bool found=false;
	TreeNode *p=tree,*q;
	while((p) && !found){
		q=p;	
		if(x==p->data)
			found=true;
		else if(x<p->data)
			p=p->lChild;
		else
			p=p->rChild;
	}
	if(!found){
		p=tree;
		TreeNode *tmp;
		while((p)){
			tmp=p;
			if(x<p->data){
				p->leftSize+=1;
				p=p->lChild;
			}
			else{
				p=p->rChild;
			}
		}
		p=new TreeNode;
		p->lChild=NULL;
		p->rChild=NULL;
		p->leftSize=1;
		p->data=x;
		if(tree){
			if(x < q->data)
				q->lChild = p;
			else
				q->rChild = p;
		}
		else
			tree = p;
	}
}

template<class T>
void BSTree<T> :: Delete(T x){
	TreeNode *p, *tmp;
	p=Search(x);
	if(p!=NULL){
		if(p->lChild==NULL && p->rChild==NULL){
			tmp=p;
			p=NULL;
			delete tmp;
		}
		else if(p->lChild==NULL){
			tmp=p;
			p=p->rChild;
			delete tmp;
		}
		else if(p->rChild==NULL){
			tmp=p;
			p=p->lChild;
			delete tmp;
		}
		else{
			
		}	
	}
}
