
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
   
   //Push function is basically to add element in the Stack
   //Here we are using it to enqueue element in the Queue
   void Push(int el, Node* &head, Node* &tail)
   {
   
      if(Isempty()) 
      {  
         top = new Node(el);
         tail = top;
         head = tail;
      }
      
      else
      {
        Node* t = new Node(el);
        tail->link(t);
        tail=top;
        tail=t;
      }
            
   }
   
   //Pop function is basically to remove element from the Stack
   //Here we are using it to dequeue element from the Queue
   int Pop(Node* &head)
   {
     if(!Isempty())
     { 
       Node *tmp;
       tmp=head;
       head=head->next1();
       return tmp->Getvalue();
       delete tmp;
     }
     else
     {
       cout<<"Stack is empty."<<endl;
     }       
   
   }    
};


//Implementation of Queue using Stack
class QueueS
{
    private:
    //Making object of Stack class
    Stack S;       
    Node *head;
    Node *tail;
    
    public:
    QueueS()
    {
       head=tail=NULL;
    }
    
    //To check whether the Queue is empty or not
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
       
       //Calling Push function of class Stack  
       S.Push(el,head,tail);
       
    }
    
    //dequeue function to remove element from the Queue
    int dequeue()
    {
       if(Isempty() != true)
       {
         
         //Calling Pop function of class Stack
         cout<<"The element dequeued from the queue is "<<S.Pop(head)<<endl;
         
       }
       else
       {
         cout<<"Queue is empty."<<endl;
       }    
    }
    
    //read function to print elements in the Queue
    void read()
    { 
       cout<<"Queue:"<<endl;
       if(Isempty())
       {
          cout<<"No elements... Queue is empty!"<<endl;
       }
       else
       {
          for(Node *i = head; i!=0; i= i->next1())
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
    Stack s;
    QueueS q1;
    q1.enqueue(10);
    q1.enqueue(9);
    q1.enqueue(11);
    q1.enqueue(12);
    q1.read();
    q1.dequeue();
    q1.dequeue();
    cout<<endl;
    q1.read();
 
    system("pause");
    return 0;
}
