//
// Created by aidankeefe on 11/21/25.
//
#include "logger.h"
#include <stdio.h>
#include <stdarg.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m" // Resets to default color

LOG_LEVEL log_level = -1;
constexpr LOG_LEVEL default_log_level = LOG_ERROR;

LOG_LEVEL get_log_level() {
    return log_level == -1 ? default_log_level : log_level;
}

void set_log_level(LOG_LEVEL user_log_level) {
    if (log_level == -1 ) {
        log_level = user_log_level;
    }
}
void log_message(LOG_LEVEL msg_log_level, const char* log_message, ...) {
    if (msg_log_level > get_log_level()) {
        return;
    }
    va_list ap;
    va_start(ap, log_message);

    switch (msg_log_level) {
        case LOG_ERROR:
            printf(ANSI_COLOR_RED "ERROR: "ANSI_COLOR_RESET);
            break;
        case LOG_INFO:
            printf(ANSI_COLOR_GREEN"INFO: "ANSI_COLOR_RESET);
            break;
        case LOG_WARN:
            printf(ANSI_COLOR_YELLOW"WARN: "ANSI_COLOR_RESET);
            break;
        case LOG_DEBUG:
            printf(ANSI_COLOR_MAGENTA"DEBUG: " ANSI_COLOR_RESET);
            break;
        default:
            return;
    }

    vprintf(log_message, ap);
    printf("\n");

    va_end(ap);
}

