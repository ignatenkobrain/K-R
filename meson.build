project('K&R', 'c')

glib_dep = dependency('glib-2.0')
scols_dep = dependency('smartcols')

executable('1.3', '1.3.c')
executable('1.5', '1.5.c')
executable('1.14', '1.14.c', dependencies : [glib_dep, scols_dep])
executable('1.15', '1.15.c', dependencies : [glib_dep, scols_dep])
