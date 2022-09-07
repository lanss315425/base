// Copyright (c) 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_TASK_DELAY_POLICY_H_
#define BASE_TASK_DELAY_POLICY_H_

namespace base {
namespace subtle {

// Policies affecting how a delayed task is scheduled when a TimeTicks is
// specified.
enum class DelayPolicy {
  // A delayed task with kFlexibleNoSooner may not run any sooner than the
  // specified time, but might run slightly after. This is the behavior implied
  // by PostDelayedTask.
  kFlexibleNoSooner,
  // A delayed task with kFlexiblePreferEarly means the task should attempt to
  // run near the deadline and preferably a little bit before than after if the
  // scheduler applies slack.
  kFlexiblePreferEarly,
  // A delayed task with kPrecise means it may not run any sooner than the
  // specified time and preferably as close as possible to the specified time,
  // which may affect scheduling policies if the scheduler usually applies
  // slack.
  kPrecise,
};

}  // namespace subtle
}  // namespace base

#endif  // BASE_TASK_SEQUENCED_TASK_RUNNER_H_
