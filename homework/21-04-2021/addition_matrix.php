<?php	
	// заполнение матриц
	$matrix1 = [];
	$matrix2 = [];
	for ($i = 0; $i < 4; $i++) {
		for ($j = 0; $j < 4; $j++) {
			$matrix1[$i][$j] = rand(1, 99);
			$matrix2[$i][$j] = rand(1, 99);
		}
	}

	// вывод матриц
	echo "Matrix 1: \n";
	foreach ($matrix1 as $i) {
		foreach ($i as $j) {
			echo "$j ";
		}
		echo "\n";
	}
	echo "\nMatrix 2: \n";
	foreach ($matrix2 as $i) {
		foreach ($i as $j) {
			echo "$j ";
		}
		echo "\n";
	}

	// сложение матриц и вывод результирующей
	$result_matrix = [];
	for ($i = 0; $i < 4; $i++) {
		for ($j = 0; $j < 4; $j++) {
			$result_matrix[$i][$j] = $matrix1[$i][$j] + $matrix2[$i][$j];
		}
	}
	echo "\nResult matrix: \n";
	foreach ($result_matrix as $i) {
		foreach ($i as $j) {
			echo "$j ";
		}
		echo "\n";
	}