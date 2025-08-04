#include "logger.h"

int main()
{
    logger_reset_state();

    log_warning("This message goes to syslog");

    logger_set_out_stdout();

    log_status("Hello!");

    logger_set_log_level(LOG_MAX_LEVEL_ERROR_WARNING_STATUS_DEBUG_TRACE);
    logger_set_log_file("log.txt");

    log_error("Logger in a file mode!");
    log_debug("This is debug message");
    log_trace("This is trace message");

    return 0;
}

