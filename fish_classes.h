#include <cstdlib>
#include <iostream>

using namespace std;

class fish {
  // Base class that defines all fish.
 public:
  int x, y, z;
  int age, eaten;
  int found;  // Property used when searching through tank for move/breed/feed.
  
  fish *next;
  
  
  
  void init(){
    // Function to initialise fish position, age and status.
    found=0;
    age=0;
    eaten=0;
    x=rand()%5;
    y=rand()%5;
    z=rand()%5;
    next=NULL;
  }
  
  void position_plusminus( int &k){
    // Used in many move functions useful to have.
    if(rand()%2)
      k=(k+1)%5;
    else
      k=(k+4)%5;
  }
  
};

class minnow: public fish{
  // Derived class that defines minnows, specifically how they move.
 public:
 

  void move(){
    
    x=(x+((rand()%3)-1))%5;
    y=(y+((rand()%3)-1))%5;
    z=(z+((rand()%3)-1))%5;
  }
};

class tuna: public fish{
 public:
  // If a shark moves 5 times without eating it dies.
  int age, eaten;
  // Derived class that defines tuna, specifically how they move.
  void move(){
    
    age++;
    // Choose which diagonal plane to move in.
    int diag;
    diag=rand()%3;
    switch (diag){
    case 0:
      plane_move(x,y);
      break;
    case 1:
      plane_move(x,z);
      break;
    case 2:
      plane_move(y,z);
      break;
    default :
      cout << "Error choosing plane"<< endl;
    }    
  }
  
  void plane_move(int &i, int &j){
    // Given a plane choose a diagonal.
    position_plusminus(i);
    position_plusminus(j);
  }


};

class shark: public fish{
 public:
  // If a shark moves 5 times without eating it dies.
  int age, eaten;
  
  // Derived class that defines sharks, specifically how they move.
  void move(){
   
    age++;
    
    // Choose which plane to move in.
    int diag;
    diag=rand()%3;
    switch (diag){
    case 0:
      plane_move(x,y);
      break;
    case 1:
      plane_move(x,z);
      break;
    case 2:
      plane_move(y,z);
      break;
    default :
      cout << "Error choosing plane"<< endl;
    }    
  }
  
  void plane_move(int &i, int &j){
    // Given a plane choose a diagonal.
    int dir=rand()%4;
    switch(dir){
    case 0:
      i=(i+2)%5;
      position_plusminus(j);
      break;
    case 1:
      j=(j+2)%5;
      position_plusminus(i);
      break;
    case 2:
      j=(j+3)%5;
      position_plusminus(i);
      break;
    case 3:
      i=(i+3)%5;
      position_plusminus(j);
      break;
    default:
      cout << "Error moving shark"<< endl;
    }
  }

  

};
