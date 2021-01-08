#set title 'Monte Carlo method for caluclating volume of Ellipsoid'
#set xlabel 'N'
#set ylabel 'Relative error'
set logscale y
#set format x '10^{%L}'
set format y '10^{%L}'
plot 'jisshu8-0-3.dat' u 1:2 w l lw 2