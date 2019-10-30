touch database.txt
x=true
while $x
do
	echo "MENU:\n2.insert record.\n3.display\n4.search\n5.delete\n6.modify\n7.exit"
	echo "enter your choice"
	read choice
	case $choice in
 
		3) cat database.txt
			;;
		2) 
			echo "\ninsert data"
			read -p "enter roll:" roll
			read -p "enter name" name
			read -p "enter dob" dob
			read -p "enter marks" marks
			echo "$roll		$name		$dob		$marks" >> database.txt
			;;
		4) echo "entr the roll no you want to search"
			read search
			z=$(grep -c -w $search database.txt)
			if test $z -eq 0
			then echo "record not present"
			fi
			grep -w $search database.txt
			;;
		5) read -p "enter the roll you want to delete" del
			z=$(grep -c -w $del database.txt)
			if test $z -eq 0
			then echo "record not present"
			else
				grep -v -w $del database.txt > database1.txt
				mv database1.txt database.txt
				echo "record deleted successfully"
			fi
			;;
		6) read -p "enter the roll no you want to modify" mod
			pq=$(grep -c -w $mod database.txt)
			if test $pq -eq 0
			then echo "record not present"
			else
				grep -v -w $mod database.txt > database1.txt
				mv database1.txt database.txt
				echo "enter new record"
				read -p "enter roll:" roll
				read -p "enter name" name
				read -p "enter dob" dob
				read -p "enter marks" marks
				echo "$roll		$name		$dob		$marks" >> database.txt
				sort database.txt  > database1.txt
				mv database1.txt database.txt
				echo "record updated successfully"
			fi
			;;
		7) x=false;;
	esac
 
done
