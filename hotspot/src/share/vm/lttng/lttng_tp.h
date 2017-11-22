
#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER jvm

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./lttng_tp.h"

#if !defined(LTTNG_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define LTTNG_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    jvm,
	report_gc_start,
    TP_ARGS(
        int, id,
		int, name
    ),
    TP_FIELDS(
        ctf_integer(int, id, id)
		ctf_integer(int, name, name)
    )
)


TRACEPOINT_EVENT(
    jvm,
	report_gc_end,
    TP_ARGS(
        int, id,
        int, name,
		int, cause,
		long, sumOfPauses,
		long, longuestPause
    ),
    TP_FIELDS(
    	ctf_integer(int, id, id)
        ctf_integer(int, name, name)
        ctf_integer(int, cause, cause)
		ctf_integer(long, sumOfPauses, sumOfPauses)
		ctf_integer(long, longuestPause, longuestPause)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_requiring_gc,
    TP_ARGS(
        int, size,
		int, gcid
    ),
    TP_FIELDS(
        ctf_integer(int, size, size)
		ctf_integer(int, gcid, gcid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_new_tlab,
    TP_ARGS(
    	char*, name,
        int, alloc_size,
		int, tlab_size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
        ctf_integer(int, alloc_size, alloc_size)
		ctf_integer(int, tlab_size, tlab_size)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_outside_tlab,
    TP_ARGS(
    	char*, name,
        int, alloc_size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
        ctf_integer(int, alloc_size, alloc_size)
    )
)

TRACEPOINT_EVENT(
    jvm,
	method_compile_begin,
    TP_ARGS(
    	char*, className,
		char*, methodName,
		char*, signature
    ),
    TP_FIELDS(
    	ctf_string(className, className)
		ctf_string(methodName, methodName)
		ctf_string(signature, signature)
    )
)

TRACEPOINT_EVENT(
    jvm,
	method_compile_end,
    TP_ARGS(
    	char*, className,
		char*, methodName,
		char*, signature
    ),
    TP_FIELDS(
    	ctf_string(className, className)
		ctf_string(methodName, methodName)
		ctf_string(signature, signature)
    )
)

#endif /* LTTNG_TP_H */

#include <lttng/tracepoint-event.h>
