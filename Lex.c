#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"


#define MAX_LEN 160
int main(int argc, char *argv[])
{

	int count=0;
   FILE *in, *out;
   char line[MAX_LEN];
  // char store[MAX_LEN];

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }
   /* read each line of input file, then count the number of lines */
   while( fgets(line, MAX_LEN, in) != NULL)  {
      count++;
   }
	  
	fclose(in);
	in = fopen(argv[1], "r");
	
	char storeArray[count][MAX_LEN];
	int i=0;
	
	//Storing the elements in the storeArray
	while( fgets(storeArray[i], MAX_LEN, in) != NULL)  {
		//fscanf(in,"%s", store);
		//fgets(line, MAX_LEN, in);
		//strcpy(storeArray[i],store);
		//storeArray[i] = line;
		i++;
	
      }
	  /*
	  for(i = 0; i<count; i++)
	{
		printf("Element is %s", storeArray[i]);
	}
	
      //fprintf(out, "line %d contains %d token%s: \n", count, n, n==1?"":"s");
     //printf("%s", Stringlist);
	  printf("\n%d \n", count);
	  */
		//strcmp(s1, s2)<0 is true if and only if s1 comes before s2
		//strcmp(s1, s2)>0 is true if and only if s1 comes after s2
		//strcmp(s1, s2)==0 is true if and only if s1 is identical to s2

	  List nList = newList();
	  if(count>0)
	  {
	  prepend(nList, 0);
	  }
	 // moveFront(nList);
	 // insertBefore(nList,10);
	  //moveFront(nList);
	 
		  for(i = 1; i<count;i++)
		  {
			  moveFront(nList);
			  
			  while(index(nList) >= 0 && strcmp(storeArray[get(nList)], storeArray[i]) < 0)
			  {
				  moveNext(nList);
			  }
			  if(index(nList) == -1)
			  {
				  append(nList,i);
			  }
			  else
			  {
				  insertBefore(nList,i);
			  }
		  }
		  
		// moveFront(nList);
		 //printList(out, nList);
		/*
		  for(i = 0; i<count; i++)
		  {
			delete(nList);
			moveNext(nList);
		  }
		*/
		//printing out to fprintf
		for(moveFront(nList); index(nList) >= 0; moveNext(nList))
		{
			fprintf(out,"%s", storeArray[get(nList)]);
		}
		
		  //delete(nList);
		  //moveFront(nList);
		  clear(nList);
		  //deleteBack(nList);
		  freeList(&nList);
		  
		  fclose(in);
		  fclose(out);
		  
		  return EXIT_SUCCESS;
	  }