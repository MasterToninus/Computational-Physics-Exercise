## prototipo di plot stato di ising

clear
reset
set size ratio -1

N= 120.0000


set view map
unset surface
set style data pm3d

unset xlabel
unset key

set pm3d implicit at b
set palette positive nops_allcF maxcolors 0 gamma 1.5 gray
splot 'Metro_Raffreddamento_0.dat'	

