
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

TRACEPOINT_EVENT(
    jvm,
	method_load,
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
	method_unload,
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
	heap_info,
    TP_ARGS(
        int, gc_id,
		int, when,
		int, commited,
		int, used
    ),
    TP_FIELDS(
        ctf_integer(int, gc_id, gc_id)
		ctf_integer(int, when, when)
		ctf_integer(int, commited, commited)
		ctf_integer(int, used, used)
    )
)

TRACEPOINT_EVENT(
    jvm,
	method_entry,
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
	method_return,
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
	thread_start,
    TP_ARGS(
    	char*, name,
		int, java_threadid,
		int, os_threadid,
		int, deamon
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, java_threadid, java_threadid)
		ctf_integer(int, os_threadid, os_threadid)
		ctf_integer(int, deamon, deamon)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_stop,
    TP_ARGS(
    	char*, name,
		int, java_threadid,
		int, os_threadid,
		int, deamon
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, java_threadid, java_threadid)
		ctf_integer(int, os_threadid, os_threadid)
		ctf_integer(int, deamon, deamon)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_sleep_start,
    TP_ARGS(
    	char*, name,
		int, java_threadid,
		int, os_threadid,
		int, deamon,
		long, millis
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, java_threadid, java_threadid)
		ctf_integer(int, os_threadid, os_threadid)
		ctf_integer(int, deamon, deamon)
		ctf_integer(long, millis, millis)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_sleep_end,
    TP_ARGS(
    	char*, name,
		int, java_threadid,
		int, os_threadid,
		int, deamon,
		int, status
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, java_threadid, java_threadid)
		ctf_integer(int, os_threadid, os_threadid)
		ctf_integer(int, deamon, deamon)
		ctf_integer(int, status, status)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmops_begin,
    TP_ARGS(
    	char*, name,
		int, evaluation_mode,
		int, is_concurrent,
		int, calling_thread
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, evaluation_mode, evaluation_mode)
		ctf_integer(int, is_concurrent, is_concurrent)
		ctf_integer(int, calling_thread, calling_thread)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmops_end,
    TP_ARGS(
    	char*, name,
		int, evaluation_mode,
		int, is_concurrent,
		int, calling_thread
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(int, evaluation_mode, evaluation_mode)
		ctf_integer(int, is_concurrent, is_concurrent)
		ctf_integer(int, calling_thread, calling_thread)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmtojava,
    TP_ARGS(
    		int, res
    ),
    TP_FIELDS(
    		ctf_integer(int, res, res)
    )
)


TRACEPOINT_EVENT(
    jvm,
    object_alloc,
    TP_ARGS(
    	char*, name,
    	int, size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
    	ctf_integer(int, size, size)
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_enter,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_entered,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_exit,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)

TRACEPOINT_EVENT(
    jvm,
    notify,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)

TRACEPOINT_EVENT(
    jvm,
    notifyAll,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)



TRACEPOINT_EVENT(
    jvm,
    monitor_waited,
    TP_ARGS(
    ),
    TP_FIELDS(
    )
)




#endif /* LTTNG_TP_H */

#include <lttng/tracepoint-event.h>
