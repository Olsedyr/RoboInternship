# 1 "scene.c"
# 1 "/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "scene.c"



# 1 "/usr/include/stdlib.h" 1 3 4
# 25 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 313 "/usr/include/features.h" 3 4
# 1 "/usr/include/bits/predefs.h" 1 3 4
# 314 "/usr/include/features.h" 2 3 4
# 346 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 353 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 354 "/usr/include/sys/cdefs.h" 2 3 4
# 347 "/usr/include/features.h" 2 3 4
# 378 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4



# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/gnu/stubs.h" 2 3 4


# 1 "/usr/include/gnu/stubs-32.h" 1 3 4
# 8 "/usr/include/gnu/stubs.h" 2 3 4
# 379 "/usr/include/features.h" 2 3 4
# 26 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 323 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3 4
typedef int wchar_t;
# 34 "/usr/include/stdlib.h" 2 3 4


# 96 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 140 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__)) ;




extern double atof (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (__const char *__nptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (__const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern float strtof (__const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern long double strtold (__const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern long int strtol (__const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

extern unsigned long int strtoul (__const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




__extension__
extern long long int strtoq (__const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





__extension__
extern long long int strtoll (__const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;

# 311 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__)) ;


extern long int a64l (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4


# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;
# 131 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 132 "/usr/include/bits/types.h" 2 3 4


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct { int __val[2]; } __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef void * __timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 62 "/usr/include/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 100 "/usr/include/sys/types.h" 3 4
typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4
# 147 "/usr/include/sys/types.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 195 "/usr/include/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 217 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 61 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/byteswap.h" 1 3 4
# 28 "/usr/include/bits/byteswap.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/byteswap.h" 2 3 4
# 62 "/usr/include/endian.h" 2 3 4
# 218 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 23 "/usr/include/bits/select.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/select.h" 2 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 24 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 121 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);



# 221 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 30 "/usr/include/sys/sysmacros.h" 3 4
__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__));
# 224 "/usr/include/sys/types.h" 2 3 4
# 235 "/usr/include/sys/types.h" 3 4
typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 270 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4
# 50 "/usr/include/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;
# 67 "/usr/include/bits/pthreadtypes.h" 3 4
typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;





typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;





    int __kind;





    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };

  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{
# 170 "/usr/include/bits/pthreadtypes.h" 3 4
  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;


    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;

  char __size[32];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/sys/types.h" 2 3 4



# 321 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));







extern double drand48 (void) __attribute__ ((__nothrow__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__));



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__));






# 498 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern void abort (void) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 530 "/usr/include/stdlib.h" 3 4





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));
# 553 "/usr/include/stdlib.h" 3 4






extern void _Exit (int __status) __attribute__ ((__nothrow__)) __attribute__ ((__noreturn__));






extern char *getenv (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;




extern char *__secure_getenv (__const char *__name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern int putenv (char *__string) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (__const char *__name, __const char *__value, int __replace)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__));






extern int clearenv (void) __attribute__ ((__nothrow__));
# 604 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 615 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 635 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 661 "/usr/include/stdlib.h" 3 4





extern int system (__const char *__command) ;

# 683 "/usr/include/stdlib.h" 3 4
extern char *realpath (__const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__)) ;






typedef int (*__compar_fn_t) (__const void *, __const void *);
# 701 "/usr/include/stdlib.h" 3 4



extern void *bsearch (__const void *__key, __const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;



extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 720 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__)) ;

# 756 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));







extern int mblen (__const char *__s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int mbtowc (wchar_t *__restrict __pwc,
     __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__)) ;


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__)) ;



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   __const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__));

extern size_t wcstombs (char *__restrict __s,
   __const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__));








extern int rpmatch (__const char *__response) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 861 "/usr/include/stdlib.h" 3 4
extern int posix_openpt (int __oflag) ;
# 896 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 912 "/usr/include/stdlib.h" 3 4

# 5 "scene.c" 2
# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest,
       __const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 94 "/usr/include/string.h" 3 4
extern void *memchr (__const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 125 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));






# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 162 "/usr/include/string.h" 2 3 4


extern int strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (__const char *__string, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 208 "/usr/include/string.h" 3 4

# 233 "/usr/include/string.h" 3 4
extern char *strchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 260 "/usr/include/string.h" 3 4
extern char *strrchr (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 279 "/usr/include/string.h" 3 4



extern size_t strcspn (__const char *__s, __const char *__reject)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 312 "/usr/include/string.h" 3 4
extern char *strpbrk (__const char *__s, __const char *__accept)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 340 "/usr/include/string.h" 3 4
extern char *strstr (__const char *__haystack, __const char *__needle)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    __const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));
# 395 "/usr/include/string.h" 3 4


extern size_t strlen (__const char *__s)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (__const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

# 425 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 443 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (__const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 487 "/usr/include/string.h" 3 4
extern char *index (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 515 "/usr/include/string.h" 3 4
extern char *rindex (__const char *__s, int __c)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 534 "/usr/include/string.h" 3 4
extern int strcasecmp (__const char *__s1, __const char *__s2)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 557 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       __const char *__restrict __delim)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__));


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        __const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
# 644 "/usr/include/string.h" 3 4

# 6 "scene.c" 2
# 1 "/usr/include/math.h" 1 3 4
# 30 "/usr/include/math.h" 3 4




# 1 "/usr/include/bits/huge_val.h" 1 3 4
# 35 "/usr/include/math.h" 2 3 4

# 1 "/usr/include/bits/huge_valf.h" 1 3 4
# 37 "/usr/include/math.h" 2 3 4
# 1 "/usr/include/bits/huge_vall.h" 1 3 4
# 38 "/usr/include/math.h" 2 3 4


# 1 "/usr/include/bits/inf.h" 1 3 4
# 41 "/usr/include/math.h" 2 3 4


# 1 "/usr/include/bits/nan.h" 1 3 4
# 44 "/usr/include/math.h" 2 3 4



# 1 "/usr/include/bits/mathdef.h" 1 3 4
# 26 "/usr/include/bits/mathdef.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 27 "/usr/include/bits/mathdef.h" 2 3 4
# 38 "/usr/include/bits/mathdef.h" 3 4
typedef long double float_t;

typedef long double double_t;
# 48 "/usr/include/math.h" 2 3 4
# 71 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4


extern double acos (double __x) __attribute__ ((__nothrow__)); extern double __acos (double __x) __attribute__ ((__nothrow__));

extern double asin (double __x) __attribute__ ((__nothrow__)); extern double __asin (double __x) __attribute__ ((__nothrow__));

extern double atan (double __x) __attribute__ ((__nothrow__)); extern double __atan (double __x) __attribute__ ((__nothrow__));

extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__));


extern double cos (double __x) __attribute__ ((__nothrow__)); extern double __cos (double __x) __attribute__ ((__nothrow__));

extern double sin (double __x) __attribute__ ((__nothrow__)); extern double __sin (double __x) __attribute__ ((__nothrow__));

extern double tan (double __x) __attribute__ ((__nothrow__)); extern double __tan (double __x) __attribute__ ((__nothrow__));




extern double cosh (double __x) __attribute__ ((__nothrow__)); extern double __cosh (double __x) __attribute__ ((__nothrow__));

extern double sinh (double __x) __attribute__ ((__nothrow__)); extern double __sinh (double __x) __attribute__ ((__nothrow__));

extern double tanh (double __x) __attribute__ ((__nothrow__)); extern double __tanh (double __x) __attribute__ ((__nothrow__));

# 87 "/usr/include/bits/mathcalls.h" 3 4


extern double acosh (double __x) __attribute__ ((__nothrow__)); extern double __acosh (double __x) __attribute__ ((__nothrow__));

extern double asinh (double __x) __attribute__ ((__nothrow__)); extern double __asinh (double __x) __attribute__ ((__nothrow__));

extern double atanh (double __x) __attribute__ ((__nothrow__)); extern double __atanh (double __x) __attribute__ ((__nothrow__));







extern double exp (double __x) __attribute__ ((__nothrow__)); extern double __exp (double __x) __attribute__ ((__nothrow__));


extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__));


extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__));


extern double log (double __x) __attribute__ ((__nothrow__)); extern double __log (double __x) __attribute__ ((__nothrow__));


extern double log10 (double __x) __attribute__ ((__nothrow__)); extern double __log10 (double __x) __attribute__ ((__nothrow__));


extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__));

# 127 "/usr/include/bits/mathcalls.h" 3 4


extern double expm1 (double __x) __attribute__ ((__nothrow__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__));


extern double log1p (double __x) __attribute__ ((__nothrow__)); extern double __log1p (double __x) __attribute__ ((__nothrow__));


extern double logb (double __x) __attribute__ ((__nothrow__)); extern double __logb (double __x) __attribute__ ((__nothrow__));






extern double exp2 (double __x) __attribute__ ((__nothrow__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__));


extern double log2 (double __x) __attribute__ ((__nothrow__)); extern double __log2 (double __x) __attribute__ ((__nothrow__));








extern double pow (double __x, double __y) __attribute__ ((__nothrow__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__));


extern double sqrt (double __x) __attribute__ ((__nothrow__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__));





extern double hypot (double __x, double __y) __attribute__ ((__nothrow__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__));






extern double cbrt (double __x) __attribute__ ((__nothrow__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__));








extern double ceil (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double fabs (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double floor (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double fmod (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__));




extern int __isinf (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int __finite (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int isinf (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int finite (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double drem (double __x, double __y) __attribute__ ((__nothrow__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__));



extern double significand (double __x) __attribute__ ((__nothrow__)); extern double __significand (double __x) __attribute__ ((__nothrow__));





extern double copysign (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));






extern double nan (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nan (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int __isnan (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern int isnan (double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern double j0 (double) __attribute__ ((__nothrow__)); extern double __j0 (double) __attribute__ ((__nothrow__));
extern double j1 (double) __attribute__ ((__nothrow__)); extern double __j1 (double) __attribute__ ((__nothrow__));
extern double jn (int, double) __attribute__ ((__nothrow__)); extern double __jn (int, double) __attribute__ ((__nothrow__));
extern double y0 (double) __attribute__ ((__nothrow__)); extern double __y0 (double) __attribute__ ((__nothrow__));
extern double y1 (double) __attribute__ ((__nothrow__)); extern double __y1 (double) __attribute__ ((__nothrow__));
extern double yn (int, double) __attribute__ ((__nothrow__)); extern double __yn (int, double) __attribute__ ((__nothrow__));






extern double erf (double) __attribute__ ((__nothrow__)); extern double __erf (double) __attribute__ ((__nothrow__));
extern double erfc (double) __attribute__ ((__nothrow__)); extern double __erfc (double) __attribute__ ((__nothrow__));
extern double lgamma (double) __attribute__ ((__nothrow__)); extern double __lgamma (double) __attribute__ ((__nothrow__));






extern double tgamma (double) __attribute__ ((__nothrow__)); extern double __tgamma (double) __attribute__ ((__nothrow__));





extern double gamma (double) __attribute__ ((__nothrow__)); extern double __gamma (double) __attribute__ ((__nothrow__));






extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__));







extern double rint (double __x) __attribute__ ((__nothrow__)); extern double __rint (double __x) __attribute__ ((__nothrow__));


extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern double remainder (double __x, double __y) __attribute__ ((__nothrow__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__));



extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__));



extern int ilogb (double __x) __attribute__ ((__nothrow__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__));




extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__));



extern double nearbyint (double __x) __attribute__ ((__nothrow__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__));



extern double round (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern double trunc (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__));






extern long int lrint (double __x) __attribute__ ((__nothrow__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__));
extern long long int llrint (double __x) __attribute__ ((__nothrow__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__));



extern long int lround (double __x) __attribute__ ((__nothrow__)); extern long int __lround (double __x) __attribute__ ((__nothrow__));
extern long long int llround (double __x) __attribute__ ((__nothrow__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__));



extern double fdim (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__));


extern double fmax (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__));


extern double fmin (double __x, double __y) __attribute__ ((__nothrow__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__));



extern int __fpclassify (double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));


