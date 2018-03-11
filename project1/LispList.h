/*
 *     Credit to MORIN
 */

#ifndef LISPLIST_H_
#define LISPLIST_H_
#include <stdlib.h>

using namespace std;

template<class T>
class LispList {
	T null;
protected:

	class Node {
	public:
		T x;
		Node *next;
		Node(T x0) {
			x = x0;
			next = NULL;
		}
	};
	Node *head;
	Node *tail;
	int n;
	LispList<T>& copy(Node *);

public:

	LispList();
	~LispList();
	T push(T x);
	T add(T x);
	T peek();
	T remove();
	T pop();
	int size();
	LispList(const LispList<T>&);
	T first();
	LispList<T> rest(LispList);
	void print();
	LispList<T> operator =(const LispList<T> &);
	void clear();
	LispList<T> append(LispList<T>, LispList<T> &);
	template<typename A, typename B, typename C>
	LispList<A> map(function<A(B,C)>, LispList<B>&, int);
};

template<class T>
LispList<T>:: LispList() {
  n = 0;
  head = tail = NULL;
}

template<class T>
LispList<T>:: ~LispList() {
  Node *u = head;
  while (u != NULL) {
    Node *w = u;
    //delete w;
		u = u->next;
  }
}

template<class T>
T LispList<T>:: add(T x) {
  Node *u = new Node(x);
  if (n == 0) {
    head = u;
  } else {
    tail->next = u;
  }
  tail = u;
  n++;
  return x;
}

	template<class T>
	int LispList<T>:: size() {
		return n;
	}

	template<class T>
	T LispList<T>:: peek() {
		return head->x;
	}

	template<class T>
	T LispList<T>:: push(T x) {
		Node *u = new Node(x);
		u->next = head;
		head = u;
		if (n == 0)
			tail = u;
		n++;
		return x;
	}

	template<class T>
	T LispList<T>:: remove() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	template<class T>
	T LispList<T>:: pop() {
		if (n == 0)	return null;
		T x = head->x;
		Node *u = head;
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	/*
	*This copy method takes a node pointer, and it return
	*the reference of LispList.
	*
	*/
	template<class T>
	LispList<T>& LispList<T>:: copy(Node * oldPtr)
	{
			Node * copyPtr;
		while(oldPtr!=NULL)//It check if the ptr is empty or not
		{
			//Here is the step to create the node one by one
			//First create a new node pointer and point to the old pointer
			//Then, access the pointer's data, and add it in to the new pointer.
			if(head==NULL)//If it is empty, then create new node.
			{
				head=copyPtr=new Node(oldPtr->x);
			}
			else//create new nodes.
			{
				copyPtr->next=new Node(oldPtr->x);
				copyPtr=copyPtr->next;
			}
			oldPtr=oldPtr->next;
			n++;//increment the size of the Lisplist
		}
		tail=copyPtr;//After the insertion, set the pointer to tail.
		copyPtr->next=NULL;//Set the pointer next to NULL
		return (*this);//return the reference.
	}

	/*
	*The print function, take no parameter and return nothing.
	*it walk through to whole LispList, then cout the data
	*it print out with parentheses and comma
	*/
	template<class T>
	void LispList<T>::print()
	{
		Node * ptr= head;
		if(ptr->next==NULL)
		{
			std::cout<<"("<<ptr->x<<")";
		}
		else
		{
			std::cout<<"(";
			while(ptr->next!=NULL)
			{
				std::cout<<ptr->x<<", ";
				ptr=ptr->next;
			}
			std::cout<<ptr->x<<")";
		}
		std::cout<<endl;
	}

	/*
	*The first function takes no parameter and return a data.
	*it check whether the head is empty or no
	*if it is empty, then do nothing
	*else return the data
	*/
	template<class T>
	T LispList<T>:: first()
	{
		if(head!=NULL)
		return head->x;
	}

	/*
	*The rest function takes a copy of the LispList, and return a LispList
	*
	*/
	template<class T>
	LispList<T> LispList<T>:: rest(LispList List)
	{
		if(List.head!=NULL)//if the headd is not empty, the pop the head
		List.pop();
		return List;
	}

	/*
	*The copy constructor takes the reference of the oldList
	*initialize the list of this, then call the copy method
	*the copy method takes the oldList.headd
	*/
	template<class T>
	LispList<T>:: LispList(const LispList<T>& oldList)
	{
		LispList();
		copy(oldList.head);
	}

	/*
	*The equal overloading operator takes the reference of oldList, and return
	*the LispList
	*/
	template<class T>
	LispList<T> LispList<T>::operator=(const LispList<T> &oldList)
	{
		if(head!=NULL)//if the head of this is not empty
			this->clear();//then it is going to call the clear function to clear the data
		return (copy(oldList.head));//it call the copy method function and return it
	}

/*
*The clear function, it delete all the elements in the LispList
*/
	template<class T>
	void LispList<T>::clear()
	{
		Node *ptr = head;//set the pointer equal head
		while (ptr)
		{
			head=ptr->next;//move the head to next
			delete ptr;//delete the currunt ptr
			ptr=head;//set the pointer = head
			n--;// size decrement
		}
		if(ptr==NULL)//if the pointer is NULL, set the size of LispList to 0
		{
			n=0;
		}
	}
	/*
	*The append function takes the copy of List, and the reference of the secondList
	*It return a LispList.
	*/
	template<class T>
	LispList<T> LispList<T>::append(LispList<T> firstList, LispList<T>& secondList)
	{
		if(secondList.n==0)//if the secondList is NULL
			return firstList;//return firstList
		else if(firstList.n==0)//if the firstList is NULL
			return secondList;//return the secondList
		else
		{
		firstList.tail->next=secondList.head;//point the firstList tail to the head of secondList
		firstList.tail=secondList.tail;//set firstList tail = secondList tail
		firstList.n+=secondList.n;//combine the size
		}
		return firstList;//return the list
	}

	/*
	*The map function takes the function, the reference of list , and an int
	*return a list
	*/
	template<class T>
	template<typename A, typename B, typename C>//three template type
	LispList<A> LispList<T>::map(function<A(B,C)> func, LispList<B>& List, int num)
	{
		LispList<A> newList;
		Node * ptr=List.head;//the pointer points to the head
		while(ptr)
		{
			newList.add(func(ptr->x, num));//add the after the data the fucntion is executed
			ptr=ptr->next;//move to the next pointer
		}
		return newList;//return a list
	}


#endif /* LISPLIST_H_ */
