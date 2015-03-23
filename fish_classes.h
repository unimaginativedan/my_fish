#include <cstdlib>

using namespace std;

class fish {
 public:
  int x, y, z;
  int age, eaten;

  void init(){
    // Function to initialise fish position, age and status.
    age = 0;
    eaten=0;

    x=rand()%25;
    y=rand()%25;
    z=rand()%25;
  }
};

class minnow: public fish{
 public:
  void move(){
    x+=((rand()%3)-1)%25;
    y+=((rand()%3)-1)%25;
    z+=((rand()%3)-1)%25;
  }

};

class tuna: public fish{
 public:
  void move(){
    int diag;
    diag=rand()%3;
    if(diag==0) {
      // Move in xy plane.
      
    }
    else if(diag==1) {
      // Move in xz plane.
    }
    else {
      // Move in yz plane.
     
    }
  }

};
