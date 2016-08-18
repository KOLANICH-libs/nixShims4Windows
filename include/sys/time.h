#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#define A5D4FF0E971594E6EB6B0A2D8E71ECA21
#endif

#include <windows.h>
#pragma comment(lib, "NtDelayExecution.lib")
#ifdef __cplusplus
extern "C"
#endif
__declspec(dllimport) LONG WINAPI NtDelayExecution(BOOLEAN bAlertable, const LARGE_INTEGER *pliTimeout);
void usleep(DWORD waitTimeMicroseconds);

#ifdef A5D4FF0E971594E6EB6B0A2D8E71ECA21
#undef NOMINMAX
#undef A5D4FF0E971594E6EB6B0A2D8E71ECA21
#endif
