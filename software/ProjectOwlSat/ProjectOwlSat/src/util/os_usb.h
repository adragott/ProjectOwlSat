/*
 * os_usb.h
 *
 * Created: 10/31/2019 5:16:08 PM
 *  Author: penguin
 */ 
#ifndef _OS_USB_H_
#define _OS_USB_H_

#include "project_owlsat.h"


bool main_cdc_enable(uint8_t port);

/*! \brief Closes the communication port
 * This is called by CDC interface when USB Host disable it.
 */
void main_cdc_disable(uint8_t port);

/*! \brief Save new DTR state to change led behavior.
 * The DTR notify that the terminal have open or close the communication port.
 */
void main_cdc_set_dtr(uint8_t port, bool b_enable);

/*! \brief Manages the leds behaviors
 * Called when a start of frame is received on USB line each 1ms.
 */
void main_sof_action(void);

/*! \brief Enters the application in low power mode
 * Callback called when USB host sets USB line in suspend state
 */
void main_suspend_action(void);

/*! \brief Turn on a led to notify active mode
 * Called when the USB line is resumed from the suspend state
 */
void main_resume_action(void);

/*! \brief Called by UDC when USB Host request a extra string different
 * of this specified in USB device descriptor
 */
bool main_extra_string(void);

/*! \brief Initialize the memories used by examples
 */
void memories_initialization(void);

//! \brief Initializes the user interface
void ui_init(void);

//! \brief Enters the user interface in power down mode
void ui_powerdown(void);

//! \brief Exits the user interface of power down mode
void ui_wakeup(void);

//! \name Callback to show the MSC read and write access
//! @{
void ui_start_read(void);
void ui_stop_read(void);
void ui_start_write(void);
void ui_stop_write(void);
//! @}

/*! \brief Called when communication port is opened
 */
void ui_com_open(uint8_t port);

/*! \brief Called when communication port is closed
 */
void ui_com_close(uint8_t port);

/*! \brief Called when a data is received on CDC
 */
void ui_com_rx_start(void);

/*! \brief Called when a data is received on port com
 */
void ui_com_tx_start(void);

/*! \brief Called when all data pending are sent on port com
 */
void ui_com_rx_stop(void);

/*! \brief Called when all data pending are sent on CDC
 */
void ui_com_tx_stop(void);

/*! \brief Called when a communication error occur
 */
void ui_com_error(void);

/*! \brief Called when a overflow occur
 */
void ui_com_overflow(void);

/*! \brief This process is called each 1ms
 * It is called only if the USB interface is enabled.
 *
 * \param framenumber  Current frame number
 */
void ui_process(uint16_t framenumber);
#endif