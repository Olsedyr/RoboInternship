# 1 "cmd.c"
# 1 "/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "cmd.c"







# 1 "/usr/include/pthread.h" 1 3 4
# 23 "/usr/include/pthread.h" 3 4
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
# 24 "/usr/include/pthread.h" 2 3 4
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
# 25 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/sched.h" 1 3 4
# 26 "/usr/include/sched.h" 3 4
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
# 27 "/usr/include/sched.h" 2 3 4


# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 30 "/usr/include/sched.h" 2 3 4


# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
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
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
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





typedef __pid_t pid_t;








extern clock_t clock (void) __attribute__ ((__nothrow__));


extern time_t time (time_t *__timer) __attribute__ ((__nothrow__));


extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__)) __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));





extern size_t strftime (char *__restrict __s, size_t __maxsize,
   __const char *__restrict __format,
   __const struct tm *__restrict __tp) __attribute__ ((__nothrow__));

# 215 "/usr/include/time.h" 3 4
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
# 216 "/usr/include/time.h" 2 3 4

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
# 24 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 34 "/usr/include/signal.h" 2 3 4
# 50 "/usr/include/signal.h" 3 4
typedef __sigset_t sigset_t;
# 408 "/usr/include/signal.h" 3 4

# 30 "/usr/include/pthread.h" 2 3 4
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
# 31 "/usr/include/pthread.h" 2 3 4
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

# 9 "cmd.c" 2
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

# 10 "cmd.c" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
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
# 105 "/usr/include/sys/types.h" 3 4
typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
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
# 220 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 23 "/usr/include/bits/select.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/select.h" 2 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 35 "/usr/include/sys/select.h" 2 3 4
# 46 "/usr/include/sys/select.h" 3 4
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
# 273 "/usr/include/sys/types.h" 3 4

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

# 11 "cmd.c" 2
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

# 164 "/usr/include/string.h" 3 4
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

# 12 "cmd.c" 2
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

# 13 "cmd.c" 2
# 1 "/usr/include/sys/times.h" 1 3 4
# 32 "/usr/include/sys/times.h" 3 4



struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;

    clock_t tms_cutime;
    clock_t tms_cstime;
  };






extern clock_t times (struct tms *__buffer) __attribute__ ((__nothrow__));


# 14 "cmd.c" 2
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4

# 175 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 176 "/usr/include/unistd.h" 2 3 4
# 199 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 200 "/usr/include/unistd.h" 2 3 4
# 228 "/usr/include/unistd.h" 3 4
typedef __useconds_t useconds_t;
# 240 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 260 "/usr/include/unistd.h" 3 4
extern int access (__const char *__name, int __type) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 277 "/usr/include/unistd.h" 3 4
extern int faccessat (int __fd, __const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;
# 303 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__));
# 322 "/usr/include/unistd.h" 3 4
extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;





extern ssize_t write (int __fd, __const void *__buf, size_t __n) ;
# 386 "/usr/include/unistd.h" 3 4
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__)) ;
# 401 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__));
# 413 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__));






extern int usleep (__useconds_t __useconds);
# 437 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__)) ;




extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;






extern int fchownat (int __fd, __const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;



extern int chdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int fchdir (int __fd) __attribute__ ((__nothrow__)) ;
# 479 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__)) ;
# 492 "/usr/include/unistd.h" 3 4
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;




extern int dup (int __fd) __attribute__ ((__nothrow__)) ;


extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__));
# 510 "/usr/include/unistd.h" 3 4
extern char **__environ;







extern int execve (__const char *__path, char *__const __argv[],
     char *__const __envp[]) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     __attribute__ ((__nothrow__));




extern int execv (__const char *__path, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execle (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execl (__const char *__path, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int execvp (__const char *__file, char *__const __argv[])
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int execlp (__const char *__file, __const char *__arg, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




extern int nice (int __inc) __attribute__ ((__nothrow__)) ;




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/bits/confname.h" 1 3 4
# 26 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG,


    _SC_LEVEL1_ICACHE_SIZE,

    _SC_LEVEL1_ICACHE_ASSOC,

    _SC_LEVEL1_ICACHE_LINESIZE,

    _SC_LEVEL1_DCACHE_SIZE,

    _SC_LEVEL1_DCACHE_ASSOC,

    _SC_LEVEL1_DCACHE_LINESIZE,

    _SC_LEVEL2_CACHE_SIZE,

    _SC_LEVEL2_CACHE_ASSOC,

    _SC_LEVEL2_CACHE_LINESIZE,

    _SC_LEVEL3_CACHE_SIZE,

    _SC_LEVEL3_CACHE_ASSOC,

    _SC_LEVEL3_CACHE_LINESIZE,

    _SC_LEVEL4_CACHE_SIZE,

    _SC_LEVEL4_CACHE_ASSOC,

    _SC_LEVEL4_CACHE_LINESIZE,



    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,

    _SC_RAW_SOCKETS,


    _SC_V7_ILP32_OFF32,

    _SC_V7_ILP32_OFFBIG,

    _SC_V7_LP64_OFF64,

    _SC_V7_LPBIG_OFFBIG,


    _SC_SS_REPL_MAX,


    _SC_TRACE_EVENT_NAME_MAX,

    _SC_TRACE_NAME_MAX,

    _SC_TRACE_SYS_MAX,

    _SC_TRACE_USER_EVENT_MAX,


    _SC_XOPEN_STREAMS,


    _SC_THREAD_ROBUST_PRIO_INHERIT,

    _SC_THREAD_ROBUST_PRIO_PROTECT,

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,



    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_V5_WIDTH_RESTRICTED_ENVS,



    _CS_V7_WIDTH_RESTRICTED_ENVS,



    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFF32_LIBS,

    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V7_LP64_OFF64_CFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V7_LP64_OFF64_LIBS,

    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS

  };
# 569 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (__const char *__path, int __name)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__));


extern long int sysconf (int __name) __attribute__ ((__nothrow__));



extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__));




extern __pid_t getpid (void) __attribute__ ((__nothrow__));


extern __pid_t getppid (void) __attribute__ ((__nothrow__));




extern __pid_t getpgrp (void) __attribute__ ((__nothrow__));
# 605 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__));
# 614 "/usr/include/unistd.h" 3 4
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__));
# 631 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) __attribute__ ((__nothrow__));
# 648 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) __attribute__ ((__nothrow__));







extern __uid_t getuid (void) __attribute__ ((__nothrow__));


extern __uid_t geteuid (void) __attribute__ ((__nothrow__));


extern __gid_t getgid (void) __attribute__ ((__nothrow__));


extern __gid_t getegid (void) __attribute__ ((__nothrow__));




extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__)) ;
# 681 "/usr/include/unistd.h" 3 4
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__));




extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__));




extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__));






extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__));




extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__));




extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__));
# 737 "/usr/include/unistd.h" 3 4
extern __pid_t fork (void) __attribute__ ((__nothrow__));






extern __pid_t vfork (void) __attribute__ ((__nothrow__));





extern char *ttyname (int __fd) __attribute__ ((__nothrow__));



extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2))) ;



extern int isatty (int __fd) __attribute__ ((__nothrow__));





extern int ttyslot (void) __attribute__ ((__nothrow__));




extern int link (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int linkat (int __fromfd, __const char *__from, int __tofd,
     __const char *__to, int __flags)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4))) ;




extern int symlink (__const char *__from, __const char *__to)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern ssize_t readlink (__const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2))) ;




extern int symlinkat (__const char *__from, int __tofd,
        __const char *__to) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3))) ;


extern ssize_t readlinkat (int __fd, __const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3))) ;



extern int unlink (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern int unlinkat (int __fd, __const char *__name, int __flag)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));



extern int rmdir (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));



extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__));


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__));






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));




extern int setlogin (__const char *__name) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
# 851 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 59 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 73 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 152 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__));
# 852 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));






extern int sethostname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern int sethostid (long int __id) __attribute__ ((__nothrow__)) ;





extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (__const char *__name, size_t __len)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;





extern int vhangup (void) __attribute__ ((__nothrow__));


extern int revoke (__const char *__file) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





extern int acct (__const char *__name) __attribute__ ((__nothrow__));



extern char *getusershell (void) __attribute__ ((__nothrow__));
extern void endusershell (void) __attribute__ ((__nothrow__));
extern void setusershell (void) __attribute__ ((__nothrow__));





extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__)) ;






extern int chroot (__const char *__path) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;



extern char *getpass (__const char *__prompt) __attribute__ ((__nonnull__ (1)));
# 937 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);






extern long int gethostid (void);


extern void sync (void) __attribute__ ((__nothrow__));




extern int getpagesize (void) __attribute__ ((__nothrow__)) __attribute__ ((__const__));




extern int getdtablesize (void) __attribute__ ((__nothrow__));




extern int truncate (__const char *__file, __off_t __length)
     __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1))) ;
# 984 "/usr/include/unistd.h" 3 4
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__)) ;
# 1004 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) __attribute__ ((__nothrow__)) ;





extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__));
# 1025 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__));
# 1048 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len) ;
# 1079 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes);
# 1117 "/usr/include/unistd.h" 3 4

# 15 "cmd.c" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4

# 48 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3 4
extern __const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
extern __const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__)) __attribute__ ((__const));
# 96 "/usr/include/ctype.h" 3 4






extern int isalnum (int) __attribute__ ((__nothrow__));
extern int isalpha (int) __attribute__ ((__nothrow__));
extern int iscntrl (int) __attribute__ ((__nothrow__));
extern int isdigit (int) __attribute__ ((__nothrow__));
extern int islower (int) __attribute__ ((__nothrow__));
extern int isgraph (int) __attribute__ ((__nothrow__));
extern int isprint (int) __attribute__ ((__nothrow__));
extern int ispunct (int) __attribute__ ((__nothrow__));
extern int isspace (int) __attribute__ ((__nothrow__));
extern int isupper (int) __attribute__ ((__nothrow__));
extern int isxdigit (int) __attribute__ ((__nothrow__));



extern int tolower (int __c) __attribute__ ((__nothrow__));


extern int toupper (int __c) __attribute__ ((__nothrow__));








extern int isblank (int) __attribute__ ((__nothrow__));


# 142 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__));



extern int toascii (int __c) __attribute__ ((__nothrow__));



extern int _toupper (int) __attribute__ ((__nothrow__));
extern int _tolower (int) __attribute__ ((__nothrow__));
# 247 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__));

extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__));



extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));


extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__));
# 323 "/usr/include/ctype.h" 3 4

# 16 "cmd.c" 2
# 1 "cmd.h" 1





# 1 "tmpnrobot.h" 1
# 9 "tmpnrobot.h"
# 1 "/usr/include/sys/time.h" 1 3 4
# 29 "/usr/include/sys/time.h" 3 4
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
# 7 "cmd.h" 2
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
# 17 "cmd.c" 2
# 1 "logger.h" 1



int logMsg(char *s);
int logStatus(char *s);
# 18 "cmd.c" 2

tmpnRSSystem rs_param=
{
 "plantname"
  ,"workcellname"
 ,"location"
  ,"robotname"
  ,"192.168.0.150"
  ,"192.168.0.250"
  ,"eth0"
  ,"scriptname"
  ,305
  ,0
  ,{
   0
  ,0
  ,0
  ,0
  ,0
  ,0
  ,"/dev/ttyS0"
  }
  ,""
  ,0
  ,0
  ,0
  ,0
 ,0
  ,10
  ,""
  ,""
  ,0
  ,1
  ,"formStdRun"
  ,1
  ,0
  ,1299
  ,1
};


extern int getFotoFriMM(void);
int demo=0;

char rs_systempath[256]="";
char rs_systemini[256]="";
static char databasePath[256];
long defpathspeed = 100000;
int defpathsamprate = 10;


TABLESPACE tspace=
{
  {{{0,0,0,0,0,0,1,30000,100000000,100000000,1,10,1},{},{},{}}}
};
volatile int roboState = 5;
float speedFactor = 0.5;

tmpnJoints m_actuator;
pthread_mutex_t actuator_mutex = { { 0, 0, 0, 0, 0, { 0 } } };
volatile int jogikscreen=0;
volatile unsigned int mposupdatecount=0;

pthread_cond_t script_cond = { { 0, 0, 0, 0, 0, (void *) 0, 0, 0 } };
pthread_mutex_t script_mutex = { { 0, 0, 0, 0, 0, { 0 } } };

pthread_cond_t upload_cond = { { 0, 0, 0, 0, 0, (void *) 0, 0, 0 } };
pthread_mutex_t upload_mtx = { { 0, 0, 0, 0, 0, { 0 } } };

pthread_cond_t uploaddone_cond = { { 0, 0, 0, 0, 0, (void *) 0, 0, 0 } };
pthread_mutex_t uploaddone_mtx = { { 0, 0, 0, 0, 0, { 0 } } };

int getMachineStateIdx(const char *machinename, const char *statename);
int getMachineTypeIdx(const char *name);

static POINTSTRUCT pdummy = {{0.0,0.0,0.0,0.0,0.0}
                            ,{0.0,0.0,0.0,0.0,0.0}
                            ,{0.0,0.0,0.0,0.0,0.0},0,((void *)0)};

tmpnMacro mpnmacro[]={
 {"testpallet",(1+100)}
 ,{"getpallet",(5+100)}
 ,{"savenextpath",(6+100)}
 ,{"runsavedpath",(7+100)}
 ,{"clearsavedpath",(17+100)}
 ,{"setio",(13+100)}
 ,{"getio",(14+100)}
};

tmpnVector *bagendpoint=((void *)0);




static void freeCommandData(COMMANDSTRUCT *dcmd)
{
  switch(dcmd->type)
  {
    case 39: free((ELSESTRUCT*)dcmd->data); break;
    case 1: free((SADSSTRUCT*)dcmd->data); break;
    case 2: free((MOVEABSSTRUCT*)dcmd->data); break;
    case 21: free((GOTOSTRUCT*)dcmd->data); break;
    case 20: free((PPSCRIPTSTRUCT*)dcmd->data); break;
    case 7: free((WSPSTRUCT*)dcmd->data); break;
    case 8: free((OUTPUTSTRUCT*)dcmd->data); break;
    case 9: free((INPUTSTRUCT*)dcmd->data); break;
    case 12: free((NAMESTRUCT*)dcmd->data); break;
    case 18: free((MOVEAXISSTRUCT*)dcmd->data); break;
    case 6: free((CANCELAXISSTRUCT*)dcmd->data); break;

    case 25: free((SPLINEHINTSTRUCT*)dcmd->data); break;
    case 23: free((STATEHINTSTRUCT*)dcmd->data); break;
    case 26: free((POSITIONHINTSTRUCT*)dcmd->data); break;
    case 4:



         free((PATHSTRUCT*)dcmd->data);
        break;
    case 11: free((NAMESTRUCT*)dcmd->data); break;
    case 19: free((MACROSTRUCT*)dcmd->data); break;
    case 13: free((CALLSTRUCT*)dcmd->data); break;
    case 46: free((RESETPRELOADSTRUCT*)dcmd->data); break;
    case 16: free((LABELSTRUCT*)dcmd->data); break;
    case 17: free((JUMPLAYERSTRUCT*)dcmd->data); break;
    case 24: free((SCOPESTRUCT*)dcmd->data); break;
    case 10: free((POINTSTRUCT*)dcmd->data); break;
    case 14: free((POINTSTRUCT*)dcmd->data); break;
    case 22: free((POINTSTRUCT*)dcmd->data); break;
    case 27: free((POINTSTRUCT*)dcmd->data); break;
    case 28: free((POINTSTRUCT*)dcmd->data); break;
    case 32: free((SLEEPSTRUCT*)dcmd->data); break;
    case 3: free((EVENTSTRUCT*)dcmd->data); break;
    case 31: free((EVENTSTRUCT*)dcmd->data); break;
    case 5: free((EVENTSTRUCT*)dcmd->data); break;
    case 29: free((COUNTERSTRUCT*)dcmd->data); break;
    case 30: free((TUNINGSTRUCT*)dcmd->data); break;
    case 48: free((SETSPEEDSTRUCT*)dcmd->data); break;
    case 15: free((NAMESTRUCT*)dcmd->data); break;
    case 47: free((ERRORSTRUCT*)dcmd->data); break;
    case 41: free((TESTSTRUCT*)dcmd->data); break;
    case 43: free((TESTSTRUCT*)dcmd->data); break;
    case 44: free((TESTSTRUCT*)dcmd->data); break;
   case 42: free((TESTSTRUCT*)dcmd->data); break;
    case 33: free((SETSTRUCT*)dcmd->data); break;
    case 34: free((SETSTATESTRUCT*)dcmd->data); break;
    case 35: free((TIMEOUTSTRUCT*)dcmd->data); break;
    case 37: free((SUBTSTRUCT*)dcmd->data); break;
    case 36: free((ADDSTRUCT*)dcmd->data); break;
    case 49: free((MULSTRUCT*)dcmd->data); break;
    case 50: free((DIVSTRUCT*)dcmd->data); break;
    case 51: free((CALCSTRUCT*)dcmd->data); break;
    case 54: free((LOADSTRUCT*)dcmd->data); break;
    case 55: free((EXECSTRUCT*)dcmd->data); break;
   case 56: free((SETFRAMESTRUCT*)dcmd->data); break;
   case 57: free((SETITEMSTRUCT*)dcmd->data); break;
   case 59: free((ROBOTSPEEDSTRUCT*)dcmd->data); break;
  }
}

static COMMANDSTRUCT *__localAddCommand(int type)
{
  COMMANDSTRUCT *cmd=((void *)0);
  ROOTSTRUCT *root=((void *)0);
  ELSESTRUCT *elses=((void *)0);
  SPLINEHINTSTRUCT *splinehint=((void *)0);
  MOVEAXISSTRUCT *moveaxis=((void *)0);
  CANCELAXISSTRUCT *cancelaxis=((void *)0);
  STATEHINTSTRUCT *statehint=((void *)0);
  POSITIONHINTSTRUCT *positionhint=((void *)0);
  SADSSTRUCT *dps=((void *)0);
  MOVEABSSTRUCT *mas=((void *)0);
  PATHSTRUCT *path=((void *)0);
  WSPSTRUCT *wsp=((void *)0);
  OUTPUTSTRUCT *out=((void *)0);
  INPUTSTRUCT *in=((void *)0);
  POINTSTRUCT *point=((void *)0);
  NAMESTRUCT *sub=((void *)0);
  MACROSTRUCT *macro=((void *)0);
  CALLSTRUCT *call=((void *)0);
  RESETPRELOADSTRUCT *resetpreload=((void *)0);
  LABELSTRUCT *label=((void *)0);
  JUMPLAYERSTRUCT *jumplayer=((void *)0);
  EVENTSTRUCT *event=((void *)0);
  SLEEPSTRUCT *sleep=((void *)0);
  COUNTERSTRUCT *counter=((void *)0);
  TUNINGSTRUCT *tuning=((void *)0);
  SETSPEEDSTRUCT *setspeed=((void *)0);
  SCOPESTRUCT *scope=((void *)0);
  GOTOSTRUCT *go=((void *)0);
  PPSCRIPTSTRUCT *ppscript=((void *)0);
  TESTSTRUCT *test=((void *)0);
 SETSTRUCT *set=((void *)0);
  SETSTATESTRUCT *setstate=((void *)0);
  TIMEOUTSTRUCT *timeout=((void *)0);
  SUBTSTRUCT *subt=((void *)0);
  ADDSTRUCT *add=((void *)0);
  MULSTRUCT *mul=((void *)0);
  CALCSTRUCT *calg=((void *)0);
  DIVSTRUCT *div=((void *)0);
  ERRORSTRUCT *error=((void *)0);
  LOADSTRUCT *load=((void *)0);
  EXECSTRUCT *exec=((void *)0);
  SETFRAMESTRUCT *setframe=((void *)0);
 SETITEMSTRUCT *setitem=((void *)0);
 ROBOTSPEEDSTRUCT *robotspeed=((void *)0);


  cmd = (COMMANDSTRUCT*)malloc(sizeof(COMMANDSTRUCT));
  if(cmd==((void *)0))
    return ((void *)0);

  cmd->type = type;
  cmd->next = ((void *)0);
  cmd->prev = ((void *)0);
  cmd->flag = 0;
  cmd->listitem = ((void *)0);
  cmd->include = 0;

  switch(type)
  {
    case 38:
      root = (ROOTSTRUCT*)malloc(sizeof(ROOTSTRUCT));
      if(root==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)root;
      break;
    case 39:
      elses = (ELSESTRUCT*)malloc(sizeof(ELSESTRUCT));
      if(elses==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)elses;
      break;
    case 1:
      dps = (SADSSTRUCT*)malloc(sizeof(SADSSTRUCT));
      if(dps==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)dps;
      break;
    case 25:
      splinehint = (SPLINEHINTSTRUCT*)malloc(sizeof(SPLINEHINTSTRUCT));
      if(splinehint==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)splinehint;
      break;
    case 18:
      moveaxis = (MOVEAXISSTRUCT*)malloc(sizeof(MOVEAXISSTRUCT));
      if(moveaxis==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)moveaxis;
      break;
    case 6:
      cancelaxis = (CANCELAXISSTRUCT*)malloc(sizeof(CANCELAXISSTRUCT));
      if(cancelaxis==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)cancelaxis;
      break;
    case 23:
      statehint = (STATEHINTSTRUCT*)malloc(sizeof(STATEHINTSTRUCT));
      if(statehint==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)statehint;
      break;
    case 26:
      positionhint = (POSITIONHINTSTRUCT*)malloc(sizeof(POSITIONHINTSTRUCT));
      if(positionhint==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)positionhint;
      break;
    case 2:
      mas = (MOVEABSSTRUCT*)malloc(sizeof(MOVEABSSTRUCT));
      if(mas==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)mas;
      break;
    case 4:
      path = (PATHSTRUCT*)malloc(sizeof(PATHSTRUCT));
      if(path==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      path->tpathdef.maxidx=0;
      path->tpathdef.maxhidx=0;
      path->tpathdef.maxpidx=0;
      path->tpathdef.id = 0;
      path->tpathdef.idx = -1;
      path->firstpoint=cmd;
      cmd->data = (void*)path;
      break;
    case 19:
      macro = (MACROSTRUCT*)malloc(sizeof(MACROSTRUCT));
      if(macro==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(macro, 0, sizeof(MACROSTRUCT));
      cmd->data = (void*)macro;
      break;
    case 46:
      resetpreload = (RESETPRELOADSTRUCT*)malloc(sizeof(RESETPRELOADSTRUCT));
      if(resetpreload==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(resetpreload, 0, sizeof(RESETPRELOADSTRUCT));
      cmd->data = (void*)resetpreload;
      break;
    case 13:
      call = (CALLSTRUCT*)malloc(sizeof(CALLSTRUCT));
      if(call==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(call, 0, sizeof(CALLSTRUCT));
      cmd->data = (void*)call;
      break;
    case 16:
      label = (LABELSTRUCT*)malloc(sizeof(LABELSTRUCT));
      if(label==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(label, 0, sizeof(LABELSTRUCT));
      cmd->data = (void*)label;
      break;
    case 17:
      jumplayer = (JUMPLAYERSTRUCT*)malloc(sizeof(JUMPLAYERSTRUCT));
      if(jumplayer==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(jumplayer, 0, sizeof(JUMPLAYERSTRUCT));
      cmd->data = (void*)jumplayer;
      break;
    case 24:
      scope = (SCOPESTRUCT*)malloc(sizeof(SCOPESTRUCT));
      if(scope==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(scope, 0, sizeof(SCOPESTRUCT));
      cmd->data = (void*)scope;
      break;
    case 21:
      go = (GOTOSTRUCT*)malloc(sizeof(GOTOSTRUCT));
      if(go==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(go, 0, sizeof(GOTOSTRUCT));
      cmd->data = (void*)go;
      break;
    case 20:
      ppscript = (PPSCRIPTSTRUCT*)malloc(sizeof(PPSCRIPTSTRUCT));
      if(ppscript==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(ppscript, 0, sizeof(PPSCRIPTSTRUCT));
      cmd->data = (void*)ppscript;
      break;
    case 7:
      wsp = (WSPSTRUCT*)malloc(sizeof(WSPSTRUCT));
      if(wsp==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)wsp;
      break;
    case 8:
      out = (OUTPUTSTRUCT*)malloc(sizeof(OUTPUTSTRUCT));
      if(out==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)out;
      break;
    case 9:
      in = (INPUTSTRUCT*)malloc(sizeof(INPUTSTRUCT));
      if(in==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)in;
      break;
    case 11:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)sub;
      break;
    case 12:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)sub;
      break;
    case 10:
    case 14:
    case 22:
    case 27:
    case 28:
      point = (POINTSTRUCT*)malloc(sizeof(POINTSTRUCT));
      if(point==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      memset(point, 0, sizeof(POINTSTRUCT));
      cmd->data = (void*)point;
      break;
    case 31:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)event;
      break;
    case 32:
      sleep = (SLEEPSTRUCT*)malloc(sizeof(SLEEPSTRUCT));
      if(sleep==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)sleep;
      break;
    case 3:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)event;
      break;
    case 29:
      counter = (COUNTERSTRUCT*)malloc(sizeof(COUNTERSTRUCT));
      if(counter==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)counter;
      break;
    case 30:
      tuning = (TUNINGSTRUCT*)malloc(sizeof(TUNINGSTRUCT));
      if(tuning==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)tuning;
      break;
    case 48:
      setspeed = (SETSPEEDSTRUCT*)malloc(sizeof(SETSPEEDSTRUCT));
      if(setspeed==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)setspeed;
      break;
    case 5:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)event;
      break;
    case 15:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)sub;
      break;
    case 47:
      error = (ERRORSTRUCT*)malloc(sizeof(ERRORSTRUCT));
      if(error==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)error;
      break;
    case 56:
      setframe = (SETFRAMESTRUCT*)malloc(sizeof(SETFRAMESTRUCT));
      if(setframe==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)setframe;
      break;
   case 57:
      setitem = (SETITEMSTRUCT*)malloc(sizeof(SETITEMSTRUCT));
      if(setitem==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)setitem;
      break;
   case 59:
      robotspeed = (ROBOTSPEEDSTRUCT*)malloc(sizeof(ROBOTSPEEDSTRUCT));
      if(robotspeed==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)robotspeed;
      break;
    case 55:
      exec = (EXECSTRUCT*)malloc(sizeof(LOADSTRUCT));
      if(exec==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)exec;
      break;
    case 54:
      load = (LOADSTRUCT*)malloc(sizeof(LOADSTRUCT));
      if(load==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)load;
      break;
    case 41:
   case 42:
    case 43:
    case 44:
      test = (TESTSTRUCT*)malloc(sizeof(TESTSTRUCT));
      if(test==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)test;
      break;
    case 33:
      set = (SETSTRUCT*)malloc(sizeof(SETSTRUCT));
      if(set==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)set;
      break;
    case 34:
      setstate = (SETSTATESTRUCT*)malloc(sizeof(SETSTATESTRUCT));
      if(setstate==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)setstate;
      break;
    case 35:
      timeout = (TIMEOUTSTRUCT*)malloc(sizeof(TIMEOUTSTRUCT));
      if(timeout==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)timeout;
      break;
    case 37:
      subt = (SUBTSTRUCT*)malloc(sizeof(SUBTSTRUCT));
      if(subt==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)subt;
      break;
   case 51:
      calg = (CALCSTRUCT*)malloc(sizeof(CALCSTRUCT));
      if(calg==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)calg;
      break;
   case 49:
      mul = (MULSTRUCT*)malloc(sizeof(MULSTRUCT));
      if(mul==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)mul;
      break;
   case 50:
      div = (DIVSTRUCT*)malloc(sizeof(DIVSTRUCT));
      if(div==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)div;
      break;
   case 36:
      add = (ADDSTRUCT*)malloc(sizeof(ADDSTRUCT));
      if(add==((void *)0))
      {
        free (cmd);
        return ((void *)0);
      }
      cmd->data = (void*)add;
      break;
 }
  return cmd;
}



void RemoveAllCommands(COMMANDSTRUCT **root)
{
  COMMANDSTRUCT *cmd, *dcmd;

  if(root==((void *)0)) return;
  cmd=*root;
  while(cmd)
  {
    dcmd = cmd;
    cmd = cmd->next;
    freeCommandData(dcmd);
    free(dcmd);
  }
  *root = ((void *)0);
}




static void __deleteCommand(COMMANDSTRUCT *currentcmd)
{
  COMMANDSTRUCT *dcmd = currentcmd;

  if(dcmd == ((void *)0))
    return;


  freeCommandData(dcmd);
  if(dcmd->prev)
    dcmd->prev->next = dcmd->next;
  if(dcmd->next)
    dcmd->next->prev = dcmd->prev;
# 731 "cmd.c"
  free(dcmd);
}

void deleteCommand(COMMANDSTRUCT *levelcmd)
{
  COMMANDSTRUCT *cmd = levelcmd->next, *dcmd;

  while(cmd && cmd->flag > levelcmd->flag)
  {
    dcmd = cmd;
    cmd = cmd->next;
    __deleteCommand(dcmd);
  }
  __deleteCommand(levelcmd);
}
# 768 "cmd.c"
COMMANDSTRUCT *InsertCommand(COMMANDSTRUCT *ptrcmd, int type)
{
  COMMANDSTRUCT *cmd;

  cmd = __localAddCommand(type);
  if(ptrcmd==((void *)0)) return cmd;

  cmd->prev = ptrcmd;
  cmd->next = ptrcmd->next;
  ptrcmd->next = cmd;
  if(cmd->next!=((void *)0))
    cmd->next->prev=cmd;
  return cmd;
}

COMMANDSTRUCT *getParentCommand(COMMANDSTRUCT *cmd)
{
  COMMANDSTRUCT *parent;

  for(parent=cmd->prev;parent!=((void *)0)&&parent->flag>=cmd->flag;parent=parent->prev);
  return parent;
}

COMMANDSTRUCT *getPreviusCommand(COMMANDSTRUCT *cmd)
{
  COMMANDSTRUCT *previus;

  previus=cmd->prev;
  if(previus!=((void *)0)&&previus->flag<cmd->flag)
  {
    previus=((void *)0);
  }
  else
  {
    for(previus=cmd->prev;previus!=((void *)0)&&previus->flag!=cmd->flag;previus=previus->prev);
  }
  return previus;
}

int SaveCommandScript(COMMANDSTRUCT *root, const char *filename)
{
  FILE *fp;
  COMMANDSTRUCT *cmd;
  char str[256];
  int prevlevel=0,l;

  if(root==((void *)0)) return 0;
  fp = fopen(filename,"w");
  if(fp==((void *)0))
    return 0;

  fprintf(fp,"VERSION %d\n", 2);
  cmd=root->next;
  while(cmd)
  {
    getCommandString(str,cmd);
    for(l=prevlevel;l>cmd->flag;l--)
    {
        fprintf(fp,"END\n");
    }
    fprintf(fp,"%s\n",str);
    prevlevel=cmd->flag;
    cmd = cmd->next;
  }
  for(l=prevlevel;l>0;l--)
  {
      fprintf(fp,"END\n");
  }
  fclose(fp);
  return 1;
}

int tmpnPatternLoad(const char *filename, tmpnPattern *pattern)
{
  FILE *fp;
  int version;
  char buffer[256];
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"PATTERNVERSION %d\n",&version);
  if(version!=2) return 0;
  fscanf(fp,"%s\n",pattern->name);
  pattern->maxidx=0;
  strcpy(pattern->filename,filename);
  pattern->width=800.0;
  pattern->length=1200.0;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"width=",6)==0)
    {
      sscanf(buffer,"width=%f\n",&pattern->width);
    }
    else if(strncmp(buffer,"length=",7)==0)
    {
      sscanf(buffer,"length=%f\n",&pattern->length);
    }
    else if(strncmp(buffer,"layer=",6)==0)
    {
      int layer; float x,y,z,v,w,u;
      sscanf(buffer,"layer=%d,wcp=%f,%f,%f,%f,%f,%f\n",&layer,&x,&y,&z,&v,&w,&u);
      pattern->item[pattern->maxidx].layer = layer;
      pattern->item[pattern->maxidx].wcp.x = x;
      pattern->item[pattern->maxidx].wcp.y = y;
      pattern->item[pattern->maxidx].wcp.z = z;
      pattern->item[pattern->maxidx].wcp.v = v;
      pattern->item[pattern->maxidx].wcp.w = w;
      pattern->item[pattern->maxidx].wcp.u = u;
      pattern->maxidx++;
    }
  }
  fclose(fp);
 printf("Loaded pattern %s %s\n",pattern->name,pattern->filename);
  return 1;
}

int tmpnPatternSave(tmpnPattern *pattern)
{
  FILE *fp;
  int i;
  fp = fopen(pattern->filename,"w");
  if(fp==((void *)0)) return 0;
 fprintf(fp,"PATTERNVERSION %d\n",2);
 fprintf(fp,"%s\n",pattern->name);
 fprintf(fp,"width=%0.0f\n",pattern->width);
 fprintf(fp,"length=%0.0f\n",pattern->length);
 for(i=0;i<pattern->maxidx;i++)
 {
    fprintf(fp,"layer=%d,wcp=%0.0f,%0.0f,%0.0f,%0.0f,%0.0f,%0.0f\n"
        ,pattern->item[i].layer
        ,pattern->item[i].wcp.x
        ,pattern->item[i].wcp.y
        ,pattern->item[i].wcp.z
        ,pattern->item[i].wcp.v
        ,pattern->item[i].wcp.w
        ,pattern->item[i].wcp.u);
  }
  fclose(fp);
  return 1;
}

int tmpnCPPatternLoad(const char *filename, tmpnCPPatterns *cppatterns)
{
  FILE *fp;
  int version;
  char buffer[256];
  tmpnCPPattern *cppattern;
  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open CP pattern file: %s\n",filename);
    return 0;
  }
  fscanf(fp,"VERSION %d\n",&version);
  if(version>1)
  {
    printf("CP Pattern version mismatch. Detected version %d. Supports up to version %d\n",version,1);
    fclose(fp);
    exit(99);
  }
  if(cppatterns->maxidx==0)
    cppatterns->cppattern = (tmpnCPPattern*)malloc(sizeof(tmpnCPPattern));
  else
    cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx + 1));
  cppattern = &cppatterns->cppattern[cppatterns->maxidx++];
  fscanf(fp,"%s user=%d\n",cppattern->name,&cppattern->user);
  strcpy(cppattern->filename,filename);
  cppattern->selectedItem=0;
  cppattern->selectedPPP=0;
  cppattern->maxidx=0;

  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"layer=",6)==0)
    {
      int layer=0, maxpush=0, gettime=0, i;
      sscanf(buffer,"layer=%d maxpush=%d gettime=%d\n",&layer,&maxpush,&gettime);
      if(cppattern->maxidx==0)
        cppattern->items = (tmpnCPPatternItem*)malloc(sizeof(tmpnCPPatternItem));
      else
        cppattern->items = (tmpnCPPatternItem*)realloc(cppattern->items,sizeof(tmpnCPPatternItem)*(cppattern->maxidx + 1));
      tmpnCPPatternItem *item = &cppattern->items[cppattern->maxidx++];
      item->layer = layer;
      item->maxpush = maxpush;
      item->gettime = gettime;
      item->ppps = (int*)malloc(sizeof(int)*maxpush);
      item->paccs = (int*)malloc(sizeof(int)*maxpush);
      item->pspeeds = (int*)malloc(sizeof(int)*maxpush);
      for(i=0;i<maxpush;i++)
      {
        if(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
        {
          if(strncmp(buffer,"ppp=",4)==0)
          {
            int ppp = 0, pacc=100, pspeed=100;
            sscanf(buffer,"ppp=%d pacc=%d pspeed=%d\n",&ppp,&pacc,&pspeed);
            item->ppps[i] = ppp;
            item->paccs[i] = pacc;
            item->pspeeds[i] = pspeed;
          }
          else
          {
            char str[256];
            int j;
            sscanf(buffer,"%s",str);
            printf("Error loading CP Pattern '%s' Got '%s', expected ppp.\n",cppattern->name,str);


            for(j=0;j<cppattern->maxidx;j++)
            {
              free(cppattern->items[j].ppps);
              free(cppattern->items[j].paccs);
              free(cppattern->items[j].pspeeds);
            }
            free(cppattern->items);
            cppatterns->maxidx--;
            cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
            fclose(fp);
            return 0;
          }
        }
        else
        {
          int j;
          printf("Error loading CP Pattern '%s' Got EOF, expected ppp\n",cppattern->name);
          for(j=0;j<cppattern->maxidx;j++)
          {
              free(cppattern->items[j].ppps);
              free(cppattern->items[j].paccs);
              free(cppattern->items[j].pspeeds);
          }
          free(cppattern->items);
          cppatterns->maxidx--;
          cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
          fclose(fp);
          return 0;
        }
      }
    }
    else
    {
      char str[256];
      int j;
      sscanf(buffer,"%s",str);
      printf("Error loading CP Pattern '%s' Got '%s', expected layer\n",cppattern->name,str);
      for(j=0;j<cppattern->maxidx;j++)
      {
          free(cppattern->items[j].ppps);
          free(cppattern->items[j].paccs);
          free(cppattern->items[j].pspeeds);
      }
      free(cppattern->items);
      cppatterns->maxidx--;
      cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
      fclose(fp);
      return 0;
    }
  }
  fclose(fp);
  printf("Loaded CP pattern %s %s\n",cppattern->name,cppattern->filename);
  return 1;
}

int tmpnCPPatternSave(tmpnCPPattern *cppattern)
{
  FILE *fp;
  int i;
  if(cppattern->user == 0)
  {
    printf("Couldn't save CP Pattern file: %s, user=0\n",cppattern->filename);
    return 0;
  }
  fp = fopen(cppattern->filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open CP pattern file: %s\n",cppattern->filename);
    return 0;
  }
 fprintf(fp,"VERSION %d\n",1);
 fprintf(fp,"%s user=%d\n",cppattern->name,cppattern->user);
  int j;
  for(i=0;i<cppattern->maxidx;i++){
    fprintf(fp,"layer=%d maxpush=%d gettime=%d\n",cppattern->items[i].layer,cppattern->items[i].maxpush,cppattern->items[i].gettime);
    for(j=0;j<cppattern->items[i].maxpush;j++){
      fprintf(fp,"ppp=%d pacc=%d pspeed=%d\n",cppattern->items[i].ppps[j],cppattern->items[i].paccs[j],cppattern->items[i].pspeeds[j]);
    }
  }
  fclose(fp);
  return 1;
}

void *getValueFunction(char *n)
{
  return ((void *)0);
}
void copyFramesFromSTMtoRobot(void)
{
  int i,idx;
 tmpnStateMachineValue *stmval;
  trobot->m_frames.maxidx=0;
  if ((idx=getMachineIdx("Frames")) != -1)
  {
    for(i=0;i<tworkcell->statemachines.statemachine[idx].numvalue;i++)
    {
     stmval=&tworkcell->statemachines.statemachine[idx].value[i];
     {
      if (stmval->type==25)
      {
           strcpy(((tmpnRobot*)trobot)->m_frames.frame[trobot->m_frames.maxidx].name,stmval->frame->name);
           trobot->m_frames.frame[trobot->m_frames.maxidx].x=stmval->frame->x;
           trobot->m_frames.frame[trobot->m_frames.maxidx].y=stmval->frame->y;
           trobot->m_frames.frame[trobot->m_frames.maxidx].z=stmval->frame->z;
           trobot->m_frames.frame[trobot->m_frames.maxidx].v=stmval->frame->v;
           trobot->m_frames.frame[trobot->m_frames.maxidx].w=stmval->frame->w;
           trobot->m_frames.frame[trobot->m_frames.maxidx].u=stmval->frame->u;
           trobot->m_frames.maxidx++;
        }
      }
   }
  }
}

void tmpnStateMachineReset(void)
{
  int i;

  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    tworkcell->statemachines.statemachine[i].type = -1;
    strcpy(tworkcell->statemachines.statemachine[i].name, "");
    tworkcell->statemachines.statemachine[i].istate = -1;
    tworkcell->statemachines.statemachine[i].next_istate = -1;
    tworkcell->statemachines.statemachine[i].new_istate = -1;
  tworkcell->statemachines.statemachine[i].timerstate = -1;
  tworkcell->statemachines.statemachine[i].debugvalue = ((void *)0);
    tworkcell->statemachines.statemachine[i].stop = 0;
    tworkcell->statemachines.statemachine[i].mcSignal = 0;
    pthread_cond_init(&tworkcell->statemachines.statemachine[i].change, ((void *)0));
    pthread_mutex_init(&tworkcell->statemachines.statemachine[i].change_mtx, ((void *)0));

    tworkcell->statemachines.statemachine[i].numstate=0;
    tworkcell->statemachines.statemachine[i].numvalue=0;
    tworkcell->statemachines.statemachine[i].numtimeout=0;
    tworkcell->statemachines.statemachine[i].numinput=0;
    tworkcell->statemachines.statemachine[i].numoutput=0;
    tworkcell->statemachines.statemachine[i].numlink=0;
 }
}

void dumpStatemachinePrg(tmpnStateMachine *stm, int stateidx);

void tmpnStateMachineDump(tmpnStateMachine *stm)
{
  int j;
  if(rs_param.statemachine_debug<=2) return;
  printf("=======================================\n");
  printf("STM=%s state=%d\n", stm->name, stm->istate);
  for(j=0;j<stm->numstate;j++)
  {
    printf("STM state %d: %s %d\n", j, stm->state[j].name, stm->state[j].statenum);
    if(rs_param.statemachine_debug>2)
      dumpStatemachinePrg(stm,j);
  }
  for(j=0;j<stm->numtimeout;j++)
  {
    printf("STM timeout %d: %s %d\n", j, stm->timeout[j].name, stm->timeout[j].timeout);
  }
  for(j=0;j<stm->numlink;j++)
  {
    printf("STM link %d: %s(%s) %d\n", j, stm->link[j].localname,stm->link[j].name, stm->link[j].stmidx);
  }
  for(j=0;j<stm->numvalue;j++)
  {
    if(stm->value[j].type==21)
  {
   if (stm->value[j].linkvalue!=((void *)0))
    printf("STM linkvalue %d: %s %s %s %d\n", j, stm->value[j].name,stm->value[j].linkname,stm->value[j].link, stm->value[j].linkvalue->data);
   else
    printf("STM linkvalue %d: %s %s %s (REMOTE = Not found yet)\n", j, stm->value[j].name,stm->value[j].linkname,stm->value[j].link);
  }
    else
      printf("STM value %d: %s %d\n", j, stm->value[j].name, stm->value[j].data);
  }
}

void error(int ln, char *e)
{
  printf("Error: line %d %s\n", ln, e);
  exit(1);
}

int getInputIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numinput;i++)
  {
    if(strcmp(stm->input[i].name, s)==0)
      return i;
  }

  return -1;
}

int getTimeoutIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numtimeout;i++)
  {
    if(strcmp(stm->timeout[i].name, s)==0)
      return i;
  }
  return -1;
}


int getOutputIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numoutput;i++)
  {
    if(strcmp(stm->output[i].name, s)==0)
      return i;
  }

  return -1;
}

tmpnFrame *getStmFrame(char *framename)
{
 int idx;
 tmpnStateMachineValue *stmval;
 if ((idx=getMachineIdx("Frames")) != -1)
 {
  if ((stmval=getMachineValue(idx,framename)) != ((void *)0))
  {
   if (stmval->type==25)
   {
    return stmval->frame;
   }
  }
 }
 return ((void *)0);
}

tmpnStateMachineValue *getStmValue(tmpnStateMachine *stm, char *valuename)
{
  int i;
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i];
  }
  return ((void *)0);
}

tmpnStateMachineValue *getMachineValue(int machine, char *valuename)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return ((void *)0);
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i];
  }
  return ((void *)0);
}

int *getMachineValuePtr(int machine, char *valuename)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return ((void *)0);
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i].data;
  }
  return ((void *)0);
}

int getMachineVersion(int machine)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return 0;
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, "VERSION")==0)
      return stm->value[i].data;
  }
  return 0;
}

int getValueIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, s)==0)
      return i;
  }

  return -1;
}

int getLinkIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numlink;i++)
  {
    if(strcmp(stm->link[i].localname, s)==0)
      return i;
  }
  return -1;
}

int findSTMIdx(tmpnStateMachine *stm, char *s)
{
 int sidx=-1,i;

 for(i=0;i<stm->numlink;i++)
 {
  if (!strcmp(stm->link[i].localname,s))
  {
   sidx = getMachineIdx(stm->link[i].name);
   break;
  }
 }
 return sidx;
}

tmpnStateMachineValue *getLinkValue(tmpnStateMachine *stm, tmpnStateMachineValue *value)
{
 static int depth=0;
  tmpnStateMachineValue *linkvalue;
 tmpnStateMachineValue *tempvalue;
  int sidx,vidx;
 linkvalue=((void *)0);


  if(strlen(value->link)>0)
  {
    sidx = findSTMIdx(stm, value->link);
   if(sidx==-1)
    sidx = getMachineIdx(value->link);
  if(sidx!=-1)
    {
      vidx = getValueIdx(&tworkcell->statemachines.statemachine[sidx], value->linkname);
      if(vidx!=-1)
      {
        linkvalue = &tworkcell->statemachines.statemachine[sidx].value[vidx];
      }
    }
  }
  if(linkvalue!=((void *)0))
  {
    if(linkvalue->type==21)
    {
   if (linkvalue==value)
   {
    printf("linkValue \"%s\" in statemachine \"%s\" referered to one self which is Not Good (tm). Quitting\n",value->linkname,stm->name);
    exit(1);
   }
   if (depth>=100)
   {
    printf("linkValue (%s,%s) recursion depth==%i reached. You should probably check linkvalues for circular references. Quitting\n",stm->name,value->name,100);
    exit(1);
   }
   else
   {
    depth++;
   }
      tempvalue=getLinkValue(stm,linkvalue);
   if(tempvalue!=((void *)0))
    linkvalue=tempvalue;
    }
  }
 depth=0;
  return linkvalue;
}


void SetupSTMLink1(tmpnStateMachine *stm)
{
  int j, l;


  for(j=0;j<stm->numlink;j++)
  {
    stm->link[j].stmidx=-1;
    for(l=0;l<tworkcell->statemachines.maxidx;l++)
    {
      if(strcmp(stm->link[j].name, tworkcell->statemachines.statemachine[l].name)==0)
     {
    stm->link[j].stmidx = l;
    }
    }
  }
}


tmpnFrame *getPatternItem(tmpnPattern *p, int idx)
{
  return &p->item[idx].wcp;
}

void SetupSTMLink2(tmpnStateMachine *stm)
{
  int j, s,p;
 int tmpsubtype;
 ARGSTRUCT *arg;
 tmpnBoptCoeff* BoptCoeffs;

 BoptCoeffs = getBoptCoeff((tmpnWorkcell*)tworkcell);

  for(j=0;j<stm->numvalue;j++)
  {
    stm->value[j].linkvalue = ((void *)0);
    if(stm->value[j].type==21)
    {
      stm->value[j].linkvalue=getLinkValue(stm,&stm->value[j]);
      if(stm->value[j].linkvalue!=((void *)0))
       stm->value[j].subtype=stm->value[j].linkvalue->subtype;
    else
        printf("linkValue=%s in %s from %s is located on a remote host ?\n", stm->value[j].name,stm->name,stm->value[j].link);
    }
    else if(stm->value[j].type==24)
    {






    }
    else if(stm->value[j].type==27)
    {
      if ((stm->value[j].pattern = getPattern(stm->value[j].link,(tmpnWorkcell*)tworkcell)) != ((void *)0))
        stm->value[j].frame = &stm->value[j].pattern->item[0].wcp;
      else
        printf("unknown pattern: %s, machine=%s\n", stm->value[j].link, stm->name);
    }
    else if(stm->value[j].type==28)
    {
      if ((stm->value[j].cppattern = getCPPattern(stm->value[j].link,(tmpnWorkcell*)tworkcell)) == ((void *)0))
      {
        printf("Load of unknown CP Pattern: '%s' in statemachine=%s\n", stm->value[j].link, stm->name);
      }
    }
    else if(stm->value[j].type==26)
  {
      stm->value[j].item = getItem(stm->value[j].link,(tmpnWorkcell*)tworkcell);
   if (stm->value[j].item==((void *)0))
   {
    printf("Load of unknown item \"%s\" in statemachine=%s\n",stm->value[j].link, stm->name);
    exit(1);
   }
  }
  }
  for(s=0;s<stm->numstate;s++)
  {
    for(p=0;p<stm->state[s].maxprgidx;p++)
    {
      if(stm->state[s].prg[p].type == 34)
      {
        ((SETSTATESTRUCT*)stm->state[s].prg[p].data)->number = getMachineStateIdx(stm->name,((SETSTATESTRUCT*)stm->state[s].prg[p].data)->name);
        if(((SETSTATESTRUCT*)stm->state[s].prg[p].data)->number==-1)
        {
          printf("unknown setstate=%s, machine=%s\n",((SETSTATESTRUCT*)stm->state[s].prg[p].data)->name,stm->name);

        }
      }
      else if(stm->state[s].prg[p].type == 54)
      {
        LOADSTRUCT *load=(LOADSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,load->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==24) load->path = value->path;
        else
          printf("load of unknown path%s in statemachine=%s\n",load->dest, stm->name);

        for(value=getStmValue(stm,load->src1);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==25) load->fromFrame = value->frame;
        else
          printf("unknown fromFrame %s, machine=%s\n",load->src1, stm->name);

        for(value=getStmValue(stm,load->src2);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==25) load->toFrame = value->frame;
        else
          printf("unknown toFrame %s, machine=%s\n",load->src2, stm->name);
      }
      else if(stm->state[s].prg[p].type == 55)
      {
        EXECSTRUCT *exec=(EXECSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,exec->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==24)
          exec->path = value->path;
        else
          printf("exec of unknown path %s in statemachine=%s\n",exec->dest, stm->name);
      }
      else if(stm->state[s].prg[p].type == 56)
      {
        SETFRAMESTRUCT *setframe=(SETFRAMESTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setframe->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==25)
          setframe->destFrame = value->frame;
        else
          printf("unknown destination frame: %s, machine=%s\n", setframe->dest, stm->name);

        for(value=getStmValue(stm,setframe->src);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==25)
          setframe->srcFrame = value->frame;
        else if(value!=((void *)0)&&value->type==27)
          setframe->srcFrame = value->frame;
        else
          printf("unknown source frame: %s, machine=%s\n", setframe->src, stm->name);
      }
   else if(stm->state[s].prg[p].type == 57)
      {
        SETITEMSTRUCT *setitem=(SETITEMSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setitem->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==26)
          setitem->destItem = &value->item;
        else
          printf("unknown destination item: %s, machine=%s\n", setitem->dest, stm->name);

        for(value=getStmValue(stm,setitem->src);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==26)
          setitem->srcItem = value->item;
        else
          printf("unknown source item: %s, machine=%s\n", setitem->src, stm->name);
      }
   else if(stm->state[s].prg[p].type == 58)
      {
        SETPATTERNSTRUCT *setpattern=(SETPATTERNSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setpattern->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==27)
          setpattern->destPattern = &value->pattern;
        else
          printf("unknown destination pattern: %s, machine=%s\n", setpattern->dest, stm->name);

        for(value=getStmValue(stm,setpattern->src);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==27)
          setpattern->srcPattern = value->pattern;
        else
          printf("unknown source pattern: %s, machine=%s\n", setpattern->src, stm->name);

      }
      else if(stm->state[s].prg[p].type == 60)
      {
        SETCPPATTERNSTRUCT *setcppattern=(SETCPPATTERNSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setcppattern->dest);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==28)
          setcppattern->destCPPattern = &value->cppattern;
        else
          printf("unknown destination CP pattern: %s, machine=%s\n", setcppattern->dest, stm->name);

        for(value=getStmValue(stm,setcppattern->src);value!=((void *)0)&&value->type==21;value=value->linkvalue);
        if(value!=((void *)0)&&value->type==28)
          setcppattern->srcCPPattern = value->cppattern;
        else
          printf("unknown source CP pattern: %s, machine=%s\n", setcppattern->src, stm->name);
      }
      else if(stm->state[s].prg[p].type == 35)
      {
        if(strlen(((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename)>0)
        {
          ((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->number = getMachineStateIdx(stm->name,((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename);
          if(((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->number==-1)
          {
            printf("unknown timeout state=%s, machine=%s\n",((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename,stm->name);

          }
        }
      }
      else if((stm->state[s].prg[p].type == 41&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == 19)
              ||(stm->state[s].prg[p].type == 43&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == 19)
              ||(stm->state[s].prg[p].type == 42&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == 19)
              ||(stm->state[s].prg[p].type == 44&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == 19))
      {
    int stmidx;
    stmidx = findSTMIdx(stm, ((TESTSTRUCT*)stm->state[s].prg[p].data)->test.valstring);
    if (stmidx!=-1) ((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.number = getStateIdx(stmidx, ((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.valstring);
        if ((((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.number==-1)||stmidx==-1)
        {
          printf("stm->name %s unknown TEST state=%s, machine=%s\n"
         ,stm->name
         ,((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.valstring
         ,((TESTSTRUCT*)stm->state[s].prg[p].data)->test.valstring);
        }
      }
   else if(stm->state[s].prg[p].type == 41
              ||stm->state[s].prg[p].type == 43
              ||stm->state[s].prg[p].type == 42
              ||stm->state[s].prg[p].type == 44)
   {
    arg=&((TESTSTRUCT*)stm->state[s].prg[p].data)->test;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
    arg=&((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
   }
   else if(stm->state[s].prg[p].type == 59)
   {
    arg=&((ROBOTSPEEDSTRUCT*)stm->state[s].prg[p].data)->src;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
   }
   else if(stm->state[s].prg[p].type == 33)
   {
    arg=&((SETSTRUCT*)stm->state[s].prg[p].data)->src;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
    arg=&((SETSTRUCT*)stm->state[s].prg[p].data)->dest;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
   }
   else if(stm->state[s].prg[p].type == 51)
   {
    arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->dest;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
    arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->src1;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
    arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->src2;
    tmpsubtype=getArgSubType(stm, arg);
    if (tmpsubtype!=-1)
    {
     arg->subtype=tmpsubtype;
    }
   }

      else if (stm->state[s].prg[p].type == 39 || stm->state[s].prg[p].type == 45 || stm->state[s].prg[p].type == 53)
      {
      }
      else
      {
        printf("Unknown STM command (type %d) in %s -> %s\n", stm->state[s].prg[p].type, stm->name, stm->state[s].name);
      }
    }
  }
}

void freeState(tmpnStateMachineState *state)
{
  int l;
 for(l=0;l<state->maxprgidx;l++)
  {
    free(state->prg[l].data);
  }
 free(state->prg);
}

void deleteSTMPrg(tmpnStateMachine *statemachine)
{
  int i;
  for(i=0;i<statemachine->numstate;i++)
  {
    freeState(&statemachine->state[i]);
  }
 free(statemachine->state);
 free(statemachine->value);
 free(statemachine->timeout);
 free(statemachine->input);
 free(statemachine->output);
 free(statemachine->link);

  statemachine->type = -1;
  strcpy(statemachine->name, "");
  statemachine->istate = -1;
  statemachine->next_istate = -1;
  statemachine->new_istate = -1;
  statemachine->stop = 0;
  statemachine->mcSignal = 0;
  statemachine->delaystop = 0;
}

void printfIndex(int level )
{
  int i;

  for(i=0;i<level*2;i++)
    printf(" ");
}

void dumpStatemachinePrg(tmpnStateMachine *stm, int stateidx)
{
  int i, level=0;

  printf("State=%s\n", stm->state[stateidx].name);
  for(i=0;i<=stm->state[stateidx].maxprgidx;i++)
  {
    printf("%3d ", i);
    switch(stm->state[stateidx].prg[i].type)
    {
      case 41 :
        printfIndex(level);
        printf("TEST level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
        ,stm->state[stateidx].prg[i].level
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
        );
    level++;
      break;
    case 42 :
        printfIndex(level - 1);
        printf("ELSETEST level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
        ,stm->state[stateidx].prg[i].level
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.number
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
        );
    break;
      case 43 :
        printfIndex(level - 1);
        printf("OR level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
        ,stm->state[stateidx].prg[i].level
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
        );
    break;
      case 44 :
        printfIndex(level - 1);
        printf("AND level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
        ,stm->state[stateidx].prg[i].level
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
        ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
        );
      break;
      case 34 :
        printfIndex(level);
        printf("SETSTATE %s\n",
          ((SETSTATESTRUCT*)stm->state[stateidx].prg[i].data)->name
          );
      break;
      case 54:
        printfIndex(level);
        printf("LOAD %s %s %s\n",
          ((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->src1
         ,((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->src2
          );
      break;
      case 55:
        printfIndex(level);
        printf("EXEC %s\n",
          ((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->dest
          );
      break;
      case 56 :
        printfIndex(level);
        printf("SETFRAME %s %s\n",
          ((SETFRAMESTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((SETFRAMESTRUCT*)stm->state[stateidx].prg[i].data)->src
          );
      break;
      case 57 :
        printfIndex(level);
        printf("SETITEM %s %s\n",
          ((SETITEMSTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((SETITEMSTRUCT*)stm->state[stateidx].prg[i].data)->src
          );
      break;
    case 59 :
        printfIndex(level);
        printf("ROBOTSPEED %d %d\n"
        ,((ROBOTSPEEDSTRUCT*)stm->state[stateidx].prg[i].data)->src.type
        ,((ROBOTSPEEDSTRUCT*)stm->state[stateidx].prg[i].data)->src.idx
        );
    break;
      case 53 :
        printfIndex(level);
        printf("PRINT %s (%d,%d,%d)\n"
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.valstring
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.type
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.idx
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.number
          );
      break;
      case 35 :
        printfIndex(level);
        printf("TIMEOUT %d %d\n",
          ((TIMEOUTSTRUCT*)stm->state[stateidx].prg[i].data)->idx
          ,((TIMEOUTSTRUCT*)stm->state[stateidx].prg[i].data)->number
          );
      break;
      case 33 :
        printfIndex(level);
        printf("SET %d %d %d %d %d\n",
          ((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.type

          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.idx
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->src.type
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->src.idx
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.number
          );
      break;
    case 51:
    printfIndex(level);
    printf("CALC %d %d %d %d %d %d %d %d\n",
        ((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.type
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.idx
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->optype
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src1.type
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src1.idx
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src2.type
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src2.idx
        ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.number
        );
    break;
      case 39 :
        printfIndex(level - 1);
        printf("ELSE level %d %d\n"
        ,stm->state[stateidx].prg[i].level
        ,((ELSESTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
        );
      break;
      case 45 :
        level--;
        printfIndex(level);
        printf("ENDTEST level %d \n",stm->state[stateidx].prg[i].level);
      break;
      case 40 :
        printfIndex(level);
        printf("END \n");
      break;
      default:
        printf("type=%d unknown in stm=%s state=%s prg=%d\n",stm->state[stateidx].prg[i].type,stm->name,stm->state[stateidx].name,i);
        break;
    }
  }
}

static int ln=0;

void SetLevelJmp(tmpnStateMachineState * stm, int idx)
{
  int i;
  int level = stm->prg[idx].level;
  int firstnontestidx=-1;
  int elseidx = -1;
 int oridx=-1;
 int elsetestidx=-1;
  for(i=idx;i>=0;i--)
  {
    if(level == stm->prg[i].level)
    {
      switch(stm->prg[i].type)
      {
   case 39 :
    ((ELSESTRUCT*)stm->prg[i].data)->doneIdx = idx + 1;
    elseidx = i;
    break;
   case 42 :
   case 41 :
   case 43 :
   case 44 :
    ((TESTSTRUCT*)stm->prg[i].data)->doneIdx = idx + 1;
    if (firstnontestidx==-1) firstnontestidx=i+1;
    if (stm->prg[i + 1].type == 43)
    {
     ((TESTSTRUCT*)stm->prg[i].data)->trueIdx = firstnontestidx;
     ((TESTSTRUCT*)stm->prg[i].data)->falseIdx = i + 1;
    }
    else
    {
     ((TESTSTRUCT*)stm->prg[i].data)->trueIdx = i + 1;
     if (oridx > -1)
     {
      ((TESTSTRUCT*)stm->prg[i].data)->falseIdx = oridx;
     }
     else if (elsetestidx > -1)
     {
      ((TESTSTRUCT*)stm->prg[i].data)->falseIdx = elsetestidx;
     }
     else if(elseidx > -1)
      ((TESTSTRUCT*)stm->prg[i].data)->falseIdx = elseidx + 1;
     else
      ((TESTSTRUCT*)stm->prg[i].data)->falseIdx = idx + 1;
    }
     if (stm->prg[i].type == 43) oridx = i;
    else if (stm->prg[i].type == 42) {
     elsetestidx = i;
     firstnontestidx=-1;
     oridx=-1;
    }
    else if (stm->prg[i].type == 41) return;
        break;
      }
    }
  }
}


void setConnectValue(tmpnConnect *connect, unsigned short value)
{
  if(connect==((void *)0)) return;
  *connect->udata &= ~(connect->mask<<connect->shift);
  *connect->udata |= ((value&connect->mask)<<connect->shift);
}

void setConnectValueSigned(tmpnConnect *connect, short value)
{
  if(connect==((void *)0)) return;
  *connect->sdata = value;
}

void setConnectValueUnSigned(tmpnConnect *connect, unsigned short value)
{
  if(connect==((void *)0)) return;
  *connect->udata = value;
}

unsigned short getConnectValue(tmpnConnect *connect)
{
  unsigned short ret=0;
  if(connect==((void *)0)) return 0;
  if(connect->shift==0)
  {
    ret=((*connect->udata)&connect->mask);
  }
  else
  {
    ret=(((*connect->udata)>>connect->shift)&connect->mask);
  }
  return ret;
}

short getConnectValueSigned(tmpnConnect *connect)
{
  short ret=0;
  if(connect==((void *)0)) return 0;
  if(connect->shift==0)
  {
    ret=*connect->sdata;
  }
  else
  {
    printf("error: shift != 0 in getConnectValueSigned\n");
    exit(99);
  }
  return ret;
}
unsigned short getConnectValueUnSigned(tmpnConnect *connect)
{
  unsigned short ret=0;
  if(connect==((void *)0)) return 0;
  if(connect->shift==0)
  {
    ret=*connect->udata;
  }
  else
  {
    printf("error: shift != 0 in getConnectValueUnSigned\n");
    exit(99);
  }
  return ret;
}

void setConnectValueInt(tmpnConnect *connect, int value)
{
  if(connect->connectType==7)
    setConnectValueSigned(connect,value);
  else if(connect->connectType==5)
    setConnectValueUnSigned(connect,value);
  else
    setConnectValue(connect,value);
}

int getConnectValueInt(tmpnConnect *connect)
{
  if(connect->connectType==6||connect->connectType==7)
    return getConnectValueSigned(connect);
  else if(connect->connectType==4||connect->connectType==5)
    return getConnectValueUnSigned(connect);
  else
    return getConnectValue(connect);
}

void printArgValue(tmpnStateMachineValue * val)
{
  if(val->type==18||val->type==17)
  {
    if(val->subtype==0)
      printf("PRINT VALUE: %s=%d",val->name,val->data);
    else
      printf("PRINT VALUE: %s=%0.4f",val->name,val->fdata);
  }
  else if(val->type==21)
  {
  if (val->linkvalue!=((void *)0))
  {
   printArgValue(val->linkvalue);
  }
  else
  {
   if (val->remote!=((void *)0)&&val->remote->remotehost!=((void *)0))
   {
    if(val->remote->subtype==0)
     printf("PRINT VALUE: %s=%d",val->remote->name,val->remote->data);
    else
     printf("PRINT VALUE: %s=%0.4f",val->remote->name,val->remote->fdata);
   }
  }
  }
  else if(val->type==22)
  {
    if(val->subtype==0)
    {
      printf("PRINT TABLE: %s=%d curtablesize=%d sum=%d sumcnt=%d maxidx=%d min=%d max=%d topidx=%d topsearchwidth=%d topval=%f"
        ,val->name
        ,val->data
        ,val->table->curtablesize
        ,val->table->sum
        ,val->table->sumcnt
        ,val->table->maxidx
        ,val->table->min
        ,val->table->max
        ,val->table->topidx
        ,val->table->topsearchwidth
        ,val->table->topval
        );
    }
    else
    {
      printf("PRINT TABLE: %s=%f curtablesize=%d sum=%f sumcnt=%d maxidx=%d min=%f max=%f topidx=%d topsearchwidth=%d topval=%f"
        ,val->name
        ,val->fdata
        ,val->table->curtablesize
        ,val->table->fsum
        ,val->table->sumcnt
        ,val->table->maxidx
        ,val->table->fmin
        ,val->table->fmax
        ,val->table->topidx
        ,val->table->topsearchwidth
        ,val->table->topval
        );
    }
  }
  else if(val->type==27)
  {
    printf("PRINT PATTERN: %s %s layer=%d wcp.x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f u=%3.2f",val->name,val->link
                        ,val->pattern->item[0].layer
                        ,val->pattern->item[0].wcp.x
                        ,val->pattern->item[0].wcp.y
                        ,val->pattern->item[0].wcp.z
                        ,val->pattern->item[0].wcp.v
                        ,val->pattern->item[0].wcp.w
                        ,val->pattern->item[0].wcp.u
                        );
  }
  else if(val->type==28)
  {
    int i,j;
    printf("PRINT CPPATTERN: %s %s\n",val->name,val->link);
    for(i=0;i<val->cppattern->maxidx;i++)
    {
      printf("layer=%d maxpush=%d gettime=%d ",val->cppattern->items[i].layer,val->cppattern->items[i].maxpush,val->cppattern->items[i].gettime);
      for(j=0;j<val->cppattern->items[i].maxpush;j++)
      {
        printf("ppp=%d pacc=%d pspeed=%d",val->cppattern->items[i].ppps[j], val->cppattern->items[i].paccs[j], val->cppattern->items[i].pspeeds[j]);
      }
      printf("\n");
    }
  }
  else if(val->type==26)
  {
    printf("PRINT ITEM: %s %s type=%s name=%s dim.x=%3.2f y=%3.2f z=%3.2f sy=%3.2f gy=%3.2f my=%3.2f gx=%3.2f weight=%3.2f",val->name,val->link
                        ,val->item->type
                        ,val->item->name
                        ,val->item->dim.x
                        ,val->item->dim.y
                        ,val->item->dim.z
                        ,val->item->sy
                        ,val->item->gy
                        ,val->item->my
                        ,val->item->gx
                        ,val->item->weight
                        );
  }
  else if(val->type==25)
  {
    printf("PRINT FRAME: %s %s  x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f"
    ,val->name,val->frame->name,val->frame->x,val->frame->y,val->frame->z,val->frame->v,val->frame->w);
  }
  else if(val->type==24)
  {
    printf("PRINT PATHHANDLE: %s state=%d mode=%d type=%d\n",val->name,val->path->state,val->path->key.mode,val->path->key.type);
    printf("PRINT ----''----: from=%s(%d,%d) x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f\n"
          ,val->path->key.from.frame.name
          ,val->path->key.from.cItem
          ,val->path->key.from.cLayer
          ,val->path->key.from.frame.x
          ,val->path->key.from.frame.y
          ,val->path->key.from.frame.z
          ,val->path->key.from.frame.v
          ,val->path->key.from.frame.w);
    printf("PRINT ----''----: to=%s(%d,%d) x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f"
          ,val->path->key.to.frame.name
          ,val->path->key.to.cItem
          ,val->path->key.to.cLayer
          ,val->path->key.to.frame.x
          ,val->path->key.to.frame.y
          ,val->path->key.to.frame.z
          ,val->path->key.to.frame.v
          ,val->path->key.to.frame.w);
  }
}

void printArg(tmpnStateMachine * stm, ARGSTRUCT *arg, int newline)
{
  static struct timeval currentTime;
  static struct timeval startTime;
  static int firsttime = 1;
  if(firsttime==1)
  {
    firsttime=0;
    gettimeofday(&startTime, ((void *)0));
  }
  gettimeofday(&currentTime, ((void *)0));
  printf("%05ld:%03ld ",currentTime.tv_sec-startTime.tv_sec, currentTime.tv_usec/1000);

  switch(arg->type)
 {
 case 20:
  printf("PRINT NUMBER: %d",arg->number);
  break;
 case 18:
  printArgValue(&stm->value[arg->idx]);
  break;
 case 2:
 case 4:
 case 6:
  printf("PRINT INPUT: %s=%d (\"%s\",\"%s\",\"%s\")"
      ,stm->input[arg->idx].name
      ,getConnectValueInt(stm->input[arg->idx].connect)
      ,stm->input[arg->idx].connect->name
      ,stm->input[arg->idx].connect->key
      ,stm->input[arg->idx].connect->text);
  break;
 case 3:
 case 5:
 case 7:
  printf("PRINT OUTPUT: %s=%d (\"%s\",\"%s\",\"%s\")"
      ,stm->output[arg->idx].name
      ,getConnectValueInt(stm->output[arg->idx].connect)
      ,stm->output[arg->idx].connect->name
      ,stm->output[arg->idx].connect->key
      ,stm->output[arg->idx].connect->text);
  break;
 case 35:
  printf("PRINT TIMEOUT: %s=%d",stm->timeout[arg->idx].name,stm->timeout[arg->idx].timeout);
  break;
 default:
  break;
 }
  if(newline) printf("\n");
}

int findDot(char *s)
{
  int i=0;
  while(s[i]!=0)
  {
    if(s[i]=='.') return i;
    i++;
  }
  return -1;
}

int splitArg(char *s, char *s1, char *s2)
{
  int i,j,x;

  strcpy(s1,s);
  s2[0]=0;
  x=findDot(s);
  if(x>=0)
  {
    s1[x]=0;
    i=x+1;
    j=0;
    while(s[i]!=0)
    {
      s2[j++]=s[i++];
    }
    s2[j]=0;
  }
  return x;
}

char *getStateString(int idx)
{
  switch(idx)
  {
    case 1: return "ST_IDLE";
    case 2: return "ST_LOADED";
    case 3: return "ST_FINISHED";
    case 4: return "ST_ERROR";
    case 5: return "ST_INACTIVE";
    case 6: return "ST_LOAD";
    case 7: return "ST_EXEC";
    case 8: return "ST_BOPTING";
    case 9: return "ST_LOADING";
    case 10: return "ST_EXECUTING";
  }
  return "";
}

int getStateStringIdx(char *s)
{
  if(strcmp(s,"ST_IDLE")==0) return 1;
  if(strcmp(s,"ST_LOADED")==0) return 2;
  if(strcmp(s,"ST_FINISHED")==0) return 3;
  if(strcmp(s,"ST_ERROR")==0) return 4;
  if(strcmp(s,"ST_INACTIVE")==0) return 5;
  if(strcmp(s,"ST_LOAD")==0) return 6;
  if(strcmp(s,"ST_EXEC")==0) return 7;
  if(strcmp(s,"ST_BOPTING")==0) return 8;
  if(strcmp(s,"ST_LOADING")==0) return 9;
  if(strcmp(s,"ST_EXECUTING")==0) return 10;
  return 0;
}

int getCmpType(tmpnStateMachine *stm, char *s, int ln)
{
  int i,x;
  char s1[256];
  char s2[256];

  x = splitArg(s,s1,s2);

  for(i=0;i<stm->numinput;i++)
 {
  if (stm->input[i].iotype==16)
  {
   if(strcmp(stm->input[i].name, s1)==0)
    return stm->input[i].connect->connectType;
  }
  else if (stm->input[i].iotype==12)
  {
   if(strcmp(stm->input[i].name, s1)==0)
    return 12;
  }
  else if (stm->input[i].iotype==9)
  {
   if(strcmp(stm->input[i].name, s1)==0)
    return 9;
  }
  else if (stm->input[i].iotype==14)
  {
   if(strcmp(stm->input[i].name, s1)==0)
    return 14;
  }
  else if (stm->input[i].iotype==10)
  {
   if(strcmp(stm->input[i].name, s1)==0)
    return 10;
  }
  }
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, s1)==0)
    {
      return 18;
    }
  }
  for(i=0;i<stm->numoutput;i++)
  {
  if (stm->output[i].iotype==15)
  {
   if(strcmp(stm->output[i].name, s1)==0)
    return stm->output[i].connect->connectType;
  }
  else if (stm->output[i].iotype==8)
  {
   if(strcmp(stm->output[i].name, s1)==0)
    return 8;
  }
  else if (stm->output[i].iotype==13)
  {
   if(strcmp(stm->output[i].name, s1)==0)
    return 13;
  }
  else if (stm->output[i].iotype==11)
  {
   if(strcmp(stm->output[i].name, s1)==0)
    return 11;
  }
 }
  for(i=0;i<stm->numlink;i++)
  {
    if(strcmp(stm->link[i].localname, s1)==0) return 19;
  }
  for(i=0;i<stm->numtimeout;i++)
  {
    if(strcmp(stm->timeout[i].name, s1)==0) return 35;
  }
  if(x>=0)
  {
    if(atof(s)==0.0&&s[0]!='0')
    {
      char str1[255];
      sprintf(str1,"type not found (%s)",s);
      error(ln,str1);
    }
  }
  else
  {
    if(atoi(s)==0&&s[0]!='0')
    {
      if(getStateStringIdx(s)==0)
      {
        char str1[255];
        sprintf(str1,"type not found (%s)",s);
        error(ln,str1);
      }
    }
  }
  return 20;
}

int getValidationType(char *s)
{
  if(strcmp(s, "=")==0) return 1;
  if(strcmp(s, "!=")==0) return 2;
  if(strcmp(s, "<")==0) return 5;
  if(strcmp(s, "<=")==0) return 6;
  if(strcmp(s, ">")==0) return 3;
  if(strcmp(s, ">=")==0) return 4;
  return -1;

}

void getArgBody(tmpnStateMachine * stm, ARGSTRUCT *data, char arg[])
{
  int x;
  x=splitArg(arg,data->valstring,data->valstring2);
  data->subtype=0;
  if(data->type==20)
 {
    if(x>0)
    {
      data->idx = -1;
      data->subtype=1;
    data->fnumber = atof(arg);
    }
    else
    {
      data->idx = -1;
      data->subtype=0;
      data->number=getStateStringIdx(arg);
    if(data->number==0)
        data->number = atoi(arg);
    }
 }
 else if(data->type==18)
 {
  if((data->idx=getValueIdx(stm,data->valstring))==-1) error(ln, "Value Does not exist");
    data->subtype=stm->value[data->idx].subtype;
 }
 else if(data->type==2||data->type==4||data->type==6||data->type==9)
 {
  if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
 }
 else if (data->type==12)
 {
  if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
  data->subtype=1;
 }
 else if (data->type==14)
 {
  if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
  if (stm->input[data->idx].macconnect->type==2||stm->input[data->idx].macconnect->type==0||stm->input[data->idx].macconnect->type==1)
   data->subtype=0;
  else
   data->subtype=1;
 }
 else if (data->type==10)
 {
  if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
  data->subtype=0;
 }
 else if(data->type==3||data->type==5||data->type==7)
 {
  if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
 }
 else if (data->type==8)
 {
  if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
  data->subtype=1;
 }
 else if (data->type==13)
 {
  if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
  if (stm->output[data->idx].macconnect->type==2||stm->output[data->idx].macconnect->type==0||stm->output[data->idx].macconnect->type==1)
   data->subtype=0;
  else
   data->subtype=1;
 }
 else if (data->type==11)
 {
  if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
  data->subtype=0;
 }
 else if (data->type == 19)
 {

    strcpy(data->valstring,arg);
  data->number = atoi(arg);
 }
 else if (data->type == 35)
 {
  data->idx = getTimeoutIdx(stm,arg);
 }
 else
  error(ln,"testtype does not exist");
}

void setArgValueFloat(tmpnStateMachineValue *val, char *valstring2, float value)
{
  switch (val->type)
 {
  case 18:
 case 17:
  val->fdata=value;
  break;
 case 21:
    if(val->linkvalue==((void *)0))
    {
      val->fdata=value;
    }
    else
    {
      setArgValueFloat(val->linkvalue,valstring2,value);
    }
  break;
  case 22:
  {
   int i,maxf;
   tmpnStateMachineTable *tab;
   tab = val->table;
   if(!strcmp(valstring2,"newtablesize"))
   {
    tab->newtablesize=value;
    return;
   }
   if(!strcmp(valstring2,"topsearchwidth")){
    tab->topsearchwidth = value;
    return;
   }
   maxf=tab->newtablesize;

   if(tab->curtablesize!=maxf)
   {
    tab->curtablesize=maxf;
    tab->maxidx=0;
    tab->sum=0;
    tab->fsum=0.0;
    for(i=0;i<tab->maxsize;i++)
    {
     tab->item[i]=0;
     tab->fitem[i]=0.0;
    }
    tab->item[0]=0;
    tab->fitem[0]=0;
    tab->sumcnt=0;
    tab->topidx=0;
    tab->topval=0.0;
    tab->min=999999999;
    tab->max=-999999999;
    tab->fmin=999999999.0;
    tab->fmax=-999999999.0;
   }
   if(tab->maxidx>=maxf) tab->maxidx=0;
   if(tab->filter==1)
   {
    tab->fsum-=tab->fitem[tab->maxidx];
    tab->fitem[tab->maxidx++]=value;
    tab->fsum+=value;
    tab->sumcnt++;
    if(tab->sumcnt>maxf) tab->sumcnt=maxf;
    val->fdata = tab->fsum/tab->sumcnt;


    if(value<tab->fmin) tab->fmin=value;
    if(value>tab->fmax) tab->fmax=value;
   }
   else
   {
    tab->fitem[tab->maxidx++]=value;
    val->fdata=value;


    if(value<tab->fmin) tab->fmin=value;
    if(value>tab->fmax) tab->fmax=value;
   }
  }
  break;
  case 24:
  if(!strcmp(valstring2,"mode"))
  {
   val->path->key.mode=value;
  }
  else if(!strcmp(valstring2,"type"))
  {
   val->path->key.type=value;
  }
  else if(!strcmp(valstring2,"state"))
  {
   val->path->state=value;
  }
  break;
  case 25:
  if(!strcmp(valstring2,"x"))
    {
      val->frame->x=value;
    }
    else if(!strcmp(valstring2,"y"))
    {
      val->frame->y=value;
    }
    else if(!strcmp(valstring2,"z"))
    {
      val->frame->z=value;
    }
    else if(!strcmp(valstring2,"v"))
    {
      val->frame->v=value;
    }
    else if(!strcmp(valstring2,"w"))
    {
      val->frame->w=value;
    }
    else if(!strcmp(valstring2,"u"))
    {
      val->frame->u=value;
    }
  break;
 case 27:
  if(!strcmp(valstring2,"idx"))
    {
      val->data=value;
      val->frame=&val->pattern->item[val->data].wcp;
    }
  break;
 case 28:
  if(val->cppattern != ((void *)0))
    {
      if(!strcmp(valstring2,"layeridx"))
      {
        val->data=value;
        val->cppattern->selectedItem = val->data;
      }
      else if(!strcmp(valstring2,"pppidx"))
      {
        val->data=value;
        val->cppattern->selectedPPP = val->data;
      }
      else
        printf("Unknown CPPattern subcommand: '%s'\n", valstring2);
    }
    else
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
  break;
  }
}

void setArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg, float value)
{
  switch(arg->type)
 {
 case 20:
  arg->number=value;
  break;
 case 18:
  setArgValueFloat(&stm->value[arg->idx],arg->valstring2,value);
  break;
 case 2:
 case 4:
 case 6:
  setConnectValueInt(stm->input[arg->idx].connect,value);
  break;
 case 3:
 case 5:
 case 7:
  setConnectValueInt(stm->output[arg->idx].connect,value);
  break;
 case 35:
  stm->timeout[arg->idx].timeout=value;
  break;
 case 8:
  stm->output[arg->idx].comskconnect->fdata=value;
  break;
 case 13:
  if (!stm->output[arg->idx].macconnect->userchange)
  {
   stm->output[arg->idx].macconnect->data=value;
   stm->output[arg->idx].macconnect->fdata=value;
   stm->output[arg->idx].macconnect->userchange=1;
  }
  break;
 case 11:
  {
   unsigned int tmpudata;
   tmpudata=*(stm->output[arg->idx].icpconnect->udata);
   tmpudata&=~(1<<stm->output[arg->idx].icpconnect->bitpos);
   tmpudata|=(((int)value)<<stm->output[arg->idx].icpconnect->bitpos);
   *(stm->output[arg->idx].icpconnect->udata)=tmpudata;
   break;
  }
 default:
  break;
 }
}

void setArgValueInt(tmpnStateMachineValue *val, char *valstring2, int value)
{
  switch (val->type)
 {
 case 18:
 case 17:
  val->data=value;
  break;
 case 21:
  if(val->linkvalue==((void *)0))
    {
      val->data=value;
    }
    else
    {
      setArgValueInt(val->linkvalue,valstring2,value);
    }
  break;
  case 22:
  {
   float fdata;
   int i,maxf;
   tmpnStateMachineTable *tab;
   tab = val->table;
   if(!strcmp(valstring2,"newtablesize"))
   {
    tab->newtablesize=value;
    return;
   }
   if(!strcmp(valstring2,"topsearchwidth")){
    tab->topsearchwidth = value;
    return;
   }
   maxf=tab->newtablesize;

   if(tab->curtablesize!=maxf)
   {
    tab->curtablesize=maxf;
    tab->maxidx=0;
    tab->sum=0;
    tab->fsum=0.0;
    for(i=0;i<tab->maxsize;i++)
    {
     tab->item[i]=0;
     tab->fitem[i]=0.0;
    }
    tab->item[0]=0;
    tab->fitem[0]=0;
    tab->sumcnt=0;
    tab->topidx=0;
    tab->topval=0.0;
    tab->min=999999999;
    tab->max=-999999999;
    tab->fmin=999999999.0;
    tab->fmax=-999999999.0;
   }
   if(tab->maxidx>=maxf) tab->maxidx=0;
   if(tab->filter==1)
   {
    tab->sum-=tab->item[tab->maxidx];
    tab->item[tab->maxidx++]=value;
    tab->sum+=value;
    tab->sumcnt++;
    if(tab->sumcnt>maxf) tab->sumcnt=maxf;
    fdata = tab->sum/tab->sumcnt;
    if(fdata>=0)
     val->data = (int)(fdata+0.5);
    else
     val->data = (int)(fdata-0.5);


    if(value<tab->min) tab->min=value;
    if(value>tab->max) tab->max=value;
   }
   else
   {
    tab->item[tab->maxidx++]=value;
    val->data=value;


    if(value<tab->min) tab->min=value;
    if(value>tab->max) tab->max=value;
   }
  }
  break;
  case 24:
  if(!strcmp(valstring2,"mode"))
    {
      val->path->key.mode=value;
    }
    else if(!strcmp(valstring2,"type"))
    {
      val->path->key.type=value;
    }
    else if(!strcmp(valstring2,"state"))
    {
      val->path->state=value;
    }
  break;
  case 25:
  if(!strcmp(valstring2,"x"))
    {
      val->frame->x=value;
    }
    else if(!strcmp(valstring2,"y"))
    {
      val->frame->y=value;
    }
    else if(!strcmp(valstring2,"z"))
    {
      val->frame->z=value;
    }
    else if(!strcmp(valstring2,"v"))
    {
      val->frame->v=value;
    }
    else if(!strcmp(valstring2,"w"))
    {
      val->frame->w=value;
    }
    else if(!strcmp(valstring2,"u"))
    {
      val->frame->u=value;
    }
  break;
  case 27:
  if(!strcmp(valstring2,"idx"))
    {
      val->data=value;
      val->frame=&val->pattern->item[val->data].wcp;
    }
  break;
  case 28:
  if(val->cppattern != ((void *)0))
    {
      if(!strcmp(valstring2,"layeridx"))
      {
        val->data=value;
        val->cppattern->selectedItem = val->data;
      }
      else if(!strcmp(valstring2,"pppidx"))
      {
        val->data=value;
        val->cppattern->selectedPPP = val->data;
      }
      else
        printf("Unknown CPPattern subcommand: '%s'\n", valstring2);
    }
    else
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
  break;
  }
}

void setArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg, int value)
{
  switch(arg->type)
 {
 case 20:
  arg->number=value;
  break;
 case 18:
  setArgValueInt(&stm->value[arg->idx],arg->valstring2,value);
  break;
 case 2:
 case 4:
 case 6:
  setConnectValueInt(stm->input[arg->idx].connect,value);
  break;
 case 3:
 case 5:
 case 7:
  setConnectValueInt(stm->output[arg->idx].connect,value);
  break;
 case 35:
  stm->timeout[arg->idx].timeout=value;
  break;
 case 8:
  stm->output[arg->idx].comskconnect->fdata=value;
  break;
 case 13:
  if (!stm->output[arg->idx].macconnect->userchange)
  {
   stm->output[arg->idx].macconnect->data=value;
   stm->output[arg->idx].macconnect->fdata=value;
   stm->output[arg->idx].macconnect->userchange=1;
  }
  break;
 case 11:
  {
   unsigned int tmpudata;
   tmpudata=*(stm->output[arg->idx].icpconnect->udata);
   tmpudata&=~(1<<stm->output[arg->idx].icpconnect->bitpos);
   tmpudata|=(((int)value)<<stm->output[arg->idx].icpconnect->bitpos);
   *(stm->output[arg->idx].icpconnect->udata)=tmpudata;
   break;
  }
 default:
  break;
 }
}

float getArgValueFloat(tmpnStateMachineValue *val, char *val2, int *argSubType)
{
  float ret=0;
 switch(val->type)
 {
 case 18:
 case 17:
  if(val->subtype==0)
      ret = val->data;
    else
      ret = val->fdata;
  break;
  case 21:
    if(val->linkvalue==((void *)0))
    {
   if (val->remote!=((void *)0)&&val->remote->remotehost!=((void *)0))
   {

    val->subtype=val->remote->subtype;
    *argSubType=val->subtype;
    if(val->subtype==0)
     ret = val->remote->data;
    else
     ret = val->remote->fdata;
   }
   else
   {
    if(val->subtype==0)
     ret = val->data;
    else
     ret = val->fdata;
   }
    }
    else
    {
      ret = getArgValueFloat(val->linkvalue,val2,argSubType);
    }
  break;
  case 22:
    if(!strcmp(val2,"maxidx"))
    {
      ret = val->table->maxidx;
    }
    else if(!strcmp(val2,"size"))
    {
      ret = val->table->curtablesize;
    }
    else if (!strcmp(val2,"topidx"))
    {
      findTopInTable(val);
      ret = val->table->topidx;
    }
    else if(!strcmp(val2,"topval"))
    {
      ret = val->table->topval;
    }
    else
    {
      if(val->subtype==0)
        ret = val->data;
      else
        ret = val->fdata;
    }
  break;
  case 24:
  if(!strcmp(val2,"mode"))
    {
      ret = val->path->key.mode;
    }
    else if(!strcmp(val2,"type"))
    {
      ret = val->path->key.type;
    }
    else if(!strcmp(val2,"state"))
    {
      ret = val->path->state;
    }
  break;
  case 25:
  if(!strcmp(val2,"x"))
    {
      ret = val->frame->x;
    }
    else if(!strcmp(val2,"y"))
    {
      ret = val->frame->y;
    }
    else if(!strcmp(val2,"z"))
    {
      ret = val->frame->z;
    }
    else if(!strcmp(val2,"v"))
    {
      ret = val->frame->v;
    }
    else if(!strcmp(val2,"w"))
    {
      ret = val->frame->w;
    }
    else if(!strcmp(val2,"u"))
    {
      ret = val->frame->u;
    }
  break;
  case 26:
  if(!strcmp(val2,"sy"))
    {
      ret = val->item->sy;
    }
    else if(!strcmp(val2,"gy"))
    {
      ret = val->item->gy;
    }
    else if(!strcmp(val2,"my"))
    {
      ret = val->item->my;
    }
  else if(!strcmp(val2,"gx"))
    {
      ret = val->item->gx;
    }
  else if(!strcmp(val2,"dy"))
    {
      ret = val->item->dim.y;
    }
  else if(!strcmp(val2,"dx"))
    {
      ret = val->item->dim.x;
    }
  else if(!strcmp(val2,"dz"))
    {
      ret = val->item->dim.z;
    }
    else if(!strcmp(val2,"weight"))
    {
      ret = val->item->weight;
    }
  break;
  case 27:
  if(!strcmp(val2,"layer"))
    {
      ret = val->pattern->item[val->data].layer;
    }
    else if(!strcmp(val2,"wcp.x"))
    {
      ret = val->pattern->item[val->data].wcp.x;
    }
    else if(!strcmp(val2,"wcp.y"))
    {
      ret = val->pattern->item[val->data].wcp.y;
    }
    else if(!strcmp(val2,"wcp.z"))
    {
      ret = val->pattern->item[val->data].wcp.z;
    }
    else if(!strcmp(val2,"wcp.v"))
    {
      ret = val->pattern->item[val->data].wcp.v;
    }
    else if(!strcmp(val2,"wcp.w"))
    {
      ret = val->pattern->item[val->data].wcp.w;
    }
    else if(!strcmp(val2,"wcp.u"))
    {
      ret = val->pattern->item[val->data].wcp.u;
    }
  break;
  case 28:
    if(val->cppattern == ((void *)0))
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
    if(!strcmp(val2,"maxlayers"))
    {
      ret = val->cppattern->maxidx;
    }
    else if(!strcmp(val2,"maxpush"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].maxpush;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"gettime"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].gettime;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.gettime: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"ppp"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].ppps[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.ppp: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pacc"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].paccs[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pacc: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pspeed"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].pspeeds[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pspeed: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else
      printf("Unknown CPPattern subcommand: '%s'\n", val2);
  break;
  }
  return ret;
}


float getArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  float ret=0;
  switch(arg->type)
 {
 case 20:
  if (arg->subtype==0)
   ret = arg->number;
  else
   ret = arg->fnumber;
  break;
 case 18:
  ret = getArgValueFloat(&stm->value[arg->idx],arg->valstring2,&arg->subtype);
  break;
 case 2:
  case 4:
 case 6:
  ret = getConnectValueInt(stm->input[arg->idx].connect);
  break;
 case 3:
 case 5:
 case 7:
  ret = getConnectValueInt(stm->output[arg->idx].connect);
  break;
 case 35:
  ret = stm->timeout[arg->idx].timeout;
  break;
 case 12:
  ret = stm->input[arg->idx].loadcellconnect->fdata;
  break;
 case 8:
  ret = stm->output[arg->idx].comskconnect->fdata;
  break;
 case 9:
  ret = stm->input[arg->idx].comskconnect->fdata;
  break;
 case 13:
  {
   macConnect *mccon;
   mccon=stm->output[arg->idx].macconnect;
   if (mccon->type==2||mccon->type==0||mccon->type==1)
    ret = (float)mccon->data;
   else
    ret = mccon->fdata;
  }
  break;
 case 14:
  {
   macConnect *mccon;
   mccon=stm->input[arg->idx].macconnect;
   if (mccon->type==2||mccon->type==0||mccon->type==1)
    ret = (float)mccon->data;
   else
    ret = mccon->fdata;
  }
  break;
 case 10:
  ret = 1&((*stm->input[arg->idx].icpconnect->udata)>>stm->input[arg->idx].icpconnect->bitpos);
  break;
 case 11:
  ret = 1&((*stm->output[arg->idx].icpconnect->udata)>>stm->output[arg->idx].icpconnect->bitpos);
  break;
 default:
  break;
 }
  return ret;
}

int getArgSubType(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  int ret=-1;
  if (arg->type==18)
 {
  switch (stm->value[arg->idx].type)
  {
  case 21:
   if(stm->value[arg->idx].linkvalue!=((void *)0))
     {
    int sidx=-1,vidx=-1;
    ARGSTRUCT temp;
    temp.type=stm->value[arg->idx].linkvalue->type;
    strncpy(temp.valstring,arg->valstring,255);
    strncpy(temp.valstring2,arg->valstring2,255);
    sidx = findSTMIdx(stm, stm->value[arg->idx].link);
    if(sidx==-1)
     sidx = getMachineIdx(stm->value[arg->idx].link);
    if(sidx!=-1)
    {
     vidx = getValueIdx(&tworkcell->statemachines.statemachine[sidx], stm->value[arg->idx].linkname);
     temp.idx=vidx;
     ret=getArgSubType(&tworkcell->statemachines.statemachine[sidx],&temp);
    }
    if (ret==-1)
    {
     ret = stm->value[arg->idx].subtype;
    }
   }
   break;
  case 22:
   if(!strcmp(arg->valstring2,"maxidx"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"size"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"topidx"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"topval"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"newtablesize"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"topsearchwidth"))
    ret = 0;
   break;
  case 24:
   if(!strcmp(arg->valstring2,"mode"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"type"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"state"))
    ret = 0;
   break;
  case 25:
   if(!strcmp(arg->valstring2,"x"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"y"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"z"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"v"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"w"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"u"))
    ret = 1;
   break;
  case 26:
   if(!strcmp(arg->valstring2,"sy"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"gy"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"my"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"gx"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"dy"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"dx"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"dz"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"weight"))
    ret = 1;
   break;
  case 27:
   if(!strcmp(arg->valstring2,"layer"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"idx"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"wcp.x"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"wcp.y"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"wcp.z"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"wcp.v"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"wcp.w"))
    ret = 1;
   else if(!strcmp(arg->valstring2,"wcp.u"))
    ret = 1;
   break;
  case 28:
   if(!strcmp(arg->valstring2,"maxlayers"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"maxpush"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"gettime"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"ppp"))
    ret = 0;
      else if(!strcmp(arg->valstring2,"pacc"))
    ret = 0;
      else if(!strcmp(arg->valstring2,"pspeed"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"layeridx"))
    ret = 0;
   else if(!strcmp(arg->valstring2,"pppidx"))
    ret = 0;
   break;
  }
 }
 return ret;
}

int getArgValueInt(tmpnStateMachineValue *val, char *val2, int *argSubType)
{
  int ret=0;
 switch(val->type)
 {
  case 18:
 case 17:
  if(val->subtype==0)
      ret = val->data;
    else
      ret = val->fdata;
  break;
  case 21:
    if(val->linkvalue==((void *)0))
    {
   if (val->remote!=((void *)0)&&val->remote->remotehost!=((void *)0))
   {

    val->subtype=val->remote->subtype;
    *argSubType=val->subtype;
    if(val->subtype==0)
     ret = val->remote->data;
    else
     ret = val->remote->fdata;
   }
   else
   {
    if(val->subtype==0)
     ret = val->data;
    else
     ret = val->fdata;
   }
    }
    else
    {
      ret = getArgValueInt(val->linkvalue,val2,argSubType);
    }
  break;
  case 22:
  if(!strcmp(val2,"maxidx"))
    {
      ret = val->table->maxidx;
    }
    else if(!strcmp(val2,"size"))
    {
      ret = val->table->curtablesize;
    }
    else if(!strcmp(val2,"topidx"))
    {
      findTopInTable(val);
      ret = val->table->topidx;
    }
    else if(!strcmp(val2,"topval"))
    {
      ret = val->table->topval;
    }
    else
    {
      if(val->subtype==0)
        ret = val->data;
      else
        ret = val->fdata;
    }
  break;
 case 24:
  if(!strcmp(val2,"mode"))
    {
      ret = val->path->key.mode;
    }
    else if(!strcmp(val2,"type"))
    {
      ret = val->path->key.type;
    }
    else if(!strcmp(val2,"state"))
    {
      ret = val->path->state;
    }
  break;
  case 25:
    if(!strcmp(val2,"x"))
    {
      ret = val->frame->x;
    }
    else if(!strcmp(val2,"y"))
    {
      ret = val->frame->y;
    }
    else if(!strcmp(val2,"z"))
    {
      ret = val->frame->z;
    }
    else if(!strcmp(val2,"v"))
    {
      ret = val->frame->v;
    }
    else if(!strcmp(val2,"w"))
    {
      ret = val->frame->w;
    }
    else if(!strcmp(val2,"u"))
    {
      ret = val->frame->u;
    }
  break;
  case 26:
    if(!strcmp(val2,"sy"))
    {
      ret = val->item->sy;
    }
    else if(!strcmp(val2,"gy"))
    {
      ret = val->item->gy;
    }
    else if(!strcmp(val2,"my"))
    {
      ret = val->item->my;
    }
  else if(!strcmp(val2,"gx"))
    {
      ret = val->item->gx;
    }
  else if(!strcmp(val2,"dy"))
    {
      ret = val->item->dim.y;
    }
  else if(!strcmp(val2,"dx"))
    {
      ret = val->item->dim.x;
    }
  else if(!strcmp(val2,"dz"))
    {
      ret = val->item->dim.z;
    }
    else if(!strcmp(val2,"weight"))
    {
      ret = val->item->weight;
    }
  break;
  case 27:
  if(!strcmp(val2,"layer"))
    {
      ret = val->pattern->item[val->data].layer;
    }
    else if(!strcmp(val2,"wcp.x"))
    {
      ret = val->pattern->item[val->data].wcp.x;
    }
    else if(!strcmp(val2,"wcp.y"))
    {
      ret = val->pattern->item[val->data].wcp.y;
    }
    else if(!strcmp(val2,"wcp.z"))
    {
      ret = val->pattern->item[val->data].wcp.z;
    }
    else if(!strcmp(val2,"wcp.v"))
    {
      ret = val->pattern->item[val->data].wcp.v;
    }
    else if(!strcmp(val2,"wcp.w"))
    {
      ret = val->pattern->item[val->data].wcp.w;
    }
    else if(!strcmp(val2,"wcp.u"))
    {
      ret = val->pattern->item[val->data].wcp.u;
    }
  break;
  case 28:
  if(val->cppattern == ((void *)0))
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
    if(!strcmp(val2,"maxlayers"))
    {
      ret = val->cppattern->maxidx;
    }
    else if(!strcmp(val2,"maxpush"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].maxpush;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"gettime"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].gettime;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.gettime: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"ppp"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].ppps[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.ppp: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pacc"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].paccs[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pacc: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pspeed"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].pspeeds[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pspeed: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else
      printf("Unknown CPPattern subcommand: '%s'\n", val2);
  break;
  }
  return ret;
}

int getArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  int ret=0;
  switch(arg->type)
 {
 case 20:
  if (arg->subtype==0)
   ret = arg->number;
  else
   ret = arg->fnumber;
  break;
 case 18:
  ret = getArgValueInt(&stm->value[arg->idx],arg->valstring2,&arg->subtype);
  break;
 case 35:
  ret = stm->timeout[arg->idx].timeout;
  break;
 case 2:
 case 4:
 case 6:
  ret = getConnectValueInt(stm->input[arg->idx].connect);
  break;
 case 3:
 case 5:
 case 7:
  ret = getConnectValueInt(stm->output[arg->idx].connect);
  break;
 case 12:
  ret = (int)stm->input[arg->idx].loadcellconnect->fdata;
  break;
 case 8:
   ret = (int)stm->output[arg->idx].comskconnect->fdata;
  break;
 case 9:
  ret = (int)stm->input[arg->idx].comskconnect->fdata;
  break;
 case 13:
  {
   macConnect *mccon;
   mccon=stm->output[arg->idx].macconnect;
   if (mccon->type==2||mccon->type==0||mccon->type==1)
    ret = mccon->data;
   else
    ret = (int)mccon->fdata;
  }
  break;
 case 14:
  {
   macConnect *mccon;
   mccon= stm->input[arg->idx].macconnect;
   if (mccon->type==2||mccon->type==0||mccon->type==1)
    ret = mccon->data;
   else
    ret = (int)mccon->fdata;
  }
  break;
 case 10:
  ret = 1&((*stm->input[arg->idx].icpconnect->udata)>>stm->input[arg->idx].icpconnect->bitpos);
  break;
 case 11:
  ret = 1&((*stm->output[arg->idx].icpconnect->udata)>>stm->output[arg->idx].icpconnect->bitpos);
  break;
 default:
  break;
 }
  return ret;
}

int findTopInTable(tmpnStateMachineValue *val)
{
  tmpnStateMachineTable *table=val->table;
  if(table->topsearchwidth <= 0)
  {
    printf("Remember to set topsearchwidth before calling topidx and topval\n");
    return 0;
  }
  else
  {
    int searchCount = table->topsearchwidth;

    if(searchCount > table->curtablesize)
      searchCount = table->curtablesize;

    int curIdx = table->maxidx, maxIdx=0;
    float curVal, maxVal = -999999999.0;
    while(searchCount >= 0)
    {
      curIdx--;
      if(curIdx < 0)
      {

        curIdx = table->curtablesize-1;
      }
      if(val->subtype==0)
        curVal = table->item[curIdx];
      else
        curVal = table->fitem[curIdx];

      if(maxVal < curVal)
      {
        maxVal = curVal;
        maxIdx = curIdx;

      }
      searchCount--;
    }
    table->topidx = maxIdx;

    table->topval = maxVal;

  }
  return 1;
}

int getFunctionBody(FILE *fp, int state, tmpnStateMachine * stm)
{
  int val, index=0;

  char s[256];
  char func[256], arg1[256], arg2[128], arg3[128], arg4[128];
  int level = 0;
 int inlinelevel = 0;
 FILE *fpold[10];
 int lnold[10];
 char* fret;
  PRINTSTRUCT* print;
  SETSTRUCT* set;
  TESTSTRUCT* test;
  CALCSTRUCT* calc;
 ROBOTSPEEDSTRUCT *robotspeed;
  index = stm->state[state].maxprgidx;
  while(inlinelevel>=0)
  {
    strcpy(func, "");
    strcpy(arg1, "");
    strcpy(arg2, "");
    strcpy(arg3, "");
  ln++;
    fret=fgets(s, 256, fp);
  if (fret==((void *)0))
  {
   inlinelevel--;
   if (inlinelevel>=0)
   {
    fp=fpold[inlinelevel];
    ln=lnold[inlinelevel];
   }
   continue;
  }
    if(strlen(s)>=255)
      error(ln, "length exceed max = 256");

    sscanf(s," %s", func);

    if(strncmp(func, ";", 1)==0)
    {

    }
    else if(strncmp(func, "TEST", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = 41;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      level++;
      stm->state[state].prg[index].level = level;

      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
   if (test->validation == -1) error(ln, "unknown test.\n");
   if(test->test.type==19) test->cmp.type = 19;
   else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1);
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==19)
      {
    if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "OR", 2)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = 43;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;

      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
   if (test->validation == -1) error(ln, "unknown test.\n");
   if(test->test.type==19) test->cmp.type = 19;
   else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1);
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==19)
      {
       if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "AND", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = 44;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;

      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
   if (test->validation == -1) error(ln, "unknown test.\n");
   if(test->test.type==19) test->cmp.type = 19;
   else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1);
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==19)
      {
       if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
  else if(strncmp(func, "ELSETEST", 8)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = 42;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;

      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
   if (test->validation == -1) error(ln, "unknown test.\n");
   if(test->test.type==19) test->cmp.type = 19;
   else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1);
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==19)
      {
    if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "EXEC", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "EXEC wrong number of arguments.\n");
      stm->state[state].prg[index].type = 55;
      stm->state[state].prg[index].data = malloc(sizeof(EXECSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((EXECSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      index++;
    }
    else if(strncmp(func, "LOAD", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4)
        error(ln, "LOAD wrong number of arguments.\n");
      stm->state[state].prg[index].type = 54;
      stm->state[state].prg[index].data = malloc(sizeof(LOADSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->src1, arg2);
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->src2, arg3);
      index++;
    }
    else if(strncmp(func, "SETFRAME", 8)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETFRAME wrong number of arguments.\n");
      stm->state[state].prg[index].type = 56;
      stm->state[state].prg[index].data = malloc(sizeof(SETFRAMESTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETFRAMESTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETFRAMESTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
  else if(strncmp(func, "SETITEM", 7)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETITEM wrong number of arguments.\n");
      stm->state[state].prg[index].type = 57;
      stm->state[state].prg[index].data = malloc(sizeof(SETITEMSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETITEMSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETITEMSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
  else if(strncmp(func, "ROBOTSPEED", 10)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "ROBOTSPEED wrong number of arguments.\n");
      stm->state[state].prg[index].type = 59;
      stm->state[state].prg[index].data = malloc(sizeof(ROBOTSPEEDSTRUCT));
      stm->state[state].prg[index].level = level;
   robotspeed = (ROBOTSPEEDSTRUCT*)stm->state[state].prg[index].data;

      robotspeed->src.type = getCmpType(stm, arg1,ln);
      getArgBody(stm,&robotspeed->src,arg1);

   if(robotspeed->src.type!=20
     &&robotspeed->src.type!=2
     &&robotspeed->src.type!=4
     &&robotspeed->src.type!=6
     &&robotspeed->src.type!=3
     &&robotspeed->src.type!=5
     &&robotspeed->src.type!=7
     &&robotspeed->src.type!=9
     &&robotspeed->src.type!=14
     &&robotspeed->src.type!=12
     &&robotspeed->src.type!=10
     &&robotspeed->src.type!=8
     &&robotspeed->src.type!=13
     &&robotspeed->src.type!=11
     &&robotspeed->src.type!=35
     &&robotspeed->src.type!=18)
    error(ln, "srctype not found");

   index++;
    }
  else if(strncmp(func, "SETPATTERN", 10)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETPATTERN wrong number of arguments.\n");
      stm->state[state].prg[index].type = 58;
      stm->state[state].prg[index].data = malloc(sizeof(SETPATTERNSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETPATTERNSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETPATTERNSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
  else if(strncmp(func, "SETCPPATTERN", 12)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETCPPATTERN wrong number of arguments.\n");
      stm->state[state].prg[index].type = 60;
      stm->state[state].prg[index].data = malloc(sizeof(SETCPPATTERNSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETCPPATTERNSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETCPPATTERNSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
    else if(strncmp(func, "SETSTATE", 8)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "SETSTATE wrong number of arguments.\n");
      stm->state[state].prg[index].type = 34;
      stm->state[state].prg[index].data = malloc(sizeof(SETSTATESTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETSTATESTRUCT*)stm->state[state].prg[index].data)->name, arg1);
      index++;
    }
    else if(strncmp(func, "PRINT", 5)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val < 2 || val > 3)
        error(ln, "PRINT wrong number of arguments.\n");
      stm->state[state].prg[index].type = 53;
      stm->state[state].prg[index].data = malloc(sizeof(PRINTSTRUCT));
      stm->state[state].prg[index].level = level;

      print = (PRINTSTRUCT*)stm->state[state].prg[index].data;

      print->arg.type = getCmpType(stm, arg1,ln);
      getArgBody(stm,&print->arg,arg1);
      if(val==2) print->newline=1;
      else print->newline=0;
      index++;
    }
    else if(strncmp(func, "SET", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SET wrong number of arguments.\n");

      stm->state[state].prg[index].type = 33;
      stm->state[state].prg[index].data = malloc(sizeof(SETSTRUCT));
      stm->state[state].prg[index].level = level;

      set = (SETSTRUCT*)stm->state[state].prg[index].data;

      set->dest.type = getCmpType(stm, arg1,ln);
      set->src.type = getCmpType(stm, arg2,ln);

      getArgBody(stm,&set->dest,arg1);


      if(set->dest.type!=3
     &&set->dest.type!=5
     &&set->dest.type!=7
     &&set->dest.type!=8
     &&set->dest.type!=13
     &&set->dest.type!=11
     &&set->dest.type!=35
     &&set->dest.type!=18)
    error(ln, "desttype not found");

      getArgBody(stm,&set->src,arg2);

      if(set->src.type!=20
     &&set->src.type!=2
     &&set->src.type!=4
     &&set->src.type!=6
     &&set->src.type!=3
     &&set->src.type!=5
     &&set->src.type!=7
     &&set->src.type!=9
     &&set->src.type!=14
     &&set->src.type!=12
     &&set->src.type!=10
     &&set->src.type!=8
     &&set->src.type!=13
     &&set->src.type!=11
     &&set->src.type!=35
     &&set->src.type!=18)
    error(ln, "srctype not found");

      index++;
    }
    else if(strncmp(func, "TIMEOUT", 7)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));


      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val<2||val>3)
        error(ln, "TIMEOUT wrong number of arguments.\n");



      stm->state[state].prg[index].type = 35;
      stm->state[state].prg[index].data = malloc(sizeof(TIMEOUTSTRUCT));
      stm->state[state].prg[index].level = level;

      ((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->idx = getTimeoutIdx(stm, arg1);
       if(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Timeout Does not exist");


      if(val==3)
      {
        strcpy(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->statename,arg2);


      }
      else
      {
        strcpy(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->statename,"");
        ((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->number = -1;
      }

      index++;

    }
    else if(strncmp(func, "CALC", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s = %s %s %s", func, arg1, arg2, arg3, arg4);
      if(val != 5)
        error(ln, "DIV wrong number of arguments.\n");
      stm->state[state].prg[index].type = 51;
      stm->state[state].prg[index].data = malloc(sizeof(CALCSTRUCT));
      calc = (CALCSTRUCT*)stm->state[state].prg[index].data;
      calc->dest.type = getCmpType(stm, arg1,ln);
      calc->src1.type = getCmpType(stm, arg2,ln);
      calc->src2.type = getCmpType(stm, arg4,ln);
      if(!strcmp(arg3,"+"))
        calc->optype = 36;
      else if(!strcmp(arg3,"-"))
        calc->optype = 37;
      else if(!strcmp(arg3,"/"))
        calc->optype = 50;
      else if(!strcmp(arg3,"*"))
        calc->optype = 49;
      else if(!strcmp(arg3,"%"))
        calc->optype = 52;
      else
       error(ln, "unknown optype\n");

      if(calc->dest.type!=3
     &&calc->dest.type!=5
     &&calc->dest.type!=7
     &&calc->dest.type!=8
     &&calc->dest.type!=13
     &&calc->dest.type!=11
     &&calc->dest.type!=18)
       error(ln, "CALC desttype not found");

      if(calc->src1.type!=20
     &&calc->src1.type!=18
     &&calc->src1.type!=2
     &&calc->src1.type!=4
     &&calc->src1.type!=6
     &&calc->src1.type!=3
     &&calc->src1.type!=5
     &&calc->src1.type!=7
     &&calc->src1.type!=9
     &&calc->src1.type!=14
     &&calc->src1.type!=12
     &&calc->src1.type!=10
     &&calc->src1.type!=8
     &&calc->src1.type!=13
     &&calc->src1.type!=11
     &&calc->src1.type!=35)
    error(ln, "CALC src1 type not found");

      if(calc->src2.type!=20
     &&calc->src2.type!=18
     &&calc->src2.type!=2
     &&calc->src2.type!=4
     &&calc->src2.type!=6
     &&calc->src2.type!=3
     &&calc->src2.type!=5
     &&calc->src2.type!=7
     &&calc->src2.type!=9
     &&calc->src2.type!=14
     &&calc->src2.type!=12
     &&calc->src2.type!=10
     &&calc->src2.type!=8
     &&calc->src2.type!=13
     &&calc->src2.type!=11
     &&calc->src2.type!=35)
    error(ln, "CALC src2 type not found");

      getArgBody(stm,&calc->dest,arg1);
      getArgBody(stm,&calc->src1,arg2);
      getArgBody(stm,&calc->src2,arg4);



      stm->state[state].prg[index].level = level;
      index++;
    }
    else if(strncmp(func, "DIV", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "DIV wrong number of arguments.\n");



      stm->state[state].prg[index].type = 50;
      stm->state[state].prg[index].data = malloc(sizeof(DIVSTRUCT));
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1)
      {

          error(ln, "Value Does not exist");
      }
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "MUL", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "MUL wrong number of arguments.\n");



      stm->state[state].prg[index].type = 49;
      stm->state[state].prg[index].data = malloc(sizeof(MULSTRUCT));
      ((MULSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((MULSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1)
      {

          error(ln, "Value Does not exist");
      }
      ((MULSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "ADD", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg2, arg1);
      if(val != 4)
        error(ln, "ADD wrong number of arguments.\n");



      stm->state[state].prg[index].type = 36;
      stm->state[state].prg[index].data = malloc(sizeof(ADDSTRUCT));
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1)
      {

          error(ln, "Value Does not exist");
      }
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "SUBT", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "SUBT wrong number of arguments.\n");



      stm->state[state].prg[index].type = 37;
      stm->state[state].prg[index].data = malloc(sizeof(SUBTSTRUCT));
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1)
      {

          error(ln, "Value Does not exist");
      }
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "ELSE", 4)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s", func);
      if(val != 1)
        error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = 39;
      stm->state[state].prg[index].data = malloc(sizeof(ELSESTRUCT));
      stm->state[state].prg[index].level = level;
      index++;
    }
    else if(strncmp(func, "ENDTEST", 7)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      stm->state[state].prg[index].type = 45;
      stm->state[state].prg[index].level = level;
      SetLevelJmp(&stm->state[state], index);
      level--;
      if(level < 0)
        error(ln, "TEST ENDTEST out of order.");
      index++;
    }
    else if(strncmp(func, "END", 3)==0)
    {
   stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      stm->state[state].prg[index].type = 40;
      stm->state[state].prg[index].level = level;
      if(level != 0)
        error(ln, "TEST ENDTEST out of order.");

      stm->state[state].maxprgidx=index;
   return index;
    }
  else if(strncmp(func,"INLINE",7)==0)
  {
   FILE *fpinline;
   char name[128];
   char inlinename[128];
   sscanf(s," INLINE %s ",name);
   sprintf(inlinename,"%s/statemachine/%s",databasePath,name);
   printf("'->Inlining at level %i: %s\n",inlinelevel,inlinename);
   fpinline = fopen(inlinename,"r");
   if(fpinline==((void *)0)){
    printf("ERROR: Load inline stm-code: cannot open file: '%s'\n", inlinename);
    exit(99);
   }
   lnold[inlinelevel] = ln;
   fpold[inlinelevel++] = fp;
   fp = fpinline;
   ln=0;
   if (inlinelevel>9)
   {
    printf("ERROR: More than 10 levels of Inline-nesting is not supported.\n");
    exit(99);
   }
  }
    else
  {
   printf("func: %s\n",func);
      error(ln, "syntax error unknown command");
  }
  }
  stm->state[state].maxprgidx=index;
  return index;
}

int connectSimulated(tmpnConnect *connect)
{
  int i,j,d;

  for(d=0;d<tworkcell->dios.maxidx;d++)
  {
    for(i=0;i<tworkcell->dios.dio[d].numOfModules;i++)
    {
      for(j=0;j<tworkcell->dios.dio[d].iotab[i].maxidx;j++)
      {
        if(connect==&tworkcell->dios.dio[d].iotab[i].connect[j])
          return tworkcell->dios.dio[d].simulate;
      }
    }
  }
  return 0;
}

int comskconnectSimulated(comskConnect *comskconnect)
{
  int i,j,d;
  for(d=0;d<tworkcell->comsks.maxidx;d++)
  {
    for(i=0;i<tworkcell->comsks.comsk[d].numOfModules;i++)
    {
   for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfOutWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].odata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
   for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].idata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
      for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInitWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].initdata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
    }
  }
  return 0;
}
# 4477 "cmd.c"
static tmpnConnect dummyConnectOn = {2,0,0,0,0xFFFF,{0},"dummyOn","dummyOn","dummyOn"};
static tmpnConnect dummyConnectOff = {2,0,0,0,0xFFFF,{0},"dummyOff","dummyOff","dummyOff"};
static tmpnConnect dummyConnectOut = {3,0,0,0,0xFFFF,{0},"dummyOut","dummyOut","dummyOut"};
static unsigned short dummyidataon=1;
static unsigned short dummyidataoff=0;
static unsigned short dummyodataout=0;

static int connectStatemachineAndIO(tmpnStateMachineIO *io, char *name, char *key)
{
  int i,j,d;

  strcpy(io->name,name);

  if(strcmp(key,"dummyOn")==0)
  {
    io->connect=&dummyConnectOn;
    io->connect->udata=&dummyidataon;
    return 1;
  }
  if(strcmp(key,"dummyOff")==0)
  {
    io->connect=&dummyConnectOff;
    io->connect->udata=&dummyidataoff;
    return 1;
  }
  if(strcmp(key,"dummyOut")==0)
  {
    io->connect=&dummyConnectOut;
    io->connect->udata=&dummyodataout;
    return 1;
  }

  for(d=0;d<tworkcell->dios.maxidx;d++)
  {
    for(i=0;i<tworkcell->dios.dio[d].numOfModules;i++)
    {
      for(j=0;j<tworkcell->dios.dio[d].iotab[i].maxidx;j++)
      {
        if(strcmp(tworkcell->dios.dio[d].iotab[i].connect[j].key,key)==0)
        {
          io->connect=&tworkcell->dios.dio[d].iotab[i].connect[j];
          if(io->iotype==16)
            io->connect->udata=&tworkcell->dios.dio[d].iotab[i].idata[io->connect->wordidx];
          else
            io->connect->udata=&tworkcell->dios.dio[d].iotab[i].odata[io->connect->wordidx];
          return 1;
        }
      }
    }
  }
 if(io->iotype==16)
  io->iotype=9;
 else if (io->iotype==15)
  io->iotype=8;
 for(d=0;d<tworkcell->comsks.maxidx;d++)
  {
    for(i=0;i<tworkcell->comsks.comsk[d].numOfModules;i++)
    {
   if(io->iotype==9)
   {
    for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInWords;j++)
    {
     if(strcmp(tworkcell->comsks.comsk[d].iotab[i].idata[j].key,key)==0)
     {
      io->comskconnect=&tworkcell->comsks.comsk[d].iotab[i].idata[j];
      return 1;
     }
    }
   }
   else if (io->iotype==8)
   {

    for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfOutWords;j++)
    {
     if(strcmp(tworkcell->comsks.comsk[d].iotab[i].odata[j].key,key)==0)
     {
      io->comskconnect=&tworkcell->comsks.comsk[d].iotab[i].odata[j];
      return 1;
     }
    }
      }
    }
  }
 if(io->iotype==9)
  io->iotype=12;
 for(d=0;d<tworkcell->loadcells.maxidx;d++)
  {
    for(i=0;i<tworkcell->loadcells.loadcell[d].numOfModules;i++)
    {
   if(io->iotype==12)
   {
    if(strcmp((char *)tworkcell->loadcells.loadcell[d].iotab[i].key,key)==0)
    {

     io->loadcellconnect=(loadcellConnect *)&tworkcell->loadcells.loadcell[d].iotab[i];
     return 1;
    }
   }
  }
 }
 if(io->iotype==12)
  io->iotype=14;
 else if (io->iotype==8)
  io->iotype=13;
 for(d=0;d<tworkcell->macs.maxidx;d++)
  {
    for(i=0;i<tworkcell->macs.mac[d].numOfMotors;i++)
    {
   if(io->iotype==14)
   {
    for(j=0;j<tworkcell->macs.mac[d].iotab[i].numOfInWords;j++)
    {
     if(strcmp(tworkcell->macs.mac[d].iotab[i].idata[j].key,key)==0)
     {
      io->macconnect=&tworkcell->macs.mac[d].iotab[i].idata[j];
      return 1;
     }
    }
   }
   else if (io->iotype==13)
   {
    for(j=0;j<tworkcell->macs.mac[d].iotab[i].numOfOutWords;j++)
    {
     if(strcmp(tworkcell->macs.mac[d].iotab[i].odata[j].key,key)==0)
     {
      io->macconnect=&tworkcell->macs.mac[d].iotab[i].odata[j];
      return 1;
     }
    }
      }
    }
  }
 if(io->iotype==14)
  io->iotype=10;
 else if (io->iotype==13)
  io->iotype=11;
 for(d=0;d<tworkcell->icpcons.maxidx;d++)
  {
    for(i=0;i<tworkcell->icpcons.icpcon[d].numOfModules;i++)
    {
   if (io->iotype==10)
   {
    for(j=0;j<tworkcell->icpcons.icpcon[d].iotab[i].numOfInBits;j++)
    {
     if(!strcmp((char *)tworkcell->icpcons.icpcon[d].iotab[i].inconnect[j].key,key))
     {
      io->icpconnect=(tmpnICPConnect *)&tworkcell->icpcons.icpcon[d].iotab[i].inconnect[j];
      return 1;
     }
    }
   }
   else if (io->iotype==11)
   {
    for(j=0;j<tworkcell->icpcons.icpcon[d].iotab[i].numOfOutBits;j++)
    {
     if(!strcmp((char *)tworkcell->icpcons.icpcon[d].iotab[i].outconnect[j].key,key))
     {
      io->icpconnect=(tmpnICPConnect *)&tworkcell->icpcons.icpcon[d].iotab[i].outconnect[j];
      return 1;
     }
    }
   }
  }
 }
  printf("%s not found\n",key);
  exit(1);
}

void getComment(char *buffer, char *n)
{
  int i,j0=0,j1=0;

  for(i=0;i<strlen(buffer);i++)
  {
    if(j0==0&&buffer[i]=='"')
    {
      j0=i;
      i++;
    }
    if(j1==0&&buffer[i]=='"') j1=i;
  }
  strncpy(n,&buffer[j0+1],j1-j0-1);
  n[j1-j0-1]=0;
}

int getMachinePtrStateIdx(tmpnStateMachine *statemachine, const char *statename)
{
  int i;
  for(i=0;i<statemachine->numstate;i++)
  {
    if(strcmp(statemachine->state[i].name,statename)==0) return i;
  }
  return -1;
}


char *getProgramName(char *stmname)
{

  int p;
 char *name;
 p = getMachineIdx(stmname);
 if (p==-1)
 {
  return "";
 }
 else
 {
   name=tworkcell->statemachines.statemachine[p].state[tworkcell->statemachines.statemachine[p].istate].name;
  if(!strncmp(name,"ST_RUNNING_",11))
   return &name[11];
  else
   return "";
 }
  return "";
}

int tmpnStateMachineLoad(const char *filename, tmpnStateMachine *statemachine, int level)
{
  FILE *fp;
  int version;
  int idx,timeout, v, delaystop;
  char name[256], s[256], key[256], n[256],l[256],includename[256],a1[256],a2[256],a3[256];
  char buffer[256];
  tmpnStateMachineTable* tab;
  int i,x;

  fp = fopen(filename,"r");
  if(fp==((void *)0)){
    printf("ERROR: Load Statemachine: cannot open file: '%s'\n", filename);
    exit(99);
  }
  ln = 0;
  fscanf(fp,"STATEMACHINEVERSION %d\n",&version);
  printf("Open statemachine %s VERSION %d\n", filename,version);
  ln++;
 if(version!=2&&version!=3)
  {
    fclose(fp);
    printf(" FAILED version mismatch\n");
    exit(99);
  }
 statemachine->version=version;
  if(level==0)
    strcpy(statemachine->filename,filename);
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    ln++;
    if(strncmp(buffer, ";", 1)==0)
    {
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {
      sscanf(buffer,"Name=%s",statemachine->name);
    }
    else if(strncmp(buffer,"Include=",8)==0)
    {
   int oldln=ln;
      printf("'->");
      sscanf(buffer,"Include=%s",name);
      sprintf(includename,"%s/statemachine/%s",databasePath,name);
      tmpnStateMachineLoad(includename, statemachine,level+1);
   ln = oldln;
    }
  else if(strncmp(buffer,"Value=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"Value=%d,%s %s\n",&idx,s,n);
      else
        sscanf(buffer,"Value=%s %s\n",s,n);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
   }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=18;
   if (!strcmp(s,"DEBUG"))
      {
       printf("DEBUG %s\n",statemachine->name);
       statemachine->debugvalue = &statemachine->value[idx];
      }
      x = splitArg(n,a2,a3);
      if(x>=0)
      {
        statemachine->value[idx].subtype=1;
        statemachine->value[idx].data=atof(n);
        statemachine->value[idx].fdata=atof(n);
      }
      else
      {
        statemachine->value[idx].data=atoi(n);
        statemachine->value[idx].fdata=atoi(n);
        statemachine->value[idx].subtype=0;
      }
    }
    else if(strncmp(buffer,"Table=",6)==0)
    {
   int new;
   new=0;
      v = sscanf(buffer,"Table=%s %s %s\n",s,n,a1);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
    new=1;
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
   }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=22;
      statemachine->value[idx].subtype=0;
      x = splitArg(n,a2,a3);
      if(x>=0)
        statemachine->value[idx].subtype=1;
      else
        statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
      statemachine->value[idx].fdata=0;
   if (new)
   {
    tab = (tmpnStateMachineTable*)malloc(sizeof(tmpnStateMachineTable));
    statemachine->value[idx].table = tab;
   }
   else
   {
    tab = statemachine->value[idx].table;
   }
      tab->maxsize=atoi(a2)*2;
   if (new)
   {
    tab->item = (int*)malloc(sizeof(int)*tab->maxsize);
    tab->fitem = (float*)malloc(sizeof(float)*tab->maxsize);
   }
   else
   {
    tab->item = (int*)realloc(tab->item,sizeof(int)*tab->maxsize);
    tab->fitem = (float*)realloc(tab->fitem,sizeof(float)*tab->maxsize);
   }
      tab->topsearchwidth = -1;
      tab->topidx = -1;
      tab->topval = 0.0;
      tab->sum=0;
      tab->fsum=0.0;
      tab->sumcnt=0;
      tab->maxidx=0;
      tab->min=0;
      tab->max=0;
      tab->fmin=999999999.0;
      tab->fmax=-999999999.0;
      tab->newtablesize=atoi(a2);
      tab->curtablesize=tab->newtablesize;
      tab->item[0]=0;
      tab->fitem[0]=0.0;
      for(i=0;i<tab->maxsize;i++)
      {
        tab->item[i]=0;
        tab->fitem[i]=0.0;
      }
      if((v==3&&!strcmp(a1,"AVG")))
        tab->filter=1;
      else
        tab->filter=0;
    }
    else if(strncmp(buffer,"Const=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"Const=%d,%s %s\n",&idx,s,n);
      else
        sscanf(buffer,"Const=%s %s\n",s,n);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=17;
   if (!strcmp(s,"DEBUG")) statemachine->debugvalue = &statemachine->value[idx];
      x = splitArg(n,a2,a3);
      if(x>=0)
      {
        statemachine->value[idx].subtype=1;
        statemachine->value[idx].data=atof(n);
        statemachine->value[idx].fdata=atof(n);
      }
      else
      {
        statemachine->value[idx].data=atoi(n);
        statemachine->value[idx].fdata=atoi(n);
        statemachine->value[idx].subtype=0;
      }
    }
    else if(strncmp(buffer,"linkValue=",10)==0)
    {
      v = sscanf(buffer,"linkValue=%s %s %s\n",s,n,l);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      if(v==2)
      {
        strcpy(statemachine->value[idx].name,s);
        strcpy(statemachine->value[idx].linkname,s);
        strcpy(statemachine->value[idx].link,n);
      }
      else if(v==3)
      {
        strcpy(statemachine->value[idx].name,s);
        strcpy(statemachine->value[idx].linkname,n);
        strcpy(statemachine->value[idx].link,l);
      }
      else
        error(ln, "wrong number of arguments");

      statemachine->value[idx].type=21;
      statemachine->value[idx].data=0;
      statemachine->value[idx].linkvalue=((void *)0);
   statemachine->value[idx].remote=((void *)0);
    }
    else if(strncmp(buffer,"Timeout=",8)==0)
    {
      if(version==2)
        sscanf(buffer,"Timeout=%d,%s %d\n",&idx,s,&timeout);
      else
        sscanf(buffer,"Timeout=%s %d\n",s,&timeout);
      idx=getTimeoutIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numtimeout++;
    statemachine->timeout=(tmpnStateMachineTimeout *)realloc(statemachine->timeout,statemachine->numtimeout*sizeof(tmpnStateMachineTimeout));
      }
      strcpy(statemachine->timeout[idx].name,s);
      statemachine->timeout[idx].timeout=timeout;
    }
    else if(strncmp(buffer,"Input=",6)==0)
    {
      if(version==2)
        v = sscanf(buffer,"Input=%d,%s",&idx,name);
      else
        v = sscanf(buffer,"Input=%s",name) + 1;

      idx=getInputIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numinput++;
    statemachine->input=(tmpnStateMachineIO *)realloc(statemachine->input,statemachine->numinput*sizeof(tmpnStateMachineIO));
      }
      if(v!=2) error(ln, "wrong number of arguments");
   statemachine->input[idx].iotype=16;
      getComment(buffer,key);
      connectStatemachineAndIO(&statemachine->input[idx],name,key);
    }
    else if(strncmp(buffer,"Output=",7)==0)
    {
      if(version==2)
        v = sscanf(buffer,"Output=%d,%s",&idx,name);
      else
        v = sscanf(buffer,"Output=%s",name) + 1;

      idx=getOutputIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numoutput++;
    statemachine->output=(tmpnStateMachineIO *)realloc(statemachine->output,statemachine->numoutput*sizeof(tmpnStateMachineIO));
      }
      if(v!=2) error(ln, "wrong number of arguments");
   statemachine->output[idx].iotype=15;
      getComment(buffer,key);
      connectStatemachineAndIO(&statemachine->output[idx],name,key);
    }
    else if(strncmp(buffer,"Link=",5)==0)
    {
      key[0]=0;
      if(version==2)
        v = sscanf(buffer,"Link=%d,%s %s\n",&idx,s,key);
      else
        v = sscanf(buffer,"Link=%s %s\n",s,key) + 1;
      idx=getLinkIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numlink++;
    statemachine->link=(tmpnStateMachineLink *)realloc(statemachine->link,statemachine->numlink*sizeof(tmpnStateMachineLink));
      }
      if(v==2)
      {
        strcpy(statemachine->link[idx].localname,s);
        strcpy(statemachine->link[idx].name,s);
      }
      else
      {
        strcpy(statemachine->link[idx].localname,s);
        strcpy(statemachine->link[idx].name,key);
      }
    }
    else if(strncmp(buffer,"Delaystop=",10)==0) {
      sscanf(buffer,"Delaystop=%d\n",&delaystop);
      statemachine->delaystop=delaystop;
      printf(" delaystop!");
    }
    else if(strncmp(buffer,"Path=",5)==0)
    {
   int new;
      int mode;
      int type;
      tmpnPathHandle* path;

      v = sscanf(buffer,"Path=%s %s %s\n",s,a1,a2);
      if(v==3)
        v = sscanf(buffer,"Path=%s %d %d\n",s,&mode,&type);
   new=0;
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
    new=1;
      }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=24;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
      statemachine->value[idx].fdata=0;
   if (new)
   {
    path = (tmpnPathHandle*)malloc(sizeof(tmpnPathHandle));
    statemachine->value[idx].path = path;
   }
   else
   {
    path = statemachine->value[idx].path;
   }
      path->state=1;
      if(v==3)
      {
        strcpy(path->script,"");
        path->firstpoint=((void *)0);
        path->key.mode=mode;
        path->key.type=type;
      }
      else
      {
        strcpy(path->script,a1);
        path->firstpoint=((void *)0);
        path->key.mode=0;
        path->key.type=0;
      }

      strcpy(path->key.from.frame.name,"");
      path->key.from.frame.x=0.0;
      path->key.from.frame.y=0.0;
      path->key.from.frame.z=0.0;
      path->key.from.frame.v=0.0;
      path->key.from.frame.w=0.0;
      path->key.from.frame.u=0.0;
      path->key.from.cItem=0;
      path->key.from.cLayer=0;
      strcpy(path->key.from.itemName,"");
      strcpy(path->key.from.patternName,"");
      path->key.from.item=((void *)0);
      path->key.from.pattern=((void *)0);

      strcpy(path->key.to.frame.name,"");
      path->key.to.frame.x=0.0;
      path->key.to.frame.y=0.0;
      path->key.to.frame.z=0.0;
      path->key.to.frame.v=0.0;
      path->key.to.frame.w=0.0;
      path->key.to.frame.u=0.0;
      path->key.to.cItem=0;
      path->key.to.cLayer=0;
      strcpy(path->key.to.itemName,"");
      strcpy(path->key.to.patternName,"");
      path->key.to.item=((void *)0);
      path->key.to.pattern=((void *)0);
    }
    else if(strncmp(buffer,"Frame=",6)==0)
    {
   int new;
      tmpnFrame frame;
      tmpnFrame *pframe;
      float x,y,z,vv,w,u;
      v = sscanf(buffer,"Frame=%s x=%f y=%f z=%f v=%f w=%f u=%f\n",frame.name,&x,&y,&z,&vv,&w,&u);
      frame.x = x;
      frame.y = y;
      frame.z = z;
      frame.v = vv;
      frame.w = w;
      frame.u = u;

   if (v != 7) error(ln, "Wrong syntax in Frame");
   new=0;
      idx=getValueIdx(statemachine,frame.name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
    new=1;
      }
      strcpy(statemachine->value[idx].name,frame.name);
      statemachine->value[idx].type=25;
      statemachine->value[idx].subtype=1;
      statemachine->value[idx].data=0;
   if (new)
   {
    pframe = (tmpnFrame*)malloc(sizeof(tmpnFrame));
    statemachine->value[idx].frame = pframe;
   }
   else
   {
    pframe = statemachine->value[idx].frame;
   }
      strcpy(pframe->name,frame.name);
      pframe->x=frame.x;
      pframe->y=frame.y;
      pframe->z=frame.z;
      pframe->v=frame.v;
      pframe->w=frame.w;
      pframe->u=frame.u;
    }
    else if(strncmp(buffer,"Item=",5)==0)
    {
      char itemName[256];
      v = sscanf(buffer,"Item=%s %s\n",name,itemName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,itemName);
      statemachine->value[idx].type=26;
      statemachine->value[idx].subtype=1;
      statemachine->value[idx].data=0;
    }
    else if(strncmp(buffer,"Pattern=",8)==0)
    {
      char patternName[256];
      v = sscanf(buffer,"Pattern=%s %s\n",name,patternName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,patternName);
      statemachine->value[idx].type=27;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
    }
    else if(strncmp(buffer,"CPPattern=",10)==0)
    {
      char cppatternName[256];
      v = sscanf(buffer,"CPPattern=%s %s\n",name,cppatternName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
    statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,cppatternName);
      statemachine->value[idx].type=28;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
    }
  }
  fclose(fp);
 return 1;
}

int tmpnStateLoad(const char *filename, tmpnStateMachine *statemachine, int level)
{
  FILE *fp;
 char name[256], s[256],includename[256];
  char buffer[256];
 int version=0,idx;
 ln=0;
 fp = fopen(filename,"r");
  fscanf(fp,"STATEMACHINEVERSION %d\n",&version);
  ln++;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    ln++;
    if(strncmp(buffer, ";", 1)==0)
    {
    }
    else if(strncmp(buffer,"Include=",8)==0)
    {
   int oldln=ln;
   sscanf(buffer,"Include=%s",name);
      sprintf(includename,"%s/statemachine/%s",databasePath,name);
      tmpnStateLoad(includename, statemachine,level+1);
   ln=oldln;
    }
    else if(strncmp(buffer,"State=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"State=%d,%s\n",&idx,s);
      else
        sscanf(buffer,"State=%s\n",s);

      idx = getMachinePtrStateIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numstate++;
    statemachine->state=(tmpnStateMachineState *)realloc(statemachine->state,statemachine->numstate*sizeof(tmpnStateMachineState));
        statemachine->state[idx].maxprgidx=0;
    statemachine->state[idx].prg=((void *)0);
        statemachine->state[idx].statenum = idx;
        strcpy(statemachine->state[idx].name,s);
      }
      else
      {
        free(statemachine->state[idx].prg);
        statemachine->state[idx].maxprgidx=0;
    statemachine->state[idx].prg=((void *)0);
      }
   if (!strcmp(s,"ST_TIMER")) statemachine->timerstate=idx;
      getFunctionBody(fp, idx, statemachine);
    }
 }
  fclose(fp);
 return 1;
}

void setStateTekst(char *tekst, int kode, int line)
{
  int i,j;
  tmpnWorkcell *workcell=(tmpnWorkcell*)tworkcell;
 tmpnStateTeksts *stptr;
  sprintf(tekst,"%s","");
  j=0;
 stptr=&workcell->statetekstlist.stateteksts[workcell->statetekstlist.currentStateTekst];
  for(i=0;i<stptr->maxidx;i++)
  {
    if(stptr->item[i].idx==kode)
    {
      if(j==line)
      {
        sprintf(tekst,stptr->item[i].tekst);
        return;
      }
      if(j>0) return;
      j++;
    }
  }
}

int tmpnStateTekstsLoad(const char *filename, tmpnStateTekstList *statetekstlist)
{
  FILE *fp;
  int version,l;
  char buffer[256];
 tmpnStateTeksts *sts;
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"STATETEKSTVERSION %d\n",&version);
  if(version!=1) return 0;
 sts = &statetekstlist->stateteksts[statetekstlist->numofStateTeksts];
  fscanf(fp,"%s\n",sts->name);
  sts->maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  { sscanf(buffer,"%d",&sts->item[sts->maxidx].idx);
    strcpy(&sts->item[sts->maxidx].tekst[0],&buffer[6]);
    l=strlen(sts->item[sts->maxidx].tekst);
    sts->item[sts->maxidx].tekst[l-1]=0x0;
    sts->maxidx++;
  }
 statetekstlist->numofStateTeksts++;
  fclose(fp);

  return 1;
}

int tmpnLanguageLoad(const char *filename, tmpnLanguages *languages)
{
 int i,j;
  FILE *fp;
  int version;
  char buffer[256];
 int line;
 tmpnLanguage *lang;
  fp = fopen(filename,"r");
  if(fp==((void *)0))
 {
  printf("Couldn't open languagefile: %s\n",filename);
  return 0;
 }
  fscanf(fp,"LANGUAGEVERSION %d\n",&version);
  if(version!=1) return 0;
 lang=&languages->language[languages->numoflanguages++];
 lang->maxidx=0;
  fscanf(fp,"%s\n",lang->name);
 line=3;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
  if (buffer[0]!=';')
  {
   sscanf(buffer,"%d",&lang->item[lang->maxidx].key);
   int dplace[4]={0,0,0,0};
   int success=0;
   int dotplace=0;
   for (j=0;j<4;j++)
   {
    for (i=dotplace+1;i<strlen(buffer);i++)
    {
     if (buffer[i]=='"')
     {
      dplace[success++]=i;
      dotplace=i;
     }
    }
   }
   if (success!=4)
   {
    printf("Unknown languageline-type '%s' in .language file line %d\n",buffer,line);
    exit(99);
   }
   int tekstlen=dplace[1]-dplace[0]-1;
   int englishlen=dplace[3]-dplace[2]-1;
   strncpy(lang->item[lang->maxidx].tekst,&buffer[dplace[0]+1],tekstlen);
   strncpy(lang->item[lang->maxidx].english,&buffer[dplace[2]+1],englishlen);
   lang->maxidx++;
  }
  line++;
  }
  fclose(fp);
  return 1;
}

int tmpnPPScriptLoad(const char *filename, tmpnPPScript *ppscript)
{

  FILE *fp;
  int version;
  char buffer[256];
  char fromstr[256];
  char tostr[256];
  char *bracket;
  int retval;

  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"PPSCRIPTVERSION %d\n",&version);
  if(version!=1&&version!=2) return 0;
  if(version==1) ppscript->layers=0;
  fscanf(fp,"%s\n",ppscript->name);
  ppscript->maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"itemsPrLayer=",13)==0)
    {
      sscanf(buffer,"itemsPrLayer=%d\n",&ppscript->itemsPrLayer);
    }
    else if(strncmp(buffer,"layers=",7)==0)
    {
      sscanf(buffer,"layers=%d\n",&ppscript->layers);
    }
    else if(strncmp(buffer,"type=",5)==0)
    {
      sscanf(buffer,"type=%d\n",&ppscript->type);
    }
    else if(strncmp(buffer,"move",4)==0)
    {
      sscanf(buffer,"%s %s from %s to %s\n"
       ,ppscript->item[ppscript->maxidx].cmd
       ,ppscript->item[ppscript->maxidx].item
       ,fromstr
       ,tostr);
      bracket = strchr(fromstr, '(');
      if (bracket != 0)
      {
        *bracket = ' ';
        float x,y,z,v,w,u;
        retval=sscanf(fromstr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
           ,ppscript->item[ppscript->maxidx].from
           ,&ppscript->item[ppscript->maxidx].layer
           ,&ppscript->item[ppscript->maxidx].idx
           ,&x
           ,&y
           ,&z
           ,&v
           ,&w
           ,&u);
    ppscript->item[ppscript->maxidx].wcp.x = x;
       ppscript->item[ppscript->maxidx].wcp.y = y;
    ppscript->item[ppscript->maxidx].wcp.z = z;
    ppscript->item[ppscript->maxidx].wcp.v = v;
    ppscript->item[ppscript->maxidx].wcp.w = w;
    ppscript->item[ppscript->maxidx].wcp.u = u;
# 5382 "cmd.c"
    if (retval==3)
    {
     ppscript->item[ppscript->maxidx].wcp.x = 0.0;
     ppscript->item[ppscript->maxidx].wcp.y = 0.0;
     ppscript->item[ppscript->maxidx].wcp.z = 0.0;
     ppscript->item[ppscript->maxidx].wcp.v = 0.0;
     ppscript->item[ppscript->maxidx].wcp.w = 0.0;
     ppscript->item[ppscript->maxidx].wcp.u = 0.0;
    }
      }
      else
      {
        strcpy(ppscript->item[ppscript->maxidx].from,fromstr);
      }
      bracket = strchr(tostr, '(');
      if (bracket != 0)
      {
        *bracket = ' ';
        float x,y,z,v,w,u;
        retval=sscanf(tostr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
           ,ppscript->item[ppscript->maxidx].to
           ,&ppscript->item[ppscript->maxidx].layer
           ,&ppscript->item[ppscript->maxidx].idx
           ,&x
           ,&y
           ,&z
           ,&v
           ,&w
           ,&u);
    ppscript->item[ppscript->maxidx].wcp.x = x;
       ppscript->item[ppscript->maxidx].wcp.y = y;
    ppscript->item[ppscript->maxidx].wcp.z = z;
    ppscript->item[ppscript->maxidx].wcp.v = v;
    ppscript->item[ppscript->maxidx].wcp.w = w;
    ppscript->item[ppscript->maxidx].wcp.u = u;
# 5427 "cmd.c"
    if (retval==3)
    {
     ppscript->item[ppscript->maxidx].wcp.x = 0.0;
     ppscript->item[ppscript->maxidx].wcp.y = 0.0;
     ppscript->item[ppscript->maxidx].wcp.z = 0.0;
     ppscript->item[ppscript->maxidx].wcp.v = 0.0;
     ppscript->item[ppscript->maxidx].wcp.w = 0.0;
     ppscript->item[ppscript->maxidx].wcp.u = 0.0;
    }
      }
      else
      {
        strcpy(ppscript->item[ppscript->maxidx].to,tostr);
      }
      ppscript->maxidx++;
    }
  }
  fclose(fp);
  return 1;
}

int tmpnBoptCoeffLoad(const char *filename, tmpnBoptCoeff *boptcoeff)
{
  FILE *fp;
  int version;
  char buffer[1024];
 char string[256];
  char str[16][256];
 char *pstr;
 float val[16];
  int retval;
 int i,j;

  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  strcpy(boptcoeff->filename,filename);
  fscanf(fp,"BOPTCOEFFVERSION %d\n",&version);
  if(version!=1) return 0;
  fscanf(fp,"%127s\n",boptcoeff->name);
  boptcoeff->maxidx=0;

 for (i=0;i<40;i++)
 {
  boptcoeff->item[i].pathName[0]=0x0;
  boptcoeff->item[i].pathtype=0;
  boptcoeff->item[i].viatype=0;
  for (j=0;j<16;j++)
  {
   boptcoeff->item[i].viapos[0].x[j].value=0.0;
   boptcoeff->item[i].viapos[1].x[j].value=0.0;
   boptcoeff->item[i].viavel[0].x[j].value=0.0;
   boptcoeff->item[i].viavel[1].x[j].value=0.0;
   boptcoeff->item[i].viapos[0].y[j].value=0.0;
   boptcoeff->item[i].viapos[1].y[j].value=0.0;
   boptcoeff->item[i].viavel[0].y[j].value=0.0;
   boptcoeff->item[i].viavel[1].y[j].value=0.0;
   boptcoeff->item[i].viapos[0].z[j].value=0.0;
   boptcoeff->item[i].viapos[1].z[j].value=0.0;
   boptcoeff->item[i].viavel[0].z[j].value=0.0;
   boptcoeff->item[i].viavel[1].z[j].value=0.0;
   boptcoeff->item[i].viapos[0].v[j].value=0.0;
   boptcoeff->item[i].viapos[1].v[j].value=0.0;
   boptcoeff->item[i].viavel[0].v[j].value=0.0;
   boptcoeff->item[i].viavel[1].v[j].value=0.0;
   boptcoeff->item[i].viapos[0].w[j].value=0.0;
   boptcoeff->item[i].viapos[1].w[j].value=0.0;
   boptcoeff->item[i].viavel[0].w[j].value=0.0;
   boptcoeff->item[i].viavel[1].w[j].value=0.0;
   boptcoeff->item[i].viapos[0].x[j].ABS=0;
   boptcoeff->item[i].viapos[1].x[j].ABS=0;
   boptcoeff->item[i].viapos[0].y[j].ABS=0;
   boptcoeff->item[i].viapos[1].y[j].ABS=0;
   boptcoeff->item[i].viapos[0].z[j].ABS=0;
   boptcoeff->item[i].viapos[1].z[j].ABS=0;
   boptcoeff->item[i].viapos[0].v[j].ABS=0;
   boptcoeff->item[i].viapos[1].v[j].ABS=0;
   boptcoeff->item[i].viapos[0].w[j].ABS=0;
   boptcoeff->item[i].viapos[1].w[j].ABS=0;
  }
  boptcoeff->item[i].macro[0].integer[0]=0;
  boptcoeff->item[i].macro[0].integer[1]=0;
  boptcoeff->item[i].macro[0].floating[0]=200.0;
  boptcoeff->item[i].macro[0].floating[1]=0.3;
  boptcoeff->item[i].macro[0].floating[2]=0.0;
  boptcoeff->item[i].macro[0].floating[3]=0.0;
  boptcoeff->item[i].macro[0].floating[4]=0.0;
  boptcoeff->item[i].macro[0].floating[5]=0.0;
  boptcoeff->item[i].macro[1].integer[0]=0;
  boptcoeff->item[i].macro[1].integer[1]=0;
  boptcoeff->item[i].macro[1].floating[0]=200.0;
  boptcoeff->item[i].macro[1].floating[1]=0.3;
  boptcoeff->item[i].macro[1].floating[2]=0.0;
  boptcoeff->item[i].macro[1].floating[3]=0.0;
  boptcoeff->item[i].macro[1].floating[4]=0.0;
  boptcoeff->item[i].macro[1].floating[5]=0.0;
  boptcoeff->item[i].params.integer[0]=0;
  boptcoeff->item[i].params.integer[1]=0;
  boptcoeff->item[i].params.floating[0]=2100.0;
  boptcoeff->item[i].params.floating[1]=250.0;
  boptcoeff->item[i].params.floating[2]=25.0;
  boptcoeff->item[i].params.floating[3]=1.0;
  boptcoeff->item[i].params.floating[4]=3500.0;
  boptcoeff->item[i].params.floating[5]=1000.0;
  boptcoeff->item[i].mv[0]=1.7;
  boptcoeff->item[i].mv[1]=3.11;
  boptcoeff->item[i].mv[2]=3.24;
  boptcoeff->item[i].mv[3]=2.62;
  boptcoeff->item[i].mv[4]=5.23;
  boptcoeff->item[i].ma[0]=4.2;
  boptcoeff->item[i].ma[1]=2.2;
  boptcoeff->item[i].ma[2]=5;
  boptcoeff->item[i].ma[3]=6;
  boptcoeff->item[i].ma[4]=6;
 }
  while (fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
  if (!strncmp(buffer,"mode",4))
    {
      retval=sscanf(buffer,"mode %d pathtype %d :\n",&boptcoeff->item[boptcoeff->maxidx].mode,&boptcoeff->item[boptcoeff->maxidx].pathtype);
   if (retval==2)
   {
    boptcoeff->maxidx++;
    if (boptcoeff->maxidx > 40)
    {
     printf("BoptCoeff: Number of boptcoeff items exeeds MAXBOPTCOEFFITEMS\n");
     exit(99);
    }
   }
   else
    return 0;
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"(%d,%d)"
       ,boptcoeff->item[boptcoeff->maxidx-1].mode
       ,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s","NULL");
  }
  else if (!strncmp(buffer,"ppscripttype",12))
    {
      retval=sscanf(buffer,"ppscripttype %d pathtype %d :\n",&boptcoeff->item[boptcoeff->maxidx].mode,&boptcoeff->item[boptcoeff->maxidx].pathtype);
   if (retval==2)
   {
    boptcoeff->maxidx++;
    if (boptcoeff->maxidx > 40)
    {
     printf("BoptCoeff: Number of boptcoeff items exeeds MAXBOPTCOEFFITEMS\n");
     exit(99);
    }
   }
   else
    return 0;
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"(%d,%d)"
       ,boptcoeff->item[boptcoeff->maxidx-1].mode
       ,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s","NULL");
  }
   else if (strncmp(buffer,"pathName",8)==0)
  {
   sscanf(buffer,"pathName %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"%s (%d,%d)"
       ,string
       ,boptcoeff->item[boptcoeff->maxidx-1].mode
       ,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
    }
   else if (strncmp(buffer,"def.fromFrame",13)==0)
  {
   sscanf(buffer,"def.fromFrame %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s"
       ,string);
    }
   else if (strncmp(buffer,"def.toFrame",11)==0)
  {
   sscanf(buffer,"def.toFrame %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s"
       ,string);
    }
   else if (strncmp(buffer,"def.fromItem",12)==0)
  {
   sscanf(buffer,"def.fromItem %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s"
       ,string);
    }
   else if (strncmp(buffer,"def.toItem",10)==0)
  {
   sscanf(buffer,"def.toItem %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s"
       ,string);
    }
   else if (strncmp(buffer,"def.fromPattern",15)==0)
  {
   sscanf(buffer,"def.fromPattern %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s"
       ,string);
    }
   else if (strncmp(buffer,"def.toPattern",13)==0)
  {
   sscanf(buffer,"def.toPattern %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s"
       ,string);
    }
  else if (boptcoeff->maxidx>0)
  {
      if (strncmp(buffer,"viatype",7)==0)
   {
    retval=sscanf(buffer,"viatype %255s\n",string);
    if (retval==1)
    {
     if(strncmp(string,"NONE",4)==0)
     {
      boptcoeff->item[boptcoeff->maxidx-1].viatype=0;
     }
     else if(strncmp(string,"START",5)==0)
     {
      boptcoeff->item[boptcoeff->maxidx-1].viatype=1;
     }
     else if(strncmp(string,"END",3)==0)
     {
      boptcoeff->item[boptcoeff->maxidx-1].viatype=2;
     }
     else if(strncmp(string,"BOTH",4)==0)
     {
      boptcoeff->item[boptcoeff->maxidx-1].viatype=3;
     }
    }
    else
    {
     return 0;
    }
   }
   else if (!strncmp(buffer,"via1pos.x",9)||!strncmp(buffer,"via1pos.y",9)||!strncmp(buffer,"via1pos.z",9)||!strncmp(buffer,"via1pos.v",9)||!strncmp(buffer,"via1pos.w",9)||!strncmp(buffer,"via2pos.x",9)||!strncmp(buffer,"via2pos.y",9)||!strncmp(buffer,"via2pos.z",9)||!strncmp(buffer,"via2pos.v",9)||!strncmp(buffer,"via2pos.w",9)||!strncmp(buffer,"via1abs.x",9)||!strncmp(buffer,"via1abs.y",9)||!strncmp(buffer,"via1abs.z",9)||!strncmp(buffer,"via1abs.v",9)||!strncmp(buffer,"via1abs.w",9)||!strncmp(buffer,"via2abs.x",9)||!strncmp(buffer,"via2abs.y",9)||!strncmp(buffer,"via2abs.z",9)||!strncmp(buffer,"via2abs.v",9)||!strncmp(buffer,"via2abs.w",9)||!strncmp(buffer,"via1vel.x",9)||!strncmp(buffer,"via1vel.y",9)||!strncmp(buffer,"via1vel.z",9)||!strncmp(buffer,"via1vel.v",9)||!strncmp(buffer,"via1vel.w",9)||!strncmp(buffer,"via2vel.x",9)||!strncmp(buffer,"via2vel.y",9)||!strncmp(buffer,"via2vel.z",9)||!strncmp(buffer,"via2vel.v",9)||!strncmp(buffer,"via2vel.w",9))
   {
    tmpnBoptParamStruct* fbuf=((void *)0);
    if (!strncmp(&buffer[4],"pos",3)||!strncmp(&buffer[4],"abs",3))
    {
     if (buffer[3]=='1') {
      if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].x;
      else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].y;
      else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].z;
      else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].v;
      else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].w;
      else return 0;
     }
     else if (buffer[3]=='2') {
      if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].x;
      else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].y;
      else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].z;
      else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].v;
      else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].w;
      else return 0;
     }
    }
    else if (!strncmp(&buffer[4],"vel",3))
    {
     if (buffer[3]=='1') {
      if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].x;
      else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].y;
      else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].z;
      else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].v;
      else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].w;
      else return 0;
     }
     else if (buffer[3]=='2') {
      if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].x;
      else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].y;
      else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].z;
      else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].v;
      else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].w;
      else return 0;
     }
    }
    if (!strncmp(&buffer[4],"abs",3))
    {
     for (i=0;i<16;i++)
     {
      fbuf[i].ABS=1;
     }
    }
    else if (!strncmp(&buffer[4],"pos",3))
    {
     for (i=0;i<16;i++)
     {
      fbuf[i].ABS=0;
     }
    }
    retval=sscanf(buffer,"%s %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",string,&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4],&str[5][0],&val[5],&str[6][0],&val[6],&str[7][0],&val[7],&str[8][0],&val[8],&str[9][0],&val[9],&str[10][0],&val[10],&str[11][0],&val[11],&str[12][0],&val[12],&str[13][0],&val[13],&str[14][0],&val[14],&str[15][0],&val[15]);
    if ((retval>=3)&&(retval%1==0))
    {
     int slen;
     int maxi=(retval-1)/2;
     for (i=0;i<maxi;i++)
     {
      pstr=&str[i][0];
      slen = strlen(pstr);
      if (slen>16) return 0;
      fbuf[i].numofparams=slen;
      fbuf[i].value=val[i];
      for (j=0;j<slen;j++)
      {
       if ((pstr[j]=='c')||(pstr[j]=='f')||(pstr[j]=='b')||(pstr[j]=='p')||(pstr[j]=='g')||(pstr[j]=='l')||(pstr[j]=='h')||(pstr[j]=='t')||(pstr[j]=='r'))
       {
        fbuf[i].table[j]=pstr[j];
       }
       else return 0;
      }
     }
    }
    else
    {
     return 0;
    }
   }
   else if (!strncmp(buffer,"macro1",6)||!strncmp(buffer,"macro2",6))
   {
    tmpnBoptMacroItem* pmac=((void *)0);
    if (buffer[5]=='1')
    {
     pmac = &boptcoeff->item[boptcoeff->maxidx-1].macro[0];
    }
    else if (buffer[5]=='2')
    {
     pmac = &boptcoeff->item[boptcoeff->maxidx-1].macro[1];
    }
    retval=sscanf(buffer,"%s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s\n",string,&str[0][0],&str[1][0],&str[2][0],&str[3][0],&str[4][0],&str[5][0],&str[6][0],&str[7][0],&str[8][0],&str[9][0],&str[10][0],&str[11][0],&str[12][0],&str[13][0],&str[14][0],&str[15][0]);
    if ((retval>=3)&&(retval%1==0))
    {
     int maxi=(retval-1);
     pstr=&str[0][0];
     for (i=0;i<maxi;i+=2)
     {
      pstr=&str[i][0];
      if (!strncmp(pstr,"type",4))
      {
       if (!strncmp(&str[i+1][0],"NOMACRO",7))
        pmac->integer[0]=0;
       else if (!strncmp(&str[i+1][0],"SPIRAL",6))
        pmac->integer[0]=1;
       else if (!strncmp(&str[i+1][0],"UPLINE",6))
        pmac->integer[0]=2;
       else if (!strncmp(&str[i+1][0],"DOWNLINE",8))
        pmac->integer[0]=3;
       else if (!strncmp(&str[i+1][0],"FASTUPLINE",10))
        pmac->integer[0]=4;
       else if (!strncmp(&str[i+1][0],"FASTDOWNLINE",12))
        pmac->integer[0]=5;
      }
      else if (!strncmp(pstr,"positionhint",12))
      {
       int phint;
       retval=sscanf(&str[i+1][0],"%d",&phint);
       if (retval==1)
        pmac->integer[1]=phint;
      }
      else if (!strncmp(pstr,"length",6))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[0]=fval;
      }
      else if (!strncmp(pstr,"time",4))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[1]=fval;
      }
      else if (!strncmp(pstr,"amplitude",9))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[2]=fval;
      }
      else if (!strncmp(pstr,"offsx",5))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[3]=fval;
      }
      else if (!strncmp(pstr,"offsz",5))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[4]=fval;
      }
      else if (!strncmp(pstr,"frequency",9))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pmac->floating[5]=fval;
      }
     }
    }
   }
   else if (!strncmp(buffer,"params",6))
   {
    tmpnBoptParamItem* pparam;
    pparam = &boptcoeff->item[boptcoeff->maxidx-1].params;
    retval=sscanf(buffer,"%s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s\n",string,&str[0][0],&str[1][0],&str[2][0],&str[3][0],&str[4][0],&str[5][0],&str[6][0],&str[7][0],&str[8][0],&str[9][0],&str[10][0],&str[11][0],&str[12][0],&str[13][0],&str[14][0],&str[15][0]);
    if ((retval>=3)&&(retval%1==0))
    {
     int maxi=(retval-1);
     for (i=0;i<maxi;i+=2)
     {
      pstr=&str[i][0];
      if (!strncmp(pstr,"tcpidx",6))
      {
       int tcp;
       retval=sscanf(&str[i+1][0],"%d",&tcp);
       if (retval==1)
        pparam->integer[0]=tcp;
      }
      else if (!strncmp(pstr,"blendtype",9))
      {
       int bt;
       retval=sscanf(&str[i+1][0],"%d",&bt);
       if (retval==1)
        pparam->integer[1]=bt;
      }
      else if (!strncmp(pstr,"maxheight",9))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[0]=fval;
      }
      else if (!strncmp(pstr,"minheight",9))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[1]=fval;
      }
      else if (!strncmp(pstr,"samplerate",10))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[2]=fval;
      }
      else if (!strncmp(pstr,"timefactor",10))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[3]=fval;
      }
      else if (!strncmp(pstr,"maxlength",9))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[4]=fval;
      }
      else if (!strncmp(pstr,"lockv",5))
      {
       float fval;
       retval=sscanf(&str[i+1][0],"%f",&fval);
       if (retval==1)
        pparam->floating[5]=fval;
      }
     }
    }
   }
   else if (!strncmp(buffer,"mv",2))
   {
    retval=sscanf(buffer,"mv %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4]);
    if ((retval>=2)&&(retval%2==0))
    {
     int maxi=retval/2;
     for (i=0;i<maxi;i++)
     {
      pstr=&str[i][0];
      if (!strncmp(pstr,"a",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].mv[0]=val[i];
      }
      else if (!strncmp(pstr,"b",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].mv[1]=val[i];
      }
      else if (!strncmp(pstr,"c",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].mv[2]=val[i];
      }
      else if (!strncmp(pstr,"d",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].mv[3]=val[i];
      }
      else if (!strncmp(pstr,"e",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].mv[4]=val[i];
      }
     }
    }
   }
   else if (!strncmp(buffer,"ma",2))
   {
    retval=sscanf(buffer,"ma %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4]);
    if ((retval>=2)&&(retval%2==0))
    {
     int maxi=retval/2;
     for (i=0;i<maxi;i++)
     {
      pstr=&str[i][0];
      if (!strncmp(pstr,"a",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].ma[0]=val[i];
      }
      else if (!strncmp(pstr,"b",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].ma[1]=val[i];
      }
      else if (!strncmp(pstr,"c",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].ma[2]=val[i];
      }
      else if (!strncmp(pstr,"d",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].ma[3]=val[i];
      }
      else if (!strncmp(pstr,"e",1))
      {
       boptcoeff->item[boptcoeff->maxidx-1].ma[4]=val[i];
      }
     }
    }
   }
  }
  else
  {
   return 0;
  }
  }
  fclose(fp);
  return 1;
}

int tmpnBoptCoeffSave(tmpnBoptCoeff *boptcoeff)
{
 FILE *fp;
 char string[1024];
 int i,j;

  fp = fopen(boptcoeff->filename,"w");
  if(fp==((void *)0))
 {
    printf("Couldn't open %s for writing!\n",boptcoeff->filename);
  return 0;
 }
 fprintf(fp,"BOPTCOEFFVERSION %d\n",1);
 fprintf(fp,"%s\n",boptcoeff->name);
 for (i=0;i<boptcoeff->maxidx;i++)
 {
  fprintf(fp,"\n");
  fprintf(fp,"mode %d pathtype %d :\n",boptcoeff->item[i].mode,boptcoeff->item[i].pathtype);
  fprintf(fp,"pathName %s\n",boptcoeff->item[i].pathName);
  switch (boptcoeff->item[i].viatype)
  {
  case 0:
   fprintf(fp,"viatype NONE\n");
   break;
  case 1:
   fprintf(fp,"viatype START\n");
   break;
  case 2:
   fprintf(fp,"viatype END\n");
   break;
  case 3:
   fprintf(fp,"viatype BOTH\n");
   break;
  }
  int notempty;
  int stl;
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].x[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f",val);
   }
  }
  if (notempty) fprintf(fp,"via1pos.x %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].y[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f",val);
   }
  }
  if (notempty) fprintf(fp,"via1pos.y %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].z[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f",val);
   }
  }
  if (notempty) fprintf(fp,"via1pos.z %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].v[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f",val);
   }
  }
  if (notempty) fprintf(fp,"via1pos.v %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].w[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f",val);
   }
  }
  if (notempty) fprintf(fp,"via1pos.w %s\n",string);

  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].x[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via1vel.x %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].y[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via1vel.y %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].z[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via1vel.z %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].v[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via1vel.v %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].w[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via1vel.w %s\n",string);

  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].x[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2pos.x %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].y[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2pos.y %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].z[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2pos.z %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].v[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2pos.v %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].w[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2pos.w %s\n",string);

  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].x[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2vel.x %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].y[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2vel.y %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].z[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2vel.z %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].v[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2vel.v %s\n",string);
  stl=0;
  notempty=0;
  string[0]='\0';
  for (j=0;j<16;j++)
  {
   tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].w[j];
   float val = fbuf->value;
   if (val!=0.0000)
   {
    notempty=1;
    stl=strlen(string);
    for (i=0;i<fbuf->numofparams;i++)
    {
     string[stl+i]=fbuf->table[i];
    }
    string[stl+i+1]='\0';
    stl=strlen(string);
    sprintf(&string[stl],"=%0.4f ",val);
   }
  }
  if (notempty) fprintf(fp,"via2vel.w %s\n",string);

  for (j=0;j<2;j++)
  {
   int macrotype;
   macrotype=boptcoeff->item[i].macro[j].integer[0];
   switch (macrotype)
   {
   case 0:
    sprintf(string,"macro%d type=NOMACRO",j+1);
    break;
   case 1:
    sprintf(string,"macro%d type=SPIRAL",j+1);
    break;
   case 2:
    sprintf(string,"macro%d type=UPLINE",j+1);
    break;
   case 3:
    sprintf(string,"macro%d type=DOWNLINE",j+1);
    break;
   case 4:
    sprintf(string,"macro%d type=FASTUPLINE",j+1);
    break;
   case 5:
    sprintf(string,"macro%d type=FASTDOWNLINE",j+1);
    break;
   default:
    sprintf(string,"macro%d type=UNKNOWN!!!!",j+1);
   }
   if (macrotype!=0)
   {
    int m;
    float f;
    m=boptcoeff->item[i].macro[j].integer[1];
    if (m!=0)
    {
     stl=strlen(string);
     sprintf(&string[stl]," positionhint=%i",m);
    }
    f=boptcoeff->item[i].macro[j].floating[0];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," length=%0.4f",f);
    }
    f=boptcoeff->item[i].macro[j].floating[1];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," time=%0.4f",f);
    }
    f=boptcoeff->item[i].macro[j].floating[2];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," amplitude=%0.4f",f);
    }
    f=boptcoeff->item[i].macro[j].floating[3];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," offsx=%0.4f",f);
    }
    f=boptcoeff->item[i].macro[j].floating[4];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," offsy=%0.4f",f);
    }
    f=boptcoeff->item[i].macro[j].floating[5];
    if (f!=0.00)
    {
     stl=strlen(string);
     sprintf(&string[stl]," frequency=%0.4f",f);
    }
   }
   fprintf(fp,"%s\n",string);
  }

  float f;
  int m;
  char *jnames[5]={"a","b","c","d","e"};

  sprintf(string,"mv");
  notempty=0;
  for (j=0;j<5;j++)
  {
   f=boptcoeff->item[i].mv[j];
   if (f!=0.00)
   {
    notempty=1;
    stl=strlen(string);
    sprintf(&string[stl]," %s=%0.4f",jnames[j],f);
   }
  }
  if (notempty) fprintf(fp,"%s\n",string);
  sprintf(string,"ma");
  notempty=0;
  for (j=0;j<5;j++)
  {
   f=boptcoeff->item[i].ma[j];
   if (f!=0.00)
   {
    notempty=1;
    stl=strlen(string);
    sprintf(&string[stl]," %s=%0.4f",jnames[j],f);
   }
  }
  if (notempty) fprintf(fp,"%s\n",string);

  sprintf(string,"params");
  m=boptcoeff->item[i].params.integer[0];
  stl=strlen(string);
  sprintf(&string[stl]," tcpidx=%i",m);
  m=boptcoeff->item[i].params.integer[1];
  stl=strlen(string);
  sprintf(&string[stl]," blendtype=%i",m);
  f=boptcoeff->item[i].params.floating[0];
  if (f!=0.00)
  {
   stl=strlen(string);
   sprintf(&string[stl]," maxheight=%0.4f",f);
  }
  f=boptcoeff->item[i].params.floating[1];
  if (f!=0.00)
  {
   stl=strlen(string);
   sprintf(&string[stl]," minheight=%0.4f",f);
  }
  f=boptcoeff->item[i].params.floating[2];
  if (f!=0.00)
  {
   stl=strlen(string);
   sprintf(&string[stl]," samplerate=%0.4f",f);
  }
  f=boptcoeff->item[i].params.floating[3];
  if (f!=0.00)
  {
   stl=strlen(string);
   sprintf(&string[stl]," timefactor=%0.4f",f);
  }
  f=boptcoeff->item[i].params.floating[4];
  if (f!=0.00)
  {
   stl=strlen(string);
   sprintf(&string[stl]," maxlength=%0.4f",f);
  }
  f=boptcoeff->item[i].params.floating[5];
  if (f!=1000.0)
  {
   stl=strlen(string);
   sprintf(&string[stl]," lockv=%0.4f",f);
  }
  fprintf(fp,"%s\n",string);
 }
 fclose(fp);
 return 1;
}

int tmpnItemLoad(const char *filename, tmpnItem *item)
{
  FILE *fp;
  int version,user;
  float x,y,z,sy,gy,my,gx,weight;
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  strcpy(item->filename,filename);
  fscanf(fp,"VERSION %d\n",&version);
 if (version==2)
 {
  fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,weight=%f\n"
      ,item->type
      ,item->name
      ,&x
      ,&y
      ,&z
      ,&sy
      ,&gy
      ,&my
      ,&weight
      );
   item->dim.x = x;
   item->dim.y = y;
  item->dim.z = z;
  item->sy = sy;
  item->gy = gy;
  item->my = my;
  item->weight=weight;
  item->gx=item->dim.x;
    item->user = 0;
  return 1;
 }
  else if (version==3)
  {
    fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,gx=%f,weight=%f\n"
           ,item->type
           ,item->name
           ,&x
           ,&y
           ,&z
           ,&sy
           ,&gy
           ,&my
           ,&gx
           ,&weight
           );
   item->dim.x = x;
   item->dim.y = y;
  item->dim.z = z;
  item->sy = sy;
  item->gy = gy;
  item->my = my;
  item->gx = gx;
  item->weight=weight;
    item->user = 0;
  }
  else if(version!=4) return 0;
  fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,gx=%f,weight=%f,user=%d\n"
     ,item->type
     ,item->name
     ,&x
     ,&y
     ,&z
     ,&sy
     ,&gy
     ,&my
     ,&gx
     ,&weight
         ,&user
     );
  item->dim.x = x;
  item->dim.y = y;
  item->dim.z = z;
  item->sy = sy;
  item->gy = gy;
  item->my = my;
  item->gx = gx;
  item->weight=weight;
  item->user = user;

  return 1;
}

int tmpnItemSave(tmpnItem *item)
{
  FILE *fp;
  if(item->user == 0)
  {
    printf("Couldn't save Item file: %s, user=0\n",item->filename);
    return 0;
  }

  fp = fopen(item->filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open Item file: %s\n",item->filename);
    return 0;
  }
 fprintf(fp,"VERSION %d\n",4);

  fprintf(fp,"%s %s dx=%.2f,dy=%.2f,dz=%.2f,sy=%.2f,gy=%.2f,my=%.2f,gx=%.2f,weight=%.2f,user=%d\n"
          ,item->type
          ,item->name
          ,item->dim.x
          ,item->dim.y
          ,item->dim.z
          ,item->sy
          ,item->gy
          ,item->my
          ,item->gx
          ,item->weight
          ,item->user);
  fclose(fp);
  return 1;
}

int tmpnToolLoad(const char *filename, tmpnTool *tool)
{
  FILE *fp;
  int version;
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=2) return 0;
  float x,y,z,weight;
 int ipl;
  fscanf(fp,"%s dx=%f,dy=%f,dz=%f,weight=%f,itemsperlift=%d\n"
     ,tool->name
     ,&x
     ,&y
     ,&z
     ,&weight
     ,&ipl
     );
  tool->dim.x = x;
 tool->dim.y = y;
  tool->dim.z = z;
  tool->weight = weight;
 tool->itemsperlift=ipl;
  return 1;
}

int tmpnScopeLoad(const char *filename, tmpnPath *path)
{
  FILE *fp;
  char ax;
  int idx,z;
  int lastidx;
  int axisidx;
  float dat;
  char buffer[256];
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  lastidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    sscanf(buffer,"%4d%c %f\n"
      ,&idx
      ,&ax
      ,&dat);
    idx=idx*path->maxidx/1000;
    axisidx=0;
    if(ax=='A')
    {
      axisidx=0;
      dat=dat*0.19*1.6;
    }
    if(ax=='B')
    {
      axisidx=1;
      dat=dat*0.30*1.6;
    }
    if(ax=='C')
    {
      axisidx=2;
      dat=dat*0.19*1.6;
    }
    if(ax=='D')
    {
      axisidx=3;
      dat=dat*0.05*1.6;
    }
    if(ax=='E')
    {
      axisidx=4;
      dat=dat*0.05*1.6;
    }
    path->position[idx].scope.array[axisidx]=trobot->m_sign.array[axisidx]
                                            *trobot->m_gearing.array[axisidx]*dat;

    for(z=lastidx+1;z<idx;z++)
    {
      path->position[z].scope.array[axisidx]=path->position[idx].scope.array[axisidx];
    }
    lastidx=idx;
  }
  fclose(fp);
  return 1;
}

int tmpnAccessoryLoad(const char *filename, tmpnAccessory *accessory)
{
  FILE *fp;
  float x,y,z;
  int version;
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=1) return 0;
  fscanf(fp,"%s\n",accessory->name);
  fscanf(fp,"dimention x=%f,y=%f,z=%f\n"
    ,&x
    ,&y
    ,&z
    );
    accessory->dimention.x = x;
    accessory->dimention.y = y;
    accessory->dimention.z = z;

  fscanf(fp,"transformation x=%f,y=%f,z=%f\n"
    ,&accessory->transformation.x
    ,&accessory->transformation.y
    ,&accessory->transformation.z
    );
  fscanf(fp,"material diffuse r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.diffuse[0]
    ,&accessory->material.diffuse[1]
    ,&accessory->material.diffuse[2]
    ,&accessory->material.diffuse[3]
    );
  fscanf(fp,"material ambient r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.ambient[0]
    ,&accessory->material.ambient[1]
    ,&accessory->material.ambient[2]
    ,&accessory->material.ambient[3]
    );
  fscanf(fp,"material specular r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.specular[0]
    ,&accessory->material.specular[1]
    ,&accessory->material.specular[2]
    ,&accessory->material.specular[3]
    );
  fscanf(fp,"shininess=%f\n",&accessory->material.shininess);
  return 1;
}

tmpnItem *getItem(const char *name, tmpnWorkcell *workcell)
{
  int i;
  if(workcell==((void *)0)) return ((void *)0);
 if(name==((void *)0)) return ((void *)0);
  for(i=0;i<workcell->items.maxidx;i++)
  {
    if(strcmp(workcell->items.item[i].name,name)==0)
    {
      return &workcell->items.item[i];
    }
  }
  if(strcmp(name,"default")==0) return &workcell->items.item[0];
  return ((void *)0);
}

tmpnTool *getTool(const char *name, tmpnWorkcell *workcell)
{
  int i;
  if(workcell==((void *)0)) return ((void *)0);
  for(i=0;i<workcell->tools.maxidx;i++)
  {
    if(strcmp(workcell->tools.tool[i].name,name)==0)
    {
      return &workcell->tools.tool[i];
    }
  }
  if(strcmp(name,"default")==0) return &workcell->tools.tool[0];
  return ((void *)0);
}

tmpnPattern *getPattern(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->patterns.maxidx;i++)
  {
    if(strcmp(workcell->patterns.pattern[i].name,name)==0)
    {
      return &workcell->patterns.pattern[i];
    }
  }
  return ((void *)0);
}

tmpnCPPattern *getCPPattern(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->cppatterns.maxidx;i++)
  {
    if(strcmp(workcell->cppatterns.cppattern[i].name,name)==0)
    {
      return &workcell->cppatterns.cppattern[i];
    }
  }
  return ((void *)0);
}

tmpnPPScript *getPPScript(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->ppscripts.maxidx;i++)
  {
    if(strcmp(workcell->ppscripts.ppscript[i].name,name)==0)
    {
      return &workcell->ppscripts.ppscript[i];
    }
  }
  return ((void *)0);
}

tmpnBoptCoeff *getBoptCoeff(tmpnWorkcell *workcell)
{
 if (workcell->boptcoeff.maxidx>0)
  return &workcell->boptcoeff;
  return ((void *)0);
}

tmpnBoptCoeffItem *getBoptCoeffItem(tmpnBoptCoeff *boptcoeff, int mode, int pathtype)
{
 int i;
 for (i=0;i<boptcoeff->maxidx;i++)
 {
  if (mode==boptcoeff->item[i].mode&&pathtype==boptcoeff->item[i].pathtype)
  {
   return &boptcoeff->item[i];
  }
 }
 return ((void *)0);
}

char *getLanguageLineFromIdx(tmpnLanguage *lang, int idx, char *defaultstring)
{
 if (idx<lang->maxidx&&idx>=0)
  return lang->item[idx].tekst;
 return defaultstring;
}

char *getLanguageLineFromKey(tmpnLanguage *lang, int key, char *defaultstring)
{
 int i;
 for (i=0;i<lang->maxidx;i++)
 {
  if (lang->item[i].key==key)
  {
   return lang->item[i].tekst;
  }
 }
 return defaultstring;
}

char *getLanguageLineFromEnglish(tmpnLanguage *lang, char *englishline, char *defaultstring)
{
 int i;
 for (i=0;i<lang->maxidx;i++)
 {
  if (!strcmp(lang->item[i].english,englishline))
  {
   return lang->item[i].tekst;
  }
 }
 return defaultstring;
}

int selectLanguage(tmpnLanguages *langs, char *languagename)
{
 int i;
 for (i=0;i<langs->numoflanguages;i++)
 {
  if (!strcmp(langs->language[i].name,languagename))
  {
   langs->currentLanguage=i;
   return i;
  }
 }
 return 0;
}

int getWorkcellIdx(const char *name, tmpnPlant *plant)
{
  int i;
  for(i=0;i<plant->workcells.maxidx;i++)
  {
    if(strcmp(plant->workcells.workcell[i].name,name)==0)
    {
      return i;
    }
  }
  return 0;
}

int getRobotIdx(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->robots.maxidx;i++)
  {
    if(strcmp(workcell->robots.robot[i].m_name,name)==0)
    {
      return i;
    }
  }
  return 0;
}

int AddProgram(int PrgStmIdx, char *newName, int copyfromidx)
{
 FILE *fp;
 int idx,i,j,h,newidx;
  char line[256];
  char temp[256];
 char *lines[5000];
 int curstateidx;
 int copystartidx=0,copyendidx=0,insertidx=-1;
 int resetidx=-1;
 int num;
  i=0;
 newidx=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
 curstateidx=-1;
 while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
  num = sscanf(line," State=%s ",temp);
  if (num==1)
  {
   curstateidx++;
   if (curstateidx==copyfromidx)
   {
    copystartidx=i;
   }
   if (curstateidx==(copyfromidx+1))
   {
    copyendidx=i-1;
   }
   if (strncmp(temp,"PROGRAM_",8)&&insertidx==-1)
   {
    insertidx=i;
    newidx=curstateidx;
   }
   if (!strcmp(temp,"ST_RESET")&&resetidx==-1)
   {
    resetidx=i+1;
   }
  }
  i++;
 }
  fclose(fp);
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
   {
  if (j==insertidx)
  {
    for (h=copystartidx;h<copyendidx;h++)
    {
     if (sscanf(lines[h]," State=PROGRAM_%s",temp)==1)
     {
      fprintf(fp,"State=PROGRAM_%s\n",newName);
     }
     else if (sscanf(lines[h]," SETSTATE ST_RUNNING_%s" ,temp)==1)
     {
      fprintf(fp,"  SETSTATE ST_RUNNING_%s\n",newName);
     }
     else
     {
      fprintf(fp,"%s",lines[h]);
     }
    }
    fprintf(fp,"\n");
  }
  if (j==resetidx)
  {
   fprintf(fp,"  TEST programidx = %i\n",newidx);
   fprintf(fp,"    SETSTATE PROGRAM_%s\n",newName);
   fprintf(fp,"  ENDTEST\n");
  }
    fprintf(fp,"%s",lines[j]);
 }
 fprintf(fp,"\nState=ST_RUNNING_%s\n",newName);
 fprintf(fp,"  SET newprogram 0\n");
 fprintf(fp,"  TEST workcell = ST_IDLE\n");
 fprintf(fp,"  OR workcell = ST_PAUSED\n");
 fprintf(fp,"    TEST programidx != %i\n",newidx);
 fprintf(fp,"      SETSTATE ST_RESET\n");
 fprintf(fp,"    ENDTEST\n");
 fprintf(fp,"  ENDTEST\n");
 fprintf(fp,"END\n");
  fclose(fp);
  for (j=0;j<i;j++)
  {
    free(lines[j]);
  }
 return 1;
}

int DeleteProgram(int PrgStmIdx,char *PrgName)
{
  FILE *fp;
 int idx,i;

  i=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
 return 1;
}

int SaveProgramVal(int PrgStmIdx,STMCOMMANDSTRUCT *stmcmd,char *prgname)
{
  int i,j,num,idx;
  FILE *fp;
  char line[256];
 char cname[256];
  char temp[256];
  int retval;
 int correctstate=0;
  char *lines[5000];
 int level;
  retval = 0;
  i=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
 correctstate=0;
 level=0;
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
  num = sscanf(line," State=%s ",temp);
  if (num==1&&(!strcmp(temp,prgname)))
   correctstate=1;
  else if (num==1&&(strcmp(temp,prgname)))
   correctstate=0;
  if (correctstate)
  {
   num = sscanf(line," %s ",temp);
   if (num==1&&!strcmp(temp,"TEST")) level++;
   else if (num==1&&!strcmp(temp,"ENDTEST")) level--;
   else
   {
        if (stmcmd->type == 33)
        {
          num = sscanf(line," SET %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETSTRUCT *set = (SETSTRUCT*)stmcmd->data;
            if(!strcmp(cname,set->dest.valstring))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S')
                {
                  strncpy(ws,line,j+4);
                  ws[j+4]='\0';
                  break;
                }
              }
              free(lines[i]);
              if (set->src.subtype==0)
                sprintf(line,"%s%s %d\n",ws,cname,set->src.number);
              if (set->src.subtype==1)
                sprintf(line,"%s%s %0.4f\n",ws,cname,set->src.fnumber);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = 1;
            }
          }
        }
        else if (stmcmd->type == 57)
        {
          num = sscanf(line," SETITEM %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETITEMSTRUCT *setitem = (SETITEMSTRUCT*)stmcmd->data;
            if(!strcmp(cname,setitem->dest))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S')
                {
                  strncpy(ws,line,j+8);
                  ws[j+8]='\0';
                  break;
                }
              }
              free(lines[i]);
              sprintf(line,"%s%s %s\n",ws,cname,setitem->src);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = 1;
            }
          }
        }
        else if (stmcmd->type == 60)
        {
          num = sscanf(line," SETCPPATTERN %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETCPPATTERNSTRUCT *setcpp = (SETCPPATTERNSTRUCT*)stmcmd->data;
            if(!strcmp(cname,setcpp->dest))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S')
                {
                  strncpy(ws,line,j+13);
                  ws[j+13]='\0';
                  break;
                }
              }
              free(lines[i]);
              sprintf(line,"%s%s %s\n",ws,cname,setcpp->src);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = 1;
            }
          }
        }
   }
  }
  i++;
  }
  fclose(fp);
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);

  if(rs_param.statemachine_debug>2)
  {
    if (stmcmd->type == 33){
      SETSTRUCT *set = (SETSTRUCT*)stmcmd->data;
      if (set->src.subtype==0)
        printf("Edited Program SET statement %s=%d and saved to file %s.\n",set->dest.valstring,set->src.number, tworkcell->statemachines.statemachine[idx].filename);
      else
        printf("Edited Program SET statement %s=%0.4f and saved to file %s.\n",set->dest.valstring,set->src.fnumber, tworkcell->statemachines.statemachine[idx].filename);
    }else if (stmcmd->type == 57){
      SETITEMSTRUCT *setitem = (SETITEMSTRUCT*)stmcmd->data;
      printf("Edited Program SETITEM statement %s=%s and saved to file %s.\n",setitem->dest,setitem->src, tworkcell->statemachines.statemachine[idx].filename);
    }
 }
  return 1;
}

int SaveConstVal(const char *stmname, const char *cname, tmpnStateMachineValue* val)
{
  int f,i,j,num,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;
 float fnum;
  char *lines[5000];
  retval = 0;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,"Const=",6)))
    {
   if (tworkcell->statemachines.statemachine[idx].version==2)
   {
    if (val->subtype==0)
    {
     if (sscanf(line,"Const=%d,%s %d",&f,name,&num)==3)
     {
      if ((!strcmp(name,cname)))
      {
       free(lines[i]);
       sprintf(line,"Const=%d,%s %d\n",f,name,val->data);
       lines[i] = (char*)malloc(1+strlen(line));
       strcpy(lines[i],line);
       retval = 1;
      }
     }
    }
    else
    {
     if (sscanf(line,"Const=%d,%s %f",&f,name,&fnum)==3)
     {
      if ((!strcmp(name,cname)))
      {
       free(lines[i]);
       sprintf(line,"Const=%d,%s %0.4f\n",f,name,val->fdata);
       lines[i] = (char*)malloc(1+strlen(line));
       strcpy(lines[i],line);
       retval = 1;
      }
     }
    }
   }
   else if (tworkcell->statemachines.statemachine[idx].version==3)
   {
    if (val->subtype==0)
    {
     if (sscanf(line,"Const=%s %d",name,&num)==2)
     {
      if ((!strcmp(name,cname)))
      {
       free(lines[i]);
       sprintf(line,"Const=%s %d\n",name,val->data);
       lines[i] = (char*)malloc(1+strlen(line));
       strcpy(lines[i],line);
       retval = 1;
      }
     }
    }
    else
    {
     if (sscanf(line,"Const=%s %f",name,&fnum)==2)
     {
      if ((!strcmp(name,cname)))
      {
       free(lines[i]);
       sprintf(line,"Const=%s %0.4f\n",name,val->fdata);
       lines[i] = (char*)malloc(1+strlen(line));
       strcpy(lines[i],line);
       retval = 1;
      }
     }
    }
   }
  }
    i++;
  }
  fclose(fp);
  if (!retval&&tworkcell->statemachines.statemachine[idx].version==2)
  {
    for (j=0;j<i;j++)
    {
      free(lines[j]);
    }
    printf("Couldn't find Const %s\n",cname);
    return 0;
  }
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
   if (val->subtype==0)
    {
      sprintf(lines[i],"Const=%s %d\n",cname,val->data);
    }
    else
    {
      sprintf(lines[i],"Const=%s %0.4f\n",cname,val->fdata);
    }
    printf("Couldn't find Const %s added to end of file\n",cname);
    retval=1;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
  if (val->subtype==0)
   printf("Edited Const %s=%d (formerly = %d) and saved to file %s.\n",cname,val->data,num,tworkcell->statemachines.statemachine[idx].filename);
  else
   printf("Edited Const %s=%f (formerly = %f) and saved to file %s.\n",cname,val->fdata,fnum,tworkcell->statemachines.statemachine[idx].filename);
  }
  return 1;
}

int SaveTimeVal(const char *stmname, const char *timename,int val)
{
  int f,i,j,num,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;
  char *lines[5000];
  retval = 0;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,"Timeout=",8)))
    {
   if (tworkcell->statemachines.statemachine[idx].version==2)
   {
    if (sscanf(line,"Timeout=%d,%s %d",&f,name,&num)==3)
    {
     if ((!strcmp(name,timename)))
     {
      free(lines[i]);
      sprintf(line,"Timeout=%d,%s %d\n",f,name,val);
      lines[i] = (char*)malloc(1+strlen(line));
      strcpy(lines[i],line);
      retval = 1;
     }
    }
   }
   else if (tworkcell->statemachines.statemachine[idx].version==3)
   {
    if (sscanf(line,"Timeout=%s %d",name,&num)==2)
    {
     if ((!strcmp(name,timename)))
     {
      free(lines[i]);
      sprintf(line,"Timeout=%s %d\n",name,val);
      lines[i] = (char*)malloc(1+strlen(line));
     strcpy(lines[i],line);
     retval = 1;
     }
    }
   }
  }
    i++;
  }
  fclose(fp);
  if (!retval&&tworkcell->statemachines.statemachine[idx].version==2)
  {
    for (j=0;j<i;j++)
    {
      free(lines[j]);
    }
    printf("Couldn't find timeout value %s\n",timename);
    return 0;
  }
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
   sprintf(lines[i],"Timeout=%s %d\n",timename,val);
    printf("Couldn't find Timeout %s added to end of file\n",timename);
    retval=1;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited timeoutval %s=%d (formerly = %d) and saved to file %s.\n",timename,val,num,tworkcell->statemachines.statemachine[idx].filename);
  }
  return 1;
}

int SaveItemVal(const char *stmname, const char *name, const char *itemName)
{
  int i,j,idx;
  FILE *fp;
  char line[256];
  char cname[256];
  char citemName[256];
  int retval;
  char *lines[5000];
  retval = 0;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,"Item=",5)))
    {
      if (tworkcell->statemachines.statemachine[idx].version==3)
   {
    if (sscanf(line,"Item=%s %s",cname,citemName)==2)
    {
     if ((!strcmp(cname,name)))
     {
      free(lines[i]);
      sprintf(line,"Item=%s %s\n",name,itemName);
      lines[i] = (char*)malloc(1+strlen(line));
            strcpy(lines[i],line);
            retval = 1;
     }
    }
   }
  }
    i++;
  }
  fclose(fp);
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
   sprintf(lines[i],"Item=%s %s\n",name,itemName);
    printf("Couldn't find Item %s added to end of file\n",name);
    retval=1;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited Item=%s %s (formerly = %s) and saved to file %s.\n",name,itemName,citemName,tworkcell->statemachines.statemachine[idx].filename);
  }
  return 1;
}

int SaveCPPatternVal(const char *stmname, const char *name, const char *cppName)
{
  int i,j,idx;
  FILE *fp;
  char line[256];
  char cname[256];
  char ccppName[256];
  int retval;
  char *lines[5000];
  retval = 0;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,"CPPattern=",10)))
    {
      if (tworkcell->statemachines.statemachine[idx].version==3)
   {
    if (sscanf(line,"CPPattern=%s %s",cname,ccppName)==2)
    {
     if ((!strcmp(cname,name)))
     {
      free(lines[i]);
      sprintf(line,"CPPattern=%s %s\n",name,cppName);
      lines[i] = (char*)malloc(1+strlen(line));
            strcpy(lines[i],line);
            retval = 1;
     }
    }
   }
  }
    i++;
  }
  fclose(fp);
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
   sprintf(lines[i],"CPPattern=%s %s\n",name,cppName);
    printf("Couldn't find CP Pattern %s added to end of file\n",name);
    retval=1;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  for (j=0;j<i;j++)
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited CPPattern=%s %s (formerly = %s) and saved to file %s.\n",name,cppName,ccppName,tworkcell->statemachines.statemachine[idx].filename);
  }
  return 1;
}

int SaveFrameVal(const char *stmname, tmpnFrame *newfr)
{
 tmpnFrame oldfr;
  int i,j,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;
  char *lines[5000];
  retval = 0;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return 0;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return 0;
  }
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,"Frame=",6)))
    {
   if (tworkcell->statemachines.statemachine[idx].version==3)
   {
    if (sscanf(line,"Frame=%s x=%f y=%f z=%f v=%f w=%f u=%f",name,&oldfr.x,&oldfr.y,&oldfr.z,&oldfr.v,&oldfr.w,&oldfr.u)==7)
    {
     if ((!strcmp(name,newfr->name)))
     {
      free(lines[i]);
      sprintf(line,"Frame=%s x=%0.4f y=%0.4f z=%0.4f v=%0.4f w=%0.4f u=%0.4f\n",name,newfr->x,newfr->y,newfr->z,newfr->v,newfr->w,oldfr.u);
      lines[i] = (char*)malloc(1+strlen(line));
      strcpy(lines[i],line);
      retval = 1;
     }
    }
   }
  }
    i++;
  }
  fclose(fp);
 if (retval)
 {
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==((void *)0))
  {
   printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
   return 0;
  }
  for (j=0;j<i;j++)
  {
   fprintf(fp,"%s",lines[j]);
   free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
   printf("Edited framevalue %s and saved to file %s.\n",newfr->name,tworkcell->statemachines.statemachine[idx].filename);
  }
  return 1;
 }
 return 0;
}

int SaveMacInitVal(tmpnMac* mac, int modidx, int initidx)
{
  int i,j;
  FILE *fp;
 char cmpline[256];
 int cmplen;
  char line[256];
  int retval;
  char *lines[1000];
  retval = 0;
 i=0;
  fp = fopen(mac->filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open %s for reading!\n",mac->filename);
    return 0;
  }
 sprintf(cmpline,"Init%i=",mac->iotab[modidx].initdata[initidx].reg);
 cmplen=strlen(cmpline);
 printf("\"%s\" %i\n",cmpline,cmplen);
  while (fgets(line,sizeof(line),fp)!=((void *)0))
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==0)&&(!strncmp(line,cmpline,cmplen)))
    {
   free(lines[i]);
   if (mac->iotab[modidx].initdata[initidx].type==2||mac->iotab[modidx].initdata[initidx].type==0||mac->iotab[modidx].initdata[initidx].type==1)
   {
    if (!strncmp(&line[cmplen],"0x",2))
     sprintf(line,"%s0x%x \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].data, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
    else
     sprintf(line,"%s%i \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].data, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
    int tmplen;
    tmplen=strlen(line);
    switch (mac->iotab[modidx].initdata[initidx].type)
    {
    case 2:
     sprintf(&line[tmplen]," longint\n");
     break;
    case 0:
     sprintf(&line[tmplen]," shortint\n");
     break;
    case 1:
     sprintf(&line[tmplen]," shortuint\n");
     break;
    }
   }
   else
   {
    sprintf(line,"%s%0.4f \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].fdata, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
    int tmplen;
    tmplen=strlen(line);
    switch (mac->iotab[modidx].initdata[initidx].type)
    {
    case 7:
     sprintf(&line[tmplen]," longint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     break;
    case 8:
     sprintf(&line[tmplen]," shortint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     break;
    case 9:
     sprintf(&line[tmplen]," shortuint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     break;
    case 3:
     if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
      sprintf(&line[tmplen]," fixed4 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     else
      sprintf(&line[tmplen]," fixed4\n");
     break;
    case 4:
     if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
      sprintf(&line[tmplen]," fixed8 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     else
      sprintf(&line[tmplen]," fixed8\n");
     break;
    case 5:
     if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
      sprintf(&line[tmplen]," fixed16 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     else
      sprintf(&line[tmplen]," fixed16\n");
     break;
    case 6:
     if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
      sprintf(&line[tmplen]," fixed24 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
     else
      sprintf(&line[tmplen]," fixed24\n");
     break;
    }
   }
   lines[i] = (char*)malloc(1+strlen(line));
   strcpy(lines[i],line);
   retval = 1;
  }
  i++;
 }
  fclose(fp);
 if (retval)
 {
  fp = fopen(mac->filename,"w");
  if(fp==((void *)0))
  {
   printf("Couldn't open %s for writing!\n",mac->filename);
   return 0;
  }
  for (j=0;j<i;j++)
  {
   fprintf(fp,"%s",lines[j]);
   free(lines[j]);
  }
  fclose(fp);
  if(rs_param.io_debug>0)
  {
   printf("Edited mac initvalue %s and saved to file %s.\n",mac->iotab[modidx].initdata[initidx].key,mac->filename);
  }
  return 1;
 }
 return 0;
}

int tmpnRobotSave(const char *fn, tmpnRobot *robot)
{
  int f,i;
  FILE *fp;
  char filename[256];

  sprintf(filename,"%s/robot/%s.robot",databasePath,fn);

  fp = fopen(filename,"w");
  if(fp==((void *)0)) return 0;
  fprintf(fp,"VERSION %d\n",3);
  fprintf(fp,"m_name=%s\n",robot->m_name);
  fprintf(fp,"m_gantryLength=%3.2f,m_legHeight=%3.2f,m_shoulderGearB=%f\n"
   ,robot->m_gantryLength
   ,robot->m_legHeight
   ,robot->m_shoulderGearB );
  for(i=0;i<5;i++)
  {
    fprintf(fp,"m_Link[%d]=%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f\n"
     ,i
     ,robot->m_Link[i].length
     ,robot->m_Link[i].mass
     ,robot->m_Link[i].massDisplacement[0]
     ,robot->m_Link[i].massDisplacement[1]
     ,robot->m_Link[i].massDisplacement[2]
     ,robot->m_Link[i].inertia[0][0]
     ,robot->m_Link[i].inertia[0][1]
     ,robot->m_Link[i].inertia[0][2]
     ,robot->m_Link[i].inertia[1][0]
     ,robot->m_Link[i].inertia[1][1]
     ,robot->m_Link[i].inertia[1][2]
     ,robot->m_Link[i].inertia[2][0]
     ,robot->m_Link[i].inertia[2][1]
     ,robot->m_Link[i].inertia[2][2]);
  }
  for(i=0;i<3;i++)
  {
    fprintf(fp,"m_State[%d]=%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f\n"
     ,i
     ,robot->m_State[i].length
     ,robot->m_State[i].mass
     ,robot->m_State[i].massDisplacement[0]
     ,robot->m_State[i].massDisplacement[1]
     ,robot->m_State[i].massDisplacement[2]
     ,robot->m_State[i].inertia[0][0]
     ,robot->m_State[i].inertia[0][1]
     ,robot->m_State[i].inertia[0][2]
     ,robot->m_State[i].inertia[1][0]
     ,robot->m_State[i].inertia[1][1]
     ,robot->m_State[i].inertia[1][2]
     ,robot->m_State[i].inertia[2][0]
     ,robot->m_State[i].inertia[2][1]
     ,robot->m_State[i].inertia[2][2]);
  }
  fprintf(fp,"m_sign.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_sign.name.a
   ,robot->m_sign.name.b
   ,robot->m_sign.name.c
   ,robot->m_sign.name.d
   ,robot->m_sign.name.e
   ,robot->m_sign.name.f);
  fprintf(fp,"m_ratedNmGear.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_ratedNmGear.name.a
   ,robot->m_ratedNmGear.name.b
   ,robot->m_ratedNmGear.name.c
   ,robot->m_ratedNmGear.name.d
   ,robot->m_ratedNmGear.name.e
   ,robot->m_ratedNmGear.name.f);
  fprintf(fp,"m_ratedRpmGear.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_ratedRpmGear.name.a
   ,robot->m_ratedRpmGear.name.b
   ,robot->m_ratedRpmGear.name.c
   ,robot->m_ratedRpmGear.name.d
   ,robot->m_ratedRpmGear.name.e
   ,robot->m_ratedRpmGear.name.f);
  fprintf(fp,"m_ratedRPM.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_ratedRPM.name.a
   ,robot->m_ratedRPM.name.b
   ,robot->m_ratedRPM.name.c
   ,robot->m_ratedRPM.name.d
   ,robot->m_ratedRPM.name.e
   ,robot->m_ratedRPM.name.f);
  fprintf(fp,"m_ratedNm.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_ratedNm.name.a
   ,robot->m_ratedNm.name.b
   ,robot->m_ratedNm.name.c
   ,robot->m_ratedNm.name.d
   ,robot->m_ratedNm.name.e
   ,robot->m_ratedNm.name.f);
  fprintf(fp,"m_maxForceNm.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_maxForceNm.name.a
   ,robot->m_maxForceNm.name.b
   ,robot->m_maxForceNm.name.c
   ,robot->m_maxForceNm.name.d
   ,robot->m_maxForceNm.name.e
   ,robot->m_maxForceNm.name.f);
  fprintf(fp,"m_pulses.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_pulses.name.a
   ,robot->m_pulses.name.b
   ,robot->m_pulses.name.c
   ,robot->m_pulses.name.d
   ,robot->m_pulses.name.e
   ,robot->m_pulses.name.f);
  fprintf(fp,"m_gearing.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_gearing.name.a
   ,robot->m_gearing.name.b
   ,robot->m_gearing.name.c
   ,robot->m_gearing.name.d
   ,robot->m_gearing.name.e
   ,robot->m_gearing.name.f);
  fprintf(fp,"m_unit.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_unit.name.a
   ,robot->m_unit.name.b
   ,robot->m_unit.name.c
   ,robot->m_unit.name.d
   ,robot->m_unit.name.e
   ,robot->m_unit.name.f);



  fprintf(fp,"m_units.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_units.name.a
   ,robot->m_units.name.b
   ,robot->m_units.name.c
   ,robot->m_units.name.d
   ,robot->m_units.name.e
   ,robot->m_units.name.f);
  fprintf(fp,"m_p_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_p_gain.name.a
   ,robot->m_p_gain.name.b
   ,robot->m_p_gain.name.c
   ,robot->m_p_gain.name.d
   ,robot->m_p_gain.name.e
   ,robot->m_p_gain.name.f);
  fprintf(fp,"m_i_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_i_gain.name.a
   ,robot->m_i_gain.name.b
   ,robot->m_i_gain.name.c
   ,robot->m_i_gain.name.d
   ,robot->m_i_gain.name.e
   ,robot->m_i_gain.name.f);
  fprintf(fp,"m_d_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_d_gain.name.a
   ,robot->m_d_gain.name.b
   ,robot->m_d_gain.name.c
   ,robot->m_d_gain.name.d
   ,robot->m_d_gain.name.e
   ,robot->m_d_gain.name.f);
  fprintf(fp,"m_vff_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_vff_gain.name.a
   ,robot->m_vff_gain.name.b
   ,robot->m_vff_gain.name.c
   ,robot->m_vff_gain.name.d
   ,robot->m_vff_gain.name.e
   ,robot->m_vff_gain.name.f);
  fprintf(fp,"m_speed.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_speed.name.a
   ,robot->m_speed.name.b
   ,robot->m_speed.name.c
   ,robot->m_speed.name.d
   ,robot->m_speed.name.e
   ,robot->m_speed.name.f);
  fprintf(fp,"m_accel.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_accel.name.a
   ,robot->m_accel.name.b
   ,robot->m_accel.name.c
   ,robot->m_accel.name.d
   ,robot->m_accel.name.e
   ,robot->m_accel.name.f);
  fprintf(fp,"m_decel.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_decel.name.a
   ,robot->m_decel.name.b
   ,robot->m_decel.name.c
   ,robot->m_decel.name.d
   ,robot->m_decel.name.e
   ,robot->m_decel.name.f);
  fprintf(fp,"m_creep.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_creep.name.a
   ,robot->m_creep.name.b
   ,robot->m_creep.name.c
   ,robot->m_creep.name.d
   ,robot->m_creep.name.e
   ,robot->m_creep.name.f);
  fprintf(fp,"m_jogspeed.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_jogspeed.name.a
   ,robot->m_jogspeed.name.b
   ,robot->m_jogspeed.name.c
   ,robot->m_jogspeed.name.d
   ,robot->m_jogspeed.name.e
   ,robot->m_jogspeed.name.f);
  fprintf(fp,"m_felimit.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_felimit.name.a
   ,robot->m_felimit.name.b
   ,robot->m_felimit.name.c
   ,robot->m_felimit.name.d
   ,robot->m_felimit.name.e
   ,robot->m_felimit.name.f);


  fprintf(fp,"m_min.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_min.x
   ,robot->m_min.y
   ,robot->m_min.z
   ,robot->m_min.v
   ,robot->m_min.w
   ,robot->m_min.u);
  fprintf(fp,"m_max.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_max.x
   ,robot->m_max.y
   ,robot->m_max.z
   ,robot->m_max.v
   ,robot->m_max.w
   ,robot->m_max.u);
  fprintf(fp,"m_localTrans.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_localTrans.x
   ,robot->m_localTrans.y
   ,robot->m_localTrans.z
   ,robot->m_localTrans.v
   ,robot->m_localTrans.w
   ,robot->m_localTrans.u);
  fprintf(fp,"m_jointCalib.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_jointCalib.a
   ,robot->m_jointCalib.b
   ,robot->m_jointCalib.c
   ,robot->m_jointCalib.d
   ,robot->m_jointCalib.e
   ,robot->m_jointCalib.f);
  fprintf(fp,"m_mpnhome.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_mpnhome.a
   ,robot->m_mpnhome.b
   ,robot->m_mpnhome.c
   ,robot->m_mpnhome.d
   ,robot->m_mpnhome.e
   ,robot->m_mpnhome.f);
  fprintf(fp,"m_tcpTrans[case].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[0].x
   ,robot->m_tcp[0].y
   ,robot->m_tcp[0].z
   ,robot->m_tcp[0].v
   ,robot->m_tcp[0].w
   ,robot->m_tcp[0].u);
  fprintf(fp,"m_tcpTrans[bag].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[1].x
   ,robot->m_tcp[1].y
   ,robot->m_tcp[1].z
   ,robot->m_tcp[1].v
   ,robot->m_tcp[1].w
   ,robot->m_tcp[1].u);
  fprintf(fp,"m_tcpTrans[zero].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[2].x
   ,robot->m_tcp[2].y
   ,robot->m_tcp[2].z
   ,robot->m_tcp[2].v
   ,robot->m_tcp[2].w
   ,robot->m_tcp[2].u);
  for(f=0;f<robot->m_frames.maxidx;f++)
  {
    fprintf(fp,"FRAME %s x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
     ,robot->m_frames.frame[f].name
     ,robot->m_frames.frame[f].x
     ,robot->m_frames.frame[f].y
     ,robot->m_frames.frame[f].z
     ,robot->m_frames.frame[f].v
     ,robot->m_frames.frame[f].w
     ,robot->m_frames.frame[f].u
      );
  }
  for(f=0;f<robot->timing.maxidx;f++)
  {
    fprintf(fp,"TIMING %s %3.2f\n"
     ,robot->timing.item[f].name
     ,robot->timing.item[f].value
      );
  }
  fclose(fp);
  return 1;
}

static void updateRobot(char *s, tmpnRobot *robot, int version)
{
  int i,j;
  if(strncmp(s,"m_name=",7)==0)
  {
    sscanf(s,"m_name=%s\n",robot->m_name);
  }
  else if(strncmp(s,"m_gantryLength=",15)==0)
  {
    sscanf(s,"m_gantryLength=%f,m_legHeight=%f,m_shoulderGearB=%f\n"
     ,&robot->m_gantryLength
     ,&robot->m_legHeight
     ,&robot->m_shoulderGearB);
  }
  else if(strncmp(s,"m_Link[",7)==0)
  {
    sscanf(s,"m_Link[%d]",&i);
    sscanf(s,"m_Link[%d]=%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n"
     ,&j
     ,&robot->m_Link[i].length
     ,&robot->m_Link[i].mass
     ,&robot->m_Link[i].massDisplacement[0]
     ,&robot->m_Link[i].massDisplacement[1]
     ,&robot->m_Link[i].massDisplacement[2]
     ,&robot->m_Link[i].inertia[0][0]
     ,&robot->m_Link[i].inertia[0][1]
     ,&robot->m_Link[i].inertia[0][2]
     ,&robot->m_Link[i].inertia[1][0]
     ,&robot->m_Link[i].inertia[1][1]
     ,&robot->m_Link[i].inertia[1][2]
     ,&robot->m_Link[i].inertia[2][0]
     ,&robot->m_Link[i].inertia[2][1]
     ,&robot->m_Link[i].inertia[2][2]);
  }
  else if(strncmp(s,"m_State[",8)==0)
  {
    sscanf(s,"m_State[%d]",&i);
    sscanf(s,"m_State[%d]=%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n"
     ,&j
     ,&robot->m_State[i].length
     ,&robot->m_State[i].mass
     ,&robot->m_State[i].massDisplacement[0]
     ,&robot->m_State[i].massDisplacement[1]
     ,&robot->m_State[i].massDisplacement[2]
     ,&robot->m_State[i].inertia[0][0]
     ,&robot->m_State[i].inertia[0][1]
     ,&robot->m_State[i].inertia[0][2]
     ,&robot->m_State[i].inertia[1][0]
     ,&robot->m_State[i].inertia[1][1]
     ,&robot->m_State[i].inertia[1][2]
     ,&robot->m_State[i].inertia[2][0]
     ,&robot->m_State[i].inertia[2][1]
     ,&robot->m_State[i].inertia[2][2]);
  }
  else if(strncmp(s,"m_sign.a=",9)==0)
  {
    sscanf(s,"m_sign.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_sign.name.a
     ,&robot->m_sign.name.b
     ,&robot->m_sign.name.c
     ,&robot->m_sign.name.d
     ,&robot->m_sign.name.e
     ,&robot->m_sign.name.f);
  }
  else if(strncmp(s,"m_ratedRpmGear.a=",13)==0)
  {
    sscanf(s,"m_ratedRpmGear.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedRpmGear.name.a
     ,&robot->m_ratedRpmGear.name.b
     ,&robot->m_ratedRpmGear.name.c
     ,&robot->m_ratedRpmGear.name.d
     ,&robot->m_ratedRpmGear.name.e
     ,&robot->m_ratedRpmGear.name.f);
  }
  else if(strncmp(s,"m_ratedNmGear.a=",13)==0)
  {
    sscanf(s,"m_ratedNmGear.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedNmGear.name.a
     ,&robot->m_ratedNmGear.name.b
     ,&robot->m_ratedNmGear.name.c
     ,&robot->m_ratedNmGear.name.d
     ,&robot->m_ratedNmGear.name.e
     ,&robot->m_ratedNmGear.name.f);
  }
  else if(strncmp(s,"m_ratedRPM.a=",13)==0)
  {
    sscanf(s,"m_ratedRPM.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedRPM.name.a
     ,&robot->m_ratedRPM.name.b
     ,&robot->m_ratedRPM.name.c
     ,&robot->m_ratedRPM.name.d
     ,&robot->m_ratedRPM.name.e
     ,&robot->m_ratedRPM.name.f);
  }
  else if(strncmp(s,"m_ratedNm.a=",12)==0)
  {
    sscanf(s,"m_ratedNm.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedNm.name.a
     ,&robot->m_ratedNm.name.b
     ,&robot->m_ratedNm.name.c
     ,&robot->m_ratedNm.name.d
     ,&robot->m_ratedNm.name.e
     ,&robot->m_ratedNm.name.f);
  }
  else if(strncmp(s,"m_maxForceNm.a=",15)==0)
  {
    sscanf(s,"m_maxForceNm.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_maxForceNm.name.a
     ,&robot->m_maxForceNm.name.b
     ,&robot->m_maxForceNm.name.c
     ,&robot->m_maxForceNm.name.d
     ,&robot->m_maxForceNm.name.e
     ,&robot->m_maxForceNm.name.f);
  }
  else if(strncmp(s,"m_pulses.a=",11)==0)
  {
    sscanf(s,"m_pulses.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_pulses.name.a
     ,&robot->m_pulses.name.b
     ,&robot->m_pulses.name.c
     ,&robot->m_pulses.name.d
     ,&robot->m_pulses.name.e
     ,&robot->m_pulses.name.f);
  }
  else if(strncmp(s,"m_gearing.a=",12)==0)
  {
    sscanf(s,"m_gearing.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_gearing.name.a
     ,&robot->m_gearing.name.b
     ,&robot->m_gearing.name.c
     ,&robot->m_gearing.name.d
     ,&robot->m_gearing.name.e
     ,&robot->m_gearing.name.f);
  }
  else if(strncmp(s,"m_unit.a=",9)==0)
  {
    sscanf(s,"m_unit.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_unit.name.a
     ,&robot->m_unit.name.b
     ,&robot->m_unit.name.c
     ,&robot->m_unit.name.d
     ,&robot->m_unit.name.e
     ,&robot->m_unit.name.f);
  }



  else if(strncmp(s,"m_p_gain.a=",11)==0)
  {
    sscanf(s,"m_p_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_p_gain.name.a
   ,&robot->m_p_gain.name.b
   ,&robot->m_p_gain.name.c
   ,&robot->m_p_gain.name.d
   ,&robot->m_p_gain.name.e
   ,&robot->m_p_gain.name.f);
  }
  else if(strncmp(s,"m_i_gain.a=",11)==0)
  {
    sscanf(s,"m_i_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_i_gain.name.a
   ,&robot->m_i_gain.name.b
   ,&robot->m_i_gain.name.c
   ,&robot->m_i_gain.name.d
   ,&robot->m_i_gain.name.e
   ,&robot->m_i_gain.name.f);
  }
  else if(strncmp(s,"m_d_gain.a=",11)==0)
  {
    sscanf(s,"m_d_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_d_gain.name.a
   ,&robot->m_d_gain.name.b
   ,&robot->m_d_gain.name.c
   ,&robot->m_d_gain.name.d
   ,&robot->m_d_gain.name.e
   ,&robot->m_d_gain.name.f);
  }
  else if(strncmp(s,"m_vff_gain.a=",13)==0)
  {
    sscanf(s,"m_vff_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_vff_gain.name.a
   ,&robot->m_vff_gain.name.b
   ,&robot->m_vff_gain.name.c
   ,&robot->m_vff_gain.name.d
   ,&robot->m_vff_gain.name.e
   ,&robot->m_vff_gain.name.f);
  }
  else if(strncmp(s,"m_speed.a=",10)==0)
  {
    sscanf(s,"m_speed.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_speed.name.a
   ,&robot->m_speed.name.b
   ,&robot->m_speed.name.c
   ,&robot->m_speed.name.d
   ,&robot->m_speed.name.e
   ,&robot->m_speed.name.f);
  }
  else if(strncmp(s,"m_accel.a=",10)==0)
  {
    sscanf(s,"m_accel.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_accel.name.a
   ,&robot->m_accel.name.b
   ,&robot->m_accel.name.c
   ,&robot->m_accel.name.d
   ,&robot->m_accel.name.e
   ,&robot->m_accel.name.f);
  }
  else if(strncmp(s,"m_decel.a=",10)==0)
  {
    sscanf(s,"m_decel.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_decel.name.a
   ,&robot->m_decel.name.b
   ,&robot->m_decel.name.c
   ,&robot->m_decel.name.d
   ,&robot->m_decel.name.e
   ,&robot->m_decel.name.f);
  }
  else if(strncmp(s,"m_creep.a=",10)==0)
  {
    sscanf(s,"m_creep.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_creep.name.a
   ,&robot->m_creep.name.b
   ,&robot->m_creep.name.c
   ,&robot->m_creep.name.d
   ,&robot->m_creep.name.e
   ,&robot->m_creep.name.f);
  }
  else if(strncmp(s,"m_jogspeed.a=",13)==0)
  {
    sscanf(s,"m_jogspeed.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_jogspeed.name.a
   ,&robot->m_jogspeed.name.b
   ,&robot->m_jogspeed.name.c
   ,&robot->m_jogspeed.name.d
   ,&robot->m_jogspeed.name.e
   ,&robot->m_jogspeed.name.f);
  }
  else if(strncmp(s,"m_felimit.a=",12)==0)
  {
    sscanf(s,"m_felimit.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_felimit.name.a
   ,&robot->m_felimit.name.b
   ,&robot->m_felimit.name.c
   ,&robot->m_felimit.name.d
   ,&robot->m_felimit.name.e
   ,&robot->m_felimit.name.f);
  }
  else if(strncmp(s,"m_min.x=",8)==0)
  {
    sscanf(s,"m_min.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_min.x
     ,&robot->m_min.y
     ,&robot->m_min.z
     ,&robot->m_min.v
     ,&robot->m_min.w
     ,&robot->m_min.u);
  }
  else if(strncmp(s,"m_max.x=",8)==0)
  {
    sscanf(s,"m_max.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_max.x
     ,&robot->m_max.y
     ,&robot->m_max.z
     ,&robot->m_max.v
     ,&robot->m_max.w
     ,&robot->m_max.u);
  }
  else if(strncmp(s,"m_localTrans.x=",15)==0)
  {
    sscanf(s,"m_localTrans.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_localTrans.x
     ,&robot->m_localTrans.y
     ,&robot->m_localTrans.z
     ,&robot->m_localTrans.v
     ,&robot->m_localTrans.w
     ,&robot->m_localTrans.u);
  }
  else if(strncmp(s,"m_jointCalib.a=",15)==0)
  {
    sscanf(s,"m_jointCalib.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_jointCalib.a
     ,&robot->m_jointCalib.b
     ,&robot->m_jointCalib.c
     ,&robot->m_jointCalib.d
     ,&robot->m_jointCalib.e
     ,&robot->m_jointCalib.f);
  }
  else if(strncmp(s,"m_mpnhome.a=",12)==0)
  {
    sscanf(s,"m_mpnhome.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_mpnhome.a
     ,&robot->m_mpnhome.b
     ,&robot->m_mpnhome.c
     ,&robot->m_mpnhome.d
     ,&robot->m_mpnhome.e
     ,&robot->m_mpnhome.f);
  }
  else if(strncmp(s,"m_tcpTrans[case].x=",19)==0)
  {
    strcpy(robot->m_tcp[0].name,"case");
    sscanf(s,"m_tcpTrans[case].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[0].x
     ,&robot->m_tcp[0].y
     ,&robot->m_tcp[0].z
     ,&robot->m_tcp[0].v
     ,&robot->m_tcp[0].w
     ,&robot->m_tcp[0].u);
  }
  else if(strncmp(s,"m_tcpTrans[bag].x=",18)==0)
  {
    strcpy(robot->m_tcp[1].name,"bag");
    sscanf(s,"m_tcpTrans[bag].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[1].x
     ,&robot->m_tcp[1].y
     ,&robot->m_tcp[1].z
     ,&robot->m_tcp[1].v
     ,&robot->m_tcp[1].w
     ,&robot->m_tcp[1].u);
  }
  else if(strncmp(s,"m_tcpTrans[zero].x=",19)==0)
  {
    strcpy(robot->m_tcp[2].name,"zero");
    sscanf(s,"m_tcpTrans[zero].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[2].x
     ,&robot->m_tcp[2].y
     ,&robot->m_tcp[2].z
     ,&robot->m_tcp[2].v
     ,&robot->m_tcp[2].w
     ,&robot->m_tcp[2].u);
  }
  else if(strncmp(s,"FRAME",5)==0)
  {
    sscanf(s,"FRAME %s x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
      ,robot->m_frames.frame[robot->m_frames.maxidx].name
      ,&robot->m_frames.frame[robot->m_frames.maxidx].x
      ,&robot->m_frames.frame[robot->m_frames.maxidx].y
      ,&robot->m_frames.frame[robot->m_frames.maxidx].z
      ,&robot->m_frames.frame[robot->m_frames.maxidx].v
      ,&robot->m_frames.frame[robot->m_frames.maxidx].w
      ,&robot->m_frames.frame[robot->m_frames.maxidx].u);
    robot->m_frames.maxidx++;
  }
  else if(strncmp(s,"SCRIPT",6)==0)
  {
    printf("this is an old type workcell. Please move SCRIPT statements to workcell\n");
  }
  else if(strncmp(s,"TIMING",6)==0)
  {
    sscanf(s,"TIMING %s %f\n"
      ,robot->timing.item[robot->timing.maxidx].name
      ,&robot->timing.item[robot->timing.maxidx].value);
    robot->timing.maxidx++;
  }
}

void copyAxisToRobotFile(tmpnRobot *robot)
{
 int i;
  for(i=0;i<6;i++)
  {
    robot->m_p_gain.array[i] = tspace.axis.array[i+1].p_gain;
    robot->m_i_gain.array[i] = tspace.axis.array[i+1].i_gain;
    robot->m_d_gain.array[i] = tspace.axis.array[i+1].d_gain;
    robot->m_ov_gain.array[i] = tspace.axis.array[i+1].ov_gain;
    robot->m_vff_gain.array[i] = tspace.axis.array[i+1].vff_gain;
    robot->m_units.array[i] = tspace.axis.array[i+1].units;
    robot->m_speed.array[i] = tspace.axis.array[i+1].speed;
    robot->m_accel.array[i] = tspace.axis.array[i+1].accel;
    robot->m_decel.array[i] = tspace.axis.array[i+1].decel;
    robot->m_creep.array[i] = tspace.axis.array[i+1].creep;
    robot->m_jogspeed.array[i] = tspace.axis.array[i+1].jogspeed;
    robot->m_felimit.array[i] = tspace.axis.array[i+1].felimit;
  }
}

void copyAxisToTableSpace(tmpnRobot *robot)
{
 int i;
  for(i=0;i<6;i++)
  {
    tspace.axis.array[i+1].p_gain = robot->m_p_gain.array[i];
    tspace.axis.array[i+1].i_gain = robot->m_i_gain.array[i];
    tspace.axis.array[i+1].d_gain = robot->m_d_gain.array[i];
    tspace.axis.array[i+1].ov_gain = robot->m_ov_gain.array[i];
    tspace.axis.array[i+1].vff_gain = robot->m_vff_gain.array[i];
    tspace.axis.array[i+1].units = robot->m_units.array[i];
    tspace.axis.array[i+1].speed = robot->m_speed.array[i];
    tspace.axis.array[i+1].accel = robot->m_accel.array[i];
    tspace.axis.array[i+1].decel = robot->m_decel.array[i];
    tspace.axis.array[i+1].creep = robot->m_creep.array[i];
    tspace.axis.array[i+1].jogspeed = robot->m_jogspeed.array[i];
    tspace.axis.array[i+1].felimit = robot->m_felimit.array[i];
  }
}

int tmpnRobotLoad(const char *filename, tmpnRobot *robot)
{
  FILE *fp;
  char buffer[256];
  int version;
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"VERSION %d\n",&version);
  if(version==1||version==2||version==3)
  {
  }
  else
    return 0;
  robot->m_frames.maxidx=0;
  robot->timing.maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    updateRobot(buffer,robot,version);
  }
  fclose(fp);
  robot->m_simulateTRIO = 0;
  robot->splineorder = 4;
  robot->splinehint = 8;
  robot->m_localTrans.y=-(robot->m_shoulderGearB+robot->m_legHeight);



  robot->m_units.name.a=robot->m_pulses.name.a*robot->m_gearing.name.a/robot->m_unit.name.a;
  robot->m_units.name.b=robot->m_pulses.name.b*robot->m_gearing.name.b/robot->m_unit.name.b;
  robot->m_units.name.c=robot->m_pulses.name.c*robot->m_gearing.name.c/robot->m_unit.name.c;
  robot->m_units.name.d=robot->m_pulses.name.d*robot->m_gearing.name.d/robot->m_unit.name.d;
  robot->m_units.name.e=robot->m_pulses.name.e*robot->m_gearing.name.e/robot->m_unit.name.e;
  robot->m_units.name.f=robot->m_pulses.name.f*robot->m_gearing.name.f/robot->m_unit.name.f;
  copyAxisToTableSpace(robot);



  return 1;
}

void selectRobot(int i)
{
  trobot = &tworkcell->robots.robot[i];

}

void selectWorkcell(int i)
{
  tworkcell = &tplant->workcells.workcell[i];

}

tmpnConnect *getConnectPtr(stbstruct *stb, char *name)
{
  int i;
  for(i=0;i<stb->maxidx;i++)
  {
    if(strcmp(stb->connect[i].name,name)==0) return &stb->connect[i];
  }
  return ((void *)0);
}

macConnect *getMacConnectPtr(tmpnStateMachine *stm, char *name)
{
  int i;

  i = getInputIdx(stm, name);
  if(i==-1)
  {
    i = getOutputIdx(stm, name);
    if(i==-1)
      return ((void *)0);
    else
      if (stm->output[i].iotype == 13)
        return stm->output[i].macconnect;
      else
        return ((void *)0);
  }
  else
    if (stm->input[i].iotype == 14)
      return stm->input[i].macconnect;
    else
      return ((void *)0);

  return ((void *)0);
}

void getConnectData(char *buffer, stbstruct *stb)
{
  int starti,i,j0=0;
  int idx;
  tmpnConnect *connect = &stb->connect[stb->maxidx];
  stb->maxidx++;
  starti=0;
  if(strncmp(buffer,"Connect",7)==0&&(buffer[8]=='='||buffer[9]=='='))
  {
    idx=(buffer[7]-'0');
    if(buffer[8]!='=')
    {
      idx=idx*10+(buffer[8]-'0');
    }
    connect->bitidx=1<<(idx-1);
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;

   if(stb->type==5
    ||stb->type==1)
    {
      connect->connectType=2;
      connect->udata=&stb->odata[connect->wordidx];
    }
    else
    {
      connect->connectType=3;
      connect->udata=&stb->odata[connect->wordidx];
    }
    sprintf(connect->name,"Connect%d",idx);
  }
  else if(strncmp(buffer,"OutConnect",10)==0&&(buffer[11]=='='||buffer[12]=='='))
  {
    connect->connectType=3;
    idx=(buffer[10]-'0');

    if(buffer[11]!='=')
    {
      idx=idx*10+(buffer[11]-'0');
    }


    connect->bitidx=1<<(idx-1);
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutConnect%d",idx);
  }
  else if(strncmp(buffer,"InConnect",9)==0&&(buffer[10]=='='||buffer[11]=='='))
  {
    connect->connectType=2;
    idx=(buffer[9]-'0');
    if(buffer[10]!='=')
    {
      idx=idx*10+(buffer[10]-'0');
    }
    connect->bitidx=1<<(idx-1);
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InConnect%d",idx);
  }
  else if(strncmp(buffer,"Ready",5)==0)
  {
    connect->connectType=2;
    idx=(buffer[5]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=0; }
    if(idx==2) { connect->wordidx=0; connect->shift=3; }
    if(idx==3) { connect->wordidx=0; connect->shift=6; }
    if(idx==4) { connect->wordidx=2; connect->shift=1; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Ready%d",idx);
  }
  else if(strncmp(buffer,"Energized",9)==0)
  {
    connect->connectType=2;
    idx=(buffer[9]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=1; }
    if(idx==2) { connect->wordidx=0; connect->shift=4; }
    if(idx==3) { connect->wordidx=0; connect->shift=7; }
    if(idx==4) { connect->wordidx=2; connect->shift=2; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Energized%d",idx);
  }
  else if(strncmp(buffer,"Tripped",7)==0)
  {
    connect->connectType=2;
    idx=(buffer[7]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=2; }
    if(idx==2) { connect->wordidx=0; connect->shift=5; }
    if(idx==3) { connect->wordidx=2; connect->shift=0; }
    if(idx==4) { connect->wordidx=2; connect->shift=3; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Tripped%d",idx);
  }
  else if(strncmp(buffer,"InWord",6)==0)
  {
    connect->connectType=4;
    connect->wordidx=(buffer[6]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InWord%d",connect->wordidx+1);
  }
  else if(strncmp(buffer,"InShort",7)==0)
  {
    connect->connectType=6;
    connect->wordidx=(buffer[7]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InWord%d",connect->wordidx+1);
  }
  else if(strncmp(buffer,"OutWord",7)==0)
  {
    connect->connectType=5;
    connect->wordidx=(buffer[7]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutWord%d",connect->wordidx+1);
  }
  else if(strncmp(buffer,"OutShort",8)==0)
  {
    connect->connectType=7;
    connect->wordidx=(buffer[8]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutWord%d",connect->wordidx+1);
  }
  else
  {
    printf("Unknown connecttype '%s' in .io file\n",buffer);
    exit(99);
  }
  if(rs_param.statemachine_debug>2)
    printf("type=%d idx=%d shift=%d mask=%d\n",connect->connectType,connect->wordidx,connect->shift,connect->mask);
  for(i=0;i<strlen(buffer)-1;i++)
  {
    if(buffer[i]=='=')
    {
      starti=i;
      break;
    }
  }
  starti+=2;
  for(i=starti;i<strlen(buffer)-1;i++)
  {
    if(buffer[i]=='"'&&buffer[i+1]==' '&&buffer[i+2]=='"')
    {
      j0=i;
   break;
    }
  }
 if (j0==0)
 {
  strcpy(connect->key, &buffer[starti]);
  connect->key[strlen(connect->key)-2]=0;
  sprintf(connect->text,"%s","");
 }
 else
 {
  strncpy(connect->key, &buffer[starti],j0-starti);
  connect->key[j0-starti]=0;
  strncpy(connect->text, &buffer[j0+3], strlen(&buffer[j0+3])-1);
  connect->text[strlen(&buffer[j0+3])-2]=0;
 }
}

int tmpnDIOLoad(const char *filename, tmpnDIO *dio)
{
  FILE *fp;
  char buffer[256];
  char sType[256];
  int io_version, i;
  stbstruct *stb=((void *)0);
  unsigned short *tmpiptr;
  unsigned short *tmpoptr;

  dio->numOfInWords = 0;
  dio->numOfOutWords = 0;
  dio->simulate = 0;
  dio->cleardioerror = 0;
  sprintf(dio->ipaddr,"%s","");
  dio->numOfModules = 0;
 tmpiptr = dio->idata;
 tmpoptr = dio->odata;

  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("LoadDioConf: Unknown file %s\n",filename);
    return 0;
  }
  fscanf(fp,"IOVERSION %d\n",&io_version);
  if(io_version!=1)
  {



      printf("LoadDioConf: Unknown version %d\n", io_version);
    exit(99);
  }
  i=0;
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&dio->numOfModules);
      dio->iotab = malloc(sizeof(stbstruct)*dio->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&dio->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",dio->ipaddr);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
      i++;
      if(i+1 > dio->numOfModules)
      {
        printf("Error: '%s' contains more dios than numOfModules (%d)\n", filename, dio->numOfModules);
        exit(99);
      }


     stb = (stbstruct *)&dio->iotab[i];
      stb->maxidx=0;
      stb->numOfInWords=0;
      stb->numOfOutWords=0;
      sscanf(buffer,"Type=%s\n",sType);
    strcpy(stb->typeStr,sType);
      if(strcmp(sType, "EHC3020")==0)
   {
    stb->type=4;
    stb->numOfInWords=6;
    stb->numOfOutWords=5;
   }
      else if(strcmp(sType, "STB3420DDI")==0||strcmp(sType, "DDI3420")==0)
                        {
    stb->type=5;
       stb->numOfInWords=2;
    stb->numOfOutWords=0;
   }
     else if(strcmp(sType, "STB3610DDI")==0||strcmp(sType, "DDI3610")==0)
   {
    stb->type=1;
       stb->numOfInWords=2;
    stb->numOfOutWords=0;
   }
     else if(strcmp(sType, "STB3725DDI")==0||strcmp(sType, "DDI3725")==0)
   {
    stb->type=8;
       stb->numOfInWords=1;
    stb->numOfOutWords=0;
   }
      else if(strcmp(sType, "STB3705DDO")==0||strcmp(sType, "DDO3705")==0)
   {
    stb->type=2;
       stb->numOfInWords=0;
    stb->numOfOutWords=1;
    }
      else if(strcmp(sType, "STB3600DDO")==0||strcmp(sType, "DDO3600")==0)
   {
    stb->type=2;
       stb->numOfInWords=2;
    stb->numOfOutWords=1;
    }
      else if(strcmp(sType, "EPI2145")==0)
   {
    stb->type=3;
       stb->numOfInWords=6;
    stb->numOfOutWords=1;
   }
      else if(strcmp(sType, "AVI1270")==0)
   {
    stb->type=6;
       stb->numOfInWords=4;
    stb->numOfOutWords=0;
   }
      else if(strcmp(sType, "AVO1250")==0)
   {
    stb->type=7;
       stb->numOfInWords=2;
    stb->numOfOutWords=2;
   }
      stb->idata = tmpiptr;
      stb->odata = tmpoptr;
      tmpiptr += stb->numOfInWords;
      tmpoptr += stb->numOfOutWords;
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {
      strncpy(stb->module_name, &buffer[5], strlen(&buffer[5])-1);
    }
    else
  {
      getConnectData(buffer,stb);
    }
  }
  fclose(fp);
  if(i+1 != dio->numOfModules)
  {
    printf("Error: numOfModules (%d) given in '%s' does not match number of dios detected (%d)\n",dio->numOfModules, filename, i+1);
    exit(99);
  }
  for(i=0;i<dio->numOfModules;i++)
  {
    dio->numOfInWords += dio->iotab[i].numOfInWords;
    dio->numOfOutWords += dio->iotab[i].numOfOutWords;
  }
  return 1;
}

int tmpnICPconLoad(const char *filename, tmpnICPcon *icpcon)
{
  FILE *fp;
  char buffer[256];
 int icp_version, i;
  icpconstruct *icp=((void *)0);
 icpcon->simulate = 0;
 sprintf(icpcon->ipaddr,"%s","");
  icpcon->numOfModules = 0;

  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("LoadICPconConf: Unknown file %s\n",filename);
    return 0;
  }
  fscanf(fp,"ICPCONVERSION %d\n",&icp_version);
  if(icp_version!=1)
  {
  printf("LoadICPconConf: Unknown version %d\n", icp_version);
    exit(99);
  }
  i=0;
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&icpcon->numOfModules);
      icpcon->iotab = malloc(sizeof(icpconstruct)*icpcon->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&icpcon->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",icpcon->ipaddr);
    }
  else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&icpcon->port);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
      i++;
      if(i+1 > icpcon->numOfModules)
      {
        printf("Error: '%s' contains more icpcons than numOfModules (%d)\n", filename, icpcon->numOfModules);
        exit(99);
      }
   icp = (icpconstruct *)&icpcon->iotab[i];
      icp->dosetup=0;
      icp->numOfInBits=0;
      icp->numOfOutBits=0;
   icp->address=0;
   icp->idata=0;
   icp->odata=0;
      sscanf(buffer,"Type=%s\n",icp->typeStr);
      if(strcmp(icp->typeStr, "7063BD")==0)
   {
    icp->type=0;
    icp->numOfInBits=8;
    icp->numOfOutBits=3;
   }
   else
   {
    printf("ICPcon: No other modules than 7063BD implemented at the time\n");
    exit(99);
   }
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {
   if (icp!=((void *)0))
   {
    strncpy(icp->module_name, &buffer[5], strlen(&buffer[5])-1);
   }
   else
   {
    printf("No module selected before line '%s' in .icpcon file\n",buffer);
    exit(99);
   }
    }
    else if(strncmp(buffer,"Address=",8)==0)
    {
   if (icp!=((void *)0))
   {
    sscanf(buffer,"Address=%d\n",&icp->address);
   }
   else
   {
    printf("No module selected before line '%s' in .icpcon file\n",buffer);
    exit(99);
   }
    }
  else if(strncmp(buffer,"DoSetup=",8)==0)
    {
   if (icp!=((void *)0))
   {
    sscanf(buffer,"DoSetup=%d\n",&icp->dosetup);
   }
   else
   {
    printf("No module selected before line '%s' in .icpcon file\n",buffer);
    exit(99);
   }
  }
  else if (strncmp(buffer,"In",2)==0)
  {
   if (icp!=((void *)0))
   {
    int num=0;
    int dotplace;
    if (buffer[3]=='=')
    {
     num=buffer[2]-'0';
     dotplace=3;
    }
    else if (buffer[4]=='=')
    {
     num=(buffer[2]-'0')*10+(buffer[3]-'0');
     dotplace=4;
    }
    else
    {
     printf("ICPcon: The line '%s' can't be parsed!\n",buffer);
     exit(99);
    }
    if (num > icp->numOfInBits)
    {
     printf("ICPcon: index-range for line '%s' in .icpcon file is too high\n",buffer);
     exit(99);
    }
    icp->inconnect[num-1].bitpos=num-1;
    int dplace[2]={0,0};
    int success=0;
    int i,j;
    for (j=0;j<2;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=2)
    {
     printf("Unknown connecttype '%s' in .icpcon file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    strncpy(icp->inconnect[num-1].key,&buffer[dplace[0]+1],keylen);
    icp->inconnect[num-1].key[keylen]='\0';
    icp->inconnect[num-1].udata=&(icp->idata);
   }
   else
   {
    printf("No module selected before line '%s' in .icpcon file\n",buffer);
    exit(99);
   }
  }
  else if (strncmp(buffer,"Out",3)==0)
  {
   if (icp!=((void *)0))
   {
    int num=0;
    int dotplace;
    if (buffer[4]=='=')
    {
     num=buffer[3]-'0';
     dotplace=4;
    }
    else if (buffer[5]=='=')
    {
     num=(buffer[3]-'0')*10+(buffer[4]-'0');
     dotplace=5;
    }
    else
    {
     printf("ICPcon: The line '%s' can't be parsed!\n",buffer);
     exit(99);
    }
    if (num > icp->numOfOutBits)
    {
     printf("ICPcon: index-range for line '%s' in .icpcon file is too high\n",buffer);
     exit(99);
    }
    icp->outconnect[num-1].bitpos=num-1;
    int dplace[2]={0,0};
    int success=0;
    int i,j;
    for (j=0;j<2;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=2)
    {
     printf("Unknown connecttype '%s' in .icpcon file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    strncpy(icp->outconnect[num-1].key,&buffer[dplace[0]+1],keylen);
    icp->outconnect[num-1].key[keylen]='\0';
    icp->outconnect[num-1].udata=&(icp->odata);
   }
   else
   {
    printf("No module selected before line '%s' in .icpcon file\n",buffer);
    exit(99);
   }
  }
  }
  fclose(fp);
  if(i+1 != icpcon->numOfModules)
  {
    printf("Error: numOfModules (%d) given in '%s' does not match number of icpcon detected (%d)\n",icpcon->numOfModules, filename, i+1);
    exit(99);
  }
  return 1;
}

int tmpnUdpAgentLoad(const char *filename, tmpnUdpAgents *udpagents,int type)
{
  FILE *fp;
  char buffer[512];
 int version,fileversion=-1, i;
  tmpnUdpAgentStruct *udpagent=((void *)0);
  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("Couldn't open udpagent file: %s\n",filename);
    return 0;
  }
 if (type==0)
 {
  fscanf(fp,"UDPSERVERVERSION %d\n",&fileversion);
  version=1;
 }
 else
 {
  fscanf(fp,"UDPCLIENTVERSION %d\n",&fileversion);
  version=1;
 }
  if(fileversion!=version)
  {
    printf("UDP version mismatch. Detected version %d. Only supports %d\n",fileversion,version);
    fclose(fp);
    exit(99);
  }
 if (type==0)
 {
  if(udpagents->servers_maxidx==0)
   udpagents->server = (tmpnUdpAgentStruct *)malloc(sizeof(tmpnUdpAgentStruct));
  else
   udpagents->server = (tmpnUdpAgentStruct *)realloc(udpagents->server,sizeof(tmpnUdpAgentStruct)*(udpagents->servers_maxidx + 1));
  udpagent = &udpagents->server[udpagents->servers_maxidx++];
 }
 else
 {
  if(udpagents->clients_maxidx==0)
   udpagents->client = (tmpnUdpAgentStruct *)malloc(sizeof(tmpnUdpAgentStruct));
  else
   udpagents->client = (tmpnUdpAgentStruct *)realloc(udpagents->client,sizeof(tmpnUdpAgentStruct)*(udpagents->clients_maxidx + 1));
  udpagent = &udpagents->client[udpagents->clients_maxidx++];
 }
  udpagent->type=type;
 udpagent->simulate = 0;
 sprintf(udpagent->ipaddr,"%s","");
  udpagent->maxqlines = 0;
  i=-1;
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
  if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&udpagent->simulate);
    }
    else if(strncmp(buffer,"serverip=",9)==0)
    {
      sscanf(buffer,"serverip=%s\n",udpagent->ipaddr);
    }
  else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&udpagent->port);
    }
    else if(strncmp(buffer,"QUESTION",8)==0)
    {
      i++;
      if(i >= 32)
      {
        printf("Error: '%s' contains more QUESTION-lines than allowed (%d)\n", filename, 32);
        exit(99);
      }

   int dotplace=7;
   int i,j;
   int dplace[4]={0,0,0,0};
   int success=0;
   int vcount=0;
   int vtype[10]={0,0,0,0,0,0,0,0,0,0};
   for (j=0;j<4;j++)
   {
    for (i=dotplace+1;i<strlen(buffer);i++)
    {
     if (buffer[i]=='"')
     {
      dplace[success++]=i;
       dotplace=i;
     }
     else if (success==2)
     {
      if (buffer[i]=='%')
      {

       if (buffer[i+1]=='f'||buffer[i+1]=='d')
        vtype[vcount]=1;
       else if (buffer[i+1]=='i'||buffer[i+1]=='d')
        vtype[vcount]=0;
       else
       {
        printf("1. Unknown format in line '%s' in .udp file\n",buffer);
        exit(99);
       }
       vcount++;
      }
     }
    }
   }
   if (success!=4)
   {
    printf("2. Unknown QUESTION type '%s' in .udp file\n",buffer);
    exit(99);
   }
   if (strncmp(&buffer[dplace[1]+2],"RESPONSE",8))
   {
    printf("3. Unknown RESPONSE type '%s' in .udp file\n",buffer);
    exit(99);
   }

   int questionlen=dplace[1]-dplace[0];
   int responselen=dplace[3]-dplace[2];
   tmpnUdpQuestionStruct *udpqstruct=&udpagent->qlines[udpagent->maxqlines];
   strncpy(udpqstruct->questionformat,&buffer[dplace[0]],questionlen);
   strncpy(udpqstruct->responseformat,&buffer[dplace[2]],responselen);
   udpqstruct->maxresponseval=0;
   dotplace=dplace[3]+1;
   for (i=dplace[3]+1;i<strlen(buffer);i++)
   {
    if (buffer[i]==':')
    {
     char stmname[128];
     char valname[128];
     if (sscanf(&buffer[i+1]," STMVAL(%127[^,],%127[^)]) ",stmname,valname)==2)
     {
      int stmidx;
      stmidx=getMachineIdx(stmname);
      if (stmidx==-1)
      {
       printf("4. Unknown Statemachine in RESPONSE-format '%s' in .udp file\n",buffer);
       exit(99);
      }
      udpqstruct->responseval[udpqstruct->maxresponseval]=(tmpnStateMachineValue *)getMachineValuePtr(stmidx, valname);
      if (udpqstruct->responseval[udpqstruct->maxresponseval]==((void *)0))
      {
       printf("5. Unknown Statemachine-value in RESPONSE-format '%s' in .udp file\n",buffer);
       exit(99);
      }
      if (udpqstruct->responseval[udpqstruct->maxresponseval]->subtype!=vtype[udpqstruct->maxresponseval])
      {
       printf("6. Mismatch between Statemachine-value type and format type in RESPONSE-format '%s' in .udp file\n",buffer);
       exit(99);
      }
      udpqstruct->maxresponseval++;
      if (udpqstruct->maxresponseval>vcount||udpqstruct->maxresponseval>10)
      {
       printf("7. Too many STMVAL's for RESPONSE-format '%s' in .udp file\n",buffer);
       exit(99);
      }
      if (udpqstruct->maxresponseval==vcount&&type==1)
      {
       float freq=1;
       if (sscanf(&buffer[i+1]," freq=%f ",&freq)==1)
       {
        udpqstruct->freq=freq;
       }
      }
     }
    }
   }
   if (udpqstruct->maxresponseval!=vcount)
   {
    printf("8. Mismatch beween format and STMVAL parameters for RESPONSE-format '%s' in .udp file\n",buffer);
    exit(99);
   }
   udpagent->maxqlines++;
  }
  }
  fclose(fp);
  return 1;
}

int tmpnComSKLoad(const char *filename, tmpnComSK *comsk)
{
  FILE *fp;
  char buffer[256];
 char type[64];
  int comsk_version, i;
  comskstruct *freq=((void *)0);

 comsk->sfd=-1;
  comsk->simulate = 0;
  sprintf(comsk->ipaddr,"%s","");
  comsk->numOfModules = 0;
 comsk->type = -1;

  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("LoadComskConf: Unknown file %s\n",filename);
    return 0;
  }
  fscanf(fp,"COMSKVERSION %d\n",&comsk_version);
  if(comsk_version!=1)
  {



  printf("LoadComskConf: Unknown version %d\n", comsk_version);
    exit(99);
  }
  i=0;
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&comsk->numOfModules);
      comsk->iotab = malloc(sizeof(comskstruct)*comsk->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&comsk->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",comsk->ipaddr);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
   type[63]='\0';
   sscanf(buffer,"Type=%63s",type);
   if (!strncmp(type,"WONLY",5)) comsk->type=0;
   else if (!strncmp(type,"RW",2)) comsk->type=1;
  }
  else if(strncmp(buffer,"Name=",5)==0)
    {
      i++;
     freq = (comskstruct *)&comsk->iotab[i];
   freq->numOfInitWords=0;
      freq->numOfInWords=0;
      freq->numOfOutWords=0;
      sscanf(buffer,"Name=%255s\n",freq->module_name);
  }
  else if(strncmp(buffer,"Address=",8)==0)
  {
   if (freq!=((void *)0))
   {
    sscanf(buffer,"Address=%d\n",&freq->address);
   }
    }
    else if (strncmp(buffer,"Init",4)==0)
  {
   if (freq!=((void *)0))
   {
    int dotplace=0;
    if (buffer[5]=='.')
    {
     freq->initdata[freq->numOfInitWords].major=buffer[4]-'0';
     dotplace=5;
    }
    else if (buffer[6]=='.')
    {
     freq->initdata[freq->numOfInitWords].major=10*(buffer[4]-'0')+(buffer[5]-'0');
     dotplace=6;
    }
    else
    {
     printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    if (buffer[dotplace+2]=='=')
    {
     freq->initdata[freq->numOfInitWords].minor=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     freq->initdata[freq->numOfInitWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    float temp;
    if (sscanf(&buffer[dotplace+1],"%f",&temp)!=1)
    {
     printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    freq->initdata[freq->numOfInitWords].fdata=temp;
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(freq->initdata[freq->numOfInitWords].key,&buffer[dplace[0]+1],keylen);
    freq->initdata[freq->numOfInitWords].key[keylen]='\0';
    strncpy(freq->initdata[freq->numOfInitWords].comment,&buffer[dplace[2]+1],commentlen);
    freq->initdata[freq->numOfInitWords].comment[commentlen]='\0';
    if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->initdata[freq->numOfInitWords].fixdec)!=1)
    {
     printf("5. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    freq->initdata[freq->numOfInitWords].factor=pow(10.0,(float)freq->initdata[freq->numOfInitWords].fixdec);
    freq->numOfInitWords++;
   }
  }
  else if (strncmp(buffer,"Output",6)==0)
  {
   if (freq!=((void *)0))
   {
    int dotplace=0;
    if (buffer[7]=='.')
    {
     freq->odata[freq->numOfOutWords].major=buffer[6]-'0';
     dotplace=7;
    }
    else if (buffer[8]=='.')
    {
     freq->odata[freq->numOfOutWords].major=10*(buffer[6]-'0')+(buffer[7]-'0');
     dotplace=8;
    }
    else
    {
     printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    if (buffer[dotplace+2]=='=')
    {
     freq->odata[freq->numOfOutWords].minor=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     freq->odata[freq->numOfOutWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(freq->odata[freq->numOfOutWords].key,&buffer[dplace[0]+1],keylen);
    freq->odata[freq->numOfOutWords].key[keylen]='\0';
    strncpy(freq->odata[freq->numOfOutWords].comment,&buffer[dplace[2]+1],commentlen);
    freq->odata[freq->numOfOutWords].comment[commentlen]='\0';
    if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->odata[freq->numOfOutWords].fixdec)!=1)
    {
     printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    freq->odata[freq->numOfOutWords].factor=pow(10.0,(float)freq->odata[freq->numOfOutWords].fixdec);
    freq->numOfOutWords++;
    if (freq->numOfOutWords>=10)
    {
     printf("Too many outputs specified for module %s\n",freq->module_name);
     exit(99);
    }
   }
  }
  else if (strncmp(buffer,"Input",5)==0)
  {
   if (freq!=((void *)0))
   {
    int dotplace=0;
    if (buffer[6]=='.')
    {
     freq->idata[freq->numOfInWords].major=buffer[5]-'0';
     dotplace=6;
    }
    else if (buffer[7]=='.')
    {
     freq->idata[freq->numOfInWords].major=10*(buffer[5]-'0')+(buffer[6]-'0');
     dotplace=7;
    }
    else
    {
     printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    if (buffer[dotplace+2]=='=')
    {
     freq->idata[freq->numOfInWords].minor=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     freq->idata[freq->numOfInWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(freq->idata[freq->numOfInWords].key,&buffer[dplace[0]+1],keylen);
    freq->idata[freq->numOfInWords].key[keylen]='\0';
    strncpy(freq->idata[freq->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
    freq->idata[freq->numOfInWords].comment[commentlen]='\0';
    if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->idata[freq->numOfInWords].fixdec)!=1)
    {
     printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
     exit(99);
    }
    freq->idata[freq->numOfInWords].factor=pow(10.0,(float)freq->idata[freq->numOfInWords].fixdec);
    freq->numOfInWords++;
    if (freq->numOfInWords>=10)
    {
     printf("Too many inputs specified for module %s\n",freq->module_name);
     exit(99);
    }
   }
  }
  }
  fclose(fp);
 if (comsk->type==0)
 {
  int i,j;

  int low=65556;
  int high=0;
  int tot=0;
  for (i=0;i<comsk->numOfModules;i++)
  {
   freq = (comskstruct *)&comsk->iotab[i];
   tot+=freq->numOfOutWords;
   for (j=0;j<freq->numOfOutWords;j++)
   {
    int adr = 100*freq->odata[j].major + freq->odata[j].minor;
    if (adr < low ) low=adr;
    if (adr > high ) high=adr;
   }
  }
  if (high-low != tot-1)
  {
   printf("COMSK: non-sequential output addresses not allowed when type=WONLY\n");
   exit(99);
  }
  comsk->highadr=high;
  comsk->lowadr=low;
  comsk->adrcount=tot;
  for (i=0;i<comsk->numOfModules;i++)
  {
   freq = (comskstruct *)&comsk->iotab[i];
   for (j=0;j<freq->numOfOutWords;j++)
   {

    int adr = 100*freq->odata[j].major + freq->odata[j].minor;
    freq->odata[j].data = &comsk->oarray[adr-comsk->lowadr];
   }
  }
 }
  return 1;
}

int tmpnMacLoad(const char *filename, tmpnMac *mac)
{
  FILE *fp;
  char buffer[256];
 char tempbuf[64];
  int mac_version, i;
  macstruct *motor=((void *)0);
 int initmode=1;
 int inoutbitmode=0;
 macConnect* bitparent=((void *)0);

 mac->sfd=-1;
  mac->simulate = 0;
  sprintf(mac->ipaddr,"%s","");
  mac->numOfMotors = 0;
 mac->port=0;
  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("LoadMacConf: Unknown file %s\n",filename);
    return 0;
  }
 strcpy(mac->filename,filename);
  fscanf(fp,"MACVERSION %d\n",&mac_version);
  if(mac_version!=1)
  {
  printf("LoadMacConf: Unknown version %d\n", mac_version);
    exit(99);
  }
  i=0;
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"NumOfMotors=",12)==0)
    {
      sscanf(buffer,"NumOfMotors=%d\n",&mac->numOfMotors);
      mac->iotab = malloc(sizeof(macstruct)*mac->numOfMotors);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&mac->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",mac->ipaddr);
    }
    else if(strncmp(buffer,"port=",5)==0)
    {
   sscanf(buffer,"port=%i",&mac->port);
  }
  else if(strncmp(buffer,"Name=",5)==0)
    {
      i++;
     motor = (macstruct *)&mac->iotab[i];
   motor->numOfInitWords=0;
      motor->numOfInWords=0;
      motor->numOfOutWords=0;
      sscanf(buffer,"Name=%255s\n",motor->module_name);
  }
  else if(strncmp(buffer,"Address=",8)==0)
  {
   if (motor!=((void *)0))
   {
    sscanf(buffer,"Address=%d\n",&motor->address);
   }
    }
  else if (strncmp(buffer,"SaveToFlash",11)==0&&initmode==1)
  {
   motor->initdata[motor->numOfInitWords].type=10;
   motor->initdata[motor->numOfInitWords].reg=0x56;
   motor->numOfInitWords++;
  }
  else if (strncmp(buffer,"SoftWareReset",13)==0&&initmode==1)
  {
   motor->initdata[motor->numOfInitWords].type=10;
   motor->initdata[motor->numOfInitWords].reg=0x57;
   motor->numOfInitWords++;
  }
  else if (strncmp(buffer,"EnterSafeMode",13)==0&&initmode==1)
  {
   motor->initdata[motor->numOfInitWords].type=10;
   motor->initdata[motor->numOfInitWords].reg=0x54;
   motor->numOfInitWords++;
  }
  else if (strncmp(buffer,"ExitSafeMode",12)==0&&initmode==1)
  {
   motor->initdata[motor->numOfInitWords].type=10;
   motor->initdata[motor->numOfInitWords].reg=0x55;
   motor->numOfInitWords++;
  }
  else if (strncmp(buffer,"EndBits",7)==0&&initmode==0)
  {
   inoutbitmode=0;
   bitparent=((void *)0);
  }
    else if (strncmp(buffer,"Init",4)==0&&initmode==1)
  {
   if (motor!=((void *)0))
   {
    motor->initdata[motor->numOfInitWords].userchange=0;
    int dotplace=0;
    if (buffer[5]=='=')
    {
     motor->initdata[motor->numOfInitWords].reg=buffer[4]-'0';
     dotplace=5;
    }
    else if (buffer[6]=='=')
    {
     motor->initdata[motor->numOfInitWords].reg=10*(buffer[4]-'0')+(buffer[5]-'0');
     dotplace=6;
    }
    else if (buffer[7]=='=')
    {
     motor->initdata[motor->numOfInitWords].reg=100*(buffer[4]-'0')+10*(buffer[5]-'0')+(buffer[6]-'0');
     dotplace=7;
    }
    else
    {
     printf("1. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int temp;
    float ftemp;
    if (sscanf(&buffer[dotplace+1],"%f",&ftemp)==1)
    {
     motor->initdata[motor->numOfInitWords].fdata=ftemp;
    }
    if (sscanf(&buffer[dotplace+1],"%i",&temp)==1)
    {
     motor->initdata[motor->numOfInitWords].data=temp;
    }
    else if (!strncmp(&buffer[dotplace+1],"0x",2))
    {
     if (sscanf(&buffer[dotplace+1],"%x",&temp)!=1)
     {
      printf("3.1 Unknown connecttype '%s' in .mac file\n",buffer);
      exit(99);
     }
     motor->initdata[motor->numOfInitWords].data=temp;
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("4. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(motor->initdata[motor->numOfInitWords].key,&buffer[dplace[0]+1],keylen);
    motor->initdata[motor->numOfInitWords].key[keylen]='\0';
    strncpy(motor->initdata[motor->numOfInitWords].comment,&buffer[dplace[2]+1],commentlen);
    motor->initdata[motor->numOfInitWords].comment[commentlen]='\0';
    int tempdot;
    if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
    {
     printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    tempbuf[63]='\0';
    if (!strcmp(tempbuf,"longint"))
    {
     motor->initdata[motor->numOfInitWords].type=2;
    }
    else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
    {
     motor->initdata[motor->numOfInitWords].type=0;
    }
    else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
    {
     motor->initdata[motor->numOfInitWords].type=1;
    }
    else if (!strcmp(tempbuf,"fixed24"))
    {
     motor->initdata[motor->numOfInitWords].type=6;
    }
    else if (!strcmp(tempbuf,"fixed16"))
    {
     motor->initdata[motor->numOfInitWords].type=5;
    }
    else if (!strcmp(tempbuf,"fixed8"))
    {
     motor->initdata[motor->numOfInitWords].type=4;
    }
    else if (!strcmp(tempbuf,"fixed4"))
    {
     motor->initdata[motor->numOfInitWords].type=3;
    }
    else
    {
     printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->initdata[motor->numOfInitWords].factor)!=1)
    {
     motor->initdata[motor->numOfInitWords].factor=1.0;
    }
    else
    {
     if (motor->initdata[motor->numOfInitWords].type==2)
      motor->initdata[motor->numOfInitWords].type=7;
     else if (motor->initdata[motor->numOfInitWords].type==0)
      motor->initdata[motor->numOfInitWords].type=8;
     else if (motor->initdata[motor->numOfInitWords].type==1)
      motor->initdata[motor->numOfInitWords].type=9;
    }
    motor->numOfInitWords++;
    if (motor->numOfInitWords>=50)
    {
     printf("Too many inits specified for module %s\n",motor->module_name);
     exit(99);
    }
   }
  }
  else if (strncmp(buffer,"Out",3)==0)
  {
   if (inoutbitmode!=0)
   {
    printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
    exit(99);
   }
   initmode=0;
   if (motor!=((void *)0))
   {
    motor->odata[motor->numOfOutWords].userchange=0;
    int dotplace=2;
    if (buffer[dotplace+2]=='=')
    {
     motor->odata[motor->numOfOutWords].reg=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     motor->odata[motor->numOfOutWords].reg=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else if (buffer[dotplace+4]=='=')
    {
     motor->odata[motor->numOfOutWords].reg=100*(buffer[dotplace+1]-'0')+10*(buffer[dotplace+2]-'0')+(buffer[dotplace+3]-'0');
     dotplace+=4;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(motor->odata[motor->numOfOutWords].key,&buffer[dplace[0]+1],keylen);
    motor->odata[motor->numOfOutWords].key[keylen]='\0';
    strncpy(motor->odata[motor->numOfOutWords].comment,&buffer[dplace[2]+1],commentlen);
    motor->odata[motor->numOfOutWords].comment[commentlen]='\0';
    int tempdot;
    if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
    {
     printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    tempbuf[63]='\0';
    if (!strcmp(tempbuf,"longint"))
    {
     motor->odata[motor->numOfOutWords].type=2;
    }
    else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
    {
     motor->odata[motor->numOfOutWords].type=0;
    }
    else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
    {
     motor->odata[motor->numOfOutWords].type=1;
    }
    else if (!strcmp(tempbuf,"fixed24"))
    {
     motor->odata[motor->numOfOutWords].type=6;
    }
    else if (!strcmp(tempbuf,"fixed16"))
    {
     motor->odata[motor->numOfOutWords].type=5;
    }
    else if (!strcmp(tempbuf,"fixed8"))
    {
     motor->odata[motor->numOfOutWords].type=4;
    }
    else if (!strcmp(tempbuf,"fixed4"))
    {
     motor->odata[motor->numOfOutWords].type=3;
    }
    else
    {
     printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->odata[motor->numOfOutWords].factor)!=1)
    {
     motor->odata[motor->numOfOutWords].factor=1.0;
    }
    else
    {
     if (motor->odata[motor->numOfOutWords].type==2)
      motor->odata[motor->numOfOutWords].type=7;
     else if (motor->odata[motor->numOfOutWords].type==0)
      motor->odata[motor->numOfOutWords].type=8;
     else if (motor->odata[motor->numOfOutWords].type==1)
      motor->odata[motor->numOfOutWords].type=9;
    }
    motor->numOfOutWords++;
    if (motor->numOfOutWords>=50)
    {
     printf("Too many outputs specified for module %s\n",motor->module_name);
     exit(99);
    }
   }
  }
  else if (strncmp(buffer,"Bit",3)==0)
  {
   if (inoutbitmode!=2)
   {
    printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
    exit(99);
   }
   if (motor!=((void *)0)&&bitparent!=((void *)0))
   {
    motor->idata[motor->numOfInWords].userchange=0;
    motor->idata[motor->numOfInWords].bitparent=bitparent;
    motor->idata[motor->numOfInWords].type=2;
    int dotplace=2;
    if (buffer[dotplace+2]=='=')
    {
     motor->idata[motor->numOfInWords].bitmode=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     motor->idata[motor->numOfInWords].bitmode=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(motor->idata[motor->numOfInWords].key,&buffer[dplace[0]+1],keylen);
    motor->idata[motor->numOfInWords].key[keylen]='\0';
    strncpy(motor->idata[motor->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
    motor->idata[motor->numOfInWords].comment[commentlen]='\0';
    motor->numOfInWords++;
    if (motor->numOfInWords>=100)
    {
     printf("Too many inputs specified for module %s\n",motor->module_name);
     exit(99);
    }
   }
  }
  else if (strncmp(buffer,"In",2)==0)
  {
   if (inoutbitmode!=0)
   {
    printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
    exit(99);
   }
   initmode=0;
   if (motor!=((void *)0))
   {
    motor->idata[motor->numOfInWords].userchange=0;
    int dotplace=1;
    if (!strncmp(&buffer[2],"Out",3))
    {
     dotplace+=3;
     inoutbitmode=1;
    }
    if (!strncmp(&buffer[2],"Bits",4))
    {
     dotplace+=4;
     inoutbitmode=2;
     bitparent=&motor->idata[motor->numOfInWords];
    }
    motor->idata[motor->numOfInWords].bitmode=-1;
    if (buffer[dotplace+2]=='=')
    {
     motor->idata[motor->numOfInWords].reg=buffer[dotplace+1]-'0';
     dotplace+=2;
    }
    else if (buffer[dotplace+3]=='=')
    {
     motor->idata[motor->numOfInWords].reg=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
     dotplace+=3;
    }
    else if (buffer[dotplace+4]=='=')
    {
     motor->idata[motor->numOfInWords].reg=100*(buffer[dotplace+1]-'0')+10*(buffer[dotplace+2]-'0')+(buffer[dotplace+3]-'0');
     dotplace+=4;
    }
    else
    {
     printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int i,j;
    int dplace[4]={0,0,0,0};
    int success=0;
    for (j=0;j<4;j++)
    {
     for (i=dotplace+1;i<strlen(buffer);i++)
     {
      if (buffer[i]=='"')
      {
       dplace[success++]=i;
       dotplace=i;
      }
     }
    }
    if (success!=4)
    {
     printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    int keylen=dplace[1]-dplace[0]-1;
    int commentlen=dplace[3]-dplace[2]-1;
    strncpy(motor->idata[motor->numOfInWords].key,&buffer[dplace[0]+1],keylen);
    motor->idata[motor->numOfInWords].key[keylen]='\0';
    strncpy(motor->idata[motor->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
    motor->idata[motor->numOfInWords].comment[commentlen]='\0';
    int tempdot;
    if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
    {
     printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    tempbuf[63]='\0';
    if (!strcmp(tempbuf,"longint"))
    {
     motor->idata[motor->numOfInWords].type=2;
    }
    else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
    {
     motor->idata[motor->numOfInWords].type=0;
    }
    else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
    {
     motor->idata[motor->numOfInWords].type=1;
    }
    else if (!strcmp(tempbuf,"fixed24"))
    {
     motor->idata[motor->numOfInWords].type=6;
    }
    else if (!strcmp(tempbuf,"fixed16"))
    {
     motor->idata[motor->numOfInWords].type=5;
    }
    else if (!strcmp(tempbuf,"fixed8"))
    {
     motor->idata[motor->numOfInWords].type=4;
    }
    else if (!strcmp(tempbuf,"fixed4"))
    {
     motor->idata[motor->numOfInWords].type=3;
    }
    else
    {
     printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
     exit(99);
    }
    if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->idata[motor->numOfInWords].factor)!=1)
    {
     motor->idata[motor->numOfInWords].factor=1.0;
    }
    else
    {
     if (motor->idata[motor->numOfInWords].type==2)
      motor->idata[motor->numOfInWords].type=7;
     else if (motor->idata[motor->numOfInWords].type==0)
      motor->idata[motor->numOfInWords].type=8;
     else if (motor->idata[motor->numOfInWords].type==1)
      motor->idata[motor->numOfInWords].type=9;
    }
    if (inoutbitmode==1)
    {
     inoutbitmode=0;
     motor->odata[motor->numOfOutWords].userchange=0;
     motor->odata[motor->numOfOutWords].factor=motor->idata[motor->numOfInWords].factor;
     motor->odata[motor->numOfOutWords].type=motor->idata[motor->numOfInWords].type;
     strcpy(motor->odata[motor->numOfOutWords].key,motor->idata[motor->numOfInWords].key);
     strcpy(motor->odata[motor->numOfOutWords].comment,motor->idata[motor->numOfInWords].comment);
     motor->odata[motor->numOfOutWords].reg=motor->idata[motor->numOfInWords].reg;
     motor->numOfOutWords++;
     if (motor->numOfOutWords>=50)
     {
      printf("Too many outputs specified for module %s\n",motor->module_name);
      exit(99);
     }
    }
    motor->numOfInWords++;
    if (motor->numOfInWords>=100)
    {
     printf("Too many inputs specified for module %s\n",motor->module_name);
     exit(99);
    }
   }
  }
  }
  fclose(fp);
 return 1;
}

int tmpnLoadCellLoad(const char *filename, tmpnLoadCell *loadcell)
{
  FILE *fp;
  char buffer[256];
  int loadcell_version;
  loadcellConnect *lcc=((void *)0);

 loadcell->sfd=-1;
  loadcell->simulate = 0;
  sprintf(loadcell->ipaddr,"%s","");
  loadcell->numOfModules = 0;
 loadcell->port=0;
 loadcell->fastmoxa=0;
  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("LoadLoadCellConf: Unknown file %s\n",filename);
    return 0;
  }
  fscanf(fp,"LOADCELLVERSION %d\n",&loadcell_version);
  if(loadcell_version!=1)
  {
  printf("LoadLoadCellConf: Unknown version %d\n", loadcell_version);
    exit(99);
  }
  while(fgets(buffer,sizeof(buffer), fp)!=((void *)0))
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&loadcell->numOfModules);
   if ((loadcell->numOfModules <= 0) || (loadcell->numOfModules > 8))
   {
    printf("1. numOfModules out of range '%s' (%d) in .loadcell file\n",buffer,loadcell->numOfModules);
    exit(99);
   }
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&loadcell->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",loadcell->ipaddr);
    }
  else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&loadcell->port);
    }
  else if(strncmp(buffer,"fastmoxa=",9)==0)
    {
      sscanf(buffer,"fastmoxa=%d\n",&loadcell->fastmoxa);
    }
    else if (strncmp(buffer,"LoadCell",8)==0)
  {
   int address=-1;
   if (buffer[9]=='=')
   {
    address=buffer[8]-'0';
    if ((address >= 0) && (address < loadcell->numOfModules))
    {
     lcc=&loadcell->iotab[address];
    }
    else
    {
     printf("1. Address out of range '%s' (%d) in .loadcell file\n",buffer,address);
     exit(99);
    }
   }
   else
   {
    printf("2. Unknown connecttype '%s' in .loadcell file\n",buffer);
    exit(99);
   }
   int dotplace;
   int i,j;
   int dplace[4]={0,0,0,0};
   int success=0;
   dotplace=9;
   for (j=0;j<4;j++)
   {
    for (i=dotplace+1;i<strlen(buffer);i++)
    {
     if (buffer[i]=='"')
     {
      dplace[success++]=i;
      dotplace=i;
     }
    }
   }
   if (success!=4)
   {
    printf("3. Unknown connecttype '%s' in .loadcell file\n",buffer);
    exit(99);
   }
   int keylen=dplace[1]-dplace[0]-1;
   int commentlen=dplace[3]-dplace[2]-1;
   strncpy(lcc->key,&buffer[dplace[0]+1],keylen);
   lcc->key[keylen]='\0';
   strncpy(lcc->comment,&buffer[dplace[2]+1],commentlen);
   lcc->comment[commentlen]='\0';
   char str[64];
   if ((sscanf(&buffer[dplace[3]+1]," %63s",str)==1)&&(!strncmp(str,"ignoreError",11)))
   {
    lcc->ignoreError=1;
   }
   else
   {
    lcc->ignoreError=0;
   }
  }
  }
  fclose(fp);
  return 1;
}


int tmpnWorkcellLoad(const char *fn, tmpnWorkcell *workcell)
{
  FILE *fp;
  char buffer[256];
  char s[256];
  char filename[256];
  int i,version;
 struct udpsave
 {
  char filename[256];
  int type;
 };
 struct udpsave us[10];
 int udpagentcount=0;

  fp = fopen(fn,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"VERSION %d\n",&version);
  if(version>2)
  {
    printf("Workcell version mismatch. Detected version %d. Supports up to version %d\n",version,2);
    fclose(fp);
    exit(99);
  }
  strcpy(workcell->filename, fn);
  fscanf(fp,"%s\n",workcell->name);

  if(version == 1)
  {
    fscanf(fp,"%s %d\n",s,&workcell->robots.maxidx);
    for(i=0;i<workcell->robots.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/robot/%s",databasePath,s);
      workcell->robots.robot[i]=*initrobot;
      tmpnRobotLoad(filename, &workcell->robots.robot[i]);
    }
    selectRobot(0);
    fscanf(fp,"%s %d\n",s,&workcell->tools.maxidx);
    for(i=0;i<workcell->tools.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/tool/%s",databasePath,s);
      if (tmpnToolLoad(filename, &workcell->tools.tool[i]) == 0)
      {
        printf("couldn't find tool \"%s\"\n",filename);
        exit(1);
      }
    }
    fscanf(fp,"%s %d\n",s,&workcell->items.maxidx);
    for(i=0;i<workcell->items.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/item/%s",databasePath,s);
      tmpnItemLoad(filename, &workcell->items.item[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->patterns.maxidx);
    for(i=0;i<workcell->patterns.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/pattern/%s",databasePath,s);
      tmpnPatternLoad(filename, &workcell->patterns.pattern[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->accessories.maxidx);
    for(i=0;i<workcell->accessories.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/accessory/%s",databasePath,s);
      tmpnAccessoryLoad(filename, &workcell->accessories.accessory[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->ppscripts.maxidx);
    for(i=0;i<workcell->ppscripts.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/ppscript/%s",databasePath,s);
      tmpnPPScriptLoad(filename, &workcell->ppscripts.ppscript[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->dios.maxidx);
    for(i=0;i<workcell->dios.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/dio/%s",databasePath,s);
      tmpnDIOLoad(filename, &workcell->dios.dio[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->comsks.maxidx);
    for(i=0;i<workcell->comsks.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/comsk/%s",databasePath,s);
      tmpnComSKLoad(filename, &workcell->comsks.comsk[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->loadcells.maxidx);
    for(i=0;i<workcell->loadcells.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/loadcell/%s",databasePath,s);
      tmpnLoadCellLoad(filename, &workcell->loadcells.loadcell[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->macs.maxidx);
    for(i=0;i<workcell->macs.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/mac/%s",databasePath,s);
      tmpnMacLoad(filename, &workcell->macs.mac[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->statemachines.maxidx);
    if(workcell->statemachines.maxidx>0)
    {



      workcell->statemachines.statemachine = (tmpnStateMachine*)malloc(sizeof(tmpnStateMachine)*workcell->statemachines.maxidx);
      tmpnStateMachineReset();
    }
    for(i=0;i<workcell->statemachines.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/statemachine/%s",databasePath,s);
      workcell->statemachines.statemachine[i].numstate = 0;
      workcell->statemachines.statemachine[i].delaystop = 0;
      workcell->statemachines.statemachine[i].state = ((void *)0);
      workcell->statemachines.statemachine[i].value = ((void *)0);
      workcell->statemachines.statemachine[i].timeout = ((void *)0);
      workcell->statemachines.statemachine[i].input = ((void *)0);
      workcell->statemachines.statemachine[i].output = ((void *)0);
      workcell->statemachines.statemachine[i].link = ((void *)0);
      tmpnStateMachineLoad(filename, &workcell->statemachines.statemachine[i],0);
   tmpnStateLoad(filename, &workcell->statemachines.statemachine[i], 0);
  }

    workcell->boptcoeff.maxidx=0;
    workcell->languages.numoflanguages=0;
    workcell->languages.currentLanguage=0;
    workcell->statetekstlist.numofStateTeksts=0;
    workcell->statetekstlist.currentStateTekst=0;
    while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
    {
      if(strncmp(buffer,"SCRIPT",6)==0)
      {
        sscanf(buffer,"SCRIPT %s\n",workcell->scripts.item[workcell->scripts.maxidx++].name);
      }
      else if(strncmp(buffer,"STATETEKST",10)==0)
      {
        char name[128];
        sscanf(buffer,"STATETEKST %127s\n",name);
        sprintf(s,"%s/statetekst/%s",databasePath,name);
        tmpnStateTekstsLoad(s,&workcell->statetekstlist);
      }
      else if(!strncmp(buffer,"REMOTEHOST",10))
      {
        if (workcell->remotehosts.maxidx < 5)
        {
          int idx = workcell->remotehosts.maxidx++;
          int a,b,c,d;
          workcell->remotehosts.remotehost[idx].port = 1299;
          sscanf(buffer,"REMOTEHOST %d.%d.%d.%d:%d\n",&a,&b,&c,&d,&workcell->remotehosts.remotehost[idx].port);
          sprintf(workcell->remotehosts.remotehost[idx].name,"%d.%d.%d.%d",a,b,c,d);
          workcell->remotehosts.remotehost[idx].sockfd = -1;
          workcell->remotehosts.remotehost[idx].sndbuf_idx = 0;
          workcell->remotehosts.remotehost[idx].repeat = 0;
          workcell->remotehosts.remotehost[idx].alive = 0;
          printf("REMOTEHOST=%s:%d declared\n",workcell->remotehosts.remotehost[idx].name,workcell->remotehosts.remotehost[idx].port);
        }
        else
        {
          printf("MAXREMOTEHOSTS\n");
          exit(99);
        }
      }
      else if(!strncmp(buffer,"BOPTCOEFF",9))
      {
        char name[128];
        sscanf(buffer,"BOPTCOEFF %127s\n",name);
        sprintf(filename,"%s/boptcoeff/%s",databasePath,name);
        tmpnBoptCoeffLoad(filename, &workcell->boptcoeff);
      }
      else if(!strncmp(buffer,"LANGUAGE",8))
      {
        char name[128];
        sscanf(buffer,"LANGUAGE %127s\n",name);
        sprintf(filename,"%s/language/%s",databasePath,name);
        tmpnLanguageLoad(filename, &workcell->languages);
      }
      else{
        char str[256];
        sscanf(buffer, "%s\n", str);
        printf("ERROR: Load WorkCell: Cannot recognize line: '%s' Number of statemachines given might be wrong.\n",str);
        exit(99);
      }
    }
  }
  else if(version == 2)
  {
    workcell->robots.maxidx = 0;
    workcell->tools.maxidx = 0;
    workcell->items.maxidx = 0;
    workcell->patterns.maxidx = 0;
    workcell->cppatterns.maxidx = 0;
    workcell->accessories.maxidx = 0;
    workcell->ppscripts.maxidx = 0;
    workcell->dios.maxidx = 0;
    workcell->comsks.maxidx = 0;
    workcell->loadcells.maxidx = 0;
    workcell->macs.maxidx = 0;
  workcell->icpcons.maxidx = 0;
    workcell->statemachines.maxidx = 0;
    workcell->boptcoeff.maxidx=0;
    workcell->languages.numoflanguages=0;
    workcell->languages.currentLanguage=0;
    workcell->statetekstlist.numofStateTeksts=0;
    workcell->statetekstlist.currentStateTekst=0;
    while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
    {
      if(strncmp(buffer, ";", 1)==0)
      {
      }
      else if(strncmp(buffer,"ROBOT",5)==0)
      {
        if(workcell->robots.maxidx < 1)
        {
          char name[128];
          sscanf(buffer,"ROBOT %127s\n",name);
          sprintf(filename,"%s/robot/%s",databasePath,name);
          workcell->robots.robot[workcell->robots.maxidx]=*initrobot;
          tmpnRobotLoad(filename, &workcell->robots.robot[workcell->robots.maxidx]);
          workcell->robots.maxidx++;
          selectRobot(0);
        }
        else
        {
          printf("MAXROBOTS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"TOOL",4)==0)
      {
        if(workcell->tools.maxidx < 3)
        {
          char name[128];
          sscanf(buffer,"TOOL %127s\n",name);
          sprintf(filename,"%s/tool/%s",databasePath,name);
          if (tmpnToolLoad(filename, &workcell->tools.tool[workcell->tools.maxidx]) == 0)
          {
            printf("couldn't find tool \"%s\"\n",filename);
            exit(1);
          }
          workcell->tools.maxidx++;
        }
        else
        {
          printf("MAXTOOLS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"ITEM",4)==0)
      {
        if(workcell->items.maxidx < 10)
        {
          char name[128];
          sscanf(buffer,"ITEM %127s\n",name);
          sprintf(filename,"%s/item/%s",databasePath,name);
          tmpnItemLoad(filename, &workcell->items.item[workcell->items.maxidx]);
          workcell->items.maxidx++;
        }
        else
        {
          printf("MAXITEMS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"PATTERN",7)==0)
      {
        if(workcell->patterns.maxidx < 12)
        {
          char name[128];
          sscanf(buffer,"PATTERN %127s\n",name);
          sprintf(filename,"%s/pattern/%s",databasePath,name);
          tmpnPatternLoad(filename, &workcell->patterns.pattern[workcell->patterns.maxidx]);
          workcell->patterns.maxidx++;
        }
        else
        {
          printf("MAXPATTERNS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"CPPATTERN",9)==0)
      {
        char name[128];
        sscanf(buffer,"CPPATTERN %127s\n",name);
        sprintf(filename,"%s/cppattern/%s",databasePath,name);
        tmpnCPPatternLoad(filename, &workcell->cppatterns);
      }
      else if(strncmp(buffer,"ACCESSORY",9)==0)
      {
        if(workcell->accessories.maxidx < 10)
        {
          char name[128];
          sscanf(buffer,"ACCESSORY %127s\n",name);
          sprintf(filename,"%s/accessory/%s",databasePath,name);
          tmpnAccessoryLoad(filename, &workcell->accessories.accessory[workcell->accessories.maxidx]);
          workcell->accessories.maxidx++;
        }
        else
        {
          printf("MAXACCESSORIES\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"PPSCRIPT",8)==0)
      {
        if(workcell->ppscripts.maxidx < 10)
        {
          char name[128];
          sscanf(buffer,"PPSCRIPT %127s\n",name);
          sprintf(filename,"%s/ppscript/%s",databasePath,name);
          tmpnPPScriptLoad(filename, &workcell->ppscripts.ppscript[workcell->ppscripts.maxidx]);
          workcell->ppscripts.maxidx++;
        }
        else
        {
          printf("MAXPPSCRIPTS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"DIO",3)==0)
      {
        if(workcell->dios.maxidx < 5)
        {
          char name[128];
          sscanf(buffer,"DIO %127s\n",name);
          sprintf(filename,"%s/dio/%s",databasePath,name);
          tmpnDIOLoad(filename, &workcell->dios.dio[workcell->dios.maxidx]);
          workcell->dios.maxidx++;
        }
        else
        {
          printf("MAXDIO\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"COMSK",5)==0)
      {
        if(workcell->comsks.maxidx < 5)
        {
          char name[128];
          sscanf(buffer,"COMSK %127s\n",name);
          sprintf(filename,"%s/comsk/%s",databasePath,name);
          tmpnComSKLoad(filename, &workcell->comsks.comsk[workcell->comsks.maxidx]);
          workcell->comsks.maxidx++;
        }
        else
        {
          printf("MAXCOMSKS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"LOADCELL",8)==0)
      {
        if(workcell->loadcells.maxidx < 3)
        {
          char name[128];
          sscanf(buffer,"LOADCELL %127s\n",name);
          sprintf(filename,"%s/loadcell/%s",databasePath,name);
          tmpnLoadCellLoad(filename, &workcell->loadcells.loadcell[workcell->loadcells.maxidx]);
          workcell->loadcells.maxidx++;
        }
        else
        {
          printf("MAXLOADCELLS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"MAC",3)==0)
      {
        if(workcell->macs.maxidx < 4)
        {
          char name[128];
          sscanf(buffer,"MAC %127s\n",name);
          sprintf(filename,"%s/mac/%s",databasePath,name);
          tmpnMacLoad(filename, &workcell->macs.mac[workcell->macs.maxidx]);
          workcell->macs.maxidx++;
        }
        else
        {
          printf("MAXMACS\n");
          exit(99);
        }
      }
   else if(strncmp(buffer,"ICPCON",6)==0)
      {
        if(workcell->icpcons.maxidx < 5)
        {
          char name[128];
          sscanf(buffer,"ICPCON %127s\n",name);
          sprintf(filename,"%s/icpcon/%s",databasePath,name);
          tmpnICPconLoad(filename, &workcell->icpcons.icpcon[workcell->icpcons.maxidx]);
          workcell->icpcons.maxidx++;
        }
        else
        {
          printf("MAXICPCONS\n");
          exit(99);
        }
      }
   else if(strncmp(buffer,"UDPSERVER",9)==0)
      {
    char name[128];
    sscanf(buffer,"UDPSERVER %127s\n",name);
    sprintf(filename,"%s/udpagents/%s",databasePath,name);
    strcpy(us[udpagentcount].filename,filename);
    us[udpagentcount].type=0;
    udpagentcount++;
    if (udpagentcount>10)
    {
     printf("MAXUDPAGENTS\n");
     exit(99);
    }
   }
   else if(strncmp(buffer,"UDPCLIENT",9)==0)
      {
        char name[128];
    sscanf(buffer,"UDPCLIENT %127s\n",name);
    sprintf(filename,"%s/udpagents/%s",databasePath,name);
    strcpy(us[udpagentcount].filename,filename);
    us[udpagentcount].type=1;
    udpagentcount++;
    if (udpagentcount>10)
    {
     printf("MAXUDPAGENTS\n");
     exit(99);
    }
   }
      else if(strncmp(buffer,"STM",3)==0)
      {
    if(workcell->statemachines.maxidx==0)
        {



          workcell->statemachines.statemachine = (tmpnStateMachine*)malloc(sizeof(tmpnStateMachine));
        }
        else
        {
          workcell->statemachines.statemachine = (tmpnStateMachine*)realloc(workcell->statemachines.statemachine, sizeof(tmpnStateMachine)*(workcell->statemachines.maxidx + 1));
        }

        int idx = workcell->statemachines.maxidx;
        workcell->statemachines.statemachine[idx].type = -1;
        strcpy(workcell->statemachines.statemachine[idx].name, "");
        workcell->statemachines.statemachine[idx].istate = -1;
        workcell->statemachines.statemachine[idx].next_istate = -1;
        workcell->statemachines.statemachine[idx].new_istate = -1;
        workcell->statemachines.statemachine[idx].timerstate = -1;
    workcell->statemachines.statemachine[idx].debugvalue = ((void *)0);
        workcell->statemachines.statemachine[idx].stop = 0;
        workcell->statemachines.statemachine[idx].mcSignal = 0;
        pthread_cond_init(&workcell->statemachines.statemachine[idx].change, ((void *)0));
        pthread_mutex_init(&workcell->statemachines.statemachine[idx].change_mtx, ((void *)0));
        workcell->statemachines.statemachine[idx].numstate=0;
        workcell->statemachines.statemachine[idx].numvalue=0;
        workcell->statemachines.statemachine[idx].numtimeout=0;
        workcell->statemachines.statemachine[idx].numinput=0;
        workcell->statemachines.statemachine[idx].numoutput=0;
        workcell->statemachines.statemachine[idx].numlink=0;

        char name[128];
        sscanf(buffer,"STM %127s\n",name);
        sprintf(filename,"%s/statemachine/%s",databasePath,name);

        workcell->statemachines.statemachine[idx].numstate = 0;
        workcell->statemachines.statemachine[idx].delaystop = 0;
        workcell->statemachines.statemachine[idx].state = ((void *)0);
        workcell->statemachines.statemachine[idx].value = ((void *)0);
        workcell->statemachines.statemachine[idx].timeout = ((void *)0);
        workcell->statemachines.statemachine[idx].input = ((void *)0);
        workcell->statemachines.statemachine[idx].output = ((void *)0);
        workcell->statemachines.statemachine[idx].link = ((void *)0);
        tmpnStateMachineLoad(filename, &workcell->statemachines.statemachine[idx],0);
    tmpnStateLoad(filename, &workcell->statemachines.statemachine[idx], 0);
        workcell->statemachines.maxidx++;
      }
      else if(strncmp(buffer,"SCRIPT",6)==0)
      {
        sscanf(buffer,"SCRIPT %s\n",workcell->scripts.item[workcell->scripts.maxidx++].name);
      }
      else if(strncmp(buffer,"STATETEKST",10)==0)
      {
        char name[128];
        sscanf(buffer,"STATETEKST %127s\n",name);
        sprintf(s,"%s/statetekst/%s",databasePath,name);
        tmpnStateTekstsLoad(s,&workcell->statetekstlist);
      }
      else if(!strncmp(buffer,"REMOTEHOST",10))
      {
        if (workcell->remotehosts.maxidx < 5)
        {
          int idx = workcell->remotehosts.maxidx++;
          int a,b,c,d;
          workcell->remotehosts.remotehost[idx].port = 1299;
          sscanf(buffer,"REMOTEHOST %d.%d.%d.%d:%d\n",&a,&b,&c,&d,&workcell->remotehosts.remotehost[idx].port);
          sprintf(workcell->remotehosts.remotehost[idx].name,"%d.%d.%d.%d",a,b,c,d);
          workcell->remotehosts.remotehost[idx].sockfd = -1;
          workcell->remotehosts.remotehost[idx].sndbuf_idx = 0;
          workcell->remotehosts.remotehost[idx].repeat = 0;
          workcell->remotehosts.remotehost[idx].alive = 0;
          printf("REMOTEHOST=%s:%d declared\n",workcell->remotehosts.remotehost[idx].name,workcell->remotehosts.remotehost[idx].port);
        }
        else
        {
          printf("MAXREMOTEHOSTS\n");
          exit(99);
        }
      }
      else if(!strncmp(buffer,"BOPTCOEFF",9))
      {
        char name[128];
        sscanf(buffer,"BOPTCOEFF %127s\n",name);
        sprintf(filename,"%s/boptcoeff/%s",databasePath,name);
        tmpnBoptCoeffLoad(filename, &workcell->boptcoeff);
      }
      else if(!strncmp(buffer,"LANGUAGE",8))
      {
        char name[128];
        sscanf(buffer,"LANGUAGE %127s\n",name);
        sprintf(filename,"%s/language/%s",databasePath,name);
        tmpnLanguageLoad(filename, &workcell->languages);
      }
      else
   {
        char str[256];
        sscanf(buffer, "%255s\n", str);
        printf("ERROR: Load WorkCell: Cannot recognize line: '%s'\n",str);
        exit(99);
      }
    }
  }

  workcell->m_root = ((void *)0);

  for(i=0;i<workcell->statemachines.maxidx;i++)
  {
    SetupSTMLink1(&workcell->statemachines.statemachine[i]);
  }
  for(i=0;i<workcell->statemachines.maxidx;i++)
  {
    SetupSTMLink2(&workcell->statemachines.statemachine[i]);
  }
 for (i=0;i<udpagentcount;i++)
 {
  tmpnUdpAgentLoad(us[i].filename, &workcell->udpagents, us[i].type);
 }
  if(rs_param.statemachine_debug>2)
    for(i=0;i<workcell->statemachines.maxidx;i++)
    {
      tmpnStateMachineDump(&workcell->statemachines.statemachine[i]);
    }
  if(workcell->robots.maxidx > 0)
    copyFramesFromSTMtoRobot();

  fclose(fp);
  return 1;
}

const char *tmpnGetDatabase(void)
{
  return &databasePath[0];
}

void tmpnSetDatabase(const char *database)
{
  strcpy(databasePath,database);
}

int tmpnPlantLoad(const char *fn, tmpnPlant *plant)
{
  FILE *fp;
  char s[256];
  char filename[256];
  int w,version;

  sprintf(filename,"%s/plant/%s.plant",databasePath,fn);
  fp = fopen(filename,"r");
  if(fp==((void *)0)) return 0;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=1) return 0;

  fscanf(fp,"%s\n",plant->name);
  fscanf(fp,"%s %d\n",s,&plant->workcells.maxidx);
  if(plant->workcells.maxidx > 2)
  {
    printf("MAXWORKCELLS");
    exit(99);
  }
  for(w=0;w<plant->workcells.maxidx;w++)
  {
    fscanf(fp,"%s\n",s);
    sprintf(filename,"%s/workcell/%s",databasePath,s);
    selectWorkcell(w);
    tmpnWorkcellLoad(filename, &plant->workcells.workcell[w]);
  }
  fclose(fp);
  return 1;
}

void updatecmdPoints(COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *prevpoint = &pdummy;
  POINTSTRUCT* point;
  int level;


  if(cmd==((void *)0)) return;
  level=cmd->flag;
  while(cmd&&cmd->flag>=level)
  {
    if(cmd->type == 10)
    {
      point = (POINTSTRUCT*)cmd->data;
      refreshPoint(cmd);
      prevpoint = (POINTSTRUCT*)cmd->data;
    }
    else if(cmd->type == 27)
    {
      point = (POINTSTRUCT*)cmd->data;
      refreshPoint(cmd);
    }
    else if(cmd->type == 22)
    {
    }
    else if(cmd->type == 14)
    {
      point = (POINTSTRUCT*)cmd->data;
      point->pp.x=prevpoint->fp.x;
      point->pp.y=prevpoint->fp.y;
      point->pp.z=prevpoint->fp.z;
      point->pp.v=prevpoint->fp.v;
      point->pp.w=prevpoint->fp.w;
      point->pp.u=prevpoint->fp.u;
      refreshPoint(cmd);
    }
    else if(cmd->type == 28)
    {
      point = (POINTSTRUCT*)cmd->data;
      point->pp.x=prevpoint->fp.x;
      point->pp.y=prevpoint->fp.y;
      point->pp.z=prevpoint->fp.z;
      point->pp.v=prevpoint->fp.v;
      point->pp.w=prevpoint->fp.w;
      point->pp.u=prevpoint->fp.u;
      refreshPoint(cmd);
    }
    cmd = cmd->next;
  }
}

int getTCPidx(char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<3;i++)
  {
    if(strcmp(name,robot->m_tcp[i].name)==0) return i;
  }
  return -1;
}

int getFrameIdx(const char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<robot->m_frames.maxidx;i++)
  {
    if(strcmp(name,robot->m_frames.frame[i].name)==0)
      return i;
  }
  return -1;
}

float getTimingValue(const char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<robot->timing.maxidx;i++)
  {
    if(strcmp(name,robot->timing.item[i].name)==0)
    {
      return robot->timing.item[i].value;
    }
  }
  return 0.0;
}

int getMachineIdx(const char *name)
{
  int i;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    if(strcmp(tworkcell->statemachines.statemachine[i].name,name)==0) return i;
  }
  if(rs_param.statemachine_debug>2)
    printf("statemachine %s not found\n",name);
  return -1;
}

int getStateIdx(int machine, const char *statename)
{
  int i;
 tmpnStateMachine *stm;
 stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numstate;i++)
  {
    if(strcmp(stm->state[i].name,statename)==0) return i;
  }
  if(rs_param.statemachine_debug>2)
    printf("stateIdx %s for machine (%s)%d not found\n",statename,stm->name,machine);
  return -1;
}

int getMachineStateIdx(const char *machinename, const char *statename)
{
  int machine;
  machine=getMachineIdx(machinename);
  if(machine==-1) return -1;
  return getStateIdx(machine,statename);
}


int getRemoteStatemachineIdx(tmpnWorkcell *workcell,char *str)
{
  int i;
  for(i=0;i<workcell->remotestatemachines.maxidx;i++)
  {
    if (!strcmp(workcell->remotestatemachines.remotestatemachine[i].name,str))
    {
      return i;
    }
  }
  return -1;
}

int getRemoteValueIdx(tmpnWorkcell *workcell,char *str1,char *str2)
{
  int i;
  for(i=0;i<workcell->remotevalues.maxidx;i++)
  {
    if (!strcmp(workcell->remotevalues.remotevalue[i].name,str1)&&!strcmp(workcell->remotevalues.remotevalue[i].link,str2))
    {
      return i;
    }
  }
  return -1;
}





COMMANDSTRUCT *addCommandString(COMMANDSTRUCT *ptrcmd, const char *t, int* level)
{
  COMMANDSTRUCT *cmd=((void *)0);
  tmpnRobot *robot=(tmpnRobot*)trobot;

  char t1[256];
  char t2[256];
  char t3[256];
  int i,forceItem,loadgroup;
  POINTSTRUCT *point;
  if(strncmp(t,"ROOT",4)==0)
  {
    cmd = InsertCommand(ptrcmd,38);
    cmd->flag = *level;
    sscanf(t,"%s",t2);
  }
  else if(strncmp(t,"MOVEABS",7)==0)
  {
    cmd = InsertCommand(ptrcmd,2);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%f,%f",t2,
      &((MOVEABSSTRUCT*)cmd->data)->dest_a,
      &((MOVEABSSTRUCT*)cmd->data)->dest_b,
      &((MOVEABSSTRUCT*)cmd->data)->dest_c,
      &((MOVEABSSTRUCT*)cmd->data)->dest_d,
      &((MOVEABSSTRUCT*)cmd->data)->dest_e
      );
  }
  else if(strncmp(t,"WSP",3)==0)
  {
    cmd = InsertCommand(ptrcmd,7);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%f,%f,%f",t2,
      &((WSPSTRUCT*)cmd->data)->x,
      &((WSPSTRUCT*)cmd->data)->y,
      &((WSPSTRUCT*)cmd->data)->z,
      &((WSPSTRUCT*)cmd->data)->v,
      &((WSPSTRUCT*)cmd->data)->w,
      &((WSPSTRUCT*)cmd->data)->u
      );
  }
  else if(strncmp(t,"SADS",4)==0)
  {
    cmd = InsertCommand(ptrcmd,1);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%d",t2,
      &((SADSSTRUCT*)cmd->data)->speed,
      &((SADSSTRUCT*)cmd->data)->accel,
      &((SADSSTRUCT*)cmd->data)->decel,
      &((SADSSTRUCT*)cmd->data)->sramp
      );
  }
  else if(strncmp(t,"SPLINEHINT",10)==0)
  {
    cmd = InsertCommand(ptrcmd,25);
    cmd->flag = *level;
    sscanf(t,"%s%d%d",t2,
      &((SPLINEHINTSTRUCT*)cmd->data)->splinehint
      ,&((SPLINEHINTSTRUCT*)cmd->data)->splineorder
      );
  }


  else if(strncmp(t,"MOVEAXIS",8)==0)
  {
    cmd = InsertCommand(ptrcmd,18);
    cmd->flag = *level;
    sscanf(t,"%s axis=%d,speed=%f,accel=%f,decel=%f,distance=%f,wait=%d",t2
     ,&((MOVEAXISSTRUCT*)cmd->data)->axis
     ,&((MOVEAXISSTRUCT*)cmd->data)->speed
     ,&((MOVEAXISSTRUCT*)cmd->data)->accel
     ,&((MOVEAXISSTRUCT*)cmd->data)->decel
     ,&((MOVEAXISSTRUCT*)cmd->data)->distance
     ,&((MOVEAXISSTRUCT*)cmd->data)->wait
      );
  }


  else if(strncmp(t,"CANCELAXIS",10)==0)
  {
    cmd = InsertCommand(ptrcmd,6);
    cmd->flag = *level;
    sscanf(t,"%s axis=%d,wait=%d",t2
     ,&((CANCELAXISSTRUCT*)cmd->data)->axis
     ,&((CANCELAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(strncmp(t,"STATEHINT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,23);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,
      &((STATEHINTSTRUCT*)cmd->data)->statehint
      );
  }
  else if(strncmp(t,"POSITIONHINT",12)==0)
  {
    cmd = InsertCommand(ptrcmd,26);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,
      &((POSITIONHINTSTRUCT*)cmd->data)->positionhint
      );
  }
  else if(strncmp(t,"OUT",3)==0)
  {
    cmd = InsertCommand(ptrcmd,8);
    cmd->flag = *level;
    sscanf(t,"%s%d %d",t2,
      &((OUTPUTSTRUCT*)cmd->data)->p,
      &((OUTPUTSTRUCT*)cmd->data)->state
      );
  }
  else if(strncmp(t,"IN",2)==0)
  {
    cmd = InsertCommand(ptrcmd,9);
    cmd->flag = *level;
    sscanf(t,"%s %d\n",t2,&((INPUTSTRUCT*)cmd->data)->p);
  }
  else if(strncmp(t,"SUB",3)==0)
  {
    cmd = InsertCommand(ptrcmd,11);
    cmd->flag = (*level)++;
    sscanf(t,"%s%s",t2,t3);
    strcpy(((NAMESTRUCT*)cmd->data)->name,t3);
  }
  else if(strncmp(t,"PATH",4)==0)
  {
    cmd = InsertCommand(ptrcmd,4);
    cmd->flag = (*level)++;
    ((PATHSTRUCT*)cmd->data)->tpathdef.runbopt = 0;
    sscanf(t,"%s%s id=%d,type=%d,time=%f,loadgroup=%d,runbopt=%d",t2,t3

    ,&((PATHSTRUCT*)cmd->data)->tpathdef.id
    ,&((PATHSTRUCT*)cmd->data)->tpathdef.pathtype
    ,&((PATHSTRUCT*)cmd->data)->tpathdef.maxTime
    ,&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup
    ,&((PATHSTRUCT*)cmd->data)->tpathdef.runbopt
    );
    strcpy(((PATHSTRUCT*)cmd->data)->tpathdef.name,t3);
  }
  else if(strncmp(t,"MACRO",5)==0)
  {
    cmd = InsertCommand(ptrcmd,19);
    cmd->flag = *level;
    sscanf(t,"%s%s%d%d%d",t2,t3
            ,&((MACROSTRUCT*)cmd->data)->parameter0
            ,&((MACROSTRUCT*)cmd->data)->parameter1
            ,&((MACROSTRUCT*)cmd->data)->parameter2);
    strcpy(((MACROSTRUCT*)cmd->data)->name,t3);
    for(i=0;i<18;i++)
    {
      if(strcmp(((MACROSTRUCT*)cmd->data)->name, mpnmacro[i].name)==0)
      {
        ((MACROSTRUCT*)cmd->data)->idx = mpnmacro[i].idx;
        i=18;
      }
    }
  }
  else if(strncmp(t,"RESETPRELOAD",12)==0)
  {
    cmd = InsertCommand(ptrcmd,46);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,&((RESETPRELOADSTRUCT*)cmd->data)->loadgroup);
  }
  else if(strncmp(t,"CALL",4)==0)
  {
    cmd = InsertCommand(ptrcmd,13);
    cmd->flag = *level;
    sscanf(t,"%s%s%d",t2,t3
            ,&((CALLSTRUCT*)cmd->data)->lag);
    strcpy(((CALLSTRUCT*)cmd->data)->script,t3);
  }
  else if(strncmp(t,"LABEL",5)==0)
  {
    cmd = InsertCommand(ptrcmd,16);
    cmd->flag = *level;
    sscanf(t,"%s%s",t2,((LABELSTRUCT*)cmd->data)->label);
  }
  else if(strncmp(t,"JUMPLAYER",9)==0)
  {
    cmd = InsertCommand(ptrcmd,17);
    cmd->flag = *level;
    sscanf(t,"%s%s%d",t2,t3
            ,&((JUMPLAYERSTRUCT*)cmd->data)->layer);
    strcpy(((JUMPLAYERSTRUCT*)cmd->data)->function,t3);
  }
  else if(strncmp(t,"SCOPE",5)==0)
  {
    cmd = InsertCommand(ptrcmd,24);
    cmd->flag = *level;
    sscanf(t,"%s%d%d%d",t2
            ,&((SCOPESTRUCT*)cmd->data)->parameter0
            ,&((SCOPESTRUCT*)cmd->data)->parameter1
            ,&((SCOPESTRUCT*)cmd->data)->parameter2);
  }
  else if(strncmp(t,"GOTO",4)==0)
  {
    cmd = InsertCommand(ptrcmd,21);
    cmd->flag = *level;
    sscanf(t,"%s %s",t2,((GOTOSTRUCT*)cmd->data)->label);
  }
  else if(strncmp(t,"PPSCRIPT",8)==0)
  {

    cmd = InsertCommand(ptrcmd,20);
    cmd->flag = *level;
    sscanf(t,"%s %s idx=%d,loadgroup=%d",t2,t3,&forceItem,&loadgroup);
    strcpy(((PPSCRIPTSTRUCT*)cmd->data)->name,t3);
    ((PPSCRIPTSTRUCT*)cmd->data)->idx=forceItem;
    ((PPSCRIPTSTRUCT*)cmd->data)->loadgroup=loadgroup;
    cmd = expandPath(cmd,level,forceItem,t3,loadgroup);
  }
  else if(strncmp(t,"END",3)==0)
  {
    (*level)--;
    cmd=ptrcmd;
  }
  else if(strncmp(t,"POINT",5)==0)
  {
    cmd = InsertCommand(ptrcmd,10);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
     ,t2
     ,t3
     ,&point->fp.x
     ,&point->fp.y
     ,&point->fp.z
     ,&point->fp.v
     ,&point->fp.w
     ,&point->fp.u
     ,&point->p.dt
     ,t1
      );
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"HPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,27);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"RPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,14);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );

    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"HRPOINT",7)==0)
  {
    cmd = InsertCommand(ptrcmd,28);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );

    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"EPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,22);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->pp.x
      ,&point->pp.y
      ,&point->pp.z
      ,&point->pp.v
      ,&point->pp.w
      ,&point->pp.u
      ,&point->p.dt
      ,t1
      );

    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"TESTEVENT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,31);
    cmd->flag = *level;
    sscanf(t,"%s%s%s",t1,t2,t3);
    ((EVENTSTRUCT*)cmd->data)->type=1;
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}

  }
  else if(strncmp(t,"SLEEP",5)==0)
  {
    cmd = InsertCommand(ptrcmd,32);
    cmd->flag = *level;
    sscanf(t,"%s%d",t1,&((SLEEPSTRUCT*)cmd->data)->ms);
  }
  else if(strncmp(t,"WAITEVENT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,3);
    cmd->flag = *level;
    sscanf(t,"%s%d%s%s",t1,&((EVENTSTRUCT*)cmd->data)->type,t2,t3);
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}
  }
  else if(strncmp(t,"SIGNALEVENT",11)==0)
  {
    cmd = InsertCommand(ptrcmd,5);
    cmd->flag = *level;
    sscanf(t,"%s%d%s%s",t1,&((EVENTSTRUCT*)cmd->data)->type,t2,t3);
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}

  }

  else if(strncmp(t,"COUNTER",7)==0)
  {
    cmd = InsertCommand(ptrcmd,29);
    cmd->flag = *level;
    sscanf(t,"%s%s%s%s",t1
    ,((COUNTERSTRUCT*)cmd->data)->name
    ,((COUNTERSTRUCT*)cmd->data)->function
    ,((COUNTERSTRUCT*)cmd->data)->value);
  }
  else if(strncmp(t,"TUNING",6)==0)
  {
    cmd = InsertCommand(ptrcmd,30);
    cmd->flag = *level;
    sscanf(t,"%s%s%d%f",t1
    ,((TUNINGSTRUCT*)cmd->data)->name
    ,&((TUNINGSTRUCT*)cmd->data)->vr
    ,&((TUNINGSTRUCT*)cmd->data)->value);
  }
  else if(strncmp(t,"SETSPEED",8)==0)
  {
    cmd = InsertCommand(ptrcmd,48);
    cmd->flag = *level;
    sscanf(t,"%s%f",t1
    ,&((SETSPEEDSTRUCT*)cmd->data)->factor);
    ((SETSPEEDSTRUCT*)cmd->data)->factor *= 0.01;
  }
  else if(strncmp(t,"STOP",4)==0)
  {
    cmd = InsertCommand(ptrcmd,15);
    cmd->flag = *level;
  }
  else if(strncmp(t,"ERROR",5)==0)
  {
    cmd = InsertCommand(ptrcmd,47);
    cmd->flag = *level;
    sscanf(t,"%s%d%s",t1,&((ERRORSTRUCT*)cmd->data)->number,((ERRORSTRUCT*)cmd->data)->text);
  }
  else
  {
    cmd = ptrcmd;
  }
  return cmd;
}

void refreshPoint(COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *point;
  if(cmd->type==10||cmd->type==14||cmd->type==22||cmd->type==27||cmd->type==28)
  {
    point = (POINTSTRUCT*)cmd->data;
    {
      point->p.x = point->fp.x + trobot->m_frames.frame[point->frameidx].x + point->pp.x;
      point->p.y = point->fp.y + trobot->m_frames.frame[point->frameidx].y + point->pp.y;
      point->p.z = point->fp.z + trobot->m_frames.frame[point->frameidx].z + point->pp.z;
      point->p.v = point->fp.v + trobot->m_frames.frame[point->frameidx].v + point->pp.v;
      point->p.w = point->fp.w + trobot->m_frames.frame[point->frameidx].w + point->pp.w;
      point->p.u = point->fp.u + trobot->m_frames.frame[point->frameidx].u + point->pp.u;
    }
  }
}



void getCommandString(char *t, COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *point;
  tmpnRobot *robot=(tmpnRobot*)trobot;
  if(cmd==((void *)0)||cmd->data==((void *)0))
  {
    strcpy(t,"");
  }
  else if(cmd->type==38)
  {
    sprintf(t,"ROOT");
  }
  else if(cmd->type==2)
  {
    sprintf(t,"MOVEABS %f,%f,%f,%f,%f",
      ((MOVEABSSTRUCT*)cmd->data)->dest_a,
      ((MOVEABSSTRUCT*)cmd->data)->dest_b,
      ((MOVEABSSTRUCT*)cmd->data)->dest_c,
      ((MOVEABSSTRUCT*)cmd->data)->dest_d,
      ((MOVEABSSTRUCT*)cmd->data)->dest_e
      );
  }
  else if(cmd->type==18)
  {
    sprintf(t,"MOVEAXIS axis=%d,speed=%3.2f,accel=%3.2f,decel=%3.2f,distance=%3.2f,wait=%d"
     ,((MOVEAXISSTRUCT*)cmd->data)->axis
     ,((MOVEAXISSTRUCT*)cmd->data)->speed
     ,((MOVEAXISSTRUCT*)cmd->data)->accel
     ,((MOVEAXISSTRUCT*)cmd->data)->decel
     ,((MOVEAXISSTRUCT*)cmd->data)->distance
     ,((MOVEAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(cmd->type==6)
  {
    sprintf(t,"CANCELAXIS axis=%d,wait=%d"
     ,((CANCELAXISSTRUCT*)cmd->data)->axis
     ,((CANCELAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(cmd->type==7)
  {
    sprintf(t,"WSP %f,%f,%f,%f,%f,%f",
      ((WSPSTRUCT*)cmd->data)->x,
      ((WSPSTRUCT*)cmd->data)->y,
      ((WSPSTRUCT*)cmd->data)->z,
      ((WSPSTRUCT*)cmd->data)->v,
      ((WSPSTRUCT*)cmd->data)->w,
      ((WSPSTRUCT*)cmd->data)->u
      );
  }
  else if(cmd->type==1)
  {
    sprintf(t,"SADS %f,%f,%f,%d",
      ((SADSSTRUCT*)cmd->data)->speed,
      ((SADSSTRUCT*)cmd->data)->accel,
      ((SADSSTRUCT*)cmd->data)->decel,
      ((SADSSTRUCT*)cmd->data)->sramp
      );
  }
  else if(cmd->type==25)
  {
    sprintf(t,"SPLINEHINT %d %d",
      ((SPLINEHINTSTRUCT*)cmd->data)->splinehint
      ,((SPLINEHINTSTRUCT*)cmd->data)->splineorder
      );
  }
  else if(cmd->type==23)
  {
    sprintf(t,"STATEHINT %d",
      ((STATEHINTSTRUCT*)cmd->data)->statehint
      );
  }
  else if(cmd->type==26)
  {
    sprintf(t,"POSITIONHINT %d",
      ((POSITIONHINTSTRUCT*)cmd->data)->positionhint
      );
  }
  else if(cmd->type==8)
  {
    sprintf(t,"OUT %d %d",
      ((OUTPUTSTRUCT*)cmd->data)->p,
      ((OUTPUTSTRUCT*)cmd->data)->state
      );
  }
  else if(cmd->type==9)
  {
    sprintf(t,"IN %d",((INPUTSTRUCT*)cmd->data)->p);
  }
  else if(cmd->type==11)
  {
    sprintf(t,"SUB %s",((NAMESTRUCT*)cmd->data)->name);
  }
  else if(cmd->type==19)
  {
    sprintf(t,"MACRO %s %d %d %d",((MACROSTRUCT*)cmd->data)->name
    ,((MACROSTRUCT*)cmd->data)->parameter0
    ,((MACROSTRUCT*)cmd->data)->parameter1
    ,((MACROSTRUCT*)cmd->data)->parameter2
    );
  }
  else if(cmd->type==46)
  {
    sprintf(t,"RESETPRELOAD %d",((RESETPRELOADSTRUCT*)cmd->data)->loadgroup);
  }
  else if(cmd->type==13)
  {
    sprintf(t,"CALL %s %d"
    ,((CALLSTRUCT*)cmd->data)->script
    ,((CALLSTRUCT*)cmd->data)->lag
    );
  }
  else if(cmd->type==16)
  {
    sprintf(t,"LABEL %s",((LABELSTRUCT*)cmd->data)->label);
  }
  else if(cmd->type==17)
  {
    sprintf(t,"JUMPLAYER %s %d"
    ,((JUMPLAYERSTRUCT*)cmd->data)->function
    ,((JUMPLAYERSTRUCT*)cmd->data)->layer
    );
  }
  else if(cmd->type==24)
  {
    sprintf(t,"SCOPE %d %d %d"
    ,((SCOPESTRUCT*)cmd->data)->parameter0
    ,((SCOPESTRUCT*)cmd->data)->parameter1
    ,((SCOPESTRUCT*)cmd->data)->parameter2
    );
  }
  else if(cmd->type==21)
  {
    sprintf(t,"GOTO %s",((GOTOSTRUCT*)cmd->data)->label);
  }
  else if(cmd->type==20)
  {
    sprintf(t,"PPSCRIPT %s idx=%d,loadgroup=%d"
    ,((PPSCRIPTSTRUCT*)cmd->data)->name
    ,((PPSCRIPTSTRUCT*)cmd->data)->idx
    ,((PPSCRIPTSTRUCT*)cmd->data)->loadgroup
    );
  }
  else if(cmd->type==31)
  {
    sprintf(t,"TESTEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==32)
  {
    sprintf(t,"SLEEP %d",((SLEEPSTRUCT*)cmd->data)->ms);
  }
  else if(cmd->type==3)
  {
    sprintf(t,"WAITEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==29)
  {
    sprintf(t,"COUNTER %s %s %s"
    ,((COUNTERSTRUCT*)cmd->data)->name
    ,((COUNTERSTRUCT*)cmd->data)->function
    ,((COUNTERSTRUCT*)cmd->data)->value);
  }
  else if(cmd->type==30)
  {
    sprintf(t,"TUNING %s %d %3.2f"
    ,((TUNINGSTRUCT*)cmd->data)->name
    ,((TUNINGSTRUCT*)cmd->data)->vr
    ,((TUNINGSTRUCT*)cmd->data)->value);
  }
  else if(cmd->type==48)
  {
    sprintf(t,"SETSPEED %3.2f"
    ,((SETSPEEDSTRUCT*)cmd->data)->factor*100.0);
  }
  else if(cmd->type==5)
  {
    sprintf(t,"SIGNALEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==4)
  {
    sprintf(t,"PATH %s id=%d,type=%d,time=%1.0f,loadgroup=%d,runbopt=%d"

    ,((PATHSTRUCT*)cmd->data)->tpathdef.name
    ,((PATHSTRUCT*)cmd->data)->tpathdef.id
    ,((PATHSTRUCT*)cmd->data)->tpathdef.pathtype
    ,((PATHSTRUCT*)cmd->data)->tpathdef.maxTime
    ,((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup
    ,((PATHSTRUCT*)cmd->data)->tpathdef.runbopt
    );
  }
  else if(cmd->type==10)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    if(robot->m_showPoint==0)
    {
      sprintf(t,"POINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
      robot->m_frames.frame[point->frameidx].name,
      point->fp.x,
      point->fp.y,
      point->fp.z,
      point->fp.v,
      point->fp.w,
      point->fp.u,
      point->p.dt,
      robot->m_tcp[point->p.tcpidx].name);
    }
    else if(robot->m_showPoint==1)
    {
      sprintf(t,"POINT(0) %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
      robot->m_frames.frame[point->frameidx].name,
      point->p.x,
      point->p.y,
      point->p.z,
      point->p.v,
      point->p.w,
      point->p.u,
      point->p.dt,
      robot->m_tcp[point->p.tcpidx].name);
    }
  }
  else if(cmd->type==27)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"HPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==14)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"RPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==28)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"HRPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==22)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"EPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,

point->pp.x,

point->pp.y,

point->pp.z,

point->pp.v,

point->pp.w,

point->pp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==15)
  {
    sprintf(t,"STOP");
  }
  else if(cmd->type==47)
  {
    sprintf(t,"ERROR %d %s"
    ,((ERRORSTRUCT*)cmd->data)->number
    ,((ERRORSTRUCT*)cmd->data)->text);
  }
}

void adjPoint(COMMANDSTRUCT *cmd
        ,float wx, float wy, float wz, float wv, float ww, float wu, float wt, int tcpidx)
{
  POINTSTRUCT *point;

  if(cmd->type==10||cmd->type==14||cmd->type==22||cmd->type==27||cmd->type==28)
  {
     point = (POINTSTRUCT*)cmd->data;
     point->fp.x=wx-trobot->m_frames.frame[point->frameidx].x-point->pp.x;
     point->fp.y=wy-trobot->m_frames.frame[point->frameidx].y-point->pp.y;
     point->fp.z=wz-trobot->m_frames.frame[point->frameidx].z-point->pp.z;
     point->fp.v=wv-trobot->m_frames.frame[point->frameidx].v-point->pp.v;
     point->fp.w=ww-trobot->m_frames.frame[point->frameidx].w-point->pp.w;
     point->fp.u=wu-trobot->m_frames.frame[point->frameidx].u-point->pp.u;
     point->p.dt=wt;
     point->p.tcpidx=tcpidx;
     refreshPoint(cmd);
  }
}

int jointToTask(const char *filename)
{
  FILE *fp;
  FILE *fpout;
  int version;
  char t[256];
  char fn[256];
  char fname[256];
  char fnout[256];
  tmpnJoints joint;
  tmpnJoints actuator;
  int dt;
  tmpnRobot *robot=(tmpnRobot*)trobot;





   sprintf(fname,"%s",filename);

 if(!strcmp(&fname[strlen(fname)-4],".rss")) {
      return 0;
    }
    sprintf(fn,"%s",fname);
    sprintf(fnout,"%s.rss",fname);

  fp = fopen(fn,"r");

  if(fp==((void *)0))
  {
    printf("xscript=%s not found!\n",fn);
    return 0;
  }

  fscanf(fp,"VERSION %d\n", &version);

  if(
     version!=1)
  {
    printf("SCRIPTVERSION error\n");
    return 0;
  }

  fpout = fopen(fnout,"w");
  if(fpout==((void *)0)) {
    printf("File: %s could not be opened for writing!\n",filename);
    return 0;
  }
  fprintf(fpout,"VERSION %d\n", 2);

  memset(t, 0, 256);
  fgets(t,256,fp);

  while(!feof(fp))
  {
    if(sscanf(t,"JOINT %f,%f,%f,%f,%f,%f,%i"
     ,&joint.a
     ,&joint.b
     ,&joint.c
     ,&joint.d
     ,&joint.e
     ,&joint.f
     ,&dt
      )) {
    actuator.a = robot->m_sign.name.a*joint.a;
    actuator.b = -robot->m_sign.name.b*joint.b;
    actuator.c = -robot->m_sign.name.c*joint.c;

    actuator.d = robot->m_sign.name.d*joint.d;

    actuator.e = joint.e - actuator.d/robot->m_gearing.name.e;
    actuator.e = robot->m_sign.name.e*actuator.e;
    actuator.f = robot->m_sign.name.f*joint.f;

    actuator.a += robot->m_jointCalib.a;
    actuator.b += robot->m_jointCalib.b;
    actuator.c += robot->m_jointCalib.c;
    actuator.d += robot->m_jointCalib.d;
    actuator.e += robot->m_jointCalib.e;
    actuator.f += robot->m_jointCalib.f;

    tmpnComputeFK(robot, actuator.a
    , actuator.b
    , actuator.c
    , actuator.d
    , actuator.e
    , actuator.f, getTCPidx("zero",robot));

    fprintf(fpout,"POINT base %f,%f,%f,%f,%f,%f,%i zero\n",robot->m_worldPoint.x
    , robot->m_worldPoint.y
    , robot->m_worldPoint.z
    , robot->m_worldPoint.v
    , robot->m_worldPoint.w
    , robot->m_worldPoint.u
    , dt
    );
    }
    else fprintf(fpout,"%s",t);
    fgets(t,256,fp);
  }
  fclose(fp);
  fclose(fpout);
  return 1;
}

int generateCommandScript(const char *fn, int flag)
{
  return 0;
}


void ResetCmdLoadBuffer(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *prcmd;

  prcmd=root;
  while(prcmd)
  {
    if(prcmd->type==4&&((PATHSTRUCT*)prcmd->data)->tpathdef.loadgroup==loadgroup)
    {
      ((PATHSTRUCT*)prcmd->data)->tpathdef.idx = -1;
    }
    prcmd = prcmd->next;
  }
}

COMMANDSTRUCT *LoadCommandScript(const char *filename, int flag)
{
  FILE *fp;
  COMMANDSTRUCT *cmd,*root;
  int i,version;
  char t[256];
  char tt[256];
  char fn[256];

  int level = 0;






  sprintf(fn,"%s/script/%s.rss",databasePath,filename);

  printf("opening %s\n",fn);
  fp = fopen(fn,"r");

  if(fp==((void *)0))
  {
    printf("yscript=%s not found!\n",fn);
    return ((void *)0);
  }

  fscanf(fp,"VERSION %d\n", &version);

  if(
     version!=2)
  {
    printf("SCRIPTVERSION error\n");
    return ((void *)0);
  }

  memset(t, 0, 256);
  fgets(t,256,fp);


  root = addCommandString(((void *)0),"ROOT",&level);
  cmd = root;


  while(!feof(fp))
  {
    strcpy(tt,t);
    for(i=0;i<strlen(t);i++)
    {
      if(t[i]!=' ')
      {
        strcpy(tt,&t[i]);
        i=strlen(t);
      }
    }
    cmd = addCommandString(cmd,tt,&level);
    memset(t, 0, 256);
    fgets(t,256,fp);
  }
  fclose(fp);
  updatecmdPoints(root);
  return root;
}


static int numOfCounters=0;
static COUNTERSTRUCT counters[100];

COUNTERSTRUCT *getCounter(char *name)
{
  int i;
  for(i=0;i<numOfCounters;i++)
  {
    if(strcmp(counters[i].name,name)==0)
      return &counters[i];
  }
  return ((void *)0);
}

char *getCounterValue(char* value)
{

  COUNTERSTRUCT *vcnt=getCounter(value);
  if(vcnt==((void *)0)) return value;
  return vcnt->value;
}

COUNTERSTRUCT *initCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    strcpy(cnt->value,getCounterValue(value));
    return cnt;
  }
  if(numOfCounters>=100) return ((void *)0);
  cnt=&counters[numOfCounters++];
  strcpy(cnt->name,name);
  strcpy(cnt->value,getCounterValue(value));
  return cnt;
}

COUNTERSTRUCT *incCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)+atoi(getCounterValue(value)));
    return cnt;
  }
  return ((void *)0);
}

COUNTERSTRUCT *mulCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)*atoi(getCounterValue(value)));
    return cnt;
  }
  return ((void *)0);
}

COUNTERSTRUCT *divCounter(char *name, char* value)
{
  int val;
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    val=atoi(getCounterValue(value));
    if(val==0)
      sprintf(cnt->value,"0");
    else
      sprintf(cnt->value,"%d",atoi(cnt->value)/val);
    return cnt;
  }
  return ((void *)0);
}

COUNTERSTRUCT *decCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)-atoi(getCounterValue(value)));
    return cnt;
  }
  return ((void *)0);
}

COMMANDSTRUCT *FindLabelCmd(COMMANDSTRUCT *pcmd, const char *label)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==16&&strcmp(((LABELSTRUCT*)cmd->data)->label,label)==0)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *FindNextCmdToUpload(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==4)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *FindFirstCmdToUpload(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==4)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *findNextToPreload(COMMANDSTRUCT *pcmd)
{
  int loadgroup;
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  loadgroup=((PATHSTRUCT*)pcmd->data)->tpathdef.loadgroup;
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==4&&((PATHSTRUCT*)cmd->data)->tpathdef.idx==-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *findFirstPreloaded(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==4&&((PATHSTRUCT*)cmd->data)->tpathdef.idx!=-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}



COMMANDSTRUCT *findFirstPathInGroup(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==4&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      if(((PATHSTRUCT*)cmd->data)->tpathdef.idx==-1)
      {
        return cmd;
      }
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}




COMMANDSTRUCT *findItemPathInGroup(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  int startload=0;

  if(loadgroup==0)
  {
    startload=atoi(getCounterValue("cAItems"));
  }
  else if(loadgroup==1)
  {
    startload=atoi(getCounterValue("cBItems"));
  }
  else
  {
    return findFirstPathInGroup(root,loadgroup);
  }
  if(rs_param.mc_task_debug>2) printf("startload(%d)=%d\n",loadgroup,startload);
  cmd=root;
  while(cmd)
  {
    if(cmd->type==4&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup&&((PATHSTRUCT*)cmd->data)->tpathdef.id==startload) return cmd;
    cmd = cmd->next;
  }
  return ((void *)0);
}

int countPreload(COMMANDSTRUCT *root, int loadgroup)
{
  int preload;
  COMMANDSTRUCT *cmd;
  cmd=root;
  preload=0;
  while(cmd)
  {
    if(cmd->type==4&&((PATHSTRUCT*)cmd->data)->tpathdef.idx!=-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      preload++;
    }
    cmd = cmd->next;
  }
  return preload;
}

static int isRuncommand(COMMANDSTRUCT *cmd)
{
  if(cmd->type==19
   ||cmd->type==24
   ||cmd->type==13
   ||cmd->type==46
   ||cmd->type==16
   ||cmd->type==21
   ||cmd->type==17
   ||cmd->type==15
   ||cmd->type==47
   ||cmd->type==18
   ||cmd->type==6
   ||cmd->type==31
   ||cmd->type==3
   ||cmd->type==32
   ||cmd->type==5
   ||cmd->type==29
   ||cmd->type==30
   ||cmd->type==48
   ||cmd->type==9
   ||cmd->type==8
   ||cmd->type==4)
    return 1;
 return 0;
}

COMMANDSTRUCT *getLabelCommand(COMMANDSTRUCT *root, const char *label)
{
  COMMANDSTRUCT *cmd;
  cmd = root;
  while(cmd)
  {
    if(cmd->type==16&&strcmp(((LABELSTRUCT*)cmd->data)->label,label)==0)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *getNextRunCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  cmd = pcmd->next;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *getNextRunCommandAtSameLevel(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  int level;
  if(pcmd==((void *)0)) return ((void *)0);
  level=pcmd->flag;
  cmd = pcmd->next;
  while(cmd)
  {
    if(isRuncommand(cmd)&&cmd->flag<=level)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

POINTSTRUCT *getPoint(COMMANDSTRUCT *pcmd, int off)
{
  COMMANDSTRUCT *cmd;
  int i;
  if(pcmd==((void *)0)) return ((void *)0);
  if(off==0) return (POINTSTRUCT*)pcmd->data;
  if(off>0)
  {
    cmd = pcmd->next;
    i=1;
    while(cmd)
    {
      if(cmd->type==10&&i++>=off)
      {
        return (POINTSTRUCT*)cmd->data;
      }
      cmd = cmd->next;
    }
  }
  else
  {
    cmd = pcmd->prev;
    i=1;
    while(cmd)
    {
      if(cmd->type==10&&i++>=-off)
      {
        return (POINTSTRUCT*)cmd->data;
      }
      cmd = cmd->prev;
    }
  }
  return ((void *)0);
}
COMMANDSTRUCT *getPrevPPScriptCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  cmd = pcmd->prev;
  while(cmd)
  {
    if(cmd->type==20)
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return ((void *)0);
}

COMMANDSTRUCT *getPrevRunCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==((void *)0)) return ((void *)0);
  cmd = pcmd->prev;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return ((void *)0);
}



COMMANDSTRUCT *getFirstRunCommand(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return ((void *)0);
}

COMMANDSTRUCT *getLastRunCommand(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  for(cmd=root;cmd!=((void *)0)&&cmd->next!=((void *)0);cmd=cmd->next);
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return ((void *)0);
}

void adjPath(PATHSTRUCT *path)
{
  COMMANDSTRUCT *pcmd = path->firstpoint;
  refreshPath(pcmd);
}

float pointDist(tmpnKeyPoint *p0, tmpnKeyPoint *p1)
{
  return sqrt((p1->x-p0->x)*(p1->x-p0->x)
             +(p1->y-p0->y)*(p1->y-p0->y)
             +(p1->z-p0->z)*(p1->z-p0->z)
             +(p1->v-p0->v)*(p1->v-p0->v)
             +(p1->w-p0->w)*(p1->w-p0->w)
             +(p1->u-p0->u)*(p1->w-p0->u));
}


void refreshPath(COMMANDSTRUCT *pcmd)
{
  POINTSTRUCT *point;
  PATHSTRUCT *path;
  int statehint=1;
  int positionhint=0;
  int i=0;
  int level;
  int firstPoint,lastPointIdx;
  COMMANDSTRUCT *cmd;
  tmpnRobot *robot=(tmpnRobot*)trobot;
  if(pcmd==((void *)0)) return;
  path = (PATHSTRUCT*)pcmd->data;
  path->tpathdef.spline=robot->splinehint;
  path->tpathdef.splineorder=robot->splineorder;
  updatecmdPoints(pcmd);
  level=pcmd->flag;
  cmd = pcmd->next;
  lastPointIdx=-1;
  path->tpathdef.samplesBetweenKeypoints=defpathsamprate;
  while(cmd&&cmd->flag>level)
  {
    if(cmd&&cmd->type==25)
    {
      path->tpathdef.spline=((SPLINEHINTSTRUCT*)cmd->data)->splinehint;
      path->tpathdef.splineorder=((SPLINEHINTSTRUCT*)cmd->data)->splineorder;
      cmd = cmd->next;
    }
    else if(cmd&&cmd->type==23)
    {
      statehint=((STATEHINTSTRUCT*)cmd->data)->statehint;
      cmd = cmd->next;
    }
    else if(cmd&&cmd->type==26)
    {
      positionhint=((POSITIONHINTSTRUCT*)cmd->data)->positionhint;
      cmd = cmd->next;
    }
    else if(cmd->type==10||cmd->type==14||cmd->type==22)
    {
      i++;
      path->tpathdef.maxidx=0;
      path->tpathdef.maxhidx=0;
      path->tpathdef.maxpidx=0;
      path->firstpoint=pcmd;
      firstPoint=1;
      while(cmd&&cmd->flag>level
               &&cmd->type!=7
               &&cmd->type!=13
               &&cmd->type!=46
               &&cmd->type!=17
               &&cmd->type!=19
               &&cmd->type!=24
               &&cmd->type!=16
               &&cmd->type!=21
               &&cmd->type!=20
               &&cmd->type!=9
               &&cmd->type!=8
               &&cmd->type!=18
               &&cmd->type!=6
               &&cmd->type!=15
               &&cmd->type!=47
               &&cmd->type!=31
               &&cmd->type!=3
               &&cmd->type!=32
               &&cmd->type!=5
               &&cmd->type!=29
               &&cmd->type!=30
               &&cmd->type!=48
               &&cmd->type!=25
               &&cmd->type!=4
               &&cmd->type!=1)
      {
        if(cmd->type==10||cmd->type==14||cmd->type==22)
        {
          point = (POINTSTRUCT*)cmd->data;
          path->tpathdef.keypoint[path->tpathdef.maxidx].x=point->p.x;
          path->tpathdef.keypoint[path->tpathdef.maxidx].y=point->p.y;
          path->tpathdef.keypoint[path->tpathdef.maxidx].z=point->p.z;
          path->tpathdef.keypoint[path->tpathdef.maxidx].v=point->p.v;
          path->tpathdef.keypoint[path->tpathdef.maxidx].w=point->p.w;
          path->tpathdef.keypoint[path->tpathdef.maxidx].u=point->p.u;
          path->tpathdef.keypoint[path->tpathdef.maxidx].dt=point->p.dt;
          path->tpathdef.keypoint[path->tpathdef.maxidx].tcpidx=point->p.tcpidx;
          path->tpathdef.keypoint[path->tpathdef.maxidx].statehint=statehint;
          path->tpathdef.keypoint[path->tpathdef.maxidx].positionhint=positionhint;
          point->path = path;
          lastPointIdx=path->tpathdef.maxidx;
          path->tpathdef.maxidx++;
        }
        else if(cmd->type==27||cmd->type==28)
        {
          point = (POINTSTRUCT*)cmd->data;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].x=point->p.x;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].y=point->p.y;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].z=point->p.z;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].v=point->p.v;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].w=point->p.w;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].u=point->p.u;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].dt=point->p.dt;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].tcpidx=point->p.tcpidx;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].keypointidx=lastPointIdx;
          point->path = path;
          path->tpathdef.maxhidx++;
        }
        else if(cmd->type==23)
        {
          statehint=((STATEHINTSTRUCT*)cmd->data)->statehint;
        }
        else if(cmd->type==26)
        {
          positionhint=((POSITIONHINTSTRUCT*)cmd->data)->positionhint;
          path->tpathdef.poshint[path->tpathdef.maxpidx].positionhint=positionhint;
          path->tpathdef.poshint[path->tpathdef.maxpidx].time=-1;
          path->tpathdef.poshint[path->tpathdef.maxpidx].i=0;
          path->tpathdef.maxpidx++;
        }
        cmd = cmd->next;
      }
   }
    else
    {
      cmd = cmd->next;
    }
  }
}

int LoadCalibrationParam(tmpnRSSystem *ini)
{
  if(!tmpnPlantLoad(ini->plant,tplant))
  {
    return 0;
  }
  selectWorkcell(getWorkcellIdx(ini->workcell,tplant));
  selectRobot(getRobotIdx(ini->robot,(tmpnWorkcell*)tworkcell));

  printf("Plant: %s Workcell: %s Robot: %s loaded.... \nLocation: \e[32m %s \e[0m\n",tplant->name,tworkcell->name,trobot->m_name,ini->location);
  return 1;
}

int SaveCalibrationParam(tmpnRSSystem *ini)
{
  if(tmpnRobotSave(ini->robot,(tmpnRobot*)trobot)==0)
  {
    return 0;
  }
  return 1;
}

static void updateRSSystem(char *s, tmpnRSSystem *ini)
{
  if(strncmp(s,"plant=",6)==0)
  {
    sscanf(s,"plant=%s\n",ini->plant);
  }
  else if(strncmp(s,"workcell=",9)==0)
  {
    sscanf(s,"workcell=%s\n",ini->workcell);
  }
  else if(strncmp(s,"location=",9)==0)
  {
    sscanf(s,"location=%s\n",ini->location);
  }
  else if(strncmp(s,"robot=",6)==0)
  {
    sscanf(s,"robot=%s\n",ini->robot);
  }
  else if(strncmp(s,"user=",5)==0)
  {
    sscanf(s,"user=%s\n",ini->user);
  }
  else if(strncmp(s,"password=",9)==0)
  {
    sscanf(s,"password=%s\n",ini->password);
  }
  else if(strncmp(s,"script=",7)==0)
  {
    sscanf(s,"script=%s\n",ini->script);
  }
  else if(strncmp(s,"mainDialog=",11)==0)
  {
    sscanf(s,"mainDialog=%s\n",ini->mainDialog);
  }
  else if(strncmp(s,"workcellid=",11)==0)
  {
    sscanf(s,"workcellid=%d\n",&ini->workcellid);
  }
  else if(strncmp(s,"touch.initialized=",18)==0)
  {
    sscanf(s,"touch.initialized=%d\n",&ini->touch.initialized);
  }
  else if(strncmp(s,"touch.offx=",11)==0)
  {
    sscanf(s,"touch.offx=%d\n",&ini->touch.offx);
  }
  else if(strncmp(s,"touch.offy=",11)==0)
  {
    sscanf(s,"touch.offy=%d\n",&ini->touch.offy);
  }
  else if(strncmp(s,"touch.calx=",11)==0)
  {
    sscanf(s,"touch.calx=%f\n",&ini->touch.calx);
  }
  else if(strncmp(s,"touch.caly=",11)==0)
  {
    sscanf(s,"touch.caly=%f\n",&ini->touch.caly);
  }
  else if(strncmp(s,"touchctrltype=",14)==0)
  {
    sscanf(s,"touchctrltype=%d\n",&ini->touch.ctrltype);
  }
  else if(strncmp(s,"touchport=",10)==0)
  {
    sscanf(s,"touchport=%s\n",ini->touch.port);
  }
  else if(strncmp(s,"statemachine_debug=",19)==0)
  {
    sscanf(s,"statemachine_debug=%d\n",&ini->statemachine_debug);
  }
  else if(strncmp(s,"io_debug=",9)==0)
  {
    sscanf(s,"io_debug=%d\n",&ini->io_debug);
  }
  else if(strncmp(s,"mc_task_debug=",14)==0)
  {
    sscanf(s,"mc_task_debug=%d\n",&ini->mc_task_debug);
  }
  else if(strncmp(s,"path_debug=",10)==0)
  {
    sscanf(s,"path_debug=%d\n",&ini->path_debug);
  }
  else if(strncmp(s,"startSpeed=",11)==0)
  {
    sscanf(s,"startSpeed=%d\n",&ini->startSpeed);
  }
  else if(strncmp(s,"simulateMC=",10)==0)
  {
    sscanf(s,"simulateMC=%d\n",&ini->simulateMC);
  }
  else if(strncmp(s,"pcIPaddr=",9)==0)
  {
    sscanf(s,"pcIPaddr=%s\n",ini->pcIPaddr);
  }
  else if(strncmp(s,"stmServerPort=",14)==0)
  {
    sscanf(s,"stmServerPort=%d\n",&ini->stmServerPort);
  }
  else if(strncmp(s,"mcIPaddr=",9)==0)
  {
    sscanf(s,"mcIPaddr=%s\n",ini->mcIPaddr);
  }
  else if(strncmp(s,"controllerIPaddr=",17)==0)
  {
    sscanf(s,"controllerIPaddr=%s\n",ini->mcIPaddr);
  }
  else if(strncmp(s,"useNic=",7)==0)
  {
    sscanf(s,"useNic=%s\n",ini->nic);
  }
  else if(strncmp(s,"lag=",4)==0)
  {
    sscanf(s,"lag=%d\n",&ini->lag);
  }
  else if(strncmp(s,"checkWeigher=",13)==0)
  {
    sscanf(s,"checkWeigher=%d\n",&ini->checkWeigher);
  }
  else if(strncmp(s,"roboStacker=",12)==0)
  {
    sscanf(s,"roboStacker=%d\n",&ini->roboStacker);
  }
  else if(strncmp(s,"scriptExec=",11)==0)
  {
    sscanf(s,"scriptExec=%d\n",&ini->scriptExec);
  }
  else if(strncmp(s,"new_trio_addr=",14)==0)
  {
    sscanf(s,"new_trio_addr=%d\n",&ini->new_trio_addr);
  }
  else if(strncmp(s,"mc_version=",11)==0)
  {
    sscanf(s,"mc_version=%d\n",&ini->mc_version);
  }
}

static int mntdatabase(void)
{
  FILE *fp;
  char buffer[256];
 fp = fopen("/mnt/mntdatabase.txt","r");
  if(fp==((void *)0))
  fp = fopen("mntdatabase.txt","r");
  if(fp==((void *)0))
    fp = fopen("/home/thn/sandbox/mnt/mntdatabase.txt","r");
  if(fp==((void *)0))
    fp = fopen("/home/lms/sandbox/mnt/mntdatabase.txt","r");
  if(fp==((void *)0))
    fp = fopen("/home/mil/sandbox/mnt/mntdatabase.txt","r");
  if(fp==((void *)0))
  {
    if(strlen(rs_systempath) == 0)
    {
      strcpy(rs_systempath,"/mnt/database");
      printf("mntdatabase.txt: defaulting to /mnt/database\n");
    }
    if(strlen(rs_systemini) == 0)
    {
      strcpy(rs_systemini,"rssystem.ini");
      printf("mntdatabase.txt: defaulting to rssystem.ini\n");
    }
    return 1;
  }

  if(strlen(rs_systempath) == 0)
  {
    if(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
    {
      sscanf(buffer,"%s\n",rs_systempath);
    }
  }
  printf("using database=%s\n",rs_systempath);

  if(strlen(rs_systemini) == 0)
  {
    if(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
    {
      sscanf(buffer,"%s\n",rs_systemini);
      if(strcmp("605system.ini",rs_systemini) == 0)
      {
        if(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
        {
          sscanf(buffer,"%s\n",rs_systemini);
          demo = 1;
        }
      }
    }
    else
    {
      strcpy(rs_systemini,"rssystem.ini");
      printf("defaulting to rssystem.ini\n");
    }
  }
  printf("using system=%s\n",rs_systemini);
  fclose(fp);
  return 1;
}

int LoadRSSystemData(tmpnRSSystem *ini)
{
  FILE *fp;
  char buffer[256];
  char filename[256];
  int cmd_version;
  if(!mntdatabase()) return 0;
  sprintf(filename,"%s/system/%s",rs_systempath,rs_systemini);
  fp = fopen(filename,"r");
  if(fp==((void *)0))
  {
    printf("rsssystem.ini: Unknown file %s\n",filename);
    return 0;
  }
  fscanf(fp,"VERSION %d\n",&cmd_version);
  if(cmd_version!=1&&cmd_version!=2)
  {
    printf("rsssystem.ini: Unknown version in file %s\n", filename);
    return 0;
  }
  while(fgets(buffer, sizeof(buffer), fp)!=((void *)0))
  {
    updateRSSystem(buffer,ini);
  }
  if(ini->touch.initialized==4)
  {
    ini->touch.offx=0;
    ini->touch.offy=0;
    ini->touch.calx=1;
    ini->touch.caly=1;
  }
  fclose(fp);
  return 1;
}

int SaveRSSystemData(tmpnRSSystem *ini)
{
  FILE *fp;
  char filename[256];
  if(!mntdatabase()) return 0;
  sprintf(filename,"%s/system/%s",rs_systempath,rs_systemini);
  if((fp = fopen(filename, "w"))==((void *)0))
  {
    printf("rsssystem.ini: Save failed %s\n",filename);
    return 0;
  }
  fprintf(fp,"VERSION 2\n");
  fprintf(fp,"plant=%s\n",ini->plant);
  fprintf(fp,"workcell=%s\n",ini->workcell);
 fprintf(fp,"location=%s\n",ini->location);
  fprintf(fp,"robot=%s\n",ini->robot);
  fprintf(fp,"pcIPaddr=%s\n",ini->pcIPaddr);
  fprintf(fp,"stmServerPort=%d\n",ini->stmServerPort);
  fprintf(fp,"mcIPaddr=%s\n",ini->mcIPaddr);
  fprintf(fp,"useNic=%s\n",ini->nic);
  fprintf(fp,"script=%s\n",ini->script);
  fprintf(fp,"workcellid=%d\n",ini->workcellid);
  fprintf(fp,"lag=%d\n",ini->lag);
  fprintf(fp,"touch.initialized=%d\n",ini->touch.initialized);
  fprintf(fp,"touch.offx=%d\n",ini->touch.offx);
  fprintf(fp,"touch.offy=%d\n",ini->touch.offy);
  fprintf(fp,"touch.calx=%f\n",ini->touch.calx);
  fprintf(fp,"touch.caly=%f\n",ini->touch.caly);
  fprintf(fp,"touchctrltype=%d\n",ini->touch.ctrltype);
  fprintf(fp,"touchport=%s\n",ini->touch.port);
  fprintf(fp,"simulateMC=%d\n",ini->simulateMC);
  fprintf(fp,"mc_task_debug=%d\n",ini->mc_task_debug);
  fprintf(fp,"path_debug=%d\n",ini->path_debug);
  fprintf(fp,"statemachine_debug=%d\n",ini->statemachine_debug);
 fprintf(fp,"io_debug=%d\n",ini->io_debug);
  fprintf(fp,"startSpeed=%d\n",ini->startSpeed);
  fprintf(fp,"user=%s\n",ini->user);
  fprintf(fp,"password=%s\n",ini->password);
  fprintf(fp,"checkWeigher=%d\n",ini->checkWeigher);
  fprintf(fp,"roboStacker=%d\n",ini->roboStacker);
  fprintf(fp,"mainDialog=%s\n",ini->mainDialog);
  fprintf(fp,"scriptExec=%d\n",ini->scriptExec);
  fprintf(fp,"new_trio_addr=%d\n",ini->new_trio_addr);
  fprintf(fp,"mc_version=%d\n",ini->mc_version);

  fclose(fp);

  return 1;
}

int saveScopeSample(char *file, char *s)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"%s/scope/%s.txt",rs_systempath, file);
  fp = fopen(filename, "a");
  if(fp!=((void *)0))
  {
    fprintf(fp,"%s", s);
    fclose(fp);
  }
  return 0;
}





int libRunCounter(COMMANDSTRUCT *cmd, COMMANDSTRUCT **pcmd)
{

  clock_t start;
  if(rs_param.mc_task_debug>1) start = times(((void *)0));
  COUNTERSTRUCT *cnt;
  char *cVal;
  char *tVal;
  char cntval[256];





  if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"=")==0)
  {
    cnt=initCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"+=")==0)
  {
    cnt=incCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"-=")==0)
  {
    cnt=decCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"*=")==0)
  {
    cnt=mulCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"/=")==0)
  {
    cnt=divCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"==")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)==atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"<")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)<atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,">")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)>atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,">=")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)>=atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }




  return 0;
}
