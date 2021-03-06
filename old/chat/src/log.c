/*
 * =====================================================================================
 *
 *       Filename:  log.c
 *
 *    Description: This source constains all log implementation used on both client and
 *    server side
 *
 *        Version:  1.0
 *        Created:  02/03/14 21:25:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José Guilherme Vanz (vanz), guilherme.sft@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "log.h"
#include <stdlib.h>

#define MIN_SIZE_MSG 100

void logger(LOG_TYPE type, const char * const format, va_list args);
void format_string(const char* format, va_list args, char * formatted_strig);

void logger(LOG_TYPE type, const char * const format, va_list args)
{
	char * log_type_str;
	switch(type){
		case INFO:
			log_type_str = "INFO";
			break;
		case WARNING:
			log_type_str = "WARNING";
			break;
		case ERROR:
			log_type_str = "ERROR";
			break;
		case DEBUG:
			log_type_str = "DEBUG";
			break;
		default:
			log_type_str = "INFO";
	}
	char * formatted_msg = malloc(MIN_SIZE_MSG);
	format_string(format, args, formatted_msg);
	printf("%s - %s\n", log_type_str, formatted_msg);
	//free(formatted_msg); FIXME - error
}

void format_string(const char* format, va_list args, char * formatted_strig)
{
	int bytes_wrote = vsprintf(formatted_strig, format, args);
	if(bytes_wrote < 0){
		fprintf(stderr, "Error formating string");
	}
}

void logInfo(const char * const msg, ...)
{
	va_list argptr;
	va_start(argptr,msg);
	logger(INFO, msg, argptr);
	va_end(argptr);
}

void logWarning(const char * const msg, ...)
{
	va_list argptr;
	va_start(argptr,msg);
	logger(WARNING, msg, argptr);
	va_end(argptr);
}

void logError(const char * const msg, ...)
{
	va_list argptr;
	va_start(argptr,msg);
	logger(ERROR, msg, argptr);
	va_end(argptr);
}

void logDebug(const char * const msg, ...)
{
	va_list argptr;
	va_start(argptr,msg);
	logger(DEBUG, msg, argptr);
	va_end(argptr);
}
