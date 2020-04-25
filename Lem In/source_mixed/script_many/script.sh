gen_result="./gen_result"
gen_map="./gen_map"
var_present=""
var_required=""
var_failed_number=0

make lem-in -C ../../

rm -f map_*
rm -f fail_map_*

for (( i=1; i <= $1; i++ ))
do
../script_one/script.sh "$2"
var_present="$(wc -l < ${gen_result} | sed 's/[^0-9]*//g')"
var_required="$(sed '2q;d' ${gen_map} | sed 's/[^0-9]*//g')"
if [ "${var_present}" -gt "${var_required}" ]; then
  printf "\033[0;31m"
  cp "${gen_map}" fail_map_$i
  var_failed_number=$((var_failed_number+1))
else
  printf "\033[0;32m"
  cp "${gen_map}" map_$i
fi
echo "Test no. $i : ${var_present}/${var_required}"
printf "\033[0m"
done

echo "Number of failed tests : ${var_failed_number}"

rm ${gen_result}
rm ${gen_map}