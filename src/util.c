
/*
 * REminiscence - Flashback interpreter
 * Copyright (C) 2005-2015 Gregory Montoir (cyx@users.sourceforge.net)
 */

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "util.h"

uint16_t g_debugMask;

void debug(uint16_t cm, const char *msg, ...)
{
   char buf[1024];
   if (cm & g_debugMask)
   {
      va_list va;
      va_start(va, msg);
      vsprintf(buf, msg, va);
      va_end(va);
      fprintf(stderr, "%s\n", buf);
      fflush(stderr);
   }
}

void error(const char *msg, ...)
{
	char buf[1024];
	va_list va;
	va_start(va, msg);
	vsnprintf(buf, sizeof(buf), msg, va);
	va_end(va);
	fprintf(stderr, "ERROR: %s!\n", buf);
	exit(-1);
}

void warning(const char *msg, ...)
{
	char buf[1024];
	va_list va;
	va_start(va, msg);
	vsnprintf(buf, sizeof(buf), msg, va);
	va_end(va);
	fprintf(stderr, "WARNING: %s!\n", buf);
}

