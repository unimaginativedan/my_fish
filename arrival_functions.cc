#include "fish_classes.h"
#include <cstdlib>


void append_minnows(minnow* head){
  
  while(head->next!=NULL){
    head=head->next;
  }
  
  for(int i=0;i<3;i++){
    head->next = new minnow;
    (head->next)->init();
    (head->next)->x=head->x;
    (head->next)->y=head->y;
    (head->next)->z=head->z;
    (head->next)->found=1;
    head=head->next;
  }

}

void append_tuna(tuna* head){
  
  while(head->next!=NULL){
    head=head->next;
  }
  
  head->next = new tuna;
  (head->next)->init();
  (head->next)->x=head->x;
  (head->next)->y=head->y;
  (head->next)->z=head->z;
  (head->next)->found=1;
  head=head->next;
  

}

void append_shark(shark* head){
  
  while(head->next!=NULL){
    head=head->next;
  }
  
  head->next = new shark;
  (head->next)->init();
  (head->next)->x=head->x;
  (head->next)->y=head->y;
  (head->next)->z=head->z;
  (head->next)->found=1;
  head=head->next;
  

}
void two_minnows(minnow* head){
  
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

    // Ensuring that not double counting
    root->found=1;

    while(search!=NULL){
      if(search->x==xcoord && search->y==ycoord && search->z==zcoord && search->found!=1){
	// If statement ensures that minnows at common sites
	// are found and that no double counting occurs.
	search->found=1;
	num_minnows++;
      }	
      search=search->next;
    }

    if(num_minnows>=2){
      // Whether or not to reproduce.
      append_minnows(head);
    }
    root=root->next;
    while( root!=NULL && root->found==1){
      // Making sure not to check sites already accounted for/last site
      root=root->next;
    }
  }
  while(head!=NULL){
    head->found=0;
    head=head->next;
  }
  
}

void two_tuna(tuna* head){
  
  tuna* root = head;
  tuna *search;
  int xcoord, ycoord, zcoord, num_tuna, num_fed_tuna;
  while(root!=NULL){
    
    // Run through list of tuna to see if there are two at any given site.
    xcoord=root->x;
    ycoord=root->y;
    zcoord=root->z;
   
    search=root;
  
    // Variable to count the number of tuna in common at a site.
    num_tuna=1;
    if(search->eaten=1)
      num_fed_tuna=1;
    else
      num_fed_tuna=0;
   
    // Ensuring that no double counting.
       
    while(search!=NULL){
      cout<< search->found << endl;
      if(search->x==xcoord && search->y==ycoord && search->z==zcoord && search->found!=1){
	// If statement ensures that tuna at common sites are found
	// and that no double counting occurs.

	search->found=1;
	num_tuna++;
	if(search->eaten)
	  num_fed_tuna++;
      }	

      search=search->next;
    }

    if(num_fed_tuna>=2){

      append_tuna(head);
    }
    root=root->next;

    while( root!=NULL && root->found==1){
      // Making sure not to check sites already accounted for.

      root=root->next;

    }

  }

  while(head!=NULL){
    head->found=0;
    head=head->next;
  }
  
}

void two_shark(shark* head){
  
  shark* root = head;
  shark *search;
  int xcoord, ycoord, zcoord, num_shark, num_fed_shark;
  while(root!=NULL){
    
    // Run through list of shark to see if there are two at any given site.
    xcoord=root->x;
    ycoord=root->y;
    zcoord=root->z;
    //    
    search=root;
  
    // Variable to count the number of shark in common at a site.
    num_shark=1;
    if(search->eaten=1)
      num_fed_shark=1;
    else
      num_fed_shark=0;
   
    // Ensuring that no double counting.
    //root->found=1;
     
    while(search!=NULL){
      cout<< search->found << endl;
      if(search->x==xcoord && search->y==ycoord && search->z==zcoord && search->found!=1){
	// If statement ensures that shark at common sites are found
	// and that no double counting occurs.

	search->found=1;
	num_shark++;
	if(search->eaten)
	  num_fed_shark++;
      }	

      search=search->next;
    }

    if(num_fed_shark>=2){

      append_shark(head);
    }
    root=root->next;

    while( root!=NULL && root->found==1){
      // Making sure not to check sites already accounted for.

      root=root->next;

    }

  }

  while(head!=NULL){
    head->found=0;
    head=head->next;
  }
  
}
