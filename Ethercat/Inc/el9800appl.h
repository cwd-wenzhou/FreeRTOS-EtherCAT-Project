/**
 * \addtogroup EL9800Appl EL9800 application
 * @{
 * This application includes three functional modules:<br>
 * Digital Input<br>
 * Digital Outputs<br>
 * Analog Input<br>
 * The objects of the modules are defined according the ETG.5001.<br>
 */

/**
\file el9800appl.h
\author EthercatSSC@beckhoff.com
\brief EL9800 Application defines, typedefs and global variables

\version 5.01

<br>Changes to version - :<br>
V5.01 : Start file change log
 */
#ifndef _EL9800APPL_H_
#define _EL9800APPL_H_

/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecatappl.h"
#include  <string.h>
//添加于12.23，电压值的全局变量外部声明
extern INT16 CH1_AD_Inputs,CH2_AD_Inputs,CH3_AD_Inputs,CH4_AD_Inputs;
extern float CH1_current,CH2_current,CH3_current,CH4_current;
//添加于12.23，电压值的全局变量外部声明


/*-----------------------------------------------------------------------------------------
------
------    Defines and Typedef
------
-----------------------------------------------------------------------------------------*/

/**
 * \addtogroup PdoMappingObjects PDO Mapping Objects
 *
 * Digital Input PDO mapping : 0x1A00<br>
 * Digital Output PDO mapping : 0x1601<br>
 * Analog Input PDO mapping : 0x1A02
 * @{
 */
/** \brief 0x1601 (Digital output RxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[9]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1601;

/** \brief 0x1602 (Digital output RxPDO) data structure*/   
//2020.8.6添加
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[5]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1602;

/** \brief 0x1A00 (Digital input TxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[4]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A00;

/** \brief 0x1A01 (Digital input TxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[9]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A01;

/** \brief 0x1A02 (Analog input TxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[4]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A02;
/** @}*/

/** \brief 0x1A03 (Self_Check_Status TxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT32   aEntries[9]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A03;
/** @}*/


/** \brief 0x1A05 (厂家信息TxPDO) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
	// CHAR   product_name[4]; /**< \brief ECMK-A/B设备名称*/
   UINT32   aEntries[8]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1A05;
/** @}*/

/**
 * \addtogroup SmAssignObjects SyncManager Assignment Objects
 * SyncManager 2 : 0x1C12 
 * <br>SyncManager 3 : 0x1C13
 * @{
 */
/** \brief 0x1C12 (SyncManager 2 assignment) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[1]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C12;


/** \brief 0x1C13 (SyncManager 3 assignment) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   UINT16   aEntries[5]; /**< \brief Entry buffer*/
} OBJ_STRUCT_PACKED_END
TOBJ1C13;
/** @}*/


/**
 * \addtogroup PDO Process Data Objects
 * Digital Inputs : 0x6000<br>
 * Analog Inputs : 0x6010<br> 
 * Digital Outputs : 0x7020
 * @{
 */
/** \brief 0x6000 (Digital input object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   INT16    CH1; /**< \brief CH1 value*/
   INT16    CH2; /**< \brief CH1 value*/
   INT16    CH3; /**< \brief CH1 value*/
   INT16    CH4; /**< \brief CH1 value*/
} OBJ_STRUCT_PACKED_END
TOBJ6000;

/** \brief 0x6010 (Digital output object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(CH1_ENABLE); /**< \brief CH1_ENABLE*/
   BOOLEAN(CH2_ENABLE); /**< \brief CH2_ENABLE*/
   BOOLEAN(CH3_ENABLE); /**< \brief CH3_ENABLE*/
   BOOLEAN(CH4_ENABLE); /**< \brief CH4_ENABLE*/
   UINT16(CH1_Frequency); /**< \brief CH1_Frequency*/
   UINT16(CH2_Frequency); /**< \brief CH2_Frequency*/
   UINT16(CH3_Frequency); /**< \brief CH3_Frequency*/
   UINT16(CH4_Frequency); /**< \brief CH4_Frequency*/
   ALIGN12(SubIndex0012) /**< \brief 12Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ6010;
/** @}*/

/** \brief 0x6020 (Analog input object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   float   CH_CURRENT[4];
} OBJ_STRUCT_PACKED_END
TOBJ6020;


/** \brief 0x6030 (Self_Check input object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(CH1_STATE); /**< \brief CH1_STATE */
   BOOLEAN(CH2_STATE); /**< \brief CH2_STATE */
   BOOLEAN(CH3_STATE); /**< \brief CH3_STATE */
   BOOLEAN(CH4_STATE); /**< \brief CH4_STATE */
	 BOOLEAN(Software_STATE); /**< \brief Software_STATE */
   BOOLEAN(Hardware_STATE); /**< \brief Hardware_STATE */
   BOOLEAN(EtherCAT_STATE); /**< \brief EtherCAT_STATE */
   BOOLEAN(ALL_STATUS); /**< \brief ALL_STATE */
   ALIGN8(SubIndex08) /**< \brief 8Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ6030;


/** \brief 0x6050 (厂家信息 input object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   CHAR   product_name[6]; /**< \brief ECMK-A/B设备名称*/
   CHAR   hardware_version[4]; /**< \brief ECMK-A/B硬件版本*/
   CHAR   software_version[4]; /**< \brief ECMK-A/B软件版本*/
   UINT16(UID); /**< \brief 设备标识符*/
	 UINT32(manufacture_ID);/**< \brief 制造商ID*/
	 UINT32(product_ID);/**< \brief 产品ID*/
	 UINT32(version_ID);/**< \brief 版本ID*/
	 UINT32(num_ID);/**< \brief 序列号ID*/
} OBJ_STRUCT_PACKED_END
TOBJ6050;



