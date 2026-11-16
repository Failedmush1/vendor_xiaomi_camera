/*
 * Copyright (C) 2023-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sensor/SensorManager.h>
#include <gui/IGraphicBufferProducer.h>
#include <utils/String16.h>
#include <utils/Errors.h>
#include <stdint.h>

using namespace android;

extern "C" {

// libgui shims
void _ZN7android18BnProducerListener16onBufferDetachedEi(int slot) {
   (void)slot;
}

extern void* _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE(
        void* thisptr, const sp<IGraphicBufferProducer>& bufferProducer, bool controlledByApp,
        const sp<IBinder>& surfaceControlHandle);

void* _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEb(
        void* thisptr, const sp<IGraphicBufferProducer>& bufferProducer, bool controlledByApp) {
    return _ZN7android7SurfaceC1ERKNS_2spINS_22IGraphicBufferProducerEEEbRKNS1_INS_7IBinderEEE(
            thisptr, bufferProducer, controlledByApp, nullptr);
}

// libui shims
extern status_t _ZN7android13GraphicBuffer4lockEjPPvPiS3_(void* thisptr, uint32_t inUsage, void** vaddr,
                                                   int32_t* outBytesPerPixel,
                                                   int32_t* outBytesPerStride);

status_t _ZN7android13GraphicBuffer4lockEjPPv(void* thisptr, uint32_t inUsage, void** vaddr) {
    return _ZN7android13GraphicBuffer4lockEjPPvPiS3_(thisptr, inUsage, vaddr, nullptr, nullptr);
}

// SensorManager shim
// _ZN7android13SensorManager13getInstanceEv
void* _ZN7android13SensorManager13getInstanceEv() {
    return &SensorManager::getInstanceForPackage(String16("com.android.camera"));
}

// RefBase shim
void _ZNK7android7RefBase10renameRefsEmPKc(void* obj, size_t n, const char* s) {
    // no-op
}

}
