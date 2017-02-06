/*
 * Copyright 2010-2016, Adrien Destugues <pulkomandy@pulkomandy.tk>.
 * Distributed under the terms of the MIT License.
 */


#include <os/locale/Catalog.h>
#include <os/locale/LocaleRoster.h>

#include <private/shared/locks.h>


static int32 sCatalogInitOnce = INIT_ONCE_UNINITIALIZED;


BCatalog*
BLocaleRoster::GetCatalog()
{
	static BCatalog sCatalog;

	asm volatile(".hidden _ZN13BLocaleRoster10GetCatalogEv");

	return _GetCatalog(&sCatalog, &sCatalogInitOnce);
}


namespace BPrivate{
	void ForceUnloadCatalog()
	{
		sCatalogInitOnce = INIT_ONCE_UNINITIALIZED;
	}
}
