/***************************************************************************
 *  Copyright (c) 2011, Resara LLC                                         *
 *  All rights reserved.                                                   *
 *                                                                         *
 *  Redistribution and use in source and binary forms, with or without     *
 *  modification, are permitted provided that the following conditions are *
 *  met:                                                                   *
 *      * Redistributions of source code must retain the above copyright   *
 *        notice, this list of conditions and the following disclaimer.    *
 *      * Redistributions in binary form must reproduce the above          *
 *        copyright notice, this list of conditions and the following      *
 *        disclaimer in the documentation and/or other materials           *
 *        provided with the distribution.                                  *
 *      * Neither the name of Resara LLC nor the names of its              *
 *        contributors may be used to endorse or promote products          *
 *        derived from this software without specific prior written        *
 *        permission.                                                      *
 *                                                                         *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL RESARA LLC BE   *
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    *
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   *
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR        *
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE   *
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN *
 *  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          *
 *                                                                         *
 ***************************************************************************/
#ifndef QTRPCCLIENTPROTOCOLSOCKET_H
#define QTRPCCLIENTPROTOCOLSOCKET_H

#include <ClientProtocolIODevice>
#include <qtrpcprivate.h>
class QLocalSocket;

namespace QtRpc
{

	class ClientProtocolSocketPrivate;
/**
	This is the client Socket implementation of the ClientProtocolIODevice. It is used when the protocol is "socket". This class should never be used directly, but instead intiated and used through a ClientMessageBus.

	@sa ClientProtocolIODevice ClientMessageBus ServerProtocolInstanceSocket

	@brief Socket implementation of the ClientProtocolIODevice
	@author Brendan Powers <brendan@resara.com>
*/
class ClientProtocolSocket : public ClientProtocolIODevice
{
	QXT_DECLARE_PRIVATE(ClientProtocolSocket);
	Q_OBJECT
public:
	ClientProtocolSocket(QObject *parent = 0);

	~ClientProtocolSocket();

protected slots:
	virtual void connected();
protected:
	virtual ReturnValue setProperty(QString, QVariant);
	virtual ReturnValue getProperty(QString);
	virtual void protocolConnect();
	virtual ReturnValue protocolDisconnect();
	virtual void protocolFunction(Signature, Arguments);
	virtual bool isConnected();
	virtual QString getServiceName();
};

}

#endif
