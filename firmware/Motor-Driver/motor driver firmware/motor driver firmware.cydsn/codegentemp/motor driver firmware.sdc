# THIS FILE IS AUTOMATICALLY GENERATED
# Project: I:\Dropbox\coroware\github\Spark_Firmware\firmware\Motor-Driver\motor driver firmware\motor driver firmware.cydsn\motor driver firmware.cyprj
# Date: Tue, 06 Oct 2015 21:30:57 GMT
#set_units -time ns
create_clock -name {Clock_2(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_8}] [get_pins {ClockBlock/ff_div_11}]]
create_clock -name {Clock_1(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_9}] [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {Motor_Current_ADC_intClock(FFB)} -period 166.66666666666666 -waveform {0 83.3333333333333} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {UART_SCBCLK(FFB)} -period 1333.3333333333333 -waveform {0 666.666666666667} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {Motor_Current_ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 33 65} [list]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for I:\Dropbox\coroware\github\Spark_Firmware\firmware\Motor-Driver\motor driver firmware\motor driver firmware.cydsn\TopDesign\TopDesign.cysch
# Project: I:\Dropbox\coroware\github\Spark_Firmware\firmware\Motor-Driver\motor driver firmware\motor driver firmware.cydsn\motor driver firmware.cyprj
# Date: Tue, 06 Oct 2015 21:30:53 GMT
