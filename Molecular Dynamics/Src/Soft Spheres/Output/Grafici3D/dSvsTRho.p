clear
reset

set xlabel "T_D [T]"
	set xrange [0.05: 1.2]

set ylabel " {\Symbol r} [d]"
	set yrange [0.05: 1.2]

set zlabel " dS^2 [{\Symbol s}]"
	set zrange [0: 1.2]

   set surface
splot './dSvsTRho.dat' 
