/*
 * Copyright 2014, Ingo Weinhold, ingo_weinhold@gmx.de.
 * Distributed under the terms of the MIT License.
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H


#include <SupportDefs.h>


extern const char* const kPackageFileNameExtension;
extern const char* const kAdminDirectoryName;
extern const char* const kActivationFileName;
extern const char* const kTemporaryActivationFileName;
extern const char* const kWritableFilesDirectoryName;
extern const char* const kPackageFileAttribute;

static const bigtime_t kHandleNodeMonitorEvents = 'nmon';

static const bigtime_t kNodeMonitorEventHandlingDelay = 500000;
static const bigtime_t kCommunicationTimeout = 1000000;


#endif	// CONSTANTS_H