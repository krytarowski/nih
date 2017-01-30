/*
 * Copyright 2010-2012, Haiku. All rights reserved.
 * Distributed under the terms of the MIT license.
 */
#ifndef _MUTABLE_LOCALE_ROSTER_H_
#define _MUTABLE_LOCALE_ROSTER_H_


#include <os/locale/Collator.h>
#include <os/locale/FormattingConventions.h>
#include <os/kernel/image.h>
#include <os/locale/Language.h>
#include <os/support/List.h>
#include <os/locale/Locale.h>
#include <os/support/Locker.h>
#include <os/locale/LocaleRoster.h>
#include <os/app/Message.h>
#include <os/storage/Resources.h>
#include <os/locale/TimeZone.h>


class BLocale;
class BCatalog;
class BCatalogData;

struct entry_ref;


namespace BPrivate {


class MutableLocaleRoster : public BLocaleRoster {
public:
								MutableLocaleRoster();
								~MutableLocaleRoster();

	static	MutableLocaleRoster* Default();

			status_t			SetDefaultFormattingConventions(
									const BFormattingConventions& conventions);
			status_t			SetDefaultTimeZone(const BTimeZone& zone);

			status_t			SetPreferredLanguages(const BMessage* message);
									// the message contains one or more
									// 'language'-string-fields which
									// contain the language-name(s)
			status_t			SetFilesystemTranslationPreferred(
									bool preferred);

			status_t			LoadSystemCatalog(BCatalog* catalog) const;

			BCatalogData*		LoadCatalog(const entry_ref& catalogOwner,
									const char* language = NULL,
									int32 fingerprint = 0) const;
			status_t			UnloadCatalog(BCatalogData* catalogData);

			BCatalogData*		CreateCatalog(const char* type,
									const char* signature,
									const char* language);
};


}	// namespace BPrivate


#endif	// _MUTABLE_LOCALE_ROSTER_H_
