#ifndef __LIBSSH2_CHANNEL_H
#define __LIBSSH2_CHANNEL_H
/* Copyright (c) 2008-2009 by Daniel Stenberg
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided
 * that the following conditions are met:
 *
 *   Redistributions of source code must retain the above
 *   copyright notice, this list of conditions and the
 *   following disclaimer.
 *
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials
 *   provided with the distribution.
 *
 *   Neither the name of the copyright holder nor the names
 *   of any other contributors may be used to endorse or
 *   promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */

/*
 * _libssh2_channel_receive_window_adjust
 *
 * Adjust the receive window for a channel by adjustment bytes. If the amount
 * to be adjusted is less than LIBSSH2_CHANNEL_MINADJUST and force is 0 the
 * adjustment amount will be queued for a later packet.
 *
 * Always non-blocking.
 */
int _libssh2_channel_receive_window_adjust(LIBSSH2_CHANNEL * channel,
                                           unsigned long adjustment,
                                           unsigned char force,
                                           unsigned int *store);

/*
 * _libssh2_channel_flush
 *
 * Flush data from one (or all) stream
 * Returns number of bytes flushed, or negative on failure
 */
int _libssh2_channel_flush(LIBSSH2_CHANNEL *channel, int streamid);

/*
 * _libssh2_channel_free
 *
 * Make sure a channel is closed, then remove the channel from the session
 * and free its resource(s)
 *
 * Returns 0 on success, negative on failure
 */
int _libssh2_channel_free(LIBSSH2_CHANNEL *channel);

int
_libssh2_channel_extended_data(LIBSSH2_CHANNEL *channel, int ignore_mode);

/*
 * _libssh2_channel_write
 *
 * Send data to a channel
 */
ssize_t
_libssh2_channel_write(LIBSSH2_CHANNEL *channel, int stream_id,
                       const char *buf, size_t buflen);

/*
 * _libssh2_channel_open
 *
 * Establish a generic session channel
 */
LIBSSH2_CHANNEL *
_libssh2_channel_open(LIBSSH2_SESSION * session, const char *channel_type,
                      unsigned int channel_type_len,
                      unsigned int window_size, unsigned int packet_size,
                      const char *message, unsigned int message_len);


/*
 * _libssh2_channel_process_startup
 *
 * Primitive for libssh2_channel_(shell|exec|subsystem)
 */
int
_libssh2_channel_process_startup(LIBSSH2_CHANNEL *channel,
                                 const char *request, unsigned int request_len,
                                 const char *message, unsigned int message_len);

#endif /* __LIBSSH2_CHANNEL_H */

