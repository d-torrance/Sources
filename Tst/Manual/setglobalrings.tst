LIB "tst.lib"; tst_init();
LIB "grobcov.lib";
ring R=(0,a,b),(x,y,z),dp;
setglobalrings();
Grobcov::@R;
Grobcov::@P;
Grobcov::@RP;
tst_status(1);$
