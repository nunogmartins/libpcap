/* -*- Mode: c; tab-width: 8; indent-tabs-mode: 1; c-basic-offset: 8; -*- */
/*
 * Copyright (c) 2003  -	The tcpdump group.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor of the Laboratory may be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * @(#) $Header: /tcpdump/master/libpcap/Attic/rawssw7.h,v 1.1 2003-09-09 17:10:15 mcr Exp $ (LBL)
 */

/*
 * This file is never used in libpcap or tcpdump. It is provided as
 * documentation linktypes 139 through 143 only.
 */

/*
 * Date: Tue, 09 Sep 2003 09:41:04 -0400
 * From: Jeff Morriss <jeff.morriss@ulticom.com>
 * To: tcpdump-workers@tcpdump.org
 * Subject: [tcpdump-workers] request for LINKTYPE_
 *
 * We've had some discussion over on ethereal-dev about a "fake link" or
 * "raw SS7" dissector that allows dumping an arbitrary protocol into a
 * file without any (otherwise necessary) lower level protocols.  The
 * common example has been dumping MTP3 into a file without, well, MTP2 or
 * M2PA.
 *
 * Here is the original post thread:
 *
 * http://ethereal.com/lists/ethereal-dev/200306/threads.html#00200
 *
 * July's thread on the subject:
 * 
 * http://ethereal.com/lists/ethereal-dev/200307/threads.html#00124
 *
 * August's thread:
 *
 * http://ethereal.com/lists/ethereal-dev/200308/threads.html#00193
 *
 *
 * and one of the last messages--which is why I'm mailing you today:
 * 
 * http://ethereal.com/lists/ethereal-dev/200308/msg00193.html
 *
 *
 * Based on the message in the last URL, I'd like to request a new
 * LINKTYPE_:  LINKTYPE_RAWSS7.
 *
 * This file type will contain a header:
 */

typedef struct _rawss7_hdr {
         /* NOTE: These are in network-byte order. */
         guint16 type;
         guint16 length;
} rawss7_hdr;

/*
 *
 * followed by protocol data for whatever protocol 'type' indicates.  E.g.:
 *
 */

/*  The list of protocols understood by the rawss7 dissector.
  *  When adding a protocol here, be sure to add a value_string entry for
  *  the protocol in "packet-rawss7.c"
  */
#define RAWSS7_MTP2           0x0001
#define RAWSS7_MTP3           0x0002
#define RAWSS7_SCCP           0x0003

/*
 *
 * There was some discussion about these protocol values being allocated by
 * tcpdump-workers as well.  In fact it would be handy to have one place to
 * allocate such numbers, so what do you think about allocating 3 more (for
 * now) LINKTYPE_'s:
 *
 * LINKTYPE_RAWSS7_MTP2
 * LINKTYPE_RAWSS7_MTP3
 * LINKTYPE_RAWSS7_SCCP
 *
 *  If not, just the LINKTYPE_RAWSS7 will be fine (Ethereal can maintain
 * the RAWSS7 types).
 *
 *
 *
 * ps. The reason we want to use the PCAP file format here is because it's
 * well defined and there isn't another (popular) file format for capturing 
 * SS7 messages that we can reverse engineer.  Rather than creating a new 
 * file format, it's a lot easier to just allocate a LINKTYPE_.
 *
 */