/** \brief 0x7010 (Digital output object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(CH1_ENABLE); /**< \brief CH1_ENABLE*/
   BOOLEAN(CH2_ENABLE); /**< \brief CH2_ENABLE*/
   BOOLEAN(CH3_ENABLE); /**< \brief CH3_ENABLE*/
   BOOLEAN(CH4_ENABLE); /**< \brief CH4_ENABLE*/
   UINT16(CH1_Frequency); /**< \brief CH1_Frequency*/
   UINT16(CH2_Frequency); /**< \brief CH2_Frequency*/
   UINT16(CH3_Frequency); /**< \brief CH3_Frequency*/
   UINT16(CH4_Frequency); /**< \brief CH4_Frequency*/
   ALIGN12(SubIndex0012) /**< \brief 12Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ7010;
/** @}*/



/** \brief 0x7010 (Digital output object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(CH1); /**< \brief AD_CH1*/
   BOOLEAN(CH2); /**< \brief AD_CH2*/
   BOOLEAN(CH3); /**< \brief AD_CH3*/
   BOOLEAN(CH4); /**< \brief AD_CH4*/
   BOOLEAN(DUMMY1); /**< \brief DUMMY1*/
   BOOLEAN(DUMMY2); /**< \brief DUMMY2*/
   BOOLEAN(DUMMY3); /**< \brief DUMMY3*/
   BOOLEAN(DUMMY4); /**< \brief DUMMY4*/
   ALIGN8(SubIndex008) /**< \brief 8Bit alignment*/
} OBJ_STRUCT_PACKED_END
TOBJ7011;
/** @}*/




//edit on 2020.12.25
/** \brief 0x7012 (电磁阀控制对象字典 output object) data structure*/
//typedef struct OBJ_STRUCT_PACKED_START {
//   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
//   BOOLEAN(diancifa1); /**< \brief diancifa1 1*/
//   BOOLEAN(diancifa2); /**< \brief diancifa1 2*/
//   BOOLEAN(diancifa3); /**< \brief diancifa1 3*/
//   BOOLEAN(diancifa4); /**< \brief diancifa1 4*/
//   ALIGN12(SubIndex0012) /**< \brief 12Bit alignment*/
//} OBJ_STRUCT_PACKED_END
//TOBJ7012;
/** @}*/


/**
 * \addtogroup ConfigObjects Configuration Objects
 * Analog input settings: 0x8020
 * @{
 */
/** \brief 0x8020 (Analog input settings object) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex 0*/
   BOOLEAN(bEnableuserscale); /**< \brief Enable user scaling*/
   BIT3(b3Presentation); /**< \brief Value presentation*/
   ALIGN2(SubIndex005) /**< \brief 2Bit Alignment*/
   BOOLEAN(bEnablelimit1); /**< \brief Enable limit 1*/
   BOOLEAN(bEnablelimit2); /**< \brief Enable limit 2*/
   ALIGN8(SubIndex009) /**< \brief 8Bit Alignment*/
   INT16   i16Offset; /**< \brief Value offset*/
   INT32   i32Gain; /**< \brief Value gain*/
   INT16   i16Limit1; /**< \brief Value limit 1*/
   INT16   i16Limit2; /**< \brief Value limit 2*/
} OBJ_STRUCT_PACKED_END
TOBJ8020;
/** @}*/


/**
 * \addtogroup DeviceParaObjects Device Parameter Objects
 * Modular Device Profile: 0xF000
 * @{
 */
/** \brief 0xF000 (Modular Device Profile) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT16   u16Moduleindexdistance; /**< \brief Module Index distance
                                     * 
                                     * Index distance between two modules (maximum number of objects per module and area)<br>
                                     * Default: 0x10*/
   UINT16   u16Maximumnumberofmodules; /**< \brief Maximum number of modules*/
} OBJ_STRUCT_PACKED_END
TOBJF000;


/** \brief 0xF010 (Module Profile List) data structure*/
typedef struct OBJ_STRUCT_PACKED_START {
   UINT16   u16SubIndex0; /**< \brief SubIndex0*/
   UINT32   aEntries[3]; /**< \brief Module profile information buffer
                          * 
                          * Bit 0..15: Profile number of the module on position 1<br>
                          * Bit 16..31: Profile specific*/
} OBJ_STRUCT_PACKED_END
TOBJF010;
/** @}*/

#endif //_EL9800APPL_H_

#ifdef _EVALBOARD_
    #define PROTO
#else
    #define PROTO extern
#endif


#ifdef _OBJD_
/**
 * \addtogroup SmAssignObjects SyncManager Assignment Objects
 * @{
 */
/**
 * \brief Entry descriptions of SyncManager assign objects
 *
 * SubIndex0<br>
 * SubIndex1 (for all other entries the same description will be used (because the object code is ARRAY))
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asPDOAssignEntryDesc[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};
/** @}*/

   
/**
 * \addtogroup EnumObjects Enum Objects
 * @{
 * Presentation (Signed/Unsigned) : 0x800
 */

