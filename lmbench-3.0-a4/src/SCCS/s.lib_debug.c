H00641
s 00010/00010/00120
d D 1.2 02/12/13 09:13:02 staelin 3 2
c lib_debug.c: fix typos; percentage_point -> percent_point
cC
cK54507
cZ+02:00
e
s 00130/00000/00000
d D 1.1 02/10/01 09:48:25 staelin 2 1
cC
cF1
cK57517
cO-rw-rw-r--
e
s 00000/00000/00000
d D 1.0 02/10/01 09:48:25 staelin 1 0
c BitKeeper file /usr/WebPaper/users/staelin/src/LMbench3/src/lib_debug.c
cBlm@lm.bitmover.com|ChangeSet|20000131225335|47351|--LMBENCH--
cHhpli69.hpli.hpl.hp.com
cK16912
cPsrc/lib_debug.c
cRe609863b14b0b8ac
cV4
cX0x821
cZ+03:00
e
u
U
f e 0
f x 0x821
t
T
I 2
#include "bench.h"
#include "lib_debug.h"

/*
 * return micro-seconds / iteration at the the fraction point.
 *
 * some examples:
 *	min = percent_point(values, size, 0.0)
 * 	1st quartile = percent_point(values, size, 0.25)
 * 	median = percent_point(values, size, 0.5)
 * 	3rd quartile = percent_point(values, size, 0.75)
 *	max = percent_point(values, size, 1.0)
 *
 * the data points in the results structure are sorted from
 * largest to smallest, so we adjust the fraction accordingly.
 */
double
percent_point(double fraction)
{
	double	t, r;
	result_t* results = get_results();

	t = (1.0 - fraction) * (results->N - 1);
	if (t == floor(t)) {
		/* no interpolation */
		r = results->v[(int)t].u / (double)results->v[(int)t].n;
	} else {
		/* percent point falls between two points, interpolate */
		r = results->v[(int)t].u / (double)results->v[(int)t].n;
		r += results->v[(int)t+1].u / (double)results->v[(int)t+1].n;
		r /= 2.0;
	}

	return r;
}

void
print_results(int details)
{
	int	i;
	result_t* results = get_results();

	fprintf(stderr, "N=%d, t={", results->N);
	for (i = 0; i < results->N; ++i) {
		fprintf(stderr, "%.2f", (double)results->v[i].u/results->v[i].n);
		if (i < results->N - 1) 
			fprintf(stderr, ", ");
	}
	fprintf(stderr, "}\n");
	if (details) {
		fprintf(stderr, "\t/* {", results->N);
		for (i = 0; i < results->N; ++i) {
			fprintf(stderr, 
				"%llu/%llu", results->v[i].u, results->v[i].n);
			if (i < results->N - 1)
				fprintf(stderr, ", ");
		}
		fprintf(stderr, "} */\n");
	}
		
}

/*
 * Prints bandwidth (MB/s) quartile information
 *
 * bytes - bytes per iteration
 */
void
bw_quartile(uint64 bytes)
{
	double	b = (double)bytes;

	fprintf(stderr, "%d\t%e\t%e\t%e\t%e\t%e\n", get_n(), 
D 3
		(double)bytes / (1000000. * percentage_point(0.00)),
		(double)bytes / (1000000. * percentage_point(0.25)),
		(double)bytes / (1000000. * percentage_point(0.50)),
		(double)bytes / (1000000. * percentage_point(0.75)),
		(double)bytes / (1000000. * percentage_point(1.00)));
E 3
I 3
		(double)bytes / (1000000. * percent_point(0.00)),
		(double)bytes / (1000000. * percent_point(0.25)),
		(double)bytes / (1000000. * percent_point(0.50)),
		(double)bytes / (1000000. * percent_point(0.75)),
		(double)bytes / (1000000. * percent_point(1.00)));
E 3
}

/*
 * Prints latency (nano-seconds) quartile information
 *
 * n - number of operations per iteration
 */
void
nano_quartile(uint64 n)
{
	fprintf(stderr, "%d\t%e\t%e\t%e\t%e\t%e\n", get_n(), 
D 3
		percentage_point(0.00) * 1000. / (double)n,
		percentage_point(0.25) * 1000. / (double)n,
		percentage_point(0.50) * 1000. / (double)n,
		percentage_point(0.75) * 1000. / (double)n,
		percentage_point(1.00) * 1000. / (double)n);
E 3
I 3
		percent_point(0.00) * 1000. / (double)n,
		percent_point(0.25) * 1000. / (double)n,
		percent_point(0.50) * 1000. / (double)n,
		percent_point(0.75) * 1000. / (double)n,
		percent_point(1.00) * 1000. / (double)n);
E 3
}

/*
 * print the page|line|word offset for each link in the pointer chain.
 */
void
print_mem(char* addr, size_t size, size_t line)
{
	char*	p;
	uint64	base, off;
	size_t	pagesize = getpagesize();

	base = (uint64)addr;
	for (p = addr; *(char**)p != addr; p = *(char**)p) {
		off = (uint64)p - base;
		fprintf(stderr, "\t%lu\t%lu\t%lu\n", off / pagesize, 
			(off % pagesize) / line, (off % line) / sizeof(char*));
	}
}

void
check_mem(char* addr, size_t size)
{
	char*	p;
	size_t	i;
	size_t	max = size / sizeof(char*) + 1;

	for (p=addr, i=0; *(char**)p != addr && i < max; p = *(char**)p, i++) {
		if (p < addr || addr + size <= p) {
			fprintf(stderr, "check_mem: pointer out of range!\n");
		}
	}
	if (*(char**)p != addr) {
		fprintf(stderr, "check_mem: pointer chain doesn't loop\n");
	}
}
E 2
I 1
E 1
