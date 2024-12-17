'''Write a python program to compute following computation on
matrix:
     a) Addition of two matrices
     b) Subtraction of two matrices
     c) Multiplication of two matrices
     d) Transpose of a matrix'''

# matrix = [[int(x) for x in input().split()] for _ in range(int(input("Enter number of rows: ")))]


class Matrix:

    def __init__(self):
        self.row = int(input("Enter no. of rows: "))
        self.col = int(input("Enter no. of columns: "))
        self.mat = [[int(x) for x in input().split()] for _ in range(self.row)]

    def add(self, m2, r2, c2):
        if(self.row != r2 or self.col != c2):
            print("Can't perform addition")
            return

        m3 = [[0]*c2 for _ in range(r2)]

        for i in range(r2):
            for j in range(c2):
                m3[i][j] = self.mat[i][j] + m2[i][j]
        print("Addition of matrix is: ")
        self.display(m3)


    def sub(self, m2, r2, c2):
        if(self.row != r2 or self.col != c2):
            print("Can't perform subtraction")
            return
        m3 = [[0]*c2 for _ in range(r2)]
        for i in range(r2):
            for j in range(c2):
                m3[i][j] = self.mat[i][j] - m2[i][j]
        print("subtraction of matrix is: ")
        self.display(m3)


    def mult(self, m2, r2, c2):
        if self.col != r2:
            print("not possible")
            return
        m3 = [[0]*c2 for _ in range(self.row)]
        for i in range(self.row):
            for j in range(c2):
                for k in range(self.col):
                    m3[i][j] += self.mat[i][k] * m2[k][j]
        print("Multiplication of mat is: ")
        self.display(m3)


    def transpose(self):
        m2 = [[0]*self.col for _ in range(self.row)]

        for i in range(self.row):
            for j in range(self.row):
                m2[j][i] = self.mat[i][j]
        print("Transpose matrix: ")
        self.display(m2)


    def display(self, mat):
        for row in mat:
            print(row)



def main():
    # Input for first matrix
    print("Input for Matrix 1:")
    mat1 = Matrix()

    # Input for second matrix
    print("\nInput for Matrix 2:")
    mat2 = Matrix()

    # Perform operations
    print("\nMatrix Operations:")

    # Addition
    mat1.add(mat2.mat, mat2.row, mat2.col)

    # Subtraction
    mat1.sub(mat2.mat, mat2.row, mat2.col)

    # Multiplication
    mat1.mult(mat2.mat, mat2.row, mat2.col)

    # Transpose of the first matrix
    mat1.transpose()

    # Transpose of the second matrix
    mat2.transpose()


if __name__ == "__main__":
    main()