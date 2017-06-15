/* an alternative to uprog2 that dribbles out output */
#include "tunistd.h"
#include "tty_public.h"

#define MILLION 1000000
#define SDELAY (8 * MILLION)

int main2()
{
  int i,j;
  for (j=0;j<10;j++){
    for(i=0; i< SDELAY; i++)
	;
    write(TTY1,"b",1);
  }
  return 4;
}
