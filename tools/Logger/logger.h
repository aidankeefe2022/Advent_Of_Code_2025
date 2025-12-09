//
// Created by aidankeefe on 11/21/25.
//

#ifndef ACO_LOGGER_H
#define ACO_LOGGER_H

typedef enum LOG_LEVELS {
    LOG_ERROR = 1,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
}LOG_LEVEL;


void set_log_level(LOG_LEVEL log_level);
void log_message(LOG_LEVEL log_level, const char* log_message, ...);

#endif //ACO_LOGGER_H