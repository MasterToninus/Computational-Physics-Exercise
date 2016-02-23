

clear
reset

#set term latex
#set output "plot.tex"

set multiplot layout 1,3
set xtics rotate
set bmargin 5
#
set title "t = 0 "
set size ratio -1

set view map
unset surface
set style data pm3d

unset xlabel
unset xtics ; unset ytics 
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
unset colorbox
splot 'Cluster_Riscaldamento_0.dat'
#
set title "t = 1"
set size ratio -1

set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Cluster_Riscaldamento_1.dat'
#
set title "t = 5 "
set size ratio -1

set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Cluster_Riscaldamento_5.dat'
#
unset multiplot
#set term x11
#set output

	

