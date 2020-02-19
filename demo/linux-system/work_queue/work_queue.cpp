/*
http://blog.csdn.net/liuhongwei123888/article/details/8681050
*/
//test.c (�ɴ��ݲ������°벿��������,��ʹ��Ĭ�ϵĹ�������)  
#include <linux/init.h>  
#include <linux/module.h>  
#include <linux/interrupt.h>  
#include <linux/irq.h>  
#include <linux/workqueue.h>  
#include <linux/sched.h>  
  
#include <mach/gpio.h>  
#include <mach/regs-gpio.h>  
  
struct my_work_struct_t {  
    struct work_struct work;  
    int data;  
};  
  
static void work_handler(struct work_struct *work)  
{  
    struct my_work_struct_t *my_work_tmp = container_of(work, struct my_work_struct_t, work);  
  
    printk("[KERN] %s %d\n", __func__, __LINE__);  
    printk("[KERN] in_interrupt() = %lu, comm = %s, data = %d\n",in_interrupt(), current->comm, my_work_tmp->data);  
    printk("[KERN] %s %d\n", __func__, __LINE__);  
}  
  
static struct my_work_struct_t mywork;  
  
static irqreturn_t key_handler(int irqno, void *dev_id)  
{  
    printk("[KERN] %s %d\n", __func__, __LINE__);  
      
    // 1. ����Ӳ�� ��ȡ���� ���ж�  
    printk("[KERN] %s %d\n", __func__, __LINE__);  
    mywork.data = 10;  
  
    // 2. �����жϵ��°벿���� ����  
    schedule_work(&mywork.work);  
    printk("[KERN] %s %d\n", __func__, __LINE__);  
  
    return IRQ_HANDLED;  
}  
  
static int __init test_init(void)  
{  
    int ret;  
      
    INIT_WORK(&mywork.work, work_handler);  
  
    ret = request_irq(gpio_to_irq(S5PV210_GPH2(0)), key_handler, IRQF_TRIGGER_FALLING, "mykey_irq", NULL);  
      
    return 0;  
}  
  
static void __exit test_exit(void)  
{  
    free_irq(gpio_to_irq(S5PV210_GPH2(0)), NULL);  
}  
  
module_init(test_init);  
module_exit(test_exit);  
  
MODULE_LICENSE("GPL");  
MODULE_AUTHOR("Micky Liu");  
MODULE_DESCRIPTION("Test for workqueue");  