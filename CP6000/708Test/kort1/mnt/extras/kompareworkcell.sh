#!/bin/sh

usage(){
    echo ""
    echo "Usage:"
    echo "$0 database1 [database2] workcell1 workcell2 [options]"
    echo "        "
    echo "        database1: path to database 1 (required)"
    echo "        database2: path to database 2. Optional. If not given, path to database1 will be used"
    echo "        workcell1: id number of workcell 1"
    echo "        workcell2: id number of workcell 2"
    echo "        options: one of the following:"
    echo "                 -reportonly: Only reports differences, does not execute kompare."
    echo "                 -diffy: Use diff -y to compare instead of kompare"
    echo "                 -diffys: Use diff -y --suppress-common-lines to compare instead of kompare"
    echo "                 -sync workcellid: executes the same as '$0 /tmp/mnt/database/ /mnt/database/ workcellid workcellid -diffys' "
    echo "                 -gendiff: "
}

argnum="1"
while [ $# -gt 0 ] ; do
    case $1 in
        --help)
            usage
            exit 0
            ;;
        -sync)
            echo "sync"
            dbpath1="/tmp/mnt/database/"
            dbpath2="/mnt/database/"
            workcell1="$2"
            workcell2="$2"
            diffy=1
            argnum="200"
            argsok=1
            break
            ;;
        -syncs)
            echo "sync"
            dbpath1="/tmp/mnt/database/"
            dbpath2="/mnt/database/"
            workcell1="$2"
            workcell2="$2"
            diffys=1
            argnum="200"
            argsok=1
            break
            ;;
        -gendiff)
            diff -y --suppress-common-lines /tmp/mnt/database/item/ /mnt/database/item/
            diff -y --suppress-common-lines /tmp/mnt/database/pattern/ /mnt/database/pattern/
            diff -y --suppress-common-lines /tmp/mnt/database/statetekst/ /mnt/database/statetekst/
            diff -y --suppress-common-lines /tmp/mnt/database/language/ /mnt/database/language/
            exit 0
            break
            ;;
        *)
            #echo "deooh $argnum"
            if [ "$argnum" = "1" ] ; then
                if [ ! -d "$1" ] ; then
                    echo "database1: '$1' is not a directory."
                    usage
                    exit 0
                else
                    dbpath1="$1"
                    argnum="2"
                    shift
                    continue
                fi
            fi
            if [ "$argnum" = "2" ] ; then
                if [ ! -d "$1" ] ; then
                    dbpath2=$dbpath1
                    ((argnum+=1))
                    #TODO: no += in ash
                    #no shift
                else
                    dbpath2="$1"
                    argnum="3"
                    shift
                fi
                continue
            fi
            if [ "$argnum" = "3" ] ; then
                workcell1="$1"
                argnum="4"
                shift
                continue
            fi
            if [ "$argnum" = "4" ] ; then
                workcell2="$1"
                argsok=1
                argnum="5"
                shift
                continue
            fi
            if [ "$argnum" = "5" ] ; then
                if [ "$1" = "-reportonly" ] ; then
                    reportonly=1
                else
                    if [ "$1" = "-diffys" ] ; then
                        diffys=1
                    else
                        if [ "$1" = "-diffy" ] ; then
                            diffy=1
                        else
                            echo "Unknown argument: '$1'. Argument is ignored."
                        fi
                    fi
                fi
                argnum="6"
                shift
                continue
            fi
            if [ "$argnum" = "6" ] ; then
                echo "Too many arguments, only one option allowed in this version"
                echo "Argument '$1' is ignored"
                break;
            fi
            ;;
    esac
done

echo "Database 1: '$dbpath1'"
echo "Workcell 1: '$workcell1'"
echo "Database 2: '$dbpath2'"
echo "Workcell 2: '$workcell2'"
echo ""

if [ -z $argsok ] ; then
    echo "Error in given arguments"
    usage
    exit 0
else
#    echo "the params: $dbpath1, $dbpath2, $workcell1, $workcell2"
    while [ "$go" != "y" -a "$go" != "Y" -a "$go" != "n" -a "$go" != "N" ]
      do
      read -p "Proceed? [y/n] " go
    done
    if [ "$go" != "y" -a "$go" != "Y" ] ; then
        exit 0
    fi
fi

dir1=`ls $dbpath1`
#if [ ! -e "$dbpath1/workcell/$workcell1.workcell" ] ; then
#    echo "Workcell $workcell1 does not exist"
#    exit 0
#fi
#if [ ! -e "$dbpath2/workcell/$workcell2.workcell" ] ; then
#    echo "Workcell $workcell2 does not exist"
#    exit 0
#fi

