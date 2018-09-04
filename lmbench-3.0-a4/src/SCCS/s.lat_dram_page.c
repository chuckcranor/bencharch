H00040
s 00001/00001/00200
d D 1.3 04/06/13 11:13:17 staelin 4 3
c - fix 32bit/64bit buglet
cC
cHhpliclu2.hpli.hpl.hp.com
cK46893
cZ+03:00
e
s 00007/00005/00194
d D 1.2 03/03/09 11:04:11 staelin 3 2
c - change benchmp() interface so we can have per-sample initialization
c   and cleanup.
cC
cK46570
e
s 00199/00000/00000
d D 1.1 02/10/17 14:16:29 staelin 2 1
cC
cF1
cK39608
cO-rw-rw-r--
e
s 00000/00000/00000
d D 1.0 02/10/17 14:16:29 staelin 1 0
c BitKeeper file /usr/WebPaper/users/staelin/src/LMbench3/src/lat_dram_page.c
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHhpli69.hpli.hpl.hp.com
cK14695
cPsrc/lat_dram_page.c
cR346a3f39cff24f5
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
 * lat_dram_page.c - guess the DRAM page latency
 *
 * usage: lat_dram_page
 *
 * Copyright (c) 2002 Carl Staelin.
 * Copyright (c) 1994 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
char	*id = "$Id$\n";

#include "bench.h"

D 3
void	dram_page_initialize(void* cookie);
E 3
I 3
void	dram_page_initialize(iter_t iterations, void* cookie);
E 3
void	benchmark_loads(iter_t iterations, void *cookie);
D 3
double	loads(support_f initialize, int len, int warmup, int repetitions, void* cookie);
E 3
I 3
double	loads(benchmp_f initialize, int len, int warmup, int repetitions, void* cookie);
E 3

struct dram_page_state
{
	struct mem_state	mstate;
	int			group;
};

int
main(int ac, char **av)
{
	int	i, j, l;
	int	verbose = 0;
	int	maxlen = 64 * 1024 * 1024;
	int	warmup = 0;
	int	repetitions = TRIES;
	int	c;
	struct dram_page_state state;
	double	dram_hit, dram_miss;
	char   *usage = "[-v] [-W <warmup>] [-N <repetitions>][-M len[K|M]]\n";

	state.mstate.width = 1;
	state.mstate.line = sizeof(char*);
	state.mstate.pagesize = getpagesize();
	state.group = 16;

	while (( c = getopt(ac, av, "avL:T:M:W:N:")) != EOF) {
		switch(c) {
		case 'v':
			verbose = 1;
			break;
		case 'L':
			state.mstate.line = bytes(optarg);
			break;
		case 'T':
			state.group = bytes(optarg);
			break;
		case 'M':
			maxlen = bytes(optarg);
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

	dram_hit = loads(mem_initialize, maxlen, warmup, repetitions, &state);
	dram_miss = loads(dram_page_initialize, maxlen, warmup, repetitions, &state);

	if (dram_hit < 0.95 * dram_miss) {
		fprintf(stderr, "%f\n", dram_miss - dram_hit);
	} else {
		fprintf(stderr, "0.0\n");
	}

	return (0);
}

#define	ONE	p = (char **)*p;
#define	FIVE	ONE ONE ONE ONE ONE
#define	TEN	FIVE FIVE
#define	FIFTY	TEN TEN TEN TEN TEN
#define	HUNDRED	FIFTY FIFTY

void
benchmark_loads(iter_t iterations, void *cookie)
{
	struct mem_state* state = (struct mem_state*)cookie;
	register char **p = (char**)state->base;
	register int i;
	register int count = state->len / (state->line * 100) + 1;

	while (iterations-- > 0) {
		for (i = 0; i < count; ++i) {
			HUNDRED;
		}
	}

	use_pointer((void *)p);
}

void
D 4
regroup(int* pages, int groupsize, void* cookie)
E 4
I 4
regroup(size_t* pages, int groupsize, void* cookie)
E 4
{
	register int i, j;
	register char* ptr;
	register char *page;
	register char *page_end;
	register char *p = 0 /* lint */;
	struct mem_state* state = (struct mem_state*)cookie;

	if (groupsize <= 1) return;

	p = state->base;

	/*
	 * for all but the last page in the group,
	 * point to the same line in the next page
	 */
	for (i = 0; i < groupsize - 1; ++i) {
		for (j = 0; j < state->pagesize; j += sizeof(char*)) {
			*(char**)(p + pages[i] + j) = p + pages[i+1] + j;
		}
	}
	
	/*
	 * for the last page, point to the next line
	 * in the first page of the group, except for
	 * the last line in the page which points to
	 * the first line in the next group
	 *
	 * since the pointers are all set up for the
	 * last line, only modify the pointers for
	 * the other lines
	 */
	page = p + pages[groupsize-1];
	page_end = page + state->pagesize;
	for (i = 0; i < state->pagesize; i += sizeof(char*)) {
		ptr = *(char**)(page + i);
		if (page <= ptr && ptr < page_end) {
			int offset = (int)(ptr - page);
			*(char**)(page + i) = p + pages[0] + offset;
		}
	}
}

/*
 * This is like mem_initialize
 */
void
D 3
dram_page_initialize(void* cookie)
E 3
I 3
dram_page_initialize(iter_t iterations, void* cookie)
E 3
{
	int i;
	struct mem_state* state = (struct mem_state*)cookie;
	struct dram_page_state*	dstate = (struct dram_page_state*)cookie;

D 3
	mem_initialize(cookie);
E 3
I 3
	if (iterations) return; 

	mem_initialize(iterations, cookie);
E 3

	for (i = 0; i < state->npages; i += dstate->group) {
		int	groupsize = dstate->group;
		if (groupsize > state->npages - i) {
			groupsize = state->npages - i;
		}
		regroup(state->pages + i, groupsize, cookie);
	}

	benchmark_loads(1, cookie);
}

double
D 3
loads(support_f initialize, int len, int warmup, int repetitions, void* cookie)
E 3
I 3
loads(benchmp_f initialize, int len, int warmup, int repetitions, void* cookie)
E 3
{
	double result;
	int count;
	int parallel = 1;
	struct mem_state* state = (struct mem_state*)cookie;

	state->len = len;
	state->maxlen = len;
	count = 100 * (state->len / (state->line * 100) + 1);

	/*
	 * Now walk them and time it.
	 */
	benchmp(initialize, benchmark_loads, mem_cleanup, 
		0, parallel, warmup, repetitions, cookie);

	/* We want to get to nanoseconds / load. */
	result = (1000. * (double)gettime()) / (double)(count * get_n());
	/*
	fprintf(stderr, "%.5f %.3f\n", len / (1024. * 1024.), result);
	/**/

	return result;
}
E 2
I 1
E 1
