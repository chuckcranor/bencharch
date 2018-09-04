H10894
s 00004/00002/00115
d D 1.2 03/03/09 11:04:11 staelin 3 2
c - change benchmp() interface so we can have per-sample initialization
c   and cleanup.
cC
cK29711
e
s 00117/00000/00000
d D 1.1 02/11/08 09:14:43 staelin 2 1
cC
cF1
cK23819
cO-rw-rw-r--
e
s 00000/00000/00000
d D 1.0 02/11/08 09:14:43 staelin 1 0
c BitKeeper file /usr/WebPaper/users/staelin/src/LMbench3/src/lat_pmake.c
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHhpli69.hpli.hpl.hp.com
cK52569
cPsrc/lat_pmake.c
cR87e7c4ead10266a7
cV4
cX0x821
cZ+02:00
e
u
U
f e 0
f x 0x821
t
T
I 2
/*
 * lat_pmake.c - time to complete N jobs which each do usecs worth of work
 *
 * usage: lat_pipe [-P <parallelism>] [-W <warmup>] [-N <repetitions>] jobs usecs
 *
 * Copyright (c) 1994 Larry McVoy.  
 * Copyright (c) 2002 Carl Staelin. Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
char	*id = "$Id$\n";

#include "bench.h"

D 3
void setup(void* cookie);
E 3
I 3
void setup(iter_t iterations, void* cookie);
E 3
void bench(iter_t iterations, void *cookie);
void work(iter_t iterations, void *cookie);

typedef struct _state {
	int	jobs;		/* number of jobs to create */
	iter_t	iterations;	/* how long each job should work */
	long*	x;		/* used by work() */
	long**	p;
} state_t;

int 
main(int ac, char **av)
{
	state_t state;
	int parallel = 1;
	int warmup = 0;
	int repetitions = TRIES;
	int c;
	uint64	usecs;
	char buf[1024];
	char* usage = "[-P <parallelism>] [-W <warmup>] [-N <repetitions>]\n";

	while (( c = getopt(ac, av, "P:W:N:")) != EOF) {
		switch(c) {
		case 'P':
			parallel = atoi(optarg);
			if (parallel <= 0) lmbench_usage(ac, av, usage);
			break;
		case 'W':
			warmup = atoi(optarg);
			break;
		case 'N':
			repetitions = atoi(optarg);
			break;
		default:
			lmbench_usage(ac, av, usage);
			break;
		}
	}
	if (optind != ac - 2) {
		lmbench_usage(ac, av, usage);
	}
	state.jobs = atoi(av[optind]);
	usecs = bytes(av[optind+1]);
	benchmp(setup, work, NULL, 0, 1, 0, TRIES, &state);
	if (gettime() == 0) exit(1);
	state.iterations = (iter_t)((usecs * get_n()) / gettime());
	/*nano("work", get_n());*/

	benchmp(setup, bench, NULL, 0, parallel, 
		warmup, repetitions, &state);
	sprintf(buf, "time to complete %d jobs, each with %lu usecs work",
		state.jobs, usecs);
	micro(buf, get_n());
	return (0);
}

void
D 3
setup(void* cookie)
E 3
I 3
setup(iter_t iterations, void* cookie)
E 3
{
	state_t *state = (state_t *) cookie;
I 3

	if (iterations) return;
E 3

	state->x = (long*)malloc(sizeof(long*));
	*(long**)state->x = state->x;
	state->p = (long**)state->x;
}

void 
bench(register iter_t iterations, void *cookie)
{
	state_t *state = (state_t *) cookie;
	int	i;
	pid_t*	pids = (pid_t*)malloc(state->jobs * sizeof(pid_t));

	signal(SIGCHLD, SIG_IGN);
	while (iterations-- > 0) {
		for (i = 0; i < state->jobs; ++i) {
			if ((pids[i] = fork()) == 0) {
				work(state->iterations, state);
				exit(0);
			}
		}
		for (i = 0; i < state->jobs; ++i) {
			waitpid(pids[i], NULL, 0);
		}
	}
}

void
work(register iter_t iterations, void* cookie)
{
	state_t *state = (state_t *) cookie;
	register long** p = state->p;

#define	WORK_TEN(one)	one one one one one one one one one one
	while (iterations-- > 0) {
		WORK_TEN(p = (long**) *p;);
	}
	state->p = p;
}
E 2
I 1
E 1
