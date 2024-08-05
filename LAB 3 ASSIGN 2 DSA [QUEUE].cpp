#include <iostream>
using namespace std;
int queue[5], n = 5, front = - 1, rear = - 1;
void enqueue()
{
  int val;
if(rear == n-1)
  cout<<"queue overflow"<<endl;
  else
{
  if(front==-1)
  front=0;
    cout<<"enter first element"<<endl;
    cin>>val;
  rear++;
queue[rear]=val;
  }
}

void dequeue()
{
  if(front==-1||front>rear)
    cout<<"queue underflow"<<endl;
  else{
    cout<<"deleted element is"<<queue[front]<<endl;
    front++;
  }
}
void display()
{
  int i;
  for( i=front;i<=rear;i++)
    cout<<queue[i]<<endl;
  }

  int main()
   { 
      int ch;
      cout<<"1) enqueue"<<endl;
      cout<<"2) dequeue"<<endl;
      cout<<"3) Display "<<endl;
      cout<<"4) Exit"<<endl;
      do{
          cout<<"Enter choice :"<<endl;
          cin>>ch;
          switch(ch)
          {
              case 1 :{
          cout<<"insertion of element: "<<endl;
                   enqueue();
                    break;
              }
              case 2 :{
                cout<<"deletion of element"<<endl;
                  
                 dequeue();
                  break;
              }
          case 3 :{
                  display();
                  break;
          }
          case 4 :{
                  cout<<"Exit"<<endl;
                  break;
          }
          default :{
                  cout<<"Invalid choice "<<endl;
          }
      }  
      }while(ch!=4);
      
      return 0;
       }

