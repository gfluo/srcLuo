#include <stdio.h>
#include "pushStream/CPushStream.h" 
#include <unistd.h> 

int main(int argc, char* argv[])
{
  while(1){
    CPushStream cps;
    cps.start();
    sleep(3600);
  }
  return 0;
}
