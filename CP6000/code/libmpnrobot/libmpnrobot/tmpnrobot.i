# 1 "tmpnrobot.c"
# 1 "/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "tmpnrobot.c"





# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
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
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 1 3 4
# 211 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3 4

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
# 37 "/usr/include/stdio.h" 2 3 4
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

# 7 "tmpnrobot.c" 2
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

# 8 "tmpnrobot.c" 2
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

# 9 "tmpnrobot.c" 2
# 1 "tmpnrobot.h" 1
# 9 "tmpnrobot.h"
# 1 "/usr/include/sys/time.h" 1 3 4
# 27 "/usr/include/sys/time.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 28 "/usr/include/sys/time.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 30 "/usr/include/sys/time.h" 2 3 4

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



# 32 "/usr/include/sys/time.h" 2 3 4








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
# 24 "/usr/include/pthread.h" 3 4
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
# 10 "tmpnrobot.c" 2
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
# 11 "tmpnrobot.c" 2
# 1 "spline.h" 1
# 9 "spline.h"
void CalcHemite(tmpnVector *v, tmpnVector *p1, tmpnVector *p2, tmpnVector *tan1, tmpnVector *tan2, double t);
void GenerateHermitePoints(int *maxidx
                          ,int numofsamples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3);
void generatePath(tmpnRobot *tmpnrobot, tmpnPathDef *pathdef, tmpnPath *path);
int bspline(int n,int k,int p1,tmpnKeyPoint *b, tmpnPosition *p, int multi);
int bsplineu(int n,int k,int p1,tmpnKeyPoint *b, tmpnPosition *p, int multi);
void GenerateSplinePoints(int *maxidx
                          ,int numofsamples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3);
int generateSplinePath(int maxidx
                      ,int numofsamples
                      ,tmpnKeyPoint *keypoint
                      ,tmpnPosition *position);
# 12 "tmpnrobot.c" 2
# 1 "hermite.h" 1
# 9 "hermite.h"
void CalcHemite(tmpnVector *v, tmpnVector *p1, tmpnVector *p2, tmpnVector *tan1, tmpnVector *tan2, double t);
void GenerateHermitePoints(int *maxidx
                          ,int numofsamples
                          ,tmpnPosition *position
                          ,tmpnKeyPoint *p0
                          ,tmpnKeyPoint *p1
                          ,tmpnKeyPoint *p2
                          ,tmpnKeyPoint *p3);
void generateHermitePath(tmpnPathDef *pathdef, tmpnPath *path);
# 13 "tmpnrobot.c" 2
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
# 14 "tmpnrobot.c" 2

int newtau=1;

static tmpnRobot gtrobot = {
"Palm.robot"
,3300.0
,530.0
,463.5
,{
 {400.0,158.0,{0.15,-0.12,0.11}
,{{9.20,7.70,-3.05},{7.70,18.13,-1.31},{-3.05,-1.31,21.95}}}
,{1000.0,58.87,{0.3555,0.0,-0.1399}
,{{0.3946,0.0003,-0.0634},{0.0003,9.6749,0.0001},{-0.0634,0.0001,9.6749}}}
,{1036.0,57.0,{0.25,0.0408,0.0080}
,{{1.1317, 2.2587,-0.4839},{2.2587,13.5974,0.0091},{-0.4839,-0.0091,13.8765}}}
,{155.0,4.79,{0.0,-0.0575,-0.0096}
,{{0.0287,0.0,0.0},{0.0,0.0085,0.0027},{0.0,0.0027,0.0294}}}
,{0.0,1.69,{0.0,0.0,0.1167}
,{{0.0058,0.0,0.0},{0.0,0.0058,0.0},{0.0,0.0,0.0010}}}
 }
,{
 {0.0,7.2,{0.0390,-0.0002,0.25}
,{{0.3778,0.0002,0.0159},{0.0002,0.2536,-0.0007},{0.0159,-0.0007,0.2591}}}
,{0.0,25.69,{0.0302,-0.0006,0.45}
,{{1.1679,0.0006,-0.0277},{0.0006,0.7650,-0.0027},{-0.0277,-0.0027,0.9227}}}
,{0.0,45.69,{0.0027,-0.0019,0.45}
,{{2.2679,0.0006,-0.0277},{0.0006,1.4650,-0.0027},{-0.0277,-0.0027,1.8227}}}
 }
,{{-1.0,-1.0,1.0,1.0,-1.0}}
,{{680.0,27.0,42.0,20.0,40.0}}
,{{40.0,1568.0,491.0,108.0,55.0}}
,{{3000.0,3000.0,3000.0,3000.0,3000.0}}
,{{7.5,18.4,7.5,2.2,2.2}}
,{{75.0,3716.8,1575.0,220.0,110.0}}
,{{65536.0,65536.0,65536.0,65536.0,65536.0,65536.0}}
,{{5.0,101.0,105.0,100.0,50.0,5.0}}
,{{50.0*3.1415926535898,360.0,360.0,360.0,360.0,360.0}}
,{{(65536*5)/(50*3.1415926535898),65536*101/360,65536*105/360,65536*100/360,65536*50/360}}
,{{0.1,0.1,0.12,0.15,0.2}}
,{{0.0,0.0,0.0,0.0,0.0}}
,{{0.15,0.15,0.15,0.20,0.25}}
,{{0.0,0.0,0.0,0.0,0.0}}
,{{8.0,8.0,8.0,8.0,8.0}}
,{{50.0,4.0,4.0,4.0,4.0}}
,{{100.0,8.0,8.0,8.0,8.0}}
,{{100.0,8.0,8.0,8.0,8.0}}
,{{0.1,0.1,0.1,0.1,0.1}}
,{{0.5,0.5,0.5,0.5,0.5}}
,{{10.0,1.0,1.0,1.0,1.0}}
,{{0.0,0.0,0.0,0.0,0.0}}
,{{0.0,0.0,0.0,0.0,0.0}}
,{-9999.0,-9999.0,0.0,-360.0,-360.0}
,{9999.0,9999.0,2450.0,360.0,360.0}
,{0.0,0.0,0.0,0.0,0.0}
,{0.0,-1333.5,0.0,0.0,0.0}
,{0.0,0.0,0.0,0.0,0.0}
,{0.0,0.0,0.0,0.0,0.0}
,0
,0
,{
   {"case",205.0,0.0,0.0,0.0,0.0}
  ,{"bag",410.0,-40.0,0.0,0.0,0.0}
  ,{"zero",-171.0,0.0,0.0,0.0,0.0}
}
,{0.0,0.0,0.0,0.0,0.0}
,{0.0,0.0,0.0,0.0,0.0}
,{{0.0,0.0,0.0,0.0,0.0}}
,{0
 ,{
  }
}
,0
,0
,1
};
static tmpnRobot temprobot;
tmpnPlant Tplant;
tmpnRobot *initrobot=&gtrobot;
tmpnPlant *tplant=&Tplant;

