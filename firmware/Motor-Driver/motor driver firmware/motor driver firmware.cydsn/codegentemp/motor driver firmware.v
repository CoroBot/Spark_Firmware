// ======================================================================
// motor driver firmware.v generated from TopDesign.cysch
// 04/18/2016 at 15:26
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PANTHER 5
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 3
`define CYDEV_CHIP_REV_EXPECT 17
`define CYDEV_CHIP_DIE_ACTUAL 3
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 5
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 6
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 7
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 8
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 9
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 10
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 11
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4F 12
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4M 13
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 14
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 15
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 16
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 17
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 18
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 2
`define CYDEV_CHIP_MEMBER_USED 10
`define CYDEV_CHIP_REVISION_USED 17
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// TCPWM_P4_v2_0(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=true, PinVisibility_phiB=true, PinVisibility_switch=false, PWMCompare=65535, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=65535, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=2, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=3, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=true, TermVisibility_interrupt=true, TermVisibility_line=false, TermVisibility_line_n=false, TermVisibility_ov=false, TermVisibility_reload=false, TermVisibility_start=true, TermVisibility_stop=false, TermVisibility_un=false, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=QuadDec_Front, CY_INSTANCE_SHORT_NAME=QuadDec_Front, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=QuadDec_Front, )
module TCPWM_P4_v2_0_0 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// TCPWM_P4_v2_0(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=true, PinVisibility_phiB=true, PinVisibility_switch=false, PWMCompare=65535, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=65535, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=2, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=3, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=true, TermVisibility_interrupt=true, TermVisibility_line=false, TermVisibility_line_n=false, TermVisibility_ov=false, TermVisibility_reload=false, TermVisibility_start=true, TermVisibility_stop=false, TermVisibility_un=false, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=QuadDec_Rear, CY_INSTANCE_SHORT_NAME=QuadDec_Rear, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=QuadDec_Rear, )
module TCPWM_P4_v2_0_1 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// SCB_P4_v3_0(ApplySbClockParam=false, BitWidthReplacementStringRx=uint8, BitWidthReplacementStringTx=uint8, BufNum=1, Cond=#, DBGW_SCB_IP_V0=true, DBGW_SCB_IP_V1=false, DBGW_SCB_IP_V2=false, EndCond=#endif, EzI2cBitWidthReplacementString=uint16, EzI2cBusVoltage=3.3, EzI2cByteModeEnable=false, EzI2cClkFreqDes=1550, EzI2cClockFromTerm=false, EzI2cClockStretching=true, EzI2cDataRate=100, EzI2cIsPrimarySlaveAddressHex=true, EzI2cIsSecondarySlaveAddressHex=true, EzI2cMedianFilterEnable=true, EzI2cNumberOfAddresses=0, EzI2cOvsFactor=16, EzI2cPrimarySlaveAddress=8, EzI2cSecondarySlaveAddress=9, EzI2cSlaveAddressMask=254, EzI2cSlewRate=0, EzI2cSubAddressSize=0, EzI2cWakeEnable=false, I2cAcceptAddress=false, I2cAcceptGeneralCall=false, I2cBusVoltage=3.3, I2cBusVoltageLevel=, I2cByteModeEnable=false, I2cClkFreqDes=1550, I2cClockFromTerm=false, I2cDataRate=100, I2cExternIntrHandler=false, I2cIsSlaveAddressHex=true, I2cIsSlaveAddressMaskHex=true, I2cManualOversampleControl=true, I2cMedianFilterEnable=true, I2cMode=1, I2cOvsFactor=16, I2cOvsFactorHigh=8, I2cOvsFactorLow=8, I2cSlaveAddress=8, I2cSlaveAddressMask=254, I2cSlewRate=0, I2cSlewRateSettings=0, I2cWakeEnable=false, PinLocationP4A=true, PinName0Unconfig=uart_rx_i2c_scl_spi_mosi, PinName0UnconfigWake=uart_rx_wake_i2c_scl_spi_mosi, PinName1Unconfig=uart_tx_i2c_sda_spi_miso, PinName2Unconfig=spi_sclk, PinName3Unconfig=spi_ss0, Pn0Unconfig=RX_SCL_MOSI, Pn0UnconfigWake=RX_WAKE_SCL_MOSI, Pn1Unconfig=TX_SDA_MISO, Pn2Unconfig=SCLK, Pn3Unconfig=SS0, RemoveI2cPins=true, RemoveMisoSdaTx=true, RemoveMosiSclRx=true, RemoveMosiSclRxWake=true, RemoveScbClk=false, RemoveScbIrq=false, RemoveSpiMasterMiso=true, RemoveSpiMasterMosi=true, RemoveSpiMasterPins=true, RemoveSpiMasterSclk=true, RemoveSpiMasterSs0Pin=true, RemoveSpiMasterSs1Pin=true, RemoveSpiMasterSs2Pin=true, RemoveSpiMasterSs3Pin=true, RemoveSpiSclk=true, RemoveSpiSlaveMiso=true, RemoveSpiSlaveMosi=true, RemoveSpiSlavePins=true, RemoveSpiSs0=true, RemoveSpiSs1=true, RemoveSpiSs2=true, RemoveSpiSs3=true, RemoveUartCtsPin=true, RemoveUartRtsPin=true, RemoveUartRxPin=false, RemoveUartRxTxPin=true, RemoveUartRxWake=true, RemoveUartRxWakeupIrq=true, RemoveUartTxPin=false, RxTriggerOutputEnable=false, ScbClkFreqDes=748.8, ScbClkMinusTolerance=5, ScbClkPlusTolerance=5, ScbClockSelect=1, ScbClockTermEnable=false, ScbCustomIntrHandlerEnable=true, ScbInterruptTermEnable=false, ScbMisoSdaTxEnable=true, ScbMode=4, ScbModeHw=2, ScbMosiSclRxEnable=true, ScbRxWakeIrqEnable=false, ScbSclkEnable=false, ScbSs0Enable=false, ScbSs1Enable=false, ScbSs2Enable=false, ScbSs3Enable=false, SpiBitRate=1000, SpiBitsOrder=1, SpiByteModeEnable=false, SpiClkFreqDes=16000, SpiClockFromTerm=false, SpiFreeRunningSclk=false, SpiInterruptMode=0, SpiIntrMasterSpiDone=false, SpiIntrRxFull=false, SpiIntrRxNotEmpty=false, SpiIntrRxOverflow=false, SpiIntrRxTrigger=false, SpiIntrRxUnderflow=false, SpiIntrSlaveBusError=false, SpiIntrTxEmpty=false, SpiIntrTxNotFull=false, SpiIntrTxOverflow=false, SpiIntrTxTrigger=false, SpiIntrTxUnderflow=false, SpiLateMisoSampleEnable=false, SpiManualOversampleControl=true, SpiMedianFilterEnable=false, SpiMode=0, SpiNumberOfRxDataBits=8, SpiNumberOfSelectLines=1, SpiNumberOfTxDataBits=8, SpiOvsFactor=16, SpiRemoveMiso=false, SpiRemoveMosi=false, SpiRemoveSclk=false, SpiRxBufferSize=8, SpiRxIntrMask=0, SpiRxOutputEnable=false, SpiRxTriggerLevel=7, SpiSclkMode=0, SpiSs0Polarity=0, SpiSs1Polarity=0, SpiSs2Polarity=0, SpiSs3Polarity=0, SpiSubMode=0, SpiTransferSeparation=1, SpiTxBufferSize=8, SpiTxIntrMask=0, SpiTxOutputEnable=false, SpiTxTriggerLevel=0, SpiWakeEnable=false, TermMode_clock=0, TermMode_interrupt=0, TermVisibility_clock=false, TermVisibility_interrupt=false, TriggerOutputEnable=false, TxTriggerOutputEnable=false, UartByteModeEnable=false, UartClkFreqDes=748.8, UartClockFromTerm=false, UartCtsEnable=false, UartCtsPolarity=0, UartDataRate=57600, UartDirection=3, UartDropOnFrameErr=false, UartDropOnParityErr=false, UartInterruptMode=1, UartIntrRxFrameErr=false, UartIntrRxFull=false, UartIntrRxNotEmpty=true, UartIntrRxOverflow=false, UartIntrRxParityErr=false, UartIntrRxTrigger=false, UartIntrRxUnderflow=false, UartIntrTxEmpty=false, UartIntrTxNotFull=false, UartIntrTxOverflow=false, UartIntrTxTrigger=false, UartIntrTxUartDone=false, UartIntrTxUartLostArb=false, UartIntrTxUartNack=false, UartIntrTxUnderflow=false, UartIrdaLowPower=false, UartIrdaPolarity=0, UartMedianFilterEnable=true, UartMpEnable=false, UartMpRxAcceptAddress=false, UartMpRxAddress=2, UartMpRxAddressMask=255, UartNumberOfDataBits=8, UartNumberOfStopBits=2, UartOvsFactor=13, UartParityType=2, UartRtsEnable=false, UartRtsPolarity=0, UartRtsTriggerLevel=4, UartRxBufferSize=64, UartRxEnable=true, UartRxIntrMask=4, UartRxOutputEnable=false, UartRxTriggerLevel=0, UartSmCardRetryOnNack=false, UartSubMode=0, UartTxBufferSize=32, UartTxEnable=true, UartTxIntrMask=0, UartTxOutputEnable=false, UartTxTriggerLevel=0, UartWakeEnable=false, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=SCB_P4_v3_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=UART, )
module SCB_P4_v3_0_2 (
    interrupt,
    clock,
    rx_tr_out,
    tx_tr_out);
    output      interrupt;
    input       clock;
    output      rx_tr_out;
    output      tx_tr_out;


          wire  uncfg_rx_irq;
          wire  Net_1191;
          wire  Net_1258;
          wire  Net_1099;
          wire  rx_irq;
          wire [3:0] ss;
          wire  Net_1257;
          wire  Net_1197;
          wire  Net_1196;
          wire  Net_1195;
          wire  Net_1194;
          wire  Net_1193;
          wire  Net_1263;
          wire  Net_663;
          wire  Net_547;
          wire  Net_467;
          wire  Net_1090;
          wire  Net_1091;
          wire  Net_1172;
          wire  Net_1089;
          wire  Net_1088;
          wire  Net_387;
          wire  Net_252;
          wire  Net_1087;
          wire  Net_1086;
          wire  Net_1000;
          wire  Net_915;
          wire  Net_916;
          wire  Net_1175;
          wire  Net_654;
          wire  Net_990;
          wire  Net_652;
          wire  Net_459;
          wire  Net_580;
          wire  Net_581;
          wire  Net_452;
          wire  Net_909;
          wire  Net_1001;
          wire  Net_899;
          wire  Net_747;
          wire  Net_891;
          wire  Net_1028;
          wire  Net_1170;
          wire  Net_1061;
          wire  Net_1053;
          wire  Net_1055;
          wire  Net_1062;
          wire  Net_1059;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("43ec2fa1-bf22-4b71-9477-b6ca7b97f0b0/2dc2d7a8-ce2b-43c7-af4a-821c8cd73ccf"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("1335470085.47009"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


    ZeroTerminal ZeroTerminal_5 (
        .z(Net_459));

	// select_s_VM (cy_virtualmux_v1_0)
	assign Net_652 = Net_459;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_452));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1194));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1195));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1196));

	// rx_VM (cy_virtualmux_v1_0)
	assign Net_654 = Net_1197;

	// rx_wake_VM (cy_virtualmux_v1_0)
	assign Net_1257 = uncfg_rx_irq;

	// clock_VM (cy_virtualmux_v1_0)
	assign Net_1170 = Net_847;

	// sclk_s_VM (cy_virtualmux_v1_0)
	assign Net_990 = Net_1196;

	// mosi_s_VM (cy_virtualmux_v1_0)
	assign Net_909 = Net_1194;

	// miso_m_VM (cy_virtualmux_v1_0)
	assign Net_663 = Net_1195;

	wire [0:0] tmpOE__tx_net;
	wire [0:0] tmpFB_0__tx_net;
	wire [0:0] tmpIO_0__tx_net;
	wire [0:0] tmpINTERRUPT_0__tx_net;
	electrical [0:0] tmpSIOVREF__tx_net;

	cy_psoc3_pins_v1_10
		#(.id("43ec2fa1-bf22-4b71-9477-b6ca7b97f0b0/23b8206d-1c77-4e61-be4a-b4037d5de5fc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		tx
		 (.oe(tmpOE__tx_net),
		  .y({Net_1062}),
		  .fb({tmpFB_0__tx_net[0:0]}),
		  .io({tmpIO_0__tx_net[0:0]}),
		  .siovref(tmpSIOVREF__tx_net),
		  .interrupt({tmpINTERRUPT_0__tx_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__tx_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1099));


    assign Net_1258 = Net_847 | Net_1099;


	cy_isr_v1_0
		#(.int_type(2'b10))
		SCB_IRQ
		 (.int_signal(interrupt));


	wire [0:0] tmpOE__rx_net;
	wire [0:0] tmpIO_0__rx_net;
	wire [0:0] tmpINTERRUPT_0__rx_net;
	electrical [0:0] tmpSIOVREF__rx_net;

	cy_psoc3_pins_v1_10
		#(.id("43ec2fa1-bf22-4b71-9477-b6ca7b97f0b0/78e33e5d-45ea-4b75-88d5-73274e8a7ce4"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		rx
		 (.oe(tmpOE__rx_net),
		  .y({1'b0}),
		  .fb({Net_1197}),
		  .io({tmpIO_0__rx_net[0:0]}),
		  .siovref(tmpSIOVREF__rx_net),
		  .interrupt({tmpINTERRUPT_0__rx_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__rx_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	// cts_VM (cy_virtualmux_v1_0)
	assign Net_1175 = Net_747;

    cy_m0s8_scb_v2_0 SCB (
        .rx(Net_654),
        .miso_m(Net_663),
        .select_m(ss[3:0]),
        .sclk_m(Net_1059),
        .mosi_s(Net_909),
        .select_s(Net_652),
        .sclk_s(Net_990),
        .mosi_m(Net_1061),
        .scl(Net_580),
        .sda(Net_581),
        .tx(Net_1062),
        .miso_s(Net_1055),
        .interrupt(interrupt),
        .cts(Net_1175),
        .rts(Net_1053),
        .tx_req(tx_tr_out),
        .rx_req(rx_tr_out),
        .clock(Net_1170));
    defparam SCB.scb_mode = 2;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_747));

	// Device_VM1 (cy_virtualmux_v1_0)
	assign Net_547 = Net_1091;

	// Device_VM5 (cy_virtualmux_v1_0)
	assign Net_891 = Net_1088;

	// Device_VM2 (cy_virtualmux_v1_0)
	assign Net_1001 = Net_1087;

	// Device_VM3 (cy_virtualmux_v1_0)
	assign Net_899 = Net_915;

	// Device_VM4 (cy_virtualmux_v1_0)
	assign uncfg_rx_irq = Net_1028;



endmodule

// Component: demux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\demux_v1_10\demux_v1_10.v"
`endif

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// TCPWM_P4_v2_0(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=65535, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_Rear, CY_INSTANCE_SHORT_NAME=PWM_Rear, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=PWM_Rear, )
module TCPWM_P4_v2_0_3 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: Bus_Connect_v2_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Bus_Connect_v2_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Bus_Connect_v2_10\Bus_Connect_v2_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Bus_Connect_v2_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Bus_Connect_v2_10\Bus_Connect_v2_10.v"
`endif

// ADC_SAR_SEQ_P4_v2_10(AdcAClock=4, AdcAdjust=0, AdcAlternateResolution=0, AdcAvgMode=1, AdcAvgSamplesNum=0, AdcBClock=4, AdcCClock=4, AdcChannelsEnConf=1, AdcChannelsModeConf=0, AdcClock=1, AdcClockFrequency=2999988, AdcCompareMode=0, AdcDataFormatJustification=0, AdcDClock=4, AdcDedicatedExtVref=false, AdcDifferentialResultFormat=1, AdcHighLimit=2047, AdcInjChannelEnabled=false, AdcInputBufGain=0, AdcLowLimit=0, AdcMaxResolution=12, AdcSampleMode=0, AdcSarMuxChannelConfig=0, AdcSequencedChannels=1, AdcSingleEndedNegativeInput=0, AdcSingleResultFormat=1, AdcSymbolHasSingleEndedInputChannel=false, AdcTotalChannels=1, AdcVrefSelect=1, AdcVrefVoltage_mV=1024, rm_int=false, SeqChannelsConfigTable=<?xml version="1.0" encoding="utf-16"?><CyChannelsConfigTable xmlns:Version="2_10"><m_channelsConfigTable><CyChannelsConfigTableRow><m_enabled>false</m_enabled><m_resolution>Twelve</m_resolution><m_mode>Single</m_mode><m_averaged>false</m_averaged><m_acqTime>AClocks</m_acqTime><m_limitsDetectIntrEnabled>false</m_limitsDetectIntrEnabled><m_saturationIntrEnabled>false</m_saturationIntrEnabled></CyChannelsConfigTableRow><CyChannelsConfigTableRow><m_enabled>true</m_enabled><m_resolution>Twelve</m_resolution><m_mode>Single</m_mode><m_averaged>false</m_averaged><m_acqTime>AClocks</m_acqTime><m_limitsDetectIntrEnabled>false</m_limitsDetectIntrEnabled><m_saturationIntrEnabled>false</m_saturationIntrEnabled></CyChannelsConfigTableRow></m_channelsConfigTable></CyChannelsConfigTable>, TermMode_aclk=0, TermMode_eoc=0, TermMode_sdone=0, TermMode_soc=0, TermMode_vinMinus0=0, TermMode_vinMinus1=0, TermMode_vinMinus10=0, TermMode_vinMinus11=0, TermMode_vinMinus12=0, TermMode_vinMinus13=0, TermMode_vinMinus14=0, TermMode_vinMinus15=0, TermMode_vinMinus2=0, TermMode_vinMinus3=0, TermMode_vinMinus4=0, TermMode_vinMinus5=0, TermMode_vinMinus6=0, TermMode_vinMinus7=0, TermMode_vinMinus8=0, TermMode_vinMinus9=0, TermMode_vinMinusINJ=0, TermMode_vinNeg=0, TermMode_vinPlus0=0, TermMode_vinPlus1=0, TermMode_vinPlus10=0, TermMode_vinPlus11=0, TermMode_vinPlus12=0, TermMode_vinPlus13=0, TermMode_vinPlus14=0, TermMode_vinPlus15=0, TermMode_vinPlus2=0, TermMode_vinPlus3=0, TermMode_vinPlus4=0, TermMode_vinPlus5=0, TermMode_vinPlus6=0, TermMode_vinPlus7=0, TermMode_vinPlus8=0, TermMode_vinPlus9=0, TermMode_vinPlusINJ=0, TermMode_Vref=0, TermVisibility_aclk=false, TermVisibility_eoc=true, TermVisibility_sdone=true, TermVisibility_soc=false, TermVisibility_vinMinus0=false, TermVisibility_vinMinus1=false, TermVisibility_vinMinus10=false, TermVisibility_vinMinus11=false, TermVisibility_vinMinus12=false, TermVisibility_vinMinus13=false, TermVisibility_vinMinus14=false, TermVisibility_vinMinus15=false, TermVisibility_vinMinus2=false, TermVisibility_vinMinus3=false, TermVisibility_vinMinus4=false, TermVisibility_vinMinus5=false, TermVisibility_vinMinus6=false, TermVisibility_vinMinus7=false, TermVisibility_vinMinus8=false, TermVisibility_vinMinus9=false, TermVisibility_vinMinusINJ=false, TermVisibility_vinNeg=false, TermVisibility_vinPlus0=true, TermVisibility_vinPlus1=false, TermVisibility_vinPlus10=false, TermVisibility_vinPlus11=false, TermVisibility_vinPlus12=false, TermVisibility_vinPlus13=false, TermVisibility_vinPlus14=false, TermVisibility_vinPlus15=false, TermVisibility_vinPlus2=false, TermVisibility_vinPlus3=false, TermVisibility_vinPlus4=false, TermVisibility_vinPlus5=false, TermVisibility_vinPlus6=false, TermVisibility_vinPlus7=false, TermVisibility_vinPlus8=false, TermVisibility_vinPlus9=false, TermVisibility_vinPlusINJ=false, TermVisibility_Vref=false, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=ADC_SAR_SEQ_P4_v2_10, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Motor_Current_ADC, CY_INSTANCE_SHORT_NAME=Motor_Current_ADC, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=Motor_Current_ADC, )
module ADC_SAR_SEQ_P4_v2_10_4 (
    soc,
    aclk,
    Vref,
    sdone,
    eoc,
    vinPlus0);
    input       soc;
    input       aclk;
    inout       Vref;
    electrical  Vref;
    output      sdone;
    output      eoc;
    inout       vinPlus0;
    electrical  vinPlus0;


          wire  Net_3209;
    electrical  Net_3164;
          wire  Net_3128;
          wire [11:0] Net_3111;
          wire  Net_3110;
          wire [3:0] Net_3109;
          wire  Net_3108;
    electrical  Net_3166;
    electrical  Net_3167;
    electrical  Net_3168;
    electrical  Net_3169;
    electrical  Net_3170;
    electrical  Net_3171;
    electrical  Net_3172;
    electrical  Net_3173;
    electrical  Net_3174;
    electrical  Net_3175;
    electrical  Net_3176;
    electrical  Net_3177;
    electrical  Net_3178;
    electrical  Net_3179;
    electrical  Net_3180;
    electrical  muxout_plus;
    electrical  Net_3181;
    electrical  muxout_minus;
    electrical  Net_3227;
    electrical  Net_3113;
    electrical  Net_3225;
    electrical [16:0] mux_bus_minus;
    electrical [16:0] mux_bus_plus;
    electrical  Net_3226;
          wire  Net_3103;
          wire  Net_3104;
          wire  Net_3105;
          wire  Net_3106;
          wire  Net_3107;
    electrical  Net_3165;
    electrical  Net_3182;
    electrical  Net_3183;
    electrical  Net_3184;
    electrical  Net_3185;
    electrical  Net_3186;
    electrical  Net_3187;
    electrical  Net_3188;
    electrical  Net_3189;
    electrical  Net_3190;
    electrical  Net_3191;
    electrical  Net_3192;
    electrical  Net_3193;
    electrical  Net_3194;
    electrical  Net_3195;
    electrical  Net_3196;
    electrical  Net_3197;
    electrical  Net_3198;
    electrical  Net_3132;
    electrical  Net_3133;
    electrical  Net_3134;
    electrical  Net_3135;
    electrical  Net_3136;
    electrical  Net_3137;
    electrical  Net_3138;
    electrical  Net_3139;
    electrical  Net_3140;
    electrical  Net_3141;
    electrical  Net_3142;
    electrical  Net_3143;
    electrical  Net_3144;
    electrical  Net_3145;
    electrical  Net_3146;
    electrical  Net_3147;
    electrical  Net_3148;
    electrical  Net_3149;
    electrical  Net_3150;
    electrical  Net_3151;
    electrical  Net_3152;
    electrical  Net_3153;
    electrical  Net_3154;
    electrical  Net_3159;
    electrical  Net_3157;
    electrical  Net_3158;
    electrical  Net_3160;
    electrical  Net_3161;
    electrical  Net_3162;
    electrical  Net_3163;
    electrical  Net_3156;
    electrical  Net_3155;
          wire  Net_3120;
    electrical  Net_3119;
    electrical  Net_3118;
          wire  Net_3124;
    electrical  Net_3122;
    electrical  Net_3117;
    electrical  Net_3121;
    electrical  Net_3123;
          wire  Net_3112;
          wire  Net_3126;
          wire  Net_3125;
    electrical  Net_2793;
    electrical  Net_2794;
    electrical  Net_1851;
    electrical  Net_2580;
    electrical [0:0] Net_2375;
    electrical [0:0] Net_1450;
    electrical  Net_3046;
    electrical  Net_3016;
          wire  Net_3235;
    electrical  Net_2099;
          wire  Net_17;
          wire  Net_1845;
    electrical  Net_2020;
    electrical  Net_124;
    electrical  Net_2102;
          wire [1:0] Net_3207;
    electrical  Net_8;
    electrical  Net_43;

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_3125));


    assign Net_3126 = Net_1845 | Net_3125;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(Net_3112));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_44 (
        .noconnect(Net_3123));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_40 (
        .noconnect(Net_3121));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_39 (
        .noconnect(Net_3117));

	// cy_analog_virtualmux_43 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_43_connect(Net_124, muxout_minus);
	defparam cy_analog_virtualmux_43_connect.sig_width = 1;

	// cy_analog_virtualmux_42 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_42_connect(Net_2020, muxout_plus);
	defparam cy_analog_virtualmux_42_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_38 (
        .noconnect(Net_3118));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_41 (
        .noconnect(Net_3119));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_43 (
        .noconnect(Net_3122));

	// adc_plus_in_sel (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 adc_plus_in_sel_connect(muxout_plus, mux_bus_plus[0]);
	defparam adc_plus_in_sel_connect.sig_width = 1;

    Bus_Connect_v2_10 Connect_1 (
        .in_bus(mux_bus_plus[16:0]),
        .out_bus(Net_1450[0:0]));
    defparam Connect_1.in_width = 17;
    defparam Connect_1.out_width = 1;

	// adc_minus_in_sel (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 adc_minus_in_sel_connect(muxout_minus, mux_bus_minus[0]);
	defparam adc_minus_in_sel_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_1851));

	// cy_analog_virtualmux_37 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_37_connect(Net_3016, mux_bus_plus[1]);
	defparam cy_analog_virtualmux_37_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_21 (
        .noconnect(Net_3147));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_20 (
        .noconnect(Net_3146));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_19 (
        .noconnect(Net_3145));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_18 (
        .noconnect(Net_3144));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_17 (
        .noconnect(Net_3143));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_16 (
        .noconnect(Net_3142));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_15 (
        .noconnect(Net_3141));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_14 (
        .noconnect(Net_3140));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_13 (
        .noconnect(Net_3139));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_12 (
        .noconnect(Net_3138));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_11 (
        .noconnect(Net_3137));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_10 (
        .noconnect(Net_3136));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_9 (
        .noconnect(Net_3135));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_8 (
        .noconnect(Net_3134));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_7 (
        .noconnect(Net_3133));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_6 (
        .noconnect(Net_3132));

	// cy_analog_virtualmux_36 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_36_connect(Net_3046, mux_bus_minus[1]);
	defparam cy_analog_virtualmux_36_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_37 (
        .noconnect(Net_3165));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_3107));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_3106));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_3105));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_3104));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_3103));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_3113));

	// ext_vref_sel (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 ext_vref_sel_connect(Net_43, Net_3225);
	defparam ext_vref_sel_connect.sig_width = 1;

    Bus_Connect_v2_10 Connect_2 (
        .in_bus(mux_bus_minus[16:0]),
        .out_bus(Net_2375[0:0]));
    defparam Connect_2.in_width = 17;
    defparam Connect_2.out_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_35 (
        .noconnect(Net_3181));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_34 (
        .noconnect(Net_3180));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_33 (
        .noconnect(Net_3179));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_32 (
        .noconnect(Net_3178));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_31 (
        .noconnect(Net_3177));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_30 (
        .noconnect(Net_3176));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_29 (
        .noconnect(Net_3175));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_28 (
        .noconnect(Net_3174));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_27 (
        .noconnect(Net_3173));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_26 (
        .noconnect(Net_3172));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_25 (
        .noconnect(Net_3171));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_24 (
        .noconnect(Net_3170));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_23 (
        .noconnect(Net_3169));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_22 (
        .noconnect(Net_3168));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_4 (
        .noconnect(Net_3167));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_3166));

	// int_vref_sel (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 int_vref_sel_connect(Net_8, Net_3113);
	defparam int_vref_sel_connect.sig_width = 1;

	// clk_src_sel (cy_virtualmux_v1_0)
	assign Net_17 = Net_1845;

    cy_psoc4_sar_v1_0 cy_psoc4_sar (
        .vplus(Net_2020),
        .vminus(Net_124),
        .vref(Net_8),
        .ext_vref(Net_43),
        .clock(Net_17),
        .sw_negvref(Net_3103),
        .cfg_st_sel(Net_3207[1:0]),
        .cfg_average(Net_3104),
        .cfg_resolution(Net_3105),
        .cfg_differential(Net_3106),
        .trigger(Net_3235),
        .data_hilo_sel(Net_3107),
        .sample_done(sdone),
        .chan_id_valid(Net_3108),
        .chan_id(Net_3109[3:0]),
        .data_valid(Net_3110),
        .eos_intr(eoc),
        .data(Net_3111[11:0]),
        .irq(Net_3112));

	// ext_vneg_sel (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 ext_vneg_sel_connect(Net_2580, Net_1851);
	defparam ext_vneg_sel_connect.sig_width = 1;

	// VMux_soc (cy_virtualmux_v1_0)
	assign Net_3235 = soc;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_3207[0]));

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_3207[1]));

	// cy_analog_virtualmux_vplus0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus0_connect(mux_bus_plus[0], vinPlus0);
	defparam cy_analog_virtualmux_vplus0_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus1_connect(mux_bus_plus[1], Net_3132);
	defparam cy_analog_virtualmux_vplus1_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus2_connect(mux_bus_plus[2], Net_3133);
	defparam cy_analog_virtualmux_vplus2_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus3_connect(mux_bus_plus[3], Net_3134);
	defparam cy_analog_virtualmux_vplus3_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus4_connect(mux_bus_plus[4], Net_3135);
	defparam cy_analog_virtualmux_vplus4_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus5_connect(mux_bus_plus[5], Net_3136);
	defparam cy_analog_virtualmux_vplus5_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus6_connect(mux_bus_plus[6], Net_3137);
	defparam cy_analog_virtualmux_vplus6_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus7 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus7_connect(mux_bus_plus[7], Net_3138);
	defparam cy_analog_virtualmux_vplus7_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus8 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus8_connect(mux_bus_plus[8], Net_3139);
	defparam cy_analog_virtualmux_vplus8_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus9 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus9_connect(mux_bus_plus[9], Net_3140);
	defparam cy_analog_virtualmux_vplus9_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus10 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus10_connect(mux_bus_plus[10], Net_3141);
	defparam cy_analog_virtualmux_vplus10_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus11 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus11_connect(mux_bus_plus[11], Net_3142);
	defparam cy_analog_virtualmux_vplus11_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus12 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus12_connect(mux_bus_plus[12], Net_3143);
	defparam cy_analog_virtualmux_vplus12_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus13 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus13_connect(mux_bus_plus[13], Net_3144);
	defparam cy_analog_virtualmux_vplus13_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus14 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus14_connect(mux_bus_plus[14], Net_3145);
	defparam cy_analog_virtualmux_vplus14_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus15 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus15_connect(mux_bus_plus[15], Net_3146);
	defparam cy_analog_virtualmux_vplus15_connect.sig_width = 1;

	// cy_analog_virtualmux_vplus_inj (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vplus_inj_connect(Net_3016, Net_3147);
	defparam cy_analog_virtualmux_vplus_inj_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus0_connect(mux_bus_minus[0], Net_3166);
	defparam cy_analog_virtualmux_vminus0_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus1_connect(mux_bus_minus[1], Net_3167);
	defparam cy_analog_virtualmux_vminus1_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus2_connect(mux_bus_minus[2], Net_3168);
	defparam cy_analog_virtualmux_vminus2_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus3_connect(mux_bus_minus[3], Net_3169);
	defparam cy_analog_virtualmux_vminus3_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus4_connect(mux_bus_minus[4], Net_3170);
	defparam cy_analog_virtualmux_vminus4_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus5_connect(mux_bus_minus[5], Net_3171);
	defparam cy_analog_virtualmux_vminus5_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus6_connect(mux_bus_minus[6], Net_3172);
	defparam cy_analog_virtualmux_vminus6_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus7 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus7_connect(mux_bus_minus[7], Net_3173);
	defparam cy_analog_virtualmux_vminus7_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus8 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus8_connect(mux_bus_minus[8], Net_3174);
	defparam cy_analog_virtualmux_vminus8_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus9 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus9_connect(mux_bus_minus[9], Net_3175);
	defparam cy_analog_virtualmux_vminus9_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus10 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus10_connect(mux_bus_minus[10], Net_3176);
	defparam cy_analog_virtualmux_vminus10_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus11 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus11_connect(mux_bus_minus[11], Net_3177);
	defparam cy_analog_virtualmux_vminus11_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus12 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus12_connect(mux_bus_minus[12], Net_3178);
	defparam cy_analog_virtualmux_vminus12_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus13 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus13_connect(mux_bus_minus[13], Net_3179);
	defparam cy_analog_virtualmux_vminus13_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus14 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus14_connect(mux_bus_minus[14], Net_3180);
	defparam cy_analog_virtualmux_vminus14_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus15 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus15_connect(mux_bus_minus[15], Net_3181);
	defparam cy_analog_virtualmux_vminus15_connect.sig_width = 1;

	// cy_analog_virtualmux_vminus_inj (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_vminus_inj_connect(Net_3046, Net_3165);
	defparam cy_analog_virtualmux_vminus_inj_connect.sig_width = 1;


	cy_clock_v1_0
		#(.id("0b16c801-e54d-4d80-b574-5f165d7572a1/5c71752a-e182-47ca-942c-9cb20adbdf2f"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("333334666.672"),
		  .is_direct(0),
		  .is_digital(0))
		intClock
		 (.clock_out(Net_1845));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_3227));



