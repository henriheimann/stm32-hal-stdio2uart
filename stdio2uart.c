#include "stdio_uart.h"

#include <stdio.h>
#include <errno.h>
#include <sys/unistd.h>

static UART_HandleTypeDef *_uart_handle;

void stdio2uart_init(UART_HandleTypeDef *handle)
{
	_uart_handle = handle;
	setvbuf(stdout, NULL, _IONBF, 0);
}

int _write(int file, char *data, int len)
{
	if ((file != STDOUT_FILENO) && (file != STDERR_FILENO)) {
		errno = EBADF;
		return -1;
	}

	HAL_StatusTypeDef status = HAL_UART_Transmit(_uart_handle, (uint8_t*)data, len, STDIO_UART_TIMEOUT);
	return (status == HAL_OK ? len : 0);
}