#workcell 1 id str length
wc1idlen=`echo $workcell1 | tr -d '\n\f\r ' | wc -c | tr -d ' '`
#workcell 1 id str length + 1
wc1idlen1=`echo 1$workcell1 | tr -d '\n\f\r ' | wc -c | tr -d ' '`

#Test if workcell id's are numbers - if not, the workcell is
#considered general and filename must be converted to lower case.
#Workcell 1 can not be general since workcell 2 then should be 
#converted to CamelCase... not really possible.
#TODO: not if wc2 also general
echo "$workcell2" | grep [^0-9] > /dev/null 2>&1
if [ "$?" -eq "0" ]; then
   # If the grep found something other than 0-9
   # then it's not an integer.
    echo "Workcell 2 is general?"
    wc2gen=1
else
    wc2gen=0
fi

echo "$workcell1" | grep [^0-9] > /dev/null 2>&1
if [ "$?" -eq "0" ]; then
   # If the grep found something other than 0-9
   # then it's not an integer.
    if [ $wc2gen -eq 1 ] ; then
        wc1gen=1
    else
        echo "Workcell 1 cannot be general when compared to a non-general Workcell 2. Cannot convert lowercase to CamelCase."
        exit 0
    fi
else
    wc1gen=0
fi

for i in $dir1
  do
  temp=`ls $dbpath1/$i/ | grep -v '~' | cut -c-$wc1idlen | grep $workcell1 | tail -1`
  if [ -z "$temp" ] ; then
      echo "Skipping '$i', contains no $workcell1* files"
      continue
  fi
  files=`ls $dbpath1/$i/$workcell1* | grep -v '~'`
  for j in $files
    do
#    if [ $wc1gen -eq 1 ] ; then
        #echo "lowering1 $wc1gen"
#        temp1=`echo ${j##*/} | cut -c$wc1idlen1-`
#        temp=`echo $temp1 | sed 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
#        file1="$dbpath1/$i/$workcell1$temp"
#    else
        file1=$j
#    fi
    if [ $wc2gen -eq 1 -a $wc1gen -eq 0 ] ; then
        #echo "lowering2 $wc2gen"
        temp1=`echo ${j##*/} | cut -c$wc1idlen1-`
        temp=`echo $temp1 | sed 'y/ABCDEFGHIJKLMNOPQRSTUVWXYZ/abcdefghijklmnopqrstuvwxyz/'`
    else
        temp=`echo ${j##*/} | cut -c$wc1idlen1-`
    fi

    file2="$dbpath2/$i/$workcell2$temp"

    #file2 exists?:
    ls $file2 > /dev/null 2>&1
    if [ "$?" -eq "0" ]; then
    #if [ -a  $file2 ] ; then # virker ikke i ash
        thediff=`diff --brief $file1 $file2`
        if [ ! -z "$thediff" ] ; then
            if [ -z $reportonly ] ; then
                echo ""
                echo "Comparing ${file1##*/} and ${file2##*/}"
                if [ ! -z $diffy ] ; then
                    diff -y $file1 $file2
                else
                    if [ ! -z $diffys ] ; then
                        diff -y --suppress-common-lines $file1 $file2
                    else
                        kompare $file1 $file2
                    fi
                fi
            else
                echo "  ${file1##*/} and ${file2##*/} differ."
            fi
#        else
#            echo "$file1 and $file2 are identical."
        fi

        #kompare includes
        file1include=`grep "Include=" $file1|cut -c9-`
        file2include=`grep "Include=" $file2|cut -c9-`
        
        if [ ! -z $file1include ]; then
            if [ ! -z $file2include ]; then
                #echo "$file1 $file2"
                #echo "TODO: kompare $file1include $file2include"
                thediff=`diff --brief $dbpath1/$i/$file1include $dbpath2/$i/$file2include`
                #echo "$dbpath1/$i/$file1include $dbpath2/$i/$file2include"
                if [ ! -z "$thediff" ] ; then
                    echo ""
                    echo "Comparing ${file1include##*/} and ${file2include##*/}"
                    if [ ! -z $diffys ] ; then
                        diff -y --suppress-common-lines $dbpath1/$i/$file1include $dbpath2/$i/$file2include
                    else
                        diff -y $dbpath1/$i/$file1include $dbpath2/$i/$file2include
                    fi
                fi
            else
                echo "$file1 got include and $file2 does not"
            fi
        else
            if [ ! -z $file2include ]; then
                echo "$file2 got include and $file1 does not"
            fi
        fi
    else
        echo "  Workcell $workcell2 does not have a $temp"
    fi
  done
done

echo "TODO: kompare includes only once"
echo "TODO: kompare inlines"
echo "TODO: kompare items, patterns, statetekst, language... all in workcell file..."