extern int __signbit (double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));



extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__));








extern double scalb (double __x, double __n) __attribute__ ((__nothrow__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__));
# 72 "/usr/include/math.h" 2 3 4
# 94 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4


extern float acosf (float __x) __attribute__ ((__nothrow__)); extern float __acosf (float __x) __attribute__ ((__nothrow__));

extern float asinf (float __x) __attribute__ ((__nothrow__)); extern float __asinf (float __x) __attribute__ ((__nothrow__));

extern float atanf (float __x) __attribute__ ((__nothrow__)); extern float __atanf (float __x) __attribute__ ((__nothrow__));

extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__));


extern float cosf (float __x) __attribute__ ((__nothrow__)); extern float __cosf (float __x) __attribute__ ((__nothrow__));

extern float sinf (float __x) __attribute__ ((__nothrow__)); extern float __sinf (float __x) __attribute__ ((__nothrow__));

extern float tanf (float __x) __attribute__ ((__nothrow__)); extern float __tanf (float __x) __attribute__ ((__nothrow__));




extern float coshf (float __x) __attribute__ ((__nothrow__)); extern float __coshf (float __x) __attribute__ ((__nothrow__));

extern float sinhf (float __x) __attribute__ ((__nothrow__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__));

extern float tanhf (float __x) __attribute__ ((__nothrow__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__));

# 87 "/usr/include/bits/mathcalls.h" 3 4


extern float acoshf (float __x) __attribute__ ((__nothrow__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__));

extern float asinhf (float __x) __attribute__ ((__nothrow__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__));

extern float atanhf (float __x) __attribute__ ((__nothrow__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__));







extern float expf (float __x) __attribute__ ((__nothrow__)); extern float __expf (float __x) __attribute__ ((__nothrow__));


extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__));


extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__));


extern float logf (float __x) __attribute__ ((__nothrow__)); extern float __logf (float __x) __attribute__ ((__nothrow__));


extern float log10f (float __x) __attribute__ ((__nothrow__)); extern float __log10f (float __x) __attribute__ ((__nothrow__));


extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__));

# 127 "/usr/include/bits/mathcalls.h" 3 4


extern float expm1f (float __x) __attribute__ ((__nothrow__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__));


extern float log1pf (float __x) __attribute__ ((__nothrow__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__));


extern float logbf (float __x) __attribute__ ((__nothrow__)); extern float __logbf (float __x) __attribute__ ((__nothrow__));






extern float exp2f (float __x) __attribute__ ((__nothrow__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__));


extern float log2f (float __x) __attribute__ ((__nothrow__)); extern float __log2f (float __x) __attribute__ ((__nothrow__));








extern float powf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__));


extern float sqrtf (float __x) __attribute__ ((__nothrow__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__));





extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__));






extern float cbrtf (float __x) __attribute__ ((__nothrow__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__));








extern float ceilf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float fabsf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float floorf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__));




extern int __isinff (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int __finitef (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int isinff (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int finitef (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float dremf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__));



extern float significandf (float __x) __attribute__ ((__nothrow__)); extern float __significandf (float __x) __attribute__ ((__nothrow__));





extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));






extern float nanf (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nanf (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int __isnanf (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern int isnanf (float __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern float j0f (float) __attribute__ ((__nothrow__)); extern float __j0f (float) __attribute__ ((__nothrow__));
extern float j1f (float) __attribute__ ((__nothrow__)); extern float __j1f (float) __attribute__ ((__nothrow__));
extern float jnf (int, float) __attribute__ ((__nothrow__)); extern float __jnf (int, float) __attribute__ ((__nothrow__));
extern float y0f (float) __attribute__ ((__nothrow__)); extern float __y0f (float) __attribute__ ((__nothrow__));
extern float y1f (float) __attribute__ ((__nothrow__)); extern float __y1f (float) __attribute__ ((__nothrow__));
extern float ynf (int, float) __attribute__ ((__nothrow__)); extern float __ynf (int, float) __attribute__ ((__nothrow__));






extern float erff (float) __attribute__ ((__nothrow__)); extern float __erff (float) __attribute__ ((__nothrow__));
extern float erfcf (float) __attribute__ ((__nothrow__)); extern float __erfcf (float) __attribute__ ((__nothrow__));
extern float lgammaf (float) __attribute__ ((__nothrow__)); extern float __lgammaf (float) __attribute__ ((__nothrow__));






extern float tgammaf (float) __attribute__ ((__nothrow__)); extern float __tgammaf (float) __attribute__ ((__nothrow__));





extern float gammaf (float) __attribute__ ((__nothrow__)); extern float __gammaf (float) __attribute__ ((__nothrow__));






extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__));







extern float rintf (float __x) __attribute__ ((__nothrow__)); extern float __rintf (float __x) __attribute__ ((__nothrow__));


extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__));



extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__));



extern int ilogbf (float __x) __attribute__ ((__nothrow__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__));




extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__));



extern float nearbyintf (float __x) __attribute__ ((__nothrow__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__));



extern float roundf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern float truncf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__));






extern long int lrintf (float __x) __attribute__ ((__nothrow__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__));
extern long long int llrintf (float __x) __attribute__ ((__nothrow__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__));



extern long int lroundf (float __x) __attribute__ ((__nothrow__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__));
extern long long int llroundf (float __x) __attribute__ ((__nothrow__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__));



extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__));


extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__));


extern float fminf (float __x, float __y) __attribute__ ((__nothrow__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__));



extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));


extern int __signbitf (float __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));



extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__));








extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__));
# 95 "/usr/include/math.h" 2 3 4
# 141 "/usr/include/math.h" 3 4
# 1 "/usr/include/bits/mathcalls.h" 1 3 4
# 53 "/usr/include/bits/mathcalls.h" 3 4


extern long double acosl (long double __x) __attribute__ ((__nothrow__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__));

extern long double asinl (long double __x) __attribute__ ((__nothrow__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__));

extern long double atanl (long double __x) __attribute__ ((__nothrow__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__));

extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__));


extern long double cosl (long double __x) __attribute__ ((__nothrow__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__));

extern long double sinl (long double __x) __attribute__ ((__nothrow__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__));

extern long double tanl (long double __x) __attribute__ ((__nothrow__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__));




extern long double coshl (long double __x) __attribute__ ((__nothrow__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__));

extern long double sinhl (long double __x) __attribute__ ((__nothrow__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__));

extern long double tanhl (long double __x) __attribute__ ((__nothrow__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__));

# 87 "/usr/include/bits/mathcalls.h" 3 4


extern long double acoshl (long double __x) __attribute__ ((__nothrow__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__));

extern long double asinhl (long double __x) __attribute__ ((__nothrow__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__));

extern long double atanhl (long double __x) __attribute__ ((__nothrow__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__));







extern long double expl (long double __x) __attribute__ ((__nothrow__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__));


extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__));


extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__));


extern long double logl (long double __x) __attribute__ ((__nothrow__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__));


extern long double log10l (long double __x) __attribute__ ((__nothrow__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__));


extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__));

# 127 "/usr/include/bits/mathcalls.h" 3 4


extern long double expm1l (long double __x) __attribute__ ((__nothrow__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__));


extern long double log1pl (long double __x) __attribute__ ((__nothrow__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__));


extern long double logbl (long double __x) __attribute__ ((__nothrow__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__));






extern long double exp2l (long double __x) __attribute__ ((__nothrow__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__));


extern long double log2l (long double __x) __attribute__ ((__nothrow__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__));








extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__));


extern long double sqrtl (long double __x) __attribute__ ((__nothrow__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__));





extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__));






extern long double cbrtl (long double __x) __attribute__ ((__nothrow__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__));








extern long double ceill (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double fabsl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double floorl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__));




extern int __isinfl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int __finitel (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int isinfl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int finitel (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__));



extern long double significandl (long double __x) __attribute__ ((__nothrow__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__));





extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));






extern long double nanl (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nanl (__const char *__tagb) __attribute__ ((__nothrow__)) __attribute__ ((__const__));





extern int __isnanl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern int isnanl (long double __value) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern long double j0l (long double) __attribute__ ((__nothrow__)); extern long double __j0l (long double) __attribute__ ((__nothrow__));
extern long double j1l (long double) __attribute__ ((__nothrow__)); extern long double __j1l (long double) __attribute__ ((__nothrow__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__));
extern long double y0l (long double) __attribute__ ((__nothrow__)); extern long double __y0l (long double) __attribute__ ((__nothrow__));
extern long double y1l (long double) __attribute__ ((__nothrow__)); extern long double __y1l (long double) __attribute__ ((__nothrow__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__));






extern long double erfl (long double) __attribute__ ((__nothrow__)); extern long double __erfl (long double) __attribute__ ((__nothrow__));
extern long double erfcl (long double) __attribute__ ((__nothrow__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__));
extern long double lgammal (long double) __attribute__ ((__nothrow__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__));






extern long double tgammal (long double) __attribute__ ((__nothrow__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__));





extern long double gammal (long double) __attribute__ ((__nothrow__)); extern long double __gammal (long double) __attribute__ ((__nothrow__));






extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__));







extern long double rintl (long double __x) __attribute__ ((__nothrow__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__));


extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));

extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__));



extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__));



extern int ilogbl (long double __x) __attribute__ ((__nothrow__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__));




extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__));



extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__));



extern long double roundl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));



extern long double truncl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__));






extern long int lrintl (long double __x) __attribute__ ((__nothrow__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__));
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__));



extern long int lroundl (long double __x) __attribute__ ((__nothrow__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__));
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__));



extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__));


extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__));


extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__));



extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));


extern int __signbitl (long double __value) __attribute__ ((__nothrow__))
     __attribute__ ((__const__));



extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__));








extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__));
# 142 "/usr/include/math.h" 2 3 4
# 157 "/usr/include/math.h" 3 4
extern int signgam;
# 198 "/usr/include/math.h" 3 4
enum
  {
    FP_NAN,

    FP_INFINITE,

    FP_ZERO,

    FP_SUBNORMAL,

    FP_NORMAL

  };
# 284 "/usr/include/math.h" 3 4
typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;




extern _LIB_VERSION_TYPE _LIB_VERSION;
# 309 "/usr/include/math.h" 3 4
struct exception

  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };




extern int matherr (struct exception *__exc);
# 465 "/usr/include/math.h" 3 4

# 7 "scene.c" 2
# 1 "scene.h" 1




# 1 "tmpnrobot.h" 1
# 9 "tmpnrobot.h"
# 1 "/usr/include/sys/time.h" 1 3 4
# 27 "/usr/include/sys/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 28 "/usr/include/sys/time.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 30 "/usr/include/sys/time.h" 2 3 4
# 39 "/usr/include/sys/time.h" 3 4

# 57 "/usr/include/sys/time.h" 3 4
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

