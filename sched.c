#include <cpu.h>
#include "sched.h"

extern void asmswtch(PEntry *oldproc, PEntry *newproc);

typedef unsigned int byte;

void schedule(int entry) {

  byte saved_eflags;

	PEntry * past_process = curproc;

	if (proctab[entry].p_status == RUN)
		curproc = (PEntry *)proctab + entry;
	else
		curproc = (PEntry *)proctab;	/* point to first entry (process 0) */

	saved_eflags = get_eflags();
	cli();

	asmswtch(past_process, curproc);

	set_eflags(saved_eflags);
}

void tsleep() {
	byte saved_eflags;

	saved_eflags = get_eflags();
	cli();

	curproc->p_status = BLOCKED;
/*	curproc->p_waitcode = event; */

	saved_eflags = get_eflags();
}

void twakeup() {
	int index;
	byte saved_eflags;

	saved_eflags = get_eflags();
	cli();
	
	for (index = 1; index < NPROC; index++) {
		if (proctab[index].p_status == BLOCKED)
			proctab[index].p_status == RUN;
	}

	set_eflags(saved_eflags);
}
