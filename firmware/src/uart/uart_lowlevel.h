
// Copyright 2020-2026 MotionLayer P.C.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UART_UART_LOWLEVEL_H_
#define UART_UART_LOWLEVEL_H_

#define UART_LINEFEED 0x0A
#define UART_CRETURN 0x0D
#define UART_ASCII_PROT_START_BYTE 0x2E
#define UART_BYTE_LIMIT 32

char uart_rx_msg[96];
uint8_t uart_rx_msg_len;

char uart_tx_msg[96];
uint8_t uart_tx_byte_idx;

void UART_Init(void);

// The following message handler is called when a UART
// message completes being received i.e.  with a newline
// character
extern void UART_ReceiveMessageHandler(void);

#endif /* UART_UART_LOWLEVEL_H_ */
