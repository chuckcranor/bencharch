H65373
s 00007/00003/00162
d D 1.28 04/08/03 16:53:28 staelin 30 29
c src/lat_mem_rd.c
c - fix bug in loads() which caused core dumps when the range (amount of
c   active memory) was smaller than the stride
cC
cK34083
e
s 00006/00018/00159
d D 1.27 04/06/13 11:07:45 staelin 29 28
c - Fixup memory sizing steps so they grow exponentially with the size
c   of memory instead of linearly.  This results in dramatically reduced
c   runtimes for large memory systems.
cC
cK29395
e
s 00010/00129/00167
d D 1.26 04/06/13 11:03:48 staelin 28 27
c - Move memory pointer chain initialization from lat_mem_rd to lib_mem
cC
cK44953
e
s 00004/00004/00292
d D 1.25 04/06/08 09:58:22 staelin 27 26
c - Fix issues related to 64bit architectures where pointers are 64bit
c   and ints are 32bit.
cC
cHhpliclu2.hpli.hpl.hp.com
cK31351
cZ+03:00
e
s 00148/00008/00148
d D 1.24 04/02/03 17:15:38 staelin 26 25
c Fixup lat_mem_rd memory access patterns.  The default pattern almost
c matches the access pattern from lmbench2, which strided backwards
c through memory in a predictable fashion, by striding forwards through
c memory similar to matrix algorithms.  The original lmbench3 access
c pattern strode sequentially through a page and randomly between pages,
c which defeated TLB prefetch and caused interesting timing artifacts
c and differences between lmbench2 and lmbench3.  The new access pattern
c mimics linked list behavior and semi-randomly jumps between page offsets
c and pages on every access.
cC
cHfirewall.staelin.co.il
cK30443
cZ+02:00
e
s 00000/00000/00156
d D 1.23 02/10/01 09:50:42 staelin 25 23
i 24
c Auto merged
cC
cHhpli69.hpli.hpl.hp.com
cK08958
cM24
e
s 00001/00001/00156
d D 1.21.1.1 02/10/01 09:49:44 staelin 24 22
c - fix latent bug in lat_mem_rd: we were using state->addr instead
c   of the page-adjusted state->base
cC
cHhpli69.hpli.hpl.hp.com
cK08507
e
s 00013/00014/00143
d D 1.22 02/09/29 21:53:51 staelin 23 22
c - switch from 'int' to 'size_t' for better portability to large memory 
c   machines
cC
cK08958
e
s 00018/00066/00139
d D 1.21 02/05/26 21:39:25 staelin 22 21
c Convert lat_mem_rd to use lib_mem's line_initialize.  This
c means that the pointer chain will be essentially random, so
c it is less vulnerable to intelligent prefetching.
cC
cHfirewall.staelin.co.il
cK08507
cZ+03:00
e
s 00006/00003/00199
d D 1.20 00/10/16 17:21:24 staelin 21 20
c - Assorted code cleanups
cC
cK10550
cZ+02:00
e
s 00003/00003/00199
d D 1.19 00/08/01 12:14:11 staelin 20 19
c - Add significant digits to memory latency reporting
cC
cK10616
e
s 00001/00001/00201
d D 1.18 00/07/30 11:46:09 staelin 19 18
c - Change type of "iterations" from uint64 to iter_t, which is a u_long
cC
cK10452
e
s 00020/00008/00182
d D 1.17 00/07/04 14:55:54 staelin 18 17
c - Update to incorporate new "-W <warmup>" and "-N <repetitions>" flags
cC
cK10359
e
s 00000/00001/00190
d D 1.16 00/05/31 16:16:17 staelin 17 16
c Remove unnecessary print statement that was confusing lmbench's result parsing scripts
cC
cK45271
cZ+03:00
e
s 00026/00015/00165
d D 1.15 00/03/01 17:23:37 staelin 16 15
c - Convert to new getopt system of flag parsing
c - Add parameter to loads() for parallelism
cC
cK48887
e
s 00072/00062/00108
d D 1.14 00/02/23 11:15:39 staelin 15 14
c Convert to use new draft benchmp() timing harness.
cC
cHhpli8.hpli.hpl.hp.com
cK39543
cZ+02:00
e
s 00018/00008/00152
d D 1.13 98/06/30 16:13:49 lm 14 13
c Go backwards instead of forwards; might fool HP machines.
cC
cK14350
e
s 00001/00001/00159
d D 1.12 98/06/29 22:37:35 lm 13 12
c Redo to compile clean with -Wall.
cK61572
cZ-07:00
e
s 00001/00001/00159
d D 1.11 97/10/31 18:06:23 lm 12 11
c use_result -> use_int/pointer
cK60686
cZ-08:00
e
s 00001/00001/00159
d D 1.10 97/06/15 22:38:58 lm 11 10
c lint
cK60411
e
s 00002/00003/00158
d D 1.9 97/06/14 18:23:34 lm 10 9
c *** empty log message ***
cK60181
e
s 00000/00001/00161
d D 1.8 97/06/12 21:30:06 lm 9 8
c new bench.h macros.
cK61081
e
s 00007/00001/00155
d D 1.7 97/04/23 22:35:06 lm 8 7
c step function.
cK62764
cZ-07:00
e
s 00005/00004/00151
d D 1.6 96/11/11 03:36:51 lm 7 6
c Auto adjusting changes.
cK55951
e
s 00014/00046/00141
d D 1.5 96/11/08 19:59:31 lm 6 5
c gcc -Wall cleanup & new timing.c integration.
c Get rid of mhz dependency (move that into the post processing).
cK52519
cZ-08:00
e
s 00000/00001/00187
d D 1.4 96/05/30 00:33:07 lm 5 4
c no what strings
cK09695
e
s 00001/00001/00187
d D 1.3 96/04/16 12:02:28 lm 4 3
c Jack Veenstra @ sgi.com found a bug that made the results off by .1%.
cK11766
cZ-07:00
e
s 00022/00001/00166
d D 1.2 96/01/22 23:25:34 lm 3 2
c make it take the k/m suffices.
cK12068
e
s 00167/00000/00000
d D 1.1 94/11/18 00:49:48 lm 2 1
c Initial revision
cK62263
e
s 00000/00000/00000
d D 1.0 94/11/18 00:49:47 lm 1 0
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHlm.bitmover.com
cK64604
cPsrc/lat_mem_rd.c
cRc02704ba4b897de0
cV4
cX0x21
cZ-08:00
e
u
U
f e 0
f x 0x21
t
lmbench src
T
I 2
/*
 * lat_mem_rd.c - measure memory load latency
 *
D 18
 * usage: lat_mem_rd size-in-MB stride [stride ...]
E 18
I 18
D 26
 * usage: lat_mem_rd [-P <parallelism>] [-W <warmup>] [-N <repetitions>] size-in-MB stride [stride ...]
E 26
I 26
 * usage: lat_mem_rd [-P <parallelism>] [-W <warmup>] [-N <repetitions>] [-t] size-in-MB [stride ...]
E 26
E 18
 *
D 26
 * Copyright (c) 1994 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
E 26
I 26
 * Copyright (c) 1994 Larry McVoy.  
 * Copyright (c) 2003, 2004 Carl Staelin.
 *
 * Distributed under the FSF GPL with additional restriction that results 
 * may published only if:
E 26
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
D 15
char	*id = "$Id$\n";
E 15
I 15
char	*id = "$Id: s.lat_mem_rd.c 1.13 98/06/30 16:13:49-07:00 lm@lm.bitmover.com $\n";
E 15

I 7
D 9
#include "timing.h"
E 9
#include "bench.h"
E 7
D 6
#define N       1000000
E 6
I 6
D 15
#define N       1000000	/* Don't change this */
E 15
I 15
D 23
/*#define N       1000000	/* Don't change this */
E 23
E 15
E 6
#define STRIDE  (512/sizeof(char *))
D 10
#define	TRIES	4
E 10
I 10
D 23
#define	MEMTRIES	4
E 23
E 10
#define	LOWER	512
D 7

