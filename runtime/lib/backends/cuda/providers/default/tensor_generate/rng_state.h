//===- rng_state.h -------------------------------------------------*--- C++
//-*-===//
//
// Copyright 2022 ByteDance Ltd. and/or its affiliates. All rights reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//===----------------------------------------------------------------------===//

#pragma once

#include "brt/backends/cuda/device/common/util.h"
#include "brt/core/framework/dtype.h"
#include "brt/core/framework/op_kernel.h"

namespace brt {
namespace cuda {
class NextOffsetOpKernel final : public OpKernel {
public:
  explicit NextOffsetOpKernel(const OpKernelInfo &info);
  common::Status RunImpl(const ExecutionContext &) override;
  common::Status ProloguePerFrame(const ExecutionContext &) override;
  common::Status EpiloguePerFrame(const ExecutionContext &) override;
};

class GetSeedOpKernel final : public OpKernel {
public:
  explicit GetSeedOpKernel(const OpKernelInfo &info);
  common::Status RunImpl(const ExecutionContext &) override;
  common::Status ProloguePerFrame(const ExecutionContext &) override;
  common::Status EpiloguePerFrame(const ExecutionContext &) override;
};

} // namespace cuda
} // namespace brt