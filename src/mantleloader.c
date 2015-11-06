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

#include <GR/mantleloader.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static HMODULE libgr;

static void open_libgr(void)
{
	libgr = LoadLibraryA("mantle64.dll");
	if (!libgr) libgr = LoadLibraryA("mantle32.dll");
}

static void close_libgr(void)
{
	FreeLibrary(libgr);
	libgr = NULL;
}

static GRLgrProc get_proc(const char *proc)
{
	return (GRLgrProc)GetProcAddress(libgr, proc);
}

static void load_procs(void);

int grlInit(void)
{
	open_libgr();
	load_procs();
	return 0;
}

void grlShutdown(void)
{
	close_libgr();
}

GRLgrProc grlGetProcAddress(const char *proc)
{
	return get_proc(proc);
}

grAllocMemoryFn*                                     grlAllocMemory;
grAttachImageViewDescriptorsFn*                      grlAttachImageViewDescriptors;
grAttachMemoryViewDescriptorsFn*                     grlAttachMemoryViewDescriptors;
grAttachNestedDescriptorsFn*                         grlAttachNestedDescriptors;
grAttachSamplerDescriptorsFn*                        grlAttachSamplerDescriptors;
grBeginCommandBufferFn*                              grlBeginCommandBuffer;
grBeginDescriptorSetUpdateFn*                        grlBeginDescriptorSetUpdate;
grBindObjectMemoryFn*                                grlBindObjectMemory;
grClearDescriptorSetSlotsFn*                         grlClearDescriptorSetSlots;
grCmdBeginQueryFn*                                   grlCmdBeginQuery;
grCmdBindDescriptorSetFn*                            grlCmdBindDescriptorSet;
grCmdBindDynamicMemoryViewFn*                        grlCmdBindDynamicMemoryView;
grCmdBindIndexDataFn*                                grlCmdBindIndexData;
grCmdBindPipelineFn*                                 grlCmdBindPipeline;
grCmdBindStateObjectFn*                              grlCmdBindStateObject;
grCmdBindTargetsFn*                                  grlCmdBindTargets;
grCmdClearColorImageFn*                              grlCmdClearColorImage;
grCmdClearColorImageRawFn*                           grlCmdClearColorImageRaw;
grCmdClearDepthStencilFn*                            grlCmdClearDepthStencil;
grCmdCloneImageDataFn*                               grlCmdCloneImageData;
grCmdCopyImageFn*                                    grlCmdCopyImage;
grCmdCopyImageToMemoryFn*                            grlCmdCopyImageToMemory;
grCmdCopyMemoryFn*                                   grlCmdCopyMemory;
grCmdCopyMemoryToImageFn*                            grlCmdCopyMemoryToImage;
grCmdDbgMarkerBeginFn*                               grlCmdDbgMarkerBegin;
grCmdDbgMarkerEndFn*                                 grlCmdDbgMarkerEnd;
grCmdDispatchFn*                                     grlCmdDispatch;
grCmdDispatchIndirectFn*                             grlCmdDispatchIndirect;
grCmdDrawFn*                                         grlCmdDraw;
grCmdDrawIndexedFn*                                  grlCmdDrawIndexed;
grCmdDrawIndexedIndirectFn*                          grlCmdDrawIndexedIndirect;
grCmdDrawIndirectFn*                                 grlCmdDrawIndirect;
grCmdEndQueryFn*                                     grlCmdEndQuery;
grCmdFillMemoryFn*                                   grlCmdFillMemory;
grCmdInitAtomicCountersFn*                           grlCmdInitAtomicCounters;
grCmdLoadAtomicCountersFn*                           grlCmdLoadAtomicCounters;
grCmdMemoryAtomicFn*                                 grlCmdMemoryAtomic;
grCmdPrepareImagesFn*                                grlCmdPrepareImages;
grCmdPrepareMemoryRegionsFn*                         grlCmdPrepareMemoryRegions;
grCmdResetEventFn*                                   grlCmdResetEvent;
grCmdResetQueryPoolFn*                               grlCmdResetQueryPool;
grCmdResolveImageFn*                                 grlCmdResolveImage;
grCmdSaveAtomicCountersFn*                           grlCmdSaveAtomicCounters;
grCmdSetEventFn*                                     grlCmdSetEvent;
grCmdUpdateMemoryFn*                                 grlCmdUpdateMemory;
grCmdWriteTimestampFn*                               grlCmdWriteTimestamp;
grCreateColorBlendStateFn*                           grlCreateColorBlendState;
grCreateColorTargetViewFn*                           grlCreateColorTargetView;
grCreateCommandBufferFn*                             grlCreateCommandBuffer;
grCreateComputePipelineFn*                           grlCreateComputePipeline;
grCreateDepthStencilStateFn*                         grlCreateDepthStencilState;
grCreateDepthStencilViewFn*                          grlCreateDepthStencilView;
grCreateDescriptorSetFn*                             grlCreateDescriptorSet;
grCreateDeviceFn*                                    grlCreateDevice;
grCreateEventFn*                                     grlCreateEvent;
grCreateFenceFn*                                     grlCreateFence;
grCreateGraphicsPipelineFn*                          grlCreateGraphicsPipeline;
grCreateImageFn*                                     grlCreateImage;
grCreateImageViewFn*                                 grlCreateImageView;
grCreateMsaaStateFn*                                 grlCreateMsaaState;
grCreateQueryPoolFn*                                 grlCreateQueryPool;
grCreateQueueSemaphoreFn*                            grlCreateQueueSemaphore;
grCreateRasterStateFn*                               grlCreateRasterState;
grCreateSamplerFn*                                   grlCreateSampler;
grCreateShaderFn*                                    grlCreateShader;
grCreateViewportStateFn*                             grlCreateViewportState;
grDbgRegisterMsgCallbackFn*                          grlDbgRegisterMsgCallback;
grDbgSetDeviceOptionFn*                              grlDbgSetDeviceOption;
grDbgSetGlobalOptionFn*                              grlDbgSetGlobalOption;
grDbgSetMessageFilterFn*                             grlDbgSetMessageFilter;
grDbgSetObjectTagFn*                                 grlDbgSetObjectTag;
grDbgSetValidationLevelFn*                           grlDbgSetValidationLevel;
grDbgUnregisterMsgCallbackFn*                        grlDbgUnregisterMsgCallback;
grDestroyDeviceFn*                                   grlDestroyDevice;
grDestroyObjectFn*                                   grlDestroyObject;
grDeviceWaitIdleFn*                                  grlDeviceWaitIdle;
grEndCommandBufferFn*                                grlEndCommandBuffer;
grEndDescriptorSetUpdateFn*                          grlEndDescriptorSetUpdate;
grFreeMemoryFn*                                      grlFreeMemory;
grGetDeviceQueueFn*                                  grlGetDeviceQueue;
grGetEventStatusFn*                                  grlGetEventStatus;
grGetExtensionSupportFn*                             grlGetExtensionSupport;
grGetFenceStatusFn*                                  grlGetFenceStatus;
grGetFormatInfoFn*                                   grlGetFormatInfo;
grGetGpuInfoFn*                                      grlGetGpuInfo;
grGetImageSubresourceInfoFn*                         grlGetImageSubresourceInfo;
grGetMemoryHeapCountFn*                              grlGetMemoryHeapCount;
grGetMemoryHeapInfoFn*                               grlGetMemoryHeapInfo;
grGetMultiGpuCompatibilityFn*                        grlGetMultiGpuCompatibility;
grGetObjectInfoFn*                                   grlGetObjectInfo;
grGetQueryPoolResultsFn*                             grlGetQueryPoolResults;
grInitAndEnumerateGpusFn*                            grlInitAndEnumerateGpus;
grLoadPipelineFn*                                    grlLoadPipeline;
grMapMemoryFn*                                       grlMapMemory;
grOpenPeerImageFn*                                   grlOpenPeerImage;
grOpenPeerMemoryFn*                                  grlOpenPeerMemory;
grOpenSharedMemoryFn*                                grlOpenSharedMemory;
grOpenSharedQueueSemaphoreFn*                        grlOpenSharedQueueSemaphore;
grPinSystemMemoryFn*                                 grlPinSystemMemory;
grQueueSetGlobalMemReferencesFn*                     grlQueueSetGlobalMemReferences;
grQueueSubmitFn*                                     grlQueueSubmit;
grQueueWaitIdleFn*                                   grlQueueWaitIdle;
grRemapVirtualMemoryPagesFn*                         grlRemapVirtualMemoryPages;
grResetCommandBufferFn*                              grlResetCommandBuffer;
grResetEventFn*                                      grlResetEvent;
grSetEventFn*                                        grlSetEvent;
grSetMemoryPriorityFn*                               grlSetMemoryPriority;
grSignalQueueSemaphoreFn*                            grlSignalQueueSemaphore;
grStorePipelineFn*                                   grlStorePipeline;
grUnmapMemoryFn*                                     grlUnmapMemory;
grWaitForFencesFn*                                   grlWaitForFences;
grWaitQueueSemaphoreFn*                              grlWaitQueueSemaphore;

