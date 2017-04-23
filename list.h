#pragma  once;
#include <assert.h>
#include<iostream>
#include <assert.h>
using namespace std;
template<class T>
struct __ListNode
{
     T  _data;
	 __ListNode<T>* _next;
	 __ListNode<T>* _prev;
	  __ListNode(const T& x)
		  :_data(x)
		  ,_next(NULL)
		  ,_prev(NULL)
	  {
	  }
};
template <class T,class Ref,class Ptr >
struct __ListIterator
{
	typedef  __ListNode<T>   Node;
    typedef  __ListIterator<T,Ref,Ptr> Self;
__ListIterator(Node* node)   
		:_node(node)
	{
	}
	Ref  operator*()
	{
	    return _node->_data;
	}
	Ptr  operator->()
	{
	    return &(_node->_data)
	}
	Self& operator++()
	{
	   _node=_node->_next;
	   return *this;
	}
	Self& operator--()
	{
		_node=_node->_prev;
		return *this;
	}
	Self operator++(int)
	{
		Self tmp=_node;
		_node=_node->_next;
		//return tmp;
		return Self(tmp) ; 
	}
	Self  operator--(int)
	{   
		Self tmp=(*this);
		_node=_node->_prev;
		return tmp;
	}
	bool operator!=(const Self& s) const
	{
	 return this->_node!=s._node;
	}
	bool operator==(const Self& s) const
	{
		return this->_node==s._node;
	}
	Node* _node;
};
template<class T>
struct List
{
    typedef  __ListNode<T> Node;
public:
	typedef  __ListIterator<T,T&,T*> Iterator;
	typedef  __ListIterator<T,const T&,const T*> ConstIterator;
	Node* GetNode(const T& x)
	{
		return new Node(x);
	}
	List()
	{
       _head=GetNode(T());
	   _head->_next=_head;
	   _head->_prev=_head;
	}
	Iterator Begin()
	{
	  return Iterator(_head->_next);
	}
	Iterator End()
	{
	  return Iterator(_head);
	}
	ConstIterator Begin() const
	{
		return ConstIterator(_head->_next);
	}
	ConstIterator End() const
	{
		return ConstIterator(_head);
	}
	 
	void PushBack(const T& x)
	{
	  /*  Node* _tail=_head->_prev;
		Node* tmp=GetNode(x);
		_tail->_next=tmp;
		tmp->_prev=_tail;
		tmp->_next=_head;
		_head->_prev=tmp;*/
		Insert(End(),x);
	}
  void PopBack()
  {
	 /* assert(_head->_prev );
      Node* tail=_head->_prev;
	  Node* prev=tail->_prev;
	  Node* next=tail->_next;
	  prev->_next=next;
	  next->_prev=prev;
	  delete tail;*/
	  Erase(--End());
  }
  void PushFront(const T& x)
  {
    /*assert(_head)
	  Node* tmp=GetNode(x);
      Node* next=_head->_next;

	  _head->_next=tmp;
	  tmp->_prev=_head;

	  tmp->_next=next;
       next->_prev=tmp;*/
	  Insert(Begin(),x);
  }
  void PopFront()
  {
	  /*assert(_head->_next);
     Node* tmp=_head->_next;
	 Node* next=tmp->_next;

     _head->_next= next;
	 next->_prev=_head;
	 delete tmp;*/

       Erase(Begin());
  }
 Iterator Insert(Iterator pos, const T& x)
 {
     assert(pos._node);
	 Node* tmp=GetNode(x);
	 Node* cur=pos._node;
	 Node* prev=cur->_prev;
	   
	 prev->_next=tmp;
	 tmp->_prev=prev;
	 tmp->_next=cur;
	 cur->_prev=tmp;
	 return  tmp;
 }
// Iterator  Erase(Iterator pos)
//{
//assert(pos._node && pos._node!=NULL);
//Node* tmp=pos._node;
////Node* itr=tmp;
//Node* next=tmp->_next;
//Node* prev=tmp->_prev;
//  
//next->_prev=prev;
//prev->_next=next;
//
//delete tmp;
//return Iterator(next);//next
//}

 Iterator  Erase(Iterator pos)
	 {
	 assert(pos._node && pos._node!=NULL);
	 Node* tmp=pos._node;
	 //assert(tmp->_next);
	 Node* itr=tmp->_next;
	 Node* next=tmp->_next;
	 Node* prev=tmp->_prev;
	   
	 next->_prev=prev;
	 prev->_next=next;
	 delete tmp;
	 
	 return Iterator(itr);//next
	 }


 
protected:
	Node* _head;
};
void PrintList(const List<int>& l)
{
	List<int>::ConstIterator It=l.Begin();
	while(It!=l.End())
	{ 
	   cout<<*It<<" ";
	   ++It;
	}
	cout<<endl;}
 void TestList2()
{
	List<int> l2;
	
	l2.PushBack(1);	 
	l2.PushBack(2);
	l2.PushBack(3);
	l2.PushBack(4);
   l2.PopBack(); 
    l2.PopBack(); 
	 l2.PopBack(); 
	  l2.PopBack(); 
	   l2.PopBack(); 
	PrintList(l2);
}
void TestList3()
{
	List<int> l3;
	l3.PushFront(1);
	l3.PushFront(2);
	l3.PushFront(3);
	l3.PushFront(4);
	l3.PopFront();
	l3.PopFront();
	l3.PopFront();
	PrintList(l3);
 
}
void TestList4()
{
    List<int>  l4;
	l4.PushBack(1);
	l4.PushBack(2);
	l4.PushBack(3);
	l4.PushBack(4);

	List<int>::Iterator it1=l4.Begin();

	while (it1!=l4.End())
	{
		cout<<*it1<<" ";
		it1++;
	}
	cout<<endl;
	List<int>::Iterator it=l4.Begin();
	while (it!=l4.End())
	{   
		l4.Erase(it);   
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	//List<int>::Iterator it2=l4.Begin();

	//while (it2!=l4.End())
	//{
	//	cout<<*it2<<" ";
	//	it2++;
	//}
	//cout<<endl;
 //
}




