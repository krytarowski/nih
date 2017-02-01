/*
 * Copyright 2001-2011, Haiku.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Ingo Weinhold (bonefish@users.sf.net)
 */

//!	Global library initialization/termination routines.


#include <stdio.h>
#include <stdlib.h>

#include <private/app/AppMisc.h>
#include <private/app/LooperList.h>
#include <private/app/MessagePrivate.h>
#include <private/app/RosterPrivate.h>
#include <private/app/TokenSpace.h>


extern void __initialize_locale_kit();


// debugging
//#define DBG(x) x
#define DBG(x)
#define OUT	printf


static void
initialize_forked_child()
{
	DBG(OUT("initialize_forked_child()\n"));

	BMessage::Private::StaticReInitForkedChild();
	BPrivate::gLooperList.InitAfterFork();
	BPrivate::gDefaultTokens.InitAfterFork();
	BPrivate::init_team_after_fork();

	DBG(OUT("initialize_forked_child() done\n"));
}


extern "C" void
initialize_before()
{
	DBG(OUT("initialize_before()\n"));

	BMessage::Private::StaticInit();
	BRoster::Private::InitBeRoster();

#if !defined(__NetBSD__)
	atfork(initialize_forked_child);
#endif

	DBG(OUT("initialize_before() done\n"));
}


extern "C" void
initialize_after()
{
	DBG(OUT("initialize_after()\n"));

	__initialize_locale_kit();

	DBG(OUT("initialize_after() done\n"));
}


extern "C" void
terminate_after()
{
	DBG(OUT("terminate_after()\n"));

	BRoster::Private::DeleteBeRoster();
	BMessage::Private::StaticCleanup();
	BMessage::Private::StaticCacheCleanup();

	DBG(OUT("terminate_after() done\n"));
}
