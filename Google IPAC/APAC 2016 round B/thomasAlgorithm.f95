subroutine thomasAlgorithm
    implicit none

    integer:: numberOfEquations,rowCounter
    integer,external :: getInteger
    real,dimension(:,:),allocatable::matrix
    real,dimension(:),allocatable::d,c,out,x

    numberOfEquations = getInteger("Enter the number of equations=")

    allocate(matrix(numberOfEquations, numberOfEquations))
    allocate(d(numberOfEquations))
    allocate(c(numberOfEquations))
    allocate(x(numberOfEquations))
    allocate(out(numberOfEquations))

    matrix = 0

    write(*,*) "Enter the values of tridiagonal elements"

    do rowCounter = 1, numberOfEquations-1
       write(*,*) "enter ai's #", rowCounter+1
       read(*,*) matrix(rowCounter + 1, rowCounter)
       write(*,*) "enter bi's #", rowCounter
       read(*,*) matrix(rowCounter, rowCounter)
       write(*,*) "enter ci's #", rowCounter
       read(*,*) matrix(rowCounter, rowCounter+1)
       write(*,*) "enter di's #", rowCounter
       read(*,*) out(rowCounter)
    end do


    write(*,*) " enter bn"
    read(*,*) matrix(numberOfEquations, numberOfEquations)
    write(*,*) "enter dn"
    read(*,*) out(numberOfEquations)
    call printMatrix2D(matrix,numberOfEquations,numberOfEquations)
    write(*,*) out
    c(1) = matrix(1,2)/matrix(1,1)
    do rowCounter = 2, numberOfEquations-1
        c(rowCounter) = (matrix(rowCounter, rowCounter+1))/(matrix(rowCounter, rowCounter) - (matrix(rowCounter, rowCounter - 1)*&
                        c(rowCounter-1)))
    end do
    write(*,*) c
    d(1) = out(1)/matrix(1,1)

    do rowCounter = 2, numberOfEquations
        d(rowCounter) = (out(rowCounter)-(matrix(rowCounter, rowCounter - 1)*d(rowCounter-1)))/&
                        ((matrix(rowCounter, rowCounter)) - matrix(rowCounter, rowCounter - 1)*c(rowCounter-1))
    end do
    write(*,*) d
    x(numberOfEquations) = d(numberOfEquations)

    do rowCounter = numberOfEquations-1, 1, -1
        x(rowCounter) = d(rowCounter) - (c(rowCounter) * x(rowCounter+1))
    end do

    write(*,*) "The solution for the given method is"
    write(*,*) x

    deallocate(matrix)
    deallocate(c)
    deallocate(d)
    deallocate(out)
    deallocate(x)

end subroutine thomasAlgorithm
