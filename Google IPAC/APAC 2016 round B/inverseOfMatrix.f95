subroutine inverseOfMatrix
    implicit none

    integer, external :: getInteger
    integer, external :: getRowNumberForMaxValueInColumn

    integer :: n

    real, dimension(:,:), allocatable :: a, b

    integer :: rows, columns
    integer :: rowCounter, columnCounter
    integer :: stepCounter

    integer :: pivotRow, pivotColumn
    real :: pivot

    integer :: rowCurrent, rowMaximum

    real :: factor

    n = getInteger("Enter the number of rows/columns for nxn matrix")

    rows = n
    columns = n

    allocate (a(rows, columns))
    allocate (b(rows, columns))

    do rowCounter = 1, rows
        write(*,*) "Enter row #", rowCounter
        do columnCounter = 1, columns
            read(*,*) a(rowCounter, columnCounter)
        end do
    end do

    do rowCounter = 1, rows
        do columnCounter = 1, columns
            if (rowCounter == columnCounter) then
                b(rowCounter, columnCounter) = 1
            else
                b(rowCounter, columnCounter) = 0
            end if
        end do
    end do

    write(*,*) "Matrix"
    call printMatrix2D(a, rows, columns)

    do stepCounter = 1, columns
        pivotRow = stepCounter
        pivotColumn = stepCounter

        rowCurrent = pivotRow
        rowMaximum = getRowNumberForMaxValueInColumn(a, rows, columns, pivotColumn, pivotRow)

        if (abs(a(rowCurrent, pivotColumn)) < abs(a(rowMaximum, pivotColumn))) then
            call swapRows(a, rows, columns, rowCurrent, rowMaximum)
        end if

        pivot = a(pivotRow, pivotColumn)

        do columnCounter = 1, columns
            a(pivotRow, columnCounter) = a(pivotRow, columnCounter) / pivot
            b(pivotRow, columnCounter) = b(pivotRow, columnCounter) / pivot
        end do

        do rowCounter = 1, rows
            factor = a(rowCounter, pivotColumn)
            do columnCounter = 1, columns
                if (rowCounter /= pivotRow) then
                    a(rowCounter, columnCounter) = a(rowCounter, columnCounter) - factor * a(pivotRow, columnCounter)
                    b(rowCounter, columnCounter) = b(rowCounter, columnCounter) - factor * b(pivotRow, columnCounter)
                end if
            end do
        end do
    end do

    write(*,*) "Inverse of the Matrix"
    call printMatrix2D(b, rows, columns)


end subroutine inverseOfMatrix