volatile tmpnRobot *trobot=((void *)0);
volatile tmpnWorkcell *tworkcell=((void *)0);





void setLink(tmpnLink *link, int idx)
{
  setLinkLength(link->length, idx);
 if (idx!=4)
  setMass(link->mass,idx);
 else
  setMass(link->mass+tworkcell->tools.tool[0].weight,idx);
  setMassDisplacement(link->massDisplacement[0]
                     ,link->massDisplacement[1]
                     ,link->massDisplacement[2],idx);
  setInertiaTensor(link->inertia[0][0]
                  ,link->inertia[0][1]
                  ,link->inertia[0][2]
                  ,link->inertia[1][0]
                  ,link->inertia[1][1]
                  ,link->inertia[1][2]
                  ,link->inertia[2][0]
                  ,link->inertia[2][1]
                  ,link->inertia[2][2]
                  ,idx);
}

int staticforce(tmpnRobot *robot)
{
  int i,j;
  static int stime=0;
  for(j=0;j<5;j++)
  {
    setLink(&robot->m_Link[j],j);
  }
  setLink(&robot->m_State[0],4);
  setq(((robot->m_max.z-robot->m_joint.a)*(float)0.001)
    ,((robot->m_joint.b+90.0)*(float)3.1415926535898/(float)180.0)
    ,((robot->m_joint.c)*(float)3.1415926535898/(float)180.0)
    ,((robot->m_joint.d)*(float)3.1415926535898/(float)180.0)
    ,((robot->m_joint.e)*(float)3.1415926535898/(float)180.0));
  setdq(0.0,0.0,0.0,0.0,0.0);
  setddq(0.0,0.0,0.0,0.0,0.0);


  if(newtau==1)
    computetaus();

  for (i=0;i<5;i++)
  {
    if(newtau==1)
      robot->m_staticForce.array[i] = tau(i);
    else
      robot->m_staticForce.array[i] = oldtau(i,stime++);

  }
  return 1;
}