endmodule

// TCPWM_P4_v2_0(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=65535, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=0, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=0, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=0, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=false, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=false, TCCaptureMode=0, TCCapturePresent=false, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=3, TCCountPresent=false, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=false, TCRunMode=0, TCStartMode=0, TCStartPresent=false, TCStopMode=0, TCStopPresent=false, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_Front, CY_INSTANCE_SHORT_NAME=PWM_Front, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=PWM_Front, )
module TCPWM_P4_v2_0_5 (
    stop,
    count,
    reload,
    start,
    capture,
    interrupt,
    ov,
    un,
    cc,
    clock,
    line,
    line_n);
    input       stop;
    input       count;
    input       reload;
    input       start;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    input       clock;
    output      line;
    output      line_n;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// Component: GlitchFilter_v2_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0\GlitchFilter_v2_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\GlitchFilter_v2_0\GlitchFilter_v2_0.v"
`endif

// OpAmp_P4_v1_10(Compensation=3, DeepSleepSupport=false, Mode=0, OutputCurrent=1, Power=2, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=OpAmp_P4_v1_10, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Opamp_1, CY_INSTANCE_SHORT_NAME=Opamp_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=10, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 CP2, INSTANCE_NAME=Opamp_1, )
module OpAmp_P4_v1_10_6 (
    Vplus,
    Vout,
    Vminus);
    inout       Vplus;
    electrical  Vplus;
    inout       Vout;
    electrical  Vout;
    inout       Vminus;
    electrical  Vminus;


          wire  Net_12;
    electrical  Net_29;
    electrical  Net_19;
    electrical  Net_18;
    electrical  Net_9;

    cy_psoc4_abuf_v1_0 cy_psoc4_abuf (
        .vplus(Vplus),
        .vminus(Net_9),
        .vout1(Net_18),
        .vout10(Net_19),
        .rs_bot(Net_29),
        .cmpout(Net_12));
    defparam cy_psoc4_abuf.deepsleep_available = 0;
    defparam cy_psoc4_abuf.has_resistor = 0;
    defparam cy_psoc4_abuf.needs_dsab = 0;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_9, Vminus);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Vout, Net_19);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_29));



endmodule

// Component: AMux_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80\AMux_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMux_v1_80\AMux_v1_80.v"
`endif

