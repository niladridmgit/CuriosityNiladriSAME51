/*
 
  begin(uint8_t idmodeset, uint32_t speedset, enum mcan_can_mode canmode)
  
  @idmodeset:
  
  #define MCP_STDEXT   0        // Standard and Extended    
  #define MCP_STD      1        // Standard IDs ONLY       
  #define MCP_EXT      2        // Extended IDs ONLY        
  #define MCP_ANY      3        // Disables Masks and Filters 

  @speedset:
  
  #define CAN_4K096BPS 4096
  #define CAN_5KBPS    5000
  #define CAN_10KBPS   10000
  #define CAN_20KBPS   20000
  #define CAN_31K25BPS 31250
  #define CAN_33K3BPS  33300
  #define CAN_40KBPS   40000
  #define CAN_50KBPS   50000
  #define CAN_80KBPS   80000
  #define CAN_100KBPS  100000
  #define CAN_125KBPS  125000
  #define CAN_200KBPS  200000
  #define CAN_250KBPS  250000
  #define CAN_500KBPS  500000
  #define CAN_1000KBPS 1000000
  
  @canmode:
  
  MCAN_MODE_CAN                             ISO 11898-1 CAN 2.0 mode 

  MCAN_MODE_EXT_LEN_CONST_RATE              Long CAN FD frame.
                                            * - TX and RX payloads up to 64 bytes.
                                            * - Slow transmitter: TX frames are sent at constant bit rate.
                                            * - Fast receiver: both constant-rate (slow) and dual-rate (fast)
                                            *   RX frames are supported and received. 

  MCAN_MODE_EXT_LEN_DUAL_RATE               Long and fast CAN FD frame.
                                            * - TX and RX payloads up to 64 bytes.
                                            * - Fast transmitter: control, data and CRC fields are transmitted at a
                                            *   higher bit rate.
                                            * - Fast receiver. 
*/

#include "same51_can.h"

SAME51_CAN can;

void setup()
{
    Serial1.begin(115200);
    while(!Serial1);
    
    uint8_t ret;
    ret = can.begin(MCP_ANY, CAN_500KBPS, MCAN_MODE_CAN);
    if (ret == CAN_OK) 
    {
        Serial1.println("CAN Initialized Successfully!");
    } else 
    {
        Serial1.println("Error Initializing CAN...");
        while(1);
    }
}

void loop()
{
    uint8_t ret;
    uint32_t id;
    uint8_t len;
    uint8_t buf[8];
    uint8_t i;
    
    ret = can.readMsgBuf(&id, &len, buf);
    if (ret == CAN_OK) {
        Serial1.print("Got a message from: ");
        Serial1.println(id);
        Serial1.print(" Len: ");
        Serial1.println(len);
        Serial1.print("Dta: ");
        for (i = 0; i < len; i++) {
            Serial1.print(buf[i], HEX);
            Serial1.print(", ");
        }
        Serial1.println();
    }
}

// END FILE
