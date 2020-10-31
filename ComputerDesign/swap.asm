.text
           .globl     main
main:     li    $v0,   5
           syscall
           move  $t7,   $v0
 
           li    $t5,   7   
hexify:    and   $t2,   $t7,   0x0f
           srl   $t7,   $t7,   4
           lb    $t3,   hex_table($t2)
           sb     $t3,   hex_digits($t5)
           sub   $t5,   $t5,   1
           bgez  $t5,   hexify       #$t5>=0 则返回标号hexify继续执行

           li    $v0,   4
           la    $a0,   the_result_is
           syscall

           li    $v0,   10
           syscall

############ data segment ###################

           .data
hex_table: .ascii   "0123456789ABCDEF"
the_result_is: .ascii    "Hexadecimal value: 0x"
hex_digits: .asciiz  "XXXXXXXX" 