/*

    This file was generated with mantleloader_gen.py, part of mantleapi
    (hosted at https://github.com/kwertz/mantleapi)

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef __mantleloader_h_
#define __mantleloader_h_

#include <GR/mantle.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GRLgrProc)(void);

/* mantleloader api */
int grlInit(void);
void grlShutdown(void);
GRLgrProc grlGetProcAddress(const char *proc);

/* Mantle functions */
extern grAllocMemoryFn*                                     grlAllocMemory;
extern grAttachImageViewDescriptorsFn*                      grlAttachImageViewDescriptors;
extern grAttachMemoryViewDescriptorsFn*                     grlAttachMemoryViewDescriptors;
extern grAttachNestedDescriptorsFn*                         grlAttachNestedDescriptors;
extern grAttachSamplerDescriptorsFn*                        grlAttachSamplerDescriptors;
extern grBeginCommandBufferFn*                              grlBeginCommandBuffer;
extern grBeginDescriptorSetUpdateFn*                        grlBeginDescriptorSetUpdate;
extern grBindObjectMemoryFn*                                grlBindObjectMemory;
extern grClearDescriptorSetSlotsFn*                         grlClearDescriptorSetSlots;
extern grCmdBeginQueryFn*                                   grlCmdBeginQuery;
extern grCmdBindDescriptorSetFn*                            grlCmdBindDescriptorSet;
extern grCmdBindDynamicMemoryViewFn*                        grlCmdBindDynamicMemoryView;
extern grCmdBindIndexDataFn*                                grlCmdBindIndexData;
extern grCmdBindPipelineFn*                                 grlCmdBindPipeline;
extern grCmdBindStateObjectFn*                              grlCmdBindStateObject;
extern grCmdBindTargetsFn*                                  grlCmdBindTargets;
extern grCmdClearColorImageFn*                              grlCmdClearColorImage;
extern grCmdClearColorImageRawFn*                           grlCmdClearColorImageRaw;
extern grCmdClearDepthStencilFn*                            grlCmdClearDepthStencil;
extern grCmdCloneImageDataFn*                               grlCmdCloneImageData;
extern grCmdCopyImageFn*                                    grlCmdCopyImage;
extern grCmdCopyImageToMemoryFn*                            grlCmdCopyImageToMemory;
extern grCmdCopyMemoryFn*                                   grlCmdCopyMemory;
extern grCmdCopyMemoryToImageFn*                            grlCmdCopyMemoryToImage;
extern grCmdDbgMarkerBeginFn*                               grlCmdDbgMarkerBegin;
extern grCmdDbgMarkerEndFn*                                 grlCmdDbgMarkerEnd;
extern grCmdDispatchFn*                                     grlCmdDispatch;
extern grCmdDispatchIndirectFn*                             grlCmdDispatchIndirect;
extern grCmdDrawFn*                                         grlCmdDraw;
extern grCmdDrawIndexedFn*                                  grlCmdDrawIndexed;
extern grCmdDrawIndexedIndirectFn*                          grlCmdDrawIndexedIndirect;
extern grCmdDrawIndirectFn*                                 grlCmdDrawIndirect;
extern grCmdEndQueryFn*                                     grlCmdEndQuery;
extern grCmdFillMemoryFn*                                   grlCmdFillMemory;
extern grCmdInitAtomicCountersFn*                           grlCmdInitAtomicCounters;
extern grCmdLoadAtomicCountersFn*                           grlCmdLoadAtomicCounters;
extern grCmdMemoryAtomicFn*                                 grlCmdMemoryAtomic;
extern grCmdPrepareImagesFn*                                grlCmdPrepareImages;
extern grCmdPrepareMemoryRegionsFn*                         grlCmdPrepareMemoryRegions;
extern grCmdResetEventFn*                                   grlCmdResetEvent;
extern grCmdResetQueryPoolFn*                               grlCmdResetQueryPool;
extern grCmdResolveImageFn*                                 grlCmdResolveImage;
extern grCmdSaveAtomicCountersFn*                           grlCmdSaveAtomicCounters;
extern grCmdSetEventFn*                                     grlCmdSetEvent;
extern grCmdUpdateMemoryFn*                                 grlCmdUpdateMemory;
extern grCmdWriteTimestampFn*                               grlCmdWriteTimestamp;
extern grCreateColorBlendStateFn*                           grlCreateColorBlendState;
extern grCreateColorTargetViewFn*                           grlCreateColorTargetView;
extern grCreateCommandBufferFn*                             grlCreateCommandBuffer;
extern grCreateComputePipelineFn*                           grlCreateComputePipeline;
extern grCreateDepthStencilStateFn*                         grlCreateDepthStencilState;
extern grCreateDepthStencilViewFn*                          grlCreateDepthStencilView;
extern grCreateDescriptorSetFn*                             grlCreateDescriptorSet;
extern grCreateDeviceFn*                                    grlCreateDevice;
extern grCreateEventFn*                                     grlCreateEvent;
extern grCreateFenceFn*                                     grlCreateFence;
extern grCreateGraphicsPipelineFn*                          grlCreateGraphicsPipeline;
extern grCreateImageFn*                                     grlCreateImage;
extern grCreateImageViewFn*                                 grlCreateImageView;
extern grCreateMsaaStateFn*                                 grlCreateMsaaState;
extern grCreateQueryPoolFn*                                 grlCreateQueryPool;
extern grCreateQueueSemaphoreFn*                            grlCreateQueueSemaphore;
extern grCreateRasterStateFn*                               grlCreateRasterState;
extern grCreateSamplerFn*                                   grlCreateSampler;
extern grCreateShaderFn*                                    grlCreateShader;
extern grCreateViewportStateFn*                             grlCreateViewportState;
extern grDbgRegisterMsgCallbackFn*                          grlDbgRegisterMsgCallback;
extern grDbgSetDeviceOptionFn*                              grlDbgSetDeviceOption;
extern grDbgSetGlobalOptionFn*                              grlDbgSetGlobalOption;
extern grDbgSetMessageFilterFn*                             grlDbgSetMessageFilter;
extern grDbgSetObjectTagFn*                                 grlDbgSetObjectTag;
extern grDbgSetValidationLevelFn*                           grlDbgSetValidationLevel;
extern grDbgUnregisterMsgCallbackFn*                        grlDbgUnregisterMsgCallback;
extern grDestroyDeviceFn*                                   grlDestroyDevice;
extern grDestroyObjectFn*                                   grlDestroyObject;
extern grDeviceWaitIdleFn*                                  grlDeviceWaitIdle;
extern grEndCommandBufferFn*                                grlEndCommandBuffer;
extern grEndDescriptorSetUpdateFn*                          grlEndDescriptorSetUpdate;
extern grFreeMemoryFn*                                      grlFreeMemory;
extern grGetDeviceQueueFn*                                  grlGetDeviceQueue;
extern grGetEventStatusFn*                                  grlGetEventStatus;
extern grGetExtensionSupportFn*                             grlGetExtensionSupport;
extern grGetFenceStatusFn*                                  grlGetFenceStatus;
extern grGetFormatInfoFn*                                   grlGetFormatInfo;
extern grGetGpuInfoFn*                                      grlGetGpuInfo;
extern grGetImageSubresourceInfoFn*                         grlGetImageSubresourceInfo;
extern grGetMemoryHeapCountFn*                              grlGetMemoryHeapCount;
extern grGetMemoryHeapInfoFn*                               grlGetMemoryHeapInfo;
extern grGetMultiGpuCompatibilityFn*                        grlGetMultiGpuCompatibility;
extern grGetObjectInfoFn*                                   grlGetObjectInfo;
extern grGetQueryPoolResultsFn*                             grlGetQueryPoolResults;
extern grInitAndEnumerateGpusFn*                            grlInitAndEnumerateGpus;
extern grLoadPipelineFn*                                    grlLoadPipeline;
extern grMapMemoryFn*                                       grlMapMemory;
extern grOpenPeerImageFn*                                   grlOpenPeerImage;
extern grOpenPeerMemoryFn*                                  grlOpenPeerMemory;
extern grOpenSharedMemoryFn*                                grlOpenSharedMemory;
extern grOpenSharedQueueSemaphoreFn*                        grlOpenSharedQueueSemaphore;
extern grPinSystemMemoryFn*                                 grlPinSystemMemory;
extern grQueueSetGlobalMemReferencesFn*                     grlQueueSetGlobalMemReferences;
extern grQueueSubmitFn*                                     grlQueueSubmit;
extern grQueueWaitIdleFn*                                   grlQueueWaitIdle;
extern grRemapVirtualMemoryPagesFn*                         grlRemapVirtualMemoryPages;
extern grResetCommandBufferFn*                              grlResetCommandBuffer;
extern grResetEventFn*                                      grlResetEvent;
extern grSetEventFn*                                        grlSetEvent;
extern grSetMemoryPriorityFn*                               grlSetMemoryPriority;
extern grSignalQueueSemaphoreFn*                            grlSignalQueueSemaphore;
extern grStorePipelineFn*                                   grlStorePipeline;
extern grUnmapMemoryFn*                                     grlUnmapMemory;
extern grWaitForFencesFn*                                   grlWaitForFences;
extern grWaitQueueSemaphoreFn*                              grlWaitQueueSemaphore;

