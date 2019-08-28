
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
      Stack S1,S2;
     
      while (S.Isempty()!= true)
       S1.Push(S.Pop());           
                 //Pop elements from orignal stack S until it becomes empty and Push those elements into first additional stack S1
      while (S1.Isempty() != true)
       S2.Push(S1.Pop());
                 //Pop elements from first additional stack S1 until it becomes empty and Push those elements into second additional stack S2
      while (S2.Isempty() != true)
       S.Push(S2.Pop());
                 //Pop elements from second additional stack S1 until it becomes empty and Push those elements into original stack S
      
      S.read();  //Now, Print original Stack S
   }
     
};     
      
//Main Function
int main()
{ 
   Stack s1;
   s1.Push(6);
   s1.Push(7);
   s1.Push(8);
   cout<<"Stack Before Reversing."<<endl;
   s1.read();
  
   cout<<endl<<"Stack After Reversing."<<endl;
   s1.Reverse(s1);
   
   cout<<endl;
   
   system("pause");
   return 0;
}
