#	$NetBSD: Makefile,v 1.83 2017/01/11 20:43:03 roy Exp $
#	@(#)Makefile	8.2 (Berkeley) 1/2/94

.include <bsd.own.mk>

CPPFLAGS+=-I${.CURDIR}/../../headers/
CFLAGS+=	-Wno-error=multichar -Wno-multichar

SRCS+=	app/AppDefs.cpp
SRCS+=	app/AppMisc.cpp
SRCS+=	app/AppServerLink.cpp
SRCS+=	app/Application.cpp
SRCS+=	app/Clipboard.cpp
SRCS+=	app/Cursor.cpp
SRCS+=	app/DesktopLink.cpp
SRCS+=	app/DirectMessageTarget.cpp
SRCS+=	app/Handler.cpp
SRCS+=	app/InitTerminateLibBe.cpp
SRCS+=	app/Invoker.cpp
SRCS+=	app/Key.cpp
SRCS+=	app/KeyStore.cpp
SRCS+=	app/LaunchRoster.cpp
SRCS+=	app/LinkReceiver.cpp
SRCS+=	app/LinkSender.cpp
SRCS+=	app/Looper.cpp
SRCS+=	app/LooperList.cpp
SRCS+=	app/Message.cpp
SRCS+=	app/MessageAdapter.cpp
SRCS+=	app/MessageFilter.cpp
SRCS+=	app/MessageQueue.cpp
SRCS+=	app/MessageRunner.cpp
SRCS+=	app/MessageUtils.cpp
SRCS+=	app/Messenger.cpp
SRCS+=	app/Notification.cpp
SRCS+=	app/PortLink.cpp
SRCS+=	app/PropertyInfo.cpp
SRCS+=	app/RegistrarDefs.cpp
SRCS+=	app/Roster.cpp
SRCS+=	app/RosterPrivate.cpp
SRCS+=	app/Server.cpp
SRCS+=	app/ServerLink.cpp
SRCS+=	app/ServerMemoryAllocator.cpp
SRCS+=	app/TokenSpace.cpp
SRCS+=	app/TypeConstants.cpp

LIB=	be

NOMAN=	yes

.include <bsd.lib.mk>
