#include <iostream>
#include <cstdlib>
#include "fish_classes.h"

using namespace std;

void append_minnows(minnow* head);
void two_minnows(minnow* head);

int main() {
  
  srand(time(NULL));
  minnow m1;
  m1.init();
  
  append_minnows(&m1);
  minnow *root;
  root = &m1;
  while(root->next!=NULL){
    root->found=0;
    cout<<root->found<<endl;
    root=root->next;
   
  }
  two_minnows(&m1);
  root=&m1;
  while(root->next!=NULL){
    cout<<"Init minnow position: "<< root->x << " " << root->y << "  " << root->z << endl;
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
