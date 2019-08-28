
// Name: Muhammad Fawad Jawaid Malik
// Roll No. 11k-2116
// Section: B

#include <iostream>

using namespace std;

//Node class to create Linked List
class Node
{
   private:
   char value;
   Node *next;
   
   public:
   Node(char el)
   {
      value=el;
      next=NULL;
   }
   
   char Getvalue()
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
   void Push(char el)
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
   char Pop()
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
};

//Main Function
int main()
{
    Stack S;
    
    char str[100];
    int i=0;
    bool IsPalindrome=true;     //Intializing bool variable Ispalindrome as 'true'
    
    cout<<"Enter a string (All letters should be in lower subscript or in higher subscript)"<<endl;
    cin.getline(str,100,'\n');    //Inputting a string
    
    cout<<endl;
    
    i=0;
    while(str[i] != 0)
    {
        S.Push(str[i]);   //Push letters of string in stack S until string pointer is not equal to 0
        i++;
    }
    
    i=0;
    while(S.Isempty()!=true)
    {
                            
        char k=S.Pop();   //Pop elements from stack S until it becomes empty
        
        if(k!=str[i])
        {
            IsPalindrome=false;
            break;
        }
        
        i++;
    } 
    
    //Checking whether string is Palindrome or not
    if(IsPalindrome)
    {
       cout<<"\""<<str<<"\""<<" is a Palindrome."<<endl;
    }
    else
    {
       cout<<"\""<<str<<"\""<<" is not a Palindrome."<<endl;
    }
    
    system("pause");
    return 0;
}
