/*
 * SPDX-License-Identifier: Apache-2.0
 */

//===---------- Passes.hpp - ONNX MLIR Passes Definition ------------------===//
//
// Copyright 2019-2020 The IBM Research Authors.
//
// =============================================================================
//
// This file exposes the entry points to create compiler passes for ONNX MLIR.
//
//===----------------------------------------------------------------------===//

#pragma once

#include <memory>

namespace mlir {
class Pass;

/// Pass for rewriting inside frontend dialect.
std::unique_ptr<Pass> createDecomposeONNXToONNXPass();

std::unique_ptr<Pass> createShapeInferencePass(
    bool analyzeAllFunctions = false);

std::unique_ptr<Pass> createConstPropONNXToONNXPass();

/// Pass for eliding the values of constant operations.
std::unique_ptr<Pass> createElideConstantValuePass();

/// Pass for enabling a memory pool for MemRefs.
std::unique_ptr<Pass> createKrnlEnableMemoryPoolPass();

/// Pass for enabling a memory pool for MemRefs.
std::unique_ptr<Pass> createKrnlBundleMemoryPoolsPass();

/// Pass for optimizing memory pools.
std::unique_ptr<Pass> createKrnlOptimizeMemoryPoolsPass();

/// Pass for instrument the Onnx ops
std::unique_ptr<Pass> createInstrumentONNXPass();

/// Add pass for lowering to Krnl IR.
std::unique_ptr<Pass> createLowerToKrnlPass();

/// Pass for lowering frontend dialects to Krnl IR dialect.
std::unique_ptr<Pass> createConvertKrnlToAffinePass();

/// Pass for lowering krnl.dim operations to standard dialect.
std::unique_ptr<Pass> createDisconnectKrnlDimFromAllocPass();

/// Pass for lowering krnl.shape operation.
std::unique_ptr<Pass> createLowerKrnlShapePass();

/// Pass for eliding the values of global Krnl operations.
std::unique_ptr<Pass> createElideConstGlobalValuePass();

/// Pass for lowering Krnl dialect to LLVM dialect.
std::unique_ptr<Pass> createConvertKrnlToLLVMPass();

} // end namespace mlir
