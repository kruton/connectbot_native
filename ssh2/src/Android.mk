LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

ssh2_files := \
	channel.c \
	comp.c \
	crypt.c \
	hostkey.c \
	kex.c \
	mac.c \
	misc.c \
	packet.c \
	publickey.c \
	scp.c \
	session.c \
	sftp.c \
	userauth.c \
	transport.c \
	version.c \
	openssl.c

LOCAL_SRC_FILES := $(ssh2_files)
LOCAL_MODULE := libssh2
LOCAL_CFLAGS += -O3 -DOPENSSL_NO_BLOWFISH -DLIBSSH2_HAVE_ZLIB -I$(LOCAL_PATH)/../include

LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -lz -lcrypto -lssl

include $(BUILD_SHARED_LIBRARY)