int tmpnComputeIK(tmpnRobot *robot
                  ,float wx
                  ,float wy
                  ,float wz
                  ,float wv
                  ,float ww
                  ,float wu
                  ,int tcpidx)
{


  float sin2,cos2;
  float angle1,angle2;
  float angle1deg,angle2deg;
  float beta,new;
  float ox,oy,ry,rz;
  tmpnVector localPointIK;
  tmpnVector worldPoint;
  tmpnJoints joint;



  if(robot->m_snapToGrid)
  {
    worldPoint.x=(wx)>=0.0?((float)((int)((wx)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((wx)*100.0 - 0.5001 ))*0.01);
    worldPoint.y=(wy)>=0.0?((float)((int)((wy)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((wy)*100.0 - 0.5001 ))*0.01);
    worldPoint.z=(wz)>=0.0?((float)((int)((wz)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((wz)*100.0 - 0.5001 ))*0.01);
    worldPoint.v=(wv-robot->m_tcp[tcpidx].v)>=0.0?((float)((int)((wv-robot->m_tcp[tcpidx].v)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((wv-robot->m_tcp[tcpidx].v)*100.0 - 0.5001 ))*0.01);
    worldPoint.w=(ww-robot->m_tcp[tcpidx].w)>=0.0?((float)((int)((ww-robot->m_tcp[tcpidx].w)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((ww-robot->m_tcp[tcpidx].w)*100.0 - 0.5001 ))*0.01);
    worldPoint.u=(wu-robot->m_tcp[tcpidx].u)>=0.0?((float)((int)((wu-robot->m_tcp[tcpidx].u)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((wu-robot->m_tcp[tcpidx].u)*100.0 - 0.5001 ))*0.01);
  }
  else
  {
    worldPoint.x=wx;
    worldPoint.y=wy;
    worldPoint.z=wz;
    worldPoint.v=wv-robot->m_tcp[tcpidx].v;
    worldPoint.w=ww-robot->m_tcp[tcpidx].w;
    worldPoint.u=wu-robot->m_tcp[tcpidx].u;
  }



  rz=(-robot->m_tcp[tcpidx].z)
    *cos(((-worldPoint.w)*(float)3.1415926535898/(float)180.0))
    -(-robot->m_tcp[tcpidx].y)
    *sin(((-worldPoint.w)*(float)3.1415926535898/(float)180.0));
  ry=(-robot->m_tcp[tcpidx].z)
    *sin(((-worldPoint.w)*(float)3.1415926535898/(float)180.0))
    +(-robot->m_tcp[tcpidx].y)
    *cos(((-worldPoint.w)*(float)3.1415926535898/(float)180.0));

  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)
    *cos(((-worldPoint.v)*(float)3.1415926535898/(float)180.0))
    +(ry)*-sin(((worldPoint.v)*(float)3.1415926535898/(float)180.0));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)
    *sin(((-worldPoint.v)*(float)3.1415926535898/(float)180.0))
    -(ry)*cos(((-worldPoint.v)*(float)3.1415926535898/(float)180.0));

  localPointIK.x=worldPoint.x+robot->m_localTrans.x-ox;
  localPointIK.y=worldPoint.y+robot->m_localTrans.y-oy;
  localPointIK.z=worldPoint.z+robot->m_localTrans.z+rz;
  localPointIK.v=worldPoint.v+robot->m_localTrans.v;
  localPointIK.w=worldPoint.w+robot->m_localTrans.w;
  localPointIK.u=worldPoint.u+robot->m_localTrans.u;

  float ikxsq = localPointIK.x*localPointIK.x;
  float ikysq = localPointIK.y*localPointIK.y;





  cos2 = ( ikxsq + ikysq
    - (robot->m_Link[1].length * robot->m_Link[1].length)
    - (robot->m_Link[2].length * robot->m_Link[2].length) )
    / ((float)2.0 * robot->m_Link[1].length * robot->m_Link[2].length);

  if (cos2 >= -1.0 && cos2 <= 1.0)
  {
    angle2 = (float)acos(cos2);

    angle2deg = ((angle2)*(float)180.0/(float)3.1415926535898);

    sin2 = (float)sin(angle2);

    beta = atan2(localPointIK.x,localPointIK.y);
    new = acos((ikxsq + ikysq + robot->m_Link[1].length * robot->m_Link[1].length - robot->m_Link[2].length * robot->m_Link[2].length) / (2.0 * robot->m_Link[1].length * sqrt(ikxsq + ikysq)));

    angle1 = beta-new;


    angle1deg = ((angle1)*(float)180.0/(float)3.1415926535898);





    joint.a=localPointIK.z;
    joint.b=-angle1deg+90.0;
    if (joint.b>180) joint.b-=360;
    joint.c=-angle2deg;
    joint.d=localPointIK.v+joint.b+joint.c;
    joint.e=localPointIK.w;
    joint.f=localPointIK.u;

  worldPoint.v+=robot->m_tcp[tcpidx].v;
  worldPoint.w+=robot->m_tcp[tcpidx].w;
  worldPoint.w+=robot->m_tcp[tcpidx].u;

    if(joint.a<robot->m_min.z) return 0;
    if(joint.a>robot->m_max.z) return 0;
    if(worldPoint.x<robot->m_min.x) return 0;
    if(worldPoint.x>robot->m_max.x) return 0;
    if(worldPoint.y<robot->m_min.y) return 0;
    if(worldPoint.y>robot->m_max.y) return 0;

    robot->m_worldPoint.x=worldPoint.x;
    robot->m_worldPoint.y=worldPoint.y;
    robot->m_worldPoint.z=worldPoint.z;
    robot->m_worldPoint.v=worldPoint.v;
    robot->m_worldPoint.w=worldPoint.w;
    robot->m_worldPoint.u=worldPoint.u;
    robot->m_joint.a = joint.a;
    robot->m_joint.b = joint.b;
    robot->m_joint.c = joint.c;
    robot->m_joint.d = joint.d;
    robot->m_joint.e = joint.e;
    robot->m_joint.f = joint.f;
    robot->m_tcpidx=tcpidx;

    return 1;
  }
  else
    return 0;
}

int tmpnJointToActuator(tmpnRobot *robot,int tcpidx)
{
  tmpnJoints actuator;

  actuator.a = robot->m_sign.name.a*robot->m_joint.a;
  actuator.b = robot->m_sign.name.b*robot->m_joint.b;
  actuator.c = robot->m_sign.name.c*robot->m_joint.c;
  actuator.d = robot->m_sign.name.d*robot->m_joint.d;
  actuator.e = robot->m_sign.name.e*(robot->m_joint.e-actuator.d/robot->m_gearing.name.e);
  actuator.f = robot->m_sign.name.f*robot->m_joint.f;


  actuator.a += robot->m_jointCalib.a;
  actuator.b += robot->m_jointCalib.b;
  actuator.c += robot->m_jointCalib.c;
  actuator.d += robot->m_jointCalib.d;

  actuator.e += robot->m_jointCalib.e;
  actuator.f += robot->m_jointCalib.f;

  robot->m_actuator.a = actuator.a;
  robot->m_actuator.b = actuator.b;
  robot->m_actuator.c = actuator.c;
  robot->m_actuator.d = actuator.d;
  robot->m_actuator.e = actuator.e;
  robot->m_actuator.f = actuator.f;
  return 1;
}



int tmpnComputeFK(tmpnRobot *robot, float a, float b, float c, float d, float e, float f, int tcpidx)
{
  float ox,oy,ry,rz;
  tmpnVector localPointFK;
  tmpnJoints actuator;


  actuator.a = a-robot->m_jointCalib.a;
  actuator.b = b-robot->m_jointCalib.b;
  actuator.c = c-robot->m_jointCalib.c;
  actuator.d = d-robot->m_jointCalib.d;

  actuator.e = e-robot->m_jointCalib.e;
  actuator.f = f-robot->m_jointCalib.f;


  robot->m_joint.a = robot->m_sign.name.a*actuator.a;
  robot->m_joint.b = robot->m_sign.name.b*actuator.b;
  robot->m_joint.c = robot->m_sign.name.c*actuator.c;
  robot->m_joint.d = robot->m_sign.name.d*actuator.d;
  robot->m_joint.e = robot->m_sign.name.e*actuator.e + actuator.d/robot->m_gearing.name.e;
  robot->m_joint.f = robot->m_sign.name.f*actuator.f;

  localPointFK.z = robot->m_joint.a;
  localPointFK.x = robot->m_Link[1].length*cos(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0))
                 + (robot->m_Link[2].length*cos(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0)
                 + ((robot->m_joint.c)*(float)3.1415926535898/(float)180.0)));
  localPointFK.y = robot->m_Link[1].length*sin(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0))
                 + (robot->m_Link[2].length*sin(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0)
                 + ((robot->m_joint.c)*(float)3.1415926535898/(float)180.0)));
  localPointFK.v = robot->m_joint.d-(robot->m_joint.b+robot->m_joint.c);
  localPointFK.w = robot->m_joint.e;
  localPointFK.u = robot->m_joint.f;


  rz=(-robot->m_tcp[tcpidx].z)*cos(((-localPointFK.w)*(float)3.1415926535898/(float)180.0))
    -(-robot->m_tcp[tcpidx].y)*sin(((-localPointFK.w)*(float)3.1415926535898/(float)180.0));
  ry=(-robot->m_tcp[tcpidx].z)*sin(((-localPointFK.w)*(float)3.1415926535898/(float)180.0))
    +(-robot->m_tcp[tcpidx].y)*cos(((-localPointFK.w)*(float)3.1415926535898/(float)180.0));

  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*cos(((-localPointFK.v)*(float)3.1415926535898/(float)180.0))
    +(ry)*-sin(((localPointFK.v)*(float)3.1415926535898/(float)180.0));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*sin(((-localPointFK.v)*(float)3.1415926535898/(float)180.0))
    -(ry)*cos(((localPointFK.v)*(float)3.1415926535898/(float)180.0));

  if(robot->m_snapToGrid)
  {
    robot->m_worldPoint.x=(localPointFK.x-robot->m_localTrans.x + ox)>=0.0?((float)((int)((localPointFK.x-robot->m_localTrans.x + ox)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.x-robot->m_localTrans.x + ox)*100.0 - 0.5001 ))*0.01);
    robot->m_worldPoint.y=(localPointFK.y-robot->m_localTrans.y + oy)>=0.0?((float)((int)((localPointFK.y-robot->m_localTrans.y + oy)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.y-robot->m_localTrans.y + oy)*100.0 - 0.5001 ))*0.01);
    robot->m_worldPoint.z=(localPointFK.z-robot->m_localTrans.z - rz)>=0.0?((float)((int)((localPointFK.z-robot->m_localTrans.z - rz)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.z-robot->m_localTrans.z - rz)*100.0 - 0.5001 ))*0.01);
    robot->m_worldPoint.v=(localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v)>=0.0?((float)((int)((localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v)*100.0 - 0.5001 ))*0.01);
    robot->m_worldPoint.w=(localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w)>=0.0?((float)((int)((localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w)*100.0 - 0.5001 ))*0.01);
    robot->m_worldPoint.u=(localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u)>=0.0?((float)((int)((localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u)*(float)100.0 + (float)0.5001 ))*(float)0.01):((float)((int)((localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u)*100.0 - 0.5001 ))*0.01);
  }
  else
  {
    robot->m_worldPoint.x=localPointFK.x-robot->m_localTrans.x + ox;
    robot->m_worldPoint.y=localPointFK.y-robot->m_localTrans.y + oy;
    robot->m_worldPoint.z=localPointFK.z-robot->m_localTrans.z - rz;
    robot->m_worldPoint.v=localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v;
    robot->m_worldPoint.w=localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w;
    robot->m_worldPoint.u=localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u;
  }

  return 1;
}