static void load_procs(void)
{
	grlAllocMemory = (grAllocMemoryFn*) get_proc("grAllocMemory");
	grlAttachImageViewDescriptors = (grAttachImageViewDescriptorsFn*) get_proc("grAttachImageViewDescriptors");
	grlAttachMemoryViewDescriptors = (grAttachMemoryViewDescriptorsFn*) get_proc("grAttachMemoryViewDescriptors");
	grlAttachNestedDescriptors = (grAttachNestedDescriptorsFn*) get_proc("grAttachNestedDescriptors");
	grlAttachSamplerDescriptors = (grAttachSamplerDescriptorsFn*) get_proc("grAttachSamplerDescriptors");
	grlBeginCommandBuffer = (grBeginCommandBufferFn*) get_proc("grBeginCommandBuffer");
	grlBeginDescriptorSetUpdate = (grBeginDescriptorSetUpdateFn*) get_proc("grBeginDescriptorSetUpdate");
	grlBindObjectMemory = (grBindObjectMemoryFn*) get_proc("grBindObjectMemory");
	grlClearDescriptorSetSlots = (grClearDescriptorSetSlotsFn*) get_proc("grClearDescriptorSetSlots");
	grlCmdBeginQuery = (grCmdBeginQueryFn*) get_proc("grCmdBeginQuery");
	grlCmdBindDescriptorSet = (grCmdBindDescriptorSetFn*) get_proc("grCmdBindDescriptorSet");
	grlCmdBindDynamicMemoryView = (grCmdBindDynamicMemoryViewFn*) get_proc("grCmdBindDynamicMemoryView");
	grlCmdBindIndexData = (grCmdBindIndexDataFn*) get_proc("grCmdBindIndexData");
	grlCmdBindPipeline = (grCmdBindPipelineFn*) get_proc("grCmdBindPipeline");
	grlCmdBindStateObject = (grCmdBindStateObjectFn*) get_proc("grCmdBindStateObject");
	grlCmdBindTargets = (grCmdBindTargetsFn*) get_proc("grCmdBindTargets");
	grlCmdClearColorImage = (grCmdClearColorImageFn*) get_proc("grCmdClearColorImage");
	grlCmdClearColorImageRaw = (grCmdClearColorImageRawFn*) get_proc("grCmdClearColorImageRaw");
	grlCmdClearDepthStencil = (grCmdClearDepthStencilFn*) get_proc("grCmdClearDepthStencil");
	grlCmdCloneImageData = (grCmdCloneImageDataFn*) get_proc("grCmdCloneImageData");
	grlCmdCopyImage = (grCmdCopyImageFn*) get_proc("grCmdCopyImage");
	grlCmdCopyImageToMemory = (grCmdCopyImageToMemoryFn*) get_proc("grCmdCopyImageToMemory");
	grlCmdCopyMemory = (grCmdCopyMemoryFn*) get_proc("grCmdCopyMemory");
	grlCmdCopyMemoryToImage = (grCmdCopyMemoryToImageFn*) get_proc("grCmdCopyMemoryToImage");
	grlCmdDbgMarkerBegin = (grCmdDbgMarkerBeginFn*) get_proc("grCmdDbgMarkerBegin");
	grlCmdDbgMarkerEnd = (grCmdDbgMarkerEndFn*) get_proc("grCmdDbgMarkerEnd");
	grlCmdDispatch = (grCmdDispatchFn*) get_proc("grCmdDispatch");
	grlCmdDispatchIndirect = (grCmdDispatchIndirectFn*) get_proc("grCmdDispatchIndirect");
	grlCmdDraw = (grCmdDrawFn*) get_proc("grCmdDraw");
	grlCmdDrawIndexed = (grCmdDrawIndexedFn*) get_proc("grCmdDrawIndexed");
	grlCmdDrawIndexedIndirect = (grCmdDrawIndexedIndirectFn*) get_proc("grCmdDrawIndexedIndirect");
	grlCmdDrawIndirect = (grCmdDrawIndirectFn*) get_proc("grCmdDrawIndirect");
	grlCmdEndQuery = (grCmdEndQueryFn*) get_proc("grCmdEndQuery");
	grlCmdFillMemory = (grCmdFillMemoryFn*) get_proc("grCmdFillMemory");
	grlCmdInitAtomicCounters = (grCmdInitAtomicCountersFn*) get_proc("grCmdInitAtomicCounters");
	grlCmdLoadAtomicCounters = (grCmdLoadAtomicCountersFn*) get_proc("grCmdLoadAtomicCounters");
	grlCmdMemoryAtomic = (grCmdMemoryAtomicFn*) get_proc("grCmdMemoryAtomic");
	grlCmdPrepareImages = (grCmdPrepareImagesFn*) get_proc("grCmdPrepareImages");
	grlCmdPrepareMemoryRegions = (grCmdPrepareMemoryRegionsFn*) get_proc("grCmdPrepareMemoryRegions");
	grlCmdResetEvent = (grCmdResetEventFn*) get_proc("grCmdResetEvent");
	grlCmdResetQueryPool = (grCmdResetQueryPoolFn*) get_proc("grCmdResetQueryPool");
	grlCmdResolveImage = (grCmdResolveImageFn*) get_proc("grCmdResolveImage");
	grlCmdSaveAtomicCounters = (grCmdSaveAtomicCountersFn*) get_proc("grCmdSaveAtomicCounters");
	grlCmdSetEvent = (grCmdSetEventFn*) get_proc("grCmdSetEvent");
	grlCmdUpdateMemory = (grCmdUpdateMemoryFn*) get_proc("grCmdUpdateMemory");
	grlCmdWriteTimestamp = (grCmdWriteTimestampFn*) get_proc("grCmdWriteTimestamp");
	grlCreateColorBlendState = (grCreateColorBlendStateFn*) get_proc("grCreateColorBlendState");
	grlCreateColorTargetView = (grCreateColorTargetViewFn*) get_proc("grCreateColorTargetView");
	grlCreateCommandBuffer = (grCreateCommandBufferFn*) get_proc("grCreateCommandBuffer");
	grlCreateComputePipeline = (grCreateComputePipelineFn*) get_proc("grCreateComputePipeline");
	grlCreateDepthStencilState = (grCreateDepthStencilStateFn*) get_proc("grCreateDepthStencilState");
	grlCreateDepthStencilView = (grCreateDepthStencilViewFn*) get_proc("grCreateDepthStencilView");
	grlCreateDescriptorSet = (grCreateDescriptorSetFn*) get_proc("grCreateDescriptorSet");
	grlCreateDevice = (grCreateDeviceFn*) get_proc("grCreateDevice");
	grlCreateEvent = (grCreateEventFn*) get_proc("grCreateEvent");
	grlCreateFence = (grCreateFenceFn*) get_proc("grCreateFence");
	grlCreateGraphicsPipeline = (grCreateGraphicsPipelineFn*) get_proc("grCreateGraphicsPipeline");
	grlCreateImage = (grCreateImageFn*) get_proc("grCreateImage");
	grlCreateImageView = (grCreateImageViewFn*) get_proc("grCreateImageView");
	grlCreateMsaaState = (grCreateMsaaStateFn*) get_proc("grCreateMsaaState");
	grlCreateQueryPool = (grCreateQueryPoolFn*) get_proc("grCreateQueryPool");
	grlCreateQueueSemaphore = (grCreateQueueSemaphoreFn*) get_proc("grCreateQueueSemaphore");
	grlCreateRasterState = (grCreateRasterStateFn*) get_proc("grCreateRasterState");
	grlCreateSampler = (grCreateSamplerFn*) get_proc("grCreateSampler");
	grlCreateShader = (grCreateShaderFn*) get_proc("grCreateShader");
	grlCreateViewportState = (grCreateViewportStateFn*) get_proc("grCreateViewportState");
	grlDbgRegisterMsgCallback = (grDbgRegisterMsgCallbackFn*) get_proc("grDbgRegisterMsgCallback");
	grlDbgSetDeviceOption = (grDbgSetDeviceOptionFn*) get_proc("grDbgSetDeviceOption");
	grlDbgSetGlobalOption = (grDbgSetGlobalOptionFn*) get_proc("grDbgSetGlobalOption");
	grlDbgSetMessageFilter = (grDbgSetMessageFilterFn*) get_proc("grDbgSetMessageFilter");
	grlDbgSetObjectTag = (grDbgSetObjectTagFn*) get_proc("grDbgSetObjectTag");
	grlDbgSetValidationLevel = (grDbgSetValidationLevelFn*) get_proc("grDbgSetValidationLevel");
	grlDbgUnregisterMsgCallback = (grDbgUnregisterMsgCallbackFn*) get_proc("grDbgUnregisterMsgCallback");
	grlDestroyDevice = (grDestroyDeviceFn*) get_proc("grDestroyDevice");
	grlDestroyObject = (grDestroyObjectFn*) get_proc("grDestroyObject");
	grlDeviceWaitIdle = (grDeviceWaitIdleFn*) get_proc("grDeviceWaitIdle");
	grlEndCommandBuffer = (grEndCommandBufferFn*) get_proc("grEndCommandBuffer");
	grlEndDescriptorSetUpdate = (grEndDescriptorSetUpdateFn*) get_proc("grEndDescriptorSetUpdate");
	grlFreeMemory = (grFreeMemoryFn*) get_proc("grFreeMemory");
	grlGetDeviceQueue = (grGetDeviceQueueFn*) get_proc("grGetDeviceQueue");
	grlGetEventStatus = (grGetEventStatusFn*) get_proc("grGetEventStatus");
	grlGetExtensionSupport = (grGetExtensionSupportFn*) get_proc("grGetExtensionSupport");
	grlGetFenceStatus = (grGetFenceStatusFn*) get_proc("grGetFenceStatus");
	grlGetFormatInfo = (grGetFormatInfoFn*) get_proc("grGetFormatInfo");
	grlGetGpuInfo = (grGetGpuInfoFn*) get_proc("grGetGpuInfo");
	grlGetImageSubresourceInfo = (grGetImageSubresourceInfoFn*) get_proc("grGetImageSubresourceInfo");
	grlGetMemoryHeapCount = (grGetMemoryHeapCountFn*) get_proc("grGetMemoryHeapCount");
	grlGetMemoryHeapInfo = (grGetMemoryHeapInfoFn*) get_proc("grGetMemoryHeapInfo");
	grlGetMultiGpuCompatibility = (grGetMultiGpuCompatibilityFn*) get_proc("grGetMultiGpuCompatibility");
	grlGetObjectInfo = (grGetObjectInfoFn*) get_proc("grGetObjectInfo");
	grlGetQueryPoolResults = (grGetQueryPoolResultsFn*) get_proc("grGetQueryPoolResults");
	grlInitAndEnumerateGpus = (grInitAndEnumerateGpusFn*) get_proc("grInitAndEnumerateGpus");
	grlLoadPipeline = (grLoadPipelineFn*) get_proc("grLoadPipeline");
	grlMapMemory = (grMapMemoryFn*) get_proc("grMapMemory");
	grlOpenPeerImage = (grOpenPeerImageFn*) get_proc("grOpenPeerImage");
	grlOpenPeerMemory = (grOpenPeerMemoryFn*) get_proc("grOpenPeerMemory");
	grlOpenSharedMemory = (grOpenSharedMemoryFn*) get_proc("grOpenSharedMemory");
	grlOpenSharedQueueSemaphore = (grOpenSharedQueueSemaphoreFn*) get_proc("grOpenSharedQueueSemaphore");
	grlPinSystemMemory = (grPinSystemMemoryFn*) get_proc("grPinSystemMemory");
	grlQueueSetGlobalMemReferences = (grQueueSetGlobalMemReferencesFn*) get_proc("grQueueSetGlobalMemReferences");
	grlQueueSubmit = (grQueueSubmitFn*) get_proc("grQueueSubmit");
	grlQueueWaitIdle = (grQueueWaitIdleFn*) get_proc("grQueueWaitIdle");
	grlRemapVirtualMemoryPages = (grRemapVirtualMemoryPagesFn*) get_proc("grRemapVirtualMemoryPages");
	grlResetCommandBuffer = (grResetCommandBufferFn*) get_proc("grResetCommandBuffer");
	grlResetEvent = (grResetEventFn*) get_proc("grResetEvent");
	grlSetEvent = (grSetEventFn*) get_proc("grSetEvent");
	grlSetMemoryPriority = (grSetMemoryPriorityFn*) get_proc("grSetMemoryPriority");
	grlSignalQueueSemaphore = (grSignalQueueSemaphoreFn*) get_proc("grSignalQueueSemaphore");
	grlStorePipeline = (grStorePipelineFn*) get_proc("grStorePipeline");
	grlUnmapMemory = (grUnmapMemoryFn*) get_proc("grUnmapMemory");
	grlWaitForFences = (grWaitForFencesFn*) get_proc("grWaitForFences");
	grlWaitQueueSemaphore = (grWaitQueueSemaphoreFn*) get_proc("grWaitQueueSemaphore");
}
