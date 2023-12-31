// Copyright 2023 The gRPC Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef GRPC_SRC_CORE_LIB_EVENT_ENGINE_WINDOWS_WINDOWS_LISTENER_H
#define GRPC_SRC_CORE_LIB_EVENT_ENGINE_WINDOWS_WINDOWS_LISTENER_H

#include <grpc/support/port_platform.h>

#ifdef GPR_WINDOWS

#include <list>

#include "y_absl/base/thread_annotations.h"
#include "y_absl/status/statusor.h"

#include <grpc/event_engine/event_engine.h>
#include <grpc/event_engine/memory_allocator.h>

#include "src/core/lib/event_engine/common_closures.h"
#include "src/core/lib/event_engine/windows/iocp.h"
#include "src/core/lib/gprpp/sync.h"

namespace grpc_event_engine {
namespace experimental {

class WindowsEventEngineListener : public EventEngine::Listener {
 public:
  WindowsEventEngineListener(
      IOCP* iocp, AcceptCallback accept_cb,
      y_absl::AnyInvocable<void(y_absl::Status)> on_shutdown,
      std::unique_ptr<MemoryAllocatorFactory> memory_allocator_factory,
      std::shared_ptr<EventEngine> engine, Executor* executor_,
      const EndpointConfig& config);
  ~WindowsEventEngineListener() override;
  y_absl::StatusOr<int> Bind(const EventEngine::ResolvedAddress& addr) override;
  y_absl::Status Start() override;
  // TODO(hork): this may only be needed for the iomgr shim, to accommodate
  // calls to grpc_tcp_server_shutdown_listeners
  void ShutdownListeners();

 private:
  /// Responsible for listening on a single port.
  class SinglePortSocketListener {
   public:
    ~SinglePortSocketListener();
    // This factory will create a bound, listening WinSocket, registered with
    // the listener's IOCP poller.
    static y_absl::StatusOr<std::unique_ptr<SinglePortSocketListener>> Create(
        WindowsEventEngineListener* listener, SOCKET sock,
        EventEngine::ResolvedAddress addr);

    // Two-stage initialization, allows creation of all bound sockets before the
    // listener is started.
    y_absl::Status Start();
    y_absl::Status StartLocked() Y_ABSL_EXCLUSIVE_LOCKS_REQUIRED(io_state_->mu);

    // Accessor methods
    EventEngine::ResolvedAddress listener_sockname() {
      return listener_sockname_;
    };
    int port() { return port_; }

   private:
    struct AsyncIOState;

    class OnAcceptCallbackWrapper : public EventEngine::Closure {
     public:
      void Run() override;
      void Prime(std::shared_ptr<AsyncIOState> io_state);

     private:
      std::shared_ptr<AsyncIOState> io_state_;
    };

    // A class to manage the data that must outlive the Endpoint.
    //
    // Once a listener is done and destroyed, there still may be overlapped
    // operations pending. To clean up safely, this data must outlive the
    // Listener, and be destroyed asynchronously when all pending overlapped
    // events are complete.
    struct AsyncIOState {
      AsyncIOState(SinglePortSocketListener* port_listener,
                   std::unique_ptr<WinSocket> listener_socket);
      ~AsyncIOState();
      SinglePortSocketListener* const port_listener;
      OnAcceptCallbackWrapper on_accept_cb;
      // Synchronize accept handling on the same socket.
      grpc_core::Mutex mu;
      // This will hold the socket for the next accept.
      SOCKET accept_socket Y_ABSL_GUARDED_BY(mu) = INVALID_SOCKET;
      // The listener winsocket.
      std::unique_ptr<WinSocket> listener_socket Y_ABSL_GUARDED_BY(mu);
    };

    SinglePortSocketListener(WindowsEventEngineListener* listener,
                             LPFN_ACCEPTEX AcceptEx,
                             std::unique_ptr<WinSocket> listener_socket,
                             int port, EventEngine::ResolvedAddress hostbyname);

    // Bind a recently-created socket for listening
    struct PrepareListenerSocketResult {
      int port;
      EventEngine::ResolvedAddress hostbyname;
    };
    static y_absl::StatusOr<PrepareListenerSocketResult> PrepareListenerSocket(
        SOCKET sock, const EventEngine::ResolvedAddress& addr);

    void OnAcceptCallbackLocked() Y_ABSL_EXCLUSIVE_LOCKS_REQUIRED(io_state_->mu);

    // The cached AcceptEx for that port.
    LPFN_ACCEPTEX AcceptEx;
    // This seemingly magic number comes from AcceptEx's documentation. each
    // address buffer needs to have at least 16 more bytes at their end.
    uint8_t addresses_[(sizeof(sockaddr_in6) + 16) * 2] = {};
    // The parent listener
    WindowsEventEngineListener* listener_;
    // shared state for asynchronous cleanup of overlapped operations
    std::shared_ptr<AsyncIOState> io_state_;
    // The actual TCP port number.
    int port_;
    EventEngine::ResolvedAddress listener_sockname_;
  };
  y_absl::StatusOr<SinglePortSocketListener*> AddSinglePortSocketListener(
      SOCKET sock, EventEngine::ResolvedAddress addr);

  IOCP* const iocp_;
  const EndpointConfig& config_;
  std::shared_ptr<EventEngine> engine_;
  Executor* executor_;
  const std::unique_ptr<MemoryAllocatorFactory> memory_allocator_factory_;
  AcceptCallback accept_cb_;
  y_absl::AnyInvocable<void(y_absl::Status)> on_shutdown_;
  std::atomic<bool> started_{false};
  grpc_core::Mutex port_listeners_mu_;
  std::list<std::unique_ptr<SinglePortSocketListener>> port_listeners_
      Y_ABSL_GUARDED_BY(port_listeners_mu_);
  bool listeners_shutdown_ Y_ABSL_GUARDED_BY(port_listeners_mu_) = false;
};

}  // namespace experimental
}  // namespace grpc_event_engine

#endif

#endif  // GRPC_SRC_CORE_LIB_EVENT_ENGINE_WINDOWS_WINDOWS_LISTENER_H
