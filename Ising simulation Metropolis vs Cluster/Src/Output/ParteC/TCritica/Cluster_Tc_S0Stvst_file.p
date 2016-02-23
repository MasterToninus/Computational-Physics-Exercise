## -_-_-_

clear
reset

# set title "Funzione di correlazione S0St vs t con algoritmo Swenden Wang a BETA CRITICO"


set xlabel "t"
set xrange [0:100]

set ylabel "CA(t)"
set yrange [0:1]
#set logscale y


plot "Cluster_Tc_S0Stvst_N330.dat" title "L = 330" 				lw 1 lt 1 lc 1
#	replot "Cluster_Tc_S0Stvst_N320.dat" title "L = 320" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N310.dat" title "L = 310" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N300.dat" title "L = 300" 	#	w l
replot "Cluster_Tc_S0Stvst_N290.dat" title "L = 290" 			lw 1 lt 1 lc 2
#	replot "Cluster_Tc_S0Stvst_N280.dat" title "L = 280" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N270.dat" title "L = 270" 	#	w l
replot "Cluster_Tc_S0Stvst_N260.dat" title "L = 260" 			lw 1 lt 1 lc 3
#	replot "Cluster_Tc_S0Stvst_N250.dat" title "L = 250" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N240.dat" title "L = 240" 	#	w l
replot "Cluster_Tc_S0Stvst_N230.dat" title "L = 230" 			lw 1 lt 1 lc 4
#	replot "Cluster_Tc_S0Stvst_N220.dat" title "L = 220" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N210.dat" title "L = 210" 	#	w l
replot "Cluster_Tc_S0Stvst_N200.dat" title "L = 200" 			lw 1 lt 1 lc 5
#	replot "Cluster_Tc_S0Stvst_N190.dat" title "L = 190" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N180.dat" title "L = 180" 	#	w l
replot "Cluster_Tc_S0Stvst_N170.dat" title "L = 170" 			lw 1 lt 1 lc 6

A_0=1
f_0(x)= exp(-x/A_0)
N=15
	fit f_0(x) "Cluster_Tc_S0Stvst_N330.dat" every ::0::N using 1:2:3 via A_0
	replot f_0(x) notitle																 lw 1 lt 1 lc 1		

A_1=1
f_1(x)= exp(-x/A_1)
#	N=50
	fit f_1(x) "Cluster_Tc_S0Stvst_N290.dat" every ::0::N using 1:2:3 via A_1
	replot f_1(x) notitle																  lw 1 lt 1 lc 2		

A_2=1
f_2(x)= exp(-x/A_2)
#	N=50
	fit f_2(x) "Cluster_Tc_S0Stvst_N260.dat" every ::0::N using 1:2:3 via A_2
	replot f_2(x) notitle																  lw 1 lt 1 lc 3		

A_3=1
f_3(x)= exp(-x/A_3)
#	N=50
	fit f_3(x) "Cluster_Tc_S0Stvst_N230.dat" every ::0::N using 1:2:3 via A_3
	replot f_3(x) notitle																  lw 1 lt 1 lc 4

A_4=1
f_4(x)= exp(-x/A_4)
#	N=50
	fit f_4(x) "Cluster_Tc_S0Stvst_N200.dat" every ::0::N using 1:2:3 via A_4
	replot f_4(x) notitle																  lw 1 lt 1 lc 5	

A_5=1
f_5(x)= exp(-x/A_5)
#	N=50
	fit f_5(x) "Cluster_Tc_S0Stvst_N170.dat" every ::0::N using 1:2:3 via A_5
	replot f_5(x) notitle																  lw 1 lt 1 lc 6	







#	replot exp(-1) lc 0 lt 7

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.25
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
unset border

#set log y
set xlabel " t" font "Times-Italic,22" offset 0,1.5
set xrange [0:100]
set xtics 20
set mxtic 2

set ylabel "< S_0 S_t >" font "Times-Italic,22" offset 2.5,0 rotate by 90
set yrange [0.7:1]
set ytics 0.1
set mytic 2

set xtics nomirror
set ytics nomirror

set output 'Cluster_Tc_S0Stvst.eps'
replot
set output '|epstopdf  Cluster_Tc_S0Stvst.eps'

set term x11
set output


