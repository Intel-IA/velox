/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <qpl/qpl.h>
#include <iostream>
#include <memory>

class Qplcodec {
 public:
  Qplcodec(qpl_path_t execute_path, qpl_compression_levels compression_level)
      : initialize_job(false),
        execute_path_(execute_path),
        compression_level_(compression_level),
        job_(NULL),
        job_buffer(NULL){};
  ~Qplcodec();
  void Initjob();
  void Decompress(
      int64_t input_length,
      const uint8_t* input,
      int64_t output_buffer_length,
      uint8_t* output);
  void Compress(
      int64_t input_length,
      const uint8_t* input,
      int64_t output_buffer_length,
      uint8_t* output);

 private:
  bool initialize_job;
  qpl_path_t execute_path_;
  qpl_compression_levels compression_level_;
  qpl_job* job_;
  uint8_t* job_buffer;
};