int tmpnComputeFKlogic(tmpnRobot *robot, float a, float b, float c, float d, float e, float f, int tcpidx)
{
  float ox,oy,ry,rz;
  tmpnVector localPointFK;

  robot->m_joint.a = a;
  robot->m_joint.b = b;
  robot->m_joint.c = c;
  robot->m_joint.d = d;
  robot->m_joint.e = e;
  robot->m_joint.f = f;

  localPointFK.z = robot->m_joint.a;
  localPointFK.x = robot->m_Link[1].length*cos(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0))
                 + (robot->m_Link[2].length*cos(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0)
                 + ((robot->m_joint.c)*(float)3.1415926535898/(float)180.0)));
  localPointFK.y = robot->m_Link[1].length*sin(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0))
                 + (robot->m_Link[2].length*sin(((robot->m_joint.b)*(float)3.1415926535898/(float)180.0)
                 + ((robot->m_joint.c)*(float)3.1415926535898/(float)180.0)));
  localPointFK.v = robot->m_joint.d-(robot->m_joint.b+robot->m_joint.c);
  localPointFK.w = robot->m_joint.e;
  localPointFK.u = robot->m_joint.f;


  rz=(-robot->m_tcp[tcpidx].z)*cos(((-localPointFK.w)*(float)3.1415926535898/(float)180.0))
    -(-robot->m_tcp[tcpidx].y)*sin(((-localPointFK.w)*(float)3.1415926535898/(float)180.0));
  ry=(-robot->m_tcp[tcpidx].z)*sin(((-localPointFK.w)*(float)3.1415926535898/(float)180.0))
    +(-robot->m_tcp[tcpidx].y)*cos(((-localPointFK.w)*(float)3.1415926535898/(float)180.0));

  ox=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*cos(((-localPointFK.v)*(float)3.1415926535898/(float)180.0))
    +(ry)*-sin(((localPointFK.v)*(float)3.1415926535898/(float)180.0));
  oy=(robot->m_Link[3].length+robot->m_tcp[tcpidx].x)*sin(((-localPointFK.v)*(float)3.1415926535898/(float)180.0))
    -(ry)*cos(((localPointFK.v)*(float)3.1415926535898/(float)180.0));
  robot->m_worldPoint.x=localPointFK.x-robot->m_localTrans.x + ox;
  robot->m_worldPoint.y=localPointFK.y-robot->m_localTrans.y + oy;
  robot->m_worldPoint.z=localPointFK.z-robot->m_localTrans.z - rz;
  robot->m_worldPoint.v=localPointFK.v-robot->m_localTrans.v+robot->m_tcp[tcpidx].v;
  robot->m_worldPoint.w=localPointFK.w-robot->m_localTrans.w+robot->m_tcp[tcpidx].w;
  robot->m_worldPoint.u=localPointFK.u-robot->m_localTrans.u+robot->m_tcp[tcpidx].u;
  return 1;
}

static int dynomads(tmpnRobot *robot, tmpnPosition *position)
{
  int i;
  static int time=0;
  setLink(&robot->m_State[position->statehint],4);
  setq(position->posRad.name.a
      ,position->posRad.name.b
      ,position->posRad.name.c
      ,position->posRad.name.d
      ,position->posRad.name.e);
  setdq(position->speedRad.name.a
       ,position->speedRad.name.b
       ,position->speedRad.name.c
       ,position->speedRad.name.d
       ,position->speedRad.name.e);
  setddq(position->accelRad.name.a
        ,position->accelRad.name.b
        ,position->accelRad.name.c
        ,position->accelRad.name.d
        ,position->accelRad.name.e);
  if(newtau==1)
    computetaus();
  for (i=0;i<5;i++)
  {
    if(newtau==1)
      position->force.array[i] = tau(i);
    else
      position->force.array[i] = oldtau(i,time++);

  }
  return 1;
}


