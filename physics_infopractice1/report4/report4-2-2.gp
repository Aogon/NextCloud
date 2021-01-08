set title 'Monte Carlo method for caluclating volume of Ellipsoid'
set xlabel 'N'
set ylabel 'Relative error'
set logscale
set format x '10^{%L}'
set format y '10^{%L}'
plot 'report4-2-2.dat' u 2:4 w lp lw 2  pt 7, 1/sqrt(x)