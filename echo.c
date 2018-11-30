#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int* p;
  p=calloc(15,sizeof(int));
  printf(1,"Address: %d",p);

  printf(1,"\n");

  p=(int*)realloc(p,sizeof(int));
  printf(1,"Address: %d",p);

  printf(1,"\n");
  
  exit();
}
