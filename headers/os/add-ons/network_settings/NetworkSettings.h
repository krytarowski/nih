/*
 * Copyright 2006-2015, Haiku, Inc. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Axel Dörfler, axeld@pinc-software.de
 */
#ifndef SETTINGS_H
#define SETTINGS_H


#include <vector>

#include <Message.h>
#include <Messenger.h>
#include <NetworkAddress.h>
#include <Path.h>
#include <StringList.h>


namespace BNetworkKit {


class BNetworkSettings {
public:
	static	const uint32		kMsgInterfaceSettingsUpdated = 'SUif';
	static	const uint32		kMsgNetworkSettingsUpdated = 'SUnw';
	static	const uint32		kMsgServiceSettingsUpdated = 'SUsv';

public:
								BNetworkSettings();
								~BNetworkSettings();

			status_t			GetNextInterface(uint32& cookie,
									BMessage& interface);
			status_t			GetInterface(const char* name,
									BMessage& interface);
			status_t			AddInterface(const BMessage& interface);
			status_t			RemoveInterface(const char* name);

			int32				CountNetworks() const;
			status_t			GetNextNetwork(uint32& cookie,
									BMessage& network) const;
			status_t			GetNetwork(const char* name,
									BMessage& network);
			status_t			AddNetwork(const BMessage& network);
			status_t			RemoveNetwork(const char* name);

			const BMessage&		Services() const;
			status_t			GetNextService(uint32& cookie,
									BMessage& service);
			status_t			GetService(const char* name, BMessage& service);
			status_t			AddService(const BMessage& service);
			status_t			RemoveService(const char* name);

			status_t			StartMonitoring(const BMessenger& target);
			status_t			StopMonitoring(const BMessenger& target);

			status_t			Update(BMessage* message);

private:
			status_t			_Load(const char* name = NULL,
									uint32* _type = NULL);
			status_t			_Save(const char* name = NULL);
			BPath				_Path(BPath& parent, const char* name);
			status_t			_GetPath(const char* name, BPath& path);

			status_t			_StartWatching(const char* name,
									const BMessenger& target);

			bool				_IsWatching(const BMessenger& target) const
									{ return fListener == target; }
			bool				_IsWatching() const
									{ return fListener.IsValid(); }

			status_t			_ConvertNetworkToSettings(BMessage& message);
			status_t			_ConvertNetworkFromSettings(BMessage& message);

			status_t			_GetItem(BMessage& container,
									const char* itemField,
									const char* nameField, const char* name,
									int32& _index, BMessage& item);
			status_t			_RemoveItem(BMessage& container,
									const char* itemField,
									const char* nameField, const char* name,
									const char* store = NULL);

private:
			BMessenger			fListener;
			BMessage			fInterfaces;
			BMessage			fNetworks;
			BMessage			fServices;
};


class BNetworkInterfaceAddressSettings {
public:
								BNetworkInterfaceAddressSettings(
									const BMessage& data);
								~BNetworkInterfaceAddressSettings();

			int					Family() const;
			bool				AutoConfigure() const;

			const BNetworkAddress&
								Address() const;
			const BNetworkAddress&
								Mask() const;
			const BNetworkAddress&
								Peer() const;
			const BNetworkAddress&
								Broadcast() const;
			const BNetworkAddress&
								Gateway() const;

private:
			int32				fFamily;
			bool				fAutoConfigure;
			BNetworkAddress		fAddress;
			BNetworkAddress		fMask;
			BNetworkAddress		fPeer;
			BNetworkAddress		fBroadcast;
			BNetworkAddress		fGateway;
};


class BNetworkInterfaceSettings {
public:
								BNetworkInterfaceSettings(
									const BMessage& message);
								~BNetworkInterfaceSettings();

			const char*			Name() const;

};


}	// namespace BNetworkKit


class BNetworkServiceAddressSettings {
public:
								BNetworkServiceAddressSettings();
								BNetworkServiceAddressSettings(
									const BMessage& data, int family = -1,
									int type = -1, int protocol = -1,
									int port = -1);
								~BNetworkServiceAddressSettings();

			int					Family() const;
			void				SetFamily(int family);
			int					Protocol() const;
			void				SetProtocol(int protocol);
			int					Type() const;
			void				SetType(int type);

			const BNetworkAddress&
								Address() const;
			BNetworkAddress&	Address();

			status_t			GetMessage(BMessage& data);

			bool				operator==(
									const BNetworkServiceAddressSettings& other)
										const;

private:
			int32				fFamily;
			int					fProtocol;
			int					fType;
			BNetworkAddress		fAddress;
};


class BNetworkServiceSettings {
public:
								BNetworkServiceSettings(
									const BMessage& message);
								~BNetworkServiceSettings();

			status_t			InitCheck() const;

			const char*			Name() const;
			bool				IsStandAlone() const;

			int32				CountArguments() const;
			const char*			ArgumentAt(int32 index) const;

			int32				CountAddresses() const;
			const BNetworkServiceAddressSettings&
								AddressAt(int32 index) const;

private:
			const BMessage&		fData;
			BStringList			fArguments;
			std::vector<BNetworkServiceAddressSettings>
								fAddresses;
};


#endif	// SETTINGS_H