.data              #���ݶα�������ַ�����ע���\0
  msg_yes: .ascii "YES\0" 
  msg_no:  .ascii "NO\0"  
  num: .word 2


.text               #������൱��main���
  li $v0,5          #scanf("%d",&a);  t0����a��ֵ
  syscall 
  move $t0,$v0  

  lw $t1,num

  bgt $t0,$t1,s1    #a>b����ת����ǩs1����¼�˵�ַ
  la $a0,msg_no     #printf("NO");
  li $v0,4
  syscall 

  j stop            #ֱ����ת���������stop

s1:
  la $a0,msg_yes     #printf("YES");
  li $v0,4
  syscall 

  stop:             #����������䣬����return 0;
  li $v0 10
  syscall 