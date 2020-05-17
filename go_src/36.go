func isValidSudoku(board [][]byte) bool {
	rows := make(map[int]map[int]bool)
	columns := make(map[int]map[int]bool)
	boxes := make(map[int]map[int]bool)

	for i := 0; i < 9; i++ {
		rows[i] = make(map[int]bool)
		columns[i] = make(map[int]bool)
		boxes[i] = make(map[int]bool)
	}

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			num := int(board[i][j]) - '0'
			if num < 0 || num > 9 {
				continue
			}
			if _, ok := rows[i][num]; ok {
				return false
			}
			rows[i][num] = true

			if _, ok := columns[j][num]; ok {
				return false
			}
			columns[j][num] = true

			boxIndex := (i / 3) * 3 + j / 3
			if _, ok := boxes[boxIndex][num]; ok {
				return false
			}
			boxes[boxIndex][num] = true
		}
	}
	return true
}
