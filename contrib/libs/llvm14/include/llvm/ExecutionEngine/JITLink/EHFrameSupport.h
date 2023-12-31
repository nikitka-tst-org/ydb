#pragma once

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//===--------- EHFrameSupport.h - JITLink eh-frame utils --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// EHFrame registration support for JITLink.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_EXECUTIONENGINE_JITLINK_EHFRAMESUPPORT_H
#define LLVM_EXECUTIONENGINE_JITLINK_EHFRAMESUPPORT_H

#include "llvm/ADT/Triple.h"
#include "llvm/ExecutionEngine/JITLink/JITLink.h"
#include "llvm/ExecutionEngine/JITSymbol.h"
#include "llvm/Support/Error.h"

namespace llvm {
namespace jitlink {

/// Supports registration/deregistration of EH-frames in a target process.
class EHFrameRegistrar {
public:
  virtual ~EHFrameRegistrar();
  virtual Error registerEHFrames(orc::ExecutorAddrRange EHFrameSection) = 0;
  virtual Error deregisterEHFrames(orc::ExecutorAddrRange EHFrameSection) = 0;
};

/// Registers / Deregisters EH-frames in the current process.
class InProcessEHFrameRegistrar final : public EHFrameRegistrar {
public:
  Error registerEHFrames(orc::ExecutorAddrRange EHFrameSection) override;

  Error deregisterEHFrames(orc::ExecutorAddrRange EHFrameSection) override;
};

using StoreFrameRangeFunction = std::function<void(
    orc::ExecutorAddr EHFrameSectionAddr, size_t EHFrameSectionSize)>;

/// Creates a pass that records the address and size of the EH frame section.
/// If no eh-frame section is found then the address and size will both be given
/// as zero.
///
/// Authors of JITLinkContexts can use this function to register a post-fixup
/// pass that records the range of the eh-frame section. This range can
/// be used after finalization to register and deregister the frame.
LinkGraphPassFunction
createEHFrameRecorderPass(const Triple &TT,
                          StoreFrameRangeFunction StoreFrameRange);

} // end namespace jitlink
} // end namespace llvm

#endif // LLVM_EXECUTIONENGINE_JITLINK_EHFRAMESUPPORT_H

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
