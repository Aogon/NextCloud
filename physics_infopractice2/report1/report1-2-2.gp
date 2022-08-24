# gnuplotの設定
set xlabel "ステップ数"
set logscale x #x軸は対数目盛
unset logscale y #y軸は通常目盛
plot "report1-2.dat" using 1:4 with linespoints title "abs(error/h-a)" #プロット