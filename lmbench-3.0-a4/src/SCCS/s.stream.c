H41292
s 00001/00001/00308
d D 1.12 04/02/03 16:52:53 staelin 13 12
c Fixup bug in stream; used wrong kernel
cC
cHfirewall.staelin.co.il
cK14911
e
s 00010/00010/00299
d D 1.11 03/03/10 10:28:41 staelin 12 11
c - fixup stream.c so it works with new benchmp interface
cC
cK15236
e
s 00024/00011/00285
d D 1.10 03/03/09 11:04:12 staelin 11 10
c - change benchmp() interface so we can have per-sample initialization
c   and cleanup.
cC
cK16966
e
s 00010/00008/00286
d D 1.9 02/11/04 08:46:13 staelin 10 9
c src/stream.c: fix bug in result reporting for parallel bandwidth
cC
cK05348
e
s 00008/00008/00286
d D 1.8 02/11/03 14:22:32 staelin 9 8
c src/stream.c: print out both latency and bandwidth.
cC
cK11739
cZ+02:00
e
s 00010/00002/00284
d D 1.7 01/06/20 09:12:23 staelin 8 7
c In stream, fix a bug in the memory requirement calculations, and 
c switch from using the median time to the minimum time, which is 
c more stable.
cC
cK13163
e
s 00016/00009/00270
d D 1.6 01/06/13 11:03:48 staelin 7 6
c Update stream so that it ensures you have enough memory; shrinks the
c problem size until it fits in memory.  Also update default problem
c size to match that of the original STREAM code(s).  Finally, comment
c out the latency reports since this is really a bandwidth benchmark.
c (It might make sense later to add in FLOPS reporting)
cC
cK01463
e
s 00122/00037/00157
d D 1.5 01/06/12 18:24:49 staelin 6 5
c Add code to stream to mimic STREAM version 2, and allow stream
c run with parallelism using benchmp.
cC
cHhpli69.hpli.hpl.hp.com
cK54294
cZ+03:00
e
s 00020/00012/00174
d D 1.4 00/10/31 10:00:57 staelin 5 4
c - Add SOCKOPT_REUSE to tcp_server() call
cC
cK12772
cZ+02:00
e
s 00003/00009/00183
d D 1.3 00/08/01 09:21:28 staelin 4 3
c - Replace custom code with call to bytes(optarg)
cC
cK06088
e
s 00011/00022/00181
d D 1.2 00/07/31 10:06:07 staelin 3 2
c Modified stream to use a[i] array indexing instead of pointer
c array access to match John McCalpin's style.
cC
cK15042
e
s 00203/00000/00000
d D 1.1 00/07/31 09:34:07 staelin 2 1
cF1
cK28275
cO-rw-rw-r--
e
s 00000/00000/00000
d D 1.0 00/07/31 09:34:07 staelin 1 0
c BitKeeper file /tmp_mnt/usr/WebPaper/users/staelin/src/LMbench/src/stream.c
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHhpli8.hpli.hpl.hp.com
cK55030
cPsrc/stream.c
cR3e0679a43128f870
cV4
cX0xa1
cZ+03:00
e
u
U
f e 0
f x 0xa1
t
T
I 2
/*
 * steam.c - lmbench version of John McCalpin's STREAM benchmark
 *
 * usage: stream
 *
 * Copyright (c) 2000 Carl Staelin.
 * Copyright (c) 1994 Larry McVoy.  Distributed under the FSF GPL with
 * additional restriction that results may published only if
 * (1) the benchmark is unmodified, and
 * (2) the version in the sccsid below is included in the report.
 * Support for this development by Sun Microsystems is gratefully acknowledged.
 */
char	*id = "$Id$\n";

#include "bench.h"

struct _state {
	double*	a;
	double*	b;
	double*	c;
	double	scalar;
	int	len;
};

D 11
void initialize(void* cookie);
I 6
void cleanup(void* cookie);
E 11
I 11
void initialize(iter_t iterations, void* cookie);
void cleanup(iter_t iterations, void* cookie);
E 11

/* These are from STREAM version 1 */
E 6
void copy(iter_t iterations, void* cookie);
void scale(iter_t iterations, void* cookie);
D 12
void sum(iter_t iterations, void* cookie);
E 12
I 12
void add(iter_t iterations, void* cookie);
E 12
void triad(iter_t iterations, void* cookie);
D 6
void cleanup(void* cookie);
E 6
I 6

