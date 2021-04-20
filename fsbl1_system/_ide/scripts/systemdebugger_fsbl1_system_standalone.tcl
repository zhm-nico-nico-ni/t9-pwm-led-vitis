# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: H:\prj\fsbl1_system\_ide\scripts\systemdebugger_fsbl1_system_standalone.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source H:\prj\fsbl1_system\_ide\scripts\systemdebugger_fsbl1_system_standalone.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -nocase -filter {name =~"APU*"}
rst -system
after 3000
targets -set -filter {jtag_cable_name =~ "Digilent JTAG-SMT2 21025DA10329" && level==0 && jtag_device_ctx=="jsn-JTAG-SMT2-21025DA10329-13722093-0"}
fpga -file H:/prj/fsbl1/_ide/bitstream/t9_1_wrapper.bit
targets -set -nocase -filter {name =~"APU*"}
loadhw -hw H:/prj/t9_empty_wrapper/export/t9_empty_wrapper/hw/t9_1_wrapper.xsa -mem-ranges [list {0x40000000 0xbfffffff}] -regs
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*"}
source H:/prj/fsbl1/_ide/psinit/ps7_init.tcl
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "*A9*#0"}
dow H:/prj/fsbl1/Debug/fsbl1.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~ "*A9*#0"}
con
