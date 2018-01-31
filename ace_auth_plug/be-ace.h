/* 
*  Copyright (c) 2017 Cigdem Sengul <cigdem.sengul@nominet.uk>
*  All  rights reserved 
*
*  be-http.h
*  Copyright (c) 2013 Jan-Piet Mens <jp@mens.de>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of mosquitto nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
*/

#include <stddef.h>

#ifdef BE_ACE

#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/buffer.h>
#include "base64.h"
#include "nxjson.h"
#include "token-cache.h"

#define MAXPARAMSLEN    1024
#define METHOD_GETUSER     1

//Not supported
//#define METHOD_SUPERUSER   2
//#define METHOD_ACLCHECK    3

struct ace_backend{
	char *ip; 
	int port; 
	char *hostheader; 
	char *getuser_uri;
//Not supported
//	char *superuser_uri;
//	char *aclcheck_uri;


	char *getuser_envs;
//Not supported
//	char *superuser_envs;
//	char *aclcheck_envs;

	char *with_tls;
	char *basic_auth;
	int retry_count;
};


void *be_ace_init();
void be_ace_destroy(void *conf); 
int be_ace_getuser(void *conf, const char *username, const char *password, char **authenticated); 
//Not supported
int be_ace_superuser(void *conf, const char *username); 
int be_ace_aclcheck(void *conf, const char *clientid, const char *username, const char *topic, int acc); 

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata); 

#endif /* BE_ACE */