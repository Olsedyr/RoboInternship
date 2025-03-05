# 1 "dynomads.c"
# 1 "/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "dynomads.c"
# 9 "dynomads.c"
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

# 10 "dynomads.c" 2
# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 203 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 416 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 458 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 488 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4
# 89 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) __attribute__ ((__nothrow__));

extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));




extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));








extern FILE *tmpfile (void) ;
# 186 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 204 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 229 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 243 "/usr/include/stdio.h" 3 4






extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;




extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 272 "/usr/include/stdio.h" 3 4

# 283 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
# 296 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 394 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;




extern int scanf (__const char *__restrict __format, ...) ;

extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 425 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;


extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;

extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__));
# 445 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 476 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf")



     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 504 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 532 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 543 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 576 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;






extern char *gets (char *__s) ;

# 638 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 710 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 746 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 765 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 788 "/usr/include/stdio.h" 3 4

# 797 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;








extern void perror (__const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 827 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 846 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 886 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 916 "/usr/include/stdio.h" 3 4

# 11 "dynomads.c" 2
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

# 12 "dynomads.c" 2

# 1 "dynomads.h" 1
# 33 "dynomads.h"
void computetaus(void);
double tau(int i);
double oldtau(int i,int timestep);

void settoolstate(int state);
void setq(double a,double b,double c,double d,double r);
void setdq(double a,double b,double c,double d,double e);
void setddq(double a,double b,double c,double d,double e);
void setLinkLength(double l, int idx);
void setMass(double m, int idx);
void setMassDisplacement(double p0, double p1, double p2, int idx);
void setInertiaTensor(double i00,double i01,double i02
                     ,double i10,double i11,double i12
                     ,double i20,double i21,double i22
                     ,int idx);
# 14 "dynomads.c" 2


static double avek(int i);
static double alphavek(int i);
static double dvek(int i);
static double ddvek(int i);
static double dddvek(int i);
static double tvek(int i);
static double dtvek(int i);
static double ddtvek(int i);

static double* P(int i,int timestep);
static int R(int i,int timestep);
static double* computeV(int i,int timestep);
static double* computeOmega(int i,int timestep);
static double* computeOmegaDot(int i,int timestep);
static double* computeVDot(int i,int timestep);
static double* computeForce(int i, int timestep);
static double* computeN(int i, int timestep);
static double* inwardForce(int i, int timestep);
static double* inwardTorque(int i, int timestep);
void printvec(double* vec);


static double q[5];

static double dq[5];

static double ddq[5];

static double L[6];

static double pdis[5][3];

static double Mass[5];

static double I[5][3][3];







static double avek(int i) {
  return L[i];
}

static double alphavek(int i) {
  static double alv[5]={0,0,0,0,3.1415926535898/2};
  return alv[i];
}

static double dvek(int i) {
  static double dv[5]={0,0,0,0,0};
  if (i==0) return q[0];
  return dv[i];
}

static double ddvek(int i) {
  static double dv[5]={0,0,0,0,0};
  if (i==0) return dq[0];
  return dv[i];
}

static double dddvek(int i) {
  static double dv[5]={0,0,0,0,0};
  if (i==0) return ddq[0];
  return dv[i];
}


static double tvek(int i) {
  if (i==0) return 0;
  if (i==1) return q[1];
  if (i==2) return q[2];
  if (i==3) return q[3]+3.1415926535898/2;
  return q[4];
}

static double dtvek(int i) {
  if (i==0) return 0;
  return dq[i];
}

static double ddtvek(int i) {
  if (i==0) return 0;
  return ddq[i];
}

static double ptrans[6][3];

static double* P(int i,int timestep) {
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if ((timestep==last_timestep[i])||(i>0)) {
    if (last_timestep[i]!=-1) return ptrans[i];
  }
  last_timestep[i] = timestep;
  if (i==5) {
    ptrans[i][0] = 0;
    ptrans[i][1] = 0;
    ptrans[i][2] = 0;
  }
  else
  {
    ptrans[i][0] = avek(i);
    ptrans[i][1] = -sin(alphavek(i))*dvek(i);
    ptrans[i][2] = cos(alphavek(i))*dvek(i);
  }
  return ptrans[i];
}

static double rtrans[6][3][3];

int R(int i,int timestep) {
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i]||(i==0)) {
    if (last_timestep[i]!=-1) return i;
  }
  last_timestep[i] = timestep;
  if (i==5) {
    rtrans[i][0][0] = 1;
    rtrans[i][0][1] = 0;
    rtrans[i][0][2] = 0;
    rtrans[i][1][0] = 0;
    rtrans[i][1][1] = 1;
    rtrans[i][1][2] = 0;
    rtrans[i][2][0] = 0;
    rtrans[i][2][1] = 0;
    rtrans[i][2][2] = 1;
  }
  else {
    rtrans[i][0][0] = cos(tvek(i));
    rtrans[i][0][1] = -sin(tvek(i));
    rtrans[i][0][2] = 0;
    rtrans[i][1][0] = sin(tvek(i))*cos(alphavek(i));
    rtrans[i][1][1] = cos(tvek(i))*cos(alphavek(i));
    rtrans[i][1][2] = -sin(alphavek(i));
    rtrans[i][2][0] = sin(tvek(i))*sin(alphavek(i));
    rtrans[i][2][1] = cos(tvek(i))*sin(alphavek(i));
    rtrans[i][2][2] = cos(alphavek(i));
  }
  return i;
}

static double vvec[6][3];

double* computeV(int i,int timestep) {
  double* o;
  double* p;
  double* l;
  double temp[3];
  int r;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    vvec[5][0]=0.0;
    vvec[5][1]=0.0;
    vvec[5][2]=0.0;
    return vvec[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return vvec[i];
  }
  last_timestep[i] = timestep;
  o = computeOmega(i-1,timestep);
  p = P(i, timestep);
  l = computeV(i-1,timestep);
  r = R(i,timestep);
  vvec[i][0] = (l[0]+(o[1]*p[2]-o[2]*p[1]));
  vvec[i][1] = (l[1]+(o[2]*p[0]-o[0]*p[2]));
  vvec[i][2] = (l[2]+(o[0]*p[1]-o[1]*p[0]));
  temp[0] = rtrans[r][0][0]*vvec[i][0]+rtrans[r][1][0]*vvec[i][1]+rtrans[r][2][0]*vvec[i][2];
  temp[1] = rtrans[r][0][1]*vvec[i][0]+rtrans[r][1][1]*vvec[i][1]+rtrans[r][2][1]*vvec[i][2];
  temp[2] = rtrans[r][0][2]*vvec[i][0]+rtrans[r][1][2]*vvec[i][1]+rtrans[r][2][2]*vvec[i][2];
  vvec[i][0] = temp[0];
  vvec[i][1] = temp[1];
  vvec[i][2] = temp[2] + ddvek(i);
  return vvec[i];
}

