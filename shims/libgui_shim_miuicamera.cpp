/*
 * Copyright (C) 2023-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sensor/SensorManager.h>
#include <utils/String16.h>

using namespace android;

extern "C" {

// libgui shim
void _ZN7android18BnProducerListener16onBufferDetachedEi(int slot) {
   (void)slot;
}

// SensorManager shim
// Using a simple return to avoid constructor linking issues in A17
void* _ZN7android13SensorManager13getInstanceEv() {
    return nullptr;
}

// RefBase shim
void _ZNK7android7RefBase10renameRefsEmPKc(void* obj, size_t n, const char* s) {
    // no-op
}

}
