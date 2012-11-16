/*
 * =============================================================================
 *
 *       Filename:  leveldb_log.h
 *
 *    Description:  log utility.
 *
 *        Created:  10/20/2012 10:06:52 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef LEVELDB_ENGINE_LOG_H
#define LEVELDB_ENGINE_LOG_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif

enum _log_level_e {
	// LEVELDB_ENGINE_LOG_QUIET = 0,
	LEVELDB_ENGINE_LOG_ERROR = 1,
	LEVELDB_ENGINE_LOG_WARN  = 2,
	LEVELDB_ENGINE_LOG_INFO  = 3,
	LEVELDB_ENGINE_LOG_DEBUG = 4
};

typedef enum _log_level_e log_level_t;

extern log_level_t log_level;

#define LOGSTREAM log_get_stream()

#define LOG_ERROR(x) if (log_level >= LEVELDB_ENGINE_LOG_ERROR) \
    log_message(LEVELDB_ENGINE_LOG_ERROR, __LINE__, __func__, log_format_message x)
#define LOG_WARN(x) if(log_level >= LEVELDB_ENGINE_LOG_WARN) \
    log_message(LEVELDB_ENGINE_LOG_WARN, __LINE__, __func__, log_format_message x)
#define LOG_INFO(x) if(log_level >= LEVELDB_ENGINE_LOG_INFO) \
    log_message(LEVELDB_ENGINE_LOG_INFO, __LINE__, __func__, log_format_message x)
#define LOG_DEBUG(x) if(log_level == LEVELDB_ENGINE_LOG_DEBUG) \
    log_message(LEVELDB_ENGINE_LOG_DEBUG, __LINE__, __func__, log_format_message x)

extern void log_message(
		log_level_t level, int line,
		const char* funcname,
		const char* message);
extern const char * log_format_message(const char* format, ...);
extern FILE * log_get_stream(void);
extern void log_set_stream(FILE *stream);
extern void log_set_debug_level(log_level_t level);

#ifdef __cplusplus
}
#endif

#endif /* LEVELDB_ENGINE_LOG_H */