#include	"timing.c"
E 7
I 6
D 15
void	loads(char *addr, int range, int stride);
E 15
I 15
D 16
void	loads(int len, int range, int stride);
E 16
I 16
D 18
void	loads(int len, int range, int stride, int parallel);
E 18
I 18
D 23
void	loads(int len, int range, int stride, int parallel, 
	      int warmup, int repetitions);
E 18
E 16
E 15
int	step(int k);
E 23
I 23
void	loads(size_t len, size_t range, size_t stride, 
	      int parallel, int warmup, int repetitions);
size_t	step(size_t k);
I 26
void	initialize(iter_t iterations, void* cookie);

D 28
benchmp_f	fpInit = initialize;

void
base_initialize(iter_t iterations, void* cookie)
{
	int	nwords, nlines, nbytes, npages, nmpages;
D 27
	int    *pages;
	int    *lines;
	int    *words;
E 27
I 27
	size_t *pages;
	size_t *lines;
	size_t *words;
E 27
	struct mem_state* state = (struct mem_state*)cookie;
	register char *p = 0 /* lint */;

	if (iterations) return;

	state->initialized = 0;

	state->maxlen = state->len;
	nbytes = state->len;
	nwords = state->line / sizeof(char*);
	nlines = state->pagesize / state->line;
	npages = (nbytes + state->pagesize - 1) / state->pagesize;
	nmpages= (state->maxlen + state->pagesize - 1) / state->pagesize;

	srand(getpid());

	words = NULL;
	lines = NULL;
	pages = permutation(nmpages, state->pagesize);
	p = state->addr = (char*)malloc(state->maxlen + 2 * state->pagesize);

	state->nwords = nwords;
	state->nlines = nlines;
	state->npages = npages;
	state->lines = lines;
	state->pages = pages;
	state->words = words;

	if (state->addr == NULL) {
		return;
	}

	if ((unsigned long)p % state->pagesize) {
		p += state->pagesize - (unsigned long)p % state->pagesize;
	}
	state->base = p;
	state->initialized = 1;
}