static double om[6][3];

double* computeOmega(int i,int timestep) {
  double* ino;
  int r;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    om[5][0] = 0.0;
    om[5][1] = 0.0;
    om[5][2] = 0.0;
    return om[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return om[i];
  }
  last_timestep[i] = timestep;
  ino = computeOmega(i-1,timestep);
  r = R(i,timestep);
  om[i][0] = rtrans[r][0][0]*ino[0]+rtrans[r][1][0]*ino[1]+rtrans[r][2][0]*ino[2];
  om[i][1] = rtrans[r][0][1]*ino[0]+rtrans[r][1][1]*ino[1]+rtrans[r][2][1]*ino[2];
  om[i][2] = rtrans[r][0][2]*ino[0]+rtrans[r][1][2]*ino[1]+rtrans[r][2][2]*ino[2]+dtvek(i);
  return om[i];
}
static double omd[6][3];

double* computeOmegaDot(int i,int timestep) {
  double* inod;
  double* ino;
  int r;
  double temp[3];
  double tem[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    omd[5][0] = 0.0;
    omd[5][1] = 0.0;
    omd[5][2] = 0.0;
    return omd[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return omd[i];
  }
  last_timestep[i] = timestep;
  r = R(i,timestep);
  inod = computeOmegaDot(i-1,timestep);
  ino = computeOmega(i-1,timestep);
  temp[0] = rtrans[r][0][0]*ino[0]+rtrans[r][1][0]*ino[1]+rtrans[r][2][0]*ino[2];
  temp[1] = rtrans[r][0][1]*ino[0]+rtrans[r][1][1]*ino[1]+rtrans[r][2][1]*ino[2];
  temp[2] = rtrans[r][0][2]*ino[0]+rtrans[r][1][2]*ino[1]+rtrans[r][2][2]*ino[2];
  tem[0] = rtrans[r][0][0]*inod[0]+rtrans[r][1][0]*inod[1]+rtrans[r][2][0]*inod[2];
  tem[1] = rtrans[r][0][1]*inod[0]+rtrans[r][1][1]*inod[1]+rtrans[r][2][1]*inod[2];
  tem[2] = rtrans[r][0][2]*inod[0]+rtrans[r][1][2]*inod[1]+rtrans[r][2][2]*inod[2];
  omd[i][0] = tem[0]+temp[1]*dtvek(i);
  omd[i][1] = tem[1]-temp[0]*dtvek(i);
  omd[i][2] = tem[2]+ddtvek(i);
  return omd[i];
}
static double ved[6][3];
double* computeVDot(int i,int timestep) {
  double* invd;
  double* inod;
  double* ino;
  double* o;
  int r;
  double* p;
  double temp[3];
  double tem[3];
  double temo[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==-1) {
    ved[5][0] = 9.81;
    ved[5][1] = 0.0;
    ved[5][2] = 0.0;
    return ved[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return ved[i];
  }
  last_timestep[i] = timestep;
  r = R(i,timestep);
  inod = computeOmegaDot(i-1,timestep);
  ino = computeOmega(i-1,timestep);
  o = computeOmega(i,timestep);
  invd = computeVDot(i-1,timestep);
  p = P(i,timestep);
  temp[0] = (ino[1]*p[2]-ino[2]*p[1]);
  temp[1] = (ino[2]*p[0]-ino[0]*p[2]);
  temp[2] = (ino[0]*p[1]-ino[1]*p[0]);
  temo[0] = (inod[1]*p[2]-inod[2]*p[1]);
  temo[1] = (inod[2]*p[0]-inod[0]*p[2]);
  temo[2] = (inod[0]*p[1]-inod[1]*p[0]);
  tem[0] = temo[0]+(ino[1]*temp[2]-ino[2]*temp[1])+invd[0];
  tem[1] = temo[1]+(ino[2]*temp[0]-ino[0]*temp[2])+invd[1];
  tem[2] = temo[2]+(ino[0]*temp[1]-ino[1]*temp[0])+invd[2];
  temp[0] = rtrans[r][0][0]*tem[0]+rtrans[r][1][0]*tem[1]+rtrans[r][2][0]*tem[2];
  temp[1] = rtrans[r][0][1]*tem[0]+rtrans[r][1][1]*tem[1]+rtrans[r][2][1]*tem[2];
  temp[2] = rtrans[r][0][2]*tem[0]+rtrans[r][1][2]*tem[1]+rtrans[r][2][2]*tem[2];
  ved[i][0] = temp[0]+2*o[1]*ddvek(i);
  ved[i][1] = temp[1]-2*o[0]*ddvek(i);
  ved[i][2] = temp[2]+dddvek(i);
  return ved[i];
}



static double vedc[5][3];
double* computeForce(int i, int timestep) {
  int j;
  double* od;
  double* o;
  double* vd;
  double temp[3];
  double tem[3];
  static int last_timestep[5]={-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return vedc[i];
  }
  last_timestep[i] = timestep;
  od = computeOmegaDot(i, timestep);
  o = computeOmega(i, timestep);
  vd = computeVDot(i, timestep);
  temp[0] = (od[1]*pdis[i][2]-od[2]*pdis[i][1]);
  temp[1] = (od[2]*pdis[i][0]-od[0]*pdis[i][2]);
  temp[2] = (od[0]*pdis[i][1]-od[1]*pdis[i][0]);
  tem[0] = (o[1]*pdis[i][2]-o[2]*pdis[i][1]);
  tem[1] = (o[2]*pdis[i][0]-o[0]*pdis[i][2]);
  tem[2] = (o[0]*pdis[i][1]-o[1]*pdis[i][0]);
  vedc[i][0] = temp[0]+(o[1]*tem[2]-o[2]*tem[1])+vd[0];
  vedc[i][1] = temp[1]+(o[2]*tem[0]-o[0]*tem[2])+vd[1];
  vedc[i][2] = temp[2]+(o[0]*tem[1]-o[1]*tem[0])+vd[2];
  for(j=0;j<3;j++) vedc[i][j] *= Mass[i];
  return vedc[i];
}

static double cn[5][3];
double* computeN(int i, int timestep) {
  double* o;
  double* od;
  double temp[3];
  double tem[3];
  int j;
  static int last_timestep[5]={-1,-1,-1,-1,-1};
  if (timestep==last_timestep[i])
  {
    if (last_timestep[i]!=-1) return cn[i];
  }
  last_timestep[i] = timestep;
  o = computeOmega(i, timestep);
  od = computeOmegaDot(i, timestep);
  for (j=0;j<3;j++)
  {
    temp[j] = I[i][j][0]*od[0]+I[i][j][1]*od[1]+I[i][j][2]*od[2];
    tem[j] = I[i][j][0]*o[0]+I[i][j][1]*o[1]+I[i][j][2]*o[2];
  }
  cn[i][0] = temp[0]+(o[1]*tem[2]-o[2]*tem[1]);
  cn[i][1] = temp[1]+(o[2]*tem[0]-o[0]*tem[2]);
  cn[i][2] = temp[2]+(o[0]*tem[1]-o[1]*tem[0]);
  return cn[i];
}


static double inwaf[6][3];
double* inwardForce(int i, int timestep) {
  double* outinwf;
  int outr;
  double* f;
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==5) {
    inwaf[5][0]=0;
    inwaf[5][1]=0;
    inwaf[5][2]=0;
    return inwaf[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return inwaf[i];
  }
  last_timestep[i] = timestep;
  outr = R(i+1,timestep);
  f = computeForce(i,timestep);
  outinwf = inwardForce(i+1,timestep);
  inwaf[i][0] = rtrans[outr][0][0]*outinwf[0]+rtrans[outr][0][1]*outinwf[1]+rtrans[outr][0][2]*outinwf[2]+f[0];
  inwaf[i][1] = rtrans[outr][1][0]*outinwf[0]+rtrans[outr][1][1]*outinwf[1]+rtrans[outr][1][2]*outinwf[2]+f[1];
  inwaf[i][2] = rtrans[outr][2][0]*outinwf[0]+rtrans[outr][2][1]*outinwf[1]+rtrans[outr][2][2]*outinwf[2]+f[2];
  return inwaf[i];
}

static double inwat[6][3];
double* inwardTorque(int i, int timestep) {
  double* outinwt;
  double* outinwf;
  int outr;
  double* t;
  double* f;
  double* p;
  double temp[3];
  double temo[3];
  double tem[3];
  static int last_timestep[6]={-1,-1,-1,-1,-1,-1};
  if (i==5) {
    inwat[5][0]=0;
    inwat[5][1]=0;
    inwat[5][2]=0;
    return inwat[5];
  }
  if (timestep==last_timestep[i]) {
    if (last_timestep[i]!=-1) return inwat[i];
  }
  last_timestep[i] = timestep;
  outr = R(i+1,timestep);
  t = computeN(i,timestep);
  f = computeForce(i,timestep);
  p = P(i+1,timestep);
  outinwf = inwardForce(i+1,timestep);
  outinwt = inwardTorque(i+1,timestep);
  temp[0] = rtrans[outr][0][0]*outinwt[0]+rtrans[outr][0][1]*outinwt[1]+rtrans[outr][0][1]*outinwt[2]+t[0];
  temp[1] = rtrans[outr][1][0]*outinwt[0]+rtrans[outr][1][1]*outinwt[1]+rtrans[outr][1][2]*outinwt[2]+t[1];
  temp[2] = rtrans[outr][2][0]*outinwt[0]+rtrans[outr][2][1]*outinwt[1]+rtrans[outr][2][2]*outinwt[2]+t[2];
  tem[0] = (pdis[i][1]*f[2]-pdis[i][2]*f[1]);
  tem[1] = (pdis[i][2]*f[0]-pdis[i][0]*f[2]);
  tem[2] = (pdis[i][0]*f[1]-pdis[i][1]*f[0]);
  temo[0] = rtrans[outr][0][0]*outinwf[0]+rtrans[outr][0][1]*outinwf[1]+rtrans[outr][0][1]*outinwf[2];
  temo[1] = rtrans[outr][1][0]*outinwf[0]+rtrans[outr][1][1]*outinwf[1]+rtrans[outr][1][2]*outinwf[2];
  temo[2] = rtrans[outr][2][0]*outinwf[0]+rtrans[outr][2][1]*outinwf[1]+rtrans[outr][2][2]*outinwf[2];
  inwat[i][0] = (p[1]*temo[2]-p[2]*temo[1])+tem[0]+temp[0];
  inwat[i][1] = (p[2]*temo[0]-p[0]*temo[2])+tem[1]+temp[1];
  inwat[i][2] = (p[0]*temo[1]-p[1]*temo[0])+tem[2]+temp[2];
  return inwat[i];
}

void setq(double a,double b,double c,double d,double e) {
  q[0]=a;
  q[1]=b;
  q[2]=c;
  q[3]=d;
  q[4]=e;
}

void setdq(double a,double b,double c,double d,double e) {
  dq[0]=a;
  dq[1]=b;
  dq[2]=c;
  dq[3]=d;
  dq[4]=e;
}

void setddq(double a,double b,double c,double d,double e) {
  ddq[0]=a;
  ddq[1]=b;
  ddq[2]=c;
  ddq[3]=d;
  ddq[4]=e;
}

void setLinkLength(double l, int idx)
{
  L[idx+1]=l*0.001;


  L[2]=(double)1.0;
  L[3]=(double)1.066;


}

static double Mfive;

void setMass(double m, int idx)
{
  Mass[idx]=m;
  if(idx==4) Mfive=m;
  if(idx==0) Mass[idx]=(double)158.0;
  if(idx==1) Mass[idx]=(double)58.87;
  if(idx==2) Mass[idx]=(double)66.8109;
  if(idx==3) Mass[idx]=(double)4.79;
  if(idx==4) Mass[idx]=Mfive;
}
void setMassDisplacement(double p0, double p1, double p2, int idx)
{
  pdis[idx][0]=p0;
  pdis[idx][1]=p1;
  pdis[idx][2]=p2;
}
void setInertiaTensor(double i00,double i01,double i02
                     ,double i10,double i11,double i12
                     ,double i20,double i21,double i22
                     ,int idx)
{
  I[idx][0][0]=i00;
  I[idx][0][1]=i01;
  I[idx][0][2]=i02;
  I[idx][1][0]=i10;
  I[idx][1][1]=i11;
  I[idx][1][2]=i12;
  I[idx][2][0]=i20;
  I[idx][2][1]=i21;
  I[idx][2][2]=i22;
}

double oldtau(int i,int timestep) {
  if (i==0) return 0.025*(inwardForce(i,timestep)[2]);

  return inwardTorque(i,timestep)[2];
}

# 1 "tau.c" 1



double taus[5];
void computetaus() {
 double cosq1 = cos(q[1]);
 double sinq1 = sin(q[1]);
 double cosq2 = cos(q[2]);
 double sinq2 = sin(q[2]);
 double cosq3 = cos(q[3]);
 double sinq3 = sin(q[3]);
 double cosq4 = cos(q[4]);
 double sinq4 = sin(q[4]);
 double cos2q4 = cos(2*q[4]);
 double sin2q4 = sin(2*q[4]);
 double cos123 = cos(q[1]+q[2]+q[3]);
 double sin123 = sin(q[1]+q[2]+q[3]);
 double cos12 = cos(q[1]+q[2]);
 double sin12 = sin(q[1]+q[2]);
 double cos23 = cos(q[2]+q[3]);
 double sin23 = sin(q[2]+q[3]);
 taus[0]=0.025*(((double)4.79 + (double)158.0 + (double)66.8109 + (double)58.87)*ddq[0] + Mfive*(ddq[0] - (dq[4])*(dq[4])*(cosq4*pdis[4][1] + pdis[4][0]*sinq4) + ddq[4]*(cosq4*pdis[4][0] - pdis[4][1]*sinq4)));
 taus[1]=(2*((double)1.0)*((double)1.0)*Mfive*ddq[1] + 2*((double)1.066)*((double)1.066)*Mfive*ddq[1] + 2*((double)1.0)*((double)1.0)*(double)4.79*ddq[1] + 2*((double)1.066)*((double)1.066)*(double)4.79*ddq[1] + 2*((double)1.0)*((double)1.0)*(double)66.8109*ddq[1] + 4*(double)1.0*(double)1.066*Mfive*cosq2*ddq[1] + 4*(double)1.0*(double)1.066*(double)4.79*cosq2*ddq[1] + 2*((double)1.066)*((double)1.066)*Mfive*ddq[2] + 2*((double)1.066)*((double)1.066)*(double)4.79*ddq[2] + 2*(double)1.0*(double)1.066*Mfive*cosq2*ddq[2] + 2*(double)1.0*(double)1.066*(double)4.79*cosq2*ddq[2] + 2*ddq[1]*I[1][2][2] + 2*ddq[1]*I[2][2][2] + 2*ddq[2]*I[2][2][2] + 2*ddq[1]*I[3][2][2] + 2*ddq[2]*I[3][2][2] + 2*ddq[3]*I[3][2][2] + ddq[1]*I[4][0][0] + ddq[2]*I[4][0][0] + ddq[3]*I[4][0][0] + ddq[1]*I[4][1][1] + ddq[2]*I[4][1][1] + ddq[3]*I[4][1][1] + 2*(double)58.87*ddq[1]*(pdis[1][0])*(pdis[1][0]) - 2*9.81*(double)58.87*cosq1*pdis[1][1] + 2*(double)58.87*ddq[1]*(pdis[1][1])*(pdis[1][1]) + 4*(double)1.0*(double)66.8109*cosq2*ddq[1]*pdis[2][0] + 2*(double)1.0*(double)66.8109*cosq2*ddq[2]*pdis[2][0] + 2*(double)66.8109*ddq[1]*(pdis[2][0])*(pdis[2][0]) + 2*(double)66.8109*ddq[2]*(pdis[2][0])*(pdis[2][0]) - 2*9.81*(double)66.8109*cos12*pdis[2][1] - 4*(double)1.0*(double)66.8109*cosq2*dq[1]*dq[2]*pdis[2][1] - 2*(double)1.0*(double)66.8109*cosq2*(dq[2])*(dq[2])*pdis[2][1] + 2*(double)66.8109*ddq[1]*(pdis[2][1])*(pdis[2][1]) + 2*(double)66.8109*ddq[2]*(pdis[2][1])*(pdis[2][1]) - 2*9.81*(double)4.79*cos123*pdis[3][0] - 4*(double)1.0*(double)4.79*cos23*dq[1]*dq[2]*pdis[3][0] - 2*(double)1.0*(double)4.79*cos23*(dq[2])*(dq[2])*pdis[3][0] - 4*(double)1.066*(double)4.79*cosq3*dq[1]*dq[3]*pdis[3][0] - 4*(double)1.0*(double)4.79*cos23*dq[1]*dq[3]*pdis[3][0] - 4*(double)1.066*(double)4.79*cosq3*dq[2]*dq[3]*pdis[3][0] - 4*(double)1.0*(double)4.79*cos23*dq[2]*dq[3]*pdis[3][0] - 2*(double)1.066*(double)4.79*cosq3*(dq[3])*(dq[3])*pdis[3][0] - 2*(double)1.0*(double)4.79*cos23*(dq[3])*(dq[3])*pdis[3][0] + 2*(double)4.79*ddq[1]*(pdis[3][0])*(pdis[3][0]) + 2*(double)4.79*ddq[2]*(pdis[3][0])*(pdis[3][0]) + 2*(double)4.79*ddq[3]*(pdis[3][0])*(pdis[3][0]) - 4*(double)1.066*(double)4.79*cosq3*ddq[1]*pdis[3][1] - 4*(double)1.0*(double)4.79*cos23*ddq[1]*pdis[3][1] - 4*(double)1.066*(double)4.79*cosq3*ddq[2]*pdis[3][1] - 2*(double)1.0*(double)4.79*cos23*ddq[2]*pdis[3][1] - 2*(double)1.066*(double)4.79*cosq3*ddq[3]*pdis[3][1] - 2*(double)1.0*(double)4.79*cos23*ddq[3]*pdis[3][1] + 2*(double)4.79*ddq[1]*(pdis[3][1])*(pdis[3][1]) + 2*(double)4.79*ddq[2]*(pdis[3][1])*(pdis[3][1]) + 2*(double)4.79*ddq[3]*(pdis[3][1])*(pdis[3][1]) + Mfive*ddq[1]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[2]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[3]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[1]*(pdis[4][1])*(pdis[4][1]) + Mfive*ddq[2]*(pdis[4][1])*(pdis[4][1]) + Mfive*ddq[3]*(pdis[4][1])*(pdis[4][1]) + cos2q4*(2*dq[3]*dq[4]*I[4][0][1] + 2*dq[3]*dq[4]*I[4][1][0] - (ddq[1] + ddq[2] + ddq[3])*(I[4][0][0] - I[4][1][1]) + Mfive*ddq[1]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[2]*(pdis[4][0])*(pdis[4][0]) - 4*Mfive*dq[3]*dq[4]*pdis[4][0]*pdis[4][1] - Mfive*ddq[1]*(pdis[4][1])*(pdis[4][1]) - Mfive*ddq[2]*(pdis[4][1])*(pdis[4][1]) + 2*dq[1]*dq[4]*(I[4][0][1] + I[4][1][0] - 2*Mfive*pdis[4][0]*pdis[4][1]) + 2*dq[2]*dq[4]*(I[4][0][1] + I[4][1][0] - 2*Mfive*pdis[4][0]*pdis[4][1]) + Mfive*ddq[3]*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1]))) + 4*(double)1.066*Mfive*cosq3*ddq[1]*pdis[4][2] + 4*(double)1.0*Mfive*cos23*ddq[1]*pdis[4][2] + 4*(double)1.066*Mfive*cosq3*ddq[2]*pdis[4][2] + 2*(double)1.0*Mfive*cos23*ddq[2]*pdis[4][2] + 2*(double)1.066*Mfive*cosq3*ddq[3]*pdis[4][2] + 2*(double)1.0*Mfive*cos23*ddq[3]*pdis[4][2] + 2*Mfive*ddq[1]*(pdis[4][2])*(pdis[4][2]) + 2*Mfive*ddq[2]*(pdis[4][2])*(pdis[4][2]) + 2*Mfive*ddq[3]*(pdis[4][2])*(pdis[4][2]) - 2*9.81*(double)1.0*Mfive*sinq1 - 2*9.81*(double)1.0*(double)4.79*sinq1 - 2*9.81*(double)1.0*(double)66.8109*sinq1 - 2*9.81*(double)58.87*pdis[1][0]*sinq1 - 4*(double)1.0*(double)1.066*Mfive*dq[1]*dq[2]*sinq2 - 4*(double)1.0*(double)1.066*(double)4.79*dq[1]*dq[2]*sinq2 - 2*(double)1.0*(double)1.066*Mfive*(dq[2])*(dq[2])*sinq2 - 2*(double)1.0*(double)1.066*(double)4.79*(dq[2])*(dq[2])*sinq2 - 4*(double)1.0*(double)66.8109*dq[1]*dq[2]*pdis[2][0]*sinq2 - 2*(double)1.0*(double)66.8109*(dq[2])*(dq[2])*pdis[2][0]*sinq2 - 4*(double)1.0*(double)66.8109*ddq[1]*pdis[2][1]*sinq2 - 2*(double)1.0*(double)66.8109*ddq[2]*pdis[2][1]*sinq2 - 2*9.81*(double)1.066*Mfive*sin12 - 2*9.81*(double)1.066*(double)4.79*sin12 - 2*9.81*(double)66.8109*pdis[2][0]*sin12 - 4*(double)1.066*(double)4.79*ddq[1]*pdis[3][0]*sinq3 - 4*(double)1.066*(double)4.79*ddq[2]*pdis[3][0]*sinq3 - 2*(double)1.066*(double)4.79*ddq[3]*pdis[3][0]*sinq3 + 4*(double)1.066*(double)4.79*dq[1]*dq[3]*pdis[3][1]*sinq3 + 4*(double)1.066*(double)4.79*dq[2]*dq[3]*pdis[3][1]*sinq3 + 2*(double)1.066*(double)4.79*(dq[3])*(dq[3])*pdis[3][1]*sinq3 - 4*(double)1.066*Mfive*dq[1]*dq[3]*pdis[4][2]*sinq3 - 4*(double)1.066*Mfive*dq[2]*dq[3]*pdis[4][2]*sinq3 - 2*(double)1.066*Mfive*(dq[3])*(dq[3])*pdis[4][2]*sinq3 - 4*(double)1.0*(double)4.79*ddq[1]*pdis[3][0]*sin23 - 2*(double)1.0*(double)4.79*ddq[2]*pdis[3][0]*sin23 - 2*(double)1.0*(double)4.79*ddq[3]*pdis[3][0]*sin23 + 4*(double)1.0*(double)4.79*dq[1]*dq[2]*pdis[3][1]*sin23 + 2*(double)1.0*(double)4.79*(dq[2])*(dq[2])*pdis[3][1]*sin23 + 4*(double)1.0*(double)4.79*dq[1]*dq[3]*pdis[3][1]*sin23 + 4*(double)1.0*(double)4.79*dq[2]*dq[3]*pdis[3][1]*sin23 + 2*(double)1.0*(double)4.79*(dq[3])*(dq[3])*pdis[3][1]*sin23 - 4*(double)1.0*Mfive*dq[1]*dq[2]*pdis[4][2]*sin23 - 2*(double)1.0*Mfive*(dq[2])*(dq[2])*pdis[4][2]*sin23 - 4*(double)1.0*Mfive*dq[1]*dq[3]*pdis[4][2]*sin23 - 4*(double)1.0*Mfive*dq[2]*dq[3]*pdis[4][2]*sin23 - 2*(double)1.0*Mfive*(dq[3])*(dq[3])*pdis[4][2]*sin23 + 2*cosq4*((dq[4])*(dq[4])*I[4][0][2] + ddq[4]*I[4][1][2] + Mfive*((-(9.81*cos123) - (double)1.0*cos23*(dq[2] + dq[3])*(2*dq[1] + dq[2] + dq[3]) - (double)1.066*cosq3*dq[3]*(2*(dq[1] + dq[2]) + dq[3]))*pdis[4][0] - (dq[4])*(dq[4])*pdis[4][0]*((double)1.066*cosq3 + (double)1.0*cos23 + pdis[4][2]) - ddq[4]*pdis[4][1]*((double)1.066*cosq3 + (double)1.0*cos23 + pdis[4][2]) - 2*ddq[1]*pdis[4][0]*((double)1.066*sinq3 + (double)1.0*sin23) - ddq[3]*pdis[4][0]*((double)1.066*sinq3 + (double)1.0*sin23) + 2*(dq[1] + dq[2] + dq[3])*dq[4]*pdis[4][1]*((double)1.066*sinq3 + (double)1.0*sin23) - ddq[2]*pdis[4][0]*(2*(double)1.066*sinq3 + (double)1.0*sin23))) + 2*9.81*(double)4.79*pdis[3][1]*sin123 - 2*9.81*Mfive*pdis[4][2]*sin123 + 2*(ddq[4]*I[4][0][2] - (dq[4])*(dq[4])*I[4][1][2] + Mfive*(-(ddq[4]*pdis[4][0]*pdis[4][2]) + pdis[4][1]*(9.81*cos123 + (dq[4])*(dq[4])*pdis[4][2]) + (double)1.066*(cosq3*(-(ddq[4]*pdis[4][0]) + (dq[3]*(2*(dq[1] + dq[2]) + dq[3]) + (dq[4])*(dq[4]))*pdis[4][1]) + (2*(dq[1] + dq[2] + dq[3])*dq[4]*pdis[4][0] + (2*(ddq[1] + ddq[2]) + ddq[3])*pdis[4][1])*sinq3) + (double)1.0*(-(cos23*ddq[4]*pdis[4][0]) + cos23*(dq[2])*(dq[2])*pdis[4][1] + cos23*(dq[3])*(dq[3])*pdis[4][1] + cos23*(dq[4])*(dq[4])*pdis[4][1] + 2*dq[3]*dq[4]*pdis[4][0]*sin23 + 2*ddq[1]*pdis[4][1]*sin23 + ddq[2]*pdis[4][1]*sin23 + ddq[3]*pdis[4][1]*sin23 + 2*dq[2]*(cos23*dq[3]*pdis[4][1] + dq[4]*pdis[4][0]*sin23) + 2*dq[1]*(cos23*(dq[2] + dq[3])*pdis[4][1] + dq[4]*pdis[4][0]*sin23))))*sinq4 + ((ddq[1] + ddq[2] + ddq[3])*(I[4][0][1] + I[4][1][0]) + 2*dq[1]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1]))) + 2*dq[2]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1]))) + 2*(-(Mfive*(ddq[1] + ddq[2] + ddq[3])*pdis[4][0]*pdis[4][1]) + dq[3]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1])))))*sin2q4)/2.;
 taus[2]=(2*((double)1.066)*((double)1.066)*Mfive*ddq[1] + 2*((double)1.066)*((double)1.066)*(double)4.79*ddq[1] + 2*(double)1.0*(double)1.066*Mfive*cosq2*ddq[1] + 2*(double)1.0*(double)1.066*(double)4.79*cosq2*ddq[1] + 2*((double)1.066)*((double)1.066)*Mfive*ddq[2] + 2*((double)1.066)*((double)1.066)*(double)4.79*ddq[2] + 2*ddq[1]*I[2][2][2] + 2*ddq[2]*I[2][2][2] + 2*ddq[1]*I[3][2][2] + 2*ddq[2]*I[3][2][2] + 2*ddq[3]*I[3][2][2] + ddq[1]*I[4][0][0] + ddq[2]*I[4][0][0] + ddq[3]*I[4][0][0] + ddq[1]*I[4][1][1] + ddq[2]*I[4][1][1] + ddq[3]*I[4][1][1] + 2*(double)1.0*(double)66.8109*cosq2*ddq[1]*pdis[2][0] + 2*(double)66.8109*ddq[1]*(pdis[2][0])*(pdis[2][0]) + 2*(double)66.8109*ddq[2]*(pdis[2][0])*(pdis[2][0]) - 2*9.81*(double)66.8109*cos12*pdis[2][1] + 2*(double)1.0*(double)66.8109*cosq2*(dq[1])*(dq[1])*pdis[2][1] + 2*(double)66.8109*ddq[1]*(pdis[2][1])*(pdis[2][1]) + 2*(double)66.8109*ddq[2]*(pdis[2][1])*(pdis[2][1]) - 2*9.81*(double)4.79*cos123*pdis[3][0] + 2*(double)1.0*(double)4.79*cos23*(dq[1])*(dq[1])*pdis[3][0] - 4*(double)1.066*(double)4.79*cosq3*dq[1]*dq[3]*pdis[3][0] - 4*(double)1.066*(double)4.79*cosq3*dq[2]*dq[3]*pdis[3][0] - 2*(double)1.066*(double)4.79*cosq3*(dq[3])*(dq[3])*pdis[3][0] + 2*(double)4.79*ddq[1]*(pdis[3][0])*(pdis[3][0]) + 2*(double)4.79*ddq[2]*(pdis[3][0])*(pdis[3][0]) + 2*(double)4.79*ddq[3]*(pdis[3][0])*(pdis[3][0]) - 4*(double)1.066*(double)4.79*cosq3*ddq[1]*pdis[3][1] - 2*(double)1.0*(double)4.79*cos23*ddq[1]*pdis[3][1] - 4*(double)1.066*(double)4.79*cosq3*ddq[2]*pdis[3][1] - 2*(double)1.066*(double)4.79*cosq3*ddq[3]*pdis[3][1] + 2*(double)4.79*ddq[1]*(pdis[3][1])*(pdis[3][1]) + 2*(double)4.79*ddq[2]*(pdis[3][1])*(pdis[3][1]) + 2*(double)4.79*ddq[3]*(pdis[3][1])*(pdis[3][1]) + Mfive*ddq[1]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[2]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[3]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[1]*(pdis[4][1])*(pdis[4][1]) + Mfive*ddq[2]*(pdis[4][1])*(pdis[4][1]) + Mfive*ddq[3]*(pdis[4][1])*(pdis[4][1]) + cos2q4*(2*dq[3]*dq[4]*I[4][0][1] + 2*dq[3]*dq[4]*I[4][1][0] - (ddq[1] + ddq[2] + ddq[3])*(I[4][0][0] - I[4][1][1]) + Mfive*ddq[1]*(pdis[4][0])*(pdis[4][0]) + Mfive*ddq[2]*(pdis[4][0])*(pdis[4][0]) - 4*Mfive*dq[3]*dq[4]*pdis[4][0]*pdis[4][1] - Mfive*ddq[1]*(pdis[4][1])*(pdis[4][1]) - Mfive*ddq[2]*(pdis[4][1])*(pdis[4][1]) + 2*dq[1]*dq[4]*(I[4][0][1] + I[4][1][0] - 2*Mfive*pdis[4][0]*pdis[4][1]) + 2*dq[2]*dq[4]*(I[4][0][1] + I[4][1][0] - 2*Mfive*pdis[4][0]*pdis[4][1]) + Mfive*ddq[3]*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1]))) + 4*(double)1.066*Mfive*cosq3*ddq[1]*pdis[4][2] + 2*(double)1.0*Mfive*cos23*ddq[1]*pdis[4][2] + 4*(double)1.066*Mfive*cosq3*ddq[2]*pdis[4][2] + 2*(double)1.066*Mfive*cosq3*ddq[3]*pdis[4][2] + 2*Mfive*ddq[1]*(pdis[4][2])*(pdis[4][2]) + 2*Mfive*ddq[2]*(pdis[4][2])*(pdis[4][2]) + 2*Mfive*ddq[3]*(pdis[4][2])*(pdis[4][2]) + 2*(double)1.0*(double)1.066*Mfive*(dq[1])*(dq[1])*sinq2 + 2*(double)1.0*(double)1.066*(double)4.79*(dq[1])*(dq[1])*sinq2 + 2*(double)1.0*(double)66.8109*(dq[1])*(dq[1])*pdis[2][0]*sinq2 - 2*(double)1.0*(double)66.8109*ddq[1]*pdis[2][1]*sinq2 - 2*9.81*(double)1.066*Mfive*sin12 - 2*9.81*(double)1.066*(double)4.79*sin12 - 2*9.81*(double)66.8109*pdis[2][0]*sin12 - 4*(double)1.066*(double)4.79*ddq[1]*pdis[3][0]*sinq3 - 4*(double)1.066*(double)4.79*ddq[2]*pdis[3][0]*sinq3 - 2*(double)1.066*(double)4.79*ddq[3]*pdis[3][0]*sinq3 + 4*(double)1.066*(double)4.79*dq[1]*dq[3]*pdis[3][1]*sinq3 + 4*(double)1.066*(double)4.79*dq[2]*dq[3]*pdis[3][1]*sinq3 + 2*(double)1.066*(double)4.79*(dq[3])*(dq[3])*pdis[3][1]*sinq3 - 4*(double)1.066*Mfive*dq[1]*dq[3]*pdis[4][2]*sinq3 - 4*(double)1.066*Mfive*dq[2]*dq[3]*pdis[4][2]*sinq3 - 2*(double)1.066*Mfive*(dq[3])*(dq[3])*pdis[4][2]*sinq3 - 2*(double)1.0*(double)4.79*ddq[1]*pdis[3][0]*sin23 - 2*(double)1.0*(double)4.79*(dq[1])*(dq[1])*pdis[3][1]*sin23 + 2*(double)1.0*Mfive*(dq[1])*(dq[1])*pdis[4][2]*sin23 + 2*cosq4*((dq[4])*(dq[4])*I[4][0][2] + ddq[4]*(I[4][1][2] - Mfive*pdis[4][1]*((double)1.066*cosq3 + pdis[4][2])) + Mfive*(-(pdis[4][0]*(9.81*cos123 + (dq[4])*(dq[4])*pdis[4][2])) + (double)1.066*(-(cosq3*(dq[3]*(2*(dq[1] + dq[2]) + dq[3]) + (dq[4])*(dq[4]))*pdis[4][0]) + (-((2*(ddq[1] + ddq[2]) + ddq[3])*pdis[4][0]) + 2*(dq[1] + dq[2] + dq[3])*dq[4]*pdis[4][1])*sinq3) + (double)1.0*pdis[4][0]*(cos23*(dq[1])*(dq[1]) - ddq[1]*sin23))) + 2*9.81*(double)4.79*pdis[3][1]*sin123 - 2*9.81*Mfive*pdis[4][2]*sin123 + 2*(ddq[4]*I[4][0][2] - (dq[4])*(dq[4])*I[4][1][2] + Mfive*(-(ddq[4]*pdis[4][0]*pdis[4][2]) + pdis[4][1]*(9.81*cos123 + (dq[4])*(dq[4])*pdis[4][2]) + (double)1.066*(cosq3*(-(ddq[4]*pdis[4][0]) + (dq[3]*(2*(dq[1] + dq[2]) + dq[3]) + (dq[4])*(dq[4]))*pdis[4][1]) + (2*(dq[1] + dq[2] + dq[3])*dq[4]*pdis[4][0] + (2*(ddq[1] + ddq[2]) + ddq[3])*pdis[4][1])*sinq3) + (double)1.0*pdis[4][1]*(-(cos23*(dq[1])*(dq[1])) + ddq[1]*sin23)))*sinq4 + ((ddq[1] + ddq[2] + ddq[3])*(I[4][0][1] + I[4][1][0]) + 2*dq[1]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1]))) + 2*dq[2]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1]))) + 2*(-(Mfive*(ddq[1] + ddq[2] + ddq[3])*pdis[4][0]*pdis[4][1]) + dq[3]*dq[4]*(I[4][0][0] - I[4][1][1] + Mfive*(-(pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1])))))*sin2q4)/2.;
 taus[3]=(2*(ddq[1] + ddq[2] + ddq[3])*I[3][2][2] + ddq[1]*I[4][0][0] - cos2q4*ddq[1]*I[4][0][0] + ddq[2]*I[4][0][0] - cos2q4*ddq[2]*I[4][0][0] + ddq[3]*I[4][0][0] - cos2q4*ddq[3]*I[4][0][0] + 2*cos2q4*dq[1]*dq[4]*I[4][0][1] + 2*cos2q4*dq[2]*dq[4]*I[4][0][1] + 2*cos2q4*dq[3]*dq[4]*I[4][0][1] + 2*cosq4*(dq[4])*(dq[4])*I[4][0][2] + 2*cos2q4*dq[1]*dq[4]*I[4][1][0] + 2*cos2q4*dq[2]*dq[4]*I[4][1][0] + 2*cos2q4*dq[3]*dq[4]*I[4][1][0] + ddq[1]*I[4][1][1] + cos2q4*ddq[1]*I[4][1][1] + ddq[2]*I[4][1][1] + cos2q4*ddq[2]*I[4][1][1] + ddq[3]*I[4][1][1] + cos2q4*ddq[3]*I[4][1][1] + 2*(double)4.79*(-(9.81*cos123*pdis[3][0]) + (ddq[1] + ddq[2] + ddq[3])*((pdis[3][0])*(pdis[3][0]) + (pdis[3][1])*(pdis[3][1])) + (double)1.066*(cosq3*((dq[1] + dq[2])*(dq[1] + dq[2])*pdis[3][0] - (ddq[1] + ddq[2])*pdis[3][1]) - ((ddq[1] + ddq[2])*pdis[3][0] + (dq[1] + dq[2])*(dq[1] + dq[2])*pdis[3][1])*sinq3) + (double)1.0*(-(ddq[1]*(cos23*pdis[3][1] + pdis[3][0]*sin23)) + (dq[1])*(dq[1])*(cos23*pdis[3][0] - pdis[3][1]*sin23)) + 9.81*pdis[3][1]*sin123) - 2*(dq[4])*(dq[4])*I[4][1][2]*sinq4 + 2*ddq[4]*(cosq4*I[4][1][2] + I[4][0][2]*sinq4) + 2*dq[1]*dq[4]*I[4][0][0]*sin2q4 + 2*dq[2]*dq[4]*I[4][0][0]*sin2q4 + 2*dq[3]*dq[4]*I[4][0][0]*sin2q4 + ddq[1]*I[4][0][1]*sin2q4 + ddq[2]*I[4][0][1]*sin2q4 + ddq[3]*I[4][0][1]*sin2q4 + ddq[1]*I[4][1][0]*sin2q4 + ddq[2]*I[4][1][0]*sin2q4 + ddq[3]*I[4][1][0]*sin2q4 - 2*dq[1]*dq[4]*I[4][1][1]*sin2q4 - 2*dq[2]*dq[4]*I[4][1][1]*sin2q4 - 2*dq[3]*dq[4]*I[4][1][1]*sin2q4 + Mfive*(ddq[1]*(pdis[4][0])*(pdis[4][0]) + ddq[2]*(pdis[4][0])*(pdis[4][0]) + ddq[3]*(pdis[4][0])*(pdis[4][0]) + ddq[1]*(pdis[4][1])*(pdis[4][1]) + ddq[2]*(pdis[4][1])*(pdis[4][1]) + ddq[3]*(pdis[4][1])*(pdis[4][1]) + cos2q4*(ddq[1]*(pdis[4][0])*(pdis[4][0]) + ddq[2]*(pdis[4][0])*(pdis[4][0]) - 4*dq[1]*dq[4]*pdis[4][0]*pdis[4][1] - 4*dq[2]*dq[4]*pdis[4][0]*pdis[4][1] - 4*dq[3]*dq[4]*pdis[4][0]*pdis[4][1] - ddq[1]*(pdis[4][1])*(pdis[4][1]) - ddq[2]*(pdis[4][1])*(pdis[4][1]) + ddq[3]*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1]))) + 2*(double)1.066*cosq3*ddq[1]*pdis[4][2] + 2*(double)1.0*cos23*ddq[1]*pdis[4][2] + 2*(double)1.066*cosq3*ddq[2]*pdis[4][2] + 2*ddq[1]*(pdis[4][2])*(pdis[4][2]) + 2*ddq[2]*(pdis[4][2])*(pdis[4][2]) + 2*ddq[3]*(pdis[4][2])*(pdis[4][2]) + 2*(double)1.066*(dq[1])*(dq[1])*pdis[4][2]*sinq3 + 4*(double)1.066*dq[1]*dq[2]*pdis[4][2]*sinq3 + 2*(double)1.066*(dq[2])*(dq[2])*pdis[4][2]*sinq3 + 2*(double)1.0*(dq[1])*(dq[1])*pdis[4][2]*sin23 + 2*cosq4*(-(ddq[4]*pdis[4][1]*pdis[4][2]) - pdis[4][0]*(9.81*cos123 + (dq[4])*(dq[4])*pdis[4][2] + (double)1.066*(-(cosq3*(dq[1] + dq[2])*(dq[1] + dq[2])) + (ddq[1] + ddq[2])*sinq3) + (double)1.0*(-(cos23*(dq[1])*(dq[1])) + ddq[1]*sin23))) - 2*9.81*pdis[4][2]*sin123 + 2*(-(ddq[4]*pdis[4][0]*pdis[4][2]) + pdis[4][1]*(9.81*cos123 + (dq[4])*(dq[4])*pdis[4][2] + (double)1.066*(-(cosq3*(dq[1] + dq[2])*(dq[1] + dq[2])) + (ddq[1] + ddq[2])*sinq3) + (double)1.0*(-(cos23*(dq[1])*(dq[1])) + ddq[1]*sin23)))*sinq4 - 2*(dq[3]*dq[4]*(pdis[4][0])*(pdis[4][0]) + ddq[1]*pdis[4][0]*pdis[4][1] + ddq[2]*pdis[4][0]*pdis[4][1] + ddq[3]*pdis[4][0]*pdis[4][1] - dq[3]*dq[4]*(pdis[4][1])*(pdis[4][1]) + dq[1]*dq[4]*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1])) + dq[2]*dq[4]*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1])))*sin2q4))/2.;
 taus[4]=-((cosq4)*(cosq4)*(dq[2])*(dq[2])*I[4][0][1]) - 2*(cosq4)*(cosq4)*dq[2]*dq[3]*I[4][0][1] - (cosq4)*(cosq4)*(dq[3])*(dq[3])*I[4][0][1] - cosq4*dq[2]*dq[4]*I[4][0][2] - cosq4*dq[3]*dq[4]*I[4][0][2] + cosq4*dq[2]*dq[4]*I[4][2][0] + cosq4*dq[3]*dq[4]*I[4][2][0] + cosq4*ddq[1]*I[4][2][1] + cosq4*ddq[2]*I[4][2][1] + cosq4*ddq[3]*I[4][2][1] + ddq[4]*I[4][2][2] + cosq4*(dq[2])*(dq[2])*I[4][1][1]*sinq4 + cosq4*(dq[3])*(dq[3])*I[4][1][1]*sinq4 + dq[2]*dq[4]*I[4][1][2]*sinq4 + dq[3]*dq[4]*I[4][1][2]*sinq4 + ddq[1]*I[4][2][0]*sinq4 + ddq[2]*I[4][2][0]*sinq4 + ddq[3]*I[4][2][0]*sinq4 - dq[2]*dq[4]*I[4][2][1]*sinq4 - dq[3]*dq[4]*I[4][2][1]*sinq4 + (dq[2])*(dq[2])*I[4][1][0]*(sinq4)*(sinq4) + 2*dq[2]*dq[3]*I[4][1][0]*(sinq4)*(sinq4) + (dq[3])*(dq[3])*I[4][1][0]*(sinq4)*(sinq4) - ((dq[2])*(dq[2])*I[4][0][0]*sin2q4)/2. - dq[2]*dq[3]*I[4][0][0]*sin2q4 - ((dq[3])*(dq[3])*I[4][0][0]*sin2q4)/2. + dq[2]*dq[3]*I[4][1][1]*sin2q4 + (dq[1])*(dq[1])*(-((cosq4)*(cosq4)*I[4][0][1]) + cosq4*I[4][1][1]*sinq4 + I[4][1][0]*(sinq4)*(sinq4) - (I[4][0][0]*sin2q4)/2.) + (Mfive*(2*cos2q4*(dq[1] + dq[2] + dq[3])*(dq[1] + dq[2] + dq[3])*pdis[4][0]*pdis[4][1] + 2*ddq[4]*((pdis[4][0])*(pdis[4][0]) + (pdis[4][1])*(pdis[4][1])) - 2*cosq4*(-(ddq[0]*pdis[4][0]) + pdis[4][1]*((ddq[1] + ddq[2] + ddq[3])*pdis[4][2] + (double)1.066*(cosq3*(ddq[1] + ddq[2]) + (dq[1] + dq[2])*(dq[1] + dq[2])*sinq3) + (double)1.0*(cos23*ddq[1] + (dq[1])*(dq[1])*sin23)) - 9.81*pdis[4][1]*sin123) - 2*(ddq[0]*pdis[4][1] + pdis[4][0]*((ddq[1] + ddq[2] + ddq[3])*pdis[4][2] + (double)1.066*(cosq3*(ddq[1] + ddq[2]) + (dq[1] + dq[2])*(dq[1] + dq[2])*sinq3) + (double)1.0*(cos23*ddq[1] + (dq[1])*(dq[1])*sin23)) - 9.81*pdis[4][0]*sin123)*sinq4 + (dq[1] + dq[2] + dq[3])*(dq[1] + dq[2] + dq[3])*((pdis[4][0])*(pdis[4][0]) - (pdis[4][1])*(pdis[4][1]))*sin2q4))/2. + dq[1]*(dq[4]*(cosq4*(-I[4][0][2] + I[4][2][0]) + (I[4][1][2] - I[4][2][1])*sinq4) + (dq[2] + dq[3])*(-2*(cosq4)*(cosq4)*I[4][0][1] + 2*I[4][1][0]*(sinq4)*(sinq4) + (-I[4][0][0] + I[4][1][1])*sin2q4));
}

# 1 "fric.c" 1
double fric[5][5]={
   { 0.00015891, 0.10000000, 3.41491170, 9.18429206, 0.00007442}
, { 0.00162252, 0.09998517,206.16327766, 5.62676130,41.76878819}
, { 0.00000000, 0.09999736,120.35649902,57.78186171, 0.00048924}
, { 0.00003541, 0.10000000,28.62822202,72.07546863, 0.29839841}
, { 0.00000136, 0.09999998,25.95103770,21.19265881, 0.00000147}
};
# 30 "tau.c" 2

double sgn(double a) {
  if (a<-0.00001)
  return -1;
  else if (a>0.00001)
  return 1;
 else
  return 0;
}

double tau(int n) {
 return taus[n]+sgn(dq[n])*(fric[n][0]*exp(-fabs(dq[n]/fric[n][1]))+fric[n][2]+fabs(dq[n])*fric[n][3])+fric[n][4]*ddq[n];
}
# 498 "dynomads.c" 2
