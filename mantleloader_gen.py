#!/usr/bin/env python

# 	ORIGINAL LOADER COURTESY OF https://github.com/skaslev/gl3w
#   This file is part of mantleapi, hosted at https://github.com/kwertz/mantleapi
#
#   This is free and unencumbered software released into the public domain.
#
#   Anyone is free to copy, modify, publish, use, compile, sell, or
#   distribute this software, either in source code form or as a compiled
#   binary, for any purpose, commercial or non-commercial, and by any
#   means.
#
#   In jurisdictions that recognize copyright laws, the author or authors
#   of this software dedicate any and all copyright interest in the
#   software to the public domain. We make this dedication for the benefit
#   of the public at large and to the detriment of our heirs and
#   successors. We intend this dedication to be an overt act of
#   relinquishment in perpetuity of all present and future rights to this
#   software under copyright law.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
#   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
#   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
#   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
#   OTHER DEALINGS IN THE SOFTWARE.

# Allow Python 2.6+ to use the print() function
from __future__ import print_function

import re
import os

# Try to import Python 3 library urllib.request
# and if it fails, fall back to Python 2 urllib2
try:
    import urllib.request as urllib2
except ImportError:
    import urllib2

# UNLICENSE copyright header
UNLICENSE = br'''/*

    This file was generated with mantleloader_gen.py, part of mantleapi
    (hosted at https://github.com/kwertz/mantleapi)

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

*/

'''

# Create directories
if not os.path.exists('include/GR'):
    os.makedirs('include/GR')
if not os.path.exists('src'):
    os.makedirs('src')

# Parse function names from mantle.h
print('Parsing mantle.h header...')
procs = []
p = re.compile(r'typedef.*GRAPI\s+(\w+)')
with open('include/GR/mantle.h', 'r') as f:
    for line in f:
        m = p.match(line)
        if m:
            procs.append(m.group(1)[:-2])
procs.sort()

def proc_t(proc):
    return { 'p': proc,
             'p_s': 'grl' + proc[2:],
             'p_t': proc + 'Fn*' }

# Generate mantleloader.h
print('Generating mantleloader.h in include/GR...')
with open('include/GR/mantleloader.h', 'wb') as f:
    f.write(UNLICENSE)
    f.write(br'''#ifndef __mantleloader_h_
#define __mantleloader_h_

#include <GR/mantle.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GRLgrProc)(void);

/* mantleloader api */
int grlInit(void);
void grlShutdown(void);
GRLgrProc grlGetProcAddress(const char *proc);

/* Mantle functions */
''')
    for proc in procs:
        f.write('extern {0[p_t]: <52} {0[p_s]};\n'.format(proc_t(proc)).encode("utf-8"))
    f.write(b'\n')
    for proc in procs:
        f.write('#define {0[p]: <45} {0[p_s]}\n'.format(proc_t(proc)).encode("utf-8"))
    f.write(br'''
#ifdef __cplusplus
}
#endif

#endif
''')

# Generate mantleloader.c
print('Generating mantleloader.c in src...')
with open('src/mantleloader.c', 'wb') as f:
    f.write(UNLICENSE)
    f.write(br'''#include <GR/mantleloader.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static HMODULE libgr;

static void open_libgr(void)
{
	libgr = LoadLibraryA("mantle64.dll");
	if (!libgr) libgr = LoadLibraryA("mantle32.dll");
}

static void close_libgr(void)
{
	FreeLibrary(libgr);
	libgr = NULL;
}

static GRLgrProc get_proc(const char *proc)
{
	return (GRLgrProc)GetProcAddress(libgr, proc);
}

static void load_procs(void);

int grlInit(void)
{
	open_libgr();
	load_procs();
	return 0;
}

void grlShutdown(void)
{
	close_libgr();
}

GRLgrProc grlGetProcAddress(const char *proc)
{
	return get_proc(proc);
}

''')
    for proc in procs:
        f.write('{0[p_t]: <52} {0[p_s]};\n'.format(proc_t(proc)).encode("utf-8"))
    f.write(br'''
static void load_procs(void)
{
''')
    for proc in procs:
        f.write('\t{0[p_s]} = ({0[p_t]}) get_proc("{0[p]}");\n'.format(proc_t(proc)).encode("utf-8"))
    f.write(b'}\n')
