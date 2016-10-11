#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node *list){
  printf("[");
  if(list-> i == NULL && list ->next== NULL){
    printf("]\n");
  }
  else{
    while(list->next){
      printf("%d,", list -> i);
      list = list ->next;
    }
    printf("%d", list ->i);
    printf("]\n");
  }
}
struct node *insert_front(struct node *list , int new){
  struct node *newList = (struct node *)malloc(sizeof(struct node));
  newList ->i = new;
  newList -> next = list;
  return newList;
}

struct node *free_list(struct node *list){
  struct node *temp,*start;
  start = list;
  while(list){
    temp = list ->next;
    list -> i = NULL;
    list -> next = NULL;
    free(list);
    list = temp;
  }
  return start;
}


int main(){
  struct node *nod, *shake, *yes, *no;
  no = (struct node *) malloc (sizeof(struct node));
  nod = (struct node *) malloc(sizeof(struct node));
  shake = (struct node *) malloc(sizeof(struct node));
  yes = (struct node *) malloc(sizeof(struct node));

  no -> i = 10;
  no ->next = NULL;
  
  nod ->i = 100;
  nod ->next = shake;
  
  shake ->i = 101;
  shake ->next = yes;
  
  yes ->i =  102;
  yes ->next = NULL;

  printf("nod structs:");
  print_list(nod);
  printf("no structs:");
  print_list(no);
  
  printf("\n");
  printf("insert 1000 into nod\n");
  nod = insert_front(nod,1000);
  print_list(nod);
  
  printf("\n");
  printf("insert 1000 into no\n");
  no = insert_front(no,1000);
  print_list(no);

  printf("\n");
  printf("free nod\n");
  nod = free_list(nod);
  print_list(nod);
  printf("nod : %d \n", nod -> i);
  return 0;
}

