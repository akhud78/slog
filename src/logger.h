#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define LOGGER_BUF_SIZE     1024

/*
 * Logging methods by levels
 */
void log_error(const char* format, ...);
void log_warning(const char* format, ...);
void log_status(const char* format, ...);
void log_debug(const char* format, ...);
void log_trace(const char* format, ...);

/*
 * Log level configurator
 * Default is LOG_MAX_LEVEL_ERROR_WARNING_STATUS
 */ 

#define LOG_MAX_LEVEL_ERROR 0
#define LOG_MAX_LEVEL_ERROR_WARNING_STATUS 1
#define LOG_MAX_LEVEL_ERROR_WARNING_STATUS_DEBUG 2
#define LOG_MAX_LEVEL_ERROR_WARNING_STATUS_DEBUG_TRACE 3

void logger_set_log_level(const int level);

/*
 * Set target type
 * Default is syslog
 */
void logger_reset_state(void);      // Reset internal state and set syslog as default target
int logger_set_log_file(const char* filename);
void logger_set_out_stdout();

#ifdef __cplusplus
}
#endif



