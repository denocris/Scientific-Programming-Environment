# Fortran

The last Fortran programme will die in five years. *M. S. Pauletti*

```fortran
program hello
   Print *, "Hello World!"
end program Hello
```

My god this thing is not key sensitive!

## Basic

```fortran
program program_name
implicit none      

! type declaration statements      
! executable statements  

end program program_name
```

```
program addNumbers

! This simple program adds two numbers     
   implicit none
   
! Type declarations
   real :: a, b, result 
   
! Executable statements 
   a = 12.0
   b = 15.0
   result = a + b
   print *, 'The total is ', result                   
   
end program addNumbers  
```
## Data Types

```

program testingInt
implicit none

   !two byte integer
   integer(kind=2) :: shortval
   
   !four byte integer
   integer(kind=4) :: longval
   
   !eight byte integer
   integer(kind=8) :: verylongval
   
   !sixteen byte integer
   integer(kind=16) :: veryverylongval
   
   !default integer 
   integer :: defval
        
   print *, huge(shortval)
   print *, huge(longval)
   print *, huge(verylongval)
   print *, huge(veryverylongval)
   print *, huge(defval)
   
end program testingInt
```

```

program division   
implicit none  

   ! Define real variables   
   real :: p, q, realRes 
   
   ! Define integer variables  
   integer :: i, j, intRes  
   
   ! Assigning  values   
   p = 2.0 
   q = 3.0    
   i = 2 
   j = 3  
   
   ! floating point division
   realRes = p/q  
   intRes = i/j
   
   print *, realRes
   print *, intRes
   
end program division
```

**Implict Typing**: very simple, don't do that! Variable names starting with i, j, k, l, m, or n, are considered to be for integer variable and others are real variables. However, you must declare all the variables as it is good programming practice. For that you start your program with the statement `implict none`

# Variables

```
program variableTesting
implicit none

   ! declaring variables
   integer :: total      
   real :: average 
   complex :: cx  
   logical :: done 
   character(len=80) :: message ! a string of 80 characters
   
   !assigning values
   total = 20000  
   average = 1666.67   
   done = .true.   
   message = "A big Hello from Tutorials Point" 
   cx = (3.0, 5.0) ! cx = 3.0 + 5.0i

   Print *, total
   Print *, average
   Print *, cx
   Print *, done
   Print *, message
   
end program variableTesting
```

# Constants

```
program gravitationalDisp

! this program calculates vertical motion under gravity 
implicit none  

   ! gravitational acceleration
   real, parameter :: g = 9.81   
   
   ! variable declaration
   real :: s ! displacement   
   real :: t ! time  
   real :: u ! initial speed  
   
   ! assigning values 
   t = 5.0   
   u = 50  
   
   ! displacement   
   s = u * t - g * (t**2) / 2  
   
   ! output 
   print *, "Time = ", t
   print *, 'Displacement = ',s  
   
end program gravitationalDisp
```

## Array

```
program arrayProg

   real :: numbers(5) !one dimensional integer array
   integer :: matrix(3,3), i , j !two dimensional real array
   
   !assigning some values to the array numbers
   do i=1,5
      numbers(i) = i * 2.0
   end do
   
   !display the values
   do i = 1, 5
      Print *, numbers(i)
   end do
   
   !assigning some values to the array matrix
   do i=1,3
      do j = 1, 3
         matrix(i, j) = i+j
      end do
   end do
   
   !display the values
   do i=1,3
      do j = 1, 3
         Print *, matrix(i,j)
      end do
   end do
   
   !short hand assignment
   numbers = (/1.5, 3.2,4.5,0.9,7.2 /)
   
   !display the values
   do i = 1, 5
      Print *, numbers(i)
   end do
   
end program arrayProg
```

### Array to procedure

