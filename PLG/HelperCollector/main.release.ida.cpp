#pragma pack(push, 4)
typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef          char   int8;
typedef signed   char   sint8;
typedef unsigned char   uint8;
typedef          short  int16;
typedef unsigned short  uint16;
typedef          int    int32;
typedef unsigned int    uint32;
#pragma pack(push, 1)
typedef unsigned __int64 ulonglong;
typedef          __int64 longlong;
extern "C"  char *__stdcall print(
        uint32 l,
        uint32 h,
        char *buf,
        int bufsize,
        int radix,
        int issigned);
 longlong make_longlong(uint32 ll,int32 hh) { return ll | (longlong(hh) << 32); }
 ulonglong make_ulonglong(uint32 ll,int32 hh) { return ll | (ulonglong(hh) << 32); }
 uint32 low      (const ulonglong &x) { return uint32(x); }
 uint32 high     (const ulonglong &x) { return uint32(x>>32); }
 uint32 low      (const longlong &x) { return uint32(x); }
 int32  high     (const longlong &x) { return uint32(x>>32); }
 char *print(longlong x,char *buf,int bufsize,int radix)
        { return print(uint32(x),uint32(x>>32),buf,bufsize,radix,true); }
 char *print(ulonglong x,char *buf,int bufsize,int radix)
        { return print(uint32(x),uint32(x>>32),buf,bufsize,radix,false); }
extern "C"  longlong __stdcall llong_scan(
        const char *buf,
        int radix,
        const char **end);
   extern "C"  ulonglong __stdcall swap64(ulonglong);
      longlong swap64(longlong x)
     {
       return longlong(swap64(ulonglong(x)));
     }
class uint128
{
  ulonglong l;
  ulonglong h;
  friend class int128;
public:
  uint128(void)  {}
  uint128(uint x) { l=x; h=0; }
  uint128(int x)  { l=x; h=(x<0)?-1:0; }
  uint128(ulonglong x) { l=x; h=0; }
  uint128(longlong x)  { l=x; h=(x<0)?-1:0; }
  uint128(ulonglong ll, ulonglong hh) { l=ll; h=hh; }
  friend ulonglong low (const uint128 &x) { return x.l; }
  friend ulonglong high(const uint128 &x) { return x.h; }
  friend uint128 operator+(const uint128 &x, const uint128 &y);
  friend uint128 operator-(const uint128 &x, const uint128 &y);
  friend uint128 operator/(const uint128 &x, const uint128 &y);
  friend uint128 operator%(const uint128 &x, const uint128 &y);
  friend uint128 operator*(const uint128 &x, const uint128 &y);
  friend uint128 operator|(const uint128 &x, const uint128 &y);
  friend uint128 operator&(const uint128 &x, const uint128 &y);
  friend uint128 operator^(const uint128 &x, const uint128 &y);
  friend uint128 operator>>(const uint128 &x, int cnt);
  friend uint128 operator<<(const uint128 &x, int cnt);
  uint128 &operator+=(const uint128 &y);
  uint128 &operator-=(const uint128 &y);
  uint128 &operator/=(const uint128 &y);
  uint128 &operator%=(const uint128 &y);
  uint128 &operator*=(const uint128 &y);
  uint128 &operator|=(const uint128 &y);
  uint128 &operator&=(const uint128 &y);
  uint128 &operator^=(const uint128 &y);
  uint128 &operator>>=(int cnt);
  uint128 &operator<<=(int cnt);
  uint128 &operator++(void);
  uint128 &operator--(void);
  friend uint128 operator+(const uint128 &x) { return x; }
  friend uint128 operator-(const uint128 &x);
  friend uint128 operator~(const uint128 &x) { return uint128(~x.l,~x.h); }
  friend int operator==(const uint128 &x, const uint128 &y) { return x.l == y.l && x.h == y.h; }
  friend int operator!=(const uint128 &x, const uint128 &y) { return x.l != y.l || x.h != y.h; }
  friend int operator> (const uint128 &x, const uint128 &y) { return x.h > y.h || (x.h == y.h && x.l >  y.l); }
  friend int operator< (const uint128 &x, const uint128 &y) { return x.h < y.h || (x.h == y.h && x.l <  y.l); }
  friend int operator>=(const uint128 &x, const uint128 &y) { return x.h > y.h || (x.h == y.h && x.l >= y.l); }
  friend int operator<=(const uint128 &x, const uint128 &y) { return x.h < y.h || (x.h == y.h && x.l <= y.l); }
};
class int128
{
  ulonglong l;
   longlong h;
  friend class uint128;
public:
  int128(void)  {}
  int128(uint x) { l=x; h=0; }
  int128(int x)  { l=x; h=(x<0)?-1:0; }
  int128(ulonglong x) { l=x; h=0; }
  int128(longlong x)  { l=x; h=(x<0)?-1:0; }
  int128(ulonglong ll, ulonglong hh) { l=ll; h=hh; }
  int128(const uint128 &x) { l=x.l; h=x.h; }
  friend ulonglong low (const int128 &x) { return x.l; }
  friend ulonglong high(const int128 &x) { return x.h; }
  friend int128 operator+(const int128 &x, const int128 &y);
  friend int128 operator-(const int128 &x, const int128 &y);
  friend int128 operator/(const int128 &x, const int128 &y);
  friend int128 operator%(const int128 &x, const int128 &y);
  friend int128 operator*(const int128 &x, const int128 &y);
  friend int128 operator|(const int128 &x, const int128 &y);
  friend int128 operator&(const int128 &x, const int128 &y);
  friend int128 operator^(const int128 &x, const int128 &y);
  friend int128 operator>>(const int128 &x, int cnt);
  friend int128 operator<<(const int128 &x, int cnt);
  int128 &operator+=(const int128 &y);
  int128 &operator-=(const int128 &y);
  int128 &operator/=(const int128 &y);
  int128 &operator%=(const int128 &y);
  int128 &operator*=(const int128 &y);
  int128 &operator|=(const int128 &y);
  int128 &operator&=(const int128 &y);
  int128 &operator^=(const int128 &y);
  int128 &operator>>=(int cnt);
  int128 &operator<<=(int cnt);
  int128 &operator++(void);
  int128 &operator--(void);
  friend int128 operator+(const int128 &x) { return x; }
  friend int128 operator-(const int128 &x);
  friend int128 operator~(const int128 &x) { return int128(~x.l,~x.h); }
  friend int operator==(const int128 &x, const int128 &y) { return x.l == y.l && x.h == y.h; }
  friend int operator!=(const int128 &x, const int128 &y) { return x.l != y.l || x.h != y.h; }
  friend int operator> (const int128 &x, const int128 &y) { return x.h > y.h || (x.h == y.h && x.l >  y.l); }
  friend int operator< (const int128 &x, const int128 &y) { return x.h < y.h || (x.h == y.h && x.l <  y.l); }
  friend int operator>=(const int128 &x, const int128 &y) { return x.h > y.h || (x.h == y.h && x.l >= y.l); }
  friend int operator<=(const int128 &x, const int128 &y) { return x.h < y.h || (x.h == y.h && x.l <= y.l); }
};
extern "C"  void __stdcall swap128(uint128 *x);
 uint128 operator+(const uint128 &x, const uint128 &y) {
  ulonglong h = x.h + y.h;
  ulonglong l = x.l + y.l;
  if ( l < x.l )
    h = h + 1;
  return uint128(l,h);
}
 uint128 operator-(const uint128 &x, const uint128 &y) {
  ulonglong h = x.h - y.h;
  ulonglong l = x.l - y.l;
  if ( l > x.l )
    h = h - 1;
  return uint128(l,h);
}
 uint128 operator|(const uint128 &x, const uint128 &y) {
  return uint128(x.l | y.l,
                        x.h | y.h);
}
 uint128 operator&(const uint128 &x, const uint128 &y) {
  return uint128(x.l & y.l,
                        x.h & y.h);
}
 uint128 operator^(const uint128 &x, const uint128 &y) {
  return uint128(x.l ^ y.l,
                        x.h ^ y.h);
}
 uint128 &uint128::operator+=(const uint128 &y) {
  return (*this = *this + y);
}
 uint128 &uint128::operator-=(const uint128 &y) {
  return (*this = *this - y);
}
 uint128 &uint128::operator|=(const uint128 &y) {
  return (*this = *this | y);
}
 uint128 &uint128::operator&=(const uint128 &y) {
  return (*this = *this & y);
}
 uint128 &uint128::operator^=(const uint128 &y) {
  return (*this = *this ^ y);
}
 uint128 &uint128::operator/=(const uint128 &y) {
  return (*this = *this / y);
}
 uint128 &uint128::operator%=(const uint128 &y) {
  return (*this = *this % y);
}
 uint128 &uint128::operator*=(const uint128 &y) {
  return (*this = *this * y);
}
 uint128 &uint128::operator<<=(int cnt) {
  return (*this = *this << cnt);
}
 uint128 &uint128::operator>>=(int cnt) {
  return (*this = *this >> cnt);
}
 uint128 &uint128::operator++(void) {
  if ( ++l == 0 ) ++h;
  return *this;
}
 uint128 &uint128::operator--(void) {
  if ( l == 0 ) --h;
  --l;
  return *this;
}
 uint128 operator-(const uint128 &x) {
  return ~x + 1;
}
#pragma pack(pop)
typedef longlong        int64;
typedef ulonglong       uint64;
typedef wchar_t         wchar16_t;
typedef uint32          wchar32_t;
typedef int32 ssize_t;
 bool can_place32(uint64 a) { return a == (uint64)(uint32)low(a); }
 bool can_place32(int64 a)  { return a == ( int64)( int32)low(a); }
  typedef uint32 ea_t;
  typedef uint32 sel_t;
  typedef uint32 asize_t;
  typedef int32 adiff_t;
typedef asize_t uval_t;
typedef adiff_t sval_t;
typedef int32 qtime32_t;
 char *qctime(qtime32_t t)
{
  time_t tmp = t;
  return ctime(&tmp);
}
 struct tm *qlocaltime(qtime32_t t)
{
  time_t tmp = t;
  return localtime(&tmp);
}
extern "C"  void __stdcall qsleep(int milliseconds);
extern "C"  void __stdcall get_nsec_stamp(uint64 *nsecs);
 extern "C" int __declspec(dllimport) __cdecl vsscanf(const char *input, const char *format, va_list va);
#pragma warning(disable : 4200)
typedef int error_t;
extern "C"  error_t __stdcall set_qerrno(error_t code);
extern "C"  error_t __stdcall get_qerrno(void);
enum ostype_t
{
   osMSDOS,
   osAIX_RISC,
   osOS2,
   osNT,
   osLINUX,
   osMACOSX,
   osBSD,
};
extern ostype_t ostype;
extern "C" bool __declspec(dllimport) under_debugger;
extern "C"  __declspec(noreturn) void __stdcall interr(int code);
typedef char COMPILE_TIME_ASSERT_470 [(sizeof(int16) == 2) ? 1 : -1];
typedef char COMPILE_TIME_ASSERT_471 [(sizeof(int32) == 4) ? 1 : -1];
typedef char COMPILE_TIME_ASSERT_472 [(sizeof(int64) == 8) ? 1 : -1];
extern "C"  void *__stdcall qalloc(size_t size);
extern "C"  void *__stdcall qrealloc(void *alloc, size_t newsize);
extern "C"  void *__stdcall qcalloc(size_t nitems, size_t itemsize);
extern "C"  void  __stdcall qfree(void *alloc);
extern "C"  char *__stdcall qstrdup(const char *string);
template <class T>
T *qalloc_array(size_t n)
{
  return (T *)qcalloc(n, sizeof(T));
}
template <class T>
T *qrealloc_array(T *ptr, size_t n)
{
  size_t nbytes = n * sizeof(T);
  if ( nbytes < n )
    return 0;
  return (T *)qrealloc(ptr, nbytes);
}
extern "C"  void *__stdcall memrev(void *buf, ssize_t size);
char *strcompact(char *string);
char *strcenter(char *s, size_t len);
extern "C"  char *__stdcall strrpl(char *str, int char1, int char2);
       char *tail(      char *str) { return strchr(str, '\0'); }
 const char *tail(const char *str) { return strchr(str, '\0'); }
extern "C"  char *__stdcall qstrncpy(char *dst, const char *src, size_t dstsize);
extern "C"  char *__stdcall qstpncpy(char *dst, const char *src, size_t dstsize);
extern "C"  char *__stdcall qstrncat(char *dst, const char *src, size_t dstsize);
extern "C"  const char *__stdcall stristr(const char *s1, const char *s2);
 char *__stdcall stristr(char *s1, const char *s2) { return const_cast<char *>(stristr((const char *)s1, s2)); }
 bool  qisspace(char c) { return isspace(uchar(c)) != 0; }
 bool  qisalpha(char c) { return isalpha(uchar(c)) != 0; }
 bool  qisalnum(char c) { return isalnum(uchar(c)) != 0; }
 bool  qispunct(char c) { return ispunct(uchar(c)) != 0; }
 bool  qislower(char c) { return islower(uchar(c)) != 0; }
 bool  qisupper(char c) { return isupper(uchar(c)) != 0; }
 bool  qisprint(char c) { return isprint(uchar(c)) != 0; }
 bool  qisdigit(char c) { return isdigit(uchar(c)) != 0; }
 bool  qisxdigit(char c) { return isxdigit(uchar(c)) != 0; }
 char  qtolower(char c) { return tolower(uchar(c)); }
 char  qtoupper(char c) { return toupper(uchar(c)); }
extern "C"   int __stdcall qvsnprintf(char *buffer, size_t n, const char *format, va_list va);
extern "C"   int __stdcall qvsscanf(const char *input, const char *format, va_list va);
extern "C"   int __stdcall qsnprintf(char *buffer, size_t n, const char *format, ...);
extern "C"   int __stdcall append_snprintf(char *buf, const char *end, const char *format, ...);
extern "C"   int __stdcall qsscanf(const char *input, const char *format, ...);
extern "C"  char *__stdcall vqmakepath(char *buf, size_t bufsize, const char *s1, va_list);
extern "C"  char *__stdcall qmakepath(char *buf, size_t bufsize, const char *s1, ...);
extern "C"  bool __stdcall qdirname(char *buf, size_t bufsize, const char *path);
extern "C"  char *__stdcall qmakefile(
        char *buf,
        size_t bufsize,
        const char *base,
        const char *ext);
extern "C"  char *__stdcall qsplitfile(char *file, char **base, char **ext);
extern "C"  bool __stdcall qisabspath(const char *file);
extern "C"  const char *__stdcall qbasename(const char *path);
 char *qbasename(char *path) { return const_cast<char *>(qbasename((const char *)path)); }
extern "C"  char *__stdcall qmake_full_path(char *dst, size_t dstsize, const char *src);
extern "C"  bool __stdcall search_path(
        const char *file,
        char *buf,
        size_t bufsize,
        bool search_cwd);
extern "C"  char *__stdcall set_file_ext(
        char *outbuf,
        size_t bufsize,
        const char *file,
        const char *ext);
extern "C"  const char *__stdcall get_file_ext(const char *file);
 bool __stdcall has_file_ext(const char *file)
  { return get_file_ext(file) != 0; }
 char *__stdcall make_file_ext(
        char *buf,
        size_t bufsize,
        const char *file,
        const char *ext)
{
  if ( has_file_ext(file) )
    return ::qstrncpy(buf, file, bufsize);
  else
    return set_file_ext(buf, bufsize, file, ext);
}
extern "C"  bool __stdcall sanitize_file_name(char *name, size_t namesize);
extern "C"  int   __stdcall qopen(const char *file, int mode);
extern "C"  int   __stdcall qcreate(const char *file, int stat);
extern "C"  int   __stdcall qread(int h, void *buf, size_t n);
extern "C"  int   __stdcall qwrite(int h, const void *buf, size_t n);
extern "C"  int32 __stdcall qtell(int h);
extern "C"  int32 __stdcall qseek(int h, int32 offset, int whence);
extern "C"  int   __stdcall qclose(int h);
extern "C"  uint32 __stdcall qfilesize(const char *fname);
extern "C"  uint32 __stdcall qfilelength(int h);
extern "C"  int   __stdcall qchsize(int h, uint32 fsize);
extern "C"  int   __stdcall qmkdir(const char *file, int mode);
extern "C"  bool  __stdcall qfileexist(const char *file);
extern "C"  bool  __stdcall qisdir(const char *file);
extern "C" void __stdcall qatexit(void (__stdcall *func)(void));
extern "C" void __stdcall del_qatexit(void (__stdcall*func)(void));
extern "C"  __declspec(noreturn) void __stdcall qexit(int code);
 bool __stdcall test_bit(const uchar *bitmap, size_t bit)
{
  return (bitmap[bit/8] & (1<<(bit&7))) != 0;
}
 void __stdcall set_bit(uchar *bitmap, size_t bit)
{
  uchar *p = bitmap + bit/8;
  *p = uchar(*p | (1<<(bit&7)));
}
 void __stdcall clear_bit(uchar *bitmap, size_t bit)
{
  uchar *p = bitmap + bit/8;
  *p = uchar(*p & ~(1<<(bit&7)));
}
 void __stdcall set_all_bits(uchar *bitmap, size_t nbits)
{
  memset(bitmap, 0xFF, (nbits+7)/8);
  if ( (nbits & 7) != 0 )
  {
    uchar *p = bitmap + nbits/8;
    *p = uchar(*p & ~((1 << (nbits&7))-1));
  }
}
 void __stdcall clear_all_bits(uchar *bitmap, size_t nbits)
{
  memset(bitmap, 0, (nbits+7)/8);
}
namespace interval
{
   bool overlap(uval_t off1, asize_t s1, uval_t off2, asize_t s2)
  {
    return off2 < off1+s1 && off1 < off2+s2;
  }
   bool includes(uval_t off1, asize_t s1, uval_t off2, asize_t s2)
  {
    return off2 >= off1 && off2+s2 <= off1+s1;
  }
   bool contains(uval_t off1, asize_t s1, uval_t off)
  {
    return off >= off1 && off < off1+s1;
  }
};
template<class T> T qrotl(T value, size_t count)
{
  const size_t nbits = sizeof(T) * 8;
  count %= nbits;
  T high = value >> (nbits - count);
  value <<= count;
  value |= high;
  return value;
}
template<class T> T qrotr(T value, size_t count)
{
  const size_t nbits = sizeof(T) * 8;
  count %= nbits;
  T low = value << (nbits - count);
  value >>= count;
  value |= low;
  return value;
}
template<class T, class U> void __stdcall setflag(T &where, U bit, bool cnd)
{
   if ( cnd )
     where = T(where | bit);
   else
     where = T(where & ~T(bit));
}
extern "C"  int __stdcall readbytes(int h, uint32 *res, int size, bool mf);
extern "C"  int __stdcall writebytes(int h, uint32 l, int size, bool mf);
extern "C"  int __stdcall read2bytes(int h, uint16 *res, bool mf);
 uint32 swap32(uint32 x)
  { return (x>>24) | (x<<24) | ((x>>8) & 0x0000FF00L) | ((x<<8) & 0x00FF0000L); }
 ushort swap16(ushort x)
  { return ushort((x<<8) | (x>>8)); }
extern "C"  void __stdcall swap_value(void *dst, const void *src, int size);
extern "C"  void __stdcall reloc_value(void *value, int size, adiff_t delta, bool mf);
extern "C"  uval_t __stdcall rotate_left(uval_t x, int count, size_t bits, size_t offset);
template <class T>  void qswap(T &a, T &b)
{
  char temp[sizeof(T)];
  memcpy(&temp, &a, sizeof(T));
  memcpy(&a, &b, sizeof(T));
  memcpy(&b, &temp, sizeof(T));
}
extern "C"  void *__stdcall qalloc_or_throw(size_t size);
extern "C"  void *__stdcall qrealloc_or_throw(void *ptr, size_t size);
struct ida_true_type {};
struct ida_false_type {};
template <class T> struct ida_type_traits     { typedef ida_false_type is_pod_type; };
template <class T> struct ida_type_traits<T*> { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits< char>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<uchar>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<  int>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits< uint>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<short>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<ushort> { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits< long>  { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<unsigned long> { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits< int64> { typedef ida_true_type is_pod_type; };
template <> struct ida_type_traits<uint64> { typedef ida_true_type is_pod_type; };
 bool check_type_trait(ida_false_type) { return false; }
 bool check_type_trait(ida_true_type) { return true; }
template <class T>  bool is_pod_type(void)
{
  typename ida_type_traits<T>::is_pod_type x;
  return check_type_trait(x);
}
template <class T> struct ida_movable_type
{
  typedef typename ida_type_traits<T>::is_pod_type is_movable_type;
};
template <class T>  bool may_move_bytes(void)
{
  typedef typename ida_movable_type<T>::is_movable_type mmb_t;
  return check_type_trait(mmb_t());
}
template <class T> class qvector
{
  T *array;
  size_t n, alloc;
  qvector<T> &assign(const qvector<T> &x)
  {
    if ( x.n > 0 )
    {
      array = (T*)qalloc_or_throw(x.alloc * sizeof(T));
      alloc = x.alloc;
      while ( n < x.n )
      {
        new (array+n) T(x.array[n]);
        ++n;
      }
    }
    return *this;
  }
  void shift_down(T *dst, T *src, size_t cnt)
  {
    if ( may_move_bytes<T>() )
    {
      memmove(dst, src, cnt*sizeof(T));
    }
    else
    {
      ssize_t s = cnt;
      while( --s >= 0 )
      {
        new(dst) T(*src);
        src->~T();
        ++src;
        ++dst;
      }
    }
  }
  void shift_up(T *dst, T *src, size_t cnt)
  {
    if ( may_move_bytes<T>() )
    {
      memmove(dst, src, cnt*sizeof(T));
    }
    else
    {
      ssize_t s = cnt;
      dst += s;
      src += s;
      while( --s >= 0 )
      {
        --src;
        --dst;
        new(dst) T(*src);
        src->~T();
      }
    }
  }
public:
  typedef T value_type;
  qvector(void) : array(0), n(0), alloc(0) {}
  qvector(const qvector<T> &x) : array(0), n(0), alloc(0) { assign(x); }
  ~qvector(void) { clear(); }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  void push_back(const T &x)
  {
    reserve(n+1);
    new (array+n) T(x);
    ++n;
  }
  T &push_back(void)
  {
    reserve(n+1);
    T *ptr = array + n;
    new (ptr) T;
    ++n;
    return *ptr;
  }
  void pop_back(void)
  {
    if ( n > 0 )
    {
      array[--n].~T();
    }
  }
  size_t size(void) const { return n; }
  bool empty(void) const { return n == 0; }
  const T &operator[](size_t idx) const { return array[idx]; }
        T &operator[](size_t idx)       { return array[idx]; }
  const T &at(size_t idx) const { return array[idx]; }
        T &at(size_t idx)       { return array[idx]; }
  const T &front(void) const { return array[0]; }
        T &front(void)       { return array[0]; }
  const T &back(void) const { return array[n-1]; }
        T &back(void)       { return array[n-1]; }
  void qclear(void)
  {
    if ( is_pod_type<T>() )
    {
      n = 0;
    }
    else
    {
      while ( n > 0 )
      {
        array[n-1].~T();
        --n;
      }
    }
  }
  void clear(void)
  {
    if ( array != 0 )
    {
      qclear();
      qfree(array);
      array = 0;
      alloc = 0;
    }
  }
  qvector<T> &operator=(const qvector<T> &x)
  {
    size_t mn = ((n) < (x.n)? (n): (x.n));
    for ( size_t i=0; i < mn; i++ )
      array[i] = x.array[i];
    if ( n > x.n )
    {
      if ( is_pod_type<T>() )
      {
        n = x.n;
      }
      else
      {
        while ( n > x.n )
        {
          array[n-1].~T();
          --n;
        }
      }
    }
    else
    {
      reserve(x.n);
      while ( n < x.n )
      {
        new(array+n) T(x.array[n]);
        ++n;
      }
    }
    return *this;
  }
  void resize(size_t s, const T &x)
  {
    if ( s < n )
    {
      if ( !is_pod_type<T>() )
        for ( ssize_t i=ssize_t(n); --i >= ssize_t(s); )
          array[i].~T();
      n = s;
    }
    else
    {
      reserve(s);
      while ( n < s )
      {
        new(array+n) T(x);
        ++n;
      }
    }
  }
  void resize(size_t s) { resize(s, T()); }
  void grow(const T &x=T())
  {
    reserve(n+1);
    new(array+n) T(x);
    ++n;
  }
  size_t capacity(void) const { return alloc; }
  void reserve(size_t cnt)
  {
    if ( cnt > alloc )
    {
      size_t m0 = alloc * 2;
      size_t m = ((m0) > (cnt)? (m0): (cnt));
      size_t b = m * sizeof(T);
      if ( b < m )
        b = 0xDEADBEEF;
      if ( may_move_bytes<T>() )
      {
        array = (T*)qrealloc_or_throw(array, b);
      }
      else
      {
        T *new_array = (T*)qalloc_or_throw(b);
        shift_down(new_array, array, n);
        qfree(array);
        array = new_array;
      }
      alloc = m;
    }
  }
  void truncate(void)
  {
    if ( alloc > n )
    {
      array = (T*)qrealloc(array, n*sizeof(T));
      alloc = n;
    }
  }
  void swap(qvector<T> &r)
  {
    T *array2     = array;
    size_t n2     = n;
    size_t alloc2 = alloc;
    array = r.array;
    n     = r.n;
    alloc = r.alloc;
    r.array = array2;
    r.n     = n2;
    r.alloc = alloc2;
  }
  T *extract(void)
  {
    truncate();
    alloc = 0;
    n = 0;
    T *res = array;
    array = 0;
    return res;
  }
  void inject(T *s, size_t len)
  {
    array = s;
    alloc = len;
    n = len;
  }
  bool operator == (const qvector<T> &r) const
  {
    if ( n != r.n )
      return false;
    for ( size_t i=0; i < n; i++ )
      if ( array[i] != r[i] )
        return false;
    return true;
  }
  bool operator != (const qvector<T> &r) const { return !(*this == r); }
  typedef T *iterator;
  typedef const T *const_iterator;
  iterator begin(void) { return array; }
  iterator end(void) { return array + n; }
  const_iterator begin(void) const { return array; }
  const_iterator end(void) const { return array + n; }
  iterator insert(iterator it, const T &x)
  {
    size_t idx = it - array;
    reserve(n+1);
    T *p = array + idx;
    size_t rest = end() - p;
    shift_up(p+1, p, rest);
    new(p) T(x);
    n++;
    return iterator(p);
  }
  template <class it2> iterator insert(iterator it, it2 first, it2 last)
  {
    size_t cnt = last - first;
    if ( cnt == 0 )
      return it;
    size_t idx = it - array;
    reserve(n+cnt);
    T *p = array + idx;
    size_t rest = end() - p;
    shift_up(p+cnt, p, rest);
    while ( first != last )
    {
      new(p) T(*first);
      ++p;
      ++first;
    }
    n += cnt;
    return iterator(array+idx);
  }
  iterator erase(iterator it)
  {
    it->~T();
    size_t rest = end() - it - 1;
    shift_down(it, it+1, rest);
    n--;
    return it;
  }
  iterator erase(iterator first, iterator last)
  {
    for ( T *p=first; p != last; ++p )
      p->~T();
    size_t rest = end() - last;
    shift_down(first, last, rest);
    n -= last - first;
    return first;
  }
  iterator find(const T &x)
  {
    iterator p;
    for ( p=begin(); p != end(); ++p )
      if ( x == *p )
        break;
    return p;
  }
  const_iterator find(const T &x) const
  {
    const_iterator p;
    for ( p=begin(); p != end(); ++p )
      if ( x == *p )
        break;
    return p;
  }
  bool has(const T &x) const { return find(x) != end(); }
  bool add_unique(const T &x)
  {
    if ( has(x) )
      return false;
    push_back(x);
    return true;
  }
  bool del(const T &x)
  {
    iterator p = find(x);
    if ( p == end() )
      return false;
    erase(p);
    return true;
  }
};
template<class T>
class qstack : public qvector<T>
{
  typedef qvector<T> base;
public:
  T pop(void)
  {
    T v = base::back();
    base::pop_back();
    return v;
  }
  const T &top(void) const
  {
    return base::back();
  }
  T &top(void) { return const_cast<T&>(const_cast<const qstack<T>*>(this)->top()); }
  void push(const T &v)
  {
    push_back(v);
  }
};
template <class T>
class qrefcnt_t
{
  T *ptr;
public:
  explicit qrefcnt_t(T *p) : ptr(p) {}
  qrefcnt_t(const qrefcnt_t &r) : ptr(r.ptr)
  {
    if ( ptr != 0 )
      ptr->refcnt++;
  }
  qrefcnt_t &operator=(const qrefcnt_t &r)
  {
    if ( ptr != 0 && --ptr->refcnt == 0 )
      ptr->release();
    ptr = r.ptr;
    if ( ptr != 0 )
      ptr->refcnt++;
    return *this;
  }
  ~qrefcnt_t(void)
  {
    if ( ptr != 0 && --ptr->refcnt == 0 )
      ptr->release();
  }
  operator T *()
  {
    return ptr;
  }
  T *operator ->()
  {
    return ptr;
  }
  T &operator *()
  {
    return *ptr;
  }
};
class qrefcnt_obj_t
{
public:
  int refcnt;
  qrefcnt_obj_t(void) : refcnt(1) {}
  virtual void __stdcall release(void) = 0;
};
template <class T>
class qiterator : public qrefcnt_obj_t
{
public:
  typedef T value_type;
  virtual bool __stdcall first(void) = 0;
  virtual bool __stdcall next(void) = 0;
  virtual T __stdcall operator *(void) = 0;
  virtual T get(void) { return this->operator*(); }
};
 size_t __stdcall qstrlen(const char *s) { return strlen(s); }
 size_t __stdcall qstrlen(const uchar *s) { return strlen((const char *)s); }
extern "C"  size_t __stdcall qstrlen(const wchar16_t *s);
 int __stdcall qstrcmp(const char *s1, const char *s2) { return strcmp(s1, s2); }
 int __stdcall qstrcmp(const uchar *s1, const uchar *s2) { return strcmp((const char *)s1, (const char *)s2); }
extern "C"  int __stdcall qstrcmp(const wchar16_t *s1, const wchar16_t *s2);
 const char *__stdcall qstrstr(const char *s1, const char *s2) { return strstr(s1, s2); }
 const uchar *__stdcall qstrstr(const uchar *s1, const uchar *s2) { return (const uchar *)strstr((const char *)s1, (const char *)s2); }
 const char *__stdcall qstrchr(const char *s1, char c) { return strchr(s1, c); }
 const uchar *__stdcall qstrchr(const uchar *s1, uchar c) { return (const uchar *)strchr((const char *)s1, c); }
extern "C"  const wchar16_t *__stdcall qstrchr(const wchar16_t *s1, wchar16_t c);
 const char *__stdcall qstrrchr(const char *s1, char c) { return strrchr(s1, c); }
 const uchar *__stdcall qstrrchr(const uchar *s1, uchar c) { return (const uchar *)strrchr((const char *)s1, c); }
extern "C"  const wchar16_t *__stdcall qstrrchr(const wchar16_t *s1, wchar16_t c);
template<class qchar>
class _qstring
{
  qvector<qchar> body;
public:
  _qstring(void) {}
  _qstring(const qchar *ptr)
  {
    if ( ptr != 0 )
    {
      size_t len = ::qstrlen(ptr) + 1;
      body.resize(len, '\0');
      memcpy(body.begin(), ptr, len*sizeof(qchar));
    }
  }
  _qstring(const qchar *ptr, size_t len)
  {
    if ( len > 0 )
    {
      body.resize(len+1, '\0');
      memcpy(body.begin(), ptr, len*sizeof(qchar));
    }
  }
  void swap(_qstring<qchar> &r) { body.swap(r.body); }
  size_t length(void) const { size_t l = body.size(); return l ? l - 1 : 0; }
  size_t size(void) const { return body.size(); }
  void resize(size_t s, qchar c)
  {
    body.resize(s+1, c);
    body[s] = 0;
  }
  void resize(size_t s) { resize(s, qchar()); }
  void reserve(size_t cnt) { body.reserve(cnt); }
  void clear(void) { body.clear(); }
  void qclear(void) { body.qclear(); }
  bool empty(void) const { return body.size() <= 1; }
  const qchar *c_str(void) const
  {
    static const qchar nullstr[] = { 0 };
    return body.empty() ? nullstr : &body[0];
  }
  typedef qchar *iterator;
  typedef const qchar *const_iterator;
        iterator begin(void)       { return body.begin(); }
  const_iterator begin(void) const { return body.begin(); }
        iterator end(void)       { return body.end(); }
  const_iterator end(void) const { return body.end(); }
  _qstring &operator=(const qchar *str)
  {
    size_t len = str == 0 ? 0 : ::qstrlen(str);
    if ( len > 0 )
    {
      body.resize(len+1, '\0');
      memcpy(body.begin(), str, len*sizeof(qchar));
      body[len] = '\0';
    }
    else
    {
      qclear();
    }
    return *this;
  }
  _qstring &operator+=(qchar c)
  {
    return append(c);
  }
  _qstring &operator+=(const _qstring &r)
  {
    return append(r);
  }
  _qstring operator+(const _qstring &r) const
  {
    _qstring s = *this;
    s += r;
    return s;
  }
  bool operator==(const _qstring &r) const
  {
    return ::qstrcmp(c_str(), r.c_str()) == 0;
  }
  bool operator==(const qchar *r) const
  {
    return ::qstrcmp(c_str(), r) == 0;
  }
  bool operator!=(const _qstring &r) const { return !(*this == r); }
  bool operator!=(const qchar *r) const { return !(*this == r); }
  bool operator<(const _qstring &r) const
  {
    return ::qstrcmp(c_str(), r.c_str()) < 0;
  }
  bool operator<(const qchar *r) const
  {
    return ::qstrcmp(c_str(), r) < 0;
  }
  const qchar &operator[](size_t idx) const
  {
    if ( !body.empty() || idx )
      return body[idx];
    static const qchar nullstr[] = { 0 };
    return nullstr[0];
  }
  qchar &operator[](size_t idx)
  {
    if ( !body.empty() || idx )
      return body[idx];
    static qchar nullstr[] = { 0 };
    return nullstr[0];
  }
  qchar *extract(void) { return body.extract(); }
  void inject(qchar *s, size_t len=0)
  {
    if ( s != 0 )
    {
      if ( len == 0 )
        len = ::qstrlen(s) + 1;
      body.inject(s, len);
    }
  }
  qchar last(void) const
  {
    size_t len = length();
    return len == 0 ? '\0' : body[len-1];
  }
  size_t find(const qchar *str, size_t pos=0) const
  {
    if ( pos <= length() )
    {
      const qchar *beg = c_str();
      const qchar *ptr = ::qstrstr(beg+pos, str);
      if ( ptr != 0 )
        return ptr - beg;
    }
    return npos;
  }
  bool replace(const qchar *what, const qchar *with)
  {
    _qstring result;
    size_t len_what = ::qstrlen(what);
    const qchar *last_pos = c_str();
    const qchar *pos = c_str();
    while ( (pos=::qstrstr(pos, what)) != 0 )
    {
      size_t n = pos - last_pos;
      if ( n > 0 )
        result.append(last_pos, n);
      result.append(with);
      pos += len_what;
      last_pos = pos;
    }
    if ( last_pos == c_str() )
      return false;
    if ( *last_pos )
      result.append(last_pos);
    swap(result);
    return true;
  }
  size_t find(const _qstring &str, size_t pos=0) const { return find(str.c_str(), pos); }
  size_t find(qchar c, size_t pos=0) const
  {
    if ( pos <= length() )
    {
      const qchar *beg = c_str();
      const qchar *ptr = qstrchr(beg+pos, c);
      if ( ptr != 0 )
        return ptr - beg;
    }
    return npos;
  }
  size_t rfind(qchar c, size_t pos=0) const
  {
    if ( pos <= length() )
    {
      const qchar *beg = c_str();
      const qchar *ptr = qstrrchr(beg+pos, c);
      if ( ptr != 0 )
        return ptr - beg;
    }
    return npos;
  }
  _qstring<qchar> substr(size_t pos=0, size_t n=npos) const
  {
    size_t endp = ((length()) < (n)? (length()): (n));
    if ( pos >= endp )
      pos = endp;
    return _qstring<qchar>(c_str()+pos, endp-pos);
  }
  _qstring& remove(size_t idx, size_t cnt)
  {
    size_t len = length();
    if ( idx < len && cnt != 0 )
    {
        cnt += idx;
        if ( cnt < len )
        {
          iterator p1 = body.begin() + cnt;
          iterator p2 = body.begin() + idx;
          memmove(p2, p1, (len-cnt)*sizeof(qchar));
          idx += len - cnt;
        }
        body.resize(idx+1, '\0');
        body[idx] = '\0';
    }
    return *this;
  }
  _qstring& insert(size_t idx, qchar c)
  {
    size_t len = length();
    body.resize(len+2, '\0');
    body[len+1] = '\0';
    if ( idx < len )
    {
      iterator p1 = body.begin() + idx;
      memmove(p1+1, p1, (len-idx)*sizeof(qchar));
      len = idx;
    }
    body[len] = c;
    return *this;
  }
  _qstring& insert(size_t idx, const qchar *str, size_t addlen = 0)
  {
    if ( addlen == 0 && str != 0 )
      addlen = ::qstrlen(str);
    if ( addlen != 0 )
    {
      size_t len = length();
      body.resize(len+addlen+1, '\0');
      body[len+addlen] = '\0';
      if ( idx < len )
      {
        iterator p1 = body.begin() + idx;
        iterator p2 = p1 + addlen;
        memmove(p2, p1, (len-idx)*sizeof(qchar));
        len = idx;
      }
      memcpy(body.begin()+len, str, addlen*sizeof(qchar));
    }
    return *this;
  }
  _qstring& insert(size_t idx, const _qstring &qstr)
  {
    size_t len = length();
    size_t add = qstr.length();
    body.resize(len+add+1, '\0');
    body[len+add] = '\0';
    if ( idx < len )
    {
      iterator p1 = body.begin() + idx;
      iterator p2 = p1 + add;
      memmove(p2, p1, (len-idx)*sizeof(qchar));
      len = idx;
    }
    memcpy(body.begin()+len, qstr.begin(), add*sizeof(qchar));
    return *this;
  }
  _qstring& before(qchar c)               { return insert(0, c);    }
  _qstring& before(const qchar *str)      { return insert(0, str);  }
  _qstring& insert(const _qstring &qstr)  { return insert(0, qstr); }
  _qstring& append(qchar c)
  {
    size_t len = length();
    body.resize(len+2, '\0');
    body[len] = c;
    body[len+1] = '\0';
    return *this;
  }
  _qstring& append(const qchar *str, size_t addlen = 0)
  {
    if ( addlen == 0 && str != 0 )
      addlen = ::qstrlen(str);
    if ( addlen != 0 )
    {
      size_t len = length();
      body.resize(len+addlen+1, '\0');
      body[len+addlen] = '\0';
      memcpy(body.begin()+len, str, addlen*sizeof(qchar));
    }
    return *this;
  }
  _qstring& append(const _qstring &qstr)
  {
    size_t add = qstr.length();
    if ( add != 0 )
    {
      size_t len = length();
      body.resize(len+add+1, '\0');
      body[len+add] = '\0';
      memcpy(body.begin()+len, qstr.begin(), add*sizeof(qchar));
    }
    return *this;
  }
   _qstring& cat_vsprnt(const char *format, va_list va)
  {
    va_list copy;
    copy = va;
    size_t add = ::qvsnprintf(0, 0, format, va);
    if ( add != 0 )
    {
      size_t len = length();
      body.resize(len+add+1, '\0');
      ::qvsnprintf(body.begin()+len, add+1, format, copy);
    }
    return *this;
  }
   _qstring& vsprnt(const char *format, va_list va)
  {
    va_list copy;
    copy = va;
    body.clear();
    size_t add = ::qvsnprintf(0, 0, format, va);
    if ( add != 0 )
    {
      body.resize(add+1, '\0');
      ::qvsnprintf(body.begin(), add+1, format, copy);
    }
    return *this;
  }
   _qstring& cat_sprnt(const char *format, ...)
  {
    va_list va;
    ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    cat_vsprnt(format, va);
    ( va = (va_list)0 );
    return *this;
  }
   _qstring& sprnt(const char *format, ...)
  {
    va_list va;
    ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    vsprnt(format, va);
    ( va = (va_list)0 );
    return *this;
  }
  _qstring& fill(int pos, qchar c, size_t len)
  {
    body.resize(pos);
    resize(pos+len, c);
    return *this;
  }
  _qstring& fill(qchar c, size_t len)
  {
    body.qclear();
    if ( len > 0 )
      resize(len, c);
    return *this;
  }
  static const size_t npos = (size_t) -1;
};
typedef _qstring<char> qstring;
typedef _qstring<uchar> qtype;
typedef _qstring<wchar16_t> qwstring;
class bytevec_t: public qvector<uchar>
{
public:
  bytevec_t() {}
  bytevec_t(const void *buf, size_t sz) { append(buf, sz); }
  bytevec_t &append(const void *buf, size_t sz)
  {
    if ( sz > 0 )
    {
      size_t cur_sz = size();
      size_t new_sz = cur_sz + sz;
      if ( new_sz < cur_sz )
        new_sz = 0xDEADBEEF;
      resize(new_sz);
      memcpy(begin() + cur_sz, buf, sz);
    }
    return *this;
  }
  bytevec_t &growfill(size_t sz, uchar filler=0)
  {
    if ( sz > 0 )
    {
      size_t cur_sz = size();
      size_t new_sz = cur_sz + sz;
      if ( new_sz < cur_sz )
        new_sz = 0xDEADBEEF;
      resize(new_sz, filler);
    }
    return *this;
  }
  void inject(void *buf, size_t len)
  {
    qvector<uchar>::inject((uchar *)buf, len);
  }
  bool test_bit(size_t bit) const   { return ::test_bit(begin(), bit); }
  void set_bit(size_t bit)          { ::set_bit(begin(), bit); }
  void clear_bit(size_t bit)        { ::clear_bit(begin(), bit); }
  void set_all_bits(size_t nbits)   { resize((nbits+7)/8); ::set_all_bits(begin(), nbits); }
  void clear_all_bits(size_t nbits) { ::clear_all_bits(begin(), nbits); }
  void set_bits(const bytevec_t &b)
  {
    size_t nbytes = b.size();
    if ( size() < nbytes )
      resize(nbytes);
    for ( size_t i=0; i < nbytes; i++ )
      at(i) |= b[i];
  }
  void clear_bits(const bytevec_t &b)
  {
    size_t nbytes = ((size()) < (b.size())? (size()): (b.size()));
    iterator p = begin();
    for ( size_t i=0; i < nbytes; i++, ++p )
      *p = uchar(*p & ~b[i]);
  }
};
struct reloc_info_t : public bytevec_t
{
};
extern "C"  bool __stdcall relocate_relobj(struct relobj_t *_relobj, ea_t ea, bool mf);
struct relobj_t : public bytevec_t
{
  ea_t base;
  reloc_info_t ri;
  relobj_t(void) : base(0) {}
  bool relocate(ea_t ea, bool mf) { return relocate_relobj(this, ea, mf); }
};
template <class T> class qlist
{
  struct listnode_t
  {
    listnode_t *next;
    listnode_t *prev;
  };
  struct datanode_t : public listnode_t
  {
    T data;
  };
  listnode_t node;
  size_t length;
  void init(void)
  {
    node.next = &node;
    node.prev = &node;
    length = 0;
  }
public:
  typedef T value_type;
  class const_iterator;
  class iterator { friend class qlist<T>;  listnode_t *cur; iterator( listnode_t *x) : cur(x) {} public: typedef  T value_type; iterator(void) {} iterator(const iterator &x) : cur(x.cur) {} friend class const_iterator; bool operator==(const iterator& x) const { return cur == x.cur; } bool operator!=(const iterator& x) const { return cur != x.cur; }  T &operator*(void) const { return ((datanode_t*)cur)->data; }  T *operator->(void) const { return &(operator*()); } iterator& operator++(void) { cur = cur->next; return *this; } iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; } iterator& operator--(void) { cur = cur->prev; return *this; } iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; } };
  class const_iterator { friend class qlist<T>; const listnode_t *cur; const_iterator(const listnode_t *x) : cur(x) {} public: typedef const T value_type; const_iterator(void) {} const_iterator(const const_iterator &x) : cur(x.cur) {} const_iterator(const iterator &x) : cur(x.cur) {} bool operator==(const const_iterator& x) const { return cur == x.cur; } bool operator!=(const const_iterator& x) const { return cur != x.cur; } const T &operator*(void) const { return ((datanode_t*)cur)->data; } const T *operator->(void) const { return &(operator*()); } const_iterator& operator++(void) { cur = cur->next; return *this; } const_iterator operator++(int) { const_iterator tmp = *this; ++(*this); return tmp; } const_iterator& operator--(void) { cur = cur->prev; return *this; } const_iterator operator--(int) { const_iterator tmp = *this; --(*this); return tmp; } };
  class reverse_iterator { iterator p; public: reverse_iterator(void) {} reverse_iterator(const iterator &x) : p(x) {} typename iterator::value_type &operator*(void) const { iterator q=p; return *--q; } typename iterator::value_type *operator->(void) const { return &(operator*()); } reverse_iterator &operator++(void) { --p; return *this; } reverse_iterator &operator++(int) { iterator q=p; --p; return q; } reverse_iterator &operator--(void) { ++p; return *this; } reverse_iterator &operator--(int) { iterator q=p; ++p; return q; } bool operator==(const reverse_iterator& x) const { return p == x.p; } bool operator!=(const reverse_iterator& x) const { return p != x.p; } };
  class const_reverse_iterator { const_iterator p; public: const_reverse_iterator(void) {} const_reverse_iterator(const const_iterator &x) : p(x) {} typename const_iterator::value_type &operator*(void) const { const_iterator q=p; return *--q; } typename const_iterator::value_type *operator->(void) const { return &(operator*()); } const_reverse_iterator &operator++(void) { --p; return *this; } const_reverse_iterator &operator++(int) { const_iterator q=p; --p; return q; } const_reverse_iterator &operator--(void) { ++p; return *this; } const_reverse_iterator &operator--(int) { const_iterator q=p; ++p; return q; } bool operator==(const const_reverse_iterator& x) const { return p == x.p; } bool operator!=(const const_reverse_iterator& x) const { return p != x.p; } };
  qlist(void) { init(); }
  qlist(const qlist<T> &x)
  {
    init();
    insert(begin(), x.begin(), x.end());
  }
  ~qlist(void)
  {
    clear();
  }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  qlist<T> &operator=(const qlist<T> &x)
  {
    if ( this != &x )
    {
      iterator first1 = begin();
      iterator last1 = end();
      const_iterator first2 = x.begin();
      const_iterator last2 = x.end();
      while ( first1 != last1 && first2 != last2 )
        *first1++ = *first2++;
      if ( first2 == last2 )
        erase(first1, last1);
      else
        insert(last1, first2, last2);
    }
    return *this;
  }
  void swap(qlist<T> &x)
  {
    std::swap(node, x.node);
    std::swap(length, x.length);
  }
  iterator begin(void) { return node.next; }
  iterator end(void) { return &node; }
  bool empty(void) const { return length == 0; }
  size_t size(void) const { return length; }
  T &front(void) { return *begin(); }
  T &back(void) { return *(--end()); }
  const_iterator begin(void) const { return node.next; }
  const_iterator end(void) const { return &node; }
  const T&front(void) const { return *begin(); }
  const T&back(void) const { return *(--end()); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
  const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
  iterator insert(iterator p, const T& x)
  {
    datanode_t *tmp = (datanode_t*)qalloc_or_throw(sizeof(datanode_t));
    new (&(tmp->data)) T(x);
    linkin(p, tmp);
    return tmp;
  }
  T &insert(iterator p)
  {
    datanode_t *tmp = (datanode_t*)qalloc_or_throw(sizeof(datanode_t));
    new (&(tmp->data)) T();
    linkin(p, tmp);
    return tmp->data;
  }
  template <class it2> void insert(iterator p, it2 first, it2 last)
  {
    while ( first != last )
      insert(p, *first++);
  }
  void push_front(const T &x) { insert(begin(), x); }
  void push_back(const T &x) { insert(end(), x); }
  T &push_back(void) { return insert(end()); }
  void erase(iterator p)
  {
    p.cur->prev->next = p.cur->next;
    p.cur->next->prev = p.cur->prev;
    ((datanode_t*)p.cur)->data.~T();
    qfree(p.cur);
    --length;
  }
  void erase(iterator first, iterator last)
  {
    while ( first != last )
      erase(first++);
  }
  void clear(void) { erase(begin(), end()); }
  void pop_front(void) { erase(begin()); }
  void pop_back(void) { iterator tmp = end(); erase(--tmp); }
  bool operator==(const qlist<T> &x) const
  {
    if ( length != x.length )
      return false;
    const_iterator q=x.begin();
    for ( const_iterator p=begin(); p != end(); ++p,++q )
      if ( *p != *q )
        return false;
    return true;
  }
  bool operator!=(const qlist<T> &x) const { return !(*this == x); }
private:
  void linkin(iterator p, listnode_t *tmp)
  {
    tmp->next = p.cur;
    tmp->prev = p.cur->prev;
    p.cur->prev->next = tmp;
    p.cur->prev = tmp;
    ++length;
  }
};
typedef qvector<uval_t> uvalvec_t;
typedef qvector<sval_t> svalvec_t;
typedef qvector<ea_t> eavec_t;
typedef qvector<int> intvec_t;
typedef qvector<qstring> qstrvec_t;
typedef qvector<qwstring> qwstrvec_t;
typedef qvector<bool> boolvec_t;
template <class T> struct ida_movable_type<qvector<T> >   { typedef ida_true_type is_movable_type; };
template <class T> struct ida_movable_type<_qstring<T> >  { typedef ida_true_type is_movable_type; };
template <class T> struct ida_movable_type<qlist<T> >     { typedef ida_true_type is_movable_type; };
template <class T> struct ida_movable_type<qiterator<T> > { typedef ida_true_type is_movable_type; };
template <class T> T align_up(T val, int elsize)
{
  int mask = elsize - 1;
  val += mask;
  val &= ~mask;
  return val;
}
template <class T> T align_down(T val, int elsize)
{
  int mask = elsize - 1;
  val &= ~mask;
  return val;
}
struct hit_counter_t;
extern "C" void __stdcall reg_hit_counter(hit_counter_t *, bool do_reg);
extern "C"  hit_counter_t *__stdcall create_hit_counter(const char *name);
extern "C"  void __stdcall hit_counter_timer(hit_counter_t *, bool enable);
void print_all_counters(const char *fname);
struct hit_counter_t
{
  const char *name;
  int total, misses;
  uint64 elapsed;
  uint64 stamp;
  hit_counter_t(const char *_name)
    : name(_name), total(0), misses(0), elapsed(0)
    { reg_hit_counter(this, true); }
  virtual ~hit_counter_t(void) { reg_hit_counter(this, false); }
  virtual void print(void);
  void start(void) { hit_counter_timer(this, true); }
  void stop(void) { hit_counter_timer(this, false); }
};
class incrementer_t
{
  hit_counter_t &ctr;
public:
  incrementer_t(hit_counter_t &_ctr) : ctr(_ctr) { ctr.total++; ctr.start(); }
  ~incrementer_t(void) { ctr.stop(); }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  void failed(void) { ctr.misses++; }
};
bool base64_encode(qstring *output, const void *input, size_t size);
bool base64_decode(bytevec_t *output, const char *input, size_t size);
extern "C"  size_t __stdcall parse_command_line(const char *cmdline, qstrvec_t *args);
uchar wchar2char(wchar16_t wc);
extern "C"  bool __stdcall u2cstr(const wchar16_t *in, qstring *out, int nsyms=-1);
extern "C"  bool __stdcall c2ustr(const char *in, qwstring *out, int nsyms=-1);
extern "C"  int __stdcall utf8_unicode(const char *in, wchar16_t *out, size_t outsize);
extern "C"  bool __stdcall win_utf2idb(char *buf);
extern "C" void __stdcall char2oem(char *inout);
extern "C" void __stdcall oem2char(char *inout);
extern "C" bool __stdcall set_codepages(int acp, int oemcp);
extern "C" int __stdcall get_codepages(int* oemcp);
extern "C" int __stdcall convert_codepage(const void* in, int insize, void* out, size_t outsize, int incp, int outcp, int flags = 0);
extern "C" int __stdcall convert_encoding(const char *fromcode, const char *tocode, const bytevec_t *indata, bytevec_t *out, int flags = 0);
extern "C" __declspec(dllimport) char SubstChar;
typedef uint32 flags_t;
typedef ea_t tid_t;
typedef uint32 bgcolor_t;
struct launch_process_params_t
{
  size_t cb;
  int flags;
  const char *path;
  const char *args;
  ssize_t in_handle;
  ssize_t out_handle;
  ssize_t err_handle;
  launch_process_params_t(void)
    : cb(sizeof(*this)), flags(0), path(0), args(0),
      in_handle(-1), out_handle(-1),  err_handle(-1) {}
};
extern "C"  void *__stdcall launch_process(const launch_process_params_t &lpi, qstring *errbuf);
extern "C"  int __stdcall term_process(void *handle);
extern "C"  int __stdcall get_process_exit_code(void *handle, int *exit_code);
typedef int (__stdcall *qthread_cb_t)(void *ud);
typedef struct __qthread_t {} *qthread_t;
extern "C"  qthread_t __stdcall qthread_create(qthread_cb_t thread_cb, void *ud);
extern "C"  void __stdcall qthread_free(qthread_t q);
extern "C"  bool __stdcall qthread_join(qthread_t q);
extern "C"  bool __stdcall qthread_kill(qthread_t q);
extern "C"  qthread_t __stdcall qthread_self(void);
extern "C"  bool __stdcall qthread_same(qthread_t q);
extern "C"  bool __stdcall is_main_thread(void);
typedef struct __qsemaphore_t {} *qsemaphore_t;
extern "C"  qsemaphore_t __stdcall qsem_create(const char *name, int init_count);
extern "C"  bool __stdcall qsem_free(qsemaphore_t sem);
extern "C"  bool __stdcall qsem_post(qsemaphore_t sem);
extern "C"  bool __stdcall qsem_wait(qsemaphore_t sem, int timeout_ms);
typedef struct __qmutex_t {} *qmutex_t;
extern "C"  bool __stdcall qmutex_free(qmutex_t m);
extern "C"  qmutex_t __stdcall qmutex_create();
extern "C"  bool __stdcall qmutex_lock(qmutex_t m);
extern "C"  bool __stdcall qmutex_unlock(qmutex_t m);
typedef void *qhandle_t;
extern "C"  int __stdcall qpipe_create(qhandle_t handles[2]);
extern "C"  ssize_t __stdcall qpipe_read(qhandle_t handle, void *buf, size_t size);
extern "C"  ssize_t __stdcall qpipe_write(qhandle_t handle, const void *buf, size_t size);
extern "C"  int __stdcall qpipe_close(qhandle_t handle);
extern "C"  int __stdcall qwait_for_handles(
        const qhandle_t *handles,
        int n,
        uint32 write_bitmask,
        int *idx,
        int timeout_ms);
extern "C" char *__stdcall qsplitpath(char *path, char **dir, char **file);
extern "C" void *__stdcall init_process(const launch_process_params_t &lpi, qstring *errbuf);
extern "C" __declspec(noreturn) void __stdcall vinterr(const char *file, int line, const char *format, va_list va);
extern "C" error_t __declspec(dllimport) qerrno;
typedef uint32 ulong;
qstring &get_buffer_for_sysdir(void);
qstring &get_buffer_for_winerr(void);
void call_atexits(void);
#pragma pack(pop)
#pragma pack(push, 1)
enum filetype_t
{
  f_EXE_old,
  f_COM_old,
  f_BIN,
  f_DRV,
  f_WIN,
  f_HEX,
  f_MEX,
  f_LX,
  f_LE,
  f_NLM,
  f_COFF,
  f_PE,
  f_OMF,
  f_SREC,
  f_ZIP,
  f_OMFLIB,
  f_AR,
  f_LOADER,
  f_ELF,
  f_W32RUN,
  f_AOUT,
  f_PRC,
  f_EXE,
  f_COM,
  f_AIXAR,
  f_MACHO,
};
typedef uchar comp_t;
typedef uchar cm_t;
struct compiler_info_t
{
  comp_t id;
  cm_t cm;
  uchar size_i;
  uchar size_b;
  uchar size_e;
  uchar defalign;
  uchar size_s;
  uchar size_l;
  uchar size_ll;
};
enum storage_type_t
{
  STT_CUR = -1,
  STT_VA  = 0,
  STT_MM  = 1,
  STT_DBG = 2,
};
struct idainfo
{
  char          tag[3];
  ushort        version;
  char          procName[8];
  void set_proc_name(const char *name)
  {
    size_t len = strlen(name) + 1;
    memcpy(procName, name, ((len) < (sizeof(procName))? (len): (sizeof(procName))));
  }
  char *get_proc_name(char *buf) const
  {
    buf[0] = procName[0];
    buf[1] = procName[1];
    buf[2] = procName[2];
    buf[3] = procName[3];
    buf[4] = procName[4];
    buf[5] = procName[5];
    buf[6] = procName[6];
    buf[7] = procName[7];
    buf[8] = '\0';
    return buf;
  }
  uchar         lflags;
  bool is_32bit(void) const { return (lflags & 0x02) != 0; }
  bool is_64bit(void) const { return (lflags & 0x04) != 0; }
  bool is_snapshot(void) const { return (lflags & 0x10) != 0; }
  bool is_dll(void) const { return (lflags & 0x20) != 0; }
  uchar         demnames;
  uchar get_demname_form(void) const { return (uchar)(demnames & 3); }
  ushort        filetype;
  bool like_binary(void) const
  { return filetype == f_BIN
        || filetype == f_HEX
        || filetype == f_MEX
        || filetype == f_SREC; }
  uval_t        fcoresiz;
  uval_t        corestart;
  ushort        ostype;
  ushort        apptype;
  ea_t          startSP;
  ushort        af;
  ea_t          startIP;
  ea_t          beginEA;
  ea_t          minEA;
  ea_t          maxEA;
  ea_t          ominEA;
  ea_t          omaxEA;
  ea_t          lowoff;
  ea_t          highoff;
  uval_t        maxref;
  uchar         ASCIIbreak;
  uchar         wide_high_byte_first;
  uchar         indent;
  uchar         comment;
  uchar         xrefnum;
  uchar         s_entab;
  uchar         specsegs;
  uchar         s_void;
  uchar         s_reserved2;
  uchar         s_showauto;
  uchar         s_auto;
  uchar         s_limiter;
  uchar         s_null;
  uchar         s_genflags;
  bool use_allasm(void) const { return (s_genflags & 0x02) != 0; }
  bool loading_idc(void) const { return (s_genflags & 0x04) != 0; }
  uchar         s_showpref;
  uchar         s_prefseg;
  uchar         asmtype;
  uval_t        baseaddr;
  uchar         s_xrefflag;
  short         binSize;
  uchar         s_cmtflg;
  char          nametype;
  uchar         s_showbads;
  uchar         s_prefflag;
  uchar         s_packbase;
  uchar         asciiflags;
  uchar         listnames;
  char          ASCIIpref[16];
  uval_t        ASCIIsernum;
  char          ASCIIzeroes;
  uchar         graph_view;
  uchar         s_reserved5;
  uchar         tribyte_order;
  uchar         mf;
  uchar         s_org;
  uchar         s_assume;
  uchar         s_checkarg;
  sel_t         start_ss;
  sel_t         start_cs;
  ea_t          main;
  uint32         short_demnames;
  uint32         long_demnames;
  uval_t        datatypes;
  int32          strtype;
  ushort        af2;
  ushort        namelen;
  ushort        margin;
  ushort        lenxref;
  char          lprefix[16];
  uchar         lprefixlen;
  compiler_info_t cc;
  uint32        database_change_count;
  uchar         size_ldbl;
  uint32        appcall_options;
  uchar         reserved[55];
  void init(void);
  bool retrieve(void);
  bool read(const char *basename);
  void write(void);
};
extern "C" idainfo __declspec(dllimport) inf;
struct dual_text_options_t
{
  int mysize;
  uchar graph_view;
  uchar xrefnum;
  uchar s_showpref;
  uchar comment;
  uchar indent;
  uchar s_limiter;
  ushort margin;
  ushort binSize;
  dual_text_options_t(bool for_graph) { init(for_graph); }
  dual_text_options_t(const idainfo &inf) { copy_from_inf(inf); }
  void init(bool for_graph);
  void copy_to_inf(idainfo &inf) const;
  void copy_from_inf(const idainfo &inf);
  bool restore(bool for_graph);
  void save(bool for_graph) const;
};
struct text_options_t
{
  dual_text_options_t text;
  dual_text_options_t graph;
  text_options_t(void) : text(false), graph(true) {}
  void copy_to_inf(bool gv, idainfo &inf) { (gv ? graph : text).copy_to_inf(inf); }
  void copy_from_inf(const idainfo &inf) { (inf.graph_view ? graph : text).copy_from_inf(inf); }
};
extern "C" text_options_t __declspec(dllimport) dto;
 bool __stdcall showRepeatables(void) { return (inf.s_cmtflg & 0x01) != 0; }
 bool __stdcall showAllComments(void) { return (inf.s_cmtflg & 0x02) != 0; }
 bool __stdcall showComments(void)    { return (inf.s_cmtflg & 0x04)  == 0; }
 bool __stdcall should_trace_sp(void) { return (inf.af & 0x0800) != 0; }
 bool __stdcall should_create_stkvars(void) { return (inf.af & 0x0400) != 0; }
 int calc_default_idaplace_flags(void)
{
  int flags = 0;
  if ( inf.s_prefflag & 0x01 )
    flags |= 0x0040;
  return flags;
}
 ea_t __stdcall toEA(sel_t reg_cs,ea_t reg_ip)
{
  return (reg_cs<<4) + reg_ip;
}
extern "C" char *__stdcall idb2scr(char *name);
extern "C" char *__stdcall scr2idb(char *name);
 char *__stdcall ansi2idb(char *name)
{
  char2oem(name);
  return name;
}
extern "C" void __stdcall dto_copy_to_inf(const dual_text_options_t *, idainfo *inf);
extern "C" void __stdcall dto_copy_from_inf(dual_text_options_t *, const idainfo *inf);
extern "C" void __stdcall dto_init(dual_text_options_t *dt, bool for_graph);
 void dual_text_options_t::copy_to_inf(idainfo &inf) const { dto_copy_to_inf(this, &inf); }
 void dual_text_options_t::copy_from_inf(const idainfo &inf) { dto_copy_from_inf(this, &inf); }
 void dual_text_options_t::init(bool for_graph) { dto_init(this, for_graph); }
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
extern "C"  FILE *__stdcall qfopen(const char *file, const char *mode);
extern "C"  int   __stdcall qfread(FILE *fp, void *buf, size_t n);
extern "C"  int   __stdcall qfwrite(FILE *fp, const void *buf, size_t n);
extern "C"  int32 __stdcall qftell(FILE *fp);
extern "C"  int   __stdcall qfseek(FILE *fp, int32 offset, int whence);
extern "C"  int   __stdcall qfclose(FILE *fp);
extern "C"  int   __stdcall qflush(FILE *fp);
extern "C"             FILE *__stdcall qtmpfile(void);
extern "C"  int   __stdcall qrename(const char *oldfname, const char *newfname);
extern "C"             char *__stdcall qtmpnam(char *buf, size_t bufsize);
extern "C"  int __stdcall qfputc(int chr, FILE *fp);
extern "C"  int __stdcall qfgetc(FILE *fp);
extern "C"  char *__stdcall qfgets(char *s, size_t len, FILE *fp);
extern "C"  int __stdcall qfputs(const char *s, FILE *fp);
extern "C"   int __stdcall qvfprintf(FILE *fp, const char *format, va_list va);
extern "C"   int __stdcall qvprintf(const char *format, va_list va);
extern "C"   int __stdcall qveprintf(const char *format, va_list va);
extern "C"   int __stdcall qvfscanf(FILE *fp, const char *format, va_list va);
extern "C"  char *__stdcall qgets(char *line, size_t linesize);
int __stdcall qgetchar(void);
   int qfprintf(FILE *fp, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = qvfprintf(fp, format, va);
  ( va = (va_list)0 );
  return code;
}
   int qprintf(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = qvprintf(format, va);
  ( va = (va_list)0 );
  return code;
}
   int qeprintf(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = qveprintf(format, va);
  ( va = (va_list)0 );
  return code;
}
   int qfscanf(FILE *fp, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = qvfscanf(fp, format, va);
  ( va = (va_list)0 );
  return code;
}
extern "C"  int __stdcall freadbytes(FILE *fp,void *res,int size,int mostfirst);
extern "C"  int __stdcall fwritebytes(FILE *fp,const void *l,int size,int mostfirst);
 int fread2bytes(FILE *fp, int16 *res, bool mostfirst) { return freadbytes(fp, res, 2, mostfirst); }  int fwrite2bytes(FILE *fp, const int16 *res, bool mostfirst) { return fwritebytes(fp, res, 2, mostfirst); }
 int fread2bytes(FILE *fp, uint16 *res, bool mostfirst) { return freadbytes(fp, res, 2, mostfirst); }  int fwrite2bytes(FILE *fp, const uint16 *res, bool mostfirst) { return fwritebytes(fp, res, 2, mostfirst); }
 int fread4bytes(FILE *fp, int32 *res, bool mostfirst) { return freadbytes(fp, res, 4, mostfirst); }  int fwrite4bytes(FILE *fp, const int32 *res, bool mostfirst) { return fwritebytes(fp, res, 4, mostfirst); }
 int fread4bytes(FILE *fp, uint32 *res, bool mostfirst) { return freadbytes(fp, res, 4, mostfirst); }  int fwrite4bytes(FILE *fp, const uint32 *res, bool mostfirst) { return fwritebytes(fp, res, 4, mostfirst); }
 int fread8bytes(FILE *fp, longlong *res, bool mostfirst) { return freadbytes(fp, res, 8, mostfirst); }  int fwrite8bytes(FILE *fp, const longlong *res, bool mostfirst) { return fwritebytes(fp, res, 8, mostfirst); }
 int fread8bytes(FILE *fp, ulonglong *res, bool mostfirst) { return freadbytes(fp, res, 8, mostfirst); }  int fwrite8bytes(FILE *fp, const ulonglong *res, bool mostfirst) { return fwritebytes(fp, res, 8, mostfirst); }
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
const int BTREE_PAGE_SIZE = 8192;
const int MAXNAMESIZE = 512;
const int MAXSPECSIZE = 1024;
typedef uint32 nodeidx_t;
const char atag = 'A';
const char stag = 'S';
const char htag = 'H';
const char vtag = 'V';
const char ntag = 'N';
const char ltag = 'L';
class netnode;
extern "C" bool  __stdcall netnode_check           (netnode *, const char *name,size_t namlen,bool create);
extern "C" void  __stdcall netnode_kill            (netnode *);
extern "C" bool  __stdcall netnode_start           (netnode *);
extern "C" bool  __stdcall netnode_end             (netnode *);
extern "C" bool  __stdcall netnode_next            (netnode *);
extern "C" bool  __stdcall netnode_prev            (netnode *);
extern "C" ssize_t __stdcall netnode_name          (nodeidx_t num, char *buf, size_t bufsize);
extern "C" bool  __stdcall netnode_rename          (nodeidx_t num, const char *newname,size_t namlen);
extern "C" ssize_t __stdcall netnode_valobj        (nodeidx_t num, void *buf, size_t bufsize);
extern "C" ssize_t __stdcall netnode_valstr        (nodeidx_t num, char *buf, size_t bufsize);
extern "C" bool  __stdcall netnode_set             (nodeidx_t num, const void *value,size_t length);
extern "C" bool  __stdcall netnode_delvalue        (nodeidx_t num);
extern "C" nodeidx_t __stdcall netnode_altval      (nodeidx_t num, nodeidx_t alt,char tag);
extern "C" uchar __stdcall netnode_charval         (nodeidx_t num, nodeidx_t alt,char tag);
extern "C" nodeidx_t __stdcall netnode_altval_idx8 (nodeidx_t num, uchar alt,char tag);
extern "C" uchar __stdcall netnode_charval_idx8    (nodeidx_t num, uchar alt,char tag);
extern "C" ssize_t __stdcall netnode_supval        (nodeidx_t num, nodeidx_t alt,void *buf,size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_supstr        (nodeidx_t num, nodeidx_t alt,char *buf,size_t bufsize,char tag);
extern "C" bool  __stdcall netnode_supset          (nodeidx_t num, nodeidx_t alt,const void *value,size_t length,char tag);
extern "C" bool  __stdcall netnode_supdel          (nodeidx_t num, nodeidx_t alt,char tag);
extern "C" nodeidx_t __stdcall netnode_sup1st      (nodeidx_t num, char tag);
extern "C" nodeidx_t __stdcall netnode_supnxt      (nodeidx_t num, nodeidx_t cur,char tag);
extern "C" nodeidx_t __stdcall netnode_suplast     (nodeidx_t num, char tag);
extern "C" nodeidx_t __stdcall netnode_supprev     (nodeidx_t num, nodeidx_t cur,char tag);
extern "C" ssize_t __stdcall netnode_supval_idx8   (nodeidx_t num, uchar alt,void *buf,size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_supstr_idx8   (nodeidx_t num, uchar alt,char *buf,size_t bufsize,char tag);
extern "C" bool  __stdcall netnode_supset_idx8     (nodeidx_t num, uchar alt,const void *value,size_t length,char tag);
extern "C" bool  __stdcall netnode_supdel_idx8     (nodeidx_t num, uchar alt,char tag);
extern "C" nodeidx_t __stdcall netnode_sup1st_idx8 (nodeidx_t num, char tag);
extern "C" nodeidx_t __stdcall netnode_supnxt_idx8 (nodeidx_t num, uchar alt,char tag);
extern "C" nodeidx_t __stdcall netnode_suplast_idx8(nodeidx_t num, char tag);
extern "C" nodeidx_t __stdcall netnode_supprev_idx8(nodeidx_t num, uchar alt,char tag);
extern "C" bool  __stdcall netnode_supdel_all      (nodeidx_t num, char tag);
extern "C" int __stdcall netnode_supdel_range      (nodeidx_t num, nodeidx_t idx1, nodeidx_t idx2, char tag);
extern "C" int __stdcall netnode_supdel_range_idx8 (nodeidx_t num, nodeidx_t idx1, nodeidx_t idx2, char tag);
extern "C" ssize_t __stdcall netnode_hashval       (nodeidx_t num, const char *idx,void *buf, size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_hashstr       (nodeidx_t num, const char *idx,char *buf, size_t bufsize,char tag);
extern "C" nodeidx_t __stdcall netnode_hashval_long(nodeidx_t num, const char *idx,char tag);
extern "C" bool  __stdcall netnode_hashset         (nodeidx_t num, const char *idx,const void *value,size_t length,char tag);
extern "C" bool  __stdcall netnode_hashdel         (nodeidx_t num, const char *idx,char tag);
extern "C" ssize_t __stdcall netnode_hash1st       (nodeidx_t num, char *buf, size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_hashnxt       (nodeidx_t num, const char *idx,char *buf, size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_hashlast      (nodeidx_t num, char *buf, size_t bufsize,char tag);
extern "C" ssize_t __stdcall netnode_hashprev      (nodeidx_t num, const char *idx,char *buf, size_t bufsize,char tag);
extern "C" size_t __stdcall netnode_blobsize       (nodeidx_t num, nodeidx_t start,char tag);
extern "C" void *__stdcall netnode_getblob         (nodeidx_t num, void *buf, size_t *bufsize, nodeidx_t start, char tag);
extern "C" bool  __stdcall netnode_setblob         (nodeidx_t num, const void *buf, size_t size, nodeidx_t start, char tag);
extern "C" int   __stdcall netnode_delblob         (nodeidx_t num, nodeidx_t start,char tag);
extern "C" bool  __stdcall netnode_inited          (void);
extern "C" size_t __stdcall netnode_copy           (nodeidx_t num, nodeidx_t count, nodeidx_t target, bool move);
extern "C" size_t __stdcall netnode_altshift       (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
extern "C" size_t __stdcall netnode_charshift      (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
extern "C" size_t __stdcall netnode_supshift       (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
extern "C" void  __stdcall netnode_altadjust       (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, bool (__stdcall *should_skip)(nodeidx_t ea));
extern "C" bool  __stdcall netnode_exist           (const netnode &n);
class netnode
{
  friend class netlink;
  friend bool __stdcall netnode_check(netnode *, const char *name, size_t namlen, bool create);
  friend void __stdcall netnode_kill (netnode *);
  friend bool __stdcall netnode_start(netnode *);
  friend bool __stdcall netnode_end  (netnode *);
  friend bool __stdcall netnode_next (netnode *);
  friend bool __stdcall netnode_prev (netnode *);
  friend size_t __stdcall netnode_altshift (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
  friend size_t __stdcall netnode_charshift(nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
  friend size_t __stdcall netnode_supshift (nodeidx_t num, nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag);
public:
  netnode(void)                 {}
  netnode(nodeidx_t num)            { netnodenumber = num; }
  operator nodeidx_t() const        { return netnodenumber; }
  netnode(const char *name, size_t namlen=0, bool do_create=false)
  {
    netnode_check(this, name, namlen, do_create);
  }
  friend bool __stdcall netnode_exist(const netnode &n);
  friend bool __stdcall exist(const netnode &n)
        { return netnode_exist(n); }
  bool create(const char *name, size_t namlen=0)
       { return netnode_check(this, name, namlen, true); }
  bool create(void)            { return create((char *)0); }
  void kill(void)  { netnode_kill(this); }
  ssize_t name(char *buf, size_t bufsize) const
  {
    return netnode_name(*this, buf, bufsize);
  }
  bool rename(const char *newname, size_t namlen=0)
  {
    return netnode_rename(*this, newname, namlen);
  }
  ssize_t valobj(void *buf, size_t bufsize) const
  {
    return netnode_valobj(*this, buf, bufsize);
  }
  ssize_t valstr(char *buf, size_t bufsize) const
  {
    return netnode_valstr(*this, buf, bufsize);
  }
  bool set(const void *value, size_t length=0)
  {
    return netnode_set(*this, value, length);
  }
  bool delvalue(void)
  {
    return netnode_delvalue(*this);
  }
  bool set_long(nodeidx_t x) { return set(&x, sizeof(x)); }
  bool value_exists(void) const { return valobj(0, 0) >= 0; }
  nodeidx_t long_value(void) const
  {
    nodeidx_t v = 0;
    if ( valobj(&v, sizeof(v)) > 0 )
      return v;
    return nodeidx_t(-1);
  }
  nodeidx_t altval(nodeidx_t alt, char tag=atag) const
  {
    return netnode_altval(*this, alt, tag);
  }
  bool altset(nodeidx_t alt, nodeidx_t value, char tag=atag)
  {
    return supset(alt, &value, sizeof(value), tag);
  }
  bool altdel(nodeidx_t alt, char tag=atag)
  {
    return supdel(alt, tag);
  }
  nodeidx_t alt1st(char tag=atag) const
  {
    return sup1st(tag);
  }
  nodeidx_t altnxt(nodeidx_t cur, char tag=atag) const
  {
    return supnxt(cur, tag);
  }
  nodeidx_t altlast(char tag=atag) const
  {
    return suplast(tag);
  }
  nodeidx_t altprev(nodeidx_t cur, char tag=atag) const
  {
    return supprev(cur, tag);
  }
  size_t altshift(nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag=atag)
  {
    return netnode_altshift(*this, from, to, size, tag);
  }
  void altadjust(nodeidx_t from, nodeidx_t to, nodeidx_t size, bool (__stdcall *should_skip)(nodeidx_t ea)=0)
  {
    netnode_altadjust(*this, from, to, size, should_skip);
  }
  uchar charval(nodeidx_t alt, char tag) const      { return netnode_charval(*this, alt, tag); }
  bool charset(nodeidx_t alt, uchar val, char tag)  { return supset(alt, &val, sizeof(val), tag); }
  bool chardel(nodeidx_t alt, char tag)             { return supdel(alt, tag); }
  nodeidx_t char1st(char tag) const                 { return sup1st(tag); }
  nodeidx_t charnxt(nodeidx_t cur, char tag) const  { return supnxt(cur, tag); }
  nodeidx_t charlast(char tag) const                { return suplast(tag); }
  nodeidx_t charprev(nodeidx_t cur, char tag) const { return supprev(cur, tag); }
  size_t charshift(nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag)
    { return netnode_charshift(*this, from, to, size, tag); }
  nodeidx_t altval_idx8(uchar alt, char tag) const   { return netnode_altval_idx8(*this, alt, tag); }
  bool altset_idx8(uchar alt, nodeidx_t val, char tag){ return supset_idx8(alt, &val, sizeof(val), tag); }
  bool altdel_idx8(uchar alt, char tag)              { return supdel_idx8(alt, tag); }
  nodeidx_t alt1st_idx8(char tag) const              { return sup1st_idx8(tag); }
  nodeidx_t altnxt_idx8(uchar cur, char tag) const   { return supnxt_idx8(cur, tag); }
  nodeidx_t altlast_idx8(char tag) const             { return suplast_idx8(tag); }
  nodeidx_t altprev_idx8(uchar cur, char tag) const  { return supprev_idx8(cur, tag); }
  uchar charval_idx8(uchar alt, char tag) const     { return netnode_charval_idx8(*this, alt, tag); }
  bool charset_idx8(uchar alt, uchar val, char tag) { return supset_idx8(alt, &val, sizeof(val), tag); }
  bool chardel_idx8(uchar alt, char tag)            { return supdel_idx8(alt, tag); }
  nodeidx_t char1st_idx8(char tag) const            { return sup1st_idx8(tag); }
  nodeidx_t charnxt_idx8(uchar cur, char tag) const { return supnxt_idx8(cur, tag); }
  nodeidx_t charlast_idx8(char tag) const           { return suplast_idx8(tag); }
  nodeidx_t charprev_idx8(uchar cur, char tag) const{ return supprev_idx8(cur, tag); }
  bool altdel(void)
  {
    return supdel_all(atag);
  }
  bool altdel_all(char tag)
  {
    return supdel_all(tag);
  }
  ssize_t supval(nodeidx_t alt, void *buf, size_t bufsize, char tag=stag) const
        { return netnode_supval(*this, alt, buf, bufsize, tag); }
  ssize_t supstr(nodeidx_t alt, char *buf, size_t bufsize, char tag=stag) const
        { return netnode_supstr(*this, alt, buf, bufsize, tag); }
  bool supset(nodeidx_t alt, const void *value, size_t length=0, char tag=stag)
        { return netnode_supset(*this, alt, value, length, tag); }
  bool supdel(nodeidx_t alt, char tag=stag)
        { return netnode_supdel(*this, alt, tag); }
  nodeidx_t sup1st(char tag=stag) const
        { return netnode_sup1st(*this, tag); }
  nodeidx_t supnxt(nodeidx_t cur, char tag=stag) const
        { return netnode_supnxt(*this, cur, tag); }
  nodeidx_t suplast(char tag=stag) const
        { return netnode_suplast(*this, tag); }
  nodeidx_t supprev(nodeidx_t cur, char tag=stag) const
        { return netnode_supprev(*this, cur, tag); }
  size_t supshift(nodeidx_t from, nodeidx_t to, nodeidx_t size, char tag=stag)
    { return netnode_supshift(*this, from, to, size, tag); }
  ssize_t   supval_idx8(uchar alt, void *buf, size_t bufsize, char tag) const { return netnode_supval_idx8(*this, alt, buf, bufsize, tag); }
  ssize_t   supstr_idx8(uchar alt, char *buf, size_t bufsize, char tag) const { return netnode_supstr_idx8(*this, alt, buf, bufsize, tag); }
  bool      supset_idx8(uchar alt, const void *value, size_t length, char tag) { return netnode_supset_idx8(*this, alt, value, length, tag); }
  bool      supdel_idx8(uchar alt, char tag)        { return netnode_supdel_idx8(*this, alt, tag); }
  nodeidx_t sup1st_idx8(char tag) const             { return netnode_sup1st_idx8(*this, tag); }
  nodeidx_t supnxt_idx8(uchar alt, char tag) const  { return netnode_supnxt_idx8(*this, alt, tag); }
  nodeidx_t suplast_idx8(char tag) const            { return netnode_suplast_idx8(*this, tag); }
  nodeidx_t supprev_idx8(uchar alt, char tag) const { return netnode_supprev_idx8(*this, alt, tag); }
  bool   supdel(void)
  {
    return supdel_all(stag);
  }
  bool supdel_all(char tag)
  {
    return netnode_supdel_all(*this, tag);
  }
  int supdel_range(nodeidx_t idx1, nodeidx_t idx2, char tag)
  {
    return netnode_supdel_range(*this, idx1, idx2, tag);
  }
  int supdel_range_idx8(uchar idx1, uchar idx2, char tag)
  {
    return netnode_supdel_range_idx8(*this, idx1, idx2, tag);
  }
  ssize_t hashval(const char *idx, void *buf, size_t bufsize, char tag=htag) const
        { return netnode_hashval(*this, idx, buf, bufsize, tag); }
  ssize_t hashstr(const char *idx, char *buf, size_t bufsize, char tag=htag) const
        { return netnode_hashstr(*this, idx, buf, bufsize, tag); }
  nodeidx_t hashval_long(const char *idx, char tag=htag) const
        { return netnode_hashval_long(*this, idx, tag); }
  bool hashset(const char *idx, const void *value, size_t length=0, char tag=htag)
        { return netnode_hashset(*this, idx, value, length, tag); }
  bool hashset(const char *idx, nodeidx_t value, char tag=htag)
        { return hashset(idx, &value, sizeof(value), tag); }
  bool hashdel(const char *idx, char tag=htag)
        { return netnode_hashdel(*this, idx, tag); }
  ssize_t hash1st(char *buf, size_t bufsize, char tag=htag) const
        { return netnode_hash1st(*this, buf, bufsize, tag); }
  ssize_t hashnxt(const char *idx, char *buf, size_t bufsize, char tag=htag) const
        { return netnode_hashnxt(*this, idx, buf, bufsize, tag); }
  ssize_t hashlast(char *buf, size_t bufsize, char tag=htag) const
        { return netnode_hashlast(*this, buf, bufsize, tag); }
  ssize_t hashprev(const char *idx, char *buf, size_t bufsize, char tag=htag) const
        { return netnode_hashprev(*this, idx, buf, bufsize, tag); }
  bool hashdel_all(char tag=htag)
  {
    return supdel_all(tag);
  }
  size_t blobsize(nodeidx_t start, char tag)
        { return netnode_blobsize(*this, start, tag); }
  void *getblob(void *buf,
                size_t *bufsize,
                nodeidx_t start,
                char tag)
        { return netnode_getblob(*this, buf, bufsize, start, tag); }
  bool setblob(const void *buf,
              size_t size,
              nodeidx_t start,
              char tag)
        { return netnode_setblob(*this, buf, size, start, tag); }
  int delblob(nodeidx_t start, char tag)
        { return netnode_delblob(*this, start, tag); }
  int   link(netnode to, netlink linktype, const char *linkspec);
  void  unlink(netnode to, netlink linktype);
  ssize_t linkspec(netnode to, char *buf, size_t bufsize, netlink linktype) const;
  bool start(void)
  {
    return netnode_start(this);
  }
  bool end(void)
  {
    return netnode_end(this);
  }
  bool next(void)
  {
    return netnode_next(this);
  }
  bool prev(void)
  {
    return netnode_prev(this);
  }
  size_t copyto(netnode target, nodeidx_t count=1) { return netnode_copy(netnodenumber, count, target.netnodenumber, false); }
  size_t moveto(netnode target, nodeidx_t count=1) { return netnode_copy(netnodenumber, count, target.netnodenumber, true); }
  bool operator==(netnode &n) const { return netnodenumber == n.netnodenumber; }
  bool operator!=(netnode &n) const { return netnodenumber != n.netnodenumber; }
  bool operator==(nodeidx_t x) const { return netnodenumber == x; }
  bool operator!=(nodeidx_t x) const { return netnodenumber != x; }
  static bool truncate_zero_pages(const char *fname);
  static bool append_zero_pages(const char *fname);
  static bool createbase(const char *fname, nodeidx_t initial_nodeid=0);
  static int  checkbase(const char *fname);
  static void set_close_flag(bool closeflag);
  static nodeidx_t reserve_nodes(nodeidx_t n);
  static void validate(const char *badbase, const char *newbase, void (*cb)(uint32));
  static void upgrade(const char *oldbase, const char *newbase, void (*cb)(uint32));
  static void compress(const char *oldbase, const char *newbase, void (*cb)(uint32));
  static bool inited(void) { return netnode_inited(); }
  static void init(const char *file, size_t cachesize, bool can_modify);
  static void flush(void);
  static void term(void);
  static void killbase(nodeidx_t iniNumber=0);
  static int  getdrive(void);
  static int  getgraph(void)
               { return atag; }
  static int  registerbase(const char *filename, size_t cachesize, bool writeFlag=true);
  static bool setbase(int drive, int graph=atag);
private:
  nodeidx_t netnodenumber;
  bool check(const char *oldname, size_t namlen=0)
        { return netnode_check(this, oldname, namlen, false); }
  qstring qsupval(nodeidx_t ea, char tag) const;
  void qsupset(nodeidx_t ea, const qstring &x, char tag);
};
class netlink
{
  friend class netnode;
  friend void select(const netlink *n);
  nodeidx_t linknumber;
  int check(const char *oldname);
public:
  netlink(void) {}
  netlink(const char *name, bool do_create=false)
  {
    if ( do_create )
      create(name);
    else
      check(name);
  }
  friend bool exist(const netlink &L)   { return L.linknumber != 0; }
  bool create(const char *name);
  ssize_t name(char *buf, size_t bufsize) const;
  bool rename(const char *newname);
  bool start(void);
  bool next(void);
  netnode firstlink(netnode from) const;
  netnode nextlink(netnode from, netnode current) const;
  bool operator==(netlink &n) const { return linknumber == n.linknumber; }
  bool operator!=(netlink &n) const { return linknumber != n.linknumber; }
};
extern "C" netnode __declspec(dllimport) RootNode;
extern void (__stdcall *netErrorHandler)(const char *message);
int netnode_key_count(void);
int for_all_supvals(nodeidx_t start,
                    int callback(nodeidx_t node,
                                 uchar tag,
                                 nodeidx_t idx,
                                 const uchar *data,
                                 size_t datlen,
                                 void *ud),
                    void *ud);
#pragma pack(pop)
extern netnode nmSerEA;
extern netnode nmSerN;
extern size_t maxSerialName;
extern "C" netnode __declspec(dllimport) net_patch;
extern "C" netnode __declspec(dllimport) import_node;
 uint32 get_wide_value(ea_t ea) { uint32 x; return netnode(ea).supval(uval_t(-1), &x, sizeof(x), atag) > 0 ? uint32(x-1) : uint32(-1); }  void set_wide_value(ea_t ea,uint32 x) { x++; netnode(ea).supset(uval_t(-1), &x, sizeof(x), atag); }  void del_wide_value(ea_t ea) { netnode(ea).supdel(uval_t(-1), atag); }
 ea_t get_strid(ea_t ea) { ea_t x; return netnode(ea).supval(3, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void _set_strid(ea_t ea,ea_t x) { x++; netnode(ea).supset(3, &x, sizeof(x), atag); }  void _del_strid(ea_t ea) { netnode(ea).supdel(3, atag); }
void set_strid(ea_t ea, tid_t tid);
void del_strid(ea_t ea);
struct xrefpos_t
{
  ea_t ea;
  char type;
};
 ssize_t get_xrefpos(ea_t ea, xrefpos_t *buf, size_t bufsize) { return netnode(ea).supval(27, buf, bufsize); }  void set_xrefpos(ea_t ea,const xrefpos_t *oi) { netnode(ea).supset(27,oi,sizeof(xrefpos_t)); }  void del_xrefpos(ea_t ea) { netnode(ea).supdel(27); }
 void  set_aflags0(ea_t ea, uint32 flags){ netnode(ea).altset(8,flags); }
 uint32 get_aflags0(ea_t ea)             { return flags_t(netnode(ea).altval(8)); }
 void  del_aflags0(ea_t ea)              { netnode(ea).altdel(8); }
extern "C" void   __stdcall set_aflags(ea_t ea, uint32 flags);
extern "C" void   __stdcall set_abits(ea_t ea,uint32 bits);
extern "C" void   __stdcall clr_abits(ea_t ea,uint32 bits);
extern "C" uint32 __stdcall get_aflags(ea_t ea);
extern "C" void   __stdcall del_aflags(ea_t ea);
 bool is_hidden_item(ea_t ea) { return (get_aflags(ea) & 0x00000010L) != 0; }  void hide_item(ea_t ea) { set_abits(ea, 0x00000010L); }  void unhide_item(ea_t ea) { clr_abits(ea, 0x00000010L); }
 bool is_hidden_border(ea_t ea) { return (get_aflags(ea) & 0x00000040L) != 0; }  void hide_border(ea_t ea) { set_abits(ea, 0x00000040L); }  void unhide_border(ea_t ea) { clr_abits(ea, 0x00000040L); }
 bool is_zstroff(ea_t ea) { return (get_aflags(ea) & 0x00000080L) != 0; }  void set_zstroff(ea_t ea) { set_abits(ea, 0x00000080L); }  void clr_zstroff(ea_t ea) { clr_abits(ea, 0x00000080L); }
 bool is__bnot0(ea_t ea) { return (get_aflags(ea) & 0x00000100L) != 0; }  void set__bnot0(ea_t ea) { set_abits(ea, 0x00000100L); }  void clr__bnot0(ea_t ea) { clr_abits(ea, 0x00000100L); }
 bool is__bnot1(ea_t ea) { return (get_aflags(ea) & 0x00000200L) != 0; }  void set__bnot1(ea_t ea) { set_abits(ea, 0x00000200L); }  void clr__bnot1(ea_t ea) { clr_abits(ea, 0x00000200L); }
 bool is_libitem(ea_t ea) { return (get_aflags(ea) & 0x00000400L) != 0; }  void set_libitem(ea_t ea) { set_abits(ea, 0x00000400L); }  void clr_libitem(ea_t ea) { clr_abits(ea, 0x00000400L); }
 bool has_ti(ea_t ea) { return (get_aflags(ea) & 0x00000800L) != 0; }  void set_has_ti(ea_t ea) { set_abits(ea, 0x00000800L); }  void clr_has_ti(ea_t ea) { clr_abits(ea, 0x00000800L); }
 bool has_ti0(ea_t ea) { return (get_aflags(ea) & 0x00001000L) != 0; }  void set_has_ti0(ea_t ea) { set_abits(ea, 0x00001000L); }  void clr_has_ti0(ea_t ea) { clr_abits(ea, 0x00001000L); }
 bool has_ti1(ea_t ea) { return (get_aflags(ea) & 0x00002000L) != 0; }  void set_has_ti1(ea_t ea) { set_abits(ea, 0x00002000L); }  void clr_has_ti1(ea_t ea) { clr_abits(ea, 0x00002000L); }
 bool has_lname(ea_t ea) { return (get_aflags(ea) & 0x00004000L) != 0; }  void set_has_lname(ea_t ea) { set_abits(ea, 0x00004000L); }  void clr_has_lname(ea_t ea) { clr_abits(ea, 0x00004000L); }
 bool is_tilcmt(ea_t ea) { return (get_aflags(ea) & 0x00008000L) != 0; }  void set_tilcmt(ea_t ea) { set_abits(ea, 0x00008000L); }  void clr_tilcmt(ea_t ea) { clr_abits(ea, 0x00008000L); }
 bool is_usersp(ea_t ea) { return (get_aflags(ea) & 0x00000002L) != 0; }  void set_usersp(ea_t ea) { set_abits(ea, 0x00000002L); }  void clr_usersp(ea_t ea) { clr_abits(ea, 0x00000002L); }
 bool is_lzero0(ea_t ea) { return (get_aflags(ea) & 0x00010000L) != 0; }  void set_lzero0(ea_t ea) { set_abits(ea, 0x00010000L); }  void clr_lzero0(ea_t ea) { clr_abits(ea, 0x00010000L); }
 bool is_lzero1(ea_t ea) { return (get_aflags(ea) & 0x00020000L) != 0; }  void set_lzero1(ea_t ea) { set_abits(ea, 0x00020000L); }  void clr_lzero1(ea_t ea) { clr_abits(ea, 0x00020000L); }
 bool is_colored_item(ea_t ea) { return (get_aflags(ea) & 0x00040000L) != 0; }  void set_colored_item(ea_t ea) { set_abits(ea, 0x00040000L); }  void clr_colored_item(ea_t ea) { clr_abits(ea, 0x00040000L); }
 bool is_terse_struc(ea_t ea) { return (get_aflags(ea) & 0x00080000L) != 0; }  void set_terse_struc(ea_t ea) { set_abits(ea, 0x00080000L); }  void clr_terse_struc(ea_t ea) { clr_abits(ea, 0x00080000L); }
 bool is__invsign0(ea_t ea) { return (get_aflags(ea) & 0x00100000L) != 0; }  void set__invsign0(ea_t ea) { set_abits(ea, 0x00100000L); }  void clr__invsign0(ea_t ea) { clr_abits(ea, 0x00100000L); }
 bool is__invsign1(ea_t ea) { return (get_aflags(ea) & 0x00200000L) != 0; }  void set__invsign1(ea_t ea) { set_abits(ea, 0x00200000L); }  void clr__invsign1(ea_t ea) { clr_abits(ea, 0x00200000L); }
 bool is_noret(ea_t ea) { return (get_aflags(ea) & 0x00400000L) != 0; }  void set_noret(ea_t ea) { set_abits(ea, 0x00400000L); }  void clr_noret(ea_t ea) { clr_abits(ea, 0x00400000L); }
 bool is_fixed_spd(ea_t ea) { return (get_aflags(ea) & 0x00800000L) != 0; }  void set_fixed_spd(ea_t ea) { set_abits(ea, 0x00800000L); }  void clr_fixed_spd(ea_t ea) { clr_abits(ea, 0x00800000L); }
 bool is_align_flow(ea_t ea) { return (get_aflags(ea) & 0x01000000L) != 0; }  void set_align_flow(ea_t ea) { set_abits(ea, 0x01000000L); }  void clr_align_flow(ea_t ea) { clr_abits(ea, 0x01000000L); }
 bool is_userti(ea_t ea) { return (get_aflags(ea) & 0x02000000L) != 0; }  void set_userti(ea_t ea) { set_abits(ea, 0x02000000L); }  void clr_userti(ea_t ea) { clr_abits(ea, 0x02000000L); }
 bool is_retfp(ea_t ea) { return (get_aflags(ea) & 0x04000000L) != 0; }  void set_retfp(ea_t ea) { set_abits(ea, 0x04000000L); }  void clr_retfp(ea_t ea) { clr_abits(ea, 0x04000000L); }
 void set_visible_item(ea_t ea, bool visible)
{
  if ( visible )
     unhide_item(ea);
  else
      hide_item(ea);
}
 bool is_visible_item(ea_t ea) { return !is_hidden_item(ea); }
 bool is_finally_visible_item(ea_t ea)
 { return (inf.s_cmtflg & 0x20) != 0 || is_visible_item(ea); }
 ea_t get_linnum0(ea_t ea) { ea_t x; return netnode(ea).supval(9, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_linnum0(ea_t ea,ea_t x) { x++; netnode(ea).supset(9, &x, sizeof(x), atag); }  void del_linnum0(ea_t ea) { netnode(ea).supdel(9, atag); }
extern "C" void   __stdcall set_source_linnum(ea_t ea, uval_t lnnum);
extern "C" uval_t __stdcall get_source_linnum(ea_t ea);
extern "C" void   __stdcall del_source_linnum(ea_t ea);
 ea_t get_absbase(ea_t ea) { ea_t x; return netnode(ea).supval(10, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_absbase(ea_t ea,ea_t x) { x++; netnode(ea).supset(10, &x, sizeof(x), atag); }  void del_absbase(ea_t ea) { netnode(ea).supdel(10, atag); }
 ea_t get_enum_id0(ea_t ea) { ea_t x; return netnode(ea).supval(11, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_enum_id0(ea_t ea,ea_t x) { x++; netnode(ea).supset(11, &x, sizeof(x), atag); }  void del_enum_id0(ea_t ea) { netnode(ea).supdel(11, atag); }
 ea_t get_enum_id1(ea_t ea) { ea_t x; return netnode(ea).supval(12, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_enum_id1(ea_t ea,ea_t x) { x++; netnode(ea).supset(12, &x, sizeof(x), atag); }  void del_enum_id1(ea_t ea) { netnode(ea).supdel(12, atag); }
 ea_t get_ind_purged(ea_t ea) { ea_t x; return netnode(ea).supval(15, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_ind_purged(ea_t ea,ea_t x) { x++; netnode(ea).supset(15, &x, sizeof(x), atag); }  void del_ind_purged(ea_t ea) { netnode(ea).supdel(15, atag); }
 uint32 get_str_type(ea_t ea) { uint32 x; return netnode(ea).supval(16, &x, sizeof(x), atag) > 0 ? uint32(x-1) : uint32(-1); }  void set_str_type(ea_t ea,uint32 x) { x++; netnode(ea).supset(16, &x, sizeof(x), atag); }  void del_str_type(ea_t ea) { netnode(ea).supdel(16, atag); }
 char __stdcall get_str_type_code(uval_t strtype) { return char(strtype); }
 char get_str_term1(int32 strtype) { return char(strtype>>8); }
 char get_str_term2(int32 strtype) { return char(strtype>>16); }
 bool is_unicode(int32 strtype)
{
  char code = get_str_type_code(strtype);
  return code == 3
      || code == 5
      || code == 6;
}
 bool is_pascal(int32 strtype)
{
  char code = get_str_type_code(strtype);
  return code == 1
      || code == 2
      || code >= 4;
}
 uchar __stdcall get_str_encoding_idx(int32 strtype) { return uchar(strtype>>24); }
 uint32 get_alignment(ea_t ea) { uint32 x; return netnode(ea).supval(17, &x, sizeof(x), atag) > 0 ? uint32(x-1) : uint32(-1); }  void set_alignment(ea_t ea,uint32 x) { x++; netnode(ea).supset(17, &x, sizeof(x), atag); }  void del_alignment(ea_t ea) { netnode(ea).supdel(17, atag); }
 uint32 _get_item_color(ea_t ea) { uint32 x; return netnode(ea).supval(20, &x, sizeof(x), atag) > 0 ? uint32(x-1) : uint32(-1); }  void _set_item_color(ea_t ea,uint32 x) { x++; netnode(ea).supset(20, &x, sizeof(x), atag); }  void _del_item_color(ea_t ea) { netnode(ea).supdel(20, atag); }
extern "C" void      __stdcall set_item_color(ea_t ea, bgcolor_t color);
extern "C" bgcolor_t __stdcall get_item_color(ea_t ea);
extern "C" void      __stdcall del_item_color(ea_t ea);
 ssize_t get_nalt_cmt(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(0, buf, bufsize); }  void set_nalt_cmt(ea_t ea,const char *oi) { netnode(ea).supset(0,oi); }  void del_nalt_cmt(ea_t ea) { netnode(ea).supdel(0); }
 ssize_t get_nalt_rptcmt(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(1, buf, bufsize); }  void set_nalt_rptcmt(ea_t ea,const char *oi) { netnode(ea).supset(1,oi); }  void del_nalt_rptcmt(ea_t ea) { netnode(ea).supdel(1); }
 ssize_t get_fop1(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(2, buf, bufsize); }  void set_fop1(ea_t ea,const char *oi) { netnode(ea).supset(2,oi); }  void del_fop1(ea_t ea) { netnode(ea).supdel(2); }
 ssize_t get_fop2(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(3, buf, bufsize); }  void set_fop2(ea_t ea,const char *oi) { netnode(ea).supset(3,oi); }  void del_fop2(ea_t ea) { netnode(ea).supdel(3); }
 ssize_t get_fop3(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(7, buf, bufsize); }  void set_fop3(ea_t ea,const char *oi) { netnode(ea).supset(7,oi); }  void del_fop3(ea_t ea) { netnode(ea).supdel(7); }
 ssize_t get_fop4(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(18, buf, bufsize); }  void set_fop4(ea_t ea,const char *oi) { netnode(ea).supset(18,oi); }  void del_fop4(ea_t ea) { netnode(ea).supdel(18); }
 ssize_t get_fop5(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(19, buf, bufsize); }  void set_fop5(ea_t ea,const char *oi) { netnode(ea).supset(19,oi); }  void del_fop5(ea_t ea) { netnode(ea).supdel(19); }
 ssize_t get_fop6(ea_t ea, char *buf, size_t bufsize) { return netnode(ea).supstr(20, buf, bufsize); }  void set_fop6(ea_t ea,const char *oi) { netnode(ea).supset(20,oi); }  void del_fop6(ea_t ea) { netnode(ea).supdel(20); }
 char *get_manual_insn0(ea_t ea,char *buf,size_t *bufsize) { return (char *)netnode(ea).getblob(buf,bufsize,0x2000,stag); }  void set_manual_insn0(ea_t ea,const char *oi,size_t size) { netnode(ea).setblob(oi,size,0x2000,stag); }  void del_manual_insn0(ea_t ea) { netnode(ea).delblob(0x2000,stag); }
 uchar *get_graph_groups0(ea_t ea,uchar *buf,size_t *bufsize) { return (uchar *)netnode(ea).getblob(buf,bufsize,0x8000,stag); }  void set_graph_groups0(ea_t ea,const uchar *oi,size_t size) { netnode(ea).setblob(oi,size,0x8000,stag); }  void del_graph_groups0(ea_t ea) { netnode(ea).delblob(0x8000,stag); }
struct jumptable_info_t
{
  ea_t table;
  asize_t size;
};
 ssize_t get_jumptable_info(ea_t ea, jumptable_info_t *buf, size_t bufsize) { return netnode(ea).supval(4, buf, bufsize); }  void set_jumptable_info(ea_t ea,const jumptable_info_t *oi) { netnode(ea).supset(4,oi,sizeof(jumptable_info_t)); }  void del_jumptable_info(ea_t ea) { netnode(ea).supdel(4); }
struct array_parameters_t
{
  int32 flags;
  int32 lineitems;
  int32 alignment;
};
 ssize_t get_array_parameters(ea_t ea, array_parameters_t *buf, size_t bufsize) { return netnode(ea).supval(5, buf, bufsize); }  void set_array_parameters(ea_t ea,const array_parameters_t *oi) { netnode(ea).supset(5,oi,sizeof(array_parameters_t)); }  void del_array_parameters(ea_t ea) { netnode(ea).supdel(5); }
struct switch_info_t
{
  ushort flags;
  int get_shift(void) const { return ((flags & 0x180) >> 7); }
  void set_shift(int shift)
  {
    flags &= ~0x180;
    flags = ushort(flags | ((shift & 3) << 7));
  }
  int get_jtable_element_size(void) const
  {
    int code = flags & (0x04|0x400);
    if ( code == 0 )
      return 2;
    if ( code == 0x04 )
      return 4;
    if ( code == 0x400 )
      return 1;
    return 8;
  }
  void set_jtable_element_size(int size)
  {
    flags &= ~0x04|0x400;
    if ( size == 4 ) { flags |= 0x04; return; }
    if ( size == 1 ) { flags |= 0x400; return; }
    if ( size == 8 ) { flags |= 0x04|0x400; return; }
    if ( size != 2 ) abort();
  }
  int get_vtable_element_size(void) const
  {
    int code = flags & (0x02|0x800);
    if ( code == 0 )
      return 2;
    if ( code == 0x02 )
      return 4;
    if ( code == 0x800 )
      return 1;
    return 8;
  }
  void set_vtable_element_size(int size)
  {
    flags &= ~0x02|0x800;
    if ( size == 4 ) { flags |= 0x02; return; }
    if ( size == 1 ) { flags |= 0x800; return; }
    if ( size == 8 ) { flags |= 0x02|0x800; return; }
    if ( size != 2 ) abort();
  }
  ushort ncases;
  ea_t jumps;
  union
  {
    ea_t values;
    uval_t lowcase;
  };
  ea_t defjump;
  ea_t startea;
};
struct switch_info_ex_t : public switch_info_t
{
  size_t cb;
  int flags2;
  int jcases;
  bool is_indirect(void)  const { return (flags & 0x8000) != 0 && (flags2 & 0x0001) != 0; }
  bool is_subtract(void)  const { return (flags & 0x8000) != 0 && (flags2 & 0x0002) != 0; }
  bool is_nolowcase(void) const { return (flags & 0x8000) != 0 && (flags2 & 0x0004) != 0; }
  int get_jtable_size(void) const { return is_indirect() ? jcases : ncases; }
  sval_t ind_lowcase;
  sval_t get_lowcase(void) const { return is_indirect() ? ind_lowcase : lowcase; }
  ea_t elbase;
  int regnum;
  char regdtyp;
  void set_expr(int r, char dt) { regnum = r; regdtyp = dt; }
  uval_t custom;
  switch_info_ex_t(void) { clear(); }
  void clear(void)
  {
    memset(this, 0, sizeof(switch_info_ex_t));
    cb = sizeof(switch_info_ex_t);
    flags = 0x8000;
    jumps = ea_t(-1);
    defjump = ea_t(-1);
    startea = ea_t(-1);
    regnum = -1;
  }
};
 ssize_t get_switch_info_ex(ea_t ea, switch_info_ex_t *buf, size_t bufsize) { return netnode(ea).supval(8, buf, bufsize); }  void set_switch_info_ex(ea_t ea,const switch_info_ex_t *oi) { netnode(ea).supset(8,oi,sizeof(switch_info_ex_t)); }  void del_switch_info_ex(ea_t ea) { netnode(ea).supdel(8); }
 ea_t get_switch_parent(ea_t ea) { ea_t x; return netnode(ea).supval(1, &x, sizeof(x), atag) > 0 ? ea_t(x-1) : ea_t(-1); }  void set_switch_parent(ea_t ea,ea_t x) { x++; netnode(ea).supset(1, &x, sizeof(x), atag); }  void del_switch_parent(ea_t ea) { netnode(ea).supdel(1, atag); }
struct custom_data_type_ids_t
{
  int16 dtid;
  int16 fids[6];
};
extern "C" int  __stdcall get_custom_data_type_ids(ea_t ea, custom_data_type_ids_t *cdis, size_t bufsize);
extern "C" void __stdcall set_custom_data_type_ids(ea_t ea, const custom_data_type_ids_t *cdis);
 void __stdcall del_custom_data_type_ids(ea_t ea) { netnode(ea).supdel(28); }
typedef uchar reftype_t;
const reftype_t
  REF_OFF8   = 0,
  REF_OFF16  = 1,
  REF_OFF32  = 2,
  REF_LOW8   = 3,
  REF_LOW16  = 4,
  REF_HIGH8  = 5,
  REF_HIGH16 = 6,
  REF_VHIGH  = 7,
  REF_VLOW   = 8,
  REF_OFF64  = 9,
  REF_LAST = REF_OFF64;
extern "C" reftype_t __stdcall get_reftype_by_size(size_t size);
struct refinfo_t
{
  ea_t    target;
  ea_t    base;
  adiff_t tdelta;
  uint32  flags;
  reftype_t type(void) const { return reftype_t(flags & 0x000F); }
  bool no_base_xref(void) const { return (flags & 0x0080) != 0; }
  bool is_pastend(void)   const { return (flags & 0x0020) != 0; }
  bool is_rvaoff(void)    const { return (flags & 0x0010) != 0; }
  bool is_custom(void)    const { return (flags & 0x0040) != 0; }
  bool is_subtract(void)  const { return (flags & 0x0100) != 0; }
  bool is_signed(void)    const { return (flags & 0x0200) != 0; }
  void set_type(reftype_t t) { flags &= ~0x000F; flags |= t; }
  void init(uint32 reft_and_flags, ea_t _base = 0, ea_t _target = ea_t(-1), adiff_t _tdelta = 0)
  {
    flags = reft_and_flags;
    base = _base;
    target = _target;
    tdelta = _tdelta;
  }
  ea_t _get_target(adiff_t opval) const;
  ea_t _get_value(ea_t target) const;
  adiff_t _get_opval(adiff_t opval) const;
};
struct strpath_t
{
  int len;
  tid_t ids[32];
  adiff_t delta;
};
struct enum_const_t
{
  tid_t tid;
  uchar serial;
};
union opinfo_t
{
  refinfo_t ri;
  tid_t tid;
  strpath_t path;
  int32 strtype;
  enum_const_t ec;
  custom_data_type_ids_t cd;
};
extern "C" int __stdcall set_refinfo_ex(ea_t ea, int n, const refinfo_t *ri);
extern "C" int __stdcall set_refinfo(ea_t ea, int n,
          reftype_t type, ea_t target=ea_t(-1), ea_t base=0, adiff_t tdelta=0);
extern "C" int __stdcall get_refinfo(ea_t ea, int n, refinfo_t *ri);
extern "C" int __stdcall del_refinfo(ea_t ea, int n);
extern "C" void __stdcall write_struc_path(netnode node, int idx, const tid_t *path, int plen, adiff_t delta);
extern "C" int  __stdcall read_struc_path(netnode node, int idx, tid_t *path, adiff_t *delta);
 int get_stroff0(ea_t ea, tid_t *path, adiff_t *delta) { return read_struc_path(netnode(ea), 15, path, delta); }  void set_stroff0(ea_t ea, const tid_t *path, int plen, adiff_t delta) { write_struc_path(netnode(ea), 15, path, plen, delta); }  void del_stroff0(ea_t ea) { netnode(ea).supdel(15); }
 int get_stroff1(ea_t ea, tid_t *path, adiff_t *delta) { return read_struc_path(netnode(ea), 16, path, delta); }  void set_stroff1(ea_t ea, const tid_t *path, int plen, adiff_t delta) { write_struc_path(netnode(ea), 16, path, plen, delta); }  void del_stroff1(ea_t ea) { netnode(ea).supdel(16); }
 ssize_t get__segtrans(ea_t ea, ea_t *buf, size_t bufsize) { return netnode(ea).supval(17, buf, bufsize); }  void set__segtrans(ea_t ea,const ea_t *oi,int size) { netnode(ea).supset(17,oi,size); }  void del__segtrans(ea_t ea) { netnode(ea).supdel(17); }
typedef uchar type_t;
typedef uchar p_list;
extern "C" bool __stdcall get_tinfo(ea_t ea, qtype *type, qtype *fields);
extern "C" bool __stdcall set_tinfo(ea_t ea, const type_t *ti, const p_list *fnames);
 void __stdcall del_tinfo(ea_t ea) { set_tinfo(ea, 0, 0); }
extern "C" bool __stdcall get_op_tinfo(ea_t ea, int n, qtype *type, qtype *fnames);
extern "C" bool __stdcall set_op_tinfo(ea_t ea, int n, const type_t *ti, const p_list *fnames);
 void __stdcall del_tinfo(ea_t ea, int n) { set_op_tinfo(ea, n, 0, 0); }
 ssize_t __stdcall get_input_file_path(char *buf, size_t bufsize)
{
  return RootNode.valstr(buf, bufsize);
}
extern "C" ssize_t __stdcall get_root_filename(char *buf, size_t bufsize);
 void set_root_filename(const char *file) { RootNode.set(file); }
 uint32 __stdcall retrieve_input_file_crc32(void) { return uint32(RootNode.altval(uval_t(-5))); }
 bool __stdcall retrieve_input_file_md5(uchar hash[16]) { return RootNode.supval(1302, hash, 16) == 16; }
 ssize_t __stdcall get_asm_inc_file(char *buf, size_t bufsize) { return RootNode.supstr(1100, buf, bufsize); }
 bool __stdcall set_asm_inc_file(const char *file) { return RootNode.supset(1100, file); }
 ea_t __stdcall get_imagebase(void) { return RootNode.altval(uval_t(-6)); }
 void __stdcall set_imagebase(ea_t base) { RootNode.altset(uval_t(-6), base); }
 netnode __stdcall get_ids_modnode(void) { return RootNode.altval(uval_t(-7)); }
 void __stdcall set_ids_modnode(netnode id) { RootNode.altset(uval_t(-7), id); }
 void __stdcall ExtraUpdate(ea_t ea, const char *str, int what) { netnode(ea).supset(what, str); }
 void __stdcall ExtraDel(ea_t ea, int what) { netnode(ea).supdel(what); }
 ssize_t __stdcall ExtraGet(ea_t ea, int what, char *buf, size_t bufsize) { return netnode(ea).supstr(what, buf, bufsize); }
 ssize_t __stdcall get_auto_plugins(char *buf, size_t bufsize) { return RootNode.supstr(1304, buf, bufsize); }
 bool __stdcall set_auto_plugins(const char *list, size_t listsize=0) { return RootNode.supset(1304, list, listsize); }
 size_t dbg_get_input_path(char *buf, size_t bufsize)
{
  if ( (inf.lflags & 0x08) != 0 )
    return get_root_filename(buf, bufsize);
  else
    return get_input_file_path(buf, bufsize);
}
extern "C" int          __stdcall get_encodings_count();
extern "C" const char * __stdcall get_encoding_name(int idx);
extern "C" int          __stdcall add_encoding(const char *encoding);
extern "C" bool         __stdcall del_encoding(int idx);
extern "C" bool         __stdcall change_encoding_name(int idx, const char *encoding);
extern "C" int          __stdcall get_default_encoding_idx(int32 strtype);
extern "C" bool         __stdcall set_default_encoding_idx(int32 strtype, int idx);
 const char *__stdcall encoding_from_strtype(int32 strtype)
{
  uchar enc = get_str_encoding_idx(strtype);
  if ( enc == 0 )
    enc = get_default_encoding_idx(strtype);
  return get_encoding_name(enc);
}
extern "C" int  __stdcall get_import_module_qty();
extern "C" bool __stdcall get_import_module_name(int mod_index, char* buf, size_t bufsize);
typedef int __stdcall import_enum_cb_t(ea_t ea, const char *name, uval_t ord, void *param);
extern "C" int __stdcall enum_import_names(int mod_index, import_enum_cb_t *callback, void *param=0);
 ssize_t get_switch_info(ea_t ea, switch_info_t *buf, size_t bufsize) { return netnode(ea).supval(8, buf, bufsize); }  void set_switch_info(ea_t ea,const switch_info_t *oi) { netnode(ea).supset(8,oi,sizeof(switch_info_t)); }  void del_switch_info(ea_t ea) { netnode(ea).supdel(8); }
extern "C" bool __stdcall get_ti(ea_t ea, type_t *buf, size_t bufsize, p_list *fnames, size_t fnsize);
extern "C" bool __stdcall set_ti(ea_t ea, const type_t *ti, const p_list *fnames);
 void __stdcall del_ti(ea_t ea) { set_ti(ea, (type_t *)"", 0); }
extern "C" bool __stdcall get_op_ti(ea_t ea, int n, type_t *buf, size_t bufsize, p_list *fnames, size_t fnsize);
extern "C" bool __stdcall set_op_ti(ea_t ea, int n, const type_t *ti, const p_list *fnames);
 void __stdcall del_ti(ea_t ea, int n) { set_op_ti(ea, n, (type_t *)"", 0); }
extern netnode ignore_micro;
 void init_ignore_micro(void) { ignore_micro.create("$ ignore micro"); }
 void term_ignore_micro(void) { ignore_micro = nodeidx_t(-1); }
 char get_ignore_micro(ea_t ea) { return ignore_micro.charval(ea, 0); }
 bool should_ignore_micro(ea_t ea) { return get_ignore_micro(ea) != 0; }
 void set_ignore_micro(ea_t ea, uchar im_type) { ignore_micro.charset(ea, im_type, 0); }
 void clr_ignore_micro(ea_t ea) { ignore_micro.chardel(ea, 0); }
 void mark_prolog_insn(ea_t ea) { set_ignore_micro(ea, 1); }
 void mark_epilog_insn(ea_t ea) { set_ignore_micro(ea, 2); }
 void mark_switch_insn(ea_t ea) { set_ignore_micro(ea, 3); }
 bool is_prolog_insn(ea_t ea) { return get_ignore_micro(ea) == 1; }
 bool is_epilog_insn(ea_t ea) { return get_ignore_micro(ea) == 2; }
 bool is_switch_insn(ea_t ea) { return get_ignore_micro(ea) == 3; }
 ea_t next_marked_insn(ea_t ea) { return ignore_micro.charnxt(ea, 0); }
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
struct area_t;
extern "C" size_t __stdcall area_t_print(const area_t *, char *buf, size_t bufsize);
struct area_t
{
  friend size_t __stdcall area_t_print(const area_t *cb, char *buf, size_t bufsize);
  ea_t startEA;
  ea_t endEA;
  area_t(void) {}
  area_t(ea_t ea1, ea_t ea2) : startEA(ea1), endEA(ea2) {}
  int compare(const area_t &r) const { return startEA > r.startEA ? 1 : startEA < r.startEA ? -1 : 0; }
  bool operator ==(const area_t &r) const { return compare(r) == 0; }
  bool operator !=(const area_t &r) const { return compare(r) != 0; }
  bool operator > (const area_t &r) const { return compare(r) >  0; }
  bool operator < (const area_t &r) const { return compare(r) <  0; }
  bool contains(ea_t ea) const { return startEA <= ea && endEA > ea; }
  bool contains(const area_t &r) const { return r.startEA >= startEA && r.endEA <= endEA; }
  bool overlaps(const area_t &r) const { return r.startEA < endEA && startEA < r.endEA; }
  void clear(void) { startEA = endEA = 0; }
  bool empty(void) const { return startEA >= endEA; }
  asize_t size(void) const { return endEA - startEA; }
  void intersect(const area_t &r)
  {
    if ( startEA < r.startEA ) startEA = r.startEA;
    if ( endEA   > r.endEA   ) endEA   = r.endEA;
    if ( endEA   < startEA   ) endEA   = startEA;
  }
  void extend(ea_t ea)
  {
    if ( startEA > ea ) startEA = ea;
    if ( endEA < ea ) endEA = ea;
  }
  size_t print(char *buf, size_t bufsize) const { return area_t_print(this, buf, bufsize); };
};
template <> struct ida_movable_type<area_t> { typedef ida_true_type is_movable_type; };
struct areavec_t : public qvector<area_t>
{
};
class  sarray;
struct lastreq_t;
class areaset_t;
extern "C" bool __stdcall areaset_t_add(areaset_t *, const area_t &area);extern "C" bool __stdcall areaset_t_sub(areaset_t *, const area_t &area);extern "C" bool __stdcall areaset_t_add2(areaset_t *, const areaset_t &aset);extern "C" bool __stdcall areaset_t_sub2(areaset_t *, const areaset_t &aset);extern "C" bool __stdcall areaset_t_has_common(const areaset_t *, const area_t &area, bool strict);extern "C" bool __stdcall areaset_t_has_common2(const areaset_t *, const areaset_t &aset);extern "C" bool __stdcall areaset_t_contains(const areaset_t *, const areaset_t &aset);extern "C" size_t __stdcall areaset_t_print(const areaset_t *, char *buf, size_t bufsize);extern "C" bool __stdcall areaset_t_intersect(areaset_t *, const areaset_t &aset);extern "C" const area_t *__stdcall areaset_t_find_area(const areaset_t *, ea_t ea);extern "C" ea_t __stdcall areaset_t_next_addr(const areaset_t *, ea_t ea);extern "C" ea_t __stdcall areaset_t_prev_addr(const areaset_t *, ea_t ea);extern "C" ea_t __stdcall areaset_t_next_area(const areaset_t *, ea_t ea);extern "C" ea_t __stdcall areaset_t_prev_area(const areaset_t *, ea_t ea);
class areaset_t
{
  friend bool __stdcall areaset_t_add(areaset_t *, const area_t &area);friend bool __stdcall areaset_t_sub(areaset_t *, const area_t &area);friend bool __stdcall areaset_t_add2(areaset_t *, const areaset_t &aset);friend bool __stdcall areaset_t_sub2(areaset_t *, const areaset_t &aset);friend bool __stdcall areaset_t_has_common(const areaset_t *, const area_t &area, bool strict);friend bool __stdcall areaset_t_has_common2(const areaset_t *, const areaset_t &aset);friend bool __stdcall areaset_t_contains(const areaset_t *, const areaset_t &aset);friend size_t __stdcall areaset_t_print(const areaset_t *, char *buf, size_t bufsize);friend bool __stdcall areaset_t_intersect(areaset_t *, const areaset_t &aset);friend const area_t *__stdcall areaset_t_find_area(const areaset_t *, ea_t ea);friend ea_t __stdcall areaset_t_next_addr(const areaset_t *, ea_t ea);friend ea_t __stdcall areaset_t_prev_addr(const areaset_t *, ea_t ea);friend ea_t __stdcall areaset_t_next_area(const areaset_t *, ea_t ea);friend ea_t __stdcall areaset_t_prev_area(const areaset_t *, ea_t ea);
  areavec_t bag;
  mutable const area_t *cache;
  bool verify(void) const;
public:
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  areaset_t(void) : cache(0) {}
  areaset_t(const area_t &area): cache(0) { if ( !area.empty() ) bag.push_back(area); }
  areaset_t(const areaset_t &ivs) : bag(ivs.bag), cache(0) {}
  void swap(areaset_t &r) { bag.swap(r.bag); }
  bool add(const area_t &area)    { return areaset_t_add(this, area); };
  bool add(ea_t start, ea_t _end) { return add(area_t(start, _end)); }
  bool add(const areaset_t &aset) { return areaset_t_add2(this, aset); };
  bool sub(ea_t ea)               { return sub(area_t(ea, ea+1)); }
  bool sub(const area_t &area)    { return areaset_t_sub(this, area); };
  bool sub(const areaset_t &aset) { return areaset_t_sub2(this, aset); };
  bool has_common(const area_t &area, bool strict=false) const
    { return areaset_t_has_common(this, area, strict); };
  size_t print(char *buf, size_t bufsize) const
    { return areaset_t_print(this, buf, bufsize); };
  asize_t count(void) const;
  const area_t &getarea(int idx) const { return bag[idx]; }
  const area_t &lastarea(void) const { return bag.back(); }
  size_t nareas(void) const { return bag.size(); }
  bool empty(void) const { return bag.empty(); }
  void clear(void) { bag.clear(); cache = 0; }
  bool has_common(const areaset_t &aset) const
    { return areaset_t_has_common2(this, aset); };
  bool contains(ea_t ea) const { return !empty() && find_area(ea) != 0; }
  bool contains(const areaset_t &aset) const
     { return areaset_t_contains(this, aset); };
  bool intersect(const areaset_t &aset)
     { return areaset_t_intersect(this, aset); };
  bool is_subset_of(const areaset_t &aset) const { return aset.contains(*this); }
  bool is_equal(const areaset_t &aset)   const { return bag == aset.bag; };
  bool operator==(const areaset_t &aset) const { return is_equal(aset); }
  bool operator!=(const areaset_t &aset) const { return !is_equal(aset); }
  typedef areavec_t::iterator iterator;
  typedef areavec_t::const_iterator const_iterator;
  const_iterator begin(void) const { return bag.begin(); }
  const_iterator end(void)   const { return bag.end(); }
  iterator begin(void) { return bag.begin(); }
  iterator end(void)   { return bag.end(); }
  const_iterator lower_bound(ea_t ea) const;
  const_iterator upper_bound(ea_t ea) const;
  const area_t *find_area(ea_t ea) const
     { return areaset_t_find_area(this, ea); };
  const area_t *cached_area(void) const { return cache; }
  ea_t next_addr(ea_t ea) const { return areaset_t_next_addr(this, ea); };
  ea_t prev_addr(ea_t ea) const { return areaset_t_prev_addr(this, ea); };
  ea_t next_area(ea_t ea) const { return areaset_t_next_area(this, ea); };
  ea_t prev_area(ea_t ea) const { return areaset_t_prev_area(this, ea); };
  int move_chunk(ea_t from, ea_t to, asize_t size);
  int check_move_args(ea_t from, ea_t to, asize_t size);
private:
  const_iterator _lower_bound(ea_t ea) const;
  const_iterator _upper_bound(ea_t ea) const;
};
template <> struct ida_movable_type<areaset_t> { typedef ida_true_type is_movable_type; };
typedef qvector<areaset_t> array_of_areasets;
class areacb_t;
class area_cache_t;
typedef int __stdcall area_visitor_t(area_t *a, void *ud);
struct area_visitor2_t
{
  virtual int __stdcall visit_area(area_t *a) = 0;
  virtual __stdcall ~area_visitor2_t(void) {}
};
extern "C" void __stdcall areacb_t_zero (areacb_t *);extern "C" void __stdcall areacb_t_terminate (areacb_t *);extern "C" void __stdcall areacb_t_save (const areacb_t *);extern "C" bool __stdcall areacb_t_link (areacb_t *,const char *file, const char *name, int infosize);extern "C" bool __stdcall areacb_t_create (areacb_t *,const char *file,const char *name,uint infosize);extern "C" void __stdcall areacb_t_kill (areacb_t *);extern "C" bool __stdcall areacb_t_create_area (areacb_t *,const area_t *info);extern "C" bool __stdcall areacb_t_update (areacb_t *,const area_t *info);extern "C" area_t *__stdcall areacb_t_get_area (areacb_t *,ea_t ea);extern "C" area_t *__stdcall areacb_t_getn_area (areacb_t *,unsigned int n);extern "C" int __stdcall areacb_t_get_area_num (areacb_t *,ea_t ea);extern "C" ea_t __stdcall areacb_t_prepare_to_create(areacb_t *,ea_t start,ea_t end);extern "C" int __stdcall areacb_t_get_next_area (areacb_t *,ea_t ea);extern "C" int __stdcall areacb_t_get_prev_area (areacb_t *,ea_t ea);extern "C" int __stdcall areacb_t_lock_area (areacb_t *,const area_t *);extern "C" int __stdcall areacb_t_unlock_area (areacb_t *,const area_t *);extern "C" int __stdcall areacb_t_get_area_locks (areacb_t *,const area_t *);extern "C" area_t *__stdcall areacb_t_prev_area_ptr (areacb_t *,ea_t ea);extern "C" area_t *__stdcall areacb_t_next_area_ptr (areacb_t *,ea_t ea);extern "C" area_t *__stdcall areacb_t_first_area_ptr (areacb_t *);extern "C" bool __stdcall areacb_t_del_area (areacb_t *,ea_t ea, bool delcmt);extern "C" bool __stdcall areacb_t_may_start_at (areacb_t *,uint n,ea_t newstart);extern "C" bool __stdcall areacb_t_may_end_at (areacb_t *,uint n,ea_t newend);extern "C" bool __stdcall areacb_t_set_start (areacb_t *,uint n,ea_t newstart);extern "C" bool __stdcall areacb_t_set_end (areacb_t *,uint n,ea_t newend);extern "C" bool __stdcall areacb_t_resize_areas (areacb_t *,uint n,ea_t newstart);extern "C" uint __stdcall areacb_t_get_area_qty (const areacb_t *);extern "C" area_t *__stdcall areacb_t_choose_area (areacb_t *,int flags, int width, char *(__stdcall*getl)(areacb_t *obj,uint32 n,char *buf), const char *title, int icon, int x0,int y0,int x1,int y1, const char * const *popup_menus, ea_t defea);extern "C" area_t *__stdcall areacb_t_choose_area2 (areacb_t *,int flags, int ncol, const int *widths, void (__stdcall*getl)(areacb_t *obj,uint32 n,char * const *arrptr), const char *title, int icon, int x0,int y0,int x1,int y1, const char * const *popup_menus, ea_t defea);extern "C" bool __stdcall areacb_t_set_area_cmt (areacb_t *,const area_t *a, const char *cmt, bool repeatable);extern "C" char *__stdcall areacb_t_get_area_cmt (const areacb_t *,const area_t *a, bool repeatable);extern "C" int __stdcall areacb_t_move_areas (areacb_t *,ea_t from,ea_t to, asize_t size, int (__stdcall*area_mover)(area_t *a, adiff_t delta, void *ud), void *ud);extern "C" void __stdcall areacb_t_make_hole (areacb_t *,ea_t ea1, ea_t ea2, bool create_tail_area);extern "C" int __stdcall areacb_t_for_all_areas2 (areacb_t *,ea_t ea1, ea_t ea2, area_visitor2_t &av);extern "C" int __stdcall areacb_t_for_all_areas(areacb_t *,ea_t ea1, ea_t ea2, area_visitor_t *av, void *ud);
class areacb_t
{
  friend void __stdcall areacb_t_zero (areacb_t *);friend void __stdcall areacb_t_terminate (areacb_t *);friend void __stdcall areacb_t_save (const areacb_t *);friend bool __stdcall areacb_t_link (areacb_t *,const char *file, const char *name, int infosize);friend bool __stdcall areacb_t_create (areacb_t *,const char *file,const char *name,uint infosize);friend void __stdcall areacb_t_kill (areacb_t *);friend bool __stdcall areacb_t_create_area (areacb_t *,const area_t *info);friend bool __stdcall areacb_t_update (areacb_t *,const area_t *info);friend area_t *__stdcall areacb_t_get_area (areacb_t *,ea_t ea);friend area_t *__stdcall areacb_t_getn_area (areacb_t *,unsigned int n);friend int __stdcall areacb_t_get_area_num (areacb_t *,ea_t ea);friend ea_t __stdcall areacb_t_prepare_to_create(areacb_t *,ea_t start,ea_t end);friend int __stdcall areacb_t_get_next_area (areacb_t *,ea_t ea);friend int __stdcall areacb_t_get_prev_area (areacb_t *,ea_t ea);friend int __stdcall areacb_t_lock_area (areacb_t *,const area_t *);friend int __stdcall areacb_t_unlock_area (areacb_t *,const area_t *);friend int __stdcall areacb_t_get_area_locks (areacb_t *,const area_t *);friend area_t *__stdcall areacb_t_prev_area_ptr (areacb_t *,ea_t ea);friend area_t *__stdcall areacb_t_next_area_ptr (areacb_t *,ea_t ea);friend area_t *__stdcall areacb_t_first_area_ptr (areacb_t *);friend bool __stdcall areacb_t_del_area (areacb_t *,ea_t ea, bool delcmt);friend bool __stdcall areacb_t_may_start_at (areacb_t *,uint n,ea_t newstart);friend bool __stdcall areacb_t_may_end_at (areacb_t *,uint n,ea_t newend);friend bool __stdcall areacb_t_set_start (areacb_t *,uint n,ea_t newstart);friend bool __stdcall areacb_t_set_end (areacb_t *,uint n,ea_t newend);friend bool __stdcall areacb_t_resize_areas (areacb_t *,uint n,ea_t newstart);friend uint __stdcall areacb_t_get_area_qty (const areacb_t *);friend area_t *__stdcall areacb_t_choose_area (areacb_t *,int flags, int width, char *(__stdcall*getl)(areacb_t *obj,uint32 n,char *buf), const char *title, int icon, int x0,int y0,int x1,int y1, const char * const *popup_menus, ea_t defea);friend area_t *__stdcall areacb_t_choose_area2 (areacb_t *,int flags, int ncol, const int *widths, void (__stdcall*getl)(areacb_t *obj,uint32 n,char * const *arrptr), const char *title, int icon, int x0,int y0,int x1,int y1, const char * const *popup_menus, ea_t defea);friend bool __stdcall areacb_t_set_area_cmt (areacb_t *,const area_t *a, const char *cmt, bool repeatable);friend char *__stdcall areacb_t_get_area_cmt (const areacb_t *,const area_t *a, bool repeatable);friend int __stdcall areacb_t_move_areas (areacb_t *,ea_t from,ea_t to, asize_t size, int (__stdcall*area_mover)(area_t *a, adiff_t delta, void *ud), void *ud);friend void __stdcall areacb_t_make_hole (areacb_t *,ea_t ea1, ea_t ea2, bool create_tail_area);friend int __stdcall areacb_t_for_all_areas2 (areacb_t *,ea_t ea1, ea_t ea2, area_visitor2_t &av);friend int __stdcall areacb_t_for_all_areas(areacb_t *,ea_t ea1, ea_t ea2, area_visitor_t *av, void *ud);
  uval_t areasCode;
  ushort infosize;
  lastreq_t *lastreq;
  uint32 used_cache;
  sarray *sa;
  area_cache_t *cache;
  area_cache_t *head;
  void *reserved2[126];
  void allocate(const char *file, bool del_other);
  area_t *search(ea_t EA, int *n);
  area_t *readArea(ea_t EA);
  area_cache_t *findCache(ea_t ea);
  area_t *addCache(const area_t *a);
  bool delCache(ea_t ea);
  void free_cache(void);
  area_cache_t *link_at_head(area_cache_t *ptr);
  area_cache_t *move_to_head(area_cache_t *ptr);
  area_cache_t *get_area_cache(const area_t *area);
  void verify_cache(void) const;
  ea_t find_nth_start(int n);
  void build_optimizer(void);
  void move_area_comment(ea_t oldea, ea_t newea);
  bool pack_and_write_area(const area_t *a);
  bool move_away(int cur,
                 ea_t ea1,
                 ea_t ea2,
                 bool create_tail_area);
public:
  void (__stdcall *read_cb)(const uchar *packed, const uchar *end, area_t *a);
  size_t (__stdcall *write_cb)(const area_t *a,uchar *packbuf, uchar *packend);
  void (__stdcall *delcache_cb)(area_t *a);
  int (__stdcall *edit_cb)(area_t *a);
  int (__stdcall *kill_cb)(area_t *a);
  int (__stdcall *new_cb)(void);
  void zero(void)               { areacb_t_zero(this); }
  areacb_t(void)                { zero(); }
  void terminate(void)          { areacb_t_terminate(this); }
  ~areacb_t(void)               { terminate(); }
   void save(void) { areacb_t_save(this); }
  bool link(const char *file,
            const char *name,
            int _infosize)
        { return areacb_t_link(this, file, name, _infosize); }
  bool create(const char *file, const char *name, uint _infosize)
        { return areacb_t_create(this, file, name, _infosize); }
  void kill(void)        { areacb_t_kill(this); }
  bool create_area(const area_t *info)
        { return areacb_t_create_area(this, info); }
  bool update(const area_t *info)
        { return areacb_t_update(this, info); }
  area_t *get_area(ea_t ea)
        { return areacb_t_get_area(this, ea); }
  area_t *getn_area(unsigned int n)
        { return areacb_t_getn_area(this, n); }
  int get_area_num(ea_t ea)
        { return areacb_t_get_area_num(this, ea); }
  ea_t prepare_to_create(ea_t start,ea_t end)
        { return areacb_t_prepare_to_create(this, start, end); }
  int get_next_area(ea_t ea)
        { return areacb_t_get_next_area(this, ea); }
  int get_prev_area(ea_t ea)
        { return areacb_t_get_prev_area(this, ea); }
  area_t *next_area_ptr(ea_t ea) { return areacb_t_next_area_ptr(this, ea); }
  area_t *prev_area_ptr(ea_t ea) { return areacb_t_prev_area_ptr(this, ea); }
  area_t *first_area_ptr(void) { return areacb_t_first_area_ptr(this); }
  area_t *last_area_ptr(void) { return areacb_t_prev_area_ptr(this, ea_t(-1)); }
  bool del_area(ea_t ea, bool delcmt=true)
        { return areacb_t_del_area(this, ea, delcmt); }
  bool may_start_at(uint n,ea_t newstart)
        { return areacb_t_may_start_at(this, n, newstart); }
  bool may_end_at(uint n,ea_t newend)
        { return areacb_t_may_end_at(this, n, newend); }
  bool set_start(uint n, ea_t newstart)
        { return areacb_t_set_start(this, n, newstart); }
  bool set_end(uint n, ea_t newend)
        { return areacb_t_set_end(this, n, newend); }
  void make_hole(ea_t ea1, ea_t ea2, bool create_tail_area)
        { areacb_t_make_hole(this, ea1, ea2, create_tail_area); }
  bool resize_areas(uint n,ea_t newstart)
        { return areacb_t_resize_areas(this, n, newstart); }
  uint get_area_qty(void) const
        { return areacb_t_get_area_qty(this); }
  area_t *choose_area(int flags,
                      int width,
                      char *(__stdcall*getl)(areacb_t *obj,uint32 n,char *buf),
                      const char *title,
                      int icon,
                      int x0=-1,int y0=-1,int x1=-1,int y1=-1,
                      const char * const *popup_menus=0,
                      ea_t defea=ea_t(-1))
  {
    return areacb_t_choose_area(this, flags, width, getl, title, icon,
                        x0, y0, x1, y1, popup_menus, defea);
  }
  area_t *choose_area2(int flags,
                      int ncol,
                      const int *widths,
                      void (__stdcall*getl)(areacb_t *obj,uint32 n,char * const *arrptr),
                      const char *title,
                      int icon,
                      int x0=-1,int y0=-1,int x1=-1,int y1=-1,
                      const char * const *popup_menus=0,
                      ea_t defea=ea_t(-1))
  {
    return areacb_t_choose_area2(this, flags, ncol, widths, getl, title, icon,
                        x0, y0, x1, y1, popup_menus, defea);
  }
  ea_t find_prev_gap(ea_t ea);
  ea_t find_next_gap(ea_t ea);
  bool set_area_cmt(const area_t *a, const char *cmt, bool repeatable)
        { return areacb_t_set_area_cmt(this, a, cmt, repeatable); }
  void del_area_cmt(const area_t *a, bool repeatable)
                { set_area_cmt(a, "", repeatable); }
  char *get_area_cmt(const area_t *a, bool repeatable) const
        { return areacb_t_get_area_cmt(this, a, repeatable); }
  int move_areas(ea_t from,
                 ea_t to,
                 asize_t size,
                 int (__stdcall *area_mover)(area_t *a, adiff_t delta, void *ud)=0,
                 void *ud=0)
        { return areacb_t_move_areas(this, from, to, size, area_mover, ud); }
  int for_all_areas(ea_t ea1, ea_t ea2, area_visitor_t *av, void *ud)
        { return areacb_t_for_all_areas(this, ea1, ea2, av, ud); }
  int for_all_areas2(ea_t ea1, ea_t ea2, area_visitor2_t &av)
        { return areacb_t_for_all_areas2(this, ea1, ea2, av); }
};
class lock_area
{
  areacb_t *cb;
  area_t *area;
public:
  lock_area(areacb_t *_cb, area_t *_area) : cb(_cb), area(_area)
  {
    areacb_t_lock_area(cb, area);
  }
  ~lock_area(void)
  {
    areacb_t_unlock_area(cb, area);
  }
};
#pragma pack(pop)
extern "C" areacb_t __declspec(dllimport) segs;
class segment_t : public area_t
{
public:
  segment_t(void)       { memset(this,0,sizeof(segment_t)); color = bgcolor_t(-1); }
  uval_t name;
  uval_t sclass;
  uval_t orgbase;
  uchar align;
  uchar comb;
  uchar perm;
  uchar bitness;
          bool use32(void) const { return bitness >= 1; }
          bool use64(void) const { return bitness == 2; }
          int  abits(void) const { return 1<<(bitness+4); }
          int  abytes(void) const { return abits() / 8; }
  ushort flags;
  bool comorg(void) const { return (flags & 0x01) != 0; }
  void set_comorg(void) { flags |= 0x01; }
  void clr_comorg(void) { flags &= ~0x01; }
  bool ob_ok(void) const { return (flags & 0x02) != 0; }
  void set_ob_ok(void) { flags |= 0x02; }
  void clr_ob_ok(void) { flags &= ~0x02; }
  bool is_visible_segm(void) const { return (flags & 0x04) == 0; }
  void set_visible_segm(bool visible) { setflag(flags, 0x04, !visible); }
  bool is_debugger_segm(void) const { return (flags & 0x08) != 0; }
  void set_debugger_segm(bool debseg) { setflag(flags, 0x08, debseg); }
  bool is_loader_segm(void) const { return (flags & 0x10) != 0; }
  void set_loader_segm(bool ldrseg) { setflag(flags, 0x10, ldrseg); }
  bool is_hidden_segtype(void) const { return (flags & 0x20) != 0; }
  void set_hidden_segtype(bool hide) { setflag(flags, 0x20, hide); }
  bool is_ephemeral_segm(void) const
    { return (flags & (0x08|0x10)) == 0x08; }
  sel_t sel;
  sel_t defsr[16];
  uchar type;
  bgcolor_t color;
  int update(void)      { return segs.update(this); }
};
 bool is_visible_segm(segment_t *s) { return s->is_visible_segm(); }
 bool is_finally_visible_segm(segment_t *s)
 { return (inf.s_cmtflg & 0x80) != 0 || is_visible_segm(s); }
extern "C" void __stdcall set_visible_segm(segment_t *s, bool visible);
extern "C" bool __stdcall is_spec_segm(uchar seg_type);
extern "C" bool __stdcall is_spec_ea(ea_t ea);
class lock_segment
{
  const segment_t *segm;
public:
  lock_segment(const segment_t *_segm) : segm(_segm)
  {
    areacb_t_lock_area(&segs, segm);
  }
  ~lock_segment(void)
  {
    areacb_t_unlock_area(&segs, segm);
  }
};
 bool is_segm_locked(const segment_t *segm)
{
  return areacb_t_get_area_locks(&segs, segm) > 0;
}
extern "C" bool __stdcall getn_selector(int n, sel_t *sel, ea_t *base);
extern "C" int __stdcall get_selector_qty(void);
extern "C" sel_t __stdcall setup_selector(ea_t segbase);
extern "C" sel_t __stdcall allocate_selector(ea_t segbase);
extern "C" sel_t __stdcall find_free_selector(void);
extern "C" int __stdcall set_selector(sel_t selector, ea_t paragraph);
extern "C" void __stdcall del_selector(sel_t selector);
extern "C" ea_t __stdcall ask_selector(sel_t selector);
extern "C" ea_t __stdcall sel2ea(sel_t selector);
extern "C" sel_t __stdcall find_selector(ea_t base);
extern "C" int __stdcall enumerate_selectors(int (__stdcall* func)(sel_t sel,ea_t para));
extern "C" ea_t __stdcall enumerate_segments_with_selector(
                                sel_t selector,
                                ea_t (__stdcall* func)(segment_t *s,void *ud),
                                void *ud);
extern "C" segment_t *__stdcall get_segm_by_sel(sel_t selector);
extern "C" int __stdcall add_segm_ex(segment_t *s,const char *name,const char *sclass,int flags);
extern "C" int __stdcall add_segm(ea_t para,
                        ea_t start,
                        ea_t end,
                        const char *name,
                        const char *sclass);
extern "C" int __stdcall del_segm(ea_t ea, int flags);
 int get_segm_qty(void){ return segs.get_area_qty(); }
 segment_t *getseg(ea_t ea) { return (segment_t *)(segs.get_area(ea)); }
 segment_t *getnseg(int n){ return (segment_t *)(segs.getn_area(n)); }
 segment_t *get_next_seg(ea_t ea) { return (segment_t *)segs.next_area_ptr(ea); }
 segment_t *get_prev_seg(ea_t ea) { return (segment_t *)segs.prev_area_ptr(ea); }
 segment_t *get_first_seg(void) { return (segment_t *)segs.first_area_ptr(); }
 segment_t *get_last_seg(void) { return (segment_t *)segs.last_area_ptr(); }
extern "C" segment_t *__stdcall get_segm_by_name(const char *name);
extern "C" int __stdcall set_segm_end(ea_t ea, ea_t newend, int flags);
extern "C" int __stdcall set_segm_start(ea_t ea, ea_t newstart, int flags);
extern "C" int __stdcall move_segm_start(ea_t ea,ea_t newstart,int mode);
extern "C" int __stdcall move_segm(segment_t *s, ea_t to, int flags=0);
extern "C" int __stdcall rebase_program(adiff_t delta, int flags);
extern "C" int __stdcall change_segment_status(segment_t *s, bool is_deb_segm);
extern "C" bool __stdcall take_memory_snapshot(bool only_loader_segs);
extern "C" bool __stdcall is_miniidb(void);
extern "C" bool __stdcall set_segm_base(segment_t *s, ea_t newbase);
       void init_groups(void);
 void save_groups(void) {}
 void term_groups(void) {}
extern "C" int __stdcall set_group_selector(sel_t grp,sel_t sel);
extern "C" sel_t __stdcall get_group_selector(sel_t grpsel);
extern "C" bool __stdcall add_segment_translation(ea_t segstart, ea_t mappedseg);
extern "C" bool __stdcall set_segment_translations(ea_t segstart, const ea_t *transmap);
 bool del_segment_translations(ea_t ea)
{
  return set_segment_translations(ea, 0);
}
extern "C" ea_t *__stdcall get_segment_translations(ea_t segstart,
                                                 ea_t *buf,
                                                 int bufsize);
 char *get_segment_cmt(const segment_t *s, bool repeatable)
{
  return segs.get_area_cmt(s,repeatable);
}
 void set_segment_cmt(segment_t *s,const char *cmt, bool repeatable)
{
  segs.set_area_cmt(s,cmt,repeatable);
}
 void del_segment_cmt(segment_t *s, bool repeatable)
{
  segs.del_area_cmt(s, repeatable);
}
extern "C" void __stdcall std_gen_segm_footer(ea_t ea);
extern "C"  int __stdcall vset_segm_name(
        segment_t *s,
        const char *format,
        va_list va);
  int set_segm_name(segment_t *s, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = vset_segm_name(s, format, va);
  ( va = (va_list)0 );
  return code;
}
extern "C" ssize_t __stdcall get_true_segm_name(const segment_t *s, char *buf, size_t bufsize);
extern "C" ssize_t __stdcall get_segm_name(const segment_t *s, char *buf, size_t bufsize);
 ssize_t __stdcall get_segm_name(ea_t ea, char *buf, size_t bufsize)
{
  return get_segm_name(getseg(ea), buf, bufsize);
}
char *get_segm_expr(ea_t from, sel_t sel, char *buf, size_t bufsize);
extern "C" ssize_t __stdcall get_segm_class(const segment_t *s, char *buf, size_t bufsize);
extern "C" int __stdcall set_segm_class(segment_t *s, const char *sclass);
extern "C" uchar __stdcall segtype(ea_t ea);
extern "C" const char *__stdcall get_segment_alignment(uchar align);
extern "C" const char *__stdcall get_segment_combination(uchar comb);
extern "C" ea_t __stdcall get_segm_para(const segment_t *s);
extern "C" ea_t __stdcall get_segm_base(const segment_t *s);
extern "C" bool __stdcall set_segm_addressing(segment_t *s, size_t bitness);
ssize_t get_based_segm_expr(ea_t from, sel_t basesel, sel_t sel, char *buf, size_t bufsize);
void    createSegmentation(const char *file);
void    initSegment     (const char *file, bool newfile);
void    save_segments   (void);
void    termSegment     (void);
void    DeleteAllSegments(void);
void delete_debug_segments(void);
 bool is_debugger_segm(ea_t ea)
{
  segment_t *s = getseg(ea);
  return s != 0 && s->is_debugger_segm();
}
 bool is_ephemeral_segm(ea_t ea)
{
  segment_t *s = getseg(ea);
  return s != 0 && s->is_ephemeral_segm();
}
 ea_t correct_address(ea_t ea, ea_t from, ea_t to, ea_t size)
{
  if ( ea >= from && ea < from+size )
    ea += to - from;
  return ea;
}
extern "C" adiff_t __stdcall segm_adjust_diff(const segment_t *s, adiff_t delta);
extern "C" ea_t __stdcall segm_adjust_ea(const segment_t *s, ea_t ea);
#pragma pack(pop)
#pragma pack(push, 1)
struct area_t;
 bool requires_color_esc(char c) { return c >= '\1' && c <= '\4'; }
typedef uchar color_t;
const color_t
  COLOR_DEFAULT  = 0x01,
  COLOR_REGCMT   = 0x02,
  COLOR_RPTCMT   = 0x03,
  COLOR_AUTOCMT  = 0x04,
  COLOR_INSN     = 0x05,
  COLOR_DATNAME  = 0x06,
  COLOR_DNAME    = 0x07,
  COLOR_DEMNAME  = 0x08,
  COLOR_SYMBOL   = 0x09,
  COLOR_CHAR     = 0x0A,
  COLOR_STRING   = 0x0B,
  COLOR_NUMBER   = 0x0C,
  COLOR_VOIDOP   = 0x0D,
  COLOR_CREF     = 0x0E,
  COLOR_DREF     = 0x0F,
  COLOR_CREFTAIL = 0x10,
  COLOR_DREFTAIL = 0x11,
  COLOR_ERROR    = 0x12,
  COLOR_PREFIX   = 0x13,
  COLOR_BINPREF  = 0x14,
  COLOR_EXTRA    = 0x15,
  COLOR_ALTOP    = 0x16,
  COLOR_HIDNAME  = 0x17,
  COLOR_LIBNAME  = 0x18,
  COLOR_LOCNAME  = 0x19,
  COLOR_CODNAME  = 0x1A,
  COLOR_ASMDIR   = 0x1B,
  COLOR_MACRO    = 0x1C,
  COLOR_DSTR     = 0x1D,
  COLOR_DCHAR    = 0x1E,
  COLOR_DNUM     = 0x1F,
  COLOR_KEYWORD  = 0x20,
  COLOR_REG      = 0x21,
  COLOR_IMPNAME  = 0x22,
  COLOR_SEGNAME  = 0x23,
  COLOR_UNKNAME  = 0x24,
  COLOR_CNAME    = 0x25,
  COLOR_UNAME    = 0x26,
  COLOR_COLLAPSED= 0x27,
  COLOR_FG_MAX   = 0x28,
  COLOR_ADDR     = COLOR_FG_MAX,
  COLOR_OPND1    = COLOR_ADDR+1,
  COLOR_OPND2    = COLOR_ADDR+2,
  COLOR_OPND3    = COLOR_ADDR+3,
  COLOR_OPND4    = COLOR_ADDR+4,
  COLOR_OPND5    = COLOR_ADDR+5,
  COLOR_OPND6    = COLOR_ADDR+6,
  COLOR_UTF8     = COLOR_ADDR+10;
extern "C" char *__stdcall tag_on(char *ptr, char *end, color_t tag);
extern "C" char *__stdcall tag_off(char *ptr, char *end, color_t tag);
extern "C" char *__stdcall tag_addchr(char *ptr, char *end, color_t tag, char chr);
extern "C" char *__stdcall tag_addstr(char *ptr, char *end, color_t tag, const char *string);
extern "C" char *__stdcall tag_addr(char *ptr, char *end, ea_t ea);
extern "C" const char *__stdcall tag_advance(const char *line, int cnt);
extern "C" const char *__stdcall tag_skipcodes(const char *line);
extern "C" const char *__stdcall tag_skipcode(const char *line);
extern "C" ssize_t __stdcall tag_strlen(const char *line);
extern "C" ssize_t __stdcall tag_remove(const char *instr, char *buf, size_t bufsize);
extern "C" color_t   __stdcall calc_prefix_color(ea_t ea);
extern "C" bgcolor_t __stdcall calc_bg_color(ea_t ea);
struct bgcolors_t
{
  bgcolor_t prolog_color;
  bgcolor_t epilog_color;
  bgcolor_t switch_color;
};
extern bgcolors_t bgcolors;
       void init_sourcefiles(void);
 void save_sourcefiles(void) {}
       void term_sourcefiles(void);
       void move_sourcefiles(ea_t from, ea_t to, asize_t size);
extern "C" bool __stdcall add_sourcefile(ea_t ea1,ea_t ea2,const char *filename);
extern "C" const char *__stdcall get_sourcefile(ea_t ea, area_t *bounds=0);
extern "C" bool __stdcall del_sourcefile(ea_t ea);
extern "C" char __declspec(dllimport) gl_comm;
extern "C" char __declspec(dllimport) gl_name;
extern "C" char __declspec(dllimport) gl_xref;
extern "C" int __declspec(dllimport) gl_psize;
extern "C" int __declspec(dllimport) gl_bpsize;
extern "C" void __stdcall set_user_defined_prefix(size_t width,
                        void (__stdcall*get_user_defined_prefix)(ea_t ea,
                                                        int lnnum,
                                                        int indent,
                                                        const char *line,
                                                        char *buf,
                                                        size_t bufsize));
extern "C" bool __stdcall MakeLine(const char *contents,int indent=-1);
extern "C"  bool __stdcall printf_line_v(
        int indent,
        const char *format,
        va_list va);
  bool printf_line(int indent, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool code = printf_line_v(indent,format,va);
  ( va = (va_list)0 );
  return code;
}
extern "C" bool __stdcall MakeNull(void);
extern "C" bool __stdcall MakeBorder(void);
extern "C" bool __stdcall MakeSolidBorder (void);
extern "C"  bool __stdcall gen_colored_cmt_line_v(
        color_t color,
        const char *format,
        va_list va);
  bool gen_cmt_line_v(const char *format, va_list va)
{
  return gen_colored_cmt_line_v(COLOR_AUTOCMT, format, va);
}
  bool gen_cmt_line(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool code = gen_cmt_line_v(format, va);
  ( va = (va_list)0 );
  return code;
}
  bool gen_collapsed_line(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool answer = gen_colored_cmt_line_v(COLOR_COLLAPSED, format, va);
  ( va = (va_list)0 );
  return answer;
}
extern "C" bool __stdcall generate_big_comment(const char *cmt, color_t color);
extern "C" bool __stdcall generate_many_lines(const char *string, color_t color);
extern "C"  void __stdcall describex(
        ea_t ea,
        const char *prefix,
        bool isprev,
        const char *format,
        va_list va);
  void describe(ea_t ea, bool isprev, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  describex(ea,0,isprev,format,va);
  ( va = (va_list)0 );
}
extern "C"  void __stdcall add_long_cmt_v(
        ea_t ea,
        bool isprev,
        const char *format,
        va_list va);
  void add_long_cmt(ea_t ea, bool isprev, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  add_long_cmt_v(ea, isprev, format, va);
  ( va = (va_list)0 );
}
  void add_pgm_cmt(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  add_long_cmt_v(inf.minEA, true, format, va);
  ( va = (va_list)0 );
}
int gen_xref_lines(
        ea_t genEA,
        ea_t (__stdcall*first)(ea_t),
        ea_t (__stdcall*next) (ea_t,ea_t),
        const char *tag,
        color_t color,
        int maxrefnum,
        size_t tail_depth,
        int checkflags);
typedef ssize_t __stdcall ml_getcmt_t(color_t *cmttype, char *buf, size_t bufsize);
typedef ssize_t __stdcall ml_getnam_t(color_t *namtype, char *buf, size_t bufsize);
typedef bool    __stdcall ml_genxrf_t(void);
typedef bool    __stdcall ml_saver_t(const char *line);
extern "C" void __stdcall setup_makeline(
        ea_t ea,
        const char *prefix,
        ml_getcmt_t *getcmt,
        ml_getnam_t *getnam,
        ml_genxrf_t *genxrf,
        ml_saver_t *saver,
        int flags);
extern "C" bool __stdcall save_line_in_array(const char *line);
extern "C" void __stdcall init_lines_array(char *lnar[],int maxsize);
extern "C" int __stdcall finish_makeline(bool restart_comments=false);
extern "C" int __stdcall generate_disassembly(
        ea_t ea,
        char *lines[],
        int bufsize,
        int *lnnum,
        bool as_stack);
extern "C" bool __stdcall generate_disasm_line(
        ea_t ea,
        char *buf,
        size_t bufsize,
        int flags=0);
int gen_labeled_line(ea_t ea);
int gen_lname_line(ea_t ea, bool make_null);
typedef bool __stdcall makeline_producer_t(const char *line, int indent);
makeline_producer_t *set_makeline_producer(makeline_producer_t *mp);
extern "C" const char *__stdcall closing_comment(void);
 char *close_comment(char *ptr, char *end)
{
  do { const char *__ida_in = (closing_comment()); while ( true ) { if ( ptr >= end ) { ptr = (end)-1; ptr[0] = '\0'; break; } if (( *ptr = *__ida_in++) == '\0' ) break; ptr++; } } while ( 0 );
  return ptr;
}
const int E_PREV = 1000;
const int E_NEXT = 2000;
void    copy_extra_lines(ea_t from, ea_t to, int what);
bool                  ExtraLines (ea_t ea, int start);
void                  ExtraKill  (ea_t ea);
extern "C" int __stdcall ExtraFree  (ea_t ea, int start);
int Dumper(ea_t EA, char* Answer[],int maxsize, void *ud);
 void init_lines(void) {}
 void save_lines(void) {}
       void term_lines(void);
extern char gl_namedone;
extern bool data_as_stack;
int calc_stack_alignment(ea_t ea);
extern "C" ea_t __stdcall align_down_to_stack(ea_t newea);
extern "C" ea_t __stdcall align_up_to_stack(ea_t ea1, ea_t ea2=ea_t(-1));
char *remove_spaces(char *buf, char *end, char *ptr);
#pragma pack(pop)
#pragma pack(push, 1)
typedef tid_t enum_t;
extern "C" error_t __stdcall enable_flags(ea_t startEA, ea_t endEA, storage_type_t stt);
extern "C" error_t __stdcall disable_flags(ea_t startEA, ea_t endEA);
extern "C" error_t __stdcall change_storage_type(ea_t startEA, ea_t endEA, storage_type_t stt);
extern "C" ea_t __stdcall nextaddr(ea_t ea);
extern "C" ea_t __stdcall prevaddr(ea_t ea);
extern "C" ea_t __stdcall nextchunk(ea_t ea);
extern "C" ea_t __stdcall prevchunk(ea_t ea);
extern "C" ea_t __stdcall chunkstart(ea_t ea);
extern "C" asize_t __stdcall chunksize(ea_t ea);
extern "C" ea_t __stdcall freechunk(ea_t bottom, asize_t size, int32 step);
typedef bool __stdcall testf_t(flags_t flags, void *ud);
extern "C" ea_t __stdcall nextthat(
        ea_t ea,
        ea_t maxea,
        testf_t *testf,
        void *ud);
 ea_t __stdcall next_unknown(ea_t ea, ea_t maxea)
{
  return nextthat(ea, maxea, 0, 0);
}
extern "C" ea_t __stdcall prevthat(
        ea_t ea,
        ea_t minea,
        testf_t *testf,
        void *ud);
 ea_t __stdcall prev_unknown(ea_t ea, ea_t minea)
{
  return prevthat(ea, minea, 0, 0);
}
extern "C" ea_t __stdcall prev_head(ea_t ea, ea_t minea);
extern "C" ea_t __stdcall next_head(ea_t ea, ea_t maxea);
extern "C" ea_t __stdcall prev_not_tail(ea_t ea);
extern "C" ea_t __stdcall next_not_tail(ea_t ea);
ea_t adjust_visea(ea_t ea);
extern "C" ea_t __stdcall prev_visea(ea_t ea);
extern "C" ea_t __stdcall next_visea(ea_t ea);
bool is_first_visea(ea_t ea);
bool is_last_visea(ea_t ea);
bool is_visible_finally(ea_t ea);
extern "C" void __stdcall invalidate_visea_cache(void);
 ea_t __stdcall get_item_head(ea_t ea);
extern "C" ea_t __stdcall get_item_end(ea_t ea);
extern "C" ea_t __stdcall calc_max_item_end(ea_t ea, int how=15);
 asize_t get_item_size(ea_t ea) { return get_item_end(ea) - ea; }
void flush_flags(void);
extern "C" bool __stdcall isEnabled(ea_t ea);
extern "C" flags_t __stdcall get_flags_ex(ea_t ea, int how);
 flags_t __stdcall get_flags_novalue(ea_t ea) { return get_flags_ex(ea, 0x0001); }
 flags_t __stdcall getFlags(ea_t ea) { return get_flags_ex(ea, 0); }
extern "C" flags_t __stdcall get_item_flag(ea_t from, int n, ea_t ea, bool appzero);
extern "C" void __stdcall setFlags(ea_t ea, flags_t flags);
extern "C" bool __stdcall setFlbits(ea_t EA, flags_t bits);
extern "C" bool __stdcall clrFlbits(ea_t EA, flags_t bits);
 bool __stdcall hasValue(flags_t F)  { return (F & 0x00000100L) != 0; }
 bool __stdcall f_hasValue(flags_t f, void *) { return hasValue(f); }
extern "C" void __stdcall delValue(ea_t ea);
extern "C" bool __stdcall isLoaded(ea_t ea);
extern "C" int __stdcall nbits(ea_t ea);
 int bytesize(ea_t ea)
          { return (nbits(ea)+7)/8; }
extern "C" uchar __stdcall get_byte(ea_t ea);
extern "C" uchar __stdcall get_db_byte(ea_t ea);
extern "C" bool __stdcall get_dbg_byte(ea_t ea, uint32 *x);
extern "C" ushort __stdcall get_word(ea_t ea);
extern "C" uint32 __stdcall get_3byte(ea_t ea);
extern "C" uint32 __stdcall get_long(ea_t ea);
extern "C" uint64 __stdcall get_qword(ea_t ea);
extern "C" uint32 __stdcall get_full_byte(ea_t ea);
extern "C" uint64 __stdcall get_full_word(ea_t ea);
extern "C" uint64 __stdcall get_full_long(ea_t ea);
extern "C" uchar __stdcall get_8bit(ea_t &ea, uint32 &v, int &nbit);
uchar get_ascii_char(ea_t &ea, uint32 &v, int &nb);
extern "C" uint32 __stdcall get_16bit(ea_t ea);
extern "C" uint32 __stdcall get_32bit(ea_t ea);
extern "C" uint64 __stdcall get_64bit(ea_t ea);
extern "C" bool __stdcall get_data_value(ea_t ea, uval_t *v, asize_t size);
extern "C" uint32 __stdcall get_original_byte(ea_t ea);
extern "C" uint64 __stdcall get_original_word(ea_t ea);
extern "C" uint64 __stdcall get_original_long(ea_t ea);
extern "C" bool __stdcall put_byte(ea_t ea, uint32 x);
extern "C" bool __stdcall put_dbg_byte(ea_t ea, uint32 x);
extern "C" void __stdcall put_word(ea_t ea, uint64 x);
extern "C" void __stdcall put_long(ea_t ea, uint64 x);
extern "C" void __stdcall put_qword(ea_t ea, uint64 x);
extern "C" bool __stdcall patch_byte(ea_t ea, uint32 x);
extern "C" bool __stdcall patch_word(ea_t ea, uint64 x);
extern "C" bool __stdcall patch_long(ea_t ea, uint64 x);
extern "C" void __stdcall add_byte(ea_t ea, uint32 value);
extern "C" void __stdcall add_word(ea_t ea, uint64 value);
extern "C" void __stdcall add_long(ea_t ea, uint64 value);
extern "C" void __stdcall add_qword(ea_t ea, uint64 value);
extern "C" bool __stdcall get_zero_areas(areaset_t *zareas, const area_t *range);
extern "C" int __stdcall get_many_bytes_ex(ea_t ea, void *buf, ssize_t size, void *mask);
extern "C" bool __stdcall get_many_bytes(ea_t ea, void *buf, ssize_t size);
extern "C" void __stdcall put_many_bytes(ea_t ea, const void *buf, size_t size);
extern "C" void __stdcall patch_many_bytes(ea_t ea, const void *buf, size_t size);
 bool __stdcall isCode(flags_t F)  { return (F & 0x00000600L) == 0x00000600L; }
 bool __stdcall f_isCode(flags_t F, void *) { return isCode(F); }
 bool __stdcall isData(flags_t F)  { return (F & 0x00000600L) == 0x00000400L; }
 bool __stdcall f_isData(flags_t F, void *) { return isData(F); }
 bool __stdcall isTail(flags_t F)    { return (F & 0x00000600L) == 0x00000200L; }
 bool __stdcall f_isTail(flags_t F, void *) { return isTail(F); }
 bool __stdcall isNotTail(flags_t F) { return !isTail(F); }
 bool __stdcall f_isNotTail(flags_t F, void *) { return isNotTail(F); }
 bool __stdcall isUnknown(flags_t F){return (F & 0x00000600L) == 0x00000000L;  }
 bool __stdcall isHead(flags_t F)  { return (F & 0x00000400L) != 0; }
 bool __stdcall f_isHead(flags_t F, void *) { return isHead(F); }
extern "C" void __stdcall do_unknown(ea_t ea, int flags);
extern "C" void __stdcall do_unknown_range(ea_t ea, size_t size, int flags);
extern "C" bool __stdcall is_manual_insn(ea_t ea);
extern "C" char *__stdcall get_manual_insn(ea_t ea,char *buf, size_t bufsize);
extern "C" void __stdcall set_manual_insn(ea_t ea,const char *manual_insn);
 bool __stdcall isFlow(flags_t F)     { return (F & 0x00010000L) != 0; }
 bool __stdcall isVar(flags_t F)      { return (F & 0x00080000L ) != 0; }
 bool __stdcall hasExtra(flags_t F)   { return (F & 0x00002000L) != 0; }
 bool __stdcall has_cmt(flags_t F)    { return (F & 0x00000800L) != 0; }
 bool __stdcall hasRef(flags_t F)     { return (F & 0x00001000L)  != 0; }
 bool __stdcall f_hasRef(flags_t f, void *) { return hasRef(f); }
 bool __stdcall has_name(flags_t F)   { return (F & 0x00004000L) != 0; }
 bool __stdcall f_has_name(flags_t f, void *) { return has_name(f); }
 bool __stdcall has_dummy_name(flags_t F){ return (F & (0x00008000L|0x00004000L)) == 0x00008000L; }
 bool __stdcall f_has_dummy_name(flags_t f, void *) { return has_dummy_name(f); }
 bool __stdcall has_auto_name(flags_t F){ return (F & (0x00008000L|0x00004000L)) == (0x00008000L|0x00004000L); }
 bool __stdcall has_any_name(flags_t F){ return (F & (0x00008000L|0x00004000L)) != 0; }
 bool __stdcall has_user_name(flags_t F){ return (F & (0x00008000L|0x00004000L)) == 0x00004000L; }
 bool __stdcall f_has_user_name(flags_t F, void *){ return has_user_name(F); }
extern "C" bool __stdcall is_invsign(ea_t ea, flags_t F, int n);
extern "C" bool __stdcall toggle_sign(ea_t ea, int n);
 flags_t __stdcall signed_data_flag(void) { return 0x00020000L; }
 bool __stdcall is_signed_data(flags_t F) { return (F & 0x00020000L) != 0; }
extern "C" bool __stdcall is_bnot(ea_t ea, flags_t F, int n);
extern "C" bool __stdcall toggle_bnot(ea_t ea, int n);
 flags_t __stdcall bnot_data_flag(void) { return 0x00040000L; }
 bool __stdcall is_bnot_data(flags_t F) { return (F & 0x00040000L) != 0; }
extern "C" bool __stdcall is_lzero(ea_t ea, int n);
extern "C" bool __stdcall set_lzero(ea_t ea, int n);
extern "C" bool __stdcall clr_lzero(ea_t ea, int n);
 bool __stdcall toggle_lzero(ea_t ea, int n)
{
  return (is_lzero(ea,n) ? clr_lzero : set_lzero)(ea,n);
}
extern "C" bool __stdcall leading_zero_important(ea_t ea, int n);
extern "C" void __stdcall doVar(ea_t ea,bool isvar=true);
 bool __stdcall isDefArg0(flags_t F) { return (F & 0x00F00000L) != 0x00000000L; }
 bool __stdcall isDefArg1(flags_t F) { return (F & 0x0F000000L) != 0x00000000L; }
 bool __stdcall isOff0(flags_t F)    { return (F & 0x00F00000L) == 0x00500000L;  }
 bool __stdcall isOff1(flags_t F)    { return (F & 0x0F000000L) == 0x05000000L;  }
 bool __stdcall isChar0(flags_t F)   { return (F & 0x00F00000L) == 0x00300000L; }
 bool __stdcall isChar1(flags_t F)   { return (F & 0x0F000000L) == 0x03000000L; }
 bool __stdcall isSeg0(flags_t F)    { return (F & 0x00F00000L) == 0x00400000L;  }
 bool __stdcall isSeg1(flags_t F)    { return (F & 0x0F000000L) == 0x04000000L;  }
 bool __stdcall isEnum0(flags_t F)   { return (F & 0x00F00000L) == 0x00800000L;  }
 bool __stdcall isEnum1(flags_t F)   { return (F & 0x0F000000L) == 0x08000000L;  }
 bool __stdcall isFop0(flags_t F)    { return (F & 0x00F00000L) == 0x00900000L;  }
 bool __stdcall isFop1(flags_t F)    { return (F & 0x0F000000L) == 0x09000000L;  }
 bool __stdcall isStroff0(flags_t F) { return (F & 0x00F00000L) == 0x00A00000L;  }
 bool __stdcall isStroff1(flags_t F) { return (F & 0x0F000000L) == 0x0A000000L;  }
 bool __stdcall isStkvar0(flags_t F) { return (F & 0x00F00000L) == 0x00B00000L;  }
 bool __stdcall isStkvar1(flags_t F) { return (F & 0x0F000000L) == 0x0B000000L;  }
 bool __stdcall isFloat0(flags_t F) { return (F & 0x00F00000L) == 0x00C00000L;  }
 bool __stdcall isFloat1(flags_t F) { return (F & 0x0F000000L) == 0x0C000000L;  }
 bool __stdcall isCustFmt0(flags_t F) { return (F & 0x00F00000L) == 0x00D00000L; }
 bool __stdcall isCustFmt1(flags_t F) { return (F & 0x0F000000L) == 0x0D000000L; }
extern "C" bool __stdcall isNum0(flags_t F);
extern "C" bool __stdcall isNum1(flags_t F);
 flags_t get_optype_flags0(flags_t F) { return F & 0x00F00000L; }
 flags_t get_optype_flags1(flags_t F) { return F & 0x0F000000L; }
extern "C" bool __stdcall isDefArg(flags_t F,int n);
extern "C" bool __stdcall isOff(flags_t F,int n);
extern "C" bool __stdcall isChar(flags_t F,int n);
extern "C" bool __stdcall isSeg(flags_t F,int n);
extern "C" bool __stdcall isEnum(flags_t F,int n);
extern "C" bool __stdcall isFop(flags_t F,int n);
extern "C" bool __stdcall isStroff(flags_t F,int n);
extern "C" bool __stdcall isStkvar(flags_t F,int n);
extern "C" bool __stdcall isFltnum(flags_t F,int n);
extern "C" bool __stdcall isCustFmt(flags_t F,int n);
extern "C" bool __stdcall isNum(flags_t F,int n);
extern "C" bool __stdcall isVoid(ea_t ea,flags_t F,int n);
extern "C" bool __stdcall set_op_type(ea_t ea,flags_t type,int n);
extern "C" flags_t __stdcall typeflag(ea_t ea,flags_t oldflag,flags_t type,int n);
extern "C" bool __stdcall op_seg(ea_t ea,int n);
extern "C" bool __stdcall op_enum(ea_t ea,int n,enum_t id, uchar serial);
extern "C" enum_t __stdcall get_enum_id(ea_t ea,int n, uchar *serial);
extern "C" bool __stdcall op_stroff(ea_t ea, int n, const tid_t *path, int path_len, adiff_t delta);
extern "C" bool __stdcall set_stroff_path(ea_t ea, int n, const tid_t *path, int plen, adiff_t delta);
extern "C" int __stdcall get_stroff_path(ea_t ea, int n, tid_t *path, adiff_t *delta);
extern "C" bool __stdcall del_stroff_path(ea_t ea, int n);
extern "C" bool __stdcall op_stkvar(ea_t ea,int n);
extern "C" bool __stdcall set_forced_operand(ea_t ea,int n,const char *op);
extern "C" ssize_t __stdcall get_forced_operand(ea_t ea, int n, char *buf, size_t bufsize);
extern "C" bool __stdcall is_forced_operand(ea_t ea, int n);
 flags_t __stdcall charflag(void) { return 0x03000000L|0x00300000L; }
 flags_t __stdcall offflag (void) { return 0x05000000L |0x00500000L ; }
 flags_t __stdcall enumflag(void) { return 0x08000000L|0x00800000L; }
 flags_t __stdcall stroffflag(void) { return 0x0A000000L|0x00A00000L; }
 flags_t __stdcall stkvarflag(void) { return 0x0B000000L|0x00B00000L; }
 flags_t __stdcall fltflag(void)  { return 0x0C000000L |0x00C00000L;  }
 flags_t __stdcall custfmtflag(void)  { return 0x0D000000L |0x00D00000L; }
 flags_t __stdcall segflag (void) { return 0x04000000L |0x00400000L;  }
extern "C" flags_t __stdcall numflag(void);
 flags_t __stdcall hexflag (void) { return 0x01000000L|0x00100000L; }
 flags_t __stdcall decflag (void) { return 0x02000000L|0x00200000L; }
 flags_t __stdcall octflag (void) { return 0x07000000L|0x00700000L; }
 flags_t __stdcall binflag (void) { return 0x06000000L|0x00600000L; }
 bool __stdcall op_chr(ea_t ea,int n) { return set_op_type(ea,charflag(),n); }
 bool __stdcall op_num(ea_t ea,int n) { return set_op_type(ea,numflag (),n); }
 bool __stdcall op_hex(ea_t ea,int n) { return set_op_type(ea,hexflag (),n); }
 bool __stdcall op_dec(ea_t ea,int n) { return set_op_type(ea,decflag (),n); }
 bool __stdcall op_oct(ea_t ea,int n) { return set_op_type(ea,octflag (),n); }
 bool __stdcall op_bin(ea_t ea,int n) { return set_op_type(ea,binflag (),n); }
 bool __stdcall op_flt(ea_t ea,int n) { return set_op_type(ea,fltflag (),n); }
extern "C" bool __stdcall op_custfmt(ea_t ea, int n, int fid);
extern "C" bool __stdcall noType(ea_t ea,int n);
extern "C" int __stdcall getDefaultRadix(void);
extern "C" int __stdcall getRadix(flags_t F,int n);
extern "C" int __stdcall getRadixEA(ea_t ea,int n);
 flags_t __stdcall codeflag(void) { return 0x00000600L; }
 flags_t __stdcall byteflag(void) { return 0x00000400L|0x00000000L; }
 flags_t __stdcall wordflag(void) { return 0x00000400L|0x10000000L; }
 flags_t __stdcall dwrdflag(void) { return 0x00000400L|0x20000000L; }
 flags_t __stdcall qwrdflag(void) { return 0x00000400L|0x30000000L; }
 flags_t __stdcall owrdflag(void) { return 0x00000400L|0x70000000L; }
 flags_t __stdcall tbytflag(void) { return 0x00000400L|0x40000000L; }
 flags_t __stdcall asciflag(void) { return 0x00000400L|0x50000000L; }
 flags_t __stdcall struflag(void) { return 0x00000400L|0x60000000L; }
 flags_t __stdcall custflag(void) { return 0x00000400L|0xD0000000L; }
 flags_t __stdcall alignflag(void) { return 0x00000400L|0xB0000000L; }
 flags_t __stdcall floatflag(void) { return 0x00000400L|0x80000000L; }
 flags_t __stdcall doubleflag(void) { return 0x00000400L|0x90000000L; }
 flags_t __stdcall tribyteflag(void) { return 0x00000400L|0xC0000000L; }
 flags_t __stdcall packrealflag(void) { return 0x00000400L|0xA0000000L; }
extern "C" flags_t __stdcall get_flags_by_size(size_t size);
extern "C" bool __stdcall do_data_ex(
        ea_t ea,
        flags_t dataflag,
        asize_t size,
        tid_t tid);
 bool __stdcall doByte(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x00000000L, length, nodeidx_t(-1)); }
 bool __stdcall doWord(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x10000000L, length, nodeidx_t(-1)); }
 bool __stdcall doDwrd(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x20000000L, length, nodeidx_t(-1)); }
 bool __stdcall doQwrd(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x30000000L, length, nodeidx_t(-1)); }
 bool __stdcall doOwrd(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x70000000L, length, nodeidx_t(-1)); }
 bool __stdcall doTbyt(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x40000000L, length, nodeidx_t(-1)); }
 bool __stdcall doFloat(ea_t ea, asize_t length)    { return do_data_ex(ea, 0x80000000L, length, nodeidx_t(-1)); }
 bool __stdcall doDouble(ea_t ea, asize_t length)   { return do_data_ex(ea, 0x90000000L, length, nodeidx_t(-1)); }
 bool __stdcall doPackReal(ea_t ea, asize_t length) { return do_data_ex(ea, 0xA0000000L, length, nodeidx_t(-1)); }
 bool __stdcall doASCI(ea_t ea, asize_t length)     { return do_data_ex(ea, 0x50000000L, length, nodeidx_t(-1)); }
 bool __stdcall do3byte(ea_t ea, asize_t length)    { return do_data_ex(ea, 0xC0000000L, length, nodeidx_t(-1)); }
 bool __stdcall doStruct(ea_t ea, asize_t length,tid_t tid) { return do_data_ex(ea, 0x60000000L, length, tid); }
 bool __stdcall doCustomData(ea_t ea, asize_t length, int dtid, int fid)
{
  return do_data_ex(ea, 0xD0000000L, length, dtid|(fid<<16));
}
extern "C" bool __stdcall doAlign(ea_t ea, asize_t length,int alignment);
extern "C" int  __stdcall calc_min_align( asize_t length);
extern "C" int  __stdcall calc_max_align(ea_t endea);
extern "C" int  __stdcall calc_def_align(ea_t ea, int mina, int maxa);
extern "C" bool __stdcall do16bit(ea_t ea, asize_t length);
extern "C" bool __stdcall do32bit(ea_t ea, asize_t length);
 bool __stdcall isByte  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x00000000L; }
 bool __stdcall isWord  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x10000000L; }
 bool __stdcall isDwrd  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x20000000L; }
 bool __stdcall isQwrd  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x30000000L; }
 bool __stdcall isOwrd  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x70000000L; }
 bool __stdcall isTbyt  (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x40000000L; }
 bool __stdcall isFloat (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x80000000L; }
 bool __stdcall isDouble(flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x90000000L; }
 bool __stdcall isPackReal(flags_t F) { return isData(F) && (F & 0xF0000000L) == 0xA0000000L; }
 bool __stdcall isASCII (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x50000000L; }
 bool __stdcall isStruct(flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0x60000000L; }
 bool __stdcall isAlign (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0xB0000000L; }
 bool __stdcall is3byte (flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0xC0000000L; }
 bool __stdcall isCustom(flags_t F)   { return isData(F) && (F & 0xF0000000L) == 0xD0000000L; }
 bool __stdcall f_isByte  (flags_t F, void *)   { return isByte(F); }
 bool __stdcall f_isWord  (flags_t F, void *)   { return isWord(F); }
 bool __stdcall f_isDwrd  (flags_t F, void *)   { return isDwrd(F); }
 bool __stdcall f_isQwrd  (flags_t F, void *)   { return isQwrd(F); }
 bool __stdcall f_isOwrd  (flags_t F, void *)   { return isOwrd(F); }
 bool __stdcall f_isTbyt  (flags_t F, void *)   { return isTbyt(F); }
 bool __stdcall f_isFloat (flags_t F, void *)   { return isFloat(F); }
 bool __stdcall f_isDouble(flags_t F, void *)   { return isDouble(F); }
 bool __stdcall f_isPackReal(flags_t F, void *) { return isPackReal(F); }
 bool __stdcall f_isASCII (flags_t F, void *)   { return isASCII(F); }
 bool __stdcall f_isStruct(flags_t F, void *)   { return isStruct(F); }
 bool __stdcall f_isAlign (flags_t F, void *)   { return isAlign(F); }
 bool __stdcall f_is3byte (flags_t F, void *)   { return is3byte(F); }
 bool __stdcall f_isCustom(flags_t F, void *)   { return isCustom(F); }
 bool __stdcall is_same_data_type(flags_t F1, flags_t F2) { return ((F1 ^ F2) & 0xF0000000L) == 0; }
extern "C" size_t __stdcall get_max_ascii_length(
        ea_t ea,
        int32 strtype,
        bool ignore_heads=false);
extern "C" bool __stdcall get_ascii_contents(
        ea_t ea,
        size_t len,
        int32 type,
        char *buf,
        size_t bufsize);
extern "C" bool __stdcall make_ascii_string(ea_t start, size_t len, int32 strtype);
extern "C" char *__stdcall print_ascii_string_type(
        char *buf,
        size_t bufsize,
        int32 strtype);
extern "C" opinfo_t *__stdcall get_opinfo(ea_t ea,
        int n,
        flags_t flags,
        opinfo_t *buf);
extern "C" bool __stdcall set_opinfo(ea_t ea,
        int n,
        flags_t flag,
        const opinfo_t *ti);
void del_opinfo(ea_t ea, flags_t flag);
void del_one_opinfo(ea_t ea, int n, flags_t flag);
extern "C" asize_t __stdcall get_data_elsize(ea_t ea, flags_t F, const opinfo_t *ti=0);
 asize_t get_full_data_elsize(ea_t ea, flags_t F, const opinfo_t *ti=0)
{
  asize_t nbytes = get_data_elsize(ea, F, ti);
  return nbytes * bytesize(ea);
}
extern "C" int __stdcall is_varsize_item(ea_t ea, flags_t F, const opinfo_t *ti=0, asize_t *itemsize=0);
extern "C" bool __stdcall can_define_item(ea_t ea, asize_t length, flags_t flags);
bool doCode(ea_t ea,int length);
 bool __stdcall isImmd(flags_t F)      { return isCode(F) && (F & 0x40000000L) != 0; }
 bool __stdcall isFunc(flags_t F)      { return isCode(F) && (F & 0x10000000L) != 0; }
extern "C" bool __stdcall doImmd(ea_t ea);
extern "C" bool __stdcall noImmd(ea_t ea);
 ushort __stdcall gettof(flags_t F) { return ushort((F & 0xFFF00000LU) >> (4*5)); }
struct data_type_t
{
  int cbsize;
  void *ud;
  int props;
  const char *name;
  const char *menu_name;
  const char *hotkey;
  const char *asm_keyword;
  asize_t value_size;
  bool (__stdcall *may_create_at)(
        void *ud,
        ea_t ea,
        size_t nbytes);
  asize_t (__stdcall *calc_item_size)(
        void *ud,
        ea_t ea,
        asize_t maxsize);
};
typedef qvector<const data_type_t *> data_types_t;
struct data_format_t
{
  int32 cbsize;
  void *ud;
  int props;
  const char *name;
  const char *menu_name;
  const char *hotkey;
  asize_t value_size;
  int32 text_width;
  bool (__stdcall *print)(
        void *ud,
        qstring *out,
        const void *value,
        asize_t size,
        ea_t current_ea,
        int operand_num,
        int dtid);
  bool (__stdcall *scan)(
        void *ud,
        bytevec_t *value,
        const char *input,
        ea_t current_ea,
        int operand_num,
        qstring *errstr);
  void (__stdcall *analyze)(
        void *ud,
        ea_t current_ea,
        int operand_num);
};
typedef qvector<const data_format_t *> data_formats_t;
extern "C" int __stdcall register_custom_data_type(const data_type_t *dtinfo);
extern "C" bool __stdcall unregister_custom_data_type(int dtid);
extern "C" int __stdcall register_custom_data_format(int dtid, const data_format_t *dtform);
extern "C" bool __stdcall unregister_custom_data_format(int dtid, int fid);
extern "C" const data_type_t *__stdcall get_custom_data_type(int dtid);
extern "C" const data_format_t *__stdcall get_custom_data_format(int dtid, int fid);
extern "C" int __stdcall get_custom_data_types(
        intvec_t *out,
        asize_t min_size=0,
        asize_t max_size=ea_t(-1));
extern "C" int __stdcall get_custom_data_formats(intvec_t *out, int dtid);
extern "C" int __stdcall find_custom_data_type(const char *name);
extern "C" int __stdcall find_custom_data_format(const char *name);
extern "C" bool __stdcall set_cmt(ea_t ea, const char *comm, bool rptble);
extern "C" ssize_t __stdcall get_cmt(ea_t ea, bool rptble, char *buf, size_t bufsize);
char *get_repeatable_cmt(ea_t ea);
char *get_any_indented_cmt(ea_t ea, color_t *cmttype);
extern "C" bool __stdcall append_cmt(ea_t ea, const char *str, bool rptble);
extern bool del_code_comments;
extern "C" ea_t __stdcall find_byte(ea_t sEA, asize_t size, uchar value, bool sense_case);
extern "C" ea_t __stdcall find_byter(ea_t sEA, asize_t size, uchar value, bool sense_case);
extern "C" ea_t __stdcall bin_search(
                 ea_t startEA,
                 ea_t endEA,
                 const uchar *image,
                 const uchar *mask,
                 size_t len,
                 int step,
                 int flags);
extern "C" bool __stdcall equal_bytes(
        ea_t ea,
        const uchar *image,
        const uchar *mask,
        size_t len,
        bool sense_case);
extern "C" void __stdcall set_dbgmem_source(
        area_t *(__stdcall*dbg_get_memory_config)(int *n),
        int (__stdcall*memory_read) (ea_t ea, void *buffer, int size),
        int (__stdcall*memory_write)(ea_t ea, const void *buffer, int size));
extern "C" void __stdcall invalidate_dbgmem_config(void);
extern "C" void __stdcall invalidate_dbgmem_contents(ea_t ea, asize_t size);
extern "C" bool __stdcall is_debugger_on(void);
struct hidden_area_t : public area_t
{
  char *description;
  char *header;
  char *footer;
  bool visible;
  bgcolor_t color;
};
extern "C" areacb_t __declspec(dllimport) hidden_areas;
 bool __stdcall update_hidden_area(hidden_area_t *ha)
  { invalidate_visea_cache(); return hidden_areas.update(ha) != 0; }
extern "C" bool __stdcall add_hidden_area(ea_t ea1,
                                       ea_t ea2,
                                       const char *description,
                                       const char *header,
                                       const char *footer,
                                       bgcolor_t color);
 hidden_area_t *__stdcall get_hidden_area(ea_t ea)
  { return (hidden_area_t *)hidden_areas.get_area(ea); }
 hidden_area_t *__stdcall getn_hidden_area(int n)
  { return (hidden_area_t *)hidden_areas.getn_area(n); }
 int __stdcall get_hidden_area_qty(void)
  { return hidden_areas.get_area_qty(); }
 int __stdcall get_hidden_area_num(ea_t ea)
  { return hidden_areas.get_area_num(ea); }
 hidden_area_t *__stdcall get_prev_hidden_area(ea_t ea)
  { return getn_hidden_area(hidden_areas.get_prev_area(ea)); }
 hidden_area_t *__stdcall get_next_hidden_area(ea_t ea)
  { return getn_hidden_area(hidden_areas.get_next_area(ea)); }
 bool __stdcall del_hidden_area(ea_t ea)
  { return hidden_areas.del_area(ea); }
bool doRef(ea_t ea);
bool noRef(ea_t ea);
 bool __stdcall doExtra(ea_t ea) { return setFlbits(ea, 0x00002000L); }
 bool __stdcall noExtra(ea_t ea) { return clrFlbits(ea, 0x00002000L); }
asize_t coagulate(ea_t ea);
bool coagulate_dref(ea_t From, ea_t To, flags_t F, bool may_define);
 ea_t __stdcall get_item_head(ea_t ea)
{
  if ( isTail(get_flags_novalue(ea)) )
    ea = prev_not_tail(ea);
  return ea;
}
void init_hidden_areas(void);
void save_hidden_areas(void);
void term_hidden_areas(void);
int check_move_args(ea_t from, ea_t to, asize_t size);
int movechunk(ea_t from, ea_t to, asize_t size);
void lock_dbgmem_config(void);
void unlock_dbgmem_config(void);
bool set_op_type_no_event(ea_t ea, flags_t type, int n);
uint32 shuffle_tribytes(uchar b1, uchar b2, uchar b3);
void validate_tofs(void);
bool set_flags_nomark(ea_t ea, flags_t bits);
bool set_flbits_nomark(ea_t ea, flags_t bits);
bool clr_flbits_nomark(ea_t ea, flags_t bits);
extern ushort ida_vpagesize;
extern ushort ida_vpages;
extern ushort ida_npagesize;
extern ushort ida_npages;
extern int fpnum_digits;
extern int fpnum_length;
void init_flags(uint32 input_size);
void term_flags(void);
bool reset_flags(void);
extern "C" asize_t __stdcall get_data_type_size(flags_t F, const opinfo_t *ti);
 bool __stdcall f_isUnknown(flags_t F, void *) { return isUnknown(F); }
extern "C" const uint32 __declspec(dllimport) power2[32];
extern "C" const uint32 __declspec(dllimport) lowbits[33];
extern "C" void __stdcall set_enum_id(ea_t ea, int n, enum_t id, uchar serial);
extern "C" error_t __stdcall FlagsEnable(ea_t startEA, ea_t endEA);
extern "C" error_t __stdcall FlagsDisable(ea_t startEA, ea_t endEA);
extern "C" opinfo_t *__stdcall get_typeinfo(ea_t ea, int n, flags_t flags, opinfo_t *buf);
extern "C" bool __stdcall set_typeinfo(ea_t ea, int n, flags_t flag, const opinfo_t *ti);
#pragma pack(pop)
#pragma pack(push, 1)
struct stkpnt_t;
struct regvar_t;
struct llabel_t;
struct regarg_t
{
  int reg;
  type_t *type;
  char *name;
};
class func_t : public area_t
{
public:
  ushort flags;
  bool is_far(void) const { return (flags & 0x00000002) != 0; }
  bool does_return(void) const { return (flags & 0x00000001) == 0; }
  bool analyzed_sp(void) const { return (flags & 0x00000400) != 0; }
  union
  {
    struct
    {
      uval_t frame;
      asize_t frsize;
      ushort frregs;
      asize_t argsize;
      asize_t fpd;
      bgcolor_t color;
      ushort pntqty;
      stkpnt_t *points;
      int regvarqty;
      regvar_t *regvars;
      int llabelqty;
      llabel_t *llabels;
      int regargqty;
      regarg_t *regargs;
      int tailqty;
      area_t *tails;
    };
    struct
    {
      ea_t owner;
      int refqty;
      ea_t *referers;
    };
  };
};
template <> struct ida_movable_type<func_t> { typedef ida_true_type is_movable_type; };
 bool is_func_entry(const func_t *pfn) { return pfn != 0 && (pfn->flags & 0x00008000) == 0; }
 bool is_func_tail(const func_t *pfn) { return pfn != 0 && (pfn->flags & 0x00008000) != 0; }
extern "C" areacb_t __declspec(dllimport) funcs;
class lock_func
{
  const func_t *pfn;
public:
  lock_func(const func_t *_pfn) : pfn(_pfn)
  {
    areacb_t_lock_area(&funcs, pfn);
  }
  ~lock_func(void)
  {
    areacb_t_unlock_area(&funcs, pfn);
  }
};
 bool is_func_locked(const func_t *pfn)
{
  return areacb_t_get_area_locks(&funcs, pfn) > 0;
}
extern "C" func_t *__stdcall get_func(ea_t ea);
extern "C" int __stdcall get_func_chunknum(func_t *pfn, ea_t ea);
 bool func_contains(func_t *pfn, ea_t ea)
{
  return get_func_chunknum(pfn, ea) >= 0;
}
extern "C" func_t *__stdcall getn_func(size_t n);
extern "C" size_t __stdcall get_func_qty(void);
extern "C" int __stdcall get_func_num(ea_t ea);
extern "C" func_t *__stdcall get_prev_func(ea_t ea);
extern "C" func_t *__stdcall get_next_func(ea_t ea);
extern "C" bool __stdcall get_func_limits(func_t *pfn, area_t *limits);
 char *get_func_cmt(func_t *fn ,bool repeatable)
                { return funcs.get_area_cmt(fn, repeatable); }
 bool set_func_cmt(func_t *fn, const char *cmt, bool repeatable)
                { return funcs.set_area_cmt(fn, cmt, repeatable); }
 void del_func_cmt(func_t *fn, bool repeatable)
                { funcs.del_area_cmt(fn, repeatable); }
 bool update_func(func_t *fn) { return funcs.update(fn) != 0; }
extern "C" bool __stdcall  add_func_ex(func_t *fn);
extern "C" bool __stdcall add_func(ea_t ea1, ea_t ea2);
extern "C" bool __stdcall del_func(ea_t ea);
extern "C" int __stdcall func_setstart(ea_t ea, ea_t newstart);
extern "C" bool __stdcall func_setend(ea_t ea, ea_t newend);
extern "C" void __stdcall reanalyze_function(func_t *pfn,
                                          ea_t ea1=0,
                                          ea_t ea2=ea_t(-1),
                                          bool analyze_parents=false);
extern "C" void __stdcall clear_func_struct(func_t *fn);
extern "C" int __stdcall find_func_bounds(ea_t ea, func_t *nfn, int flags);
extern "C" char *__stdcall get_func_name(ea_t ea, char *buf, size_t bufsize);
extern "C" int __stdcall get_func_bitness(const func_t *pfn);
 int __stdcall get_func_bits(func_t *pfn) { return 1 << (get_func_bitness(pfn)+4); }
 int __stdcall get_func_bytes(func_t *pfn) { return get_func_bits(pfn)/8; }
 bool is_visible_func(func_t *pfn) { return (pfn->flags & 0x00000040) == 0; }
 bool is_finally_visible_func(func_t *pfn)
 { return (inf.s_cmtflg & 0x40) != 0 || is_visible_func(pfn); }
extern "C" void __stdcall set_visible_func(func_t *pfn, bool visible);
extern "C" int __stdcall set_func_name_if_jumpfunc(func_t *fn, const char *oldname);
extern "C" ea_t __stdcall calc_thunk_func_target(func_t *fn, ea_t *fptr);
extern "C" char *__stdcall a2funcoff(ea_t ea, char *buf, size_t bufsize);
extern "C" void __stdcall std_gen_func_header(func_t *pfn);
extern "C" bool __stdcall func_does_return(ea_t callee);
extern "C" bool __stdcall set_noret_insn(ea_t insn_ea, bool noret);
 func_t *get_fchunk(ea_t ea) { return (func_t *)funcs.get_area(ea); }
 func_t *getn_fchunk(int n) { return (func_t *)funcs.getn_area(n); }
 size_t get_fchunk_qty(void) { return funcs.get_area_qty(); }
 int get_fchunk_num(ea_t ea) { return funcs.get_area_num(ea); }
 func_t *get_prev_fchunk(ea_t ea) { return getn_fchunk(funcs.get_prev_area(ea)); }
 func_t *get_next_fchunk(ea_t ea) { return getn_fchunk(funcs.get_next_area(ea)); }
extern "C" bool __stdcall append_func_tail(func_t *pfn, ea_t ea1, ea_t ea2);
extern "C" bool __stdcall remove_func_tail(func_t *pfn, ea_t tail_ea);
extern "C" bool __stdcall set_tail_owner(func_t *fnt, ea_t func_start);
class func_parent_iterator_t;
class func_tail_iterator_t;
class func_item_iterator_t;
extern "C" bool __stdcall func_tail_iterator_set(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);extern "C" bool __stdcall func_tail_iterator_set2(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);extern "C" bool __stdcall func_tail_iterator_set_ea(func_tail_iterator_t *fti, ea_t ea);extern "C" bool __stdcall func_parent_iterator_set(func_parent_iterator_t *fpi, func_t *pfn);extern "C" bool __stdcall func_parent_iterator_set2(func_parent_iterator_t *fpi, func_t *pfn);extern "C" bool __stdcall func_item_iterator_next(func_item_iterator_t *fii, testf_t *testf, void *ud);extern "C" bool __stdcall func_item_iterator_prev(func_item_iterator_t *fii, testf_t *testf, void *ud);extern "C" bool __stdcall func_item_iterator_decode_prev_insn(func_item_iterator_t *fii);extern "C" bool __stdcall func_item_iterator_decode_preceding_insn(func_item_iterator_t *fii, eavec_t *visited, bool *p_farref);
 bool __stdcall f_any(flags_t, void *) { return true; }
class func_tail_iterator_t
{
  friend bool __stdcall func_tail_iterator_set(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set2(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set_ea(func_tail_iterator_t *fti, ea_t ea);friend bool __stdcall func_parent_iterator_set(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_parent_iterator_set2(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_item_iterator_next(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_prev(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_decode_prev_insn(func_item_iterator_t *fii);friend bool __stdcall func_item_iterator_decode_preceding_insn(func_item_iterator_t *fii, eavec_t *visited, bool *p_farref);
  func_t *pfn;
  int idx;
  area_t seglim;
public:
  func_tail_iterator_t(void) : pfn(0) {}
  func_tail_iterator_t(func_t *_pfn, ea_t ea=ea_t(-1)) : pfn(0) { set(_pfn, ea); }
  ~func_tail_iterator_t(void)
  {
    if ( pfn != 0 )
      areacb_t_unlock_area(&funcs, pfn);
  }
  bool set(func_t *_pfn, ea_t ea=ea_t(-1)) { return func_tail_iterator_set2(this, _pfn, ea); }
  bool set_ea(ea_t ea) { return func_tail_iterator_set_ea(this, ea); }
  bool set_range(ea_t ea1, ea_t ea2)
  {
    this->~func_tail_iterator_t();
    pfn = 0;
    idx = -1;
    seglim = area_t(ea1, ea2);
    return !seglim.empty();
  }
  const area_t &chunk(void) const { if ( pfn == 0 ) return seglim; return idx >= 0 ? pfn->tails[idx] : *(area_t*)pfn; }
  bool first(void) { if ( pfn != 0 ) { idx = 0; return pfn->tailqty > 0; } return false; }
  bool last(void) { if ( pfn != 0 ) { idx = pfn->tailqty - 1; return true; } return false; }
  bool next(void) { if ( pfn != 0 && idx+1 < pfn->tailqty ) { idx++; return true; } return false; }
  bool prev(void) { if ( idx >= 0 ) { idx--; return true; } return false; }
  bool main(void) { idx = -1; return pfn != 0; }
};
extern "C" void __stdcall iterate_func_chunks(
                          func_t *pfn,
                          void (__stdcall *func)(ea_t ea1, ea_t ea2, void *ud),
                          void *ud=0,
                          bool include_parents=false);
class func_item_iterator_t
{
  friend bool __stdcall func_tail_iterator_set(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set2(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set_ea(func_tail_iterator_t *fti, ea_t ea);friend bool __stdcall func_parent_iterator_set(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_parent_iterator_set2(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_item_iterator_next(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_prev(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_decode_prev_insn(func_item_iterator_t *fii);friend bool __stdcall func_item_iterator_decode_preceding_insn(func_item_iterator_t *fii, eavec_t *visited, bool *p_farref);
  func_tail_iterator_t fti;
  ea_t ea;
public:
  func_item_iterator_t(void) {}
  func_item_iterator_t(func_t *pfn, ea_t ea=ea_t(-1)) { set(pfn, ea); }
  bool set(func_t *pfn, ea_t _ea=ea_t(-1))
  {
    ea = (_ea != ea_t(-1) || pfn == 0) ? _ea : pfn->startEA;
    return fti.set(pfn, _ea);
   }
  bool set_range(ea_t ea1, ea_t ea2) { ea = ea1; return fti.set_range(ea1, ea2); }
  bool first(void) { if ( !fti.main() ) return false; ea=fti.chunk().startEA; return true; }
  bool last(void) { if ( !fti.last() ) return false; ea=fti.chunk().endEA; return true; }
  ea_t current(void) const { return ea; }
  const area_t &chunk(void) const { return fti.chunk(); }
  bool next(testf_t *func, void *ud) { return func_item_iterator_next(this, func, ud); }
  bool prev(testf_t *func, void *ud) { return func_item_iterator_prev(this, func, ud); }
  bool next_addr(void) { return next(f_any, 0); }
  bool next_head(void) { return next(f_isHead, 0); }
  bool next_code(void) { return next(f_isCode, 0); }
  bool next_data(void) { return next(f_isData, 0); }
  bool next_not_tail(void) { return next(f_isNotTail, 0); }
  bool prev_addr(void) { return prev(f_any, 0); }
  bool prev_head(void) { return prev(f_isHead, 0); }
  bool prev_code(void) { return prev(f_isCode, 0); }
  bool prev_data(void) { return prev(f_isData, 0); }
  bool prev_not_tail(void) { return prev(f_isNotTail, 0); }
  bool decode_prev_insn(void) { return func_item_iterator_decode_prev_insn(this); }
  bool decode_preceding_insn(eavec_t *visited, bool *p_farref)
    { return func_item_iterator_decode_preceding_insn(this, visited, p_farref); }
};
class func_parent_iterator_t
{
  friend bool __stdcall func_tail_iterator_set(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set2(func_tail_iterator_t *fti, func_t *pfn, ea_t ea);friend bool __stdcall func_tail_iterator_set_ea(func_tail_iterator_t *fti, ea_t ea);friend bool __stdcall func_parent_iterator_set(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_parent_iterator_set2(func_parent_iterator_t *fpi, func_t *pfn);friend bool __stdcall func_item_iterator_next(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_prev(func_item_iterator_t *fii, testf_t *testf, void *ud);friend bool __stdcall func_item_iterator_decode_prev_insn(func_item_iterator_t *fii);friend bool __stdcall func_item_iterator_decode_preceding_insn(func_item_iterator_t *fii, eavec_t *visited, bool *p_farref);
  func_t *fnt;
  int idx;
public:
  func_parent_iterator_t(void) : fnt(0) {}
  func_parent_iterator_t(func_t *_fnt) : fnt(0) { set(_fnt); }
  ~func_parent_iterator_t(void)
  {
    if ( fnt != 0 )
      areacb_t_unlock_area(&funcs, fnt);
  }
  bool set(func_t *_fnt) { return func_parent_iterator_set2(this, _fnt); }
  ea_t parent(void) const { return fnt->referers[idx]; }
  bool first(void) { idx = 0; return is_func_tail(fnt) && fnt->refqty > 0; }
  bool last(void) { idx = fnt->refqty - 1; return idx >= 0; }
  bool next(void) { if ( idx+1 < fnt->refqty ) { idx++; return true; } return false; }
  bool prev(void) { if ( idx > 0 ) { idx--; return true; } return false; }
  void reset_fnt(func_t *_fnt) { fnt = _fnt; }
};
extern "C" ea_t __stdcall get_prev_func_addr(func_t *pfn, ea_t ea);
extern "C" ea_t __stdcall get_next_func_addr(func_t *pfn, ea_t ea);
extern "C" void __stdcall read_regargs(func_t *pfn);
extern "C" void __stdcall add_regarg(func_t *pfn, int reg, const type_t *type, const char *name);
void del_regargs(ea_t ea);
int write_regargs(func_t *pfn);
regarg_t *find_regarg(func_t *pfn, int reg);
void free_regarg(regarg_t *v);
extern "C" int __stdcall plan_to_apply_idasgn(const char *fname);
extern "C" bool __stdcall apply_idasgn(int advance);
extern "C" int __stdcall apply_idasgn_to(const char *signame, ea_t ea, bool is_startup);
extern "C" int __stdcall get_idasgn_qty(void);
extern "C" int __stdcall get_current_idasgn(void);
extern "C" int __stdcall calc_idasgn_state(int n);
extern "C" int __stdcall del_idasgn(int n);
extern "C" int32 __stdcall get_idasgn_desc(
        int n,
        char *signame,
        size_t signamesize,
        char *optlibs,
        size_t optlibssize);
extern "C" char *__stdcall get_sig_filename(
        char *buf,
        size_t bufsize,
        const char *signame);
class idasgn_t;
extern "C" idasgn_t *__stdcall get_idasgn_header_by_short_name(const char *name);
extern "C" char *__stdcall get_idasgn_title(
        const char *name,
        char *buf,
        size_t bufsize);
extern "C" void __stdcall determine_rtl(void);
extern "C" bool __stdcall apply_startup_sig(ea_t ea, const char *startup);
extern "C" int __stdcall try_to_add_libfunc(ea_t ea);
       void init_signatures(void);
 void save_signatures(void) {}
       void term_signatures(void);
void init_funcs(void);
void save_funcs(void);
void term_funcs(void);
void move_funcs(ea_t from, ea_t to, asize_t size);
bool copy_noret_info(func_t *fn, ea_t to, const char *name=0);
void recalc_func_noret_flag(func_t *pfn);
bool plan_for_noret_analysis(ea_t insn_ea);
bool invalidate_sp_analysis(func_t *pfn);
 bool invalidate_sp_analysis(ea_t ea)
  { return invalidate_sp_analysis(get_func(ea)); }
void create_func_eas_array(void);
ea_t auto_add_func_tails(ea_t ea);
bool read_tails(func_t *pfn);
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
typedef uchar color_t;
typedef uval_t bmask_t;
typedef tid_t enum_t;
struct areavec_t;
enum mbox_kind_t
{
  mbox_internal,
  mbox_info,
  mbox_warning,
  mbox_error,
  mbox_nomem,
  mbox_feedback,
  mbox_readerror,
  mbox_writeerror,
  mbox_filestruct,
  mbox_wait,
  mbox_hide,
  mbox_replace,
};
enum choose_type_t
{
  chtype_generic,
  chtype_idasgn,
  chtype_entry,
  chtype_name,
  chtype_stkvar_xref,
  chtype_xref,
  chtype_enum,
  chtype_enum_by_value,
  chtype_func,
  chtype_segm,
  chtype_segreg,
  chtype_struc,
  chtype_strpath,
  chtype_generic2,
  chtype_idatil,
};
enum beep_t
{
  beep_default = 0
};
class func_t;
class segment_t;
class segreg_t;
class struc_t;
class member_t;
class TView;
class plugin_t;
class minsn_t;
class idc_value_t;
class linput_t;
union callui_t
{
  bool cnd;
  char i8;
  int i;
  short i16;
  int32 i32;
  uchar u8;
  ushort u16;
  uint32 u32;
  char *cptr;
  void *vptr;
  func_t *fptr;
  segment_t *segptr;
  segreg_t *sregptr;
  struc_t *strptr;
  plugin_t *pluginptr;
};
typedef char COMPILE_TIME_ASSERT_113 [(sizeof(callui_t) <= sizeof(size_t)) ? 1 : -1];
enum ui_notification_t
{
  ui_null = 0,
  ui_range,
  ui_list,
  ui_idcstart,
  ui_idcstop,
  ui_suspend,
  ui_resume,
  ui_jumpto,
  ui_readsel,
  ui_unmarksel,
  ui_screenea,
  ui_saving,
  ui_saved,
  ui_refreshmarked,
  ui_refresh,
  ui_choose,
  ui_close_chooser,
  ui_banner,
  ui_setidle,
  ui_noabort,
  ui_term,
  ui_mbox,
  ui_beep,
  ui_msg,
  ui_askyn,
  ui_askfile,
  ui_form,
  ui_close_form,
  ui_clearbreak,
  ui_wasbreak,
  ui_asktext,
  ui_askstr,
  ui_askident,
  ui_askaddr,
  ui_askseg,
  ui_asklong,
  ui_showauto,
  ui_setstate,
  ui_add_idckey,
  ui_del_idckey,
  ui_old_get_marker,
  ui_analyzer_options,
  ui_is_msg_inited,
  ui_load_file,
  ui_run_dbg,
  ui_get_cursor,
  ui_get_curline,
  ui_get_hwnd,
  ui_copywarn,
  ui_getvcl,
  ui_idp_event,
  ui_lock_range_refresh,
  ui_unlock_range_refresh,
  ui_setbreak,
  ui_genfile_callback,
  ui_open_url,
  ui_hexdumpea,
  ui_set_xml,
  ui_get_xml,
  ui_del_xml,
  ui_push_xml,
  ui_pop_xml,
  ui_get_key_code,
  ui_setup_plugins_menu,
  ui_refresh_navband,
  ui_new_custom_viewer,
  ui_add_menu_item,
  ui_del_menu_item,
  ui_debugger_menu_change,
  ui_get_curplace,
  ui_create_tform,
  ui_open_tform,
  ui_close_tform,
  ui_switchto_tform,
  ui_find_tform,
  ui_get_current_tform,
  ui_get_tform_handle,
  ui_tform_visible,
  ui_tform_invisible,
  ui_get_ea_hint,
  ui_get_item_hint,
  ui_set_nav_colorizer,
  ui_refresh_custom_viewer,
  ui_destroy_custom_viewer,
  ui_jump_in_custom_viewer,
  ui_set_custom_viewer_popup,
  ui_add_custom_viewer_popup,
  ui_set_custom_viewer_handlers,
  ui_get_custom_viewer_curline,
  ui_get_current_viewer,
  ui_is_idaview,
  ui_get_custom_viewer_hint,
  ui_readsel2,
  ui_set_custom_viewer_range,
  ui_database_inited,
  ui_ready_to_run,
  ui_set_custom_viewer_handler,
  ui_refresh_chooser,
  ui_add_chooser_cmd,
  ui_open_builtin,
  ui_preprocess,
  ui_postprocess,
  ui_set_custom_viewer_mode,
  ui_gen_disasm_text,
  ui_gen_idanode_text,
  ui_install_cli,
  ui_execute_sync,
  ui_enable_input_hotkeys,
  ui_get_chooser_obj,
  ui_enable_chooser_item_attrs,
  ui_get_chooser_item_attrs,
  ui_set_dock_pos,
  ui_get_opnum,
  ui_install_custom_datatype_menu,
  ui_install_custom_optype_menu,
  ui_get_range_marker,
  ui_get_highlighted_identifier,
  ui_lookup_key_code,
  ui_load_custom_icon_file,
  ui_load_custom_icon,
  ui_free_custom_icon,
  ui_process_action,
  ui_last,
  ui_dbg_begin = 1000,
  ui_dbg_run_requests = ui_dbg_begin,
  ui_dbg_get_running_request,
  ui_dbg_get_running_notification,
  ui_dbg_clear_requests_queue,
  ui_dbg_get_process_state,
  ui_dbg_start_process,
  ui_dbg_request_start_process,
  ui_dbg_suspend_process,
  ui_dbg_request_suspend_process,
  ui_dbg_continue_process,
  ui_dbg_request_continue_process,
  ui_dbg_exit_process,
  ui_dbg_request_exit_process,
  ui_dbg_get_thread_qty,
  ui_dbg_getn_thread,
  ui_dbg_select_thread,
  ui_dbg_request_select_thread,
  ui_dbg_step_into,
  ui_dbg_request_step_into,
  ui_dbg_step_over,
  ui_dbg_request_step_over,
  ui_dbg_run_to,
  ui_dbg_request_run_to,
  ui_dbg_step_until_ret,
  ui_dbg_request_step_until_ret,
  ui_dbg_get_oldreg_val,
  ui_dbg_set_oldreg_val,
  ui_dbg_request_set_oldreg_val,
  ui_dbg_get_bpt_qty,
  ui_dbg_getn_oldbpt,
  ui_dbg_get_oldbpt,
  ui_dbg_add_bpt,
  ui_dbg_request_add_bpt,
  ui_dbg_del_bpt,
  ui_dbg_request_del_bpt,
  ui_dbg_update_oldbpt,
  ui_dbg_enable_bpt,
  ui_dbg_request_enable_bpt,
  ui_dbg_set_trace_size,
  ui_dbg_clear_trace,
  ui_dbg_request_clear_trace,
  ui_dbg_is_step_trace_enabled,
  ui_dbg_enable_step_trace,
  ui_dbg_request_enable_step_trace,
  ui_dbg_get_step_trace_options,
  ui_dbg_set_step_trace_options,
  ui_dbg_request_set_step_trace_options,
  ui_dbg_is_insn_trace_enabled,
  ui_dbg_enable_insn_trace,
  ui_dbg_request_enable_insn_trace,
  ui_dbg_get_insn_trace_options,
  ui_dbg_set_insn_trace_options,
  ui_dbg_request_set_insn_trace_options,
  ui_dbg_is_func_trace_enabled,
  ui_dbg_enable_func_trace,
  ui_dbg_request_enable_func_trace,
  ui_dbg_get_func_trace_options,
  ui_dbg_set_func_trace_options,
  ui_dbg_request_set_func_trace_options,
  ui_dbg_get_tev_qty,
  ui_dbg_get_tev_info,
  ui_dbg_get_insn_tev_oldreg_val,
  ui_dbg_get_insn_tev_oldreg_result,
  ui_dbg_get_call_tev_callee,
  ui_dbg_get_ret_tev_return,
  ui_dbg_get_bpt_tev_ea,
  ui_dbg_get_reg_value_type,
  ui_dbg_get_process_qty,
  ui_dbg_get_process_info,
  ui_dbg_attach_process,
  ui_dbg_request_attach_process,
  ui_dbg_detach_process,
  ui_dbg_request_detach_process,
  ui_dbg_get_first_module,
  ui_dbg_get_next_module,
  ui_dbg_bring_to_front,
  ui_dbg_get_current_thread,
  ui_dbg_wait_for_next_event,
  ui_dbg_get_debug_event,
  ui_dbg_set_debugger_options,
  ui_dbg_set_remote_debugger,
  ui_dbg_load_debugger,
  ui_dbg_retrieve_exceptions,
  ui_dbg_store_exceptions,
  ui_dbg_define_exception,
  ui_dbg_suspend_thread,
  ui_dbg_request_suspend_thread,
  ui_dbg_resume_thread,
  ui_dbg_request_resume_thread,
  ui_dbg_get_process_options,
  ui_dbg_check_bpt,
  ui_dbg_set_process_state,
  ui_dbg_get_manual_regions,
  ui_dbg_set_manual_regions,
  ui_dbg_enable_manual_regions,
  ui_dbg_set_process_options,
  ui_dbg_is_busy,
  ui_dbg_hide_all_bpts,
  ui_dbg_edit_manual_regions,
  ui_dbg_get_reg_val,
  ui_dbg_set_reg_val,
  ui_dbg_request_set_reg_val,
  ui_dbg_get_insn_tev_reg_val,
  ui_dbg_get_insn_tev_reg_result,
  ui_dbg_register_provider,
  ui_dbg_unregister_provider,
  ui_dbg_handle_debug_event,
  ui_dbg_add_vmod,
  ui_dbg_del_vmod,
  ui_dbg_compare_bpt_locs,
  ui_dbg_save_bpts,
  ui_dbg_getn_bpt,
  ui_dbg_get_bpt,
  ui_dbg_update_bpt,
  ui_dbg_set_bptloc_string,
  ui_dbg_get_bptloc_string,
  ui_dbg_internal_appcall,
  ui_dbg_internal_cleanup_appcall,
  ui_dbg_internal_get_sreg_base,
  ui_dbg_internal_ioctl,
  ui_dbg_end,
};
extern "C" void __stdcall init_kernel(
                  callui_t (__stdcall*_callui)(ui_notification_t what,...),
                  int argc,
                  char *argv[]);
extern "C" callui_t __declspec(dllimport) (__stdcall*callui)(ui_notification_t what,...);
extern "C" int __stdcall init_database(int argc, const char *const *argv, int *newfile);
extern "C" void __stdcall term_database(void);
extern "C" void __stdcall term_kernel(void);
 bool get_kernel_version(char *buf, size_t bufsize)
{
  return callui(ui_clearbreak, 0x23967034, 0xAAEE67BE, buf, bufsize).cnd;
}
extern "C" __declspec(noreturn)  void __stdcall verror(const char *format, va_list va);
extern "C"  void __stdcall vshow_hex(
        const void *dataptr,
        size_t len,
        const char *format,
        va_list va);
extern "C"  void __stdcall vshow_hex_file(
        linput_t *li,
        int32 pos,
        size_t count,
        const char *format,
        va_list va);
class place_t
{
public:
  short lnnum;
  place_t(void) {}
  place_t(short ln) : lnnum(ln) {}
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  virtual void __stdcall print(void *ud,char *buf, size_t bufsize) const  = 0;
  virtual uval_t __stdcall touval(void *ud) const                         = 0;
  virtual place_t *__stdcall clone(void) const                            = 0;
  virtual void __stdcall copyfrom(const place_t *from)                    = 0;
  virtual place_t *__stdcall makeplace(void *ud, uval_t x, short lnnum) const= 0;
  virtual int __stdcall compare(const place_t *t2) const                  = 0;
  virtual void __stdcall adjust(void *ud)                                 = 0;
  virtual bool __stdcall prev(void *ud)                                   = 0;
  virtual bool __stdcall next(void *ud)                                   = 0;
  virtual bool __stdcall beginning(void *ud) const                        = 0;
  virtual bool __stdcall ending(void *ud) const                           = 0;
  virtual int __stdcall generate(
        void *ud,
        char *lines[],
        int maxsize,
        int *default_lnnum,
        color_t *pfx_color,
        bgcolor_t *bgcolor) const                = 0;
};
extern "C" int __stdcall l_compare(const place_t *t1, const place_t *t2);
struct simpleline_t
{
  qstring line;
  color_t color;
  bgcolor_t bgcolor;
  simpleline_t(void) : color(1), bgcolor(bgcolor_t(-1)) {}
  simpleline_t(color_t c, const char *str) : line(str), color(c), bgcolor(bgcolor_t(-1)) {}
  simpleline_t(const char *str) : line(str), color(1), bgcolor(bgcolor_t(-1)) {}
  simpleline_t(const qstring &str) : line(str), color(1), bgcolor(bgcolor_t(-1)) {}
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
};
typedef qvector<simpleline_t> strvec_t;
class simpleline_place_t; extern "C" void __stdcall simpleline_place_t__print(const simpleline_place_t *,void*,char*, size_t); extern "C" uval_t __stdcall simpleline_place_t__touval(const simpleline_place_t *,void*); extern "C" place_t *__stdcall simpleline_place_t__clone(const simpleline_place_t *); extern "C" void __stdcall simpleline_place_t__copyfrom(simpleline_place_t *,const place_t*); extern "C" place_t *__stdcall simpleline_place_t__makeplace(const simpleline_place_t *,void*,uval_t,short); extern "C" int __stdcall simpleline_place_t__compare(const simpleline_place_t *,const place_t*); extern "C" void __stdcall simpleline_place_t__adjust(simpleline_place_t *,void*); extern "C" bool __stdcall simpleline_place_t__prev(simpleline_place_t *,void*); extern "C" bool __stdcall simpleline_place_t__next(simpleline_place_t *,void*); extern "C" bool __stdcall simpleline_place_t__beginning(const simpleline_place_t *,void*); extern "C" bool __stdcall simpleline_place_t__ending(const simpleline_place_t *,void*); extern "C" int __stdcall simpleline_place_t__generate(const simpleline_place_t *,void*,char**,int,int*,color_t*,bgcolor_t*);
class simpleline_place_t : public place_t
{
public:
  size_t n;
  simpleline_place_t(void) { n = 0; lnnum = 0; }
  simpleline_place_t(int _n) { n = _n; lnnum = 0; }
  void __stdcall print(void *ud,char *buf, size_t bufsize) const { simpleline_place_t__print(this,ud,buf,bufsize); } uval_t __stdcall touval(void *ud) const { return simpleline_place_t__touval(this,ud); } place_t *__stdcall clone(void) const { return simpleline_place_t__clone(this); } void __stdcall copyfrom(const place_t *from) { simpleline_place_t__copyfrom(this,from); } place_t *__stdcall makeplace(void *ud,uval_t x,short _lnnum) const { return simpleline_place_t__makeplace(this,ud,x,_lnnum); } int __stdcall compare(const place_t *t2) const { return simpleline_place_t__compare(this,t2); } void __stdcall adjust(void *ud) { simpleline_place_t__adjust(this,ud); } bool __stdcall prev(void *ud) { return simpleline_place_t__prev(this,ud); } bool __stdcall next(void *ud) { return simpleline_place_t__next(this,ud); } bool __stdcall beginning(void *ud) const { return simpleline_place_t__beginning(this,ud); } bool __stdcall ending (void *ud) const { return simpleline_place_t__ending(this,ud); } int __stdcall generate (void *ud,char *lines[],int maxsize,int *_lnnum, color_t *pfx_color, bgcolor_t *bg_color) const { return simpleline_place_t__generate(this,ud,lines,maxsize,_lnnum, pfx_color, bg_color); };
};
class idaplace_t; extern "C" void __stdcall idaplace_t__print(const idaplace_t *,void*,char*, size_t); extern "C" uval_t __stdcall idaplace_t__touval(const idaplace_t *,void*); extern "C" place_t *__stdcall idaplace_t__clone(const idaplace_t *); extern "C" void __stdcall idaplace_t__copyfrom(idaplace_t *,const place_t*); extern "C" place_t *__stdcall idaplace_t__makeplace(const idaplace_t *,void*,uval_t,short); extern "C" int __stdcall idaplace_t__compare(const idaplace_t *,const place_t*); extern "C" void __stdcall idaplace_t__adjust(idaplace_t *,void*); extern "C" bool __stdcall idaplace_t__prev(idaplace_t *,void*); extern "C" bool __stdcall idaplace_t__next(idaplace_t *,void*); extern "C" bool __stdcall idaplace_t__beginning(const idaplace_t *,void*); extern "C" bool __stdcall idaplace_t__ending(const idaplace_t *,void*); extern "C" int __stdcall idaplace_t__generate(const idaplace_t *,void*,char**,int,int*,color_t*,bgcolor_t*);
class idaplace_t : public place_t {
public:
  ea_t ea;
  idaplace_t(void) {}
  idaplace_t(ea_t x,short ln) : place_t(ln), ea(x) {}
  void __stdcall print(void *ud,char *buf, size_t bufsize) const { idaplace_t__print(this,ud,buf,bufsize); } uval_t __stdcall touval(void *ud) const { return idaplace_t__touval(this,ud); } place_t *__stdcall clone(void) const { return idaplace_t__clone(this); } void __stdcall copyfrom(const place_t *from) { idaplace_t__copyfrom(this,from); } place_t *__stdcall makeplace(void *ud,uval_t x,short _lnnum) const { return idaplace_t__makeplace(this,ud,x,_lnnum); } int __stdcall compare(const place_t *t2) const { return idaplace_t__compare(this,t2); } void __stdcall adjust(void *ud) { idaplace_t__adjust(this,ud); } bool __stdcall prev(void *ud) { return idaplace_t__prev(this,ud); } bool __stdcall next(void *ud) { return idaplace_t__next(this,ud); } bool __stdcall beginning(void *ud) const { return idaplace_t__beginning(this,ud); } bool __stdcall ending (void *ud) const { return idaplace_t__ending(this,ud); } int __stdcall generate (void *ud,char *lines[],int maxsize,int *_lnnum, color_t *pfx_color, bgcolor_t *bg_color) const { return idaplace_t__generate(this,ud,lines,maxsize,_lnnum, pfx_color, bg_color); };
};
class enumplace_t; extern "C" void __stdcall enumplace_t__print(const enumplace_t *,void*,char*, size_t); extern "C" uval_t __stdcall enumplace_t__touval(const enumplace_t *,void*); extern "C" place_t *__stdcall enumplace_t__clone(const enumplace_t *); extern "C" void __stdcall enumplace_t__copyfrom(enumplace_t *,const place_t*); extern "C" place_t *__stdcall enumplace_t__makeplace(const enumplace_t *,void*,uval_t,short); extern "C" int __stdcall enumplace_t__compare(const enumplace_t *,const place_t*); extern "C" void __stdcall enumplace_t__adjust(enumplace_t *,void*); extern "C" bool __stdcall enumplace_t__prev(enumplace_t *,void*); extern "C" bool __stdcall enumplace_t__next(enumplace_t *,void*); extern "C" bool __stdcall enumplace_t__beginning(const enumplace_t *,void*); extern "C" bool __stdcall enumplace_t__ending(const enumplace_t *,void*); extern "C" int __stdcall enumplace_t__generate(const enumplace_t *,void*,char**,int,int*,color_t*,bgcolor_t*);
class enumplace_t : public place_t {
public:
  size_t idx;
  bmask_t bmask;
  uval_t value;
  uchar serial;
  enumplace_t(void) {}
  enumplace_t(size_t i, bmask_t m, uval_t v, uchar s, short ln)
    : place_t(ln), idx(i), bmask(m), value(v), serial(s) {}
  void __stdcall print(void *ud,char *buf, size_t bufsize) const { enumplace_t__print(this,ud,buf,bufsize); } uval_t __stdcall touval(void *ud) const { return enumplace_t__touval(this,ud); } place_t *__stdcall clone(void) const { return enumplace_t__clone(this); } void __stdcall copyfrom(const place_t *from) { enumplace_t__copyfrom(this,from); } place_t *__stdcall makeplace(void *ud,uval_t x,short _lnnum) const { return enumplace_t__makeplace(this,ud,x,_lnnum); } int __stdcall compare(const place_t *t2) const { return enumplace_t__compare(this,t2); } void __stdcall adjust(void *ud) { enumplace_t__adjust(this,ud); } bool __stdcall prev(void *ud) { return enumplace_t__prev(this,ud); } bool __stdcall next(void *ud) { return enumplace_t__next(this,ud); } bool __stdcall beginning(void *ud) const { return enumplace_t__beginning(this,ud); } bool __stdcall ending (void *ud) const { return enumplace_t__ending(this,ud); } int __stdcall generate (void *ud,char *lines[],int maxsize,int *_lnnum, color_t *pfx_color, bgcolor_t *bg_color) const { return enumplace_t__generate(this,ud,lines,maxsize,_lnnum, pfx_color, bg_color); };
};
class structplace_t; extern "C" void __stdcall structplace_t__print(const structplace_t *,void*,char*, size_t); extern "C" uval_t __stdcall structplace_t__touval(const structplace_t *,void*); extern "C" place_t *__stdcall structplace_t__clone(const structplace_t *); extern "C" void __stdcall structplace_t__copyfrom(structplace_t *,const place_t*); extern "C" place_t *__stdcall structplace_t__makeplace(const structplace_t *,void*,uval_t,short); extern "C" int __stdcall structplace_t__compare(const structplace_t *,const place_t*); extern "C" void __stdcall structplace_t__adjust(structplace_t *,void*); extern "C" bool __stdcall structplace_t__prev(structplace_t *,void*); extern "C" bool __stdcall structplace_t__next(structplace_t *,void*); extern "C" bool __stdcall structplace_t__beginning(const structplace_t *,void*); extern "C" bool __stdcall structplace_t__ending(const structplace_t *,void*); extern "C" int __stdcall structplace_t__generate(const structplace_t *,void*,char**,int,int*,color_t*,bgcolor_t*);
class structplace_t : public place_t {
public:
  uval_t idx;
  uval_t offset;
  structplace_t(void) {}
  structplace_t(uval_t i, uval_t o, short ln) : place_t(ln), idx(i), offset(o) {}
  void __stdcall print(void *ud,char *buf, size_t bufsize) const { structplace_t__print(this,ud,buf,bufsize); } uval_t __stdcall touval(void *ud) const { return structplace_t__touval(this,ud); } place_t *__stdcall clone(void) const { return structplace_t__clone(this); } void __stdcall copyfrom(const place_t *from) { structplace_t__copyfrom(this,from); } place_t *__stdcall makeplace(void *ud,uval_t x,short _lnnum) const { return structplace_t__makeplace(this,ud,x,_lnnum); } int __stdcall compare(const place_t *t2) const { return structplace_t__compare(this,t2); } void __stdcall adjust(void *ud) { structplace_t__adjust(this,ud); } bool __stdcall prev(void *ud) { return structplace_t__prev(this,ud); } bool __stdcall next(void *ud) { return structplace_t__next(this,ud); } bool __stdcall beginning(void *ud) const { return structplace_t__beginning(this,ud); } bool __stdcall ending (void *ud) const { return structplace_t__ending(this,ud); } int __stdcall generate (void *ud,char *lines[],int maxsize,int *_lnnum, color_t *pfx_color, bgcolor_t *bg_color) const { return structplace_t__generate(this,ud,lines,maxsize,_lnnum, pfx_color, bg_color); };
};
struct saved_structplace_t
{
  ushort lnnum;
  ushort x,y;
  uval_t idx;
  uval_t offset;
};
class twinpos_t
{
public:
  place_t *at;
  int x;
  twinpos_t(void)                 {}
  twinpos_t(place_t *t)           { at=t; }
  twinpos_t(place_t *t,int x0)    { at=t; x=x0; }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  bool operator != (const twinpos_t &r)
  {
    if ( x != r.x ) return true;
    if ( (at == 0) != (r.at == 0) ) return true;
    if ( at != 0 && (at->compare(r.at) != 0 || at->lnnum != r.at->lnnum) ) return true;
    return false;
  }
  bool operator == (const twinpos_t &r) { return !(*this != r); }
};
class twinline_t
{
public:
  place_t *at;
  char *line;
  color_t prefix_color;
  bgcolor_t bg_color;
  bool is_default;
  twinline_t(void) {}
  twinline_t(place_t *t,char *l,color_t pc, bgcolor_t bc)
  {
    at           = t;
    line         = l;
    prefix_color = pc;
    bg_color     = bc;
    is_default   = false;
  }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
};
typedef qvector<twinline_t> text_t;
typedef qvector<text_t> texts_t;
extern "C" int __declspec(dllimport) lnar_size;
class linearray_t;
extern "C" void __stdcall linearray_t_ctr (linearray_t *, void *ud); extern "C" void __stdcall linearray_t_dtr (linearray_t *); extern "C" void __stdcall linearray_t_set_place(linearray_t *, const place_t *new_at); extern "C" bool __stdcall linearray_t_beginning(const linearray_t *); extern "C" bool __stdcall linearray_t_ending (const linearray_t *); extern "C" char *__stdcall linearray_t_down (linearray_t *); extern "C" char *__stdcall linearray_t_up (linearray_t *);
class linearray_t
{
  friend void __stdcall linearray_t_ctr (linearray_t *, void *ud); friend void __stdcall linearray_t_dtr (linearray_t *); friend void __stdcall linearray_t_set_place(linearray_t *, const place_t *new_at); friend bool __stdcall linearray_t_beginning(const linearray_t *); friend bool __stdcall linearray_t_ending (const linearray_t *); friend char *__stdcall linearray_t_down (linearray_t *); friend char *__stdcall linearray_t_up (linearray_t *);
  void  _set_place(const place_t *new_at);
  char *_down     (void);
  char *_up       (void);
  char **lines;
  place_t *at;
  void *ud;
  int linecnt;
  color_t prefix_color;
  bgcolor_t bg_color;
  char *extra;
  int dlnnum;
  void  getlines        (void);
  void  cleanup         (void);
public:
  linearray_t(void *_ud)                     { linearray_t_ctr(this, _ud); }
  ~linearray_t(void)                         { linearray_t_dtr(this); }
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  void set_place(const place_t *new_at)      { linearray_t_set_place(this, new_at); }
  place_t* get_place    (void) const         { return at; }
  bgcolor_t get_bg_color(void) const         { return bg_color; }
  bgcolor_t get_pfx_color(void) const        { return prefix_color; }
  int   get_dlnnum      (void) const         { return dlnnum; }
  int   get_linecnt     (void) const         { return linecnt; }
  void *userdata        (void) const         { return ud; }
  void set_userdata     (void *userd)        { ud = userd; }
  bool beginning(void) const                 { return linearray_t_beginning(this); }
  bool ending(void) const                    { return linearray_t_ending(this); }
  char *down(void)
        { return linearray_t_down(this); }
  char *up(void)
        { return linearray_t_up(this); }
};
extern "C" int __declspec(dllimport) dirty_infos;
 void request_refresh(int mask)
{
  dirty_infos |= mask;
}
extern "C" uint32 __declspec(dllimport) debug;
  int deb(int ida_debug_bits, const char *format, ...)
{
  int nbytes = 0;
  if ( debug & ida_debug_bits )
  {
    va_list va;
    ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    nbytes = callui(ui_msg, format, va).i;
    ( va = (va_list)0 );
  }
  return nbytes;
}
void ida_debug_time(const char *file, int line);
extern "C" void __stdcall ida_checkmem(const char *file, int line);
  void show_hex(
        const void *dataptr,
        size_t len,
        const char *format,
        ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vshow_hex(dataptr, len, format, va);
  ( va = (va_list)0 );
}
  void show_hex_file(
        linput_t *li,
        int32 pos,
        size_t count,
        const char *format,
        ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vshow_hex_file(li, pos, count, format, va);
  ( va = (va_list)0 );
}
 int askbuttons_cv(
        const char *Yes,
        const char *No,
        const char *Cancel,
        int deflt,
        const char *format,
        va_list va);
 char *vaskstr(
        int hist,
        const char *defval,
        const char *format,
        va_list va);
 char *vasktext(
        size_t size,
        char *answer,
        const char *defval,
        const char *format,
        va_list va);
 int vmsg(const char *format, va_list va);
 void vwarning(const char *format, va_list va);
 void vinfo(const char *format, va_list va);
 __declspec(noreturn) void vnomem(const char *format, va_list va);
typedef int32 chooser_event_t;
const chooser_event_t
  EMPTY_SEL =  0,
  START_SEL = -1,
  END_SEL   = -2;
typedef uint32 __stdcall chooser_cb_t(void *obj, uint32 n);
struct chooser_item_attrs_t
{
  int cb;
  int flags;
  bgcolor_t color;
  void reset(void)
  {
    cb    = sizeof(chooser_item_attrs_t);
    flags = 0;
    color = bgcolor_t(-1);
  }
};
struct chooser_info_t
{
  uint32 cb;
  int flags;
  int width, height;
  const char *title;
  void *obj;
  int columns;
  const int *widths;
  int icon;
  uint32 deflt;
  const char *const *popup_names;
  uint32 (__stdcall *sizer)(void *obj);
  void (__stdcall *getl)(void *obj, uint32 n, char *const *arrptr);
  uint32 (__stdcall *del)(void *obj, uint32 n);
  void (__stdcall *ins)(void *obj);
  uint32 (__stdcall *update)(void *obj, uint32 n);
  void (__stdcall *edit)(void *obj, uint32 n);
  void (__stdcall *enter)(void *obj, uint32 n);
  void (__stdcall *destroyer)(void *obj);
  int (__stdcall *get_icon)(void *obj, uint32 n);
  void (__stdcall *select)(void *obj, const intvec_t & sel);
  void (__stdcall *refresh)(void *obj);
};
uint32 choose(
        int flags,
        int x0,int y0,
        int x1,int y1,
        void *obj,
        int width,
        uint32 (__stdcall*sizer)(void *obj),
        char *(__stdcall*getl)(void *obj,uint32 n,char *buf),
        const char *title,
        int icon,
        uint32 deflt=1,
        chooser_cb_t *del=0,
        void (__stdcall*ins)(void *obj)=0,
        chooser_cb_t *update=0,
        void (__stdcall*edit)(void *obj,uint32 n)=0,
        void (__stdcall*enter)(void * obj,uint32 n)=0,
        void (__stdcall*destroy)(void *obj)=0,
        const char * const *popup_names=0,
        int (__stdcall*get_icon)(void *obj,uint32 n)=0);
 uint32 choose(
        void *obj,
        int width,
        uint32 (__stdcall*sizer)(void *obj),
        char *(__stdcall*getl)(void *obj,uint32 n,char *buf),
        const char *title,
        int icon=-1,
        uint32 deflt=1,
        chooser_cb_t *del=0,
        void (__stdcall*ins)(void *obj)=0,
        chooser_cb_t *update=0,
        void (__stdcall*edit)(void *obj,uint32 n)=0,
        void (__stdcall*enter)(void * obj,uint32 n)=0,
        void (__stdcall*destroy)(void *obj)=0,
        const char * const *popup_names=0,
        int (__stdcall*get_icon)(void *obj,uint32 n)=0)
{
  return choose(0x01,-1,-1,-1,-1, obj, width, sizer,
                getl, title, icon, deflt, del, ins,
                update, edit, enter, destroy, popup_names, get_icon);
}
uint32 choose2(
        int flags,
        int x0,int y0,
        int x1,int y1,
        void *obj,
        int ncol,
        const int *widths,
        uint32 (__stdcall*sizer)(void *obj),
        void (__stdcall*getl)(void *obj,uint32 n,char * const *arrptr),
        const char *title,
        int icon,
        uint32 deflt=1,
        chooser_cb_t *del=0,
        void (__stdcall*ins)(void *obj)=0,
        chooser_cb_t *update=0,
        void (__stdcall*edit)(void *obj,uint32 n)=0,
        void (__stdcall*enter)(void * obj,uint32 n)=0,
        void (__stdcall*destroy)(void *obj)=0,
        const char * const *popup_names=0,
        int (__stdcall*get_icon)(void *obj,uint32 n)=0);
 uint32 choose2(
        void *obj,
        int ncol,
        const int *widths,
        uint32 (__stdcall*sizer)(void *),
        void (__stdcall*getl)(void *,uint32,char*const*),
        const char *title,
        int icon=-1,
        uint32 deflt=1,
        chooser_cb_t *del=0,
        void (__stdcall*ins)(void *)=0,
        chooser_cb_t *update=0,
        void (__stdcall*edit)(void *,uint32)=0,
        void (__stdcall*enter)(void *,uint32)=0,
        void (__stdcall*destroy)(void *)=0,
        const char * const *popup_names=0,
        int (__stdcall*get_icon)(void *obj,uint32 n)=0)
{
  return choose2(0x01,-1,-1,-1,-1, obj, ncol, widths,
                 sizer, getl, title, icon, deflt, del,
                 ins, update, edit, enter, destroy, popup_names, get_icon);
}
typedef uint32 __stdcall nav_colorizer_t(ea_t ea, asize_t nbytes);
typedef bool __stdcall menu_item_callback_t(void *ud);
namespace Controls
{
  class TWinControl;
  class TCustomControl;
};
using Controls::TWinControl;
using Controls::TCustomControl;
enum custom_viewer_handler_id_t
{
  CVH_USERDATA,
  CVH_KEYDOWN,
  CVH_POPUP,
  CVH_DBLCLICK,
  CVH_CURPOS,
  CVH_CLOSE,
  CVH_CLICK,
  CVH_QT_AWARE
};
typedef bool __stdcall custom_viewer_keydown_t(TCustomControl *cv, int vk_key, int shift, void *ud);
typedef void __stdcall custom_viewer_popup_t(TCustomControl *cv, void *ud);
typedef bool __stdcall custom_viewer_click_t(TCustomControl *cv, int shift, void *ud);
typedef bool __stdcall custom_viewer_dblclick_t(TCustomControl *cv, int shift, void *ud);
typedef void __stdcall custom_viewer_curpos_t(TCustomControl *cv, void *ud);
typedef void __stdcall custom_viewer_close_t(TCustomControl *cv, void *ud);
struct cli_t
{
  size_t size;
  int32 flags;
  const char *sname;
  const char *lname;
  const char *hint;
  bool (__stdcall *execute_line)(const char *line);
  bool (__stdcall *complete_line)(
        qstring *completion,
        const char *prefix,
        int n,
        const char *line,
        int x);
  bool (__stdcall *keydown)(
        qstring *line,
        int *p_x,
        int *p_sellen,
        int *vk_key,
        int shift);
};
struct exec_request_t
{
  enum { MFF_MAGIC = 0x12345678 };
  bool valid(void) const
  {
    return (code & ~7) == MFF_MAGIC && (sem != 0 || (code & 0x0004) != 0);
  }
  int code;
  qsemaphore_t sem;
  virtual int __stdcall execute(void) = 0;
  exec_request_t(void) : sem(0) {}
  virtual ~exec_request_t(void) { qsem_free(sem); sem = 0; code = 0; }
};
 bool jumpto(ea_t ea,int opnum=-1)   { return callui(ui_jumpto, ea, opnum).cnd; }
 bool banner(int wait)               { return callui(ui_banner, wait).cnd;}
  bool is_msg_inited(void){ return callui(ui_is_msg_inited).cnd; }
 void refresh_idaview(void)          { callui(ui_refreshmarked);}
 void refresh_idaview_anyway(void)   { callui(ui_refresh);      }
 void analyzer_options(void)         { callui(ui_analyzer_options); }
 ea_t get_screen_ea(void)            { ea_t ea; callui(ui_screenea, &ea); return ea; }
 int get_opnum(void)                 { return callui(ui_get_opnum).i; }
 bool get_cursor(int *x, int *y)     { return callui(ui_get_cursor, x, y).cnd; }
 char *get_curline(void)             { return callui(ui_get_curline).cptr; }
 bool read_selection(ea_t *ea1, ea_t *ea2) { return callui(ui_readsel, ea1, ea2).cnd; }
 void unmark_selection(void)         { callui(ui_unmarksel); }
 void open_url(const char *url)      { callui(ui_open_url, url); }
 ea_t get_hexdump_ea(int hexdump_num) { ea_t ea; callui(ui_hexdumpea, &ea, hexdump_num); return ea; }
 bool set_xml(const char *path, const char *name, const char *value) { return callui(ui_set_xml, path, name, value).cnd; }
 bool get_xml(const char *path, idc_value_t *value) { return callui(ui_get_xml, path, value).cnd; }
 bool del_xml(const char *path)      { return callui(ui_del_xml, path).cnd; }
 bool push_xml(const char *path)     { return callui(ui_push_xml, path).cnd; }
 bool pop_xml(void)                  { return callui(ui_pop_xml).cnd; }
 ushort get_key_code(const char *keyname) { return callui(ui_get_key_code, keyname).i16; }
 ushort lookup_key_code(int key, int shift, bool is_qt) { return callui(ui_lookup_key_code, key, shift, is_qt).i16; }
 void refresh_navband(bool force)     { callui(ui_refresh_navband, force); }
 bool refresh_chooser(const char *title) { return callui(ui_refresh_chooser, title).cnd; }
 bool close_chooser(const char *title) { return callui(ui_close_chooser, title).cnd; }
 void install_command_interpreter(const cli_t *cp) { callui(ui_install_cli, cp, true); }
 void remove_command_interpreter(const cli_t *cp) { callui(ui_install_cli, cp, false); }
 void gen_disasm_text(ea_t ea1, ea_t ea2, text_t &text, bool truncate_lines) { callui(ui_gen_disasm_text, ea1, ea2, &text, truncate_lines); }
  int execute_sync(exec_request_t &req, int reqf) { return callui(ui_execute_sync, &req, reqf).i; }
 bool set_dock_pos(const char *src_ctrl, const char *dest_ctrl, int orient, int left = 0, int top = 0, int right = 0, int bottom = 0)
{
  return callui(ui_set_dock_pos, src_ctrl, dest_ctrl, orient, left, top, right, bottom).cnd;
}
 bool enable_input_hotkeys(bool enable) { return callui(ui_enable_input_hotkeys, enable).cnd; }
 int load_custom_icon(const char *file_name) { return callui(ui_load_custom_icon_file, file_name).i; }
 int load_custom_icon(const void *ptr, unsigned int len, const char *format) { return callui(ui_load_custom_icon, ptr, len, format).i; }
 void free_custom_icon(int icon_id) { callui(ui_free_custom_icon, icon_id); }
 bool process_ui_action(const char *name, int flags=0, void *param=0)
{
  return callui(ui_process_action, name, flags, param).cnd;
}
 bool add_menu_item(
        const char *menupath,
        const char *name,
        const char *hotkey,
        int flags,
        menu_item_callback_t *callback,
        void *ud)
{
  return callui(ui_add_menu_item, menupath, name, hotkey, flags, callback, ud).cnd;
}
 bool del_menu_item(const char *menupath) { return callui(ui_del_menu_item, menupath).cnd; }
namespace Forms
{
  class TForm;
};
using Forms::TForm;
namespace Menus
{
  class TPopupMenu;
}
using Menus::TPopupMenu;
typedef struct HWND__ *HWND;
 TForm *create_tform(const char *caption, HWND *handle)
{
  return (TForm *)callui(ui_create_tform, caption, handle).vptr;
}
 HWND get_tform_handle(TForm *form)
{
  return (HWND)callui(ui_get_tform_handle, form).vptr;
}
 void open_tform(TForm *form, int options)
{
  callui(ui_open_tform, form, options);
}
 void close_tform(TForm *form, int options)
{
  callui(ui_close_tform, form, options);
}
 void switchto_tform(TForm *form, bool take_focus)
{
  callui(ui_switchto_tform, form, take_focus);
}
 TForm *find_tform(const char *caption)
{
  return (TForm *)callui(ui_find_tform, caption).vptr;
}
 TForm *get_current_tform(void)
{
  return (TForm *)callui(ui_get_current_tform).vptr;
}
 TCustomControl *create_custom_viewer(
        const char *title,
        TWinControl *parent,
        const place_t *minplace,
        const place_t *maxplace,
        const place_t *curplace,
        int y,
        void *ud)
{
  return (TCustomControl*)callui(ui_new_custom_viewer, title, parent,
                minplace, maxplace, curplace, y, ud).vptr;
}
 void refresh_custom_viewer(TCustomControl *custom_viewer)
{
  callui(ui_refresh_custom_viewer, custom_viewer);
}
 void destroy_custom_viewer(TCustomControl *custom_viewer)
{
  callui(ui_destroy_custom_viewer, custom_viewer);
}
 bool jumpto(TCustomControl *custom_viewer, place_t *place, int x, int y)
{
  return callui(ui_jump_in_custom_viewer, custom_viewer, place, x, y).cnd;
}
 place_t *get_custom_viewer_place(
        TCustomControl *custom_viewer,
        bool mouse,
        int *x,
        int *y)
{
  return (place_t *)callui(ui_get_curplace, custom_viewer, mouse, x, y).vptr;
}
 void set_custom_viewer_popup_menu(
        TCustomControl *custom_viewer,
        TPopupMenu *menu)
{
  callui(ui_set_custom_viewer_popup, custom_viewer, menu);
}
 bool is_idaq()
{
  return callui(ui_clearbreak, 0x23967034, 0xAAEE67BE+2, 0, 0).cnd;
}
 void add_custom_viewer_popup_item(
        TCustomControl *custom_viewer,
        const char *title,
        const char *hotkey,
        menu_item_callback_t *cb,
        void *ud)
{
  callui(ui_add_custom_viewer_popup, custom_viewer, title, hotkey, cb, ud);
}
 void set_custom_viewer_handlers(
        TCustomControl *custom_viewer,
        custom_viewer_keydown_t *keyboard_handler,
        custom_viewer_popup_t *popup_handler,
        custom_viewer_dblclick_t *dblclick_handler,
        custom_viewer_curpos_t *curpos_handler,
        custom_viewer_close_t *close_handler,
        void *user_data)
{
  callui(ui_set_custom_viewer_handlers, custom_viewer, keyboard_handler,
         popup_handler, dblclick_handler, curpos_handler, close_handler,
         user_data);
}
 void *set_custom_viewer_handler(
        TCustomControl *custom_viewer,
        custom_viewer_handler_id_t handler_id,
        void *handler_or_data)
{
  return callui(ui_set_custom_viewer_handler, custom_viewer, handler_id,
                handler_or_data).vptr;
}
 bool set_custom_viewer_qt_aware(TCustomControl *custom_viewer)
{
  return callui(ui_set_custom_viewer_handler, custom_viewer, CVH_QT_AWARE).cnd;
}
 const char *get_custom_viewer_curline(TCustomControl *custom_viewer, bool mouse)
{
  return callui(ui_get_custom_viewer_curline, custom_viewer, mouse).cptr;
}
 TCustomControl *get_current_viewer(void)
{
  return (TCustomControl *)callui(ui_get_current_viewer).vptr;
}
 void set_custom_viewer_range(
        TCustomControl *custom_viewer,
        const place_t *minplace,
        const place_t *maxplace)
{
  callui(ui_set_custom_viewer_range, custom_viewer, minplace, maxplace);
}
 bool is_idaview(TCustomControl *v)
{
  return callui(ui_is_idaview, v).cnd;
}
 bool readsel2(TCustomControl *v, twinpos_t *p1, twinpos_t *p2)
{
  return callui(ui_readsel2, v, p1, p2).cnd;
}
 void clearBreak(void) { callui(ui_clearbreak); }
 void setBreak(void) { callui(ui_setbreak); }
 bool wasBreak(void) { return callui(ui_wasbreak).cnd; }
 bool ui_load_new_file(const char *filename,
                             linput_t *li,
                             ushort neflags)
{
  return callui(ui_load_file, filename, li, neflags).cnd;
}
 bool ui_run_debugger(const char *dbgopts,
                            const char *exename,
                            int argc,
                            const char *const *argv)
{
  return callui(ui_run_dbg, dbgopts, exename, argc, argv).cnd;
}
 int add_idc_hotkey(const char *hotkey,const char *idcfunc)
{
  return callui(ui_add_idckey, hotkey, idcfunc).i;
}
 bool del_idc_hotkey(const char *hotkey)
{
  return callui(ui_del_idckey, hotkey).cnd;
}
extern void (__stdcall*range_marker)(ea_t ea, asize_t size);
 void setup_range_marker(void)
{
  void *ptr = callui(ui_get_range_marker).vptr;
  if ( ptr != 0 )
    range_marker = (void (__stdcall*)(ea_t, asize_t))ptr;
}
 bool get_highlighted_identifier(char *buf, size_t bufsize, int flags)
{
  return callui(ui_get_highlighted_identifier, buf, bufsize, flags).cnd;
}
 void mark_range_for_refresh(ea_t ea, asize_t size)
{
  if ( range_marker != 0 )
    range_marker(ea, size);
}
 void mark_all_eaviews_for_refresh(void)
{
  if ( range_marker != 0 )
    range_marker(0, ea_t(-1));
}
 TForm *open_exports_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 0, ea).vptr;
}
 TForm *open_imports_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 1, ea).vptr;
}
 TForm *open_names_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 2, ea).vptr;
}
 TForm *open_funcs_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 3, ea).vptr;
}
 TForm *open_strings_window(ea_t ea, ea_t selstart=ea_t(-1), ea_t selend=ea_t(-1))
{
  return (TForm *)callui(ui_open_builtin, 4, ea, selstart, selend).vptr;
}
 TForm *open_segments_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 5, ea).vptr;
}
 TForm *open_segregs_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 6, ea).vptr;
}
 TForm *open_selectors_window(void)
{
  return (TForm *)callui(ui_open_builtin, 7, 0).vptr;
}
 TForm *open_signatures_window(void)
{
  return (TForm *)callui(ui_open_builtin, 8, 0).vptr;
}
 TForm *open_tils_window(void)
{
  return (TForm *)callui(ui_open_builtin, 9, 0).vptr;
}
 TForm *open_loctypes_window(int ordinal)
{
  return (TForm *)callui(ui_open_builtin, 10, ordinal).vptr;
}
 TForm *open_calls_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 11, ea).vptr;
}
 TForm *open_problems_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 12, ea).vptr;
}
 TForm *open_bpts_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 13, ea).vptr;
}
 TForm *open_threads_window(void)
{
  return (TForm *)callui(ui_open_builtin, 14, 0).vptr;
}
 TForm *open_modules_window(void)
{
  return (TForm *)callui(ui_open_builtin, 15, 0).vptr;
}
 TForm *open_trace_window(void)
{
  return (TForm *)callui(ui_open_builtin, 16, 0).vptr;
}
 TForm *open_stack_window(void)
{
  return (TForm *)callui(ui_open_builtin, 17, 0).vptr;
}
 TForm *open_xrefs_window(ea_t ea)
{
  return (TForm *)callui(ui_open_builtin, 18, ea).vptr;
}
 TForm *open_frame_window(func_t *pfn, uval_t offset)
{
  return (TForm *)callui(ui_open_builtin, 25, pfn, offset).vptr;
}
 TForm *open_navband_window(ea_t ea, int zoom)
{
  return (TForm *)callui(ui_open_builtin, 26, ea, zoom).vptr;
}
 TForm *open_enums_window(tid_t const_id=ea_t(-1))
{
  return (TForm *)callui(ui_open_builtin, 27, const_id).vptr;
}
 TForm *open_structs_window(tid_t id=ea_t(-1), uval_t offset=0)
{
  return (TForm *)callui(ui_open_builtin, 28, id, offset).vptr;
}
 TForm *open_disasm_window(const char *window_title, const areavec_t *ranges=0)
{
  return (TForm *)callui(ui_open_builtin, 29, window_title, ea_t(-1), ranges, 0).vptr;
}
 TForm *open_hexdump_window(const char *window_title)
{
  return (TForm *)callui(ui_open_builtin, 30, window_title, ea_t(-1), 0).vptr;
}
 TForm *open_notepad_window(void)
{
  return (TForm *)callui(ui_open_builtin, 31, 0).vptr;
}
 char *choose_idasgn(void)
{
  return callui(ui_choose, chtype_idasgn).cptr;
}
 bool choose_til(char *buf, size_t bufsize)
{
  return callui(ui_choose, chtype_idatil, buf, bufsize).cnd;
}
 ea_t choose_entry(const char *title)
{
  ea_t ea;
  callui(ui_choose, chtype_entry, &ea, title);
  return ea;
}
 ea_t choose_name(const char *title)
{
  ea_t ea;
  callui(ui_choose, chtype_name, &ea, title);
  return ea;
}
 ea_t choose_stkvar_xref(func_t *pfn, member_t *mptr)
{
  ea_t ea;
  callui(ui_choose, chtype_stkvar_xref, &ea, pfn, mptr);
  return ea;
}
 ea_t choose_xref(ea_t to)
{
  ea_t ea;
  callui(ui_choose, chtype_xref, &ea, to);
  return ea;
}
 enum_t choose_enum(const char *title, enum_t default_id)
{
  enum_t enum_id = default_id;
  callui(ui_choose, chtype_enum, &enum_id, title);
  return enum_id;
}
 enum_t choose_enum_by_value(const char *title, enum_t default_id,
                                                uval_t value, uchar *serial)
{
  enum_t enum_id = default_id;
  callui(ui_choose, chtype_enum_by_value, &enum_id, title, value, serial);
  return enum_id;
}
 func_t *choose_func(const char *title, ea_t default_ea)
{
  return callui(ui_choose, chtype_func, title, default_ea).fptr;
}
 segment_t *choose_segm(const char *title, ea_t default_ea)
{
  return callui(ui_choose, chtype_segm, title, default_ea).segptr;
}
 segreg_t *choose_segreg(const char *title)
{
  return callui(ui_choose, chtype_segreg, title).sregptr;
}
 struc_t *choose_struc(const char *title)
{
  return callui(ui_choose, chtype_struc, title).strptr;
}
 int choose_struc_path(const char *title, tid_t strid,
                      uval_t offset, adiff_t delta, bool appzero, tid_t *path)
{
  return callui(ui_choose, chtype_strpath, title, strid,
                                            offset, delta, appzero, path).i;
}
 uint32 choose(
        int flags,
        int x0,int y0,
        int x1,int y1,
        void *obj,
        int width,
        uint32 (__stdcall*sizer)(void *obj),
        char *(__stdcall*getl)(void *obj,uint32 n,char *buf),
        const char *title,
        int icon,
        uint32 deflt,
        chooser_cb_t *del,
        void (__stdcall*ins)(void *obj),
        chooser_cb_t *update,
        void (__stdcall*edit)(void *obj,uint32 n),
        void (__stdcall*enter)(void * obj,uint32 n),
        void (__stdcall*destroy)(void *obj),
        const char * const *popup_names,
        int (__stdcall*get_icon)(void *obj,uint32 n))
{
  return callui(ui_choose, chtype_generic, flags, x0, y0, x1, y1, obj, width,
                sizer, getl, title, icon, deflt, del, ins, update,
                edit, enter, destroy, popup_names, get_icon).i32;
}
 uint32 choose2(
        int flags,
        int x0,int y0,
        int x1,int y1,
        void *obj,
        int ncol,
        const int *widths,
        uint32 (__stdcall*sizer)(void *obj),
        void (__stdcall*getl)(void *obj,uint32 n,char * const *arrptr),
        const char *title,
        int icon,
        uint32 deflt,
        chooser_cb_t *del,
        void (__stdcall*ins)(void *obj),
        chooser_cb_t *update,
        void (__stdcall*edit)(void *obj,uint32 n),
        void (__stdcall*enter)(void * obj,uint32 n),
        void (__stdcall*destroy)(void *obj),
        const char * const *popup_names,
        int (__stdcall*get_icon)(void *obj,uint32 n))
{
  return callui(ui_choose, chtype_generic2, flags, x0, y0, x1, y1, obj, ncol,
                widths, sizer, getl, title, icon, deflt, del, ins,
                update, edit, enter, destroy, popup_names, get_icon).i32;
}
 bool add_chooser_command(
        const char *chooser_caption,
        const char *cmd_caption,
        chooser_cb_t *chooser_cb,
        int menu_index=-1,
        int icon=-1,
        int flags=0)
{
  return callui(ui_add_chooser_cmd, chooser_caption, cmd_caption, chooser_cb,
                menu_index, icon, flags).cnd;
}
 void *get_chooser_obj(const char *chooser_caption)
{
  return callui(ui_get_chooser_obj, chooser_caption).vptr;
}
 bool __stdcall enable_chooser_item_attrs(const char *chooser_caption, bool enable)
{
  return callui(ui_enable_chooser_item_attrs, chooser_caption, enable).cnd;
}
  void show_wait_box_v(const char *format, va_list va)
{
  callui(ui_mbox, mbox_wait, format, va);
}
  void show_wait_box(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  show_wait_box_v(format, va);
  ( va = (va_list)0 );
}
 void hide_wait_box(void)
{
  callui(ui_mbox, mbox_hide, 0, &callui);
}
  void replace_wait_box(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  callui(ui_mbox, mbox_replace, format, va);
  ( va = (va_list)0 );
}
  int AskUsingForm_cv(const char *format, va_list va)
{
  return callui(ui_form, format, va).i;
}
 void close_form(TView *fields[], int close_normally)
{
  callui(ui_close_form, fields, close_normally);
}
 void beep(beep_t beep_type=beep_default)
{
  callui(ui_beep, beep_type);
}
   int askbuttons_cv(
        const char *Yes,
        const char *No,
        const char *Cancel,
        int deflt,
        const char *format,
        va_list va)
{
  return callui(ui_askyn, Yes, No, Cancel, deflt, format, va).i;
}
  char *askfile_cv(
        int savefile,
        const char *defval,
        const char *format,
        va_list va)
{
  return callui(ui_askfile, savefile, defval, format, va).cptr;
}
   void ask_for_feedback(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  callui(ui_mbox, mbox_feedback, format, va);
  ( va = (va_list)0 );
}
  char *askident(const char *defval, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  char *result = callui(ui_askident, defval, format, va).cptr;
  ( va = (va_list)0 );
  return result;
}
  int askaddr(ea_t *addr, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool cnd = callui(ui_askaddr, addr, format, va).cnd;
  ( va = (va_list)0 );
  return cnd;
}
  int askseg(sel_t *sel, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool code = callui(ui_askseg, sel, format, va).cnd;
  ( va = (va_list)0 );
  return code;
}
  int asklong(sval_t *value, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  bool code = callui(ui_asklong, value, format, va).cnd;
  ( va = (va_list)0 );
  return code;
}
  char *vaskstr(
        int hist,
        const char *defval,
        const char *format,
        va_list va)
{
  return callui(ui_askstr, hist, defval, format, va).cptr;
}
  char *vasktext(
        size_t size,
        char *answer,
        const char *defval,
        const char *format,
        va_list va)
{
  return callui(ui_asktext, size, answer, defval, format, va).cptr;
}
   void vwarning(const char *format, va_list va)
{
  callui(ui_mbox, mbox_warning, format, va);
}
   void vinfo(const char *format, va_list va)
{
  callui(ui_mbox, mbox_info, format, va);
}
  __declspec(noreturn)  void vnomem(const char *format, va_list va)
{
  callui(ui_mbox, mbox_nomem, format, va);
  abort();
}
   int vmsg(const char *format, va_list va)
{
  return callui(ui_msg, format, va).i;
}
 bool display_copyright_warning(void)
{
  return callui(ui_copywarn).cnd;
}
 bool set_xml(const char *path, const char *name, int value)
{
  char buffer[12];
  ::qsnprintf(buffer, sizeof(buffer), "%d", value);
  return set_xml(path, name, buffer);
}
extern "C" int __declspec(dllimport) batch;
extern "C" int __declspec(dllimport) errorexit;
  __declspec(noreturn)  void error(const char *format,...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  verror(format, va);
}
   void warning(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vwarning(format, va);
  ( va = (va_list)0 );
}
   void info(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vinfo(format, va);
  ( va = (va_list)0 );
}
  __declspec(noreturn)  void nomem(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vnomem(format, va);
}
   int msg(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int nbytes = vmsg(format, va);
  ( va = (va_list)0 );
  return nbytes;
}
int AskUsingForm_cv(const char *form, va_list va);
 int AskUsingForm_c(const char *form, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(form) ) + ( (sizeof(form) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = AskUsingForm_cv(form, va);
  ( va = (va_list)0 );
  return code;
}
typedef void (__stdcall *formcb_t)(TView *fields[], int code);
void close_form(TView *fields[], int is_ok);
struct form_actions_t
{
  virtual bool __stdcall get_field_value(int field_id, void *buf) = 0;
  virtual bool __stdcall set_field_value(int field_id, const void *buf) = 0;
  virtual bool __stdcall enable_field(int field_id, bool enable) = 0;
  virtual bool __stdcall show_field(int field_id, bool display) = 0;
  virtual bool __stdcall move_field(int field_id, int x, int y, int w, int h) = 0;
  virtual int __stdcall get_focused_field(void) = 0;
  virtual bool __stdcall set_focused_field(int field_id) = 0;
  virtual void __stdcall refresh_field(int field_id) = 0;
};
typedef int (__stdcall *formchgcb_t)(int field_id, form_actions_t &fa);
  int askyn_cv(int deflt, const char *format, va_list va)
{
  return askbuttons_cv(0, 0, 0, deflt, format, va);
}
  int askyn_c(int deflt, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = askyn_cv(deflt, format, va);
  ( va = (va_list)0 );
  return code;
}
  int askbuttons_c(
        const char *Yes,
        const char *No,
        const char *Cancel,
        int deflt,
        const char *format,
        ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = askbuttons_cv(Yes, No, Cancel, deflt, format, va);
  ( va = (va_list)0 );
  return code;
}
  char *askstr(int hist, const char *defval, const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  char *result = vaskstr(hist, defval, format, va);
  ( va = (va_list)0 );
  return result;
}
  char *asktext(
        size_t size,
        char *answer,
        const char *defval,
        const char *format,
        ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  char *result = vasktext(size, answer, defval, format, va);
  ( va = (va_list)0 );
  return result;
}
 char *askfile_cv(
        int savefile,
        const char *defval,
        const char *format,
        va_list va);
  char *askfile_c(
        int savefile,
        const char *defval,
        const char *format,
        ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  char *answer = askfile_cv(savefile, defval, format, va);
  ( va = (va_list)0 );
  return answer;
}
extern "C"  char *__stdcall addblanks(char *str,ssize_t len);
extern "C"  char *__stdcall trim(char *str);
extern "C"  const char *__stdcall skipSpaces(const char *ptr);
 char *skipSpaces(char *ptr)
  { return const_cast<char*>(skipSpaces((const char *)ptr)); }
struct strarray_t
{
  int code;
  const char *text;
};
extern "C"  const char *__stdcall strarray(const strarray_t *array, size_t array_size, int code);
extern "C"  void __stdcall entab(char *string);
extern "C" size_t __stdcall ea2str(ea_t ea, char *buf, size_t bufsize);
extern "C" bool __stdcall str2ea(const char *str, ea_t *ea_ptr, ea_t screenEA);
extern "C" bool __stdcall atoea(const char *str, ea_t *pea);
extern "C" size_t __stdcall stoa(ea_t from, sel_t seg, char *buf, size_t bufsize);
extern "C" int __stdcall atos(const char *str, sel_t *seg);
extern "C" size_t __stdcall b2a_width(int nbytes, int radix);
extern "C" size_t __stdcall b2a32(uint32 x, char *buf, size_t bufsize, int nbytes, int radix);
extern "C" size_t __stdcall b2a64(uint64 x, char *buf, size_t bufsize, int nbytes, int radix);
extern "C" size_t __stdcall btoa32(char *buf, size_t bufsize, uint32 x, int radix=0);
extern "C" size_t __stdcall btoa64(char *buf, size_t bufsize, uint64 x, int radix=0);
extern "C" size_t __stdcall btoa128(char *buf, size_t bufsize, uint128 x, int radix=0);
extern "C" size_t __stdcall btoa_width(int nbytes, flags_t flag, int n);
extern "C" size_t __stdcall numop2str(char *buf,
                                   size_t bufsize,
                                   ea_t ea,
                                   int n,
                                   uint64 x,
                                   int nbytes,
                                   int radix=0);
extern "C" bool __stdcall atob32(const char *str, uint32 *x);
extern "C" bool __stdcall atob64(const char *str, uint64 *x);
extern "C" size_t __stdcall print_disp(char *buf, char *end, adiff_t disp);
extern "C"  char *__stdcall str2user(char *dst, const char *src, size_t dstsize);
extern "C"  char *__stdcall user2str(char *dst, const char *src, size_t dstsize);
extern "C"  char __stdcall back_char(const char *&p);
extern "C"  void __stdcall qstr2user(qstring *dst, const qstring &src);
extern "C"  void __stdcall user2qstr(qstring *dst, const qstring &src);
extern "C"  int __stdcall r50_to_asc(const ushort *r, char *p, int k);
int                    asc_to_r50(const char *p, ushort *r, int k);
extern "C" char __declspec(dllimport) AsciiStringChars[256+1];
  uchar *__stdcall pack_db(uchar *ptr, uchar *end, uchar x)
{
  if ( ptr < end )
    *ptr++ = x;
  return ptr;
}
  uchar __stdcall unpack_db(const uchar **pptr, const uchar *end)
{
  const uchar *ptr = *pptr;
  uchar x = 0;
  if ( ptr < end )
    x = *ptr++;
  *pptr = ptr;
  return x;
}
extern "C"  uchar *__stdcall pack_dw(uchar *ptr, uchar *end, uint16 x);
extern "C"  uchar *__stdcall pack_dd(uchar *ptr, uchar *end, uint32 x);
extern "C"  uchar *__stdcall pack_dq(uchar *ptr, uchar *end, uint64 x);
extern "C"  ushort __stdcall unpack_dw(const uchar **pptr, const uchar *end);
extern "C"  uint32 __stdcall unpack_dd(const uchar **pptr, const uchar *end);
extern "C"  uint64 __stdcall unpack_dq(const uchar **pptr, const uchar *end);
  uchar *pack_ea(uchar *ptr, uchar *end, ea_t ea)
{
  return pack_dd(ptr, end, ea);
}
  ea_t unpack_ea(const uchar **ptr, const uchar *end)
{
  return unpack_dd(ptr, end);
}
extern "C"  uchar *__stdcall pack_ds(uchar *ptr, uchar *end, const char *x, size_t len=0);
extern "C"  char  *__stdcall unpack_ds(const uchar **pptr, const uchar *end, bool empty_null);
  void *__stdcall unpack_obj(const uchar **pptr, const uchar *end, void *destbuf, size_t destsize)
{
  const uchar *src = *pptr;
  if ( src+destsize > end )
    return 0;
  *pptr = src + destsize;
  return memcpy(destbuf, src, destsize);
}
  void *__stdcall unpack_buf(const uchar **pptr, const uchar *end, size_t *sz)
{
  size_t size = *sz = unpack_dd(pptr, end);
  if ( size == 0 )
    return 0;
  void *dst = qalloc(size);
  if ( dst != 0 )
  {
    const uchar *src = *pptr;
    memcpy(dst, src, size);
    *pptr += size;
  }
  return dst;
}
  const void *__stdcall unpack_obj_inplace(const uchar **pptr, const uchar *end, size_t objsize)
{
  const uchar *ret = *pptr;
  if ( ret+objsize > end )
    return 0;
  *pptr = ret + objsize;
  return ret;
}
  const void *__stdcall unpack_buf_inplace(const uchar **pptr, const uchar *end, size_t *sz)
{
  size_t objsize = unpack_dd(pptr, end);
  const uchar *ret = *pptr;
  if ( ret+objsize > end )
    return 0;
  *pptr = ret + objsize;
  *sz   = objsize;
  return ret;
}
  void unpack_eavec(ea_t ea, eavec_t &insns, const uchar **ptr, const uchar *end)
{
  ea_t old = ea;
  int n = unpack_dw(ptr, end);
  insns.resize(n);
  for ( int i=0; i < n; i++ )
  {
    old += unpack_ea(ptr, end);
    insns[i] = old;
  }
}
  uint64 unpack_uleb128(const uchar **pptr, const uchar* end)
{
  uint64 result = 0;
  int  bit = 0;
  const uchar *ptr = *pptr;
  uchar byte;
  do
  {
    if ( ptr >= end )
    {
      result = uint64(-1);
      break;
    }
    byte = *ptr++;
    uint64 slice = byte & 0x7f;
    if ( bit >= 64 || ((slice << bit) >> bit) != slice )
    {
      result = uint64(-1);
      break;
    }
    else
    {
      result |= (slice << bit);
      bit += 7;
    }
  }
  while ( byte & 0x80 );
  *pptr = ptr;
  return result;
}
  int64 unpack_sleb128(const uchar **pptr, const uchar *end)
{
  int64 result = 0;
  int bit = 0;
  const uchar *ptr = *pptr;
  uchar byte;
  do
  {
    if ( ptr >= end )
    {
      byte = 0;
      result = -1;
      break;
    }
    byte = *ptr++;
    uint64 slice = byte & 0x7f;
    if ( bit >= 64 || ((slice << bit) >> bit) != slice )
    {
      byte = 0;
      result = -1;
      break;
    }
    else
    {
      result |= (slice << bit);
      bit += 7;
    }
  }
  while ( byte & 0x80 );
  if ( (byte & 0x40) != 0 )
    result |= uint64(-1) << bit;
  *pptr = ptr;
  return result;
}
static const int ea_packed_size = sizeof(ea_t) + sizeof(ea_t)/4;
static const int dq_packed_size = 10;
static const int dd_packed_size = 5;
static const int dw_packed_size = 3;
 int ds_packed_size(const char *s) { return s ? int(strlen(s)+dd_packed_size) : 1; }
  void append_db(bytevec_t &v, uchar x)
{
  v.push_back(x);
}
  void append_obj(bytevec_t &v, const void *obj, size_t size)
{
  v.append(obj, size);
}
  void append_dw(bytevec_t &v, uint16 x)
{
  uchar packed[3];
  size_t len = pack_dw(packed, packed+sizeof(packed), x) - packed;
  append_obj(v, packed, len);
}
  void append_dd(bytevec_t &v, uint32 x)
{
  uchar packed[5];
  size_t len = pack_dd(packed, packed+sizeof(packed), x) - packed;
  append_obj(v, packed, len);
}
  void append_dq(bytevec_t &v, uint64 x)
{
  uchar packed[10];
  size_t len = pack_dq(packed, packed+sizeof(packed), x) - packed;
  append_obj(v, packed, len);
}
  void append_ea(bytevec_t &v, ea_t x)
{
  uchar packed[10];
  size_t len = pack_ea(packed, packed+sizeof(packed), x) - packed;
  append_obj(v, packed, len);
}
  void append_ds(bytevec_t &v, const char *x)
{
  size_t len = strlen(x);
  append_dd(v, uint32(len));
  append_obj(v, x, len);
}
  void append_buf(bytevec_t &v, const void *buf, size_t len)
{
  append_dd(v, uint32(len));
  append_obj(v, buf, len);
}
  void append_eavec(bytevec_t &v, ea_t ea, const eavec_t &insns)
{
  int n = (int)insns.size();
  append_dw(v, (ushort)n);
  ea_t old = ea;
  for ( int i=0; i < n; i++ )
  {
    ea_t nea = insns[i];
    append_ea(v, nea-old);
    old = nea;
  }
}
extern "C"  uint32 __stdcall calc_crc32(uint32 crc, const void *buf, size_t len);
extern "C"  uint32 __stdcall calc_file_crc32(linput_t *fp);
extern "C" int __stdcall regex_match(const char *str, const char *pattern, bool sense_case);
typedef idc_value_t value_t;
#pragma pack(pop)
#pragma pack(push, 1)
class func_t;
class member_t;
enum cref_t
{
  fl_U,
  fl_CF = 16,
  fl_CN,
  fl_JF,
  fl_JN,
  fl_USobsolete,
  fl_F,
};
enum dref_t
{
  dr_U,
  dr_O,
  dr_W,
  dr_R,
  dr_T,
  dr_I,
};
extern "C" char __stdcall xrefchar(char xrtype);
extern "C" bool __stdcall add_cref(ea_t from, ea_t to, cref_t type);
extern "C" int __stdcall del_cref(ea_t from, ea_t to, bool expand);
extern "C" bool __stdcall add_dref(ea_t from, ea_t to, dref_t type);
extern "C" void __stdcall del_dref(ea_t from, ea_t to);
struct xrefblk_t;
extern "C" bool __stdcall xrefblk_t_first_from(xrefblk_t *,ea_t from,int flags);
extern "C" bool __stdcall xrefblk_t_next_from(xrefblk_t *);
extern "C" bool __stdcall xrefblk_t_first_to(xrefblk_t *,ea_t to,int flags);
extern "C" bool __stdcall xrefblk_t_next_to(xrefblk_t *);
struct xrefblk_t
{
  ea_t from;
  ea_t to;
  uchar iscode;
  uchar type;
  uchar user;
  bool first_from(ea_t from,int flags)
    { return xrefblk_t_first_from(this, from, flags); }
  bool next_from(void)
    { return xrefblk_t_next_from(this); }
  bool first_to(ea_t to,int flags)
    { return xrefblk_t_first_to(this, to, flags); }
  bool next_to(void)
    { return xrefblk_t_next_to(this); }
  bool next_from(ea_t from, ea_t _to, int flags)
  {
    if ( first_from(from, flags) )
    {
      to = _to;
      return next_from();
    }
    return false;
  }
  bool next_to(ea_t _from, ea_t to, int flags)
  {
    if ( first_to(to, flags) )
    {
      from = _from;
      return next_to();
    }
    return false;
  }
};
extern char lastXR;
extern "C" ea_t __stdcall get_first_dref_from(ea_t from);
extern "C" ea_t __stdcall get_next_dref_from(ea_t from,ea_t current);
extern "C" ea_t __stdcall get_first_dref_to(ea_t to);
extern "C" ea_t __stdcall get_next_dref_to(ea_t to,ea_t current);
extern "C" ea_t __stdcall get_first_cref_from(ea_t from);
extern "C" ea_t __stdcall get_next_cref_from(ea_t from,ea_t current);
extern "C" ea_t __stdcall get_first_cref_to(ea_t to);
extern "C" ea_t __stdcall get_next_cref_to(ea_t from,ea_t current);
extern "C" ea_t __stdcall get_first_fcref_from(ea_t from);
extern "C" ea_t __stdcall get_next_fcref_from (ea_t from,ea_t current);
extern "C" ea_t __stdcall get_first_fcref_to  (ea_t to);
extern "C" ea_t __stdcall get_next_fcref_to   (ea_t to,ea_t current);
extern "C" bool __stdcall has_external_refs(func_t *pfn, ea_t ea);
extern "C" void __stdcall create_switch_table(
        ea_t insn_ea,
        const switch_info_ex_t *si);
extern "C" void __stdcall create_switch_xrefs(
        ea_t insn_ea,
        const switch_info_ex_t *si);
typedef qvector<svalvec_t> casevec_t;
extern "C" bool __stdcall calc_switch_cases(
        ea_t insn_ea,
        const switch_info_ex_t *si,
        casevec_t *casevec,
        eavec_t *targets);
extern "C" int __stdcall create_xrefs_from(ea_t ea);
void create_xrefs_from_data(ea_t ea);
extern "C" void __stdcall delete_all_xrefs_from(ea_t ea,int expand);
void delete_data_xrefs_from(ea_t ea);
void delete_code_xrefs_from(ea_t ea,int expand);
bool has_jump_or_flow_xref(ea_t ea);
bool has_call_xref(ea_t ea);
bool destroy_switch_info(ea_t ea);
#pragma pack(pop)
typedef uchar optype_t;
const optype_t
  o_void     =  0,
  o_reg      =  1,
  o_mem      =  2,
  o_phrase   =  3,
  o_displ    =  4,
  o_imm      =  5,
  o_far      =  6,
  o_near     =  7,
  o_idpspec0 =  8,
  o_idpspec1 =  9,
  o_idpspec2 = 10,
  o_idpspec3 = 11,
  o_idpspec4 = 12,
  o_idpspec5 = 13,
  o_last     = 14;
class op_t
{
public:
  uchar         n;
  optype_t      type;
  char          offb;
  char          offo;
  uchar         flags;
  void set_showed()     { flags |=  0x08; }
  void clr_showed()     { flags &= ~0x08; }
  bool showed() const   { return (flags & 0x08) != 0; }
  char          dtyp;
  union
  {
    uint16 reg;
    uint16 phrase;
  };
  bool is_reg(int r) const { return type == o_reg && reg == r; }
  union {
    uval_t value;
    struct {
        uint16 low;
        uint16 high;
    } value_shorts;
  };
  bool is_imm(uval_t v) const { return type == o_imm && value == v; }
  union {
    ea_t addr;
    struct {
        uint16 low;
        uint16 high;
    } addr_shorts;
  };
  union {
    ea_t specval;
    struct {
        uint16 low;
        uint16 high;
    } specval_shorts;
  };
  char          specflag1;
  char          specflag2;
  char          specflag3;
  char          specflag4;
};
class insn_t
{
public:
  ea_t cs;
  ea_t ip;
  ea_t ea;
  uint16 itype;
   bool is_canon_insn(void) const;
   uint32 get_canon_feature(void) const;
   const char *get_canon_mnem(void) const;
  uint16 size;
  union
  {
    uint16 auxpref;
    struct
    {
      uchar low;
      uchar high;
    } auxpref_chars;
  };
  char segpref;
  char insnpref;
  op_t Operands[6];
  char flags;
  bool is_macro(void) const { return (flags & 0x01) != 0; }
};
union value_u
{
  uint8  v_char;
  uint16 v_short;
  uint32 v_long;
  struct dq_t { uint32 low; uint32 high; } _dq;
  struct dt_t { uint32 low; uint32 high; uint16 upper; } dt;
  uint8 byte16[16];
  uint32 dword3[3];
};
extern "C" size_t __stdcall get_operand_immvals(ea_t ea, int n, uval_t *v);
extern "C" insn_t __declspec(dllimport) cmd;
extern "C" int __declspec(dllimport) lookback;
extern "C" flags_t __declspec(dllimport) uFlag;
extern "C" ea_t __stdcall dataSeg_opreg(int opnum, int rgnum);
extern "C" ea_t __stdcall dataSeg_op(int opnum);
extern "C" ea_t __stdcall dataSeg(void);
extern "C" ea_t __stdcall codeSeg(ea_t addr, int opnum);
enum tribyte_order_t
{
  tbo_123,
  tbo_132,
  tbo_213,
  tbo_231,
  tbo_312,
  tbo_321,
};
extern "C" uint8  __stdcall ua_next_byte(void);
extern "C" uint16 __stdcall ua_next_word(void);
extern "C" uint32 __stdcall ua_next_long(void);
extern "C" uint64 __stdcall ua_next_qword(void);
extern "C" void __stdcall init_output_buffer(char *buf, size_t bufsize);
extern "C" char *__stdcall term_output_buffer(void);
extern "C"  int __stdcall out_snprintf(const char *format, ...);
extern "C" char *__stdcall set_output_ptr(char *ptr);
 char *__stdcall get_output_ptr(void) { return set_output_ptr(0); }
extern "C" void __stdcall out_insert(char *ptr, const char *string);
extern "C" int __stdcall OutMnem(int width=8, const char *postfix=0);
extern "C" void __stdcall OutBadInstruction(void);
extern "C" int __stdcall out_one_operand(int n);
extern "C" flags_t __stdcall OutValue(op_t &x, int outflags=0);
uval_t get_immval(const op_t &x,
                  int outf=0,
                  bool extend_sign=false,
                  char *dtyp_ptr=0,
                  size_t *nbytes_ptr=0);
extern "C" void __stdcall out_symbol(char c);
extern "C" void __stdcall out_line(const char *str, color_t color);
 void out_keyword(const char *str)
{
  out_line(str, COLOR_KEYWORD);
}
 void out_register(const char *str)
{
  out_line(str, COLOR_REG);
}
extern "C" void __stdcall out_tagon(color_t tag);
extern "C" void __stdcall out_tagoff(color_t tag);
extern "C" void __stdcall out_addr_tag(ea_t ea);
extern "C" void __stdcall out_colored_register_line(const char *str);
extern "C" void __stdcall OutLine(const char *s);
extern "C" void __stdcall OutChar(char c);
extern "C" void __stdcall OutLong(uval_t Word, char radix);
extern "C" void __stdcall OutImmChar(op_t &x);
extern "C" bool __stdcall showAsChar(const void *ptr, char *buf, int size);
extern "C" bool __stdcall out_real(const void *v, int size, char *buf, size_t bufsize);
extern "C" int __declspec(dllimport) voidop;
extern "C" void __stdcall out_long(sval_t v, char radix);
extern "C" bool __stdcall out_name_expr(const op_t &x,
                                     ea_t ea,
                                     adiff_t off=ea_t(-1));
extern "C" bool __stdcall ua_dodata2(int opoff, ea_t ea, int dtype);
extern "C" bool __stdcall ua_stkvar2(const op_t &x, adiff_t v, int flags);
extern "C" void __stdcall ua_add_cref(int opoff, ea_t to, cref_t type);
extern "C" void __stdcall ua_add_dref(int opoff, ea_t to, dref_t type);
extern "C" ea_t __stdcall ua_add_off_drefs(const op_t &x, dref_t type);
extern "C" ea_t __stdcall ua_add_off_drefs2(const op_t &x, dref_t type, int outf);
extern "C" flags_t __stdcall get_dtyp_flag(char dtype);
extern "C" size_t __stdcall get_dtyp_size(char dtype);
extern "C" char __stdcall get_dtyp_by_size(asize_t size);
extern "C" int __stdcall create_insn(ea_t ea);
extern "C" int __stdcall decode_insn(ea_t ea);
extern "C" bool __stdcall ua_outop2(ea_t ea, char *buf, size_t bufsize, int n, int flags=0);
extern "C" const char *__stdcall ua_mnem(ea_t ea, char *buf, size_t bufsize);
extern "C" ea_t __stdcall decode_prev_insn(ea_t ea);
extern "C" ea_t __stdcall decode_preceding_insn(ea_t ea, bool *p_farref);
extern "C" bool __stdcall construct_macro(bool enable,
                        bool (__stdcall *build_macro)(insn_t &s, bool may_go_forward));
extern "C" ea_t __stdcall guess_table_address(void);
extern "C" asize_t __stdcall guess_table_size(ea_t jump_table);
extern "C" int __stdcall get_spoiled_reg(const uint32 *regs, size_t n);
int ua_out(ea_t ea, bool create_insn);
bool ua_use_fixup(void);
void init_ua(void);
void term_ua(void);
size_t get_equal_items(ea_t ea, size_t itemsize, value_u *v, bool *isdef);
extern "C" void __stdcall ua_dodata(ea_t ea, int dtype);
extern "C" bool __stdcall ua_outop(ea_t ea, char *buf, size_t bufsize, int n);
extern "C" bool __stdcall ua_stkvar(const op_t &x, adiff_t v);
extern "C" int __stdcall ua_ana0(ea_t ea);
extern "C" int __stdcall ua_code(ea_t ea);
#pragma pack(pop)
class member_t;
class mvm_t;
typedef int help_t;
class WorkReg;
struct AbstractRegister
{
  virtual uval_t __stdcall value(void) const = 0;
  virtual bool __stdcall isDef(void) const = 0;
};
struct rginfo
{
  AbstractRegister  *low;
  AbstractRegister *high;
  AbstractRegister *word;
};
typedef struct
{
  uchar len;
  uchar *bytes;
} bytes_t;
typedef const char *(__stdcall set_options_t)(const char *keyword, int value_type,
                                            const void *value);
extern "C" bool __stdcall read_user_config_file(const char *file,
                                             set_options_t *callback,
                                             const char *macroname = 0);
struct instruc_t
{
  const char *name;
  uint32 feature;
};
extern "C" bool __stdcall InstrIsSet(int icode,int bit);
extern "C" bool __stdcall is_call_insn(ea_t ea);
extern "C" bool __stdcall is_ret_insn(ea_t ea, bool strict=true);
extern "C" bool __stdcall is_indirect_jump_insn(ea_t ea);
extern "C" bool __stdcall is_basic_block_end(bool call_insn_stops_block);
typedef struct
{
    char  *iaflg;
    char  *prefix;
    char  *seg;
    char  *reg;
    char  *offset;
} s_preline;
enum ca_operation_t  {
  ca_lev_on   = 020,
  ca_lev_off  = 1,
  ca_not      = 2,
  ca_minus    = 3,
  ca_plus     = 4,
  ca_mod      = 5,
  ca_div_u    = 6,
  ca_div      = 7,
  ca_mul      = 010,
  ca_and      = 011,
  ca_or       = 012,
  ca_xor      = 013,
  ca_shl      = 014,
  ca_shr      = 015,
  ca_UN_MSK   = 020,
  ca_not_UN   = ca_UN_MSK | ca_not,
  ca_minus_UN = ca_UN_MSK | ca_minus,
  ca_h_delim  = 037,
};
enum _chkarg_cmd  {
  chkarg_atomprefix = 1,
  chkarg_preline    = 2,
  chkarg_operseg    = 3,
  chkarg_cmpseg     = 4,
  chkarg_gettable   = 5
};
struct asm_t
{
  uint32 flag;
  uint16 uflag;
  const char *name;
  help_t help;
  const char **header;
  const uint16 *badworks;
  const char *origin;
  const char *end;
  const char *cmnt;
  char ascsep;
  char accsep;
  const char *esccodes;
  const char *a_ascii;
  const char *a_byte;
  const char *a_word;
  const char *a_dword;
  const char *a_qword;
  const char *a_oword;
  const char *a_float;
  const char *a_double;
  const char *a_tbyte;
  const char *a_packreal;
  const char *a_dups;
  const char *a_bss;
  const char *a_equ;
  const char *a_seg;
  bool (__stdcall* checkarg_dispatch)(void *a1, void *a2, uchar cmd);
  void *_UNUSED1_was_atomprefix;
  void *_UNUSED2_was_checkarg_operations;
  const uchar *XlatAsciiOutput;
  const char *a_curip;
  void (__stdcall *func_header)(func_t *);
  void (__stdcall *func_footer)(func_t *);
  const char *a_public;
  const char *a_weak;
  const char *a_extrn;
  const char *a_comdef;
  ssize_t (__stdcall *get_type_name)(flags_t flag,
                                  ea_t ea_or_id,
                                  char *buf,
                                  size_t bufsize);
  const char *a_align;
  char lbrace;
  char rbrace;
  const char *a_mod;
  const char *a_band;
  const char *a_bor;
  const char *a_xor;
  const char *a_bnot;
  const char *a_shl;
  const char *a_shr;
  const char *a_sizeof_fmt;
  uint32 flag2;
  const char *cmnt2;
  const char *low8;
  const char *high8;
  const char *low16;
  const char *high16;
  const char *a_include_fmt;
  const char *a_vstruc_fmt;
  const char *a_3byte;
  const char *a_rva;
};
struct processor_t
{
  int version;
  int id;
  uint32 flag;
  bool has_segregs(void) const  { return (flag & 0x000001)     != 0; }
  bool use32(void) const        { return (flag & (0x002000|0x000002)) != 0; }
  bool use64(void) const        { return (flag & 0x002000)    != 0; }
  bool ti(void) const           { return (flag & 0x001000) != 0; }
  bool stkup(void) const        { return (flag & 0x008000) != 0; }
  bool use_tbyte(void) const    { return (flag & 0x8000000) != 0; }
  int get_segm_bitness(void) const { return (flag & 0x10000000) != 0 ? 2 : (flag & 0x000004) != 0; }
  int cnbits;
  int dnbits;
  int cbsize(void) { return (cnbits+7)/8; }
  int dbsize(void) { return (dnbits+7)/8; }
  const char **psnames;
  const char **plnames;
  asm_t **assemblers;
  enum cust_fix
  {
      cf_base,
      cf_size,
      cf_desc,
      cf_apply,
      cf_move,
  };
  enum idp_notify
  {
        init,
        term,
        newprc,
        newasm,
        newfile,
        oldfile,
        newbinary,
        endbinary,
        newseg,
        assemble,
        obsolete_makemicro,
        outlabel,
        rename,
        may_show_sreg,
        closebase,
        load_idasgn,
        coagulate,
        auto_empty,
        auto_queue_empty,
        func_bounds,
        may_be_func,
        is_sane_insn,
        is_jump_func,
        gen_regvar_def,
        setsgr,
        set_compiler,
        is_basic_block_end,
        reglink,
        get_vxd_name,
        custom_ana,
        custom_out,
        custom_emu,
        custom_outop,
        custom_mnem,
        undefine,
        make_code,
        make_data,
        moving_segm,
        move_segm,
        is_call_insn,
        is_ret_insn,
        get_stkvar_scale_factor,
        create_flat_group,
        kernel_config_loaded,
        might_change_sp,
        is_alloca_probe,
        out_3byte,
        get_reg_name,
        savebase,
        gen_asm_or_lst,
        out_src_file_lnnum,
        get_autocmt,
        is_insn_table_jump,
        auto_empty_finally,
        loader_finished,
        loader_elf_machine,
        is_indirect_jump,
        verify_noreturn,
        verify_sp,
        renamed,
        add_func,
        del_func,
        set_func_start,
        set_func_end,
        treat_hindering_item,
        str2reg,
        create_switch_xrefs,
        calc_switch_cases,
        determined_main,
        preprocess_chart,
        get_bg_color,
        validate_flirt_func,
        get_operand_string,
        add_cref,
        add_dref,
        del_cref,
        del_dref,
        coagulate_dref,
        custom_fixup,
        off_preproc,
        set_proc_options,
        last_cb_before_debugger,
        get_operand_info = 100,
        get_reg_info,
        get_jump_target,
        calc_step_over,
        get_macro_insn_head,
        get_dbr_opnum,
        insn_sets_tbit,
        reserved_entry,
        calc_next_eas,
        decorate_name=500,
        setup_til,
        based_ptr,
        max_ptr_size,
        get_default_enum_size,
        calc_arglocs,
        use_stkarg_type,
        use_regarg_type,
        use_arg_types,
        get_fastcall_regs,
        get_thiscall_regs,
        calc_cdecl_purged_bytes,
        get_stkarg_offset,
        calc_purged_bytes,
        calc_arglocs2,
        calc_retloc,
        calc_varglocs,
        get_varcall_regs,
        use_regarg_type2,
        use_arg_types2,
        get_fastcall_regs2,
        get_thiscall_regs2,
        get_varcall_regs2,
        calc_cdecl_purged_bytes2,
        get_stkarg_offset2,
        til_for_file,
        loader=1000,
  };
  int   (__stdcall* notify)(idp_notify msgid, ...);
   int get_stkvar_scale(void)
     { return (flag & 0x400000) ? notify(get_stkvar_scale_factor) : 1; }
  void  (__stdcall* header)(void);
  void  (__stdcall* footer)(void);
  void  (__stdcall* segstart)(ea_t ea);
  void  (__stdcall* segend)  (ea_t ea);
  void  (__stdcall* assumes) (ea_t ea);
  int   (__stdcall* u_ana)   (void);
  int   (__stdcall* u_emu)   (void);
  void  (__stdcall* u_out)   (void);
  bool  (__stdcall* u_outop) (op_t &op);
  void  (__stdcall* d_out)   (ea_t ea);
  bool  (__stdcall* cmp_opnd)(const op_t &op1, const op_t &op2);
  bool  (__stdcall* can_have_type)(op_t &op);
  int   regsNum;
  const char **regNames;
  AbstractRegister *(__stdcall* getreg)(int regnum);
  int   rFiles;
  const char **rFnames;
  rginfo *rFdescs;
  WorkReg *CPUregs;
  int   regFirstSreg;
  int   regLastSreg;
  int   segreg_size;
  int   regCodeSreg;
  int   regDataSreg;
  const bytes_t *codestart;
  const bytes_t *retcodes;
  int   instruc_start;
  int   instruc_end;
  bool is_canon_insn(uint16 itype) const { return itype >= instruc_start && itype < instruc_end; }
  instruc_t *instruc;
  int   (__stdcall* is_far_jump)(int icode);
  ea_t (__stdcall* translate)(ea_t base, adiff_t offset);
  size_t tbyte_size;
  int (__stdcall* realcvt)(void *m, uint16 *e, uint16 swt);
  char real_width[4];
  bool (__stdcall* is_switch)(switch_info_ex_t *si);
  int32 (__stdcall* gen_map_file)(FILE *fp);
  ea_t (__stdcall* extract_address)(ea_t ea,const char *string,int x);
   int (__stdcall* is_sp_based)(const op_t &x);
   bool (__stdcall* create_func_frame)(func_t *pfn);
   int (__stdcall* get_frame_retsize)(func_t *pfn);
   void (__stdcall* gen_stkvar_def)(char *buf,
                                 size_t bufsize,
                                 const member_t *mptr,
                                 sval_t v);
   bool (__stdcall* u_outspec)(ea_t ea,uchar segtype);
   int icode_return;
  set_options_t *set_idp_options;
  int (__stdcall* is_align_insn)(ea_t ea);
  mvm_t *mvm;
  int high_fixup_bits;
};
extern "C" processor_t __declspec(dllimport) ph;
extern "C" asm_t __declspec(dllimport) ash;
extern "C" int __stdcall str2regf(const char *p);
extern "C" int __stdcall str2reg(const char *p);
extern "C" ssize_t __stdcall get_reg_name(int reg, size_t width, char *buf, size_t bufsize, int reghi=-1);
 const char *get_reg_info(const char *regname, uint64 *mask)
{
  const char *r2;
  if ( ph.notify != 0 )
  {
    if ( ph.notify(ph.get_reg_info, regname, &r2, mask) == 0 )
      return r2;
    if ( str2reg(regname) != -1 )
    {
      if ( mask != 0 )
        *mask = 0;
      return regname;
    }
  }
  return 0;
}
struct reg_info_t
{
  int reg;
  int size;
  bool operator==(const reg_info_t &r) const
  {
    return reg == r.reg && size == r.size;
  }
  bool operator!=(const reg_info_t &r) const
  {
    return !(*this == r);
  }
};
template <> struct ida_movable_type<reg_info_t> { typedef ida_true_type is_movable_type; };
typedef qvector<reg_info_t> reginfovec_t;
extern "C" bool __stdcall parse_reg_name(const char *regname, reg_info_t *ri);
 bool insn_t::is_canon_insn(void) const
{
  return ph.is_canon_insn(itype);
}
 const char *insn_t::get_canon_mnem(void) const
{
  return is_canon_insn() ? ph.instruc[itype-ph.instruc_start].name : 0;
}
 uint32 insn_t::get_canon_feature(void) const
{
  return is_canon_insn() ? ph.instruc[itype-ph.instruc_start].feature : 0;
}
 size_t sizeof_ldbl(void)
{
  return inf.size_ldbl ? inf.size_ldbl : ph.tbyte_size;
}
extern "C" void __stdcall intel_data(ea_t ea);
extern "C" bool __stdcall gen_spcdef(ea_t ea,uchar segtype);
extern "C" bool __stdcall gen_extern(ea_t ea,const char *name);
extern "C" bool __stdcall gen_abssym(ea_t ea,const char *name);
extern "C" bool __stdcall gen_comvar(ea_t ea,const char *name);
extern "C" char *__stdcall set_processor_type(const char *procname,int level);
extern "C" char *__stdcall get_idp_name(char *buf, size_t bufsize);
extern "C" bool __stdcall set_target_assembler(int asmnum);
void free_processor_module(void);
void read_config_file(int npass, bool testmode);
namespace idb_event
{
  enum event_code_t
  {
    byte_patched,
    cmt_changed,
    ti_changed,
    op_ti_changed,
    op_type_changed,
    enum_created,
    enum_deleted,
    enum_bf_changed,
    enum_renamed,
    enum_cmt_changed,
    enum_const_created,
    enum_const_deleted,
    struc_created,
    struc_deleted,
    struc_renamed,
    struc_expanded,
    struc_cmt_changed,
    struc_member_created,
    struc_member_deleted,
    struc_member_renamed,
    struc_member_changed,
    thunk_func_created,
    func_tail_appended,
    func_tail_removed,
    tail_owner_changed,
    func_noret_changed,
    segm_added,
    segm_deleted,
    segm_start_changed,
    segm_end_changed,
    segm_moved,
    area_cmt_changed,
    changing_cmt,
    changing_ti,
    changing_op_ti,
    changing_op_type,
    deleting_enum,
    changing_enum_bf,
    renaming_enum,
    changing_enum_cmt,
    deleting_enum_const,
    deleting_struc,
    renaming_struc,
    expanding_struc,
    changing_struc_cmt,
    deleting_struc_member,
    renaming_struc_member,
    changing_struc_member,
    removing_func_tail,
    deleting_segm,
    changing_segm_start,
    changing_segm_end,
    changing_area_cmt,
    changing_segm_name,
    changing_segm_class,
    segm_name_changed,
    segm_class_changed,
  };
};
void gen_idb_event(idb_event::event_code_t code, ...);
#pragma pack(pop)
#pragma pack(push, 1)
typedef int atype_t;
const atype_t
  AU_NONE = 00,
  AU_UNK  = 10,
  AU_CODE = 20,
  AU_WEAK = 25,
  AU_PROC = 30,
  AU_TAIL = 35,
  AU_TRSP = 38,
  AU_USED = 40,
  AU_TYPE = 50,
  AU_LIBF = 60,
  AU_LBF2 = 70,
  AU_LBF3 = 80,
  AU_CHLB = 90,
  AU_FINAL=200;
typedef int idastate_t;
const idastate_t
  st_Ready  = 0,
  st_Think  = 1,
  st_Waiting= 2,
  st_Work   = 3;
extern "C" int __declspec(dllimport) autoEnabled;
extern "C" atype_t __declspec(dllimport) auto_state;
struct auto_display_t
{
  atype_t type;
  ea_t ea;
  idastate_t state;
};
extern "C" auto_display_t __declspec(dllimport) auto_display;
 void showAuto(ea_t ea, atype_t type=AU_NONE)
{
  auto_display.type = type;
  auto_display.ea = ea;
}
 void showAddr(ea_t ea) { showAuto(ea); }
 idastate_t setStat(idastate_t st)
{
  idastate_t old = auto_display.state;
  auto_display.state = st;
  return old;
}
 bool may_create_stkvars(void)
{
  return should_create_stkvars() && auto_state == AU_USED;
}
 bool may_trace_sp(void)
{
  return should_trace_sp() && (auto_state == AU_USED || auto_state == AU_TRSP);
}
extern "C" void __stdcall auto_mark_range(ea_t start,ea_t end,atype_t type);
 void autoMark(ea_t ea, atype_t type)
{
  if ( ea != ea_t(-1) )
    auto_mark_range(ea, ea+1, type);
}
extern "C" void __stdcall autoUnmark(ea_t start,ea_t end,atype_t type);
 void noUsed(ea_t ea)
  { autoMark(ea,AU_USED); }
 void noUsed(ea_t sEA,ea_t eEA)
  { auto_mark_range(sEA,eEA,AU_USED); }
 void auto_make_code(ea_t ea)
  { autoMark(ea,AU_CODE); }
 void auto_make_proc(ea_t ea)
  { auto_make_code(ea); autoMark(ea,AU_PROC); }
void queue_weak_code(ea_t ea);
extern "C" void __stdcall reanalyze_callers(ea_t ea, bool noret);
void auto_process_all(ea_t low, ea_t high, atype_t type);
extern "C" void __stdcall auto_apply_type(ea_t caller, ea_t callee);
extern "C" int __stdcall analyze_area(ea_t sEA,ea_t eEA);
bool is_planned_ea(ea_t ea);
ea_t get_next_planned_ea(ea_t ea);
void autoDelCode(ea_t ea);
extern "C" bool __stdcall autoWait(void);
extern "C" void __stdcall autoCancel(ea_t ea1,ea_t ea2);
extern "C" bool __stdcall autoIsOk(void);
extern "C" bool __stdcall autoStep(void);
ea_t autoPeek(ea_t lowEA, atype_t type);
extern "C" ea_t __stdcall auto_get(ea_t lowEA, ea_t highEA, atype_t *type);
void auto_init(void);
void auto_save(void);
void auto_term(void);
extern "C" const char *__stdcall autoGetName(atype_t type);
extern ea_t ea_without_xrefs;
#pragma pack(pop)
#pragma pack(push, 1)
extern "C"  const char *__stdcall idadir(const char *subdir);
extern "C"  char *__stdcall getsysfile(
        char *buf,
        size_t bufsize,
        const char *filename,
        const char *subdir);
extern "C"  const char *__stdcall get_user_idadir(void);
extern "C"  int __stdcall enumerate_files(
        char *answer,
        size_t answer_size,
        const char *path,
        const char *fname,
        int (__stdcall*func)(const char *file,void *ud),
        void *ud);
  int __stdcall enumerate_system_files(
       char *answer,
       size_t answer_size,
       const char *subdir,
       const char *fname,
       int (__stdcall*func)(const char *file,void *ud),
       void *ud)
{
  return enumerate_files(answer, answer_size, idadir(subdir), fname, func, ud);
}
extern "C"  FILE *__stdcall fopenWT(const char *file);
extern "C"  FILE *__stdcall fopenWB(const char *file);
extern "C"  FILE *__stdcall fopenRT(const char *file);
extern "C"  FILE *__stdcall fopenRB(const char *file);
extern "C"  FILE *__stdcall fopenM(const char *file);
extern "C"  FILE *__stdcall fopenA(const char *file);
extern "C"  FILE *__stdcall openR(const char *file);
extern "C"  FILE *__stdcall openRT(const char *file);
extern "C"  FILE *__stdcall openM(const char *file);
extern "C"  FILE *__stdcall ecreate(const char *file);
extern "C"  FILE *__stdcall ecreateT(const char *file);
extern "C"  void __stdcall eclose(FILE *fp);
extern "C"  void __stdcall eread(FILE *fp, void *buf, ssize_t size);
extern "C"  void __stdcall ewrite(FILE *fp, const void *buf, ssize_t size);
extern "C"  void __stdcall eseek(FILE *fp, int32 pos);
extern "C"  uint32 __stdcall efilelength(FILE *fp);
extern "C"  void __stdcall echsize(FILE *fp,uint32 size);
extern "C"  uint64 __stdcall getdspace(const char *path);
struct ioport_bit_t
{
  char *name;
  char *cmt;
};
typedef ioport_bit_t ioport_bits_t[16];
struct ioport_t
{
  ea_t address;
  char *name;
  char *cmt;
  ioport_bits_t *bits;
  void *userdata;
};
extern "C"  ioport_t *__stdcall read_ioports(
        size_t *_numports,
        const char *file,
        char *default_device,
        size_t dsize,
        const char *(__stdcall* callback)(
                const ioport_t *ports,
                size_t numports,
                const char *line));
extern "C"  bool __stdcall choose_ioport_device(
        const char *file,
        char *device,
        size_t device_size,
        const char *(__stdcall* parse_params)(
                const char *line,
                char *buf,
                size_t bufsize));
extern "C"  const ioport_t *__stdcall find_ioport(const ioport_t *ports, size_t numports, ea_t address);
extern "C"  const ioport_bit_t *__stdcall find_ioport_bit(const ioport_t *ports, size_t numports, ea_t address, size_t bit);
extern "C"  void __stdcall free_ioports(ioport_t *ports, size_t numports);
extern "C"  int __stdcall call_system(const char *command);
class linput_t;
enum linput_type_t
{
  LINPUT_NONE,
  LINPUT_LOCAL,
  LINPUT_RFILE,
  LINPUT_PROCMEM,
  LINPUT_GENERIC
};
extern "C" void __stdcall lread(linput_t *li, void *buf, size_t size);
extern "C" ssize_t __stdcall qlread(linput_t *li, void *buf, size_t size);
extern "C" char *__stdcall qlgets(char *s, size_t len, linput_t *li);
extern "C" int __stdcall qlgetc(linput_t *li);
extern "C" int __stdcall lreadbytes(linput_t *li, void *buf, size_t size, bool mf);
 int __stdcall lread2bytes(linput_t *li, int16 *res, bool mf) { return lreadbytes(li, res, 2, mf); }
 int __stdcall lread2bytes(linput_t *li, uint16 *res, bool mf) { return lreadbytes(li, res, 2, mf); }
 int __stdcall lread4bytes(linput_t *li, int32 *res, bool mf) { return lreadbytes(li, res, 4, mf); }
 int __stdcall lread4bytes(linput_t *li, uint32 *res, bool mf) { return lreadbytes(li, res, 4, mf); }
 int __stdcall lread8bytes(linput_t *li, int64 *res, bool mf) { return lreadbytes(li, res, 8, mf); }
 int __stdcall lread8bytes(linput_t *li, uint64 *res, bool mf) { return lreadbytes(li, res, 8, mf); }
extern "C" char *__stdcall qlgetz(
        linput_t *li,
        int32 fpos,
        char *buf,
        size_t bufsize);
extern "C" int32 __stdcall qlsize(linput_t *li);
extern "C" int32 __stdcall qlseek(linput_t *li, int32 pos, int whence=0);
 int32 __stdcall qltell(linput_t *li) { return qlseek(li, 0, 1); }
extern "C" linput_t *__stdcall open_linput(const char *file, bool remote);
extern "C" void __stdcall close_linput(linput_t *li);
extern "C" FILE *__stdcall qlfile(linput_t *li);
extern "C" linput_t *__stdcall make_linput(FILE *fp);
extern "C" void __stdcall unmake_linput(linput_t *li);
struct generic_linput_t
{
  uint32 filesize;
  uint32 blocksize;
  virtual ssize_t __stdcall read(off_t off, void *buffer, size_t nbytes) = 0;
  virtual __stdcall ~generic_linput_t(void) {}
};
extern "C" linput_t *__stdcall create_generic_linput(generic_linput_t *gl);
extern "C" linput_t *__stdcall create_memory_linput(ea_t start, asize_t size);
 linput_type_t __stdcall get_linput_type(linput_t *li)
{
  return *(linput_type_t *)li;
}
generic_linput_t *create_remote_linput(const char *file);
extern "C" int __stdcall set_thread_priority(ushort pclass,int32 delta);
#pragma pack(pop)
#pragma pack(push, 1)
extern "C"  int __stdcall zip_deflate(
        void *ud,
        ssize_t (__stdcall *file_reader)(void *ud, void *buf, size_t size),
        ssize_t (__stdcall *file_writer)(void *ud, const void *buf, size_t size));
extern "C"  int __stdcall zip_inflate(
        void *ud,
        ssize_t (__stdcall *file_reader)(void *ud, void *buf, size_t size),
        ssize_t (__stdcall *file_writer)(void *ud, const void *buf, size_t size));
extern "C"  int __stdcall process_zipfile(
        const char *zipfile,
        int (__stdcall *_callback)(
                         void *ud,
                         int32 offset,
                         int method,
                         uint32 csize,
                         uint32 ucsize,
                         uint32 attributes,
                         const char *filename),
        void *ud);
extern bool legacy_idb;
enum linput_close_code_t
{
  LOC_CLOSE,
  LOC_UNMAKE,
  LOC_KEEP,
};
extern "C"  linput_t *__stdcall create_zip_linput(
        linput_t *in,
        ssize_t insize=-1,
        linput_close_code_t loc=LOC_CLOSE);
#pragma pack(pop)
#pragma pack(push, 4)
#pragma pack(push, 4)
typedef uchar type_t;
typedef uchar p_list;
class idc_value_t;
typedef uint32 argloc_t;
typedef int pid_t;
typedef int thid_t;
struct process_info_t
{
  pid_t pid;
  char name[1024];
};
template <> struct ida_movable_type<process_info_t> { typedef ida_true_type is_movable_type; };
typedef unsigned char register_class_t;
struct register_info_t
{
  const char *name;
  uint32 flags;
  register_class_t register_class;
  char dtyp;
  const char *const *bit_strings;
  int bit_strings_default;
};
template <> struct ida_movable_type<register_info_t> { typedef ida_true_type is_movable_type; };
struct memory_info_t : public area_t
{
  memory_info_t(void)
    : sbase(0),bitness(0),perm(0) {}
  qstring name;
  qstring sclass;
  ea_t sbase;
  uchar bitness;
  uchar perm;
  bool operator ==(const memory_info_t &r) const
  {
    return startEA == r.startEA
        && endEA   == r.endEA
        && name    == r.name
        && sclass  == r.sclass
        && sbase   == r.sbase
        && bitness == r.bitness
        && perm    == r.perm;
  }
  bool operator !=(const memory_info_t &r) const { return !(*this == r); }
};
template <> struct ida_movable_type<memory_info_t> { typedef ida_true_type is_movable_type; };
typedef qvector<memory_info_t> meminfo_vec_t;
enum event_id_t
{
  NO_EVENT       = 0x00000000,
  PROCESS_START  = 0x00000001,
  PROCESS_EXIT   = 0x00000002,
  THREAD_START   = 0x00000004,
  THREAD_EXIT    = 0x00000008,
  BREAKPOINT     = 0x00000010,
  STEP           = 0x00000020,
  EXCEPTION      = 0x00000040,
  LIBRARY_LOAD   = 0x00000080,
  LIBRARY_UNLOAD = 0x00000100,
  INFORMATION    = 0x00000200,
  SYSCALL        = 0x00000400,
  WINMESSAGE     = 0x00000800,
  PROCESS_ATTACH = 0x00001000,
  PROCESS_DETACH = 0x00002000,
  PROCESS_SUSPEND= 0x00004000,
};
struct module_info_t
{
  char name[1024];
  ea_t base;
  asize_t size;
  ea_t rebase_to;
};
struct e_breakpoint_t
{
  ea_t hea;
  ea_t kea;
};
struct e_exception_t
{
  uint32 code;
  bool can_cont;
  ea_t ea;
  char info[1024];
};
struct debug_event_t
{
  debug_event_t(void) : eid(NO_EVENT) {}
  event_id_t eid;
  pid_t pid;
  thid_t tid;
  ea_t ea;
  bool handled;
  union
  {
    module_info_t modinfo;
    int exit_code;
    char info[1024];
    e_breakpoint_t bpt;
    e_exception_t exc;
  };
  ea_t bpt_ea(void) const
  {
    return eid == BREAKPOINT && bpt.kea != ea_t(-1) ? bpt.kea : ea;
  }
};
typedef int bpttype_t;
const bpttype_t
  BPT_EXEC  =  0,
  BPT_WRITE =  1,
  BPT_RDWR  =  3,
  BPT_SOFT  =  4;
struct exception_info_t
{
  uint code;
  uint32 flags;
  bool break_on(void) const { return (flags & 0x0001) != 0; }
  bool handle(void) const { return (flags & 0x0002) != 0; }
  qstring name;
  qstring desc;
  exception_info_t(void) {}
  exception_info_t(uint _code, uint32 _flags, const char *_name, const char *_desc)
    : code(_code), flags(_flags), name(_name), desc(_desc) {}
};
template <> struct ida_movable_type<exception_info_t> { typedef ida_true_type is_movable_type; };
typedef qvector<exception_info_t> excvec_t;
struct regval_t
{
  int32 rvtype;
  union
  {
    uint64 ival;
    uint16 fval[6];
    uchar reserve[sizeof(bytevec_t)];
  };
  regval_t(void) : rvtype((-1)), ival(~uint64(0)) {}
  ~regval_t(void) { clear(); }
  regval_t(const regval_t &r) : rvtype((-1)) { *this = r; }
  regval_t &operator = (const regval_t &r)
  {
    if ( r.rvtype >= 0 )
    {
      if ( rvtype >= 0 )
        bytes() = r.bytes();
      else
        new (&bytes()) bytevec_t(r.bytes());
    }
    else
    {
      if ( rvtype >= 0 )
        bytes().~bytevec_t();
      memcpy(fval, r.fval, sizeof(fval));
    }
    rvtype = r.rvtype;
    return *this;
  }
  void clear(void)
  {
    if ( rvtype >= 0 )
    {
      bytes().~bytevec_t();
      rvtype = (-1);
    }
  }
  bool operator == (const regval_t &r) const
  {
    if ( rvtype == r.rvtype )
    {
      if ( rvtype == (-1) )
        return ival == r.ival;
      return memcmp(get_data(), r.get_data(), get_data_size()) == 0;
    }
    return false;
  }
  bool operator != (const regval_t &r) const { return !(*this == r); }
  void _set_int(uint64 x) { ival = x; }
  void _set_float(const ushort *x) { memcpy(fval, x, sizeof(fval)); rvtype = (-2); }
  void set_int(uint64 x) { clear(); _set_int(x); }
  void set_float(const ushort *x) { clear(); _set_float(x); }
  void swap(regval_t &r) { qswap(*this, r); }
        bytevec_t &bytes(void)       { return *(bytevec_t *)reserve; }
  const bytevec_t &bytes(void) const { return *(bytevec_t *)reserve; }
  void _set_bytes(const uchar *data, size_t size) { new (&bytes()) bytevec_t(data, size); rvtype = 0; }
  void _set_bytes(const bytevec_t &v) { new (&bytes()) bytevec_t(v); rvtype = 0; }
  void set_bytes(const uchar *data, size_t size) { clear(); _set_bytes(data, size); }
  void set_bytes(const bytevec_t &v) { clear(); _set_bytes(v); }
  bytevec_t &_set_bytes(void) { new (&bytes()) bytevec_t; rvtype = 0; return bytes(); }
  bytevec_t &set_bytes(void) { clear(); _set_bytes(); return bytes(); }
        void *get_data(void)       { return rvtype >= 0 ? (void *)bytes().begin() : (void *)&fval; }
  const void *get_data(void) const { return rvtype >= 0 ? (void *)bytes().begin() : (void *)&fval; }
  size_t get_data_size(void) const { return rvtype >= 0 ? bytes().size() : rvtype == (-1) ? sizeof(ival) : sizeof(fval); }
};
template <> struct ida_movable_type<regval_t> { typedef ida_true_type is_movable_type; };
typedef qvector<regval_t> regvals_t;
struct call_stack_info_t
{
  ea_t callea;
  ea_t funcea;
  ea_t fp;
  bool funcok;
  bool operator==(const call_stack_info_t &r) const
  {
    return callea == r.callea
        && funcea == r.funcea
        && funcok == r.funcok
        && fp     == r.fp;
  }
  bool operator!=(const call_stack_info_t &r) const { return !(*this == r); }
};
template <> struct ida_movable_type<call_stack_info_t> { typedef ida_true_type is_movable_type; };
struct call_stack_t : public qvector<call_stack_info_t>
{
  bool dirty;
};
extern "C" error_t __stdcall appcall(
        ea_t func_ea,
        thid_t tid,
        const type_t *type,
        const p_list *fields,
        int argnum,
        idc_value_t *argv,
        idc_value_t *r);
extern "C" error_t __stdcall cleanup_appcall(thid_t tid);
enum gdecode_t
{
  GDE_ERROR = -1,
  GDE_NO_EVENT,
  GDE_ONE_EVENT,
  GDE_MANY_EVENTS,
};
struct update_bpt_info_t
{
  ea_t ea;
  bytevec_t orgbytes;
  bpttype_t type;
  uchar size;
  uchar code;
};
typedef qvector<update_bpt_info_t> update_bpt_vec_t;
struct lowcnd_t
{
  ea_t ea;
  qstring cndbody;
  bpttype_t type;
  bytevec_t orgbytes;
  insn_t cmd;
  bool compiled;
};
typedef qvector<lowcnd_t> lowcnd_vec_t;
int __stdcall handle_debug_event(const debug_event_t *ev, int rqflags);
struct debugger_t
{
  int version;
  const char *name;
  int id;
  const char *processor;
  uint32 flags;
  bool is_remote(void) const { return (flags & 0x00000001) != 0; }
  bool must_have_hostname(void) const
    { return (flags & (0x00000001|0x00000002)) == 0x00000001; }
  bool can_continue_from_bpt(void) const
    { return (flags & 0x00000010) != 0; }
  bool may_disturb(void) const
    { return (flags & 0x00000040) == 0; }
  bool is_safe(void) const
    { return (flags & 0x00000080) != 0; }
  bool use_sregs(void) const
    { return (flags & 0x00000200) != 0; }
  size_t cache_block_size(void) const
    { return (flags & 0x00004000) != 0 ? 256 : 1024; }
  bool use_memregs(void) const
    { return (flags & 0x00008000) != 0; }
  bool may_take_exit_snapshot(void) const
    { return (flags & 0x00010000) != 0; }
  bool virtual_threads(void) const
    { return (flags & 0x00020000) != 0; }
  bool supports_lowcnds(void) const
    { return (flags & 0x00040000) != 0; }
  bool supports_debthread(void) const
    { return (flags & 0x00080000) != 0; }
  bool can_debug_standalone_dlls(void) const
    { return (flags & 0x00100000) != 0; }
  const char    **register_classes;
  int             register_classes_default;
  register_info_t *registers;
  int             registers_size;
  int             memory_page_size;
  const uchar     *bpt_bytes;
  uchar            bpt_size;
  uchar            filetype;
  ushort           reserved;
  bool (__stdcall *init_debugger)(const char *hostname, int portnum, const char *password);
  bool (__stdcall *term_debugger)(void);
  int (__stdcall *process_get_info)(int n, process_info_t *info);
  int (__stdcall *start_process)(const char *path,
                              const char *args,
                              const char *startdir,
                              int dbg_proc_flags,
                              const char *input_path,
                              uint32 input_file_crc32);
  int (__stdcall *attach_process)(pid_t pid, int event_id);
  int (__stdcall *detach_process)(void);
  void (__stdcall *rebase_if_required_to)(ea_t new_base);
  int (__stdcall *prepare_to_pause_process)(void);
  int (__stdcall *exit_process)(void);
  gdecode_t (__stdcall *get_debug_event)(debug_event_t *event, int timeout_ms);
  int (__stdcall *continue_after_event)(const debug_event_t *event);
  void (__stdcall *set_exception_info)(const exception_info_t *info, int qty);
  void (__stdcall *stopped_at_debug_event)(bool dlls_added);
  int (__stdcall *thread_suspend) (thid_t tid);
  int (__stdcall *thread_continue)(thid_t tid);
  int (__stdcall *thread_set_step)(thid_t tid);
  int (__stdcall *read_registers)(thid_t tid, int clsmask, regval_t *values);
  int (__stdcall *write_register)(thid_t tid, int regidx, const regval_t *value);
  int (__stdcall *thread_get_sreg_base)(thid_t tid, int sreg_value, ea_t *answer);
  int (__stdcall *get_memory_info)(meminfo_vec_t &areas);
  ssize_t (__stdcall *read_memory)(ea_t ea, void *buffer, size_t size);
  ssize_t (__stdcall *write_memory)(ea_t ea, const void *buffer, size_t size);
  int (__stdcall *is_ok_bpt)(bpttype_t type, ea_t ea, int len);
  int (__stdcall *update_bpts)(update_bpt_info_t *bpts, int nadd, int ndel);
  int (__stdcall *update_lowcnds)(const lowcnd_t *lowcnds, int nlowcnds);
  int  (__stdcall *open_file)(const char *file, uint32 *fsize, bool readonly);
  void (__stdcall *close_file)(int fn);
  ssize_t (__stdcall *read_file)(int fn, uint32 off, void *buf, size_t size);
  ea_t (__stdcall *map_address)(ea_t off, const regval_t *regs, int regnum);
  const char *(__stdcall *set_dbg_options)(
        const char *keyword,
        int value_type,
        const void *value);
  const void *(__stdcall *get_debmod_extensions)(void);
  bool (__stdcall *update_call_stack)(thid_t tid, call_stack_t *trace);
  ea_t (__stdcall *appcall)(
        ea_t func_ea,
        thid_t tid,
        const struct func_type_info_t *fti,
        int nargs,
        const struct regobjs_t *regargs,
        struct relobj_t *stkargs,
        struct regobjs_t *retregs,
        qstring *errbuf,
        debug_event_t *event,
        int options);
  int (__stdcall *cleanup_appcall)(thid_t tid);
  int (__stdcall *eval_lowcnd)(thid_t tid, ea_t ea);
  ssize_t (__stdcall *write_file)(int fn, uint32 off, const void *buf, size_t size);
  int (__stdcall *send_ioctl)(int fn, const void *buf, size_t size, void **poutbuf, ssize_t *poutsize);
};
typedef char COMPILE_TIME_ASSERT_887 [((sizeof(debugger_t) % 4) == 0) ? 1 : -1];
typedef thid_t thread_id_t;
typedef pid_t process_id_t;
struct idd_opinfo_old_t { ea_t addr; uval_t value;  bool modified; };
#pragma pack(pop)
extern "C" debugger_t __declspec(dllimport) *dbg;
enum dbg_notification_t
{
  dbg_null = 0,
  dbg_process_start,
  dbg_process_exit,
  dbg_process_attach,
  dbg_process_detach,
  dbg_thread_start,
  dbg_thread_exit,
  dbg_library_load,
  dbg_library_unload,
  dbg_information,
  dbg_exception,
  dbg_suspend_process,
  dbg_bpt,
  dbg_trace,
  dbg_request_error,
  dbg_step_into,
  dbg_step_over,
  dbg_run_to,
  dbg_step_until_ret,
  dbg_last,
};
bool __stdcall run_requests(void);
ui_notification_t __stdcall get_running_request(void);
 bool is_request_running(void) { return get_running_request() != ui_null; }
dbg_notification_t __stdcall get_running_notification(void);
void __stdcall clear_requests_queue(void);
int __stdcall get_process_state(void);
int __stdcall set_process_state(int newstate, thid_t *p_thid, int dbginv);
 int __stdcall invalidate_dbg_state(int dbginv)
{
  return set_process_state(0, 0, dbginv);
}
int __stdcall start_process(const char *path = 0,
                         const char *args = 0,
                         const char *sdir = 0);
int __stdcall request_start_process(const char *path = 0,
                                 const char *args = 0,
                                 const char *sdir = 0);
bool __stdcall suspend_process(void);
bool __stdcall request_suspend_process(void);
bool __stdcall continue_process(void);
bool __stdcall request_continue_process(void);
bool __stdcall exit_process(void);
bool __stdcall request_exit_process(void);
int __stdcall get_process_qty(void);
pid_t __stdcall get_process_info(int n, process_info_t *process_info);
 pid_t getn_process(int n) { return get_process_info(n, 0); }
int __stdcall attach_process(pid_t pid=pid_t(0xFFFFFFFF), int event_id=-1);
int __stdcall request_attach_process(pid_t pid, int event_id);
bool __stdcall detach_process(void);
bool __stdcall request_detach_process(void);
bool __stdcall is_debugger_busy(void);
int __stdcall get_thread_qty(void);
thid_t __stdcall getn_thread(int n);
thid_t __stdcall get_current_thread(void);
bool __stdcall select_thread(thid_t tid);
bool __stdcall request_select_thread(thid_t tid);
int __stdcall suspend_thread(thid_t tid);
int __stdcall request_suspend_thread(thid_t tid);
int __stdcall resume_thread(thid_t tid);
int __stdcall request_resume_thread(thid_t tid);
bool __stdcall get_first_module(module_info_t *modinfo);
bool __stdcall get_next_module(module_info_t *modinfo);
bool __stdcall step_into(void);
bool __stdcall request_step_into(void);
bool __stdcall step_over(void);
bool __stdcall request_step_over(void);
bool __stdcall run_to(ea_t ea);
bool __stdcall request_run_to(ea_t ea);
bool __stdcall step_until_ret(void);
bool __stdcall request_step_until_ret(void);
bool __stdcall get_reg_val(const char *regname, regval_t *regval);
 bool get_reg_val(const char *regname, uint64 *ival)
{
  regval_t regval;
  if ( !get_reg_val(regname, &regval) )
    return false;
  if ( regval.rvtype != (-1) )
    return false;
  if ( ival != 0 )
    *ival = regval.ival;
  return true;
}
bool __stdcall set_reg_val(const char *regname, const regval_t *regval);
bool __stdcall request_set_reg_val(const char *regname, const regval_t *regval);
 bool set_reg_val(const char *regname, uint64 ival)
{
  regval_t regval;
  regval.ival = ival;
  return set_reg_val(regname, &regval);
}
bool __stdcall is_reg_integer(const char *regname);
bool __stdcall is_reg_float(const char *regname);
bool __stdcall is_reg_custom(const char *regname);
int __stdcall set_bptloc_string(const char *s);
const char *__stdcall get_bptloc_string(int i);
enum bpt_loctype_t
{
  BPLT_ABS,
  BPLT_REL,
  BPLT_SYM,
  BPLT_SRC,
};
struct bpt_location_t
{
  ea_t info;
  int index;
  bpt_loctype_t loctype;
  bpt_loctype_t type(void) const { return loctype; }
  bool is_empty_path(void) const { return index == 0; }
  const char *path(void) const { return get_bptloc_string(index); }
  const char *symbol(void) const { return get_bptloc_string(index); }
  int lineno(void) const { return int(info); }
  uval_t offset(void) const { return (uval_t)info; }
  ea_t ea(void) const { return info; }
  bpt_location_t(void) : loctype(BPLT_ABS) {}
  void set_abs_bpt(ea_t a)
  {
    info = a;
    loctype = BPLT_ABS;
  }
  void set_src_bpt(const char *fn, int lineno)
  {
    index   = set_bptloc_string(fn);
    info    = lineno;
    loctype = BPLT_SRC;
  }
  void set_sym_bpt(const char *symbol, uval_t offset=0)
  {
    index   = set_bptloc_string(symbol);
    info    = offset;
    loctype = BPLT_SYM;
  }
  void set_rel_bpt(const char *mod, uval_t offset)
  {
    index   = set_bptloc_string(mod);
    info    = offset;
    loctype = BPLT_REL;
  }
  int compare(const bpt_location_t &r) const { return callui(ui_dbg_compare_bpt_locs, this, &r).i; }
  bool operator==(const bpt_location_t &r) const { return compare(r) == 0; }
  bool operator!=(const bpt_location_t &r) const { return compare(r) != 0; }
  bool operator< (const bpt_location_t &r) const { return compare(r) <  0; }
  bool operator> (const bpt_location_t &r) const { return compare(r) >  0; }
  bool operator<=(const bpt_location_t &r) const { return compare(r) <= 0; }
  bool operator>=(const bpt_location_t &r) const { return compare(r) >= 0; }
  size_t print(char *buf, size_t bufsize) const;
};
struct bpt_t
{
  qstring cndbody;
  bpt_location_t loc;
  ea_t ea;
  bpttype_t type;
  int pass_count;
  uint8 flags;
  uint8 props;
  uint16 size;
  int cndidx;
  bpt_t(void) : ea(ea_t(-1)), type(BPT_SOFT), pass_count(0), flags(0x01|0x08),
                props(0), size(0), cndidx(-1) {}
  bool is_hwbpt(void) const { return type != BPT_SOFT; }
  bool enabled(void) const { return (flags & 0x08) != 0; }
  bool is_low_level(void) const { return (flags & 0x10) != 0; }
  bool badbpt(void) const { return (props & 0x01) != 0; }
  bool listbpt(void) const { return (props & 0x02) != 0; }
  bool is_compiled(void) const { return (props & 0x20) != 0; }
  bool is_active(void) const { return (props & (0x10|0x08)) == 0x08; }
  bool is_partially_active(void) const { return (props & 0x10) != 0; }
  bool is_inactive(void) const { return (props & (0x10|0x08)) == 0; }
  void set_abs_bpt(ea_t a) { loc.set_abs_bpt(a); ea = a; }
  void set_src_bpt(const char *fn, int lineno) { loc.set_src_bpt(fn, lineno); ea = ea_t(-1); }
  void set_sym_bpt(const char *sym, uval_t o) { loc.set_sym_bpt(sym, o); ea = ea_t(-1); }
  void set_rel_bpt(const char *mod, uval_t o) { loc.set_rel_bpt(mod, o); ea = ea_t(-1); }
  bool is_absbpt(void) const { return loc.type() == BPLT_ABS; }
  bool is_relbpt(void) const { return loc.type() == BPLT_REL; }
  bool is_symbpt(void) const { return loc.type() == BPLT_SYM; }
  bool is_srcbpt(void) const { return loc.type() == BPLT_SRC; }
  void set_cond(const char *cnd);
  bool eval_cond(ea_t ea, bool *fire, const char *bpt_type);
};
int __stdcall get_bpt_qty(void);
bool __stdcall getn_bpt(int n, bpt_t *bpt);
bool __stdcall get_bpt(ea_t ea, bpt_t *bpt);
 bool exist_bpt(ea_t ea) { return get_bpt(ea, 0); }
bool __stdcall add_bpt(ea_t ea, asize_t size = 0, bpttype_t type = BPT_SOFT);
bool __stdcall request_add_bpt(ea_t ea, asize_t size = 0, bpttype_t type = BPT_SOFT);
bool __stdcall del_bpt(ea_t ea);
bool __stdcall request_del_bpt(ea_t ea);
bool __stdcall update_bpt(const bpt_t *bpt);
bool __stdcall enable_bpt(ea_t ea, bool enable = true);
 bool disable_bpt(ea_t ea) { return enable_bpt(ea, false); }
bool __stdcall request_enable_bpt(ea_t ea, bool enable = true);
 bool request_disable_bpt(ea_t ea) { return request_enable_bpt(ea, false); }
int __stdcall check_bpt(ea_t ea);
bool __stdcall set_trace_size(int size);
void __stdcall clear_trace(void);
void __stdcall request_clear_trace(void);
bool __stdcall is_step_trace_enabled(void);
bool __stdcall enable_step_trace(int enable = true);
 bool disable_step_trace(void) { return enable_step_trace(false); }
bool __stdcall request_enable_step_trace(int enable = true);
 bool request_disable_step_trace(void) { return request_enable_step_trace(false); }
int __stdcall get_step_trace_options(void);
void __stdcall set_step_trace_options(int options);
void __stdcall request_set_step_trace_options(int options);
bool __stdcall is_insn_trace_enabled(void);
bool __stdcall enable_insn_trace(int enable = true);
 bool disable_insn_trace(void) { return enable_insn_trace(false); }
bool __stdcall request_enable_insn_trace(int enable = true);
 bool request_disable_insn_trace(void) { return request_enable_insn_trace(false); }
int __stdcall get_insn_trace_options(void);
void __stdcall set_insn_trace_options(int options);
void __stdcall request_set_insn_trace_options(int options);
bool __stdcall is_func_trace_enabled(void);
bool __stdcall enable_func_trace(int enable = true);
 bool disable_func_trace(void) { return enable_func_trace(false); }
bool __stdcall request_enable_func_trace(int enable = true);
 bool request_disable_func_trace(void) { return request_enable_func_trace(false); }
int __stdcall get_func_trace_options(void);
void __stdcall set_func_trace_options(int options);
void __stdcall request_set_func_trace_options(int options);
enum tev_type_t
{
  tev_none = 0,
  tev_insn,
  tev_call,
  tev_ret,
  tev_bpt,
};
struct tev_info_t
{
  tev_type_t  type;
  thid_t tid;
  ea_t        ea;
};
int __stdcall get_tev_qty(void);
bool __stdcall get_tev_info(int n, tev_info_t *tev_info);
bool __stdcall get_insn_tev_reg_val(int n, const char *regname, regval_t *regval);
 bool get_insn_tev_reg_val(int n, const char *regname, uint64 *ival)
{
  regval_t regval;
  if ( !get_insn_tev_reg_val(n, regname, &regval) )
    return false;
  if ( regval.rvtype != (-1) )
    return false;
  if ( ival != 0 )
    *ival = regval.ival;
  return true;
}
bool __stdcall get_insn_tev_reg_result(int n, const char *regname, regval_t *regval);
 bool get_insn_tev_reg_result(int n, const char *regname, uint64 *ival)
{
  regval_t regval;
  if ( !get_insn_tev_reg_result(n, regname, &regval) )
    return false;
  if ( regval.rvtype != (-1) )
    return false;
  if ( ival != 0 )
    *ival = regval.ival;
  return true;
}
ea_t __stdcall get_call_tev_callee(int n);
ea_t __stdcall get_ret_tev_return(int n);
ea_t __stdcall get_bpt_tev_ea(int n);
enum dbg_event_code_t
{
  DEC_NOTASK  = -2,
  DEC_ERROR   = -1,
  DEC_TIMEOUT = 0,
};
dbg_event_code_t __stdcall wait_for_next_event(int wfne, int timeout_in_secs);
const debug_event_t *__stdcall get_debug_event(void);
uint __stdcall set_debugger_options(uint options);
void __stdcall set_remote_debugger(const char *host, const char *pass, int port=-1);
void __stdcall get_process_options(qstring *path, qstring *args, qstring *sdir,
                                qstring *host, qstring *pass, int *port);
void __stdcall set_process_options(const char *path, const char *args, const char *sdir,
                                const char *host, const char *pass, int port);
excvec_t *__stdcall retrieve_exceptions(void);
bool __stdcall store_exceptions(void);
const char *__stdcall define_exception(uint code, const char *name, const char *desc, int flags);
 bool have_set_options(const debugger_t *dbg)
{
  return dbg != 0 && dbg->version >= 10 && dbg->set_dbg_options != 0;
}
 const char *__stdcall set_dbg_options(
        const char *keyword,
        int value_type,
        const void *value)
{
  const char *code = ((char*)1);
  if ( have_set_options(dbg) )
    code = dbg->set_dbg_options(keyword, value_type, value);
  return code;
}
 bool __stdcall run_requests(void)                                                         { return callui(ui_dbg_run_requests).cnd; }
 ui_notification_t __stdcall get_running_request(void)                                     { return (ui_notification_t)callui(ui_dbg_get_running_request).i; }
 dbg_notification_t __stdcall get_running_notification(void)                               { return (dbg_notification_t)callui(ui_dbg_get_running_notification).i; }
 void __stdcall clear_requests_queue(void)                                                 { callui(ui_dbg_clear_requests_queue); }
 int __stdcall get_process_state(void)                                                     { return callui(ui_dbg_get_process_state).i; }
 int __stdcall start_process(const char *path, const char *args, const char *sdir)         { return callui(ui_dbg_start_process, path, args, sdir).i; }
 int __stdcall request_start_process(const char *path, const char *args, const char *sdir) { return callui(ui_dbg_request_start_process, path, args, sdir).i; }
 bool __stdcall suspend_process(void)                                                      { return callui(ui_dbg_suspend_process).cnd; }
 bool __stdcall request_suspend_process(void)                                              { return callui(ui_dbg_request_suspend_process).cnd; }
 bool __stdcall continue_process(void)                                                     { return callui(ui_dbg_continue_process).cnd; }
 bool __stdcall request_continue_process(void)                                             { return callui(ui_dbg_request_continue_process).cnd; }
 bool __stdcall exit_process(void)                                                         { return callui(ui_dbg_exit_process).cnd; }
 bool __stdcall request_exit_process(void)                                                 { return callui(ui_dbg_request_exit_process).cnd; }
 int __stdcall get_process_qty(void)                                                       { return callui(ui_dbg_get_process_qty).i; }
 pid_t __stdcall get_process_info(int n, process_info_t *process_info)                     { return (pid_t)callui(ui_dbg_get_process_info, n, process_info).i; }
 int __stdcall attach_process(pid_t pid, int event_id)                                     { return callui(ui_dbg_attach_process, pid, event_id).i; }
 int __stdcall request_attach_process(pid_t pid, int event_id)                             { return callui(ui_dbg_request_attach_process, pid, event_id).i; }
 bool __stdcall detach_process(void)                                                       { return callui(ui_dbg_detach_process).cnd; }
 bool __stdcall request_detach_process(void)                                               { return callui(ui_dbg_request_detach_process).cnd; }
 int __stdcall get_thread_qty(void)                                                        { return callui(ui_dbg_get_thread_qty).i; }
 thid_t __stdcall getn_thread(int n)                                                       { return (thid_t)callui(ui_dbg_getn_thread, n).i; }
 bool __stdcall select_thread(thid_t tid)                                                  { return callui(ui_dbg_select_thread, tid).cnd; }
 bool __stdcall request_select_thread(thid_t tid)                                          { return callui(ui_dbg_request_select_thread, tid).cnd; }
 bool __stdcall step_into(void)                                                            { return callui(ui_dbg_step_into).cnd; }
 bool __stdcall request_step_into(void)                                                    { return callui(ui_dbg_request_step_into).cnd; }
 bool __stdcall step_over(void)                                                            { return callui(ui_dbg_step_over).cnd; }
 bool __stdcall request_step_over(void)                                                    { return callui(ui_dbg_request_step_over).cnd; }
 bool __stdcall run_to(ea_t ea)                                                            { return callui(ui_dbg_run_to, ea).cnd; }
 bool __stdcall request_run_to(ea_t ea)                                                    { return callui(ui_dbg_request_run_to, ea).cnd; }
 bool __stdcall step_until_ret(void)                                                       { return callui(ui_dbg_step_until_ret).cnd; }
 bool __stdcall request_step_until_ret(void)                                               { return callui(ui_dbg_request_step_until_ret).cnd; }
 bool __stdcall get_reg_val(const char *regname, regval_t *regval)                         { return callui(ui_dbg_get_reg_val, regname, regval).cnd; }
 bool __stdcall set_reg_val(const char *regname, const regval_t *regval)                   { return callui(ui_dbg_set_reg_val, regname, regval).cnd; }
 bool __stdcall request_set_reg_val(const char *regname, const regval_t *regval)           { return callui(ui_dbg_request_set_reg_val, regname, regval).cnd; }
 int __stdcall get_bpt_qty(void)                                                           { return callui(ui_dbg_get_bpt_qty).i; }
 bool __stdcall getn_bpt(int n, bpt_t *bpt)                                                { return callui(ui_dbg_getn_bpt, n, bpt).cnd; }
 bool __stdcall get_bpt(ea_t ea, bpt_t *bpt)                                               { return callui(ui_dbg_get_bpt, ea, bpt).cnd; }
 bool __stdcall add_bpt(ea_t ea, asize_t size, bpttype_t type)                             { return callui(ui_dbg_add_bpt, ea, size, type).cnd; }
 bool __stdcall request_add_bpt(ea_t ea, asize_t size, bpttype_t type)                     { return callui(ui_dbg_request_add_bpt, ea, size, type).cnd; }
 bool __stdcall del_bpt(ea_t ea)                                                           { return callui(ui_dbg_del_bpt, ea).cnd; }
 bool __stdcall request_del_bpt(ea_t ea)                                                   { return callui(ui_dbg_request_del_bpt, ea).cnd; }
 bool __stdcall update_bpt(const bpt_t *bpt)                                               { return callui(ui_dbg_update_bpt, bpt).cnd; }
 bool __stdcall enable_bpt(ea_t ea, bool enable)                                           { return callui(ui_dbg_enable_bpt, ea, enable).cnd; }
 bool __stdcall request_enable_bpt(ea_t ea, bool enable)                                   { return callui(ui_dbg_request_enable_bpt, ea, enable).cnd; }
 bool __stdcall set_trace_size(int size)                                                   { return callui(ui_dbg_set_trace_size, size).cnd; }
 void __stdcall clear_trace(void)                                                          { callui(ui_dbg_clear_trace); }
 void __stdcall request_clear_trace(void)                                                  { callui(ui_dbg_request_clear_trace); }
 bool __stdcall is_step_trace_enabled(void)                                                { return callui(ui_dbg_is_step_trace_enabled).cnd; }
 bool __stdcall enable_step_trace(int enable)                                              { return callui(ui_dbg_enable_step_trace, enable).cnd; }
 bool __stdcall request_enable_step_trace(int enable)                                      { return callui(ui_dbg_request_enable_step_trace, enable).cnd; }
 int __stdcall get_step_trace_options(void)                                                { return callui(ui_dbg_get_step_trace_options).i; }
 void __stdcall set_step_trace_options(int options)                                        { callui(ui_dbg_set_step_trace_options, options); }
 void __stdcall request_set_step_trace_options(int options)                                { callui(ui_dbg_request_set_step_trace_options, options); }
 bool __stdcall is_insn_trace_enabled(void)                                                { return callui(ui_dbg_is_insn_trace_enabled).cnd; }
 bool __stdcall enable_insn_trace(int enable)                                              { return callui(ui_dbg_enable_insn_trace, enable).cnd; }
 bool __stdcall request_enable_insn_trace(int enable)                                      { return callui(ui_dbg_request_enable_insn_trace, enable).cnd; }
 int __stdcall get_insn_trace_options(void)                                                { return callui(ui_dbg_get_insn_trace_options).i; }
 void __stdcall set_insn_trace_options(int options)                                        { callui(ui_dbg_set_insn_trace_options, options); }
 void __stdcall request_set_insn_trace_options(int options)                                { callui(ui_dbg_request_set_insn_trace_options, options); }
 bool __stdcall is_func_trace_enabled(void)                                                { return callui(ui_dbg_is_func_trace_enabled).cnd; }
 bool __stdcall enable_func_trace(int enable)                                              { return callui(ui_dbg_enable_func_trace, enable).cnd; }
 bool __stdcall request_enable_func_trace(int enable)                                      { return callui(ui_dbg_request_enable_func_trace, enable).cnd; }
 int __stdcall get_func_trace_options(void)                                                { return callui(ui_dbg_get_func_trace_options).i; }
 void __stdcall set_func_trace_options(int options)                                        { callui(ui_dbg_set_func_trace_options, options); }
 void __stdcall request_set_func_trace_options(int options)                                { callui(ui_dbg_request_set_func_trace_options, options); }
 int __stdcall get_tev_qty(void)                                                           { return callui(ui_dbg_get_tev_qty).i; }
 bool __stdcall get_tev_info(int n, tev_info_t *tev_info)                                  { return callui(ui_dbg_get_tev_info, n, tev_info).cnd; }
 bool __stdcall get_insn_tev_reg_val(int n, const char *regname, regval_t *regval)         { return callui(ui_dbg_get_insn_tev_reg_val, n, regname, regval).cnd; }
 bool __stdcall get_insn_tev_reg_result(int n, const char *regname, regval_t *regval)      { return callui(ui_dbg_get_insn_tev_reg_result, n, regname, regval).cnd; }
 ea_t __stdcall get_call_tev_callee(int n)                                                 { ea_t ea; callui(ui_dbg_get_call_tev_callee, n, &ea); return ea; }
 ea_t __stdcall get_ret_tev_return(int n)                                                  { ea_t ea; callui(ui_dbg_get_ret_tev_return, n, &ea); return ea; }
 ea_t __stdcall get_bpt_tev_ea(int n)                                                      { ea_t ea; callui(ui_dbg_get_bpt_tev_ea, n, &ea); return ea; }
 bool __stdcall is_reg_integer(const char *regname)                                        { return callui(ui_dbg_get_reg_value_type, regname).i-2 == (-1); }
 bool __stdcall is_reg_float(const char *regname)                                          { return callui(ui_dbg_get_reg_value_type, regname).i-2 == (-2); }
 bool __stdcall is_reg_custom(const char *regname)                                         { return callui(ui_dbg_get_reg_value_type, regname).i >= 2; }
 bool __stdcall get_first_module(module_info_t *modinfo)                                   { return callui(ui_dbg_get_first_module, modinfo).cnd; }
 bool __stdcall get_next_module(module_info_t *modinfo)                                    { return callui(ui_dbg_get_next_module, modinfo).cnd; }
 void __stdcall bring_debugger_to_front(void)                                              { callui(ui_dbg_bring_to_front); }
 thid_t __stdcall get_current_thread(void)                                                 { return callui(ui_dbg_get_current_thread).i; }
 dbg_event_code_t __stdcall wait_for_next_event(int wfne, int timeout)                     { return dbg_event_code_t(callui(ui_dbg_wait_for_next_event, wfne, timeout).i); }
 const debug_event_t *__stdcall get_debug_event(void)                                      { return (const debug_event_t *)callui(ui_dbg_get_debug_event).vptr; }
 uint __stdcall set_debugger_options(uint options)                                         { return callui(ui_dbg_set_debugger_options, options).i; }
 void __stdcall set_remote_debugger(const char *host, const char *pass, int port)          { callui(ui_dbg_set_remote_debugger, host, pass, port); }
 bool __stdcall load_debugger(const char *dbgname, bool use_remote)                        { return callui(ui_dbg_load_debugger, dbgname, use_remote).cnd; }
 excvec_t *__stdcall retrieve_exceptions(void)                                             { return (excvec_t *)callui(ui_dbg_retrieve_exceptions).vptr; }
 bool __stdcall store_exceptions(void)                                                     { return callui(ui_dbg_store_exceptions).cnd; }
 const char *__stdcall define_exception(uint code, const char *name, const char *desc, int flags) { return callui(ui_dbg_define_exception, code, name, desc, flags).cptr; }
 int __stdcall suspend_thread(thid_t tid)                                                  { return callui(ui_dbg_suspend_thread, tid).i; }
 int __stdcall request_suspend_thread(thid_t tid)                                          { return callui(ui_dbg_request_suspend_thread, tid).i; }
 int __stdcall resume_thread(thid_t tid)                                                   { return callui(ui_dbg_resume_thread, tid).i; }
 int __stdcall request_resume_thread(thid_t tid)                                           { return callui(ui_dbg_request_resume_thread, tid).i; }
 void __stdcall get_process_options(qstring *path, qstring *args, qstring *sdir, qstring *host, qstring *pass, int *port) { callui(ui_dbg_get_process_options, path, args, sdir, host, pass, port); }
 void __stdcall set_process_options(const char *path, const char *args, const char *sdir, const char *host, const char *pass, int port) { callui(ui_dbg_set_process_options, path, args, sdir, host, pass, port); }
 int __stdcall check_bpt(ea_t ea)                                                          { return callui(ui_dbg_check_bpt, ea).i; }
 int __stdcall set_process_state(int newstate, thid_t *p_thid, int dbginv)                 { return callui(ui_dbg_set_process_state, newstate, p_thid, dbginv).i; }
 void __stdcall get_manual_regions(meminfo_vec_t *areas)                                   { callui(ui_dbg_get_manual_regions, areas); }
 void __stdcall set_manual_regions(const meminfo_vec_t *areas)                             { callui(ui_dbg_set_manual_regions, areas); }
 void __stdcall edit_manual_regions()                                                      { callui(ui_dbg_edit_manual_regions); }
 void __stdcall enable_manual_regions(bool enable)                                         { callui(ui_dbg_enable_manual_regions, enable); }
 bool __stdcall is_debugger_busy(void)                                                     { return callui(ui_dbg_is_busy).cnd; }
 int  __stdcall hide_all_bpts(void)                                                        { return callui(ui_dbg_hide_all_bpts).i; }
 int  __stdcall handle_debug_event(const debug_event_t *ev, int rqflags)                   { return callui(ui_dbg_handle_debug_event, ev, rqflags).i; }
 bool __stdcall add_virt_module(const module_info_t *mod)                                  { return callui(ui_dbg_add_vmod, mod).cnd; }
 bool __stdcall del_virt_module(const ea_t base)                                           { return callui(ui_dbg_del_vmod, base).cnd; }
 int  __stdcall set_bptloc_string(const char *s)                                           { return callui(ui_dbg_set_bptloc_string, s).i; }
 const char *__stdcall get_bptloc_string(int i)                                            { return callui(ui_dbg_get_bptloc_string, i).cptr; }
#pragma pack(pop)
typedef int32 __stdcall demangler_t(
        char *answer,
        uint answer_length,
        const char *str,
        uint32 disable_mask);
extern "C" demangler_t demangle;
typedef int mangled_name_type_t;
const mangled_name_type_t MANGLED_CODE = 0;
const mangled_name_type_t MANGLED_DATA = 1;
const mangled_name_type_t MANGLED_UNKNOWN = 2;
extern "C" mangled_name_type_t __stdcall get_mangled_name_type(const char *name);
enum dem_mode_t
{
  dem_mode16 = 0,
  dem_mode32 = 1,
  dem_mode64 = 2
};
void init_demangler(dem_mode_t mode);
bool is_mangled_string_name(const char *name);
#pragma pack(push, 1)
extern "C" size_t __stdcall get_entry_qty(void);
extern "C" bool __stdcall add_entry(uval_t ord, ea_t ea,const char *name, bool makecode);
extern "C" uval_t __stdcall get_entry_ordinal(size_t idx);
extern "C" ea_t __stdcall get_entry(uval_t ord);
extern "C" ssize_t __stdcall get_entry_name(uval_t ord, char *buf, size_t bufsize);
extern "C" bool __stdcall rename_entry(uval_t ord, const char *name);
void init_entries(void);
void term_entries(void);
void move_entries(ea_t from, ea_t to, asize_t size);
bool set_entry_name(uval_t ord, const char *name);
#pragma pack(pop)
#pragma pack(push, 1)
extern "C" netnode __declspec(dllimport) enums;
typedef tid_t enum_t;
typedef uval_t bmask_t;
typedef uval_t const_t;
const uchar MAX_ENUM_SERIAL = 255;
 void     init_enums(void) { enums.create("$ enums"); }
 void     save_enums(void) {}
 void     term_enums(void) {}
bool set_enum_flag(enum_t id, uint32 bit, bool set);
void sync_from_enum(enum_t id, const char *name);
void del_all_enum_members(enum_t id);
 size_t   get_enum_qty(void)      { return size_t(enums.altval(uval_t(-1))); }
 enum_t   getn_enum(size_t n)     { return ((uval_t)(int(n))==uval_t(-1)) ? nodeidx_t(-1) : enums.altval(n)-1; }
 uval_t   get_enum_idx(enum_t id) { return enums.altval(id,'Y')-1; }
extern "C" enum_t __stdcall get_enum(const char *name);
 bool     is_bf(enum_t id)                        { return (netnode(id).altval(uval_t(-5)) & 0x00000001) != 0; }
 bool     is_enum_hidden(enum_t id)               { return (netnode(id).altval(uval_t(-5)) & 0x00000002) != 0; }
 bool     set_enum_hidden(enum_t id, bool hidden) { return set_enum_flag(id, 0x00000002, hidden); }
 bool     is_enum_fromtil(enum_t id)               { return (netnode(id).altval(uval_t(-5)) & 0x00000004) != 0; }
 bool     set_enum_fromtil(enum_t id, bool fromtil) { return set_enum_flag(id, 0x00000004, fromtil); }
 ssize_t  get_enum_name(enum_t id, char *buf, size_t bufsize) { return id > 0xFF000000L ? netnode(id).name(buf, bufsize) : -1;  }
 size_t   get_enum_width(enum_t id)                { return id > 0xFF000000L ? size_t((netnode(id).altval(uval_t(-5)) & 0x00000038) >> 3) : 0; }
extern "C" bool __stdcall set_enum_width(enum_t id, int width);
 ssize_t  get_enum_cmt(enum_t id, bool repeatable, char *buf, size_t bufsize) { return id > 0xFF000000L ? netnode(id).supstr(repeatable != 0, buf, bufsize) : -1; }
 size_t   get_enum_size(enum_t id)                { return id > 0xFF000000L ? size_t(netnode(id).altval(uval_t(-1))) : 0; }
 flags_t  get_enum_flag(enum_t id)                { return id > 0xFF000000L ? flags_t(netnode(id).altval(uval_t(-3))) : 0; }
extern "C" const_t __stdcall get_enum_member_by_name(const char *name);
 uval_t   get_enum_member_value(const_t id)             { return id > 0xFF000000L ? netnode(id).altval(uval_t(-3)) : 0; }
 enum_t   get_enum_member_enum(const_t id)              { return id > 0xFF000000L ? netnode(id).altval(uval_t(-2))-1 : nodeidx_t(-1); }
 bmask_t  get_enum_member_bmask(const_t id)             { return id > 0xFF000000L ? netnode(id).altval(uval_t(-6))-1 : nodeidx_t(-1); }
extern "C" const_t __stdcall get_enum_member(enum_t id, uval_t value, uchar serial, bmask_t mask);
 bmask_t  get_first_bmask(enum_t id)              { return netnode(id).alt1st('m'); }
 bmask_t  get_last_bmask(enum_t id)               { return netnode(id).altlast('m'); }
 bmask_t  get_next_bmask(enum_t id,bmask_t bmask) { return netnode(id).altnxt(bmask,'m'); }
 bmask_t  get_prev_bmask(enum_t id,bmask_t bmask) { return netnode(id).altprev(bmask,'m'); }
extern "C" uval_t __stdcall get_first_enum_member(enum_t id, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_last_enum_member(enum_t id, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_next_enum_member(enum_t id, uval_t value, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_prev_enum_member(enum_t id, uval_t value, bmask_t bmask=(bmask_t(-1)));
 ssize_t  get_enum_member_name(const_t id, char *buf, size_t bufsize) { return netnode(id).name(buf, bufsize);  }
 ssize_t  get_enum_member_cmt(const_t id, bool repeatable, char *buf, size_t bufsize) { return netnode(id).supstr(repeatable != 0, buf, bufsize); }
extern "C" const_t __stdcall get_first_serial_enum_member(enum_t id, uval_t value, uchar *serial, bmask_t bmask);
extern "C" const_t __stdcall get_last_serial_enum_member(enum_t id, uval_t value, uchar *serial, bmask_t bmask);
extern "C" const_t __stdcall get_next_serial_enum_member(const_t first_cid, uchar *serial);
extern "C" const_t __stdcall get_prev_serial_enum_member(const_t first_cid, uchar *serial);
struct enum_member_visitor_t
{
  virtual int __stdcall visit_enum_member(const_t cid, uval_t value) = 0;
};
extern "C" int __stdcall for_all_enum_members(enum_t id, enum_member_visitor_t &cv);
 uchar get_enum_member_serial(const_t cid) { return uchar(netnode(cid).altval(uval_t(-7))); }
 int32 get_enum_type_ordinal(enum_t id) { return int32(netnode(id).altval(uval_t(-8))-1); }
 void set_enum_type_ordinal(enum_t id, int32 ord) { netnode(id).altset(uval_t(-8), ord+1); }
extern "C" enum_t __stdcall add_enum(size_t idx, const char *name, flags_t flag);
extern "C" void   __stdcall del_enum(enum_t id);
extern "C" bool   __stdcall set_enum_idx(enum_t id, size_t idx);
extern "C" bool __stdcall set_enum_bf(enum_t id, bool bf);
extern "C" bool __stdcall set_enum_name(enum_t id,const char *name);
extern "C" bool __stdcall set_enum_cmt(enum_t id,const char *cmt,bool repeatable);
 bool set_enum_flag(enum_t id, flags_t flag) { return netnode(id).altset(uval_t(-3),flag) != 0; }
extern "C" int __stdcall add_enum_member(enum_t id,const char *name, uval_t value, bmask_t bmask=(bmask_t(-1)));
extern "C" bool __stdcall del_enum_member(enum_t id, uval_t value, uchar serial, bmask_t bmask);
extern "C" bool __stdcall set_enum_member_name(const_t id, const char *name);
 bool set_enum_member_cmt(const_t id, const char *cmt, bool repeatable) { return set_enum_cmt(id, cmt, repeatable); }
 uval_t   get_selected_enum(size_t n) { return enums.altval(n,'Z'); }
 void     add_selected_enum(size_t *idx, enum_t id) { enums.altset((*idx)++,id,'Z'); }
 void     unmark_selected_enums(void){ enums.altdel_all('Z'); }
bool is_good_bmask(enum_t id, bmask_t bmask);
 bool is_one_bit_mask(bmask_t mask)
{
  return (mask & (mask-1)) == 0;
}
 netnode get_bmask_node(enum_t id, bmask_t bmask)
{
  if ( !is_bf(id) ) return nodeidx_t(-1);
  return netnode(id).altval(bmask, 'm')-1;
}
 bool set_enum_flag(enum_t id, uint32 bit, bool set)
{
  if ( id == nodeidx_t(-1) ) return false;
  netnode n(id);
  uint32 f = uint32(n.altval(uval_t(-5)));
  setflag(f, bit, set);
  return n.altset(uval_t(-5), f) != 0;
}
 bool set_bmask_name(enum_t id,bmask_t bmask, const char *name)
  { return get_bmask_node(id,bmask).rename(name); }
 ssize_t get_bmask_name(enum_t id,bmask_t bmask, char *buf, size_t bufsize)
  { return get_bmask_node(id,bmask).name(buf, bufsize);       }
 bool set_bmask_cmt(enum_t id,bmask_t bmask, const char *cmt, bool repeatable)
  { return set_enum_cmt(get_bmask_node(id,bmask), cmt, repeatable); }
 ssize_t get_bmask_cmt(enum_t id,bmask_t bmask, bool repeatable, char *buf, size_t bufsize)
  { return get_bmask_node(id,bmask).supstr(repeatable != 0, buf, bufsize); }
enum_t get_bmask_enum(const char *mask_name, bmask_t *value);
 uval_t enum_encode(enum_t id, uchar serial)
{
  return id + (uval_t(serial) << (sizeof(uval_t)*8-8));
}
 enum_t enum_decode(uval_t code, uchar *serial)
{
  uval_t delta = (code - 0xFF000000L) & (uval_t(0xFF)<<(sizeof(uval_t)*8-8));
  if ( serial != 0 )
    *serial = uchar(delta >> (sizeof(uval_t)*8-8));
  return code - delta;
}
extern "C" int __stdcall add_const(enum_t id,const char *name, uval_t value, bmask_t bmask=(bmask_t(-1)));
extern "C" bool __stdcall del_const(enum_t id, uval_t value, uchar serial, bmask_t bmask);
extern "C" bool __stdcall set_const_name(const_t id, const char *name);
 bool set_const_cmt(const_t id, const char *cmt, bool repeatable) { return set_enum_cmt(id, cmt, repeatable); }
extern "C" const_t __stdcall get_const_by_name(const char *name);
 uval_t   get_const_value(const_t id)             { return id > 0xFF000000L ? netnode(id).altval(uval_t(-3)) : 0; }
 enum_t   get_const_enum(const_t id)              { return id > 0xFF000000L ? netnode(id).altval(uval_t(-2))-1 : nodeidx_t(-1); }
 bmask_t  get_const_bmask(const_t id)             { return id > 0xFF000000L ? netnode(id).altval(uval_t(-6))-1 : nodeidx_t(-1); }
extern "C" const_t __stdcall get_const(enum_t id, uval_t value, uchar serial, bmask_t mask);
extern "C" uval_t __stdcall get_first_const(enum_t id, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_last_const(enum_t id, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_next_const(enum_t id, uval_t value, bmask_t bmask=(bmask_t(-1)));
extern "C" uval_t __stdcall get_prev_const(enum_t id, uval_t value, bmask_t bmask=(bmask_t(-1)));
 ssize_t get_const_name(const_t id, char *buf, size_t bufsize) { return netnode(id).name(buf, bufsize);  }
 ssize_t get_const_cmt(const_t id, bool repeatable, char *buf, size_t bufsize) { return netnode(id).supstr(repeatable != 0, buf, bufsize); }
extern "C" const_t __stdcall get_first_serial_const(enum_t id, uval_t value, uchar *serial, bmask_t bmask);
extern "C" const_t __stdcall get_last_serial_const(enum_t id, uval_t value, uchar *serial, bmask_t bmask);
extern "C" const_t __stdcall get_next_serial_const(const_t first_cid, uchar *serial);
extern "C" const_t __stdcall get_prev_serial_const(const_t first_cid, uchar *serial);
struct const_visitor_t
{
  virtual int __stdcall visit_const(const_t cid, uval_t value) = 0;
};
extern "C" int __stdcall for_all_consts(enum_t id, const_visitor_t &cv);
 uchar get_const_serial(const_t cid) { return uchar(netnode(cid).altval(uval_t(-7))); }
#pragma pack(pop)
#pragma pack(push, 1)
extern "C"   void __stdcall vqperror(const char *format, va_list va);
extern "C"  char *__stdcall qstrerror(int _qerrno, char *buf, size_t bufsize);
extern "C"  char *__stdcall winerr(int code);
extern "C"  int __stdcall qerrcode(int new_code=-1);
extern "C" const char *__stdcall qerrstr(int code=-1);
   void qperror(const char *format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vqperror(format, va);
  ( va = (va_list)0 );
}
  void set_errno(int code)
{
  (*_errno()) = code;
  set_qerrno(1);
}
extern "C"  void __stdcall set_error_data(int n, size_t data);
extern "C"  void __stdcall set_error_string(int n, const char *str);
extern "C"  size_t __stdcall get_error_data(int n);
extern "C"  const char *__stdcall get_error_string(int n);
#pragma pack(pop)
#pragma pack(push, 1)
struct exehdr
{
    uint16 exe_ident;
    uint16 PartPag;
    uint16 PageCnt;
    uint16 ReloCnt;
    uint16 HdrSize;
    uint16 MinMem;
    uint16 MaxMem;
    uint16 ReloSS;
    uint16 ExeSP;
    uint16 ChkSum;
    uint16 ExeIP;
    uint16 ReloCS;
    uint16 TablOff;
    uint16 Overlay;
    int32 CalcEXE_Length(void)
    {
      int32 len = PageCnt * 512L - HdrSize * 16;
      if ( PartPag != 0 )
        len -= 512 - PartPag;
      return len;
    }
    void CalcEXE_Pages(int32 len)
    {
      PartPag = uint16(len % 512);
      PageCnt = uint16(len / 512);
      if ( PartPag != 0 )
        PageCnt++;
    }
};
struct exehdr_full: exehdr
{
    uint16 res[4];
    uint16 oemid;
    uint16 oeminfo;
    uint16 res2[10];
    uint32 lfanew;
};
#pragma pack(pop)
#pragma pack(push, 1)
class idc_value_t;
class idc_class_t;
class idc_object_t;
extern "C"  error_t __stdcall VarLong(idc_value_t *v);
extern "C"  error_t __stdcall VarInt64(idc_value_t *v);
extern "C"  error_t __stdcall VarNum(idc_value_t *v);
extern "C"  error_t __stdcall VarString2(idc_value_t *v);
extern "C"  error_t __stdcall VarFloat(idc_value_t *v);
extern "C"  error_t __stdcall VarObject(idc_value_t *v, const idc_class_t *icls=0);
extern "C"  error_t __stdcall VarCopy(idc_value_t *dst, const idc_value_t *src);
extern "C"  void __stdcall VarFree(idc_value_t *v);
extern "C"  void __stdcall VarSwap(idc_value_t *v1, idc_value_t *v2);
extern "C"  error_t __stdcall VarGetClassName(const idc_value_t *obj, qstring *name);
extern "C"  error_t __stdcall VarGetAttr(
        const idc_value_t *obj,
        const char *attr,
        idc_value_t *res,
        bool may_use_getattr=false);
extern "C"  error_t __stdcall VarSetAttr(
        idc_value_t *obj,
        const char *attr,
        const idc_value_t *value,
        bool may_use_setattr=false);
extern "C"  error_t __stdcall VarDelAttr(
        idc_value_t *obj,
        const char *attr);
extern "C"  const char *__stdcall VarFirstAttr(const idc_value_t *obj);
extern "C"  const char *__stdcall VarLastAttr(const idc_value_t *obj);
extern "C"  const char *__stdcall VarNextAttr(const idc_value_t *obj, const char *attr);
extern "C"  const char *__stdcall VarPrevAttr(const idc_value_t *obj, const char *attr);
extern "C"  error_t __stdcall VarAssign(idc_value_t *dst, const idc_value_t *src);
extern "C"  error_t __stdcall VarMove(idc_value_t *dst, idc_value_t *src);
extern "C" void __stdcall VarPrint(
        qstring *out,
        const idc_value_t *v,
        const char *name=0,
        int indent=0);
extern "C"  error_t __stdcall VarGetSlice(
        const idc_value_t *v,
        uval_t i1,
        uval_t i2,
        idc_value_t *res,
        int flags=0);
extern "C"  error_t __stdcall VarSetSlice(
        idc_value_t *v,
        uval_t i1,
        uval_t i2,
        const idc_value_t *in,
        int flags=0);
extern "C"  idc_class_t *__stdcall add_idc_class(
        const char *name,
        const idc_class_t *super=0);
extern "C"  idc_class_t *__stdcall find_idc_class(const char *name);
extern "C"  bool __stdcall set_idc_method(idc_class_t *icls, const char *fullfuncname);
extern "C"  const char *__stdcall set_idc_getattr(idc_class_t *icls, const char *fullfuncname);
extern "C"  const char *__stdcall set_idc_setattr(idc_class_t *icls, const char *fullfuncname);
extern "C"  const char *__stdcall set_idc_dtor(idc_class_t *icls, const char *fullfuncname);
extern "C"  idc_value_t *__stdcall VarDeref(idc_value_t *v, int vref_flags);
extern "C"  bool __stdcall VarRef(idc_value_t *ref, const idc_value_t *v);
extern "C"  idc_value_t *__stdcall add_idc_gvar(const char *name);
extern "C"  idc_value_t *__stdcall find_idc_gvar(const char *name);
class idc_value_t
{
public:
  char vtype;
  union
  {
    char *str;
    sval_t num;
    ushort e[6];
    idc_object_t *obj;
    int funcidx;
    void *pvoid;
    int64 i64;
    uchar reserve[sizeof(qstring)];
  };
  idc_value_t(int n=0) : vtype(2),num(n) {}
  idc_value_t(const idc_value_t &r) : vtype(2) { VarAssign(this, &r); }
  idc_value_t(const char *_str) : vtype(7) { new(&qstr()) qstring(_str); }
  idc_value_t(const qstring &_str) : vtype(7) { new(&qstr()) qstring(_str); }
  ~idc_value_t(void) { clear(); }
  void clear(void) { VarFree(this); }
  idc_value_t &operator = (const idc_value_t &r)
  {
    VarAssign(this, &r);
    return *this;
  }
        qstring &qstr(void)       { return *(qstring *)&num; }
  const qstring &qstr(void) const { return *(qstring *)&num; }
  const char *c_str(void) const   { return qstr().c_str(); }
  const uchar *u_str(void) const  { return (const uchar *)c_str(); }
  void swap(idc_value_t &v) { VarSwap(this, &v); }
  bool is_zero(void) const { return vtype == 2 && num == 0; }
  bool is_convertible(void) const { return (vtype >= 1 && vtype <= 3) || vtype == 7 || vtype == 9; }
  void _create_empty_string(void) { vtype = 7; new (&qstr()) qstring; }
  void _set_string(const char *str, size_t len=0)
  {
    vtype = 7;
    new (&qstr()) qstring(str, (len || str == 0) ? len : strlen(str));
  }
  void _set_long(sval_t v) { vtype = 2; num = v; }
  void create_empty_string(void) { clear(); _create_empty_string(); }
  void set_string(const char *str, size_t len=0) { clear(); _set_string(str, len); }
  void set_long(sval_t v) { clear(); _set_long(v); }
  void set_pvoid(void *p) { clear(); vtype = 8; pvoid = p; }
  void set_int64(int64 v) { clear(); vtype = 9; i64 = v; }
};
struct idc_global_t
{
  qstring name;
  idc_value_t value;
  idc_global_t(void) {}
  idc_global_t(const char *n) : name(n) {}
};
typedef qvector<idc_global_t> idc_vars_t;
typedef error_t __stdcall idc_func_t(idc_value_t *argv,idc_value_t *r);
struct extfun_t
{
  const char *name;
  idc_func_t *fp;
  const char *args;
  int flags;
};
struct funcset_t
{
  int qnty;
  extfun_t *f;
  error_t (__stdcall *startup)(void);
  error_t (__stdcall *shutdown)(void);
  void (__stdcall *init_idc)(void);
  void (__stdcall *term_idc)(void);
  bool (__stdcall *is_database_open)(void);
  size_t (__stdcall *ea2str)(ea_t ea, char *buf, size_t bufsize);
  bool (__stdcall *undeclared_variable_ok)(const char *name);
  int get_unkvar;
  int set_unkvar;
  int exec_resolved_func;
  int calc_sizeof;
  int get_field_ea;
};
template <> struct ida_movable_type<idc_value_t> { typedef ida_true_type is_movable_type; };
template <> struct ida_movable_type<idc_global_t> { typedef ida_true_type is_movable_type; };
extern "C" funcset_t __declspec(dllimport) IDCFuncs;
extern "C"  bool __stdcall set_idc_func_ex(
        const char *name,
        idc_func_t *fp,
        const char *args,
        int extfunc_flags);
struct extlang_t
{
  size_t size;
  uint32 flags;
  const char *name;
  bool (__stdcall *compile)(
        const char *name,
        ea_t current_ea,
        const char *expr,
        char *errbuf,
        size_t errbufsize);
  bool (__stdcall *run)(
        const char *name,
        int nargs,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize);
  bool (__stdcall *calcexpr)(
        ea_t current_ea,
        const char *expr,
        idc_value_t *rv,
        char *errbuf,
        size_t errbufsize);
  bool (__stdcall *compile_file)(
        const char *file,
        char *errbuf,
        size_t errbufsize);
  const char *fileext;
  bool (__stdcall *create_object)(
        const char *name,
        int nargs,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize);
  bool (__stdcall *get_attr)(
        const idc_value_t *obj,
        const char *attr,
        idc_value_t *result);
  bool (__stdcall *set_attr)(
        idc_value_t *obj,
        const char *attr,
        idc_value_t *value);
  bool (__stdcall *call_method)(
    const idc_value_t *obj,
    const char *name,
    int nargs,
    const idc_value_t args[],
    idc_value_t *result,
    char *errbuf,
    size_t errbufsize);
};
typedef qvector<const extlang_t *> extlangs_t;
extern "C" __declspec(dllimport) const extlang_t *extlang;
extern "C" bool __stdcall install_extlang(const extlang_t *el);
extern "C" bool __stdcall remove_extlang(const extlang_t *el);
extern "C" bool __stdcall select_extlang(const extlang_t *el);
 const char *get_extlang_fileext(void)
{
  const extlang_t *el = extlang;
  if ( el != 0 && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->fileext)) )
    return el->fileext;
  return 0;
}
extern "C" const extlangs_t *__stdcall get_extlangs();
extern "C" const extlang_t *__stdcall find_extlang_by_ext(const char *ext);
extern "C"  const char *__stdcall get_idcpath(void);
extern "C"  bool __stdcall set_header_path(const char *path, bool add);
extern "C"  char *__stdcall get_idc_filename(
        char *buf,
        size_t bufsize,
        const char *file);
extern "C"  bool __stdcall dosysfile(bool complain_if_no_file, const char *file);
extern "C" bool __stdcall calcexpr_long(
        ea_t where,
        const char *line,
        sval_t *res,
        char *errbuf,
        size_t errbufsize);
 bool __stdcall calcexpr_long(
        ea_t where,
        const char *line,
        uval_t *res,
        char *errbuf,
        size_t errbufsize)
{
  return calcexpr_long(where, line, (sval_t *)res, errbuf, errbufsize);
}
extern "C" bool __stdcall calcexpr(
        ea_t where,
        const char *line,
        idc_value_t *rv,
        char *errbuf,
        size_t errbufsize);
extern "C" bool __stdcall calc_idc_expr(
        ea_t where,
        const char *buf,
        idc_value_t *rv,
        char *errbuf,
        size_t errbufsize);
extern "C" bool __stdcall execute(const char *line);
extern "C"  bool __stdcall CompileEx(
        const char *file,
        int cpl_flags,
        char *errbuf,
        size_t errbufsize);
 bool __stdcall Compile(
        const char *file,
        char *errbuf,
        size_t errbufsize)
{
  return CompileEx(file, 0x0001|0x0002, errbuf, errbufsize);
}
 bool __stdcall extlang_compile_file_exists(const extlang_t *el = 0)
{
  if ( el == 0 )
    el = extlang;
  return el != 0
      && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->compile_file))
      && el->compile_file != 0;
}
 bool compile_script_file(
        const char *file,
        char *errbuf,
        size_t errbufsize)
{
  bool (__stdcall *func)(const char *, char *, size_t);
  func = extlang_compile_file_exists() ? extlang->compile_file : Compile;
  return func(file, errbuf, errbufsize);
}
extern "C" bool __stdcall extlang_compile_file(
        const char *file,
        char *errbuf,
        size_t errbufsize,
        const extlang_t **el);
extern "C"  bool __stdcall CompileLineEx(
        const char *line,
        char *errbuf,
        size_t bufsize,
        uval_t (__stdcall*_getname)(const char *name)=0,
        bool only_safe_funcs=false);
extern "C" bool __stdcall compile_script_func(
        const char *name,
        ea_t current_ea,
        const char *expr,
        char *errbuf,
        size_t errbufsize);
extern "C" bool __stdcall Run(
        const char *fname,
        int argsnum,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize);
 bool run_script_func(
        const char *fname,
        int argsnum,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize)
{
  bool (__stdcall *func)(const char *, int, const idc_value_t[], idc_value_t *,
                                                               char *, size_t);
  func = extlang != 0 ? extlang->run : Run;
  return func(fname, argsnum, args, result, errbuf, errbufsize);
}
extern "C" bool __stdcall create_idc_object(
        const char *name,
        int argsnum,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize);
 bool __stdcall extlang_get_attr_exists(void)
{
  const extlang_t *el = extlang;
  return el != 0
      && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->get_attr))
      && el->get_attr != 0;
}
 bool get_script_attr(
        const idc_value_t *obj,
        const char *attr,
        idc_value_t *result)
{
  return extlang_get_attr_exists() ? extlang->get_attr(obj, attr, result) : VarGetAttr(obj, attr, result) == 0;
}
 bool __stdcall extlang_set_attr_exists(void)
{
  const extlang_t *el = extlang;
  return el != 0
      && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->set_attr))
      && el->set_attr != 0;
}
 bool set_script_attr(
        idc_value_t *obj,
        const char *attr,
        idc_value_t *value)
{
  return extlang_set_attr_exists() ? extlang->set_attr(obj, attr, value) : VarSetAttr(obj, attr, value) == 0;
}
 bool __stdcall extlang_create_object_exists(void)
{
  const extlang_t *el = extlang;
  return el != 0
      && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->create_object))
      && el->create_object != 0;
}
 bool create_script_object(
        const char *name,
        int nargs,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize)
{
  bool (__stdcall *func)(const char *, int,
                        const idc_value_t [], idc_value_t *, char *, size_t);
  func = extlang_create_object_exists() ? extlang->create_object : create_idc_object;
  return func(name, nargs, args, result, errbuf, errbufsize);
}
extern "C" bool __stdcall call_idc_method(
        const idc_value_t *obj,
        const char *name,
        int nargs,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize);
 bool __stdcall extlang_call_method_exists(void)
{
  const extlang_t *el = extlang;
  return el != 0
    && el->size > (size_t)&reinterpret_cast<const volatile char&>((((extlang_t *)0)->call_method))
    && el->call_method != 0;
}
 bool __stdcall call_script_method(
        const idc_value_t *obj,
        const char *name,
        int nargs,
        const idc_value_t args[],
        idc_value_t *result,
        char *errbuf,
        size_t errbufsize)
{
  bool (__stdcall *func)(const idc_value_t *, const char *, int,
                        const idc_value_t [], idc_value_t *, char *, size_t);
  func = extlang_call_method_exists() ? extlang->call_method : call_idc_method;
  return func(obj, name, nargs, args, result, errbuf, errbufsize);
}
extern "C"  bool __stdcall ExecuteLine(
                const char *line,
                const char *func,
                uval_t (__stdcall*getname)(const char *name),
                int argsnum,
                const idc_value_t args[],
                idc_value_t *result,
                char *errbuf,
                size_t errbufsize);
extern "C"  bool __stdcall ExecuteFile(
                const char *file,
                const char *func,
                int argsnum,
                const idc_value_t args[],
                idc_value_t *result,
                char *errbuf,
                size_t errbufsize);
extern "C"  bool __stdcall set_idc_func_body(
                const char *name,
                int narg,
                const uchar *body,
                size_t len);
extern "C"  uchar *__stdcall get_idc_func_body(
                const char *name,
                int *narg,
                size_t *len);
extern "C" void __stdcall setup_lowcnd_regfuncs(idc_func_t *getreg, idc_func_t *setreg);
extern int idc_stacksize;
extern int idc_calldepth;
int expr_printf(idc_value_t *argv, idc_value_t *r);
int expr_sprintf(idc_value_t *argv, idc_value_t *r);
int expr_printfer(int (*outer)(void *,char), void *ud, idc_value_t *argv, idc_value_t *r);
void __stdcall init_idc(void);
void __stdcall term_idc(void);
void __stdcall create_default_idc_classes(void);
extfun_t *find_builtin_idc_func(const char *name);
void insn_to_idc(class insn_t &ins, idc_value_t &r);
extern qmutex_t idc_mutex;
extern class lexer_t *idc_lx;
extern idc_vars_t idc_vars;
extern ea_t idc_resolver_ea;
uval_t __stdcall idc_resolve_label(const char *name);
extern extlangs_t extlangs;
typedef char COMPILE_TIME_ASSERT_1149 [(sizeof(qstring) <= 12) ? 1 : -1];
typedef idc_value_t value_t;
extern "C" error_t __stdcall VarString(idc_value_t *v);
extern "C" bool __stdcall set_idc_func(const char *name, idc_func_t *fp, const char *args);
extern "C" bool __stdcall CompileLine(const char *line, char *errbuf, size_t errbufsize, uval_t (__stdcall*_getname)(const char *name)=0);
#pragma pack(pop)
#pragma pack(push, 1)
struct fixup_data_t
{
  uchar type;
  ushort sel;
  ea_t off;
  adiff_t displacement;
   bool is_custom(void) const { return (type & 0xF) == 0xF; }
};
extern "C" netnode __declspec(dllimport) fixup_node;
extern "C" void __stdcall set_fixup(ea_t source, const fixup_data_t *fp);
extern "C" void __stdcall set_fixup_ex(ea_t source, fixup_data_t *fd, ea_t offset_base);
extern "C" void __stdcall del_fixup(ea_t source);
extern "C" bool __stdcall get_fixup(ea_t source, fixup_data_t *fd);
extern "C" ea_t __stdcall get_first_fixup_ea(void);
extern "C" ea_t __stdcall get_next_fixup_ea(ea_t ea);
extern "C" ea_t __stdcall get_prev_fixup_ea(ea_t ea);
bool apply_fixup(ea_t item_ea, ea_t fixup_ea, int n, bool is_macro);
extern "C" ea_t __stdcall get_fixup_base(ea_t source, const fixup_data_t *fd);
 ea_t get_fixup_extdef_ea(ea_t source, const fixup_data_t *fd)
{
  return (fd != 0 && (fd->type & 0x20) != 0)
        ? get_fixup_base(source, fd) + fd->off
        : ea_t(-1);
}
 sel_t get_fixup_segdef_sel(const fixup_data_t *fd)
{
  return (fd != 0 && (fd->type & 0x20) == 0)
        ? fd->sel
        : sel_t(-1);
}
 ea_t get_fixup_extdef_ea(ea_t ea)
{
  fixup_data_t fd;
  if ( get_fixup(ea, &fd) )
    return get_fixup_extdef_ea(ea, &fd);
  return ea_t(-1);
}
 sel_t get_fixup_segdef_sel(ea_t ea)
{
  fixup_data_t fd;
  if ( get_fixup(ea, &fd) )
    return get_fixup_segdef_sel(&fd);
  return sel_t(-1);
}
extern "C" char *__stdcall get_fixup_desc(ea_t source,
                                       fixup_data_t *fdp,
                                       char *buf,
                                       size_t bufsize);
extern "C" int __stdcall contains_fixups(ea_t ea, asize_t size);
void convert_fixups(void);
void move_fixups(ea_t from, ea_t to, asize_t size);
extern "C" void __stdcall gen_fix_fixups(ea_t from, ea_t to, asize_t size);
#pragma pack(pop)
#pragma pack(push, 1)
class struc_t;
class member_t;
class op_t;
struct stkpnt_t
{
  ea_t ea;
  sval_t spd;
  bool operator < (const stkpnt_t &r) const { return ea < r.ea; }
};
extern "C" bool __stdcall add_frame(func_t *pfn,
                                 asize_t frsize,
                                 ushort frregs,
                                 asize_t argsize);
extern "C" bool __stdcall del_frame(func_t *pfn);
extern "C" bool __stdcall set_frame_size(func_t *pfn,
                                      asize_t frsize,
                                      ushort frregs,
                                      asize_t argsize);
extern "C" asize_t __stdcall get_frame_size(func_t *pfn);
extern "C" int __stdcall get_frame_retsize(func_t *pfn);
extern "C" struc_t *__stdcall get_frame(const func_t *pfn);
 struc_t *get_frame(ea_t ea) { return get_frame(get_func(ea)); }
extern "C" bool __stdcall update_fpd(func_t *pfn, asize_t fpd);
extern "C" bool __stdcall set_purged(ea_t ea, int nbytes, bool override_old_value);
extern "C" ea_t __stdcall get_func_by_frame(tid_t frame_id);
extern "C" member_t *__stdcall get_stkvar(const op_t &x, sval_t v, sval_t *actval);
extern "C" bool __stdcall add_stkvar3(const op_t &x, sval_t v, int flags);
extern "C" bool __stdcall add_stkvar2(func_t *pfn,
                                   const char *name,
                                   sval_t off,
                                   flags_t flags,
                                   const opinfo_t *ti,
                                   asize_t nbytes);
extern "C" char *__stdcall build_stkvar_name(char *buf, size_t bufsize, func_t *pfn, sval_t v);
int add_frame_spec_member(struc_t *sptr, const char *name, ea_t offset, asize_t nbytes);
void del_stkvars(ea_t ea1, ea_t ea2);
ea_t calc_frame_offset(func_t *pfn, const op_t *x, sval_t v);
extern "C" ea_t __stdcall calc_stkvar_struc_offset(func_t *pfn, ea_t ea, int n);
extern "C" int __stdcall delete_unreferenced_stkvars(func_t *pfn);
extern "C" int __stdcall delete_wrong_stkvar_ops(func_t *pfn);
struct regvar_t : public area_t
{
  char *canon;
  char *user;
  char *cmt;
};
extern "C" int __stdcall add_regvar(func_t *pfn, ea_t ea1, ea_t ea2,
                        const char *canon,
                        const char *user,
                        const char *cmt);
extern "C" regvar_t *__stdcall find_regvar(func_t *pfn, ea_t ea1, ea_t ea2, const char *canon, const char *user);
 regvar_t *find_regvar(func_t *pfn, ea_t ea, const char *canon)
{
  return find_regvar(pfn, ea, ea+1, canon, 0);
}
extern "C" int __stdcall rename_regvar(func_t *pfn, regvar_t *v, const char *user);
extern "C" int __stdcall set_regvar_cmt(func_t *pfn, regvar_t *v, const char *cmt);
extern "C" int __stdcall del_regvar(func_t *pfn, ea_t ea1, ea_t ea2, const char *canon);
void read_regvars(func_t *pfn);
bool write_regvars(func_t *pfn);
void del_regvars(ea_t ea);
void free_regvar(regvar_t *v);
bool gen_regvar_defs(func_t *pfn, ea_t ea);
struct llabel_t
{
  ea_t ea;
  char *name;
};
bool set_llabel(func_t *pfn, ea_t ea, const char *name);
ea_t get_llabel_ea(func_t *pfn, const char *name);
const char *get_llabel(func_t *pfn, ea_t ea);
void read_llabels(func_t *pfn);
bool write_llabels(func_t *pfn);
void del_llabels(ea_t ea);
void free_llabel(llabel_t *l);
extern "C" bool __stdcall add_auto_stkpnt2(func_t *pfn, ea_t ea, sval_t delta);
extern "C" bool __stdcall add_user_stkpnt(ea_t ea, sval_t delta);
extern "C" bool __stdcall del_stkpnt(func_t *pfn, ea_t ea);
extern "C" sval_t __stdcall get_spd(func_t *pfn, ea_t ea);
extern "C" sval_t __stdcall get_sp_delta(func_t *pfn, ea_t ea);
extern "C" ea_t __stdcall get_min_spd_ea(func_t *pfn);
extern "C" bool __stdcall recalc_spd(ea_t cur_ea);
extern "C" bool __stdcall add_auto_stkpnt(ea_t ea, sval_t delta);
extern "C" bool __stdcall add_stkvar(const op_t &x, sval_t v);
stkpnt_t * read_stkpnts(func_t *pfn);
bool write_stkpnts(func_t *pfn);
int del_stkpnts(func_t *pfn, ea_t ea1, ea_t ea2);
bool rename_frame(tid_t frame_id, ea_t ea);
#pragma pack(pop)
#pragma pack(push, 4)
class node_iterator;
class qflow_chart_t;
class gdl_graph_t;
enum fc_block_type_t
{
  fcb_normal,
  fcb_indjump,
  fcb_ret,
  fcb_cndret,
  fcb_noret,
  fcb_enoret,
  fcb_extern,
  fcb_error,
};
extern "C" node_iterator &__stdcall node_iterator_goup(node_iterator *); extern "C" void __stdcall create_qflow_chart(qflow_chart_t &); extern "C" bool __stdcall append_to_flowchart(qflow_chart_t &, ea_t, ea_t); extern "C" fc_block_type_t __stdcall fc_calc_block_type(const qflow_chart_t &, size_t); extern "C" bool __stdcall create_multirange_qflow_chart(qflow_chart_t &, const areavec_t &);
class intseq_t : public qvector<int>
{
public:
  int  __stdcall index(int value) const
  {
    for ( size_t i=0; i < size(); i++ )
      if ( (*this)[i] == value )
        return i;
    return -1;
  }
  bool __stdcall contains(int value) const { return index(value) != -1; }
  void __stdcall add(int value) { push_back(value); }
  bool __stdcall add_unique(int value)
  {
    if ( contains(value) )
      return false;
    add(value);
    return true;
  }
  void __stdcall add_unique(const intseq_t &s);
  int  __stdcall get(void) { int v = back(); pop_back(); return v; }
  size_t __stdcall print(char *buf, size_t bufsize) const;
  const char *__stdcall dstr(void) const;
  void __stdcall add_block(int nb);
  void __stdcall remove_block(int from, int to);
};
class intset_t : public std::set<int>
{
public:
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  size_t __stdcall print(char *buf, size_t bufsize) const;
  const char *__stdcall dstr(void) const;
  bool has(int value) const
  {
    const_iterator p = find(value);
    const_iterator q = end();
    return p != q;
  }
};
typedef qvector<intseq_t> array_of_intseq_t;
class intmap_t : public std::map<int, int>
{
public:
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  size_t __stdcall print(char *buf, size_t bufsize) const;
  const char *__stdcall dstr(void) const;
};
typedef std::vector<intmap_t> array_of_intmap_t;
class node_set_t : public intset_t
{
public:
  __stdcall node_set_t(void) {}
  __stdcall node_set_t(int node) { insert(node); }
  __stdcall node_set_t(const gdl_graph_t *g);
  bool __stdcall add(int node) { return insert(node).second; }
  void __stdcall sub(int node) { erase(node); }
  void __stdcall sub(const node_set_t &r);
  void __stdcall add(const node_set_t &r);
  void __stdcall intersect(const node_set_t &r);
  void __stdcall extract(intseq_t &out) const;
  int  __stdcall first(void) const { return empty() ? -1 : *begin(); }
};
typedef std::vector<node_set_t> array_of_node_set_t;
class node_iterator
{
  friend node_iterator &__stdcall node_iterator_goup(node_iterator *); friend void __stdcall create_qflow_chart(qflow_chart_t &); friend bool __stdcall append_to_flowchart(qflow_chart_t &, ea_t, ea_t); friend fc_block_type_t __stdcall fc_calc_block_type(const qflow_chart_t &, size_t); friend bool __stdcall create_multirange_qflow_chart(qflow_chart_t &, const areavec_t &);
  friend class gdl_graph_t;
  const gdl_graph_t *g;
  int i;
  node_iterator &_goup(void);
  node_iterator &goup(void) { return node_iterator_goup(this); }
public:
  node_iterator(const gdl_graph_t *_g, int n) : g(_g), i(n) {}
  node_iterator &operator++(void) { i++; return goup(); }
  bool operator==(const node_iterator &n) const { return i == n.i && g == n.g; }
  bool operator!=(const node_iterator &n) const { return !(*this == n); }
  int operator*(void) const { return i; }
};
class gdl_graph_t
{
  bool __stdcall path(node_set_t &visited, int m, int n) const;
public:
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  virtual __stdcall ~gdl_graph_t(void) {}
  virtual char *__stdcall get_node_label(int , char *buf, int ) const { buf[0] = '\0'; return buf; }
  virtual void __stdcall print_graph_attributes(FILE * ) const {}
  virtual bool __stdcall print_node(FILE * , int ) const { return false; }
  virtual bool __stdcall print_edge(FILE * , int , int ) const { return false; }
  virtual void __stdcall print_node_attributes(FILE * , int ) const {}
  virtual int  __stdcall size(void) const = 0;
  virtual int  __stdcall node_qty(void) const { return size(); }
  virtual bool __stdcall exists(int ) const { return true; }
  virtual int  __stdcall entry(void) const { return 0; }
  virtual int  __stdcall exit(void) const { return size()-1; }
  virtual int  __stdcall nsucc(int node) const = 0;
  virtual int  __stdcall npred(int node) const = 0;
  virtual int  __stdcall succ(int node, int i) const = 0;
  virtual int  __stdcall pred(int node, int i) const = 0;
  virtual bool __stdcall empty(void) const { return node_qty() == 0; }
  virtual bgcolor_t __stdcall get_node_color(int ) const { return bgcolor_t(-1); }
  virtual bgcolor_t __stdcall get_edge_color(int , int ) const { return bgcolor_t(-1); }
          void __stdcall gen_gdl(FILE *fp) const;
          void __stdcall gen_gdl(const char *file) const;
          size_t __stdcall nedge(int node, bool ispred) const { return ispred ? npred(node) : nsucc(node); }
          int  __stdcall edge(int node, int i, bool ispred) const { return ispred ? pred(node, i) : succ(node, i); }
          int  __stdcall front(void) { return *begin(); }
  node_iterator __stdcall begin(void) const { return node_iterator(this, 0).goup(); }
  node_iterator __stdcall end(void)   const { return node_iterator(this, size()); }
  bool __stdcall path_exists(int m, int n) const { node_set_t v; return path(v, m, n); }
  void __stdcall gen_dot(FILE *fp) const;
  void __stdcall gen_dot(const char *file) const;
};
extern "C" void __stdcall gen_gdl(const gdl_graph_t *g, const char *fname);
extern "C" int __stdcall display_gdl(const char *fname);
extern "C" bool __stdcall gen_flow_graph(
        const char *filename,
        const char *title,
        func_t *pfn,
        ea_t ea1, ea_t ea2,
        int gflags);
extern int default_graph_format;
extern "C" bool __stdcall gen_simple_call_chart(
        const char *filename,
        const char *wait,
        const char *title,
        int gflags);
extern "C" bool __stdcall gen_complex_call_chart(
        const char *filename,
        const char *wait,
        const char *title,
        ea_t ea1,
        ea_t ea2,
        int flags,
        int32 recursion_depth=-1);
extern "C" void __stdcall setup_graph_subsystem(const char *grapher, bgcolor_t (__stdcall *get_graph_color)(int color));
class cancellable_graph_t : public gdl_graph_t
{
public:
  mutable bool cancelled;
  char padding[3];
  cancellable_graph_t(void) : cancelled(false) {}
  virtual __stdcall ~cancellable_graph_t(void) {}
  bool __stdcall check_cancel(void) const;
};
struct qbasic_block_t : public area_t
{
  intseq_t succ;
  intseq_t pred;
};
 bool is_noret_block(fc_block_type_t btype)
{
  return btype == fcb_noret || btype == fcb_enoret;
}
 bool is_ret_block(fc_block_type_t btype)
{
  return btype == fcb_ret || btype == fcb_cndret;
}
class qflow_chart_t : public cancellable_graph_t
{
public:
  typedef qvector<qbasic_block_t> blocks_t;
  friend node_iterator &__stdcall node_iterator_goup(node_iterator *); friend void __stdcall create_qflow_chart(qflow_chart_t &); friend bool __stdcall append_to_flowchart(qflow_chart_t &, ea_t, ea_t); friend fc_block_type_t __stdcall fc_calc_block_type(const qflow_chart_t &, size_t); friend bool __stdcall create_multirange_qflow_chart(qflow_chart_t &, const areavec_t &);
  qstring title;
  area_t bounds;
  func_t *pfn;
  int flags;
  blocks_t blocks;
  int nproper;
  __stdcall qflow_chart_t(void) : flags(0) {}
  __stdcall qflow_chart_t(const char *_title, func_t *_pfn, ea_t _ea1, ea_t _ea2, int _flags)
    : title(_title), bounds(_ea1, _ea2), pfn(_pfn), flags(_flags)
  {
    refresh();
  }
  virtual __stdcall ~qflow_chart_t(void) {}
  void __stdcall create(const char *_title, func_t *_pfn, ea_t _ea1, ea_t _ea2, int _flags)
  {
    title  = _title;
    pfn    = _pfn;
    bounds = area_t(_ea1, _ea2);
    flags  = _flags;
    refresh();
  }
  void __stdcall create(const char *_title, const areavec_t &ranges, int _flags)
  {
    title  = _title;
    flags  = _flags;
    create_multirange_qflow_chart(*this, ranges);
  }
  void __stdcall append_to_flowchart(ea_t ea1, ea_t ea2) { ::append_to_flowchart(*this, ea1, ea2); }
  void __stdcall refresh(void) { create_qflow_chart(*this); }
  fc_block_type_t calc_block_type(size_t blknum) const
    { return fc_calc_block_type(*this, blknum); }
  bool is_ret_block(size_t blknum) const { return ::is_ret_block(calc_block_type(blknum)); }
  bool is_noret_block(size_t blknum) const { return ::is_noret_block(calc_block_type(blknum)); }
  void __stdcall print_node_attributes(FILE * , int ) const {}
  int  __stdcall nsucc(int node) const { return int(blocks[node].succ.size()); }
  int  __stdcall npred(int node) const { return int(blocks[node].pred.size()); }
  int  __stdcall succ(int node, int i) const { return blocks[node].succ[i]; }
  int  __stdcall pred(int node, int i) const { return blocks[node].pred[i]; }
  bool __stdcall print_names(void) const { return (flags & 0x0001) != 0; }
  char *__stdcall get_node_label(int , char* , int ) const { return 0; }
  int  __stdcall size(void) const { return int(blocks.size()); }
};
class graph_intseq_t : public std::vector<int>
{
public:
  void add(int x) { push_back(x); }
  void add_unique(int x)
  {
    if ( std::find(begin(), end(), x) == end() )
      add(x);
  }
};
struct basic_block_t : public area_t
{
  graph_intseq_t succ;
};
typedef std::map<ea_t, int> bn_t;
class flow_chart_t;
extern "C" void __stdcall create_flow_chart(flow_chart_t &);
class flow_chart_t : public cancellable_graph_t
{
  friend void __stdcall create_flow_chart(flow_chart_t &);
public:
  typedef std::vector<basic_block_t> blocks_t;
  qstring title;
  area_t bounds;
  func_t *pfn;
  int flags;
  blocks_t blocks;
  bn_t bn;
  int nproper;
  __stdcall flow_chart_t(void) : flags(0) {}
  __stdcall flow_chart_t(const char *_title, func_t *_pfn, ea_t _ea1, ea_t _ea2, bool _print_names)
    : title(_title), bounds(_ea1, _ea2), pfn(_pfn), flags(_print_names ? 0x0001 : 0)
  {
    refresh();
  }
  virtual __stdcall ~flow_chart_t(void) {}
  void __stdcall create(const char *_title, func_t *_pfn, ea_t _ea1, ea_t _ea2, bool _print_names)
  {
    title = _title;
    pfn   = _pfn;
    bounds = area_t(_ea1, _ea2);
    if ( _print_names )
      flags |= 0x0001;
    refresh();
  }
  void __stdcall refresh(void) { create_flow_chart(*this); }
  void __stdcall print_graph_attributes(FILE * ) const;
  bool __stdcall print_node(FILE * , int ) const;
  bool __stdcall print_edge(FILE * , int , int ) const;
  void __stdcall print_node_attributes(FILE * , int ) const {}
  int  __stdcall nsucc(int node) const { return (int)blocks[node].succ.size(); }
  int  __stdcall npred(int ) const { return 0; }
  int  __stdcall succ(int node, int i) const { return blocks[node].succ[i]; }
  int  __stdcall pred(int , int ) const { return -1; }
  bool __stdcall print_names(void) const { return (flags & 0x0001) != 0; }
  char *__stdcall get_node_label(int , char* , int ) const { return 0; }
  int  __stdcall size(void) const { return int(blocks.size()); }
};
extern "C" bool __stdcall display_flow_graph(const char *title,
                                          func_t *pfn,
                                          ea_t ea1, ea_t ea2,
                                          bool print_names);
extern "C" bool __stdcall display_simple_call_chart(const char *wait,
                                                 const char *title,
                                                 bool ignore_libfuncs);
extern "C" bool __stdcall display_complex_call_chart(const char *wait,
                                                  const char *title,
                                                  ea_t ea1,
                                                  ea_t ea2,
                                                  int flags,
                                                  int32 recursion_depth=-1);
#pragma pack(pop)
#pragma pack(push, 4)
#pragma pack(push, 1)
class linput_t;
struct extlang_t;
struct loader_t
{
  uint32 version;
  uint32 flags;
  int (__stdcall* accept_file)(linput_t *li,
                            char fileformatname[64],
                            int n);
  void (__stdcall* load_file)(linput_t *li,
                           ushort neflags,
                           const char *fileformatname);
  int (__stdcall* save_file)(FILE *fp, const char *fileformatname);
  int (__stdcall* move_segm)(ea_t from,
                          ea_t to,
                          asize_t size,
                          const char *fileformatname);
  bool (__stdcall* init_loader_options)(linput_t *li);
};
extern "C"  __declspec(noreturn) void __stdcall vloader_failure(const char *format, va_list va);
 __declspec(noreturn)  void loader_failure(const char *format=0, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vloader_failure(format, va);
}
struct load_info_t
{
  load_info_t *next;
  char dllname[260];
  char ftypename[64];
  filetype_t ftype;
  int pri;
};
extern "C" load_info_t *__stdcall build_loaders_list(linput_t *li);
extern "C" void __stdcall free_loaders_list(load_info_t *list);
extern "C" char *__stdcall get_loader_name_from_dll(char *dllname);
extern "C" ssize_t __stdcall get_loader_name(char *buf, size_t bufsize);
extern "C" bool __stdcall init_loader_options(linput_t *li, const load_info_t *loader);
extern "C" bool __stdcall load_binary_file(
                             const char *filename,
                             linput_t *li,
                             ushort _neflags,
                             int32 fileoff,
                             ea_t basepara,
                             ea_t binoff,
                             uint32 nbytes);
extern "C" bool __stdcall load_nonbinary_file(
                                const char *filename,
                                linput_t *li,
                                const char *sysdlldir,
                                ushort _neflags,
                                load_info_t *loader);
typedef int ofile_type_t;
const ofile_type_t
  OFILE_MAP  = 0,
  OFILE_EXE  = 1,
  OFILE_IDC  = 2,
  OFILE_LST  = 3,
  OFILE_ASM  = 4,
  OFILE_DIF  = 5;
typedef int __stdcall html_header_cb_t(FILE *fp);
typedef int __stdcall html_footer_cb_t(FILE *fp);
typedef int __stdcall html_line_cb_t(FILE *fp,
                                  const char *line,
                                  bgcolor_t prefix_color,
                                  bgcolor_t bg_color);
extern "C" int __stdcall gen_file(ofile_type_t otype, FILE *fp, ea_t ea1, ea_t ea2, int flags);
extern "C" int __stdcall file2base(linput_t *li,
                                int32 pos,
                                ea_t ea1,
                                ea_t ea2,
                                int patchable);
extern "C" int __stdcall mem2base(const void *memptr,ea_t ea1,ea_t ea2,int32 fpos);
extern "C" int __stdcall base2file(FILE *fp,int32 pos,ea_t ea1,ea_t ea2);
extern "C" int __stdcall load_loader_module(linput_t *li,
                                         const char *lname,
                                         const char *fname,
                                         bool is_remote);
extern "C" void __stdcall create_filename_cmt(void);
extern "C" filetype_t __stdcall get_basic_file_type(linput_t *li);
extern "C" size_t __stdcall get_file_type_name(char *buf, size_t bufsize);
struct impinfo_t
{
  const char *dllname;
  void (__stdcall*func)(uval_t num, const char *name, uval_t node);
  uval_t node;
};
typedef int (__stdcall*importer_t)(linput_t *li,impinfo_t *ii);
extern "C" void __stdcall import_module(const char *module,
                   const char *windir,
                   uval_t modnode,
                   importer_t importer,
                   const char *ostype);
extern "C" int __stdcall load_ids_module(char *fname);
class plugin_t
{
public:
  int version;
  int flags;
  int (__stdcall* init)(void);
  void (__stdcall* term)(void);
  void (__stdcall* run)(int arg);
  const char *comment;
  const char *help;
  const char *wanted_name;
  const char *wanted_hotkey;
};
extern "C" __declspec(dllexport) plugin_t PLUGIN;
typedef int __stdcall hook_cb_t(void *user_data, int notification_code, va_list va);
enum hook_type_t
{
  HT_IDP,
  HT_UI,
  HT_DBG,
  HT_IDB,
  HT_DEV,
  HT_LAST
};
extern "C" bool __stdcall hook_to_notification_point(hook_type_t hook_type,
                                hook_cb_t *cb,
                                void *user_data);
extern "C" int __stdcall unhook_from_notification_point(hook_type_t hook_type,
                                    hook_cb_t *cb,
                                    void *user_data = 0);
extern "C" int __stdcall invoke_callbacks(hook_type_t hook_type, int notification_code, va_list va);
extern "C" const char *__stdcall get_plugin_options(const char *plugin);
struct idadll_t
{
  void *dllinfo[10];
  void *entry;
  idadll_t(void) { dllinfo[0] = 0; entry = 0; }
  bool is_loaded(void) const { return dllinfo[0] != 0; }
};
int load_dll(const char *file, idadll_t *dllmem);
void                  load_dll_or_die(const char *file, idadll_t *dllmem);
extern "C" int __stdcall load_dll_or_say(const char *file, idadll_t *dllmem);
extern "C" void __stdcall free_dll(idadll_t *dllmem);
extern "C" char *__stdcall get_idp_desc(const char *file, char *buf, size_t bufsize);
extern "C" int __stdcall enum_processor_modules(
  int (__stdcall *func)(const char *file, void *ud),
  void *ud,
  char *answer,
  size_t answer_size,
  const extlang_t **el = 0);
extern "C" int __stdcall enum_plugins(
  int (__stdcall *func)(const char *file, void *ud),
  void *ud,
  char *answer,
  size_t answer_size,
  const extlang_t **el = 0);
struct plugin_info_t
{
  plugin_info_t *next;
  char *path;
  char *org_name;
  char *name;
  ushort org_hotkey;
  ushort hotkey;
  int arg;
  plugin_t *entry;
  idadll_t dllmem;
  int flags;
};
extern "C" plugin_info_t *__stdcall get_plugins(void);
extern "C" plugin_t *__stdcall load_plugin(const char *name);
extern "C" bool __stdcall run_plugin(const plugin_t *ptr, int arg);
 bool __stdcall load_and_run_plugin(const char *name, int arg)
{
  return run_plugin(load_plugin(name), arg);
}
extern "C" bool __stdcall invoke_plugin(plugin_info_t *ptr);
struct dbg_info_t
{
  plugin_info_t *pi;
  struct debugger_t *dbg;
  dbg_info_t(plugin_info_t *_pi, struct debugger_t *_dbg) : pi(_pi), dbg(_dbg) {}
};
template <> struct ida_movable_type<dbg_info_t> { typedef ida_true_type is_movable_type; };
extern "C" size_t __stdcall get_debugger_plugins(const dbg_info_t **array);
extern "C" void __stdcall init_plugins(int flag);
extern "C" void __stdcall term_plugins(int flag);
void init_fileregions(void);
void term_fileregions(void);
 void save_fileregions(void) {}
void add_fileregion(ea_t ea1,ea_t ea2,int32 fpos);
void move_fileregions(ea_t from, ea_t to, asize_t size);
void del_fileregions(ea_t ea1, ea_t ea2);
extern "C" int32 __stdcall get_fileregion_offset(ea_t ea);
extern "C" ea_t __stdcall get_fileregion_ea(int32 offset);
extern "C" int __stdcall gen_exe_file(FILE *fp);
extern "C" int __stdcall reload_file(const char *file, bool is_remote);
int local_gen_idc_file(FILE *fp, ea_t ea1, ea_t ea2, bool onlytypes);
class place_t;
int32 print_all_places(FILE *fp, const place_t *pl, html_line_cb_t *line_cb = 0);
extern html_line_cb_t save_text_line;
int32 __stdcall print_all_structs(FILE *fp, html_line_cb_t *line_cb = 0);
int32 __stdcall print_all_enums(FILE *fp, html_line_cb_t *line_cb = 0);
extern "C" __declspec(dllimport) char command_line_file[260];
extern "C" __declspec(dllimport) char database_idb[260];
extern "C" __declspec(dllimport) char database_id0[260];
extern "C" bool __stdcall is_database_ext(const char *ext);
extern uint32 ida_database_memory;
extern char ida_workdir[];
extern "C" uint32 __declspec(dllimport) database_flags;
 bool is_temp_database(void) { return (database_flags & 0x08) != 0; }
extern bool pe_create_idata;
extern bool pe_load_resources;
extern bool pe_create_flat_group;
extern bool initializing;
extern int highest_processor_level;
typedef int dbcheck_t;
const dbcheck_t
  DBCHK_NONE = 0,
  DBCHK_OK   = 1,
  DBCHK_BAD  = 2,
  DBCHK_NEW  = 3;
dbcheck_t check_database(const char *file);
int open_database(bool isnew, const char *file, uint32 input_size, bool is_temp_database);
extern "C" int __stdcall flush_buffers(void);
extern "C" bool __stdcall save_database(const char *outfile, bool delete_unpacked);
bool get_workbase_fname(char *buf, size_t bufsize, const char *ext);
void close_database(void);
bool compress_btree(const char *btree_file);
bool get_input_file_from_archive(char *filename, size_t namesize, bool is_remote, char **temp_file_ptr);
bool loader_move_segm(ea_t from, ea_t to, asize_t size, bool keep);
int generate_ida_copyright(FILE *fp, const char *cmt, html_line_cb_t *line_cb);
void clear_plugin_options(void);
bool is_in_loader(void);
bool is_embedded_dbfile_ext(const char *ext);
void get_ids_filename(char *buf,
                      size_t bufsize,
                      const char *idsname,
                      const char *ostype,
                      bool *use_ordinals,
                      char **autotils,
                      int maxtils);
bool add_plugin_option(const char *plugin_options);
const char *get_plugins_path(void);
#pragma pack(pop)
class func_t;
class abstract_graph_t;
extern "C" void __stdcall set_node_info(ea_t ea, int node, const bgcolor_t *pcolor, const ea_t *pea2, const char *text);
extern "C" char *__stdcall get_node_info(ea_t ea, int node, bgcolor_t *pcolor, ea_t *pea);
typedef int __stdcall graph_dispatcher_t(int code, ...);
extern "C" void __stdcall set_graph_dispatcher(graph_dispatcher_t *dsp);
extern "C" graph_dispatcher_t __declspec(dllimport) *grentry;
class node_ordering_t
{
  intseq_t node_by_order;
  intseq_t order_by_node;
public:
  void *operator new (size_t size) { return qalloc_or_throw(size); } void *operator new[](size_t size) { return qalloc_or_throw(size); } void *operator new(size_t , void *v) { return v; } void operator delete (void *blk) { qfree(blk); } void operator delete[](void *blk) { qfree(blk); } void operator delete(void *, void *) {}
  void __stdcall clear(void)
  {
    node_by_order.clear();
    order_by_node.clear();
  }
  void __stdcall resize(int n)
  {
    clear();
    node_by_order.resize(n, -1);
  }
  size_t __stdcall size(void) const { return node_by_order.size(); }
  void __stdcall set(int node, int num)
  {
    node_by_order[num] = node;
    if ( !order_by_node.empty() )
      order_by_node[node] = num;
  }
  bool __stdcall clr(int node);
  int  __stdcall node(size_t order) const { return size() > order ? node_by_order[order] : -1; }
  int  __stdcall order(int node);
};
struct edge_t
{
  int src;
  int dst;
  __stdcall edge_t(void) {}
  __stdcall edge_t(int x, int y) : src(x), dst(y) {}
  bool __stdcall operator < (const edge_t &y) const
    { return src < y.src || (src == y.src && dst < y.dst); }
  bool __stdcall operator == (const edge_t &y) const
    { return src == y.src && dst == y.dst; }
  bool __stdcall operator != (const edge_t &y) const
    { return src != y.src || dst != y.dst; }
};
template <> struct ida_movable_type<edge_t> { typedef ida_true_type is_movable_type; };
typedef qvector<edge_t> edgevec_t;
typedef std::set<edge_t> edgeset_t;
enum edge_type_t
{
  edge_error   = 0,
  edge_tree    = 1,
  edge_forward = 2,
  edge_back    = 3,
  edge_cross   = 4,
  edge_subgraph= 5
};
class edge_typer_t
{
public:
  virtual void __stdcall reset(void) = 0;
  virtual edge_type_t &__stdcall edge_type(int i, int j) = 0;
  edge_type_t &__stdcall edge_type(const edge_t &e) { return edge_type(e.src, e.dst); }
  virtual __stdcall ~edge_typer_t(void) {}
};
class simple_edge_typer_t : public edge_typer_t
{
public:
  typedef std::map<edge_t, edge_type_t> edge_types_t;
  edge_types_t edge_types;
  void __stdcall reset(void) { edge_types.clear(); }
  edge_type_t &__stdcall edge_type(int i, int j) { return edge_types[edge_t(i, j)]; }
};
class graph_node_visitor_t
{
  node_set_t visited;
public:
  void __stdcall reinit(void) { visited.clear(); }
  void __stdcall set_visited(int n) { visited.add(n); }
  bool __stdcall is_visited(int n) const { return visited.has(n); }
  virtual int  __stdcall visit_node(int ) { return 0; }
  virtual bool __stdcall is_forbidden_edge(int , int ) const { return false; }
  virtual __stdcall ~graph_node_visitor_t(void) {}
};
struct graph_path_visitor_t
{
  intseq_t path;
  bool prune;
  virtual int __stdcall walk_forward(int ) { return 0; }
  virtual int __stdcall walk_backward(int ) { return 0; }
  virtual __stdcall ~graph_path_visitor_t(void) {}
};
struct point_t
{
  int x, y;
  point_t(void) {}
  point_t(int _x, int _y) : x(_x), y(_y) {}
  point_t &add(const point_t &r)
  {
    x += r.x;
    y += r.y;
    return *this;
  }
  point_t &sub(const point_t &r)
  {
    x -= r.x;
    y -= r.y;
    return *this;
  }
  template <class T> void div(T d)
  {
    x /= d;
    y /= d;
  }
  void negate(void)
  {
    x = -x;
    y = -y;
  }
  bool operator ==(const point_t &r) const { return x == r.x && y == r.y; }
  bool operator !=(const point_t &r) const { return !(*this == r); }
  const char *__stdcall dstr(void) const;
  size_t __stdcall print(char *buf, size_t bufsize) const;
};
 double calc_dist(point_t p, point_t q)
{
  double dx = q.x - p.x;
  double dy = q.y - p.y;
  return sqrt(dx*dx+dy*dy);
}
class pointseq_t : public qvector<point_t>
{
public:
  const char *__stdcall dstr(void) const;
  size_t __stdcall print(char *buf, size_t bufsize) const;
};
struct rect_t
{
  int left;
  int top;
  int right;
  int bottom;
  rect_t(void) {}
  rect_t(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
  rect_t(const point_t &p0, const point_t &p1)
    : left  (((p0.x) < (p1.x)? (p0.x): (p1.x))),
      top   (((p0.y) < (p1.y)? (p0.y): (p1.y))),
      right (((p0.x) > (p1.x)? (p0.x): (p1.x))),
      bottom(((p0.y) > (p1.y)? (p0.y): (p1.y)))  {}
  int width(void) const { return right - left; }
  int height(void) const { return bottom - top; }
  void move_to(const point_t &p)
  {
    int dx  = p.x - left;
    int dy  = p.y - top;
    move_by(point_t(dx, dy));
  }
  void move_by(const point_t &p)
  {
    left   += p.x;
    right  += p.x;
    top    += p.y;
    bottom += p.y;
  }
  point_t center(void) const
  {
    return point_t((left+right)/2, (top+bottom)/2);
  }
  point_t topleft(void) const
  {
    return point_t(left, top);
  }
  point_t bottomright(void) const
  {
    return point_t(right, bottom);
  }
  void grow(int delta)
  {
    left   -= delta;
    right  += delta;
    top    -= delta;
    bottom += delta;
  }
  void intersect(const rect_t &r)
  {
    if ( left   < r.left   ) left   = r.left;
    if ( right  > r.right  ) right  = r.right;
    if ( top    < r.top    ) top    = r.top;
    if ( bottom > r.bottom ) bottom = r.bottom;
  }
  void make_union(const rect_t &r)
  {
    if ( left   > r.left   ) left   = r.left;
    if ( right  < r.right  ) right  = r.right;
    if ( top    > r.top    ) top    = r.top;
    if ( bottom < r.bottom ) bottom = r.bottom;
  }
  bool empty(void) const
  {
    return left >= right || top >= bottom;
  }
  bool is_intersection_empty(const rect_t &r) const
  {
    return left   >= r.right
        || right  <= r.left
        || top    >= r.bottom
        || bottom <= r.top;
  }
  bool contains(const point_t &p) const
  {
    return left <= p.x
        && right > p.x
        && top <= p.y
        && bottom > p.y;
  }
  int area(void) const { return width()*height(); }
  bool __stdcall operator == (const rect_t &r) const
  {
    return left   == r.left
        && right  == r.right
        && top    == r.top
        && bottom == r.bottom;
  }
  bool __stdcall operator != (const rect_t &r) const { return !(*this == r); }
  bool __stdcall operator < (const rect_t &r) const;
};
struct TPointDouble
{
  double x, y;
  TPointDouble(void) {}
  TPointDouble(double a, double b) : x(a), y(b) {}
  TPointDouble(const point_t &r) : x(r.x), y(r.y) {}
  void add(const TPointDouble &r)
  {
    x += r.x;
    y += r.y;
  }
  void sub(const TPointDouble &r)
  {
    x -= r.x;
    y -= r.y;
  }
  void negate(void)
  {
    x = -x;
    y = -y;
  }
  template <class T> void div(T d)
  {
    x /= d;
    y /= d;
  }
  bool operator ==(const TPointDouble &r) const { return x == r.x && y == r.y; }
  bool operator !=(const TPointDouble &r) const { return !(*this == r); }
};
typedef int layout_type_t;
const layout_type_t
  layout_none    = 0,
  layout_digraph = 1,
  layout_tree    = 2,
  layout_circle  = 3;
struct edge_info_t
{
  int color;
  int width;
  int srcoff;
  int dstoff;
  pointseq_t layout;
  void __stdcall reverse_layout(void) { std::reverse(&layout[0], &layout[layout.size()]); }
  void __stdcall add_layout_point(point_t p);
       __stdcall edge_info_t(void) : color(-1), width(1), srcoff(-1), dstoff(-1) {}
};
struct edge_layout_point_t
{
  int pidx;
  edge_t e;
  __stdcall edge_layout_point_t(void) : pidx(-1), e(-1, -1) {}
  __stdcall edge_layout_point_t(const edge_layout_point_t &r) : pidx(r.pidx), e(r.e) {}
  __stdcall edge_layout_point_t(const edge_t &_e, int _pidx) : pidx(_pidx), e(_e) {}
  int __stdcall compare(const edge_layout_point_t &r) const
  {
    if ( e < r.e )
      return -1;
    if ( r.e < e )
      return 1;
    return pidx - r.pidx;
  }
  bool __stdcall operator == (const edge_layout_point_t &r) const
  {
    return pidx == r.pidx && e == r.e;
  }
  bool __stdcall operator != (const edge_layout_point_t &r) const
  {
    return !(*this == r);
  }
};
struct selection_item_t
{
  bool is_node;
  int node;
  edge_layout_point_t elp;
  __stdcall selection_item_t(void) {}
  __stdcall selection_item_t(int n) : is_node(true), node(n) {}
  __stdcall selection_item_t(edge_layout_point_t &_elp)
    : is_node(false), node(-1), elp(_elp) {}
  __stdcall selection_item_t(edge_t e, int idx)
    : is_node(false), node(-1), elp(e, idx) {}
  __stdcall selection_item_t(class graph_item_t &);
  int __stdcall compare(const selection_item_t &r) const
  {
    if ( is_node != r.is_node )
      return is_node - r.is_node;
    if ( is_node )
      return node - r.node;
    return elp.compare(r.elp);
  }
  bool __stdcall operator == (const selection_item_t &r) const
    { return compare(r) == 0; }
  bool __stdcall operator < (const selection_item_t &r) const
    { return compare(r) < 0; }
};
struct screen_graph_selection_t : std::set<selection_item_t>
{
  bool __stdcall has(const selection_item_t &item) const
    { return (const_iterator)find(item) != end(); }
  void __stdcall add(const screen_graph_selection_t &s)
  {
    for ( screen_graph_selection_t::const_iterator p=s.begin(); p != s.end(); ++p )
      insert(*p);
  }
  void __stdcall sub(const screen_graph_selection_t &s)
  {
    for ( screen_graph_selection_t::const_iterator p=s.begin(); p != s.end(); ++p )
      erase(*p);
  }
  void __stdcall add_node(int n) { insert(selection_item_t(n)); }
  void __stdcall del_node(int n) { erase(selection_item_t(n)); }
  void __stdcall add_point(edge_t e, int idx) { insert(selection_item_t(e, idx)); }
  void __stdcall del_point(edge_t e, int idx) { erase(selection_item_t(e, idx)); }
};
struct edge_segment_t
{
  edge_t e;
  int nseg;
  int x0, x1;
  size_t __stdcall length(void) const { return abs(x1-x0); }
  bool __stdcall toright(void) const { return x1 > x0; }
  bool __stdcall operator < (const edge_segment_t &r) const
  {
    return e < r.e;
  }
};
enum graph_item_type_t
{
  git_none,
  git_edge,
  git_node,
  git_tool,
  git_text,
  git_elp,
};
class graph_item_t
{
public:
  graph_item_type_t type;
  edge_t e;
  int n;
  int b;
  point_t p;
  edge_layout_point_t elp;
  bool operator == (const graph_item_t &r) const;
  bool is_node(void) const { return type >= git_node && type <= git_text; }
  bool is_edge(void) const { return type == git_edge || type == git_elp; }
};
struct interval_t
{
  int x0, x1;
  bool empty(void) const { return x0 < x1; }
  void intersect(const interval_t &r)
  {
    if ( x0 < r.x0 ) x0 = r.x0;
    if ( x1 > r.x1 ) x1 = r.x1;
  }
  void make_union(const interval_t &r)
  {
    if ( x0 > r.x0 ) x0 = r.x0;
    if ( x1 < r.x1 ) x1 = r.x1;
  }
  void move_by(int shift)
  {
    x0 += shift;
    x1 += shift;
  }
  interval_t(void) {}
  interval_t(int y0, int y1)
  {
    x0 = ((y0) < (y1)? (y0): (y1));
    x1 = ((y0) > (y1)? (y0): (y1));
  }
  interval_t(const edge_segment_t &s)
  {
    x0 = ((s.x0) < (s.x1)? (s.x0): (s.x1));
    x1 = ((s.x0) > (s.x1)? (s.x0): (s.x1));
  }
  int length(void) const { return x1 - x0; }
  bool contains(int x) const { return x0 <= x && x <= x1; }
  bool operator ==(const interval_t &r) const { return x0 == r.x0 && x1 == r.x1; }
  bool operator !=(const interval_t &r) const { return !(*this == r); }
};
typedef std::set<edge_segment_t> edge_segments_t;
typedef std::vector<edge_segment_t> edge_seg_vec_t;
typedef std::vector<edge_segments_t> edge_segs_vec_t;
typedef std::map<edge_t, edge_info_t> edge_infos_t;
struct row_info_t
{
  intseq_t nodes;
  int top;
  int bottom;
  int height(void) const { return bottom - top; }
  row_info_t(void) : top(0) {}
};
typedef qvector<row_info_t> graph_row_info_t;
static const int ygap = 30;
static const int xgap = 10;
static const int arrow_height = 10;
static const int arrow_width = 8;
struct graph_location_info_t;
class graph_visitor_t;
class abstract_graph_t : public gdl_graph_t
{
  void __stdcall find_entries(node_set_t &entries) const;
  void __stdcall depth_first(int root, struct depth_first_info_t &di) const;
  size_t __stdcall remove_reachable(int n, node_set_t &s) const;
  int    __stdcall longest_path(int n, intseq_t &tops, int row_height) const;
  size_t __stdcall sort_layer_nodes(const row_info_t &r1,
                         const intmap_t &lpi1,
                         row_info_t &r2,
                         intmap_t &lpi2,
                         bool ispred) const;
  size_t __stdcall calc_cross_num(const intseq_t &r1,
                       const intseq_t &r2,
                       const intmap_t &lpi1,
                       bool ispred) const;
  size_t __stdcall num_crossings(const graph_row_info_t &gri, const array_of_intmap_t &nodepi) const;
  int    __stdcall calc_x_coord(const row_info_t &ri, int idx, bool ispred, int first_added_node) const;
  void   __stdcall try_move_down(intseq_t &tops, int n, int row_height) const;
protected:
  void __stdcall get_connected_components(intseq_t &entries) const;
  int __stdcall calc_longest_pathes(
        const node_set_t &entries,
        intseq_t &tops,
        int row_height) const;
  void __stdcall move_nodes_down(
        intseq_t &tops,
        const node_ordering_t &post,
        int first_reverser_node,
        int row_height) const;
  void __stdcall create_graph_row_info(
        const intseq_t &tops,
        graph_row_info_t &gri,
        int graph_height) const;
  void __stdcall calc_row_heights(graph_row_info_t &gri) const;
  void __stdcall minimize_crossings(graph_row_info_t &gri) const;
  void __stdcall set_x_coords(
        const graph_row_info_t &gri,
        const node_set_t &selfrefs,
        int first_added_node);
  void __stdcall gather_edge_segments(
        const graph_row_info_t &gri,
        edge_segs_vec_t &ges) const;
  void __stdcall make_rect_edges(
        graph_row_info_t &gri,
        const edge_segs_vec_t &ges,
        int first_reverser_node);
  void __stdcall assign_edge_ports(
        const graph_row_info_t &gri,
        const node_set_t &selfrefs);
  void __stdcall recalc_edge_widths(
        const edgeset_t &back_edges,
        const edge_infos_t &self_edges);
  void __stdcall clear_layout_info(void);
  void __stdcall depth_first(
        node_ordering_t *pre,
        node_ordering_t *post,
        edge_typer_t *et) const;
  void __stdcall create_spanning_tree(
        edge_typer_t *et,
        node_set_t *entries,
        edgeset_t *back_edges,
        node_ordering_t *pre,
        node_ordering_t *post) const;
  void __stdcall tree_layout(edge_typer_t &et, const node_set_t &entries);
  bool __stdcall path_back(const array_of_node_set_t &domin, int m, int n) const;
  bool __stdcall path_back(edge_typer_t &et, int m, int n) const;
  int __stdcall visit_nodes(int node, graph_node_visitor_t &gv) const;
  int __stdcall visit_paths(int node, graph_path_visitor_t &gv) const;
public:
  qstring title;
  bool rect_edges_made;
  layout_type_t current_layout;
  point_t circle_center;
  int circle_radius;
  hook_cb_t *callback;
  void *callback_ud;
  __stdcall abstract_graph_t(void)
    : rect_edges_made(false),
      current_layout(layout_none),
      callback(0),
      callback_ud(0)
  {}
  virtual __stdcall ~abstract_graph_t(void) {}
  void __stdcall clear(void);
  void __stdcall dump_graph(void) const;
  bool __stdcall calc_bounds(rect_t *r);
  bool __stdcall calc_fitting_params(
        const rect_t &area,
        graph_location_info_t *gli,
        double max_zoom);
  int __stdcall for_all_nodes_edges(graph_visitor_t &nev, bool visit_nodes=true);
  const edge_info_t *__stdcall get_edge_ports(
        edge_t e,
        point_t &s,
        point_t &d) const;
  void __stdcall add_node_edges(edgeset_t &dlist, int node);
  const rect_t &__stdcall nrect(int n) const
    { return (const_cast<abstract_graph_t *>(this))->nrect(n); }
  const edge_info_t *__stdcall get_edge(edge_t e) const
    { return (const_cast<abstract_graph_t *>(this))->get_edge(e); }
  virtual rect_t &__stdcall nrect(int n) = 0;
  virtual edge_info_t *__stdcall get_edge(edge_t e) = 0;
  virtual abstract_graph_t *__stdcall clone(void) const = 0;
  bool __stdcall create_tree_layout(void);
  bool __stdcall create_circle_layout(point_t p, int radius);
  void set_callback(hook_cb_t *_callback, void *_ud)
  {
    callback = _callback;
    callback_ud = _ud;
  }
  int vgrcall(int code, va_list va)
  {
    if ( callback != 0 )
      return callback(callback_ud, code, va);
    return 0;
  }
  int grcall(int code, ...)
  {
    va_list va;
    ( va = (va_list)( &reinterpret_cast<const char &>(code) ) + ( (sizeof(code) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
    int result = vgrcall(code, va);
    ( va = (va_list)0 );
    return result;
  }
};
class mutable_graph_t : public abstract_graph_t
{
  typedef abstract_graph_t inherited;
  typedef std::map<int, int> destset_t;
  friend int __stdcall graph_dispatcher(int code, ...);
  int __stdcall _find_subgraph_node(int group, int n) const;
  void __stdcall collapse_edges(const intset_t &nodes, int group);
  void __stdcall del_node_keep_edges(int n);
  void __stdcall add_dest(destset_t &ne, edge_t e, int g);
  void __stdcall reverse_edges(
        const edgeset_t &back_edges,
        edge_infos_t &self_edges,
        node_set_t &entries);
  void __stdcall layout_self_reference_edges(const edge_infos_t &selfrefs);
  void __stdcall restore_edges(int first_reserver_node, bool failed);
  void __stdcall add_layer_nodes(graph_row_info_t &gri, intseq_t &tops);
  void __stdcall del_layer_nodes(graph_row_info_t &gri, int first_added_node);
public:
  uval_t gid;
  intseq_t belongs;
  boolvec_t is_group;
  array_of_intseq_t org_succs;
  array_of_intseq_t org_preds;
  array_of_intseq_t succs;
  array_of_intseq_t preds;
  typedef qvector<rect_t> node_layout_t;
  node_layout_t nodes;
  edge_infos_t edges;
  __stdcall mutable_graph_t(uval_t id) : gid(id) {}
  __stdcall mutable_graph_t(const abstract_graph_t &g, uval_t id);
  virtual __stdcall ~mutable_graph_t(void) {}
  int  __stdcall size(void) const { return int(succs.size()); }
  int  __stdcall node_qty(void) const;
  void __stdcall clear(void);
  bool __stdcall empty(void) const;
  bool __stdcall exists(int node) const { return is_visible_node(node); }
  int  __stdcall get_node_representative(int node);
  int  __stdcall get_node_group(int node) const { return (belongs[node] & ~0x80000000); }
  void __stdcall set_node_group(int node, int group) { belongs[node] = group | (belongs[node] & 0x80000000); }
  bool __stdcall is_deleted_node(int node) const { return belongs[node] == 2147483647; }
  void __stdcall set_deleted_node(int node) { belongs[node] = 2147483647; }
  bool __stdcall is_subgraph_node(int node) const { return get_node_group(node) != node; }
  bool __stdcall is_group_node(int node) const { return is_group[node]; }
  bool __stdcall is_simple_node(int node) const { return !is_group_node(node); }
  bool __stdcall is_collapsed_node(int node) const { return (belongs[node] & 0x80000000) != 0; }
  bool __stdcall is_uncollapsed_node(int node) const { return is_group_node(node) && !is_collapsed_node(node); }
  bool __stdcall is_visible_node(int node) const;
  bool __stdcall groups_are_present(void) const;
  int  __stdcall get_first_subgraph_node(int group) const { return _find_subgraph_node(group, 0); }
  int  __stdcall get_next_subgraph_node(int group, int current) const { return _find_subgraph_node(group, current+1); }
  void __stdcall insert_visible_nodes(intset_t &nodes, int group) const;
  void __stdcall insert_simple_nodes(intset_t &nodes, int group) const;
  bool __stdcall check_new_group(const intset_t &nodes, intset_t &refined);
  int  __stdcall create_group(const intset_t &nodes);
  bool __stdcall delete_group(int group);
  bool __stdcall change_group_visibility(int group, bool expand);
  bool __stdcall change_visibility(const intset_t &nodes, bool expand);
  void __stdcall recalc_edges(void);
  int  __stdcall nsucc(int b) const  { return (int)succs[b].size(); }
  int  __stdcall npred(int b) const  { return (int)preds[b].size(); }
  int  __stdcall succ(int b, int i) const { return succs[b][i]; }
  int  __stdcall pred(int b, int i) const { return preds[b][i]; }
  const intseq_t &__stdcall succset(int b) const { return succs[b]; }
  const intseq_t &__stdcall predset(int b) const { return preds[b]; }
  void __stdcall reset(void) { resize(0); }
  virtual bool __stdcall redo_layout(void) ;
  virtual void __stdcall resize(int n) ;
  virtual int  __stdcall add_node(const rect_t *r) ;
  virtual ssize_t __stdcall del_node(int n) ;
  virtual bool __stdcall add_edge(int i, int j, const edge_info_t *ei) ;
  virtual bool __stdcall del_edge(int i, int j) ;
  virtual bool __stdcall replace_edge(int i, int j, int x, int y) ;
  virtual bool __stdcall refresh(void) ;
  virtual mutable_graph_t *__stdcall clone(void) const ;
  const rect_t &__stdcall nrect(int n) const
    { return (const_cast<mutable_graph_t *>(this))->nrect(n); }
  rect_t &__stdcall nrect(int n);
  virtual edge_info_t *__stdcall get_edge(edge_t e) ;
  virtual bool __stdcall set_nrect(int n, const rect_t &r) ;
  virtual bool __stdcall set_edge(edge_t e, const edge_info_t *ei) ;
  bool __stdcall create_digraph_layout(void);
  void __stdcall del_custom_layout(void);
  bool __stdcall get_custom_layout(void);
  void __stdcall set_custom_layout(void) const;
  bool __stdcall get_graph_groups(void);
  void __stdcall set_graph_groups(void) const;
  virtual ea_t __stdcall calc_group_ea(const intset_t& ) { return ea_t(-1); }
  point_t __stdcall calc_center_of(const intset_t &nodes) const;
  void __stdcall move_to_same_place(const intset_t &collapsing_nodes, point_t p);
  void __stdcall move_grouped_nodes(const intset_t &groups, const mutable_graph_t *ng);
  virtual bool __stdcall is_user_graph() { return false; }
};
class graph_visitor_t
{
protected:
  abstract_graph_t *g;
  virtual int __stdcall visit_node(int n, rect_t &r) = 0;
  virtual int __stdcall visit_edge(edge_t e, edge_info_t *ei) = 0;
  friend int __stdcall abstract_graph_t::for_all_nodes_edges(graph_visitor_t &nev, bool visit_nodes);
};
enum graph_notification_t
{
  grcode_calculating_layout,
  grcode_layout_calculated,
  grcode_changed_graph,
  grcode_changed_current,
  grcode_clicked,
  grcode_dblclicked,
  grcode_creating_group,
  grcode_deleting_group,
  grcode_group_visibility,
  grcode_gotfocus,
  grcode_lostfocus,
  grcode_user_refresh,
  grcode_user_gentext,
  grcode_user_text,
  grcode_user_size,
  grcode_user_title,
  grcode_user_draw,
  grcode_user_hint,
  grcode_destroyed,
  grcode_create_graph_viewer = 256,
  grcode_get_graph_viewer,
  grcode_get_viewer_graph,
  grcode_create_mutable_graph,
  grcode_set_viewer_graph,
  grcode_refresh_viewer,
  grcode_fit_window,
  grcode_get_curnode,
  grcode_center_on,
  grcode_set_gli,
  grcode_add_menu_item,
  grcode_del_menu_item,
  grcode_get_selection,
  grcode_del_custom_layout,
  grcode_set_custom_layout,
  grcode_set_graph_groups,
  grcode_clear,
  grcode_create_digraph_layout,
  grcode_create_tree_layout,
  grcode_create_circle_layout,
  grcode_get_node_representative,
  grcode_find_subgraph_node,
  grcode_create_group,
  grcode_get_custom_layout,
  grcode_get_graph_groups,
  grcode_empty,
  grcode_is_visible_node,
  grcode_delete_group,
  grcode_change_group_visibility,
  grcode_set_edge,
  grcode_node_qty,
  grcode_nrect,
  grcode_set_titlebar_height,
  grcode_create_user_graph_place,
  grcode_create_disasm_graph1,
  grcode_create_disasm_graph2,
};
class TForm;
typedef TCustomControl graph_viewer_t;
 graph_viewer_t *__stdcall create_graph_viewer(
        TForm *parent,
        uval_t id,
        hook_cb_t *callback,
        void *ud,
        int title_height)
{
  graph_viewer_t *gv = 0;
  grentry(grcode_create_graph_viewer, parent, &gv, id, callback, ud, title_height);
  return gv;
}
 graph_viewer_t *__stdcall get_graph_viewer(TForm *parent)                { graph_viewer_t *gv = 0; grentry(grcode_get_graph_viewer, parent, &gv); return gv; }
 mutable_graph_t *__stdcall get_viewer_graph(graph_viewer_t *gv)          { mutable_graph_t *g = 0; grentry(grcode_get_viewer_graph, gv, &g); return g; }
 mutable_graph_t *__stdcall create_mutable_graph(uval_t id)               { mutable_graph_t *g = 0; grentry(grcode_create_mutable_graph, id, &g); return g; }
 mutable_graph_t *__stdcall create_disasm_graph(ea_t ea)                  { mutable_graph_t *g = 0; grentry(grcode_create_disasm_graph1, ea, &g); return g; }
 mutable_graph_t *__stdcall create_disasm_graph(const areavec_t &ranges)  { mutable_graph_t *g = 0; grentry(grcode_create_disasm_graph2, &ranges, &g); return g; }
 void __stdcall set_viewer_graph(graph_viewer_t *gv, mutable_graph_t *g)  {        grentry(grcode_set_viewer_graph, gv, g); }
 void __stdcall refresh_viewer(graph_viewer_t *gv)                        {        grentry(grcode_refresh_viewer, gv); }
 void __stdcall viewer_fit_window(graph_viewer_t *gv)                     {        grentry(grcode_fit_window, gv); }
 int  __stdcall viewer_get_curnode(graph_viewer_t *gv)                    { return grentry(grcode_get_curnode, gv); }
 void __stdcall viewer_center_on(graph_viewer_t *gv, int node)            {        grentry(grcode_center_on, gv, node); }
 void __stdcall viewer_set_gli(graph_viewer_t *gv,
                                  const graph_location_info_t *gli)          { grentry(grcode_set_gli, gv, gli); }
 bool __stdcall viewer_add_menu_item(graph_viewer_t *gv,
                                        const char *title,
                                        menu_item_callback_t *callback,
                                        void *ud,
                                        const char *hotkey,
                                        int flags)                           { return grentry(grcode_add_menu_item, gv, title, callback, ud, hotkey, flags); }
 bool __stdcall viewer_del_menu_item(graph_viewer_t *gv,
                                        const char *title)                   { return grentry(grcode_del_menu_item, gv, title); }
 bool __stdcall viewer_get_selection(graph_viewer_t *gv,
                                        screen_graph_selection_t *sgs)       { return grentry(grcode_get_selection, gv, sgs); }
 int  __stdcall viewer_set_titlebar_height(graph_viewer_t *gv,
                                        int height)                          { return grentry(grcode_set_titlebar_height, gv, height); }
 void __stdcall mutable_graph_t::del_custom_layout(void)                  {        grentry(grcode_del_custom_layout, this); }
 void __stdcall mutable_graph_t::set_custom_layout(void) const            {        grentry(grcode_set_custom_layout, this); }
 void __stdcall mutable_graph_t::set_graph_groups(void) const             {        grentry(grcode_set_graph_groups, this); }
 void __stdcall mutable_graph_t::clear(void)                              {        grentry(grcode_clear, this); }
 bool __stdcall mutable_graph_t::create_digraph_layout(void)              { return grentry(grcode_create_digraph_layout, this); }
 bool __stdcall abstract_graph_t::create_tree_layout(void)                { return grentry(grcode_create_tree_layout, this); }
 bool __stdcall abstract_graph_t::create_circle_layout(point_t c, int radius) { return grentry(grcode_create_circle_layout, this, c.x, c.y, radius); }
 int  __stdcall mutable_graph_t::get_node_representative(int node)        { return grentry(grcode_get_node_representative, this, node); }
 int  __stdcall mutable_graph_t::_find_subgraph_node(int gr, int n) const { return grentry(grcode_find_subgraph_node, this, gr, n); }
 int  __stdcall mutable_graph_t::create_group(const intset_t &nodes)      { return grentry(grcode_create_group, this, &nodes); }
 bool __stdcall mutable_graph_t::get_custom_layout(void)                  { return grentry(grcode_get_custom_layout, this); }
 bool __stdcall mutable_graph_t::get_graph_groups(void)                   { return grentry(grcode_get_graph_groups, this); }
 bool __stdcall mutable_graph_t::empty(void) const                        { return grentry(grcode_empty, this); }
 bool __stdcall mutable_graph_t::is_visible_node(int node) const          { return grentry(grcode_is_visible_node, this, node); }
 bool __stdcall mutable_graph_t::delete_group(int group)                  { return grentry(grcode_delete_group, this, group); }
 bool __stdcall mutable_graph_t::change_group_visibility(int gr, bool exp){ return grentry(grcode_change_group_visibility, this, gr, exp); }
 bool __stdcall mutable_graph_t::set_edge(edge_t e, const edge_info_t *ei){ return grentry(grcode_set_edge, this, e.src, e.dst, ei); }
 int  __stdcall mutable_graph_t::node_qty(void) const                     { return grentry(grcode_node_qty, this); }
 rect_t &__stdcall mutable_graph_t::nrect(int n)                          { rect_t *r; grentry(grcode_nrect, this, n, &r); return *r; }
struct user_graph_place_t : public place_t
{
  int node;
};
 user_graph_place_t *create_user_graph_place(int node, int lnnum)      { user_graph_place_t *r; grentry(grcode_create_user_graph_place, node, lnnum, &r); return r; }
#pragma pack(pop)
#pragma pack(push, 1)
typedef int help_t;
enum
{
  ErOk = 0,
  ErNoFile = -1,
  ErBadHelp = -2,
  ErBadVers = -3,
  ErIO = -4,
  ErNoMem = -5,
  ErBadOS = -6
};
int HelpInit(const char *defaultpath, const char *helpfile, int *argc, char *argv[], char sw);
extern "C"  char *__stdcall ivalue(help_t mes, char *buf, size_t bufsize);
extern "C"  char *__stdcall qivalue(help_t mes);
class itext
{
  char *ptr;
public:
  itext(help_t mes) { ptr = qivalue(mes); }
  ~itext(void)      { qfree(ptr); }
  operator char*()  { return ptr; }
};
__declspec(noreturn)  void Err(help_t format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  verror(itext(format), va);
}
 void Warn(help_t format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vwarning(itext(format), va);
  ( va = (va_list)0 );
}
 void Info(help_t format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  vinfo(itext(format), va);
  ( va = (va_list)0 );
}
 int Message(help_t format,...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int nbytes = vmsg(itext(format), va);
  ( va = (va_list)0 );
  return nbytes;
}
 int askyn_v(int deflt, help_t format, va_list va)
{
  return askyn_cv(deflt, itext(format), va);
}
 int askyn(int deflt, help_t format, ...)
{
  va_list va;
  ( va = (va_list)( &reinterpret_cast<const char &>(format) ) + ( (sizeof(format) + sizeof(int) - 1) & ~(sizeof(int) - 1) ) );
  int code = askyn_cv(deflt, itext(format), va);
  ( va = (va_list)0 );
  return code;
}
#pragma pack(pop)
#pragma pack(push, 1)
typedef uint16 eNE[6];
typedef uint16 eNI[(6+3)];
extern "C" const eNE __declspec(dllimport) ieee_ezero;
extern "C" const eNE __declspec(dllimport) ieee_eone;
extern const eNE ieee_etwo;
extern const eNE ieee_e32;
extern const eNE ieee_elog2;
extern const eNE ieee_esqrt2;
extern const eNE ieee_eoneopi;
extern const eNE ieee_epi;
extern const eNE ieee_eeul;
 void ecleaz(eNI x) { memset(x, 0, sizeof(eNI)); }
extern "C"  void __stdcall emovo(const eNI a, eNE b);
extern "C"  void __stdcall emovi(const eNE a, eNI b);
extern "C"  int  __stdcall eshift(eNI x, int sc);
extern "C"  int  __stdcall emdnorm(eNI s, int lost, int subflg, int32 exp, int rndbase);
int __stdcall realcvt(void *m, eNE e, uint16 swt);
int l_realcvt(void *m, eNE e, uint16 swt);
int b_realcvt(void *m, eNE e, uint16 swt);
extern "C"  int __stdcall ieee_realcvt(void *m, eNE e, uint16 swt);
extern "C"  void __stdcall realtoasc(const eNE x, char *buf, size_t bufsize, uint mode);
extern "C"  int __stdcall asctoreal(const char **sss, eNE y);
extern "C"  void __stdcall eltoe(sval_t l, eNE e);
extern "C"  void __stdcall eltoe64(int64 l, eNE e);
extern "C"  void __stdcall eltoe64u(uint64 l, eNE e);
extern "C"  int __stdcall eetol(const eNE a, sval_t *l, bool roundflg);
extern "C"  int __stdcall eetol64(const eNE a, int64 *l, bool roundflg);
extern "C"  int __stdcall eetol64u(const eNE a, uint64 *l, bool roundflg);
extern "C"  int __stdcall eldexp(const eNE a, int32 pwr2, eNE b);
extern "C"  int __stdcall eadd(const eNE a, const eNE b, eNE c, int subflg);
extern "C"  int __stdcall emul(const eNE a, const eNE b, eNE c);
extern "C"  int __stdcall ediv(const eNE a, const eNE b, eNE c);
void eclear(eNE a);
void emov(eNE a, eNE b);
void eabs(eNE x);
 void eneg(eNE x)
{
  if(x[6-1])
    x[6-1] ^= 0x8000;
}
int esign(eNE x);
extern "C"  int __stdcall ecmp(const eNE a, const eNE b);
#pragma pack(pop)
#pragma pack(push, 1)
class insn_t;
class WorkReg;
extern "C" ssize_t __stdcall get_predef_insn_cmt(
        const insn_t &cmd,
        char *buf,
        size_t bufsize);
extern "C" ssize_t __stdcall get_predef_cmt(
        const char *info,
        int wrktyp,
        char *buf,
        size_t bufsize);
 char *__stdcall get_vxd_func_name(
        int vxdnum,
        int funcnum,
        char *buf,
        size_t bufsize)
{
  buf[0] = '\0';
  ph.notify(ph.get_vxd_name, vxdnum, funcnum, buf, bufsize);
  return buf[0] ? buf : 0;
}
void init_predefs(void);
void term_predefs(void);
#pragma pack(pop)
#pragma pack(push, 1)
typedef ushort lxtype;
const lxtype
  lx_end      = 1,
  lx_ident    = 2,
  lx_number   = 3,
  lx_string   = 4,
  lx_char     = 5,
  lx_typename = 6,
  lx_float    = 7,
  lx_int64    = 8,
  lx_key      = 128;
struct token_t
{
  lxtype type;
  char str[1024];
  sval_t num;
  bool unicode;
  union
  {
    ushort fnum[6];
    size_t slen;
    int64 i64;
  };
};
class lexer_t;
typedef error_t lx_resolver_t(lexer_t *lx, void *ud, token_t *curtok, sval_t *res);
typedef int __stdcall lx_preprocessor_cb(void *ud, const char *fname, int nl, char *line);
typedef int __stdcall lx_pragma_cb(void *ud, const char *line);
typedef int __stdcall lx_macro_cb(
        void *ud,
        const char *name,
        const char *body,
        int nargs,
        bool isfunc,
        bool is_new_macro);
extern "C" lexer_t *__stdcall create_lexer(const char *const *keys,
                                        size_t size,
                                        void *ud=0);
extern "C" void __stdcall destroy_lexer(lexer_t *lx);
extern "C" error_t __stdcall lex_define(lexer_t *lx,
                                     const char *macro,
                                     const char *body,
                                     int nargs=0,
                                     bool isfunc=false);
extern "C" void __stdcall lex_undef(lexer_t *lx,
                                 const char *macro);
extern "C" error_t __stdcall lxget(lexer_t *lx, token_t *t);
extern "C" int __stdcall lex_enum_macros(
        const lexer_t *lx,
        int __stdcall cb(const char *name, const char *body, int nargs, bool isfunc, void *ud),
        void *ud);
extern "C" const char *__stdcall lxascii(const token_t *t, char *buf, size_t bufsize);
struct macro_t;
extern "C" error_t __stdcall lxini(lexer_t *lx,
                                const char *line,
                                macro_t **macros=0);
const char *lxptr(const lexer_t *lx);
const char *lxprev(const lexer_t *lx);
void set_lxprev(lexer_t *lx, const char *ptr);
extern "C" error_t __stdcall lxgetsini(lexer_t *lx, const char *file);
extern "C" const char *__stdcall lxgetserr(
        lexer_t *lx,
        int32 *linenum,
        const char **lineptr,
        int level=0);
extern "C" void __stdcall lxgetstrm(lexer_t *lx, bool del_macros);
lx_preprocessor_cb *set_preprocessor_cb(lexer_t *lx, lx_preprocessor_cb *cb);
lx_pragma_cb *set_pragma_cb(lexer_t *lx, lx_pragma_cb *cb);
lx_macro_cb *set_macro_cb(lexer_t *lx, lx_macro_cb *cb);
void *set_cb_data(lexer_t *lx, void *user_data);
error_t lx_eval(lexer_t *lx, const char *macro, sval_t *answer, lx_resolver_t *cb);
void ce_lxget(lexer_t *lx);
macro_t **extract_macro_table(lexer_t *lx);
void free_macro_table(macro_t **macros);
error_t push_lex_macro(lexer_t *lx, const char *name);
error_t pop_lex_macro(lexer_t *lx, const char *name);
int __stdcall lex_set_cmttype(lexer_t *lx, int lex_cmttype);
void ExprGetError(lexer_t *lx,
                  error_t code,
                  const token_t *ahead,
                  char *buf,
                  size_t bufsize);
typedef const char *__stdcall lxgets_t(lexer_t *lx, error_t *res);
extern "C" const char *__stdcall lxgets(lexer_t *lx, error_t *res);
extern "C" error_t __stdcall line_lxget(lexer_t *lx, token_t *t);
#pragma pack(pop)
#pragma pack(push, 1)
struct MD5Context
{
  uint32 buf[4];
  uint32 bits[2];
  unsigned char in[64];
};
extern "C"  void __stdcall MD5Init(MD5Context *context);
extern "C"  void __stdcall MD5Update(MD5Context *context, const uchar *buf, size_t len);
extern "C"  void __stdcall MD5Final(uchar digest[16], MD5Context *context);
extern "C"  void __stdcall MD5Transform(uint32 buf[4], uint32 const in[16]);
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
const int ST_SIZE = (MAXSPECSIZE/sizeof(uval_t));
class sistack_t;
extern "C" void __stdcall sistack_t_flush(const sistack_t *ss);
class sistack_t
{
  friend void __stdcall sistack_t_flush(const sistack_t *ss);
  uval_t code;
  size_t chunk;
  size_t ptr;
  uval_t cache[ ST_SIZE ];
public:
  sistack_t(void) : code(ea_t(-1)), chunk(0), ptr(0) {}
  ~sistack_t(void)      { if ( code != ea_t(-1) ) flush(); }
  int  attach(const char *name);
  void create(const char *name);
  void kill(void);
  void flush(void)      { sistack_t_flush(this); }
  size_t size(void) const { return chunk*ST_SIZE+ptr; }
  void doempty(void)    { chunk = ptr = 0; }
  void push(uval_t x);
  uval_t pop(void);
  uval_t get(size_t depth);
  uval_t top(void);
  uval_t dup(void)      { uval_t x = top(); push(x); return x; }
protected:
  uval_t netcode(void) const { return code; }
};
#pragma pack(pop)
struct graph_location_info_t
{
  double zoom;
  double orgx;
  double orgy;
  graph_location_info_t(void) : zoom(0), orgx(0), orgy(0) {}
  bool operator == (const graph_location_info_t &r)
    { return zoom == r.zoom && orgx == r.orgx && orgy == r.orgy; }
  bool operator != (const graph_location_info_t &r)
    { return !(*this == r); }
};
class curloc;
class location_t;
extern "C" void __stdcall curloc_linkTo (curloc *, const char *stackName);extern "C" void __stdcall curloc_jump_push(curloc *, bool try_to_unhide, ea_t ea, int lnnum, int x, int y);extern "C" bool __stdcall curloc_pop (curloc *, bool try_tohide);extern "C" bool __stdcall curloc_get (curloc *, size_t depth);extern "C" int __stdcall curloc_mark (curloc *, int marker,const char *title, const char *desc);extern "C" ea_t __stdcall curloc_markedpos(curloc *, int *marker);extern "C" bool __stdcall curloc_jump (curloc *, int marker);extern "C" ssize_t __stdcall curloc_markdesc(curloc *, int marker, char *buf, size_t bufsize);
extern "C" void __stdcall location_linkTo (location_t *, const char *name);extern "C" void __stdcall location_push_and_jump(location_t *, bool try_to_unhide, ea_t ea, int lnnum, int x, int y, const graph_location_info_t *gi);extern "C" bool __stdcall location_pop (location_t *, bool try_tohide);extern "C" bool __stdcall location_get (location_t *, size_t depth);extern "C" int __stdcall location_mark (location_t *, int marker, const char *title, const char *desc);extern "C" bool __stdcall location_jump (location_t *, int marker);
class curloc : public sistack_t
{
  void push(void);
  friend void __stdcall curloc_linkTo (curloc *, const char *stackName);friend void __stdcall curloc_jump_push(curloc *, bool try_to_unhide, ea_t ea, int lnnum, int x, int y);friend bool __stdcall curloc_pop (curloc *, bool try_tohide);friend bool __stdcall curloc_get (curloc *, size_t depth);friend int __stdcall curloc_mark (curloc *, int marker,const char *title, const char *desc);friend ea_t __stdcall curloc_markedpos(curloc *, int *marker);friend bool __stdcall curloc_jump (curloc *, int marker);friend ssize_t __stdcall curloc_markdesc(curloc *, int marker, char *buf, size_t bufsize);
  void unhide_if_necessary(ea_t ea);
  void hide_if_necessary(void);
protected:
  void toup(ea_t _ea) { ea = _ea; lnnum = 0; x = 0; y = 0; flags = 0; target = ea_t(-1); };
public:
  ea_t ea;
  ushort x,y;
  ushort lnnum;
  ushort flags;
  ea_t target;
  curloc(void)                   { ea = target = ea_t(-1); flags = 0; x = 0; y = 0; }
  curloc(const char *stackName)  { linkTo(stackName); }
  void linkTo(const char *stackName)
        { curloc_linkTo(this, stackName); }
  void setx(int xx)              { x  = ushort(xx); }
  void jump_push(bool try_to_unhide, ea_t ea=ea_t(-1), int lnnum=0, int x=0, int y=0)
        { curloc_jump_push(this, try_to_unhide, ea, lnnum, x, y); }
  bool pop(bool try_tohide)
        { return curloc_pop(this, try_tohide); }
  bool get(size_t depth)
        { return curloc_get(this, depth); }
  size_t size(void)               { return sistack_t::size()/4; }
  void copy_current_location(const curloc &loc)
  {
    ea    = loc.ea;
    lnnum = loc.lnnum;
    x     = loc.x;
    y     = loc.y;
  }
  int mark(int marker, const char *title, const char *desc)
        { return curloc_mark(this, marker, title, desc); }
  ea_t markedpos(int *marker)
        { return curloc_markedpos(this, marker); }
  bool jump(int marker)
        { return curloc_jump(this, marker); }
  ssize_t markdesc(int marker, char *buf, size_t bufsize)
        { return curloc_markdesc(this, marker, buf, bufsize); }
};
class location_t : public curloc
{
  typedef curloc inherited;
  friend void __stdcall location_linkTo (location_t *, const char *name);friend void __stdcall location_push_and_jump(location_t *, bool try_to_unhide, ea_t ea, int lnnum, int x, int y, const graph_location_info_t *gi);friend bool __stdcall location_pop (location_t *, bool try_tohide);friend bool __stdcall location_get (location_t *, size_t depth);friend int __stdcall location_mark (location_t *, int marker, const char *title, const char *desc);friend bool __stdcall location_jump (location_t *, int marker);
public:
  graph_location_info_t gli;
  location_t(void) {}
  location_t(const char *name) { linkTo(name); }
  void linkTo(const char *name) { location_linkTo(this, name); }
  void push_and_jump(bool try_to_unhide, ea_t ea=ea_t(-1), int lnnum=0,
                int x=0, int y=0,  graph_location_info_t *gli=0)
    { location_push_and_jump(this, try_to_unhide, ea, lnnum, x, y, gli); }
  bool pop(bool try_tohide)
    { return location_pop(this, try_tohide); }
  bool get(size_t depth)
    { return location_get(this, depth); }
  void copy_current_location(const location_t &loc)
  {
    inherited::copy_current_location(loc);
    gli = loc.gli;
  }
  int mark(int marker, const char *title, const char *desc)
    { return location_mark(this, marker, title, desc); }
  bool jump(int marker)
    { return location_jump(this, marker); }
};
void init_marks(void);
void term_marks(void);
void change_jumps_stack_format(void);
void move_marks(ea_t from, ea_t to, asize_t size);
static const char loc_gtag = 'G';
#pragma pack(pop)
#pragma pack(push, 1)
class func_t;
typedef uchar color_t;
extern "C" char __declspec(dllimport) XlatAsciiName[256];
extern "C" bool __stdcall set_name(ea_t ea,const char *name,int flag);
 bool set_name(ea_t ea,const char *name)
{
  return set_name(ea,name, 0x01);
}
 bool del_global_name(ea_t ea) { return set_name(ea,"", 0x100); }
 bool del_local_name(ea_t ea)  { return set_name(ea,"", 0x200|0x100);}
extern "C" bool __stdcall set_dummy_name(ea_t from, ea_t ea);
extern "C" bool __stdcall make_name_auto(ea_t ea);
extern "C" bool __stdcall make_name_user(ea_t ea);
extern "C" bool __stdcall do_name_anyway(ea_t ea, const char *name, size_t maxlen=0);
extern "C" char *__stdcall validate_name(char *name);
extern "C" bool __stdcall is_ident_char(char c);
extern "C" bool __stdcall is_visible_char(char c);
extern "C" char *__stdcall make_visible_name(char *dstname,
                                          const char *srcname,
                                          size_t dstsize);
extern "C" bool __stdcall isident(const char *name);
extern "C" bool __stdcall is_uname(const char *name);
extern "C" bool __stdcall is_valid_typename(const char *name);
extern "C" ea_t __stdcall dummy_name_ea(const char *name);
extern "C" char *__stdcall extract_name(const char *line,
                                     int x,
                                     char *buf,
                                     size_t bufsize);
extern "C" void __stdcall hide_name(ea_t ea);
extern "C" void __stdcall show_name(ea_t ea);
extern "C" ea_t __stdcall get_name_ea(ea_t from, const char *name);
extern "C" ea_t __stdcall get_name_base_ea(ea_t from, ea_t to);
extern "C" int __stdcall get_name_value(ea_t from,const char *name, uval_t *value);
extern "C" char *__stdcall get_true_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
extern "C" char *__stdcall get_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
extern "C" char *__stdcall get_colored_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
char *get_short_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
char *get_long_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
char *get_colored_short_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
char *get_colored_long_name(ea_t from, ea_t ea, char *buf, size_t bufsize);
extern "C" color_t __stdcall get_name_color(ea_t from, ea_t ea);
extern "C" char *__stdcall get_demangled_name(ea_t from, ea_t ea, char *buf, size_t bufsize,
                         int32 inhibitor, int demform, bool strict);
extern "C" char *__stdcall get_colored_demangled_name(ea_t from,
                                                   ea_t ea,
                                                   char *buf,
                                                   size_t bufsize,
                                                   int32 inhibitor,
                                                   int demform,
                                                   bool strict);
extern "C" ssize_t __stdcall get_name_expr(
        ea_t from,
        int n,
        ea_t ea,
        uval_t off,
        char *buf,
        size_t bufsize,
        int flags=0x0001);
extern "C" ssize_t __stdcall get_nice_colored_name(
        ea_t ea,
        char *buf,
        size_t bufsize,
        int flags=0);
extern "C" flags_t __stdcall append_struct_fields(
                        int n,
                        const tid_t *path,
                        int plen,
                        flags_t flags,
                        char *ptr,
                        char *end,
                        adiff_t *disp,
                        adiff_t delta,
                        bool appzero);
extern "C" int __stdcall get_struct_operand(ea_t ea,
                                         int n,
                                         tid_t *path,
                                         adiff_t *disp,
                                         adiff_t *delta);
extern "C" bool __stdcall is_public_name(ea_t ea);
extern "C" void __stdcall make_name_public(ea_t ea);
extern "C" void __stdcall make_name_non_public(ea_t ea);
extern "C" int __stdcall gen_name_decl(ea_t ea,const char *name);
extern "C" bool __stdcall is_weak_name(ea_t ea);
extern "C" void __stdcall make_name_weak(ea_t ea);
extern "C" void __stdcall make_name_non_weak(ea_t ea);
extern "C" size_t __stdcall get_nlist_size(void);
extern "C" size_t __stdcall get_nlist_idx(ea_t ea);
extern "C" bool __stdcall is_in_nlist(ea_t ea);
extern "C" ea_t __stdcall get_nlist_ea(size_t idx);
extern "C" const char *__stdcall get_nlist_name(size_t idx);
extern "C" void __stdcall rebuild_nlist(void);
extern "C" void __stdcall reorder_dummy_names(void);
enum debug_name_how_t
{
  DEBNAME_EXACT,
  DEBNAME_LOWER,
  DEBNAME_UPPER,
  DEBNAME_NICE,
};
struct ea_name_t
{
  ea_t ea;
  qstring name;
  ea_name_t(void) {}
  ea_name_t(ea_t _ea, const qstring &_name) : ea(_ea), name(_name) {}
};
template <> struct ida_movable_type<ea_name_t> { typedef ida_true_type is_movable_type; };
typedef qvector<ea_name_t> ea_name_vec_t;
extern "C" int  __stdcall set_debug_names(const ea_t *addrs, const char *const *names, int qty);
extern "C" bool __stdcall set_debug_name(ea_t ea, const char *name);
extern "C" bool __stdcall get_debug_name(ea_t *ea_ptr, debug_name_how_t how,
                                                char *buf, size_t bufsize);
extern "C" void __stdcall del_debug_names(ea_t ea1, ea_t ea2);
extern "C" ea_t __stdcall get_debug_name_ea(const char *name);
extern "C" void __stdcall get_debug_names(ea_t ea1, ea_t ea2, ea_name_vec_t &names);
size_t addDummyName(ea_t ea);
void convert_debug_names_to_normal(ea_t ea1, ea_t ea2);
void convert_name_formats(void);
void showhide_name(ea_t ea);
bool clear_lname_bit(ea_t ea, bool setflags);
void fix_new_name(ea_t ea,const char *oldname,const char *newname, bool lname);
bool rename(tid_t id,const char *name);
void move_names(ea_t from, ea_t to, asize_t size);
bool is_noret_name(const char *name);
typedef int ignore_name_def_t;
const ignore_name_def_t
  ignore_none   = 0,
  ignore_regvar = 1,
  ignore_llabel = 2,
  ignore_stkvar = 3,
  ignore_glabel = 4;
extern "C" bool __stdcall is_name_defined_locally(func_t *pfn, const char *name,
                   ignore_name_def_t ignore, ea_t ea1=ea_t(-1), ea_t ea2=ea_t(-1));
extern "C" int32 __stdcall demangle_name(
        char *buf,
        size_t bufsize,
        const char *name,
        uint32 disable_mask);
class Varray;
extern Varray *nameVa;
extern "C" __declspec(dllimport) char NameChars[256];
extern "C" __declspec(dllimport) char MangleChars[256];
 char *get_short_name(ea_t from, ea_t ea, char *buf, size_t bufsize)
{
  return get_demangled_name(from, ea, buf, bufsize,
                    int32(inf.short_demnames), inf.demnames & 3, false);
}
 char *get_long_name(ea_t from,ea_t ea,char *buf, size_t bufsize)
{
  return get_demangled_name(from, ea, buf, bufsize,
                    int32(inf.long_demnames), inf.demnames & 3, false);
}
 char *get_colored_short_name(ea_t from, ea_t ea, char *buf, size_t bufsize)
{
  return get_colored_demangled_name(from, ea, buf, bufsize,
                    int32(inf.short_demnames), inf.demnames & 3, false);
}
 char *get_colored_long_name(ea_t from,ea_t ea,char *buf, size_t bufsize)
{
  return get_colored_demangled_name(from, ea, buf, bufsize,
                    int32(inf.long_demnames), inf.demnames & 3, false);
}
#pragma pack(pop)
#pragma pack(push, 1)
extern "C" bool __stdcall set_offset(ea_t ea, int n, ea_t base);
extern "C" int __stdcall op_offset_ex(ea_t ea, int n, const refinfo_t *ri);
extern "C" int __stdcall op_offset(ea_t ea, int n, reftype_t type, ea_t target=ea_t(-1),
                        ea_t base=0, adiff_t tdelta=0);
extern "C" ea_t __stdcall get_offbase(ea_t ea,int n);
extern "C" int __stdcall get_offset_expression(
                          ea_t ea,
                          int n,
                          ea_t from,
                          adiff_t offset,
                          char *buf,
                          size_t bufsize,
                          int getn_flags=0);
extern "C" int __stdcall get_offset_expr(
                          ea_t ea,
                          int n,
                          refinfo_t &ri,
                          ea_t from,
                          adiff_t offset,
                          char *buf,
                          size_t bufsize,
                          int getn_flags=0);
extern "C" ea_t __stdcall can_be_off32(ea_t ea);
ea_t calc_probable_base(ea_t ea, asize_t itemsize, const uval_t *p_off);
extern "C" ea_t __stdcall calc_probable_base_by_value(ea_t ea, uval_t off);
extern "C" reftype_t __stdcall get_default_reftype(ea_t ea);
extern "C" ea_t __stdcall calc_reference_target(ea_t from, refinfo_t &ri, adiff_t opval);
extern "C" ea_t __stdcall calc_reference_basevalue(ea_t from, refinfo_t &ri, adiff_t opval, ea_t target);
 ea_t calc_target(ea_t from, ea_t ea, int n, adiff_t opval)
{
  refinfo_t ri;
  if ( get_refinfo(ea, n, &ri) )
    return calc_reference_target(from, ri, opval);
  return ea_t(-1);
}
#pragma pack(pop)
#pragma pack(push, 1)
  struct qffblk_t
  {
    long           ff_reserved;
    long           ff_fsize;
    unsigned long  ff_attrib;
    unsigned short ff_ftime;
    unsigned short ff_fdate;
    char           ff_name[260];
  };
extern "C"  int __stdcall qfindfirst(const char *pattern, qffblk_t *blk, int attr);
extern "C"  int __stdcall qfindnext(qffblk_t *blk);
extern "C"  void __stdcall qfindclose(qffblk_t *blk);
#pragma pack(pop)
#pragma pack(push, 1)
typedef uchar qtype_t;
const qtype_t
  Q_noBase  =  1,
  Q_noName  =  2,
  Q_noFop   =  3,
  Q_noComm  =  4,
  Q_noRef   =  5,
  Q_jumps   =  6,
  Q_disasm  =  7,
  Q_head    =  8,
  Q_noValid =  9,
  Q_lines   = 10,
  Q_badstack= 11,
  Q_att     = 12,
  Q_final   = 13,
  Q_rolled  = 14,
  Q_collsn  = 15,
  Q_Qnum    = 16;
extern "C" void __stdcall QueueMark(qtype_t type,ea_t ea);
extern "C" ea_t __stdcall QueueGet(qtype_t *type);
extern "C" ea_t __stdcall QueueGetType(qtype_t type,ea_t lowea);
extern "C" void __stdcall QueueDel(qtype_t type,ea_t ea);
void QueueDel(ea_t ea);
extern "C" const char *__stdcall get_long_queue_name(qtype_t type);
extern "C" const char *__stdcall get_short_queue_name(qtype_t type);
extern "C" bool __stdcall QueueIsPresent(qtype_t t, ea_t ea);
       void init_queue(void);
 void save_queue(void) {}
       void term_queue(void);
void move_problems(ea_t from, ea_t to, asize_t size);
void queue_del(ea_t ea1, ea_t ea2);
void mark_ida_decision(ea_t ea);
void unmark_ida_decision(ea_t ea);
 bool was_ida_decision(ea_t ea) { return QueueIsPresent(Q_final, ea); }
void mark_rollback(ea_t ea, int rollback_type);
int get_rollback_type(ea_t ea);
#pragma pack(pop)
typedef off_t regoff_t;
typedef struct {
        int re_magic;
        size_t re_nsub;
        const char *re_endp;
        struct re_guts *re_g;
} regex_t;
typedef struct {
        regoff_t rm_so;
        regoff_t rm_eo;
} regmatch_t;
extern "C"  int    __stdcall regcomp(regex_t *, const char *, int);
extern "C"  size_t __stdcall regerror(int, const regex_t *, char *, size_t);
extern "C"  int    __stdcall regexec(const regex_t *,const char *, size_t, regmatch_t [], int);
extern "C"  void   __stdcall regfree(regex_t *);
#pragma pack(push, 1)
 bool search_down(int sflag)      { return (sflag & 0x001) != 0; }
extern "C" ea_t __stdcall find_error(ea_t ea, int sflag, int *opnum=0);
extern "C" ea_t __stdcall find_notype(ea_t ea, int sflag, int *opnum=0);
extern "C" ea_t __stdcall find_unknown(ea_t ea,int sflag);
extern "C" ea_t __stdcall find_defined(ea_t ea,int sflag);
extern "C" ea_t __stdcall find_void(ea_t ea,int sflag, int *opnum=0);
extern "C" ea_t __stdcall find_data(ea_t ea,int sflag);
extern "C" ea_t __stdcall find_code(ea_t ea,int sflag);
extern "C" ea_t __stdcall find_not_func(ea_t ea,int sflag);
extern "C" ea_t __stdcall find_imm(ea_t newEA,int sflag, sval_t srchValue, int *opnum=0);
extern "C" ea_t __stdcall find_binary(ea_t startea,
                 ea_t endea,
                 const char *ubinstr,
                 int radix,
                 int sflag);
extern "C" ea_t __stdcall find_text(ea_t startEA, int y, int x, const char *ustr, int sflag);
class place_t;
extern "C" int __stdcall search(
                void *ud,
                place_t *start,
                const place_t *end,
                int *startx,
                const char *str,
                int sflag);
extern "C" int __stdcall user2bin(
                ea_t ea,
                const char *in,
                uchar *out,
                uchar *mask,
                int radix,
                bool unicode);
#pragma pack(pop)
#pragma pack(push, 1)
class segment_t;
class segreg_t : public area_t
{
  sel_t _sRegs[16];
  uchar _tags [16];
public:
        sel_t &reg(int n)       { return _sRegs[n-ph.regFirstSreg]; }
  const sel_t &reg(int n) const { return _sRegs[n-ph.regFirstSreg]; }
        uchar  &tag(int n)       { return _tags [n-ph.regFirstSreg]; }
  const uchar  &tag(int n) const { return _tags [n-ph.regFirstSreg]; }
  void undefregs(void)  { memset(_sRegs,0xFF,sizeof(_sRegs)); }
  void setregs(sel_t Regs[]) { memcpy(_sRegs,Regs,sizeof(_sRegs)); }
  void settags(uchar v) { memset(_tags,v,sizeof(_tags)); }
};
extern "C" areacb_t __declspec(dllimport) SRareas;
class lock_segreg
{
  const segreg_t *sreg;
public:
  lock_segreg(const segreg_t *_sreg) : sreg(_sreg)
  {
    areacb_t_lock_area(&SRareas, sreg);
  }
  ~lock_segreg(void)
  {
    areacb_t_unlock_area(&SRareas, sreg);
  }
};
 bool is_segreg_locked(const segreg_t *sreg)
{
  return areacb_t_get_area_locks(&SRareas, sreg) > 0;
}
extern "C" sel_t __stdcall getSR(ea_t ea,int rg);
extern "C" bool __stdcall SetDefaultRegisterValue(segment_t *sg, int rg, sel_t value);
extern "C" bool __stdcall splitSRarea1(ea_t ea,
                                    int rg,
                                    sel_t v,
                                    uchar tag,
                                    bool silent=false);
extern "C" void __stdcall set_sreg_at_next_code(ea_t ea1, ea_t ea2, int reg, sel_t value);
segreg_t *getSRarea(ea_t ea) { return (segreg_t *)(SRareas.get_area(ea)); }
segreg_t *getnSRarea(int n) { return (segreg_t *)(SRareas.getn_area(n)); }
extern "C" void __stdcall set_default_dataseg(sel_t ds_sel);
int createSRarea(ea_t sEA, ea_t eEA);
int killSRareas(ea_t sEA, ea_t eEA);
int delSRarea(ea_t EA);
int SRareaStart(ea_t sEA, ea_t newstart);
int SRareaEnd(ea_t sEA, ea_t newend);
bool splitSRarea(ea_t sEA);
void SRinit(const char *file);
void SRterm(void);
void SRsave(void);
#pragma pack(pop)
#pragma pack(push, 1)
struct strwinsetup_t
{
  uint32 strtypes;
  sval_t minlen;
  uchar display_only_existing_strings;
  uchar only_7bit;
  uchar ignore_heads;
  ea_t ea1, ea2;
  bool setup_strings_window(void);
  void save_config(void);
  void restore_config(void);
};
struct string_info_t
{
  ea_t ea;
  int length;
  int type;
  string_info_t() : ea(ea_t(-1)), length(0), type(0) { }
  string_info_t(ea_t _ea) : ea(_ea), length(0), type(0) { }
  bool operator<(const string_info_t& string_info) const { return ea < string_info.ea; }
};
template <> struct ida_movable_type<string_info_t> { typedef ida_true_type is_movable_type; };
extern "C" bool __stdcall set_strlist_options(const strwinsetup_t *options);
extern "C" void __stdcall refresh_strlist(ea_t ea1, ea_t ea2);
extern "C" size_t __stdcall get_strlist_qty(void);
extern "C" bool __stdcall get_strlist_item(int n, string_info_t *si);
void move_strings(ea_t from, ea_t to, asize_t size);
#pragma pack(pop)
#pragma pack(push, 1)
struct til_t;
void            init_structs(void);
 void     save_structs(void) {}
void            term_structs(void);
class member_t
{
public:
  tid_t id;
  ea_t soff;
  ea_t eoff;
  flags_t flag;
  uint32 props;
  bool unimem(void)    const { return (props & 0x00000002) != 0; }
  bool has_union(void) const { return (props & 0x00000004) != 0; }
  bool by_til(void)    const { return (props & 0x00000008)  != 0; }
  bool has_ti(void)    const { return (props & 0x00000010)  != 0; }
  ea_t get_soff(void) const { return unimem() ? 0 : soff; }
};
class struc_t
{
public:
  tid_t id;
  size_t memqty;
  member_t *members;
  ushort age;
  uint32 props;
  bool is_varstr(void)    const { return (props & 0x00000001)    != 0; }
  bool is_union(void)     const { return (props & 0x00000002)  != 0; }
  bool has_union(void)    const { return (props & 0x00000004) != 0; }
  bool is_choosable(void) const { return (props & 0x00000008) == 0; }
  bool from_til(void)     const { return (props & 0x00000010) != 0; }
  bool is_hidden(void)    const { return (props & 0x00000020) != 0; }
  mutable int32 ordinal;
};
extern "C" size_t __stdcall get_struc_qty(void);
extern "C" uval_t __stdcall get_first_struc_idx(void);
extern "C" uval_t __stdcall get_last_struc_idx(void);
 uval_t            get_prev_struc_idx(uval_t idx) { return (idx==nodeidx_t(-1)) ? idx : idx - 1; }
extern "C" uval_t __stdcall get_next_struc_idx(uval_t idx);
extern "C" uval_t __stdcall get_struc_idx(tid_t id);
extern "C" tid_t  __stdcall get_struc_by_idx(uval_t idx);
extern "C" struc_t *__stdcall get_struc(tid_t id);
 tid_t get_struc_id(const char *name)
{
  tid_t id = netnode(name);
  return get_struc(id) == 0 ? ea_t(-1) : id;
}
 ssize_t get_struc_name(tid_t id, char *buf, size_t bufsize) { return netnode(id).name(buf, bufsize); }
 ssize_t get_struc_cmt(tid_t id, bool repeatable, char *buf, size_t bufsize) { return netnode(id).supstr(repeatable != 0, buf, bufsize); }
extern "C" asize_t __stdcall get_struc_size(const struc_t *sptr);
 asize_t get_struc_size(tid_t id) { return get_struc_size(get_struc(id)); }
extern "C" ea_t __stdcall get_struc_prev_offset(const struc_t *sptr, ea_t offset);
extern "C" ea_t __stdcall get_struc_next_offset(const struc_t *sptr, ea_t offset);
extern "C" ea_t __stdcall get_struc_last_offset(const struc_t *sptr);
extern "C" ea_t __stdcall get_struc_first_offset(const struc_t *sptr);
 ea_t get_max_offset(struc_t *sptr)
{
  if ( sptr == 0 ) return 0;
  return sptr->is_union()
                ? sptr->memqty
                : get_struc_size(sptr);
}
 bool is_varstr(tid_t id)
{
  struc_t *sptr = get_struc(id);
  return sptr != 0 && sptr->is_varstr();
}
 bool is_union(tid_t id)
{
  struc_t *sptr = get_struc(id);
  return sptr != 0 && sptr->is_union();
}
extern "C" struc_t  *__stdcall get_member_struc(const char *fullname);
extern "C" struc_t  *__stdcall get_sptr(const member_t *mptr);
extern "C" member_t *__stdcall get_member(const struc_t *sptr, asize_t offset);
extern "C" member_t *__stdcall get_member_by_name(const struc_t *sptr,const char *membername);
extern "C" member_t *__stdcall get_member_by_fullname(const char *fullname,struc_t **sptr_place);
 ssize_t __stdcall get_member_fullname(tid_t mid, char *buf, size_t bufsize) { return netnode(mid).name(buf, bufsize); }
extern "C" ssize_t __stdcall get_member_name(tid_t mid, char *buf, size_t bufsize);
 ssize_t __stdcall get_member_cmt(tid_t mid, bool repeatable, char *buf, size_t bufsize) { return netnode(mid).supstr(repeatable != 0, buf, bufsize); }
 asize_t get_member_size(const member_t *mptr)     { return mptr->unimem() ? mptr->eoff : (mptr->eoff - mptr->soff); }
extern "C" bool __stdcall is_varmember(const member_t *mptr);
extern "C" member_t *__stdcall get_best_fit_member(const struc_t *sptr, asize_t offset);
extern "C" ssize_t __stdcall get_next_member_idx(const struc_t *sptr, asize_t off);
extern "C" ssize_t __stdcall get_prev_member_idx(const struc_t *sptr, asize_t off);
extern "C" tid_t __stdcall add_struc(uval_t idx, const char *name, bool is_union=false);
extern "C" void __stdcall del_struc(struc_t *sptr);
extern "C" bool __stdcall set_struc_idx(const struc_t *sptr, uval_t idx);
extern "C" bool __stdcall set_struc_name(tid_t id, const char *name);
extern "C" bool __stdcall set_struc_cmt(tid_t id, const char *cmt, bool repeatable);
extern "C" int __stdcall add_struc_member(
                  struc_t *sptr,
                  const char *fieldname,
                  ea_t offset,
                  flags_t flag,
                  const opinfo_t *mt,
                  asize_t nbytes);
extern "C" bool __stdcall del_struc_member(struc_t *sptr, ea_t offset);
extern "C" int __stdcall del_struc_members(struc_t *sptr, ea_t off1, ea_t off2);
extern "C" bool __stdcall set_member_name(struc_t *sptr, ea_t offset,const char *name);
extern "C" bool __stdcall set_member_type(struc_t *sptr, ea_t offset, flags_t flag,const opinfo_t *mt, asize_t nbytes);
extern "C" bool __stdcall set_member_cmt(member_t* mptr,const char *cmt,bool repeatable);
extern "C" bool __stdcall expand_struc(struc_t *sptr, ea_t offset, adiff_t delta, bool recalc=true);
extern "C" void __stdcall save_struc2(const struc_t *sptr, bool may_update_ltypes=true);
extern "C" bool __stdcall get_member_tinfo(const member_t *mptr, qtype *buf, qtype *fields);
extern "C" bool __stdcall del_member_tinfo(const struc_t *sptr, member_t *mptr);
extern "C" bool __stdcall set_member_tinfo(
        const til_t *til,
        struc_t *sptr,
        member_t *mptr,
        uval_t memoff,
        const type_t *type,
        const p_list *fields,
        int flags);
extern "C" bool __stdcall get_or_guess_member_tinfo(const member_t *mptr, qtype *type, qtype *fields);
 opinfo_t *retrieve_member_info(const member_t *mptr, opinfo_t *buf)
{
  if ( mptr == 0 )
    return 0;
  return get_opinfo(mptr->id, 0, mptr->flag, buf);
}
 bool is_anonymous_member_name(const char *name)
{
  return name == 0
      || strncmp(name, "anonymous", 9) == 0;
}
 bool is_dummy_member_name(const char *name)
{
  return name == 0
      || strncmp(name, "arg_", 4) == 0
      || strncmp(name, "var_", 4) == 0
      || is_anonymous_member_name(name);
}
 bool is_member_id(tid_t mid)
{
  char buf[1024];
  return get_member_fullname(mid, buf, sizeof(buf)) > 0
      && get_member_by_fullname(buf, 0) != 0;
}
extern "C" bool __stdcall is_special_member(tid_t id);
 bool stroff_as_size(int plen, const struc_t *sptr, asize_t value)
{
  return plen == 1
      && value > 0
      && sptr != 0
      && !sptr->is_varstr()
      && value == get_struc_size(sptr);
}
void sync_from_struc(const struc_t *sptr);
extern "C" void __stdcall save_struc(const struc_t *sptr);
extern "C" bool __stdcall get_or_guess_member_type(const member_t *mptr, type_t *type, size_t tsize);
extern "C" bool __stdcall get_member_ti(const member_t *mptr, type_t *buf, size_t bufsize);
extern "C" bool __stdcall set_member_ti(struc_t *sptr, member_t *mptr, const type_t *type, int flags);
 bool del_ti(struc_t *sptr, member_t *mptr) { return set_member_ti(sptr, mptr, (type_t*)"", 0); }
#pragma pack(pop)
#pragma pack(push, 1)
typedef uchar type_t;
typedef uchar p_string;
typedef uchar p_list;
struct til_t;
class lexer_t;
const type_t TYPE_BASE_MASK  = 0x0F;
const type_t TYPE_FLAGS_MASK = 0x30;
const type_t TYPE_MODIF_MASK = 0xC0;
const type_t TYPE_FULL_MASK = (TYPE_BASE_MASK | TYPE_FLAGS_MASK);
const type_t  BT_UNK         = 0x00;
const type_t  BT_VOID        = 0x01;
const type_t    BTMT_SIZE0   = 0x00;
const type_t    BTMT_SIZE12  = 0x10;
const type_t    BTMT_SIZE48  = 0x20;
const type_t    BTMT_SIZE128 = 0x30;
const type_t BT_UNK_BYTE  = (BT_VOID | BTMT_SIZE12);
const type_t BT_UNK_WORD  = (BT_UNK  | BTMT_SIZE12);
const type_t BT_UNK_DWORD = (BT_VOID | BTMT_SIZE48);
const type_t BT_UNK_QWORD = (BT_UNK  | BTMT_SIZE48);
const type_t BT_UNK_OWORD = (BT_VOID | BTMT_SIZE128);
const type_t BT_UNKNOWN   = (BT_UNK  | BTMT_SIZE128);
const type_t BTF_VOID = (BT_VOID | BTMT_SIZE0);
const type_t  BT_INT8        = 0x02;
const type_t  BT_INT16       = 0x03;
const type_t  BT_INT32       = 0x04;
const type_t  BT_INT64       = 0x05;
const type_t  BT_INT128      = 0x06;
const type_t  BT_INT         = 0x07;
const type_t    BTMT_UNKSIGN = 0x00;
const type_t    BTMT_SIGNED  = 0x10;
const type_t    BTMT_USIGNED = 0x20;
const type_t    BTMT_CHAR    = 0x30;
const type_t BT_SEGREG    = (BT_INT | BTMT_CHAR);
const type_t  BT_BOOL        = 0x08;
const type_t    BTMT_DEFBOOL = 0x00;
const type_t    BTMT_BOOL1   = 0x10;
const type_t    BTMT_BOOL2   = 0x20;
const type_t    BTMT_BOOL4   = 0x30;
const type_t  BT_FLOAT       = 0x09;
const type_t    BTMT_FLOAT   = 0x00;
const type_t    BTMT_DOUBLE  = 0x10;
const type_t    BTMT_LNGDBL  = 0x20;
const type_t    BTMT_SPECFLT = 0x30;
const type_t _BT_LAST_BASIC  = BT_FLOAT;
const type_t  BT_PTR         = 0x0A;
const type_t    BTMT_DEFPTR  = 0x00;
const type_t    BTMT_NEAR    = 0x10;
const type_t    BTMT_FAR     = 0x20;
const type_t    BTMT_CLOSURE = 0x30;
const type_t  BT_ARRAY       = 0x0B;
const type_t    BTMT_NONBASED= 0x10;
const type_t    BTMT_ARRESERV= 0x20;
const type_t  BT_FUNC        = 0x0C;
const type_t    BTMT_DEFCALL  = 0x00;
const type_t    BTMT_NEARCALL = 0x10;
const type_t    BTMT_FARCALL  = 0x20;
const type_t    BTMT_INTCALL  = 0x30;
const type_t  BT_COMPLEX     = 0x0D;
const type_t    BTMT_STRUCT  = 0x00;
const type_t    BTMT_UNION   = 0x10;
const type_t    BTMT_ENUM    = 0x20;
const type_t    BTMT_TYPEDEF = 0x30;
const type_t BT_BITFIELD     = 0x0E;
const type_t BTMT_BFLDI8    = 0x00;
const type_t BTMT_BFLDI16   = 0x10;
const type_t BTMT_BFLDI32   = 0x20;
const type_t BTMT_BFLDI64   = 0x30;
const type_t BT_RESERVED     = 0x0F;
const type_t BTF_STRUCT  = (BT_COMPLEX | BTMT_STRUCT);
const type_t BTF_UNION   = (BT_COMPLEX | BTMT_UNION);
const type_t BTF_ENUM    = (BT_COMPLEX | BTMT_ENUM);
const type_t BTF_TYPEDEF = (BT_COMPLEX | BTMT_TYPEDEF);
const type_t  BTM_CONST      = 0x40;
const type_t  BTM_VOLATILE   = 0x80;
typedef uchar bte_t;
const bte_t   BTE_SIZE_MASK = 0x07;
const bte_t   BTE_RESERVED    = 0x08;
const bte_t   BTE_BITFIELD    = 0x10;
const bte_t   BTE_OUT_MASK  = 0x60;
const bte_t   BTE_HEX         = 0x00;
const bte_t   BTE_CHAR        = 0x20;
const bte_t   BTE_SDEC        = 0x40;
const bte_t   BTE_UDEC        = 0x60;
const bte_t   BTE_ALWAYS    = 0x80;
 bool is_type_const(type_t t)   { return (t & BTM_CONST) != 0; }
 bool is_type_volatile(type_t t){ return (t & BTM_VOLATILE) != 0; }
 type_t get_base_type(type_t t) { return (t & TYPE_BASE_MASK); }
 type_t get_type_flags(type_t t){ return (t & TYPE_FLAGS_MASK); }
 type_t get_full_type(type_t t) { return (t & TYPE_FULL_MASK); }
 bool is_typeid_last(type_t t)  { return(get_base_type(t) <= _BT_LAST_BASIC); }
 bool is_type_partial(type_t t) { return(get_base_type(t) <= BT_VOID) && get_type_flags(t) != 0; }
 bool is_type_void(type_t t)    { return(get_full_type(t) == BTF_VOID); }
 bool is_type_unknown(type_t t) { return(get_full_type(t) == BT_UNKNOWN); }
 bool is_type_ptr(type_t t)     { return(get_base_type(t) == BT_PTR); }
 bool is_type_complex(type_t t) { return(get_base_type(t) == BT_COMPLEX); }
 bool is_type_func(type_t t)    { return(get_base_type(t) == BT_FUNC); }
 bool is_type_array(type_t t)   { return(get_base_type(t) == BT_ARRAY); }
 bool is_type_typedef(type_t t) { return(get_full_type(t) == BTF_TYPEDEF); }
 bool is_type_sue(type_t t)     { return is_type_complex(t) && !is_type_typedef(t); }
 bool is_type_struct(type_t t)  { return(get_full_type(t) == BTF_STRUCT); }
 bool is_type_union(type_t t)   { return(get_full_type(t) == BTF_UNION); }
 bool is_type_struni(type_t t)  { return(is_type_struct(t) || is_type_union(t)); }
 bool is_type_enum(type_t t)    { return(get_full_type(t) == BTF_ENUM); }
 bool is_type_bitfld(type_t t)  { return(get_base_type(t) == BT_BITFIELD); }
 bool is_type_int64(const type_t t)
{
  return get_full_type(t) == (BT_INT64|BTMT_UNKSIGN)
      || get_full_type(t) == (BT_INT64|BTMT_SIGNED);
}
 bool is_type_long(const type_t t)
{
  return get_full_type(t) == (BT_INT32|BTMT_UNKSIGN)
      || get_full_type(t) == (BT_INT32|BTMT_SIGNED);
}
 bool is_type_short(const type_t t)
{
  return get_full_type(t) == (BT_INT16|BTMT_UNKSIGN)
      || get_full_type(t) == (BT_INT16|BTMT_SIGNED);
}
 bool is_type_char(const type_t t)
{
  return get_full_type(t) == (BT_INT8|BTMT_CHAR)
      || get_full_type(t) == (BT_INT8|BTMT_SIGNED);
}
 bool is_type_uint(const type_t t)   { return get_full_type(t) == (BT_INT|BTMT_USIGNED); }
 bool is_type_uchar(const type_t t)  { return get_full_type(t) == (BT_INT8|BTMT_USIGNED); }
 bool is_type_ushort(const type_t t) { return get_full_type(t) == (BT_INT16|BTMT_USIGNED); }
 bool is_type_ulong(const type_t t)  { return get_full_type(t) == (BT_INT32|BTMT_USIGNED); }
 bool is_type_uint64(const type_t t) { return get_full_type(t) == (BT_INT64|BTMT_USIGNED); }
 bool is_type_ldouble(const type_t t){ return get_full_type(t) == (BT_FLOAT|BTMT_LNGDBL); }
 bool is_type_double(const type_t t) { return get_full_type(t) == (BT_FLOAT|BTMT_DOUBLE); }
 bool is_type_float(const type_t t)  { return get_full_type(t) == (BT_FLOAT|BTMT_FLOAT); }
 bool is_type_floating(const type_t t){return get_base_type(t) == BT_FLOAT; }
 bool is_type_bool(const type_t t)   { return get_base_type(t) == BT_BOOL; }
 bool is_type_sdacl(type_t t)
    { return(((t & ~TYPE_FLAGS_MASK) ^ TYPE_MODIF_MASK) <= BT_VOID); }
 int sdacl_unpack(type_t t)
    { return(((t & TYPE_FLAGS_MASK) >> 3) | (t & 1)); }
 int sdacl_pack(int algn)
    { return((((algn & 6) << 3) | (algn & 1)) | TYPE_MODIF_MASK); }
extern "C" type_t *__stdcall set_argloc(type_t *pt, int reg, int reghi=-1, bool ret=false);
extern "C" type_t *__stdcall set_spoils(type_t *pt, uint reg, uint size);
 unsigned get_spoil_cnt(type_t t) { return (unsigned)t & 0xF; }
extern "C" type_t *__stdcall set_dt(type_t *pt, int value);
extern "C" type_t *__stdcall set_da(type_t *pt, uint32 num_el, uint32 base = 0);
extern "C" type_t *__stdcall set_de(type_t *pt, uint32 val);
extern "C" int  __stdcall get_dt(const type_t * &pt);
extern "C" bool __stdcall get_da(const type_t * &pt, uint32 *num_el, uint32 *base);
extern "C" bool __stdcall get_de(const type_t * &pt, uint32 *val);
extern "C" bool __stdcall append_dt(qtype *type, int n);
extern "C" bool __stdcall append_de(qtype *type, uint32 n);
extern "C" bool __stdcall append_da(qtype *type, uint32 n1, uint32 n2);
extern "C" bool __stdcall append_name(qtype *fields, const char *name);
 const type_t *skip_ptr_type_header(const type_t *type)
{
  if ( get_type_flags(*type++) == BTMT_CLOSURE
    && *type++ == 0xFF )
  {
    type++;
  }
  return type;
}
 const type_t *skip_array_type_header(const type_t *type)
{
  if ( get_type_flags(*type++) & BTMT_NONBASED )
  {
    int n = get_dt(type);
    if ( n < 0 )
      type = 0;
  }
  else
  {
    uint32 num, base;
    if ( !get_da(type, &num, &base) )
      type = 0;
  }
  return type;
}
 type_t *skip_ptr_type_header(type_t *type) { return const_cast<type_t *>(skip_ptr_type_header((const type_t *)type)); }
 type_t *skip_array_type_header(type_t *type) { return const_cast<type_t *>(skip_array_type_header((const type_t *)type)); }
 type_t *typend(const type_t *ptr)  { return (type_t *)strchr((char *)ptr, '\0'); }
 size_t typlen(const type_t *ptr)  { return strlen((const char *)ptr); }
 type_t *typncpy(type_t *dst, const type_t *src, size_t size)
        { return (type_t *)::qstrncpy((char *)dst, (const char *)src, size); }
 type_t *tppncpy(type_t *dst, const type_t *src, size_t size)
        { return (type_t *)::qstpncpy((char *)dst, (const char *)src, size); }
 int     typcmp(const type_t *dst, const type_t *src)
        { return strcmp((const char *)dst, (const char *)src); }
 int     typncmp(const type_t *dst, const type_t *src, size_t size)
        { return strncmp((const char *)dst, (const char *)src, size); }
 type_t *typdup(const type_t *src)
        { return (type_t *)::qstrdup((const char *)src); }
extern "C" bool __stdcall equal_types(const til_t *ti, const type_t *t1, const type_t *t2);
extern "C" const type_t *__stdcall resolve_typedef2(
        const til_t *ti,
        const type_t *p,
        const p_list **fields=0,
        char *namebuf=0);
extern "C" bool __stdcall is_type_resolvable(const type_t *p, char *namebuf=0);
extern "C" bool __stdcall is_restype_const  (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_void   (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_ptr    (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_func   (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_array  (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_complex(const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_struct (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_union  (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_struni (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_enum   (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_restype_bitfld (const til_t *til, const type_t *type);
extern "C" bool __stdcall is_castable2(const til_t *til, const type_t *from, const type_t *to);
extern "C" bool __stdcall remove_constness(type_t *type);
extern "C" bool __stdcall remove_type_pointer(
        const til_t *til,
        const type_t **ptype,
        const char **pname);
extern "C" bool __stdcall build_array_type(
        qtype *outtype,
        const type_t *type,
        int size);
extern "C" type_t __stdcall get_int_type_bit(int size);
extern "C" type_t __stdcall get_unk_type_bit(int size);
struct type_names_t
{
  const char
        *type_void,
        *type_int8,
        *type_int16,
        *type_int32,
        *type_int64,
        *type_int128,
        *type_char,
        *type_int,
        *type_bool,
        *type_float,
        *type_double,
        *type_longdouble,
        *type_shortfloat,
        *type_seg,
        *type_unknown,
        *type_byte,
        *type_word,
        *type_dword,
        *type_qword,
        *type_oword,
        *type_tbyte,
        *type_signed,
        *type_unsigned,
        *cc_cdecl,
        *cc_stdcall,
        *cc_pascal,
        *cc_fastcall,
        *cc_thiscall,
        *cc_manual,
        *cc_specialp,
        *cc_special;
};
extern type_names_t  type_names;
struct til_t
{
  char *name;
  char *desc;
  int nbases;
  struct til_t **base;
  uint32 flags;
   bool is_dirty(void) const { return (flags & 0x0040) != 0; }
   void set_dirty(void) { flags |= 0x0040; }
  compiler_info_t cc;
  struct til_bucket_t *syms;
  struct til_bucket_t *types;
  struct til_bucket_t *macros;
  int nrefs;
  int nstreams;
  struct til_stream_t **streams;
  til_t(void) { memset(this, 0, sizeof(*this)); }
};
struct til_symbol_t
{
  const char *name;
  const til_t *til;
  til_symbol_t(const char *n = 0, const til_t *t = 0): name(n), til(t) {};
};
template <> struct ida_movable_type<til_symbol_t> { typedef ida_true_type is_movable_type; };
extern "C" til_t *__stdcall new_til(const char *name, const char *desc);
int add_base_tils(til_t *ti, const char *tildir, const char *bases, char *errbuf, size_t bufsize);
extern "C" til_t *__stdcall load_til(const char *tildir, const char *name, char *errbuf, size_t bufsize);
extern "C" bool __stdcall sort_til(til_t *ti);
extern "C" bool __stdcall compact_til(til_t *ti);
extern "C" bool __stdcall store_til(til_t *ti, const char *tildir, const char *name);
extern "C" void __stdcall free_til(til_t *ti);
extern "C" til_t *__stdcall load_til_header(const char *tildir, const char *name, char *errbuf, size_t bufsize);
void til_add_macro(til_t *ti, const char *name, const char *body, int nargs, bool isfunc);
bool til_next_macro(const til_t *ti, const char **current, const char **body, int *nargs, bool *isfunc);
extern "C" size_t __stdcall get_type_size(const til_t *ti, const type_t * &ptr, size_t *lp = 0);
 size_t get_type_size0(const til_t *ti, const type_t *ptr, size_t *lp = 0)
{
  return get_type_size(ti, ptr, lp);
}
extern "C" const type_t *__stdcall skip_type(const til_t *ti, const type_t *&ptr);
 bool check_skip_type(const til_t *ti, const type_t *&ptr)
{
  return skip_type(ti, ptr) != 0;
}
 bool is_valid_full_type(const til_t *ti, const type_t *&ptr)
{
  return skip_type(ti, ptr) != 0 && *ptr == '\0';
}
extern "C" ssize_t __stdcall get_ptr_object_size(const til_t *til, const type_t *type);
extern "C" size_t __stdcall get_funcarg_size(const til_t *til, const type_t *&type, size_t *lp=0);
const size_t BADSIZE = size_t(-1);
struct descr_t
{
  const   p_list *Names;
  const   p_list *Cmts;
};
typedef bool (__stdcall*tcbfn)(
        void *cb_data,
        int level,
        const char *str,
        const char *cmt);
extern "C" int __stdcall unpack_type(
        const til_t *ti,
        const type_t *pt,
        tcbfn cb_func,
        void  *cb_data,
        const char *name = 0,
        const char *cmt = 0,
        const descr_t *Descr = 0,
        unsigned int flags=0);
extern "C" int __stdcall print_type_to_one_line(
        char  *buf,
        size_t bufsize,
        const til_t *ti,
        const type_t *pt,
        const char *name = 0,
        const char *cmt = 0,
        const p_list *field_names = 0,
        const p_list *field_cmts = 0);
extern "C" int __stdcall print_type_to_many_lines(
        bool (__stdcall*printer)(void *cbdata, const char *buf),
        void *cbdata,
        const char *prefix,
        int indent,
        int cmtindent,
        const til_t *ti,
        const type_t *pt,
        const char *name = 0,
        const char *cmt = 0,
        const p_list *field_names = 0,
        const p_list *field_cmts = 0);
extern "C" ssize_t __stdcall print_type_to_qstring(
        qstring *result,
        const char *prefix,
        int indent,
        int cmtindent,
        int flags,
        const til_t *ti,
        const type_t *pt,
        const char *name=0,
        const char *cmt=0,
        const p_list *field_names=0,
        const p_list *field_cmts=0);
extern "C" bool __stdcall print_type(ea_t ea, char *buf, size_t bufsize, bool one_line);
void show_type(int (*print_cb)(const char *format, ...),
               const type_t *ptr);
void show_plist(int (*print_cb)(const char *format, ...),
                const char *header,
                const p_list *list);
const p_list *skip_function_arg_names(const til_t *til, const type_t *type, const p_list *fields);
bool perform_funcarg_conversion(const til_t *til, qtype &type);
bool get_argloc_info(
        const til_t *til,
        const type_t *func,
        const type_t *type,
        cm_t cc,
        uint32 *arglocs,
        size_t n);
const cm_t CM_MASK = 0x03;
const cm_t  CM_UNKNOWN   = 0x00;
const cm_t  CM_N8_F16    = 0x01;
const cm_t  CM_N64       = 0x01;
const cm_t  CM_N16_F32   = 0x02;
const cm_t  CM_N32_F48   = 0x03;
const cm_t CM_M_MASK = 0x0C;
const cm_t  CM_M_NN      = 0x00;
const cm_t  CM_M_FF      = 0x04;
const cm_t  CM_M_NF      = 0x08;
const cm_t  CM_M_FN      = 0x0C;
 bool is_code_far(cm_t cm) { return((cm & 4) != 0); }
 bool is_data_far(cm_t cm) { return((cm &= CM_M_MASK) && cm != CM_M_FN); }
const cm_t CM_CC_MASK = 0xF0;
const cm_t  CM_CC_INVALID  = 0x00;
const cm_t  CM_CC_UNKNOWN  = 0x10;
const cm_t  CM_CC_VOIDARG  = 0x20;
const cm_t  CM_CC_CDECL    = 0x30;
const cm_t  CM_CC_ELLIPSIS = 0x40;
const cm_t  CM_CC_STDCALL  = 0x50;
const cm_t  CM_CC_PASCAL   = 0x60;
const cm_t  CM_CC_FASTCALL = 0x70;
const cm_t  CM_CC_THISCALL = 0x80;
const cm_t  CM_CC_MANUAL   = 0x90;
const cm_t  CM_CC_SPOILED  = 0xA0;
const cm_t  CM_CC_RESERVE4 = 0xB0;
const cm_t  CM_CC_RESERVE3 = 0xC0;
const cm_t  CM_CC_SPECIALE = 0xD0;
const cm_t  CM_CC_SPECIALP = 0xE0;
const cm_t  CM_CC_SPECIAL  = 0xF0;
typedef uint32 argloc_t;
typedef qvector<argloc_t> arglocvec_t;
 bool is_reg_argloc(uint32 argloc) { return (argloc & 0x80000000L) != 0; }
 bool is_stack_argloc(uint32 argloc) { return !is_reg_argloc(argloc); }
 bool is_reg2_argloc(uint32 reg_argloc) { return (reg_argloc & 0x40000000L) != 0; }
 int get_argloc_r1(uint32 reg_argloc) { return (reg_argloc & 0x7FFF); }
 int get_argloc_r2(uint32 reg_argloc) { return (reg_argloc >> 15) & 0x7FFF; }
 argloc_t make_argloc(int r1, int r2)
{
  argloc_t a = 0;
  if ( r1 != -1 ) a |= 0x80000000L | r1;
  if ( r2 != -1 ) a |= 0x40000000L | (r2 << 15);
  return a;
}
 void split_argloc(argloc_t al, int *r1, int *r2)
{
  if ( is_reg_argloc(al) )
  {
    *r1 = get_argloc_r1(al);
    *r2 = is_reg2_argloc(al) ? get_argloc_r2(al) : -1;
  }
  else
  {
    *r1 = -1;
    *r2 = -1;
  }
}
 void extract_argloc(const type_t *&ptr, int *p1, int *p2)
{
  type_t high = *ptr++;
  *p1 = (high & 0x7F) - 1;
  if ( high > 0x80 )
    *p2 = *ptr++ - 1;
  else
    *p2 = -1;
}
 argloc_t extract_argloc(const type_t *&ptr)
{
  int p1, p2;
  extract_argloc(ptr, &p1, &p2);
  return make_argloc(p1, p2);
}
 uint32 extract_and_convert_argloc(const type_t *&tp)
{
  int r1, r2;
  extract_argloc(tp, &r1, &r2);
  if ( r1 == -1 )
    return 0;
  return make_argloc(r1, r2);
}
 void extract_spoiledreg(const type_t *&ptr, uchar *reg, uchar *len)
{
  type_t t = *ptr++;
  if ( !(t & 0x80) ) {
    *len = uchar(1 + (t >> 4));
    *reg = uchar((t & (uchar)0xF) - 1);
  } else {
    *len = *ptr++;
    *reg = uchar(t & 0x7F);
  }
}
extern "C" const type_t *__stdcall skip_spoiled_info(const type_t *ptr);
const cm_t C_PC_TINY    = (CM_N16_F32 | CM_M_NN);
const cm_t C_PC_SMALL   = (CM_N16_F32 | CM_M_NN);
const cm_t C_PC_COMPACT = (CM_N16_F32 | CM_M_NF);
const cm_t C_PC_MEDIUM  = (CM_N16_F32 | CM_M_FN);
const cm_t C_PC_LARGE   = (CM_N16_F32 | CM_M_FF);
const cm_t C_PC_HUGE    = (CM_N16_F32 | CM_M_FF);
const cm_t C_PC_FLAT    = (CM_N32_F48 | CM_M_NN);
 cm_t get_cc (cm_t cm) { return(cm & CM_CC_MASK); }
 bool is_user_cc(cm_t cm)
{
  cm_t cc = get_cc(cm);
  return cc >= CM_CC_SPECIALE;
}
 bool is_vararg_cc(cm_t cm)
{
  cm_t cc = get_cc(cm);
  return cc == CM_CC_ELLIPSIS || cc == CM_CC_SPECIALE;
}
 bool is_purging_cc(cm_t cm)
{
  cm_t cc = get_cc(cm);
  return cc == CM_CC_STDCALL || cc == CM_CC_PASCAL || cc == CM_CC_SPECIALP || cc == CM_CC_FASTCALL || cc == CM_CC_THISCALL;
}
const comp_t COMP_MASK   = 0x0F;
const comp_t  COMP_UNK     = 0x00;
const comp_t  COMP_MS      = 0x01;
const comp_t  COMP_BC      = 0x02;
const comp_t  COMP_WATCOM  = 0x03;
const comp_t  COMP_GNU     = 0x06;
const comp_t  COMP_VISAGE  = 0x07;
const comp_t  COMP_BP      = 0x08;
const comp_t  COMP_UNSURE  = 0x80;
 comp_t get_comp(comp_t comp) { return(comp & COMP_MASK); }
extern "C" const char *__stdcall get_compiler_name(comp_t id);
 comp_t is_comp_unsure(comp_t comp) { return(comp & COMP_UNSURE); }
 comp_t default_compiler(void) { return(get_comp(inf.cc.id)); }
extern "C" bool __stdcall set_compiler(const compiler_info_t &cc, int flags);
 bool __stdcall set_compiler_id(comp_t id)
{
  compiler_info_t cc;
  cc.id = id;
  return set_compiler(cc, 0x0002);
}
comp_t get_compiler_id(char c);
extern "C" bool __stdcall extract_pstr(const p_list * &pt, char *buff, size_t buff_sz);
 bool extract_name(const p_list *&pt, char *buff)   { return extract_pstr(pt, buff, 512); }
 bool skipName(const p_list *&pt)                   { return extract_name(pt, 0); }
 bool extract_comment(const p_list *&pt, char *buff){ return extract_pstr(pt, buff, 1024); }
 bool skipComment(const p_list *&pt)                { return extract_comment(pt, 0); }
 bool extract_fargcmt(const p_list *&pt, char *buff){ return extract_pstr(pt, buff, 64); }
 void skip_argloc(const type_t *&ptr)               { if ( *ptr++ > 0x80 ) ptr++; }
enum abs_t    { abs_unk, abs_no, abs_yes };
enum sclass_t
{
  sc_unk,
  sc_type,
  sc_ext,
  sc_stat,
  sc_reg,
  sc_auto,
  sc_friend,
  sc_virt
};
typedef int __stdcall h2ti_type_cb(
     const char *name,
     const type_t *type,
     const char *cmt,
     const p_list *field_names,
     const p_list *field_cmts,
     const uint32 *value,
     void *cb_data);
typedef  int printer_t(const char *format, ...);
extern "C" int __stdcall h2ti(
         til_t *ti,
         lexer_t *lx,
         const char *input,
         int flags=0,
         h2ti_type_cb *type_cb=0,
         h2ti_type_cb *var_cb=0,
         printer_t *print_cb=0,
         void *_cb_data=0,
         abs_t _isabs=abs_unk);
 void h2ti_warning(void *parser, const char *format, ...);
extern "C" bool __stdcall parse_decl(
        til_t *til,
        const char *decl,
        qstring *name,
        qtype *type,
        qtype *fields,
        int flags);
extern "C" int __stdcall parse_decls(
        til_t *til,
        const char *input,
        printer_t *printer,
        int hti_flags);
extern "C" int __stdcall get_named_type(
        const til_t *ti,
        const char *name,
        int ntf_flags,
        const type_t **type=0,
        const p_list **fields=0,
        const char **cmt=0,
        const p_list **fieldcmts=0,
        sclass_t *sclass=0,
        uint32 *value=0);
extern "C" bool __stdcall set_named_type(
        til_t *ti,
        const char *name,
        int ntf_flags,
        const type_t *ptr,
        const p_list *fields=0,
        const char *cmt=0,
        const p_list *fieldcmts=0,
        const sclass_t *sclass=0,
        const uint32 *value=0);
extern "C" size_t __stdcall get_named_type_size(
        const til_t *ti,
        const char *name,
        int ntf_flags,
        size_t *lp = 0);
extern "C" bool __stdcall del_named_type(til_t *ti, const char *name, int ntf_flags);
extern "C" int __stdcall rename_named_type(til_t *ti, const char *from, const char *to, int ntf_flags);
extern "C" const char *__stdcall first_named_type(const til_t *ti, int ntf_flags);
extern "C" const char *__stdcall next_named_type(const til_t *ti, const char *name, int ntf_flags);
 bool decorate_name(
        const til_t *ti,
        const char *name,
        const type_t *type,
        char *outbuf,
        size_t bufsize,
        bool mangle,
        cm_t cc=0)
{
  if ( !ph.ti() )
    return false;
  return ph.notify(ph.decorate_name, ti, name,
                        type, outbuf, bufsize, mangle, cc) != 0;
}
extern "C" bool __stdcall gen_decorate_name(
        const til_t *ti,
        const char *name,
        const type_t *type,
        char *outbuf,
        size_t bufsize,
        bool mangle,
        cm_t cc);
extern "C" bool __stdcall calc_bare_name(
        const char *name,
        const type_t *type,
        char *buf,
        size_t bufsize);
typedef bool __stdcall predicate_t(const char *name, const type_t *type, const p_list *fields);
extern "C" bool __stdcall choose_named_type2(
                const til_t *root_til,
                const char *title,
                int ntf_flags,
                predicate_t *func,
                til_symbol_t* sym);
extern "C" const char *__stdcall choose_named_type(
                const til_t *root_til,
                const char *title,
                int ntf_flags,
                predicate_t *func);
typedef int __stdcall local_predicate_t(uint32 ord, const type_t *type, const p_list *fields, void *ud);
extern "C" uint32 __stdcall choose_local_type(
                const til_t *ti,
                const char *title,
                local_predicate_t *func,
                void *ud);
bool enable_numbered_types(til_t *ti, bool enable);
extern "C" bool __stdcall get_numbered_type(
        const til_t *ti,
        uint32 ordinal,
        const type_t **type=0,
        const p_list **fields=0,
        const char **cmt=0,
        const p_list **fieldcmts=0,
        sclass_t *sclass=0);
extern "C" uint32 __stdcall alloc_type_ordinals(til_t *ti, int qty);
 uint32 alloc_type_ordinal(til_t *ti) { return alloc_type_ordinals(ti, 1); }
extern "C" uint32 __stdcall get_ordinal_qty(const til_t *ti);
extern "C" bool __stdcall set_numbered_type(
        til_t *ti,
        uint32 ordinal,
        int ntf_flags,
        const char *name,
        const type_t *type,
        const p_list *fields=0,
        const char *cmt=0,
        const p_list *fldcmts=0,
        const sclass_t *sclass=0);
extern "C" bool __stdcall del_numbered_type(til_t *ti, uint32 ordinal);
extern "C" bool __stdcall set_type_alias(til_t *ti, uint32 src_ordinal, uint32 dst_ordinal);
extern "C" uint32 __stdcall get_alias_target(const til_t *ti, uint32 ordinal);
 int32 get_type_ordinal(const til_t *ti, const char *name)
{
  uint32 ordinal = 0;
  get_named_type(ti, name, 0x0001|0x0002, 0, 0, 0, 0, 0, &ordinal);
  return ordinal;
}
extern "C" const char *__stdcall get_numbered_type_name(const til_t *ti, uint32 ordinal);
extern "C" size_t __stdcall create_numbered_type_name(int32 ord, char *buf, size_t bufsize);
 bool is_ordinal_name(const char *name, uint32 *ord)
{
  if ( name[0] != '#' )
    return false;
  const type_t *ptr = (const type_t *)name + 1;
  return get_de(ptr, ord);
}
extern "C" int __stdcall get_ordinal_from_idb_type(const char *name, const type_t *type);
 bool __stdcall is_autosync(const char *name, const type_t *type)
{
  return get_ordinal_from_idb_type(name, type) != -1;
}
extern "C" void __stdcall build_anon_type_name(
        char *buf,
        size_t bufsize,
        const type_t *type,
        const p_list *fields);
 size_t get_default_align(cm_t) { return inf.cc.defalign; }
 void align_size(size_t &size, size_t algn)
  { if ( size && (int)--algn > 0) size = (size + algn ) & ~algn; }
 void align_size(size_t &cur_tot_size, size_t elem_size, size_t algn)
    { align_size(cur_tot_size, ((elem_size) < (algn)? (elem_size): (algn))); }
 size_t get_default_enum_size(cm_t cm)
  { return ph.ti() ? ph.notify(ph.get_default_enum_size, cm) : 0; }
 int max_ptr_size(void) { return ph.notify(ph.max_ptr_size)-1; }
 const char *__stdcall based_ptr_name_and_size(unsigned ptrt, size_t &size)
{
  if ( !ph.ti() )
    return 0;
  const char *ptrname;
  size = ph.notify(ph.based_ptr, ptrt, &ptrname);
  return ptrname;
}
extern "C" bool __stdcall deref_ptr(
        const til_t *ti,
        const type_t *type,
        ea_t *ptr_ea,
        ea_t *closure_obj=0);
extern "C" int __stdcall calc_argloc_info(
        const til_t *til,
        const type_t *type,
        uint32 *arglocs,
        size_t maxn);
 int get_stkarg_offset(void)
{
  if ( !ph.ti() )
    return 0;
  return ph.notify(ph.get_stkarg_offset2) - 2;
}
struct type_visitor_t
{
  virtual int __stdcall visit_type(const type_t *type) = 0;
  virtual __stdcall ~type_visitor_t(void) {}
};
extern "C" int __stdcall for_all_types(const type_t **ptype, type_visitor_t &tv);
struct type_pair_t
{
  qtype type1;
  qtype type2;
  type_pair_t(void) {}
  type_pair_t(const qtype &l) : type1(l) {}
  type_pair_t(const qtype &l, const qtype &g) : type1(l), type2(g) {}
};
struct type_pair_vec_t : qvector<type_pair_t>
{
  void add_names(const qstring &name1, const qstring &name2);
};
extern "C" int __stdcall replace_subtypes(qtype &type, const type_pair_vec_t &type_pairs);
extern "C" tid_t __stdcall import_type(const til_t *til, int idx, const char *name, int flags=0);
extern "C" int __stdcall add_til2(const char *name, int flags);
extern "C" bool __stdcall del_til(const char *name);
extern "C" bool __stdcall apply_named_type(ea_t ea, const char *name);
extern "C" bool __stdcall apply_tinfo(
        const til_t *til,
        ea_t ea,
        const type_t *type,
        const p_list *fields,
        int userti);
extern "C" bool __stdcall apply_cdecl2(til_t *til, ea_t ea, const char *decl, int flags=0);
extern "C" void __stdcall apply_callee_type(
        ea_t caller,
        const type_t *type,
        const p_list *fields);
extern "C" bool __stdcall apply_once_type_and_name(ea_t ea, const type_t *type, const char *name);
extern "C" int __stdcall guess_func_tinfo(func_t *pfn, qtype *type, qtype *fields);
extern "C" int __stdcall guess_tinfo(tid_t id, qtype *type, qtype *fields);
 void set_c_header_path(const char *incdir)           { RootNode.supset(65, incdir); }
 ssize_t get_c_header_path(char *buf, size_t bufsize) { return RootNode.supstr(65, buf, bufsize); }
 void set_c_macros(const char *macros)                { RootNode.supset(66, macros); }
 ssize_t get_c_macros(char *buf, size_t bufsize)      { return RootNode.supstr(66, buf, bufsize); }
extern "C" __declspec(dllimport) til_t *idati;
void init_til(bool newfile);
void save_til(void);
void term_til(void);
void determine_til(void);
void sync_from_til(const til_t *ti, const char *oname, const char *name, const type_t *type);
extern "C" char *__stdcall get_tilpath(char *tilbuf, size_t tilbufsize);
void autoload_til(const char *cfgfname, const char *sigfname);
extern "C" bool __stdcall get_idainfo_by_type2(
        const til_t *til,
        const type_t *&rtype,
        const p_list *fields,
        size_t *psize,
        flags_t *pflags,
        opinfo_t *mt,
        size_t *alsize=0);
void apply_callee_type(ea_t caller, ea_t callee);
void propagate_stkargs(void);
struct funcarg_info_t
{
  argloc_t argloc;
  qstring name;
  qtype type;
  qtype fields;
  funcarg_info_t(): argloc(0) {};
};
struct func_type_info_t : public qvector<funcarg_info_t>
{
  int flags;
  qtype rettype;
  qtype retfields;
  argloc_t retloc;
  uval_t stkargs;
  reginfovec_t spoiled;
  cm_t cc;
  type_t basetype;
  func_type_info_t(): flags(0), retloc(0), stkargs(0), cc(0), basetype(0) {};
};
extern "C" int __stdcall build_funcarg_info(
        const til_t *til,
        const type_t *type,
        const p_list *fields,
        func_type_info_t *info,
        int bfi_flags);
extern "C" bool __stdcall build_func_type(
        qtype *p_type,
        qtype *p_fields,
        const func_type_info_t &fi);
extern "C" bool __stdcall build_func_type2(
        const til_t *ti,
        qtype *p_type,
        qtype *p_fields,
        const func_type_info_t &fi);
extern "C" int __stdcall get_func_rettype(
        const til_t *til,
        const type_t **type,
        const p_list **fields,
        qtype *rettype,
        qtype *retfields=0,
        argloc_t *p_retloc=0,
        cm_t *p_cc=0);
extern "C" cm_t __stdcall get_func_cc(
        const til_t *til,
        const type_t **p_type,
        const p_list **p_fields=0);
 int __stdcall calc_func_nargs(const til_t *til, const type_t *type)
{
  return get_func_rettype(til, &type, 0, 0);
}
 int calc_purged_bytes(const type_t *type)
{
  return ph.notify(ph.calc_purged_bytes, type) - 2;
}
extern "C" error_t __stdcall calc_names_cmts(
        const til_t *ti,
        const type_t *type,
        bool __stdcall find_var(
                int level,
                void *ud,
                const char **name,
                const char **cmt),
        void *ud,
        p_list **names,
        p_list **cmts);
extern "C" bool __stdcall resolve_complex_type2(
        const til_t *til,
        const type_t **ptype,
        const p_list **fields,
        qstring *type_name,
        type_t *bt,
        int *N);
extern "C" int __stdcall visit_strmems(
        const til_t *til,
        const type_t *type,
        const p_list *fields,
        int N,
        bool is_union,
        int __stdcall visitor(
                uint32 offset,
                const type_t *type,
                const p_list *fields,
                const char *name,
                void *ud),
        void *ud);
extern "C" bool __stdcall is_type_scalar2(const til_t *til, const type_t *type);
typedef int type_sign_t;
const type_sign_t
  no_sign       = 0,
  type_signed   = 1,
  type_unsigned = 2;
extern "C" type_sign_t __stdcall get_type_sign(const til_t *til, const type_t *type);
 bool is_type_signed  (const til_t *til, const type_t *type) { return get_type_sign(til, type) == type_signed; }
 bool is_type_unsigned(const til_t *til, const type_t *type) { return get_type_sign(til, type) == type_unsigned; }
struct regobj_t
{
  int regidx;
  int relocate;
  bytevec_t value;
  size_t size(void) const { return value.size(); }
};
struct regobjs_t : public qvector<regobj_t>
{
};
extern "C" error_t __stdcall unpack_object_from_idb(
        idc_value_t *obj,
        til_t *ti,
        const type_t *type,
        const p_list *fields,
        ea_t ea,
        const bytevec_t *off0,
        int pio_flags=0);
extern "C" error_t __stdcall unpack_object_from_bv(
        idc_value_t *obj,
        til_t *ti,
        const type_t *type,
        const p_list *fields,
        const bytevec_t &bytes,
        int pio_flags=0);
extern "C" error_t __stdcall pack_object_to_idb(
        const idc_value_t *obj,
        til_t *ti,
        const type_t *type,
        const p_list *fields,
        ea_t ea,
        int pio_flags=0);
extern "C" error_t __stdcall pack_object_to_bv(
        const idc_value_t *obj,
        til_t *ti,
        const type_t *type,
        const p_list *fields,
        relobj_t *bytes,
        void *objoff,
        int pio_flags=0);
struct get_strmem_t
{
  int flags;
  int index;
  asize_t offset;
  asize_t delta;
  qstring name;
  qtype ftype;
  qtype fnames;
  qstring sname;
};
extern "C" bool __stdcall get_strmem2(
        const til_t *til,
        const type_t *type,
        const p_list *fields,
        get_strmem_t *info);
extern "C" bool __stdcall apply_type_to_stkarg(
        op_t &x,
        uval_t v,
        const type_t *type,
        const char *name);
extern "C" int __stdcall use_regarg_type_cb(
        ea_t ea,
        const type_t **rtypes,
        const char **rnames,
        uint32 *rlocs,
        int rn,
        void *ud=0);
typedef bool __stdcall set_op_type_t(op_t &x, const type_t *type, const char *name);
typedef bool __stdcall is_stkarg_load_t(int *src, int *dst);
typedef bool __stdcall has_delay_slot_t(ea_t caller);
extern "C" int __stdcall gen_use_arg_types(
        ea_t caller,
        const type_t * const *types,
        const char * const *names,
        const uint32 *arglocs,
        int n,
        const type_t **rtypes,
        const char **rnames,
        uint32 *rlocs,
        int rn,
        set_op_type_t *set_op_type,
        is_stkarg_load_t *is_stkarg_load,
        has_delay_slot_t *has_delay_slot=0);
enum update_type_t
{
  UTP_ENUM,
  UTP_STRUCT,
};
extern "C" void __stdcall begin_type_updating(update_type_t utp);
extern "C" void __stdcall end_type_updating(update_type_t utp);
extern "C" int __stdcall add_til(const char *name);
 bool is_type_voiddef(type_t t) { return(get_full_type(t) == BTF_VOID); }
 bool is_type_void_obsolete(type_t t) { return(get_base_type(t) == BT_VOID); }
 bool is_type_unk(type_t t)     { return(get_base_type(t) == BT_UNK); }
 bool is_type_only_size(type_t t){ return get_base_type(t) <= BT_VOID; }
extern "C" bool __stdcall apply_type(ea_t ea, const type_t *type, const p_list *fields);
extern "C" bool __stdcall apply_type2(ea_t ea, const type_t *rtype, const p_list *fields, int userti);
extern "C" bool __stdcall parse_type(const char *decl, char **name, type_t **type, p_list **fields, int flags=0);
extern "C" int __stdcall parse_types(const char *input, bool isfile, printer_t *printer);
extern "C" int __stdcall parse_types2(const char *input, printer_t *printer, int hti_flags);
extern "C" bool __stdcall resolve_complex_type(const type_t **ptype, const p_list **fields, char *fname, size_t fnamesize, type_t *bt, int *N);
extern "C" int __stdcall foreach_strmem(const type_t *type, const p_list *fields, int N, bool is_union, int __stdcall func(uint32 offset, const type_t *type, const p_list *fields, const char *name, void *ud), void *ud);
extern "C" bool __stdcall get_struct_member(const type_t *type, const p_list *fields, asize_t offset, asize_t *delta, char *name, size_t namesize, type_t *ftype, size_t typesize, p_list *ffields, size_t ffldsize, char *sname, size_t snamesize);
extern "C" bool __stdcall apply_cdecl(ea_t ea, const char *decl);
extern "C" tid_t __stdcall til2idb(int idx, const char *name);
extern "C" bool __stdcall get_idainfo_by_type(const type_t *&rtype, const p_list *fields, size_t *psize,  flags_t *pflags,  opinfo_t *mt, size_t *alsize=0);
extern "C" bool __stdcall remove_pointerness(const type_t **ptype, const char **pname);
extern "C" int  __stdcall get_pointer_object_size(const type_t *t);
extern "C" bool __stdcall is_type_scalar(const type_t *type);
extern "C" type_sign_t __stdcall get_type_signness(const type_t *type);
 bool is_type_signed  (const type_t *type) { return get_type_sign(idati, type) == type_signed; }
 bool is_type_unsigned(const type_t *type) { return get_type_sign(idati, type) == type_unsigned; }
extern "C" bool __stdcall is_resolved_type_const  (const type_t *type);
extern "C" bool __stdcall is_resolved_type_void   (const type_t *type);
extern "C" bool __stdcall is_resolved_type_ptr    (const type_t *type);
extern "C" bool __stdcall is_resolved_type_func   (const type_t *type);
extern "C" bool __stdcall is_resolved_type_array  (const type_t *type);
extern "C" bool __stdcall is_resolved_type_complex(const type_t *type);
extern "C" bool __stdcall is_resolved_type_struct (const type_t *type);
extern "C" bool __stdcall is_resolved_type_union  (const type_t *type);
extern "C" bool __stdcall is_resolved_type_struni (const type_t *type);
extern "C" bool __stdcall is_resolved_type_enum   (const type_t *type);
extern "C" bool __stdcall is_resolved_type_bitfld (const type_t *type);
extern "C" bool __stdcall is_castable(const type_t *from, const type_t *to);
extern "C" int __stdcall guess_func_type(func_t *pfn, type_t *type, size_t tsize, p_list *fields, size_t fsize);
extern "C" int __stdcall guess_type(tid_t id, type_t *type, size_t tsize, p_list *fields, size_t fsize);
extern "C" bool __stdcall make_array_type(type_t *buf, size_t bufsize, const type_t *type, int size);
extern "C" type_t *__stdcall extract_func_ret_type(const type_t *type, type_t *buf, int bufsize);
extern "C" int __stdcall get_func_nargs(const type_t **type);
extern "C" int __stdcall build_funcarg_arrays(const type_t *type, const p_list *fields, uint32 *arglocs, type_t **types, char **names, int maxargs, bool remove_constness);
extern "C" void __stdcall free_funcarg_arrays(type_t **types, char **names, int n);
extern "C" int __stdcall calc_arglocs(const type_t *&type, uint32 *arglocs, int maxn);
extern "C" const type_t *__stdcall resolve_typedef(const til_t *ti, const type_t *p, const p_list **fields);
extern "C" bool __stdcall get_strmem(const til_t *til, const type_t *type, const p_list *fields, asize_t offset, asize_t *delta, qstring *name, qtype *ftype=0, qtype *fnames=0, qstring *sname=0);
extern "C" bool __stdcall get_strmem_by_name(const til_t *til, const type_t *type, const p_list *fields, const char *name, asize_t *offset, qtype *ftype=0, qtype *fnames=0, qstring *sname=0);
#pragma pack(pop)
#pragma pack(push, 1)
#pragma pack(push, 1)
typedef ushort vm_pagenum_t;
const vm_pagenum_t VM_BADPAGE = vm_pagenum_t(-1);
const int HASH_SIZE  = 512;
class VM_page
{
  friend class VM;
  VM_page *hash_next;
  VM_page *time_prev;
  VM_page *time_next;
  vm_pagenum_t Number;
  char dirty;
  char locked;
  char data[1];
  friend VM_page *PagePtr(void *buf);
};
 VM_page *PagePtr(void *buf)
  { return  (VM_page *)((char *)buf - sizeof(VM_page) + 1); }
class VM
{
public:
  int linkTo(
        int ALLpages,
        const char *file,
        bool RWmode,
        size_t psize);
  VM(void)
  {
    handle = 0;
    filename = 0;
    Core = 0;
  }
  friend bool isOk(VM *v)         { return v->handle != 0; }
  size_t PageSize(void)           { return Psize; }
  ~VM(void);
  void vflush(void);
  void vclose(void);
  void saveOne(void);
  bool lock(vm_pagenum_t pnum)
  {
    if ( locks > 0 )
    {
      VM_page *found = searchhash(pnum);
      do if ( !(found != 0) ) do { if ( under_debugger ) __debugbreak(); interr(18); } while(1); while (0);
      if ( !found->locked )
        locks--;
      found->locked++;
      return true;
    }
    return false;
  }
  void unlock(vm_pagenum_t pnum)
  {
    VM_page *found = searchhash(pnum);
    do if ( !(found != 0) ) do { if ( under_debugger ) __debugbreak(); interr(19); } while(1); while (0);
    if ( found->locked > 0 )
    {
      found->locked--;
      if ( !found->locked )
        locks++;
    }
  }
  void vchsize(uint32 size);
  const char *file(void) const { return filename; }
protected:
  void *vread(vm_pagenum_t pnum)        { return _read(pnum, true); }
  void *valloc(vm_pagenum_t pnum)       { return _read(pnum, false); }
  void vwrite(void *buffer)        { PagePtr(buffer)->dirty = true; }
  void  vfree(void *buffer);
  bool lock(void *buffer)
  {
    if ( locks > 0 )
    {
      VM_page *ptr = PagePtr(buffer);
      if ( !ptr->locked ) locks--;
      ptr->locked++;
      return true;
    }
    return false;
  }
  void unlock(void *buffer)
  {
    VM_page *ptr = PagePtr(buffer);
    if ( ptr->locked > 0 )
    {
      ptr->locked--;
      if ( !ptr->locked ) locks++;
    }
  }
  vm_pagenum_t pagenum(void *buffer) { return PagePtr(buffer)->Number; }
  void setpage(void *buffer, vm_pagenum_t newnum);
  bool swap(void *buf1,void *buf2);
private:
  size_t Psize;
  int locks;
  FILE *handle;
  VM_page *hashtable[HASH_SIZE];
  VM_page *head;
  void *Core;
  char *filename;
  size_t PageLength(void)
  {
    return sizeof(VM_page) - 1 + Psize;
  }
  VM_page *AddOne(VM_page *ptr)
  {
    return (VM_page *)((char *)ptr + PageLength());
  }
  void DoWrite(VM_page *P);
  void DoRead (VM_page *P);
  void *_read(vm_pagenum_t pnum, bool readflag);
  VM_page *searchhash(vm_pagenum_t pnum) const;
  void inserthash(VM_page *ptr);
  void removehash(vm_pagenum_t pnum);
};
extern void (*VMErrorHandler)(const VM *v, const char *message, vm_pagenum_t pnum);
void VmDefaultHandler(const VM *v, const char *message, vm_pagenum_t);
template <class type>
class vmclass : public VM
{
public:
  type *vread(vm_pagenum_t num) { return (type *)VM::vread(num); }
  type *valloc(vm_pagenum_t num) { return (type *)VM::valloc(num); }
  void vwrite(type *buffer) { VM::vwrite(buffer); }
  void vfree(type *buffer) { VM::vfree(buffer); }
  bool lock(type *buffer) { return VM::lock(buffer); }
  void unlock(type *buffer) { VM::unlock(buffer); }
  vm_pagenum_t pagenum(type *buffer) { return VM::pagenum(buffer); }
  void setpage(type *buffer, vm_pagenum_t n){ VM::setpage(buffer,n); }
  bool swap(type *buf1, type *buf2){ return VM::swap(buf1,buf2); }
};
#pragma pack(pop)
struct vaptr_t
{
  ea_t start;
  ea_t end;
  uval_t offset;
  void correct_offset(size_t pagesize)
  {
    size_t psize = pagesize / sizeof(uint32);
    offset = offset - offset%pagesize + (start%psize)*sizeof(uint32);
  }
  asize_t size(void) const { return end - start; }
};
struct vaheader_t
{
  char magic[4];
  ushort nchunks;
  ushort eof;
};
typedef bool __stdcall va_test(uint32, void *ud);
class Varray
{
public:
        Varray(void)    { Pages = 0; }
        ~Varray(void)   { vclose(); }
        int     linkTo  (const char *file, uint Psize, uint PoolSize);
        void    vclose   (void);
        error_t enable  (ea_t start,ea_t end);
        error_t disable (ea_t start,ea_t end);
        bool    enabled (ea_t addr)
                                { return getoff(addr) != 0; }
        bool in_fast_cache(ea_t addr)
        {
          return lastvp != 0 && lastvp->start <= addr && lastvp->end > addr;
        }
        ea_t nextaddr  (ea_t addr);
        ea_t prevaddr  (ea_t addr);
        ea_t prevchunk (ea_t addr);
        ea_t nextchunk (ea_t addr);
        asize_t chunksize(ea_t addr)
        {
          if ( getoff(addr) == 0 )
            return 0;
          return lastvp->end - lastvp->start;
        }
        ea_t get_chunk_start(ea_t addr)
        {
          if ( getoff(addr) == 0 )
            return ea_t(-1);
          return lastvp->start;
        }
        ea_t get_chunk_end(ea_t addr)
        {
          if ( getoff(addr) == 0 )
            return 0;
          return lastvp->end;
        }
        ea_t first_enabled_addr(ea_t ea1, ea_t ea2) const;
        int movechunk  (ea_t from, ea_t to, asize_t size);
        int check_move_args(ea_t from, ea_t to, asize_t size);
        uint32   vread  (ea_t ea)             { return *Raddr(ea); }
        void    vwrite  (ea_t ea, uint32 val) { *Waddr(ea)  =  val; }
        void    setbits (ea_t ea, uint32 bit) { *Waddr(ea) |=  bit; }
        void    clrbits (ea_t ea, uint32 bit) { *Waddr(ea) &= ~bit; }
        uint32*  Waddr  (ea_t ea);
        uint32*  Raddr  (ea_t ea);
        void    vflush  (void)          { Pages->vflush(); }
        void memset(ea_t start, asize_t size, uint32 x);
        void memcpy(ea_t start, asize_t size, Varray &src, ea_t srcstart);
        ea_t memcmp(ea_t start, asize_t size, Varray &v2, ea_t v2start);
        ea_t memscn (ea_t start, asize_t size, uint32 x);
        ea_t memtst (ea_t start, asize_t size, va_test *test, void *ud);
        ea_t memtstr(ea_t start, asize_t size, va_test *test, void *ud);
        uint32  *vread  (ea_t start,      uint32 *buffer, size_t size);
        void    vwrite  (ea_t start,const uint32 *buffer, size_t size);
        void    shright (ea_t from);
        void    shleft  (ea_t from);
        ea_t bsearch(ea_t ea);
        bool addsorted(ea_t ea);
        bool delsorted(ea_t ea);
        void vadump(const char *msg, bool ea_sort_order);
        const char *check(bool ea_sort_order);
        typedef vaptr_t *iterator;
        typedef const vaptr_t *const_iterator;
        const_iterator begin(void) const { return const_iterator(header+1); }
        const_iterator end(void) const { return begin() + header->nchunks; }
        iterator begin(void) { return iterator(header+1); }
        iterator end(void) { return begin() + header->nchunks; }
  ea_t vascan(
        ea_t _start,
        asize_t size,
        ssize_t (__stdcall*perform)(uint32 *page, ssize_t s, void *ud),
        bool change,
        void *ud);
  ea_t vascanr(
        ea_t _start,
        asize_t size,
        ssize_t (__stdcall*perform)(uint32 *page, ssize_t s, void *ud),
        bool change,
        void *ud);
private:
  vmclass<uint32> *Pages;
  vaheader_t *header;
  ea_t lastea;
  vaptr_t *lastvp;
  uint32 lastoff;
  ushort lastPage;
  uint32 *lPage;
  size_t psize;
  size_t pagesize;
  uint32 getoff(ea_t addr);
  int shiftPages(uval_t offset, int op, int np, bool changecur);
  void move_vm_chunk(size_t p1, size_t p2, ssize_t n);
  void swap(size_t x1, size_t x2, ssize_t n);
  vaptr_t *split(vaptr_t *cvp, ea_t from, ea_t end);
  void split_page(size_t kp, ea_t from);
  void merge_if_necessary(vaptr_t *vp);
  int add_pages(uval_t offset, int npages, bool changecur)
    { return shiftPages(offset, 0, npages, changecur); }
  int del_pages(uval_t offset, int npages, bool changecur)
    { return shiftPages(offset, npages, 0, changecur); }
  size_t getidx(const vaptr_t *vp) const { return size_t(vp - begin()); }
  bool is_first(const vaptr_t *vp) const { return getidx(vp) == 0; }
  bool is_last(const vaptr_t *vp) const;
};
struct vaidx_info_t
{
  Varray *source;
  ea_t index;
};
struct vascan_info_t
{
  va_test *test;
  void *ud;
  vascan_info_t(va_test *_test, void *_ud) : test(_test), ud(_ud) {}
};
#pragma pack(pop)
