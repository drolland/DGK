# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#



LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := sdl2-prebuilt
LOCAL_SRC_FILES := SDL2/libs/$(TARGET_ARCH_ABI)/libSDL2.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := main

FILE_LIST := $(wildcard $(LOCAL_PATH)/../../*.c)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%) 
LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv1_CM -lGLESv2 
LOCAL_STATIC_LIBRARIES := android_native_app_glue
#LOCAL_CFLAGS = -D__NO_SDL__
LOCAL_SHARED_LIBRARIES := sdl2-prebuilt
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)


