.data
    prompt1: .asciiz "Enter the number\n"
    prompt2: .asciiz "The factorial of n is:\n"

.text
    # Print prompt1
    li $v0, 4
    la $a0, prompt1
    syscall
    
    
    
    
    # Read integer
         la $a0, value1      #$t0 保存初始值的地址
	li $a1 30
       li $v0, 8           #读取整数值（kernel serice 8）
       syscall
       
       la $s2 value2
       addi $s4 $zero 49
       sb $s4 ($s2)
       addi  
       
       la $t1 value1
       mark1:
       lb $t3 ($t1)
       addi $t1 $t1 1
       bne $t0 $t3 mark1
       subi $t1 $t1 1
       
       move $s1 $a0
     
         la $s3,rst
       add $s3 $s3 1000
       lb $s4 empty
       sb $s4 ($s3)
       
 loop:
       la $s3,rst
       add $t3 $s3 999
       
      j setzero
      returnfromsetzero:
      
       j multiply
       multiplyreturn:
       
       move $t4 $t1
       j sub1
       returnfromsub1:
       
       bne $s1 $t1 loop

       lb $t0, empty
       la $t7 rst
       add $t7 $t7 1000
       sb $t0 ($t7) 
       subi $t7 $t7 1
       move $t8 $t7
       la $t6 rst
       
      	 
      	


    ## END OF YOUR CODE
  #jr $ra
  
  
     # Exit
    li $v0, 10
    syscall
  
setzero:
       add $t5 $zero 48
       sb $t5 ($t3)
       sub $t3 $t3 1
       bne $s3 $t3 setzero
       j returnfromsetzero
  
multiply:
    
       lb $t0, empty
       move $t4 $t1
       
       out:
       subi $t2 $t2 1
       lb $s5 ($t2)
       addi $s5 $s5 -48
       
       
       move $s7 $t7
       inner:
       subi $t1 $t1 1
       lb $s6 ($t1)
       addi $s6 $s6 -48
       mul $s4 $s5 $s6
       lb $s3 ($s7)
       addi $s3 $s3 -48
       add $s3 $s4 $s3
       move $s4 $zero
       blt $s3  10 nocarry
       carry:
       addi $s4 $s4 1
       subi $s3 $s3 10
       bge $s3 10 carry
       nocarry:
       
       addi $s3 $s3 48
       sb $s3 ($s7)
       subi $s7 $s7 1
       lb $s3 ($s7)
       addi $s3 $s3 -48
       add $s3 $s4 $s3 
       addi $s3 $s3 48
       sb $s3 ($s7)
       
       bne $t1 $s1 inner
       move $t1 $t4    
       subi $t7 $t7 1       
       bne $s2 $t2 out
       
       lb $t0 ($s7)
       bne $t0,48 noadding
       addi $s7 $s7 1
       noadding:
       
       j multiplyreturn
       
       
sub1:
 
       subi $t4 $t4 1
       lb $t5 ($t4)
       
        ble $t5 48 jiewei
        
        subi $t5 $t5 1
        sb $t5 ($t4)
        j finish
       
       jiewei:
       add $t5 $zero 57
       sb $t5 ($t4)
       
       j sub1
       finish:
       
       lb $t0 ($t4)
       bne $t0,48 noadding1
       addi $s1 $s1 1
       noadding1:
     j  returnfromsub1


######   data segment####################################

       .data
value1: .space 1024
value2: .space 1024
rst:.space 1024
empty: .byte '\n'
msg1:  .asciiz "result= "
