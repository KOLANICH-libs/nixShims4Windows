#include <sys/time.h>
void usleep(DWORD waitTimeMicroseconds) {
	LARGE_INTEGER pliTimeout;
	pliTimeout.LowPart = waitTimeMicroseconds / 100;
	NtDelayExecution(FALSE, &pliTimeout);
}
