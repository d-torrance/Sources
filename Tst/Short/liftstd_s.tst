LIB "tst.lib";
tst_init();
//
// test script for liftstd command
//
pagelength = 10000;
ring r1 = 32003,(x,y,z),(c,ls);
r1;
LIB "lib0";
"-------------------------------";
ideal i1=maxideal(3);
ideal i2=x6,y4,z5,xy,yz,xz;
i2;
matrix m1[3][3]=x,y,z,xz,yx,12zx,0,y2,3xy2;
pmat(m1);
liftstd(i2,m1);
"---------------------------------";
vector v1=[x4,y2,xz2];
vector v2=[y3,x8,2z4];
module m=v1,v2;
m;
pmat(m1);
liftstd(m,m1);
"--------------------------------";
listvar(all);
kill r1;
ring R;
poly f=x3+y7+z2+xyz;
ideal i=jacob(f);
matrix T;
ideal sm=liftstd(i,T);
matrix(sm)-matrix(i)*T;
kill R;
$;
