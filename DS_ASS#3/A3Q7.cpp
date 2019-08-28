
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
      top=NULL;
   }
   
   //To check whether the Stack is empty or not.
   bool Isempty()
   {
      if(top==NULL) 
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
     if(Isempty()!=true)
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

bool Is_Matching_Pair(char ch1, char ch2)
{
    if(ch1 == '(' && ch2 == ')')
    return 1;
    else if(ch1 == '{' && ch2=='}')
    return 1;
    else if(ch1=='[' && ch2==']')
    return 1;
    else 
    return 0;
}


//Main Function
int main()
{
    Stack S;
    
    char str[100];
    int i=0;
    bool IsBalanced=true;     //Intializing bool variable IsBalanced as 'true'
    
    cout<<"Enter a string (A set of Parenthesis)."<<endl;
    cin.getline(str,100);     //Inputting a string
    
    cout<<endl;
    
    i=0;
    while(str[i] != 0)
    { 
        //If str[i] is a starting parenthesis then push it in the Stack         
        if(str[i]=='{' || str[i]=='(' || str[i]=='[')
        { 
                                                             
          S.Push(str[i]);
        }
        
        //If str[i] is a ending parenthesis then pop from the stack and check if the popped parenthesis is a matching pair or not
        if((str[i]=='}' || str[i]==')' || str[i]==']'))
        {   
            //If we see ending parenthesis without a pair then print Not Balanced
            if(S.Isempty()==true)
            {  
               cout<<str<<" is not Balanced."<<endl;
               system("pause");
               return 0;
            }
            
            //Pop the element from the Stack if it is not pair parenthesis of a character then there is a mismatch
            else if(!Is_Matching_Pair(S.Pop(),str[i]))
            {  
               cout<<str<<" is not Balanced."<<endl;
               system("pause");
               return 0;
            }           
                    
        }
        
        i++;
    } 
    
    //Checking whether the string of parenthesis is balanced or not 
    if(S.Isempty()==true)
    {
       cout<<str<<" is Balanced."<<endl;
    }
    else
    {
       cout<<str<<" is not Balanced."<<endl;
    }
    
    system("pause");
    return 0;
}
