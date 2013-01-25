/*
 * tusb.h
 *
 *  Created on: Nov 27, 2012
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2012, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tinyUSB stack.
 */

/** \file
 *  \brief Tiny USB header
 *
 *  \note Tiny USB header Note
 */

#ifndef _TUSB_H_
#define _TUSB_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "common/common.h"

#ifdef TUSB_CFG_HOST
  #include "host/usbd_host.h"

  #ifdef HOST_CLASS_HID
    #include "class/hid_host.h"
  #endif
#endif

#ifdef TUSB_CFG_DEVICE
  #include "device/dcd.h"

  #if DEVICE_CLASS_HID
    #include "class/hid_device.h"
  #endif

  #ifdef TUSB_CFG_DEVICE_CDC
    #include "class/cdc.h"
  #endif
#endif

#if !(defined TUSB_CFG_HOST) && !(defined TUSB_CFG_DEVICE)
 #error please enable either TUSB_CFG_HOST or TUSB_CFG_DEVICE
#endif


tusb_error_t tusb_init(void);

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_H_ */