```
program arrayToProcedure      
implicit  none    

   integer, dimension (10) :: myArray  
   integer :: i
   
   interface 
      subroutine fillArray (a)
         integer, dimension(:), intent (out) :: a 
         integer :: i         
      end subroutine fillArray      

      subroutine printArray (a)
         integer, dimension(:) :: a 
         integer :: i         
      end subroutine printArray   
   end interface 
   
   call fillArray (myArray)      
   call printArray(myArray)
   
end program arrayToProcedure


subroutine fillArray (a)      
implicit none      
   integer,dimension (:), intent (out) :: a      
   
   ! local variables     
   integer :: i, arraySize  
   arraySize = size(a)
   
   do i = 1, arraySize         
      a(i) = i      
   end do  
   
end subroutine fillArray 


subroutine printArray(a)
implicit none

   integer,dimension (:) :: a  
   integer::i, arraySize
   arraySize = size(a)
   
   do i = 1, arraySize
     Print *, a(i)
   end do
   
end subroutine printArray
```

### Array Subsection

```
program arraySubsection

   real, dimension(10) :: a, b
   integer:: i, asize, bsize
   
   a(1:7) = 5.0 ! a(1) to a(7) assigned 5.0
   a(8:) = 0.0  ! rest are 0.0 
   b(2:10:2) = 3.9
   b(1:9:2) = 2.5
   
   !display
   asize = size(a)
   bsize = size(b)
   
   do i = 1, asize
      Print *, a(i)
   end do
   
   do i = 1, bsize
      Print *, b(i)
   end do
   
end program arraySubsection
```

## Dynamic Array

```
implicit none 

   !rank is 2, but size not known   
   real, dimension (:,:), allocatable :: darray    
   integer :: s1, s2     
   integer :: i, j     
   
   print*, "Enter the size of the array:"     
   read*, s1, s2      
   
   ! allocate memory      
   allocate ( darray(s1,s2) )      
   
   do i = 1, s1           
      do j = 1, s2                
         darray(i,j) = i*j               
         print*, "darray(",i,",",j,") = ", darray(i,j)           
      end do      
   end do      
   
   deallocate (darray)  
end program dynamic_array
```

# Functions

```
program calling_func

   real :: a
   a = area_of_circle(2.0) 
   
   Print *, "The area of a circle with radius 2.0 is"
   Print *, a
   
end program calling_func


! this function computes the area of a circle with radius r  
function area_of_circle (r)  

! function result     
implicit none      

   ! dummy arguments        
   real :: area_of_circle   
   
   ! local variables 
   real :: r     
   real :: pi
   
   pi = 4 * atan (1.0)     
   area_of_circle = pi * r**2  
   
end function area_of_circle
```

# Modules

```
module constants  
implicit none 

   real, parameter :: pi = 3.1415926536  
   real, parameter :: e = 2.7182818285 
   
contains      
   subroutine show_consts()          
      print*, "Pi = ", pi          
      print*,  "e = ", e     
   end subroutine show_consts 
   
end module constants 


program module_example     
use constants      
implicit none     

   real :: x, ePowerx, area, radius 
   x = 2.0
   radius = 7.0
   ePowerx = e ** x
   area = pi * radius**2     
   
   call show_consts() 
   
   print*, "e raised to the power of 2.0 = ", ePowerx
   print*, "Area of a circle with radius 7.0 = ", area  
   
end program module_example
```

```
module constants  
implicit none 

   real, parameter,private :: pi = 3.1415926536  
   real, parameter, private :: e = 2.7182818285 
   
contains      
   subroutine show_consts()          
      print*, "Pi = ", pi          
      print*, "e = ", e     
   end subroutine show_consts 
   
   function ePowerx(x)result(ePx) 
   implicit none
      real::x
      real::ePx
      ePx = e ** x
   end function ePowerx
    
   function areaCircle(r)result(a)  
   implicit none
      real::r
      real::a
      a = pi * r**2  
   end function areaCircle
    
end module constants 


program module_example     
use constants      
implicit none     

   call show_consts() 
   
   Print*, "e raised to the power of 2.0 = ", ePowerx(2.0)
   print*, "Area of a circle with radius 7.0 = ", areaCircle(7.0)  
   
end program module_example
```