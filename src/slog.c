#include "logger.h"

int main()
{
    logger_reset_state();

    log_warning("This message goes to syslog");

    logger_set_out_stdout();

    log_status("Hello!");

    logger_set_log_file("log.txt");

    log_error("Logger in a file mode!");

    return 0;
}

