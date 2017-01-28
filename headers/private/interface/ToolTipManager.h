/*
 * Copyright 2009, Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _TOOL_TIP_MANAGER_H
#define _TOOL_TIP_MANAGER_H


#include <os/support/Locker.h>
#include <os/app/Messenger.h>
#include <os/interface/Point.h>


class BToolTip;


class BToolTipManager {
public:
	static	BToolTipManager*	Manager();

			void				ShowTip(BToolTip* tip, BPoint where,
									void* owner);
			void				HideTip();

			void				SetShowDelay(bigtime_t time);
			bigtime_t			ShowDelay() const;
			void				SetHideDelay(bigtime_t time);
			bigtime_t			HideDelay() const;

			bool				Lock()		{ return fLock.Lock(); }
			void				Unlock()	{ fLock.Unlock(); }

private:
								BToolTipManager();
	virtual						~BToolTipManager();

	static	void				_InitSingleton();

private:
			BLocker				fLock;
			BMessenger			fWindow;

			bigtime_t			fShowDelay;
			bigtime_t			fHideDelay;

	static	BToolTipManager*	sDefaultInstance;
};


#endif	// _TOOL_TIP_MANAGER_H
