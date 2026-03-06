//////////////////////////////////////////////////////////////////////////////////////////////////
//  
// ACS Motion Control Ltd.
// Copyright © 1999 - 2025. All Rights Reserved.
//
// PROJECT			:    SPiiPlus 
// SUBSYSTEM		:    SPiiPlus C Library
// FILE				:	 ACSC.h
// VERSION			:    7.6.0.0 

// OVERVIEW
// ========
//
// SPiiPlus C Library export functions definition
// 
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _ACSC_H_
#define _ACSC_H_

#if defined(_WIN32)
#include <windows.h>
#include <Winsock.h>
#include <wtypes.h> 
#include <tchar.h>
#define UnsignedInt64 unsigned __int64
#elif defined(__linux__) || defined(__APPLE__)
#define RPCTRY 
#define RPCTRYEND(n) 
#define WINAPI   
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
typedef void* HANDLE;
typedef int BOOL;
typedef unsigned int DWORD;
typedef signed int	INT32;
typedef char* BSTR;
typedef uintptr_t DWORD_PTR;
typedef int32_t __int32;
#define UnsignedInt64 uint64_t
#endif

#include <math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
// General definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_VER					0x7060000


#define ACSC_MAXCHANNEL				10			//Maximum number of communication channels
#define ACSC_INVALID				(HANDLE)-1	//Invalid communication handle 
#define ACSC_NONE					-1				
#define ACSC_INT_BINARY				4			//Size of the controller integer variable
#define ACSC_REAL_BINARY			8			//Size of the controller real variable
#define ACSC_STRING_BINARY			16
#define ACSC_FILE					-2
#define ACSC_DEFAULT_REMOTE_PORT	9999
#define ACSC_CALLBACK_PORT			9998		//Lunux callback port
#define ACSC_AXES_MAX_NUMBER		128			//Maximum number of supported axes
#define ACSC_BUFFERS_MAX_NUMBER		65			//Maximum number of supported buffers (including D-Buffer)
#define ACSC_SP_MAX_NUMBER			128			//Maximum number of supported Servo Processors (SP)
#define ACSC_DC_VAR_MAX_NUMBER		24			//Maximum number of variables to be collected by one command
#define ACSC_MAX_LINE				100000		//Maximum number of lines in program buffer
#define ACSC_COUNTERCLOCKWISE		1			//Counterclockwise rotation
#define ACSC_CLOCKWISE				-1			//Clockwise rotation
#define ACSC_POSITIVE_DIRECTION		1			//A move in positive direction
#define ACSC_NEGATIVE_DIRECTION		-1			//A move in negative direction

// for compatibility with the previous library
#define MAXCHANNEL					10				

// Set/Get configuration keys
#define ACSC_CONF_WORD1_KEY					1
#define ACSC_CONF_INT_EDGE_KEY				3
#define ACSC_CONF_ENCODER_KEY				4
#define ACSC_CONF_MFLAGS9_KEY				204
#define ACSC_CONF_DIGITAL_SOURCE_KEY		205
#define ACSC_CONF_SP_OUT_PINS_KEY			206
#define ACSC_CONF_OUT_KEY					29
#define ACSC_CONF_BRAKE_OUT_KEY				229

// System Information keys
#define ACSC_SYS_MODEL_KEY					1
#define ACSC_SYS_VERSION_KEY				2
#define ACSC_SYS_NBUFFERS_KEY				10
#define ACSC_SYS_DBUF_INDEX_KEY				11
#define ACSC_SYS_NAXES_KEY					13
#define ACSC_SYS_NNODES_KEY					14
#define ACSC_SYS_NDCCH_KEY					15
#define ACSC_SYS_ECAT_KEY					16


//////////////////////////////////////////////////////////////////////////////////////////////////
// ACSPL+ variables types
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_INT_TYPE						1	//Integer type of the variable (Decimal representation)
#define ACSC_REAL_TYPE						2	//Real type of the variable (Decimal representation)
#define ACSC_STATIC_INT_TYPE				3	//Static Integer type of the variable (Decimal representation)
#define ACSC_STATIC_REAL_TYPE				4	//Static Real type of the variable (Decimal representation)

//////////////////////////////////////////////////////////////////////////////////////////////////
// Represintation types of file stored variables
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_DEC_REAL_TYPE					8	 //Decimal representation of Real type variable
#define ACSC_DEC_INT_TYPE					4	 //Decimal representation of Integer type variable
#define ACSC_BIN_INT_TYPE					2	 //Binary representation of Integer type variable
#define ACSC_OCT_INT_TYPE					1	 //Octal representation of Integer type variable
#define ACSC_HEX_INT_TYPE 					16	 //Hexadecimal representation of Integer type variable

//////////////////////////////////////////////////////////////////////////////////////////////////
// Serial communication options
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_AUTO -1

//////////////////////////////////////////////////////////////////////////////////////////////////
// Ethernet communication options
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_SOCKET_DGRAM_PORT				700
#define ACSC_SOCKET_STREAM_PORT				701

//////////////////////////////////////////////////////////////////////////////////////////////////
// Old Axes Definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_AXIS_X							0
#define ACSC_AXIS_Y							1
#define ACSC_AXIS_Z							2
#define ACSC_AXIS_T							3
#define ACSC_AXIS_A							4
#define ACSC_AXIS_B							5
#define ACSC_AXIS_C							6
#define ACSC_AXIS_D							7

//////////////////////////////////////////////////////////////////////////////////////////////////
// New Axes Definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_PAR_ALL						-2
#define ACSC_SYSTEM							-3
#define ACSC_AXIS_0							0
#define ACSC_AXIS_1							1
#define ACSC_AXIS_2							2
#define ACSC_AXIS_3							3
#define ACSC_AXIS_4							4
#define ACSC_AXIS_5							5
#define ACSC_AXIS_6							6
#define ACSC_AXIS_7							7
#define ACSC_AXIS_8							8
#define ACSC_AXIS_9							9
#define ACSC_AXIS_10						10
#define ACSC_AXIS_11						11
#define ACSC_AXIS_12						12
#define ACSC_AXIS_13						13
#define ACSC_AXIS_14						14
#define ACSC_AXIS_15						15
#define ACSC_AXIS_16						16
#define ACSC_AXIS_17						17
#define ACSC_AXIS_18						18
#define ACSC_AXIS_19						19
#define ACSC_AXIS_20						20
#define ACSC_AXIS_21						21
#define ACSC_AXIS_22						22
#define ACSC_AXIS_23						23
#define ACSC_AXIS_24						24
#define ACSC_AXIS_25						25
#define ACSC_AXIS_26						26
#define ACSC_AXIS_27						27
#define ACSC_AXIS_28						28
#define ACSC_AXIS_29						29
#define ACSC_AXIS_30						30
#define ACSC_AXIS_31						31
#define ACSC_AXIS_32						32
#define ACSC_AXIS_33						33
#define ACSC_AXIS_34						34
#define ACSC_AXIS_35						35
#define ACSC_AXIS_36						36
#define ACSC_AXIS_37						37
#define ACSC_AXIS_38						38
#define ACSC_AXIS_39						39
#define ACSC_AXIS_40						40
#define ACSC_AXIS_41						41
#define ACSC_AXIS_42						42
#define ACSC_AXIS_43						43
#define ACSC_AXIS_44						44
#define ACSC_AXIS_45						45
#define ACSC_AXIS_46						46
#define ACSC_AXIS_47						47
#define ACSC_AXIS_48						48
#define ACSC_AXIS_49						49
#define ACSC_AXIS_50						50
#define ACSC_AXIS_51						51
#define ACSC_AXIS_52						52
#define ACSC_AXIS_53						53
#define ACSC_AXIS_54						54
#define ACSC_AXIS_55						55
#define ACSC_AXIS_56						56
#define ACSC_AXIS_57						57
#define ACSC_AXIS_58						58
#define ACSC_AXIS_59						59
#define ACSC_AXIS_60						60
#define ACSC_AXIS_61						61
#define ACSC_AXIS_62						62
#define ACSC_AXIS_63						63
#define ACSC_AXIS_64						64
#define ACSC_AXIS_65						65
#define ACSC_AXIS_66						66
#define ACSC_AXIS_67						67
#define ACSC_AXIS_68						68
#define ACSC_AXIS_69						69
#define ACSC_AXIS_70						70
#define ACSC_AXIS_71						71
#define ACSC_AXIS_72						72
#define ACSC_AXIS_73						73
#define ACSC_AXIS_74						74
#define ACSC_AXIS_75						75
#define ACSC_AXIS_76						76
#define ACSC_AXIS_77						77
#define ACSC_AXIS_78						78
#define ACSC_AXIS_79						79
#define ACSC_AXIS_80						80
#define ACSC_AXIS_81						81
#define ACSC_AXIS_82						82
#define ACSC_AXIS_83						83
#define ACSC_AXIS_84						84
#define ACSC_AXIS_85						85
#define ACSC_AXIS_86						86
#define ACSC_AXIS_87						87
#define ACSC_AXIS_88						88
#define ACSC_AXIS_89						89
#define ACSC_AXIS_90						90
#define ACSC_AXIS_91						91
#define ACSC_AXIS_92						92
#define ACSC_AXIS_93						93
#define ACSC_AXIS_94						94
#define ACSC_AXIS_95						95
#define ACSC_AXIS_96						96
#define ACSC_AXIS_97						97
#define ACSC_AXIS_98						98
#define ACSC_AXIS_99						99
#define ACSC_AXIS_100						100
#define ACSC_AXIS_101						101
#define ACSC_AXIS_102						102
#define ACSC_AXIS_103						103
#define ACSC_AXIS_104						104
#define ACSC_AXIS_105						105
#define ACSC_AXIS_106						106
#define ACSC_AXIS_107						107
#define ACSC_AXIS_108						108
#define ACSC_AXIS_109						109
#define ACSC_AXIS_110						110
#define ACSC_AXIS_111						111
#define ACSC_AXIS_112						112
#define ACSC_AXIS_113						113
#define ACSC_AXIS_114						114
#define ACSC_AXIS_115						115
#define ACSC_AXIS_116						116
#define ACSC_AXIS_117						117
#define ACSC_AXIS_118						118
#define ACSC_AXIS_119						119
#define ACSC_AXIS_120						120
#define ACSC_AXIS_121						121
#define ACSC_AXIS_122						122
#define ACSC_AXIS_123						123
#define ACSC_AXIS_124						124
#define ACSC_AXIS_125						125
#define ACSC_AXIS_126						126
#define ACSC_AXIS_127						127



//////////////////////////////////////////////////////////////////////////////////////////////////
// Buffers Definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_BUFFER_ALL						-2
#define ACSC_BUFFER_0						0
#define ACSC_BUFFER_1						1
#define ACSC_BUFFER_2						2
#define ACSC_BUFFER_3						3
#define ACSC_BUFFER_4						4
#define ACSC_BUFFER_5						5
#define ACSC_BUFFER_6						6
#define ACSC_BUFFER_7						7
#define ACSC_BUFFER_8						8
#define ACSC_BUFFER_9						9
#define ACSC_BUFFER_10						10
#define ACSC_BUFFER_11						11
#define ACSC_BUFFER_12						12
#define ACSC_BUFFER_13						13
#define ACSC_BUFFER_14						14
#define ACSC_BUFFER_15						15
#define ACSC_BUFFER_16						16
#define ACSC_BUFFER_17						17
#define ACSC_BUFFER_18						18
#define ACSC_BUFFER_19						19
#define ACSC_BUFFER_20						20
#define ACSC_BUFFER_21						21
#define ACSC_BUFFER_22						22
#define ACSC_BUFFER_23						23
#define ACSC_BUFFER_24						24
#define ACSC_BUFFER_25						25
#define ACSC_BUFFER_26						26
#define ACSC_BUFFER_27						27
#define ACSC_BUFFER_28						28
#define ACSC_BUFFER_29						29
#define ACSC_BUFFER_30						30
#define ACSC_BUFFER_31						31
#define ACSC_BUFFER_32						32
#define ACSC_BUFFER_33						33
#define ACSC_BUFFER_34						34
#define ACSC_BUFFER_35						35
#define ACSC_BUFFER_36						36
#define ACSC_BUFFER_37						37
#define ACSC_BUFFER_38						38
#define ACSC_BUFFER_39						39
#define ACSC_BUFFER_40						40
#define ACSC_BUFFER_41						41
#define ACSC_BUFFER_42						42
#define ACSC_BUFFER_43						43
#define ACSC_BUFFER_44						44
#define ACSC_BUFFER_45						45
#define ACSC_BUFFER_46						46
#define ACSC_BUFFER_47						47
#define ACSC_BUFFER_48						48
#define ACSC_BUFFER_49						49
#define ACSC_BUFFER_50						50
#define ACSC_BUFFER_51						51
#define ACSC_BUFFER_52						52
#define ACSC_BUFFER_53						53
#define ACSC_BUFFER_54						54
#define ACSC_BUFFER_55						55
#define ACSC_BUFFER_56						56
#define ACSC_BUFFER_57						57
#define ACSC_BUFFER_58						58
#define ACSC_BUFFER_59						59
#define ACSC_BUFFER_60						60
#define ACSC_BUFFER_61						61
#define ACSC_BUFFER_62						62
#define ACSC_BUFFER_63						63
#define ACSC_BUFFER_64						64

//////////////////////////////////////////////////////////////////////////////////////////////////
// Servo Processors Definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_SP_ALL							-2
#define ACSC_SP_0							0
#define ACSC_SP_1							1
#define ACSC_SP_2							2
#define ACSC_SP_3							3
#define ACSC_SP_4							4
#define ACSC_SP_5							5
#define ACSC_SP_6							6
#define ACSC_SP_7							7
#define ACSC_SP_8							8
#define ACSC_SP_9							9
#define ACSC_SP_10							10
#define ACSC_SP_11							11
#define ACSC_SP_12							12
#define ACSC_SP_13							13
#define ACSC_SP_14							14
#define ACSC_SP_15							15
#define ACSC_SP_16							16
#define ACSC_SP_17							17
#define ACSC_SP_18							18
#define ACSC_SP_19							19
#define ACSC_SP_20							20
#define ACSC_SP_21							21
#define ACSC_SP_22							22
#define ACSC_SP_23							23
#define ACSC_SP_24							24
#define ACSC_SP_25							25
#define ACSC_SP_26							26
#define ACSC_SP_27							27
#define ACSC_SP_28							28
#define ACSC_SP_29							29
#define ACSC_SP_30							30
#define ACSC_SP_31							31
#define ACSC_SP_32							32
#define ACSC_SP_33							33
#define ACSC_SP_34							34
#define ACSC_SP_35							35
#define ACSC_SP_36							36
#define ACSC_SP_37							37
#define ACSC_SP_38							38
#define ACSC_SP_39							39
#define ACSC_SP_40							40
#define ACSC_SP_41							41
#define ACSC_SP_42							42
#define ACSC_SP_43							43
#define ACSC_SP_44							44
#define ACSC_SP_45							45
#define ACSC_SP_46							46
#define ACSC_SP_47							47
#define ACSC_SP_48							48
#define ACSC_SP_49							49
#define ACSC_SP_50							50
#define ACSC_SP_51							51
#define ACSC_SP_52							52
#define ACSC_SP_53							53
#define ACSC_SP_54							54
#define ACSC_SP_55							55
#define ACSC_SP_56							56
#define ACSC_SP_57							57
#define ACSC_SP_58							58
#define ACSC_SP_59							59
#define ACSC_SP_60							60
#define ACSC_SP_61							61
#define ACSC_SP_62							62
#define ACSC_SP_63							63
#define ACSC_SP_64							64
#define ACSC_SP_65							65
#define ACSC_SP_66							66
#define ACSC_SP_67							67
#define ACSC_SP_68							68
#define ACSC_SP_69							69
#define ACSC_SP_70							70
#define ACSC_SP_71							71
#define ACSC_SP_72							72
#define ACSC_SP_73							73
#define ACSC_SP_74							74
#define ACSC_SP_75							75
#define ACSC_SP_76							76
#define ACSC_SP_77							77
#define ACSC_SP_78							78
#define ACSC_SP_79							79
#define ACSC_SP_80							80
#define ACSC_SP_81							81
#define ACSC_SP_82							82
#define ACSC_SP_83							83
#define ACSC_SP_84							84
#define ACSC_SP_85							85
#define ACSC_SP_86							86
#define ACSC_SP_87							87
#define ACSC_SP_88							88
#define ACSC_SP_89							89
#define ACSC_SP_90							90
#define ACSC_SP_91							91
#define ACSC_SP_92							92
#define ACSC_SP_93							93
#define ACSC_SP_94							94
#define ACSC_SP_95							95
#define ACSC_SP_96							96
#define ACSC_SP_97							97
#define ACSC_SP_98							98
#define ACSC_SP_99							99
#define ACSC_SP_100							100
#define ACSC_SP_101							101
#define ACSC_SP_102							102
#define ACSC_SP_103							103
#define ACSC_SP_104							104
#define ACSC_SP_105							105
#define ACSC_SP_106							106
#define ACSC_SP_107							107
#define ACSC_SP_108							108
#define ACSC_SP_109							109
#define ACSC_SP_110							110
#define ACSC_SP_111							111
#define ACSC_SP_112							112
#define ACSC_SP_113							113
#define ACSC_SP_114							114
#define ACSC_SP_115							115
#define ACSC_SP_116							116
#define ACSC_SP_117							117
#define ACSC_SP_118							118
#define ACSC_SP_119							119
#define ACSC_SP_120							120
#define ACSC_SP_121							121
#define ACSC_SP_122							122
#define ACSC_SP_123							123
#define ACSC_SP_124							124
#define ACSC_SP_125							125
#define ACSC_SP_126							126
#define ACSC_SP_127							127

//////////////////////////////////////////////////////////////////////////////////////////////////
// Dynamic Error Compensation Definitions
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_ZONES_MAX_NUMBER				10  //Maximum number of zones
#define ACSC_ZONE_0							0
#define ACSC_ZONE_1							1
#define ACSC_ZONE_2							2
#define ACSC_ZONE_3							3
#define ACSC_ZONE_4							4
#define ACSC_ZONE_5							5
#define ACSC_ZONE_6							6
#define ACSC_ZONE_7							7
#define ACSC_ZONE_8							8
#define ACSC_ZONE_9							9

//////////////////////////////////////////////////////////////////////////////////////////////////
// PCI interrupts flags
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_INTR_PEG						3
#define ACSC_INTR_MARK1						7
#define ACSC_INTR_MARK2						8
#define ACSC_INTR_EMERGENCY					15
#define ACSC_INTR_PHYSICAL_MOTION_END		16
#define ACSC_INTR_LOGICAL_MOTION_END		17
#define ACSC_INTR_MOTION_FAILURE			18
#define ACSC_INTR_MOTOR_FAILURE				19
#define ACSC_INTR_PROGRAM_END				20
#define ACSC_INTR_COMMAND					21	// FOR BACKWARD COMPATIBILITY
#define ACSC_INTR_ACSPL_PROGRAM_EX			21
#define ACSC_INTR_ACSPL_PROGRAM				22
#define ACSC_INTR_INPUT						23
#define ACSC_INTR_MOTION_START				24
#define ACSC_INTR_MOTION_PHASE_CHANGE		25
#define ACSC_INTR_TRIGGER					26
#define ACSC_INTR_NEWSEGM					27
#define ACSC_INTR_SYSTEM_ERROR				28
#define ACSC_INTR_ETHERCAT_ERROR			29
#define ACSC_INTR_CYCLE						30	// FOR BACKWARD COMPATIBILITY
#define ACSC_INTR_FPGA_UPGRADE				30
#define ACSC_INTR_MESSAGE					31
#define ACSC_INTR_COMM_CHANNEL_CLOSED		32
#define ACSC_INTR_SOFTWARE_ESTOP			33

//////////////////////////////////////////////////////////////////////////////////////////////////
// Bit masks definitions
//////////////////////////////////////////////////////////////////////////////////////////////////

// Communication options
#define ACSC_COMM_USE_CHECKSUM				0x00000001
#define ACSC_COMM_AUTORECOVER_HW_ERROR		0x00000002

// Motion flags
#define ACSC_AMF_WAIT						0x00000001	// SAME AS ACSC_AMF_WEIGHT
#define ACSC_AMF_WEIGHT                     0x00000001	// SAME AS ACSC_AMF_WAIT
#define ACSC_AMF_RELATIVE					0x00000002
#define ACSC_AMF_VELOCITY					0x00000004
#define ACSC_AMF_ENDVELOCITY				0x00000008	// SAME AS ACSC_AMF_REQUIRED_VELOCITY, ACSC_PEG_FASTLOADINGPEG
#define ACSC_AMF_REQUIRED_VELOCITY          0x00000008	// SAME AS ACSC_AMF_ENDVELOCITY, ACSC_PEG_FASTLOADINGPEG
#define ACSC_AMF_FASTLOADINGPEG				0x00000008	// SAME AS ACSC_AMF_ENDVELOCITY, ACSC_AMF_REQUIRED_VELOCITY

#define ACSC_AMF_POSITIONLOCK				0x00000010
#define ACSC_AMF_VELOCITYLOCK				0x00000020

#define ACSC_AMF_CYCLIC						0x00000100	// SAME AS ACSC_AMF_CORNER, ACSC_AMF_DYNAMIC_ERROR_COMPENSATION1D
#define ACSC_AMF_CORNER                     0x00000100	// SAME AS ACSC_AMF_CYCLIC, ACSC_AMF_DYNAMIC_ERROR_COMPENSATION1D
#define ACSC_AMF_DYNAMIC_ERROR_COMPENSATION1D  0x00000100	// SAME AS ACSC_AMF_CYCLIC, ACSC_AMF_CORNER
#define ACSC_AMF_VARTIME					0x00000200	// SAME AS ACSC_STALLED, ACSC_AMF_TIME
#define ACSC_AMF_STALLED					0x00000200	// SAME AS ACSC_AMF_VARTIME, ACSC_AMF_TIME
#define ACSC_AMF_TIME                       0x00000200	// SAME AS ACSC_AMF_VARTIME, ACSC_AMF_STALLED
#define ACSC_AMF_CUBIC						0x00000400
#define ACSC_AMF_2                          0x00000800

#define ACSC_AMF_EXTRAPOLATED				0x00001000	// SAME AS ACSC_AMF_ENVELOPE
#define ACSC_AMF_ENVELOPE			        0x00001000	// SAME AS ACSC_AMF_EXTRAPOLATED
#define ACSC_AMF_AXISLIMIT					0x00002000	// SAME AS ACSC_AMF_NURBS_EXCEPTION_LENGTH, ACSC_AMF_LOCAL
#define ACSC_AMF_NURBS_EXCEPTION_LENGTH    	0x00002000	// SAME AS ACSC_AMF_AXISLIMIT, ACSC_AMF_LOCAL
#define ACSC_AMF_LOCAL                      0x00002000	// SAME AS ACSC_AMF_AXISLIMIT, ACSC_AMF_NURBS_EXCEPTION_LENGTH
#define ACSC_AMF_MAXIMUM					0x00004000	// SAME AS ACSC_AMF_BSEGTIME, ACSC_AMF_MODULE, ACSC_AMF_MAXIMUM_ARR_SIZE
#define ACSC_AMF_MAXIMUM_ARR_SIZE			0x00004000	// SAME AS ACSC_AMF_BSEGTIME, ACSC_AMF_MAXIMUM, ACSC_AMF_MODULE
#define ACSC_AMF_BSEGTIME					0x00004000	// SAME AS ACSC_AMF_MAXIMUM, ACSC_AMF_MODULE, ACSC_AMF_MAXIMUM_ARR_SIZE
#define ACSC_AMF_SYNCHRONOUS				0x00008000	// SAME AS ACSC_AMF_BSEGJERK
#define ACSC_AMF_BSEGJERK					0x00008000	// SAME AS ACSC_AMF_SYNCHRONOUS

#define ACSC_AMF_JUNCTIONVELOCITY			0x00010000
#define ACSC_AMF_ANGLE						0x00020000	// SAME AS ACSC_AMF_ACCURATE, ACSC_AMF_BSEGACC, ACSC_AMF_NURBS_EXCEPTION_ANGLE
#define ACSC_AMF_ACCURATE					0x00020000	// SAME AS ACSC_AMF_ANGLE, ACSC_AMF_BSEGACC AND ACSC_AMF_NURBS_EXCEPTION_ANGLE
#define ACSC_AMF_BSEGACC					0x00020000	// SAME AS ACSC_AMF_ANGLE, ACSC_AMF_ACCURATE, ACSC_AMF_BSEGACC
#define ACSC_AMF_NURBS_EXCEPTION_ANGLE    	0x00020000 	// SAME AS ACSC_AMF_ANGLE, ACSC_AMF_ACCURATE, ACSC_AMF_BSEGACC
#define ACSC_AMF_USERVARIABLES				0x00040000  // SAME AS ACSC_AMF_MIN_AXIS_DIRECTION
#define ACSC_AMF_MIN_AXIS_DIRECTION			0x00040000	// SAME AS ACSC_AMF_USERVARIABLES
#define ACSC_AMF_INVERT_OUTPUT				0x00080000

#define ACSC_AMF_CURVEVELOCITY				0x00100000	// SAME AS ACSC_AMF_DWELLTIME, ACSC_AMF_DUMMY, ACSC_AMF_FIXED_TIME, ACSC_PEG_DYNAMICLOADINGPEG
#define ACSC_AMF_DWELLTIME					0x00100000	// SAME AS ACSC_AMF_CURVEVELOCITY, ACSC_AMF_DUMMY, ACSC_AMF_FIXED_TIME, ACSC_PEG_DYNAMICLOADINGPEG
#define ACSC_AMF_DUMMY                      0x00100000	// SAME AS ACSC_AMF_CURVEVELOCITY, ACSC_AMF_DWELLTIME, ACSC_AMF_FIXED_TIME, ACSC_PEG_DYNAMICLOADINGPEG
#define ACSC_AMF_FIXED_TIME                 0x00100000	// SAME AS ACSC_AMF_CURVEVELOCITY, ACSC_AMF_DWELLTIME, ACSC_AMF_DUMMY, ACSC_PEG_DYNAMICLOADINGPEG
#define ACSC_AMF_DYNAMICLOADINGPEG			0x00100000	// SAME AS ACSC_AMF_CURVEVELOCITY, ACSC_AMF_DWELLTIME, ACSC_AMF_DUMMY, ACSC_AMF_FIXED_TIME
#define ACSC_AMF_CORNERDEVIATION			0x00200000	// SAME AS ACSC_AMF_NURBS_CONSIDER_ACC
#define ACSC_AMF_NURBS_CONSIDER_ACC 		0x00200000	// SAME AS ACSC_AMF_CORNERDEVIATION
#define ACSC_AMF_CORNERRADIUS				0x00400000
#define ACSC_AMF_CORNERLENGTH				0x00800000

#define ACSC_AMF_CURVEAUTO					0x01000000  // SAME AS ACSC_AMF_DYNAMIC_ERROR_COMPENSATION2D
#define ACSC_AMF_DYNAMIC_ERROR_COMPENSATION2D  0x01000000  // SAME AS ACSC_AMF_CURVEAUTO
#define ACSC_AMF_EXT_LOOP    				0x02000000
#define ACSC_AMF_EXT_LOOP_SYNC    			0x04000000
#define ACSC_AMF_DELAY_MOTION            	0x08000000

#define ACSC_AMF_LCI_STATE      			0x10000000
#define ACSC_AMF_LOCALCS      		    	0x20000000   //  SAME AS ACSC_AMF_DYNAMIC_ERROR_COMPENSATION3D
#define ACSC_AMF_DYNAMIC_ERROR_COMPENSATION3D 0x20000000 // SAME AS ACSC_AMF_LOCALCS
#define ACSC_AMF_KNOT                       0x40000000

#define  ACSC_AMF_ENDLESS                   0x00001000  //SAME AS ACSC_AMF_ENVELOPE,ACSC_AMF_EXTRAPOLATED
#define  ACSC_AMF_MODULE                    0x00004000  //SAME AS ACSC_AMF_MAXIMUM,ACSC_AMF_BSEGTIME, ACSC_AMF_MAXIMUM_ARR_SIZE

// Data collection flags
#define ACSC_DCF_TEMPORAL					0x00000001
#define ACSC_DCF_CYCLIC						0x00000002
#define ACSC_DCF_SYNC					    0x00000004
#define ACSC_DCF_WAIT						0x00000008

// Servo Processor Data Collection flags
#define ACSC_SPDCF_REAL_TYPE				0x00000001

// Dynamic Error Compensation flags
#define ACSC_DECOMP_00							0x00000001
#define ACSC_DECOMP_01							0x00000002
#define ACSC_DECOMP_02							0x00000004
#define ACSC_DECOMP_PREVENT_COMP_INDEX_MARK_PEG	0x00000008
#define ACSC_DECOMP_REFERENCED_AXIS				0x00000010
#define ACSC_DECOMP_ANALOG_INPUT				0x00000020
#define ACSC_DECOMP_FIRST_ANALOG_INPUT			0x00000040
#define ACSC_DECOMP_SECOND_ANALOG_INPUT			0x00000080
#define ACSC_DECOMP_THIRD_ANALOG_INPUT			0x00000100

// Controller Protection flags
#define ACSC_PRIMARY_PROTECTION             0x00000001
#define ACSC_SECONDARY_PROTECTION           0x00000002
#define ACSC_ALLOW_SYSTEM_RECONFIGURATION   0x00000004
#define ACSC_VARIABLES_PROTECTION			0x00000008

// Motor states
#define ACSC_MST_ENABLE						0x00000001
#define ACSC_MST_INPOS						0x00000010			
#define ACSC_MST_MOVE						0x00000020
#define ACSC_MST_ACC						0x00000040

// Motion states
#define ACSC_AST_LEAD						0x00000001
#define ACSC_AST_DC							0x00000002
#define ACSC_AST_PEG						0x00000004
#define ACSC_AST_PEGREADY					0x00000010
#define ACSC_AST_MOVE						0x00000020
#define ACSC_AST_ACC						0x00000040
#define ACSC_AST_SEGMENT					0x00000080
#define ACSC_AST_VELLOCK					0x00000100
#define ACSC_AST_POSLOCK					0x00000200
#define ACSC_AST_DECOMPON					0x04000000

// Index states
#define ACSC_IST_IND						0x00000001
#define ACSC_IST_IND2						0x00000002
#define ACSC_IST_MARK						0x00000004
#define ACSC_IST_MARK2						0x00000008

// Program states
#define ACSC_PST_COMPILED					0x00000001
#define ACSC_PST_RUN						0x00000002
#define ACSC_PST_SUSPEND					0x00000004
#define ACSC_PST_DEBUG						0x00000020
#define ACSC_PST_AUTO						0x00000080
#define ACSC_PST_BUFHOLD					0x00000100

// Program Flags
#define ACSC_PFLAGS_NOAUTO					0x00000001
#define ACSC_PFLAGS_NOEDIT					0x00000002
#define ACSC_PFLAGS_DYNAMIC					0x00000004
#define ACSC_PFLAGS_JIT						0x00000008
#define ACSC_PFLAGS_PRIVLG					0x00000010
#define ACSC_PFLAGS_DEBUG					0x00000020
#define ACSC_PFLAGS_NOVIEW					0x00000040
#define ACSC_PFLAGS_NOEDIT2					0x00000080
#define ACSC_PFLAGS_NOVIEW2					0x00000100
#define ACSC_PFLAGS_PRIVLG2					0x00000200

// Setup Flags
#define ACSC_S_SETUP_ENHPROT				0x00000010
#define ACSC_S_SETUP_CONFPROT				0x00000020
#define ACSC_S_SETUP_BUFPROT				0x00020000
#define ACSC_S_SETUP_VARPROT				0x00040000
#define ACSC_S_SETUP_BUFPROT2				0x01000000

// Safety control masks
#define ACSC_SAFETY_RL						0x00000001
#define ACSC_SAFETY_LL						0x00000002
#define ACSC_SAFETY_NETWORK					0x00000004
#define ACSC_SAFETY_HOT						0x00000010
#define ACSC_SAFETY_SRL						0x00000020
#define ACSC_SAFETY_SLL						0x00000040
#define ACSC_SAFETY_ENCNC					0x00000080
#define ACSC_SAFETY_ENC2NC					0x00000100
#define ACSC_SAFETY_DRIVE					0x00000200
#define ACSC_SAFETY_ENC						0x00000400
#define ACSC_SAFETY_ENC2					0x00000800
#define ACSC_SAFETY_PE						0x00001000
#define ACSC_SAFETY_CPE						0x00002000
#define ACSC_SAFETY_VL						0x00004000
#define ACSC_SAFETY_AL						0x00008000
#define ACSC_SAFETY_CL						0x00010000
#define ACSC_SAFETY_SP						0x00020000
#define ACSC_SAFETY_STO						0x00040000
#define ACSC_SAFETY_HSSINC					0x00100000

#define ACSC_SAFETY_EXTNT					0x00800000
#define ACSC_SAFETY_TEMP					0x01000000
#define ACSC_SAFETY_PROG					0x02000000
#define ACSC_SAFETY_MEM						0x04000000
#define ACSC_SAFETY_TIME					0x08000000
#define ACSC_SAFETY_ES						0x10000000
#define ACSC_SAFETY_INT						0x20000000
#define ACSC_SAFETY_INTGR					0x40000000
#define ACSC_SAFETY_FAILURE					0x80000000

// EtherCAT flags
#define ACSC_ETHERCAT_1BYTE					0x00000001
#define ACSC_ETHERCAT_2BYTES				0x00000002
#define ACSC_ETHERCAT_4BYTES			    0x00000004
#define ACSC_ETHERCAT_FLOAT					0x00000008
#define ACSC_ETHERCAT_NETWORK_0				0x00000010
#define ACSC_ETHERCAT_NETWORK_1				0x00000020
#define ACSC_BIT_OFFSET			            0x00000040

//////////////////////////////////////////////////////////////////////////////////////////////////
// Old Axes Masks
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_MASK_AXIS_X					0x00000001
#define ACSC_MASK_AXIS_Y					0x00000002
#define ACSC_MASK_AXIS_Z					0x00000004
#define ACSC_MASK_AXIS_T					0x00000008
#define ACSC_MASK_AXIS_A					0x00000010
#define ACSC_MASK_AXIS_B					0x00000020
#define ACSC_MASK_AXIS_C					0x00000040
#define ACSC_MASK_AXIS_D					0x00000080

