

clear
reset

set title "<S0 St> vs t (Metropolis)"


set xlabel "t"
set xrange [0:100]

set ylabel "<S0 St>"
set yrange [-0.05:0.4]

plot " Metro_S0Stvst_0.dat" using 1:2 title "beta = 0.01 " w yerrorbars 	
replot " Metro_S0Stvst_1.dat" using 1:2 title "beta = 0.21 " with yerrorbars	
replot " Metro_S0Stvst_2.dat" using 1:2 title "beta = 0.41 " with yerrorbars
replot " Metro_S0Stvst_5.dat" using 1:2 title "beta = 0.426 " with yerrorbars	
replot " Metro_S0Stvst_6.dat" using 1:2 title "beta = 0.43 " with yerrorbars	
replot " Metro_S0Stvst_7.dat" using 1:2 title "beta = 0.436 " with yerrorbars	
replot " Metro_S0Stvst_8.dat" using 1:2 title "beta_critica " with yerrorbars		
#replot " Metro_S0Stvst_3.dat" using 1:2 title "beta = 0.61 " with yerrorbars	

  
