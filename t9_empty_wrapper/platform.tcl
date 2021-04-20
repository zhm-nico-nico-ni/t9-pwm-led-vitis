# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct H:\prj\t9_empty_wrapper\platform.tcl
# 
# OR launch xsct and run below command.
# source H:\prj\t9_empty_wrapper\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {t9_empty_wrapper}\
-hw {H:\project_2\t9_empty_wrapper.xsa}\
-fsbl-target {psu_cortexa53_0} -out {H:/prj}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {zynq_fsbl}
platform generate -domains 
platform active {t9_empty_wrapper}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
platform clean
platform generate
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_2/t9_empty_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform clean
platform generate
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
domain active {zynq_fsbl}
bsp reload
domain active {standalone_ps7_cortexa9_0}
bsp reload
platform generate -domains 
platform generate
platform clean
platform generate
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform clean
platform generate
platform clean
platform generate
platform active {t9_empty_wrapper}
bsp reload
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform clean
platform generate
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform active {t9_empty_wrapper}
platform config -updatehw {H:/project_3/t9_1_wrapper.xsa}
platform generate -domains 
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
domain active {zynq_fsbl}
bsp reload
bsp reload
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform clean
platform active {t9_empty_wrapper}
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform clean
platform active {t9_empty_wrapper}
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform generate
platform config -updatehw {H:/t9_now_work/t9_1_wrapper.xsa}
platform generate -domains 
