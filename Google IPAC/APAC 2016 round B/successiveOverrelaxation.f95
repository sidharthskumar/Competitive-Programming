subroutine successiveOverrelaxation

    implicit none

    integer, external :: getInteger

    logical, external :: isDiagonallyDominant

    integer :: numberOfEquations
    integer :: rows, columns
    integer :: rowCounter, columnCounter
    integer :: iterationCounter = 0

    real, dimension(:,:), allocatable :: a
    real, dimension(:), allocatable :: b, x, xOld
    real, dimension(:), allocatable :: error
    real :: w=0.4
    real :: factor

    real, parameter :: tolerance = 1.0e-6

    logical :: solutionFound = .false.

    write(*,*) "System of Linear Algebraic Equations"
    write(*,*) "Method: Successive Overrelaxation"
    write(*,*)

    numberOfEquations = getInteger("Enter number of equations:")

    rows = numberOfEquations
    columns = numberOfEquations

    allocate(a(rows, columns))
    allocate(b(rows))
    allocate(x(rows))
    allocate(xOld(rows))
    allocate(error(rows))

    do rowCounter = 1, rows
        write(*,10) "Enter equation #", rowCounter
        do columnCounter = 1, columns
            read(*,*) a(rowCounter, columnCounter)
        end do
        read(*,*) b(rowCounter)
    end do

    do rowCounter = 1, rows
        write(*,20) "Enter the initial estimate for x", rowCounter
        read(*,*) x(rowCounter)
    end do

    xOld = x

    write(*,*) "The Matrix of Coefficients:"
    call printMatrix2D(a, rows, columns)

    write(*,*) "The Column Vector on the Right:"
    call printMatrix2D(b, rows, 1)

    write(*,*) "The Initial Estimates for x:"
    call printMatrix2D(x, rows, 1)

    if(isDiagonallyDominant(a, rows, columns) .eqv. .true.) then
        do while(solutionFound .eqv. .false.)
            iterationCounter = iterationCounter + 1
            do rowCounter = 1, rows
                factor = 0
                do columnCounter = 1, columns
                    if (rowCounter /= columnCounter) then
                        factor = factor + a(rowCounter, columnCounter) * x(columnCounter)
                    end if
                end do

                x(rowCounter) = (1-w)*xOld(rowCounter) + w *((1 / a(rowCounter, rowCounter)) * (b(rowCounter) - factor))
            end do

            do rowCounter = 1, rows
                error(rowCounter) = abs(((x(rowCounter)) - (xOld(rowCounter))) / (x(rowCounter)))
            end do

            if(maxval(error) < tolerance) then
                solutionFound = .true.
            end if

            xOld = x
        end do

        write(*,30) "Iterations required = ", iterationCounter
        call printMatrix2D(x, rows, 1)
    else
        write(*,*) "The matrix of coefficients is not diagonally dominant. The iterations may not converge."
    end if

    10 format(a16, i2)
    20 format(a32, i2)
    30 format(a22, i2)

    deallocate(a)
    deallocate(b)
    deallocate(x)
    deallocate(xOld)
    deallocate(error)

end subroutine successiveOverrelaxation
