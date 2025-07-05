class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        rows = len(matrix)
        cols = len(matrix[0])
        store_row = [] 
        store_col = []
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    store_row.append(i)
                    store_col.append(j)

        for row in store_row:
            matrix[row] = [0] * cols

        for col in store_col:
            for row in range(rows):
                matrix[row][col] = 0