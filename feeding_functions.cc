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
    return temp;
  }
  else return dead_fish;
    
}


void tuna_eating(tuna* predator, minnow* prey){
  int xcoord, ycoord, zcoord;
  cout<<"In tuna eating"<<endl;
  
  tuna* pred = predator;
  
  xcoord=pred->x;
  ycoord=pred->y;
  zcoord=pred->z;

  while(prey!=NULL){
   
    prey=minnow_getting_eaten(pred, prey, xcoord, ycoord, zcoord);
   
    if(prey!=NULL)
      prey=prey->next;
  }

}

tuna* tuna_getting_eaten(shark* pred, tuna* dead_fish, int xcoord, int ycoord, int zcoord){
  cout<<"In tuna getting eaten"<<endl;
  tuna* temp;
  
  if(dead_fish==NULL)
    return NULL;
  
  else if(dead_fish->x==xcoord && dead_fish->y==ycoord && dead_fish->z==zcoord){
    
    pred->eaten=1;
    temp = dead_fish->next;

    return temp;
  }
  else return dead_fish;
    
}



void shark_eating(shark* predator, tuna* prey){
  int xcoord, ycoord, zcoord;
  shark* pred = predator;
  
  xcoord=pred->x;
  ycoord=pred->y;
  zcoord=pred->z;
  int eaten=0;

  while(prey!=NULL){
    if(prey->x==xcoord && prey->y == ycoord && prey->z==zcoord)
      eaten=1;
    prey=tuna_getting_eaten(pred, prey, xcoord, ycoord, zcoord);
    if(eaten)
      break;
    if(prey!=NULL)
      prey=prey->next;
  }

}
