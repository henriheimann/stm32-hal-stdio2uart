# stdio2uart

## Usage
Before any calls to writing to stdout such as `printf` call the initialisation function with the UART handle you want to use. For example UART2:
```c
stdio2uart_init(&huart2);
```

## Supported Platforms
STM32L0 and STM32L4 are supported. The HAL header includes for other platforms may be added in `stdio2uart.h`.
