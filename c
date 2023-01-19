[[ -z $1 ]] && { echo "missing args"; exit; }

clone=$1
shift

if [[ -z $1 ]];
then
    found=$(cat -)
else
    found=$(f $@)
fi

[[ -z $found ]] && { echo "nothing found"; exit; }
count=$(echo "$found" | wc -l)
if [[ $count -gt 1 ]]; 
then 
    echo "$found"
else
    f=$(dirname $found)/$clone
    cp $found $f
    echo "Created $f"
fi
