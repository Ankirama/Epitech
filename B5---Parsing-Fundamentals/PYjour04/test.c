const int a;
extern int bite : 8;
register float d = 42;
auto double b;
char a;
unsigned char a;
int a;
unsigned int a;
short test;
unsigned short test;
short int test3;
short short test4;
int int test5;
long test1;
unsigned long test1;
long long test2;
unsigned long long test2;
int *pi;
static int aaa;
extern short bbbb;
void **buf;
unsigned buffer[sizeof(struct s) * 512];
float bigbuffer[42][32][41];
char * const toto;
volatile char *volatile*const* theStr;

int (*callback)(int, char **);
void tutu(void *, ...);
int (*const*volatile*tululu[23])(int, char **);
typedef double GG;
GG boulon;
typedef int (*entry_point)(int, char **);
enum E {A,B = 5 * sizeof(int),C = 4,D} F;
struct _list { void *data; int bla : 4; struct _list *next;};
union A {int a; double d;};
union W {int a; double d;} V;
inline int max(int x, int y) {return (x < y)? y : x;}

struct {int x; double y;} *carnage(enum e, double*[]);
