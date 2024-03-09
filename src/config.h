#ifndef CONFIG_H_
#define CONFIG_H_

#include <Arduino.h>
#include <CircularBuffer.h>

#include "version.h"

#define HMG_01

//---DEFAULT---
//LAN
#define ETH_CLK_MODE_0 ETH_CLOCK_GPIO0_IN
#define ETH_POWER_PIN_0 255
#define ETH_TYPE_0 ETH_PHY_LAN8720
#define ETH_ADDR_0 1
#define ETH_MDC_PIN_0 255
#define ETH_MDIO_PIN_0 255
//ZIGBEE
#define RESTART_ZIGBEE_0 15
#define FLASH_ZIGBEE_0 22
#define ZRXD_0 23
#define ZTXD_0 19

//---WT32-ETH01---
//LAN
#define ETH_CLK_MODE_1 ETH_CLOCK_GPIO0_IN
#define ETH_POWER_PIN_1 16
#define ETH_TYPE_1 ETH_PHY_LAN8720
#define ETH_ADDR_1 1
#define ETH_MDC_PIN_1 23
#define ETH_MDIO_PIN_1 18
//ZIGBEE
#define RESTART_ZIGBEE_1 33
#define FLASH_ZIGBEE_1 32
#define ZRXD_1 5
#define ZTXD_1 17

#ifndef HMG_01
//---TTGO T-Internet-POE---
//LAN
#define ETH_CLK_MODE_2 ETH_CLOCK_GPIO17_OUT
#define ETH_POWER_PIN_2 -1
#define ETH_TYPE_2 ETH_PHY_LAN8720
#define ETH_ADDR_2 0
#define ETH_MDC_PIN_2 23
#define ETH_MDIO_PIN_2 18
//ZIGBEE
#define RESTART_ZIGBEE_2 16
#define FLASH_ZIGBEE_2 32
#define ZRXD_2 36
#define ZTXD_2 4
#else
//--- clone UZG-01 HamGeek Corogoo HMG-01 POE Plus---
/* 
SMC8720A Lan
RS2099  bidirectional 4-channel single-pole (SPDT)
CH340C Usb-Rs232
GPIO CONTROL SMC8720A-LAN8720
ETH_CLK_MODE_1 ETH_CLOCK_GPIO17_OUT GPIO 3
ETH_POWER_PIN_1 5
ETH_TYPE_1 ETH_PHY_LAN8720 Type of the Ethernet PHY
ETH_ADDR_1 0 
ETH_MDC_PIN_1 GPIO 23
ETH_MDIO_PIN_1 GPIO 18
CC2652P
GPIO CONTROL CC2652P
CC2652P_RST OUTPUT GPIO 16
CC2652P_FLSH OUTPUT GPIO 32
CC2652P_RXD GPIO 36
CC2652P_TXD GPIO 4
--------------------------
GPIOs ESP32
GPIO EN-> RESET ->CH340
GPIO 0->  BOOT ->CH340
GPIO 1->  RXD Pin 13 (NC4) RS2099 (SPDT) USB
GPIO 2->  NC
GPIO 3->  RXD pin 9 (NC3) RS2099 (SPDT) USB
GPIO 4->  TXD pin 16 COM1 RS2099 
GPIO 5->  PIN 15 nRST LAN8720  
GPIO 6->  NC
GPIO 7->  NC
GPIO 8->  NC
GPIO 9->  NC
GPIO 10-> NC
GPIO 11-> NC
GPIO 12-> Led red
GPIO 13-> NC
GPIO 14-> Led blue
GPIO 15-> NC
GPIO 16-> pin 35 RST CC2652
GPIO 17-> pin 5 CLKIN LAN8720 
GPIO 18-> pin 12 MDIO LAN8720
GPIO 19-> pin 17 TXD0 LAN8720
GPIO 21-> pin 16 TXEN LAN8720
GPIO 22-> pin 18 TXD1 LAN8720
GPIO 23-> pin 13 MDC LAN8720
GPIO 25-> pin 8 RXD0 LAN8720 + MODE0
GPIO 26-> pin 7 RXD1 LAN8720 + MODE1
GPIO 27-> pin 11 CRS_DV LAN8720 + MODE2
GPIO 32-> pin DIO15 FLSR CC2652P
GPIO 33-> pin 2/10 IN1-2/INI3-4 RS2099 (SPDT) 0->Ethernet, 1->USB
GPIO 34-> NC
GPIO 35-> BUTOON config.
GPIO 36-> pin 4 COM2 RS2099 pin (SPDT) 0->GPIO36-DIO13 1->GPIO4-DIO12
GPIO 39-> NC 
*/
#define ETH_TYPE_2 ETH_PHY_LAN8720
#define ETH_ADDR_2 0
#define ETH_MDC_PIN_2 23
#define ETH_MDIO_PIN_2 18
#define ETH_POWER_PIN_2 5
#define ETH_CLK_MODE_2 ETH_CLOCK_GPIO17_OUT 
//ZIGBEE
#define RESTART_ZIGBEE_2 16
#define FLASH_ZIGBEE_2 32
#define ZRXD_2 36
#define ZTXD_2 4
//BUTOON
#define BTN 35
//SWITCH 
#define MODE_SWITCH 33 // mode USB 1, 0 enable zigbee serial
//LEDs
#define LED_USB 12 // Red
#define LED_PWR 14 // Blue
#endif

