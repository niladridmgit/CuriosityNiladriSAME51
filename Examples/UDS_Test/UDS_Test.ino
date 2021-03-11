#include "same51_can.h"
#include "iso-tp.h"
#include "uds.h"

SAME51_CAN can;
IsoTp isotp(&can);
UDS uds(&isotp);

struct Session_t session;

void setup()
{
  Serial1.begin(115200);
  Serial.begin(115200);
  while(!Serial1);
  while(!Serial);
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
  delay(5000);
}

void loop()
{
  uint8_t ds[]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F};
  struct Session_t diag;
  uint16_t retval=0;
  Serial.println(F("Diag Session"));
  Serial1.println(F("Diag Session"));
  diag.tx_id=0x7E0;
  diag.rx_id=0x7E8;
  diag.sid=UDS_SID_TRANSFER_DATA;
  diag.Data=ds;
  diag.len=15;
  if(retval=uds.Session(&diag))
  {
    Serial1.print(F("UDS Session Error "));
    Serial1.print(retval); Serial1.print(F(" NRC "));
    Serial1.println(retval,HEX);
    Serial.print(F("UDS Session Error "));
    Serial.print(retval); Serial.print(F(" NRC "));
    Serial.println(retval,HEX);
  }
  else
  {
    Serial1.println(F("Established with "));
    Serial.println(F("Established with "));
    uds.print_buffer(diag.Data,diag.len);
  }
  delay(1000);
}