//////////////////////////////////////////////////////////////////////////////////////////////////
// New Axes Masks
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_MASK_AXIS_0					0x0000000000000001
#define ACSC_MASK_AXIS_1					0x0000000000000002
#define ACSC_MASK_AXIS_2					0x0000000000000004
#define ACSC_MASK_AXIS_3					0x0000000000000008
#define ACSC_MASK_AXIS_4					0x0000000000000010
#define ACSC_MASK_AXIS_5					0x0000000000000020
#define ACSC_MASK_AXIS_6					0x0000000000000040
#define ACSC_MASK_AXIS_7					0x0000000000000080
#define ACSC_MASK_AXIS_8					0x0000000000000100
#define ACSC_MASK_AXIS_9					0x0000000000000200
#define ACSC_MASK_AXIS_10					0x0000000000000400
#define ACSC_MASK_AXIS_11					0x0000000000000800
#define ACSC_MASK_AXIS_12					0x0000000000001000
#define ACSC_MASK_AXIS_13					0x0000000000002000
#define ACSC_MASK_AXIS_14					0x0000000000004000
#define ACSC_MASK_AXIS_15					0x0000000000008000
#define ACSC_MASK_AXIS_16					0x0000000000010000
#define ACSC_MASK_AXIS_17					0x0000000000020000
#define ACSC_MASK_AXIS_18					0x0000000000040000
#define ACSC_MASK_AXIS_19					0x0000000000080000
#define ACSC_MASK_AXIS_20					0x0000000000100000
#define ACSC_MASK_AXIS_21					0x0000000000200000
#define ACSC_MASK_AXIS_22					0x0000000000400000
#define ACSC_MASK_AXIS_23					0x0000000000800000
#define ACSC_MASK_AXIS_24					0x0000000001000000
#define ACSC_MASK_AXIS_25					0x0000000002000000
#define ACSC_MASK_AXIS_26					0x0000000004000000
#define ACSC_MASK_AXIS_27					0x0000000008000000
#define ACSC_MASK_AXIS_28					0x0000000010000000
#define ACSC_MASK_AXIS_29					0x0000000020000000
#define ACSC_MASK_AXIS_30					0x0000000040000000
#define ACSC_MASK_AXIS_31					0x0000000080000000
#define ACSC_MASK_AXIS_32					0x0000000100000000
#define ACSC_MASK_AXIS_33					0x0000000200000000
#define ACSC_MASK_AXIS_34					0x0000000400000000
#define ACSC_MASK_AXIS_35					0x0000000800000000
#define ACSC_MASK_AXIS_36					0x0000001000000000
#define ACSC_MASK_AXIS_37					0x0000002000000000
#define ACSC_MASK_AXIS_38					0x0000004000000000
#define ACSC_MASK_AXIS_39					0x0000008000000000
#define ACSC_MASK_AXIS_40					0x0000010000000000
#define ACSC_MASK_AXIS_41					0x0000020000000000
#define ACSC_MASK_AXIS_42					0x0000040000000000
#define ACSC_MASK_AXIS_43					0x0000080000000000
#define ACSC_MASK_AXIS_44					0x0000100000000000
#define ACSC_MASK_AXIS_45					0x0000200000000000
#define ACSC_MASK_AXIS_46					0x0000400000000000
#define ACSC_MASK_AXIS_47					0x0000800000000000
#define ACSC_MASK_AXIS_48					0x0001000000000000
#define ACSC_MASK_AXIS_49					0x0002000000000000
#define ACSC_MASK_AXIS_50					0x0004000000000000
#define ACSC_MASK_AXIS_51					0x0008000000000000
#define ACSC_MASK_AXIS_52					0x0010000000000000
#define ACSC_MASK_AXIS_53					0x0020000000000000
#define ACSC_MASK_AXIS_54					0x0040000000000000
#define ACSC_MASK_AXIS_55					0x0080000000000000
#define ACSC_MASK_AXIS_56					0x0100000000000000
#define ACSC_MASK_AXIS_57					0x0200000000000000
#define ACSC_MASK_AXIS_58					0x0400000000000000
#define ACSC_MASK_AXIS_59					0x0800000000000000
#define ACSC_MASK_AXIS_60					0x1000000000000000
#define ACSC_MASK_AXIS_61					0x2000000000000000
#define ACSC_MASK_AXIS_62					0x4000000000000000
#define ACSC_MASK_AXIS_63					0x8000000000000000

#define ACSC_MASK_AXIS_64					0x0000000000000001
#define ACSC_MASK_AXIS_65					0x0000000000000002
#define ACSC_MASK_AXIS_66					0x0000000000000004
#define ACSC_MASK_AXIS_67					0x0000000000000008
#define ACSC_MASK_AXIS_68					0x0000000000000010
#define ACSC_MASK_AXIS_69					0x0000000000000020
#define ACSC_MASK_AXIS_70					0x0000000000000040
#define ACSC_MASK_AXIS_71					0x0000000000000080
#define ACSC_MASK_AXIS_72					0x0000000000000100
#define ACSC_MASK_AXIS_73					0x0000000000000200
#define ACSC_MASK_AXIS_74					0x0000000000000400
#define ACSC_MASK_AXIS_75					0x0000000000000800
#define ACSC_MASK_AXIS_76					0x0000000000001000
#define ACSC_MASK_AXIS_77					0x0000000000002000
#define ACSC_MASK_AXIS_78					0x0000000000004000
#define ACSC_MASK_AXIS_79					0x0000000000008000
#define ACSC_MASK_AXIS_80					0x0000000000010000
#define ACSC_MASK_AXIS_81					0x0000000000020000
#define ACSC_MASK_AXIS_82					0x0000000000040000
#define ACSC_MASK_AXIS_83					0x0000000000080000
#define ACSC_MASK_AXIS_84					0x0000000000100000
#define ACSC_MASK_AXIS_85					0x0000000000200000
#define ACSC_MASK_AXIS_86					0x0000000000400000
#define ACSC_MASK_AXIS_87					0x0000000000800000
#define ACSC_MASK_AXIS_88					0x0000000001000000
#define ACSC_MASK_AXIS_89					0x0000000002000000
#define ACSC_MASK_AXIS_90					0x0000000004000000
#define ACSC_MASK_AXIS_91					0x0000000008000000
#define ACSC_MASK_AXIS_92					0x0000000010000000
#define ACSC_MASK_AXIS_93					0x0000000020000000
#define ACSC_MASK_AXIS_94					0x0000000040000000
#define ACSC_MASK_AXIS_95					0x0000000080000000
#define ACSC_MASK_AXIS_96					0x0000000100000000
#define ACSC_MASK_AXIS_97					0x0000000200000000
#define ACSC_MASK_AXIS_98					0x0000000400000000
#define ACSC_MASK_AXIS_99					0x0000000800000000
#define ACSC_MASK_AXIS_100					0x0000001000000000
#define ACSC_MASK_AXIS_101					0x0000002000000000
#define ACSC_MASK_AXIS_102					0x0000004000000000
#define ACSC_MASK_AXIS_103					0x0000008000000000
#define ACSC_MASK_AXIS_104					0x0000010000000000
#define ACSC_MASK_AXIS_105					0x0000020000000000
#define ACSC_MASK_AXIS_106					0x0000040000000000
#define ACSC_MASK_AXIS_107					0x0000080000000000
#define ACSC_MASK_AXIS_108					0x0000100000000000
#define ACSC_MASK_AXIS_109					0x0000200000000000
#define ACSC_MASK_AXIS_110					0x0000400000000000
#define ACSC_MASK_AXIS_111					0x0000800000000000
#define ACSC_MASK_AXIS_112					0x0001000000000000
#define ACSC_MASK_AXIS_113					0x0002000000000000
#define ACSC_MASK_AXIS_114					0x0004000000000000
#define ACSC_MASK_AXIS_115					0x0008000000000000
#define ACSC_MASK_AXIS_116					0x0010000000000000
#define ACSC_MASK_AXIS_117					0x0020000000000000
#define ACSC_MASK_AXIS_118					0x0040000000000000
#define ACSC_MASK_AXIS_119					0x0080000000000000
#define ACSC_MASK_AXIS_120					0x0100000000000000
#define ACSC_MASK_AXIS_121					0x0200000000000000
#define ACSC_MASK_AXIS_122					0x0400000000000000
#define ACSC_MASK_AXIS_123					0x0800000000000000
#define ACSC_MASK_AXIS_124					0x1000000000000000
#define ACSC_MASK_AXIS_125					0x2000000000000000
#define ACSC_MASK_AXIS_126					0x4000000000000000
#define ACSC_MASK_AXIS_127					0x8000000000000000

// Buffer masks
#define ACSC_MASK_BUFFER_0					0x0000000000000001
#define ACSC_MASK_BUFFER_1					0x0000000000000002
#define ACSC_MASK_BUFFER_2					0x0000000000000004
#define ACSC_MASK_BUFFER_3					0x0000000000000008
#define ACSC_MASK_BUFFER_4					0x0000000000000010
#define ACSC_MASK_BUFFER_5					0x0000000000000020
#define ACSC_MASK_BUFFER_6					0x0000000000000040
#define ACSC_MASK_BUFFER_7					0x0000000000000080
#define ACSC_MASK_BUFFER_8					0x0000000000000100
#define ACSC_MASK_BUFFER_9					0x0000000000000200
#define ACSC_MASK_BUFFER_10					0x0000000000000400
#define ACSC_MASK_BUFFER_11					0x0000000000000800
#define ACSC_MASK_BUFFER_12					0x0000000000001000
#define ACSC_MASK_BUFFER_13					0x0000000000002000
#define ACSC_MASK_BUFFER_14					0x0000000000004000
#define ACSC_MASK_BUFFER_15					0x0000000000008000
#define ACSC_MASK_BUFFER_16					0x0000000000010000
#define ACSC_MASK_BUFFER_17					0x0000000000020000
#define ACSC_MASK_BUFFER_18					0x0000000000040000
#define ACSC_MASK_BUFFER_19					0x0000000000080000
#define ACSC_MASK_BUFFER_20					0x0000000000100000
#define ACSC_MASK_BUFFER_21					0x0000000000200000
#define ACSC_MASK_BUFFER_22					0x0000000000400000
#define ACSC_MASK_BUFFER_23					0x0000000000800000
#define ACSC_MASK_BUFFER_24					0x0000000001000000
#define ACSC_MASK_BUFFER_25					0x0000000002000000
#define ACSC_MASK_BUFFER_26					0x0000000004000000
#define ACSC_MASK_BUFFER_27					0x0000000008000000
#define ACSC_MASK_BUFFER_28					0x0000000010000000
#define ACSC_MASK_BUFFER_29					0x0000000020000000
#define ACSC_MASK_BUFFER_30					0x0000000040000000
#define ACSC_MASK_BUFFER_31					0x0000000080000000
#define ACSC_MASK_BUFFER_32					0x0000000100000000
#define ACSC_MASK_BUFFER_33					0x0000000200000000
#define ACSC_MASK_BUFFER_34					0x0000000400000000
#define ACSC_MASK_BUFFER_35					0x0000000800000000
#define ACSC_MASK_BUFFER_36					0x0000001000000000
#define ACSC_MASK_BUFFER_37					0x0000002000000000
#define ACSC_MASK_BUFFER_38					0x0000004000000000
#define ACSC_MASK_BUFFER_39					0x0000008000000000
#define ACSC_MASK_BUFFER_40					0x0000010000000000
#define ACSC_MASK_BUFFER_41					0x0000020000000000
#define ACSC_MASK_BUFFER_42					0x0000040000000000
#define ACSC_MASK_BUFFER_43					0x0000080000000000
#define ACSC_MASK_BUFFER_44					0x0000100000000000
#define ACSC_MASK_BUFFER_45					0x0000200000000000
#define ACSC_MASK_BUFFER_46					0x0000400000000000
#define ACSC_MASK_BUFFER_47					0x0000800000000000
#define ACSC_MASK_BUFFER_48					0x0001000000000000
#define ACSC_MASK_BUFFER_49					0x0002000000000000
#define ACSC_MASK_BUFFER_50					0x0004000000000000
#define ACSC_MASK_BUFFER_51					0x0008000000000000
#define ACSC_MASK_BUFFER_52					0x0010000000000000
#define ACSC_MASK_BUFFER_53					0x0020000000000000
#define ACSC_MASK_BUFFER_54					0x0040000000000000
#define ACSC_MASK_BUFFER_55					0x0080000000000000
#define ACSC_MASK_BUFFER_56					0x0100000000000000
#define ACSC_MASK_BUFFER_57					0x0200000000000000
#define ACSC_MASK_BUFFER_58					0x0400000000000000
#define ACSC_MASK_BUFFER_59					0x0800000000000000
#define ACSC_MASK_BUFFER_60					0x1000000000000000
#define ACSC_MASK_BUFFER_61					0x2000000000000000
#define ACSC_MASK_BUFFER_62					0x4000000000000000
#define ACSC_MASK_BUFFER_63					0x8000000000000000

// Input masks
#define ACSC_MASK_INPUT_0					0x00000001
#define ACSC_MASK_INPUT_1					0x00000002
#define ACSC_MASK_INPUT_2					0x00000004
#define ACSC_MASK_INPUT_3					0x00000008
#define ACSC_MASK_INPUT_4					0x00000010
#define ACSC_MASK_INPUT_5					0x00000020
#define ACSC_MASK_INPUT_6					0x00000040
#define ACSC_MASK_INPUT_7					0x00000080
#define ACSC_MASK_INPUT_8					0x00000100
#define ACSC_MASK_INPUT_9					0x00000200
#define ACSC_MASK_INPUT_10					0x00000400
#define ACSC_MASK_INPUT_11					0x00000800
#define ACSC_MASK_INPUT_12					0x00001000
#define ACSC_MASK_INPUT_13					0x00002000
#define ACSC_MASK_INPUT_14					0x00004000
#define ACSC_MASK_INPUT_15					0x00008000
#define ACSC_MASK_INPUT_16					0x00010000
#define ACSC_MASK_INPUT_17					0x00020000
#define ACSC_MASK_INPUT_18					0x00040000
#define ACSC_MASK_INPUT_19					0x00080000
#define ACSC_MASK_INPUT_20					0x00100000
#define ACSC_MASK_INPUT_21					0x00200000
#define ACSC_MASK_INPUT_22					0x00400000
#define ACSC_MASK_INPUT_23					0x00800000
#define ACSC_MASK_INPUT_24					0x01000000
#define ACSC_MASK_INPUT_25					0x02000000
#define ACSC_MASK_INPUT_26					0x04000000
#define ACSC_MASK_INPUT_27					0x08000000
#define ACSC_MASK_INPUT_28					0x10000000
#define ACSC_MASK_INPUT_29					0x20000000
#define ACSC_MASK_INPUT_30					0x40000000
#define ACSC_MASK_INPUT_31					0x80000000


//////////////////////////////////////////////////////////////////////////////////////////////////
// Errors codes
//////////////////////////////////////////////////////////////////////////////////////////////////
#define ACSC_ERRORBASE				100
#define ACSC_UNKNOWNERROR		   	ACSC_ERRORBASE		//Unknown error
#define ACSC_ONLYSYNCHRONOUS    	(ACSC_ERRORBASE+1)	//Asynchronous call is not supported
#define ACSC_ENOENTLOGFILE			(ACSC_ERRORBASE+2)	//No such file or directory
#define ACSC_OLD_FW					(ACSC_ERRORBASE+3)  //FW does not support all desired features
#define ACSC_MEMORY_OVERFLOW		(ACSC_ERRORBASE+4)  //Controllers reply is too long
#define ACSC_EBADFLOGFILE			(ACSC_ERRORBASE+9)	//Invalid log file handle 
#define ACSC_RTOS_NOT_INITIALIZED	(ACSC_ERRORBASE+10) //RTOS is not initialized
#define ACSC_SHM_NOT_INITIALIZED	(ACSC_ERRORBASE+11) //Shared Memory is not initialized
#define ACSC_SHM_WRONG_TYPE			(ACSC_ERRORBASE+12) //Wrong type of shared memory variable
#define ACSC_SHM_INVALID_ADDRESS	(ACSC_ERRORBASE+13) //Invalid address of shared memory variable
#define ACSC_SHE_NOT_SUPPORTED		(ACSC_ERRORBASE+14) //Shared Event is not supported
#define ACSC_SHE_INITERROR			(ACSC_ERRORBASE+15) //Shared Event initialization error
#define ACSC_SHE_NOT_INITIALIZED	(ACSC_ERRORBASE+16) //Shared Event is not initialized
#define ACSC_SHE_ARG_READ_ERROR		(ACSC_ERRORBASE+17) //Shared Event argument read error
#define ACSC_SHE_CLOSE_ERROR		(ACSC_ERRORBASE+18) //Shared Event close error
#define ACSC_ILLEGAL_FLAGS_SPEC		(ACSC_ERRORBASE+19) //Illegal flags specification
#define ACSC_EINVALLOGFILE			(ACSC_ERRORBASE+22)	//Write error in Log file
#define ACSC_EMFILELOGFILE			(ACSC_ERRORBASE+24)	//Unable to open file
#define ACSC_ENOSPCLOGFILE			(ACSC_ERRORBASE+28)	//Cannot open Log file. The drive is full
#define ACSC_TIMEOUT				(ACSC_ERRORBASE+30)	//The controller stopped responding
#define ACSC_SIMULATOR_NOT_RUN		(ACSC_ERRORBASE+31)	//Atempted to stop simulator that was not running
#define ACSC_INITFAILURE			(ACSC_ERRORBASE+32)	//Communication initialization failure
#define ACSC_SIMULATOR_RUN_EXT		(ACSC_ERRORBASE+33)	//Stand-alone simulator has been executed not via UMD
#define ACSC_INVALIDHANDLE			(ACSC_ERRORBASE+34)	//Invalid communication handle
#define ACSC_ALLCHANNELSBUSY		(ACSC_ERRORBASE+35)	//All channels are busy
#define ACSC_SIMULATOR_NOT_SET		(ACSC_ERRORBASE+36)	//Stand-alone simulator has not been set in UMD
#define ACSC_RECEIVEDTOOLONG		(ACSC_ERRORBASE+37)	//Received message too long(more than size of user buffer)
#define ACSC_INVALIDBUFSIZE			(ACSC_ERRORBASE+38)	//Functions acsc_DownloadBuffer: the program contains string longer than 2032 bytes
#define ACSC_INVALIDPARAMETERS		(ACSC_ERRORBASE+39) //Function parameters are invalid
#define ACSC_CLOSEDHISTORYBUF		(ACSC_ERRORBASE+40)	//History buffer is closed 
#define ACSC_EMPTYNAMEVAR			(ACSC_ERRORBASE+41)	//Name variable must be specified
#define	ACSC_INPUTPAR				(ACSC_ERRORBASE+42)	//Error in index specification
#define	ACSC_RECEIVEDTOOSMALL		(ACSC_ERRORBASE+43)	//Controller reply contains less values than expected
#define	ACSC_FUNCTIONNOTSUPPORTED	(ACSC_ERRORBASE+45)	//Function is not supported in current version
#define ACSC_INITHISTORYBUFFAILED	(ACSC_ERRORBASE+47) //History buffer initialization failure
#define ACSC_CLOSEDMESSAGEBUF		(ACSC_ERRORBASE+50)	//Unsolicited messages buffer is closed 
#define ACSC_SETCALLBACKERROR		(ACSC_ERRORBASE+51) //Callback registration error
#define ACSC_CALLBACKALREADYSET		(ACSC_ERRORBASE+52) //Callback function has been already installed
#define ACSC_CHECKSUMERROR			(ACSC_ERRORBASE+53)	//Checksum of controller reply error
#define ACSC_REPLIESSEQUENCEERROR	(ACSC_ERRORBASE+54)	//Internal error: Replies sequence error
#define ACSC_WAITFAILED				(ACSC_ERRORBASE+55)	//Internal error: WaitForSingleObject error
#define ACSC_INITMESSAGEBUFFAILED	(ACSC_ERRORBASE+57) //Unsolicited messages buffer initialization failure
#define ACSC_OPERATIONABORTED		(ACSC_ERRORBASE+58) //Non-waiting call has been aborted
#define ACSC_CANCELOPERATIONERROR	(ACSC_ERRORBASE+59) //Error of the non-waiting call cancellation
#define ACSC_COMMANDSQUEUEFULL		(ACSC_ERRORBASE+60)	//Internal error: Queue of transmitted commands is full
#define ACSC_SENDINGFAILED			(ACSC_ERRORBASE+62)	//Internal error: Sending is failed
#define ACSC_RECEIVINGFAILED		(ACSC_ERRORBASE+63)	//Internal error: Receiving is failed
#define ACSC_CHAINSENDINGFAILED		(ACSC_ERRORBASE+64)	//Internal error: Sending of chain is failed
#define ACSC_DUPLICATED_IP			(ACSC_ERRORBASE+65)	//Specified IP address is duplicated
#define ACSC_APPLICATION_NOT_FOUND	(ACSC_ERRORBASE+66) //There is no Application with such Handle
#define ACSC_ARRAY_EXPECTED     	(ACSC_ERRORBASE+67) //Array name was expected
#define ACSC_INVALID_FILE_FORMAT    (ACSC_ERRORBASE+68) //The file is not a valid ANSI data file
#define ACSC_APPSL_CRC				(ACSC_ERRORBASE+71)	// Application Saver Loader CRC Error
#define ACSC_APPSL_HEADERCRC		(ACSC_ERRORBASE+72)	// Application Saver Loader Header CRC Error
#define ACSC_APPSL_FILESIZE		    (ACSC_ERRORBASE+73)	// Application Saver Loader File Size Error
#define ACSC_APPSL_FILEOPEN			(ACSC_ERRORBASE+74)	// Application Saver Loader File Open Error
#define ACSC_APPSL_UNKNOWNFILE		(ACSC_ERRORBASE+75) // Application Saver Loader Unknown File Error
#define ACSC_APPSL_VERERROR         (ACSC_ERRORBASE+76) // Application Saver Loader Format Version Error
#define ACSC_APPSL_SECTION_SIZE		(ACSC_ERRORBASE+77) // Application Saver Loader Section Size is Zero
#define ACSC_TLSERROR				(ACSC_ERRORBASE+79)	//Internal error: Thread local storage error
#define ACSC_INITDRIVERFAILED		(ACSC_ERRORBASE+80)	//PCI driver initialization failure
#define ACSC_CAN_INITFAILURE		(ACSC_ERRORBASE+81)	//CAN library not found or initialization failure
#define ACSC_CLOSED_BY_CONTROLLER	(ACSC_ERRORBASE+82)	//Communication closed by the controller
#define ACSC_INVALIDPOINTER			(ACSC_ERRORBASE+85)	//Pointer to the buffer is invalid || Null pointer recieved instead of user allocated object
#define ACSC_SETPRIORITYERROR		(ACSC_ERRORBASE+89)	//Specified priority for the callback thread cannot be set
#define ACSC_DIRECTDPRAMACCESS		(ACSC_ERRORBASE+90)	//Attempt to access DPRAM not via PCI
#define ACSC_DDERROR				(ACSC_ERRORBASE+91)	//Spii.vxd/sys can not be found or installed
#define ACSC_INVALID_DPRAM_ADDR		(ACSC_ERRORBASE+92) //Invalid DPRAM address 
#define ACSC_OLD_SIMULATOR			(ACSC_ERRORBASE+93) //Old version of SPiiPlus Simulator
#define ACSC_HW_PROBLEM				(ACSC_ERRORBASE+94) //Hardware won't work properly
#define ACSC_FILE_NOT_FOUND			(ACSC_ERRORBASE+95)
#define ACSC_AUTHENTICATIONEXCEPTION	(ACSC_ERRORBASE+96) //Authentication error
#define ACSC_SERVEREXCEPTION		(ACSC_ERRORBASE+97)
#define ACSC_STOPPED_RESPONDING		(ACSC_ERRORBASE+98)
#define ACSC_DLL_UMD_VERSION		(ACSC_ERRORBASE+99) //DLL and Server are not of the same Version

#define ACSC_FRF_INPUT_START_FREQUENCY_OUT_OF_RANGE (ACSC_ERRORBASE+100)
#define ACSC_FRF_INPUT_END_FREQUENCY_OUT_OF_RANGE (ACSC_ERRORBASE+101)
#define ACSC_FRF_INPUT_START_FREQUENCY_IS_HIGHER_THAN_END_FREQUENCY (ACSC_ERRORBASE+102)
#define ACSC_FRF_INPUT_FREQPERDEC_OUT_OF_RANGE (ACSC_ERRORBASE+103) // Standard resolution frequency per decade is out of range
#define ACSC_FRF_INPUT_HR_FREQPERDEC_OUT_OF_RANGE (ACSC_ERRORBASE+104) // High resolution frequency per decade is out of range
#define ACSC_FRF_INPUT_FREQUENCY_RESOLUTION_LINEAR_OUT_OF_RANGE (ACSC_ERRORBASE+105) // Required freqeuncy resolution (linear distribution) is out of range
#define ACSC_FRF_INPUT_AMPLITUDE_OUT_OF_RANGE (ACSC_ERRORBASE+106) //Excitation amplitude is out of range
#define ACSC_FRF_INPUT_AXIS_OUT_OF_RANGE (ACSC_ERRORBASE+107) // Axis is out of range of Controller axes
#define ACSC_FRF_INPUT_NUMBER_OF_REPETITIONS_OUT_OF_RANGE (ACSC_ERRORBASE+108) // Number of Excitation repetitions is out of range
#define ACSC_FRF_INPUT_DURATION_OUT_OF_RANGE (ACSC_ERRORBASE+109) // Excitation duration is out of range
#define ACSC_FRF_INPUT_ENUM_VALUE_OUT_OF_RANGE (ACSC_ERRORBASE + 110) // Excitation duration is out of range
#define ACSC_FRF_MEMORY_ALLOCATION_FAILED_AT_HOST (ACSC_ERRORBASE+111) // Failed to allocate memory at PC
#define ACSC_FRF_DATA_READ_FROM_CONTROLLER_INCONSISTENT (ACSC_ERRORBASE+112) // Internal error
#define ACSC_FRF_DSP_DOESNT_HAVE_REQUIRED_PARAMETERS (ACSC_ERRORBASE+113) // DSP should have appropriate parameters
#define ACSC_FRF_FAILED_TO_COMMUNICATE_WITH_CONTROLLER (ACSC_ERRORBASE+114) // Failed to send/receive command to/from controller
#define ACSC_FRF_FAILED_TO_READ_SERVO_PARAMETERS (ACSC_ERRORBASE+115) //internal error
#define ACSC_FRF_DUMMY_AXIS_NOT_SUPPORTED (ACSC_ERRORBASE+116)
#define ACSC_FRF_MOTOR_SHOULD_BE_SET_TO_CLOSED_LOOP (ACSC_ERRORBASE+117) //MFLAGS.#OPEN should be set to 1
#define ACSC_FRF_MOTOR_SHOULD_BE_ENABLED (ACSC_ERRORBASE+118)
#define ACSC_FRF_MOTOR_SHOULD_COMMUTATED (ACSC_ERRORBASE+119) // For brushless motors
#define ACSC_FRF_SPDC_IS_ALREADY_IN_PROGRESS (ACSC_ERRORBASE+120) //SPDC command is already running
#define ACSC_FRF_ABORTED_BY_USER (ACSC_ERRORBASE+121) // FRF abort issued by the user
#define ACSC_FRF_MOTOR_DISABLED_DURING_MEASUREMENT (ACSC_ERRORBASE+122) 
#define ACSC_FRF_DISABLE_OR_FAULT_OCCURED_DURING_MEASUREMENT (ACSC_ERRORBASE+123)
#define ACSC_FRF_FAULT_OCCURED_DURING_MEASUREMENT (ACSC_ERRORBASE+124)
#define ACSC_FRF_ARRAY_SIZES_INCOMATIBLE (ACSC_ERRORBASE+125) //internal error
#define ACSC_FRF_NUMBER_OF_POINTS_SHOULD_BE_POSITIVE (ACSC_ERRORBASE+126) //internal error
#define ACSC_FRF_MEMORY_ALLOCATION_FAILED_AT_CONTROLLER (ACSC_ERRORBASE+127) // Failed to allocate memory in controller
#define ACSC_FRF_EXCITATION_DURATION_IS_TOO_LONG (ACSC_ERRORBASE+128) //internal error
#define ACSC_FRF_USER_DEFINED_EXCITATION_SIGNAL_REQUIRED_BUT_NOT_DEFINED (ACSC_ERRORBASE+129) //
#define ACSC_FRF_USER_DEFINED_EXCITATION_SIGNAL_OUT_OF_BOUNDARIES (ACSC_ERRORBASE+130) //
#define ACSC_FRF_FRD_LENGTH_TOO_SHORT (ACSC_ERRORBASE+131) //
#define ACSC_FRF_FRD_FREQUENCIES_SHOULD_BE_CONTINUOUSLY_INCREASING (ACSC_ERRORBASE+132) // 

#define ACSC_JITTER_ANALYSIS_JITTER_ARRAY_TOO_SHORT (ACSC_ERRORBASE+133) 
#define ACSC_JITTER_ANALYSIS_SAMPLING_FREQUENCY_NOT_VALID (ACSC_ERRORBASE+134) // Frequency should not be >= 0
#define ACSC_JITTER_ANALYSIS_WINDOW_TYPE_NOT_SUPPORTED (ACSC_ERRORBASE+135) // 
#define ACSC_JITTER_ANALYSIS_FREQUENCY_RANGE_NOT_VALID (ACSC_ERRORBASE+136) // 
#define ACSC_JITTER_ANALYSIS_FREQUENCY_RESOLUTION_NOT_VALID (ACSC_ERRORBASE+137) // 

#define ACSC_LICENSE_COMMON_PROBLEM (ACSC_ERRORBASE+138)  
#define ACSC_LICENSE_DONGLE_NOT_FOUND (ACSC_ERRORBASE+139) 
#define ACSC_LICENSE_ENTRY_NOT_FOUND (ACSC_ERRORBASE+140)  
#define ACSC_LICENSE_INVALID_HANDLE (ACSC_ERRORBASE+141)
#define ACSC_LICENSE_NO_DATA_AVAILABLE (ACSC_ERRORBASE+142)  
#define ACSC_LICENSE_INVALID_PN (ACSC_ERRORBASE+143) 

#define ACSC_SC_INCORRECT_PROC_ALLOC (ACSC_ERRORBASE+144) //SPiiPlusSC: Incorrect Windows Processor Allocation
#define ACSC_SC_MISSING_DRIVERS (ACSC_ERRORBASE+145) //SPiiPlusSC: Missing drivers 
#define ACSC_SC_INCORRECT_MEMORY (ACSC_ERRORBASE+146) //SPiiPlusSC: Incorrect Memory Reservations
#define ACSC_SC_RTOS_SERVICE (ACSC_ERRORBASE+147) //SPiiPlusSC: RTOS Service isn't running 
#define ACSC_SC_REBOOT (ACSC_ERRORBASE+148) //SPiiPlusSC: System requires reboot
#define ACSC_SC_DONGLE_VERSION (ACSC_ERRORBASE+149) //SPiiPlusSC: Detected CmStick Version of Dongle is too old

#define ACSC_LICENSE_NONLICENSED_FEATURE_MATLAB (ACSC_ERRORBASE+150) // MATLAB labrary is not licensed according to existing License PN 
#define ACSC_LICENSE_NONLICENSED_FEATURE_FRF (ACSC_ERRORBASE+151) // FRF library is not licensed according to existing License PN 
#define ACSC_LICENSE_NONLICENSED_FEATURE_COMMON (ACSC_ERRORBASE+152) // Feature is not licensed according to existing License PN 
#define ACSC_FRF_GENERAL_ERROR (ACSC_ERRORBASE+153) //General error mainly for .]resolving .NET library conflict when function returns 0 and errorCode is also 0
#define ACSC_FRF_RECALCULATE_INCOMPATIBLE_DATA (ACSC_ERRORBASE+154) //When recalculate required with raw data length different from durationSec*NumberOfRepetitions
#define ACSC_FRF_LOOP_RECALCULATE_INCOMPATIBLE_DATA (ACSC_ERRORBASE+155) //when acsc_FRF_CalculateLoopDataFRD called with incompatibe measure and target loop types
#define ACSC_FRF_SLVRAT_DATA_TOO_SHORT (ACSC_ERRORBASE+156) //
#define ACSC_FRF_SLVRAT_CALCULATION_PHASE_IS_INCOMPATIBLE (ACSC_ERRORBASE+157) //
#define ACSC_FRF_SLVRAT_CALCULATION_FAILED (ACSC_ERRORBASE+158) //
#define ACSC_FRF_INPUT_AXIS_ILLEGAL_DSP_NUMBER (ACSC_ERRORBASE+159) // Axis assigned to a non existing DSP
#define ACSC_FRF_CROSS_COUPLING_INPUT_NUMBER_OF_AXES_TOO_LOW (ACSC_ERRORBASE+160) // Number of axes in cross coupling measurement is too low
#define ACSC_FRF_CROSS_COUPLING_INPUT_NUMBER_OF_AXES_TOO_HIGH (ACSC_ERRORBASE+161) // Number of axes in cross coupling measurement is too high
#define ACSC_FRF_CROSS_COUPLING_CUSTOM_OUTPUT_DOESNT_EXIST (ACSC_ERRORBASE+162) // Custom output variable doesn't exist
#define ACSC_FRF_CROSS_COUPLING_UNSUPPORTED_FEATURE (ACSC_ERRORBASE+163) // This functionality of the FRF Library is not supported yet
#define ACSC_FRF_SPRT_IS_ALREADY_IN_PROGRESS (ACSC_ERRORBASE+164) //SPRT command is already running

#define ACSC_CONTROLLER_IS_ALREADY_PROTECTED     (ACSC_ERRORBASE+165) //Controller is already protected
#define ACSC_INVALIDPROTECTION                   (ACSC_ERRORBASE+166) //Protection status is invalid
#define ACSC_BUFFER_IS_ALREADY_PROTECTED         (ACSC_ERRORBASE+167) //Buffer is already protected

#define ACSC_HW_ERRORBASE			500						// Hardware specific errors
#define ACSC_HW_NO_INT				(ACSC_HW_ERRORBASE+2)
#define ACSC_HW_INT_PERIOD			(ACSC_HW_ERRORBASE+4)
#define ACSC_HW_NO_INT_NOTIF		(ACSC_HW_ERRORBASE+6)
#define ACSC_HW_SPiiFAILURE			(ACSC_HW_ERRORBASE+8)

#define ACSC_CANDEVICE_CUSTOM1		1
#define ACSC_CANDEVICE_CUSTOM2		2
#define ACSC_CANDEVICE_NI			11

#if defined (_ACSC_LIBRARY_DLL_) && defined (_WIN32)
#define _ACSCLIB_ __declspec( dllexport )
#elif defined (_WIN32)
#define _ACSCLIB_ __declspec( dllimport )
#elif defined (_ACSC_LIBRARY_DLL_) && (defined(__linux__) || defined(__APPLE__))
#define _ACSCLIB_ __attribute__((visibility("default")))
#else
#define _ACSCLIB_
#endif

typedef enum
{
	Plant,
	Controller,
	OpenLoop,
	ClosedLoop,
	Sensitivity
} FRF_DATA_TYPE;
typedef enum
{
	PositionVelocity,
	Position,
	Velocity,
	Current,
	Open,
	DualLoopOpen,
	DualLoop
} FRF_LOOP_TYPE;
typedef enum
{
	NoOverlap,
	HalfSignal
} FRF_OVERLAP;
typedef enum
{
	WhiteNoise,
	ChirpPeriodic,
	UserDefined
} FRF_EXCITATION_TYPE;
typedef enum
{
	LogarithmicChirp,
	LinearChirp
} FRF_CHIRP_TYPE;
typedef enum
{
	Hanning,
	Rectangular,
	Hamming
} FRF_WINDOW_TYPE;
typedef enum {
	Logarithmic,
	Linear
}FRF_FREQUENCY_DISTRIBUTION_TYPE;

typedef enum
{
	OneDirectionOpen,
	OneDirection,
	Complete,
	CompleteOpen,
	CustomInput,
	CustomOutput
}FRF_CROSS_COUPLING_TYPE;

typedef struct _FRD
{
	double* real;
	double* imag;
	double* frequencyHz;
	unsigned int length;
} FRD;
typedef struct _FRF_STABILITY_MARGINS
{
	double* gainMarginArray;
	double* gainMarginArrayFrequencyHz;
	unsigned int gainMarginArrayLength;
	double gainMarginWorst;
	double gainMarginWorstFrequencyHz;

	double* phaseMarginArray;
	double* phaseMarginArrayFrequencyHz;
	unsigned int phaseMarginArrayLength;
	double phaseMarginWorst;
	double phaseMarginWorstFrequencyHz;

	double modulusMargin;
	double modulusMarginFrequencyHz;

	double bandwidth;
} FRF_STABILITY_MARGINS;
typedef struct _FRF_DURATION_CALCULATION_PARAMETERS
{
	FRF_FREQUENCY_DISTRIBUTION_TYPE frequencyDistributionType;
	double startFreqHz;
	double endFreqHz;
	int freqPerDec;

	double highResolutionStart;
	int highResolutionFreqPerDec;

	double frequencyHzResolutionForLinear;
} FRF_DURATION_CALCULATION_PARAMETERS;

