# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\K Documents\Coroware\github_coro\Spark_Firmware\firmware\Spark-Interface\MSFT_Interface.cydsn\MSFT_Interface.cyprj
# Date: Sat, 01 Aug 2015 22:11:53 GMT
#set_units -time ns
create_clock -name {ADC_IntClock(routed)} -period 696.969696969697 -waveform {0 348.484848484849} [list [get_pins {ClockBlock/dclk_1}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.151515151515152 -waveform {0 7.57575757575758} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {ADC_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 47 93} -nominal_period 696.969696969697 [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {U_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 73 145} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 661 1321} -nominal_period 10000 [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 7 11} -nominal_period 83.333333333333329 [list [get_pins {ClockBlock/dclk_glb_0}]]


# Component constraints for E:\K Documents\Coroware\github_coro\Spark_Firmware\firmware\Spark-Interface\MSFT_Interface.cydsn\TopDesign\TopDesign.cysch
# Project: E:\K Documents\Coroware\github_coro\Spark_Firmware\firmware\Spark-Interface\MSFT_Interface.cydsn\MSFT_Interface.cyprj
# Date: Sat, 01 Aug 2015 22:11:36 GMT
