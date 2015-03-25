#include <iostream>
#include "fish_classes.h"
#include <cstdlib>

minnow* minnow_getting_eaten(tuna* pred, minnow* dead_fish, int xcoord, int ycoord, int zcoord){
  minnow* temp;
  if(dead_fish==NULL)
    return NULL;
  
  else if(dead_fish->x==xcoord && dead_fish->y==ycoord && dead_fish->z==zcoord){
    pred->eaten=1;
    temp = dead_fish->next;
    free(dead_fish);
    return temp;
  }
  else return dead_fish;
    
}


void tuna_eating(tuna* predator, minnow* prey){
  int xcoord, ycoord, zcoord;
  
  tuna* pred = predator;
  
  xcoord=pred->x;
  ycoord=pred->y;
  zcoord=pred->z;

  while(prey->next!=NULL){
    prey=minnow_getting_eaten(pred, prey, xcoord, ycoord, zcoord);
    prey=prey->next;
  }

}