// Structure used for defining FRF input parameters
typedef struct _FRF_INPUT
{
	int axis;
	FRF_LOOP_TYPE loopType;
	FRF_EXCITATION_TYPE excitationType;
	FRF_CHIRP_TYPE chirpType;
	FRF_WINDOW_TYPE windowType;
	FRF_FREQUENCY_DISTRIBUTION_TYPE frequencyDistributionType;
	FRF_OVERLAP overlap;
	double startFreqHz;
	double endFreqHz;
	int freqPerDec;
	double excitationAmplitudePercentIp;

	int numberOfRepetitions;
	double highResolutionStart;
	int highResolutionFreqPerDec;

	double durationSec; // applicable for Chirp and White Noise options

	// User defined excitation signal
	double* userDefinedExcitationSignal;
	int userDefinedExcitationSignalLength;

	// Quick recalculate without remeasuring
	double* inRaw;
	double* outRaw;
	int lengthRaw;
	BOOL recalculate;
} FRF_INPUT;
// Structure used for defining FRF output parameters
typedef struct _FRF_OUTPUT
{
	// Plant parameters
	FRD* plant; // P
	FRD* controller; //C
	FRD* openLoop; //L
	FRD* closedLoop; //T
	FRD* sensitivity; //S
	FRD* coherence;	
	FRF_STABILITY_MARGINS* stabilityMargins;

	FRF_LOOP_TYPE loopType;

	double* inRaw;
	double* outRaw;
	int lengthRaw;

	double excitationAmplitude;

	FRD* plantVelocityToPosition; // Plant from Velocity to Position. 1/s for a rigid body. Some Transfer function in dual loop systems
	FRD* coherenceVelocityToPosition;
} FRF_OUTPUT;

typedef struct _FILTER_ROUTING
{
#pragma region
	double SLVNFRQ0;
	double SLVNWID0;
	double SLVNATT0;

	double SLVB0NF0;
	double SLVB0DF0;
	double SLVB0ND0;
	double SLVB0DD0;

	double SLVB1NF0;
	double SLVB1DF0;
	double SLVB1ND0;
	double SLVB1DD0;
#pragma endregion Axis 0
#pragma region
	double SLVNFRQ1;
	double SLVNWID1;
	double SLVNATT1;

	double SLVB0NF1;
	double SLVB0DF1;
	double SLVB0ND1;
	double SLVB0DD1;

	double SLVB1NF1;
	double SLVB1DF1;
	double SLVB1ND1;
	double SLVB1DD1;
#pragma endregion Axis 1
#pragma region
	double SLVNFRQ2;
	double SLVNWID2;
	double SLVNATT2;

	double SLVB0NF2;
	double SLVB0DF2;
	double SLVB0ND2;
	double SLVB0DD2;

	double SLVB1NF2;
	double SLVB1DF2;
	double SLVB1ND2;
	double SLVB1DD2;
#pragma endregion Axis 2
#pragma region
	double SLVNFRQ3;
	double SLVNWID3;
	double SLVNATT3;

	double SLVB0NF3;
	double SLVB0DF3;
	double SLVB0ND3;
	double SLVB0DD3;

	double SLVB1NF3;
	double SLVB1DF3;
	double SLVB1ND3;
	double SLVB1DD3;
#pragma endregion Axis 3

	INT32 MFLAGS0;
	INT32 MFLAGS1;
	INT32 MFLAGS2;
	INT32 MFLAGS3;
} FILTER_ROUTING;

typedef struct _SERVO_PARAMETERS
{
	double SLIKP;
	double SLIKI;
	double SLILI;

	double SLPKP;
	double SLPKI;
	double SLPLI;

	double SLVKP;
	double SLVKI;
	double SLVLI;

	double SLVSOF;
	double SLVSOFD;

	double SLVNFRQ;
	double SLVNWID;
	double SLVNATT;

	double SLVB0NF;
	double SLVB0DF;
	double SLVB0ND;
	double SLVB0DD;

	double SLVB1NF;
	double SLVB1DF;
	double SLVB1ND;
	double SLVB1DD;

	double XVEL;
	double EFAC;
	double SLVRAT;
	double SLAFF;

	INT32 MFLAGS;
	INT32 MFLAGSX;

	FILTER_ROUTING FilterRouting;
//	FILTER_ROUTING* FilterRoutingPtr;
} SERVO_PARAMETERS;

typedef struct _FRF_CALCULATE_LOOP_DATA
{
	// Plant parameters
	FRD* plant; // P
	FRD* plantVelocityToPosition; // Plant from Velocity to Position. 1/s for a rigid body. Some Transfer function in dual loop systems

	SERVO_PARAMETERS* servoParameters;
	FRF_DATA_TYPE dataType;
	FRF_LOOP_TYPE measureLoopType;
	FRF_LOOP_TYPE targetLoopType;
} FRF_CALCULATE_LOOP_DATA;

typedef struct _FRF_CALCULATE_SLVRAT_DATA
{
	FRD* plantVelocityToPosition;
	double startFrequencyHz;
	double endFrequencyHz;
} FRF_CALCULATE_SLVRAT_DATA;

typedef struct _JITTER_ANALYSIS_INPUT
{
	// Jitter array
	double* jitter;
	unsigned int jitterLength;

	unsigned int samplingFrequencyHz;

	double desiredFrequencyResolutionHz;

	// Parameters for frequency bands cumulative analysis
	double* jitterFrequencyBandsCumulativeAmplitudeRMSthreshold;
	double* frequencyBandsHz;
	unsigned int frequencyBandsHzLength;

	// Window type. Applied to a signal in time domain
	FRF_WINDOW_TYPE windowType;
} JITTER_ANALYSIS_INPUT;

typedef struct _JITTER_ANALYSIS_OUTPUT
{
	//following three arrays have the same length defined in frequencyLength
	double* jitterAmplitudeRMS;
	double* jitterCumulativeAmplitudeRMS;
	double* frequencyHz;
	unsigned int frequencyLength;

	// Result of frequency bands cumulative analysis
	double* jitterFrequencyBandsCumulativeAmplitudeRMS;
	double* frequencyBandsHz;
	unsigned int frequencyBandsHzLength;
	int jitterFrequencyBandsResultBool;

	double jitterRMS;
	double jitterAmplitudePeak2Peak;
} JITTER_ANALYSIS_OUTPUT;

typedef struct _FRF_CROSS_COUPLING_INPUT
{
	int* axes;
	int axesLength;
	FRF_CROSS_COUPLING_TYPE crossCouplingType;
	FRF_EXCITATION_TYPE excitationType;
	FRF_CHIRP_TYPE chirpType;
	FRF_WINDOW_TYPE windowType;
	FRF_FREQUENCY_DISTRIBUTION_TYPE frequencyDistributionType;
	FRF_OVERLAP overlap;
	double startFreqHz;
	double endFreqHz;
	int freqPerDec;
	double* excitationAmplitudePercentIp;

	int numberOfRepetitions;
	double highResolutionStart;
	int highResolutionFreqPerDec;

	double durationSec; // applicable for Chirp and White Noise options

	// User defined excitation signal
	double* userDefinedExcitationSignal;
	int userDefinedExcitationSignalLength;

	char* customOutputName;
	int customOutputNode;

	char* customInputName;
	int customInputNode;

	double customInputScale;
	double customInputOffset;
} FRF_CROSS_COUPLING_INPUT;

typedef struct _FRF_CROSS_COUPLING_OUTPUT
{
	FRD* plant; // P plant matrix
	FRD* controller; //C controller matix
	FRD* characteristicPolynomial; //L - not a matrix
	FRD* closedLoop; //T matrix
	FRD* sensitivity; //S matix
	FRD* coherencePS; //matrix
	FRD* coherenceS; //matrix
	FRD* RGA; // Relative gain array matrix
	FRF_STABILITY_MARGINS* stabilityMargins;
	FRF_CROSS_COUPLING_TYPE crossCouplingType;
	double* excitationAmplitude;
	int matrixSize; //reflects column count f the square P, C, T, S and coherence matrices
} FRF_CROSS_COUPLING_OUTPUT;

// Structure is used for non-waiting calls of the library functions
typedef struct
{
	HANDLE Event;				//signal event
	int	   Ret;					//code of return
} ACSC_WAITBLOCK, *LP_ACSC_WAITBLOCK, WAITBLOCK, *LP_WAITBLOCK;

//Defines for COMLib 6.5
#define ACSC_SYNCHRONOUS		(LP_ACSC_WAITBLOCK)NULL		// Synchronous call
#define ACSC_IGNORE				(LP_ACSC_WAITBLOCK)-1		// Ignore result of Asyncronous call
#define ACSC_ASYNCHRONOUS		(LP_ACSC_WAITBLOCK)-2		// Asynchronous call

typedef enum
{
	Default_Type   = 0,
	String_Type    = 0,
	Buffer_Type    = 1,
	Integer_Type   = 2,
	Real_Type      = 3,
	Scalar_Type    = 4,
	Vector_Type    = 5,
	Matrix_Type    = 6,
	Typeless_Type  = 7,
	Binary_Type    = 8,
	ACSPL_String_Type = 9,
	Struct_Type = 10
} ACSC_RETURN_TYPE;

// Structure defines a physical location of PCI card
typedef struct
{
	unsigned int BusNumber;		//PCI physical bus number of card
	unsigned int SlotNumber;	//PCI physical slot number of card
	unsigned int Function;		//PCI function of card
} ACSC_PCI_SLOT, *LP_ACSC_PCI_SLOT, PCI_SLOT, *LP_PCI_SLOT;

typedef enum
{
	Minimum,
	Medium,
	Maximum
} ACSC_LOG_DETALIZATION_LEVEL;

typedef enum {
	Compact,
	Formatted,
	Full
} ACSC_LOG_DATA_PRESENTATION;

//This struct describes single UMD connection
typedef struct
{
	char Application[100];				// Application Name
	HANDLE Handle;						// Channel's Handle
	DWORD ProcessId;
} ACSC_CONNECTION_DESC;
typedef enum
{
	ACSC_NOT_CONNECTED = 0,
	ACSC_SERIAL = 1,
	ACSC_PCI = 2,
	ACSC_ETHERNET = 3,
	ACSC_DIRECT = 4
} ACSC_CONNECTION_TYPE;
typedef struct
{
	ACSC_CONNECTION_TYPE Type;
	int SerialPort;
	int SerialBaudRate;
	int PCISlot;
	int EthernetProtocol;
	char EthernetIP[100];
	int EthernetPort;
} ACSC_CONNECTION_INFO;


//This structures used for Application Saver / Loader functions
typedef struct
{
	int length;
	char* string;
} ACSC_APPSL_STRING;

typedef enum
{
	ACSC_ADJ,
	ACSC_SP,
	ACSC_ACSPL,
	ACSC_PAR,
	ACSC_USER,
	ACSC_PROT_STRING,
	ACSC_PROT2_STRING
} ACSC_APPSL_FILETYPE;

typedef struct
{
	ACSC_APPSL_FILETYPE type;			// section type
	ACSC_APPSL_STRING filename;			// section file name
	ACSC_APPSL_STRING description;		// section description
	unsigned int size;					// data size
	unsigned int offset;				// offset in the file data section
	unsigned int CRC;					// data CRC
	int inuse;							// selected for save/load
	int error;							// error code
	char* data;							// data as is
} ACSC_APPSL_SECTION;

// Atrriburte key-value pair structure
typedef struct
{
	ACSC_APPSL_STRING key;				// attribute's key (name)
	ACSC_APPSL_STRING value;			// key data
} ACSC_APPSL_ATTRIBUTE;

// Data file structure
// Describe data file header, attributes array and file sections array
typedef struct
{
	ACSC_APPSL_STRING filename;			// file name
	ACSC_APPSL_STRING description;		// file description
	int isNewFile;                      // 1 - if writing new file, 0 - if adding
	int ErrCode;						// Error code from controller
	unsigned int attributes_num;	    // attributes count
	ACSC_APPSL_ATTRIBUTE* attributes;   // attributes array
	unsigned int sections_num;		    // sections count
	ACSC_APPSL_SECTION* sections;	    // sections array
} ACSC_APPSL_INFO;

// Structure of history and message buffer
// Please never change data of this structure!
struct ACSC_HISTORYBUFFER
{
	int    Max;							//buffer size
	int    Cur;							//number of bytes currently stored in the buffer
	int    Ring;						//circular index in the buffer
	char*  Buf;							//pointer to buffer
};



// struct for controller info
//for acsc_GetEthernetCardsExt function
typedef struct _ACSC_CONTROLLER_INFO
{
	struct in_addr IpAddress;				// controller ip adrress
	char SerialNumber[100];					// controller serial number
	char PartNumber[100];					// controller part number
	char Version[100];						// controller firmware version
} ACSC_CONTROLLER_INFO;

typedef struct ACSC_HISTORYBUFFER* LP_ACSC_HISTORYBUFFER;

typedef struct _AXMASK_EXT
{
	UnsignedInt64 AXMASK64; //0-63 axes
	UnsignedInt64 AXMASK128; //64-127
	UnsignedInt64 Reserved1;
	UnsignedInt64 Reserved2;

} AXMASK_EXT;

typedef int (WINAPI *ACSC_INTR_CALLBACK_FUNC)(int Param);
typedef int (WINAPI *ACSC_INTR_CALLBACK_FUNC_EXT)(int Param, void* CardContext);
typedef int (WINAPI *ACSC_USER_CONDITION_FUNC)(HANDLE Handle);
#define ACSC_DUMMY_CALLBACK (ACSC_INTR_CALLBACK_FUNC)-1
#define ACSC_DUMMY_CALLBACK_EXT (ACSC_INTR_CALLBACK_FUNC_EXT)-1


//////////////////////////////////////////////////////////////////////////////////////////////////
typedef int (WINAPI *ACSC_USER_CALLBACK_FUNCTION)(UnsignedInt64 Param, void* CardContext);
#define ACSC_DUMMY_CALLBACK_FUNCTION (ACSC_USER_CALLBACK_FUNCTION)-1
//////////////////////////////////////////////////////////////////////////////////////////////////

typedef int (WINAPI* ACSC_USER_CALLBACK_FUNCTION_EXT)(AXMASK_EXT Mask, void* CardContext);
#define ACSC_DUMMY_CALLBACK_FUNCTION_EXT (ACSC_USER_CALLBACK_FUNCTION_EXT)-1
 
