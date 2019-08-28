
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
   
   //topp function to return top of the stack
   int topp()
   {
       if(Isempty()==true)
       {
           cout<<"Stack is empty."<<endl;
       }
       else
       {
           return top->Getvalue();
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
 
   //To arrange elements on stack in Ascending Order
   void Ascending_Order(Stack &S)
   {
      Stack S1;
      
        while(S.Isempty()!=true)
        {  
           int temp = S.Pop();  //Poping elements from original stack and assigning it to variable temp
          
           while (S1.Isempty()!=true && temp<S1.topp())
               S.Push(S1.Pop());    
               //Pop elements from the Stack S1 until it becomes empty and temp is less than the top of stack S1 then
               //Push those elements into the original stack S
               
           S1.Push(temp);  //Now Push temp into stack S1.
        }
        
        while(S1.Isempty()!=true)
               S.Push(S1.Pop());   //Pop elements from additional stack S1 until it becomes empty and Push it into original stack S
         
    S.read();      //Printing original stack S
      
   }  
};

//Main Function           
int main()
{ 
   Stack S;
   S.Push(14);
   S.Push(11);
   S.Push(18);
   S.Push(16);
   cout<<"Elements on the Stack S."<<endl;
   S.read();
   
   cout<<endl<<"Elements on the Stack S in Ascending Order."<<endl;
   S.Ascending_Order(S);
   
   cout<<endl;
   
   system("pause");
   return 0;
}