/*---------------------------------------------
-    0x0800: ENUM (Signed/Unsigned Presentation)
-----------------------------------------------*/
CHAR sEnum0800_Value00[] = "\000\000\000\000Signed presentation"; /**< \brief Value = 0x00, Text = Signed presentation */
CHAR sEnum0800_Value01[] = "\001\000\000\000Unsigned presentation"; /**< \brief Value = 0x01, Text = Unsigned presentation */
CHAR *apEnum0800[2] = { sEnum0800_Value00, sEnum0800_Value01};/**< \brief List of Enum (0x800) values*/

/**
 * \brief Enum entry description
 *
 * SubIndex0<br>
 * Enum (Signed Presentation)
 * enum (Unsigned Presentation)
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x0800[] =
   {{DEFTYPE_UNSIGNED8, 8, ACCESS_READ | OBJACCESS_NOPDOMAPPING},
    {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value00), ACCESS_READ | OBJACCESS_NOPDOMAPPING},
   {DEFTYPE_OCTETSTRING, 8*SIZEOF(sEnum0800_Value01), ACCESS_READ | OBJACCESS_NOPDOMAPPING}};
/** @}*/


/**
* \addtogroup PdoMappingObjects PDO Mapping Objects
* @{
*/
/**
 * \brief Object 0x1601 (Digital output RxPDO) entry descriptions
 * 
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
 */
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1601[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

/**
 * \brief Object 0x1601 (Digital output RxPDO) name
 *
 * In this example no specific entry name is defined ("SubIndex xxx" is used)
 */
OBJCONST UCHAR OBJMEM aName0x1601[] = "DO RxPDO-Map\000\377";
#endif //#ifdef _OBJD_


/**
 * \brief Object 0x1601 (Digital output RxPDO) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x7010.1 1bit (Reference to CH1_ENABLE)<br>
 * SubIndex 2 : 0x7010.1 1bit (Reference to CH2_ENABLE)<br>
 * SubIndex 3 : 0x7010.1 1bit (Reference to CH3_ENABLE)<br>
 * SubIndex 4 : 0x7010.1 1bit (Reference to CH4_ENABLE)<br>
 * SubIndex 5 : 0x7010.1 16bit (Reference to CH1_Frequency)<br>
 * SubIndex 6 : 0x7010.1 16bit (Reference to CH2_Frequency)<br>
 * SubIndex 7 : 0x7010.1 16bit (Reference to CH3_Frequency)<br>
 * SubIndex 8 : 0x7010.1 16bit (Reference to CH4_Frequency)
 */
PROTO TOBJ1601 AD_Switch_Cmd_IN
#ifdef _EVALBOARD_
 = {9, {0x70100101, 0x70100201, 0x70100301, 0x70100401,0x0c,0x70100510, 0x70100610, 0x70100710, 0x70100810}}
#endif
;
/** @}*/

 //添加于2020.12.25
 //电磁阀控制对象字典
//#ifdef _OBJD_
// OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1602[] = {
//   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
//   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

///**
// * \brief Object 0x1601 (Digital output RxPDO) name
// *
// * In this example no specific entry name is defined ("SubIndex xxx" is used)
// */
//OBJCONST UCHAR OBJMEM aName0x1602[] = "AO RxPDO-Map\000\377";
//#endif //#ifdef _OBJD_

//PROTO TOBJ1602 sDORxPDOMap_test
//#ifdef _EVALBOARD_
// = {5, {0x70120101, 0x70120201, 0x70120301, 0x70120401,0x0c}}
//#endif
//;
//添加于2020.12.25
 


/**
 * \addtogroup PdoParameter PDO Parameter
 * @{
 *
 * Parameter for PDO mapping object 0x1A02 : 0x1802
 */
#ifdef _OBJD_
/**
 * \brief Entry descriptions of TxPDO Parameter object (0x1802)
 * 
 * Subindex 0<br>
 * SubIndex 1 - 5 : not defined<br>
 * SubIndex 6 : Exclude TxPDOs<br>
 * SubIndex 7 : TxPDO State<br>
 * SubIndex 8 : not defined<br>
 * SubIndex 9 : TxPDO Toggle
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x1802[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {0, 0x0, 0},
   {DEFTYPE_OCTETSTRING, 0x00, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING},
   {0, 0x0, 0},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_TXPDOMAPPING}};

/**
 * \brief Object 0x1802 (TxPDO Parameter) object and entry names
 */
OBJCONST UCHAR OBJMEM aName0x1802[] = "TxPDO Parameter\000\000\000\000\000\000Exclude TxPDOs\000TxPDOState\000\000TxPDO Toggle\000\377";
#endif //#ifdef _OBJD_



/**
 * \brief Object 0x1802 (TxPDO Parameter) variable to handle object data
 * 
 * Only Subindex0 for this Object is stored here (all values are stored in other structures, see "ReadObject0x1802" for more details)
 */
PROTO UINT16 TxPDO1802Subindex0
#ifdef _EVALBOARD_
    = 9
#endif
    ;
/** @}*/


/**
 * \addtogroup PdoMapping PDO Mapping Objects
 * @{
 */
/**
 * \brief Object 0x1A00 (Digital input TxPDO) entry descriptions
 *
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A00[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};


/**
 * \brief Object 0x1A00 (Digital input TxPDO) object and entry names
 *
 * In this example no specific entry name is defined ("SubIndex xxx" is used)
 */
OBJCONST UCHAR OBJMEM aName0x1A00[] = "DI TxPDO-Map\000\377";
#endif //#ifdef _OBJD_


/**
 * \brief Object 0x1A00 (Digital Input TxPDO) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x6000.1 16bit (Reference to CH1)<br>
 * SubIndex 1 : 0x6000.2 16bit (Reference to CH2)<br>
 * SubIndex 1 : 0x6000.3 16bit (Reference to CH3)<br>
 * SubIndex 1 : 0x6000.4 16bit (Reference to CH4)<br>
 */
PROTO TOBJ1A00 sDITxPDOMap
#ifdef _EVALBOARD_
 = {4, {0x60000110, 0x60000210, 0x60000310, 0x60000410}}
#endif
;

 
/**
 * \brief Object 0x1601 (Digital output RxPDO) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x6010.1 1bit (Reference to CH1_ENABLE)<br>
 * SubIndex 2 : 0x6010.1 1bit (Reference to CH2_ENABLE)<br>
 * SubIndex 3 : 0x6010.1 1bit (Reference to CH3_ENABLE)<br>
 * SubIndex 4 : 0x6010.1 1bit (Reference to CH4_ENABLE)<br>
 * SubIndex 5 : 0x6010.1 16bit (Reference to CH1_Frequency)<br>
 * SubIndex 6 : 0x6010.1 16bit (Reference to CH2_Frequency)<br>
 * SubIndex 7 : 0x6010.1 16bit (Reference to CH3_Frequency)<br>
 * SubIndex 8 : 0x6010.1 16bit (Reference to CH4_Frequency) 
 * 修改于2020.12.23
 */ 

#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A01[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};


OBJCONST UCHAR OBJMEM aName0x1A01[] = "AO RxPDO-Map\000\377";
#endif //#ifdef _OBJD_

PROTO TOBJ1A01 AD_Switch_Status
#ifdef _EVALBOARD_
 = {9, {0x60100101, 0x60100201, 0x60100301, 0x60100401,0x0c,0x60100510, 0x60100610, 0x60100710, 0x60100810}}
#endif
;
//添加于2020.9.10
 

/**
 * \brief Object 0x1A02 (Current input TxPDO) entry descriptions
 *修改于2020.12.22
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A02[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ}, /* SubIndex 001: SubIndex 001 */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ}, /* SubIndex 002: SubIndex 002 */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ}, /* SubIndex 003: SubIndex 003 */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ}, /* SubIndex 004: SubIndex 004 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 005: SubIndex 005 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 006: SubIndex 006 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}, /* SubIndex 007: SubIndex 007 */
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}}; /* SubIndex 008: SubIndex 008 */


