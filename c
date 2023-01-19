[[ -z $2 ]] && { echo "missing args"; exit; }
clone=$1
shift
found=$(f $@)
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
