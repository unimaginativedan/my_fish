#include "fish_classes.h"
#include <cstdlib>


void append_minnows(minnow* head){
  
  while(head->next!=NULL){
    head=head->next;
  }
  for(int i=0;i<3;i++){
    minnow* head->next = new minnow;
    (head->next)->init();
    (head->next)->x=head->x;
    (head->next)->y=head->y;
    (head->next)->z=head->z;
    (head->next)->found=1;
    head=head->next;
  }

}

fish* two_minnows(minnow* head){
  
  minnow* root = head;
  minnow *search;
  int xcoord, ycoord, zcoord, num_minnows;
  while(root!=NULL){
    // Run through list of minnows to see if there are two at any given site.
    xcoord=root->x;
    ycoord=root->y;
    zcoord=root->z;
    search=root;
    // Variable to count the number of minnows in common at a site.
    num_minnows=0;
    // Ensuring that
    root->found=1;
    while(search!=NULL){
      if(search->x==xcoord && search->y==ycoord && search->z==zcoord && search->found==0){
	// If statement ensures that minnows at common sites are found
	// and that no double counting occurs.
	search->found=1;
	num_minnows++;
      }	
      search=search->next;
    }
    if(num_minnows>=2)
      append_minnows(head);
    
    root=root->next;
    while(root->found==1){
      // Making sure not to check sites already accounted for.
      root=root->next;
    }
  }
  while(head!=NULL){
    head->found=0;
    head=head->next;
  }
  
}
