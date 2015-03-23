#include <iostream>
#include <cstdlib>
#include "fish_classes.h"

using namespace std;

int main() {
  
  srand(time(NULL));
  minnow m1;
  m1.init();
  cout<<"Init minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;

  m1.move();
  cout<<"Next minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;

  m1.move();
  cout<<"Next minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;


  m1.move();
  cout<<"Finl minnow position: "<< m1.x << " " << m1.y << "  " << m1.z << endl;
}