void solveIK(tmpnRobot *robot, int maxidx, tmpnPosition *position)
{
  int i;
  for ( i=0; i<maxidx; i++)
  {
    tmpnComputeIK(robot
            ,position[i].taskSpace.x
            ,position[i].taskSpace.y
            ,position[i].taskSpace.z
            ,position[i].taskSpace.v
            ,position[i].taskSpace.w
            ,position[i].taskSpace.u
            ,position[i].tcpidx);
    tmpnJointToActuator(robot,position[i].tcpidx);
    position[i].jointSpace.name.a=robot->m_joint.a;
    position[i].jointSpace.name.b=robot->m_joint.b;
    position[i].jointSpace.name.c=robot->m_joint.c;
    position[i].jointSpace.name.d=robot->m_joint.d;
    position[i].jointSpace.name.e=robot->m_joint.e;
    position[i].jointSpace.name.f=robot->m_joint.f;
    position[i].actuatorSpace.name.a=robot->m_actuator.a;
    position[i].actuatorSpace.name.b=robot->m_actuator.b;
    position[i].actuatorSpace.name.c=robot->m_actuator.c;
    position[i].actuatorSpace.name.d=robot->m_actuator.d;
    position[i].actuatorSpace.name.e=robot->m_actuator.e;
    position[i].actuatorSpace.name.f=robot->m_actuator.f;
  }
}
void solveFK(tmpnRobot *robot, int maxidx, tmpnPosition *position)
{
  int i;
  for ( i=0; i<maxidx; i++)
  {
    tmpnComputeFK(robot
                 ,position[i].actuatorSpace.name.a
                 ,position[i].actuatorSpace.name.b
                 ,position[i].actuatorSpace.name.c
                 ,position[i].actuatorSpace.name.d
                 ,position[i].actuatorSpace.name.e
                 ,position[i].actuatorSpace.name.f
                 ,position[i].tcpidx);
    position[i].taskSpace.x=robot->m_worldPoint.x;
    position[i].taskSpace.y=robot->m_worldPoint.y;
    position[i].taskSpace.z=robot->m_worldPoint.z;
    position[i].taskSpace.v=robot->m_worldPoint.v;
    position[i].taskSpace.w=robot->m_worldPoint.w;
    position[i].taskSpace.u=robot->m_worldPoint.u;
    position[i].jointSpace.name.a=robot->m_joint.a;
    position[i].jointSpace.name.b=robot->m_joint.b;
    position[i].jointSpace.name.c=robot->m_joint.c;
    position[i].jointSpace.name.d=robot->m_joint.d;
    position[i].jointSpace.name.e=robot->m_joint.e;
    position[i].jointSpace.name.f=robot->m_joint.f;
  }






}