void
initialize(iter_t iterations, void* cookie)
{
	struct mem_state* state = (struct mem_state*)cookie;
	size_t	i;
	size_t	range = state->len;
	size_t	stride = state->line;
	char*	addr;

	base_initialize(iterations, cookie);
	addr = state->base;

	/*
	 * Create a circular list of pointers using a simple striding
	 * algorithm.  
	 * 
	 * This access pattern corresponds to many array/matrix
	 * algorithms.  It should be easily and correctly predicted
	 * by any decent hardware prefetch algorithm.
	 */
	for (i = stride; i < range; i += stride) {
		*(char **)&addr[i - stride] = (char*)&addr[i];
	}
	*(char **)&addr[i - stride] = (char*)&addr[0];
	state->p[0] = addr;
}

void
initialize_thrash(iter_t iterations, void* cookie)
{
	struct mem_state* state = (struct mem_state*)cookie;
	int	npages = (state->len + state->pagesize - 1) / state->pagesize;
D 27
	int    *pages;
E 27
I 27
	size_t *pages;
E 27
	size_t	i;
	size_t	j;
	size_t	cur;
	size_t	next;
	size_t	start;
	size_t	range = state->len;
	size_t	stride = state->line;
	char*	addr;

	base_initialize(iterations, cookie);
	addr = state->base;

	/*
	 * Create a circular list of pointers with a random access
	 * pattern.
	 *
	 * This stream corresponds more closely to linked list
	 * memory access patterns.  For large data structures each
	 * access will likely cause both a cache miss and a TLB miss.
	 * 
	 * Access a different page each time.  This will eventually
	 * cause a tlb miss each page.  It will also cause maximal
	 * thrashing in the cache between the user data stream and
	 * the page table entries.
	 */
	pages = state->pages;
	cur = pages[0];
	for (i = 0; i < state->nlines; ++i) {
	    for (j = 0; j < state->npages; ++j) {
		if (j < state->npages - 1) {
		    next = pages[j + 1] + ((i + j + 1) % state->nlines) * state->line;
		} else {
		    next = pages[0] + ((i + 1) % state->nlines) * state->line;
		}
		*(char **)&addr[cur] = (char*)&addr[next];
		cur = next;
	    }
	}
	state->p[0] = (char*)&addr[pages[0]];
}
E 28
I 28
benchmp_f	fpInit = stride_initialize;
E 28
E 26
E 23
E 6