typedef struct timezone *__restrict __timezone_ptr_t;
# 73 "/usr/include/sys/time.h" 3 4
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int settimeofday (__const struct timeval *__tv,
    __const struct timezone *__tz)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int adjtime (__const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__));




enum __itimer_which
  {

    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,



    ITIMER_PROF = 2

  };



struct itimerval
  {

    struct timeval it_interval;

    struct timeval it_value;
  };






typedef int __itimer_which_t;




extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__));




extern int setitimer (__itimer_which_t __which,
        __const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__));




extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int lutimes (__const char *__file, __const struct timeval __tvp[2])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int futimes (int __fd, __const struct timeval __tvp[2]) __attribute__ ((__nothrow__));
# 191 "/usr/include/sys/time.h" 3 4

# 10 "tmpnrobot.h" 2
# 1 "/usr/include/sys/times.h" 1 3 4
# 29 "/usr/include/sys/times.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 30 "/usr/include/sys/times.h" 2 3 4





struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;

    clock_t tms_cutime;
    clock_t tms_cstime;
  };






extern clock_t times (struct tms *__buffer) __attribute__ ((__nothrow__));


# 11 "tmpnrobot.h" 2
# 1 "/usr/include/pthread.h" 1 3 4
# 25 "/usr/include/pthread.h" 3 4
# 1 "/usr/include/sched.h" 1 3 4
# 29 "/usr/include/sched.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 30 "/usr/include/sched.h" 2 3 4


# 1 "/usr/include/time.h" 1 3 4
# 33 "/usr/include/sched.h" 2 3 4


# 1 "/usr/include/bits/sched.h" 1 3 4
# 71 "/usr/include/bits/sched.h" 3 4
struct sched_param
  {
    int __sched_priority;
  };





extern int clone (int (*__fn) (void *__arg), void *__child_stack,
    int __flags, void *__arg, ...) __attribute__ ((__nothrow__));


extern int unshare (int __flags) __attribute__ ((__nothrow__));


extern int sched_getcpu (void) __attribute__ ((__nothrow__));










struct __sched_param
  {
    int __sched_priority;
  };
# 113 "/usr/include/bits/sched.h" 3 4
typedef unsigned long int __cpu_mask;






typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;
# 196 "/usr/include/bits/sched.h" 3 4


extern int __sched_cpucount (size_t __setsize, const cpu_set_t *__setp)
  __attribute__ ((__nothrow__));
extern cpu_set_t *__sched_cpualloc (size_t __count) __attribute__ ((__nothrow__)) ;
extern void __sched_cpufree (cpu_set_t *__set) __attribute__ ((__nothrow__));


# 36 "/usr/include/sched.h" 2 3 4







extern int sched_setparam (__pid_t __pid, __const struct sched_param *__param)
     __attribute__ ((__nothrow__));


extern int sched_getparam (__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__));


extern int sched_setscheduler (__pid_t __pid, int __policy,
          __const struct sched_param *__param) __attribute__ ((__nothrow__));


extern int sched_getscheduler (__pid_t __pid) __attribute__ ((__nothrow__));


extern int sched_yield (void) __attribute__ ((__nothrow__));


extern int sched_get_priority_max (int __algorithm) __attribute__ ((__nothrow__));


extern int sched_get_priority_min (int __algorithm) __attribute__ ((__nothrow__));


extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__));
# 118 "/usr/include/sched.h" 3 4

# 26 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4








# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
# 131 "/usr/include/time.h" 3 4


struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  __const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;
# 180 "/usr/include/time.h" 3 4



extern clock_t clock (void) __attribute__ ((__nothrow__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));

# 217 "/usr/include/time.h" 3 4
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     __const char *__restrict __format,
     __const struct tm *__restrict __tp,
     __locale_t __loc) __attribute__ ((__nothrow__));
# 230 "/usr/include/time.h" 3 4



extern struct tm *gmtime (__const time_t *__timer) __attribute__ ((__nothrow__));



extern struct tm *localtime (__const time_t *__timer) __attribute__ ((__nothrow__));





extern struct tm *gmtime_r (__const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__));



extern struct tm *localtime_r (__const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__));





extern char *asctime (__const struct tm *__tp) __attribute__ ((__nothrow__));


extern char *ctime (__const time_t *__timer) __attribute__ ((__nothrow__));







extern char *asctime_r (__const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__));


extern char *ctime_r (__const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__));




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) __attribute__ ((__nothrow__));



extern int daylight;
extern long int timezone;





extern int stime (__const time_t *__when) __attribute__ ((__nothrow__));
# 313 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));


extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));


extern int dysize (int __year) __attribute__ ((__nothrow__)) __attribute__ ((__const__));
# 328 "/usr/include/time.h" 3 4
extern int nanosleep (__const struct timespec *__requested_time,
        struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__));


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__));


extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     __attribute__ ((__nothrow__));






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       __const struct timespec *__req,
       struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__));




extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__));


extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__));


extern int timer_settime (timer_t __timerid, int __flags,
     __const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__));


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__));


extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__));
# 417 "/usr/include/time.h" 3 4

# 27 "/usr/include/pthread.h" 2 3 4


# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 34 "/usr/include/signal.h" 2 3 4
# 408 "/usr/include/signal.h" 3 4

# 30 "/usr/include/pthread.h" 2 3 4

# 1 "/usr/include/bits/setjmp.h" 1 3 4
# 27 "/usr/include/bits/setjmp.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 28 "/usr/include/bits/setjmp.h" 2 3 4






typedef int __jmp_buf[6];
# 32 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 33 "/usr/include/pthread.h" 2 3 4



enum
{
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};



enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
# 63 "/usr/include/pthread.h" 3 4
};




enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
# 117 "/usr/include/pthread.h" 3 4
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
# 149 "/usr/include/pthread.h" 3 4
enum
{
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};



enum
{
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};



enum
{
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};
# 184 "/usr/include/pthread.h" 3 4
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};


enum
{
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum
{
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};
# 222 "/usr/include/pthread.h" 3 4





extern int pthread_create (pthread_t *__restrict __newthread,
      __const pthread_attr_t *__restrict __attr,
      void *(*__start_routine) (void *),
      void *__restrict __arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));





extern void pthread_exit (void *__retval) __attribute__ ((__noreturn__));







extern int pthread_join (pthread_t __th, void **__thread_return);
# 265 "/usr/include/pthread.h" 3 4
extern int pthread_detach (pthread_t __th) __attribute__ ((__nothrow__));



extern pthread_t pthread_self (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern int pthread_equal (pthread_t __thread1, pthread_t __thread2) __attribute__ ((__nothrow__));







extern int pthread_attr_init (pthread_attr_t *__attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_destroy (pthread_attr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getdetachstate (__const pthread_attr_t *__attr,
     int *__detachstate)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
     int __detachstate)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getguardsize (__const pthread_attr_t *__attr,
          size_t *__guardsize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
          size_t __guardsize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getschedparam (__const pthread_attr_t *__restrict
           __attr,
           struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
           __const struct sched_param *__restrict
           __param) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_getschedpolicy (__const pthread_attr_t *__restrict
     __attr, int *__restrict __policy)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getinheritsched (__const pthread_attr_t *__restrict
      __attr, int *__restrict __inherit)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
      int __inherit)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getscope (__const pthread_attr_t *__restrict __attr,
      int *__restrict __scope)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_attr_getstackaddr (__const pthread_attr_t *__restrict
          __attr, void **__restrict __stackaddr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));





extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
          void *__stackaddr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));


extern int pthread_attr_getstacksize (__const pthread_attr_t *__restrict
          __attr, size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
          size_t __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_attr_getstack (__const pthread_attr_t *__restrict __attr,
      void **__restrict __stackaddr,
      size_t *__restrict __stacksize)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3)));




extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
      size_t __stacksize) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 415 "/usr/include/pthread.h" 3 4
extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
      __const struct sched_param *__param)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));


extern int pthread_getschedparam (pthread_t __target_thread,
      int *__restrict __policy,
      struct sched_param *__restrict __param)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));


extern int pthread_setschedprio (pthread_t __target_thread, int __prio)
     __attribute__ ((__nothrow__));
# 468 "/usr/include/pthread.h" 3 4
extern int pthread_once (pthread_once_t *__once_control,
    void (*__init_routine) (void)) __attribute__ ((__nonnull__ (1, 2)));
# 480 "/usr/include/pthread.h" 3 4
extern int pthread_setcancelstate (int __state, int *__oldstate);



extern int pthread_setcanceltype (int __type, int *__oldtype);


extern int pthread_cancel (pthread_t __th);




extern void pthread_testcancel (void);




typedef struct
{
  struct
  {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
  } __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
# 514 "/usr/include/pthread.h" 3 4
struct __pthread_cleanup_frame
{
  void (*__cancel_routine) (void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
};
# 654 "/usr/include/pthread.h" 3 4
extern void __pthread_register_cancel (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__regparm__ (1)));
# 666 "/usr/include/pthread.h" 3 4
extern void __pthread_unregister_cancel (__pthread_unwind_buf_t *__buf)
  __attribute__ ((__regparm__ (1)));
# 707 "/usr/include/pthread.h" 3 4
extern void __pthread_unwind_next (__pthread_unwind_buf_t *__buf)
     __attribute__ ((__regparm__ (1))) __attribute__ ((__noreturn__))

     __attribute__ ((__weak__))

     ;



struct __jmp_buf_tag;
extern int __sigsetjmp (struct __jmp_buf_tag *__env, int __savemask) __attribute__ ((__nothrow__));





extern int pthread_mutex_init (pthread_mutex_t *__mutex,
          __const pthread_mutexattr_t *__mutexattr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_destroy (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_trylock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutex_lock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
                                    __const struct timespec *__restrict
                                    __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_mutex_unlock (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 769 "/usr/include/pthread.h" 3 4
extern int pthread_mutex_consistent_np (pthread_mutex_t *__mutex)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 782 "/usr/include/pthread.h" 3 4
extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_mutexattr_getpshared (__const pthread_mutexattr_t *
      __restrict __attr,
      int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
      int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 838 "/usr/include/pthread.h" 3 4
extern int pthread_mutexattr_getrobust (__const pthread_mutexattr_t *__attr,
     int *__robustness)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));







extern int pthread_mutexattr_setrobust (pthread_mutexattr_t *__attr,
     int __robustness)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 864 "/usr/include/pthread.h" 3 4
extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
    __const pthread_rwlockattr_t *__restrict
    __attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
           __const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
           __const struct timespec *__restrict
           __abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getpshared (__const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
       int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_rwlockattr_getkind_np (__const pthread_rwlockattr_t *
       __restrict __attr,
       int *__restrict __pref)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
       int __pref) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));







extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
         __const pthread_condattr_t *__restrict
         __cond_attr) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_destroy (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_signal (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_cond_broadcast (pthread_cond_t *__cond)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
         pthread_mutex_t *__restrict __mutex)
     __attribute__ ((__nonnull__ (1, 2)));
# 976 "/usr/include/pthread.h" 3 4
extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
       pthread_mutex_t *__restrict __mutex,
       __const struct timespec *__restrict
       __abstime) __attribute__ ((__nonnull__ (1, 2, 3)));




extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_condattr_getpshared (__const pthread_condattr_t *
                                        __restrict __attr,
                                        int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
                                        int __pshared) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_condattr_getclock (__const pthread_condattr_t *
          __restrict __attr,
          __clockid_t *__restrict __clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
          __clockid_t __clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 1020 "/usr/include/pthread.h" 3 4
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_destroy (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_lock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_trylock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_spin_unlock (pthread_spinlock_t *__lock)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
     __const pthread_barrierattr_t *__restrict
     __attr, unsigned int __count)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_destroy (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrier_wait (pthread_barrier_t *__barrier)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_barrierattr_getpshared (__const pthread_barrierattr_t *
        __restrict __attr,
        int *__restrict __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
                                           int __pshared)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 1087 "/usr/include/pthread.h" 3 4
extern int pthread_key_create (pthread_key_t *__key,
          void (*__destr_function) (void *))
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern int pthread_key_delete (pthread_key_t __key) __attribute__ ((__nothrow__));


extern void *pthread_getspecific (pthread_key_t __key) __attribute__ ((__nothrow__));


extern int pthread_setspecific (pthread_key_t __key,
    __const void *__pointer) __attribute__ ((__nothrow__)) ;




extern int pthread_getcpuclockid (pthread_t __thread_id,
      __clockid_t *__clock_id)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
# 1121 "/usr/include/pthread.h" 3 4
extern int pthread_atfork (void (*__prepare) (void),
      void (*__parent) (void),
      void (*__child) (void)) __attribute__ ((__nothrow__));
# 1135 "/usr/include/pthread.h" 3 4

# 12 "tmpnrobot.h" 2
# 183 "tmpnrobot.h"
enum tcpName{caseGripper
            ,bagGripper
            ,zeroGripper};
# 496 "tmpnrobot.h"
typedef struct comskConnect
{
 int fixdec;
 float factor;
 float fdata;
 int major;
 int minor;
 short* data;
 char key[256];
 char comment[256];
} comskConnect;

typedef struct comskstruct
{
  char module_name[256];
 int address;
  int numOfInitWords;
  int numOfInWords;
  int numOfOutWords;
 comskConnect initdata[40];
  comskConnect idata[10];
  comskConnect odata[10];
} comskstruct;

typedef struct tmpnComSK
{
  int sfd;
  int simulate;
 int type;
  char ipaddr[256];
  int numOfModules;
  comskstruct *iotab;
 int highadr;
 int lowadr;
 int adrcount;
 short oarray[10*10];
} tmpnComSK;

typedef struct tmpnComSKs
{
  char name[256];
  int maxidx;
  tmpnComSK comsk[5];
} tmpnComSKs;
# 557 "tmpnrobot.h"
typedef struct macConnect
{
 int type;
 float factor;
 int reg;
 int bitmode;
 void *bitparent;
 int data;
 float fdata;
 int userchange;
 char key[256];
 char comment[256];
} macConnect;

typedef struct macstruct
{
  char module_name[256];
 int address;
  int numOfInitWords;
  int numOfInWords;
  int numOfOutWords;
 macConnect initdata[50];
  macConnect idata[100];
  macConnect odata[50];
} macstruct;

typedef struct tmpnMac
{
 char filename[256];
  int sfd;
  int simulate;
  char ipaddr[256];
 int port;
  int numOfMotors;
  macstruct *iotab;
} tmpnMac;

typedef struct tmpnMacs
{
  char name[256];
  int maxidx;
  tmpnMac mac[4];
} tmpnMacs;


typedef struct loadcellConnect
{
 float factor;
 float fdata;
 int ignoreError;
 char key[256];
 char comment[256];
} loadcellConnect;

typedef struct tmpnLoadCell
{
  int sfd;
  int simulate;
  char ipaddr[256];
 int port;
 int fastmoxa;
  int numOfModules;
  loadcellConnect iotab[8];
} tmpnLoadCell;

typedef struct tmpnLoadCells
{
  char name[256];
  int maxidx;
  tmpnLoadCell loadcell[3];
} tmpnLoadCells;
# 644 "tmpnrobot.h"
typedef struct tmpnConnect
{
  int connectType;
  int wordidx;
  int bitidx;
  int shift;
  unsigned short mask;
  union
  {
    short *sdata;
    unsigned short *udata;
  };
  char name[256];
  char key[256];
  char text[256];
} tmpnConnect;

typedef struct stbstruct
{
  int type;
  char typeStr[256];
  char module_name[256];
  int maxidx;
  int numOfInWords;
  int numOfOutWords;
  tmpnConnect connect[30];
  unsigned short *idata;
  unsigned short *odata;
} stbstruct;

typedef struct tmpnDIO
{
  int sfd;
  volatile int cleardioerror;
  int simulate;
  char ipaddr[256];
  int numOfModules;
  stbstruct *iotab;
  int numOfInWords;
  unsigned short idata[1000];
  int numOfOutWords;
  unsigned short odata[1000];
} tmpnDIO;

typedef struct tmpnDIOs
{
  char name[256];
  int maxidx;
  tmpnDIO dio[5];
} tmpnDIOs;

typedef struct MPN_SUMMARY {
  float wdog;
  float emergency;
  float state;
  float mtypet;
  float mtypef;
  float axist;
  float axisa;
  float axisb;
  float axisc;
  float axisd;
  float axise;
  float axisf;
  float fea;
  float feb;
  float fec;
  float fed;
  float fee;
  float fef;
} MPN_SUMMARY;



typedef struct tmpnICPConnect
{
 int bitpos;
  char key[256];
 unsigned int *udata;
} tmpnICPConnect;

typedef struct icpconstruct
{
  int type;
  char typeStr[256];
  char module_name[256];
 int address;
 int dosetup;
  int numOfInBits;
  int numOfOutBits;
  tmpnICPConnect inconnect[16];
 tmpnICPConnect outconnect[16];
  unsigned int idata;
  unsigned int odata;
} icpconstruct;

typedef struct tmpnICPcon
{
  int sfd;
  int simulate;
  char ipaddr[256];
 int port;
  int numOfModules;
  icpconstruct *iotab;
} tmpnICPcon;

typedef struct tmpnICPcons
{
  int maxidx;
  tmpnICPcon icpcon[5];
} tmpnICPcons;

typedef struct AXIS_PARAMETER {
  float atype;
  float p_gain;
  float i_gain;
  float d_gain;
  float ov_gain;
  float vff_gain;
  float units;
  float speed;
  float accel;
  float decel;
  float creep;
  float jogspeed;
  float felimit;
  float dac;
  float servo;
  float redispt;
  float fwd_in;
  float rev_in;
  float dat_in;
  float fh_in;
  float fslimit;
  float rslimit;
  float mtype;
  float ntype;
  float mpos;
  float dpos;
  float fe;
  float axisstatus;
  float vpspeed;
} AXIS_PARAMETER;

typedef struct SCOPECMD
{
  float rtn;
  float arg[20];
  float cmd_nr;
  float type;
  float length;
  float numofsamples;
  float scale[6];
  float buffer[20];
} SCOPECMD;

typedef struct CONTROLLERCMD
{
  float rtn;
  float arg[10];
  float cmd_nr;
} CONTROLLERCMD;

typedef struct MPNCMD
{
  float rtn;
  float arg[10];
  float cmd_nr;
} MPNCMD;

typedef struct AXIS_NAME
{
  AXIS_PARAMETER t,a,b,c,d,e,f;
} AXIS_NAME;

typedef union AXIS_UNION
{
  AXIS_NAME name;
  AXIS_PARAMETER array[7];
} AXIS_UNION;

typedef struct TABLESPACE
{
  AXIS_UNION axis;
  SCOPECMD scope;
  CONTROLLERCMD ctrl_cmd;
  MPNCMD mpn_cmd;
  MPN_SUMMARY summary;
  float mpn_trio_basic_error;
  float mpn_trio_basic_line_error;
  float mpn_cancel;
  float mpn_running;
  float mpn_state;
  float num_of_path_index;
  float path_index[100];
} TABLESPACE;







typedef struct tmpnVectorXYZ
{
  float x,y,z;
} tmpnVectorXYZ;

typedef struct tmpnColor
{
 float r,g,b;
} tmpnColor;



typedef struct tmpnMaterial
{
  float diffuse[4];
  float ambient[4];
  float specular[4];
  float shininess;
} tmpnMaterial;
typedef struct tmpnBone
{
  long id;
  char name[80];
  tmpnVectorXYZ rot;
  tmpnVectorXYZ trans;
  tmpnVectorXYZ dim;
  tmpnColor color;
  tmpnMaterial material;
  int gllist;
  int cyl;
} tmpnBone;

typedef struct tmpnScene
{
  int coord;

  tmpnBone floor;
  tmpnBone foot,leg;
  tmpnBone gantry,shoulder;
  tmpnBone upperArm,lowerArm,lowerArm2,wrist,flange;
  tmpnBone gearA,gearB,gearC,gearD,gearE;


  tmpnBone tool;

  struct
  {
    int maxidx;
    tmpnBone accessory[10];
  } accessories;




  tmpnBone pallet;

  tmpnBone key;

  int boxpicked;
  int palletAboxPlaced[10][4];
  int palletCboxPlaced[10][4];
} tmpnScene;


typedef struct tmpnVector
{
  float x,y,z,v,w,u;
} tmpnVector;

typedef struct tmpnDualVector
{
  float x,y,z,v,w,u;
  int absx,absy,absz,absv,absw,absu;
} tmpnDualVector;

typedef struct tmpnFrame
{

  char name[256];
  float x,y,z,v,w,u;
} tmpnFrame;

typedef struct tmpnFrames
{
  int maxidx;
  tmpnFrame frame[30];
} tmpnFrames;

typedef struct tmpnTimingItem
{
  char name[256];
  float value;
} tmpnTimingItem;

typedef struct tmpnTiming
{
  int maxidx;
  tmpnTimingItem item[50];
} tmpnTiming;

typedef struct tmpnMacro
{
  char name[256];
  int idx;
} tmpnMacro;

typedef struct tmpnJoints
{
  float a,b,c,d,e,f;
} tmpnJoints;

typedef union tmpnJointsUnion
{
  tmpnJoints name;
  float array[6];
} tmpnJointsUnion;





typedef struct tmpnBoptParamStruct
{
# 979 "tmpnrobot.h"
 int numofparams;
 char table[16];
 float value;
 int ABS;
} tmpnBoptParamStruct;

typedef struct tmpnBoptViaVector
{
 tmpnBoptParamStruct x[16];
 tmpnBoptParamStruct y[16];
 tmpnBoptParamStruct z[16];
 tmpnBoptParamStruct v[16];
 tmpnBoptParamStruct w[16];
} tmpnBoptViaVector;

typedef struct tmpnBoptMacroItem
{
# 1009 "tmpnrobot.h"
 int integer[2];
 float floating[6];
} tmpnBoptMacroItem;

typedef struct tmpnBoptParamItem
{
# 1028 "tmpnrobot.h"
 int integer[2];
 float floating[6];
} tmpnBoptParamItem;

typedef struct tmpnBoptCoeffItem
{
 char pathName[256];
 int mode;
 int pathtype;
 int viatype;
  struct
  {
    char fromFrame[256];
    char toFrame[256];
    char fromItem[256];
    char toItem[256];
    char fromPattern[256];
    char toPattern[256];
  } def;
 tmpnBoptViaVector viapos[2];
 tmpnBoptViaVector viavel[2];
  tmpnBoptMacroItem macro[2];
 float mv[5];
 float ma[5];
 tmpnBoptParamItem params;
} tmpnBoptCoeffItem;

typedef struct tmpnBoptCoeff
{
  char name[128];
 char filename[256];
 int maxidx;
 tmpnBoptCoeffItem item[40];
} tmpnBoptCoeff;





typedef struct tmpnItem
{
  char type[256];
  char name[256];
  char filename[256];
  tmpnVectorXYZ dim;
  float sy;
  float gy;
  float my;
  float gx;
  float weight;
  int user;
} tmpnItem;

typedef struct tmpnPatternItem
{
  int layer;
  tmpnFrame wcp;
} tmpnPatternItem;

typedef struct tmpnPattern
{
  char name[256];
  char filename[256];
  int maxidx;
  float width;
  float length;
  tmpnPatternItem item[200];
} tmpnPattern;





typedef struct tmpnCPPatternItem
{
  int layer;
  int maxpush;
  int gettime;
  int *ppps;
  int *paccs;
  int *pspeeds;
} tmpnCPPatternItem;

typedef struct tmpnCPPattern
{
  char name[256];
  char filename[256];
  int user;
  int selectedItem;
  int selectedPPP;
  int maxidx;
  tmpnCPPatternItem *items;
} tmpnCPPattern;




typedef struct tmpnKeyPoint
{
  int tcpidx;
  int statehint;
  float positionhint;
  float x,y,z,v,w,u;
  float dt;
  float t;
  float sp;
} tmpnKeyPoint;

typedef struct tmpnHPoint
{
  int i;
  int time;
  float x,y,z,v,w,u;
  float dt;
  int tcpidx;
  int keypointidx;
} tmpnHPoint;

typedef struct tmpnPosHint
{
  int positionhint;
  int i;
  int time;
} tmpnPosHint;

typedef struct tmpnPosition {
   tmpnVector taskSpace;
   tmpnJointsUnion jointSpace;
   tmpnJointsUnion actuatorSpace;

   tmpnKeyPoint *keypoint;
   int tcpidx;
   int statehint;
   float positionhint;
   tmpnJointsUnion dif;
   tmpnJointsUnion speed;
   tmpnJointsUnion rev;
   tmpnJointsUnion pctRatedSpeed;
   tmpnJointsUnion posRad;
   tmpnJointsUnion speedRad;
   tmpnJointsUnion accelRad;
   tmpnJointsUnion jerkRad ;
   tmpnJointsUnion force;
   tmpnJointsUnion scope;
   int maxrev;
   float dt;
   float t;
   float sp;
} tmpnPosition;

typedef struct tmpnPathDef
{
  char name[256];
  int id;
  volatile int seqnum;
  volatile int idx;
  int maxidx;
  int numofsamples;
  int samplesBetweenKeypoints;
  int pathtype;
  int runbopt;
  int spline;
  int loadgroup;
  int splineorder;
  float maxTime;
  float maxSpeed;
  tmpnKeyPoint keypoint[500];
  int maxhidx;
  tmpnHPoint hpoint[20];
  int maxpidx;
  tmpnPosHint poshint[20];
} tmpnPathDef;

typedef struct tmpnPath
{
  int maxidx;
  tmpnPosition position[5000];
} tmpnPath;


typedef struct bufferstruct
{
  tmpnPathDef *tpathdef;
  tmpnPath pathdata;
} bufferstruct;
# 1228 "tmpnrobot.h"
typedef struct tmpnPathKeyFrame
{
  tmpnFrame frame;
  int cItem;
  int cLayer;
  char itemName[256];
  tmpnItem *item;
  char patternName[256];
  tmpnPattern *pattern;
} tmpnPathKeyFrame;

typedef struct tmpnPathKey
{
  int mode;
  int type;
 tmpnBoptCoeffItem* boptcoeff;
  tmpnPathKeyFrame from;
  tmpnPathKeyFrame to;
} tmpnPathKey;

typedef struct tmpnPathHandle
{
  tmpnPathKey key;
  int state;

  char script[256];
  struct COMMANDSTRUCT *firstpoint;
} tmpnPathHandle;

typedef struct tmpnPathItem
{
  tmpnPathHandle handle;
  tmpnPathDef pathdef;
  int bopted;
  tmpnPathHandle *path;
} tmpnPathItem;


typedef struct tmpnPathTable
{
  int maxidx;
  int newidx;
  tmpnPathItem item[500];
  int currentidx;
  tmpnPath pathdata;
} tmpnPathTable;

typedef struct tmpnScopeItem
{
  tmpnJointsUnion force;
} tmpnScopeItem;

typedef struct tmpnScope
{
  int maxidx;
  tmpnScopeItem *sample;
} tmpnScope;
typedef struct tmpnAccessory
{
  char name[256];
  tmpnVectorXYZ dimention;
  tmpnVectorXYZ transformation;
  tmpnMaterial material;
} tmpnAccessory;





typedef struct tmpnRemoteHost
{
  char name[128];
  int port;
  int sockfd;
  int alive;
  int repeat;
  int sndbuf_idx;
  char sndbuf[2048];
} tmpnRemoteHost;

typedef struct tmpnRemoteStateMachine
{
  tmpnRemoteHost *remotehost;
  char name[128];
  char state[128];
  char safe[128];
 pthread_mutex_t remotelock;
} tmpnRemoteStateMachine;

typedef struct tmpnRemoteValue
{
  tmpnRemoteHost *remotehost;
  char name[128];
  char link[128];
 int subtype;
 int data;
 float fdata;
} tmpnRemoteValue;

typedef struct tmpnMachineType
{
  int idx;
  char name[256];
} tmpnMachineType;

typedef struct tmpnStateName
{
  int idx;
  char name[256];
} tmpnStateName;

typedef struct tmpnStateMachineIO
{
  char name[256];
  int iotype;


 union {
  tmpnConnect *connect;
  comskConnect *comskconnect;
  loadcellConnect *loadcellconnect;
  macConnect *macconnect;
  tmpnICPConnect *icpconnect;
 };
} tmpnStateMachineIO;

typedef struct STMCOMMANDSTRUCT
{
  int type;
  void *data;
  int level;
} STMCOMMANDSTRUCT;

typedef struct tmpnStateMachineState
{
  char name[256];
  int statenum;
  int maxprgidx;
  STMCOMMANDSTRUCT *prg;
} tmpnStateMachineState;

typedef struct tmpnStateMachineTimeout
{
  char name[256];
  int timeout;
} tmpnStateMachineTimeout;

typedef struct tmpnStateMachineTable
{
  int maxsize;
  int filter;
  int newtablesize;
  int curtablesize;
  int sum;
  int sumcnt;
  int maxidx;
  int min;
  int max;
  int *item;
  int topsearchwidth;
  int topidx;
  float fsum;
  float fmin;
  float fmax;
  float *fitem;
  float topval;
} tmpnStateMachineTable;

typedef struct tmpnStateMachineValue
{
  char name[256];
  int type;
  int subtype;
  int data;
  float fdata;
  char linkname[256];
  char link[256];

  tmpnStateMachineTable *table;
  tmpnPathHandle *path;
  tmpnFrame *frame;
  tmpnItem *item;
  tmpnPattern *pattern;
  tmpnCPPattern *cppattern;
  struct tmpnStateMachineValue *linkvalue;
 tmpnRemoteValue *remote;
} tmpnStateMachineValue;

typedef struct tmpnStateMachineLink
{
  int stmidx;
  char localname[256];
  char name[256];
} tmpnStateMachineLink;

typedef struct tmpnStateMachine
{
  int version;
  int type;
  char filename[256];
  char name[256];


  int mcSignal;

  int delaystop;
  struct timeval stoptimer;

  volatile int istate;
  int next_istate;
  int new_istate;
  volatile int stop;
  pthread_cond_t change;
  pthread_mutex_t change_mtx;
  struct timeval timer;
 int timerstate;
 tmpnStateMachineValue *debugvalue;
  int numstate;
  tmpnStateMachineState *state;
 int numvalue;
  tmpnStateMachineValue *value;
  int numtimeout;
  tmpnStateMachineTimeout *timeout;
  int numinput;
  tmpnStateMachineIO *input;
  int numoutput;
  tmpnStateMachineIO *output;
  int numlink;
  tmpnStateMachineLink *link;
} tmpnStateMachine;




typedef struct tmpnUdpQuestionStruct
{
 float freq;
 char questionformat[256];
 char responseformat[256];
 int maxresponseval;
 tmpnStateMachineValue *responseval[10];
} tmpnUdpQuestionStruct;

typedef struct tmpnUdpAgentStruct
{
 int type;
 int simulate;
 char ipaddr[256];
  int port;
  int sockfd;
  int sndbuf_idx;
  char sndbuf[2048];
 int maxqlines;
 tmpnUdpQuestionStruct qlines[32];
} tmpnUdpAgentStruct;

typedef struct tmpnUdpAgents
{
  int servers_maxidx;
 int clients_maxidx;
  tmpnUdpAgentStruct *server;
  tmpnUdpAgentStruct *client;
} tmpnUdpAgents;




typedef struct tmpnPPScriptItem
{
  char cmd[256];
  char item[256];
  char from[256];
  char to[256];
  int layer;
  int idx;
  tmpnVector wcp;
} tmpnPPScriptItem;

typedef struct tmpnCoeff
{
  char name[256];
  float value;
} tmpnCoeff;

typedef struct tmpnPPScript
{
  char name[256];
  int type;

  int maxidx;
  int itemsPrLayer;
  int layers;
  tmpnPPScriptItem item[200];
} tmpnPPScript;

typedef struct tmpnRSSystem
{
  char plant[256];
  char workcell[256];
  char location[256];
  char robot[256];
  char pcIPaddr[256];
  char mcIPaddr[256];
  char nic[256];
  char script[256];
  int workcellid;
  int lag;
  struct
  {
    int initialized;
    int offx;
    int offy;
    float calx;
    float caly;
    int ctrltype;
    char port[256];
  } touch;
  char scriptname[256];
  int simulateMC;
  int mc_task_debug;
  int path_debug;
  int statemachine_debug;
 int io_debug;
  int startSpeed;
  char user[256];
  char password[256];
  int checkWeigher;
  int roboStacker;
  char mainDialog[256];
  int scriptExec;
  int new_trio_addr;
  int stmServerPort;
  int mc_version;
} tmpnRSSystem;



typedef struct tmpnTCP
{
  char name[256];
  float x,y,z,v,w,u;
} tmpnTCP;

typedef struct tmpnTool
{
  char name[256];
  tmpnVectorXYZ dim;
  float weight;
 int itemsperlift;



} tmpnTool;


typedef struct tmpnServoAxis {
} tmpnServoAxis;

typedef struct tmpnLink
{
  float length;
  float mass;
  float massDisplacement[3];
  float inertia[3][3];
} tmpnLink;

typedef struct tmpnStateTekst
{
  int idx;
  char tekst[256];
} tmpnStateTekst;

typedef struct tmpnStateTeksts
{
  char name[256];
  int maxidx;
  tmpnStateTekst item[1000];
} tmpnStateTeksts;

typedef struct tmpnStateTekstList
{
 int numofStateTeksts;
  tmpnStateTeksts stateteksts[6];
 int currentStateTekst;
} tmpnStateTekstList;

typedef struct tmpnLanguageLine
{
  int key;
  char tekst[256];
 char english[256];
} tmpnLanguageLine;

typedef struct tmpnLanguage
{
  char name[256];
  int maxidx;
  tmpnLanguageLine item[1000];
} tmpnLanguage;

typedef struct tmpnLanguages
{
 int numoflanguages;
  tmpnLanguage language[6];
 int currentLanguage;
} tmpnLanguages;

typedef struct tmpnScript
{
  char name[256];
} tmpnScript;

typedef struct tmpnScripts
{
  int maxidx;
  tmpnScript item[10];
} tmpnScripts;

typedef struct COMMANDSTRUCT {
  int type;
  void *data;
  struct COMMANDSTRUCT *next;
  struct COMMANDSTRUCT *prev;
  int flag;
  void *listitem;
  int include;
} COMMANDSTRUCT;

typedef struct tmpnRobot
{
  char m_name[256];
  float m_gantryLength;
  float m_legHeight;
  float m_shoulderGearB;
  tmpnLink m_Link[5];
  tmpnLink m_State[3];
  tmpnJointsUnion m_sign;
  tmpnJointsUnion m_ratedRpmGear;
  tmpnJointsUnion m_ratedNmGear;
  tmpnJointsUnion m_ratedRPM;
  tmpnJointsUnion m_ratedNm;
  tmpnJointsUnion m_maxForceNm;
  tmpnJointsUnion m_pulses;
  tmpnJointsUnion m_gearing;
  tmpnJointsUnion m_unit;

  tmpnJointsUnion m_units;
  tmpnJointsUnion m_p_gain;
  tmpnJointsUnion m_i_gain;
  tmpnJointsUnion m_d_gain;
  tmpnJointsUnion m_ov_gain;
  tmpnJointsUnion m_vff_gain;
  tmpnJointsUnion m_speed;
  tmpnJointsUnion m_accel;
  tmpnJointsUnion m_decel;
  tmpnJointsUnion m_creep;
  tmpnJointsUnion m_jogspeed;
  tmpnJointsUnion m_felimit;

  tmpnJointsUnion m_Trms;
  tmpnJointsUnion m_lifeTimeGear;

  tmpnVector m_min;
  tmpnVector m_max;

  tmpnVector m_worldPoint;

  tmpnVector m_localTrans;

  tmpnJoints m_jointCalib;

  tmpnJoints m_mpnhome;

  int m_state;
  int m_tcpidx;
  tmpnTCP m_tcp[3];

  tmpnJoints m_actuator;
  tmpnJoints m_joint;
  tmpnJointsUnion m_staticForce;

  tmpnFrames m_frames;
  int m_showPoint;
  int m_snapToGrid;
  int m_simulateTRIO;


  int splinehint;
  int splineorder;
  tmpnTiming timing;

} tmpnRobot;

typedef struct tmpnRobots
{
  int maxidx;
  tmpnRobot robot[1];
} tmpnRobots;

typedef struct tmpnPatterns
{
  int maxidx;
  tmpnPattern pattern[12];
} tmpnPatterns;

typedef struct tmpnCPPatterns
{
  int maxidx;
  tmpnCPPattern *cppattern;
} tmpnCPPatterns;

typedef struct tmpnItems
{
  int maxidx;
  tmpnItem item[10];
} tmpnItems;

typedef struct tmpnTools
{
  int maxidx;
  tmpnTool tool[3];
} tmpnTools;

typedef struct tmpnAccessories
{
  int maxidx;
  tmpnAccessory accessory[10];
} tmpnAccessories;

typedef struct tmpnPPScripts
{
  int maxidx;
  tmpnPPScript ppscript[10];
} tmpnPPScripts;

typedef struct tmpnStateMachines
{
  int maxidx;
  tmpnStateMachine *statemachine;
} tmpnStateMachines;

typedef struct tmpnRemoteStateMachines
{
  int maxidx;
  tmpnRemoteStateMachine remotestatemachine[100];
} tmpnRemoteStateMachines;

typedef struct tmpnRemoteValues
{
  int maxidx;
  tmpnRemoteValue remotevalue[100];
} tmpnRemoteValues;

typedef struct tmpnRemoteHosts
{
  int maxidx;
  tmpnRemoteHost remotehost[5];
} tmpnRemoteHosts;

typedef struct tmpnWorkcell
{
  char name[256];
 char filename[256];
 tmpnLanguages languages;
  tmpnRobots robots;
  tmpnPatterns patterns;
  tmpnCPPatterns cppatterns;
  tmpnTools tools;
  tmpnItems items;
  tmpnAccessories accessories;
  tmpnPPScripts ppscripts;
 tmpnBoptCoeff boptcoeff;
  tmpnStateMachines statemachines;
  tmpnRemoteStateMachines remotestatemachines;
  tmpnRemoteValues remotevalues;
  tmpnRemoteHosts remotehosts;
 tmpnUdpAgents udpagents;
  tmpnDIOs dios;
 tmpnComSKs comsks;
 tmpnLoadCells loadcells;
 tmpnMacs macs;
 tmpnICPcons icpcons;
  tmpnScripts scripts;
  tmpnStateTekstList statetekstlist;


  volatile COMMANDSTRUCT *m_root;






} tmpnWorkcell;

typedef struct tmpnWorkcells
{
  int maxidx;
  tmpnWorkcell workcell[2];
} tmpnWorkcells;

typedef struct tmpnPlant
{
  char name[256];
  tmpnWorkcells workcells;
} tmpnPlant;



typedef struct SPLINEHINTSTRUCT {
  int splinehint;
  int splineorder;
} SPLINEHINTSTRUCT;

typedef struct RESETPRELOADSTRUCT {
  int loadgroup;
} RESETPRELOADSTRUCT;

typedef struct ROOTSTRUCT {
  int dummy;
} ROOTSTRUCT;

typedef struct STATEHINTSTRUCT {
  int statehint;
} STATEHINTSTRUCT;

typedef struct POSITIONHINTSTRUCT {
  int positionhint;
} POSITIONHINTSTRUCT;

typedef struct SADSSTRUCT {
  float speed;
  float accel;
  float decel;
  int sramp;
} SADSSTRUCT;

typedef struct MOVEABSSTRUCT {
  float dest_a;
  float dest_b;
  float dest_c;
  float dest_d;
  float dest_e;
  float dest_f;
} MOVEABSSTRUCT;

typedef struct MOVEAXISSTRUCT {
  int axis;
  float speed;
  float accel;
  float decel;
  float distance;
  int wait;
} MOVEAXISSTRUCT;

typedef struct CANCELAXISSTRUCT {
  int axis;
  int wait;
} CANCELAXISSTRUCT;

typedef struct WSPSTRUCT {
  float x;
  float y;
  float z;
  float v;
  float w;
  float u;
} WSPSTRUCT;

extern WSPSTRUCT CalOffset;

typedef struct OUTPUTSTRUCT {
  int p;
  int state;
} OUTPUTSTRUCT;

typedef struct INPUTSTRUCT {
  int p;
} INPUTSTRUCT;

typedef struct EVENTSTRUCT {
  int type;
  char machineName[256];
  char stateName[256];
  char machine;
  char state;
} EVENTSTRUCT;

typedef struct COUNTERSTRUCT {
  char function[256];
  char name[256];
  char value[256];
} COUNTERSTRUCT;

typedef struct ERRORSTRUCT {
  int number;
  char text[256];
} ERRORSTRUCT;

typedef struct TUNINGSTRUCT {
  char name[256];
  int vr;
  float value;
} TUNINGSTRUCT;

typedef struct SETSPEEDSTRUCT {
  float factor;
} SETSPEEDSTRUCT;

typedef struct MACROSTRUCT {
  char name[256];
  int idx;
  int parameter0;
  int parameter1;
  int parameter2;
} MACROSTRUCT;

typedef struct CALLSTRUCT {
  char script[256];
  int lag;
} CALLSTRUCT;

typedef struct GOTOSTRUCT {
  char label[256];
} GOTOSTRUCT;

typedef struct LABELSTRUCT {
  char label[256];
} LABELSTRUCT;

typedef struct SLEEPSTRUCT {
  int ms;
} SLEEPSTRUCT;

typedef struct JUMPLAYERSTRUCT {
  char function[256];
  int layer;
} JUMPLAYERSTRUCT;

typedef struct SCOPESTRUCT {
  int parameter0;
  int parameter1;
  int parameter2;
} SCOPESTRUCT;

typedef struct CACHESTRUCT {
  char name[256];
  int idx;
} CACHESTRUCT;

typedef struct PPSCRIPTSTRUCT {
  char name[256];
  int idx,loadgroup;
} PPSCRIPTSTRUCT;

typedef struct PATHSTRUCT {
  tmpnPathDef tpathdef;
  struct COMMANDSTRUCT *firstpoint;
} PATHSTRUCT;

typedef struct POINTSTRUCT {
  tmpnKeyPoint fp;
  tmpnKeyPoint p;

  tmpnKeyPoint pp;
  int frameidx;
  PATHSTRUCT *path;
} POINTSTRUCT;

typedef struct SUBSTRUCT {
  char name[256];
} SUBSTRUCT;

typedef struct NAMESTRUCT {
  char name[256];
} NAMESTRUCT;

typedef struct ARGSTRUCT
{
  int type;
  int idx;
  int number;
  float fnumber;
  int subtype;
  char valstring[256];
  char valstring2[256];
} ARGSTRUCT;

typedef struct SETSTRUCT
{
  ARGSTRUCT dest;
  ARGSTRUCT src;
} SETSTRUCT;

typedef struct ROBOTSPEEDSTRUCT
{
  ARGSTRUCT src;
} ROBOTSPEEDSTRUCT;

typedef struct CALCSTRUCT
{
  ARGSTRUCT dest;
  ARGSTRUCT src1;
  int optype;
  ARGSTRUCT src2;
} CALCSTRUCT;

typedef struct PRINTSTRUCT
{
  ARGSTRUCT arg;
  int newline;
} PRINTSTRUCT;

typedef struct TESTSTRUCT
{
  ARGSTRUCT test;
  int validation;
  ARGSTRUCT cmp;
  int trueIdx;
  COMMANDSTRUCT *trueCmd;
  int falseIdx;
  COMMANDSTRUCT *falseCmd;
 int doneIdx;
} TESTSTRUCT;

typedef struct ELSESTRUCT
{
  int doneIdx;
  COMMANDSTRUCT *nextCmd;
} ELSESTRUCT;

typedef struct SETSTATESTRUCT
{
  char name[256];
  int number;
} SETSTATESTRUCT;

typedef struct SETFRAMESTRUCT
{
  tmpnFrame *destFrame;
  tmpnFrame *srcFrame;
  char dest[256];
  char src[256];
} SETFRAMESTRUCT;

typedef struct SETITEMTRUCT
{
  tmpnItem **destItem;
  tmpnItem *srcItem;
  char dest[256];
  char src[256];
} SETITEMSTRUCT;

typedef struct SETPATTERNSTRUCT
{
  tmpnPattern **destPattern;
  tmpnPattern *srcPattern;
  char dest[256];
  char src[256];
} SETPATTERNSTRUCT;

typedef struct SETCPPATTERNSTRUCT
{
  tmpnCPPattern **destCPPattern;
  tmpnCPPattern *srcCPPattern;
  char dest[256];
  char src[256];
} SETCPPATTERNSTRUCT;

typedef struct TIMEOUTSTRUCT
{
  int idx;
  int number;
  char statename[256];
} TIMEOUTSTRUCT;

typedef struct LOADSTRUCT
{
  tmpnPathHandle *path;
  tmpnFrame *fromFrame;
  tmpnFrame *toFrame;
  char dest[256];
  char src1[256];
  char src2[256];
} LOADSTRUCT;

typedef struct EXECSTRUCT
{
  tmpnPathHandle *path;
  char dest[256];
} EXECSTRUCT;

typedef struct MULSTRUCT
{
  int idx;
 int arg1idx;
  int arg2idx;
} MULSTRUCT;

typedef struct DIVSTRUCT
{
  int idx;
 int arg1idx;
  int arg2idx;
} DIVSTRUCT;

typedef struct ADDSTRUCT
{
  int idx;
 int arg1idx;
  int arg2idx;
} ADDSTRUCT;

typedef struct SUBTSTRUCT
{
  int idx;
 int arg1idx;
  int arg2idx;
} SUBTSTRUCT;

typedef struct ENDSTRUCT
{

} ENDSTRUCT;

typedef struct tmpnScopeData
{
  tmpnStateMachine *stm;
  ARGSTRUCT arg;
  tmpnStateMachineValue *sampling;
} tmpnScopeData;






  int staticforce(tmpnRobot *robot);
  int tmpnComputeIK(tmpnRobot *trobot, float wx, float wy, float wz, float wv, float ww, float wu, int tcpidx);
  int tmpnJointToActuator(tmpnRobot *robot,int tcpidx);
  int tmpnComputeFK(tmpnRobot *trobot, float a, float b, float c, float d, float e, float f, int tcpidx);
  int tmpnComputeFKlogic(tmpnRobot *trobot, float a, float b, float c, float d, float e, float f, int tcpidx);
  void solve(tmpnRobot *robot, int maxidx, tmpnPosition *position, float maxTime, float *maxSpeed, int order);
  void generatePath(tmpnRobot *tmpnrobot, tmpnPathDef *pathdef, tmpnPath *path);
  void copyPath(tmpnPath *dest, tmpnPath *source);
  void hackPositionHint(tmpnPath *path, tmpnPathDef *pathdef);
  void copyKeypoint(tmpnPath *path, tmpnPathDef *pathdef);
# 2188 "tmpnrobot.h"
tmpnRobot *initrobot;
volatile tmpnRobot *trobot;
volatile tmpnWorkcell *tworkcell;
tmpnPlant *tplant;
int newtau;
extern tmpnBoptCoeffItem coeff;
extern tmpnStateName stateName[];
# 6 "scene.h" 2



void loadScene(tmpnWorkcell *workcell);







extern tmpnScene *scene;
# 8 "scene.c" 2
# 1 "cmd.h" 1
# 36 "cmd.h"
extern tmpnRSSystem rs_param;
extern char rs_systempath[256];
extern char rs_systemini[256];
extern char cmdstr[][255];
extern long defpathspeed;
extern int defpathsamprate;
extern TABLESPACE tspace;
extern volatile int roboState;

extern float speedFactor;
extern volatile int ctrlNumOfUploads[1];
extern volatile int jumpToLayer;
extern volatile int scriptLoaded;
extern pthread_cond_t script_cond;
extern pthread_mutex_t script_mutex;
extern pthread_cond_t upload_cond;
extern pthread_mutex_t upload_mtx;
extern pthread_cond_t uploaddone_cond;
extern pthread_mutex_t uploaddone_mtx;







extern int jointToTask(const char *filename);
extern int tmpnScopeLoad(const char *filename, tmpnPath *path);

extern int SaveCommandScript(COMMANDSTRUCT *root, const char *filename);
extern COMMANDSTRUCT *LoadCommandScript(const char *filename, int flag);
extern int AddProgram(int PrgStmIdx, char *newName, int copyfromidx);
extern int SaveProgramVal(int PrgStmIdx, STMCOMMANDSTRUCT *stmcmd, char *prgname);
extern int SaveTimeVal(const char *stmname, const char *timename,int val);
extern int SaveConstVal(const char *stmname, const char *constname,tmpnStateMachineValue* val);
extern int SaveItemVal(const char *stmname, const char *name, const char *itemName);
extern int SaveCPPatternVal(const char *stmname, const char *name, const char *cppName);
extern int SaveFrameVal(const char *stmname, tmpnFrame *newfr);
extern int SaveMacInitVal(tmpnMac* mac, int modidx, int initidx);
extern int tmpnRobotLoad(const char *filename, tmpnRobot *robot);
extern int tmpnRobotSave(const char *filename, tmpnRobot *robot);
extern void selectRobot(int i);

extern int tmpnPatternLoad(const char *filename, tmpnPattern *pattern);
extern int tmpnPatternSave(tmpnPattern *pattern);
extern tmpnPattern *getPattern(const char *name, tmpnWorkcell *workcell);
extern void getPatternString(char *s, int i, tmpnPattern *pattern);

extern int tmpnCPPatternLoad(const char *filename, tmpnCPPatterns *cppatterns);
extern int tmpnCPPatternSave(tmpnCPPattern *cppattern);
extern tmpnCPPattern *getCPPattern(const char *name, tmpnWorkcell *workcell);

extern tmpnPPScript *getPPScript(const char *name, tmpnWorkcell *workcell);

extern int tmpnBoptCoeffLoad(const char *filename, tmpnBoptCoeff *boptcoeff);
extern int tmpnBoptCoeffSave(tmpnBoptCoeff *boptcoeff);

extern tmpnBoptCoeff *getBoptCoeff(tmpnWorkcell *workcell);
extern tmpnBoptCoeffItem *getBoptCoeffItem(tmpnBoptCoeff *boptcoeff, int mode, int pathtype);

extern char *getLanguageLineFromIdx(tmpnLanguage *lang, int idx, char *defaultstring);
extern char *getLanguageLineFromKey(tmpnLanguage *lang, int key, char *defaultstring);
extern char *getLanguageLineFromEnglish(tmpnLanguage *lang, char *englishline, char *defaultstring);
extern int selectLanguage(tmpnLanguages *langs, char *languagename);
extern int tmpnItemLoad(const char *filename, tmpnItem *item);
extern int tmpnItemSave(tmpnItem *item);
extern tmpnItem *getItem(const char *name, tmpnWorkcell *workcell);

extern int tmpnToolLoad(const char *filename, tmpnTool *tool);
extern tmpnTool *getTool(const char *name, tmpnWorkcell *workcell);

extern int tmpnWorkcellLoad(const char *filename, tmpnWorkcell *workcell);
extern int tmpnWorkcellSave(const char *filename, tmpnWorkcell *workcell);
extern void selectWorkcell(int i);

extern int tmpnPlantLoad(const char *filename, tmpnPlant *plant);
extern int tmpnPlantSave(const char *filename, tmpnPlant *plant);

extern int tmpnStateMachineLoad(const char *filename, tmpnStateMachine *statemachine, int level);
extern int tmpnStateLoad(const char *filename, tmpnStateMachine *statemachine, int level);
extern void SetupSTMLink1(tmpnStateMachine *stm);
extern void SetupSTMLink2(tmpnStateMachine *stm);
extern int getArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern void setArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg, int value);
extern void printArg(tmpnStateMachine * stm, ARGSTRUCT *arg, int newline);

extern void copyAxisToRobotFile(tmpnRobot *robot);
extern void copyAxisToTableSpace(tmpnRobot *robot);

extern int LoadCalibrationParam(tmpnRSSystem *ini);
extern int SaveCalibrationParam(tmpnRSSystem *ini);
extern int LoadRSSystemData(tmpnRSSystem *ini);
extern int SaveRSSystemData(tmpnRSSystem *ini);

extern char *getMachineTypeName(int num);
extern int getMachineIdx(const char *machinename);
extern int getMachineStateIdx(const char *machinename, const char *statename);
extern int getStateIdx(int machine, const char *statename);
extern void deleteSTMPrg(tmpnStateMachine *statemachine);
extern void setStateTekst(char *tekst, int state, int line);
extern const char *tmpnGetDatabase(void);
extern void tmpnSetDatabase(const char *database);
extern int getRemoteStatemachineIdx(tmpnWorkcell *workcell,char *str);
extern int getRemoteValueIdx(tmpnWorkcell *workcell,char *str1,char *str2);
extern int getTCPidx(char *name, tmpnRobot *trobot);
extern int getFrameIdx(const char *name, tmpnRobot *robot);
extern int getRobotIdx(const char *name, tmpnWorkcell *workcell);
extern int getWorkcellIdx(const char *name, tmpnPlant *plant);

extern float getTimingValue(const char *name, tmpnRobot *robot);
extern int connectSimulated(tmpnConnect *connect);

extern void getCommandString(char *t, COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *addCommandString(COMMANDSTRUCT *ptrcmd, const char *t, int* level);
extern void deleteCommand(COMMANDSTRUCT *cmd);
extern void refreshPoint(COMMANDSTRUCT *cmd);
extern void adjPoint(COMMANDSTRUCT *cmd
        ,float wx, float wy, float wz, float wv, float ww, float wu, float wt, int tcpidx);

extern void refreshPath(COMMANDSTRUCT *cmd);
extern void adjPath(PATHSTRUCT *path);
extern void updatecmdPoints(COMMANDSTRUCT *cmd);
extern char *getProgramName(char *stmname);


extern tmpnStateMachineValue *getMachineValue(int machine, char *valuename);
extern int getMachineVersion(int machine);
extern tmpnFrame *getStmFrame(char *framename);
extern int *getMachineValuePtr(int machine, char *valuename);
extern unsigned short *getMachineInputPtr(int machine, char *inputname);

tmpnConnect *getConnectPtr(stbstruct *stb,char *name);
unsigned short getConnectValue(tmpnConnect *connect);
int getConnectValueInt(tmpnConnect *connect);
short getConnectValueSigned(tmpnConnect *connect);
void setConnectValue(tmpnConnect *connect, unsigned short value);
void setConnectValueInt(tmpnConnect *connect, int value);
void setConnectValueSigned(tmpnConnect *connect, short value);
macConnect *getMacConnectPtr(tmpnStateMachine *stm, char *name);

extern float getArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern void setArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg, float value);


extern void selectRunCommand(COMMANDSTRUCT *runcmd);
extern COMMANDSTRUCT *getRunCommand(void);
extern COMMANDSTRUCT *getNextRunCommand(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getNextRunCommandAtSameLevel(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getPrevRunCommand(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getFirstRunCommand(COMMANDSTRUCT *root);
extern COMMANDSTRUCT *getFirstCommand( COMMANDSTRUCT *root);
extern COMMANDSTRUCT *getLastRunCommand( COMMANDSTRUCT *root);
extern COMMANDSTRUCT *AddCommand(int type);
extern COMMANDSTRUCT *InsertCommand(COMMANDSTRUCT *ptrcmd, int type);
extern POINTSTRUCT *getPoint(COMMANDSTRUCT *pcmd, int off);
extern COMMANDSTRUCT *getPrevPPScriptCommand(COMMANDSTRUCT *pcmd);

extern int GetActualNumber(void);
extern int FindNextCommand(void);
extern int FindPrevCommand(void);
extern int FindFirstCommand(void);
extern int FindLastCommand(void);
extern int GetCurrentCommandType(void);
extern COMMANDSTRUCT *GetCommandNumber(int idx);
extern COMMANDSTRUCT *selectCommand(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *getParentCommand(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *getPreviusCommand(COMMANDSTRUCT *cmd);
extern COUNTERSTRUCT *getCounter(char *name);
extern COUNTERSTRUCT *initCounter(char *name, char *value);
extern COUNTERSTRUCT *incCounter(char *name, char *value);
extern COUNTERSTRUCT *decCounter(char *name, char *value);
extern COUNTERSTRUCT *mulCounter(char *name, char *value);
extern COUNTERSTRUCT *divCounter(char *name, char *value);
extern char *getCounterValue(char* value);
extern COMMANDSTRUCT *FindNextCmdToUpload(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *findNextToPreload(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *FindLayerCmd(COMMANDSTRUCT *pcmd, int layer);

extern COMMANDSTRUCT *expandPath(COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);

extern void RemoveAllCommands(COMMANDSTRUCT **root);
extern void ResetCmdLoadBuffer(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *FindFirstCmdToUpload(COMMANDSTRUCT *root);
extern int countPreload(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *getLabelCommand(COMMANDSTRUCT *root, const char *label);
extern COMMANDSTRUCT *findFirstPreloaded( COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *findFirstPathInGroup(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *findItemPathInGroup( COMMANDSTRUCT *root, int loadgroup);
extern int libRunCounter(COMMANDSTRUCT *cmd, COMMANDSTRUCT **pcmd);

extern char *getStateString(int idx);
int saveScopeSample(char *file, char *s);
extern int getCmpType(tmpnStateMachine *stm, char *s, int ln);
extern void getArgBody(tmpnStateMachine * stm, ARGSTRUCT *data, char arg[]);
extern float getArgValueFloat(tmpnStateMachineValue *val, char *val2, int *argSubType);
extern int getArgValueInt(tmpnStateMachineValue *val, char *val2, int *argSubType);
extern void setArgValueFloat(tmpnStateMachineValue *val, char *val2, float v);
extern void setArgValueInt(tmpnStateMachineValue *val, char *val2, int v);
extern int getArgSubType(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern int findTopInTable(tmpnStateMachineValue *value);
extern void copyFramesFromSTMtoRobot(void);
# 9 "scene.c" 2

static tmpnScene Scene;
tmpnScene *scene=&Scene;

static int boneId=0;
static int GEID=0;
static int GDID=0;
static int GBID=0;
static int GCID=0;
static int GAID=0;
static tmpnMaterial redMaterial={{1.0f, 0.0, 0.0,1.0},{1.0f, 0.0, 0.0,1.0},{1.0f, 0.0, 0.0,1.0},1.0};
static tmpnMaterial floorMaterial={{0.6f, 0.6, 0.6, 1.0},{0.6f, 0.6, 0.6, 1.0},{0.0f, 0.0, 0.0, 1.0}, 1.0};
static tmpnMaterial woodMaterial={{1.0f, 1.0, 0.0,1.0},{1.0f, 1.0, 0.0,1.0},{0.0f, 0.0, 0.0,1.0},0.0};
static tmpnMaterial mpnMaterial={{0.0f, 0.545098f, 0.8f,0.75},{0.0f, 0.545098f, 0.8f,1.0},{0.0f, 0.545098f, 0.8f,1.0},127.0};
static tmpnMaterial armMaterial={ {0.9f, 0.9f, 0.9f,0.6},{0.9f, 0.9f, 0.9f,0.6},{0.2f, 0.2f, 0.2f,0.6},0.1};
static tmpnMaterial keyMaterial={ {10.0f, 10.0f, 10.0f,10.0},{10.0f, 10.0f, 10.0f,10.0},{10.0f, 10.0f, 10.0f,10.0},127.0};
static tmpnColor currentmpnColor={1.0, 1.0, 1.0};
static tmpnMaterial currentmpnMaterial={{0.9, 0.0, 0.0, 1.0},{0.9, 0.0, 0.0, 1.0},{0.9, 0.0, 0.0, 1.0},1.0};

static void setmpnMaterial(tmpnMaterial m)
{
  currentmpnMaterial=m;
  currentmpnColor.r=m.ambient[0];
  currentmpnColor.g=m.ambient[1];
  currentmpnColor.b=m.ambient[2];
}

static void newBone(tmpnBone *bone,const char* name, float tx,float ty,float tz
            ,float lx, float ly,float lz, int cyl)
{
  bone->id = boneId++;
  bone->dim.x = lx;
  bone->dim.y = ly;
  bone->dim.z = lz;
  bone->cyl = cyl;
  bone->color.r = currentmpnColor.r;
  bone->color.g = currentmpnColor.g;
  bone->color.b = currentmpnColor.b;
  bone->material.diffuse[0]=1.2*currentmpnMaterial.diffuse[0];
  bone->material.diffuse[1]=1.2*currentmpnMaterial.diffuse[1];
  bone->material.diffuse[2]=1.2*currentmpnMaterial.diffuse[2];
  bone->material.diffuse[3]=1.0*currentmpnMaterial.diffuse[3];

  bone->material.ambient[0]=1.2*currentmpnMaterial.ambient[0];
  bone->material.ambient[1]=1.2*currentmpnMaterial.ambient[1];
  bone->material.ambient[2]=1.2*currentmpnMaterial.ambient[2];
  bone->material.ambient[3]=1.0*currentmpnMaterial.ambient[3];

  bone->material.specular[0]=0.2*currentmpnMaterial.specular[0];
  bone->material.specular[1]=0.2*currentmpnMaterial.specular[1];
  bone->material.specular[2]=0.2*currentmpnMaterial.specular[2];
  bone->material.specular[3]=1.0*currentmpnMaterial.specular[3];

  bone->material.shininess=0.2*currentmpnMaterial.shininess;
  strcpy(bone->name,name);
  bone->trans.x = tx;
  bone->trans.y = ty;
  bone->trans.z = tz;
  bone->gllist=0;
}

static void createRobotObjects(tmpnRobot *robot)
{
  boneId=1;
  setmpnMaterial(floorMaterial);
  newBone(&scene->floor,"Floor",-2000.0,-1500.0,-2000.0,3500.0,50.0,robot->m_gantryLength+700,1);
  setmpnMaterial(mpnMaterial);
  if(atoi(robot->m_name)<400||atoi(robot->m_name)>499)
  {
    newBone(&scene->foot ,"Foot" ,0.0, 0.0,0.0,400.0,0.0,400.0 ,1);
    newBone(&scene->leg ,"Leg" ,0.0,0.0,0.0,400.0,robot->m_legHeight, 400.0,1);
    newBone(&scene->gantry,"Gantry",0.0,robot->m_legHeight ,0.0,400.0,302.0,robot->m_gantryLength,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearA,"Gear A",0.0,0.0,0.0,0.0,0.0,0.0,1);
    GAID = scene->gearA.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->shoulder,"Shoulder", 0.0, 302.0, 200.0
    ,400.0,650.0, 400.0,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearB,"Gear B" , 400.0*0.5, robot->m_shoulderGearB-302.0,400.0
    ,0.0, 0.0, 0.0,1);
     scene->gearB.rot.z = 0.0;
    GBID = scene->gearB.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->upperArm,"UpperArm", 0.0, 0.0, 0.0
    ,robot->m_Link[1].length, 120.0, 120.0,2);

     setmpnMaterial(redMaterial);
    newBone(&scene->gearC,"Gear C" , robot->m_Link[1].length, 0.0, 0.0
    ,0.0, 0.0, 0.0,1);
    scene->gearC.rot.z = -90.0;
    GCID = scene->gearC.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->lowerArm,"LowerArm", 0.0, 0.0, 0.0
    ,robot->m_Link[2].length, 100.0, 100.0*0.5,2);
    newBone(&scene->lowerArm2,"LowerArm2",robot->m_Link[2].length-150.0, -70.0, -100.0
    ,220.0 , 140.0, 200.0,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearD,"Gear D" , 150.0, 70.0, 100.0
    ,0.0, 0.0, 0.0,1);
    GDID = scene->gearD.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->wrist,"Wrist" , 0.0, 0.0, 0.0
    ,robot->m_Link[3].length, 110.0*0.25, 110.0*0.5,2);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearE,"Gear E" , robot->m_Link[3].length, 0.0, 0.0
    ,0.0, 0.0, 0.0,1);
    scene->gearE.rot.z = 0.0;
    GEID = scene->gearE.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->flange,"Flange" , 0.0, 0.0, 0.0
    ,0.0, 40.0, 40.0,2);
  }
  else
  {
    newBone(&scene->foot ,"Foot" ,0.0, 0.0,0.0,100.0,0.0,100.0 ,1);
    newBone(&scene->leg ,"Leg" ,0.0,0.0,0.0,100.0,robot->m_legHeight, 100.0,1);
    newBone(&scene->gantry,"Gantry",0.0,robot->m_legHeight ,0.0,100.0,302.0,robot->m_gantryLength,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearA,"Gear A",0.0,0.0,0.0,0.0,0.0,0.0,1);
    GAID = scene->gearA.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->shoulder,"Shoulder", 0.0, 302.0, 200.0
    ,200.0,250.0, 280.0,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearB,"Gear B" , 100.0*0.5, robot->m_shoulderGearB-302.0,280.0
    ,0.0, 0.0, 0.0,1);
     scene->gearB.rot.z = 0.0;
    GBID = scene->gearB.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->upperArm,"UpperArm", 0.0, 0.0, 0.0
     ,robot->m_Link[1].length, 90.0, 90.0,2);

     setmpnMaterial(redMaterial);
    newBone(&scene->gearC,"Gear C" , robot->m_Link[1].length, 0.0, 0.0
    ,0.0, 0.0, 0.0,1);
    scene->gearC.rot.z = -90.0;
    GCID = scene->gearC.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->lowerArm,"LowerArm", 0.0, 0.0, 0.0
    ,robot->m_Link[2].length, 80.0, 80.0*0.5,2);
    newBone(&scene->lowerArm2,"LowerArm2",robot->m_Link[2].length-150.0, -70.0, -100.0
    ,220.0 , 140.0, 200.0,1);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearD,"Gear D" , 150.0, 70.0, 100.0
    ,0.0, 0.0, 0.0,1);
    GDID = scene->gearD.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->wrist,"Wrist" , 0.0, 0.0, 0.0
    ,robot->m_Link[3].length, 110.0*0.25, 110.0*0.5,2);

    setmpnMaterial(redMaterial);
    newBone(&scene->gearE,"Gear E" , robot->m_Link[3].length, 0.0, 0.0
    ,0.0, 0.0, 0.0,1);
    scene->gearE.rot.z = 0.0;
    GEID = scene->gearE.id;
    setmpnMaterial(armMaterial);
    newBone(&scene->flange,"Flange" , 0.0, 0.0, 0.0
    ,0.0, 40.0, 40.0,2);
  }
}

void loadScene(tmpnWorkcell *workcell)
{
  int l,b;
  boneId=1;
  createRobotObjects(&workcell->robots.robot[0]);

  setmpnMaterial(armMaterial);
  newBone(&scene->tool,"Tool" , 0.0, 0.0, 0.0
  ,0.0, 0.0, 0.0,1);


  setmpnMaterial(woodMaterial);
  newBone(&scene->pallet,"Pallet" , 0.0, -150.0, 0.0
  ,1200.0, 150.0, 800.0,1);

  setmpnMaterial(keyMaterial);
  newBone(&scene->key,"Key",0.0,0.0,0.0,20.0,20.0,20.0,1);

  for(l=0;l<workcell->accessories.maxidx;l++)
  {
    setmpnMaterial(workcell->accessories.accessory[l].material);
    newBone(&scene->accessories.accessory[l],"Accessory"
    ,workcell->accessories.accessory[l].transformation.x
    ,workcell->accessories.accessory[l].transformation.y
    ,workcell->accessories.accessory[l].transformation.z
    ,workcell->accessories.accessory[l].dimention.x
    ,workcell->accessories.accessory[l].dimention.y
    ,workcell->accessories.accessory[l].dimention.z
    ,1);
  }
  scene->accessories.maxidx=workcell->accessories.maxidx;
  scene->boxpicked=0;
  for(l=0;l<10;l++)
  {
    for(b=0;b<4;b++)
    {
      scene->palletAboxPlaced[l][b]=1;
    }
  }
}