//---China-GW---
//LAN
#define ETH_CLK_MODE_3 ETH_CLOCK_GPIO17_OUT
#define ETH_POWER_PIN_3 12
#define ETH_TYPE_3 ETH_PHY_LAN8720
#define ETH_ADDR_3 0
#define ETH_MDC_PIN_3 23
#define ETH_MDIO_PIN_3 18
//ZIGBEE
#define RESTART_ZIGBEE_3 12
#define FLASH_ZIGBEE_3 14
#define ZRXD_3 32
#define ZTXD_3 33

//---Omilex EPS32-POE---
//LAN
#define ETH_CLK_MODE_4 ETH_CLOCK_GPIO17_OUT
#define ETH_POWER_PIN_4 12
#define ETH_TYPE_4 ETH_PHY_LAN8720
#define ETH_ADDR_4 0
#define ETH_MDC_PIN_4 23
#define ETH_MDIO_PIN_4 18
//ZIGBEE
#define RESTART_ZIGBEE_4 16
#define FLASH_ZIGBEE_4 32
#define ZRXD_4 36
#define ZTXD_4 4

#define PRODUCTION 1
#define FLASH 0

#define MAX_SOCKET_CLIENTS 5
#define BAUD_RATE 38400
#define TCP_LISTEN_PORT 9999

#define ETH_ERROR_TIME 30

#define FORMAT_LITTLEFS_IF_FAILED true

#ifndef HMG_01
#define ONE_WIRE_BUS 33
#endif

struct ConfigSettingsStruct
{
  bool enableWiFi;
  char ssid[50];
  char password[50];
  char ipAddressWiFi[18];
  char ipMaskWiFi[16];
  char ipGWWiFi[18];
  bool dhcpWiFi;
  bool dhcp;
  bool connectedEther;
  char ipAddress[18];
  char ipMask[16];
  char ipGW[18];
  int serialSpeed;
  int socketPort;
  bool disableWeb;
  int refreshLogs;
  char hostname[50];
  bool connectedSocket[10];
  int connectedClients;
  bool wifiModeAP;
  unsigned long socketTime;
  unsigned long disconnectEthTime;
  int board;
  char boardName[50];
  bool emergencyWifi;
  int rstZigbeePin;
  int flashZigbeePin;
  bool mqttEnable;
  char mqttServer[50];
  IPAddress mqttServerIP;
  int mqttPort;
  char mqttUser[50];
  char mqttPass[50];
  char mqttTopic[50];
  //bool mqttRetain;
  int mqttInterval;
  bool mqttDiscovery;
  unsigned long mqttReconnectTime;
  unsigned long mqttHeartbeatTime;
  int tempOffset;
  bool webAuth;
  char webUser[50];
  char webPass[50];
  bool disableEmerg;
  int wifiRetries;
  bool disablePingCtrl;
  int restarts;
  unsigned long wifiAPenblTime;
};

struct InfosStruct
{
  char device[8];
  char mac[8];
  char flash[8];
};

typedef CircularBuffer<char, 1024> LogConsoleType;

#define WL_MAC_ADDR_LENGTH 6

#ifdef DEBUG
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#endif
#endif
