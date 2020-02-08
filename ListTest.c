#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include"List.c"

int main(int argc, char* argv[]){
   
   List A = newList();
   List B = newList();
   List C = NULL;
   int i;
   int j;
   char z[100] = "This is a sick test";
   //printf("%s\n",z);
 
	
		prepend(A, 5);
        append(A, 7);
        prepend(A, 2);
        moveFront(A);
        insertBefore(A, 43);
        deleteFront(A);
		printf("%d\n",front(A));
        delete(A);
        //if (front(A) != 5) return 1;
        //return 0;
		printf("%d\n",front(A));
	//printf("%d " , A->data);
	//moveNext(A);
	//printf("getA %d back data %d" , get(A) , A->back->data);
	//moveNext(A);
//}
	//for(moveFront(A); index(A)>=0; moveNext(A)){
      //printf("%d ", get(A));
   //}
	//printf("%d" , A->cIndex);
	//printf("%d" , A->length);
	//printf("\n"); 
	//moveFront(A);
	//for(j=1; j<=A->length; j++){
		//moveNext(A);
		//printf("%d" , get(A));
	//}
		//clear(A);
		//printf("\n"); 
		//get(A);
		printf("\n"); 

	printf("\n"); 
	//printf("%d\n",front(A));
	
   freeList(&A);
   freeList(&B);
   freeList(&C);
   
   return 0;
}
/*
//  for(j=1; j<=20; j++){
 // append(A,j);
 // printf("%d" , get(A));
 //  }
   printf("\n");
   for(i=1; i<=19; i++){
   append(B,i);
   //printf("%d" , get(B));
   }
   printf("\n");
  //printf("%d\n" , length(A));
  // printf("%d\n" , A->cIndex);
	//if(A->cIndex == - 1)
	//{
		//printf("Check");
	//}
 // printf("%d\n" , index(A));
 // printf("%d\n" , front(A));
 //  printf("%d\n" , back(A));
   //printf("%d\n", get(A));
   //printf("%d\n", equals(A,B));
  
   moveFront(A);
   printf("%d\n",A->cIndex);
   moveBack(A);
   printf("%d\n",A->cIndex);
   movePrev(A);
   printf("%d\n",A->cIndex);
   movePrev(A);
   printf("%d\n",A->cIndex);
   moveFront(A);
   printf("%d\n",A->cIndex);
   movePrev(A);
   printf("%d\n",A->cIndex);
   moveNext(A);
   printf("%d\n",A->cIndex);
   moveNext(A);
 ` printf("%d\n",A->cIndex);
	
  prepend(A, 22);
  for(j=1; j<=20; j++){
 append(A,j);
  //printf("%d" , get(A));
*/