/* These are from STREAM version 2 */
void fill(iter_t iterations, void* cookie);
/* NOTE: copy is the same as in version 1 */
void daxpy(iter_t iterations, void* cookie);
D 12
void cumsum(iter_t iterations, void* cookie);
E 12
I 12
void sum(iter_t iterations, void* cookie);
E 12

E 6

/*
 * Assumptions:
 *
 * 1) Cache lines are a multiple of pointer-size words
 * 2) Cache lines are no larger than 1/4 a page size
 * 3) Pages are an even multiple of cache lines
 */
int
main(int ac, char **av)
{
	int	i, j, l;
D 6
	int	verbose = 0;
E 6
I 6
	int	version = 1;
	int	parallel = 1;
E 6
	int	warmup = 0;
	int	repetitions = TRIES;
	int	c;
I 10
	uint64	datasize;
E 10
	struct _state state;
I 7
	char   *p;
E 7
D 6
	char   *usage = "[-v] [-W <warmup>] [-N <repetitions>][-M len[K|M]]\n";
E 6
I 6
	char   *usage = "[-v <stream version 1|2>] [-M <len>[K|M]] [-P <parallelism>] [-W <warmup>] [-N <repetitions>]\n";
E 6

D 7
        state.len = 1000 * 1000;
E 7
I 7
        state.len = 1000 * 1000 * 3 * sizeof(double);
E 7
	state.scalar = 3.0;

D 6
	while (( c = getopt(ac, av, "vM:W:N:")) != EOF) {
E 6
I 6
	while (( c = getopt(ac, av, "v:M:P:W:N:")) != EOF) {
E 6
		switch(c) {
		case 'v':
D 6
			verbose = 1;
E 6
I 6
			version = atoi(optarg);
			if (version != 1 && version != 2) 
				lmbench_usage(ac, av, usage);
			break;
		case 'P':
			parallel = atoi(optarg);
			if (parallel <= 0) lmbench_usage(ac, av, usage);
E 6
			break;
		case 'M':
D 4
			l = strlen(optarg);
			if (optarg[l-1] == 'm' || optarg[l-1] == 'M') {
				state.len = 1024 * 1024;
				optarg[l-1] = 0;
			} else if (optarg[l-1] == 'k' || optarg[l-1] == 'K') {
				state.len = 1024;
				optarg[l-1] = 0;
			}
			state.len *= atoi(optarg);
E 4
I 4
			state.len = bytes(optarg);
D 8
			/* convert from bytes to array length */
			state.len /= 3 * sizeof(double);
E 8
E 4
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

I 7
	/* ensure that we can malloc the desired space */
	while (!(p = malloc(state.len)))
		state.len /= 2;
	free(p);
		
I 8
	/* convert from bytes to array length */
	state.len /= 3 * sizeof(double);
I 10
	datasize = sizeof(double) * state.len * parallel;
E 10
E 8

E 7
D 6
	benchmp(initialize, copy, cleanup, 0, 1, warmup, repetitions, &state);
	save_minimum();
D 5
	nano("STREAM copy latency", state.len * get_n());
	fprintf(stderr, "STREAM copy bandwidth: ");
D 3
	mb(sizeof(double) * state.len * get_n());
E 3
I 3
	mb(2 * sizeof(double) * state.len * get_n());
E 5
I 5
	if (gettime() > 0) {
		nano("STREAM copy latency", state.len * get_n());
		fprintf(stderr, "STREAM copy bandwidth: ");
		mb(2 * sizeof(double) * state.len * get_n());
	}
E 5
E 3

	benchmp(initialize, scale, cleanup, 0, 1, warmup, repetitions, &state);
	save_minimum();
D 5
	nano("STREAM scale latency", state.len * get_n());
	fprintf(stderr, "STREAM scale bandwidth: ");
D 3
	mb(sizeof(double) * state.len * get_n());
E 3
I 3
	mb(2 * sizeof(double) * state.len * get_n());
E 5
I 5
	if (gettime() > 0) {
		nano("STREAM scale latency", state.len * get_n());
		fprintf(stderr, "STREAM scale bandwidth: ");
		mb(2 * sizeof(double) * state.len * get_n());
	}
E 5
E 3

	benchmp(initialize, sum, cleanup, 0, 1, warmup, repetitions, &state);
	save_minimum();
D 5
	nano("STREAM sum latency", state.len * get_n());
	fprintf(stderr, "STREAM sum bandwidth: ");
D 3
	mb(sizeof(double) * state.len * get_n());
E 3
I 3
	mb(3 * sizeof(double) * state.len * get_n());
E 5
I 5
	if (gettime() > 0) {
		nano("STREAM sum latency", state.len * get_n());
		fprintf(stderr, "STREAM sum bandwidth: ");
		mb(3 * sizeof(double) * state.len * get_n());
	}
E 5
E 3

	benchmp(initialize, triad, cleanup, 0, 1, warmup, repetitions, &state);
	save_minimum();
D 5
	nano("STREAM triad latency", state.len * get_n());
	fprintf(stderr, "STREAM triad bandwidth: ");
D 3
	mb(sizeof(double) * state.len * get_n());
E 3
I 3
	mb(3 * sizeof(double) * state.len * get_n());
E 5
I 5
	if (gettime() > 0) {
		nano("STREAM triad latency", state.len * get_n());
		fprintf(stderr, "STREAM triad bandwidth: ");
		mb(3 * sizeof(double) * state.len * get_n());
E 6
I 6
	if (version == 1) {
		benchmp(initialize, copy, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM copy latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM copy latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM copy latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM copy bandwidth: ");
D 10
			mb(2 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(2 * datasize * get_n());
E 10
		}

		benchmp(initialize, scale, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM scale latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM scale latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM scale latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM scale bandwidth: ");
D 10
			mb(2 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(2 * datasize * get_n());
E 10
		}

		benchmp(initialize, sum, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM sum latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM sum latency", state.len * get_n());*/
E 9
I 9
D 12
			nano("STREAM sum latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM sum bandwidth: ");
E 12
I 12
			nano("STREAM add latency", state.len * get_n());
			fprintf(stderr, "STREAM add bandwidth: ");
E 12
D 10
			mb(3 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(3 * datasize * get_n());
E 10
		}

		benchmp(initialize, triad, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM triad latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM triad latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM triad latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM triad bandwidth: ");
D 10
			mb(3 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(3 * datasize * get_n());
E 10
		}
	} else {
		benchmp(initialize, fill, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM2 fill latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM2 fill latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM2 fill latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM2 fill bandwidth: ");
D 10
			mb(sizeof(double) * state.len * get_n());
E 10
I 10
			mb(datasize * get_n());
E 10
		}

		benchmp(initialize, copy, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM2 copy latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM2 copy latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM2 copy latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM2 copy bandwidth: ");
D 10
			mb(2 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(2 * datasize * get_n());
E 10
		}

		benchmp(initialize, daxpy, cleanup, 
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM2 daxpy latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM2 daxpy latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM2 daxpy latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM2 daxpy bandwidth: ");
D 10
			mb(3 * sizeof(double) * state.len * get_n());
E 10
I 10
			mb(3 * datasize * get_n());
E 10
		}

D 13
		benchmp(initialize, cumsum, cleanup, 
E 13
I 13
		benchmp(initialize, sum, cleanup, 
E 13
			0, parallel, warmup, repetitions, &state);
		if (gettime() > 0) {
I 8
			save_minimum();
E 8
D 7
			nano("STREAM2 sum latency", state.len * get_n());
E 7
I 7
D 9
			/*nano("STREAM2 sum latency", state.len * get_n());*/
E 9
I 9
			nano("STREAM2 sum latency", state.len * get_n());
E 9
E 7
			fprintf(stderr, "STREAM2 sum bandwidth: ");
D 10
			mb(sizeof(double) * state.len * get_n());
E 10
I 10
			mb(datasize * get_n());
E 10
		}
E 6
	}
E 5
E 3

	return(0);
}

void
D 11
initialize(void* cookie)
E 11
I 11
initialize(iter_t iterations, void* cookie)
E 11
{
	int i;
	struct _state* state = (struct _state*)cookie;
	
I 11
	if (iterations) return;

E 11
	state->a = (double*)malloc(sizeof(double) * state->len);
	state->b = (double*)malloc(sizeof(double) * state->len);
	state->c = (double*)malloc(sizeof(double) * state->len);

	if (state->a == NULL || state->b == NULL || state->c == NULL) {
		exit(1);
	}

	for (i = 0; i < state->len; ++i) {
D 6
		state->a[i] = 0.;
		state->b[i] = 0.;
E 6
I 6
		state->a[i] = 1.;
		state->b[i] = 2.;
E 6
		state->c[i] = 0.;
	}
}

D 3

#define TEN(a) a a a a a a a a a a
#define HUNDRED(a) TEN(TEN(a))

E 3
#define BODY(expr)							\
{									\
D 3
	register int N = state->len - state->len % 100;			\
E 3
I 3
	register int i;							\
	register int N = state->len;					\
E 3
	register double* a = state->a;					\
	register double* b = state->b;					\
	register double* c = state->c;					\
	register double scalar = state->scalar;				\
									\
	state->a = state->b;						\
	state->b = state->c;						\
	state->c = a;							\
									\
D 3
	for (i = 0; i < N; i+=100) {					\
		HUNDRED(expr);						\
	}								\
	N = state->len;							\
	for (; i < N; ++i) {						\
E 3
I 3
	for (i = 0; i < N; ++i) {					\
E 3
		expr;							\
	}								\
}

D 11
void copy(iter_t iterations, void *cookie)
E 11
I 11
void
copy(iter_t iterations, void *cookie)
E 11
{
D 3
	register int i;
E 3
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
D 3
		BODY(*(c++) = *(a++);)
E 3
I 3
		BODY(c[i] = a[i];)
E 3
	}
}

D 11
void scale(iter_t iterations, void *cookie)
E 11
I 11
void
scale(iter_t iterations, void *cookie)
E 11
{
D 3
	register int i;
E 3
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
D 3
		BODY(*(b++) = scalar * *(c++);)
E 3
I 3
		BODY(b[i] = scalar * c[i];)
E 3
	}
}

D 11
void sum(iter_t iterations, void *cookie)
E 11
I 11
void
D 12
sum(iter_t iterations, void *cookie)
E 12
I 12
add(iter_t iterations, void *cookie)
E 12
E 11
{
D 3
	register int i;
E 3
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
D 3
		BODY(*(c++) = *(a++) + *(b++);)
E 3
I 3
		BODY(c[i] = a[i] + b[i];)
E 3
	}
}

D 11
void triad(iter_t iterations, void *cookie)
E 11
I 11
void
triad(iter_t iterations, void *cookie)
E 11
{
D 3
	register int i;
E 3
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
D 3
		BODY(*(a++) = *(b++) + scalar * *(c++);)
E 3
I 3
		BODY(a[i] = b[i] + scalar * c[i];)
E 3
	}
I 6
}

/*
 * STREAM version 2 benchmark kernels
 *
 * NOTE: copy is the same as version 1's benchmark
 */
D 11
void fill(iter_t iterations, void *cookie)
E 11
I 11
void
fill(iter_t iterations, void *cookie)
E 11
{
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
		BODY(a[i] = 0;)
	}
}

D 11
void daxpy(iter_t iterations, void *cookie)
E 11
I 11
void
daxpy(iter_t iterations, void *cookie)
E 11
{
	struct _state* state = (struct _state*)cookie;

	while (iterations-- > 0) {
		BODY(a[i] = a[i] + scalar * b[i];)
	}
}

D 11
void cumsum(iter_t iterations, void *cookie)
E 11
I 11
void
D 12
cumsum(iter_t iterations, void *cookie)
E 12
I 12
sum(iter_t iterations, void *cookie)
E 12
E 11
{
D 12
	register double	sum;
E 12
I 12
	register double	s;
E 12
	struct _state* state = (struct _state*)cookie;

D 12
	sum = 0.0;
E 12
I 12
	s = 0.0;
E 12
	while (iterations-- > 0) {
D 12
		BODY(sum += a[i];)
E 12
I 12
		BODY(s += a[i];)
E 12
	}
D 12
	use_int((int)sum);
E 12
I 12
	use_int((int)s);
E 12
E 6
}

D 11
void cleanup(void* cookie)
E 11
I 11
void
cleanup(iter_t iterations, void* cookie)
E 11
{
	struct _state* state = (struct _state*)cookie;
I 11

	if (iterations) return;

E 11
	free(state->a);
	free(state->b);
	free(state->c);
}



E 2
I 1
E 1