/**
 * \brief Object 0x1A02 (Analog input TxPDO) object and entry names
 *
 * In this example no specific entry name is defined ("SubIndex xxx" is used)
 */
OBJCONST UCHAR OBJMEM aName0x1A02[] = "AI TxPDO-Map\000\377";
#endif //#ifdef _OBJD_

	
/**
 *
 * \brief Object 0x1A02 (Analog Input TxPDO) variable to handle object data
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x6020.1 32bit (Reference to CH1-CURRENT)<br>
 * SubIndex 2 : 0x6020.2 32bit (Reference to CH2-CURRENT)<br>
 * SubIndex 3 : 0x6020.3 32bit (Reference to CH3-CURRENT)<br>
 * SubIndex 4 : 0x6020.5 32bit (Reference to CH4-CURRENT)<br>
 */
PROTO TOBJ1A02 sAITxPDOMap
#ifdef _EVALBOARD_
= {4, {0x60200120, 0x60200220, 0x60200320, 0x60200420}}
#endif
;
/**修改于2020.12.22@}*/




/**
 * \brief Object 0x1A03 (电磁阀状态 input TxPDO) entry descriptions
 *修改于2020.12.25
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A03[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

/**
 * \brief Object 0x1A03 (Self_Check_Status input TxPDO) entry descriptions
 *
 * In this example no specific entry name is defined ("SubIndex xxx" is used)
 */
OBJCONST UCHAR OBJMEM aName0x1A03[] = "AI TxPDO-Map\000\377";
#endif //#ifdef _OBJD_

	
/**
 *
 * \brief Object 0x1A03(Self_Check_Status input TxPDO) entry descriptions
 */
PROTO TOBJ1A03 Selfcheck_STATUS_1A03
#ifdef _EVALBOARD_
= {9, {0x60300101, 0x60300201, 0x60300301, 0x60300401,0x60300501, 0x60300601, 0x60300701, 0x60300801,0x08}}
#endif
;
/**修改于2020.12.29@}*/




/**
 * \brief Object 0x1A05 (厂家信息 input TxPDO) entry descriptions
 *修改于2020.12.28
 * SubIndex 0 : read only<br>
 * SubIndex x : read only<br>
 *  (x > 0)
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC	OBJMEM asEntryDesc0x1A05[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

/**
 * \brief Object 0x1A05 (厂家信息 input TxPDO) entry descriptions
 *
 * In this example no specific entry name is defined ("SubIndex xxx" is used)
 */
OBJCONST UCHAR OBJMEM aName0x1A05[] = "PRODUCT INFO TxPDO-Map\000\377";
#endif //#ifdef _OBJD_0

	
/**
 *
 * \brief Object 0x1A05 (厂家信息 input TxPDO) entry descriptions
 */
