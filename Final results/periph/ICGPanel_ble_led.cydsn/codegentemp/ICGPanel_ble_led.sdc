# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\gala_\Documents\cycling_glove\together\AN91162\ICGPanel_ble_led.cydsn\ICGPanel_ble_led.cyprj
# Date: Sat, 16 Jan 2021 21:07:12 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFCLK} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {StripLights_Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\Users\gala_\Documents\cycling_glove\together\AN91162\ICGPanel_ble_led.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\gala_\Documents\cycling_glove\together\AN91162\ICGPanel_ble_led.cydsn\ICGPanel_ble_led.cyprj
# Date: Sat, 16 Jan 2021 21:07:07 GMT
