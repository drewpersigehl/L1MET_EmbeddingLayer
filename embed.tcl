open_project -reset embed-proj
set_top embed
add_files embed.cpp
add_files embed.h
add_files -tb embed-test.cpp
open_solution "solution1"
set_part {xa7a12tcsg325-1q}
create_clock -period 10 -name default

csim_design -clean
csynth_design
cosim_design
export_design -format ip_catalog
