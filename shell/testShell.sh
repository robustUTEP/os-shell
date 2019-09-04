#set -x
if [ -z $1 ] ; then 
    echo "Usage: $0 [myShell]" >&2
    exit 1
fi
myShell=$1

export PS1=""			# supress prompt

_uname=$(which uname)
_cat=$(which cat)
_passwd=$(which passwd)

rm -f testLog.txt


chkcmd () {
    echo "Testing $2"
    echo -e "$1" | bash > /tmp/t1
    echo -e "$1" | $myShell > /tmp/t2
    if diff /tmp/t1 /tmp/t2 ; then
	result=PASSED
    else
	result=FAILED
    fi
    echo -e "$result: $2" | tee -a testLog.txt
    echo "-----------------------------------------"
}

chkcmd "$_uname" "no parameter, full pathname"
chkcmd "$_uname \n $_uname" "two commands, full pathname"
chkcmd "$_uname \n\n $_uname" "two commands, blank line in-between, full pathname"
chkcmd "uname" "no parameter, no pathname"
chkcmd "$_cat $_passwd" "one parameter, full pathname"
chkcmd "cat $_passwd" "one parameter, no pathname"
chkcmd "cat $_passwd | sort " "pipe"
chkcmd "cat $_passwd | sort | wc " "2 pipes"
chkcmd "cat < $_passwd" "redirect input"
chkcmd "uname > /tmp/x \n cat /tmp/x" "redirect output"
(echo "sleep 1" ; echo "echo 1") > /tmp/c1
chkcmd 'bash < /tmp/c1 &\n echo 2 \n sleep 3' "background"
chkcmd 'cd .. \n pwd' "change dir"

echo -e "\n\nResults"
cat testLog.txt

rm /tmp/c1 /tmp/t1 /tmp/t2