static void keypoint_sumt(int maxidx, tmpnKeyPoint *keypoint, float maxTime)
{
  int i;
  float sumt,units,dt,temp1;
  sumt=0.0;
  keypoint[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {




    dt=keypoint[i].dt;
    sumt+=dt;
    keypoint[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {

    temp1 = keypoint[i].t/sumt;
    keypoint[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    keypoint[i].sp = (keypoint[i+1].t-keypoint[i].t)*maxTime;
  }

}
static void position_sumt4(int maxidx, tmpnPosition *position, float maxTime)
{
  int i;
  float sumt,units,temp1;
  sumt=0.0;
  position[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {
    sumt+=position[i].dt;
    position[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {
    temp1 = position[i].t/sumt;
    position[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
}

static void position_sumt(int maxidx, tmpnPosition *position, float maxTime)
{
  int i;
  float sumt,units,dt,temp1;
  sumt=0.0;
  position[0].t=0.0;
  for(i=0;i<maxidx-1;i++)
  {
    dt=10;
    sumt+=dt;
    position[i+1].t = sumt;
  }
  units=1000000.0;
  if(sumt>0.0) units=1000000.0/sumt;
  if(sumt==0.0) sumt=1000.0;
  for(i=0;i<maxidx;i++)
  {
    temp1 = position[i].t/sumt;
    position[i].t = temp1;
  }
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
}




void VA(float x1,float x2,float x3,float y1,float y2,float y3,float* vel,float* acc) {
  float A,B;
 float temp1,temp2,temp3;
 temp1=y1/((x1-x2)*(x1-x3));
 temp2=y2/((x2-x1)*(x2-x3));
 temp3=y3/((x3-x1)*(x3-x2));
 A = temp1 + temp2 + temp3;
 B = -1.0*((x1+x2)*temp3+(x1+x3)*temp2+(x2+x3)*temp1);
 *acc=2*A;
 *vel=(*acc)*x2+B;
}

void solve(tmpnRobot *robot, int maxidx, tmpnPosition *position, float maxTime, float *maxSpeed, int order)
{
  int i,j;
  tmpnJointsUnion nsum,tsum,T,n,Trms;
  float p,rGear,tdif,tmax,ts;
  *maxSpeed=0.0;
  float samplePeriod = (1000.0/((maxTime)*((position[(0)+1].t-position[(0)].t)/position[maxidx-1].t)));
  if(order==4)
    position_sumt(maxidx,position,maxTime);
  else
    position_sumt4(maxidx,position,maxTime);
  solveIK(robot,maxidx,position);
  for(i=0;i<maxidx-1;i++)
  {
    position[i].sp = (position[i+1].t-position[i].t)*maxTime;
  }
  for ( i=0; i<maxidx; i++)
  {

    position[i].posRad.name.a=((robot->m_max.z-position[i].jointSpace.name.a)*(float)0.001);
    position[i].posRad.name.b=((90.0-position[i].jointSpace.name.b)*(float)3.1415926535898/(float)180.0);
    position[i].posRad.name.c=((-position[i].jointSpace.name.c)*(float)3.1415926535898/(float)180.0);
    position[i].posRad.name.d=((position[i].jointSpace.name.d)*(float)3.1415926535898/(float)180.0);
    position[i].posRad.name.e=((position[i].jointSpace.name.e)*(float)3.1415926535898/(float)180.0);
    position[i].posRad.name.f=((position[i].jointSpace.name.f)*(float)0.001);
  }
  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
    samplePeriod=1000.0/position[(i)].sp;

    for(j=0;j<6;j++)
    {

      position[i].dif.array[j]=(position[i+1].jointSpace.array[j]-position[i].jointSpace.array[j]);


      position[i].speed.array[j]=position[i].dif.array[j]*samplePeriod;

      position[i].rev.array[j]=position[i].speed.array[j]*60.0*robot->m_gearing.array[j]/robot->m_unit.array[j];

      position[i].pctRatedSpeed.array[j]=position[i].rev.array[j]*100.0/temprobot.m_ratedRPM.array[j];
      if(fabs(position[i].pctRatedSpeed.array[j])>*maxSpeed)
      {
        *maxSpeed=fabs(position[i].pctRatedSpeed.array[j]);
        position[i].maxrev=j;
      }
    }

  if (i!=0)
  {
   float dummy;
   for(j=0;j<6;j++)
    VA(position[i-1].t*maxTime*0.001,
           position[i ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].posRad.array[j],
           position[i ].posRad.array[j],
           position[i+1].posRad.array[j],
          &position[i].speedRad.array[j],&dummy);
  }
  else
  {
   position[i].speedRad.name.a=(position[i+1].posRad.name.a-position[i].posRad.name.a)*samplePeriod;
   for(j=0;j<6;j++)
    position[i].speedRad.array[j]=(position[i+1].posRad.array[j]-position[i].posRad.array[j])*samplePeriod;
  }
  }

  for(j=0;j<6;j++)
  {
    position[maxidx-1].dif.array[j]=0;
    position[maxidx-1].speed.array[j]=0;
    position[maxidx-1].speedRad.array[j]=0;
    position[maxidx-1].rev.array[j]=0;
    position[maxidx-1].pctRatedSpeed.array[j]=0;
  }

  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;


    samplePeriod=1000.0/position[(i)].sp;
    for(j=0;j<6;j++)
    {
   if (i!=0)
   {
    float dummy;
    VA(position[i-1].t*maxTime*0.001,
           position[i ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].speedRad.array[j],
           position[i ].speedRad.array[j],
           position[i+1].speedRad.array[j],
          &position[i ].accelRad.array[j],&dummy);
   }
   else
   {
     position[i].accelRad.array[j]=position[i+1].speedRad.array[j]-position[i].speedRad.array[j];
     position[i].accelRad.array[j]*=samplePeriod;
   }
    }
  }
  for(j=0;j<6;j++)
  {
    position[maxidx-1].accelRad.array[j]=0;
  }
  for ( i=0; i<maxidx-1; i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;
    samplePeriod=1000.0/position[(i)].sp;



    for(j=0;j<6;j++)
    {
   if (i!=0)
   {
    float dummy;
    VA(position[i-1].t*maxTime*0.001,
           position[i ].t*maxTime*0.001,
           position[i+1].t*maxTime*0.001,
           position[i-1].accelRad.array[j],
           position[i ].accelRad.array[j],
           position[i+1].accelRad.array[j],
           &position[i ].jerkRad.array[j],&dummy);
   }
   else
   {
    position[i].jerkRad.array[j]=position[i+1].accelRad.array[j]-position[i].accelRad.array[j];
    position[i].jerkRad.array[j]*=samplePeriod;
   }
    }
  }
  for(j=0;j<6;j++)
  {
    position[maxidx-1].jerkRad.array[j]=0;
  }
  for(j=0;j<5;j++)
  {
    setLink(&robot->m_Link[j],j);
  }
  for(i=0;i<maxidx;i++)
  {
    dynomads(robot,&position[i]);
  }

  for(j=0;j<6;j++)
  {
    Trms.array[j]=0.0;
    nsum.array[j]=0.0;
    tsum.array[j]=0.0;
    T.array[j]=0.0;
  }
  for(i=0;i<maxidx-1;i++)
  {
    tdif=position[(i)+1].t-position[(i)].t;
    tmax=position[(maxidx)-1].t;
    ts=tdif/tmax;
    ts=ts*maxTime;
    if(ts<1.0)
      samplePeriod=0.0;
    else
      samplePeriod=1000.0/ts;


    for(j=0;j<6;j++)
    {

      p = pow(fabs(position[i].force.array[j]),10.0/3.0);
      rGear = fabs(position[i].rev.array[j]/robot->m_gearing.array[j]);
      T.array[j] += (1.0/samplePeriod) * rGear * p;
      nsum.array[j] += (1.0/samplePeriod) * rGear;
      tsum.array[j] += (1.0/samplePeriod);

      Trms.array[j] += ((1.0/samplePeriod)
                      *(position[i].force.array[j]/robot->m_gearing.array[j])
                      *(position[i].force.array[j]/robot->m_gearing.array[j]));
    }
  }

  for(j=0;j<6;j++)
  {
    T.array[j]=pow(T.array[j]/nsum.array[j],3.0/10.0);
    n.array[j]=nsum.array[j]/tsum.array[j];
    p = pow(robot->m_ratedNmGear.array[j]/T.array[j],10.0/3.0);
    robot->m_lifeTimeGear.array[j] = 6000.0 * (robot->m_ratedRpmGear.array[j]/n.array[j]) * p;

    robot->m_Trms.array[j]=sqrt(Trms.array[j]/tsum.array[j]);
  }
}
# 913 "tmpnrobot.c"
static tmpnPath ipath;

void B_SPLINE(tmpnRobot *robot, tmpnPath *path, tmpnPath *ipath, int nos, int order);

void mpnSplineJointSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos);
void mpnSplineTaskSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos);
# 949 "tmpnrobot.c"
void solvePositionHint(int maxpidx
                      ,tmpnPosHint *poshint
                      ,int maxidx
                      ,tmpnPosition *position
                      ,int bsplinesamples)
{
  int p,i,ii=1;
  for(p=0;p<maxpidx;p++)
  {
    for(i=ii;i<maxidx;i++)
    {


      if(position[i].positionhint+0.50005>poshint[p].positionhint)
      {
        poshint[p].i=i;

        poshint[p].time=position[i].t;
        ii=i;
        i=maxidx;
      }
    }
  }
}

void generatePath(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path)
{
  int j;
  if(pathdef==((void *)0)||path==((void *)0)) return;
  path->maxidx=0;
  if(pathdef->maxidx<=1) return;
  memcpy(&temprobot,robot,sizeof(temprobot));
  temprobot.m_snapToGrid=0;
  switch(pathdef->spline)
  {
    case 5:

            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            copyKeypoint(path, pathdef);

            solveIK(&temprobot,path->maxidx,path->position);
            mpnSplineJointSpace(&temprobot, pathdef, path, &ipath, pathdef->samplesBetweenKeypoints);
            copyPath(path, &ipath);
            break;
    case 6:

            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            copyKeypoint(path, pathdef);
            mpnSplineTaskSpace(&temprobot, pathdef, path, &ipath, pathdef->samplesBetweenKeypoints);

            solveIK(&temprobot,ipath.maxidx,ipath.position);
            copyPath(path, &ipath);
            break;
    case 7:


            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            path->maxidx = bspline(pathdef->maxidx
                                  ,pathdef->splineorder
                                  ,pathdef->samplesBetweenKeypoints
                                  ,pathdef->keypoint
                                  ,path->position
                                  ,0);

            solveIK(&temprobot,path->maxidx,path->position);
            break;
    case 8:

            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);

            copyKeypoint(path, pathdef);

            solveIK(&temprobot,path->maxidx,path->position);
     break;
    case 9:



            keypoint_sumt(pathdef->maxidx,pathdef->keypoint,pathdef->maxTime);
            path->maxidx = bspline(pathdef->maxidx
                                  ,pathdef->splineorder
                                  ,pathdef->samplesBetweenKeypoints
                                  ,pathdef->keypoint
                                  ,path->position
                                  ,0);
            solve(&temprobot,path->maxidx,path->position,pathdef->maxTime,&pathdef->maxSpeed,pathdef->splineorder);
            break;
  }

  if(pathdef->spline==8)
  {
    B_SPLINE(&temprobot, path, &ipath, pathdef->samplesBetweenKeypoints,pathdef->splineorder);
  }
  else
  {
    copyPath(&ipath, path);
  }
  solveFK(&temprobot,ipath.maxidx,ipath.position);
  solve(&temprobot,ipath.maxidx,ipath.position,pathdef->maxTime,&pathdef->maxSpeed,pathdef->splineorder);

  hackPositionHint(&ipath, pathdef);
  solvePositionHint(pathdef->maxpidx
        ,pathdef->poshint
      ,ipath.maxidx
      ,ipath.position
      ,pathdef->samplesBetweenKeypoints);
  if(temprobot.m_simulateTRIO==1)
  {
    copyPath(path, &ipath);
  }


  for(j=0;j<6;j++)
  {
    robot->m_lifeTimeGear.array[j] = temprobot.m_lifeTimeGear.array[j];
    robot->m_Trms.array[j]=temprobot.m_Trms.array[j];
  }
}

void hackPositionHint(tmpnPath *path, tmpnPathDef *pathdef)
{
  if (!strcmp(rs_param.script,"308C14")&&(pathdef->pathtype==21))
  {
    int i;
    float positionhint=-1.0;
    float minSpecialPct=0.5;
    float specialPos=920.0;
    float ttime=path->position[path->maxidx-1].t;
    for(i=0;i<path->maxidx;i++)
    {
      float Pct=path->position[i].t/ttime;
      if ((Pct>minSpecialPct)&&(path->position[i].taskSpace.y<=specialPos))
      {
    path->position[i].positionhint++;
    if (positionhint==-1.0)
     positionhint=path->position[i].positionhint;
      }
    }
    if (positionhint!=-1.0)
    {
      pathdef->poshint[pathdef->maxpidx].positionhint=positionhint;
      pathdef->maxpidx++;
    }
  }
}

void copyKeypoint(tmpnPath *path, tmpnPathDef *pathdef)
{
  int i;
  path->maxidx=pathdef->maxidx;
  for(i=0;i<pathdef->maxidx;i++)
  {
    path->position[i].taskSpace.x = pathdef->keypoint[i].x;
    path->position[i].taskSpace.y = pathdef->keypoint[i].y;
    path->position[i].taskSpace.z = pathdef->keypoint[i].z;
    path->position[i].taskSpace.v = pathdef->keypoint[i].v;
    path->position[i].taskSpace.w = pathdef->keypoint[i].w;
    path->position[i].taskSpace.u = pathdef->keypoint[i].u;
    path->position[i].dt = pathdef->keypoint[i].dt;
    path->position[i].t = pathdef->keypoint[i].t;
    path->position[i].sp = pathdef->keypoint[i].sp;
    path->position[i].statehint = pathdef->keypoint[i].statehint;
    path->position[i].positionhint = pathdef->keypoint[i].positionhint;
    path->position[i].tcpidx = pathdef->keypoint[i].tcpidx;
    path->position[i].keypoint = &pathdef->keypoint[i];
  }
}

void copyPath(tmpnPath *dest, tmpnPath *source)
{
  int i;
  dest->maxidx=source->maxidx;
  for(i=0;i<source->maxidx;i++)
  {
    dest->position[i] = source->position[i];
  }
}
# 1139 "tmpnrobot.c"
void splinePoints(int *maxidx, int samples, float *cambox, float p1, float p2, float p3, float p4)
{
  float onesixth=1.0/6.0;
  float t,stepsize;
  float a0,a1,a2,a3;
  int i;
  a0 = ( -p1 + 3.0*p2 - 3.0*p3 + p4) * onesixth;
  a1 = ( 3.0*p1 - 6.0*p2 + 3.0*p3 ) * onesixth;
  a2 = (-3.0*p1 + 3.0*p3 ) * onesixth;
  a3 = ( p1 + 4.0*p2 + p3 ) * onesixth;
  stepsize=1.0/(float)samples;

  for(i=0;i<samples;i++)
  {
  t=i*stepsize;
    cambox[*maxidx] = a3 + t*(a2 + t*(a1 + t*a0));
    (*maxidx)++;
  }
}
# 1171 "tmpnrobot.c"
int splineExpand(int numofkeypoints, float *keypoint, int samples, float *cambox)
{
  int i,pmaxidx;
  if(numofkeypoints<4) return 0;

  pmaxidx=0;
  splinePoints(&pmaxidx,samples,cambox,keypoint[0],keypoint[0],keypoint[0],keypoint[1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[0],keypoint[0],keypoint[1],keypoint[2]);
  for ( i=2; i < numofkeypoints-1; i++)
    splinePoints(&pmaxidx,samples,cambox,keypoint[i-2],keypoint[i-1],keypoint[i],keypoint[i+1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[numofkeypoints-3],keypoint[numofkeypoints-2],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1]);
  splinePoints(&pmaxidx,samples,cambox,keypoint[numofkeypoints-2],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1],keypoint[numofkeypoints-1]);
  cambox[pmaxidx] = keypoint[numofkeypoints-1];
  pmaxidx++;
# 1194 "tmpnrobot.c"
  return pmaxidx;
}

int timeExpand(int numofkeypoints, float *keypoint, int samples, float *cambox)
{
  int i,pmaxidx;
 float diff;
  if(numofkeypoints<4) return 0;
  pmaxidx=(numofkeypoints+1)*samples;
 diff=(keypoint[numofkeypoints-1]-keypoint[0])/((float)pmaxidx);
  for ( i=0; i < pmaxidx; i++)
 {
  cambox[i]=diff*i;
 }
  return pmaxidx;
}

void B_SPLINE(tmpnRobot *robot, tmpnPath *path, tmpnPath *ipath, int nos, int order)
{
  int i,j,p;
  float table[500];
  float cambox[5000];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.a;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.a=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.b;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.b=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.c;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.c=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.d;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.d=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.e;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.e=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].actuatorSpace.name.f;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].actuatorSpace.name.f=cambox[i];

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].t;
  if(order==4)
    ipath->maxidx=timeExpand(path->maxidx,table,nos,cambox);
  else
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].t=cambox[i];


  if(order!=4)
  {
    for(i=0;i<path->maxidx;i++)
      table[i]=path->position[i].dt;
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
    for(i=0;i<ipath->maxidx;i++)
      ipath->position[i].dt=cambox[i];
  }

  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].sp;
  if(order==4)
    ipath->maxidx=timeExpand(path->maxidx,table,nos,cambox);
  else
    ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].sp=cambox[i];


  for(i=0;i<path->maxidx;i++)
    table[i]=path->position[i].positionhint;
  ipath->maxidx=splineExpand(path->maxidx,table,nos,cambox);
  for(i=0;i<ipath->maxidx;i++)
    ipath->position[i].positionhint=cambox[i];

  p=1;
  ipath->position[0].statehint = path->position[0].statehint;
  ipath->position[0].keypoint = path->position[0].keypoint;
  ipath->position[0].tcpidx = path->position[0].tcpidx;
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[0].statehint;
    ipath->position[p].keypoint = path->position[0].keypoint;
    ipath->position[p++].tcpidx = path->position[0].tcpidx;
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[1].statehint;
    ipath->position[p].keypoint = path->position[1].keypoint;
    ipath->position[p++].tcpidx = path->position[1].tcpidx;
  }
  for(i=2;i<path->maxidx-1;i++)
  {
    for(j=0;j<nos;j++)
    {
      ipath->position[p].statehint = path->position[i].statehint;
      ipath->position[p].keypoint = path->position[i].keypoint;
      ipath->position[p++].tcpidx = path->position[i].tcpidx;
    }
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[path->maxidx-2].statehint;
    ipath->position[p].keypoint = path->position[path->maxidx-2].keypoint;
    ipath->position[p++].tcpidx = path->position[path->maxidx-2].tcpidx;
  }
  for(j=0;j<nos;j++)
  {
    ipath->position[p].statehint = path->position[path->maxidx-1].statehint;
    ipath->position[p].keypoint = path->position[path->maxidx-1].keypoint;
    ipath->position[p++].tcpidx = path->position[path->maxidx-1].tcpidx;
  }

}


void mpnSplineJointSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos)
{
  int i;
  tmpnKeyPoint keytable[500];
  tmpnPosition postable[5000];
  for(i=0;i<path->maxidx;i++)
  {
    keytable[i].x=path->position[i].actuatorSpace.name.a;
    keytable[i].y=path->position[i].actuatorSpace.name.b;
    keytable[i].z=path->position[i].actuatorSpace.name.c;
    keytable[i].v=path->position[i].actuatorSpace.name.d;
    keytable[i].w=path->position[i].actuatorSpace.name.e;
    keytable[i].u=path->position[i].actuatorSpace.name.f;
    keytable[i].t=path->position[i].t;
    keytable[i].statehint=path->position[i].statehint;
    keytable[i].positionhint=path->position[i].positionhint;
    keytable[i].tcpidx =path->position[i].tcpidx;
  }
  ipath->maxidx = bspline(path->maxidx
                          ,pathdef->splineorder
                          ,nos
                          ,keytable
                          ,postable
                          ,0 );
  for(i=0;i<ipath->maxidx;i++)
  {
    ipath->position[i].actuatorSpace.name.a=postable[i].taskSpace.x;
    ipath->position[i].actuatorSpace.name.b=postable[i].taskSpace.y;
    ipath->position[i].actuatorSpace.name.c=postable[i].taskSpace.z;
    ipath->position[i].actuatorSpace.name.d=postable[i].taskSpace.v;
    ipath->position[i].actuatorSpace.name.e=postable[i].taskSpace.w;
    ipath->position[i].actuatorSpace.name.f=postable[i].taskSpace.u;
    ipath->position[i].t =postable[i].t;
    ipath->position[i].statehint=postable[i].statehint;
    ipath->position[i].positionhint=postable[i].positionhint;
    ipath->position[i].tcpidx=postable[i].tcpidx;
  }
}

