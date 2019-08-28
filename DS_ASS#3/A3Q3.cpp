
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
    
    //enqueue function is basically to add element in the Queue
    //Here we are using it to Push element in the Stack
    void enqueue(int el, Node*& top)
    {
       if(Isempty()) 
       {
         head = new Node(el);
         top=head;
       }
       else
       {
         Node *t =new Node(el);
         t->link(top);
         top=head;
         top=t;
       }
    }
    
    //dequeue function is basically to remove element from the Queue
    //Here we are using it to Pop element from the Stack
    int dequeue(Node* &top)
    {
       if(Isempty() != true)
       {
         Node *tmp;
         tmp=top;
         top=top->next1();    
         return tmp->Getvalue();
         delete tmp;
       }
       else
       {
         cout<<"Queue is empty."<<endl;
       }    
    }
    
};


//Implementation of Stack using Queue
class StackQ
{
   private:
   Node *top;
   //Making object of Queue class
   Queue Q;
   
   public:
   StackQ()
   {
      top=0;
   }
   
   //To check whether the Stack is empty or not
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
      
      //Calling enqueue function of class Queue   
      Q.enqueue(el,top);
               
   }
   
   //Pop function to remove element from the Stack
   int Pop()
   {
     if(!Isempty())
     { 
       
       //Calling dequeue function of class Queue
       cout<<"The element popped from the stack is "<<Q.dequeue(top)<<endl;
       
     }
     else
     {
       cout<<"Stack is empty."<<endl;
     }       
   
   }
   
   //read function to print elements in the Stack
   int read()
   {
       cout<<"Stack:"<<endl;
       if(Isempty())
       {
         cout<<"No elements... Stack is empty!";
       }
       else
       {
          for(Node *i = top; i!=0; i= i->next1())
          {
            cout<<i -> Getvalue()<<" ";
          }
       }
       cout<<endl;
   } 
};

//Main Function
int main()
{
   StackQ s1;
   s1.Push(6);
   s1.Push(7);
   s1.Push(8);
   s1.Push(9);
   s1.read();
   s1.Pop();
   s1.Pop();
   cout<<endl;
   s1.read();
   
   cout<<endl;
   
   system("pause");
   return 0;
}
