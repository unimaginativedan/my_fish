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

void tuna_eating(tuna* pred, minnow* prey);
void shark_eating(shark* pred, tuna* prey);

int main() {
  
  srand(time(NULL));


  /*-----------------------------------------------------------------------------------------
    Don't have enough time to initialise population properly or write all of the functions 
    so this main is just meant to show that the ones I have written do work.
    ---------------------------------------------------------------------------------------*/
  minnow minnow_school;
  minnow_school.init();
  minnow *minnow_root;
  
  minnow_root=&minnow_school;
  append_minnows(minnow_root);
  for(int j=0;j<2;j++){
    while(minnow_root!=NULL){
      for(int i=0;i<5;i++)
	minnow_root->move();
      minnow_root=minnow_root->next;
    }
  }

  tuna tuna_school;
  tuna_school.init();
  tuna *tuna_root;
  
  tuna_root=&tuna_school;
  append_tuna(tuna_root);
  for(int j=0;j<2;j++){
    while(tuna_root!=NULL){
      for(int i=0;i<5;i++)
	tuna_root->move();
      tuna_root=tuna_root->next;
    }
  }
  
  shark shark_pack;
  shark_pack.init();
  shark *shark_root;
  
  shark_root=&shark_pack;
  append_shark(shark_root);
  for(int j=0;j<2;j++){
    while(shark_root!=NULL){
      for(int i=0;i<5;i++)
	shark_root->move();
      shark_root=shark_root->next;
    }
  }
  // Measure the initial population of species.
  int minnow_population=0;
  minnow_root=&minnow_school;
  while(minnow_root!=NULL){
    minnow_population++;
    minnow_root=minnow_root->next;
  }

  int tuna_population=0;
  tuna_root=&tuna_school;
  while(tuna_root!=NULL){
    tuna_population++;
    tuna_root=tuna_root->next;
  }


  int shark_population=0;
  shark_root=&shark_pack;
  while(shark_root!=NULL){
    shark_population++;
    shark_root=shark_root->next;
  }

  cout<<"Minnow population is:"<< minnow_population<< endl;
  cout<<"Tuna population is:"<< tuna_population<< endl;
  cout<<"Shark population is:"<< shark_population<< endl;
  /*----------------------------------------------
    Chooses a species to move then a member of 
    that species to move L^3 times.
    ----------------------------------------------*/
  for(int j=0;j<125;j++){
    int choose = rand()%3;
    if(choose==0){
      int count=rand()%minnow_population;
      minnow_root=&minnow_school;
      for(int i=0;i<count;i++)
	minnow_root=minnow_root->next;
      minnow_root->move();
    }
    else if(choose==1){
      int count=rand()%tuna_population;
      tuna_root=&tuna_school;
      for(int i=0;i<count;i++)
	tuna_root=tuna_root->next;
      if(drand48()<0.9){
	tuna_root->move();
	tuna_eating(&tuna_school, &minnow_school);
      }
    }
    else{
      int count=rand()%shark_population;
      shark_root=&shark_pack;
      for(int i=0;i<count;i++)
	shark_root=shark_root->next;
      if(drand48()<0.9){
	shark_root->move();
	shark_eating(&shark_pack, &tuna_school);
      }
    }
  }
 minnow_population=0;
  minnow_root=&minnow_school;
  while(minnow_root!=NULL){
    minnow_population++;
    minnow_root=minnow_root->next;
  }

  tuna_population=0;
  tuna_root=&tuna_school;
  while(tuna_root!=NULL){
    tuna_population++;
    tuna_root=tuna_root->next;
  }


  shark_population=0;
  shark_root=&shark_pack;
  while(shark_root!=NULL){
    shark_population++;
    shark_root=shark_root->next;
  }
  cout<<"Minnow population is:"<< minnow_population<< endl;
  cout<<"Tuna population is:"<< tuna_population<< endl;
  cout<<"Shark population is:"<< shark_population<< endl;
}