PROTO TOBJ1A05 ECMK_INFO_1A05
#ifdef _EVALBOARD_
= {8, {0x60500130, 0x60500220, 0x60500320, 0x60500410,0x60500520,0x60500620,0x60500720,0x60500820}}
#endif
;
/**修改于2020.12.28@}*/



/**
 * \addtogroup SmAssignObjects SyncManager Assignment Objects
 * @{
 */
#ifdef _OBJD_
/**
 * \brief 0x1C12 (SyncManager 2 assignment) object name 
 * 
 * No entry names defined because the object code is ARRAY and all entry names are "SubIndex 000"
 */
OBJCONST UCHAR OBJMEM aName0x1C12[] = "RxPDO assign";
#endif //#ifdef _OBJD_


/**
 * \brief 0x1C12 (SyncManager 2 assignment) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x1601
 */
PROTO TOBJ1C12 sRxPDOassign
#ifdef _EVALBOARD_
= {0x01, {0x1601}}
#endif
;


#ifdef _OBJD_
/**
 * \brief 0x1C13 (SyncManager 3 assignment) object name 
 * 
 * No entry names defined because the object code is ARRAY and all entry names are "SubIndex 000"
 */
OBJCONST UCHAR OBJMEM aName0x1C13[] = "TxPDO assign";
#endif //#ifdef _OBJD_


/**
 * \brief 0x1C13 (SyncManager 3 assignment) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex 1 : 0x1A00<br>
 * SubIndex 2 : 0x1A02
 */
PROTO TOBJ1C13 sTxPDOassign
#ifdef _EVALBOARD_
= {0x05, {0x1A00,0x1A01,0x1A02,0x1A03,0x1A05}}
#endif
;
/** @}*/


/**
 * \addtogroup PDO Process Data Objects
 * @{
 */
#ifdef _OBJD_
/**
 * \brief Object 0x6000 (Digital input object) entry descriptions
 *
 * SubIndex 0 : read only<br>
 * SubIndex x : (One description for each switch) read only and TxPdo mappable<br>
 *  (x > 0)
*/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6000[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 001: CH 1 */
	 {DEFTYPE_INTEGER16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 001: CH 2 */
	 {DEFTYPE_INTEGER16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 001: CH 3 */
	 {DEFTYPE_INTEGER16, 0x10, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 001: CH 4 */
   }; /* Subindex 004 for align */

/**
 * \brief 0x6000 (Digital input object) object and entry names
 */
OBJCONST UCHAR OBJMEM aName0x6000[] = "AD Inputs\000CH 1\000CH 2\000CH 3\000CH 4\000\377";
#endif //#ifdef _OBJD_


/**
 * \brief 0x6000 (Digital input object) variable to handle object data
 * 
 * SubIndex 0 : 1<br>
 * SubIndex x : every switch value is 0 by default
 */
PROTO TOBJ6000 AD_Inputs
#ifdef _EVALBOARD_
= {4, 0x00, 0x00, 0x00, 0x00}
#endif
;


/**
 * \brief Object 0x6010 (AD_Switch_Status output object) entry descriptions
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6010[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: CH1_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: CH2_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: CH3_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: CH4_ENABLE  */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 005: CH1_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 006: CH2_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 007: CH3_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 008: CH4_Frequency */
   {0x0000, 0x04, 0}}; /* Subindex 008 for align */

/**
 * \brief 0x6000 (Digital input object) object and entry names
 */
OBJCONST UCHAR OBJMEM aName0x6010[] = "AD_Switch_Status Outputs\000CH1_ENABLE 1\000CH2_ENABLE 2\000CH3_ENABLE 3\000CH4_ENABLE 4\000CH1_Frequency 5\000CH2_Frequency 6\000CH3_Frequency 7\000CH4_Frequency 8\000\000\377";
#endif //#ifdef _OBJD_

/**
 * \brief 0x6010 (Analog input object) variable to handle object data
 * 
 */
PROTO TOBJ6010 AD_Switch_Status_OUT
#ifdef _EVALBOARD_
= {8, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0}
#endif
;	 


#ifdef _OBJD_
/**
 * \brief Object 0x6020 (Analog input object) entry descriptions
**/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6020[] = {
   {DEFTYPE_REAL32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING},/* SubIndex 001: CH1_VOLTAGE  */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING},/* SubIndex 002: CH2_VOLTAGE  */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING},/* SubIndex 003: CH3_VOLTAGE  */
   {DEFTYPE_REAL32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING} /* SubIndex 004: CH4_VOLTAGE  */
	 };


/**
 * \brief 0x6020 (Analog input object) object and entry names
 */
OBJCONST UCHAR OBJMEM aName0x6020[] = "AI Outputs\000CH1_VOLTAGE 1\000CH2_VOLTAGE 2\000CH3_VOLTAGE 3\000CH4_VOLTAGE 4\000\000\377";
#endif //#ifdef _OBJD_



/**
 * \brief 0x6020 (Analog input object) variable to handle object data
 * 
 */
PROTO TOBJ6020 Current_Inputs
#ifdef _EVALBOARD_
= {4, 0x00, 0x00, 0x00, 0x00}
#endif
;


