#include "types.h"
#include "stat.h"
#include "user.h"

typedef struct{ 
   char name[4]; 
   int age; 
  }people; 

int main(int argc, char * argv[])
{
  int fd;
  int i;
  char temp;
  if(!(fd = open("README", 0)))
  {
    printf(1, "Fail to open file!\n");
  }

  people *p_map = mmap(sizeof(people)*10, fd, 0);
  close( fd ); 
  temp = 'a'; 
  for(i=0; i<10; i++) 
  { 
   temp += 1; 
   memmove( ( *(p_map+i) ).name, &temp,2 ); 
   ( *(p_map+i) ).age = 20+i; 
  } 

  for(i = 0;i<10;i++) 
  { 
    printf(1, "name: %s age %d;\n",(*(p_map+i)).name, (*(p_map+i)).age ); 
  } 

  exit();
}