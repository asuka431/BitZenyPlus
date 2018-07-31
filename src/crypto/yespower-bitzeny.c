/*-
 * Copyright 2018 bitzenyPlus Developers
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
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file was originally written by bitzenyPlus Developers as part of the bitzenyPlus.
 */

#include "yespower/insecure_memzero.h"
#include "yespower/sha256.c"
#include "yespower/sha256.h"
#include "yespower/yespower.h"
#include "yespower/yespower-opt.c"

static const yespower_params_t yespower_0_5_bitzeny = {YESPOWER_0_5, 2048, 8, "Client Key", 10};

// WARNING DO NOT USE THIS IN yespower_hash YET. For later HF to yespower 1.0
// TODO Find HF solution using unixtime
// For 1.0 personalization string is not required. you can set its pointer to NULL and its length to 0.
static const yespower_params_t yespower_1_0_bitzeny = {YESPOWER_1_0, 2048, 8, NULL, 0};

// yespower 0.5 only
void yespower_hash(const char *input, char *output){
  if (yespower_tls(input, 80, &yespower_0_5_bitzeny, (yespower_binary_t *) output))
  abort();
}
