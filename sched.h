#include "proc.h"

typedef enum process_number {user_1 = 1, user_2, user_3} process;

void schedule(int entry);
void tsleep(void);
void twakeup(void);
