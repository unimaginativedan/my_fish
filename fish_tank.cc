#include <iostream>
#include <cstdlib>
#include "fish_classes.h"

using namespace std;

void append_minnows(minnow* head);
void two_minnows(minnow* head);

void append_tuna(tuna* head);
void two_tuna(tuna* head);

void append_shark(shark* head);
void two_shark(shark* head);

int main() {
  
  srand(time(NULL));
  tuna t1;
  t1.init();
  
  minnow m1;
  m1.init();

  tuna *root;
  root = &m1;
  while(root->next!=NULL){
    root->found=0;
    cout<<root->found<<endl;
    root=root->next;
   
  }
  two_tuna(&m1);
  root=&m1;
  while(root->next!=NULL){
    cout<<"Init tuna position: "<< root->x << " " << root->y << "  " << root->z << endl;
    root=root->next;
    // for(int i=0;i<5;i++)
    //  root->move();
  }
    
  
  cout<<"Init minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;
  /*
  m1.move();
  cout<<"Next minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;
  
  m1.move();  
  cout<<"Next minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;
  
  m1.move();
  cout<<"Finl minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;
  */
  
}
