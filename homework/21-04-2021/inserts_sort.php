<?php	
	// массив случайных чисел
	echo "Random array: ";
	$arr = range(0, 100);
	shuffle($arr);
	foreach($arr as $i) {
	echo "$i ";
	}
	echo "\nSorted array: ";
	
	// сортировка массива
	for ($i = 1; $i < count($arr); $i++) {
		$j = $i;
		while($j > 0 and $arr[$j] < $arr[$j-1]) {
			$tmp = $arr[$j];
			$arr[$j] = $arr[$j-1];
			$arr[$j-1] = $tmp;
			$j--;
		}
	}
	foreach($arr as $i) {
	echo "$i ";
	}