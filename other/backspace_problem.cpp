#include<iostream>
using namespace std;

char array[100];
int top = -1;


void push(char c)
{
  top++;
  array[top] = c;
};


void pop()
{
  if(top!= -1)
  {
    top = top - 1;
  }

  else
  {
    top = -1;
  }
};


int main()
{
   string input;
   cout<<"ENTER THE INPUT STRINGS \n ";
   cin>>input;

   int i;
   for(i=0;i<input.size();i++)
   {
      if(input[i] == '#')
      {
        pop();
      }

      else
      {
        push(input[i]);
      }

   }

  cout<<"THE FINAL STRING IS \n";
  for(i=0;i<=top;i++)
  {
    cout<<array[i];
  }

}
