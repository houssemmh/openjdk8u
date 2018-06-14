
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
    	long, id,
        long, name
    ),
    TP_FIELDS(
        ctf_integer(long, id, id)
		ctf_integer(long, name, name)
    )
)


TRACEPOINT_EVENT(
    jvm,
	report_gc_end,
    TP_ARGS(
    	long, id,
        long, name,
        long, cause,
		long, sumOfPauses,
		long, longuestPause
    ),
    TP_FIELDS(
    	ctf_integer(long, id, id)
        ctf_integer(long, name, name)
        ctf_integer(long, cause, cause)
		ctf_integer(long, sumOfPauses, sumOfPauses)
		ctf_integer(long, longuestPause, longuestPause)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_requiring_gc,
    TP_ARGS(
    	long, size,
    	long, gcid
    ),
    TP_FIELDS(
        ctf_integer(long, size, size)
		ctf_integer(long, gcid, gcid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_new_tlab,
    TP_ARGS(
    	char*, name,
    	long, alloc_size,
    	long, tlab_size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
        ctf_integer(long, alloc_size, alloc_size)
		ctf_integer(long, tlab_size, tlab_size)
    )
)

TRACEPOINT_EVENT(
    jvm,
	alloc_outside_tlab,
    TP_ARGS(
    	char*, name,
    	long, alloc_size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
        ctf_integer(long, alloc_size, alloc_size)
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
    	long, gc_id,
    	long, when,
    	long, commited,
    	long, used
    ),
    TP_FIELDS(
        ctf_integer(long, gc_id, gc_id)
		ctf_integer(long, when, when)
		ctf_integer(long, commited, commited)
		ctf_integer(long, used, used)
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
    	long, java_threadid,
    	long, os_threadid,
    	long, deamon,
    	long, compiler
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, java_threadid, java_threadid)
		ctf_integer(long, os_threadid, os_threadid)
		ctf_integer(long, deamon, deamon)
		ctf_integer(long, compiler, compiler)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_stop,
    TP_ARGS(
    	char*, name,
    	long, java_threadid,
    	long, os_threadid,
    	long, deamon
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, java_threadid, java_threadid)
		ctf_integer(long, os_threadid, os_threadid)
		ctf_integer(long, deamon, deamon)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmthread_start,
    TP_ARGS(
    	char*, name,
    	long, os_threadid
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, os_threadid, os_threadid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmthread_stop,
    TP_ARGS(
    	char*, name,
    	long, os_threadid
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, os_threadid, os_threadid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	gctaskthread_start,
    TP_ARGS(
    	char*, name,
    	long, os_threadid
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, os_threadid, os_threadid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	gctaskthread_end,
    TP_ARGS(
    	char*, name,
    	long, os_threadid
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, os_threadid, os_threadid)
    )
)

TRACEPOINT_EVENT(
    jvm,
	gctask_start,
    TP_ARGS(
    	char*, name
    ),
    TP_FIELDS(
    	ctf_string(name, name)
    )
)

TRACEPOINT_EVENT(
    jvm,
	gctask_end,
    TP_ARGS(
    	char*, name
    ),
    TP_FIELDS(
    	ctf_string(name, name)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_sleep_start,
    TP_ARGS(
    	char*, name,
    	long, java_threadid,
    	long, os_threadid,
    	long, deamon,
		long, millis
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, java_threadid, java_threadid)
		ctf_integer(long, os_threadid, os_threadid)
		ctf_integer(long, deamon, deamon)
		ctf_integer(long, millis, millis)
    )
)

TRACEPOINT_EVENT(
    jvm,
	thread_sleep_end,
    TP_ARGS(
    	char*, name,
    	long, java_threadid,
    	long, os_threadid,
    	long, deamon,
    	long, status
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, java_threadid, java_threadid)
		ctf_integer(long, os_threadid, os_threadid)
		ctf_integer(long, deamon, deamon)
		ctf_integer(long, status, status)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmops_begin,
    TP_ARGS(
    	char*, name,
    	long, evaluation_mode,
    	long, is_concurrent,
    	long, calling_thread
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, evaluation_mode, evaluation_mode)
		ctf_integer(long, is_concurrent, is_concurrent)
		ctf_integer(long, calling_thread, calling_thread)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmops_end,
    TP_ARGS(
    	char*, name,
    	long, evaluation_mode,
    	long, is_concurrent,
    	long, calling_thread
    ),
    TP_FIELDS(
    	ctf_string(name, name)
		ctf_integer(long, evaluation_mode, evaluation_mode)
		ctf_integer(long, is_concurrent, is_concurrent)
		ctf_integer(long, calling_thread, calling_thread)
    )
)

TRACEPOINT_EVENT(
    jvm,
	vmtojava,
    TP_ARGS(
    		long, res
    ),
    TP_FIELDS(
    		ctf_integer(long, res, res)
    )
)


TRACEPOINT_EVENT(
    jvm,
    object_alloc,
    TP_ARGS(
    	char*, name,
    	long, size
    ),
    TP_FIELDS(
    	ctf_string(name, name)
    	ctf_integer(long, size, size)
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_ask,
    TP_ARGS(
    	unsigned long int, ptr,
    	char*, name
    ),
    TP_FIELDS(
    	ctf_integer(unsigned long int, ptr, ptr)
    	ctf_string(name, name)
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_enter,
    TP_ARGS(
    	unsigned long int, ptr,
    	char*, name
    ),
    TP_FIELDS(
    	ctf_integer(unsigned long int, ptr, ptr)
    	ctf_string(name, name)
    )
)

TRACEPOINT_EVENT(
    jvm,
    contended_entered,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
	)
)

TRACEPOINT_EVENT(
    jvm,
    contended_exit,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
	)
)


TRACEPOINT_EVENT(
    jvm,
    monitor_wait,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name,
		long, millis
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
		ctf_integer(long, millis, millis)
	)
)

TRACEPOINT_EVENT(
    jvm,
    monitor_waited,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
	)
)


TRACEPOINT_EVENT(
    jvm,
    notify,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
	)
)

TRACEPOINT_EVENT(
    jvm,
    notifyAll,
    TP_ARGS(
		unsigned long int, ptr,
		char*, name
	),
	TP_FIELDS(
		ctf_integer(unsigned long int, ptr, ptr)
		ctf_string(name, name)
	)
)


TRACEPOINT_EVENT(
    jvm,
    thread_status,
    TP_ARGS(
    	long, status
    ),
    TP_FIELDS(
    	ctf_integer(long, status, status)
    )
)







#endif /* LTTNG_TP_H */

#include <lttng/tracepoint-event.h>
