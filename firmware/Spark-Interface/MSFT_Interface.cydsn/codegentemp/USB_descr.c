/*******************************************************************************
* File Name: USB_descr.c
* Version 2.80
*
* Description:
*  USB descriptors and storage.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USB.h"
#include "USB_pvt.h"


/*****************************************************************************
*  User supplied descriptors.  If you want to specify your own descriptors,
*  define USER_SUPPLIED_DESCRIPTORS below and add your descriptors.
*****************************************************************************/
/* `#START USER_DESCRIPTORS_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
*  USB Customizer Generated Descriptors
***************************************/

#if !defined(USER_SUPPLIED_DESCRIPTORS)
/*********************************************************************
* Device Descriptors
*********************************************************************/
const uint8 CYCODE USB_DEVICE0_DESCR[18u] = {
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: DEVICE                  */ 0x01u,
/* bcdUSB (ver 2.0)                        */ 0x00u, 0x02u,
/* bDeviceClass                            */ 0x02u,
/* bDeviceSubClass                         */ 0x00u,
/* bDeviceProtocol                         */ 0x00u,
/* bMaxPacketSize0                         */ 0x08u,
/* idVendor                                */ 0xD6u, 0x2Bu,
/* idProduct                               */ 0x01u, 0x42u,
/* bcdDevice                               */ 0x01u, 0x00u,
/* iManufacturer                           */ 0x01u,
/* iProduct                                */ 0x02u,
/* iSerialNumber                           */ 0x80u,
/* bNumConfigurations                      */ 0x01u
};
/*********************************************************************
* Config Descriptor  
*********************************************************************/
const uint8 CYCODE USB_DEVICE0_CONFIGURATION0_DESCR[67u] = {
/*  Config Descriptor Length               */ 0x09u,
/*  DescriptorType: CONFIG                 */ 0x02u,
/*  wTotalLength                           */ 0x43u, 0x00u,
/*  bNumInterfaces                         */ 0x02u,
/*  bConfigurationValue                    */ 0x01u,
/*  iConfiguration                         */ 0x01u,
/*  bmAttributes                           */ 0xC0u,
/*  bMaxPower                              */ 0x32u,
/*********************************************************************
* CDC Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x00u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x02u,
/*  bInterfaceSubClass                     */ 0x02u,
/*  bInterfaceProtocol                     */ 0x01u,
/*  iInterface                             */ 0x03u,
/*********************************************************************
* Header Descriptor
*********************************************************************/
/*  Header Descriptor Length               */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x00u,
/*  bcdADC                                 */ 0x10u, 0x01u,
/*********************************************************************
* Abstract Control Management Descriptor
*********************************************************************/
/*  Abstract Control Management Descriptor Length*/ 0x04u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x02u,
/*  bmCapabilities                         */ 0x02u,
/*********************************************************************
* Union Descriptor
*********************************************************************/
/*  Union Descriptor Length                */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x06u,
/*  bControlInterface                      */ 0x00u,
/*  bSubordinateInterface                  */ 0x01u,
/*********************************************************************
* Call Management Descriptor
*********************************************************************/
/*  Call Management Descriptor Length      */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x01u,
/*  bmCapabilities                         */ 0x00u,
/*  bDataInterface                         */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x81u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x08u, 0x00u,
/*  bInterval                              */ 0x0Au,
/*********************************************************************
* Data Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x01u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x0Au,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x04u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x82u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x03u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x01u
};

/*********************************************************************
* String Descriptor Table
*********************************************************************/
const uint8 CYCODE USB_STRING_DESCRIPTORS[183u] = {
/*********************************************************************
* Language ID Descriptor
*********************************************************************/
/* Descriptor Length                       */ 0x04u,
/* DescriptorType: STRING                  */ 0x03u,
/* Language Id                             */ 0x09u, 0x04u,
/*********************************************************************
* String Descriptor: "Coroware, Inc."
*********************************************************************/
/* Descriptor Length                       */ 0x1Eu,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'o', 0u,(uint8)'r', 0u,(uint8)'o', 0u,(uint8)'w', 0u,
 (uint8)'a', 0u,(uint8)'r', 0u,(uint8)'e', 0u,(uint8)',', 0u,(uint8)' ', 0u,
 (uint8)'I', 0u,(uint8)'n', 0u,(uint8)'c', 0u,(uint8)'.', 0u,
/*********************************************************************
* String Descriptor: "RS485 Multidrop Controller"
*********************************************************************/
/* Descriptor Length                       */ 0x36u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'R', 0u,(uint8)'S', 0u,(uint8)'4', 0u,(uint8)'8', 0u,(uint8)'5', 0u,
 (uint8)' ', 0u,(uint8)'M', 0u,(uint8)'u', 0u,(uint8)'l', 0u,(uint8)'t', 0u,
 (uint8)'i', 0u,(uint8)'d', 0u,(uint8)'r', 0u,(uint8)'o', 0u,(uint8)'p', 0u,
 (uint8)' ', 0u,(uint8)'C', 0u,(uint8)'o', 0u,(uint8)'n', 0u,(uint8)'t', 0u,
 (uint8)'r', 0u,(uint8)'o', 0u,(uint8)'l', 0u,(uint8)'l', 0u,(uint8)'e', 0u,
 (uint8)'r', 0u,
/*********************************************************************
* String Descriptor: "CDC Communication Interface"
*********************************************************************/
/* Descriptor Length                       */ 0x38u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'C', 0u,
 (uint8)'o', 0u,(uint8)'m', 0u,(uint8)'m', 0u,(uint8)'u', 0u,(uint8)'n', 0u,
 (uint8)'i', 0u,(uint8)'c', 0u,(uint8)'a', 0u,(uint8)'t', 0u,(uint8)'i', 0u,
 (uint8)'o', 0u,(uint8)'n', 0u,(uint8)' ', 0u,(uint8)'I', 0u,(uint8)'n', 0u,
 (uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,(uint8)'a', 0u,
 (uint8)'c', 0u,(uint8)'e', 0u,
/*********************************************************************
* String Descriptor: "CDC Data Interface"
*********************************************************************/
/* Descriptor Length                       */ 0x26u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'D', 0u,
 (uint8)'a', 0u,(uint8)'t', 0u,(uint8)'a', 0u,(uint8)' ', 0u,(uint8)'I', 0u,
 (uint8)'n', 0u,(uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,
 (uint8)'a', 0u,(uint8)'c', 0u,(uint8)'e', 0u,
/*********************************************************************/
/* Marks the end of the list.              */ 0x00u};
/*********************************************************************/

/*********************************************************************
* Serial Number String Descriptor
*********************************************************************/
const uint8 CYCODE USB_SN_STRING_DESCRIPTOR[2] = {
/* Descriptor Length                       */ 0x02u,
/* DescriptorType: STRING                  */ 0x03u,

};



/*********************************************************************
* Endpoint Setting Table -- This table contain the endpoint setting
*                           for each endpoint in the configuration. It
*                           contains the necessary information to
*                           configure the endpoint hardware for each
*                           interface and alternate setting.
*********************************************************************/
const T_USB_EP_SETTINGS_BLOCK CYCODE USB_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[3u] = {
/* IFC  ALT    EPAddr bmAttr MaxPktSize Class ********************/
{0x00u, 0x00u, 0x81u, 0x03u, 0x0008u,   0x02u},
{0x01u, 0x00u, 0x82u, 0x02u, 0x0040u,   0x0Au},
{0x01u, 0x00u, 0x03u, 0x02u, 0x0040u,   0x0Au}
};
const uint8 CYCODE USB_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[2u] = {
0x02u, 0x0Au
};
/*********************************************************************
* Config Dispatch Table -- Points to the Config Descriptor and each of
*                          and endpoint setup table and to each
*                          interface table if it specifies a USB Class
*********************************************************************/
const T_USB_LUT CYCODE USB_DEVICE0_CONFIGURATION0_TABLE[5u] = {
    {0x01u,     &USB_DEVICE0_CONFIGURATION0_DESCR},
    {0x03u,     &USB_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,     &USB_DEVICE0_CONFIGURATION0_INTERFACE_CLASS}
};
/*********************************************************************
* Device Dispatch Table -- Points to the Device Descriptor and each of
*                          and Configuration Tables for this Device 
*********************************************************************/
const T_USB_LUT CYCODE USB_DEVICE0_TABLE[2u] = {
    {0x01u,     &USB_DEVICE0_DESCR},
    {0x01u,     &USB_DEVICE0_CONFIGURATION0_TABLE}
};
/*********************************************************************
* Device Table -- Indexed by the device number.
*********************************************************************/
const T_USB_LUT CYCODE USB_TABLE[1u] = {
    {0x01u,     &USB_DEVICE0_TABLE}
};

#endif /* USER_SUPPLIED_DESCRIPTORS */

#if defined(USB_ENABLE_MSOS_STRING)

    /******************************************************************************
    *  USB Microsoft OS String Descriptor
    *  "MSFT" identifies a Microsoft host
    *  "100" specifies version 1.00
    *  USB_GET_EXTENDED_CONFIG_DESCRIPTOR becomes the bRequest value
    *  in a host vendor device/class request
    ******************************************************************************/

    const uint8 CYCODE USB_MSOS_DESCRIPTOR[USB_MSOS_DESCRIPTOR_LENGTH] = {
    /* Descriptor Length                       */   0x12u,
    /* DescriptorType: STRING                  */   0x03u,
    /* qwSignature - "MSFT100"                 */   (uint8)'M', 0u, (uint8)'S', 0u, (uint8)'F', 0u, (uint8)'T', 0u,
                                                    (uint8)'1', 0u, (uint8)'0', 0u, (uint8)'0', 0u,
    /* bMS_VendorCode:                         */   USB_GET_EXTENDED_CONFIG_DESCRIPTOR,
    /* bPad                                    */   0x00u
    };

    /* Extended Configuration Descriptor */

    const uint8 CYCODE USB_MSOS_CONFIGURATION_DESCR[USB_MSOS_CONF_DESCR_LENGTH] = {
    /*  Length of the descriptor 4 bytes       */   0x28u, 0x00u, 0x00u, 0x00u,
    /*  Version of the descriptor 2 bytes      */   0x00u, 0x01u,
    /*  wIndex - Fixed:INDEX_CONFIG_DESCRIPTOR */   0x04u, 0x00u,
    /*  bCount - Count of device functions.    */   0x01u,
    /*  Reserved : 7 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    /*  bFirstInterfaceNumber                  */   0x00u,
    /*  Reserved                               */   0x01u,
    /*  compatibleID    - "CYUSB\0\0"          */   (uint8)'C', (uint8)'Y', (uint8)'U', (uint8)'S', (uint8)'B',
                                                    0x00u, 0x00u, 0x00u,
    /*  subcompatibleID - "00001\0\0"          */   (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'1',
                                                    0x00u, 0x00u, 0x00u,
    /*  Reserved : 6 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };

#endif /* USB_ENABLE_MSOS_STRING */

/* DIE ID string descriptor for 8 bytes ID */
#if defined(USB_ENABLE_IDSN_STRING)
    uint8 USB_idSerialNumberStringDescriptor[USB_IDSN_DESCR_LENGTH];
#endif /* USB_ENABLE_IDSN_STRING */


/* [] END OF FILE */