// top
module top ;

    electrical  Net_1365;
    electrical  Net_1290;
          wire  Net_1100;
          wire  Net_1076;
          wire  Net_1075;
          wire  Net_1074;
          wire  Net_1073;
          wire  Net_1072;
          wire  Net_1071;
          wire  Net_1070;
          wire  Net_1069;
          wire  Net_1068;
    electrical  Net_1008;
    electrical  Net_1007;
    electrical  Net_1006;
    electrical  Net_1005;
    electrical  Net_1004;
    electrical  Net_1003;
    electrical  Net_1002;
    electrical  Net_1001;
    electrical  Net_1000;
    electrical  Net_999;
    electrical  Net_998;
    electrical  Net_997;
    electrical  Net_996;
    electrical  Net_995;
    electrical  Net_994;
    electrical  Net_993;
    electrical  Net_992;
    electrical  Net_991;
    electrical  Net_990;
    electrical  Net_989;
    electrical  Net_988;
    electrical  Net_987;
    electrical  Net_986;
    electrical  Net_985;
    electrical  Net_984;
    electrical  Net_982;
    electrical  Net_981;
    electrical  Net_980;
    electrical  Net_979;
    electrical  Net_978;
    electrical  Net_977;
    electrical  Net_976;
    electrical  Net_975;
    electrical  Net_974;
    electrical  Net_973;
    electrical  Net_972;
    electrical  Net_971;
    electrical  Net_970;
    electrical  Net_969;
    electrical  Net_968;
    electrical  Net_967;
    electrical  Net_966;
    electrical  Net_965;
    electrical  Net_964;
    electrical  Net_963;
    electrical  Net_962;
    electrical  Net_961;
    electrical  Net_960;
    electrical  Net_959;
    electrical  Net_958;
    electrical  Net_957;
    electrical  Net_956;
    electrical  Net_955;
    electrical  Net_954;
    electrical  Net_953;
    electrical  Net_952;
    electrical  Net_951;
    electrical  Net_950;
    electrical  Net_949;
    electrical  Net_948;
    electrical  Net_947;
    electrical  Net_946;
    electrical  Net_945;
    electrical  Net_944;
    electrical  Net_943;
    electrical  Net_942;
    electrical  Net_941;
    electrical  Net_940;
    electrical  Net_939;
    electrical  Net_938;
    electrical  Net_937;
    electrical  Net_936;
    electrical  Net_935;
    electrical  Net_934;
    electrical  Net_933;
    electrical  Net_932;
    electrical  Net_1241;
    electrical  Net_1240;
    electrical  Net_1239;
    electrical  Net_1238;
    electrical  Net_1237;
    electrical  Net_1236;
    electrical  Net_1235;
    electrical  Net_1234;
    electrical  Net_1233;
    electrical  Net_1232;
    electrical  Net_1231;
    electrical  Net_1230;
    electrical  Net_1229;
    electrical  Net_1228;
    electrical  Net_1227;
    electrical  Net_1226;
    electrical  Net_1225;
    electrical  Net_1224;
    electrical  Net_1223;
    electrical  Net_1222;
    electrical  Net_1221;
    electrical  Net_1220;
    electrical  Net_1219;
    electrical  Net_1218;
    electrical  Net_1217;
    electrical  Net_1216;
    electrical  Net_1215;
    electrical  Net_1214;
    electrical  Net_1213;
    electrical  Net_1212;
    electrical  Net_1211;
    electrical  Net_1210;
    electrical  Net_1209;
    electrical  Net_1208;
    electrical  Net_1207;
    electrical  Net_1206;
    electrical  Net_1205;
    electrical  Net_1203;
    electrical  Net_1202;
          wire  Net_864;
          wire  Net_863;
          wire  Net_862;
          wire  Net_861;
          wire  Net_860;
          wire  Net_859;
          wire  Net_858;
          wire  Net_857;
          wire  Net_856;
          wire  Net_855;
          wire  Net_1539;
          wire  Net_1538;
          wire  Net_1537;
          wire  Net_1536;
    electrical  Net_1535;
          wire  Net_1014;
          wire  Net_874;
          wire  Net_873;
          wire  Net_872;
          wire  Net_871;
          wire  Net_870;
          wire  Net_869;
          wire  Net_868;
          wire  Net_867;
          wire  Net_866;
          wire  Net_865;
          wire  Net_1045;
          wire  Net_1044;
          wire  Net_1043;
          wire  Net_1042;
          wire  Net_1041;
          wire  Net_1040;
          wire  Net_1038;
          wire  Net_1037;
          wire  Net_1036;
          wire  Net_854;
          wire  Net_819;
          wire  Net_818;
          wire  Net_817;
          wire  Net_816;
          wire  Net_828;
          wire  Net_827;
          wire  Net_826;
          wire  Net_825;
          wire  Net_824;
          wire  Net_823;
          wire  Net_822;
          wire  Net_821;
          wire  Net_820;
          wire  Net_837;
          wire  Net_836;
          wire  Net_835;
          wire  Net_834;
          wire  Net_833;
          wire  Net_832;
          wire  Net_831;
          wire  Net_830;
          wire  Net_829;
    electrical  Net_1359;
    electrical  Net_1366;
    electrical  Net_1437;
    electrical  Net_1302;
    electrical  Net_1265;
    electrical  Net_1204;
    electrical  Net_1201;
    electrical  Net_1063;
    electrical  Net_1062;
          wire [3:0] Net_1095;
          wire [3:0] Net_1093;
    electrical  Net_1963;
    electrical  Net_1938;
    electrical  Net_2013;
    electrical  Net_1988;
    electrical  Net_890;
    electrical  Net_891;
    electrical  Net_885;
    electrical  Net_884;
          wire  Net_983;
          wire  Net_336;
          wire  Net_303;
          wire  Net_1019;
          wire  Net_304;
          wire  Net_149;
          wire  Net_137;
          wire  Net_101;
          wire  Net_98;
          wire  Net_397;

	wire [0:0] tmpOE__M1QA_net;
	wire [0:0] tmpIO_0__M1QA_net;
	wire [0:0] tmpINTERRUPT_0__M1QA_net;
	electrical [0:0] tmpSIOVREF__M1QA_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		M1QA
		 (.oe(tmpOE__M1QA_net),
		  .y({1'b0}),
		  .fb({Net_1093[0]}),
		  .io({tmpIO_0__M1QA_net[0:0]}),
		  .siovref(tmpSIOVREF__M1QA_net),
		  .interrupt({tmpINTERRUPT_0__M1QA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__M1QA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__M1QB_net;
	wire [0:0] tmpIO_0__M1QB_net;
	wire [0:0] tmpINTERRUPT_0__M1QB_net;
	electrical [0:0] tmpSIOVREF__M1QB_net;

	cy_psoc3_pins_v1_10
		#(.id("eb572053-af8f-4392-9921-7f00c36a2ecd"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		M1QB
		 (.oe(tmpOE__M1QB_net),
		  .y({1'b0}),
		  .fb({Net_1093[1]}),
		  .io({tmpIO_0__M1QB_net[0:0]}),
		  .siovref(tmpSIOVREF__M1QB_net),
		  .interrupt({tmpINTERRUPT_0__M1QB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__M1QB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    TCPWM_P4_v2_0_0 QuadDec_Front (
        .stop(1'b0),
        .reload(1'b0),
        .start(Net_1095[3]),
        .count(Net_1095[2]),
        .capture(1'b0),
        .interrupt(Net_832),
        .ov(Net_833),
        .un(Net_834),
        .cc(Net_835),
        .line(Net_836),
        .line_n(Net_837),
        .clock(Net_397));

    TCPWM_P4_v2_0_1 QuadDec_Rear (
        .stop(1'b0),
        .reload(1'b0),
        .start(Net_1095[1]),
        .count(Net_1095[0]),
        .capture(1'b0),
        .interrupt(Net_823),
        .ov(Net_824),
        .un(Net_825),
        .cc(Net_826),
        .line(Net_827),
        .line_n(Net_828),
        .clock(Net_397));

    SCB_P4_v3_0_2 UART (
        .interrupt(Net_816),
        .clock(1'b0),
        .rx_tr_out(Net_818),
        .tx_tr_out(Net_819));


	cy_clock_v1_0
		#(.id("bc1543b0-9302-487d-b6fc-c7ada39733b4"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("1000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_397));


	wire [0:0] tmpOE__M2QB_net;
	wire [0:0] tmpIO_0__M2QB_net;
	wire [0:0] tmpINTERRUPT_0__M2QB_net;
	electrical [0:0] tmpSIOVREF__M2QB_net;

	cy_psoc3_pins_v1_10
		#(.id("8d4d1162-3193-4c84-9203-b8e966d7d308"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		M2QB
		 (.oe(tmpOE__M2QB_net),
		  .y({1'b0}),
		  .fb({Net_1093[3]}),
		  .io({tmpIO_0__M2QB_net[0:0]}),
		  .siovref(tmpSIOVREF__M2QB_net),
		  .interrupt({tmpINTERRUPT_0__M2QB_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__M2QB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__M2QA_net;
	wire [0:0] tmpIO_0__M2QA_net;
	wire [0:0] tmpINTERRUPT_0__M2QA_net;
	electrical [0:0] tmpSIOVREF__M2QA_net;

	cy_psoc3_pins_v1_10
		#(.id("3c413afd-1b0d-4619-afae-4ce829bee841"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		M2QA
		 (.oe(tmpOE__M2QA_net),
		  .y({1'b0}),
		  .fb({Net_1093[2]}),
		  .io({tmpIO_0__M2QA_net[0:0]}),
		  .siovref(tmpSIOVREF__M2QA_net),
		  .interrupt({tmpINTERRUPT_0__M2QA_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__M2QA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__cursense1_net;
	wire [0:0] tmpFB_0__cursense1_net;
	wire [0:0] tmpIO_0__cursense1_net;
	wire [0:0] tmpINTERRUPT_0__cursense1_net;
	electrical [0:0] tmpSIOVREF__cursense1_net;

	cy_psoc3_pins_v1_10
		#(.id("77715107-f8d5-47e5-a629-0fb83101ac6b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		cursense1
		 (.oe(tmpOE__cursense1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__cursense1_net[0:0]}),
		  .analog({Net_1062}),
		  .io({tmpIO_0__cursense1_net[0:0]}),
		  .siovref(tmpSIOVREF__cursense1_net),
		  .interrupt({tmpINTERRUPT_0__cursense1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__cursense1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_1201,
            Net_1265
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

	wire [0:0] tmpOE__Mode_Front_net;
	wire [0:0] tmpFB_0__Mode_Front_net;
	wire [0:0] tmpIO_0__Mode_Front_net;
	wire [0:0] tmpINTERRUPT_0__Mode_Front_net;
	electrical [0:0] tmpSIOVREF__Mode_Front_net;

	cy_psoc3_pins_v1_10
		#(.id("a588a868-ad84-45c3-bfa5-9bca1479b2af"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Mode_Front
		 (.oe(tmpOE__Mode_Front_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Mode_Front_net[0:0]}),
		  .io({tmpIO_0__Mode_Front_net[0:0]}),
		  .siovref(tmpSIOVREF__Mode_Front_net),
		  .interrupt({tmpINTERRUPT_0__Mode_Front_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Mode_Front_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Mode_Rear_net;
	wire [0:0] tmpFB_0__Mode_Rear_net;
	wire [0:0] tmpIO_0__Mode_Rear_net;
	wire [0:0] tmpINTERRUPT_0__Mode_Rear_net;
	electrical [0:0] tmpSIOVREF__Mode_Rear_net;

	cy_psoc3_pins_v1_10
		#(.id("8791be04-a2b9-46e6-a1b6-ff5fd10e805b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Mode_Rear
		 (.oe(tmpOE__Mode_Rear_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Mode_Rear_net[0:0]}),
		  .io({tmpIO_0__Mode_Rear_net[0:0]}),
		  .siovref(tmpSIOVREF__Mode_Rear_net),
		  .interrupt({tmpINTERRUPT_0__Mode_Rear_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Mode_Rear_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- De Mux start --
    if (1)
    begin : demux_2
        reg  tmp__demux_2_0_reg;
        reg  tmp__demux_2_1_reg;
        always @(Net_1019 or Net_336)
        begin
            case (Net_336)
                1'b0:
                begin
                    tmp__demux_2_0_reg = Net_1019;
                    tmp__demux_2_1_reg = 1'b0;
                end
                1'b1:
                begin
                    tmp__demux_2_0_reg = 1'b0;
                    tmp__demux_2_1_reg = Net_1019;
                end
            endcase
        end
        assign Net_137 = tmp__demux_2_0_reg;
        assign Net_149 = tmp__demux_2_1_reg;
    end
    // -- De Mux end --

    CyControlReg_v1_80 Front_Dir (
        .control_1(Net_1036),
        .control_2(Net_1037),
        .control_3(Net_1038),
        .control_0(Net_304),
        .control_4(Net_1040),
        .control_5(Net_1041),
        .control_6(Net_1042),
        .control_7(Net_1043),
        .clock(1'b0),
        .reset(1'b0));
    defparam Front_Dir.Bit0Mode = 0;
    defparam Front_Dir.Bit1Mode = 0;
    defparam Front_Dir.Bit2Mode = 0;
    defparam Front_Dir.Bit3Mode = 0;
    defparam Front_Dir.Bit4Mode = 0;
    defparam Front_Dir.Bit5Mode = 0;
    defparam Front_Dir.Bit6Mode = 0;
    defparam Front_Dir.Bit7Mode = 0;
    defparam Front_Dir.BitValue = 0;
    defparam Front_Dir.BusDisplay = 0;
    defparam Front_Dir.ExtrReset = 0;
    defparam Front_Dir.NumOutputs = 1;

    TCPWM_P4_v2_0_3 PWM_Rear (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_870),
        .ov(Net_871),
        .un(Net_872),
        .cc(Net_873),
        .line(Net_1019),
        .line_n(Net_874),
        .clock(Net_983));


	cy_clock_v1_0
		#(.id("674b97d0-4faf-4f6f-957d-c6211b5493a2"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("83333333.3333333"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_2
		 (.clock_out(Net_983));


    cy_annotation_universal_v1_0 Motor_Front (
        .connect({
            Net_884,
            Net_885
        })
    );
    defparam Motor_Front.comp_name = "Motor_v1_0";
    defparam Motor_Front.port_names = "T1, T2";
    defparam Motor_Front.width = 2;

	wire [0:0] tmpOE__BIN2_2_net;
	wire [0:0] tmpFB_0__BIN2_2_net;
	wire [0:0] tmpIO_0__BIN2_2_net;
	wire [0:0] tmpINTERRUPT_0__BIN2_2_net;
	electrical [0:0] tmpSIOVREF__BIN2_2_net;

	cy_psoc3_pins_v1_10
		#(.id("88c65c5c-e421-47cd-bc9c-d6389fd2b8c2"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BIN2_2
		 (.oe(tmpOE__BIN2_2_net),
		  .y({Net_149}),
		  .fb({tmpFB_0__BIN2_2_net[0:0]}),
		  .io({tmpIO_0__BIN2_2_net[0:0]}),
		  .siovref(tmpSIOVREF__BIN2_2_net),
		  .interrupt({tmpINTERRUPT_0__BIN2_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BIN2_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 Motor_Rear (
        .connect({
            Net_890,
            Net_891
        })
    );
    defparam Motor_Rear.comp_name = "Motor_v1_0";
    defparam Motor_Rear.port_names = "T1, T2";
    defparam Motor_Rear.width = 2;

    ADC_SAR_SEQ_P4_v2_10_4 Motor_Current_ADC (
        .Vref(Net_1535),
        .sdone(Net_1536),
        .eoc(Net_1537),
        .aclk(1'b0),
        .soc(1'b0),
        .vinPlus0(Net_1302));

    // -- De Mux start --
    if (1)
    begin : demux_1
        reg  tmp__demux_1_0_reg;
        reg  tmp__demux_1_1_reg;
        always @(Net_303 or Net_304)
        begin
            case (Net_304)
                1'b0:
                begin
                    tmp__demux_1_0_reg = Net_303;
                    tmp__demux_1_1_reg = 1'b0;
                end
                1'b1:
                begin
                    tmp__demux_1_0_reg = 1'b0;
                    tmp__demux_1_1_reg = Net_303;
                end
            endcase
        end
        assign Net_98 = tmp__demux_1_0_reg;
        assign Net_101 = tmp__demux_1_1_reg;
    end
    // -- De Mux end --

    TCPWM_P4_v2_0_5 PWM_Front (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_860),
        .ov(Net_861),
        .un(Net_862),
        .cc(Net_863),
        .line(Net_303),
        .line_n(Net_864),
        .clock(Net_983));

	wire [0:0] tmpOE__AIN2_2_net;
	wire [0:0] tmpFB_0__AIN2_2_net;
	wire [0:0] tmpIO_0__AIN2_2_net;
	wire [0:0] tmpINTERRUPT_0__AIN2_2_net;
	electrical [0:0] tmpSIOVREF__AIN2_2_net;

	cy_psoc3_pins_v1_10
		#(.id("691fd598-0708-4bf6-9d69-091ed15f3a12"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		AIN2_2
		 (.oe(tmpOE__AIN2_2_net),
		  .y({Net_149}),
		  .fb({tmpFB_0__AIN2_2_net[0:0]}),
		  .io({tmpIO_0__AIN2_2_net[0:0]}),
		  .siovref(tmpSIOVREF__AIN2_2_net),
		  .interrupt({tmpINTERRUPT_0__AIN2_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__AIN2_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__BIN1_2_net;
	wire [0:0] tmpFB_0__BIN1_2_net;
	wire [0:0] tmpIO_0__BIN1_2_net;
	wire [0:0] tmpINTERRUPT_0__BIN1_2_net;
	electrical [0:0] tmpSIOVREF__BIN1_2_net;

	cy_psoc3_pins_v1_10
		#(.id("d641017b-b082-44c2-92fe-ce18db066e18"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BIN1_2
		 (.oe(tmpOE__BIN1_2_net),
		  .y({Net_137}),
		  .fb({tmpFB_0__BIN1_2_net[0:0]}),
		  .io({tmpIO_0__BIN1_2_net[0:0]}),
		  .siovref(tmpSIOVREF__BIN1_2_net),
		  .interrupt({tmpINTERRUPT_0__BIN1_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BIN1_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__AIN1_2_net;
	wire [0:0] tmpFB_0__AIN1_2_net;
	wire [0:0] tmpIO_0__AIN1_2_net;
	wire [0:0] tmpINTERRUPT_0__AIN1_2_net;
	electrical [0:0] tmpSIOVREF__AIN1_2_net;

	cy_psoc3_pins_v1_10
		#(.id("0d9ced7a-0379-4a2e-91e0-612df985d662"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		AIN1_2
		 (.oe(tmpOE__AIN1_2_net),
		  .y({Net_137}),
		  .fb({tmpFB_0__AIN1_2_net[0:0]}),
		  .io({tmpIO_0__AIN1_2_net[0:0]}),
		  .siovref(tmpSIOVREF__AIN1_2_net),
		  .interrupt({tmpINTERRUPT_0__AIN1_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__AIN1_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__BIN2_1_net;
	wire [0:0] tmpFB_0__BIN2_1_net;
	wire [0:0] tmpIO_0__BIN2_1_net;
	wire [0:0] tmpINTERRUPT_0__BIN2_1_net;
	electrical [0:0] tmpSIOVREF__BIN2_1_net;

	cy_psoc3_pins_v1_10
		#(.id("73bc00c9-6a50-4ee0-b144-76690bd3c4bb"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BIN2_1
		 (.oe(tmpOE__BIN2_1_net),
		  .y({Net_101}),
		  .fb({tmpFB_0__BIN2_1_net[0:0]}),
		  .io({tmpIO_0__BIN2_1_net[0:0]}),
		  .siovref(tmpSIOVREF__BIN2_1_net),
		  .interrupt({tmpINTERRUPT_0__BIN2_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BIN2_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__AIN2_1_net;
	wire [0:0] tmpFB_0__AIN2_1_net;
	wire [0:0] tmpIO_0__AIN2_1_net;
	wire [0:0] tmpINTERRUPT_0__AIN2_1_net;
	electrical [0:0] tmpSIOVREF__AIN2_1_net;

	cy_psoc3_pins_v1_10
		#(.id("33202954-1d99-4626-8a94-1711b14b7794"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		AIN2_1
		 (.oe(tmpOE__AIN2_1_net),
		  .y({Net_101}),
		  .fb({tmpFB_0__AIN2_1_net[0:0]}),
		  .io({tmpIO_0__AIN2_1_net[0:0]}),
		  .siovref(tmpSIOVREF__AIN2_1_net),
		  .interrupt({tmpINTERRUPT_0__AIN2_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__AIN2_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__BIN1_1_net;
	wire [0:0] tmpFB_0__BIN1_1_net;
	wire [0:0] tmpIO_0__BIN1_1_net;
	wire [0:0] tmpINTERRUPT_0__BIN1_1_net;
	electrical [0:0] tmpSIOVREF__BIN1_1_net;

	cy_psoc3_pins_v1_10
		#(.id("f09cb779-deef-4416-a9d4-afcfe187c2b7"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		BIN1_1
		 (.oe(tmpOE__BIN1_1_net),
		  .y({Net_98}),
		  .fb({tmpFB_0__BIN1_1_net[0:0]}),
		  .io({tmpIO_0__BIN1_1_net[0:0]}),
		  .siovref(tmpSIOVREF__BIN1_1_net),
		  .interrupt({tmpINTERRUPT_0__BIN1_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__BIN1_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__AIN1_1_net;
	wire [0:0] tmpFB_0__AIN1_1_net;
	wire [0:0] tmpIO_0__AIN1_1_net;
	wire [0:0] tmpINTERRUPT_0__AIN1_1_net;
	electrical [0:0] tmpSIOVREF__AIN1_1_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		AIN1_1
		 (.oe(tmpOE__AIN1_1_net),
		  .y({Net_98}),
		  .fb({tmpFB_0__AIN1_1_net[0:0]}),
		  .io({tmpIO_0__AIN1_1_net[0:0]}),
		  .siovref(tmpSIOVREF__AIN1_1_net),
		  .interrupt({tmpINTERRUPT_0__AIN1_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__AIN1_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Power_Front_net;
	wire [0:0] tmpFB_0__Power_Front_net;
	wire [0:0] tmpIO_0__Power_Front_net;
	wire [0:0] tmpINTERRUPT_0__Power_Front_net;
	electrical [0:0] tmpSIOVREF__Power_Front_net;

	cy_psoc3_pins_v1_10
		#(.id("86dd5c1a-6fbc-48a9-8e9f-0e18c702343a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Power_Front
		 (.oe(tmpOE__Power_Front_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Power_Front_net[0:0]}),
		  .io({tmpIO_0__Power_Front_net[0:0]}),
		  .siovref(tmpSIOVREF__Power_Front_net),
		  .interrupt({tmpINTERRUPT_0__Power_Front_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Power_Front_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Power_Rear_net;
	wire [0:0] tmpFB_0__Power_Rear_net;
	wire [0:0] tmpIO_0__Power_Rear_net;
	wire [0:0] tmpINTERRUPT_0__Power_Rear_net;
	electrical [0:0] tmpSIOVREF__Power_Rear_net;

	cy_psoc3_pins_v1_10
		#(.id("ea12f4e0-52d6-43a8-a00a-e0ceef1cefaa"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Power_Rear
		 (.oe(tmpOE__Power_Rear_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Power_Rear_net[0:0]}),
		  .io({tmpIO_0__Power_Rear_net[0:0]}),
		  .siovref(tmpSIOVREF__Power_Rear_net),
		  .interrupt({tmpINTERRUPT_0__Power_Rear_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Power_Rear_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_1202,
            Net_1204
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_1202
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_1265
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

    cy_annotation_universal_v1_0 Front_VSS (
        .connect({
            Net_1201,
            Net_1212,
            Net_1213,
            Net_1214,
            Net_1215,
            Net_1216,
            Net_1217,
            Net_1218,
            Net_1219,
            Net_1220,
            Net_1221,
            Net_1203,
            Net_1222,
            Net_1205,
            Net_1206,
            Net_1207,
            Net_1208,
            Net_1209,
            Net_1210,
            Net_1211
        })
    );
    defparam Front_VSS.comp_name = "Connector20_v1_0";
    defparam Front_VSS.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Front_VSS.width = 20;

    cy_annotation_universal_v1_0 Rear_VSS (
        .connect({
            Net_1204,
            Net_1231,
            Net_1232,
            Net_1233,
            Net_1234,
            Net_1235,
            Net_1236,
            Net_1237,
            Net_1238,
            Net_1239,
            Net_1240,
            Net_1223,
            Net_1241,
            Net_1224,
            Net_1225,
            Net_1226,
            Net_1227,
            Net_1228,
            Net_1229,
            Net_1230
        })
    );
    defparam Rear_VSS.comp_name = "Connector20_v1_0";
    defparam Rear_VSS.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Rear_VSS.width = 20;

	wire [0:0] tmpOE__cursense2_net;
	wire [0:0] tmpFB_0__cursense2_net;
	wire [0:0] tmpIO_0__cursense2_net;
	wire [0:0] tmpINTERRUPT_0__cursense2_net;
	electrical [0:0] tmpSIOVREF__cursense2_net;

	cy_psoc3_pins_v1_10
		#(.id("0b3760e4-aebb-4240-9f49-cd8780b78946"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		cursense2
		 (.oe(tmpOE__cursense2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__cursense2_net[0:0]}),
		  .analog({Net_1063}),
		  .io({tmpIO_0__cursense2_net[0:0]}),
		  .siovref(tmpSIOVREF__cursense2_net),
		  .interrupt({tmpINTERRUPT_0__cursense2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__cursense2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 Front_Driver_P11 (
        .connect({
            Net_1988,
            Net_940,
            Net_941,
            Net_942,
            Net_943,
            Net_944,
            Net_945,
            Net_946,
            Net_947,
            Net_948,
            Net_949,
            Net_932,
            Net_950,
            Net_933,
            Net_934,
            Net_935,
            Net_936,
            Net_937,
            Net_938,
            Net_939
        })
    );
    defparam Front_Driver_P11.comp_name = "Connector20_v1_0";
    defparam Front_Driver_P11.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Front_Driver_P11.width = 20;

    cy_annotation_universal_v1_0 Rear_Driver_P11 (
        .connect({
            Net_2013,
            Net_959,
            Net_960,
            Net_961,
            Net_962,
            Net_963,
            Net_964,
            Net_965,
            Net_966,
            Net_967,
            Net_968,
            Net_951,
            Net_969,
            Net_952,
            Net_953,
            Net_954,
            Net_955,
            Net_956,
            Net_957,
            Net_958
        })
    );
    defparam Rear_Driver_P11.comp_name = "Connector20_v1_0";
    defparam Rear_Driver_P11.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Rear_Driver_P11.width = 20;

    cy_annotation_universal_v1_0 Front_Driver_P12 (
        .connect({
            Net_1938,
            Net_978,
            Net_979,
            Net_980,
            Net_981,
            Net_982,
            Net_984,
            Net_985,
            Net_986,
            Net_987,
            Net_988,
            Net_970,
            Net_989,
            Net_971,
            Net_972,
            Net_973,
            Net_974,
            Net_975,
            Net_976,
            Net_977
        })
    );
    defparam Front_Driver_P12.comp_name = "Connector20_v1_0";
    defparam Front_Driver_P12.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Front_Driver_P12.width = 20;

    cy_annotation_universal_v1_0 Rear_Driver_P12 (
        .connect({
            Net_1963,
            Net_998,
            Net_999,
            Net_1000,
            Net_1001,
            Net_1002,
            Net_1003,
            Net_1004,
            Net_1005,
            Net_1006,
            Net_1007,
            Net_990,
            Net_1008,
            Net_991,
            Net_992,
            Net_993,
            Net_994,
            Net_995,
            Net_996,
            Net_997
        })
    );
    defparam Rear_Driver_P12.comp_name = "Connector20_v1_0";
    defparam Rear_Driver_P12.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam Rear_Driver_P12.width = 20;

    CyControlReg_v1_80 Rear_Dir (
        .control_1(Net_1068),
        .control_2(Net_1069),
        .control_3(Net_1070),
        .control_0(Net_336),
        .control_4(Net_1071),
        .control_5(Net_1072),
        .control_6(Net_1073),
        .control_7(Net_1074),
        .clock(1'b0),
        .reset(1'b0));
    defparam Rear_Dir.Bit0Mode = 0;
    defparam Rear_Dir.Bit1Mode = 0;
    defparam Rear_Dir.Bit2Mode = 0;
    defparam Rear_Dir.Bit3Mode = 0;
    defparam Rear_Dir.Bit4Mode = 0;
    defparam Rear_Dir.Bit5Mode = 0;
    defparam Rear_Dir.Bit6Mode = 0;
    defparam Rear_Dir.Bit7Mode = 0;
    defparam Rear_Dir.BitValue = 0;
    defparam Rear_Dir.BusDisplay = 0;
    defparam Rear_Dir.ExtrReset = 0;
    defparam Rear_Dir.NumOutputs = 1;

    GlitchFilter_v2_0 GlitchFilter_1 (
        .d(Net_1093[3:0]),
        .reset(1'b0),
        .clock(Net_397),
        .q(Net_1095[3:0]));
    defparam GlitchFilter_1.BypassFilter = 0;
    defparam GlitchFilter_1.GlitchLength = 4;
    defparam GlitchFilter_1.SignalWidth = 4;

    OpAmp_P4_v1_10_6 Opamp_1 (
        .Vplus(Net_1437),
        .Vout(Net_1302),
        .Vminus(Net_1290));

    cy_annotation_universal_v1_0 R_3 (
        .connect({
            Net_1366,
            Net_1359
        })
    );
    defparam R_3.comp_name = "Resistor_v1_0";
    defparam R_3.port_names = "T1, T2";
    defparam R_3.width = 2;

    cy_annotation_universal_v1_0 R_4 (
        .connect({
            Net_1365,
            Net_1366
        })
    );
    defparam R_4.comp_name = "Resistor_v1_0";
    defparam R_4.port_names = "T1, T2";
    defparam R_4.width = 2;

	wire [0:0] tmpOE__opamp_out_net;
	wire [0:0] tmpFB_0__opamp_out_net;
	wire [0:0] tmpIO_0__opamp_out_net;
	wire [0:0] tmpINTERRUPT_0__opamp_out_net;
	electrical [0:0] tmpSIOVREF__opamp_out_net;

	cy_psoc3_pins_v1_10
		#(.id("173a5e76-f97b-451a-b777-6a89e05155c0"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		opamp_out
		 (.oe(tmpOE__opamp_out_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__opamp_out_net[0:0]}),
		  .analog({Net_1302}),
		  .io({tmpIO_0__opamp_out_net[0:0]}),
		  .siovref(tmpSIOVREF__opamp_out_net),
		  .interrupt({tmpINTERRUPT_0__opamp_out_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__opamp_out_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__inverting_in_net;
	wire [0:0] tmpFB_0__inverting_in_net;
	wire [0:0] tmpIO_0__inverting_in_net;
	wire [0:0] tmpINTERRUPT_0__inverting_in_net;
	electrical [0:0] tmpSIOVREF__inverting_in_net;

	cy_psoc3_pins_v1_10
		#(.id("0c570274-82c8-4d58-a7fb-30490dc54b55"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		inverting_in
		 (.oe(tmpOE__inverting_in_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__inverting_in_net[0:0]}),
		  .analog({Net_1290}),
		  .io({tmpIO_0__inverting_in_net[0:0]}),
		  .siovref(tmpSIOVREF__inverting_in_net),
		  .interrupt({tmpINTERRUPT_0__inverting_in_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__inverting_in_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- AMux AMux_1 start -- ***
    // -- Mux A --
    
    cy_psoc3_amux_v1_0 AMux_1(
        .muxin({
            Net_1063,
            Net_1062
            }),
        .vout(Net_1437)
        );
    
    defparam AMux_1.muxin_width = 2;
    defparam AMux_1.init_mux_sel = 2'h0;
    defparam AMux_1.one_active = 0;
    defparam AMux_1.connect_mode = 1;
    
    // -- AMux AMux_1 end --

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_1365
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;



endmodule

