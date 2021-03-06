/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2017-2020 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
 ***********************************************************************************************************************
 * @file  llpcPatchPushConstOp.h
 * @brief LLPC header file: contains declaration of class Llpc::PatchPushConstOp.
 ***********************************************************************************************************************
 */
#pragma once

#include "llpcPatch.h"

namespace llvm
{

class CallInst;

}

namespace Llpc
{

class PipelineState;

// =====================================================================================================================
// Represents the pass of LLVM patching opertions for push constant operations.
class PatchPushConstOp:
    public Patch
{
public:
    PatchPushConstOp();

    void getAnalysisUsage(llvm::AnalysisUsage& analysisUsage) const override;
    bool runOnModule(llvm::Module& module) override;

    // -----------------------------------------------------------------------------------------------------------------

    static char ID; // ID of this pass

private:
    PatchPushConstOp(const PatchPushConstOp&) = delete;
    PatchPushConstOp& operator=(const PatchPushConstOp&) = delete;

    void visitCallInst(llvm::CallInst& callInst);

    // -----------------------------------------------------------------------------------------------------------------

    llvm::SmallVector<llvm::Instruction*, 8> m_instsToRemove;   // List of instructions to remove.
    PipelineState*  m_pPipelineState = nullptr;                 // Pipeline state from PipelineStateWrapper pass
};

} // Llpc
