
// Name: Muhammad Fawad Jawaid Malik
// Roll No. 11k-2116
// Section: B

#include<iostream>

using namespace std;

//Node class to create Linked List
class Node
{
   private:
   int value;
   Node *next;
   
   public:
   Node(int el)
   {
      value=el;
      next=NULL;
   }
   
   int Getvalue()
   {
      return value;
   }
   
   Node *next1()
   {
      return next;
   }
   
   void link(Node *node)
   {
      next=node;
   }
};

//Implementation of Queue using Linked List
class Queue
{
    private:
    Node *head;
    Node *tail;
    
    public:
    Queue()
    {
       head=tail=NULL;
    }
    
    //To check whether the Queue is empty or not.
    bool Isempty()
    {
       if(head==NULL) 
           return true;
       else 
           return false;
    }    
    
    //enqueue function to add element in the Queue
    void enqueue(int el)
    {
       if(Isempty()) 
       {
         tail = new Node(el);
         head=tail;
       }
       else
       {
         Node *t =new Node(el);
         tail->link(t);
         tail=t;
       }
    }
    
    //dequeue function to remove element from the Queue
    int dequeue()
    {
       if(Isempty() != true)
       {
         Node *tmp;
         tmp=head;
         head=head->next1();    
         return tmp->Getvalue();
         delete tmp;
       }
       else
       {
         cout<<"Queue is empty."<<endl;
       }    
    }
    
    //read function to print elements in the Queue
    void read()
    { 
       cout<<"Queue."<<endl;
       for(Node *i = head; i!=0; i= i->next1())
       {
        cout<<i -> Getvalue()<<" ";
       }
       cout<<endl;      
    }
};


//Implementation of Stack using Linked List
class Stack
{
   private:
   Node *top;
   
   public:
   Stack()
   {
      top=0;
   }
   
   //To check whether the Stack is empty or not.
   bool Isempty()
   {
      if(top==0) 
        return true;
      else 
        return false;  
   }
   
   //Push function to add element in the Stack
   void Push(int el)
   {
   
      if(Isempty()) 
        top = new Node(el);
      else
      {
        Node *t =new Node(el);
        t->link(top);
        top=t;
      }
            
   }
   
   //Pop function to remove element from the Stack
   int Pop()
   {
     if(!Isempty())
     { 
       Node *tmp;
       tmp=top;
       top=top->next1();
       return tmp->Getvalue();
       delete tmp;
     }
     else
     {
       cout<<"Stack is empty."<<endl;
     }       
   
   }
   
   //read function to print the Stack
   int read()
   {
       for(Node *i = top; i!=0; i= i->next1())
       {
        cout<<i -> Getvalue()<<" ";
       }
       cout<<endl;
   } 
   
   //To Reverse the order of Stack
   void Reverse(Stack S)
   {
      Queue Q;
     
      while (S.Isempty() != true)
       Q.enqueue(S.Pop());
                   //Pop elements from orignal stack S until it becomes empty and enqueue those elements into additional queue Q
      while (Q.Isempty() != true)
       S.Push(Q.dequeue());
                   //dequeue elements from queue Q until it becomes empty and Push those elements into stack S 
    
      S.read();    //Now, Print original Stack S
   }
     
};     

//Main Function
int main()
{ 
   Stack s1;
   s1.Push(6);
   s1.Push(7);
   s1.Push(8);
   s1.Push(9);
   cout<<"Stack Before Reversing."<<endl;
   s1.read();
   
   cout<<endl<<"Stack After Reversing."<<endl;
   s1.Reverse(s1);
   
   cout<<endl;
   
   system("pause");
   return 0;
}   
