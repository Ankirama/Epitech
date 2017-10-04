#!/bin/sh

IFS=''
filename="sh.db"
separator="dijwqodq--@djwqdozj9031ei2kqapozomdDQWl2e9312aizkdq21__"
id="1"
display="0"
is_key="false"
key=""
is_value="false"
error_select="false"
is_dollar="false"
value=""

flush_key()
{
    if [[ "$is_value" = "true" ]] || [[ "$is_key" = "true" ]] ; then
	usage
    fi
  echo -n > $filename
}

#add a key (usage : put <key> <value>)
#don't display
put_key()
{
    if [[ "$is_key" = "false" ]] || [[ "$is_value" = "false" ]] ; then
	usage
    fi
    if [[ ! -e "$filename" ]] ; then
	`echo "$key $separator$value" > "$filename"`
    fi
    tmpp="$(echo -E "$key$separator")"
    tmp="$(grep -F "$(echo $tmpp)" $filename)"
    if [[ -z "$tmp" ]] ; then
	`echo "$key$separator$value" >> "$filename"`
    else
	curr_val="$(echo -E "$tmp" | sed "s/.*$(echo $separator)//g")"
	sed -i "s/^$(echo "$tmpp")$(echo "$curr_val")/$(echo "$tmpp")$(echo "$value")/g" $filename
    fi
}

#remove a key (usage : remove <key> [<value>])
#if <value> isn't specified then just put the key to null
#if value is bad or key doesn't exist then do nothing
#don't display
del_key()
{
  if [[ "$is_key" == "false" ]] ; then
    usage
  fi
  tmpp="$(echo -E $key$separator)"
  curr_val="$(grep -m 1 ^"$(echo $tmpp)" $filename | sed 's/'$tmpp'//g')"
  if [[ "$is_value" = "false" ]] ; then
    if [[ "$curr_val" != "" ]] ; then
      sed -i "/^$(echo "$key")/ s/$(echo "$curr_val")//g" $filename
    fi
  else
    if [[ "$value" = "$curr_val" ]] ; then
      sed -i "/^$(echo "$tmpp")/d" $filename
    fi
  fi
}

#it will display matched <key> (usage: select [<expression])
#if no parameters, then display every keys
select_key()
{
  if [[ "$is_value" = "true" ]] ; then
    usage
  fi
  if [[ "$error_select" = "true" ]] ; then
    exit 0
  fi
  if [[ "$is_key" = "false" ]] ; then
    while read -r p ; do
      key="$(echo $p | sed "s/$(echo $separator).*$//g")"
      cut="$(echo $p | sed "s/^.*$(echo $separator)//g")"
      if [[ "$display" = "1" ]] ; then
          echo "$key=$cut"
      else
          echo "$cut"
      fi
    done < $filename
  else
    while read -r p ; do
      key_tmp="$(echo $p | sed "s/$(echo $separator).*$//g" | grep -e $(echo $key))"
      if [[ -z "$key_tmp" ]] ; then
        continue
      fi
      key_tmp="$(echo $p | sed "s/$(echo $separator).*$//g")"
      cut="$(echo $p | sed "s/^.*$(echo $separator)//g")"
      if [[ "$display" = "1" ]] ; then
        echo "$key_tmp=$cut"
      else
        echo "$cut"
      fi
    done < $filename
  fi
}

usage()
{
    echo "Syntax error : Usage bdsh.sh [-k] [-f <db_file>] (put (<clef> | $<clef>) (<valeur> | $<clef>) | del (<clef> | $<clef>) [<valeur> | $<clef>] | select [<expr> | $<clef>] | flush)" >&2
    exit 1
}

##----------init index value and options----------##
if [[ "$#" -ge 1 ]] ; then
  if [[ "$1" = "-k" ]] ; then
    display="1"
    if [[ "$#" -ge 2 ]] && [[ "$2" = "-f" ]] ; then
	     if [[ "$#" -ge 4 ]] ; then
	        filename="$3"
	        id="4"
	     else
          usage
	     fi
    else
	     if [[ "$#" -ge 2 ]] ; then
	        id="2"
	     else
	        usage
	     fi
    fi
  else
    if [[ "$1" = "-f" ]] ; then
      if [[ "$#" -ge 3 ]] ; then
          filename="$2"
	        id="3"
      else
        usage
      fi
    fi
  fi
else
  usage
fi

action=$(eval echo "\$$id")

##-----------Check si le fichier est correct-------------##
if [[ "$action" != "put" ]] ; then
    if [[ ! -e "$filename" ]] ; then
	echo "No base found : file \"$filename\" doesn't exist" >&2
	exit 1
    else
	if [[ ! -f "$filename" ]] ; then
	    echo "No base found : file \"$filename\" isn't a regular file" >&2
	    exit 1
	else
	    if [[ ! -r "$filename" ]] ; then
		echo "No base found : file \"$filename\" isn't a readable file" >&2
		exit 1
	    else
		if [[ ! -w "$filename" ]] ; then
		    echo "No base found : file \"$filename\" isn't a writable file" >&2
		    exit 1
		fi
	    fi
	fi
    fi
fi
##---------END check fichier----------#

max=$((id+2))

if [[ "$#" -eq "$max" ]] ; then
    key_id=$((id+1))
    value_id="$max"
    is_key="true"
    key=$(eval echo "\$$key_id")
    is_value="true"
    value=$(eval echo "\$$value_id")
else
    max_less=$((id+1))
    if [[ "$#" -eq "$max_less" ]] ; then
	key_id="$max_less"
	is_key="true"
	key=$(eval echo "\$$key_id")
    else
	if [[ "$action" != "select" ]] && [[ "$action" != "flush" ]]; then
	    usage
	fi
    fi
fi
if [[ "$is_value" = "true" ]] && [[ "$value" = "\$"* ]] ; then
    value_tmp="$(echo $value | cut -d '$' -f2-)"
    value_tmp1="$(grep  -m 1 "$(echo $value_tmp)$separator" $filename)"
    if [[ -z "$value_tmp1" ]] ; then
	if [[ "$action" = "select" ]] ; then
	    error_select="true"
	else
	    echo "No such key : unable to find '$value_tmp'" >&2
	    exit 1
	fi
    fi
    value="$(echo $value_tmp1 | sed "s/^.*$(echo $separator)//g")"
fi
if [[ "$is_key" = "true" ]] && [[ "$key" = "\$"* ]] ; then
  is_dollar="true"
  key_tmp="$(echo $key | cut -d '$' -f2-)"
  key_tmp1="$(grep  -m 1 "$(echo $key_tmp)$separator" $filename)"
  if [[ -z "$key_tmp1" ]] ; then
      if [[ "$action" = "select" ]] ; then
	  error_select="true"
      else
	  echo "No such key : unable to find '$key_tmp'" >&2
	  exit 1
      fi
  fi
  key="$(echo $key_tmp1 | sed "s/^.*$(echo $separator)//g")"
fi
##----------            END            ----------##

case "$action" in
    'put')
	put_key
	;;
    'flush')
	flush_key
	;;
    'select')
	select_key
	;;
    'del')
	del_key
	;;
    *)
	usage
	;;
esac
exit 0
