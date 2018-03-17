/*!
	@file	rn2483.h
	@author	Alexander Collins (alexander-collins@outlook.com)
	@date	September 2017 - April 2018
	@brief	A library for embedded platforms that handles interaction with a Microchip RN2483.

	@note By default, this library uses "fgetc(stdin)" to read from the RN2483. 
			Depending on your platform this will likely require changing. This can be done by 
			either redefining "fgetc(stream)" with a macro or using something like freopen() to 
			redirect the stdin stream to the RN2483 UART RX stream.

	@note By default, this library uses "fprintf(stdout, buff)" to write from the RN2483. 
			Depending on your platform this will likely require changing. This can be done by 
			either redefining "fprintf(stream, buff)" with a macro or using something like 
			freopen() to redirect the stdout stream to the RN2483 UART TX stream.

	@see https://www.microchip.com/wwwproducts/en/RN2483
	@see https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/knowledge-items/application-notes-for-the-internet-of-things/LoRaWAN%20Specification%201R0.pdf
*/

#ifndef RN2483
#define RN2483

//========
// MACROS
//========
//includes
#include <stdio.h>
#include <string.h>
//defines
#define RN2483_MAX_BUFF	33 /**< Maximum(+1) number of characters returned by RN2483 responses */

//=========
// GLOBALS
//=========
//! Values returned by RN2483_* functions
enum RN2483_ReturnCodes {
	RN2483_SUCCESS,                 /**< Success */
	RN2483_ERR_PARAM,               /**< Error: invalid parameter passed to function */
	RN2483_EOB = RN2483_MAX_BUFF    /**< Reached limit on buffer (help avoid buffer overflow) */
};
//! Valid LoRaWAN join modes @see RN2483_join(int mode)	@see LoRaWAN Specification V1.0, 6. End-Device Activation
enum RN2483_JoinModes {
    RN2483_OTAA,	/**< Over-the-Air-Activation */
	RN2483_ABP		/**< Activation-By-Personalization */
};

//===========
// FUNCTIONS
//===========
//system
//! Resets the RN2483 by toggling the RESET pin
/*!
	TODO
*/
int RN2483_reset();
//! Attempts to trigger the auto-baud detection sequence.
/*!
	TODO
*/
int RN2483_autobaud();
//! Write a command to the RN2483 and recieve it's response
/*!
	TODO
*/
int	RN2483_command(const char *command, char *response);
//! Retrieves the firmware version of the RN2483 module and stores it in buff.
/*!
	TODO
*/
int RN2483_firmware(char *buff);

//LoRa
//! Initialises all the RN2483 MAC settings required to run LoRa commands (join, tx, etc).
/*!
	TODO
*/
int RN2483_initMAC();
//! Attempts to join a LoRa network using the specified mode.
/*!
	TODO
*/
int RN2483_join(int mode);
//! Sends a confirmed/unconfirmed frame with an application payload of buff.
/*!
	TODO
*/
int RN2483_tx(const uint8_t *buff, bool confirm);

#endif // RN2483