#if defined(__cplusplus)
extern "C" {
#endif


	//////////////////////////////////////////////////////////////////////////////////////////////////
	// If you want to load ACSC.dll dynamically at runtime, 
	// define ACSC_RUNTIME_DYNAMIC_LINKING in your project before including this file
	// Otherwise load-time dynamic linking is implied
	//////////////////////////////////////////////////////////////////////////////////////////////////
#if !defined (ACSC_RUNTIME_DYNAMIC_LINKING)
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates communication via serial port
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommSerial(int Channel, int Rate);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates communication via Ethernet
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommEthernet(char* Address, int Port);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function opens communication with the controller via Ethernet using TCP protocol.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommEthernetTCP(char* Address, int Port);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function opens communication with the controller via Ethernet using the UDP protocol.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommEthernetUDP(char* Address, int Port);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates direct communication with simulator
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommDirect();

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The functions collects IP addresses of SPiiPlus cards connected to the local segment
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ acsc_GetEthernetCards(struct in_addr* IPaddresses, int Max, int* Ncontrollers, unsigned long BroadcastAddress);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The functions collects IP addresses,serial number and part number of SPiiPlus cards connected to the local segment
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ acsc_GetEthernetCardsExt(ACSC_CONTROLLER_INFO* ControllerInfo, unsigned long ControllerInfoSize, int Max, int* Ncontrollers, unsigned long BroadcastAddress);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates communication via PCI device driver
	//////////////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommPCI(int SlotNumber);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a PCI bus information for the PCI cards installed
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetPCICards(ACSC_PCI_SLOT* Cards, int Count, int* ObtainedCards);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function closes communication (for all kinds of communications)
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseComm(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sends message
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Send(HANDLE Handle, char* Buf, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function receives message
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Receive(HANDLE Handle, char* Buf, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides transaction: sends request and receives reply
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_Transaction(HANDLE Handle, char* OutBuf, int OutCount, char* InBuf, int InCount, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sends a command to the controller and analyzes the controller response.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Command(HANDLE Handle, char* OutBuf, int OutCount, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for completion of asynchronous call and retrieves a data.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitForAsyncCall(HANDLE Handle, void* Buf, int* Received, ACSC_WAITBLOCK* Wait, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function cancels any asynchronous (non-waiting) call
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CancelOperation(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the last error code
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// function of the new library
	int	_ACSCLIB_ WINAPI acsc_GetLastError();

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the explanation of an error code. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_GetErrorString(HANDLE Handle, int ErrorCode, char* ErrorStr, int Count, int* Received);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets communication call delay
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetQueueOverflowTimeout(HANDLE Handle, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves communication call delay 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetQueueOverflowTimeout(HANDLE Handle);
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets communication timeout
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetTimeout(HANDLE Handle, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves communication timeout
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetTimeout(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves default communication timeout
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetDefaultTimeout(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the number of iterations of one transaction
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetIterations(HANDLE Handle, int Iterations);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets communication options
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetCommOptions(HANDLE Handle, unsigned int Options);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves communication options
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetCommOptions(HANDLE Handle, unsigned int* Options);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function Clears breakpoints
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ClearBreakpoints(HANDLE handle, int Buffer, int line, ACSC_WAITBLOCK* wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function Sets a breakpoint
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetBreakpoint(HANDLE handle, int Buffer, int line, ACSC_WAITBLOCK* wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves breakpoints of a buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetBreakpointsList(HANDLE handle, int Buffer, int* ArrayIn, int ArraySize, int* replySize, ACSC_WAITBLOCK* wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves ACSC Library version
	//////////////////////////////////////////////////////////////////////////////////////////////////
	unsigned int _ACSCLIB_ WINAPI acsc_GetLibraryVersion();

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSPL+ program to the specified program buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadBuffer(HANDLE Handle, int Buffer, char* Text, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSPL+ program to the specified program buffer.
	// Service lines are ignored.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadBufferIgnoreServiceLines(HANDLE Handle, int Buffer, char* Text, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSPL+ programs to the specified program buffers.
	// From *.prg file
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadBuffersFromFile(HANDLE Handle, char* Filename, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function appends one or more ACSPL+ lines to the program in the specified program buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AppendBuffer(HANDLE Handle, int Buffer, char* Text, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function downloads text to a program buffer. The function is similar to the function acsc_AppendBuffer() 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DownloadBuffer(HANDLE Handle, int Buffer, char* Text, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function uploads text from a program buffer 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_UploadBuffer(HANDLE Handle, int Buffer, int Offset, char* Text, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function deletes the specified ACSPL+ program lines in the specified program buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ClearBuffer(HANDLE Handle, int Buffer, int FromLine, int ToLine, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function compiles ACSPL+ program in the specified program buffer(s).
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CompileBuffer(HANDLE Handle, int Buffer, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function starts up ACSPL+ program in the specified program buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_RunBuffer(HANDLE Handle, int Buffer, char* Label, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function stops ACSPL+ program in the specified program buffer(s).
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StopBuffer(HANDLE Handle, int Buffer, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function suspends ACSPL+ program in the specified program buffer(s).
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SuspendBuffer(HANDLE Handle, int Buffer, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from integer variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadInteger(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, int* Values, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to integer variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteInteger(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, int* Values, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from real variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadReal(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, double* Values, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to real variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteReal(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, double* Values, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from String variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadString(HANDLE Handle, int NBuf, const char* Var, int From1, int To1, int From2, int To2, char* Strings, unsigned short StringSize, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to String variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteString(HANDLE Handle, int NBuf, const char* Var, int From1, int To1, int From2, int To2, char* Strings, unsigned short StringSize, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from Struct variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadStruct(HANDLE Handle, int NBuf, const char* Var, int From1, int To1, int From2, int To2, void* Values, int ValuesSize, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to Struct variable
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteStruct(HANDLE Handle, int NBuf, const char* Var, int From1, int To1, int From2, int To2, void* Values, int ValuesSize, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function captures communication
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CaptureComm(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function releases communication
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReleaseComm(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates history buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	LP_ACSC_HISTORYBUFFER _ACSCLIB_ WINAPI acsc_OpenHistoryBuffer(HANDLE Handle, int Size);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function closes history buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseHistoryBuffer(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the contents of the history buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetHistory(HANDLE Handle, char* Buf, int Count, int* Received, BOOL bClear);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates unsolicited messages buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	LP_ACSC_HISTORYBUFFER _ACSCLIB_ WINAPI acsc_OpenMessageBuffer(HANDLE Handle, int Size);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function closes unsolicited messages buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseMessageBuffer(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves all stored unsolicited messages from buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetMessage(HANDLE Handle, char* Buf, int Count, int* Received, BOOL bClear);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a single unsolicited message or exits by timeout
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSingleMessage(HANDLE Handle, char* Buf, int Count, int* Received, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function opens a log file.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_OpenLogFile(HANDLE Handle, char* FileName);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function opens the SPiiPlusSC log file.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_OpenSCLogFile(HANDLE Handle, char* FileName);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function closes logfile. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseLogFile(HANDLE Handle);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function closes the SPiiPlusSC log file.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseSCLogFile(HANDLE Handle);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes to logfile. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteLogFile(HANDLE Handle, char* Buf, int Count);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes to the SPiiPlusSC log file. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteSCLogFile(HANDLE Handle, char* Buf, int Count);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function allows flushing the SPiiPlus UMD (User Mode Driver) internal binary buffer to a
	// specified text file from the C Library application.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FlushLogFile(char* Filename);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function enables flushing the SPiiPlusSC internal binary buffer to a specified text file from the C
	// Library application.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FlushSCLogFile(char* Filename, BOOL bClear);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the data of firmware log
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetLogData(HANDLE Handle, char* Buf, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a value of motion velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetVelocity(HANDLE Handle, int Axis, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a value of motion velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetVelocity(HANDLE Handle, int Axis, double* Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a value of motion acceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetAcceleration(HANDLE Handle, int Axis, double Acceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a value of motion acceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetAcceleration(HANDLE Handle, int Axis, double* Acceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a value of motion deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetDeceleration(HANDLE Handle, int Axis, double Deceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a value of motion deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetDeceleration(HANDLE Handle, int Axis, double* Deceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a value of motion jerk.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetJerk(HANDLE Handle, int Axis, double Jerk, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a value of motion jerk.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetJerk(HANDLE Handle, int Axis, double* Jerk, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a value of kill deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetKillDeceleration(HANDLE Handle, int Axis, double KillDeceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a value of kill deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetKillDeceleration(HANDLE Handle, int Axis, double* KillDeceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides on-the-fly change a value of motion velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetVelocityImm(HANDLE Handle, int Axis, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides on-the-fly change a value of motion acceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetAccelerationImm(HANDLE Handle, int Axis, double Acceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides on-the-fly change a value of motion deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetDecelerationImm(HANDLE Handle, int Axis, double Deceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides on-the-fly change a value of motion jerk.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetJerkImm(HANDLE Handle, int Axis, double Jerk, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides on-the-fly change a value of kill deceleration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetKillDecelerationImm(HANDLE Handle, int Axis, double KillDeceleration, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function assigns a current value of target position for several axes.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetTargetPositionM(HANDLE Handle, int* Axes, double* TargetPositions, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function assigns a current value of target position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetTargetPosition(HANDLE Handle, int Axis, double TargetPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a current value of motor feedback position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetTargetPosition(HANDLE Handle, int Axis, double* TargetPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function assigns a current value of target position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetFPosition(HANDLE Handle, int Axis, double FPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a current value of motor feedback position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetFPosition(HANDLE Handle, int Axis, double* FPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function assigns a current value of reference position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetRPosition(HANDLE Handle, int Axis, double RPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a current value of reference position.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetRPosition(HANDLE Handle, int Axis, double* RPosition, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a current value of motor feedback velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetFVelocity(HANDLE Handle, int Axis, double* FVelocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves a current value of reference velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetRVelocity(HANDLE Handle, int Axis, double* RVelocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function activates a motor.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Enable(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function activates several motors.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_EnableM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function shuts off a motor.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Disable(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function shuts off several motors.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DisableM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function shuts off all motors.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DisableAll(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function performs commutation to brushless motor.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Commut(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function performs commutation to brushless motor. Extended parameters
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CommutExt(HANDLE Handle, int Axis, float Current, int Settle, int Slope, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function creates a coordinate system for multi-axis motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Group(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function breaks down an axis group created before by the acsc_Group function.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Split(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function breaks down all axis groups created before by the acsc_Group function.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SplitAll(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function starts up a motion that is waiting in the specified motion queue.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Go(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function synchronously starts up several motions 
	// that are waiting in the specified motion queues. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GoM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates a motion using the full deceleration profile.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Halt(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates several motions using the full deceleration profile.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_HaltM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates a motion using reduced deceleration profile.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Kill(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates several motions using reduced deceleration profile.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_KillM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates all currently executed motions.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_KillAll(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates a motion immediately and 
	// provides a smooth transition to the next motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Break(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates several motions immediately and 
	// provides a smooth transition to the next motions.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BreakM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis motion to the specified point.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ToPoint(HANDLE Handle, int Flags, int Axis, double Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis motion to the specified point
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ToPointM(HANDLE Handle, int Flags, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis motion to the specified point 
	// using the specified velocity or end velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtToPoint(HANDLE Handle, int Flags, int Axis, double Point, double Velocity, double EndVelocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis motion to the specified point 
	// using the specified velocity or end velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtToPointM(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis track motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Track(HANDLE Handle, int Flags, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multile-axis track motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_TrackM(HANDLE Handle, int Flags, int* Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function clears the current faults and results of previous faults stored in the MERR variable.
	// For single axis
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FaultClear(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function clears the current faults and results of previous faults stored in the MERR variable.
	// For multiple axes
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FaultClearM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads number of available axes
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetAxesCount(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads number of available ACSPL+ programming buffers
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetBuffersCount(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads index of D-Buffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetDBufferIndex(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads system information
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SysInfo(HANDLE Handle, int Key, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes system configuration
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetConf(HANDLE Handle, int Key, int Index, double Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads system configuration
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetConf(HANDLE Handle, int Key, int Index, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes system configuration-obsolete
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Setconf(HANDLE Handle, int Key, int Index, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads system configuration-obsolete
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Getconf(HANDLE Handle, int Key, int Index, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis jog motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Jog(HANDLE Handle, int Flags, int Axis, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis jog motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_JogM(HANDLE Handle, int Flags, int* Axes, int* Direction, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates calculating of master value for an axis.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetMaster(HANDLE Handle, int Axis, char* Formula, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a master-slave motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Slave(HANDLE Handle, int Flags, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a master-slave motion with a limited following area.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SlaveStalled(HANDLE Handle, int Flags, int Axis, double Left, double Right, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis multi-point motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_MultiPoint(HANDLE Handle, int Flags, int Axis, double Dwell, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis multi-point motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_MultiPointM(HANDLE Handle, int Flags, int* Axes, double Dwell, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines a motion profile using the MotionBoost Feature.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BoostedPointToPointMotion(HANDLE Handle, int Flags, int* Axes, double* point, double Velocity, double FinalVelocity, double Time, double FixedTime, double MotionDelay, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides for positioning to specific target,
	// The motion profile is optimized to pass on a rounded path near the breaking point, minimizing changes in speedand direction that would cause unwanted vibrations in the system.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SmoothPointToPointMotion(HANDLE Handle, int Flags, int* Axes, double* point, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// If the axis is moving when the command is issued, the controller creates the motion and inserts it into the axis motion queue.
	// The motion waits in the queue until all motions before it finish, and only then starts.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SmoothTransitionPointToPointMotion(HANDLE Handle, int Flags, int* Axes, double* point, double Velocity, double MotionDelay, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a single-axis spline motion. 
	// The motion follows an arbitrary path defined by a set of points.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Spline(HANDLE Handle, int Flags, int Axis, double Period, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis spline motion. 
	// The motion follows an arbitrary path defined by a set of points.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SplineM(HANDLE Handle, int Flags, int* Axes, double Period, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Segment(HANDLE Handle, int Flags, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentedMotion(HANDLE Handle, int Flags, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis extended segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtendedSegmentedMotion(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double StarvationMargin, char* Segments, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis extended segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtendedSegmentedMotionExt(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double CurveVelocity, double Deviation, double Radius, double MaxLength, double StarvationMargin, char* Segments, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis extended segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtendedSegmentedMotionV2(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double CurveVelocity, double Deviation, double Radius, double MaxLength, double StarvationMargin, char* Segments, int ExtLoopType, double MinSegmentLength, double MaxAllowedDeviation, int OutputIndex, int BitNumber, int Polarity, double MotionDelay, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates a multi-axis blended segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BlendedSegmentMotion(HANDLE Handle, int Flags, int* Axes, double* Point, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a blended segmented motion
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BlendedLine(HANDLE Handle, int Flags, int* Axes, double* Point, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point and the direction of rotation.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BlendedArc1(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_BlendedArc2(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Line(HANDLE Handle, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a segmented motion and specifies a motion velocity.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtLine(HANDLE Handle, int* Axes, double* Point, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a segmented motion
	// Specifies motion velocity, end motion velocity, and user variables parameters
	// -- Obsolete --
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentLine(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a segmented motion
	// Specifies motion velocity, end motion velocity, and user variables parameters
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentLineExt(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a linear segment to a segmented motion
	// Specifies motion velocity, end motion velocity, and user variables parameters
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentLineV2(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, int ExtLoopType, double MinSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point and the direction of rotation.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Arc1(HANDLE Handle, int* Axes, double* Center, double* FinalPoint, int Rotation, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point, direction of rotation and 
	// the vector velocity for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtArc1(HANDLE Handle, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point, direction of rotation, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc1(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point, direction of rotation, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc1Ext(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point, direction of rotation, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtendedSegmentArc1(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, coordinates of the final point, direction of rotation, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc1V2(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, int ExtLoopType, double MinSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);


	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point and rotation angle.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Arc2(HANDLE Handle, int* Axes, double* Center, double Angle, ACSC_WAITBLOCK* Wait);


	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle and the vector velocity for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtArc2(HANDLE Handle, int* Axes, double* Center, double Angle, double Velocity, ACSC_WAITBLOCK* Wait);


	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc2(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc2Ext(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle, final point for secondary axes, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtendedSegmentArc2(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double* FinalPoint, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an arc segment to a segmented motion and specifies the coordinates 
	// of center point, rotation angle, final point for secondary axes, vector velocity,
	// end motion velocity, and user variables parameters for the current segment.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SegmentArc2V2(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double* FinalPoint, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, int ExtLoopType, double MinSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function Create NURBS motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_NurbsMotion(HANDLE Handle, int Flags, int* Axes, double Velocity, double ExceptionAngle, double ExceptionLength, double MotionDelay, char* Segments, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function Add next control point to Nurbs MG.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_NurbsPoints(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double Required_vel, double Knot, double Weight, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function Initiate a Path Smoothing Motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SmoothPathMotion(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double ExceptionAngle, double ExceptionLength, double MotionDelay, char* Segments, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function add a new control point to SPath MG.
	//////////////////////////////////////////////////////////////////////////////////////////////////

	int _ACSCLIB_ WINAPI acsc_SmoothPathSegment(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double Required_vel, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function provides a smooth transition between two segments of segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Stopper(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets a projection matrix for segmented motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Projection(HANDLE Handle, int* Axes, char* Matrix, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a single-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPoint(HANDLE Handle, int Axis, double Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a multi-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPointM(HANDLE Handle, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a single-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtAddPoint(HANDLE Handle, int Axis, double Point, double Rate, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a multi-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ExtAddPointM(HANDLE Handle, int* Axes, double* Point, double Rate, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a single-axis PVT spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPVTPoint(HANDLE Handle, int Axis, double Point, double Velocity, double TimeInterval, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a multi-axis PVT spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPVTPointM(HANDLE Handle, int* Axis, double* Point, double* Velocity, double TimeInterval, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a single-axis PV spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPVPoint(HANDLE Handle, int Axis, double Point, double Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds a point to a multi-axis PV spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddPVPointM(HANDLE Handle, int* Axis, double* Point, double* Velocity, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an array of points to a single-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddMPoint(HANDLE Handle, int Axis, char* Name, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function adds an array of points to a multi-axis multi-point or spline motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AddMPointM(HANDLE Handle, int* Axes, char* Name, int Count, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function informs the controller, that no more points will be specified for the current single-axis motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_EndSequence(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function informs the controller, that no more points or segments will be specified for the current multi-axis motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_EndSequenceM(HANDLE Handle, int* Axes, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Collect(HANDLE Handle, int Flags, char* Array, int NSample, int Period, char** Vars, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CollectB(HANDLE Handle, int Flags, char* Array, int NSample, int Period, char* Vars, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DataCollection(HANDLE Handle, int Flags, int Axis, char* Array, int NSample, int Period, char* Vars, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DataCollectionExt(HANDLE Handle, int Flags, int Axis, char* Array, int NSample, double Period, char* Vars, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StopCollect(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates Servo Processor Data Collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SPDataCollectionStop(HANDLE Handle, int ServoProcessorIndex, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function performs Servo Processor Data Collection for the specified Servo Processor 
	// variables with a constant maximum sampling rate of 20kHz.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SPDataCollectionStart(HANDLE Handle, int Flags, const char* Array, int NSample, double Period, int ServoProcessorIndex, int ServoProcessorAddress1, int ServoProcessorAddress2, int ServoProcessorAddress3, int ServoProcessorAddress4, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads address of the variable in the Servo Processor memory that is used for
	// Servo_Processor_Data_Collection in EtherCAT network.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSPAddress(HANDLE Handle, int Flags, int ServoProcessorIndex, const char* ServoProcessorVariable, int* ServoProcessorAddress);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current motor state.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetMotorState(HANDLE Handle, int Axis, int* State, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current axis state.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetAxisState(HANDLE Handle, int Axis, int* State, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the index and mark variables.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetIndexState(HANDLE Handle, int Axis, int* State, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function resets the specified bits of the index/mark state.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ResetIndexState(HANDLE Handle, int Axis, int Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the program buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetProgramState(HANDLE Handle, int Buffer, int* State, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified digital input.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetInput(HANDLE Handle, int Port, int Bit, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified digital input port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetInputPort(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified digital output.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetOutput(HANDLE Handle, int Port, int Bit, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified digital output port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetOutputPort(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the specified digital output to the specified value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetOutput(HANDLE Handle, int Port, int Bit, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the specified digital output port to the specified value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetOutputPort(HANDLE Handle, int Port, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current numerical value of the specified analog inputs.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetAnalogInput(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);
	int _ACSCLIB_ WINAPI acsc_GetAnalogInputNT(HANDLE Handle, int Port, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current numerical value of  the specified analog outputs.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetAnalogOutput(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);
	int _ACSCLIB_ WINAPI acsc_GetAnalogOutputNT(HANDLE Handle, int Port, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes the current numerical value to the specified analog outputs.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetAnalogOutput(HANDLE Handle, int Port, int Value, ACSC_WAITBLOCK* Wait);
	int _ACSCLIB_ WINAPI acsc_SetAnalogOutputNT(HANDLE Handle, int Port, double Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified extended input.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetExtInput(HANDLE Handle, int Port, int Bit, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified extended input port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetExtInputPort(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified extended output.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetExtOutput(HANDLE Handle, int Port, int Bit, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified extended output port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetExtOutputPort(HANDLE Handle, int Port, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the specified extended output to the specified value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetExtOutput(HANDLE Handle, int Port, int Bit, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the specified extended output port to the specified value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetExtOutputPort(HANDLE Handle, int Port, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the set of bits, that indicate the motor or system faults.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetFault(HANDLE Handle, int Axis, int* Fault, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the mask, that defines which controller faults are examined and processed.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetFaultMask(HANDLE Handle, int Axis, int* Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the mask, that enables/disables the examination and processing of the controller faults.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetFaultMask(HANDLE Handle, int Axis, int Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function enables the specified motor or system fault.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_EnableFault(HANDLE Handle, int Axis, int Fault, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function disables the specified motor or system fault.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DisableFault(HANDLE Handle, int Axis, int Fault, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the mask, that defines for which motor or system faults the controller provides default response.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetResponseMask(HANDLE Handle, int Axis, int* Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the mask, that defines for which motor or system faults the controller provides default response.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetResponseMask(HANDLE Handle, int Axis, int Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function enables the response to the specified motor or system fault.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_EnableResponse(HANDLE Handle, int Axis, int Response, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function disables the default response to the specified motor or system fault.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DisableResponse(HANDLE Handle, int Axis, int Response, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified safety input.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSafetyInput(HANDLE Handle, int Axis, int Input, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the current state of  the specified safety input port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSafetyInputPort(HANDLE Handle, int Axis, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the set of bits that define inversion for the specified safety input port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSafetyInputPortInv(HANDLE Handle, int Axis, int* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the set of bits that define inversion for the specified safety input port.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetSafetyInputPortInv(HANDLE Handle, int Axis, int Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the end of a motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitMotionEnd(HANDLE Handle, int Axis, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the logical end of a motion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitLogicalMotionEnd(HANDLE Handle, int Axis, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the end of data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitCollectEnd(HANDLE Handle, int Timeout); //Deprecated

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the end of data collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitCollectEndExt(HANDLE Handle, int Timeout, int Axis);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the end of Servo Processor Data Collection.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitSPDataCollectionEnd(HANDLE Handle, int Timeout, int ServoProcessorIndex);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the program termination in the specified buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitProgramEnd(HANDLE Handle, int Buffer, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the specified state of the specified motor.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitMotorEnabled(HANDLE Handle, int Axis, int State, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the specified state of the specified motor.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitMotorCommutated(HANDLE Handle, int Axis, int State, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the specified state of digital input.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitInput(HANDLE Handle, int Port, int Bit, int State, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for user-defined condition.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitUserCondition(HANDLE Handle, ACSC_USER_CONDITION_FUNC UserCondition, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function waits for the readiness of the PEG engine.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitPegReadyNT(HANDLE Handle, int Axis, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function installs a user-defined callback function for the specified interrupt condition
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetCallback(HANDLE Handle, ACSC_INTR_CALLBACK_FUNC Callback, int Interrupt);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function installs a user-defined callback function for the specified interrupt condition
	// with specified card context
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetCallbackExt(HANDLE Handle, ACSC_INTR_CALLBACK_FUNC_EXT Callback, void* CardContext, int Interrupt);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function installs a user-defined callback function for the specified interrupt condition
	// with specified card context
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_InstallCallback(HANDLE Handle, ACSC_USER_CALLBACK_FUNCTION Callback, void* CardContext, int Interrupt);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function installs a user-defined callback function for the specified interrupt condition
	// with specified card context, supports more than 64 axes
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_InstallCallbackExt(HANDLE Handle, ACSC_USER_CALLBACK_FUNCTION_EXT Callback, void* CardContext, int Interrupt);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the priority for all callback threads. 
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetCallbackPriority(HANDLE Handle, int Priority);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the mask for specified interrupt
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetInterruptMask(HANDLE Handle, int Interrupt, unsigned int Mask);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the mask for specified interrupt, supports more than 64 axes
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetCallbackMaskExt(HANDLE Handle, int Interrupt, AXMASK_EXT Mask);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function sets the mask for specified callback
	//////////////////////////////////////////////////////////////////////////////////////////////////

	int _ACSCLIB_ WINAPI acsc_SetCallbackMask(HANDLE Handle, int Interrupt, UnsignedInt64 Mask);
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the mask for specified interrupt
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetInterruptMask(HANDLE Handle, int Interrupt, unsigned int* Mask);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the mask for specified callback, supports more than 64 axes
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetCallbackMask(HANDLE Handle, int Interrupt, UnsignedInt64* Mask);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the mask for specified callback (up to 128 axes)
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetCallbackMaskExt(HANDLE Handle, int Interrupt, AXMASK_EXT* Mask);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function creates the persistent global variable.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DeclareVariable(HANDLE Handle, int Type, char* Name, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function deletes all persistent global variables.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ClearVariables(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the firmware version of the controller.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetFirmwareVersion(HANDLE Handle, char* Version, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the controller serial number.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSerialNumber(HANDLE Handle, char* SerialNumber, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates a motion using reduced deceleration profile with Reason of kill.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_KillExt(HANDLE Handle, int Axis, int Reason, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function disables motor and sets Reason of disable.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DisableExt(HANDLE Handle, int Axis, int Reason, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the reason why the motor was disabled.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetMotorError(HANDLE Handle, int Axis, int* Error, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the termination code of the last executed motion of the specified axis.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetMotionError(HANDLE Handle, int Axis, int* Error, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the error code of the last program error encountered in the specified buffer.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetProgramError(HANDLE Handle, int Buffer, int* Error, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// Those functions access directly DPRAM via PCI bus only
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadDPRAMInteger(HANDLE Handle, int index, int* result);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes 32-bit integer to the DPRAM.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteDPRAMInteger(HANDLE Handle, int index, int data);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads 64-bit Real from the DPRAM.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadDPRAMReal(HANDLE Handle, int index, double* result);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes 64-bit Real to the DPRAM.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteDPRAMReal(HANDLE Handle, int index, double data);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads the address of shared memory variable.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetSharedMemoryAddress(HANDLE Handle, int NBuf, char* Var, unsigned int* Address, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from a real shared memory variable.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadSharedMemoryReal(HANDLE Handle, unsigned int Address, int From1, int To1, int From2, int To2, double* Values);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reads value(s) from an integer shared memory variable.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadSharedMemoryInteger(HANDLE Handle, unsigned int Address, int From1, int To1, int From2, int To2, int* Values);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to the real shared memory variable.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteSharedMemoryReal(HANDLE Handle, unsigned int Address, int From1, int To1, int From2, int To2, double* Values);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// The function writes value(s) to the integer shared memory variable.
	////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteSharedMemoryInteger(HANDLE Handle, unsigned int Address, int From1, int To1, int From2, int To2, int* Values);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// This function defines communication server IP address
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetServer(char* IP);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// This function defines communication server IP address and Port
	/////////////////////////////////////////////////////////////////////////////////////////////////////	
	int _ACSCLIB_ WINAPI acsc_SetServerExt(char* IP, int Port);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines the User Mode Driver (UMD) host IP address, and port along with passing login
	// data.
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetServerExtLogin(char* IP, int Port, char* Username, char* Password, char* Domain);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// *** OBSOLETE ***
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegI(HANDLE Handle, int Flags, int Axis, double Width, int FirstPoint, int Interval, int LastPoint, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// *** OBSOLETE ***
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegR(HANDLE Handle, int Flags, int Axis, double Width, char* PointArray, char* StateArray, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates incremental PEG. Incremental PEG function is defined by first point, last point
	// and the interval.
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegInc(HANDLE Handle, int Flags, int Axis, double Width, double FirstPoint, double Interval, double LastPoint, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates random PEG. Random PEG function specifies an array of points where
	// position - based events should be generated.
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegRandom(HANDLE Handle, int Flags, int Axis, double Width, char* PointArray, char* StateArray, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function defines whether a digital output is allocated to the corresponding bit of the OUT array
	// (for general purpose use) or allocated for PEG function use.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AssignPins(HANDLE Handle, int Axis, unsigned short Mask, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function stops PEG.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StopPeg(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used for engine-to-encoder assignment as well as for the additional digital outputs
	// assignment for use as PEG stateand PEG pulse outputs.As of V3.12, a new flag is available calling for
	// fast loading of Random PEG arrays
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AssignPegNT(HANDLE Handle, int Axis, int EngToEncBitCode, int GpOutsBitCode, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used for engine-to-encoder assignment as well as for the additional digital outputs
	// assignment for use as PEG stateand PEG pulse outputs.As of V3.12, a new flag is available calling for
	// fast loading of Random PEG arrays
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AssignPegNTV2(HANDLE Handle, int Flags, int Axis, int EngToEncBitCode, int GpOutsBitCode, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for setting output pins assignment and mapping between FGP_OUT signals to
	// the bits of the ACSPL + OUT(x) variable, where x is the index that has been assigned to the controller
	// in the network during System Configuration.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AssignPegOutputsNT(HANDLE Handle, int Axis, int OutputIndex, int BitCode, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used to switch MARK_1 physical inputs to ACSPL+ variables as fast general purpose
	// inputs.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AssignFastInputsNT(HANDLE Handle, int Axis, int InputIndex, int BitCode, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for setting the parameters for the Incremental PEG mode. The Incremental PEG
	// function is defined by first point, last point and the interval.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegIncNT(HANDLE Handle, int Flags, int Axis, double Width, double FirstPoint, double Interval, double LastPoint, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for setting the parameters for the Incremental PEG mode and support dynamic error compensation.The Incremental PEG 
	// function is defined by first point, last point and the interval.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegIncNTV2(HANDLE Handle, int Flags, int Axis, double Width, double FirstPoint, double Interval, double LastPoint, int ErrMapAxis1, double AxisCoord1, int ErrMapAxis2, double AxisCoord2, int ErrMapMaxSize, double MinDirDistance, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for setting the parameters for the Random PEG mode. The Random PEG
	// function specifies an array of points where position - based events are to be generated.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegRandomNT(HANDLE Handle, int Flags, int Axis, double Width, int Mode, int FirstIndex, int LastIndex, char* PointArray, char* StateArray, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for setting the parameters for the Random PEG mode and support dynamic error compensation. The Random PEG
	// function specifies an array of points where position - based events are to be generated.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_PegRandomNTV2(HANDLE Handle, int Flags, int Axis, double Width, int Mode, int FirstIndex, int LastIndex, char* PointArray, char* StateArray,int ErrMapAxis1, double AxisCoord1, int ErrMapAxis2, double AxisCoord2, double MinDirDistance, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used to initiate the PEG process.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StartPegNT(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used to terminate the PEG process immediately on the specified axis. The function
	// can be used in both the Incrementaland Random PEG modes.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StopPegNT(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function receives axis index and zone index. This function activates
	// error correction for the mechanical error compensation for the specified zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationOn(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function receives axis index and zone index. The This function
	// deactivates error mapping correction for the mechanical error compensation for the specified zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationOff(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function receives axis index and zone index. This function deactivates
	// error correction for the mechanical error compensation for the specified zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationRemove(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function configures and activates 1D error correction for the mechanical error
	// compensation for the specified zone, so that the compensated reference position will be calculated
	// by subtracting the linearly(by default) interpolated error from the desired position so that the actual
	// value will be closer to the desired value.
	// The calculation assumes fixed Intervals between points inside the zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation1D(HANDLE Handle, int Flags, int Axis, int Zone, double Base0, double Step0, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function configures and activates 1D error correction for the mechanical error
	// compensation for the specified zone, so that the compensated reference position will be calculated
	// by subtracting the linearly(by default) interpolated error from the desired position so that the actual
	// value will be closer to the desired value.
	// The calculation is based on an arbitrary network of points inside the zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN1D(HANDLE Handle, int Flags, int Axis, int Zone, char* AxisCommands,  char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This function configures and activates 1D error correction for the mechanical error
	// compensation for the specified zone, so that the compensated reference position will be calculated
	// by multiplying the scaling factor by the desired position so that the actual value will be closer to the
	// desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationA1D(HANDLE Handle, int Flags, int Axis, int Zone, double ScalingFactor, double Offset, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 2D error correction for the mechanical error
	// compensation of the ‘axis0’ command for the specified zone, so that the compensated reference position will 
	// be calculated by subtracting the linearly (by default) interpolated error from the desired position so that the actual 
	// value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation2D(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, double Base0, double Step0, double Base1, double Step1, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 2D error correction for the mechanical error 
	// compensation of the ‘axis0’ command for the specified zone, so that the compensated reference position will 
	// be calculated by subtracting the linearly (by default) interpolated error from the desired position so that the actual  
	// value will be closer to the desired value.
	// The calculation is based on an arbitrary network of points inside the zone.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN2D(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, char* Axis0Commands, char* Axis1Commands, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: function configures and activates 2D error correction for the mechanical 
	// error compensation of the specified axis for the specified zone, so that the compensated reference position will be 
	// calculated by taking into account the angle for the orthogonality correction so that the actual value will be closer to 
	// the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationA2D(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, double Angle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation3D2(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation3D3(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation3D5(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensation3DA(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, char* CorrectionMap5Variable, char* CorrectionMap6Variable, char* CorrectionMap7Variable, char* CorrectionMap8Variable, char* CorrectionMap9Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN3D2(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN3D3(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN3D5(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Dynamic Error Compensation: This configures and activates 3D error correction for the mechanical error 
	// compensation of the ‘axis0’ command, ‘axis1’ command, and 'axis2' command for the specified zone, 
	// so that the compensated reference position will be calculated by adding the linearly (by default) interpolated error 
	// from the desired position so that the actual value will be closer to the desired value.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DynamicErrorCompensationN3DA(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, char* CorrectionMap5Variable, char* CorrectionMap6Variable, char* CorrectionMap7Variable, char* CorrectionMap8Variable, char* CorrectionMap9Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// *** OBSOLETE *** 
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadFileToIntegerVariable(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, char* Filename, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// *** OBSOLETE ***
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadFileToRealVariable(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, char* Filename, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// *** OBSOLETE ***
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DownloadBinVariableToFile(HANDLE Handle, int NBuf, char* Var, int Size, int From1, int To1, int From2, int To2, char* Filename, char* Format, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function sets the log file options.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SetLogFileOptions(HANDLE Handle, ACSC_LOG_DETALIZATION_LEVEL Detalization, ACSC_LOG_DATA_PRESENTATION Presentation);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//The function writes value(s) from text file to SPiiPlus controller (variable or file).
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadDataToController(HANDLE Handle, int Dest, char* DestName, int From1, int To1, int From2, int To2, char* SrcFileName, int SrcNumFormat, BOOL bTranspose, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//This function writes value(s) from the SPiiPlus controller (variable or file) to a text file.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_UploadDataFromController(HANDLE Handle, int Src, char* SrcName, int SrcNumFormat, int From1, int To1, int From2, int To2, char* DestFileName, char* DestNumFormat, BOOL bTranspose, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function copies file to controller
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CopyFileToController(HANDLE Handle, char* SourceFileName, char* DestinationFileName, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function deletes file from controller
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DeleteFileFromController(HANDLE Handle, char* FileName, ACSC_WAITBLOCK* Wait);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the list of all currently opened communication channels(connections), on active Server.//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetConnectionsList(ACSC_CONNECTION_DESC* ConnectionsList, int MaxNumConnections, int* NumConnections);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves additional information of specified connection, on active Server.						 //
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetConnectionInfo(HANDLE Handle, ACSC_CONNECTION_INFO* ConnectionInfo);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates single communication channel(connection), on active Server.//
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_TerminateConnection(ACSC_CONNECTION_DESC* Connection);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function initiates the Emergency Stop functionality for calling application.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_RegisterEmergencyStop();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function terminates the Emergency Stop functionality for the calling application.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_UnregisterEmergencyStop();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function returns version of UMD                                                //
	////////////////////////////////////////////////////////////////////////////////////////
	unsigned int _ACSCLIB_ WINAPI acsc_GetUMDVersion();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function analyzes an application file and returns information about the file’s components, such
	// as, saved ACSPL + programs, configuration parameters, user files, etc.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_AnalyzeApplication(HANDLE Handle, const char* FileName, ACSC_APPSL_INFO** Info, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function frees memory previously allocated by the acsc_AnalyzeApplication function.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FreeApplication(ACSC_APPSL_INFO* Info);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function saves a user application from the controller to a file on the host PC.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_SaveApplication(HANDLE Handle, const char* FileName, ACSC_APPSL_INFO* Info, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function loads a section of data from the host PC disk and saves it in the controller’s files.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_LoadApplication(HANDLE Handle, const char* FileName, ACSC_APPSL_INFO* Info, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// Function calculates fast Fourier transform.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FFT(double* in, double* outReal, double* outImag, int length, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// This function initializes FRF measurement.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_Measure(HANDLE Handle, FRF_INPUT* inputParams, FRF_OUTPUT** outputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// To Be Filled.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_CrossCouplingMeasure(HANDLE Handle, FRF_CROSS_COUPLING_INPUT* inputParams, FRF_CROSS_COUPLING_OUTPUT** outputParams, int* errorCode);
	
	////////////////////////////////////////////////////////////////////////////////////////
	// Function aborts FRF measurement. If FRF was aborted “outputParams” will not contain valid data
	// (all pointers will be set to nullptr) and errorCode will reflect that FRF was aborted by the user.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_Stop(HANDLE Handle, int Axis, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// This function calculates the required duration of measurement (DurationSec parameter of FRFInput
	// class) in order to satisfy the specified frequency resolution.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_CalculateMeasurementDuration(FRF_DURATION_CALCULATION_PARAMETERS* params, double* duration, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Initializes the inputParams structure of the “acsc_FRF_Measure” function to valid initial values.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_InitInput(FRF_INPUT* inputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Releases memory allocated for “outputParams” during calling to “acsc_FRF_
	// CalculateMeasurementDuration”
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_FreeOutput(FRF_OUTPUT* inputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Frees memory allocated for calculate Loop data.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_FreeCalculateLoopData(FRF_CALCULATE_LOOP_DATA* loopData, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function reads all required servo parameters for calculation of Controller, OpenLoop, ClosedLoop
	// etc.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_ReadServoParameters(HANDLE Handle, int axis, SERVO_PARAMETERS* servoParameters, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// This fucnction Calculate the loop data.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_CalculateLoopDataFRD(FRF_CALCULATE_LOOP_DATA* loopData, FRD** data, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// To Be filled
	////////////////////////////////////////////////////////////////////////////////////////
	//int	_ACSCLIB_ WINAPI acsc_FRF_CalculatePlantFRDV2(FRF_CALCULATE_LOOP_DATA* loopData, FRD** plant, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function calculates controller FRD (Frequency Response Data) based on servo parameters,
	// servo loopand frequency vector.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_CalculateControllerFRD(SERVO_PARAMETERS* servoParameters, FRF_LOOP_TYPE loopType, double* frequencyHz, int frequencyLength, FRD** controller, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// This function calculates open loop FRD based on servo parameters, servo loop and frequency
	// vector.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_CalculateOpenLoopFRD(SERVO_PARAMETERS* servoParameters, FRD* plant, FRF_LOOP_TYPE loopType, FRD** openLoop, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// To Be filled
	////////////////////////////////////////////////////////////////////////////////////////
	//int	_ACSCLIB_ WINAPI acsc_FRF_CalculateOpenLoopFRDV2(FRF_CALCULATE_LOOP_DATA *loopData, FRD** openLoop, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// This function calculates closed loop FRD based on servo parameters, servo loop and frequency
	// vector
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_CalculateClosedLoopFRD(SERVO_PARAMETERS* servoParameters, FRD* plant, FRF_LOOP_TYPE loopType, FRD** closedLoop, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// To Be filled
	////////////////////////////////////////////////////////////////////////////////////////
	//int	_ACSCLIB_ WINAPI acsc_FRF_CalculateClosedLoopFRDV2(FRF_CALCULATE_LOOP_DATA* loopData, FRD** openLoop, int* errorCode);
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// To Be filled
	////////////////////////////////////////////////////////////////////////////////////////
	//int	_ACSCLIB_ WINAPI acsc_FRF_CalculateSensitivityFRDV2(FRF_CALCULATE_LOOP_DATA* loopData, FRD** sensitivity, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function calculates required stability margins based on the frequency response data of the open
	// loop.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_CalculateStabilityMargins(FRD* openLoop, FRF_STABILITY_MARGINS** stabilityMargins, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function calculates the SLVRAT parameter into the double parameter.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_CalculateSLVRAT(FRF_CALCULATE_SLVRAT_DATA* inputParams, double *slvrat, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Frees memory allocated for FRD.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_FreeFRD(FRD* inputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Internal use ONLY.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_FreeFRD_Internal(FRD* frdToFree);

	////////////////////////////////////////////////////////////////////////////////////////
	// Internal use ONLY.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_FreeFRD_Matrix_Internal(FRD* matrixToFree, int mSize);

	////////////////////////////////////////////////////////////////////////////////////////
	// Frees memory allocated for FRF Cross Coupling Measurment.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FRF_FreeCrossCouplingOutput(FRF_CROSS_COUPLING_OUTPUT* output, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Function frees memory allocated for stability margins.
	////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_FRF_FreeStabilityMargins(FRF_STABILITY_MARGINS* inputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Function executes jitter analysis.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_JitterAnalysis(JITTER_ANALYSIS_INPUT* in, JITTER_ANALYSIS_OUTPUT** out, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Release memory allocated for JITTER_ANALYSIS.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_JitterAnalysis_FreeOutput(JITTER_ANALYSIS_OUTPUT* inputParams, int* errorCode);

	////////////////////////////////////////////////////////////////////////////////////////
	// Controller Protection: The function applies protection for controller.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DefineControllerProtection(HANDLE Handle, int Flags, int* NoEditBuffers, int* NoViewBuffers, char* StandardVariables, const char* Password, int Timeout);
	
	////////////////////////////////////////////////////////////////////////////////////////
	// Controller Protection: The function removes protection from controller.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_RemoveControllerProtection(HANDLE Handle, int Flags, const char* Password, int Timeout);

	////////////////////////////////////////////////////////////////////////////////////////
	// Controller Protection: The function Temporarily Disables Variable Protection
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_TemporarilyDisableVariableProtection(HANDLE Handle, const char* Password, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// Controller Protection: The function Restore Variable Protection That Was Temporarily Disabled
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_RestoreVariableProtection(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function reboots controller and waits for process completion.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ControllerReboot(HANDLE Handle, int Timeout);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function reboots controller, restores factory default settings and waits for process completion
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ControllerFactoryDefault(HANDLE Handle, int Timeout);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function saves to flash
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ControllerSaveToFlash(HANDLE Handle, int* Parameters, int* Buffers, int* SPPrograms, char* UserArrays);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to retrieve the EtherCAT state.
	//////////////////////////////////////////////////////////////////////////////////////////////////	
	int _ACSCLIB_ WINAPI acsc_GetEtherCATState(HANDLE Handle, int* State, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// this function is used to retrieve the last EtherCAT error
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATError(HANDLE Handle, int* Error, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for raw mapping of network input variables of any size. Once the function is
	// called successfully, the firmware copies the value of the network input variable at the corresponding
	// EtherCAT offset into the ACSPL + variable, every controller cycle.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_MapEtherCATInput(HANDLE Handle, int Flags, int Offset, char* VariableName, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function is used for raw mapping of network output variables of any size. Once the function is
	// called successfully, the firmware copies the value of specified ACSPL + variable into the network
	// output variable at the corresponding EtherCAT offset, every controller cycle.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_MapEtherCATOutput(HANDLE Handle, int Flags, int Offset, char* VariableName, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function resets all previous mapping defined by acsc_MapEtherCATInput and acsc_MapEtherCATOutput.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_UnmapEtherCATInputsOutputs(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the index of EtherCAT slave according to the parameters that are specified.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveIndex(HANDLE Handle, int VendorID, int ProductID, int Count, double* SlaveIndex, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns offset of a network variable of the specified EtherCAT slave in EtherCAT telegram.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveOffset(HANDLE Handle, char* VariableName, int SlaveIndex, double* SlaveOffset, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns offset of a network variable of the specified EtherCAT slave in EtherCAT telegram.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveOffsetV2(HANDLE Handle, int Flags, char* VariableName, int SlaveIndex, double* SlaveOffset, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Vendor ID of specified EtherCAT slave.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveVendorID(HANDLE Handle, int SlaveIndex, double* VendorID, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Vendor ID of specified EtherCAT slave.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveVendorIDV2(HANDLE Handle,int Flags, int SlaveIndex, double* VendorID, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to retrieve the EtherCAT slave Serial number.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveSerialNumber(HANDLE Handle, int Flags,  int SlaveIndex, double* SerialNumber, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Product ID of the specified EtherCAT slave.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveProductID(HANDLE Handle, int SlaveIndex, double* ProductID, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Product ID of the specified EtherCAT slave.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveProductIDV2(HANDLE Handle,int Flags, int SlaveIndex, double* ProductID, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Revision of the specified EtherCAT slave.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveRevision(HANDLE Handle, int SlaveIndex, double* Revision, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the Revision of the specified EtherCAT slave..
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveRevisionV2(HANDLE Handle, int Flags, int SlaveIndex, double* Revision, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the type of the specified EtherCAT slave.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveType(HANDLE Handle, int VendorID, int ProductID, double* SlaveType, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the EtherCAT machine state of the specified EtherCAT slave.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveState(HANDLE Handle, int SlaveIndex, double* SlaveState, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function returns the EtherCAT machine state of the specified EtherCAT slave.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveStateV2(HANDLE Handle, int Flags, int SlaveIndex, double* SlaveState, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function downloads a file over EtherCAT from the controller’s flash to slave.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_DownloadFileOverEtherCAT(HANDLE Handle, char* Path, char* Filename, int SlaveIndex, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to read Object Dictionary entry from CoE slave.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadSDOValueOverEtherCAT(HANDLE Handle, int Flags, int SlaveIndex, int Index, int SubIndex, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to write a value into the CoE slave Object Dictionary.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WriteSDOValueOverEtherCAT(HANDLE Handle, int Flags, int SlaveIndex, int Index, int SubIndex, double Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// ESC Error Counters Registers (Beckhoff Memory). The ESCs have numerous error counters that help
	// you detectand locate errors.This function enables you to view the contents of these registers
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlaveRegister(HANDLE Handle, int Flags, int SlaveIndex, int Offset, double* Value, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to retrieve the EtherCAT state.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ClearEtherCATSlaveRegister(HANDLE Handle, int Flags, int SlaveIndex, int Offset, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// This function is used to retrieve the number of EtherCAT slaves connected to the master.
	// The EtherCAT network is identified by Flags parameter.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetEtherCATSlavesCount(HANDLE Handle, int Flags, double* SlavesCount, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the percentage of the volatile memory load.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetVolatileMemoryUsage(HANDLE Handle, double* UsageInPercents, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the amount of total volatile memory in bytes.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetVolatileMemoryTotal(HANDLE Handle, double* TotalMemory, ACSC_WAITBLOCK* Wait);
	
	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the amount of free volatile memory in bytes.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetVolatileMemoryFree(HANDLE Handle, double* FreeMemory, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the percentage of the non-volatile memory load.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetNonVolatileMemoryUsage(HANDLE Handle, double* UsageInPercents, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the amount of total non-volatile memory in bytes.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetNonVolatileMemoryTotal(HANDLE Handle, double* TotalMemory, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function retrieves the amount of free non-volatile memory in bytes.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_GetNonVolatileMemoryFree(HANDLE Handle, double* FreeMemory, ACSC_WAITBLOCK* Wait);

	////////////////////////////////////////////////////////////////////////////////////////
	// The function starts the SPiiPlusSC controller.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StartSPiiPlusSC();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function stops the SPiiPlusSC controller.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_StopSPiiPlusSC();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function Stops the SPiiPlus simulator via UMD in the case that it is running.
	////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_CloseSimulator();

	////////////////////////////////////////////////////////////////////////////////////////
	// The function executes the SPiiPlus stand-alone simulator via SPiiPlus User ModeDriver in the case
	// that it is not running.
	// The function connects to the simulator via TCP / IP protocol.
	////////////////////////////////////////////////////////////////////////////////////////
	HANDLE _ACSCLIB_ WINAPI acsc_OpenCommSimulator();

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: The function waits for completion of asynchronous call and retrieves a data. *Buf pointer must be freed after use.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_WaitForResult(HANDLE Handle, void** Buf, int* Received, ACSC_RETURN_TYPE* ReturnType, ACSC_WAITBLOCK* Wait, int Timeout);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: Read variable typeless
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadTypeless(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, void** pValues, int* DataSize, int* Dim1, int* Dim2, int* DataOffset, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: Read variable typeless
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_ReadTypeless2(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, void** pValues, int* DataSize, int* Dim1, int* Dim2, int* DataOffset, ACSC_RETURN_TYPE ReturnType, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: Raw Transaction
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_RawTransaction(HANDLE Handle, char* OutBuf, int OutCount, BSTR* Reply, ACSC_WAITBLOCK* Wait);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: Transaction2
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_Transaction2(HANDLE Handle, char* OutBuf, int OutCount, BSTR* Reply, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: Transaction3
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_Transaction3(HANDLE Handle, char* OutBuf, int OutCount, void** Reply, unsigned long* N, ACSC_WAITBLOCK* Wait);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: FreeBufferMemory
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int _ACSCLIB_ WINAPI acsc_FreeBufferMemory(void* pbuf);

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// Undocumented: UploadEntireBuffer
	//////////////////////////////////////////////////////////////////////////////////////////////////
	int	_ACSCLIB_ WINAPI acsc_UploadEntireBuffer(HANDLE Handle, char* OutBuf, int OutCount, void** Reply, unsigned long* N, ACSC_WAITBLOCK* Wait);
	
#else // defined (ACSC_RUNTIME_DYNAMIC_LINKING)

// function type definitions
	typedef int (WINAPI *ACSC_AddMPoint)(HANDLE, int, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddMPointM)(HANDLE, int*, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddPoint)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddPointM)(HANDLE, int*, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AppendBuffer)(HANDLE, int, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Arc1)(HANDLE, int*, double*, double*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Arc2)(HANDLE, int*, double*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Break)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_BreakM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_CancelOperation)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_CaptureComm)(HANDLE);
	typedef int (WINAPI *ACSC_ClearBreakpoints)(HANDLE handle, int Buffer, int line, ACSC_WAITBLOCK* wait);
	typedef int (WINAPI *ACSC_ClearBuffer)(HANDLE, int, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ClearVariables)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_CloseComm)(HANDLE);
	typedef int (WINAPI *ACSC_CloseHistoryBuffer)(HANDLE);
	typedef int (WINAPI *ACSC_CloseLogFile)(HANDLE);
	typedef int (WINAPI *ACSC_CloseSCLogFile)(HANDLE);
	typedef int (WINAPI *ACSC_CloseMessageBuffer)(HANDLE);
	typedef int (WINAPI *ACSC_Collect)(HANDLE, int, char*, int, int, char**, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Command)(HANDLE, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Commut)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_CommutExt)(HANDLE, int, float, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_CompileBuffer)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DeclareVariable)(HANDLE, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Disable)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DisableAll)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DisableFault)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DisableM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DisableResponse)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DownloadBuffer)(HANDLE, int, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Enable)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_EnableFault)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_EnableM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_EnableResponse)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_EndSequence)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_EndSequenceM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtAddPoint)(HANDLE, int, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtAddPointM)(HANDLE, int*, double*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtArc1)(HANDLE, int*, double*, double*, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtArc2)(HANDLE, int*, double*, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtLine)(HANDLE, int*, double*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtToPoint)(HANDLE, int, int, double, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ExtToPointM)(HANDLE, int, int*, double*, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_FlushLogFile)(char*);
	typedef int (WINAPI *ACSC_FlushSCLogFile)(char*, BOOL);
	typedef int (WINAPI *ACSC_GetAcceleration)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetAnalogInput)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetAnalogOutput)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetAxisState)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetBreakpointsList)(HANDLE handle, int BufferNum, int* Array, int Size, int* replySize, ACSC_WAITBLOCK* wait);
	typedef int (WINAPI *ACSC_GetCommOptions)(HANDLE, unsigned int*);
	typedef int (WINAPI *ACSC_GetDeceleration)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetDefaultTimeout)(HANDLE);
	typedef int	(WINAPI *ACSC_GetErrorString)(HANDLE, int, char*, int, int*);
	typedef int (WINAPI *ACSC_GetExtInput)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetExtInputPort)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetExtOutput)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetExtOutputPort)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetFPosition)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetFVelocity)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetFault)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetFaultMask)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetFirmwareVersion)(HANDLE, char*, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetHistory)(HANDLE, char*, int, int*, BOOL);
	typedef int (WINAPI *ACSC_GetIndexState)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetInput)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetInputPort)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetInterruptMask)(HANDLE, int, unsigned int*);
	typedef int (WINAPI *ACSC_GetCallbackMask)(HANDLE, int, unsigned __int64*);
	typedef int (WINAPI* ACSC_GetCallbackMaskExt)(HANDLE, int, AXMASK_EXT*);

	typedef int (WINAPI *ACSC_GetJerk)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetKillDeceleration)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetLastError)();
	typedef unsigned int (WINAPI *ACSC_GetLibraryVersion)();
	typedef int (WINAPI *ACSC_GetMessage)(HANDLE, char*, int, int*, BOOL);
	typedef int (WINAPI *ACSC_GetMotionError)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetMotorError)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetMotorState)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetOutput)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetOutputPort)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetPCICards)(ACSC_PCI_SLOT*, int, int*);
	typedef int (WINAPI *ACSC_GetEthernetCards) (struct in_addr*, int, int*, unsigned long);
	typedef int (WINAPI *ACSC_GetEthernetCardsExt) (ACSC_CONTROLLER_INFO*, unsigned long, int, int*, unsigned long);
	typedef int (WINAPI *ACSC_GetProgramError)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetProgramState)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetRPosition)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetRVelocity)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetResponseMask)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetSafetyInput)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetSafetyInputPort)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetSafetyInputPortInv)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetSerialNumber)(HANDLE, char*, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetTimeout)(HANDLE);
	typedef int (WINAPI *ACSC_GetVelocity)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Go)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GoM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Group)(HANDLE, int*, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_Halt)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_HaltM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Jog)(HANDLE, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_JogM)(HANDLE, int, int*, int*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Kill)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_KillExt)(HANDLE Handle, int Axis, int Reason, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DisableExt)(HANDLE Handle, int Axis, int Reason, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_KillAll)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_KillM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Line)(HANDLE, int*, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadBuffer)(HANDLE, int, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_MultiPoint)(HANDLE, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_MultiPointM)(HANDLE, int, int*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_BoostedPointToPointMotion)(HANDLE, int, int*, double*, double, double, double, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SmoothPointToPointMotion)(HANDLE, int, int*, double*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SmoothTransitionPointToPointMotion)(HANDLE, int, int*, double*, double, double, ACSC_WAITBLOCK*);
	typedef HANDLE(WINAPI *ACSC_OpenCommDirect)();
	typedef int (WINAPI *ACSC_CloseSimulator)();
	typedef HANDLE(WINAPI *ACSC_OpenCommSimulator)();
	typedef HANDLE(WINAPI *ACSC_OpenCommEthernet)(char*, int);
	typedef HANDLE(WINAPI *ACSC_OpenCommEthernetUDP)(char*, int);
	typedef HANDLE(WINAPI *ACSC_OpenCommEthernetTCP)(char*, int);
	typedef HANDLE(WINAPI *ACSC_OpenCommSerial)(int, int);
	typedef HANDLE(WINAPI *ACSC_OpenCommPCI)(int);
	typedef LP_ACSC_HISTORYBUFFER(WINAPI *ACSC_OpenHistoryBuffer)(HANDLE, int);
	typedef int (WINAPI *ACSC_OpenLogFile)(HANDLE, char*);
	typedef int (WINAPI *ACSC_OpenSCLogFile)(HANDLE, char*);
	typedef LP_ACSC_HISTORYBUFFER(WINAPI *ACSC_OpenMessageBuffer)(HANDLE, int);
	typedef int (WINAPI *ACSC_Projection)(HANDLE, int*, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ReadDPRAMInteger)(HANDLE, int, int*);
	typedef int (WINAPI *ACSC_ReadDPRAMReal)(HANDLE, int, double*);
	typedef int (WINAPI *ACSC_ReadInteger)(HANDLE, int, char*, int, int, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ReadReal)(HANDLE, int, char*, int, int, int, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ReadString)(HANDLE, int, const char*, int, int, int, int, char*, unsigned short, ACSC_WAITBLOCK*);
	typedef int (WINAPI* ACSC_ReadStruct)(HANDLE, int, const char*, int, int, int, int, void*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI* ACSC_WriteStruct)(HANDLE, int, const char*, int, int, int, int, void*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Receive)(HANDLE, char*, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ReleaseComm)(HANDLE);
	typedef int (WINAPI *ACSC_ResetIndexState)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_RunBuffer)(HANDLE, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Segment)(HANDLE, int, int*, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Send)(HANDLE, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetAcceleration)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetAccelerationImm)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetAnalogOutput)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetBreakpoint)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetCallback)(HANDLE, ACSC_INTR_CALLBACK_FUNC, int);
	typedef int (WINAPI *ACSC_SetCallbackPriority)(HANDLE, int);
	typedef int (WINAPI *ACSC_SetCommOptions)(HANDLE, unsigned int);
	typedef int (WINAPI *ACSC_SetDeceleration)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetDecelerationImm)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetExtOutput)(HANDLE, int, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetExtOutputPort)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetFPosition)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetFaultMask)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetInterruptMask)(HANDLE, int, unsigned int);
	typedef int (WINAPI *ACSC_SetCallbackMask)(HANDLE, int, unsigned __int64);
	typedef int (WINAPI *ACSC_SetCallbackMaskExt)(HANDLE, int, AXMASK_EXT);
	typedef int (WINAPI *ACSC_SetIterations)(HANDLE, int);
	typedef int (WINAPI *ACSC_SetJerk)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetJerkImm)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetKillDeceleration)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetKillDecelerationImm)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetMaster)(HANDLE, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetOutput)(HANDLE, int, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetOutputPort)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetRPosition)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetResponseMask)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetSafetyInputPortInv)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetTimeout)(HANDLE, int);
	typedef int (WINAPI *ACSC_SetVelocity)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetVelocityImm)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Slave)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SlaveStalled)(HANDLE, int, int, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Spline)(HANDLE, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SplineM)(HANDLE, int, int*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Split)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SplitAll)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_StopBuffer)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_StopCollect)(HANDLE, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Stopper)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SuspendBuffer)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ToPoint)(HANDLE, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ToPointM)(HANDLE, int, int*, double*, ACSC_WAITBLOCK*);
	typedef int	(WINAPI *ACSC_Transaction)(HANDLE, char*, int, char*, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_UploadBuffer)(HANDLE, int, int, char*, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_WaitCollectEnd)(HANDLE, int);
	typedef int (WINAPI *ACSC_WaitCollectEndExt)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WaitSPDataCollectionEnd)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WaitForAsyncCall)(HANDLE, void*, int*, ACSC_WAITBLOCK*, int);
	typedef int (WINAPI *ACSC_WaitInput)(HANDLE, int, int, int, int);
	typedef int (WINAPI *ACSC_WaitLogicalMotionEnd)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WaitMotionEnd)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WaitMotorEnabled)(HANDLE, int, int, int);
	typedef int (WINAPI *ACSC_WaitMotorCommutated)(HANDLE, int, int, int);
	typedef int (WINAPI *ACSC_WaitProgramEnd)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WaitUserCondition)(HANDLE, ACSC_USER_CONDITION_FUNC, int);
	typedef int (WINAPI *ACSC_WriteDPRAMInteger)(HANDLE, int, int);
	typedef int (WINAPI *ACSC_WriteDPRAMReal)(HANDLE, int, double);
	typedef int (WINAPI *ACSC_WriteInteger)(HANDLE, int, char*, int, int, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_WriteLogFile)(HANDLE, char*, int);
	typedef int (WINAPI *ACSC_WriteSCLogFile)(HANDLE, char*, int);
	typedef int (WINAPI *ACSC_WriteReal)(HANDLE, int, char*, int, int, int, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_WriteString)(HANDLE, int, const char*, int, int, int, int, char*, unsigned short, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadBufferIgnoreServiceLines)(HANDLE, int, char*, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadBuffersFromFile)(HANDLE, char*, ACSC_WAITBLOCK*);

	typedef int (WINAPI *ACSC_PegI)(HANDLE, int, int, double, int, int, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_PegR)(HANDLE, int, int, double, char*, char*, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_PegInc)(HANDLE, int, int, double, double, double, double, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_PegRandom)(HANDLE, int, int, double, char*, char*, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AssignPins)(HANDLE, int, unsigned short, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_StopPeg)(HANDLE, int, ACSC_WAITBLOCK*);

	typedef int (WINAPI *ACSC_AssignPegNT)(HANDLE Handle, int Axis, int EngToEncBitCode, int GpOutsBitCode, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_AssignPegNTV2)(HANDLE Handle, int flags, int Axis, int EngToEncBitCode, int GpOutsBitCode, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_AssignPegOutputsNT)(HANDLE Handle, int Axis, int OutputIndex, int BitCode, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_AssignFastInputsNT)(HANDLE Handle, int Axis, int InputIndex, int BitCode, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_PegIncNT)(HANDLE Handle, int Flags, int Axis, double Width, double FirstPoint, double Interval, double LastPoint, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_PegIncNTV2)(HANDLE Handle, int Flags, int Axis, double Width, double FirstPoint, double Interval, double LastPoint, int ErrMapAxis1, double AxisCoord1, int ErrMapAxis2, double AxisCoord2, int ErrMapMaxSize, double MinDirDistance, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_PegRandomNT)(HANDLE Handle, int Flags, int Axis, double Width, int Mode, int FirstIndex, int LastIndex, char* PointArray, char* StateArray, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_PegRandomNTV2)(HANDLE Handle, int Flags, int Axis, double Width, int Mode, int FirstIndex, int LastIndex, char* PointArray, char* StateArray, int ErrMapAxis1, double AxisCoord1, int ErrMapAxis2, double AxisCoord2, double MinDirDistance, int TbNumber, double TbPeriod, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_WaitPegReadyNT)(HANDLE Handle, int Axis, int Timeout);
	typedef int (WINAPI *ACSC_StartPegNT)(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_StopPegNT)(HANDLE Handle, int Axis, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_CollectB)(HANDLE, int, char*, int, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DataCollection)(HANDLE, int, int, char*, int, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_DataCollectionExt)(HANDLE Handle, int Flags, int Axis, char* Array, int NSample, double Period, char* Vars, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SPDataCollectionStart)(HANDLE Handle, int Flags, const char* Array, int NSample, double Period, int ServoProcessorIndex, int ServoProcessorAddress1, int ServoProcessorAddress2, int ServoProcessorAddress3, int ServoProcessorAddress4, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SPDataCollectionStop)(HANDLE Handle, int ServoProcessorIndex, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetSPAddress)(HANDLE Handle, int Flags, int ServoProcessorIndex, const char* ServoProcessorVariable, int* ServoProcessorAddress);
	typedef int (WINAPI *ACSC_AddPVPoint)(HANDLE, int, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddPVPointM)(HANDLE, int*, double*, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddPVTPoint)(HANDLE, int, double, double, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_AddPVTPointM)(HANDLE, int*, double*, double*, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadFileToRealVariable)(HANDLE, int, char*, int, int, int, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadFileToIntegerVariable)(HANDLE, int, char*, int, int, int, int, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_LoadDataToController)(HANDLE, int, char*, int, int, int, int, char*, int, BOOL, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_UploadDataFromController)(HANDLE, int, char*, int, int, int, int, int, char*, char*, BOOL, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetQueueOverflowTimeout)(HANDLE, int);
	typedef int (WINAPI *ACSC_GetQueueOverflowTimeout)(HANDLE);
	typedef int (WINAPI *ACSC_SetTargetPosition)(HANDLE, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetTargetPosition)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetTargetPositionM)(HANDLE, int*, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Track)(HANDLE, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_TrackM)(HANDLE, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_FaultClearM)(HANDLE, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_FaultClear)(HANDLE, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Getconf)(HANDLE, int, int, int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_Setconf)(HANDLE, int, int, int, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetCallbackExt)(HANDLE, ACSC_INTR_CALLBACK_FUNC_EXT, void*, int);
	typedef int (WINAPI *ACSC_InstallCallback)(HANDLE, ACSC_USER_CALLBACK_FUNCTION, void*, int);
	typedef int (WINAPI* ACSC_InstallCallbackExt)(HANDLE, ACSC_USER_CALLBACK_FUNCTION_EXT, void*, int);
	typedef int (WINAPI *ACSC_DownloadBinVariableToFile)(HANDLE, int, char*, int, int, int, int, int, char*, char*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetLogFileOptions)(HANDLE, ACSC_LOG_DETALIZATION_LEVEL, ACSC_LOG_DATA_PRESENTATION);

	typedef int (WINAPI *ACSC_GetConf)(HANDLE, int, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetConf)(HANDLE, int, int, double, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SysInfo)(HANDLE Handle, int Key, double* Value, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_GetAxesCount)(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetBuffersCount)(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetDBufferIndex)(HANDLE Handle, double* Value, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_SetServer)(char* IP);
	typedef int (WINAPI *ACSC_SetServerExt)(char*, int);
	typedef int (WINAPI *ACSC_SetServerExtLogin)(char*, int, char*, char*, char*);
	typedef int (WINAPI *ACSC_GetSingleMessage)(HANDLE Handle, char* Buf, int Count, int* Received, int Timeout);

	typedef int (WINAPI *ACSC_GetConnectionsList)(ACSC_CONNECTION_DESC* ConnectionsList, int MaxNumConnections, int* NumConnections);
	typedef int (WINAPI *ACSC_GetConnectionInfo)(HANDLE Handle, ACSC_CONNECTION_INFO* ConnectionInfo);
	typedef int (WINAPI *ACSC_TerminateConnection)(ACSC_CONNECTION_DESC* Connection);

	typedef int (WINAPI *ACSC_GetLogData)(HANDLE Handle, char* Buf, int Count, int* Received, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_RegisterEmergencyStop)();
	typedef int (WINAPI *ACSC_UnregisterEmergencyStop)();

	typedef unsigned int (WINAPI *ACSC_GetUMDVersion)();

	typedef int (WINAPI* ACSC_AnalyzeApplication)(HANDLE, const char*, ACSC_APPSL_INFO**, ACSC_WAITBLOCK*);
	typedef int (WINAPI* ACSC_FreeApplication)(ACSC_APPSL_INFO*);
	typedef int (WINAPI* ACSC_SaveApplication)(HANDLE, const char*, ACSC_APPSL_INFO*, ACSC_WAITBLOCK*);
	typedef int (WINAPI* ACSC_LoadApplication)(HANDLE, const char*, ACSC_APPSL_INFO*, ACSC_WAITBLOCK*);

	typedef int (WINAPI* ACSC_FFT)(double*, double*, double*, int, int*);
	typedef int (WINAPI* ACSC_FRF_Measure)(HANDLE, FRF_INPUT*, FRF_OUTPUT**, int*);
	typedef int	(WINAPI* ACSC_FRF_FreeFRD_Internal)(FRD* frdToFree);
	typedef int (WINAPI* ACSC_FRF_CalculateSLVRAT)(FRF_CALCULATE_SLVRAT_DATA* inputParams, double* slvrat, int* errorCode);
	typedef int	(WINAPI* ACSC_FRF_CalculateLoopDataFRD)(FRF_CALCULATE_LOOP_DATA* loopData, FRD** data, int* errorCode);
	typedef int (WINAPI* ACSC_FRF_FreeCalculateLoopData)(FRF_CALCULATE_LOOP_DATA* loopData, int* errorCode);
	typedef int (WINAPI* ACSC_FRF_CrossCouplingMeasure)(HANDLE Handle, FRF_CROSS_COUPLING_INPUT* inputParams, FRF_CROSS_COUPLING_OUTPUT** outputParams, int* errorCode);
	typedef int (WINAPI* ACSC_FRF_Stop)(HANDLE, int, int*);
	typedef int (WINAPI* ACSC_FRF_CalculateMeasurementDuration)(FRF_DURATION_CALCULATION_PARAMETERS*, double*, int*);
	typedef int (WINAPI* ACSC_FRF_InitInput)(FRF_INPUT*, int*);
	typedef int (WINAPI* ACSC_FRF_FreeOutput)(FRF_OUTPUT*, int*);
	typedef int (WINAPI* ACSC_FRF_FreeCrossCouplingOutput)(FRF_CROSS_COUPLING_OUTPUT*, int*);
	typedef int (WINAPI* ACSC_FRF_ReadServoParameters)(HANDLE, int, SERVO_PARAMETERS*, int*);
	typedef int (WINAPI* ACSC_FRF_CalculateControllerFRD)(SERVO_PARAMETERS*, FRF_LOOP_TYPE, double*, int, FRD**, int*);
	typedef int (WINAPI* ACSC_FRF_CalculateOpenLoopFRD)(SERVO_PARAMETERS*, FRD*, FRF_LOOP_TYPE, FRD**, int*);
	typedef int (WINAPI* ACSC_FRF_CalculateClosedLoopFRD)(SERVO_PARAMETERS*, FRD*, FRF_LOOP_TYPE, FRD**, int*);
	typedef int (WINAPI* ACSC_FRF_CalculateStabilityMargins)(FRD*, FRF_STABILITY_MARGINS**, int*);
	typedef int (WINAPI* ACSC_FRF_FreeFRD)(FRD*, int*);
	typedef int (WINAPI* ACSC_FRF_FreeStabilityMargins)(FRF_STABILITY_MARGINS*, int*);
	typedef int (WINAPI* ACSC_JitterAnalysis)(JITTER_ANALYSIS_INPUT*, JITTER_ANALYSIS_OUTPUT**, int*);
	typedef int (WINAPI* ACSC_JitterAnalysis_FreeOutput)(JITTER_ANALYSIS_OUTPUT*, int*);
	
	typedef int (WINAPI* ACSC_ReadTypeless)(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, void** pValues, int* DataSize, int* Dim1, int* Dim2, int* DataOffset, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_ReadTypeless2)(HANDLE Handle, int NBuf, char* Var, int From1, int To1, int From2, int To2, void** pValues, int* DataSize, int* Dim1, int* Dim2, int* DataOffset, ACSC_RETURN_TYPE ReturnType, ACSC_WAITBLOCK* Wait);
	typedef int	(WINAPI* ACSC_RawTransaction)(HANDLE Handle, char* OutBuf, int OutCount, BSTR* Reply, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_Transaction2)(HANDLE Handle, char* OutBuf, int OutCount, BSTR* Reply, ACSC_WAITBLOCK* Wait);
	typedef int	(WINAPI* ACSC_Transaction3)(HANDLE Handle, char* OutBuf, int OutCount, void** Reply, unsigned long* N, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_FreeBufferMemory)(void* pbuf);
	typedef int	(WINAPI* ACSC_UploadEntireBuffer)(HANDLE Handle, char* OutBuf, int OutCount, void** Reply, unsigned long* N, ACSC_WAITBLOCK* Wait);
	typedef int	(WINAPI* ACSC_FRF_FreeFRD_Matrix_Internal)(FRD* matrixToFree, int mSize);


	typedef int (WINAPI *ACSC_ControllerReboot)(HANDLE, int);
	typedef int (WINAPI *ACSC_ControllerFactoryDefault)(HANDLE, int);
	typedef int (WINAPI *ACSC_ControllerSaveToFlash)(HANDLE, int*, int*, int*, char*);

	typedef int (WINAPI *ACSC_GetSharedMemoryAddress)(HANDLE, int, char*, unsigned int*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_ReadSharedMemoryReal)(HANDLE, unsigned int, int, int, int, int, double*);
	typedef int (WINAPI *ACSC_ReadSharedMemoryInteger)(HANDLE, unsigned int, int, int, int, int, int*);
	typedef int (WINAPI *ACSC_WriteSharedMemoryReal)(HANDLE, unsigned int, int, int, int, int, double*);
	typedef int (WINAPI *ACSC_WriteSharedMemoryInteger)(HANDLE, unsigned int, int, int, int, int, int*);
	typedef int (WINAPI* ACSC_WaitForResult)(HANDLE Handle, void** Buf, int* Received, ACSC_RETURN_TYPE* ReturnType, ACSC_WAITBLOCK* Wait, int Timeout);


	typedef int (WINAPI *ACSC_GetEtherCATState)(HANDLE Handle, int* State, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATError)(HANDLE Handle, int* Error, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_MapEtherCATInput)(HANDLE Handle, int Flags, int Offset, char* VariableName, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_MapEtherCATOutput)(HANDLE Handle, int Flags, int Offset, char* VariableName, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_UnmapEtherCATInputsOutputs)(HANDLE Handle, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveIndex)(HANDLE Handle, int VendorID, int ProductID, int Count, double* SlaveIndex, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveOffset)(HANDLE Handle, char* VariableName, int SlaveIndex, double* SlaveOffset, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_GetEtherCATSlaveOffsetV2)(HANDLE Handle, int Flags, char* VariableName, int SlaveIndex, double* SlaveOffset, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveVendorID)(HANDLE Handle, int SlaveIndex, double* VendorID, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveVendorIDV2)(HANDLE Handle, int Flags, int SlaveIndex, double* VendorID, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveSerialNumber)(HANDLE Handle, int Flags, int SlaveIndex, double* SerialNumber, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveProductID)(HANDLE Handle, int SlaveIndex, double* ProductID, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveProductIDV2)(HANDLE Handle, int Flags, int SlaveIndex, double* ProductID, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveRevision)(HANDLE Handle, int SlaveIndex, double* Revision, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_GetEtherCATSlaveRevisionV2)(HANDLE Handle, int Flags, int SlaveIndex, double* Revision, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveType)(HANDLE Handle, int VendorID, int ProductID, double* SlaveType, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveState)(HANDLE Handle, int SlaveIndex, double* SlaveState, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_GetEtherCATSlaveStateV2)(HANDLE Handle,int Flags, int SlaveIndex, double* SlaveState, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DownloadFileOverEtherCAT)(HANDLE Handle, char* Path, char* Filename, int SlaveIndex, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ReadSDOValueOverEtherCAT)(HANDLE Handle, int Flags, int SlaveIndex, int Index, int SubIndex, double* Value, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_WriteSDOValueOverEtherCAT)(HANDLE Handle, int Flags, int SlaveIndex, int Index, int SubIndex, double Value, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlaveRegister)(HANDLE Handle, int Flags, int SlaveIndex, int Offset, double* Value, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ClearEtherCATSlaveRegister)(HANDLE Handle, int Flags, int SlaveIndex, int Offset, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetEtherCATSlavesCount)(HANDLE Handle, int Flags, double* SlavesCount, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_DynamicErrorCompensationOn)(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationOff)(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationRemove)(HANDLE Handle, int Axis, int Zone, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation1D)(HANDLE Handle, int Flags, int Axis, int Zone, double Base0, double Step0, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN1D)(HANDLE Handle, int Flags, int Axis, int Zone, char* AxisCommands, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationA1D)(HANDLE Handle, int Flags, int Axis, int Zone, double ScalingFactor, double Offset, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation2D)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, double Base0, double Step0, double Base1, double Step1, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN2D)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, char* Axis0Commands, char* Axis1Commands, char* CorrectionMapVariable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationA2D)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Zone, double Angle, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation3D2)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation3D3)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation3D5)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensation3DA)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, double Base0, double Step0, double Base1, double Step1, double Base2, double Step2, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, char* CorrectionMap5Variable, char* CorrectionMap6Variable, char* CorrectionMap7Variable, char* CorrectionMap8Variable, char* CorrectionMap9Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN3D2)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN3D3)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN3D5)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DynamicErrorCompensationN3DA)(HANDLE Handle, int Flags, int Axis0, int Axis1, int Axis2, int Zone, char* Axis0Commands, char* Axis1Commands, char* Axis2Commands, char* CorrectionMap0Variable, char* CorrectionMap1Variable, char* CorrectionMap2Variable, char* CorrectionMap3Variable, char* CorrectionMap4Variable, char* CorrectionMap5Variable, char* CorrectionMap6Variable, char* CorrectionMap7Variable, char* CorrectionMap8Variable, char* CorrectionMap9Variable, int ReferencedAxisOrAnalogInput0, int ReferencedAxisOrAnalogInput1, int ReferencedAxisOrAnalogInput2, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_CopyFileToController)(HANDLE Handle, char* SourceFileName, char* DestinationFileName, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_DeleteFileFromController)(HANDLE Handle, char* FileName, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_DefineControllerProtection)(HANDLE Handle, int Flags, int* NoEditBuffers, int* NoViewBuffers, char* StandardVariables, const char* Password, int Timeout);
	typedef int (WINAPI *ACSC_RemoveControllerProtection)(HANDLE Handle, int Flags, const char* Password, int Timeout);
	typedef int (WINAPI *ACSC_TemporarilyDisableVariableProtection)(HANDLE Handle, const char* Password, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_RestoreVariableProtection)(HANDLE Handle, ACSC_WAITBLOCK* Wait);

	typedef int (WINAPI *ACSC_SegmentedMotion)(HANDLE Handle, int Flags, int* Axes, double* Point, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ExtendedSegmentedMotion)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double StarvationMargin, char* Segments, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ExtendedSegmentedMotionExt)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double CurveVelocity, double Deviation, double Radius, double MaxLength, double StarvationMargin, char* Segments, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ExtendedSegmentedMotionV2)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double JunctionVelocity, double Angle, double CurveVelocity, double Deviation, double Radius, double MaxLength, double StarvationMargin, char* Segments, int ExtLoopType, double MinSegmentLength, double MaxAllowedDeviation, int OutputIndex, int BitNumber, int Polarity, double MotionDelay, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentLine)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentLineExt)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_SegmentLineV2)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double EndVelocity, double Time, char* Values, char* Variables,int Index, char* Masks, int ExtLoopType, double MimSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentArc1)(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentArc2)(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double Velocity, double EndVelocity, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentArc1Ext)(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_SegmentArc2Ext)(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ExtendedSegmentArc1)(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_ExtendedSegmentArc2)(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double* FinalPoint, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_SegmentArc1V2)(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, int ExtLoopType, double MimSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_SegmentArc2V2)(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double* FinalPoint, double Velocity, double EndVelocity, double Time, char* Values, char* Variables, int Index, char* Masks, int ExtLoopType, double MimSegmentLength, double MaxAllowedDeviation, int LciState, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_BlendedSegmentMotion)(HANDLE Handle, int Flags, int* Axes, double* Point, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_BlendedLine)(HANDLE Handle, int Flags, int* Axes, double* Point, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_BlendedArc1)(HANDLE Handle, int Flags, int* Axes, double* Center, double* FinalPoint, int Rotation, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_BlendedArc2)(HANDLE Handle, int Flags, int* Axes, double* Center, double Angle, double SegmentTime, double AccelerationTime, double JerkTime, double DwellTime, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI *ACSC_GetAnalogInputNT)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetAnalogOutputNT)(HANDLE, int, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_SetAnalogOutputNT)(HANDLE, int, double, ACSC_WAITBLOCK*);

	typedef int (WINAPI *ACSC_GetVolatileMemoryUsage)(HANDLE, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetVolatileMemoryTotal)(HANDLE, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetVolatileMemoryFree)(HANDLE, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetNonVolatileMemoryUsage)(HANDLE, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetNonVolatileMemoryTotal)(HANDLE, double*, ACSC_WAITBLOCK*);
	typedef int (WINAPI *ACSC_GetNonVolatileMemoryFree)(HANDLE, double*, ACSC_WAITBLOCK*);

	typedef int (WINAPI *ACSC_StartSPiiPlusSC)();
	typedef int (WINAPI *ACSC_StopSPiiPlusSC)();

	typedef int (WINAPI* ACSC_NurbsMotion)(HANDLE Handle, int Flags, int* Axes, double Velocity, double ExceptionAngle, double ExceptionLength, double MotionDelay, char* Segments, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_NurbsPoints)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double Required_vel, double Knot, double Weight, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_SmoothPathMotion)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double ExceptionAngle, double ExceptionLength, double MotionDelay, char* Segments, ACSC_WAITBLOCK* Wait);
	typedef int (WINAPI* ACSC_SmoothPathSegment)(HANDLE Handle, int Flags, int* Axes, double* Point, double Velocity, double Required_vel, ACSC_WAITBLOCK* Wait);

#if !defined (ACSC_RUNTIME_DYNAMIC_VARIABLES)
	ACSC_AddMPoint							acsc_AddMPoint;
	ACSC_AddMPointM							acsc_AddMPointM;
	ACSC_AddPoint							acsc_AddPoint;
	ACSC_AddPointM							acsc_AddPointM;
	ACSC_AppendBuffer						acsc_AppendBuffer;
	ACSC_Arc1								acsc_Arc1;
	ACSC_Arc2								acsc_Arc2;
	ACSC_Break								acsc_Break;
	ACSC_BreakM								acsc_BreakM;
	ACSC_CancelOperation					acsc_CancelOperation;
	ACSC_CaptureComm						acsc_CaptureComm;
	ACSC_ClearBuffer						acsc_ClearBuffer;
	ACSC_ClearBreakpoints					acsc_ClearBreakpoints;
	ACSC_ClearVariables						acsc_ClearVariables;
	ACSC_CloseComm							acsc_CloseComm;
	ACSC_CloseHistoryBuffer					acsc_CloseHistoryBuffer;
	ACSC_CloseLogFile						acsc_CloseLogFile;
	ACSC_CloseSCLogFile						acsc_CloseSCLogFile;
	ACSC_CloseMessageBuffer					acsc_CloseMessageBuffer;
	ACSC_Collect							acsc_Collect;
	ACSC_Command							acsc_Command;
	ACSC_Commut								acsc_Commut;
	ACSC_CommutExt							acsc_CommutExt;
	ACSC_CompileBuffer						acsc_CompileBuffer;
	ACSC_DeclareVariable					acsc_DeclareVariable;
	ACSC_Disable							acsc_Disable;
	ACSC_DisableAll							acsc_DisableAll;
	ACSC_DisableFault						acsc_DisableFault;
	ACSC_DisableM							acsc_DisableM;
	ACSC_DisableResponse					acsc_DisableResponse;
	ACSC_DownloadBuffer						acsc_DownloadBuffer;
	ACSC_Enable								acsc_Enable;
	ACSC_EnableFault						acsc_EnableFault;
	ACSC_EnableM							acsc_EnableM;
	ACSC_EnableResponse						acsc_EnableResponse;
	ACSC_EndSequence						acsc_EndSequence;
	ACSC_EndSequenceM						acsc_EndSequenceM;
	ACSC_ExtAddPoint						acsc_ExtAddPoint;
	ACSC_ExtAddPointM						acsc_ExtAddPointM;
	ACSC_ExtArc1							acsc_ExtArc1;
	ACSC_ExtArc2							acsc_ExtArc2;
	ACSC_ExtLine							acsc_ExtLine;
	ACSC_ExtToPoint							acsc_ExtToPoint;
	ACSC_ExtToPointM						acsc_ExtToPointM;
	ACSC_FlushLogFile						acsc_FlushLogFile;
	ACSC_FlushSCLogFile						acsc_FlushSCLogFile;
	ACSC_GetAcceleration					acsc_GetAcceleration;
	ACSC_GetAnalogInput						acsc_GetAnalogInput;
	ACSC_GetAnalogOutput					acsc_GetAnalogOutput;
	ACSC_GetAxisState						acsc_GetAxisState;
	ACSC_GetBreakpointsList					acsc_GetBreakpointsList;
	ACSC_GetCommOptions						acsc_GetCommOptions;
	ACSC_GetDeceleration					acsc_GetDeceleration;
	ACSC_GetDefaultTimeout					acsc_GetDefaultTimeout;
	ACSC_GetErrorString						acsc_GetErrorString;
	ACSC_GetExtInput						acsc_GetExtInput;
	ACSC_GetExtInputPort					acsc_GetExtInputPort;
	ACSC_GetExtOutput						acsc_GetExtOutput;
	ACSC_GetExtOutputPort					acsc_GetExtOutputPort;
	ACSC_GetFPosition						acsc_GetFPosition;
	ACSC_GetFVelocity						acsc_GetFVelocity;
	ACSC_GetFault							acsc_GetFault;
	ACSC_GetFaultMask						acsc_GetFaultMask;
	ACSC_GetFirmwareVersion					acsc_GetFirmwareVersion;
	ACSC_GetHistory							acsc_GetHistory;
	ACSC_GetIndexState						acsc_GetIndexState;
	ACSC_GetInput							acsc_GetInput;
	ACSC_GetInputPort						acsc_GetInputPort;
	ACSC_GetInterruptMask					acsc_GetInterruptMask;
	ACSC_GetCallbackMask					acsc_GetCallbackMask;
	ACSC_GetCallbackMaskExt					acsc_GetCallbackMaskExt;
	ACSC_GetJerk							acsc_GetJerk;
	ACSC_GetKillDeceleration				acsc_GetKillDeceleration;
	ACSC_GetLastError						acsc_GetLastError;
	ACSC_GetLibraryVersion					acsc_GetLibraryVersion;
	ACSC_GetMessage							acsc_GetMessage;
	ACSC_GetMotionError						acsc_GetMotionError;
	ACSC_GetMotorError						acsc_GetMotorError;
	ACSC_GetMotorState						acsc_GetMotorState;
	ACSC_GetOutput							acsc_GetOutput;
	ACSC_GetOutputPort						acsc_GetOutputPort;
	ACSC_GetPCICards						acsc_GetPCICards;
	ACSC_GetEthernetCards                   acsc_GetEthernetCards;
	ACSC_GetEthernetCardsExt                acsc_GetEthernetCardsExt;
	ACSC_GetProgramError					acsc_GetProgramError;
	ACSC_GetProgramState					acsc_GetProgramState;
	ACSC_GetRPosition						acsc_GetRPosition;
	ACSC_GetRVelocity						acsc_GetRVelocity;
	ACSC_GetResponseMask					acsc_GetResponseMask;
	ACSC_GetSafetyInput						acsc_GetSafetyInput;
	ACSC_GetSafetyInputPort					acsc_GetSafetyInputPort;
	ACSC_GetSafetyInputPortInv				acsc_GetSafetyInputPortInv;
	ACSC_GetSerialNumber					acsc_GetSerialNumber;
	ACSC_GetTimeout							acsc_GetTimeout;
	ACSC_GetVelocity						acsc_GetVelocity;
	ACSC_Go									acsc_Go;
	ACSC_GoM								acsc_GoM;
	ACSC_Group								acsc_Group;
	ACSC_Halt								acsc_Halt;
	ACSC_HaltM								acsc_HaltM;
	ACSC_Jog								acsc_Jog;
	ACSC_JogM								acsc_JogM;
	ACSC_Kill								acsc_Kill;
	ACSC_KillExt							acsc_KillExt;
	ACSC_DisableExt							acsc_DisableExt;
	ACSC_KillAll							acsc_KillAll;
	ACSC_KillM								acsc_KillM;
	ACSC_Line								acsc_Line;
	ACSC_LoadBuffer							acsc_LoadBuffer;
	ACSC_MultiPoint							acsc_MultiPoint;
	ACSC_MultiPointM						acsc_MultiPointM;
	ACSC_BoostedPointToPointMotion    	    acsc_BoostedPointToPointMotion;
	ACSC_SmoothPointToPointMotion			acsc_SmoothPointToPointMotion;
	ACSC_SmoothTransitionPointToPointMotion	acsc_SmoothTransitionPointToPointMotion;
	ACSC_OpenCommDirect						acsc_OpenCommDirect;
	ACSC_CloseSimulator						acsc_CloseSimulator;
	ACSC_OpenCommSimulator					acsc_OpenCommSimulator;
	ACSC_OpenCommEthernet					acsc_OpenCommEthernet;
	ACSC_OpenCommEthernetUDP				acsc_OpenCommEthernetUDP;
	ACSC_OpenCommEthernetTCP				acsc_OpenCommEthernetTCP;
	ACSC_OpenCommSerial						acsc_OpenCommSerial;
	ACSC_OpenCommPCI						acsc_OpenCommPCI;
	ACSC_OpenHistoryBuffer					acsc_OpenHistoryBuffer;
	ACSC_OpenLogFile						acsc_OpenLogFile;
	ACSC_OpenSCLogFile						acsc_OpenSCLogFile;
	ACSC_OpenMessageBuffer					acsc_OpenMessageBuffer;
	ACSC_Projection							acsc_Projection;
	ACSC_ReadDPRAMInteger					acsc_ReadDPRAMInteger;
	ACSC_ReadDPRAMReal						acsc_ReadDPRAMReal;
	ACSC_ReadInteger						acsc_ReadInteger;
	ACSC_ReadReal							acsc_ReadReal;
	ACSC_ReadString							acsc_ReadString;
	ACSC_ReadStruct						    acsc_ReadStruct;
	ACSC_WriteStruct						acsc_WriteStruct;
	ACSC_Receive							acsc_Receive;
	ACSC_ReleaseComm						acsc_ReleaseComm;
	ACSC_ResetIndexState					acsc_ResetIndexState;
	ACSC_RunBuffer							acsc_RunBuffer;
	ACSC_Segment							acsc_Segment;
	ACSC_Send								acsc_Send;
	ACSC_SetAcceleration					acsc_SetAcceleration;
	ACSC_SetAccelerationImm					acsc_SetAccelerationImm;
	ACSC_SetAnalogOutput					acsc_SetAnalogOutput;
	ACSC_SetBreakpoint						acsc_SetBreakpoint;
	ACSC_SetCallback						acsc_SetCallback;
	ACSC_SetCallbackPriority				acsc_SetCallbackPriority;
	ACSC_SetCommOptions						acsc_SetCommOptions;
	ACSC_SetDeceleration					acsc_SetDeceleration;
	ACSC_SetDecelerationImm					acsc_SetDecelerationImm;
	ACSC_SetExtOutput						acsc_SetExtOutput;
	ACSC_SetExtOutputPort					acsc_SetExtOutputPort;
	ACSC_SetFPosition						acsc_SetFPosition;
	ACSC_SetFaultMask						acsc_SetFaultMask;
	ACSC_SetInterruptMask					acsc_SetInterruptMask;
	ACSC_SetCallbackMask					acsc_SetCallbackMask;
	ACSC_SetCallbackMaskExt					acsc_SetCallbackMaskExt;
	ACSC_SetIterations						acsc_SetIterations;
	ACSC_SetJerk							acsc_SetJerk;
	ACSC_SetJerkImm							acsc_SetJerkImm;
	ACSC_SetKillDeceleration				acsc_SetKillDeceleration;
	ACSC_SetKillDecelerationImm				acsc_SetKillDecelerationImm;
	ACSC_SetMaster							acsc_SetMaster;
	ACSC_SetOutput							acsc_SetOutput;
	ACSC_SetOutputPort						acsc_SetOutputPort;
	ACSC_SetRPosition						acsc_SetRPosition;
	ACSC_SetResponseMask					acsc_SetResponseMask;
	ACSC_SetSafetyInputPortInv				acsc_SetSafetyInputPortInv;
	ACSC_SetTimeout							acsc_SetTimeout;
	ACSC_SetVelocity						acsc_SetVelocity;
	ACSC_SetVelocityImm						acsc_SetVelocityImm;
	ACSC_Slave								acsc_Slave;
	ACSC_SlaveStalled						acsc_SlaveStalled;
	ACSC_Spline								acsc_Spline;
	ACSC_SplineM							acsc_SplineM;
	ACSC_Split								acsc_Split;
	ACSC_SplitAll							acsc_SplitAll;
	ACSC_StopBuffer							acsc_StopBuffer;
	ACSC_StopCollect						acsc_StopCollect;
	ACSC_Stopper							acsc_Stopper;
	ACSC_SuspendBuffer						acsc_SuspendBuffer;
	ACSC_ToPoint							acsc_ToPoint;
	ACSC_ToPointM							acsc_ToPointM;
	ACSC_Transaction						acsc_Transaction;
	ACSC_UploadBuffer						acsc_UploadBuffer;
	ACSC_WaitCollectEnd						acsc_WaitCollectEnd;
	ACSC_WaitCollectEndExt					acsc_WaitCollectEndExt;
	ACSC_WaitSPDataCollectionEnd			acsc_WaitSPDataCollectionEnd;
	ACSC_WaitForAsyncCall					acsc_WaitForAsyncCall;
	ACSC_WaitInput							acsc_WaitInput;
	ACSC_WaitLogicalMotionEnd				acsc_WaitLogicalMotionEnd;
	ACSC_WaitMotionEnd						acsc_WaitMotionEnd;
	ACSC_WaitMotorEnabled					acsc_WaitMotorEnabled;
	ACSC_WaitMotorCommutated				acsc_WaitMotorCommutated;
	ACSC_WaitProgramEnd						acsc_WaitProgramEnd;
	ACSC_WaitUserCondition					acsc_WaitUserCondition;
	ACSC_WriteDPRAMInteger					acsc_WriteDPRAMInteger;
	ACSC_WriteDPRAMReal						acsc_WriteDPRAMReal;
	ACSC_WriteInteger						acsc_WriteInteger;
	ACSC_WriteLogFile						acsc_WriteLogFile;
	ACSC_WriteSCLogFile						acsc_WriteSCLogFile;
	ACSC_WriteReal							acsc_WriteReal;
	ACSC_WriteString						acsc_WriteString;
	ACSC_LoadBufferIgnoreServiceLines		acsc_LoadBufferIgnoreServiceLines;
	ACSC_LoadBuffersFromFile				acsc_LoadBuffersFromFile;

	ACSC_PegI								acsc_PegI;
	ACSC_PegR								acsc_PegR;
	ACSC_PegInc								acsc_PegInc;
	ACSC_PegRandom							acsc_PegRandom;
	ACSC_AssignPins							acsc_AssignPins;
	ACSC_StopPeg							acsc_StopPeg;

	ACSC_AssignPegNT						acsc_AssignPegNT;
	ACSC_AssignPegNTV2						acsc_AssignPegNTV2;
	ACSC_AssignPegOutputsNT					acsc_AssignPegOutputsNT;
	ACSC_AssignFastInputsNT					acsc_AssignFastInputsNT;
	ACSC_PegIncNT							acsc_PegIncNT;
	ACSC_PegIncNTV2							acsc_PegIncNTV2;
	ACSC_PegRandomNT						acsc_PegRandomNT;
	ACSC_PegRandomNTV2						acsc_PegRandomNTV2;
	ACSC_WaitPegReadyNT						acsc_WaitPegReadyNT;
	ACSC_StartPegNT							acsc_StartPegNT;
	ACSC_StopPegNT							acsc_StopPegNT;

	ACSC_CollectB							acsc_CollectB;
	ACSC_DataCollection                     acsc_DataCollection;
	ACSC_DataCollectionExt					acsc_DataCollectionExt;
	ACSC_SPDataCollectionStart				acsc_SPDataCollectionStart;
	ACSC_SPDataCollectionStop				acsc_SPDataCollectionStop;
	ACSC_GetSPAddress						acsc_GetSPAddress;
	ACSC_AddPVPoint							acsc_AddPVPoint;
	ACSC_AddPVPointM						acsc_AddPVPointM;
	ACSC_AddPVTPoint						acsc_AddPVTPoint;
	ACSC_AddPVTPointM						acsc_AddPVTPointM;
	ACSC_LoadFileToRealVariable				acsc_LoadFileToRealVariable;
	ACSC_LoadFileToIntegerVariable			acsc_LoadFileToIntegerVariable;
	ACSC_LoadDataToController               acsc_LoadDataToController;
	ACSC_UploadDataFromController           acsc_UploadDataFromController;
	ACSC_SetQueueOverflowTimeout			acsc_SetQueueOverflowTimeout;
	ACSC_GetQueueOverflowTimeout			acsc_GetQueueOverflowTimeout;
	ACSC_SetTargetPosition					acsc_SetTargetPosition;
	ACSC_GetTargetPosition					acsc_GetTargetPosition;
	ACSC_SetTargetPositionM					acsc_SetTargetPositionM;
	ACSC_Track								acsc_Track;
	ACSC_TrackM								acsc_TrackM;
	ACSC_FaultClearM						acsc_FaultClearM;
	ACSC_FaultClear							acsc_FaultClear;
	ACSC_Getconf							acsc_Getconf;
	ACSC_Setconf							acsc_Setconf;
	ACSC_GetConf							acsc_GetConf;
	ACSC_SetConf							acsc_SetConf;
	ACSC_SysInfo							acsc_SysInfo;

	ACSC_GetAxesCount						acsc_GetAxesCount;
	ACSC_GetBuffersCount					acsc_GetBuffersCount;
	ACSC_GetDBufferIndex					acsc_GetDBufferIndex;

	ACSC_SetCallbackExt						acsc_SetCallbackExt;
	ACSC_InstallCallback					acsc_InstallCallback;
	ACSC_InstallCallbackExt					acsc_InstallCallbackExt;
	ACSC_DownloadBinVariableToFile			acsc_DownloadBinVariableToFile;
	ACSC_SetLogFileOptions					acsc_SetLogFileOptions;

	ACSC_SetServer							acsc_SetServer;
	ACSC_SetServerExt					    acsc_SetServerExt;
	ACSC_SetServerExtLogin					acsc_SetServerExtLogin;

	ACSC_GetSingleMessage					acsc_GetSingleMessage;

	ACSC_GetConnectionsList			    	acsc_GetConnectionsList;
	ACSC_GetConnectionInfo			    	acsc_GetConnectionInfo;
	ACSC_TerminateConnection				acsc_TerminateConnection;

	ACSC_GetLogData							acsc_GetLogData;

	ACSC_RegisterEmergencyStop              acsc_RegisterEmergencyStop;
	ACSC_UnregisterEmergencyStop			acsc_UnregisterEmergencyStop;

	ACSC_GetUMDVersion						acsc_GetUMDVersion;

	ACSC_AnalyzeApplication                 acsc_AnalyzeApplication;
	ACSC_FreeApplication		        	acsc_FreeApplication;
	ACSC_SaveApplication                    acsc_SaveApplication;
	ACSC_LoadApplication		        	acsc_LoadApplication;

	ACSC_WaitForResult						acsc_WaitForResult;
	ACSC_ReadTypeless						acsc_ReadTypeless;
	ACSC_ReadTypeless2						acsc_ReadTypeless2;
	ACSC_RawTransaction						acsc_RawTransaction;
	ACSC_Transaction2						acsc_Transaction2;
	ACSC_Transaction3						acsc_Transaction3;
	ACSC_FreeBufferMemory					acsc_FreeBufferMemory;
	ACSC_UploadEntireBuffer					acsc_UploadEntireBuffer;
	ACSC_FRF_FreeFRD_Matrix_Internal		acsc_FRF_FreeFRD_Matrix_Internal;
	ACSC_FFT						   		acsc_FFT;
	ACSC_FRF_Measure					   	acsc_FRF_Measure;
	ACSC_FRF_FreeFRD_Internal				acsc_FRF_FreeFRD_Internal;
	ACSC_FRF_CalculateSLVRAT				acsc_FRF_CalculateSLVRAT;
	ACSC_FRF_CalculateLoopDataFRD			acsc_FRF_CalculateLoopDataFRD;
	ACSC_FRF_CrossCouplingMeasure			acsc_FRF_CrossCouplingMeasure;
	ACSC_FRF_FreeCalculateLoopData			acsc_FRF_FreeCalculateLoopData;
	ACSC_FRF_Stop					       	acsc_FRF_Stop;
	ACSC_FRF_CalculateMeasurementDuration	acsc_FRF_CalculateMeasurementDuration;
	ACSC_FRF_InitInput						acsc_FRF_InitInput;
	ACSC_FRF_FreeOutput						acsc_FRF_FreeOutput;
	ACSC_FRF_FreeCrossCouplingOutput		acsc_FRF_FreeCrossCouplingOutput;
	ACSC_FRF_ReadServoParameters			acsc_FRF_ReadServoParameters;
	ACSC_FRF_CalculateControllerFRD			acsc_FRF_CalculateControllerFRD;
	ACSC_FRF_CalculateOpenLoopFRD			acsc_FRF_CalculateOpenLoopFRD;
	ACSC_FRF_CalculateClosedLoopFRD			acsc_FRF_CalculateClosedLoopFRD;
	ACSC_FRF_CalculateStabilityMargins		acsc_FRF_CalculateStabilityMargins;
	ACSC_FRF_FreeFRD						acsc_FRF_FreeFRD;
	ACSC_FRF_FreeStabilityMargins			acsc_FRF_FreeStabilityMargins;

	ACSC_JitterAnalysis						acsc_JitterAnalysis;
	ACSC_JitterAnalysis_FreeOutput			acsc_JitterAnalysis_FreeOutput;

	ACSC_ControllerReboot					acsc_ControllerReboot;
	ACSC_ControllerFactoryDefault			acsc_ControllerFactoryDefault;
	ACSC_ControllerSaveToFlash				acsc_ControllerSaveToFlash;
	
	ACSC_DefineControllerProtection			acsc_DefineControllerProtection;
	ACSC_RemoveControllerProtection			acsc_RemoveControllerProtection;
	ACSC_TemporarilyDisableVariableProtection		acsc_TemporarilyDisableVariableProtection;
	ACSC_RestoreVariableProtection			acsc_RestoreVariableProtection;

	ACSC_GetSharedMemoryAddress				acsc_GetSharedMemoryAddress;
	ACSC_ReadSharedMemoryReal				acsc_ReadSharedMemoryReal;
	ACSC_ReadSharedMemoryInteger			acsc_ReadSharedMemoryInteger;
	ACSC_WriteSharedMemoryReal				acsc_WriteSharedMemoryReal;
	ACSC_WriteSharedMemoryInteger			acsc_WriteSharedMemoryInteger;

	ACSC_GetEtherCATState					acsc_GetEtherCATState;
	ACSC_GetEtherCATError					acsc_GetEtherCATError;
	ACSC_MapEtherCATInput					acsc_MapEtherCATInput;
	ACSC_MapEtherCATOutput					acsc_MapEtherCATOutput;
	ACSC_UnmapEtherCATInputsOutputs			acsc_UnmapEtherCATInputsOutputs;
	ACSC_GetEtherCATSlaveIndex				acsc_GetEtherCATSlaveIndex;
	ACSC_GetEtherCATSlaveOffset				acsc_GetEtherCATSlaveOffset;
	ACSC_GetEtherCATSlaveOffsetV2			acsc_GetEtherCATSlaveOffsetV2;
	ACSC_GetEtherCATSlaveVendorID			acsc_GetEtherCATSlaveVendorID;
	ACSC_GetEtherCATSlaveVendorIDV2			acsc_GetEtherCATSlaveVendorIDV2;
	ACSC_GetEtherCATSlaveSerialNumber		acsc_GetEtherCATSlaveSerialNumber;
	ACSC_GetEtherCATSlaveProductID			acsc_GetEtherCATSlaveProductID;
	ACSC_GetEtherCATSlaveProductIDV2		acsc_GetEtherCATSlaveProductIDV2;
	ACSC_GetEtherCATSlaveRevision			acsc_GetEtherCATSlaveRevision;
	ACSC_GetEtherCATSlaveRevisionV2			acsc_GetEtherCATSlaveRevisionV2;
	ACSC_GetEtherCATSlaveType				acsc_GetEtherCATSlaveType;
	ACSC_GetEtherCATSlaveState				acsc_GetEtherCATSlaveState;
	ACSC_GetEtherCATSlaveStateV2			acsc_GetEtherCATSlaveStateV2;
	ACSC_DownloadFileOverEtherCAT			acsc_DownloadFileOverEtherCAT;
	ACSC_ReadSDOValueOverEtherCAT			acsc_ReadSDOValueOverEtherCAT;
	ACSC_WriteSDOValueOverEtherCAT			acsc_WriteSDOValueOverEtherCAT;
	ACSC_GetEtherCATSlaveRegister           acsc_GetEtherCATSlaveRegister;
	ACSC_ClearEtherCATSlaveRegister			acsc_ClearEtherCATSlaveRegister;
	ACSC_GetEtherCATSlavesCount				acsc_GetEtherCATSlavesCount;

	ACSC_DynamicErrorCompensationOn			acsc_DynamicErrorCompensationOn;
	ACSC_DynamicErrorCompensationOff		acsc_DynamicErrorCompensationOff;
	ACSC_DynamicErrorCompensationRemove		acsc_DynamicErrorCompensationRemove;
	ACSC_DynamicErrorCompensation1D			acsc_DynamicErrorCompensation1D;
	ACSC_DynamicErrorCompensationN1D		acsc_DynamicErrorCompensationN1D;
	ACSC_DynamicErrorCompensationA1D		acsc_DynamicErrorCompensationA1D;
	ACSC_DynamicErrorCompensation2D			acsc_DynamicErrorCompensation2D;
	ACSC_DynamicErrorCompensationN2D		acsc_DynamicErrorCompensationN2D;
	ACSC_DynamicErrorCompensationA2D		acsc_DynamicErrorCompensationA2D;
	ACSC_DynamicErrorCompensation3D2		acsc_DynamicErrorCompensation3D2;
	ACSC_DynamicErrorCompensation3D3		acsc_DynamicErrorCompensation3D3;
	ACSC_DynamicErrorCompensation3D5		acsc_DynamicErrorCompensation3D5;
	ACSC_DynamicErrorCompensation3DA		acsc_DynamicErrorCompensation3DA;
	ACSC_DynamicErrorCompensationN3D2		acsc_DynamicErrorCompensationN3D2;
	ACSC_DynamicErrorCompensationN3D3		acsc_DynamicErrorCompensationN3D3;
	ACSC_DynamicErrorCompensationN3D5		acsc_DynamicErrorCompensationN3D5;
	ACSC_DynamicErrorCompensationN3DA		acsc_DynamicErrorCompensationN3DA;

	ACSC_CopyFileToController				acsc_CopyFileToController;
	ACSC_DeleteFileFromController			acsc_DeleteFileFromController;

	ACSC_SegmentedMotion					acsc_SegmentedMotion;
	ACSC_ExtendedSegmentedMotion			acsc_ExtendedSegmentedMotion;
	ACSC_ExtendedSegmentedMotionExt			acsc_ExtendedSegmentedMotionExt;
	ACSC_ExtendedSegmentedMotionV2          acsc_ExtendedSegmentedMotionV2;
	ACSC_SegmentLine						acsc_SegmentLine;
	ACSC_SegmentLineExt						acsc_SegmentLineExt;
	ACSC_SegmentLineV2						acsc_SegmentLineV2;
	ACSC_SegmentArc1						acsc_SegmentArc1;
	ACSC_SegmentArc1Ext						acsc_SegmentArc1Ext;
	ACSC_SegmentArc2						acsc_SegmentArc2;
	ACSC_SegmentArc2Ext						acsc_SegmentArc2Ext;
	ACSC_ExtendedSegmentArc1				acsc_ExtendedSegmentArc1;
	ACSC_ExtendedSegmentArc2				acsc_ExtendedSegmentArc2;
	ACSC_SegmentArc1V2						acsc_SegmentArc1V2;
	ACSC_SegmentArc2V2						acsc_SegmentArc2V2;
	ACSC_BlendedSegmentMotion				acsc_BlendedSegmentMotion;
	ACSC_BlendedLine						acsc_BlendedLine;
	ACSC_BlendedArc1						acsc_BlendedArc1;
	ACSC_BlendedArc2						acsc_BlendedArc2;
	ACSC_GetAnalogInputNT					acsc_GetAnalogInputNT;
	ACSC_GetAnalogOutputNT					acsc_GetAnalogOutputNT;
	ACSC_SetAnalogOutputNT					acsc_SetAnalogOutputNT;

	ACSC_GetVolatileMemoryUsage				acsc_GetVolatileMemoryUsage;
	ACSC_GetVolatileMemoryTotal				acsc_GetVolatileMemoryTotal;
	ACSC_GetVolatileMemoryFree				acsc_GetVolatileMemoryFree;
	ACSC_GetNonVolatileMemoryUsage			acsc_GetNonVolatileMemoryUsage;
	ACSC_GetNonVolatileMemoryTotal			acsc_GetNonVolatileMemoryTotal;
	ACSC_GetNonVolatileMemoryFree			acsc_GetNonVolatileMemoryFree;

	ACSC_StartSPiiPlusSC					acsc_StartSPiiPlusSC;
	ACSC_StopSPiiPlusSC						acsc_StopSPiiPlusSC;

	ACSC_NurbsMotion						acsc_NurbsMotion;
	ACSC_NurbsPoints						acsc_NurbsPoints;
	ACSC_SmoothPathMotion					acsc_SmoothPathMotion;
	ACSC_SmoothPathSegment					acsc_SmoothPathSegment;

	static HMODULE hACSCLibraryModule;

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSCL_x86.DLL or ACSCL_x64.DLL and obtains addresses for all exported functions.
	// Call this function before any using of ACSC API.
	// Check return value for success.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	static int InitLibrary(const TCHAR* dllname)
	{
		if (dllname == NULL)
			return 0;
		

		hACSCLibraryModule = LoadLibrary(dllname);


		if (hACSCLibraryModule == NULL)
			return 0;

		acsc_AddMPoint = (ACSC_AddMPoint)GetProcAddress(hACSCLibraryModule, "acsc_AddMPoint");																//	   2
		acsc_AddMPointM = (ACSC_AddMPointM)GetProcAddress(hACSCLibraryModule, "acsc_AddMPointM");															//     3
		acsc_AddPoint = (ACSC_AddPoint)GetProcAddress(hACSCLibraryModule, "acsc_AddPoint");																	//     4
		acsc_AddPointM = (ACSC_AddPointM)GetProcAddress(hACSCLibraryModule, "acsc_AddPointM");																//	   5
		acsc_AppendBuffer = (ACSC_AppendBuffer)GetProcAddress(hACSCLibraryModule, "acsc_AppendBuffer");														//	   6
		acsc_Arc1 = (ACSC_Arc1)GetProcAddress(hACSCLibraryModule, "acsc_Arc1");																				//	   7
		acsc_Arc2 = (ACSC_Arc2)GetProcAddress(hACSCLibraryModule, "acsc_Arc2");																				//	   8
		acsc_Break = (ACSC_Break)GetProcAddress(hACSCLibraryModule, "acsc_Break");																			//     9
		acsc_BreakM = (ACSC_BreakM)GetProcAddress(hACSCLibraryModule, "acsc_BreakM");																		//     10
		acsc_CancelOperation = (ACSC_CancelOperation)GetProcAddress(hACSCLibraryModule, "acsc_CancelOperation");												//     11
		acsc_CaptureComm = (ACSC_CaptureComm)GetProcAddress(hACSCLibraryModule, "acsc_CaptureComm");															//     12
		acsc_ClearBuffer = (ACSC_ClearBuffer)GetProcAddress(hACSCLibraryModule, "acsc_ClearBuffer");														//     13
		acsc_ClearVariables = (ACSC_ClearVariables)GetProcAddress(hACSCLibraryModule, "acsc_ClearVariables");												//     14
		acsc_CloseComm = (ACSC_CloseComm)GetProcAddress(hACSCLibraryModule, "acsc_CloseComm");																//     15
		acsc_CloseHistoryBuffer = (ACSC_CloseHistoryBuffer)GetProcAddress(hACSCLibraryModule, "acsc_CloseHistoryBuffer");									//     16
		acsc_CloseLogFile = (ACSC_CloseLogFile)GetProcAddress(hACSCLibraryModule, "acsc_CloseLogFile");														//     17
		acsc_CloseMessageBuffer = (ACSC_CloseMessageBuffer)GetProcAddress(hACSCLibraryModule, "acsc_CloseMessageBuffer");									//     18
		acsc_Collect = (ACSC_Collect)GetProcAddress(hACSCLibraryModule, "acsc_Collect");																	//     19
		acsc_Command = (ACSC_Command)GetProcAddress(hACSCLibraryModule, "acsc_Command");																	//     20
		acsc_CompileBuffer = (ACSC_CompileBuffer)GetProcAddress(hACSCLibraryModule, "acsc_CompileBuffer");													//     21
		acsc_DeclareVariable = (ACSC_DeclareVariable)GetProcAddress(hACSCLibraryModule, "acsc_DeclareVariable");											//     22
		acsc_Disable = (ACSC_Disable)GetProcAddress(hACSCLibraryModule, "acsc_Disable");																	//     23
		acsc_DisableAll = (ACSC_DisableAll)GetProcAddress(hACSCLibraryModule, "acsc_DisableAll");															//     24
		acsc_DisableFault = (ACSC_DisableFault)GetProcAddress(hACSCLibraryModule, "acsc_DisableFault");														//     25
		acsc_DisableM = (ACSC_DisableM)GetProcAddress(hACSCLibraryModule, "acsc_DisableM");																	//     26
		acsc_DisableResponse = (ACSC_DisableResponse)GetProcAddress(hACSCLibraryModule, "acsc_DisableResponse");											//     27
		acsc_DownloadBuffer = (ACSC_DownloadBuffer)GetProcAddress(hACSCLibraryModule, "acsc_DownloadBuffer");												//     28
		acsc_Enable = (ACSC_Enable)GetProcAddress(hACSCLibraryModule, "acsc_Enable");																		//     29
		acsc_EnableFault = (ACSC_EnableFault)GetProcAddress(hACSCLibraryModule, "acsc_EnableFault");														//     30
		acsc_EnableM = (ACSC_EnableM)GetProcAddress(hACSCLibraryModule, "acsc_EnableM");																	//     31
		acsc_EnableResponse = (ACSC_EnableResponse)GetProcAddress(hACSCLibraryModule, "acsc_EnableResponse");												//     32
		acsc_EndSequence = (ACSC_EndSequence)GetProcAddress(hACSCLibraryModule, "acsc_EndSequence");														//     33
		acsc_EndSequenceM = (ACSC_EndSequenceM)GetProcAddress(hACSCLibraryModule, "acsc_EndSequenceM");														//     34
		acsc_ExtAddPoint = (ACSC_ExtAddPoint)GetProcAddress(hACSCLibraryModule, "acsc_ExtAddPoint");														//     35
		acsc_ExtAddPointM = (ACSC_ExtAddPointM)GetProcAddress(hACSCLibraryModule, "acsc_ExtAddPointM");														//     36
		acsc_ExtArc1 = (ACSC_ExtArc1)GetProcAddress(hACSCLibraryModule, "acsc_ExtArc1");																	//     37
		acsc_ExtArc2 = (ACSC_ExtArc2)GetProcAddress(hACSCLibraryModule, "acsc_ExtArc2");																	//     38
		acsc_ExtLine = (ACSC_ExtLine)GetProcAddress(hACSCLibraryModule, "acsc_ExtLine");																	//     39
		acsc_ExtToPoint = (ACSC_ExtToPoint)GetProcAddress(hACSCLibraryModule, "acsc_ExtToPoint");															//     40
		acsc_ExtToPointM = (ACSC_ExtToPointM)GetProcAddress(hACSCLibraryModule, "acsc_ExtToPointM");														//     41
		acsc_GetAcceleration = (ACSC_GetAcceleration)GetProcAddress(hACSCLibraryModule, "acsc_GetAcceleration");											//     42
		acsc_GetAnalogInput = (ACSC_GetAnalogInput)GetProcAddress(hACSCLibraryModule, "acsc_GetAnalogInput");												//     43
		acsc_GetAnalogOutput = (ACSC_GetAnalogOutput)GetProcAddress(hACSCLibraryModule, "acsc_GetAnalogOutput");											//     44
		acsc_GetAxisState = (ACSC_GetAxisState)GetProcAddress(hACSCLibraryModule, "acsc_GetAxisState");														//     45
		acsc_GetCommOptions = (ACSC_GetCommOptions)GetProcAddress(hACSCLibraryModule, "acsc_GetCommOptions");												//     46
		acsc_GetDeceleration = (ACSC_GetDeceleration)GetProcAddress(hACSCLibraryModule, "acsc_GetDeceleration");											//     47
		acsc_GetDefaultTimeout = (ACSC_GetDefaultTimeout)GetProcAddress(hACSCLibraryModule, "acsc_GetDefaultTimeout");										//     48
		acsc_GetErrorString = (ACSC_GetErrorString)GetProcAddress(hACSCLibraryModule, "acsc_GetErrorString");												//     49
		acsc_GetExtInput = (ACSC_GetExtInput)GetProcAddress(hACSCLibraryModule, "acsc_GetExtInput");														//     50
		acsc_GetExtInputPort = (ACSC_GetExtInputPort)GetProcAddress(hACSCLibraryModule, "acsc_GetExtInputPort");											//     51
		acsc_GetExtOutput = (ACSC_GetExtOutput)GetProcAddress(hACSCLibraryModule, "acsc_GetExtOutput");														//     52
		acsc_GetExtOutputPort = (ACSC_GetExtOutputPort)GetProcAddress(hACSCLibraryModule, "acsc_GetExtOutputPort");											//     53
		acsc_GetFPosition = (ACSC_GetFPosition)GetProcAddress(hACSCLibraryModule, "acsc_GetFPosition");														//     54
		acsc_GetFVelocity = (ACSC_GetFVelocity)GetProcAddress(hACSCLibraryModule, "acsc_GetFVelocity");														//     55
		acsc_GetFault = (ACSC_GetFault)GetProcAddress(hACSCLibraryModule, "acsc_GetFault");																	//     56
		acsc_GetFaultMask = (ACSC_GetFaultMask)GetProcAddress(hACSCLibraryModule, "acsc_GetFaultMask");														//     57
		acsc_GetFirmwareVersion = (ACSC_GetFirmwareVersion)GetProcAddress(hACSCLibraryModule, "acsc_GetFirmwareVersion");									//     58
		acsc_GetHistory = (ACSC_GetHistory)GetProcAddress(hACSCLibraryModule, "acsc_GetHistory");															//     59
		acsc_GetIndexState = (ACSC_GetIndexState)GetProcAddress(hACSCLibraryModule, "acsc_GetIndexState");													//     60
		acsc_GetInput = (ACSC_GetInput)GetProcAddress(hACSCLibraryModule, "acsc_GetInput");																	//     61
		acsc_GetInputPort = (ACSC_GetInputPort)GetProcAddress(hACSCLibraryModule, "acsc_GetInputPort");														//     62
		acsc_GetInterruptMask = (ACSC_GetInterruptMask)GetProcAddress(hACSCLibraryModule, "acsc_GetInterruptMask");											//     63
		acsc_GetJerk = (ACSC_GetJerk)GetProcAddress(hACSCLibraryModule, "acsc_GetJerk");																	//     64
		acsc_GetKillDeceleration = (ACSC_GetKillDeceleration)GetProcAddress(hACSCLibraryModule, "acsc_GetKillDeceleration");								//     65
		acsc_GetLastError = (ACSC_GetLastError)GetProcAddress(hACSCLibraryModule, "acsc_GetLastError");														//     66
		acsc_GetLibraryVersion = (ACSC_GetLibraryVersion)GetProcAddress(hACSCLibraryModule, "acsc_GetLibraryVersion");										//     67
		acsc_GetMessage = (ACSC_GetMessage)GetProcAddress(hACSCLibraryModule, "acsc_GetMessage");															//     68
		acsc_GetMotionError = (ACSC_GetMotionError)GetProcAddress(hACSCLibraryModule, "acsc_GetMotionError");												//     69
		acsc_GetMotorError = (ACSC_GetMotorError)GetProcAddress(hACSCLibraryModule, "acsc_GetMotorError");													//     70
		acsc_GetMotorState = (ACSC_GetMotorState)GetProcAddress(hACSCLibraryModule, "acsc_GetMotorState");													//     71
		acsc_GetOutput = (ACSC_GetOutput)GetProcAddress(hACSCLibraryModule, "acsc_GetOutput");																//     72
		acsc_GetOutputPort = (ACSC_GetOutputPort)GetProcAddress(hACSCLibraryModule, "acsc_GetOutputPort");													//     73
		acsc_GetPCICards = (ACSC_GetPCICards)GetProcAddress(hACSCLibraryModule, "acsc_GetPCICards");														//     74
		acsc_GetProgramError = (ACSC_GetProgramError)GetProcAddress(hACSCLibraryModule, "acsc_GetProgramError");											//     75
		acsc_GetProgramState = (ACSC_GetProgramState)GetProcAddress(hACSCLibraryModule, "acsc_GetProgramState");											//     76
		acsc_GetRPosition = (ACSC_GetRPosition)GetProcAddress(hACSCLibraryModule, "acsc_GetRPosition");														//     77
		acsc_GetRVelocity = (ACSC_GetRVelocity)GetProcAddress(hACSCLibraryModule, "acsc_GetRVelocity");														//     78
		acsc_GetResponseMask = (ACSC_GetResponseMask)GetProcAddress(hACSCLibraryModule, "acsc_GetResponseMask");											//     79
		acsc_GetSafetyInput = (ACSC_GetSafetyInput)GetProcAddress(hACSCLibraryModule, "acsc_GetSafetyInput");												//     80
		acsc_GetSafetyInputPort = (ACSC_GetSafetyInputPort)GetProcAddress(hACSCLibraryModule, "acsc_GetSafetyInputPort");									//     81
		acsc_GetSafetyInputPortInv = (ACSC_GetSafetyInputPortInv)GetProcAddress(hACSCLibraryModule, "acsc_GetSafetyInputPortInv");							//     82
		acsc_GetSerialNumber = (ACSC_GetSerialNumber)GetProcAddress(hACSCLibraryModule, "acsc_GetSerialNumber");											//     83
		acsc_GetTimeout = (ACSC_GetTimeout)GetProcAddress(hACSCLibraryModule, "acsc_GetTimeout");															//     84
		acsc_GetVelocity = (ACSC_GetVelocity)GetProcAddress(hACSCLibraryModule, "acsc_GetVelocity");														//     85
		acsc_Go = (ACSC_Go)GetProcAddress(hACSCLibraryModule, "acsc_Go");																					//     86
		acsc_GoM = (ACSC_GoM)GetProcAddress(hACSCLibraryModule, "acsc_GoM");																				//     87
		acsc_Group = (ACSC_Group)GetProcAddress(hACSCLibraryModule, "acsc_Group");																			//     88
		acsc_Halt = (ACSC_Halt)GetProcAddress(hACSCLibraryModule, "acsc_Halt");																				//     89
		acsc_HaltM = (ACSC_HaltM)GetProcAddress(hACSCLibraryModule, "acsc_HaltM");																			//     90
		acsc_Jog = (ACSC_Jog)GetProcAddress(hACSCLibraryModule, "acsc_Jog");																				//     91
		acsc_JogM = (ACSC_JogM)GetProcAddress(hACSCLibraryModule, "acsc_JogM");																				//     92
		acsc_Kill = (ACSC_Kill)GetProcAddress(hACSCLibraryModule, "acsc_Kill");																				//     93
		acsc_KillAll = (ACSC_KillAll)GetProcAddress(hACSCLibraryModule, "acsc_KillAll");																		//     94
		acsc_KillM = (ACSC_KillM)GetProcAddress(hACSCLibraryModule, "acsc_KillM");																			//     95
		acsc_Line = (ACSC_Line)GetProcAddress(hACSCLibraryModule, "acsc_Line");																				//     96
		acsc_LoadBuffer = (ACSC_LoadBuffer)GetProcAddress(hACSCLibraryModule, "acsc_LoadBuffer");															//     97
		acsc_MultiPoint = (ACSC_MultiPoint)GetProcAddress(hACSCLibraryModule, "acsc_MultiPoint");															//     98
		acsc_MultiPointM = (ACSC_MultiPointM)GetProcAddress(hACSCLibraryModule, "acsc_MultiPointM");														//     99
		acsc_OpenCommDirect = (ACSC_OpenCommDirect)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommDirect");												//     100
		acsc_OpenCommEthernet = (ACSC_OpenCommEthernet)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommEthernet");											//     101
		acsc_OpenCommPCI = (ACSC_OpenCommPCI)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommPCI");															//     102
		acsc_OpenCommSerial = (ACSC_OpenCommSerial)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommSerial");												//     103
		acsc_OpenHistoryBuffer = (ACSC_OpenHistoryBuffer)GetProcAddress(hACSCLibraryModule, "acsc_OpenHistoryBuffer");										//     104
		acsc_OpenLogFile = (ACSC_OpenLogFile)GetProcAddress(hACSCLibraryModule, "acsc_OpenLogFile");															//     105
		acsc_OpenMessageBuffer = (ACSC_OpenMessageBuffer)GetProcAddress(hACSCLibraryModule, "acsc_OpenMessageBuffer");										//     106
		acsc_Projection = (ACSC_Projection)GetProcAddress(hACSCLibraryModule, "acsc_Projection");															//     107
		acsc_ReadDPRAMInteger = (ACSC_ReadDPRAMInteger)GetProcAddress(hACSCLibraryModule, "acsc_ReadDPRAMInteger");											//     108
		acsc_ReadDPRAMReal = (ACSC_ReadDPRAMReal)GetProcAddress(hACSCLibraryModule, "acsc_ReadDPRAMReal");													//     109
		acsc_ReadInteger = (ACSC_ReadInteger)GetProcAddress(hACSCLibraryModule, "acsc_ReadInteger");														//     110
		acsc_ReadReal = (ACSC_ReadReal)GetProcAddress(hACSCLibraryModule, "acsc_ReadReal");																	//     111
		acsc_Receive = (ACSC_Receive)GetProcAddress(hACSCLibraryModule, "acsc_Receive");																	//     112
		acsc_ReleaseComm = (ACSC_ReleaseComm)GetProcAddress(hACSCLibraryModule, "acsc_ReleaseComm");															//     113
		acsc_ResetIndexState = (ACSC_ResetIndexState)GetProcAddress(hACSCLibraryModule, "acsc_ResetIndexState");											//     114
		acsc_RunBuffer = (ACSC_RunBuffer)GetProcAddress(hACSCLibraryModule, "acsc_RunBuffer");																//     115
		acsc_Segment = (ACSC_Segment)GetProcAddress(hACSCLibraryModule, "acsc_Segment");																	//     116
		acsc_Send = (ACSC_Send)GetProcAddress(hACSCLibraryModule, "acsc_Send");																				//     117
		acsc_SetAcceleration = (ACSC_SetAcceleration)GetProcAddress(hACSCLibraryModule, "acsc_SetAcceleration");											//     118
		acsc_SetAccelerationImm = (ACSC_SetAccelerationImm)GetProcAddress(hACSCLibraryModule, "acsc_SetAccelerationImm");									//     119
		acsc_SetAnalogOutput = (ACSC_SetAnalogOutput)GetProcAddress(hACSCLibraryModule, "acsc_SetAnalogOutput");											//     120
		acsc_SetCallback = (ACSC_SetCallback)GetProcAddress(hACSCLibraryModule, "acsc_SetCallback");														//     121
		acsc_SetCallbackPriority = (ACSC_SetCallbackPriority)GetProcAddress(hACSCLibraryModule, "acsc_SetCallbackPriority");									//     122
		acsc_SetCommOptions = (ACSC_SetCommOptions)GetProcAddress(hACSCLibraryModule, "acsc_SetCommOptions");												//     123
		acsc_SetDeceleration = (ACSC_SetDeceleration)GetProcAddress(hACSCLibraryModule, "acsc_SetDeceleration");											//     124
		acsc_SetDecelerationImm = (ACSC_SetDecelerationImm)GetProcAddress(hACSCLibraryModule, "acsc_SetDecelerationImm");									//     125
		acsc_SetExtOutput = (ACSC_SetExtOutput)GetProcAddress(hACSCLibraryModule, "acsc_SetExtOutput");														//     126
		acsc_SetExtOutputPort = (ACSC_SetExtOutputPort)GetProcAddress(hACSCLibraryModule, "acsc_SetExtOutputPort");											//     127
		acsc_SetFPosition = (ACSC_SetFPosition)GetProcAddress(hACSCLibraryModule, "acsc_SetFPosition");														//     128
		acsc_SetFaultMask = (ACSC_SetFaultMask)GetProcAddress(hACSCLibraryModule, "acsc_SetFaultMask");														//     129
		acsc_SetInterruptMask = (ACSC_SetInterruptMask)GetProcAddress(hACSCLibraryModule, "acsc_SetInterruptMask");											//     130
		acsc_SetIterations = (ACSC_SetIterations)GetProcAddress(hACSCLibraryModule, "acsc_SetIterations");													//     131
		acsc_SetJerk = (ACSC_SetJerk)GetProcAddress(hACSCLibraryModule, "acsc_SetJerk");																	//     132
		acsc_SetJerkImm = (ACSC_SetJerkImm)GetProcAddress(hACSCLibraryModule, "acsc_SetJerkImm");															//     133
		acsc_SetKillDeceleration = (ACSC_SetKillDeceleration)GetProcAddress(hACSCLibraryModule, "acsc_SetKillDeceleration");								//     134
		acsc_SetKillDecelerationImm = (ACSC_SetKillDecelerationImm)GetProcAddress(hACSCLibraryModule, "acsc_SetKillDecelerationImm");						//     135
		acsc_SetMaster = (ACSC_SetMaster)GetProcAddress(hACSCLibraryModule, "acsc_SetMaster");																//     136
		acsc_SetOutput = (ACSC_SetOutput)GetProcAddress(hACSCLibraryModule, "acsc_SetOutput");																//     137
		acsc_SetOutputPort = (ACSC_SetOutputPort)GetProcAddress(hACSCLibraryModule, "acsc_SetOutputPort");													//     138
		acsc_SetRPosition = (ACSC_SetRPosition)GetProcAddress(hACSCLibraryModule, "acsc_SetRPosition");														//     139
		acsc_SetResponseMask = (ACSC_SetResponseMask)GetProcAddress(hACSCLibraryModule, "acsc_SetResponseMask");											//     140
		acsc_SetSafetyInputPortInv = (ACSC_SetSafetyInputPortInv)GetProcAddress(hACSCLibraryModule, "acsc_SetSafetyInputPortInv");							//     141
		acsc_SetTimeout = (ACSC_SetTimeout)GetProcAddress(hACSCLibraryModule, "acsc_SetTimeout");															//     142
		acsc_SetVelocity = (ACSC_SetVelocity)GetProcAddress(hACSCLibraryModule, "acsc_SetVelocity");														//     143
		acsc_SetVelocityImm = (ACSC_SetVelocityImm)GetProcAddress(hACSCLibraryModule, "acsc_SetVelocityImm");												//     144
		acsc_Slave = (ACSC_Slave)GetProcAddress(hACSCLibraryModule, "acsc_Slave");																			//     145
		acsc_SlaveStalled = (ACSC_SlaveStalled)GetProcAddress(hACSCLibraryModule, "acsc_SlaveStalled");														//     146
		acsc_Spline = (ACSC_Spline)GetProcAddress(hACSCLibraryModule, "acsc_Spline");																		//     147
		acsc_SplineM = (ACSC_SplineM)GetProcAddress(hACSCLibraryModule, "acsc_SplineM");																	//     148
		acsc_Split = (ACSC_Split)GetProcAddress(hACSCLibraryModule, "acsc_Split");																			//     149
		acsc_SplitAll = (ACSC_SplitAll)GetProcAddress(hACSCLibraryModule, "acsc_SplitAll");																	//     150
		acsc_StopBuffer = (ACSC_StopBuffer)GetProcAddress(hACSCLibraryModule, "acsc_StopBuffer");															//     151
		acsc_StopCollect = (ACSC_StopCollect)GetProcAddress(hACSCLibraryModule, "acsc_StopCollect");															//     152
		acsc_Stopper = (ACSC_Stopper)GetProcAddress(hACSCLibraryModule, "acsc_Stopper");																	//     153
		acsc_SuspendBuffer = (ACSC_SuspendBuffer)GetProcAddress(hACSCLibraryModule, "acsc_SuspendBuffer");													//     154
		acsc_ToPoint = (ACSC_ToPoint)GetProcAddress(hACSCLibraryModule, "acsc_ToPoint");																	//     155
		acsc_ToPointM = (ACSC_ToPointM)GetProcAddress(hACSCLibraryModule, "acsc_ToPointM");																	//     156
		acsc_Transaction = (ACSC_Transaction)GetProcAddress(hACSCLibraryModule, "acsc_Transaction");														//     157
		acsc_UploadBuffer = (ACSC_UploadBuffer)GetProcAddress(hACSCLibraryModule, "acsc_UploadBuffer");														//     158
		acsc_WaitCollectEnd = (ACSC_WaitCollectEnd)GetProcAddress(hACSCLibraryModule, "acsc_WaitCollectEnd");												//     159
		acsc_WaitForAsyncCall = (ACSC_WaitForAsyncCall)GetProcAddress(hACSCLibraryModule, "acsc_WaitForAsyncCall");											//     160
		acsc_WaitInput = (ACSC_WaitInput)GetProcAddress(hACSCLibraryModule, "acsc_WaitInput");																//     161
		acsc_WaitLogicalMotionEnd = (ACSC_WaitLogicalMotionEnd)GetProcAddress(hACSCLibraryModule, "acsc_WaitLogicalMotionEnd");								//     162
		acsc_WaitMotionEnd = (ACSC_WaitMotionEnd)GetProcAddress(hACSCLibraryModule, "acsc_WaitMotionEnd");													//     163
		acsc_WaitMotorEnabled = (ACSC_WaitMotorEnabled)GetProcAddress(hACSCLibraryModule, "acsc_WaitMotorEnabled");											//     164
		acsc_WaitProgramEnd = (ACSC_WaitProgramEnd)GetProcAddress(hACSCLibraryModule, "acsc_WaitProgramEnd");												//     165
		acsc_WaitUserCondition = (ACSC_WaitUserCondition)GetProcAddress(hACSCLibraryModule, "acsc_WaitUserCondition");										//     166
		acsc_WriteDPRAMInteger = (ACSC_WriteDPRAMInteger)GetProcAddress(hACSCLibraryModule, "acsc_WriteDPRAMInteger");										//     167
		acsc_WriteDPRAMReal = (ACSC_WriteDPRAMReal)GetProcAddress(hACSCLibraryModule, "acsc_WriteDPRAMReal");												//     168
		acsc_WriteInteger = (ACSC_WriteInteger)GetProcAddress(hACSCLibraryModule, "acsc_WriteInteger");														//     169
		acsc_WriteLogFile = (ACSC_WriteLogFile)GetProcAddress(hACSCLibraryModule, "acsc_WriteLogFile");														//     170
		acsc_WriteReal = (ACSC_WriteReal)GetProcAddress(hACSCLibraryModule, "acsc_WriteReal");																//     171
		acsc_LoadBufferIgnoreServiceLines = (ACSC_LoadBufferIgnoreServiceLines)GetProcAddress(hACSCLibraryModule, "acsc_LoadBufferIgnoreServiceLines");		//     196
		acsc_PegI = (ACSC_PegI)GetProcAddress(hACSCLibraryModule, "acsc_PegI");																				//     197
		acsc_PegR = (ACSC_PegR)GetProcAddress(hACSCLibraryModule, "acsc_PegR");																				//     198
		acsc_AssignPins = (ACSC_AssignPins)GetProcAddress(hACSCLibraryModule, "acsc_AssignPins");															//	   199
		acsc_StopPeg = (ACSC_StopPeg)GetProcAddress(hACSCLibraryModule, "acsc_StopPeg");																	//	   200
		acsc_CollectB = (ACSC_CollectB)GetProcAddress(hACSCLibraryModule, "acsc_CollectB");																	//     201
		acsc_AddPVPoint = (ACSC_AddPVPoint)GetProcAddress(hACSCLibraryModule, "acsc_AddPVPoint");															//     202
		acsc_AddPVPointM = (ACSC_AddPVPointM)GetProcAddress(hACSCLibraryModule, "acsc_AddPVPointM");														//     203
		acsc_AddPVTPoint = (ACSC_AddPVTPoint)GetProcAddress(hACSCLibraryModule, "acsc_AddPVTPoint");														//     204
		acsc_AddPVTPointM = (ACSC_AddPVTPointM)GetProcAddress(hACSCLibraryModule, "acsc_AddPVTPointM");														//     205
		acsc_LoadFileToRealVariable = (ACSC_LoadFileToRealVariable)GetProcAddress(hACSCLibraryModule, "acsc_LoadFileToRealVariable");						//     206
		acsc_LoadFileToIntegerVariable = (ACSC_LoadFileToIntegerVariable)GetProcAddress(hACSCLibraryModule, "acsc_LoadFileToIntegerVariable");				//     207
		acsc_SetQueueOverflowTimeout = (ACSC_SetQueueOverflowTimeout)GetProcAddress(hACSCLibraryModule, "acsc_SetQueueOverflowTimeout");						//     208
		acsc_GetQueueOverflowTimeout = (ACSC_GetQueueOverflowTimeout)GetProcAddress(hACSCLibraryModule, "acsc_GetQueueOverflowTimeout");						//     209
		acsc_LoadBuffersFromFile = (ACSC_LoadBuffersFromFile)GetProcAddress(hACSCLibraryModule, "acsc_LoadBuffersFromFile");								//     210
		acsc_SetTargetPosition = (ACSC_SetTargetPosition)GetProcAddress(hACSCLibraryModule, "acsc_SetTargetPosition");										//     211
		acsc_GetTargetPosition = (ACSC_GetTargetPosition)GetProcAddress(hACSCLibraryModule, "acsc_GetTargetPosition");										//     212
		acsc_SetTargetPositionM = (ACSC_SetTargetPositionM)GetProcAddress(hACSCLibraryModule, "acsc_SetTargetPositionM");									//     213
		acsc_Track = (ACSC_Track)GetProcAddress(hACSCLibraryModule, "acsc_Track");																			//     214
		acsc_TrackM = (ACSC_TrackM)GetProcAddress(hACSCLibraryModule, "acsc_TrackM");																		//     215
		acsc_FaultClearM = (ACSC_FaultClearM)GetProcAddress(hACSCLibraryModule, "acsc_FaultClearM");														//     216
		acsc_FaultClear = (ACSC_FaultClear)GetProcAddress(hACSCLibraryModule, "acsc_FaultClear");															//     217
		acsc_Getconf = (ACSC_Getconf)GetProcAddress(hACSCLibraryModule, "acsc_Getconf");																	//     218
		acsc_Setconf = (ACSC_Setconf)GetProcAddress(hACSCLibraryModule, "acsc_Setconf");																	//     219
		acsc_SetCallbackExt = (ACSC_SetCallbackExt)GetProcAddress(hACSCLibraryModule, "acsc_SetCallbackExt");												//	   222
		acsc_DownloadBinVariableToFile = (ACSC_DownloadBinVariableToFile)GetProcAddress(hACSCLibraryModule, "acsc_DownloadBinVariableToFile");				//     223
		acsc_SetLogFileOptions = (ACSC_SetLogFileOptions)GetProcAddress(hACSCLibraryModule, "acsc_SetLogFileOptions");										//	   224

		acsc_KillExt = (ACSC_KillExt)GetProcAddress(hACSCLibraryModule, "acsc_KillExt");																	//	   225
		acsc_DisableExt = (ACSC_DisableExt)GetProcAddress(hACSCLibraryModule, "acsc_DisableExt");															//	   226

		acsc_GetConf = (ACSC_GetConf)GetProcAddress(hACSCLibraryModule, "acsc_GetConf");																	//	   228
		acsc_SetConf = (ACSC_SetConf)GetProcAddress(hACSCLibraryModule, "acsc_SetConf");																	//	   229
		acsc_SetServer = (ACSC_SetServer)GetProcAddress(hACSCLibraryModule, "acsc_SetServer");																//	   230
		acsc_GetSingleMessage = (ACSC_GetSingleMessage)GetProcAddress(hACSCLibraryModule, "acsc_GetSingleMessage");											//	   231

		acsc_GetCallbackMask = (ACSC_GetCallbackMask)GetProcAddress(hACSCLibraryModule, "acsc_GetCallbackMask");											//     232
		acsc_SetCallbackMask = (ACSC_SetCallbackMask)GetProcAddress(hACSCLibraryModule, "acsc_SetCallbackMask");											//     233
		acsc_InstallCallback = (ACSC_InstallCallback)GetProcAddress(hACSCLibraryModule, "acsc_InstallCallback");											//	   234
		acsc_PegInc = (ACSC_PegInc)GetProcAddress(hACSCLibraryModule, "acsc_PegInc");																		//     235
		acsc_PegRandom = (ACSC_PegRandom)GetProcAddress(hACSCLibraryModule, "acsc_PegRandom");																//     236
		acsc_Commut = (ACSC_Commut)GetProcAddress(hACSCLibraryModule, "acsc_Commut");																		//     237
		acsc_WaitMotorCommutated = (ACSC_WaitMotorCommutated)GetProcAddress(hACSCLibraryModule, "acsc_WaitMotorCommutated");								//     238
		acsc_GetConnectionsList = (ACSC_GetConnectionsList)GetProcAddress(hACSCLibraryModule, "acsc_GetConnectionsList");									//     245
		acsc_TerminateConnection = (ACSC_TerminateConnection)GetProcAddress(hACSCLibraryModule, "acsc_TerminateConnection");									//     246
		acsc_SetServerExt = (ACSC_SetServerExt)GetProcAddress(hACSCLibraryModule, "acsc_SetServerExt");														//     247
		acsc_SetServerExtLogin = (ACSC_SetServerExtLogin)GetProcAddress(hACSCLibraryModule, "acsc_SetServerExtLogin");										//     248
		acsc_DataCollection = (ACSC_DataCollection)GetProcAddress(hACSCLibraryModule, "acsc_DataCollection");												//     249
		acsc_LoadDataToController = (ACSC_LoadDataToController)GetProcAddress(hACSCLibraryModule, "acsc_LoadDataToController");								//     250
		acsc_RegisterEmergencyStop = (ACSC_RegisterEmergencyStop)GetProcAddress(hACSCLibraryModule, "acsc_RegisterEmergencyStop");							//     251
		acsc_UnregisterEmergencyStop = (ACSC_UnregisterEmergencyStop)GetProcAddress(hACSCLibraryModule, "acsc_UnregisterEmergencyStop");						//     252
		acsc_UploadDataFromController = (ACSC_UploadDataFromController)GetProcAddress(hACSCLibraryModule, "acsc_UploadDataFromController");					//     253
		acsc_AnalyzeApplication = (ACSC_AnalyzeApplication)GetProcAddress(hACSCLibraryModule, "acsc_AnalyzeApplication");									//     254
		acsc_FreeApplication = (ACSC_FreeApplication)GetProcAddress(hACSCLibraryModule, "acsc_FreeApplication");												//     255
		acsc_SaveApplication = (ACSC_SaveApplication)GetProcAddress(hACSCLibraryModule, "acsc_SaveApplication");											//     256
		acsc_LoadApplication = (ACSC_LoadApplication)GetProcAddress(hACSCLibraryModule, "acsc_LoadApplication");											//     257
		acsc_GetUMDVersion = (ACSC_GetUMDVersion)GetProcAddress(hACSCLibraryModule, "acsc_GetUMDVersion");													//	   258

		acsc_OpenCommEthernetTCP = (ACSC_OpenCommEthernetTCP)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommEthernetTCP");									//     259
		acsc_OpenCommEthernetUDP = (ACSC_OpenCommEthernetUDP)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommEthernetUDP");									//     260
		acsc_ControllerReboot = (ACSC_ControllerReboot)GetProcAddress(hACSCLibraryModule, "acsc_ControllerReboot");											//     262
		acsc_ControllerFactoryDefault = (ACSC_ControllerFactoryDefault)GetProcAddress(hACSCLibraryModule, "acsc_ControllerFactoryDefault");					//     263

		acsc_GetSharedMemoryAddress = (ACSC_GetSharedMemoryAddress)GetProcAddress(hACSCLibraryModule, "acsc_GetSharedMemoryAddress");						//     264
		acsc_ReadSharedMemoryReal = (ACSC_ReadSharedMemoryReal)GetProcAddress(hACSCLibraryModule, "acsc_ReadSharedMemoryReal");								//     265
		acsc_ReadSharedMemoryInteger = (ACSC_ReadSharedMemoryInteger)GetProcAddress(hACSCLibraryModule, "acsc_ReadSharedMemoryInteger");					//     266
		acsc_WriteSharedMemoryReal = (ACSC_WriteSharedMemoryReal)GetProcAddress(hACSCLibraryModule, "acsc_WriteSharedMemoryReal");							//     267
		acsc_WriteSharedMemoryInteger = (ACSC_WriteSharedMemoryInteger)GetProcAddress(hACSCLibraryModule, "acsc_WriteSharedMemoryInteger");					//     268

		acsc_SysInfo = (ACSC_SysInfo)GetProcAddress(hACSCLibraryModule, "acsc_SysInfo");																	//	   269

		acsc_GetAxesCount = (ACSC_GetAxesCount)GetProcAddress(hACSCLibraryModule, "acsc_GetAxesCount");														//	   270
		acsc_GetBuffersCount = (ACSC_GetBuffersCount)GetProcAddress(hACSCLibraryModule, "acsc_GetBuffersCount");											//	   271
		acsc_GetDBufferIndex = (ACSC_GetDBufferIndex)GetProcAddress(hACSCLibraryModule, "acsc_GetDBufferIndex");											//	   272

		acsc_AssignPegNT = (ACSC_AssignPegNT)GetProcAddress(hACSCLibraryModule, "acsc_AssignPegNT");														//	   273
		acsc_AssignPegOutputsNT = (ACSC_AssignPegOutputsNT)GetProcAddress(hACSCLibraryModule, "acsc_AssignPegOutputsNT");									//	   274
		acsc_AssignFastInputsNT = (ACSC_AssignFastInputsNT)GetProcAddress(hACSCLibraryModule, "acsc_AssignFastInputsNT");									//	   275
		acsc_PegIncNT = (ACSC_PegIncNT)GetProcAddress(hACSCLibraryModule, "acsc_PegIncNT");																	//	   276
		acsc_PegRandomNT = (ACSC_PegRandomNT)GetProcAddress(hACSCLibraryModule, "acsc_PegRandomNT");														//	   277
		acsc_WaitPegReadyNT = (ACSC_WaitPegReadyNT)GetProcAddress(hACSCLibraryModule, "acsc_WaitPegReadyNT");												//	   278
		acsc_StartPegNT = (ACSC_StartPegNT)GetProcAddress(hACSCLibraryModule, "acsc_StartPegNT");															//	   279
		acsc_StopPegNT = (ACSC_StopPegNT)GetProcAddress(hACSCLibraryModule, "acsc_StopPegNT");																//	   280

		acsc_GetEtherCATState = (ACSC_GetEtherCATState)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATState");											//     281
		acsc_GetEtherCATError = (ACSC_GetEtherCATError)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATError");											//     282
		acsc_MapEtherCATInput = (ACSC_MapEtherCATInput)GetProcAddress(hACSCLibraryModule, "acsc_MapEtherCATInput");											//     283
		acsc_MapEtherCATOutput = (ACSC_MapEtherCATOutput)GetProcAddress(hACSCLibraryModule, "acsc_MapEtherCATOutput");										//     284
		acsc_UnmapEtherCATInputsOutputs = (ACSC_UnmapEtherCATInputsOutputs)GetProcAddress(hACSCLibraryModule, "acsc_UnmapEtherCATInputsOutputs");			//     285
		acsc_GetEtherCATSlaveIndex = (ACSC_GetEtherCATSlaveIndex)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveIndex");							//     286
		acsc_GetEtherCATSlaveOffset = (ACSC_GetEtherCATSlaveOffset)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveOffset");						//     287
		acsc_GetEtherCATSlaveVendorID = (ACSC_GetEtherCATSlaveVendorID)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveVendorID");					//     288
		acsc_GetEtherCATSlaveProductID = (ACSC_GetEtherCATSlaveProductID)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveProductID");				//     289
		acsc_GetEtherCATSlaveRevision = (ACSC_GetEtherCATSlaveRevision)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveRevision");					//     290
		acsc_GetEtherCATSlaveType = (ACSC_GetEtherCATSlaveType)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveType");								//     291
		acsc_GetEtherCATSlaveState = (ACSC_GetEtherCATSlaveState)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveState");							//     292
		acsc_DownloadFileOverEtherCAT = (ACSC_DownloadFileOverEtherCAT)GetProcAddress(hACSCLibraryModule, "acsc_DownloadFileOverEtherCAT");					//     293
		acsc_ReadSDOValueOverEtherCAT = (ACSC_ReadSDOValueOverEtherCAT)GetProcAddress(hACSCLibraryModule, "acsc_ReadSDOValueOverEtherCAT");					//     294
		acsc_WriteSDOValueOverEtherCAT = (ACSC_WriteSDOValueOverEtherCAT)GetProcAddress(hACSCLibraryModule, "acsc_WriteSDOValueOverEtherCAT");				//     295

		acsc_GetConnectionInfo = (ACSC_GetConnectionInfo)GetProcAddress(hACSCLibraryModule, "acsc_GetConnectionInfo");										//     296
		acsc_GetLogData = (ACSC_GetLogData)GetProcAddress(hACSCLibraryModule, "acsc_GetLogData");															//     297

		acsc_OpenSCLogFile = (ACSC_OpenSCLogFile)GetProcAddress(hACSCLibraryModule, "acsc_OpenSCLogFile");													//     298
		acsc_CloseSCLogFile = (ACSC_CloseSCLogFile)GetProcAddress(hACSCLibraryModule, "acsc_CloseSCLogFile");												//     299
		acsc_WriteSCLogFile = (ACSC_WriteSCLogFile)GetProcAddress(hACSCLibraryModule, "acsc_WriteSCLogFile");												//     300
		acsc_FlushSCLogFile = (ACSC_FlushSCLogFile)GetProcAddress(hACSCLibraryModule, "acsc_FlushSCLogFile");												//     301
		acsc_FlushLogFile = (ACSC_FlushLogFile)GetProcAddress(hACSCLibraryModule, "acsc_FlushLogFile");														//     302

		acsc_DataCollectionExt = (ACSC_DataCollectionExt)GetProcAddress(hACSCLibraryModule, "acsc_DataCollectionExt");										//     303

		acsc_CopyFileToController = (ACSC_CopyFileToController)GetProcAddress(hACSCLibraryModule, "acsc_CopyFileToController");								//     304

		acsc_SegmentedMotion = (ACSC_SegmentedMotion)GetProcAddress(hACSCLibraryModule, "acsc_SegmentedMotion");											//     305
		acsc_ExtendedSegmentedMotion = (ACSC_ExtendedSegmentedMotion)GetProcAddress(hACSCLibraryModule, "acsc_ExtendedSegmentedMotion");					//     306
		acsc_SegmentLine = (ACSC_SegmentLine)GetProcAddress(hACSCLibraryModule, "acsc_SegmentLine");														//     307
		acsc_SegmentArc1 = (ACSC_SegmentArc1)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc1");														//	   308
		acsc_SegmentArc2 = (ACSC_SegmentArc2)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc2");														//	   309

		acsc_GetAnalogInputNT = (ACSC_GetAnalogInputNT)GetProcAddress(hACSCLibraryModule, "acsc_GetAnalogInputNT");											//     310
		acsc_GetAnalogOutputNT = (ACSC_GetAnalogOutputNT)GetProcAddress(hACSCLibraryModule, "acsc_GetAnalogOutputNT");										//     311
		acsc_SetAnalogOutputNT = (ACSC_SetAnalogOutputNT)GetProcAddress(hACSCLibraryModule, "acsc_SetAnalogOutputNT");										//     312

		acsc_GetVolatileMemoryUsage = (ACSC_GetVolatileMemoryUsage)GetProcAddress(hACSCLibraryModule, "acsc_GetVolatileMemoryUsage");						//     313
		acsc_GetVolatileMemoryTotal = (ACSC_GetVolatileMemoryTotal)GetProcAddress(hACSCLibraryModule, "acsc_GetVolatileMemoryTotal");						//     314
		acsc_GetVolatileMemoryFree = (ACSC_GetVolatileMemoryFree)GetProcAddress(hACSCLibraryModule, "acsc_GetVolatileMemoryFree");							//     315
		acsc_GetNonVolatileMemoryUsage = (ACSC_GetNonVolatileMemoryUsage)GetProcAddress(hACSCLibraryModule, "acsc_GetNonVolatileMemoryUsage");				//     316
		acsc_GetNonVolatileMemoryTotal = (ACSC_GetNonVolatileMemoryTotal)GetProcAddress(hACSCLibraryModule, "acsc_GetNonVolatileMemoryTotal");				//     317
		acsc_GetNonVolatileMemoryFree = (ACSC_GetNonVolatileMemoryFree)GetProcAddress(hACSCLibraryModule, "acsc_GetNonVolatileMemoryFree");					//     318

		acsc_DeleteFileFromController = (ACSC_DeleteFileFromController)GetProcAddress(hACSCLibraryModule, "acsc_DeleteFileFromController");					//     319

		acsc_ControllerSaveToFlash = (ACSC_ControllerSaveToFlash)GetProcAddress(hACSCLibraryModule, "acsc_ControllerSaveToFlash");							//     320

		acsc_StartSPiiPlusSC = (ACSC_StartSPiiPlusSC)GetProcAddress(hACSCLibraryModule, "acsc_StartSPiiPlusSC");												//     321
		acsc_StopSPiiPlusSC = (ACSC_StopSPiiPlusSC)GetProcAddress(hACSCLibraryModule, "acsc_StopSPiiPlusSC");												//     322

		acsc_OpenCommSimulator = (ACSC_OpenCommSimulator)GetProcAddress(hACSCLibraryModule, "acsc_OpenCommSimulator");										//     323
		acsc_CloseSimulator = (ACSC_CloseSimulator)GetProcAddress(hACSCLibraryModule, "acsc_CloseSimulator");												//     324

		acsc_ClearBreakpoints = (ACSC_ClearBreakpoints)GetProcAddress(hACSCLibraryModule, "acsc_ClearBreakpoints");											//     325
		acsc_SetBreakpoint = (ACSC_SetBreakpoint)GetProcAddress(hACSCLibraryModule, "acsc_SetBreakpoints");													//     326
		acsc_GetBreakpointsList = (ACSC_GetBreakpointsList)GetProcAddress(hACSCLibraryModule, "acsc_GetBreakpointsList");									//     327
		acsc_GetEthernetCards = (ACSC_GetEthernetCards)GetProcAddress(hACSCLibraryModule, "acsc_GetEthernetCards");											//	   328

		acsc_WaitCollectEndExt = (ACSC_WaitCollectEndExt)GetProcAddress(hACSCLibraryModule, "acsc_WaitCollectEndExt");										//	   329
		acsc_CommutExt = (ACSC_CommutExt)GetProcAddress(hACSCLibraryModule, "acsc_CommutExt");																//     330

		acsc_SegmentLineExt = (ACSC_SegmentLineExt)GetProcAddress(hACSCLibraryModule, "acsc_SegmentLine");													//     331
		acsc_SegmentArc1Ext = (ACSC_SegmentArc1Ext)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc1");													//	   332
		acsc_SegmentArc2Ext = (ACSC_SegmentArc2Ext)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc2");													//	   333
		acsc_ExtendedSegmentedMotionExt = (ACSC_ExtendedSegmentedMotionExt)GetProcAddress(hACSCLibraryModule, "acsc_ExtendedSegmentedMotion");				//     334
		acsc_BlendedSegmentMotion = (ACSC_BlendedSegmentMotion)GetProcAddress(hACSCLibraryModule, "acsc_BlendedSegmentMotion");								//     335
		acsc_BlendedLine = (ACSC_BlendedLine)GetProcAddress(hACSCLibraryModule, "acsc_BlendedLine");														//     336
		acsc_BlendedArc1 = (ACSC_BlendedArc1)GetProcAddress(hACSCLibraryModule, "acsc_BlendedArc1");														//     337
		acsc_BlendedArc2 = (ACSC_BlendedArc2)GetProcAddress(hACSCLibraryModule, "acsc_BlendedArc2");														//     338

		acsc_ExtendedSegmentArc1 = (ACSC_ExtendedSegmentArc1)GetProcAddress(hACSCLibraryModule, "acsc_ExtendedSegmentArc1");								//     339
		acsc_ExtendedSegmentArc2 = (ACSC_ExtendedSegmentArc2)GetProcAddress(hACSCLibraryModule, "acsc_ExtendedSegmentArc2");								//     340

		acsc_FFT = (ACSC_FFT)GetProcAddress(hACSCLibraryModule, "acsc_FFT");																				//     341
		acsc_FRF_CalculateClosedLoopFRD = (ACSC_FRF_CalculateClosedLoopFRD)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateClosedLoopFRD");           //     342
		acsc_FRF_CalculateControllerFRD = (ACSC_FRF_CalculateControllerFRD)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateControllerFRD");           //     343
		acsc_FRF_CalculateMeasurementDuration = (ACSC_FRF_CalculateMeasurementDuration)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateMeasurementDuration");	//     344!
		acsc_FRF_CalculateOpenLoopFRD = (ACSC_FRF_CalculateOpenLoopFRD)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateOpenLoopFRD");                 //     345
		acsc_FRF_CalculateStabilityMargins = (ACSC_FRF_CalculateStabilityMargins)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateStabilityMargins");  //     346
		acsc_FRF_FreeFRD = (ACSC_FRF_FreeFRD)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeFRD");															//     347
		acsc_FRF_FreeOutput = (ACSC_FRF_FreeOutput)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeOutput");												//     348
		acsc_FRF_FreeStabilityMargins = (ACSC_FRF_FreeStabilityMargins)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeStabilityMargins");                  //     349
		acsc_FRF_InitInput = (ACSC_FRF_InitInput)GetProcAddress(hACSCLibraryModule, "acsc_FRF_InitInput");													//     350
		acsc_FRF_Measure = (ACSC_FRF_Measure)GetProcAddress(hACSCLibraryModule, "acsc_FRF_Measure");														//     351
		acsc_FRF_ReadServoParameters = (ACSC_FRF_ReadServoParameters)GetProcAddress(hACSCLibraryModule, "acsc_FRF_ReadServoParameters");                    //     352
		acsc_FRF_Stop = (ACSC_FRF_Stop)GetProcAddress(hACSCLibraryModule, "acsc_FRF_Stop");																	//     353
		acsc_JitterAnalysis = (ACSC_JitterAnalysis)GetProcAddress(hACSCLibraryModule, "acsc_JitterAnalysis");                                               //     354   
		acsc_JitterAnalysis_FreeOutput = (ACSC_JitterAnalysis_FreeOutput)GetProcAddress(hACSCLibraryModule, "acsc_JitterAnalysis_FreeOutput");               //     355
		acsc_InstallCallbackExt = (ACSC_InstallCallbackExt)GetProcAddress(hACSCLibraryModule, "acsc_InstallCallbackExt");									//	   356
		acsc_SetCallbackMaskExt = (ACSC_SetCallbackMaskExt)GetProcAddress(hACSCLibraryModule, "acsc_SetCallbackMaskExt");									//	   357
		acsc_GetCallbackMaskExt = (ACSC_GetCallbackMaskExt)GetProcAddress(hACSCLibraryModule, "acsc_GetCallbackMaskExt");									//	   358
		acsc_GetEthernetCardsExt = (ACSC_GetEthernetCardsExt)GetProcAddress(hACSCLibraryModule, "acsc_GetEthernetCardsExt");					     			//     359
		acsc_ExtendedSegmentedMotionV2 = (ACSC_ExtendedSegmentedMotionV2)GetProcAddress(hACSCLibraryModule, "acsc_ExtendedSegmentedMotionV2");				//     360
		acsc_SegmentLineV2 = (ACSC_SegmentLineV2)GetProcAddress(hACSCLibraryModule, "acsc_SegmentLineV2");													//     361
		acsc_SegmentArc1V2 = (ACSC_SegmentArc1V2)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc1V2");													//     362
		acsc_SegmentArc2V2 = (ACSC_SegmentArc2V2)GetProcAddress(hACSCLibraryModule, "acsc_SegmentArc2V2");													//     363
		acsc_NurbsMotion = (ACSC_NurbsMotion)GetProcAddress(hACSCLibraryModule, "acsc_NurbsMotion");														//     364
		acsc_NurbsPoints = (ACSC_NurbsPoints)GetProcAddress(hACSCLibraryModule, "acsc_NurbsPoints");														//     365
		acsc_SmoothPathMotion = (ACSC_SmoothPathMotion)GetProcAddress(hACSCLibraryModule, "acsc_SmoothPathMotion");										    //     366
		acsc_SmoothPathSegment = (ACSC_SmoothPathSegment)GetProcAddress(hACSCLibraryModule, "acsc_SmoothPathSegment");										//     367
		acsc_BoostedPointToPointMotion = (ACSC_BoostedPointToPointMotion)GetProcAddress(hACSCLibraryModule, "acsc_BoostedPointToPointMotion");				//     368
		acsc_AssignPegNTV2 = (ACSC_AssignPegNTV2)GetProcAddress(hACSCLibraryModule, "acsc_AssignPegNTV2");											    	//	   369
		acsc_SmoothPointToPointMotion = (ACSC_SmoothPointToPointMotion)GetProcAddress(hACSCLibraryModule, "acsc_SmoothPointToPointMotion");					//	   370
		acsc_SmoothTransitionPointToPointMotion = (ACSC_SmoothTransitionPointToPointMotion)GetProcAddress(hACSCLibraryModule, "acsc_SmoothTransitionPointToPointMotion");	//	   371
		acsc_GetEtherCATSlaveVendorIDV2 = (ACSC_GetEtherCATSlaveVendorIDV2)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveVendorIDV2");			//     372
		acsc_GetEtherCATSlaveProductIDV2 = (ACSC_GetEtherCATSlaveProductIDV2)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveProductIDV2");		//     373
		acsc_GetEtherCATSlaveRevisionV2 = (ACSC_GetEtherCATSlaveRevisionV2)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveRevisionV2");			//     374
		acsc_GetEtherCATSlaveStateV2 = (ACSC_GetEtherCATSlaveStateV2)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveStateV2");					//     375
		acsc_GetEtherCATSlaveOffsetV2 = (ACSC_GetEtherCATSlaveOffsetV2)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveOffsetV2");					//     376
		acsc_GetEtherCATSlaveSerialNumber = (ACSC_GetEtherCATSlaveSerialNumber)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveSerialNumber");	    //     377
		acsc_GetEtherCATSlaveRegister = (ACSC_GetEtherCATSlaveRegister)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlaveRegister");					//     378
		acsc_ClearEtherCATSlaveRegister = (ACSC_ClearEtherCATSlaveRegister)GetProcAddress(hACSCLibraryModule, "acsc_ClearEtherCATSlaveRegister");	        //     379
		acsc_ReadString = (ACSC_ReadString)GetProcAddress(hACSCLibraryModule, "acsc_ReadString");															//     380
		acsc_WriteString = (ACSC_WriteString)GetProcAddress(hACSCLibraryModule, "acsc_WriteString");														//     381
		acsc_GetEtherCATSlavesCount = (ACSC_GetEtherCATSlavesCount)GetProcAddress(hACSCLibraryModule, "acsc_GetEtherCATSlavesCount");					    //     382
		acsc_DynamicErrorCompensationOn = (ACSC_DynamicErrorCompensationOn)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationOn");			//     383
		acsc_DynamicErrorCompensationOff = (ACSC_DynamicErrorCompensationOff)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationOff");	    //     384
		acsc_DynamicErrorCompensationRemove = (ACSC_DynamicErrorCompensationRemove)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationRemove");	//     385
		acsc_DynamicErrorCompensation1D = (ACSC_DynamicErrorCompensation1D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation1D");		    //     386
		acsc_DynamicErrorCompensationN1D = (ACSC_DynamicErrorCompensationN1D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN1D");	    //     387
		acsc_DynamicErrorCompensationA1D = (ACSC_DynamicErrorCompensationA1D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationA1D");	    //     388
		acsc_FRF_FreeCrossCouplingOutput = (ACSC_FRF_FreeCrossCouplingOutput)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeCrossCouplingOutput");			//     389
		acsc_DynamicErrorCompensation2D = (ACSC_DynamicErrorCompensation2D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation2D");		    //     390
		acsc_DynamicErrorCompensationN2D = (ACSC_DynamicErrorCompensationN2D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN2D");	    //     391
		acsc_DynamicErrorCompensationA2D = (ACSC_DynamicErrorCompensationA2D)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationA2D");	    //     392
		acsc_DynamicErrorCompensation3D2 = (ACSC_DynamicErrorCompensation3D2)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation3D2");	    //     393
		acsc_DynamicErrorCompensation3D3 = (ACSC_DynamicErrorCompensation3D3)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation3D3");	    //     394
		acsc_DynamicErrorCompensation3D5 = (ACSC_DynamicErrorCompensation3D5)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation3D5");	    //     395
		acsc_DynamicErrorCompensation3DA = (ACSC_DynamicErrorCompensation3DA)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensation3DA");	    //     396
		acsc_DynamicErrorCompensationN3D2 = (ACSC_DynamicErrorCompensationN3D2)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN3D2");	    //     397
		acsc_DynamicErrorCompensationN3D3 = (ACSC_DynamicErrorCompensationN3D3)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN3D3");	    //     398
		acsc_DynamicErrorCompensationN3D5 = (ACSC_DynamicErrorCompensationN3D5)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN3D5");	    //     399
		acsc_DynamicErrorCompensationN3DA = (ACSC_DynamicErrorCompensationN3DA)GetProcAddress(hACSCLibraryModule, "acsc_DynamicErrorCompensationN3DA");	    //     400
		acsc_PegIncNTV2 = (ACSC_PegIncNTV2)GetProcAddress(hACSCLibraryModule, "acsc_PegIncNTV2");															//	   401
		acsc_PegRandomNTV2 = (ACSC_PegRandomNTV2)GetProcAddress(hACSCLibraryModule, "acsc_PegRandomNTV2");												    //	   402
		acsc_SPDataCollectionStart = (ACSC_SPDataCollectionStart)GetProcAddress(hACSCLibraryModule, "acsc_SPDataCollectionStart");							//	   403
		acsc_SPDataCollectionStop = (ACSC_SPDataCollectionStop)GetProcAddress(hACSCLibraryModule, "acsc_SPDataCollectionStop");								//	   404
		acsc_GetSPAddress = (ACSC_GetSPAddress)GetProcAddress(hACSCLibraryModule, "acsc_GetSPAddress");														//	   405
		acsc_WaitSPDataCollectionEnd = (ACSC_WaitSPDataCollectionEnd)GetProcAddress(hACSCLibraryModule, "acsc_WaitSPDataCollectionEnd");					//	   406
		acsc_ReadStruct = (ACSC_ReadStruct)GetProcAddress(hACSCLibraryModule, "acsc_ReadStruct");															//     407
		acsc_WriteStruct = (ACSC_WriteStruct)GetProcAddress(hACSCLibraryModule, "acsc_WriteStruct");														//     408
		acsc_DefineControllerProtection = (ACSC_DefineControllerProtection)GetProcAddress(hACSCLibraryModule, "acsc_DefineControllerProtection");			//     409
		acsc_RemoveControllerProtection = (ACSC_RemoveControllerProtection)GetProcAddress(hACSCLibraryModule, "acsc_RemoveControllerProtection");			//     410
		acsc_TemporarilyDisableVariableProtection = (ACSC_TemporarilyDisableVariableProtection)GetProcAddress(hACSCLibraryModule, "acsc_TemporarilyDisableVariableProtection");			//     411
		acsc_RestoreVariableProtection = (ACSC_RestoreVariableProtection)GetProcAddress(hACSCLibraryModule, "acsc_RestoreVariableProtection");				//     412
		acsc_FRF_CrossCouplingMeasure = (ACSC_FRF_CrossCouplingMeasure)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CrossCouplingMeasure");					//     413
		acsc_FRF_FreeCalculateLoopData = (ACSC_FRF_FreeCalculateLoopData)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeCalculateLoopData");				//     414
		acsc_FRF_CalculateLoopDataFRD = (ACSC_FRF_CalculateLoopDataFRD)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateLoopDataFRD");					//     415
		acsc_FRF_CalculateSLVRAT = (ACSC_FRF_CalculateSLVRAT)GetProcAddress(hACSCLibraryModule, "acsc_FRF_CalculateSLVRAT");								//     416
		acsc_FRF_FreeFRD_Internal = (ACSC_FRF_FreeFRD_Internal)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeFRD_Internal");								//     417
		acsc_WaitForResult = (ACSC_WaitForResult)GetProcAddress(hACSCLibraryModule, "acsc_WaitForResult");													//     418
		acsc_ReadTypeless = (ACSC_ReadTypeless)GetProcAddress(hACSCLibraryModule, "acsc_ReadTypeless");														//     419
		acsc_ReadTypeless2 = (ACSC_ReadTypeless2)GetProcAddress(hACSCLibraryModule, "acsc_ReadTypeless2");												    //     420
		acsc_RawTransaction = (ACSC_RawTransaction)GetProcAddress(hACSCLibraryModule, "acsc_RawTransaction");												//     421
		acsc_Transaction2 = (ACSC_Transaction2)GetProcAddress(hACSCLibraryModule, "acsc_Transaction2");														//     422
		acsc_Transaction3 = (ACSC_Transaction3)GetProcAddress(hACSCLibraryModule, "acsc_Transaction3");														//     423
		acsc_FreeBufferMemory = (ACSC_FreeBufferMemory)GetProcAddress(hACSCLibraryModule, "acsc_FreeBufferMemory");											//     424
		acsc_UploadEntireBuffer = (ACSC_UploadEntireBuffer)GetProcAddress(hACSCLibraryModule, "acsc_UploadEntireBuffer");									//     425
		acsc_FRF_FreeFRD_Matrix_Internal = (ACSC_FRF_FreeFRD_Matrix_Internal)GetProcAddress(hACSCLibraryModule, "acsc_FRF_FreeFRD_Matrix_Internal");		//     426

		return 1;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSCL_x64.DLL and obtains addresses for all exported functions.
	// Call this function before any using of ACSC API.
	// Check return value for success.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	static int InitACSCLibrary64()
	{
		return InitLibrary(_T("ACSCL_x64.dll"));
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function loads ACSCL_x86.DLL and obtains addresses for all exported functions.
	// Call this function before any using of ACSC API.
	// Check return value for success.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	static int InitACSCLibrary()
	{
		return InitLibrary(_T("ACSCL_x86.dll"));
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	// The function unmapps from the address space of the calling process.
	//////////////////////////////////////////////////////////////////////////////////////////////////
	static int FreeACSCLibrary()
	{
		return FreeLibrary(hACSCLibraryModule);
	}

#else // defined (ACSC_RUNTIME_DYNAMIC_VARIABLES)

	extern ACSC_AddMPoint						acsc_AddMPoint;
	extern ACSC_AddMPointM						acsc_AddMPointM;
	extern ACSC_AddPoint						acsc_AddPoint;
	extern ACSC_AddPointM						acsc_AddPointM;
	extern ACSC_AppendBuffer					acsc_AppendBuffer;
	extern ACSC_Arc1							acsc_Arc1;
	extern ACSC_Arc2							acsc_Arc2;
	extern ACSC_Break							acsc_Break;
	extern ACSC_BreakM							acsc_BreakM;
	extern ACSC_CancelOperation					acsc_CancelOperation;
	extern ACSC_CaptureComm						acsc_CaptureComm;
	extern ACSC_ClearBuffer						acsc_ClearBuffer;
	extern ACSC_ClearVariables					acsc_ClearVariables;
	extern ACSC_CloseComm						acsc_CloseComm;
	extern ACSC_CloseHistoryBuffer				acsc_CloseHistoryBuffer;
	extern ACSC_CloseLogFile					acsc_CloseLogFile;
	extern ACSC_CloseSCLogFile					acsc_CloseSCLogFile;
	extern ACSC_CloseMessageBuffer				acsc_CloseMessageBuffer;
	extern ACSC_Collect							acsc_Collect;
	extern ACSC_Command							acsc_Command;
	extern ACSC_Commut							acsc_Commut;
	extern ACSC_CommutExt						acsc_CommutExt;
	extern ACSC_CompileBuffer					acsc_CompileBuffer;
	extern ACSC_DeclareVariable					acsc_DeclareVariable;
	extern ACSC_Disable							acsc_Disable;
	extern ACSC_DisableAll						acsc_DisableAll;
	extern ACSC_DisableFault					acsc_DisableFault;
	extern ACSC_DisableM						acsc_DisableM;
	extern ACSC_DisableResponse					acsc_DisableResponse;
	extern ACSC_DownloadBuffer					acsc_DownloadBuffer;
	extern ACSC_Enable							acsc_Enable;
	extern ACSC_EnableFault						acsc_EnableFault;
	extern ACSC_EnableM							acsc_EnableM;
	extern ACSC_EnableResponse					acsc_EnableResponse;
	extern ACSC_EndSequence						acsc_EndSequence;
	extern ACSC_EndSequenceM					acsc_EndSequenceM;
	extern ACSC_ExtAddPoint						acsc_ExtAddPoint;
	extern ACSC_ExtAddPointM					acsc_ExtAddPointM;
	extern ACSC_ExtArc1							acsc_ExtArc1;
	extern ACSC_ExtArc2							acsc_ExtArc2;
	extern ACSC_ExtLine							acsc_ExtLine;
	extern ACSC_ExtToPoint						acsc_ExtToPoint;
	extern ACSC_ExtToPointM						acsc_ExtToPointM;
	extern ACSC_FlushLogFile					acsc_FlushLogFile;
	extern ACSC_FlushSCLogFile					acsc_FlushSCLogFile;
	extern ACSC_GetAcceleration					acsc_GetAcceleration;
	extern ACSC_GetAnalogInput					acsc_GetAnalogInput;
	extern ACSC_GetAnalogOutput					acsc_GetAnalogOutput;
	extern ACSC_GetAxisState					acsc_GetAxisState;
	extern ACSC_GetCommOptions					acsc_GetCommOptions;
	extern ACSC_GetDeceleration					acsc_GetDeceleration;
	extern ACSC_GetDefaultTimeout				acsc_GetDefaultTimeout;
	extern ACSC_GetErrorString					acsc_GetErrorString;
	extern ACSC_GetExtInput						acsc_GetExtInput;
	extern ACSC_GetExtInputPort					acsc_GetExtInputPort;
	extern ACSC_GetExtOutput					acsc_GetExtOutput;
	extern ACSC_GetExtOutputPort				acsc_GetExtOutputPort;
	extern ACSC_GetFPosition					acsc_GetFPosition;
	extern ACSC_GetFVelocity					acsc_GetFVelocity;
	extern ACSC_GetFault						acsc_GetFault;
	extern ACSC_GetFaultMask					acsc_GetFaultMask;
	extern ACSC_GetFirmwareVersion				acsc_GetFirmwareVersion;
	extern ACSC_GetHistory						acsc_GetHistory;
	extern ACSC_GetIndexState					acsc_GetIndexState;
	extern ACSC_GetInput						acsc_GetInput;
	extern ACSC_GetInputPort					acsc_GetInputPort;
	extern ACSC_GetInterruptMask				acsc_GetInterruptMask;
	extern ACSC_GetCallbackMask					acsc_GetCallbackMask;
	extern ACSC_GetCallbackMaskExt				acsc_GetCallbackMaskExt;
	extern ACSC_GetJerk							acsc_GetJerk;
	extern ACSC_GetKillDeceleration				acsc_GetKillDeceleration;
	extern ACSC_GetLastError					acsc_GetLastError;
	extern ACSC_GetLibraryVersion				acsc_GetLibraryVersion;
	extern ACSC_GetMessage						acsc_GetMessage;
	extern ACSC_GetMotionError					acsc_GetMotionError;
	extern ACSC_GetMotorError					acsc_GetMotorError;
	extern ACSC_GetMotorState					acsc_GetMotorState;
	extern ACSC_GetOutput						acsc_GetOutput;
	extern ACSC_GetOutputPort					acsc_GetOutputPort;
	extern ACSC_GetPCICards						acsc_GetPCICards;
	extern ACSC_GetEthernetCards				acsc_GetEthernetCards;
	extern ACSC_GetEthernetCardsExt				acsc_GetEthernetCardsExt;
	extern ACSC_GetProgramError					acsc_GetProgramError;
	extern ACSC_GetProgramState					acsc_GetProgramState;
	extern ACSC_GetRPosition					acsc_GetRPosition;
	extern ACSC_GetRVelocity					acsc_GetRVelocity;
	extern ACSC_GetResponseMask					acsc_GetResponseMask;
	extern ACSC_GetSafetyInput					acsc_GetSafetyInput;
	extern ACSC_GetSafetyInputPort				acsc_GetSafetyInputPort;
	extern ACSC_GetSafetyInputPortInv			acsc_GetSafetyInputPortInv;
	extern ACSC_GetSerialNumber					acsc_GetSerialNumber;
	extern ACSC_GetTimeout						acsc_GetTimeout;
	extern ACSC_GetVelocity						acsc_GetVelocity;
	extern ACSC_Go								acsc_Go;
	extern ACSC_GoM								acsc_GoM;
	extern ACSC_Group							acsc_Group;
	extern ACSC_Halt							acsc_Halt;
	extern ACSC_HaltM							acsc_HaltM;
	extern ACSC_Jog								acsc_Jog;
	extern ACSC_JogM							acsc_JogM;
	extern ACSC_Kill							acsc_Kill;
	extern ACSC_KillExt							acsc_KillExt;
	extern ACSC_DisableExt						acsc_DisableExt;
	extern ACSC_KillAll							acsc_KillAll;
	extern ACSC_KillM							acsc_KillM;
	extern ACSC_Line							acsc_Line;
	extern ACSC_LoadBuffer						acsc_LoadBuffer;
	extern ACSC_MultiPoint						acsc_MultiPoint;
	extern ACSC_MultiPointM						acsc_MultiPointM;
	extern ACSC_BoostedPointToPointMotion		acsc_BoostedPointToPointMotion;
	extern ACSC_SmoothPointToPointMotion		acsc_SmoothPointToPointMotion;
	extern ACSC_SmoothTransitionPointToPointMotion		acsc_SmoothTransitionPointToPointMotion;
	extern ACSC_OpenCommDirect					acsc_OpenCommDirect;
	extern ACSC_OpenCommSimulator				acsc_OpenCommSimulator;
	extern ACSC_CloseSimulator					acsc_CloseSimulator;
	extern ACSC_OpenCommEthernet				acsc_OpenCommEthernet;
	extern ACSC_OpenCommEthernetUDP				acsc_OpenCommEthernetUDP;
	extern ACSC_OpenCommEthernetTCP				acsc_OpenCommEthernetTCP;
	extern ACSC_OpenCommSerial					acsc_OpenCommSerial;
	extern ACSC_OpenCommPCI						acsc_OpenCommPCI;
	extern ACSC_OpenHistoryBuffer				acsc_OpenHistoryBuffer;
	extern ACSC_OpenLogFile						acsc_OpenLogFile;
	extern ACSC_OpenSCLogFile					acsc_OpenSCLogFile;
	extern ACSC_OpenMessageBuffer				acsc_OpenMessageBuffer;
	extern ACSC_Projection						acsc_Projection;
	extern ACSC_ReadDPRAMInteger				acsc_ReadDPRAMInteger;
	extern ACSC_ReadDPRAMReal					acsc_ReadDPRAMReal;
	extern ACSC_ReadInteger						acsc_ReadInteger;
	extern ACSC_ReadReal						acsc_ReadReal;
	extern ACSC_ReadString						acsc_ReadString;
	extern ACSC_ReadStruct						acsc_ReadStruct;
	extern ACSC_WriteStruct						acsc_WriteStruct;
	extern ACSC_Receive							acsc_Receive;
	extern ACSC_ReleaseComm						acsc_ReleaseComm;
	extern ACSC_ResetIndexState					acsc_ResetIndexState;
	extern ACSC_RunBuffer						acsc_RunBuffer;
	extern ACSC_Segment							acsc_Segment;
	extern ACSC_Send							acsc_Send;
	extern ACSC_SetAcceleration					acsc_SetAcceleration;
	extern ACSC_SetAccelerationImm				acsc_SetAccelerationImm;
	extern ACSC_SetAnalogOutput					acsc_SetAnalogOutput;
	extern ACSC_SetCallback						acsc_SetCallback;
	extern ACSC_SetCallbackPriority				acsc_SetCallbackPriority;
	extern ACSC_SetCommOptions					acsc_SetCommOptions;
	extern ACSC_SetDeceleration					acsc_SetDeceleration;
	extern ACSC_SetDecelerationImm				acsc_SetDecelerationImm;
	extern ACSC_SetExtOutput					acsc_SetExtOutput;
	extern ACSC_SetExtOutputPort				acsc_SetExtOutputPort;
	extern ACSC_SetFPosition					acsc_SetFPosition;
	extern ACSC_SetFaultMask					acsc_SetFaultMask;
	extern ACSC_SetInterruptMask				acsc_SetInterruptMask;
	extern ACSC_SetCallbackMask					acsc_SetCallbackMask;
	extern ACSC_SetCallbackMaskExt				acsc_SetCallbackMaskExt;
	extern ACSC_SetIterations					acsc_SetIterations;
	extern ACSC_SetJerk							acsc_SetJerk;
	extern ACSC_SetJerkImm						acsc_SetJerkImm;
	extern ACSC_SetKillDeceleration				acsc_SetKillDeceleration;
	extern ACSC_SetKillDecelerationImm			acsc_SetKillDecelerationImm;
	extern ACSC_SetMaster						acsc_SetMaster;
	extern ACSC_SetOutput						acsc_SetOutput;
	extern ACSC_SetOutputPort					acsc_SetOutputPort;
	extern ACSC_SetRPosition					acsc_SetRPosition;
	extern ACSC_SetResponseMask					acsc_SetResponseMask;
	extern ACSC_SetSafetyInputPortInv			acsc_SetSafetyInputPortInv;
	extern ACSC_SetTimeout						acsc_SetTimeout;
	extern ACSC_SetVelocity						acsc_SetVelocity;
	extern ACSC_SetVelocityImm					acsc_SetVelocityImm;
	extern ACSC_Slave							acsc_Slave;
	extern ACSC_SlaveStalled					acsc_SlaveStalled;
	extern ACSC_Spline							acsc_Spline;
	extern ACSC_SplineM							acsc_SplineM;
	extern ACSC_Split							acsc_Split;
	extern ACSC_SplitAll						acsc_SplitAll;
	extern ACSC_StopBuffer						acsc_StopBuffer;
	extern ACSC_StopCollect						acsc_StopCollect;
	extern ACSC_Stopper							acsc_Stopper;
	extern ACSC_SuspendBuffer					acsc_SuspendBuffer;
	extern ACSC_ToPoint							acsc_ToPoint;
	extern ACSC_ToPointM						acsc_ToPointM;
	extern ACSC_Transaction						acsc_Transaction;
	extern ACSC_UploadBuffer					acsc_UploadBuffer;
	extern ACSC_WaitCollectEnd					acsc_WaitCollectEnd;
	extern ACSC_WaitCollectEndExt				acsc_WaitCollectEndExt;
	extern ACSC_WaitSPDataCollectionEnd			acsc_WaitSPDataCollectionEnd;
	extern ACSC_WaitForAsyncCall				acsc_WaitForAsyncCall;
	extern ACSC_WaitInput						acsc_WaitInput;
	extern ACSC_WaitLogicalMotionEnd			acsc_WaitLogicalMotionEnd;
	extern ACSC_WaitMotionEnd					acsc_WaitMotionEnd;
	extern ACSC_WaitMotorEnabled				acsc_WaitMotorEnabled;
	extern ACSC_WaitMotorCommutated				acsc_WaitMotorCommutated;
	extern ACSC_WaitProgramEnd					acsc_WaitProgramEnd;
	extern ACSC_WaitUserCondition				acsc_WaitUserCondition;
	extern ACSC_WriteDPRAMInteger				acsc_WriteDPRAMInteger;
	extern ACSC_WriteDPRAMReal					acsc_WriteDPRAMReal;
	extern ACSC_WriteInteger					acsc_WriteInteger;
	extern ACSC_WriteLogFile					acsc_WriteLogFile;
	extern ACSC_WriteSCLogFile					acsc_WriteSCLogFile;
	extern ACSC_WriteReal						acsc_WriteReal;
	extern ACSC_WriteString						acsc_WriteString;
	extern ACSC_LoadBufferIgnoreServiceLines	acsc_LoadBufferIgnoreServiceLines;
	extern ACSC_LoadBuffersFromFile				acsc_LoadBuffersFromFile;

	extern ACSC_PegI							acsc_PegI;
	extern ACSC_PegR							acsc_PegR;
	extern ACSC_PegInc							acsc_PegInc;
	extern ACSC_PegRandom						acsc_PegRandom;
	extern ACSC_AssignPins						acsc_AssignPins;
	extern ACSC_StopPeg							acsc_StopPeg;

	extern ACSC_AssignPegNT						acsc_AssignPegNT;
	extern ACSC_AssignPegNTV2					acsc_AssignPegNTV2;
	extern ACSC_AssignPegOutputsNT				acsc_AssignPegOutputsNT;
	extern ACSC_AssignFastInputsNT				acsc_AssignFastInputsNT;
	extern ACSC_PegIncNT						acsc_PegIncNT;
	extern ACSC_PegIncNTV2						acsc_PegIncNTV2;
	extern ACSC_PegRandomNT						acsc_PegRandomNT;
	extern ACSC_PegRandomNTV2					acsc_PegRandomNTV2;
	extern ACSC_WaitPegReadyNT					acsc_WaitPegReadyNT;
	extern ACSC_StartPegNT						acsc_StartPegNT;
	extern ACSC_StopPegNT						acsc_StopPegNT;

	extern ACSC_CollectB						acsc_CollectB;
	extern ACSC_DataCollection					acsc_DataCollection;
	extern ACSC_DataCollectionExt				acsc_DataCollectionExt;
	extern ACSC_SPDataCollectionStart			acsc_SPDataCollectionStart;
	extern ACSC_SPDataCollectionStop			acsc_SPDataCollectionStop;
	extern ACSC_GetSPAddress					acsc_GetSPAddress;
	extern ACSC_AddPVPoint						acsc_AddPVPoint;
	extern ACSC_AddPVPointM						acsc_AddPVPointM;
	extern ACSC_AddPVTPoint						acsc_AddPVTPoint;
	extern ACSC_AddPVTPointM					acsc_AddPVTPointM;
	extern ACSC_LoadFileToRealVariable			acsc_LoadFileToRealVariable;
	extern ACSC_LoadFileToIntegerVariable		acsc_LoadFileToIntegerVariable;
	extern ACSC_LoadDataToController			acsc_LoadDataToController;
	extern ACSC_UploadDataFromController		acsc_UploadDataFromController;
	extern ACSC_SetQueueOverflowTimeout			acsc_SetQueueOverflowTimeout;
	extern ACSC_GetQueueOverflowTimeout			acsc_GetQueueOverflowTimeout;
	extern ACSC_SetTargetPosition				acsc_SetTargetPosition;
	extern ACSC_GetTargetPosition				acsc_GetTargetPosition;
	extern ACSC_SetTargetPositionM				acsc_SetTargetPositionM;
	extern ACSC_Track							acsc_Track;
	extern ACSC_TrackM							acsc_TrackM;
	extern ACSC_FaultClearM						acsc_FaultClearM;
	extern ACSC_FaultClear						acsc_FaultClear;
	extern ACSC_Getconf							acsc_Getconf;
	extern ACSC_Setconf							acsc_Setconf;
	extern ACSC_GetConf							acsc_GetConf;
	extern ACSC_SetConf							acsc_SetConf;
	extern ACSC_SysInfo							acsc_SysInfo;

	extern ACSC_GetAxesCount					acsc_GetAxesCount;
	extern ACSC_GetBuffersCount					acsc_GetBuffersCount;
	extern ACSC_GetDBufferIndex					acsc_GetDBufferIndex;

	extern ACSC_SetCallbackExt					acsc_SetCallbackExt;
	extern ACSC_InstallCallback					acsc_InstallCallback;
	extern ACSC_InstallCallbackExt				acsc_InstallCallbackExt;
	extern ACSC_DownloadBinVariableToFile		acsc_DownloadBinVariableToFile;
	extern ACSC_SetLogFileOptions				acsc_SetLogFileOptions;

	extern ACSC_SetServer						acsc_SetServer;
	extern ACSC_SetServerExt					acsc_SetServerExt;
	extern ACSC_SetServerExtLogin				acsc_SetServerExtLogin;

	extern ACSC_GetSingleMessage				acsc_GetSingleMessage;

	extern ACSC_GetConnectionsList			    acsc_GetConnectionsList;
	extern ACSC_GetConnectionInfo			    acsc_GetConnectionInfo;
	extern ACSC_TerminateConnection				acsc_TerminateConnection;

	extern ACSC_GetLogData						acsc_GetLogData;

	extern ACSC_RegisterEmergencyStop			acsc_RegisterEmergencyStop;
	extern ACSC_UnregisterEmergencyStop			acsc_UnregisterEmergencyStop;

	extern ACSC_GetUMDVersion					acsc_GetUMDVersion;

	extern ACSC_AnalyzeApplication				acsc_AnalyzeApplication;
	extern ACSC_FreeApplication		        	acsc_FreeApplication;
	extern ACSC_SaveApplication					acsc_SaveApplication;
	extern ACSC_LoadApplication					acsc_LoadApplication;
	extern ACSC_WaitForResult					acsc_WaitForResult;
	extern ACSC_ReadTypeless					acsc_ReadTypeless;
	extern ACSC_ReadTypeless2					acsc_ReadTypeless2;
	extern ACSC_RawTransaction					acsc_RawTransaction;
	extern ACSC_Transaction2					acsc_Transaction2;
	extern ACSC_Transaction3					acsc_Transaction3;
	extern ACSC_FreeBufferMemory				acsc_FreeBufferMemory;
	extern ACSC_UploadEntireBuffer				acsc_UploadEntireBuffer;
	extern ACSC_FRF_FreeFRD_Matrix_Internal		acsc_FRF_FreeFRD_Matrix_Internal;
	extern ACSC_FFT								acsc_FFT;
	extern ACSC_FRF_Measure						acsc_FRF_Measure;
	extern ACSC_FRF_FreeFRD_Internal			acsc_FRF_FreeFRD_Internal;
	extern ACSC_FRF_CalculateSLVRAT				acsc_FRF_CalculateSLVRAT;
	extern ACSC_FRF_CalculateLoopDataFRD		acsc_FRF_CalculateLoopDataFRD;
	extern ACSC_FRF_CrossCouplingMeasure		acsc_FRF_CrossCouplingMeasure;
	extern ACSC_FRF_FreeCalculateLoopData       acsc_FRF_FreeCalculateLoopData;
	extern ACSC_FRF_Stop						acsc_FRF_Stop;
	extern ACSC_FRF_CalculateMeasurementDuration	acsc_FRF_CalculateMeasurementDuration;
	extern ACSC_FRF_InitInput					acsc_FRF_InitInput;
	extern ACSC_FRF_FreeOutput					acsc_FRF_FreeOutput;
	extern ACSC_FRF_FreeCrossCouplingOutput		acsc_FRF_FreeCrossCouplingOutput;
	extern ACSC_FRF_ReadServoParameters			acsc_FRF_ReadServoParameters;
	extern ACSC_FRF_CalculateControllerFRD		acsc_FRF_CalculateControllerFRD;
	extern ACSC_FRF_CalculateOpenLoopFRD		acsc_FRF_CalculateOpenLoopFRD;
	extern ACSC_FRF_CalculateClosedLoopFRD		acsc_FRF_CalculateClosedLoopFRD;
	extern ACSC_FRF_CalculateStabilityMargins	acsc_FRF_CalculateStabilityMargins;
	extern ACSC_FRF_FreeFRD						acsc_FRF_FreeFRD;
	extern ACSC_FRF_FreeStabilityMargins		acsc_FRF_FreeStabilityMargins;
	extern ACSC_JitterAnalysis					acsc_JitterAnalysis;
	extern ACSC_JitterAnalysis_FreeOutput		acsc_JitterAnalysis_FreeOutput;

	extern ACSC_ControllerReboot				acsc_ControllerReboot;
	extern ACSC_ControllerFactoryDefault		acsc_ControllerFactoryDefault;
	extern ACSC_ControllerSaveToFlash			acsc_ControllerSaveToFlash;

	extern ACSC_DefineControllerProtection		acsc_DefineControllerProtection;
	extern ACSC_RemoveControllerProtection		acsc_RemoveControllerProtection;
	extern ACSC_TemporarilyDisableVariableProtection		acsc_TemporarilyDisableVariableProtection;
	extern ACSC_RestoreVariableProtection		acsc_RestoreVariableProtection;

	extern ACSC_GetSharedMemoryAddress			acsc_GetSharedMemoryAddress;
	extern ACSC_ReadSharedMemoryReal			acsc_ReadSharedMemoryReal;
	extern ACSC_ReadSharedMemoryInteger			acsc_ReadSharedMemoryInteger;
	extern ACSC_WriteSharedMemoryReal			acsc_WriteSharedMemoryReal;
	extern ACSC_WriteSharedMemoryInteger		acsc_WriteSharedMemoryInteger;

	extern ACSC_GetEtherCATState				acsc_GetEtherCATState;
	extern ACSC_GetEtherCATError				acsc_GetEtherCATError;
	extern ACSC_MapEtherCATInput				acsc_MapEtherCATInput;
	extern ACSC_MapEtherCATOutput				acsc_MapEtherCATOutput;
	extern ACSC_UnmapEtherCATInputsOutputs		acsc_UnmapEtherCATInputsOutputs;
	extern ACSC_GetEtherCATSlaveIndex			acsc_GetEtherCATSlaveIndex;
	extern ACSC_GetEtherCATSlaveOffset			acsc_GetEtherCATSlaveOffset;
	extern ACSC_GetEtherCATSlaveOffsetV2		acsc_GetEtherCATSlaveOffsetV2;
	extern ACSC_GetEtherCATSlaveVendorID		acsc_GetEtherCATSlaveVendorID;
	extern ACSC_GetEtherCATSlaveVendorIDV2		acsc_GetEtherCATSlaveVendorIDV2;
	extern ACSC_GetEtherCATSlaveSerialNumber	acsc_GetEtherCATSlaveSerialNumber;
	extern ACSC_GetEtherCATSlaveProductID		acsc_GetEtherCATSlaveProductID;
	extern ACSC_GetEtherCATSlaveProductIDV2		acsc_GetEtherCATSlaveProductIDV2;
	extern ACSC_GetEtherCATSlaveRevision		acsc_GetEtherCATSlaveRevision;
	extern ACSC_GetEtherCATSlaveRevisionV2		acsc_GetEtherCATSlaveRevisionV2;
	extern ACSC_GetEtherCATSlaveType			acsc_GetEtherCATSlaveType;
	extern ACSC_GetEtherCATSlaveState			acsc_GetEtherCATSlaveState;
	extern ACSC_GetEtherCATSlaveStateV2			acsc_GetEtherCATSlaveStateV2;
	extern ACSC_DownloadFileOverEtherCAT		acsc_DownloadFileOverEtherCAT;
	extern ACSC_ReadSDOValueOverEtherCAT		acsc_ReadSDOValueOverEtherCAT;
	extern ACSC_WriteSDOValueOverEtherCAT		acsc_WriteSDOValueOverEtherCAT;
	extern ACSC_GetEtherCATSlaveRegister		acsc_GetEtherCATSlaveRegister;
	extern ACSC_ClearEtherCATSlaveRegister		acsc_ClearEtherCATSlaveRegister;
	extern ACSC_GetEtherCATSlavesCount			acsc_GetEtherCATSlavesCount;

	extern ACSC_DynamicErrorCompensationOn		acsc_DynamicErrorCompensationOn;
	extern ACSC_DynamicErrorCompensationOff		acsc_DynamicErrorCompensationOff;
	extern ACSC_DynamicErrorCompensationRemove  acsc_DynamicErrorCompensationRemove;
	extern ACSC_DynamicErrorCompensation1D		acsc_DynamicErrorCompensation1D;
	extern ACSC_DynamicErrorCompensationN1D		acsc_DynamicErrorCompensationN1D;
	extern ACSC_DynamicErrorCompensationA1D		acsc_DynamicErrorCompensationA1D;
	extern ACSC_DynamicErrorCompensation2D      acsc_DynamicErrorCompensation2D;
	extern ACSC_DynamicErrorCompensationN2D     acsc_DynamicErrorCompensationN2D;
	extern ACSC_DynamicErrorCompensationA2D     acsc_DynamicErrorCompensationA2D;
	extern ACSC_DynamicErrorCompensation3D2		acsc_DynamicErrorCompensation3D2;
	extern ACSC_DynamicErrorCompensation3D3		acsc_DynamicErrorCompensation3D3;
	extern ACSC_DynamicErrorCompensation3D5		acsc_DynamicErrorCompensation3D5;
	extern ACSC_DynamicErrorCompensation3DA		acsc_DynamicErrorCompensation3DA;
	extern ACSC_DynamicErrorCompensationN3D2    acsc_DynamicErrorCompensationN3D2;
	extern ACSC_DynamicErrorCompensationN3D3    acsc_DynamicErrorCompensationN3D3;
	extern ACSC_DynamicErrorCompensationN3D5    acsc_DynamicErrorCompensationN3D5;
	extern ACSC_DynamicErrorCompensationN3DA    acsc_DynamicErrorCompensationN3DA;

	extern ACSC_CopyFileToController			acsc_CopyFileToController;
	extern ACSC_DeleteFileFromController		acsc_DeleteFileFromController;

	extern ACSC_SegmentedMotion					acsc_SegmentedMotion;
	extern ACSC_ExtendedSegmentedMotion			acsc_ExtendedSegmentedMotion;
	extern ACSC_ExtendedSegmentedMotionExt		acsc_ExtendedSegmentedMotionExt;
	extern ACSC_ExtendedSegmentedMotionV2		acsc_ExtendedSegmentedMotionV2;
	extern ACSC_SegmentLine						acsc_SegmentLine;
	extern ACSC_SegmentLineExt					acsc_SegmentLineExt;
	extern ACSC_SegmentLineV2					acsc_SegmentLineV2;
	extern ACSC_SegmentArc1						acsc_SegmentArc1;
	extern ACSC_SegmentArc2						acsc_SegmentArc2;
	extern ACSC_SegmentArc1Ext					acsc_SegmentArc1Ext;
	extern ACSC_SegmentArc2Ext					acsc_SegmentArc2Ext;
	extern ACSC_ExtendedSegmentArc1				acsc_ExtendedSegmentArc1;
	extern ACSC_ExtendedSegmentArc2				acsc_ExtendedSegmentArc2;
	extern ACSC_SegmentArc1V2					acsc_SegmentArc1V2;
	extern ACSC_SegmentArc2V2					acsc_SegmentArc2V2;
	extern ACSC_BlendedSegmentMotion			acsc_BlendedSegmentMotion;
	extern ACSC_BlendedLine						acsc_BlendedLine;
	extern ACSC_BlendedArc1						acsc_BlendedArc1;
	extern ACSC_BlendedArc2						acsc_BlendedArc2;

	extern ACSC_NurbsMotion         			acsc_NurbsMotion;
	extern ACSC_NurbsPoints						acsc_NurbsPoints;
	extern ACSC_SmoothPathMotion				acsc_SmoothPathMotion;
	extern ACSC_SmoothPathSegment				acsc_SmoothPathSegment;

	extern ACSC_ClearBreakpoints				acsc_ClearBreakpoints;
	extern ACSC_SetBreakpoint					acsc_SetBreakpoint;
	extern ACSC_GetBreakpointsList				acsc_GetBreakpointsList;

	extern ACSC_GetAnalogInputNT				acsc_GetAnalogInputNT;
	extern ACSC_GetAnalogOutputNT				acsc_GetAnalogOutputNT;
	extern ACSC_SetAnalogOutputNT				acsc_SetAnalogOutputNT;

	extern ACSC_GetVolatileMemoryUsage			acsc_GetVolatileMemoryUsage;
	extern ACSC_GetVolatileMemoryTotal			acsc_GetVolatileMemoryTotal;
	extern ACSC_GetVolatileMemoryFree			acsc_GetVolatileMemoryFree;
	extern ACSC_GetNonVolatileMemoryUsage		acsc_GetNonVolatileMemoryUsage;
	extern ACSC_GetNonVolatileMemoryTotal		acsc_GetNonVolatileMemoryTotal;
	extern ACSC_GetNonVolatileMemoryFree		acsc_GetNonVolatileMemoryFree;

	extern ACSC_StartSPiiPlusSC					acsc_StartSPiiPlusSC;
	extern ACSC_StopSPiiPlusSC					acsc_StopSPiiPlusSC;
	extern HMODULE hACSCLibraryModule;

	extern ACSC_GetEthernetCardsExt             acsc_GetEthernetCardsExt;

#endif

#endif

#if defined(__cplusplus)
}
#endif



//////////////////////////////////////////////////////////////////////////////////////////////////
// Internal functions that save and read a global errors
//////////////////////////////////////////////////////////////////////////////////////////////////

// Save last global error
void SetGlobalError(DWORD dwError);

// Read last global error
DWORD GetGlobalError();

#endif
