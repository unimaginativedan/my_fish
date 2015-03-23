#include <iostream>
#include <cstdlib>
#include "fish_classes.h"

using namespace std;

int main() {
  
  srand(time(NULL));
  shark s1;
  s1.init();
  cout<<"Init shark position: "<< s1.x << " " << s1.y << "  " << s1.z << endl;

  s1.move();
  cout<<"Next shark position: "<< s1.x << " " << s1.y << "  " << s1.z << endl;
  
  s1.move();  
  cout<<"Next shark position: "<< s1.x << " " << s1.y << "  " << s1.z << endl;
  
  s1.move();
  cout<<"Finl shark position: "<< s1.x << " " << s1.y << "  " << s1.z << endl;

  
}