void mpnSplineTaskSpace(tmpnRobot *robot, tmpnPathDef *pathdef, tmpnPath *path, tmpnPath *ipath, int nos)
{
  int i;
  tmpnKeyPoint keytable[500];
  tmpnPosition postable[5000];
  for(i=0;i<path->maxidx;i++)
  {
    keytable[i].x=path->position[i].taskSpace.x;
    keytable[i].y=path->position[i].taskSpace.y;
    keytable[i].z=path->position[i].taskSpace.z;
    keytable[i].v=path->position[i].taskSpace.v;
    keytable[i].w=path->position[i].taskSpace.w;
    keytable[i].u=path->position[i].taskSpace.u;
    keytable[i].t=path->position[i].t;
    keytable[i].statehint=path->position[i].statehint;
    keytable[i].positionhint=path->position[i].positionhint;
  }
  ipath->maxidx = bspline(path->maxidx
                          ,pathdef->splineorder
                          ,nos
                          ,keytable
                          ,postable
                          ,0 );
  for(i=0;i<ipath->maxidx;i++)
  {
    ipath->position[i].taskSpace.x=postable[i].taskSpace.x;
    ipath->position[i].taskSpace.y=postable[i].taskSpace.y;
    ipath->position[i].taskSpace.z=postable[i].taskSpace.z;
    ipath->position[i].taskSpace.v=postable[i].taskSpace.v;
    ipath->position[i].taskSpace.w=postable[i].taskSpace.w;
    ipath->position[i].taskSpace.u=postable[i].taskSpace.u;
    ipath->position[i].t =postable[i].t;
    ipath->position[i].statehint=postable[i].statehint;
    ipath->position[i].positionhint=postable[i].positionhint;
  }
}
