clear
reset

#set title "<S_0 S_t> vs t (Cluster)"
set style data dots
set bars large

plot "Cluster_S0Stvst_0.dat" using 1:2:3 title "{/Symbol b} = 0.01 " w yerrorbars 		 lw 3 lc 1 
A_0=1
f_0(x)= exp(-x/A_0)
N=3
	fit f_0(x) "Cluster_S0Stvst_0.dat" every ::0::N using 1:2:3 via A_0
	replot f_0(x) notitle																 lw 1 lt 1 lc 0		

replot "Cluster_S0Stvst_1.dat" using 1:2:3 title "{/Symbol b} = 0.21 " with yerrorbars	 lw 3 lc 2
A_1=1
f_1(x)= exp(-x/A_1)
N=5
	fit f_1(x) "Cluster_S0Stvst_1.dat" every ::0::N using 1:2:3 via A_1
	replot f_1(x) notitle																  lw 1 lt 1 lc 0		

replot "Cluster_S0Stvst_2.dat" using 1:2:3 title "{/Symbol b} = 0.41 " with yerrorbars	 lw 3 lc 3
A_2=1
f_2(x)= exp(-x/A_2)
N=25
	fit f_2(x) "Cluster_S0Stvst_2.dat" every ::0::N using 1:2:3 via A_2
	replot f_2(x) notitle																  lw 1 lt 1 lc 0		

replot "Cluster_S0Stvst_4.dat" using 1:2:3 title "{/Symbol b} = 0.42 " with yerrorbars	 lw 3 lc 9
A_4=1
f_4(x)= exp(-x/A_4)
N=40
	fit f_4(x) "Cluster_S0Stvst_4.dat" every ::0::N using 1:2:3 via A_4
	replot f_4(x) notitle																  lw 1 lt 1 lc 0	

replot "Cluster_S0Stvst_5.dat" using 1:2:3 title "{/Symbol b} = 0.425 " with yerrorbars  lw 3 lc 4	
A_5=1
f_5(x)= exp(-x/A_5)
N=50
	fit f_5(x) "Cluster_S0Stvst_5.dat" every ::0::N using 1:2:3 via A_5
	replot f_5(x) notitle																  lw 1 lt 1 lc 0		

	replot "Cluster_S0Stvst_6.dat" using 1:2:3 title "{/Symbol b} = 0.43 " with yerrorbars	 lw 3 lc 11
A_6=1
f_6(x)= exp(-x/A_6)
N=50
	fit f_6(x) "Cluster_S0Stvst_6.dat" every ::0::N using 1:2:3 via A_6
	replot f_6(x) notitle																 lw 1 lt 1 lc 0		

	replot "Cluster_S0Stvst_7.dat" using 1:2:3 title "{/Symbol b} = 0.435 " with yerrorbars  lw 3 lc 5	
A_7=1
f_7(x)= exp(-x/A_7)
N=50
	fit f_7(x) "Cluster_S0Stvst_7.dat" every ::0::N using 1:2:3 via A_7
	replot f_7(x) notitle																 lw 1 lt 1 lc 0			

	replot "Cluster_S0Stvst_8.dat" using 1:2:3 title "{/Symbol b}_{critica} " with yerrorbars lw 3 lc 18		
A_8=1
f_8(x)= exp(-x/A_8)
N=50
	fit f_8(x) "Cluster_S0Stvst_8.dat" every ::0::N using 1:2:3 via A_8
	replot f_8(x) notitle																  lw 1 lt 1 lc 0			

	replot "Cluster_S0Stvst_3.dat" using 1:2:3 title "{/Symbol b} = 0.61 " with yerrorbars  lw 3 lc 8	
	replot "Cluster_S0Stvst_3.dat" notitle "{/Symbol b} = 0.01 " 		 w lines		 lw 1 lt 1 lc 0	

replot exp(-1) lc 0 lt 7

set terminal postscript eps size 15cm,7cm enhanced color \
    font 'Helvetica,20' linewidth 1.5
set pointsize 1.25
set grid
set xzeroaxis lc -1 lt -1 lw 1
set yzeroaxis lc -1 lt -1 lw 1
unset border

#set log x
set xlabel " t" font "Times-Italic,22" offset 0,1.5
set xrange [0:100]
set xtics 20
set mxtic 2

set ylabel "< S_0 S_t >" font "Times-Italic,22" offset 2.5,0 rotate by 90
set yrange [-0.05:1]
set ytics 0.2
set mytic 2

set xtics nomirror
set ytics nomirror

set output 'Cluster_S0Stvst.eps'
replot
set output '|epstopdf  Cluster_S0Stvst.eps'

set term x11
set output
  
