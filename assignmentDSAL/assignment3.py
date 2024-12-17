# Function to input a matrix
def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Enter element at position ({i+1}, {j+1}): "))
            row.append(element)
        matrix.append(row)
    return matrix


# Function to display a matrix
def display_matrix(matrix):
    for row in matrix:
        print(row)


# Function to perform addition of two matrices
def add_matrices(m1, m2, r1, c1):
    m3 = [[0]*c1 for _ in range(r1)]
    for i in range(r1):
        for j in range(c1):
            m3[i][j] = m1[i][j] + m2[i][j]
    print("Addition of two matrices is: ")
    display_matrix(m3)


# Function to perform subtraction of two matrices
def subtract_matrices(m1, m2, r1, c1):
    m4 = [[0]*c1 for _ in range(r1)]
    for i in range(r1):
        for j in range(c1):
            m4[i][j] = m1[i][j] - m2[i][j]
    print("Subtraction of two matrices is: ")
    display_matrix(m4)

# Function to perform multiplication of two matrices
def multiply_matrices(m1, m2, r1, c1, r2, c2):
    if c1 == r2:  # Checking if multiplication is possible
        m5 = [[0]*c2 for _ in range(r1)]
        for i in range(r1):
            for j in range(c2):
                for k in range(c1):
                    m5[i][j] += m1[i][k] * m2[k][j]
        print("Multiplication of two matrices is: ")
        display_matrix(m5)
    else:
        print("Matrices cannot be multiplied. Number of columns in the first matrix should be equal to the number of rows in the second matrix.")


# Function to find transpose of a matrix
def transpose_matrix(m, r, c):
    m_transpose = [[0]*r for _ in range(c)]
    for i in range(r):
        for j in range(c):
            m_transpose[j][i] = m[i][j]
    return m_transpose


# Main function
def main():
    # Taking input for first matrix
    r1 = int(input("Enter number of rows for 1st matrix: "))
    c1 = int(input("Enter number of columns for 1st matrix: "))
    m1 = input_matrix(r1, c1)
    
    print("First matrix is:")
    display_matrix(m1)

    # Taking input for second matrix
    r2 = int(input("Enter number of rows for 2nd matrix: "))
    c2 = int(input("Enter number of columns for 2nd matrix: "))
    m2 = input_matrix(r2, c2)
    
    print("Second matrix is:")
    display_matrix(m2)

    # a) Addition of matrices
    if r1 == r2 and c1 == c2:
        add_matrices(m1, m2, r1, c1)
    else:
        print("Matrices cannot be added. Dimensions are different.")

    # b) Subtraction of matrices
    if r1 == r2 and c1 == c2:
        subtract_matrices(m1, m2, r1, c1)
    else:
        print("Matrices cannot be subtracted. Dimensions are different.")

    # c) Multiplication of matrices
    multiply_matrices(m1, m2, r1, c1, r2, c2)

    # d) Transpose of matrices
    m6 = transpose_matrix(m1, r1, c1)
    print("Transpose of 1st matrix is: ")
    display_matrix(m6)

    m7 = transpose_matrix(m2, r2, c2)
    print("Transpose of 2nd matrix is: ")
    display_matrix(m7)


# Run the main function
if __name__ == "__main__":
    main()

