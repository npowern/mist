/*
 * Copyright (c) 2012, Thingsquare, www.thingsquare.com.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of Thingsquare Mist.
 */

/*
 *  \file
 *      leds-arch.c
 *   \author
 *      Marcus Lunden <marcus@thingsquare.com>>
 *   \desc
 *      LED arch dependent drivers
 *      
 *      
 */

#include "contiki.h"
#include "dev/leds.h"
#include "SDK_EVAL_Led.h"
#include "../platform-conf.h"


/*---------------------------------------------------------------------------*/
void
leds_arch_init(void)
{
  SdkEvalLedInit(LED1);
  SdkEvalLedInit(LED2);
  SdkEvalLedInit(LED3);
  SdkEvalLedInit(LED4);
  SdkEvalLedInit(LED5);

  SdkEvalLedOff(LED1);
  SdkEvalLedOff(LED2);
  SdkEvalLedOff(LED3);
  SdkEvalLedOff(LED4);
  SdkEvalLedOff(LED5);
}
/*---------------------------------------------------------------------------*/
unsigned char
leds_arch_get(void)
{
  unsigned char ret = 0xff;

  if(SdkEvalLedGetState(LED1)) {
    ret |= LEDS_CONF_RED;
  }
  
  if(SdkEvalLedGetState(LED2)) {
    ret |= LEDS_CONF_GREEN;
  }
  
  if(SdkEvalLedGetState(LED3)) {
    ret |= LEDS_CONF_BLUE;
  }

  return ret;
}
/*---------------------------------------------------------------------------*/
void
leds_arch_set(unsigned char leds)
{
  /* the LEDs API uses active low, hence if bit is set, it should be off. */
  if(leds & LEDS_CONF_RED) {
    SdkEvalLedOn(LED1);
  } else {
    SdkEvalLedOff(LED1);
  }

  if(leds & LEDS_CONF_GREEN) {
    SdkEvalLedOn(LED2);
  } else {
    SdkEvalLedOff(LED2);
  }

  if(leds & LEDS_CONF_BLUE) {
    SdkEvalLedOn(LED3);
  } else {
    SdkEvalLedOff(LED3);
  }
}
/*---------------------------------------------------------------------------*/