D 6
main(ac, av)
        char  **av;
E 6
I 6
int
main(int ac, char **av)
E 6
{
D 23
        int     len;
	int	range;
	int	stride;
E 23
	int	i;
D 6
	float	clk, getclock();
E 6
D 16
        char   *addr;
E 16
I 16
	int	c;
	int	parallel = 1;
D 18
	char   *usage = "[-P <parallelism>] len [stride...]\n";
E 18
I 18
	int	warmup = 0;
	int	repetitions = TRIES;
I 23
        size_t	len;
	size_t	range;
	size_t	stride;
E 23
D 26
	char   *usage = "[-P <parallelism>] [-W <warmup>] [-N <repetitions>] len [stride...]\n";
E 26
I 26
	char   *usage = "[-P <parallelism>] [-W <warmup>] [-N <repetitions>] [-t] len [stride...]\n";
E 26
E 18

D 18
	while (( c = getopt(ac, av, "P:")) != EOF) {
E 18
I 18
D 26
	while (( c = getopt(ac, av, "P:W:N:")) != EOF) {
E 26
I 26
	while (( c = getopt(ac, av, "tP:W:N:")) != EOF) {
E 26
E 18
		switch(c) {
I 26
		case 't':
D 28
			fpInit = initialize_thrash;
E 28
I 28
			fpInit = thrash_initialize;
E 28
			break;
E 26
		case 'P':
			parallel = atoi(optarg);
			if (parallel <= 0) lmbench_usage(ac, av, usage);
			break;
I 18
		case 'W':
			warmup = atoi(optarg);
			break;
		case 'N':
			repetitions = atoi(optarg);
			break;
E 18
		default:
			lmbench_usage(ac, av, usage);
			break;
		}
	}
	if (optind == ac) {
		lmbench_usage(ac, av, usage);
	}
E 16

D 5
	write(2, id, strlen(id));
E 5
D 16
        len = atoi(av[1]) * 1024 * 1024;
E 16
I 16
D 28
        len = atoi(av[optind]) * 1024 * 1024;
E 28
I 28
        len = atoi(av[optind]);
	len *= 1024 * 1024;
E 28
E 16
D 15
        addr = (char *)malloc(len);
E 15
D 6
	clk = getclock();
	printf("clk=%.2f\n", clk);
E 6

D 16
	if (av[2] == 0) {
E 16
I 16
	if (optind == ac - 1) {
E 16
		fprintf(stderr, "\"stride=%d\n", STRIDE);
		for (range = LOWER; range <= len; range = step(range)) {
D 6
			loads(addr, range, STRIDE, clk);
E 6
I 6
D 15
			loads(addr, range, STRIDE);
E 15
I 15
D 16
			loads(len, range, STRIDE);
E 16
I 16
D 18
			loads(len, range, STRIDE, parallel);
E 18
I 18
			loads(len, range, STRIDE, parallel, 
			      warmup, repetitions);
E 18
E 16
E 15
E 6
		}
	} else {
D 16
		for (i = 2; i < ac; ++i) {
E 16
I 16
		for (i = optind + 1; i < ac; ++i) {
E 16
D 3
			stride = atoi(av[i]);
E 3
I 3
			stride = bytes(av[i]);
E 3
			fprintf(stderr, "\"stride=%d\n", stride);
			for (range = LOWER; range <= len; range = step(range)) {
D 6
				loads(addr, range, stride, clk);
E 6
I 6
D 15
				loads(addr, range, stride);
E 15
I 15
D 16
				loads(len, range, stride);
E 16
I 16
D 18
				loads(len, range, stride, parallel);
E 18
I 18
				loads(len, range, stride, parallel, 
				      warmup, repetitions);
E 18
E 16
E 15
E 6
			}
			fprintf(stderr, "\n");
		}
	}
D 11
	exit(0);
E 11
I 11
	return(0);
E 11
}

D 6
loads(addr, range, stride, clk)
	char	*addr;
	int	stride;
	float	clk;
E 6
I 6
D 15
void
loads(char *addr, int range, int stride)
E 15
I 15
#define	ONE	p = (char **)*p;
#define	FIVE	ONE ONE ONE ONE ONE
#define	TEN	FIVE FIVE
#define	FIFTY	TEN TEN TEN TEN TEN
#define	HUNDRED	FIFTY FIFTY

D 22
struct _state {
	char*	addr;
	int	len;
	int	range;
	int	stride;
};

D 21
void initialize_loads(void* cookie)
E 21
I 21
void
initialize_loads(void* cookie)
E 21
E 15
E 6
{
I 15
	struct _state* state = (struct _state*)cookie;
E 15
D 13
	register char **p;
E 13
I 13
	register char **p = 0 /* lint */;
E 13
        int     i;
	int	tries = 0;
	int	result = 0x7fffffff;

D 14
        /*
	 * First create a list of pointers.
	 */
E 14
D 15
     	if (stride & (sizeof(char *) - 1)) {
E 15
I 15
        state->addr = (char *)malloc(state->len);

     	if (state->stride & (sizeof(char *) - 1)) {
E 15
D 14
		fprintf(stderr, "list: stride must be aligned.\n");
E 14
I 14
		printf("lat_mem_rd: stride must be aligned.\n");
		return;
	}
	
D 15
	if (range < stride) {
E 15
I 15
	if (state->range < state->stride) {
E 15
E 14
		return;
	}

D 14
     	for (i = 0; i < range; i += stride) {
E 14
I 14
	/*
	 * First create a list of pointers.
	 *
	 * This used to go forwards, we want to go backwards to try and defeat
	 * HP's fetch ahead.
	 *
	 * We really need to do a random pattern once we are doing one hit per 
	 * page.
	 */
D 15
	for (i = range - stride; i >= 0; i -= stride) {
E 15
I 15
	for (i = state->range - state->stride; i >= 0; i -= state->stride) {
E 15
E 14
		char	*next;

D 15
		p = (char **)&addr[i];
D 14
		if (i + stride >= range) {
			next = &addr[0];
E 14
I 14
		if (i < stride) {
			next = &addr[range - stride];
E 15
I 15
		p = (char **)&(state->addr[i]);
		if (i < state->stride) {
			next = &(state->addr[state->range - state->stride]);
E 15
E 14
		} else {
D 14
			next = &addr[i + stride];
E 14
I 14
D 15
			next = &addr[i - stride];
E 15
I 15
			next = &(state->addr[i - state->stride]);
E 15
E 14
		}
		*p = next;
	}
I 15
}
E 22
E 15

D 15
	/*
	 * Now walk them and time it.
	 */
D 10
        for (tries = 0; tries < TRIES; ++tries) {
E 10
I 10
        for (tries = 0; tries < MEMTRIES; ++tries) {
E 10
                /* time loop with loads */
#define	ONE	p = (char **)*p;
#define	FIVE	ONE ONE ONE ONE ONE
#define	TEN	FIVE FIVE
#define	FIFTY	TEN TEN TEN TEN TEN
#define	HUNDRED	FIFTY FIFTY
D 4
		i = N - 1000;
E 4
I 4
		i = N;
E 4
D 10
		p = (char **)addr;
E 10
D 7
                start();
E 7
I 7
                start(0);
E 7
                while (i > 0) {
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			HUNDRED
			i -= 1000;
                }
D 7
		i = stop(p);
E 7
I 7
		i = stop(0,0);
D 12
		use_result((int)p);
E 12
I 12
		use_pointer((void *)p);
E 12
E 7
		if (i < result) {
			result = i;
		}
E 15
I 15
D 19
void benchmark_loads(uint64 iterations, void *cookie)
E 19
I 19
D 21
void benchmark_loads(iter_t iterations, void *cookie)
E 21
I 21
void
benchmark_loads(iter_t iterations, void *cookie)
E 21
E 19
{
D 22
	struct _state* state = (struct _state*)cookie;
E 22
I 22
	struct mem_state* state = (struct mem_state*)cookie;
E 22
D 24
	register char **p = (char**)state->addr;
E 24
I 24
D 26
	register char **p = (char**)state->base;
E 26
I 26
	register char **p = (char**)state->p[0];
E 26
E 24
I 22
D 23
	register int i;
	register int count = state->len / (state->line * 100) + 1;
E 23
I 23
	register size_t i;
	register size_t count = state->len / (state->line * 100) + 1;
E 23
E 22

	while (iterations-- > 0) {
D 22
		HUNDRED;
E 22
I 22
		for (i = 0; i < count; ++i) {
			HUNDRED;
		}
E 22
E 15
	}
I 15

	use_pointer((void *)p);
I 26
	state->p[0] = (char*)p;
E 26
}

D 21
void cleanup_loads(void* cookie)
E 21
I 21
D 22
void
cleanup_loads(void* cookie)
E 21
{
	struct _state* state = (struct _state*)cookie;
	free(state->addr);
	state->addr = NULL;
}

E 22

void
D 16
loads(int len, int range, int stride)
E 16
I 16
D 18
loads(int len, int range, int stride, int parallel)
E 18
I 18
D 23
loads(int len, int range, int stride, int parallel, int warmup, int repetitions)
E 23
I 23
loads(size_t len, size_t range, size_t stride, 
	int parallel, int warmup, int repetitions)
E 23
E 18
E 16
{
D 20
	int result;
E 20
I 20
	double result;
E 20
D 22
	struct _state state;
E 22
I 22
D 23
	int count;
E 23
I 23
	size_t count;
E 23
	struct mem_state state;
E 22

I 30
	if (range < stride) return;

E 30
D 22
	state.len = len;
	state.range = range;
	state.stride = stride;
E 22
I 22
	state.width = 1;
	state.len = range;
	state.maxlen = len;
	state.line = stride;
	state.pagesize = getpagesize();
	count = 100 * (state.len / (state.line * 100) + 1);
E 22

I 26
#if 0
	(*fpInit)(0, &state);
	fprintf(stderr, "loads: after init\n");
D 30
	(*benchmark_loads)(1, &state);
E 30
I 30
	(*benchmark_loads)(2, &state);
E 30
	fprintf(stderr, "loads: after benchmark\n");
	mem_cleanup(0, &state);
	fprintf(stderr, "loads: after cleanup\n");
D 30
#endif

E 30
I 30
	settime(1);
	save_n(1);
#else
E 30
E 26
E 15
	/*
D 15
	 * We want to get to nanoseconds / load.  We don't want to
	 * lose any precision in the process.  What we have is the
	 * milliseconds it took to do N loads, where N is 1 million,
	 * and we expect that each load took between 10 and 2000
	 * nanoseconds.
	 *
	 * We want just the memory latency time, not including the
	 * time to execute the load instruction.  We allow one clock
	 * for the instruction itself.  So we need to subtract off
	 * N * clk nanoseconds.
	 *
I 6
	 * lmbench 2.0 - do the subtration later, in the summary.
	 * Doing it here was problematic.
	 *
E 6
	 * XXX - we do not account for loop overhead here.
E 15
I 15
	 * Now walk them and time it.
E 15
	 */
D 6
     	i = (clk * N) / 1000;		/* load instruction time in usecs */
	result -= i;			/* time for the loads themselves */
E 6
D 15
	result *= 1000;			/* convert to nanoseconds */
	result /= N;				/* nanosecs per load */
E 15
I 15
D 16
	benchmp(initialize_loads, benchmark_loads, NOCLEANUP, 0, 1, &state);
E 16
I 16
D 18
	benchmp(initialize_loads, benchmark_loads, NULL, 0, parallel, &state);
E 18
I 18
D 22
	benchmp(initialize_loads, benchmark_loads, NULL, 0, parallel, 
		warmup, repetitions, &state);
E 22
I 22
D 26
	benchmp(line_initialize, benchmark_loads, mem_cleanup, 
		0, parallel, warmup, repetitions, &state);
E 26
I 26
	benchmp(fpInit, benchmark_loads, mem_cleanup, 
		100000, parallel, warmup, repetitions, &state);
I 30
#endif
E 30
E 26
E 22
E 18
E 16

	/* We want to get to nanoseconds / load. */
I 26
	save_minimum();
E 26
D 17
	fprintf(stderr,"*****************************************\n");
E 17
D 20
	result = (int)(((uint64)1000 * gettime()) / ((uint64)100 * get_n()));
E 15
	fprintf(stderr, "%.5f %d\n", range / (1024. * 1024), result);
E 20
I 20
D 22
	result = (1000. * (double)gettime()) / (100. * (double)get_n());
	fprintf(stderr, "%.5f %.3f\n", range / (1024. * 1024), result);
E 22
I 22
	result = (1000. * (double)gettime()) / (double)(count * get_n());
	fprintf(stderr, "%.5f %.3f\n", range / (1024. * 1024.), result);
E 22
E 20
I 15

D 16
	benchmp(initialize_loads, benchmark_loads, NOCLEANUP, 0, 2, &state);

	/* We want to get to nanoseconds / load. */
	fprintf(stderr,"*****************************************\n");
	result = (int)(((uint64)1000 * gettime()) / ((uint64)100 * get_n()));
	fprintf(stderr, "\t%.5f %d %d\n", range / (1024. * 1024), result, 2);
E 16
E 15
}

D 6
step(k)
E 6
I 6
D 23
int
step(int k)
E 23
I 23
size_t
step(size_t k)
E 23
E 6
{
	if (k < 1024) {
		k = k * 2;
        } else if (k < 4*1024) {
		k += 1024;
D 28
        } else if (k < 32*1024) {
E 28
I 28
D 29
	} else if (k < 32*1024) {
E 28
		k += 2048;
D 28
        } else if (k < 64*1024) {
E 28
I 28
	} else if (k < 64*1024) {
E 28
		k += 4096;
D 28
        } else if (k < 128*1024) {
E 28
I 28
	} else if (k < 128*1024) {
E 28
		k += 8192;
D 28
        } else if (k < 256*1024) {
E 28
I 28
	} else if (k < 256*1024) {
E 28
		k += 16384;
D 28
        } else if (k < 512*1024) {
E 28
I 28
	} else if (k < 512*1024) {
E 28
		k += 32*1024;
D 8
	} else {
E 8
I 8
	} else if (k < 4<<20) {
E 8
		k += 512 * 1024;
I 8
	} else if (k < 8<<20) {
		k += 1<<20;
	} else if (k < 20<<20) {
		k += 2<<20;
D 28
	} else {
E 28
I 28
 	} else {
E 28
		k += 10<<20;
E 29
I 29
	} else {
		size_t s;

		for (s = 32 * 1024; s <= k; s *= 2)
			;
		k += s / 16;
E 29
E 8
	}
	return (k);
}
D 6

float
getclock()
{
	float	c;
	FILE	*f = popen("mhz -c", "r");

	fscanf(f, "%f", &c);
	return (c);
}
I 3

int
bytes(s)
	char	*s;
{
	int	n = atoi(s);

	if ((last(s) == 'k') || (last(s) == 'K'))
		n *= 1024;
	if ((last(s) == 'm') || (last(s) == 'M'))
		n *= (1024 * 1024);
	return (n);
}

last(s)
	char	*s;
{
	while (*s++)
		;
	return (s[-2]);
}
E 6
E 3
E 2
I 1
E 1
