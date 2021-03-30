#include "common.h"

#ifndef WIN32
char getch(){ return 'a'; }
#else
#include <conio.h>
#endif

