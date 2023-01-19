[[ -z $1 ]] && { echo "missing arg"; exit; }
path=*$(echo $@ | tr ' ' '*')*
find $PWD -type f -ipath $path | grep -viP '.swp$'
