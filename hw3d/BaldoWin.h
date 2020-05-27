#pragma once

// target win7 and later
#define _WIN32_WINT 0x601
#include <winsdkver.h>

// The following defines disable some unused windows stuff.
// It makes the build faster
#define WIN32_LEAN_AND_MEAN
#define NOGDICAPMASKS
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOSYSCOMMANDS
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOMINMAX
#define NOOPENFILE
#define NOSCROLL
#define NONLS
#define NOSERVICE
#define NOSOUND
#define NOKERNEL
#define NOPROFILER
#define NOMEMMGR
#define NOMETAFILE
#define NORPC
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOMCX
#define NOIMAGE
#define NOTAPE

#define STRICT

#include <Windows.h>