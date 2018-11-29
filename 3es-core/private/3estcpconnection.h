//
// author: Kazys Stepanas
//
#ifndef _3ESTCPCONNECTION_H_
#define _3ESTCPCONNECTION_H_

#include "../3esserver.h"

#include "3esbaseconnection.h"

namespace tes
{
  class TcpSocket;

  class TcpConnection : public BaseConnection
  {
  public:
    /// Create a new connection using the given @p clientSocket.
    /// @param clientSocket The socket to communicate on.
    /// @param settings Various server settings to initialise with.
    TcpConnection(TcpSocket *clientSocket, const ServerSettings &settings);
    ~TcpConnection();

    /// Close the socket connection.
    void close() override;

    const char *address() const override;
    uint16_t port() const override;
    bool isConnected() const override;

  protected:
    int writeBytes(const uint8_t *data, int byteCount) override;

  private:
    TcpSocket *_client;
  };
}

#endif // _3ESTCPCONNECTION_H_
