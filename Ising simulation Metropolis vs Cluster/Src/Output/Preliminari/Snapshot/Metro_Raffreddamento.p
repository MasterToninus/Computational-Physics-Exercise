

clear
reset
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
splot 'Metro_Raffreddamento_0.dat'
#
set title "t = 5"
set size ratio -1

set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Metro_Raffreddamento_5.dat'
#
set title "t = 30 "
set size ratio -1

set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Metro_Raffreddamento_30.dat'
#
unset multiplot


	