#define grAllocMemory                                 grlAllocMemory
#define grAttachImageViewDescriptors                  grlAttachImageViewDescriptors
#define grAttachMemoryViewDescriptors                 grlAttachMemoryViewDescriptors
#define grAttachNestedDescriptors                     grlAttachNestedDescriptors
#define grAttachSamplerDescriptors                    grlAttachSamplerDescriptors
#define grBeginCommandBuffer                          grlBeginCommandBuffer
#define grBeginDescriptorSetUpdate                    grlBeginDescriptorSetUpdate
#define grBindObjectMemory                            grlBindObjectMemory
#define grClearDescriptorSetSlots                     grlClearDescriptorSetSlots
#define grCmdBeginQuery                               grlCmdBeginQuery
#define grCmdBindDescriptorSet                        grlCmdBindDescriptorSet
#define grCmdBindDynamicMemoryView                    grlCmdBindDynamicMemoryView
#define grCmdBindIndexData                            grlCmdBindIndexData
#define grCmdBindPipeline                             grlCmdBindPipeline
#define grCmdBindStateObject                          grlCmdBindStateObject
#define grCmdBindTargets                              grlCmdBindTargets
#define grCmdClearColorImage                          grlCmdClearColorImage
#define grCmdClearColorImageRaw                       grlCmdClearColorImageRaw
#define grCmdClearDepthStencil                        grlCmdClearDepthStencil
#define grCmdCloneImageData                           grlCmdCloneImageData
#define grCmdCopyImage                                grlCmdCopyImage
#define grCmdCopyImageToMemory                        grlCmdCopyImageToMemory
#define grCmdCopyMemory                               grlCmdCopyMemory
#define grCmdCopyMemoryToImage                        grlCmdCopyMemoryToImage
#define grCmdDbgMarkerBegin                           grlCmdDbgMarkerBegin
#define grCmdDbgMarkerEnd                             grlCmdDbgMarkerEnd
#define grCmdDispatch                                 grlCmdDispatch
#define grCmdDispatchIndirect                         grlCmdDispatchIndirect
#define grCmdDraw                                     grlCmdDraw
#define grCmdDrawIndexed                              grlCmdDrawIndexed
#define grCmdDrawIndexedIndirect                      grlCmdDrawIndexedIndirect
#define grCmdDrawIndirect                             grlCmdDrawIndirect
#define grCmdEndQuery                                 grlCmdEndQuery
#define grCmdFillMemory                               grlCmdFillMemory
#define grCmdInitAtomicCounters                       grlCmdInitAtomicCounters
#define grCmdLoadAtomicCounters                       grlCmdLoadAtomicCounters
#define grCmdMemoryAtomic                             grlCmdMemoryAtomic
#define grCmdPrepareImages                            grlCmdPrepareImages
#define grCmdPrepareMemoryRegions                     grlCmdPrepareMemoryRegions
#define grCmdResetEvent                               grlCmdResetEvent
#define grCmdResetQueryPool                           grlCmdResetQueryPool
#define grCmdResolveImage                             grlCmdResolveImage
#define grCmdSaveAtomicCounters                       grlCmdSaveAtomicCounters
#define grCmdSetEvent                                 grlCmdSetEvent
#define grCmdUpdateMemory                             grlCmdUpdateMemory
#define grCmdWriteTimestamp                           grlCmdWriteTimestamp
#define grCreateColorBlendState                       grlCreateColorBlendState
#define grCreateColorTargetView                       grlCreateColorTargetView
#define grCreateCommandBuffer                         grlCreateCommandBuffer
#define grCreateComputePipeline                       grlCreateComputePipeline
#define grCreateDepthStencilState                     grlCreateDepthStencilState
#define grCreateDepthStencilView                      grlCreateDepthStencilView
#define grCreateDescriptorSet                         grlCreateDescriptorSet
#define grCreateDevice                                grlCreateDevice
#define grCreateEvent                                 grlCreateEvent
#define grCreateFence                                 grlCreateFence
#define grCreateGraphicsPipeline                      grlCreateGraphicsPipeline
#define grCreateImage                                 grlCreateImage
#define grCreateImageView                             grlCreateImageView
#define grCreateMsaaState                             grlCreateMsaaState
#define grCreateQueryPool                             grlCreateQueryPool
#define grCreateQueueSemaphore                        grlCreateQueueSemaphore
#define grCreateRasterState                           grlCreateRasterState
#define grCreateSampler                               grlCreateSampler
#define grCreateShader                                grlCreateShader
#define grCreateViewportState                         grlCreateViewportState
#define grDbgRegisterMsgCallback                      grlDbgRegisterMsgCallback
#define grDbgSetDeviceOption                          grlDbgSetDeviceOption
#define grDbgSetGlobalOption                          grlDbgSetGlobalOption
#define grDbgSetMessageFilter                         grlDbgSetMessageFilter
#define grDbgSetObjectTag                             grlDbgSetObjectTag
#define grDbgSetValidationLevel                       grlDbgSetValidationLevel
#define grDbgUnregisterMsgCallback                    grlDbgUnregisterMsgCallback
#define grDestroyDevice                               grlDestroyDevice
#define grDestroyObject                               grlDestroyObject
#define grDeviceWaitIdle                              grlDeviceWaitIdle
#define grEndCommandBuffer                            grlEndCommandBuffer
#define grEndDescriptorSetUpdate                      grlEndDescriptorSetUpdate
#define grFreeMemory                                  grlFreeMemory
#define grGetDeviceQueue                              grlGetDeviceQueue
#define grGetEventStatus                              grlGetEventStatus
#define grGetExtensionSupport                         grlGetExtensionSupport
#define grGetFenceStatus                              grlGetFenceStatus
#define grGetFormatInfo                               grlGetFormatInfo
#define grGetGpuInfo                                  grlGetGpuInfo
#define grGetImageSubresourceInfo                     grlGetImageSubresourceInfo
#define grGetMemoryHeapCount                          grlGetMemoryHeapCount
#define grGetMemoryHeapInfo                           grlGetMemoryHeapInfo
#define grGetMultiGpuCompatibility                    grlGetMultiGpuCompatibility
#define grGetObjectInfo                               grlGetObjectInfo
#define grGetQueryPoolResults                         grlGetQueryPoolResults
#define grInitAndEnumerateGpus                        grlInitAndEnumerateGpus
#define grLoadPipeline                                grlLoadPipeline
#define grMapMemory                                   grlMapMemory
#define grOpenPeerImage                               grlOpenPeerImage
#define grOpenPeerMemory                              grlOpenPeerMemory
#define grOpenSharedMemory                            grlOpenSharedMemory
#define grOpenSharedQueueSemaphore                    grlOpenSharedQueueSemaphore
#define grPinSystemMemory                             grlPinSystemMemory
#define grQueueSetGlobalMemReferences                 grlQueueSetGlobalMemReferences
#define grQueueSubmit                                 grlQueueSubmit
#define grQueueWaitIdle                               grlQueueWaitIdle
#define grRemapVirtualMemoryPages                     grlRemapVirtualMemoryPages
#define grResetCommandBuffer                          grlResetCommandBuffer
#define grResetEvent                                  grlResetEvent
#define grSetEvent                                    grlSetEvent
#define grSetMemoryPriority                           grlSetMemoryPriority
#define grSignalQueueSemaphore                        grlSignalQueueSemaphore
#define grStorePipeline                               grlStorePipeline
#define grUnmapMemory                                 grlUnmapMemory
#define grWaitForFences                               grlWaitForFences
#define grWaitQueueSemaphore                          grlWaitQueueSemaphore

#ifdef __cplusplus
}
#endif

#endif
