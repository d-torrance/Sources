#ifndef LONGALG_H
#define LONGALG_H
/****************************************
*  Computer Algebra System SINGULAR     *
****************************************/
/* $Id: longalg.h,v 1.23 2000-12-08 16:20:33 Singular Exp $ */
/*
* ABSTRACT:   algebraic numbers
*/
#include "structs.h"
#include "longrat.h"
#include "polys-impl.h"

struct slnumber;
typedef struct slnumber * lnumber;

//make parameter type same as exponent type
#define PARAMETER_TYPE short
#define SIZEOF_PARAMETER SIZEOF_SHORT

struct reca
{
  alg ne;
  number ko;
  PARAMETER_TYPE e[1];
};

struct slnumber
{
  alg z;
  alg n;
  BOOLEAN s;
};

extern int naNumbOfPar;             /* maximal number of parameters */
extern alg naMinimalPoly;
extern char **naParNames;
extern int napMonomSize;

void naSetChar(int p, ring r);
#define napAddExp(P,I,E)  ((P)->e[I-1]+=(E))
#define napLength(p)      (pLength((poly)p))
#ifdef LDEBUG
void    naDBDelete (number *p,char *f, int l);
#define naDelete(A) naDBDelete(A,__FILE__,__LINE__)
#else
void    naDelete (number *p);
#endif
number  naInit(int i);                              /* z := i */
number  naPar(int i);                               /* z := par(i) */
int     naParDeg(number n);                         /* i := deg(n) */
int     naSize(number n);                           /* size desc. */
int     naInt(number &n);
void    naNumberToInt(number n, int *i);
void    naNew(number *z);
BOOLEAN naIsZero(number za);                         /* za = 0 ? */
BOOLEAN naIsOne(number  za);                         /* za = 1 ? */
BOOLEAN naIsMOne(number  za);                        /* za = -1 ? */
BOOLEAN naEqual(number a, number b);                  /* a = b ? */
BOOLEAN naGreater(number a, number b);                  /* dummy */
number  naNeg(number za);                           /* za := - za */
number  naInvers(number a);
BOOLEAN naGreaterZero(number a);
void    naPower(number x, int exp, number *lo);
BOOLEAN naGreaterZero(number a);
number  naCopy(number p);                              /* erg:= p */
number  naAdd(number la, number li);               /* lu := la+li */
number  naMult(number la, number li);              /* lo := la*li */
number  naDiv(number la, number li);               /* lo := la/li */
number  naIntDiv(number la, number li);            /* lo := la/li */
//number  naIntMod(number la, number li);            /* lo := la/li */
number  naSub(number la, number li);               /* lu := la-li */
void    naNormalize(number &p);
number  naGcd(number a, number b);
number  naLcm(number a, number b);
char *  naRead(char * s, number * p);
void    naWrite(number &p);
char *  naName(number n);
BOOLEAN naSetMap(ring r);
#ifdef LDEBUG
BOOLEAN naDBTest(number a, char *f,int l);
#endif

void    naSetIdeal(ideal I);

// external access to the interna
#define RECA_SIZE (sizeof(alg)+sizeof(number))
alg napAdd(alg p1, alg p2);
void napDelete(alg *p);
poly naPermNumber(number z, int * par_perm, int P, ring r);
#define napVariables naNumbOfPar
#define napNext(p) (p->ne)
#define napIter(p) ((p) = (p)->ne)
#define napGetCoeff(p) (p->ko)
#define napGetExp(p,i) ((p)->e[(i)-1])
#define napGetExpFrom(p,i,r) ((p)->e[(i)-1])
#define napSetExp(p,i,ee) ((p)->e[(i)-1]=ee)
#define napNew() ((alg)omAlloc0(napMonomSize))
#define nanumber lnumber
#define naGetNom0(na)  (((nanumber)(na))->z)
#define naGetDenom0(na)  (((nanumber)(na))->n)
extern number   (*nacCopy)(number a);
extern BOOLEAN  (*nacIsZero)(number a);
extern number   (*nacInit)(int i);
extern void     (*nacNormalize)(number &a);
extern void napWrite(alg l);
extern number   naGetDenom(number &n);
#endif

