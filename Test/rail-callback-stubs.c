// This file is generated by Ember Desktop.  Please do not edit manually.
//
//

#include <stdint.h>
#include "rail.h"
#include "rail_types.h"
#include CONFIGURATION_HEADER



/**
 * Callback that lets the app know when the radio has finished init
 * and is ready.
 */
void RAILCb_RfReady(void) {}


/**
 * Interrupt level callback to signify when the packet was sent
 * @param txPacketInfo Information about the packet that was transmitted.
 * @note that this structure is only valid during the timeframe of the
 * callback.
 */
void RAILCb_TxPacketSent(RAIL_TxPacketInfo_t *txPacketInfo) {}


/**
 * Interrupt level callback
 * Allows the user finer granularity in tx radio events.
 *
 * Radio Statuses:
 * RAIL_TX_CONFIG_BUFFER_UNDERFLOW
 * RAIL_TX_CONFIG_CHANNEL_BUSY
 *
 * @param[in] status A bit field that defines what event caused the callback
 */
void RAILCb_TxRadioStatus(uint8_t status) {}


/**
 * Receive packet callback.
 *
 * @param[in] rxPacketHandle Contains a handle that points to the memory that
 *   the packet was stored in. This handle will be the same as something
 *   returned by the RAILCb_AllocateMemory() API. To convert this into a receive
 *   packet info struct use the *** function.
 *
 * This function is called whenever a packet is received and returns to you the
 * memory handle for where this received packet and its appended information was
 * stored. After this callback is done we will release the memory handle so you
 * must somehow increment a reference count or copy the data out within this
 * function.
 */
void RAILCb_RxPacketReceived(void *rxPacketHandle) {}


/**
 * Called whenever an enabled radio status event occurs
 *
 * Triggers:
 *  RAIL_RX_CONFIG_PREAMBLE_DETECT
 *  RAIL_RX_CONFIG_SYNC1_DETECT
 *  RAIL_RX_CONFIG_SYNC2_DETECT
 *  RAIL_RX_CONFIG_INVALID_CRC
 *  RAIL_RX_CONFIG_BUFFER_OVERFLOW
 *  RAIL_RX_CONFIG_ADDRESS_FILTERED
 *
 * @param[in] status The event that triggered this callback
 */
void RAILCb_RxRadioStatus(uint8_t status) {}


/**
 * Callback that notifies the application that a calibration is needed.
 *
 * This callback function is called whenever the RAIL library detects that a
 * calibration is needed. It is up to the application to determine a valid
 * window to call RAIL_CalStart().
 *
 */
void RAILCb_CalNeeded(void)
{
  // Perform the necessary calibrations without saving the results
  RAIL_CalStart(NULL, RAIL_CAL_ALL_PENDING, false);
}



/**
 * Interrupt level callback to signify when the radio changes state.
 *
 * @param[in] state Current state of the radio, as defined by EFR32 data sheet
 * TODO: Unify these states with the RAIL_RadioState_t type? (There are much
 *    more than just TX, RX, and IDLE)
 */
void RAILCb_RadioStateChanged(uint8_t state) {}


/**
 * This function is called when the RAIL timer expires
 *
 * You must implement a stub for this in your RAIL application even if you
 * don't use the timer.
 */
void RAILCb_TimerExpired(void)
{
}

