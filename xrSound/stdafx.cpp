// stdafx.cpp : source file that includes just the standard includes
// xrSound.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

#ifdef __BORLANDC__
#	pragma comment(lib,	"eaxB"			)
#	pragma comment(lib,	"vorbisfileB"	)
#	pragma comment(lib,	"xrCoreB"		)
#	pragma comment(lib,	"EToolsB"		)
#	pragma comment(lib,	"OpenAL32B"		)
#	pragma comment(lib,	"dsoundb" 		)
#else
#	pragma comment(lib,	"eax"		)
#	pragma comment(lib,	"xrCore"		)
#	pragma comment(lib,	"xrCDB"			)
#	pragma comment(lib,	"dsound" 		)
#endif

#pragma comment(lib,	"msacm32"		)