#ifdef _OBJD_
/**
 * \brief Object 0x6030 (SELF_CHECK_STATUS input object)entry descriptions
**/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6030[] = {
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: CH1_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: CH2_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: CH3_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: CH4_state */
	 {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 005: software_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: hardware_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: EtherCAT_state */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: ALL_state */
	 {0x0000, 0x08, 0}
	 };


/**
 * \brief Object 0x6030 (SELF_CHECK_STATUS input object) entry descriptions
 */
OBJCONST UCHAR OBJMEM aName0x6030[] = "Diancifa_states_Inputs Outputs\000CH1_state 1\000CH2_state 2\000CH3_state 3\000CH4_state 4\000software_state 5\000hardware_state 6\000EtherCAT_state 7\000ALL_state 8\000\000\377";
#endif //#ifdef _OBJD_



/**
 * \brief 0x6030 (SELF_CHECK_STATUS input object) variable to handle object data
 * 
 */
PROTO TOBJ6030 Selfcheck_STATUS_6030
#ifdef _EVALBOARD_
= {8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
#endif
;

#ifdef _OBJD_
/**
 * \brief Object 0x6050 (厂家信息input object)entry descriptions
**/
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x6050[] = {
   {DEFTYPE_VISIBLESTRING, 0x30, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: ECMK-A/B 设备名称 */
   {DEFTYPE_VISIBLESTRING, 0x20, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: V1.0 硬件版本 */
   {DEFTYPE_VISIBLESTRING, 0x20, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: V1.0 软件版本*/
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: 0x04设备标识符 */
	 {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 005: 0x1制造商ID*/
	 {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 006: 0x1产品码ID*/
	 {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 007: 0x1版本号ID*/
	 {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_TXPDOMAPPING}, /* SubIndex 008: 0x1序列号ID*/
	 };


/**
 * \brief Object 0x6050 (厂家信息input object) entry descriptions
 */
OBJCONST UCHAR OBJMEM aName0x6050[] = "Product_Info_Query Outputs\000ECMKA/B 1\000HARDWARE-VERSION 2\000SOFTWARE-VERSION 3\000UDI 4\000manufactured ID 5\000PRODUCT ID 6\000PRODUCT ID 7\000PRODUCT ID 8\000\000\377";
#endif //#ifdef _OBJD_



/**
 * \brief 0x6050 (厂家信息input object)entry descriptions
 * 
 */
PROTO TOBJ6050 ECMK_INFO_6050
#ifdef _EVALBOARD_
//= {8,0x01,0x01,0x01, 0x04,0x1,0x1,0x1,0x1,0}
= {8,"ECMK-A", "V1.0", "V1.0", 0x04,0x11111111,0x01,0x01,0x01}
#endif
;


/**
 * \brief Object 0x7010 (Digital output object) entry descriptions
 *
 * SubIndex 0 : read only<br>
 * SubIndex x : (One description for each led) read only and RxPdo mappable<br>
 *  (x > 0)
*/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7010[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: CH1_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: CH2_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: CH3_ENABLE  */
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: CH4_ENABLE  */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 005: CH1_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 006: CH2_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 007: CH3_Frequency */
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 008: CH4_Frequency */
   {0x0000, 0x04, 0}}; /* Subindex 008 for align */

/**
 * \brief 0x6000 (Digital input object) object and entry names
 */
OBJCONST UCHAR OBJMEM aName0x7010[] = "DO Outputs\000CH1_ENABLE 1\000CH2_ENABLE 2\000CH3_ENABLE 3\000CH4_ENABLE 4\000CH1_Frequency 5\000CH2_Frequency 6\000CH3_Frequency 7\000CH4_Frequency 8\000\000\377";
#endif //#ifdef _OBJD_

/**
 * \brief 0x6020 (Analog input object) variable to handle object data
 * 
 */
PROTO TOBJ7010 AD_Switch_Cmd
#ifdef _EVALBOARD_
= {8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0}
#endif
;	 


//测试用
#ifdef _OBJD_
     //                                                        类型                长度  权限          权限
	OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7011[] = {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ | OBJACCESS_RXPDOMAPPING };
	OBJCONST UCHAR OBJMEM aName0x7011[] = "Var0x7011_OUTPUTS\000\377";
#endif //#ifdef _OBJD_

PROTO UINT32 VAR0x7011
#ifdef _EVALBOARD_
= 0x01
#endif
;

//电磁阀控制命令 	
//#ifdef _OBJD_
//OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x7012[] = {
//   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ }, /* Subindex 000 */
//   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 001: diancifa_cmd 1 */
//   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 002: diancifa_cmd 2 */
//   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 003: diancifa_cmd 3 */
//   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READ | OBJACCESS_RXPDOMAPPING}, /* SubIndex 004: diancifa_cmd 4 */
//   {0x0000, 0x0c, 0}}; /* Subindex 008 for align */


//OBJCONST UCHAR OBJMEM aName0x7012[] = "Var0x7012 Outputs\000TEST 1\000TEST 2\000TEST 3\000TEST 4\000TEST 5\000TEST 6\000TEST 7\000TEST 8\000\000\377";
//#endif //#ifdef _OBJD_

//PROTO TOBJ7012 Diancifa_cmd
//#ifdef _EVALBOARD_
//= {5, 0x00, 0x00, 0x00, 0x00, 0}
//#endif
//;	 	 





/** @}*/



/**
 * \addtogroup ConfigObjects Configuration Objects
 * @{
 */
/**
 * \brief Object 0x8020 (Analog input settings) entry descriptions
 *
 * SubIndex 0<br>
 * SubIndex 001: Enable user scale<br>
 * SubIndex 002: Presentation<br>
 * Subindex 003 doesn't exist<br>
 * Subindex 004 doesn't exist<br>
 * Subindex 005 for align<br>
 * Subindex 006 doesn't exist<br>
 * SubIndex 007: Enable limit 1<br>
 * SubIndex 008: Enable limit 2<br>
 * Subindex 009 for align<br>
 * Subindex 010 doesn't exist<br>
 * Subindex 011 doesn't exist<br>
 * Subindex 012 doesn't exist<br>
 * Subindex 013 doesn't exist<br>
 * Subindex 014 doesn't exist<br>
 * Subindex 015 doesn't exist<br>
 * Subindex 016 doesn't exist<br>
 * SubIndex 017: Offset<br>
 * SubIndex 018: Gain<br>
 * SubIndex 019: Limit 1<br>
 * SubIndex 020: Limit 2
 */
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0x8020[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0800, 0x03, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0x02, 0},
   {0x0000, 0, 0},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_BOOLEAN, 0x01, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {0x0000, 0x08, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {0x0000, 0, 0},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER32, 0x20, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS},
   {DEFTYPE_INTEGER16, 0x10, ACCESS_READWRITE | OBJACCESS_BACKUP | OBJACCESS_SETTINGS}};

/** \brief Object 0x8020 (Analog input settings) object and entry names*/
OBJCONST UCHAR OBJMEM aName0x8020[] = "AI Settings\000Enable user scale\000Presentation\000\000\000\000\000Enable limit 1\000Enable limit 2\000\000\000\000\000\000\000\000\000Offset\000Gain\000Limit 1\000Limit 2\000\377";
#endif //#ifdef _OBJD_

/** \brief Object 0x8020 (Analog input settings) variable*/
PROTO TOBJ8020 sAISettings
#ifdef _EVALBOARD_
= {20, 0x00, 0x00, 0, 0x00, 0x00, 0, 0x00, 0x00, 0x00, 0x00}
#endif
;
/** @}*/


/**
 * \addtogroup DeviceParaObjects Device Parameter Objects
 * @{
 */
#ifdef _OBJD_
/** 
 * \brief 0xF000 (Modular Device Profile) entry descriptions
 *
 * Subindex 000<br>
 * SubIndex 001: Module index distance<br>
 * SubIndex 002: Maximum number of modules<br>
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF000[] = {
   {DEFTYPE_UNSIGNED8, 0x8, ACCESS_READ },
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ},
   {DEFTYPE_UNSIGNED16, 0x10, ACCESS_READ}};


/** \brief 0xF000 (Modular Device Profile) object and entry names*/
OBJCONST UCHAR OBJMEM aName0xF000[] = "Modular device profile\000Module index distance\000Maximum number of modules\000\377";
#endif


/**
 * \brief 0xF000 (Modular Device Profile) variable to handle the object data
 *
 * SubIndex 0
 * SubIndex 1 (Module Index distance) : 0x10
 * SubIndex 2 (Maximum number of Modules) : 3
 */
/******************************************************************************
*                    Object 0xF000
******************************************************************************/
PROTO TOBJF000 sModulardeviceprofile
#ifdef _EVALBOARD_
= {2, 0x10, 0x03}
#endif
;


#ifdef _OBJD_
/** 
 * \brief 0xF010 (Module profile list) entry descriptions
 *
 * Subindex 0<br>
 * SubIndex x
 * (x > 0)
 */
OBJCONST TSDOINFOENTRYDESC    OBJMEM asEntryDesc0xF010[] = {
   {DEFTYPE_UNSIGNED8, 0x08, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ},
   {DEFTYPE_UNSIGNED32, 0x20, ACCESS_READ}};

/**
 * \brief 0xF010 (Module profile list) object name
 *
 * no entry names defined because the object is an array (for every entry > 0 "SubIndex xxx" is returned)
 */
OBJCONST UCHAR OBJMEM aName0xF010[] = "Module profile list";
#endif


/**
 *\brief 0xF010 (Module profile list) variable to handle object data
 * 
 * SubIndex 0 : 3
 * SubIndex 1 : 100 (Digital Input SubProfile)
 * SubIndex 2 : 200 (Digital Output SubProfile)
 * SubIndex 3 : 300 (Analog Input SubProfile)
 */
PROTO TOBJF010 sModulelist
#ifdef _EVALBOARD_
= {0x03,{0x64, 0xC8, 0x12C}}
#endif
;
/** @}*/


#ifdef _OBJD_
PROTO UINT8 ReadObject0x1802( UINT16 index, UINT8 subindex, UINT32 dataSize, UINT16 MBXMEM * pData, UINT8 bCompleteAccess );

/*if _PIC18 is enabled the object dictionary is fixed defined in coeappl.c*/

/**
 *\brief EL9800 Application specific object dictionary
 * 
 */
TOBJECT    OBJMEM ApplicationObjDic[] = {
   /* Enum 0x0800 */
   {NULL,NULL, 0x0800, {DEFTYPE_ENUM, 0x02 | (OBJCODE_REC << 8)}, asEntryDesc0x0800, 0, apEnum0800 },
   /* Object 0x1601 */
   {NULL,NULL,  0x1601, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1601, aName0x1601, &AD_Switch_Cmd_IN, NULL, NULL, 0x0000 },
	 
//	 {NULL,NULL,  0x1602, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1602, aName0x1602, &sDORxPDOMap_test, NULL, NULL, 0x0000 },	 
   /* Object 0x1802 */
   {NULL,NULL,  0x1802, {DEFTYPE_RECORD, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1802, aName0x1802,&TxPDO1802Subindex0, ReadObject0x1802, NULL, 0x0000 },
   /* Object 0x1A00 */
   {NULL,NULL,   0x1A00, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A00, aName0x1A00, &sDITxPDOMap, NULL, NULL, 0x0000 },
	  /* Object 0x1A01 */
   {NULL,NULL,   0x1A01, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A01, aName0x1A01, &AD_Switch_Status, NULL, NULL, 0x0000 },
   /* Object 0x1A02 */
   {NULL,NULL,   0x1A02, {DEFTYPE_PDOMAPPING, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x1A02, aName0x1A02, &sAITxPDOMap, NULL, NULL, 0x0000 },
	 /* Object 0x1A03 */
   {NULL,NULL,   0x1A03, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A03, aName0x1A03, &Selfcheck_STATUS_1A03, NULL, NULL, 0x0000 },
	 /* Object 0x1A05 */
   {NULL,NULL,   0x1A05, {DEFTYPE_PDOMAPPING, 9 | (OBJCODE_REC << 8)}, asEntryDesc0x1A05, aName0x1A05, &ECMK_INFO_1A05, NULL, NULL, 0x0000 },
    /* Object 0x1C12 */
   {NULL,NULL,   0x1C12, {DEFTYPE_UNSIGNED16, 1 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C12, &sRxPDOassign, NULL, NULL, 0x0000 },
   /* Object 0x1C13 */
   {NULL,NULL,   0x1C13, {DEFTYPE_UNSIGNED16, 2 | (OBJCODE_ARR << 8)}, asPDOAssignEntryDesc, aName0x1C13, &sTxPDOassign, NULL, NULL, 0x0000 },
   /* Object 0x6000 */
   {NULL,NULL,   0x6000, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x6000, aName0x6000, &AD_Inputs, NULL, NULL, 0x0000 },
	 
	 /* Object 0x6010 */
   {NULL,NULL,   0x6010, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x6010, aName0x6010, &AD_Switch_Status_OUT, NULL, NULL, 0x0000 },
	 //                     数据类型    ，子索引个数
   /* Object 0x6020 */
   {NULL,NULL,   0x6020, {DEFTYPE_RECORD, 17 | (OBJCODE_REC << 8)}, asEntryDesc0x6020, aName0x6020, &Current_Inputs, NULL, NULL, 0x0000 },
	    /* Object 0x6030 */
   {NULL,NULL,   0x6030, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x6030, aName0x6030, &Selfcheck_STATUS_6030, NULL, NULL, 0x0000 },
	 	    /* Object 0x6050 */
   {NULL,NULL,   0x6050, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x6050, aName0x6050, &ECMK_INFO_6050, NULL, NULL, 0x0000 },
   /* Object 0x7010 */
   {NULL,NULL,   0x7010, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x7010, aName0x7010, &AD_Switch_Cmd, NULL, NULL, 0x0000 },
	 /* Object 0x7011 for test */
	 {NULL,NULL,   0x7011, {DEFTYPE_UNSIGNED32, 0 | (OBJCODE_VAR << 8)}, asEntryDesc0x7011, aName0x7011, &VAR0x7011, NULL, NULL, 0x0000 },	 
	 
	// {NULL,NULL,   0x7012, {DEFTYPE_RECORD, 8 | (OBJCODE_REC << 8)}, asEntryDesc0x7012, aName0x7012, &Diancifa_cmd, NULL, NULL, 0x0000 },
	     /* Object 0x8020 */
    {NULL,NULL,   0x8020, {DEFTYPE_RECORD, 20 | (OBJCODE_REC << 8)}, asEntryDesc0x8020, aName0x8020, &sAISettings, NULL, NULL, 0x0008 },
    /* Object 0xF000 */
   {NULL,NULL,   0xF000, {DEFTYPE_RECORD, 2 | (OBJCODE_REC << 8)}, asEntryDesc0xF000, aName0xF000, &sModulardeviceprofile, NULL, NULL, 0x0000 },
   /* Object 0xF010 */
   {NULL,NULL,   0xF010, {DEFTYPE_UNSIGNED32, 3 | (OBJCODE_ARR << 8)}, asEntryDesc0xF010, aName0xF010, &sModulelist, NULL, NULL, 0x0000 },
   {NULL,NULL, 0xFFFF, {0, 0}, NULL, NULL, NULL, NULL}};
#endif    //#ifdef _OBJD_

PROTO void APPL_Application(void);

PROTO void   APPL_AckErrorInd(UINT16 stateTrans);
PROTO UINT16 APPL_StartMailboxHandler(void);
PROTO UINT16 APPL_StopMailboxHandler(void);
PROTO UINT16 APPL_StartInputHandler(UINT16 *pIntMask);
PROTO UINT16 APPL_StopInputHandler(void);
PROTO UINT16 APPL_StartOutputHandler(void);
PROTO UINT16 APPL_StopOutputHandler(void);

PROTO UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize);
PROTO void APPL_InputMapping(UINT16* pData);
PROTO void APPL_OutputMapping(UINT16* pData);


#undef PROTO
/** @}*/
