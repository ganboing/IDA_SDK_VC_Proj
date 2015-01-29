//include necessary std headers first
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>
#include <new>
#include <io.h>
#include <direct.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <math.h>
#include <Windows.h>
// IDA libs

#define inline 
#define __inline
#define __forceinline

#define struct struct __declspec(dllexport)
#define class class __declspec(dllexport)

int IDA_INCLUDE_BEGINS;

#include <pro.h>
#include <ida.hpp>
#include <idp.hpp>

#include <area.hpp>
#include <auto.hpp>
#include <bytes.hpp>
#include <compress.hpp>
#include <dbg.hpp>
#include <demangle.hpp>
#include <diskio.hpp>
#include <entry.hpp>
#include <enum.hpp>
#include <err.h>
#include <exehdr.h>
#include <expr.hpp>
#include <fixup.hpp>
#include <fpro.h>
#include <frame.hpp>
#include <funcs.hpp>
#include <gdl.hpp>
#include <graph.hpp>
#include <help.h>
#include <ida.hpp>
#include <idd.hpp>
#include <idp.hpp>
#include <ieee.h>
#include <ints.hpp>
#include <kernwin.hpp>
#include <lex.hpp>
#include <lines.hpp>
#include <llong.hpp>
#include <loader.hpp>
#include <md5.h>
#include <moves.hpp>
#include <nalt.hpp>
#include <name.hpp>
#include <netnode.hpp>
#include <offset.hpp>
#include <pro.h>
#include <prodir.h>
#include <queue.hpp>
#include <regex.h>
#include <search.hpp>
#include <segment.hpp>
#include <sistack.hpp>
#include <srarea.hpp>
#include <strlist.hpp>
#include <struct.hpp>
#include <typeinf.hpp>
#include <ua.hpp>
#include <va.hpp>
#include <vm.hpp>
#include <xref.hpp>

#include <../ldr/pe/pe.h>
#include <../ldr/pe/common.h>
#include <../ldr/pe/common.cpp>

#define ENABLE_LOWCNDS

#include <debmod.h>
#include <debmod.cpp>

#include <pc_debmod.h>
#include <pc_debmod.cpp>
